/// <summary>
/// Name: Allexis Alvarico
/// Login: C00242855
/// Date: 9th of January
/// --------------------------------------------------------
/// Summary: 
/// The program is to test all vector3 mathematics for use
/// in future labs.
/// ---------------------------------------------------------WS
/// Estinmated time: 5-7 hours
/// Session 1 5:30pm to 7:30pm  9th of January
/// Session 2 10:00am to 11:00am 10th of January 
/// Session 3 5:00pm to 7:30pm 10th of January
/// Session 4 3:00pm to 6:30pm 11th of January 
/// Session 5 5:00pm to 7:00pm 14th of January 
/// Actual time: 9hrs
/// Known Bugs: 
/// </summary> 
#include "MyVector3.h"
#include <string.h>
#define PI 3.14159265358979323846

/// <summary>
/// Default constructor set all 3 values to zero
/// </summary>
MyVector3::MyVector3() :
	x{ 0.0 },
	y{ 0.0 },
	z{ 0.0 }
{
}

/// <summary>
/// default destructor
/// nothing to release because we only have
/// primitive type data
/// </summary>
MyVector3::~MyVector3()
{
}

/// <summary>
/// 
/// </summary>
/// <returns>the vector as a string surrounded by square brackets and separated by commas</returns>
std::string MyVector3::toString()
{
	const std::string output = "[" + std::to_string(x) + "," + std::to_string(y) + "," + std::to_string(z) + "]";
	return output;
}

MyVector3::MyVector3(double t_x, double t_y, double t_z)
{
	x = t_x; // assigns x
	y = t_y; // assigns y
	z = t_z; // assigns z
}

/// <summary>
/// create a vector 3 from an sf::vector3f
/// </summary>
/// <param name="t_sfVector">input vector</param>
MyVector3::MyVector3(sf::Vector3f t_sfVector)
{
	x = static_cast<double>(t_sfVector.x); // double
	y = static_cast<double>(t_sfVector.y); // double
	z = static_cast<double>(t_sfVector.z); // double
}

MyVector3::MyVector3(sf::Vector3i t_sfVector)
{
	x = static_cast<double>(t_sfVector.x); // integer
	y = static_cast<double>(t_sfVector.y); // integer
	z = static_cast<double>(t_sfVector.z); // integer
}

MyVector3::MyVector3(sf::Vector2i t_sfVector)
{
	x = static_cast<double>(t_sfVector.x); // integer
	y = static_cast<double>(t_sfVector.y); // integer
	z = 0;
}

MyVector3::MyVector3(sf::Vector2u t_sfVector)
{
	x = static_cast<double>(t_sfVector.x); // unsigned integer
	y = static_cast<double>(t_sfVector.y); // unsigned integer
	z = 0;
}

MyVector3::MyVector3(sf::Vector2f t_sfVector)
{
	x = static_cast<double>(t_sfVector.x); // double
	y = static_cast<double>(t_sfVector.y); // double
	z = 0;
}

MyVector3 MyVector3::operator+(const MyVector3 t_right) const
{
	sf::Vector3f newVector = {}; // vector's assignments
	newVector.x = x + t_right.x; // x + x
	newVector.y = y + t_right.y; // y + y
	newVector.z = z + t_right.z; // z + z

	return newVector; // returns the answer
}

MyVector3 MyVector3::operator-(const MyVector3 t_right) const
{

	sf::Vector3f newVector{}; // vector's assignments
	newVector.x = x - t_right.x; // x - x
	newVector.y = y - t_right.y; // y - y
	newVector.z = z - t_right.z; // z - z

	return newVector; // returns the answer 
}

MyVector3 MyVector3::operator*(const double t_scalar) const
{

	sf::Vector3f newVector{}; // vector's assignments
	newVector.x = x * t_scalar; // multiply x by the scalar
	newVector.y = y * t_scalar; // multiply y by the scalar 
	newVector.z = z * t_scalar; // multiply z by the scalar

	return newVector; // returns the answer
}

MyVector3 MyVector3::operator/(const double t_divisor) const
{
	sf::Vector3f newVector{}; // vector's assignments
	newVector.x = x / t_divisor; // divide x by the divisor
	newVector.y = y / t_divisor; // divide y by the divisor
	newVector.z = z / t_divisor; // divide z by the divisor

	return newVector; // returns the answer
}

