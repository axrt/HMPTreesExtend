//
//  TaxonomicNode.cpp
//  RcppStudy
//
//  Created by Alexander Tuzhikov on 9/29/14.
//  Copyright (c) 2014 Alexander Tuzhikov. All rights reserved.
//


#include "TaxonomicNode.h"

TaxonomicNode::TaxonomicNode(Ranks rank,  std::string* scientificName ){
    
    this->rank=rank;
    this->scientificName=scientificName;
    this->children=new std::set<TaxonomicNode*,set_compare>();
    
}
TaxonomicNode::~TaxonomicNode(){
    if (this->rank) {
        ~this->rank;
    }
    if (this->children){
        this->children->clear();
        delete this->children;
        this->children=nullptr;
    }
    if (this->scientificName) {
        delete scientificName;
        this->scientificName=nullptr;
    }
}
TaxonomicNode::Ranks TaxonomicNode::getRank()const{
    return this->rank;
}

bool TaxonomicNode::operator==(const TaxonomicNode& another){
    std::cout<<"=="<<std::endl;
    if (this->rank==another.rank) {
        
        if(*this->scientificName==*another.scientificName){
            
            return true;
        }
    }
    return false;
}

bool TaxonomicNode::operator>(const TaxonomicNode& another){
    if(this->rank!=another.rank){
        
        return this->rank>another.rank;
    }else{
        return *this->scientificName==*another.scientificName;
    }
    
}
bool TaxonomicNode::operator<(const TaxonomicNode& another){
    if(this->rank!=another.rank){
        
        return this->rank<another.rank;
    }else{
        return *this->scientificName==*another.scientificName;
    }
}


TaxonomicNode* TaxonomicNode::add(TaxonomicNode* anotherNode) throw(std::invalid_argument){
    
    if(this->rank!=anotherNode->rank){
        throw std::invalid_argument("Adding an invalid node!");
    }
    if(*this->scientificName==*anotherNode->scientificName){
        for(TaxonomicNode* thisChildrenNode:*this->children){
            for(TaxonomicNode *thatChildrenNode:*anotherNode->children){
                thisChildrenNode->add(thatChildrenNode);
            }
        }
        for(TaxonomicNode *thatChildrenNode:*anotherNode->children){
            this->children->insert(thatChildrenNode);
        }
    }
    return this;
}

void TaxonomicNode::setParent(TaxonomicNode *parentNode){
    this->parent=parentNode;
}

void TaxonomicNode::addChild(TaxonomicNode* childNode) const throw(std::invalid_argument){
    this->children->insert(childNode);
}

void TaxonomicNode::toString() const{
    std::cout<<""<<std::endl;
}

std::string* TaxonomicNode::getName()const{
    return this->scientificName;
}

