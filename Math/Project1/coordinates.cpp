#include "coordinates.h"

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
