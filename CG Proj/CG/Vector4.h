#pragma once
#include "vector3.h"
class Vector4 :
	public Vector3
{

protected:
	double _w;

public:
	Vector4();
	Vector4(double x, double y, double z, double w);
	~Vector4();
	double getW();
	void set(double x, double y, double z, double w);
	Vector4 operator=(const Vector4& vec);
	Vector4 operator*(double num);
	Vector4 operator+(const Vector4& vec);
	Vector4 operator-(const Vector4& vec);
};

