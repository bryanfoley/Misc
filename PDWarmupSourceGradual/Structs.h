/*
 * Structs.h
 *
 *  Created on: Apr 30, 2013
 *      Author: bfoley
 */

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <ctime>

#ifndef STRUCTS_H_
#define STRUCTS_H_

struct DutyCycle {
    double A;
    double B;
    double C;
};

struct GateTime {
    double A;
    double B;
    double C;
};

/*struct fpc {
	float FPCMaxDarktime;
	int FPCMaxRepeatTimes;
	float FPCMaxDutyCycle;
	float FPCMaxGateTime;
};*/


#endif /* STRUCTS_H_ */
