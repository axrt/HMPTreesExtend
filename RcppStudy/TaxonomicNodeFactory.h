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


#endif /* defined(__RcppStudy__TaxonomicNodeFactory__) */



class TaxonomicNodeFactory{
    
    
public:
    
    TaxonomicNodeFactory();
    virtual ~TaxonomicNodeFactory();
    
    virtual TaxonomicNode* newInstanceFromComponents(TaxonomicNode::Ranks rank, std::string* scientificName)const;
    
    virtual TaxonomicNode* newInstanceFromVector(std::vector<std::string*> *vec)const throw (std::invalid_argument);
    
};