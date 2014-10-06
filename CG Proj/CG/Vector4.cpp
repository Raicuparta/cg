#include "Vector4.h"


Vector4::Vector4() {
	Vector4(0, 0, 0, 0);
}	


Vector4::Vector4(double x, double y, double z, double w) : Vector3(x, y, z) {
	_w = w;
}

Vector4::~Vector4() {
}


double Vector4::getW()  {
	return _w;
}

void Vector4::set(double x, double y, double z, double w) {
	Vector3::set(x, y, z);
	_w = w;
}

Vector4 Vector4::operator=(const Vector4 &vec) {
	_x = vec._x;
	_y = vec._y;
	_z = vec._z;
	return *this;
}

Vector4 Vector4::operator*(double num) {
	double newW = _w*num;

	Vector3 v3 = Vector3::operator*(num);

	return Vector4(v3.getX(), v3.getY(), v3.getZ(), newW);

}

Vector4 Vector4::operator+(const Vector4& vec) {
	double newW = _w + vec._x;

	Vector3 v3 = Vector3::operator+(vec);

	return Vector4(v3.getX(), v3.getY(), v3.getZ(), newW);
}

Vector4 Vector4::operator-(const Vector4& vec) {
	double newW = _w - vec._x;

	Vector3 v3 = Vector3::operator-(vec);

	return Vector4(v3.getX(), v3.getY(), v3.getZ(), newW);
}