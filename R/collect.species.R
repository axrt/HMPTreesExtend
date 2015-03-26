collect.species<-function(sys.command,files){
  species.set<-c()
  for (s in files){
    df<-find.species(sys.command,s)
    species.set<-get.full.species.set(df,species.set)
  }
  df<-data.frame(row.names = species.set)
  for (s in files){
    sample.species<-find.species(sys.command,s)
    absent<-setdiff(y=rownames(sample.species),x = rownames(df))
    absent.df<-data.frame(row.names = absent,rep(x = 0,times = length(absent)))
    colnames(absent.df)<-c("V2")
    n.df<-rbind(sample.species,absent.df)
    df<-cbind(df,n.df[rownames(df),])
  }
  colnames(df)<-files
  return(df[order(rownames(df)),])
}

find.species<-function(sys.command,file){
  text.representation<-system(command = paste(sys.command,file,sep = " "),intern = TRUE)
  tc<-textConnection(text.representation)
  tbl<-read.table(tc,header = FALSE,sep = "\t",row.names = 1)
  close(con = tc)
  return(tbl)
}

get.full.species.set<-function(df,c){
  c<-union(c,rownames(df))
  return(c)
}