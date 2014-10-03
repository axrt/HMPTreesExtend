//
//  TaxonomicNodeFactory.cpp
//  RcppStudy
//
//  Created by Alexander Tuzhikov on 10/1/14.
//  Copyright (c) 2014 Alexander Tuzhikov. All rights reserved.
//

#include "TaxonomicNodeFactory.h"

TaxonomicNodeFactory::TaxonomicNodeFactory(){
    
}
TaxonomicNodeFactory::~TaxonomicNodeFactory(){
    
}

TaxonomicNode* TaxonomicNodeFactory::TaxonomicNodeFactory::newInstanceFromComponents(TaxonomicNode::Ranks rank, string * scientificName)const{
    
    return new TaxonomicNode(rank,scientificName);
}

TaxonomicNode* TaxonomicNodeFactory::newInstanceFromVector(vector<string*> *vec)const throw (invalid_argument){
    
    return this->newInstanceFromVectorWithScores(vec, nullptr);
}

TaxonomicNode* TaxonomicNodeFactory::newInstanceFromVectorWithScores(vector<string *> *vec,vector<double> *scores)const throw (invalid_argument){
    
    //Check for fails
    TaxonomicNode::Ranks lowest=TaxonomicNode::species;
    if(vec->size() > lowest ||vec->size()==0){
        const string& exp ="Bad record format!";
        throw invalid_argument(exp);
    }
    
    //Convert all to TaxonomicNodes
    unsigned int i=0;
    vector<TaxonomicNode*> nodes;
    for(i=0;i<vec->size();i++){
        if(scores==nullptr){
        nodes.push_back(this->newInstanceFromComponents((TaxonomicNode::Ranks)i,vec->at(i)));
        }else{
        nodes.push_back(this->newInstanceFromComponentsWithScores((TaxonomicNode::Ranks)i,vec->at(i), scores));
        }
    }
    
    //Set self as parent
    nodes.at(0)->setParent(nodes.at(0));
    
    //Link all together
    for(i=1;i<nodes.size();i++){
        TaxonomicNode *parent=nodes.at(i-1);
        TaxonomicNode *child=nodes.at(i);
        parent->addChild(child);
        child->setParent(parent);
    }
    
    //return the head
    return nodes.at(0);
}

TaxonomicNode* TaxonomicNodeFactory::tree(vector<vector<string*>*> *hierRowNames)const{
    
    TaxonomicNode *first=this->newInstanceFromVector(hierRowNames->at(0));
    for(unsigned int i=1;i<hierRowNames->size();i++){
        first->add(this->newInstanceFromVector(hierRowNames->at(i)));
    }
    
    return first;
}

TaxonomicNode *TaxonomicNodeFactory::newInstanceFromComponentsWithScores(TaxonomicNode::Ranks rank, string *scientificName, vector<double>* scores)const{
    return new TaxonomicNode(rank,scientificName,scores);
}

