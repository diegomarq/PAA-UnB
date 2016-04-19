#!/usr/bin/python
import subprocess
import time
import os
import sys

def escreva(outfile_name,sum=None,num=None,mode=None,tipo=None):
	with open(outfile_name,"a") as f:
		if not num == None:
			print "Escrevendo: " + outfile_name
			if not sum == None:
				duracao = "{0:.7f}".format(sum)
				print "Time:" + duracao
			else:
				duracao = "estimar"
			f.write(str(num) + "," + duracao)
			f.write("\n")
		else:
			f.write(mode + " " + tipo)
			f.write("\n")

if (len(sys.argv) > 2):
	sort = ["Bubble","Comb","Insertion"]
	files = ["Reversed","Shuffle","Normal"]
	archives = 20
	timeout = int(sys.argv[1]);
	times = int(sys.argv[2])
	sum = float(0)
	for mode in sort:
		print "Rodando para o algoritmo " + mode
		outpath = "./Saidas/" + mode + "/"
		if not os.path.isdir(outpath):
			print "Caminho: " + outpath + "\nNao existe e sera criado"
			os.makedirs(outpath)
		for type in files:
			inpath = "./Entradas/" + type + "/"
			outfile_name = outpath + "saida_" + type.lower() + ".csv";
			estoura = False
			escreva(outfile_name,None,None,mode,type)
			num = 10
			for i in range(0,archives):
				if(estoura):
					print "Nao precisa fazer " + str(num) + " pois sera maior que o timeout"
					escreva(outfile_name,None,num,None,None)
					num*=2
					continue
				sum = float(0)
				infile_name = inpath + str(num) + "_" + type.lower() + ".txt"
				cmd = " ./bin/" + mode.lower() + ".out <" + infile_name
				print "Running: " + cmd
				for j in range(0,times):
					print "times " + str(j);		
					process = subprocess.Popen(cmd,shell=True, stdout=subprocess.PIPE)
					process.wait()
					tempo = float(process.stdout.read())
					if(tempo >= timeout):
						estoura = True
						print "Nao precisa fazer " + str(num) + " pois sera maior que o timeout"
						escreva(outfile_name,None,num,None,None)
						break
					sum += tempo
					time.sleep(1)
				if(not estoura):
					sum/=times
					escreva(outfile_name,sum,num,None,None)
				num*=2
				if(i == 3):
					num = 100
			sum = float(0)
else:
	print "Usage: ./script <timout> <times>"
