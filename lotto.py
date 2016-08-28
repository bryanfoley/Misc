import os, sys, time, numpy, random
import re
from lottoObject import lottoResult
from finalsObject import finalResult
from paramObject import paramHandler

data = open('lottoresults.xml')
regex_numbers = re.compile(r'<Number>[0-9]*')
regex_date = re.compile(r'<DrawDate>[0-9]*-[0-9]*-[0-9]*')

def get_num(x):
    return int(''.join(ele for ele in x if ele.isdigit()))

def get_date(x):
    date = time.strptime(x,"%Y-%m-%d")
    return date

def getLottoNumbers():
    results_array = []
    counter = 1
    temp_results =[]
    for line in data:
        lotto_numbers = regex_numbers.findall(line)
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
	
# def getLottoDates():
    # results_array = []
    # for line in data:
        # lotto_dates = regex_date.findall(line)
        # for date in lotto_dates:
            # date = get_date(date)
            # print date
            # results_array.append(date)
    # return results_array
	
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
	
def generateAnyNumbers():
    numbers = []
    complete = False
    while not complete:
        num = round((finals.std_dev)*(random.uniform(params.lower_bound,params.upper_bound)))
        if num < params.upper_bound and num not in numbers:
            numbers.append(num)
        if len(numbers) == params.numbers_per_line:
            complete = True
    return numbers, numpy.var(numbers), numpy.mean(numbers), numpy.std(numbers)

	
def generateExactNumbers():
    lotto = []
    satisfied = False
    while not satisfied:
        line,var,mean,std = generateAnyNumbers()
        if (var <= params.fudge_factor*finals.variance) and (std <= params.fudge_factor*finals.std_dev):
            lotto.append(line)
        if len(lotto) == params.lines_per_play:
            satisfied = True
    return lotto			
	

if __name__ == '__main__':
    params = paramHandler()
    numbers_history = getLottoNumbers()
    # dates_history = getLottoDates()
    array_of_objects = getArrayOfObjects(numbers_history)
    # getResults(array_of_objects)
    finals = calculateFinals(array_of_objects)
    lotto = generateExactNumbers()
    print lotto
	