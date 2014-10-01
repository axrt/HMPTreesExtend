//
//  main.cpp
//  RcppStudy
//
//  Created by Alexander Tuzhikov on 9/29/14.
//  Copyright (c) 2014 Alexander Tuzhikov. All rights reserved.
//
#include "TaxonomicNode.h"

int main(int argc, const char * argv[]) {
    
    std::string* parent=new std::string("parent");
    TaxonomicNode::Ranks paretnRank=TaxonomicNode::Ranks::domain;
    TaxonomicNode *parentNode=new TaxonomicNode(paretnRank, parent);
    
    std::string* child=new std::string("child");
    TaxonomicNode::Ranks childRank=TaxonomicNode::Ranks::domain;
    TaxonomicNode *childNode=new TaxonomicNode(childRank, child);
    
    std::string* child2=new std::string("child");
    TaxonomicNode::Ranks childRank2=TaxonomicNode::Ranks::domain;
    TaxonomicNode *childNode2=new TaxonomicNode(childRank2, child2);

    std::set<TaxonomicNode,set_compare> *testSet=new std::set<TaxonomicNode,set_compare>();
    testSet->insert(*childNode);
    std::cout<<testSet->size()<<std::endl;
    testSet->insert(*parentNode);
    std::cout<<testSet->size()<<std::endl;
    testSet->insert(*childNode2);
    std::cout<<testSet->size()<<std::endl;
    
    std::cout<<"----"<<std::endl;
    std::cout<<(*childNode==*childNode2)<<std::endl;
    
    //std::cout<<*parentNode->getName()<<std::endl;
    delete parentNode;
    delete childNode;
    delete testSet;
    return 0;
}
