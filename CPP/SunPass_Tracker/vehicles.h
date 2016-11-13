/*
	vehicles.h
	10/18/16
	Ralph McCracken, III
	mccracke

	Project 4:
		Class Vehicle Definition
		Class Car Definition
		Class Truck Definition
		Class Van Definition
		Class Tanker Definition
		Class Flatbed Definition

		Methods LoadCapacity, ShortName, and Toll as well as all destructors are established as virtual.
*/

#ifndef _VEHICLES_H
#define _VEHICLES_H

#include <shapes.h>

// Enumerated type
enum VehicleType
{
	badSn,
	vehicle,
	car,
	truck,
	van,
	tanker,
	flatbed
};

// ====================================================================================
// = Class Vehicle Prototypes																													=
// ====================================================================================
class Vehicle
{
public:
	const char*           SerialNumber       () const;					// returns serial number
	unsigned int          PassengerCapacity  () const;					// returns passenger capacity
	virtual float         LoadCapacity       () const;					// returns 0
	virtual const char*   ShortName          () const;					// returns "UNK"
	virtual float         Toll               () const;					// returns toll using fee schedule
	static  VehicleType   SnDecode           (const char* sn);

	Vehicle  ();																								// default constructor
	Vehicle  ( const char* sn, unsigned int pc, bool v = 0 );		// constructor [3 arguements: private, protected variables]
	virtual ~Vehicle ();																				// destructor

private:
	char*        serialNumber_;
	unsigned int passengerCapacity_;

	Vehicle ( const Vehicle& v );																// private copy constructor
	Vehicle& operator= ( const Vehicle& v );										// privarte assignment operator

protected:
	bool verbose_;																							// default value 0 given in constructor prototype
};

// ====================================================================================
// = Class Car Prototypes																															=
// ====================================================================================
class Car : public Vehicle
{
public:
	const char* ShortName() const;		// returns "CAR"

	Car  ();													// default constructor
	Car  ( const char* sn, unsigned int pc, bool v = 0 );
	virtual ~Car ();									// destructor

private:
	Car  ( const Car& c );						// private copy constructor
	Car& operator= ( const Car& c );	// private assignment operator
};

// ====================================================================================
// = Class Truck Prototypes																														=
// ====================================================================================
class Truck : public Vehicle
{
public:
	const char*   ShortName          () const;	// returns "TRK"
	float         Toll               () const;	// returns toll using fee schedule
	const char*   DOTLicense         () const;	// returns the license no

	Truck  ();																	// default constructor
	Truck  ( const char * sn, unsigned int pc, const char* dot, bool v = 0 );
	virtual ~Truck ();													// destructor

private:
	char* DOTLicense_;

	Truck  ( const Truck& t );									// private copy constructor
	Truck& operator= ( const Truck& t );				// private assignment operator
};

// ====================================================================================
// = Class Van Prototypes																															=
// ====================================================================================
class Van : public Truck, public Box
{
public:
	float         LoadCapacity       () const;	// returns volume of box
	const char*   ShortName          () const;	// returns "VAN"

	Van  ();																		// default constructor
	Van  ( const char* sn, unsigned int pc, const char* dot, float l, float w, float h, bool v = 0 );
	virtual ~Van ();														// destructor

private:
	Van  ( const Van& v );											// private copy construuctor
	Van& operator= ( const Van& v );						// private assignment operator
};

// ====================================================================================
// = Class Tanker Prototypes																													=
// ====================================================================================
class Tanker : public Truck, public Cylinder
{
public:
	float         LoadCapacity       () const;	// returns volume of cylinder
	const char*   ShortName          () const;	// returns "TNK"

	Tanker  ();																	// default constructor
	Tanker  ( const char* sn, unsigned int pc, const char* dot, float l, float r, bool v = 0 );
	virtual ~Tanker ();													// destructor

private:
	Tanker  ( const Tanker& t );								// private copy construtor
	Tanker& operator= ( const Tanker& t );			// private assignment operator
};

// ====================================================================================
// = Class Flatbed Prototypes																													=
// ====================================================================================
class Flatbed : public Truck, public Plane
{
public:
	float         LoadCapacity       () const;	// returns area of plane
	const char*   ShortName          () const;	// returns "FLT"

	Flatbed  ();																// defualt constructor
	Flatbed  ( const char* sn, unsigned int pc, const char* dot, float l, float w, bool v = 0 );
	virtual ~Flatbed ();												// destructor
};

#endif
