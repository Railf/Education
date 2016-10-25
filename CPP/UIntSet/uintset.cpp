/*
  uintset.cpp
  10/12/16
  Ralph McCracken, III

    UIntSet Class Implementation
    Global Operator Overloading Implementation
    Output Stream Operator Overloading Implementation
*/

#include <uintset.h>
#include <iostream>

// ====================================================================================
// = Class UIntSet Implementation                                                     =
// ====================================================================================

// inserts n into set
void  UIntSet::Insert   ( unsigned long n )
{
  bv_.Set(n);
}

// removes n from set
void  UIntSet::Remove   ( unsigned long n )
{
  bv_.Unset(n);
}

// makes set empty
void  UIntSet::Clear    ()
{
  bv_.Unset();
}

// returns true iff n is in set
bool  UIntSet::Member   ( unsigned long n ) const
{
  bool member = bv_.Test(n);
  return member;
}

// returns upper bound of range/universe [0,ub)
size_t  UIntSet::Range  () const
{
  return bv_.Size();
}

// true if set is empty
bool  UIntSet::Empty    () const
{
  for(size_t i = 0; i < Range(); ++i)
  {
    if(bv_.Test(i)) return false;
  }
  return true;
}

// returns number of elements in set
size_t  UIntSet::Size   () const
{
  size_t size = 0;
  for(size_t i = 0; i < Range(); ++i)
  {
    if(Member(i)) ++size;
  }
  return size;
}

// used in development & testing; displays underlying bitvector state
void  UIntSet::Dump     ( std::ostream& os ) const
{
  bv_.Dump(os);
}

// set = s (assignment operator)
UIntSet& UIntSet::operator =  ( const UIntSet& s )
{
  if(this != &s)
  {
    Clear();
    for(size_t i = 0; i < Range(); ++i)
    {
      if(s.Member(i))
        Insert(i);
    }
  }
  return *this;
}

// set = set union s [ A union B = all A + all B]
UIntSet& UIntSet::operator += ( const UIntSet& s )
{
  for(size_t i = 0; i < Range(); ++i)
  {
    if(s.Member(i))
      Insert(i);
  }
  return *this;
}

// set = set intersection s [ A intersect B = elements shared by both A and B ]
UIntSet& UIntSet::operator *= ( const UIntSet& s )
{
  for(size_t i = 0; i < Range(); ++i)
  {
    if(Member(i) && s.Member(i))
      Insert(i);
    else
      Remove(i);
  }
  return *this;
}

// set = set difference s [ A difference B = elements of A without the elements that are also in B ]
UIntSet& UIntSet::operator -= ( const UIntSet& s )
{
  for(size_t i = 0; i < Range(); ++i)
  {
    if(Member(i) && s.Member(i)) Remove(i);
  }
  return *this;
}


//default constructor
UIntSet::UIntSet (): bv_(64)
{}

// constructor
UIntSet::UIntSet ( unsigned long n ): bv_(n)
{}

// destructor
UIntSet::~UIntSet ()
{
  // no memory allocated to return with decontrustor
}

// copy constructor
UIntSet::UIntSet ( const UIntSet& s ): bv_(s.bv_)
{}

// assignment operator [ see above (set = s) ]


// ====================================================================================
// = Global Operator Overloading Implementation                                       =
// ====================================================================================

// returns s1 union s2
UIntSet operator +  ( const UIntSet& s1, const UIntSet& s2 )
{
  UIntSet s(s1);
  s += s2;
  return s;
}

// returns s1 intersection s2
UIntSet operator *  ( const UIntSet& s1, const UIntSet& s2 )
{
  UIntSet s(s1);
  s *= s2;
  return s;
}

// returns s1 difference s2
UIntSet operator -  ( const UIntSet& s1, const UIntSet& s2 )
{
  UIntSet s(s1);
  s -= s2;
  return s;
}

// true iff s1 and s2 are equal as sets
bool    operator == ( const UIntSet& s1, const UIntSet& s2 )
{
  for(size_t i = 0; i < s1.Range(); ++i)
  {
    if(s1.Member(i) != s2.Member(i)) return false;
  }
  return true;
}

// true iff s1 and s2 are not equal
bool    operator != ( const UIntSet& s1, const UIntSet& s2 )
{
  bool equal = operator==(s1,s2);
  return !(equal);
}


// ====================================================================================
// = Output Stream Overloading Implementation                                         =
// ====================================================================================

// output operator
std::ostream& operator << ( std::ostream& os, const UIntSet& s )
{
  os << "{";
  for(size_t i = 0; i < s.Range(); ++i)
  {
    if(s.Member(i)) os << " " << i;
  }
  os << " }";
  return os;
}
