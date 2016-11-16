/*
	shapes.cpp
	10/18/16
	Ralph McCracken, III
	mccracke

	Project 4:
		Class Box Implementation
		Class Cylinder Implementation
		Class Plane Implementation
*/

#include <shapes.h>
#include <cmath>
#include <iostream>

// ====================================================================================
// = Class Box Implementation																													=
// ====================================================================================
float Box::Volume() const
{
	// Volume of a box: w*l*h
	return (width_ * length_ * height_);
}

Box::Box()
: length_(0), width_(0), height_(0), verbose_(0)
{}

Box::Box	( float l, float w, float h, bool  v )
: length_(l), width_(w), height_(h), verbose_(v)
{
	if(verbose_) std::cout << "Box()\n";

}

Box::~Box	()
{
	if(verbose_) std::cout << "~Box()\n";

}

// ====================================================================================
// = Class Cylinder Implementation																										=
// ====================================================================================
float Cylinder::Volume() const
{
	// Volume of a cylinder: PI*(r^2)*l
	return (M_PI * radius_ * radius_ * length_);
}

Cylinder::Cylinder  ()
: length_(0.0), radius_(0.0), verbose_(0)
{}

Cylinder::Cylinder  ( float l, float r, bool v )
: length_(l), radius_(r), verbose_(v)
{
	if(verbose_) std::cout << "Cylinder()\n";

}

Cylinder::~Cylinder ()
{
	if(verbose_) std::cout << "~Cylinder()\n";

}

// ====================================================================================
// = Class Plane Implementation																												=
// ====================================================================================
float Plane::Area() const
{
	// Area of a plane: l*w
	return (length_ * width_);
}

Plane::Plane  ()
: length_(0.0), width_(0.0), verbose_(0)
{}

Plane::Plane  ( float l, float w, bool v )
: length_(l), width_(w), verbose_(v)
{
	if(verbose_) std::cout << "Plane()\n";

}

Plane::~Plane ()
{
	if(verbose_) std::cout << "~Plane()\n";

}
