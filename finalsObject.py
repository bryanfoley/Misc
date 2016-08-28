import numpy

class finalResult:

    variance = 0.0
    mean = 0.0
    std_dev = 0.0
    average = 0.0
    differentials = []
    data = []
    num_of_records = 0

    def appendValues(self):
        self.finalVariance = []
    	self.finalMean = []
    	self.finalStd_dev = []
    	self.finalAverage = []
    	for result in self.data:
    		self.finalVariance.append(result.variance)
    		self.finalMean.append(result.mean)
    		self.finalStd_dev.append(result.std_dev)
    		self.finalAverage.append(result.average)
	
    def calculateFinals(self):
    	self.variance = numpy.var(self.finalVariance)
    	self.mean = numpy.mean(self.finalMean)
    	self.std_dev = numpy.var(self.finalStd_dev)
    	self.average = numpy.average(self.finalAverage)

    def printResults(self):
        print '------------------'
        print '------------------'
        print 'Variance: %f'%self.variance
        print '------------------'
        print 'Mean: %f'%self.mean
        print '------------------'
        print 'Std: %f'%self.std_dev
        print '------------------'
        print 'Average: %f'%self.average
        print '------------------'
        print 'Num of Records: %d'%self.num_of_records
        print '------------------'
        print '------------------'
		
    def execute(self):
        self.appendValues()
        self.calculateFinals()
        self.printResults()
	
    def __init__(self, array):
    	self.data = array
        self.num_of_records = len(self.data)
    	self.execute()