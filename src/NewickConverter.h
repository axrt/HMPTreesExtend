//
//  NewickConverter.h
//  RcppStudy
//
//  Created by Alexander Tuzhikov on 10/2/14.
//  Copyright (c) 2014 Alexander Tuzhikov. All rights reserved.
//

#ifndef __RcppStudy__NewickConverter__
#define __RcppStudy__NewickConverter__

#include <stdio.h>
#include <Rcpp.h>
#include "TaxonomicNodeFactory.h"
#include "TaxonomicNodeHelper.h"


RcppExport SEXP convertToNewick( SEXP hmptNames);

RcppExport SEXP convertToItol( SEXP hmptNames);

#endif /* defined(__RcppStudy__NewickConverter__) */

