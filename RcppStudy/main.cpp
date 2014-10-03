//
//  main.cpp
//  RcppStudy
//
//  Created by Alexander Tuzhikov on 9/29/14.
//  Copyright (c) 2014 Alexander Tuzhikov. All rights reserved.
//
#include "TaxonomicNodeFactory.h"
#include "TaxonomicNodeHelper.h"

int main(int argc, const char * argv[]) {
    
    const TaxonomicNodeFactory tnf;
    
    std::string* parent=new std::string("parent");
    TaxonomicNode::Ranks paretnRank=TaxonomicNode::domain;
    TaxonomicNode *parentNode=new TaxonomicNode(paretnRank, parent);
    
    std::string* child=new std::string("child");
    TaxonomicNode::Ranks childRank=TaxonomicNode::domain;
    TaxonomicNode *childNode=new TaxonomicNode(childRank, child);
    
    std::string* child2=new std::string("child");
    TaxonomicNode::Ranks childRank2=TaxonomicNode::domain;
    TaxonomicNode *childNode2=new TaxonomicNode(childRank2, child2);

    std::string* child3=new std::string("child3");
    TaxonomicNode::Ranks childRank3=TaxonomicNode::domain;
    TaxonomicNode *childNode3=tnf.newInstanceFromComponents(childRank3, child3);
    
    
    std::string* child4=new std::string("child4");
    TaxonomicNode::Ranks childRank4=TaxonomicNode::domain;
    TaxonomicNode *childNode4=tnf.newInstanceFromComponents(childRank4, child4);
    
    std::cout<<(*childNode3->getName())<<std::endl;
    std::cout<<"----"<<std::endl;

    std::set<TaxonomicNode*,TaxonomicNode::set_compare> *testSet=new std::set<TaxonomicNode*,TaxonomicNode::set_compare>();
    testSet->insert(childNode);
    std::cout<<testSet->size()<<std::endl;
    testSet->insert(parentNode);
    std::cout<<testSet->size()<<std::endl;
    testSet->insert(childNode2);
    std::cout<<testSet->size()<<std::endl;

    
    std::vector<std::string*>* nodesVec=new std::vector<std::string*>();
    nodesVec->push_back(parent);
    nodesVec->push_back(child);
    nodesVec->push_back(child4);
    TaxonomicNode *testHierNode=tnf.newInstanceFromVector(nodesVec);
    
    
    std::cout<<*testHierNode->getName()<<std::endl;
    
    std::cout<<"----"<<std::endl;

    
    
    std::cout<<"----"<<std::endl;
    std::cout<<TaxonomicNode::domain<<std::endl;
    std::cout<< TaxonomicNode::domain<<std::endl;

    std::cout<<(*childNode==*childNode2)<<std::endl;
    
    //std::cout<<*parentNode->getName()<<std::endl;
    
    std::cout<<"----"<<std::endl;
    
    
    std::vector<std::string*>* nodesVec2=new std::vector<std::string*>();
    nodesVec2->push_back(new string("parent"));
    nodesVec2->push_back(child3);
    
    TaxonomicNode *testHierNode2=tnf.newInstanceFromVector(nodesVec2);
    testHierNode->add(testHierNode2);
    delete testHierNode2;
    std::cout<<"----"<<std::endl;
    
    std::cout<<*toNewick(testHierNode)<<std::endl;
    
    
    delete testHierNode;

    delete childNode4;
    testSet->clear();
    delete child3;
    delete nodesVec;
    delete nodesVec2;
    delete testSet;
    
    return 0;
}
