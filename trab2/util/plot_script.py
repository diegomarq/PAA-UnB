#!/usr/bin/python
from matplotlib import pyplot as plt
import numpy as np
import linecache
import os

def read_datafile(file_name):
    # the skiprows keyword is for heading, but I don't know if trailing lines
    # can be specified
    data = np.genfromtxt(file_name, delimiter=',', skip_header=1, names=['x', 'y'])
    return data

#Plotting to our canvas

files = ["Normal","Reversed","Shuffle"]
dirs = ["Bubble","Comb","Insertion","Merge","Merge_insert4","Merge_insert8","Merge_insert32","Merge_insert64","Selection","Shell"]
for sorts in dirs:
    for tipo in files:
        entrada = "./io/saidas/" + tipo + "/" + sorts + "/" + "saida_" + tipo.lower() + ".csv"
        outpath = "./io/graficos/" + sorts + "/";
        if not os.path.isdir(outpath):
        	print "Caminho: " + outpath + "\nNao existe e sera criado"
        	os.makedirs(outpath)
        data = read_datafile(entrada)

        tmp = linecache.getline(entrada, 1)
        tmp = tmp[0:len(tmp)-1]
        tmp = sorts + " " + tipo

        plt.title(tmp)
        plt.plot(data['x'], data['y'],"-sr")
        plt.ylabel('Tempo (s)')
        plt.xlabel('Tamanho da entrada')

        saida = "grafico" + sorts + "_" + tipo + ".png"
        plt.savefig(outpath+saida)

        plt.close()
