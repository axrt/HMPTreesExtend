//
//  TaxonomicNodeFactory.h
//  RcppStudy
//
//  Created by Alexander Tuzhikov on 10/1/14.
//  Copyright (c) 2014 Alexander Tuzhikov. All rights reserved.
//

#ifndef __RcppStudy__TaxonomicNodeFactory__
#define __RcppStudy__TaxonomicNodeFactory__

#include <stdio.h>
#include "TaxonomicNode.h"


using namespace std;
class TaxonomicNodeFactory{
    
    
public:
    
    TaxonomicNodeFactory();
    virtual ~TaxonomicNodeFactory();
    
    virtual TaxonomicNode* newInstanceFromComponents(TaxonomicNode::Ranks rank, string* scientificName)const;
    
    virtual TaxonomicNode* newInstanceFromComponentsWithScores(TaxonomicNode::Ranks rank, string* scientificName, vector<double>* scores)const;
    
    virtual TaxonomicNode* newInstanceFromVectorWithScores(vector<string*> *vec,vector<double>*scores)const throw (invalid_argument);
    
    virtual TaxonomicNode* newInstanceFromVector(vector<string*> *vec)const throw (invalid_argument);
    
    
    
    virtual TaxonomicNode* tree(vector<vector<string*>*> *hierRowNames)const;

    
};

#endif /* defined(__RcppStudy__TaxonomicNodeFactory__) */
