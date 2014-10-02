//
//  NewickConverter.cpp
//  RcppStudy
//
//  Created by Alexander Tuzhikov on 10/2/14.
//  Copyright (c) 2014 Alexander Tuzhikov. All rights reserved.
//

#include "NewickConverter.h"


using namespace std;
using namespace Rcpp;
SEXP convertToNewick(SEXP hmptNames){
    
    List l(hmptNames);
    StringVector s(l.size());
    
    for(int i=0;i<l.size();i++){
        SEXP sexp=l[i];
        StringVector line(sexp);
        for(int j=0; j<line.size(); j++){
            cout<< line[j] <<endl;
        }
        
    }
    
    return Rcpp::wrap(true);
}