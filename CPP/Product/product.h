/*  product.h - Project 2: Product
 14 September, 2016
 Ralph McCracken, III
 
 Definition of the Product class.
 Product class method function prototypes.
 Output stream operator overloading prototype.   */

#ifndef _PRODUCT_H  // morph of the file name into a legal identifier
#define _PRODUCT_H

#include <cstdint>  // for uint32_t
#include <iostream>
#include <cstdlib>

// ====================================================================================
// = Class Product Method Prototypes                                                  =
// ====================================================================================
class Product
{
    
public:
    void        SetName    ( const char* );             // sets the name field
    void        SetBarCode ( uint32_t );                // sets the bar code field
    void        SetCost    ( float );                   // sets the cost field
    const char* GetName    () const;                    // returns a const pointer to the name field
    uint32_t    GetBarCode () const;                    // returns the bar code by value
    float       GetCost    () const;                    // returns cost by value
    
    Product ();                                           // default constructor
    Product ( const char* name, uint32_t code, float cost );    // constructor
    ~Product ();                                          // destructor
    Product ( const Product& p );       // copy constructor
    Product& operator = ( const Product& p );             // assignment operator
    
private:
    char *   name_;                                     // the product name
    uint32_t code_;                                     // the product bar code
    float    cost_;                                     // the product cost
};

// ====================================================================================
// = Output stream operator overloading prototype                                     =
// ====================================================================================
std::ostream& operator << ( std::ostream& os, const Product& p);

#endif
