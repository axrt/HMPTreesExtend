as.newick <- function(df,sep="."){
  
  if(!class(df)=="data.frame"){
    stop("Dataframe expected with \"df\"!");
  }
  
  tree.rows<-row.names(df)
  tax.list<-strsplit(x = tree.rows,split = sep,fixed = TRUE,perl = TRUE,useBytes = FALSE)
  
  .Call( "convertToNewick",tax.list)
}