import os, sys, time, numpy, random
import re
from lottoObject import lottoResult
from finalsObject import finalResult
from paramObject import paramHandler
from statisticsObject import statisticsResult

xmlData = open('lottoresults.xml')
archiveData = open('lottoArchive.txt')
regex_numbers_xml = re.compile(r'<Number>[0-9]*-')
regex_date_xml = re.compile(r'<DrawDate>[0-9]*-[0-9]*-[0-9]*')
regex_numbers_archive = re.compile(r'[0-9]*-')

def get_num(x):
    return int(''.join(ele for ele in x if ele.isdigit()))

def get_date(x):
    date = time.strptime(x,"%Y-%m-%d")
    return date

def getLottoNumbersFromArchive():
    results_array = []
    temp_results = []
    for line in archiveData:
        temp_results = regex_numbers_archive.findall(line)
        temp_results = [i.rstrip('-') for i in temp_results]
        temp_results = [int(i) for i in temp_results]
        results_array.append(temp_results)
    if params.number_of_records == None:
        params.number_of_records = len(results_array)
    else:
        del results_array[params.number_of_records:]
    return results_array

def getLottoNumbersFromXML():
    results_array = []
    counter = 1
    temp_results =[]
    for line in xmlData:
        lotto_numbers = regex_numbers_xml.findall(line)
        for number in lotto_numbers:
            counter+=1
            number = get_num(number)
            temp_results.append(number)
            if counter%(params.numbers_per_line + 1) == 0:
                results_array.append(temp_results)
                temp_results =[]
                counter = 0
    del results_array[params.number_of_records:]
    return results_array
	
def getArrayOfObjects(results_history):	
    array_of_objects = []
    for item in results_history:
        x = lottoResult(item,'NoDate')
        array_of_objects.append(x)
    return array_of_objects
	
def getResults(array_of_objects):
    for result in array_of_objects:
        result.getAnalysis()
		
def calculateFinals(array_of_objects):
    finals = finalResult(array_of_objects)
    return finals

def generateStatistics():
    plots = statisticsResult(numbers_history,params,finalsObject)


if __name__ == '__main__':
    params = paramHandler()
    numbers_history = getLottoNumbersFromArchive()
    lottoObjects = getArrayOfObjects(numbers_history)
    finalsObject = calculateFinals(lottoObjects)
    generateStatistics()
	