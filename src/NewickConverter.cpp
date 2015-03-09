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

vector<vector<string*>*>* toNames (SEXP hmptNames){
   List l(hmptNames);
    vector<vector<string*>*>* names=new vector<vector<string*>*>();
    
    for(int i=0;i<l.size();i++){
        SEXP sexp=l[i];
        StringVector line(sexp);
        vector<string*> *cppLine=new vector<string*>();
        for(int j=0; j<line.size(); j++){
            cppLine->push_back(new string((string)line[j]));
        }
        names->push_back(cppLine);
    }
    return(names);
}

SEXP convertToItol(SEXP hmptNames){
    
    vector<vector<string*>*>* names=toNames(hmptNames);
    TaxonomicNodeFactory *factory=new TaxonomicNodeFactory();
    TaxonomicNode * tree=factory->tree(names);
    string * tn= toItol(tree);
    delete names;
    delete tree;
    delete factory;
    SEXP itolString=Rcpp::wrap(*tn);
    delete tn;
    
    return itolString;
}

SEXP convertToNewick(SEXP hmptNames){
    
    vector<vector<string*>*>* names=toNames(hmptNames);
    TaxonomicNodeFactory *factory=new TaxonomicNodeFactory();
    TaxonomicNode * tree=factory->tree(names);
    string * tn= toNewick(tree);
    *tn+=";";
    delete names;
    delete tree;
    delete factory;
    SEXP newickString=Rcpp::wrap(*tn);
    delete tn;
    
    return newickString;
}
