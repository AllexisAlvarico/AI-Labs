#ifndef MYVECTOR3 
#define MYVECTOR3

/// <summary>
/// Name: Allexis Alvarico
/// Login: C00242855
/// Date: 9th of January
/// --------------------------------------------------------
/// Summary: 
/// The program is to test all vector3 mathematics for use
/// in future labs.
/// ---------------------------------------------------------
/// Estinmated time: 5-7 hours
/// Session 1 5:30pm to 7:30pm  9th of January
/// Session 2 10:00am to 11:00am 10th of January 
/// Session 3 5:00pm to 7:30pm 10th of January
/// Session 4 3:00pm to 6:30pm 11th of January 
/// Session 5 5:00pm to 7:00pm 14th of January 
/// Actual time: 9hrs
/// Known Bugs: 

#include <iostream>
#include <SFML/Graphics.hpp>


class MyVector3
{
public:
	double x;
	double y;
	double z;

	MyVector3();
	~MyVector3();
	std::string toString();



	MyVector3(double x, double y, double z);
	MyVector3(sf::Vector3f t_sfVector);
	MyVector3(sf::Vector3i t_sfVector);
	MyVector3(sf::Vector2i t_sfVector);
	MyVector3(sf::Vector2u t_sfVector);
	MyVector3(sf::Vector2f t_sfVector);


	MyVector3 operator +(const MyVector3 t_right) const;
	MyVector3 operator -(const MyVector3 t_right) const;
	MyVector3 operator *(const double t_scalar) const;
	MyVector3 operator /(const double t_divisor) const;
	MyVector3 operator +=(const MyVector3 t_right);
	MyVector3 operator -=(const MyVector3 t_right);

	bool operator == (const MyVector3 t_right) const;
	bool operator != (const MyVector3 t_right) const;

	// negative of a vector 
	MyVector3 operator -();  // this changes the vector
	//new methods for bouncing off sides of table in billiards
	void reverseX(); // this negates the x element of the vector
	void reverseY();  // this negates the y element of the vector

	double length()const;
	double lengthSquared()const;
	double dot(const MyVector3 t_other) const;
	MyVector3 crossProduct(const MyVector3 t_other)const;
	double angleBetween(const MyVector3 t_other)const;  // answer in degrees
	MyVector3 unit() const;  // vector doesn't change
	void normalise(); // vector changes and will have length 1 
	MyVector3 projection(const MyVector3 t_onto)const;
	// projection onto the other vector so answer will parallel to other vector.
	MyVector3 rejection(const MyVector3 t_onto)const;


	operator sf::Vector2f() { return sf::Vector2f{ static_cast<float>(x),static_cast<float>(y) }; }; // {2.4,-2.6,3.0} ->  {2.4~,-2.6~}
	operator sf::Vector2i() { return sf::Vector2i{ static_cast<int>(round(x)),static_cast<int>(round(y)) }; };// {2.4,-2.6,3.0} ->  {2,3}
	operator sf::Vector2u();// {2.4,-2.6,3.0} ->  {2,3}  needs more space than an inline
	operator sf::Vector3i() { return sf::Vector3i{ static_cast<int>(round(x)),static_cast<int>(round(y)),static_cast<int>(round(z)) }; };// {2.4,-2.6,3.0} ->  {2,-3,3}
	operator sf::Vector3f() { return sf::Vector3f{ static_cast<float>(x),static_cast<float>(y),static_cast<float>(z) }; };// {2.4,-2.6,3.0} ->  {2.4~,-2.6~, 3.0}

};



#endif // !MYVECTOR3