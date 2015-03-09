extract.rank<-function(df,rank=6,sep="."){
  
  select.drv<-strsplit(x = row.names(df),split = sep,fixed = TRUE,useBytes = FALSE)
  select.drv<-sapply(1:length(select.drv),function(x){
    if(length(select.drv[[x]])==rank){
      return(TRUE)
    }else{
      return(FALSE)
    }
  })
  return(df[select.drv,,FALSE])
}

extract.rank.name<-function(df,sep="."){
  rownams.split<-strsplit(x=row.names(df),split = sep,fixed = TRUE,useBytes = FALSE)
  new.rownams<-sapply(1:length(rownams.split),function(x){
    return(rownams.split[[x]][length(rownams.split[[x]])])
  })
  row.names(df)<-new.rownams
  return(df)
}

extract.mle.cutoff<-function(df,cutoff=0.01){
  return(df[df[,1]>=cutoff,,FALSE])
}