#pragma once
#include <math.h>

class coordinates
{
public:
	static float toCoordinate(float val, bool axis);
	static float linearFunction(float x, float a, float b);
	static float addTillMatchEdge(float &val, float end);
	static float pythagorasSide(float hypotenuse, float sideB);
	static float pythagorasHyp(float sideA, float sideB);
	static const float SYSTEM_LENGHT;
	static const float CENT_LENGHT;
};

