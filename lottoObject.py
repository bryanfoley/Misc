import numpy

class lottoResult:

    results = []
    differentials = []
    variance = 0.0
    mean = 0.0
    average = 0.0
    std_dev = 0.0
    date = ''

    def calcVariance(self):
        self.variance = numpy.var(self.results)

    def calcMean(self):
        self.mean = numpy.mean(self.results)

    def calcStdDev(self):
        self.std_dev = numpy.std(self.results)
    
    def calcAverage(self):
        self.average = numpy.average(self.results)

    def calcDifferentials(self):
        pass

    def getAnalysis(self):
        print''
        print 'Date of Draw: %s'%self.date
        print 'Variance: %f'%self.variance
        print 'Mean: %f'%self.mean
        print 'Std: %f'%self.std_dev
        print 'Std: %f'%self.average
        print ''		

    def execute(self):
        self.calcVariance()
        self.calcMean()
        self.calcStdDev()
        self.calcAverage()
        self.calcDifferentials()
		
    def __init__(self,numbers,date):
        self.results = numbers
        self.date = date
        self.execute()