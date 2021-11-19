#include "coordinates.h"

const float coordinates::SYSTEM_LENGHT = 400.0f;
const float coordinates::CENT_LENGHT = 40.0f;

float coordinates::toCoordinate(float val, bool axis) //true if x axis, false if y axis
{
	if (axis) {
		if (val == 0)
			return 5.0f;
		else
			return 5.0f + val;
	}
	else {
		if (val == 0)
			return 5.0f;
		else
			return 5.0f - val;
	}
}

float coordinates::linearFunction(float x, float a, float b)
{
	return a * x + b;
}