MyVector3 MyVector3::operator+=(const MyVector3 t_right)
{

	x += t_right.x; // adds t_right to x
	y += t_right.y; // adds t_right to y
	z += t_right.z; // adds t_right to z

	return MyVector3{ x,y,z }; // returns the answer 
}

MyVector3 MyVector3::operator-=(const MyVector3 t_right)
{
	x -= t_right.x; // subtracts t_right to x
	y -= t_right.y; // subtracts t_right to y
	z -= t_right.z; // subtracts t_right to z

	return MyVector3{ x,y,z }; // returns the answer 
}

bool MyVector3::operator==(const MyVector3 t_right) const
{
	if (x == t_right.x && y == t_right.y && z == t_right.z) // if true
	{
		return true; // return answer
	}

	return false;
}

bool MyVector3::operator!=(const MyVector3 t_right) const
{
	if (x != t_right.x || y != t_right.y || z != t_right.z) // if one is true
	{
		return false; // return answer
	}

	return true; // return
}

MyVector3 MyVector3::operator-()
{

	x *= -1; // multiply -1
	y *= -1; // multiply -1 
	z *= -1; // multiply -1

	return MyVector3(x, y, z);
}

void MyVector3::reverseX()
{
	x *= -1;  // multiply X by -1
}

void MyVector3::reverseY()
{
	y *= -1;  // multiply Y by -1
}

double MyVector3::length() const
{
	float lenght = (x * x) + (y * y) + (z * z); //gets the lenght
	const float lenghtSqrt = sqrt(lenght); // sqaure roots it
	return lenghtSqrt; // returns it back
}

double MyVector3::lengthSquared() const
{
	float lenghtSquared = (x * x) + (y * y) + (z * z);//gets the lenght's square root
	return lenghtSquared; //returns it back
}

double MyVector3::dot(const MyVector3 t_other) const
{
	float dotProduct = (x * t_other.x) + (y * t_other.y) + (z * t_other.z); // gets the dot product
	return dotProduct; // returns it back
}

MyVector3 MyVector3::crossProduct(const MyVector3 t_other) const
{
	float newVectorX = y * t_other.z - z * t_other.y; // gets the x-value
	float newVectorY = z * t_other.x - x * t_other.z; // gets the y-value
	float newVectorZ = x * t_other.y - y * t_other.x; // gets the z-value

	return MyVector3(newVectorX, newVectorY, newVectorZ); // return
}

double MyVector3::angleBetween(const MyVector3 t_other) const
{
	MyVector3 vectorOne{ x,y,z }; // the value of the vector
	double angle = acos((vectorOne.dot(t_other) / (vectorOne.length() * t_other.length()))); // calulates the angle between
	return angle * (180 / PI); // return in degrees
}

MyVector3 MyVector3::unit() const
{
	MyVector3 unitVec(x, y, z); // the value of the vector
	double lenght = unitVec.length(); // gets the lenght
	unitVec = unitVec / lenght; // calulates the unit

	return unitVec;
}

void MyVector3::normalise()
{
	MyVector3 newVector{ x,y,z }; // the value of the vector

	x = x / newVector.length(); // gets the x-value
	y = y / newVector.length(); // gets the y-value
	z = z / newVector.length(); // gets the z-value

}

MyVector3 MyVector3::projection(const MyVector3 t_onto) const
{
	MyVector3 projection{ x,y,z }; // the value of the vector
	double lenght = t_onto.length(); // gets the lenght
	double projectionCalulation = projection.dot(t_onto) / (lenght * lenght); // the projection calulation
	return MyVector3(projectionCalulation * t_onto.x, projectionCalulation * t_onto.y, projectionCalulation * t_onto.z); // return the answer
}

MyVector3 MyVector3::rejection(const MyVector3 t_onto) const
{
	MyVector3 newVector{ x,y,z }; // the value of the vector
	MyVector3 projectionVec{}; // projection result
	projectionVec = newVector.projection(t_onto); // projection calulation
	MyVector3 rejection = newVector - projectionVec; // rejection result
	return MyVector3(rejection); // return
}

MyVector3::operator sf::Vector2u()
{
	int newX = 0; // new x value
	int newY = 0; // new y value

	if (x < 0) // if less than zero
	{
		newX = x * -1; // to make it positive
	}
	if (y < 0) // if less than zero
	{
		newY = y * -1; // to make it positive
	}

	return sf::Vector2u{ static_cast<unsigned int>(round(newX)),static_cast<unsigned int>(round(newY)) }; // returns
}