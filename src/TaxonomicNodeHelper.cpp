//
//  TaxonomicNodeHelper.cpp
//  RcppStudy
//
//  Created by Alexander Tuzhikov on 10/3/14.
//  Copyright (c) 2014 Alexander Tuzhikov. All rights reserved.
//

#include "TaxonomicNodeHelper.h"

string* toNewick(TaxonomicNode *rootNode){
    
    string lbrack="(";
    string rbrack=")";
    
    string* newick=new string();
    *newick+=*rootNode->getName();
    if(rootNode->getChildren()->size()>0){
        newick->insert(0,lbrack);
        int i=0;
        for(TaxonomicNode* child:*rootNode->getChildren()){
            string *childrenResponce=toNewick(child);
            if(i<rootNode->getChildren()->size()-1){
                *childrenResponce+=",";
                i++;
            }
            newick->insert(newick->length()-rootNode->getName()->length(),*childrenResponce);
            delete childrenResponce;
            
        }
        newick->insert(newick->length()-rootNode->getName()->length(),rbrack);
    }
    return newick;
}

string* toItol(TaxonomicNode *rootNode){
  
  string sep="|";
  
  string* itol=new string();
  if(rootNode->getChildren()->size()>0){
    
    for(TaxonomicNode* child:*rootNode->getChildren()){
      *itol+=*child->getName();
      *itol+="|";
    }
    *itol=itol->substr(0,itol->length()-1);
    *itol+="\t";
    *itol+=*rootNode->getName();
    *itol+="\n";
    for(TaxonomicNode* child:*rootNode->getChildren()){
      *itol+=*toItol(child);
    }
  }
  return itol;
}