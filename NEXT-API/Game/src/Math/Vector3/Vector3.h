#pragma once
#include <string>

/// <summary>
/// A Vector in 3D space composed of components (x, y, z)
/// </summary>
struct Vector3
{

	float x;
	float y;
	float z;

	float w; // homogeneous vertex coordinate

	Vector3();

	Vector3(float x, float y, float z);

	// Operations
	Vector3 operator+(const Vector3 &other) const;
	Vector3 &operator+=(const Vector3 &other);
	Vector3 operator -(const Vector3 &other) const;
	Vector3 &operator -=(const Vector3 &other);
	Vector3 operator*(float scalar) const;
	Vector3 operator *=(float scalar);
	Vector3 operator/(float scalar) const;
	Vector3 operator/=(float scalar);
	bool operator ==(const Vector3 &other) const;
	bool operator !=(const Vector3 &other) const;

	// ToDo: Create a Vector3.Util to seperate these and expand (Clamp, Rotate, ToEuler, etc).

	/// <summary>
	/// Normalize vector. Keep direction but it's length is 1.0
	/// </summary>
	/// <returns>Your vector with a magnitude of 1</returns>
	Vector3 Normalize() const;

	/// <summary>
	/// Returns the length of this vector
	/// </summary>
	float Magnitude() const;

	/// <summary>
	/// Returns the squared length of this vector.
	/// </summary>
	float SqrMagnitude() const;

	/// <summary>
	/// Returns the dot product (float value equal to the magnitudes of the vectors 
	/// multiplied together and then multiplied by the cosine of the angle between them).
	/// </summary>
	float Dot(const Vector3 &other) const;

	Vector3 Cross(const Vector3& other) const;

	std::string ToString();



};

