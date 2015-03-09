//
//  TaxonomicNodeHelper.h
//  RcppStudy
//
//  Created by Alexander Tuzhikov on 10/3/14.
//  Copyright (c) 2014 Alexander Tuzhikov. All rights reserved.
//

#ifndef __RcppStudy__TaxonomicNodeHelper__
#define __RcppStudy__TaxonomicNodeHelper__

#include <stdio.h>
#include "TaxonomicNode.h"

using namespace std;

string* toNewick(TaxonomicNode *rootNode);

string* toItol(TaxonomicNode *rootNode);

#endif /* defined(__RcppStudy__TaxonomicNodeHelper__) */
