import matplotlib.pyplot as plt
import numpy, random

class statisticsResult:
    data = []
    probabilities = []
    probables = []
    lotto = []

    def flattenData(self):
        self.data = sum(self.data,[])

    def calcProbabilities(self):
        for number in range(self.params.lower_bound+1,self.params.upper_bound):
            temp = self.data.count(number)
            temp = temp/float((self.params.upper_bound-1))
            self.probabilities.append(temp)

    def calcProbables(self):
        self.probables = numpy.argsort(self.probabilities)[::-1][:6]
        self.probables = [x+1 for x in self.probables]

    def getProbables(self):
        return self.probables

    def getProbabilities(self):
        return self.probabilities

    def getData(self):
        return self.data

    def getLotto(self):
        return lotto

    def generateCustomRandom(self):
        print 'Using a custom metric'
        num = round((self.finals.std_dev)*(random.uniform(self.params.lower_bound+1,self.params.upper_bound-1)))
        return num

    def generateUniformRandom(self):
        print 'Using a Uniform metric'        
        num = round(random.uniform(self.params.lower_bound+1,self.params.upper_bound-1))
        return num
		
    def generateGaussianRandom(self):
        print 'Using a Gaussian metric'
        num = round(random.gauss(self.finals.mean,self.finals.std_dev))
        return num

    def generateAnyNumbers(self):
        numbers = []
        complete = False
        while not complete:
            num = self.generateUniformRandom()
            if num < self.params.upper_bound and num not in numbers:
                numbers.append(num)
            if len(numbers) == self.params.numbers_per_line:
                complete = True
        return numbers, numpy.var(numbers), numpy.mean(numbers), numpy.std(numbers)
	
    def generateExactNumbers(self):
        satisfied = False
        while not satisfied:
            line,var,mean,std = self.generateAnyNumbers()
            if (var <= self.params.fudge_factor*self.finals.variance) and (std <= self.params.fudge_factor*self.finals.std_dev):
                self.lotto.append(line)
            if len(self.lotto) == self.params.lines_per_play:
                satisfied = True

    def plotHistogram(self):
        plt.hist(self.data,self.bins)
        plt.title('Frequency of numbers from the past %d Lotto results'%self.params.number_of_records)
        plt.xlabel('Number')
        plt.ylabel('Frequency')
        plt.show()

    def printResults(self):
        print '------------------'
        print '------------------'
        print 'The most Frequent Lotto numbers are: '
        print '%s'%self.probables
        print '------------------'
        print '------------------'
		
    def printLotto(self):
        print '------------------'
        print '------------------'
        print 'The following numbers are predicted to yield'
        for item in self.lotto:
            print item
        print '------------------'
        print '------------------'

    def execute(self):
        self.flattenData()
        self.calcProbabilities()
        self.calcProbables()
        self.printResults()
        self.generateExactNumbers()
        self.printLotto()
		
    def __init__(self, numbers, parameters, finals):
        print 'Histogram Object initialised'
        self.params = parameters
        self.data = numbers
        self.finals = finals
        self.bins = numpy.linspace(self.params.lower_bound+1,self.params.upper_bound,self.params.upper_bound)
        self.execute()