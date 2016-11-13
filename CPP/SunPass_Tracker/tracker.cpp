/*
	tracker.cpp
	10/26/16
	Ralph McCracken, III
	mccracke

	Project 5:
		Implementation of client program tracker of the SunPass vehicle system.
*/

#include <iostream>
#include <iomanip>
#include <cstring>
#include <vehicles.h>

																				// # GLOBAL CONSTANSTS ==============================================================
const unsigned int C1	= 6;							// Column width for short name field.
const unsigned int C2	= 7;							// Column width for toll field.
const unsigned int C3	= 10;							// Column width for passenger capacity field.
const unsigned int C4	= 10;							// Column width for load capacity field.
const unsigned int c5	= 2;							// Space prior to column width for DOT License field.
const unsigned int c6	= 2;							// Space prior to column width for Serial Number field.
const unsigned int P1	= 2;							// std::setprecision(2)

int main()
{
																				// # CONSTANTS ======================================================================
																				// [6 of code requirements] =========================================================
	const size_t	maxSegmentSize	= 100;	// Maximum number of vehicles in a traffic segment, size is set to 100 [0 - 99, + \0]
	const size_t	maxSerialSize		= 20;		// Maximum number of characters in a serial number, set to 20
	const size_t	maxDOTSize			= 20;		// Maximum number of characters in a truck's DOT License, set to 20

																				// # VARIABLE VEHICLE TYPE DECLARATION ==============================================
	VehicleType vehicleType;							// Placeholder for the vehicle's type: badSn, Vehicle, Car, Truck, Van, Tanker, Flat

	std::cout << "\nTracker started...\n";// Prompt user that the tracker has started.
																				// [mimicing area51 tracker_i.x]

																				// # DATA USED BY LOOP ==============================================================
	size_t				segmentSize;						// Variable size_t size of a segment, provided by user

																				// # LOOP PROCESS [as stated in number 3 of code requirements] ======================
	do																		// do-while to justify a possible 0 segment-size, segmentSize, case
	{
		std::cin >> segmentSize;						// Read in segment size, segmentSize, from user.

		if( segmentSize == 0 )							// Code requirement 7: if size 0 is read or some size greater than max size, exit
		{
			break;
		}else if ( segmentSize > maxSegmentSize )
		{
			std::cerr << "\nMaximum segment size exceeded (100)! \n Exiting...\n";
			break;
		}else if ( !std::cin )							// If not size_t is entered; for example, a char
		{
			std::cerr << "\nInvalid type entered (non- size_t)! \n Exiting...\n";
			break;
		}

																						// # VARIABLE DECLARATION =======================================================
		Vehicle*			segment[maxSegmentSize];	// Vehicle object pointer, segment, created with maximum segment size
		char					sn[maxSerialSize];				// Variable character, sn, created with maximum, constant size		[name provided]
		char					DOTL[maxDOTSize];					// Variable character, DOTL, created with maximum, constant size	[name provided]
		unsigned int	pc;												// Variable unsigned int, to match vehicles.h, pc									[name provided]
		float					d1;												// Variable float, to match shapes.h, d1 = length									[name provided]
		float					d2;												// Variable float, to match shapes.h, d2 = width or radius				[name provided]
		float					d3;												// Variable flaot, to match shapes.h, d3 = height									[name provided]

																						// # VARIABLE COLUMN WIDTH HANDLER VARIABLES ====================================
		unsigned int C5 = 11;										// Variable established to default DOT License column length, 11.
		unsigned int C6 = 13;										// Variable established to default Serial Number column length, 13.
																						//  Type   Toll  Pass Cap  Load Cap  DOT License  Serial Number
																						//	----   ----  --------  --------  -----------  -------------
																						//	   4      4         8         8           11             13
																						// ! Visualization of column lengths


																						// # STATISTIC VARIABLES ========================================================
																						// [mimicing area51 tracker_i.x]
		int						cars			= 0;						// Variable int, cars, tracks number of cars in segment.
		int						trucks		= 0;						// Variable int, trucks, tracks number of trucks in segment.
		int						vans			= 0;						// Variable int, vans, tracks number of vans in segment.
		int						tankers		= 0;						// Variable int, tankers, tracks number of tankers in segment.
		int						flatbeds	= 0;						// Variable int, flatbeds, tracks number of flatbeds in segment.
		int						unknowns	= 0;						// Variable int, unknowns, tracks number of unknowns in segment.
		int						badSns		= 0;						// Variable int, badSns, tracks number of badSns in segment.
		float					tonnage		= 0.0;					// Variable float, tonnage, tracks total tonnage in segment.
		float					tolls			= 0.0;					// Variable float, tolls, tracks total tolls in segment.

		for ( size_t i = 0; i < segmentSize; ++i )		// # READ THROUGH ENTIRE SEGMENT ==========================================
		{
																									// # VEHICLE OBJECTS ======================================================
																									// [3 of code requirements] ===============================================
			std::cin >> sn;															// Read serial number.
			vehicleType = Vehicle::SnDecode(sn);				// Vehicle type determined by SnDecode implementation from vehicle.cpp.

			switch ( vehicleType )											// Create Vehicle objects based on the vehicle type.
			{
																									// # CAR OBJECT ===========================================================
				case car:																	// When vehicle type is car, create car object:
					std::cin >> pc;													// Read passenger capacity for car object.
					segment[i] = new Car( sn, pc );					// Create car object with parameters: sn, pc
					++cars;																	// Add 1 to number of cars in segment.

					break;																	// Exit car case.

																									// # TRUCK OBJECT =========================================================
				case truck:																// When vehicle type is truck, create truck object:
					std::cin >> pc;													// Read passenger capacity for truck object.
					std::cin >> DOTL;												// Read DOT License for truck object.
					segment[i] = new Truck( sn, pc, DOTL );	// Create truck object with parameters: sn, pc, DOTL
					++trucks;																// Add 1 to number of trucks in segment.

					break;																	// Exit truck case.

																									// # VAN OBJECT ===========================================================
				case van:																	// When vehicle type is van, create van object:
					std::cin >> pc;													// Read passenger capacity for van object.
					std::cin >> DOTL;												// Read DOT License for van object.
					std::cin >> d1;													// Read length for van object.
					std::cin >> d2;													// Read width for van object.
					std::cin >> d3;													// Read height for van object.
																									// Create van object with parameters: sn, pc, DOTL, d1, d2, d3
					segment[i] = new Van( sn, pc, DOTL, d1, d2, d3 );
					++vans;																	// Add 1 to number of vans in segment.

					break;																	// Exit van case.

																									// # TANKER OBJECT ========================================================
				case tanker:															// When vehicle type is tanker, create tanker object:
					std::cin >> pc;													// Read passenger capacity for tanker object.
					std::cin >> DOTL;												// Read DOT License for tanker object.
					std::cin >> d1;													// Read length for tanker object.
					std::cin >> d2;													// Read radius for tanker object.
																									// Create tanker object with parameters: sn, pc, DOTL, d1, d2
					segment[i] = new Tanker( sn, pc, DOTL, d1, d2 );
					++tankers;															// Add 1 to number of tankers in segment.

					break;																	// Exit tanker case.

																									// # TANKER OBJECT ========================================================
				case flatbed:															// When vehicle type is flatbed, create flatbed object:
					std::cin >> pc;													// Read passenger capacity for flatbed object.
					std::cin >> DOTL;												// Read DOT License for flatbed object.
					std::cin >> d1;													// Read length for flatbed object.
					std::cin >> d2;													// Read width for flatbed object.
																									// Create flatbed object with parameters: sn, pc, DOTL, d1, d2
					segment[i] = new Flatbed( sn, pc, DOTL, d1, d2 );
					++flatbeds;															// Add 1 to number of flatbeds in segment.

					break;																	// Exit flatbed case.

																									// # VEHICLE OBJECT [UNKNOWN] =============================================
				case vehicle:															// When vehicle type is vehicle, create vehicle object:
					std::cin >> pc;													// Read passenger capacity for vehicle object.
					segment[i] = new Vehicle( sn, pc );			// Create vehicle object with parameters: sn, pc
					++unknowns;															// Add 1 to number of unknowns in segment.

					break;																	// Exit unknown case.

																									// # VEHICLE OBJECT [BAD SERIAL #] ========================================
				case badSn:																// When vehicle type is vehicle, create vehicle object:
					std::cin >> pc;													// Read passenger capacity for vehicle object.
					segment[i] = new Vehicle( sn, pc );			// Create vehicle object with parameters: sn, pc
					++badSns;																// Add 1 to number of bad serial numbers in segment.

					break;																	// Exit bad serial number case.

																									// # DEFAULT CASE =========================================================
				default:
					std::cerr << "\nInvalid serial number!\n";
					break;																	// Exit default case.
			}																						// End switch statement.

																									// # TONNAGE AND TOLL TRACKING ============================================
			tonnage	+=	segment[i]->LoadCapacity();			// Add current element's load capacity to the total segment's tonnage.
			tolls		+=	segment[i]->Toll();							// Add current element's toll to the total segment's toll.

																									// # LONGEST DOT LICENSE AND SERIAL NUMBER HOLDERS ========================
			size_t longestDOTL	= strlen(DOTL);
			size_t longestSn		= strlen(sn);
			if ( C5 < longestDOTL )											// If current longest DOTL is smaller than current DOTL,
				C5 = longestDOTL;													// set current DOTL to longest DOTL.

			if ( C6 < longestSn)												// If current longest Sn is smaller than current Sn,
				C6 = longestSn;														// set current Sn to longest Sn.
		}																							// End for statement.
		C5 += c5;
		C6 += c6;
																												// # SEGMENT SUMMARRY================================================
																												// [3.4 of code requirements] =======================================
																												// [mimicing area51 tracker_i.x]
		std::cout << "\n";
		std::cout << "Segment Summary\n";
		std::cout << "===============\n";
		std::cout << "\n";
		std::cout << "  Cars:     "		<< cars			<< "\n";	// Number of cars in segment.
		std::cout << "  Trucks:   "		<< trucks		<< "\n";	// Number of trucks in segment.
		std::cout << "  Vans:     "		<< vans			<< "\n";	// Number of vans in segment.
		std::cout << "  Tankers:  "		<< tankers	<< "\n";	// Number of tankers in segment.
		std::cout << "  Flatbeds: "		<< flatbeds	<< "\n";	// Number of flatbeds in segment.
		std::cout << "  Unknowns: "		<< unknowns	<< "\n";	// Number of unknowns in segment.
		std::cout << "  Badsn:    "		<< badSns		<< "\n";	// Number of bad serial numbers in segment.
		std::cout << std::setprecision(P1) << std::fixed;		// Set float formatting ostream flags [mimicing area51 tracker_i.x]
		std::cout << "  Tonnage:  "		<< tonnage	<< "\n";	// Total sum of tons in segment.
		std::cout << "  Tolls:    $"	<< tolls		<< "\n";	// Total sum of tolls in segment.

																												// # SEGMENT DETAILS ================================================
																												// [5 of code requirements] =========================================
																												// [mimicing area51 tracker_i.x]

																												//  Type   Toll  Pass Cap  Load Cap  DOT License  Serial Number
																												//	----   ----  --------  --------  -----------  -------------
																												//	   6      7        10        10           13             15
																												// ! Visualization of column width sizes

		std::cout << "\n";
		std::cout << "Segment Details\n";
		std::cout << "===============\n";
		std::cout << "\n";
		std::cout << std::right															//  Type   Toll  Pass Cap  Load Cap  DOT License  Serial Number
		<< std::setw(C1)		<< "Type"
		<< std::setw(C2)		<< "Toll"
		<< std::setw(C3)		<< "Pass Cap"
		<< std::setw(C4)		<< "Load Cap"
		<< std::setw(C5)		<< "DOT License"
		<< std::setw(C6)		<< "Serial Number" << "\n";
		std::cout << std::right															//	----   ----  --------  --------  -----------  -------------
		<< std::setw(C1)		<< "----"
		<< std::setw(C2)		<< "----"
		<< std::setw(C3)		<< "--------"
		<< std::setw(C4)		<< "--------"
		<< std::setw(C5)		<< "-----------"
		<< std::setw(C6)		<< "-------------" << "\n";

																									// # VEHICLE DATA REPORT ==================================================
																									// [5.1 of code requirements] =============================================
																									// [mimicing area51 tracker_i.x]
		for( size_t i = 0; i < segmentSize; ++i )																						// For each segment:
		{
			std::cout << std::right << std::fixed << std::setprecision(P1)										// Define float as fixed x.yz.
			<< std::setw(C1)	<< segment[i]->ShortName()																			// Display Short Name.
			<< std::setw(C2)	<< segment[i]->Toll()																						// Display Toll.
			<< std::setw(C3)	<< segment[i]->PassengerCapacity()															// Display Passenger Capacity.
			<< std::setw(C4)	<< segment[i]->LoadCapacity();																	// Display Load Capacity.

			if( truck <= Vehicle::SnDecode(segment[i]->SerialNumber()) )											// If a truck:
				std::cout << std::setw(C5) << (dynamic_cast<Truck*>(segment[i]))->DOTLicense();	// Display DOT License.
			else																																							// If not a truck:
				std::cout << std::setw(C5) << "(NA)";																						// Display "(NA)".

			std::cout << std::setw(C6)	<< segment[i]->SerialNumber();												// Display Serial Number.
			std::cout << "\n";

																																												// # RELEASE ALLOCATED MEMORY =======
			delete segment[i];																																// [5.2 of code requirements] =======
		}

	} while( segmentSize > 0 || segmentSize < maxSegmentSize );														// End do-while statement.

	std::cout << "\n";
	std::cout << "\n";
	std::cout << "...Thank you for using SunPass Tracker.";	// Prompt user that the tracker has started.
																													// [mimicing area51 tracker_i.x]
	std::cout << "\n";
	std::cout << "\n";

}	// End main function.
