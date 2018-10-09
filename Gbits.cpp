// File created: 2018-09-12

#include "gbits.h"

Gbits::Gbits(int bitCount) {
	init(bitCount, 0);
}

Gbits::Gbits(int bitCount, unsigned long  value) {
	init(bitCount, value);
}

void Gbits::init(int bitCount, unsigned long  value) {
	_bitCount = bitCount;
	setValue(value);
}

unsigned long Gbits::getValue() {
	return _value;
}

void Gbits::setValue(unsigned long  value) {
	_value = value;
}
String Gbits::header(bool eightIndexNumbers, bool bitIndexNumber, bool bitIndexTenNumber) {
	int 	num, x;

	String 	str = "", 
			eightPos = "",
			posNumbers = "",
			tenTenNumbers = "";
	
	for (int i = 0; i < _bitCount; i++){
		if (i % 8 == 0) {
			str+=' ';
			if (eightIndexNumbers) eightPos+=' ';
			if (bitIndexNumber)    posNumbers+=' ';
			if (bitIndexTenNumber) tenTenNumbers+=' ';
		}
		num = _bitCount-1-i;

		if (eightIndexNumbers) {
			eightPos+=(char)(48 + (num % 8));
		}
		if (bitIndexNumber) {
			posNumbers+=(char)(48 + (num % 10));
		}
		if (bitIndexTenNumber) {
			x = (num / 10) % 10;
			if (x == 0 ) tenTenNumbers+= ' ';
			else tenTenNumbers+= (char)(48 + x);
		}
		str+='-';
	}
	if (eightIndexNumbers) str = eightPos      + '\n' + str;
	if (bitIndexNumber)	   str = posNumbers    + '\n' + str;
	if (bitIndexTenNumber) str = tenTenNumbers + '\n' + str;
	return str;

}
String Gbits::valueToBitString(unsigned long value, int bitCount,bool includeDecimal) {
	String str = "";
	int val;
	for (int i = 0; i < bitCount; i++){
		if (i % 8 == 0)
			str+=' ';
		val = (value >> (bitCount-1 ) - i) & 1;
		if (val == 1)
			str+='1';
		else
			str+='0';
	}
	if (includeDecimal)
		str+="   |   " + String(value);
	return str;

}
String Gbits::valueToBitString(bool includeDecimal) {
	return valueToBitString(_value, _bitCount, includeDecimal);
}
