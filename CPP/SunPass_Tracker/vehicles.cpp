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
*/

#include <vehicles.h>
#include <iostream>
#include <cstring>

// ====================================================================================
// = Class Vehicle Implementation																											=
// ====================================================================================
const char*           Vehicle::SerialNumber       () const
{
	return serialNumber_;
}

unsigned int          Vehicle::PassengerCapacity  () const
{
	return passengerCapacity_;
}

float                 Vehicle::LoadCapacity       () const
{
	return 0.0;
}

const char*           Vehicle::ShortName          () const
{
	return "UNK";
}

float                 Vehicle::Toll               () const
{
	return 2.00;
}

VehicleType   Vehicle::SnDecode           (const char* sn)
{
	switch( sn[0] )
	{
		case '0':
			return badSn;
		case '1':
			return vehicle;
		case '2':
			return car;
		case '3':
			return truck;
		case '4':
			return van;
		case '5':
			return tanker;
		case '6':
			return flatbed;
		default:
			return badSn;
	}
}

Vehicle::Vehicle()
: serialNumber_(nullptr), passengerCapacity_(0.0)
{}

Vehicle::Vehicle  ( const char* sn, unsigned int pc, bool v )
: serialNumber_(nullptr), passengerCapacity_(pc), verbose_(v)
{
	size_t size = strlen( sn );
	serialNumber_ = new char[1+size];
	serialNumber_[size] = '\0';
	strcpy( serialNumber_, sn );

	if( verbose_ ) std::cout << "Vehicle()\n";

}

Vehicle::~Vehicle ()
{
	if( serialNumber_ != NULL ) delete [] serialNumber_;

	if( verbose_ ) std::cout << "~Vehicle()\n";

}

// ====================================================================================
// = Class Car Implementation																													=
// ====================================================================================
const char* Car::ShortName() const
{
	return "CAR";
}

Car::Car  ()
: Vehicle()
{}

Car::Car  ( const char* sn, unsigned int pc, bool v )
: Vehicle( sn, pc, v )
{
	if( Vehicle::verbose_ ) std::cout << "Car()\n";

}

Car::~Car ()
{
	if( Vehicle::verbose_ ) std::cout << "~Car()\n";

}

// ====================================================================================
// = Class Truck Implementation																												=
// ====================================================================================
const char*   Truck::ShortName          () const
{
	return "TRK";
}

float         Truck::Toll               () const
{
	return 10.00;
}

const char*   Truck::DOTLicense         () const
{
	return DOTLicense_;
}

Truck::Truck  ()
: Vehicle(), DOTLicense_(nullptr)
{}

Truck::Truck  ( const char * sn, unsigned int pc, const char* dot, bool v )
: Vehicle( sn, pc, v )
{
	size_t size = strlen( dot );
	DOTLicense_ = new char[1+size];
	DOTLicense_[size] = '\0';
	strcpy( DOTLicense_, dot );

	if( Truck::verbose_ ) std::cout << "Truck()\n";

}

Truck::~Truck ()
{
	if( DOTLicense_ != NULL ) delete [] DOTLicense_;

	if( Truck::verbose_ ) std::cout << "~Truck()\n";

}

// ====================================================================================
// = Class Van Implementation																													=
// ====================================================================================
float         Van::LoadCapacity       () const
{
	return Box::Volume();
}

const char*   Van::ShortName          () const
{
	return "VAN";
}

Van::Van  ()
: Truck(), Box()
{}

Van::Van  ( const char* sn, unsigned int pc, const char* dot, float l, float w, float h, bool v )
: Truck( sn, pc, dot, v ), Box( l, w, h, v)
{
	if( Vehicle::verbose_ && Truck::verbose_ ) std::cout << "Van()\n";

}

Van::~Van ()
{
	if( Vehicle::verbose_ && Truck::verbose_ ) std::cout << "~Van()\n";

}

// ====================================================================================
// = Class Tanker Implementation																											=
// ====================================================================================
float         Tanker::LoadCapacity       () const
{
	return Cylinder::Volume();
}

const char*   Tanker::ShortName          () const
{
	return "TNK";
}

Tanker::Tanker  ()
: Truck(), Cylinder()
{}

Tanker::Tanker  ( const char* sn, unsigned int pc, const char* dot, float l, float r, bool v )
: Truck( sn, pc, dot, v ), Cylinder( l, r, v )
{
  if( Vehicle::verbose_ && Truck::verbose_ ) std::cout << "Tanker()\n";

}

Tanker::~Tanker ()
{
	if( Vehicle::verbose_ && Truck::verbose_ ) std::cout << "~Tanker()\n";

}

// ====================================================================================
// = Class Flatbed Implementation																											=
// ====================================================================================
float         Flatbed::LoadCapacity       () const
{
	return Plane::Area();
}

const char*   Flatbed::ShortName          () const
{
	return "FLT";
}

Flatbed::Flatbed  ()
: Truck(), Plane()
{}

Flatbed::Flatbed  ( const char* sn, unsigned int pc, const char* dot, float l, float w, bool v )
: Truck( sn, pc, dot, v ), Plane( l, w, v )
{
	if( Vehicle::verbose_ && Truck::verbose_ ) std::cout << "Flatbed()\n";

}

Flatbed::~Flatbed ()
{
	if( Vehicle::verbose_ && Truck::verbose_ ) std::cout << "~Flatbed()\n";

}
