import matplotlib.pyplot as plt
import numpy

class statisticsResult:
    data = []
    probabilities = []
    probables = []

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

    def execute(self):
        self.flattenData()
        self.calcProbabilities()
        self.calcProbables()
        self.printResults()
        self.plotHistogram()
		
    def __init__(self, numbers, parameters):
        print 'Histogram Object initialised'
        self.params = parameters
        self.data = numbers
        self.bins = numpy.linspace(self.params.lower_bound+1,self.params.upper_bound,self.params.upper_bound)
        self.execute()