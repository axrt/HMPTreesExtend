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

TaxonomicNode* TaxonomicNodeFactory::TaxonomicNodeFactory::newInstanceFromComponents(TaxonomicNode::Ranks rank, std::string * scientificName)const{
    
    return new TaxonomicNode(rank,scientificName);
}

TaxonomicNode* TaxonomicNodeFactory::newInstanceFromVector(std::vector<std::string*> *vec)const throw (std::invalid_argument){
    //Check for fails
    if(vec->size()>TaxonomicNode::Ranks::species||vec->size()==0){
        const std::string& exp ="Bad record format!";
        throw std::invalid_argument(exp);
    }
    //Convert all to TaxonomicNodes
    int i=0;
    std::vector<TaxonomicNode*> nodes;
    
    
    for(i=0;i<vec->size();i++){
        nodes.push_back(this->newInstanceFromComponents((TaxonomicNode::Ranks)i,vec->at(i)));
    }
    //Set self as parent
    nodes.at(0)->setParent(nodes.at(0));
    
    for(i=1;i<nodes.size();i++){
        TaxonomicNode *parent=nodes.at(i-1);
        TaxonomicNode *child=nodes.at(i);
        parent->addChild(child);
        child->setParent(parent);
    }
    std::cout<<"current: "<<*nodes.at(0)->getName()<<std::endl;
    return nodes.at(0);
}
