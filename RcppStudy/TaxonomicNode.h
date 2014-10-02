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

#endif /* defined(__RcppStudy__TaxonomicNode__) */


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
    
    TaxonomicNode(Ranks rank, std::string* scientificName);
    virtual ~TaxonomicNode();
    
    virtual TaxonomicNode* add(TaxonomicNode* anotherNode) throw(std::invalid_argument);
    virtual std::string *getName()const;
    virtual Ranks getRank()const;
    virtual void setParent(TaxonomicNode* parentNode);
    virtual void addChild(TaxonomicNode* childNode)const throw(std::invalid_argument);
    virtual void toString()const;
    virtual bool operator==(const TaxonomicNode &another);
    virtual bool operator>(const TaxonomicNode &another);
    virtual bool operator<(const TaxonomicNode &another);
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
    
protected:
    
    Ranks rank;
    std::string* scientificName;
    TaxonomicNode* parent;
    std::set<TaxonomicNode*,set_compare> *children;
    
    
};



