#!/usr/bin/python
from matplotlib import pyplot as plt
import numpy as np
import linecache

def read_datafile(file_name):
    # the skiprows keyword is for heading, but I don't know if trailing lines
    # can be specified
    data = np.genfromtxt(file_name, delimiter=',', skip_header=1, names=['x', 'y'])
    return data

#Plotting to our canvas


files = ["reversed","shuffle","normal"]
dirs = ["Bubble", "Comb", "Insertion"]
for sorts in dirs:
    for tipo in files:
        entrada = "./Saidas/" + sorts + "/" + "saida_" + tipo + ".csv"
        data = read_datafile(entrada)
        print "Amaral mto foda"

        tmp = linecache.getline(entrada, 1)

        plt.plot(data['x'], data['y'])
        plt.title(tmp)
        plt.ylabel('Tempo (s)')
        plt.xlabel('Tamanho da entrada')

        saida = "grafico" + str(i) + ".png"
        plt.savefig(saida)

        plt.close()
