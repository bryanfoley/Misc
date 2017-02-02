//============================================================================
// Name        : segmentedSieveOfEratosthenes.cpp
// Author      : Bryan Foley
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <time.h>
#include <chrono>
using namespace std;

// This functions finds all primes smaller than 'limit'
// using simple sieve of eratosthenes. It also stores
// found primes in vector prime[]

template < class T >
void printVector(vector< T > &vectorRef);
void calcExecutionTime(time_t startTime,time_t endTime);
void simpleSieve(long limit, vector<long> &prime, long n);
void segmentedSieve(long n);

int main()
{
	time_t start, end;
    long n;
    cin >> n;
    cout << "The " << n << "th prime:\n";
    time(&start);
    segmentedSieve(n);
    time(&end);
    calcExecutionTime(start,end);
    return 0;
}

void simpleSieve(long limit, vector<int> &prime, long n)
{
    bool mark[limit];
    memset(mark, true, sizeof(mark));

    for (long p=2; p*p<limit; p++)
    {
        if (mark[p] == true)
        {
            for (long i=p*2; i<limit; i+=p)
                mark[i] = false;
        }
    }

    for (long p=2; p<limit; p++)
    {
        if (mark[p] == true && prime.size() <n)
        {
            prime.push_back(p);
        }
    }
}

void segmentedSieve(long n)
{
    long limit = 8000000;
    vector<int> prime;
    simpleSieve(limit,prime,n);

    long low  = limit;
    long high = low+limit;

    while (prime.size() < n)
    {
        if (prime.size()==n){
        	break;
        }
        bool mark[limit];
        memset(mark, true, sizeof(mark));

        for (long i = 0; i < prime.size(); i++)
        {
            long loLim = floor(low/prime[i]) * prime[i];
            if (loLim < low)
                loLim += prime[i];

            for (long j=loLim; j<high; j+=prime[i])
                mark[j-low] = false;
        }

        for (long i = low; i<high; i++){
            if (mark[i - low] == true){
                prime.push_back(i);
            	if (prime.size()==n){
            		break;
            	}
            }
        }

        low  = low + limit;
        high = high + limit;
    }
    vector<int>::iterator it = prime.end();
    --it;
    cout << *it <<endl;
}

template < class T >
void printVector(vector< T > &vectorRef){
	if(vectorRef.empty()){
		cout << "Vector is empty";
	}
	else{
		vector < long >::iterator iter = vectorRef.begin();
		while (iter!=vectorRef.end()){
			cout << *iter << " ";
			iter++;
		}
		cout << endl;
	}
}

void calcExecutionTime(time_t startTime,time_t endTime){
	//Calculate the time to run the loop
	double diff = difftime(endTime,startTime);
	cout << "It has taken " << diff << " seconds to run the main loop." << endl;
}
