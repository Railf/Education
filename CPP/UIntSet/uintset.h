*
  uintset.h
  10/12/16
  Ralph McCracken, III
  mccracke

  Project 3:
    UIntSet Class Definitiion
    Global Operator Overloading Prototypes
    Output Stream Operator Overloading Prototype
*/

#ifndef _UINTSET_H
#define _UINTSET_H

#include <bitvect.h>

// ====================================================================================
// = Class UIntSet Method Prototypes                                                  =
// ====================================================================================
class UIntSet
{
public:
  void        Insert   ( unsigned long n );        // inserts n into set
  void        Remove   ( unsigned long n );        // removes n from set
  void        Clear    ();                         // makes set empty
  bool        Member   ( unsigned long n ) const;  // returns true iff n is in set

  bool        Empty    () const;   // true iff set is empty
  size_t      Size     () const;   // returns number of elements in set
  size_t      Range    () const;   // returns upper bound of range/universe [0,ub)

  UIntSet& operator =  ( const UIntSet& s );  // set = s (assignment operator)
  UIntSet& operator += ( const UIntSet& s );  // set = set union s
  UIntSet& operator *= ( const UIntSet& s );  // set = set intersection s
  UIntSet& operator -= ( const UIntSet& s );  // set = set difference s

  void        Dump     ( std::ostream& os ) const; // used in development & testing; displays underlying bitvector state

  UIntSet ();                    // default constructor
  UIntSet ( unsigned long n );   // constructor
  ~UIntSet ();                   // destructor
  UIntSet ( const UIntSet& s );  // copy constructor
                                 // assignment operator (see above)

private:
  fsu::BitVector bv_;    // bitvmector representing set

};  // end class UIntSet

// ====================================================================================
// = Global Operator Overloading Prototypes                                           =
// ====================================================================================
UIntSet operator +  ( const UIntSet& s1, const UIntSet& s2 );  // returns s1 union s2
UIntSet operator *  ( const UIntSet& s1, const UIntSet& s2 );  // returns s1 intersection s2
UIntSet operator -  ( const UIntSet& s1, const UIntSet& s2 );  // returns s1 difference s2
bool    operator == ( const UIntSet& s1, const UIntSet& s2 );  // true iff s1 and s2 are equal as sets
bool    operator != ( const UIntSet& s1, const UIntSet& s2 );  // true iff s1 and s2 are not equal

// ====================================================================================
// = Output Stream Overloading Prototype                                              =
// ====================================================================================
std::ostream& operator << ( std::ostream& os, const UIntSet& s ); // output operator

#endif
