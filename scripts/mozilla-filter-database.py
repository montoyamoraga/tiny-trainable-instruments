import csv
import os
import random

print(os.getcwd())

wantedWords = ["cero", "uno", "dos"]
wantedWordsCounter = [0, 0, 0]

with open('./dev.tsv','r') as tsvin:
    for line in csv.reader(tsvin, delimiter='\t'):
      for i in range(0, len(wantedWords)):
        if (line[2] == wantedWords[i]):
          wantedWordsCounter[i] += 1
          # print(line[2])
        #   print(os.getcwd() + "/clips/" + line[1])
          dirCurrent = os.getcwd() + "/clips/" + line[1]
          dirNew = os.getcwd() + "/selection/" + wantedWords[i] + "_" + str(random.randrange(1000000)) + ".mp3"
        #   print(dirNew)
          os.rename(dirCurrent, dirNew)

print(wantedWordsCounter)
