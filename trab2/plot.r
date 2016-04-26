library(ggplot2)

algorithm = c("Bubble","Comb","Insertion","Merge","Merge_insert4","Merge_insert8","Merge_insert32","Merge_insert64","Selection","Shell")
tab = c("Reversed")

basepath = "/home/diego/Dropbox/UnB/1_2016/PAA/PAA-UnB/trab2/io/saidas/"

name = c()
inversoes = c()
tempo = c()
for(b in tab) {
  
  # inputfile = paste(inputpath, "saida","_", tolower(b), ".csv", sep = "")
  inputfile = paste(basepath, "Conta_Inversao", "/", "saida_reversed.csv", sep = "")
  datafile = read.table(inputfile, sep = ",", header = T)
  
  for(a in algorithm) {
    
    inputinsert = paste(basepath, a, "/", "saida_reversed.csv", sep = "")
    datasort = read.csv(inputinsert, sep = ",")
    #datafile = cbind(datafile, datasort)
    for(d in 1:20){
      inversoes = c(inversoes, datafile[d,1])
      name = c(name, a)
      tempo = c(tempo, datasort[d,ncol(datasort)])
    }
    
  }
}
res = data.frame(inversoes,tempo,name)
  
ggplot(res, aes(x=inversoes, y=log(tempo)/log(2),group=name)) +
  geom_line(aes(linetype=name, color = name)) +
  geom_point(aes(color=name))+
  labs(x="Número de inversões", y = "log2(tempo(s))")+
  ggtitle("log2(tempo(s)) x número de inversões")

ggplot(res, aes(x=inversoes, y=tempo,group=name)) +
  geom_line(aes(linetype=name, color = name)) +
  geom_point(aes(color=name))+
  labs(x="Número de inversões", y = "tempo(s)")+
  ggtitle("tempo(s) x número de inversões")
