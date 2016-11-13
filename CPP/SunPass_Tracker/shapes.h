/*
	shapes.h
	10/18/16
	Ralph McCracken, III
	mccracke

	Project 4:
		Class Box Definition
		Class Cylinder Definition
		Class Plane Definition

		All destructors are established as virtual.
*/

#ifndef _SHAPES_H
#define _SHAPES_H

// ====================================================================================
// = Class Box Prototypes																															=
// ====================================================================================
class Box
{
public:
	float Volume() const;														// returns volume of box object

	Box  ();																				// default constructor
	Box  ( float l, float w, float h, bool v = 0 );	// constructor [4 arguements: private variables]
	virtual ~Box ();																// destructor

private:
	float length_, width_, height_;
	bool verbose_;																	// default value 0 given in constructor prototype

	Box  ( const Box& b );													// private copy constructor
	Box& operator= ( const Box& b );								// private assignment operator
};

// ====================================================================================
// = Class Cylinder Prototypes																												=
// ====================================================================================
class Cylinder
{
public:
	float Volume() const;												// returns volume of cylinder object

	Cylinder  ();																// default constructor
	Cylinder  ( float l, float r, bool v = 0 ); // constructor [3 arguements: private variables]
	virtual ~Cylinder ();												// destructor

private:
	float length_, radius_;
	bool verbose_;															// default value 0 given in constructor prototype

	Cylinder  ( const Cylinder& c );						// private copy constructor
	Cylinder& operator= ( const Cylinder& c );	// private assignment operator
};

// ====================================================================================
// = Class Plane Prototypes																														=
// ====================================================================================
class Plane
{
public:
	float Area() const;												// returns area of plane object

	Plane  ();																// default constructor
	Plane  ( float l, float w, bool v = 0 );	// constructor [4 arguements: private variables]
	virtual ~Plane ();												// destructor

private:
	float length_, width_;
	bool verbose_;														// default value 0 given in constructor prototype

	Plane ( const Plane& p );									// private copy constructor
	Plane& operator= ( const Plane& p );			// private assignment operator
};

#endif
