#include "stdafx.h"
#include "Vector3.h"

Vector3::Vector3() : x(0.0f), y(0.0f), z(0.0f)
{
}

Vector3::Vector3(float inX, float inY, float inZ) : x(inX), y(inY), z(inZ)
{
}

Vector3 Vector3::operator+(const Vector3& other) const
{
	return Vector3(this->x + other.x, this->y + other.y, this->z + other.z);
}

Vector3& Vector3::operator+=(const Vector3& other)
{
	x += other.x;
	y += other.y;
	z += other.z;
	return *this;
}

Vector3 Vector3::operator-(const Vector3& other) const
{
	return Vector3(this->x - other.x, this->y - other.y, this->z - other.z);
}

Vector3& Vector3::operator-=(const Vector3& other)
{
	x -= other.x;
	y -= other.y;
	z -= other.z;
	return *this;
}

Vector3 Vector3::operator*(float scalar) const
{
	return Vector3(this->x * scalar, this->y * scalar, this->z * scalar);
}

Vector3 Vector3::operator*=(float scalar)
{
	x *= scalar;
	y *= scalar;
	z *= scalar;
	return *this;
}

Vector3 Vector3::operator/(float scalar) const
{
	return Vector3(this->x / scalar, this->y / scalar, this->z / scalar);
}

Vector3 Vector3::operator/=(float scalar)
{
	x /= scalar;
	y /= scalar;
	z /= scalar;
	return *this;
}

bool Vector3::operator==(const Vector3& other) const
{
	return x == other.x && y == other.y && z == other.z;
}

bool Vector3::operator!=(const Vector3& other) const // ***
{
	return x != other.x || y != other.y || z != other.z;
}

Vector3 Vector3::Normalize() const
{
	return Vector3();
}

float Vector3::Magnitude() const
{
	return 0.0f;
}

float Vector3::SqrMagnitude() const
{
	return 0.0f;
}

float Vector3::Dot(const Vector3& other) const
{
	return 0.0f;
}

Vector3 Vector3::Cross(const Vector3& other) const
{
	return Vector3();
}

std::string Vector3::ToString()
{
	return std::string();
}
