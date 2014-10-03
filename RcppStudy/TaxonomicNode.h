//
//  TaxonomicNode.h
//  RcppStudy
//
//  Created by Alexander Tuzhikov on 9/29/14.
//  Copyright (c) 2014 Alexander Tuzhikov. All rights reserved.
//

#ifndef __RcppStudy__TaxonomicNode__
#define __RcppStudy__TaxonomicNode__

#include <stdio.h>
#include <string>
#include <iostream>
#include <set>
#include <string>
#include <stdexcept>
#include <vector>

using namespace std;
class TaxonomicNode{
public:
    
    typedef enum {
        domain,
        phylum,
        c_lass,
        order,
        family,
        genus,
        species
    } Ranks;
    
    struct set_compare {
        bool operator() (const TaxonomicNode* left, const TaxonomicNode* right) const{
            if(left->getRank() == right->getRank()){
                if(*left->getName()==*right->getName()){
                    return false;
                }else{
                    return true;
                }
            }else return (left->getRank() < right->getRank());
        }
    };
    
    TaxonomicNode(Ranks rank, string* scientificName);
    TaxonomicNode(Ranks rank, string* scientificName, vector<double>* scores);
    virtual ~TaxonomicNode();
    
    virtual TaxonomicNode* add(TaxonomicNode* anotherNode) throw(invalid_argument);
    virtual string *getName()const;
    virtual Ranks getRank()const;
    virtual vector<double> *getScores()const;
    virtual void setParent(TaxonomicNode* parentNode);
    virtual void addChild(TaxonomicNode* childNode)const throw(invalid_argument);
    virtual void toString()const;
    virtual bool operator==(const TaxonomicNode &another);
    virtual bool operator>(const TaxonomicNode &another);
    virtual bool operator<(const TaxonomicNode &another);
    virtual set<TaxonomicNode*,set_compare>* getChildren()const;
    
    
protected:
    
    Ranks rank;
    string* scientificName;
    TaxonomicNode* parent;
    set<TaxonomicNode*,set_compare> *children;
    vector<double>* scores;
    
    
};

#endif /* defined(__RcppStudy__TaxonomicNode__) */



