/*
 * PDParamContainer.h
 *
 *  Created on: May 5, 2013
 *      Author: bfoley
 */

#ifndef PDPARAMCONTAINER_H_
#define PDPARAMCONTAINER_H_

class PDParamContainer
{
public:
	PDParamContainer();
	virtual ~PDParamContainer();

	float FPDarktime;
	int FPRepeatTimes;
	float FPDutyCycle[9];
	float FPGateTime[9];

	int fillParams();
	int writeParams();
	int getSize();

private:
};


#endif /* PDPARAMCONTAINER_H_ */
