#!/usr/bin/python
import subprocess
import os
#Shuffle
files = [("Reversed","2"),("Shuffle","3"),("Normal","1")]
for type in files:
	num = 10
	archives = 20
	for i in range(0,archives):
		outpath = "./Entradas/" + type[0] + "/";
		if not os.path.isdir(outpath):
			print "Caminho: " + outpath + "\nNao existe e sera criado"
			os.makedirs(outpath)
		cmd = "./maker.out " + str(num) + " " + type[1]  + " > " + outpath  + str(num) + "_" + type[0].lower() + ".txt"
		print "Running : " + cmd
		process = subprocess.Popen(cmd,shell=True, stdout=subprocess.PIPE)
		process.wait()
		num*=2
		if(i == 3):
			num = 100
