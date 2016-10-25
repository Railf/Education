/*  product.cpp - Prpject 2: Product
 14 September, 2016
 Ralph McCracken, III

 Implementation of the Product class methods and operators.
 Output stream operator overloading implementation.     */

#include <product.h>
#include <cstring>
#include <iomanip>

// ====================================================================================
// = Class Product Method Functions                                                   =
// ====================================================================================
void Product::SetName ( const char* name )  // sets the name field
{
    if (name_ != NULL)      // if name_ exists...
        delete [] name_;    // delete the allocated data
    size_t size = strlen(name);   // set array size variable, size, to length of given cstring
    name_ = new char [size + 1];  // allot memeory for char array of size: given cstring length plus one
    name_[size] = '\0';     // place null terminator at the size + 1 memory location
    strcpy(name_ , name);   // copy const char* name to name_
}

void Product::SetBarCode ( uint32_t code )      // sets the bar code field
{
    code_ = code;
}

void Product::SetCost ( float cost )            // sets the cost field
{
    cost_ = cost;
}

const char* Product::GetName () const         // returns a const pointer to the name field
{
    return name_;
}

uint32_t Product::GetBarCode () const         // returns the bar code by value
{
    return code_;
}

float Product::GetCost () const               // returns cost by value
{
    return cost_;
}

// ====================================================================================
// = Proper Type Constructors                                                         =
// ====================================================================================
Product::Product ()                                             // default constructor
: name_(NULL), code_(0x00000000), cost_(0.0)
{
    name_ = new char [2]; // alot space for name_, two memory locations
    name_[0] = '#';   // # in first location
    name_[1] = '\0';    // null terminator in second location
}

Product::Product ( const char* name, uint32_t code, float cost )    // constructor
: name_(NULL), code_(code) , cost_(cost)
{ // proceed as SetName
    size_t size = strlen(name);
    name_ = new char [size + 1];
    name_[size] = '\0';
    strcpy(name_ , name);
}

Product::~Product()             // destructor
{
    if (name_ != NULL)    // if name_ exists...
      delete [] name_;  // delete allocated memory
}

Product::Product ( const Product& p )                           // copy constructor
: name_(NULL), code_(p.code_) , cost_(p.cost_)
{ // proceed as SetName
    size_t size = strlen(p.name_);
    name_ = new char [size + 1];
    name_[size] = '\0';
    strcpy(name_ , p.name_);
}

Product& Product::operator = ( const Product& p )               // assignment operator
{
    if ( this != &p )     // if this is not the same object...
    {
  if (name_ != NULL)    // if name_ exists...
            delete [] name_;    // delete allocated memory
      size_t size = strlen(p.name_);  // proceed as SetName
      name_ = new char [size + 1];
      name_[size] = '\0';
      strcpy(name_ , p.name_);
  code_ = p.code_;    // code_ = code_ from object
  cost_ = p.cost_;    // cost_ = cost_ from object
    }

    return *this;     // return object
}

// ====================================================================================
// = Output stream operator overloading implementation                                =
// ====================================================================================
std::ostream& operator << ( std::ostream& os , const Product& p)
{
    std::ios_base::fmtflags flags = os.flags();
    os.setf(std::ios::fixed | std::ios::showpoint);                 // prep for $ output
    os.precision(2);
    os << p.GetName() << '\t'
    << std::hex << std::uppercase << std::setfill('0') << std::setw(8)  // prep for hex output
    << p.GetBarCode()
    << std::dec << std::setfill(' ') << '\t'                            // return dec output
    << p.GetCost();
    os.setf(flags);                                                   // return flags to previous states
    return os;
}
