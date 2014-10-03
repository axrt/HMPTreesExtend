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
    vector<vector<string*>*> names;
    
    for(int i=0;i<l.size();i++){
        SEXP sexp=l[i];
        StringVector line(sexp);
        vector<string*> *cppLine=new vector<string*>();
        for(int j=0; j<line.size(); j++){
            cppLine->push_back(new string((string)line[j]));
        }
        names.push_back(cppLine);
    }
    
    
    cout<< names.size() <<endl;
    
    return Rcpp::wrap(true);
}