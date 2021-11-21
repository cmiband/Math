#pragma once
#include <math.h>

class coordinates
{
public:
	static float toCoordinate(float val, bool axis);
	static float linearFunction(float x, float a, float b);
	static float reverseLinearFunction(float y, float a, float b);
	static const float SYSTEM_LENGHT;
	static const float CENT_LENGHT;
};

