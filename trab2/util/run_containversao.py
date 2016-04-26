#!/usr/bin/python
import subprocess, os, sys
 
size = [10,20,40,80,100,200,400,800,1600,3200,6400,12800,25600,51200,102400,204800,409600,819200,1638400,3276800]
tab = ["Reversed","Shuffle","Normal"]
 
if not os.path.isdir("./io/saidas/" + "Conta_inversao" + "/"):
    os.makedirs("./io/saidas/" + "Conta_inversao" + "/")
 
for y in tab:
    saida = "./io/saidas/Conta_inversao/" + "saida_" + y.lower + ".csv"
    fp=open(saida, "w+")
    for z in size:
        # entrada = "Entradas/ent_" + y + "_" + str(z) + ".txt"
        inpath = "./io/entradas/" + y + "/"
        infile_name = inpath + str(z) + "_" + y.lower + ".txt"
        cmd = " ./bin/" + mode.lower() + ".out < " + infile_name
        p = subprocess.Popen(cmd,stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
        line = ""
        for aux in iter(p.stdout.readline, b''):
            line = str(aux.rstrip())
            break
        aux = line.split("'")
        print(aux[1], file=fp)