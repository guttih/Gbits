// File created: 2018-09-12
#ifndef GBITSH
#define GBITSH

#include <Arduino.h>

class Gbits {
	private:
		unsigned long _value;
		int _bitCount;
		void init(int bitCount, unsigned long value);
	public:
		Gbits(int bitCount);
		Gbits(int bitCount, unsigned long  value);
		unsigned long getValue();
		void setValue(unsigned long  value);
		String header(bool eightIndexNumbers=false, bool bitIndexNumber=true, bool bitIndexTenNumber=true);
		String valueToBitString(unsigned long value, int bitCount,bool includeDecimal);
		String valueToBitString(bool includeDecimal = false);
};

#endif //GBITSH
