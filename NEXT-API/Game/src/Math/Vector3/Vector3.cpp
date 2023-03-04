#include "stdafx.h"
#include "Vector3.h"

const Vector3 Vector3::Zero = Vector3(0, 0, 0);
const Vector3 Vector3::One = Vector3(1, 1, 1);
const Vector3 Vector3::Up = Vector3(0, 1, 0);
const Vector3 Vector3::Down = Vector3(0, -1, 0);
const Vector3 Vector3::Left = Vector3(-1, 0, 0);
const Vector3 Vector3::Right = Vector3(1, 0, 0);
const Vector3 Vector3::Forward = Vector3(0, 0, 1);
const Vector3 Vector3::Back = Vector3(0, 0, -1);

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
	Vector3 v;
	if (this->SqrMagnitude() > 0)
	{
		v = *this / this->Magnitude();
	}
	return v;
}

float Vector3::Magnitude() const
{
	return sqrtf(x * x + y * y + z * z);
}

float Vector3::SqrMagnitude() const
{
	return x * x + y * y + z * z;
}

float Vector3::Dot(const Vector3& other) const
{
	return x * other.x + y * other.y + z * other.z;
}

Vector3 Vector3::Cross(const Vector3& other) const
{
	return Vector3(y * other.z - other.y * z, z * other.x - other.z * x, x * other.y - other.x * y);
}

std::string Vector3::ToString()
{
	return "(" + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + ")";
}

float Vector3::Distance(Vector3 from, Vector3 to)
{
	float x = (from.x - to.x) * (from.x - to.x);
	float y = (from.y - to.y) * (from.y - to.y);
	float z = (from.z - to.z) * (from.z - to.z);
	return sqrtf(x + y + z);
	// return (from - to).Magnitude(); // Gets the same result but I don't want to rely on Magnitude().
}
