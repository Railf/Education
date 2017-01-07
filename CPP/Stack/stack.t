/*
	stack.t
	Novemeber 29, 2016
	Ralph McCracken, III
 
	Definition and implementation of the stack class template (fsu::Stack<T,N>)
*/

#ifndef _STACK_T
#define _STACK_T

#include <iostream>

// =================================================================================
// = fsu::
// =================================================================================
namespace fsu
{
	// Stack Implementation Plan
	template < typename T, size_t N = 100 >
	class Stack
	{
	private:
		// Stack Data
		const size_t capacity_;  // = N = size of array   - fixed during life of stack
		T            data_[N];   // statically declared array of T objects    - where T objects are stored
		size_t       size_;      // current size of stack - dynamic during life of stack
    
	public:
		// Stack < T , N > API
		void     Push     (const T& t); // push t onto stack; error if full
		T        Pop      ();           // pop stack and return removed element; error if stack is empty
		T&       Top      ();           // return top element of stack; error if stack is empty
		const T& Top      () const;     // const version
		size_t   Size     () const;     // return number of elements in stack
		size_t   Capacity () const;     // return storage capacity [maximum size] of stack
		bool     Empty    () const;     // return 1/true if stack is empty, 0/false if not empty
		void     Clear    ();           // make the stack empty
		void     Display  (std::ostream& os, char ofc = '\0') const; // output stack contents through os
		void     Dump     (std::ostream& os); // output all private data (for development use only)

		// Stack Constructors
		Stack             ();             // default constructor
		Stack             (T fill);       // puts "fill" in each slot of the underlying array (keeps size = 0)
		Stack             (const Stack&); // copy constructor
		~Stack            ();             // destructor
		Stack& operator = (const Stack&); // assignment operator
	};
  
	// Provided By Instructor ========================================================
	// Output Operator Overloading
  
	// Output Operator Overloading
	template < typename T , size_t N >
	std::ostream& operator << (std::ostream& os, const Stack<T,N>& s)
	{
		s.Display (os, '\0');
		return os;
	}

	// ===============================================================================
	// = Stack Template Implementation
	// ===============================================================================

	// -tors =========================================================================
	// Default Constructor
	// Constructor
	// Copy Constructor
	// Destructor
	// Assignment Operator

	// Default Constructor
	template < typename T, size_t N >
	Stack<T, N>::Stack()
	: capacity_(N), data_(), size_(0)
	{}

	// Constructor
	template < typename T, size_t N >
	Stack<T, N>::Stack(T fill)
	: capacity_(N), data_(), size_(0)
	{
		for (size_t i = 0; i < N; ++i)
		{
			data_[i] = fill;
		}
	}

	// Copy Constructor
	template < typename T, size_t N >
	Stack<T,N>::Stack(const Stack& prevStack)
	: capacity_(prevStack.capacity_), data_(), size_(prevStack.size_)
	{
		for (size_t i = 0; i < N; ++i)
		{
			data_[i] = prevStack.data_[i];
		}
	}
  
	// Destructor
	template < typename T, size_t N >
	Stack<T,N>::~Stack()
	{}
  
	// Assignment Operator
	template < typename T, size_t N >
	Stack<T,N>& Stack<T,N>::operator = (const Stack& originStack)
	{
		if (&originStack != this)
		{
			size_ = originStack.size_;
			for (size_t i = 0; i < N; ++i)
			{
				data_[i] = originStack.data_[i];
			}
	}
		return *this;
	}

  // Stack Method Implementations ==================================================
  // Push
  // Pop
  // Top
  // Top, const
  // Size
  // Capacity
  // Empty
  // Clear
  // Display
  // Dump
  
  // Push
  template < typename T, size_t N >
  void Stack<T,N>::Push(const T& t)
  {
    if (size_ == capacity_)
    {
      std::cerr << "** Stack error: Push called on full stack" << "\n";
      exit(EXIT_FAILURE);
    }else if (size_ < N)
    {
      data_[size_] = t;
      ++size_;
    }
  }
  
  // Pop
  template < typename T, size_t N >
  T Stack<T,N>::Pop()
  {
    if (size_ == 0)
    {
      std::cerr << "** Stack error: Pop called on empty stack" << "\n";
      exit(EXIT_FAILURE);
    }
    T topElement;
    topElement = data_[size_];
    --size_;
    
    return topElement;
  }
  
  // Top
  template < typename T, size_t N >
  T& Stack<T,N>::Top()
  {
    if (size_ == 0)
    {
      std::cerr << "** Stack error: Top called on empty stack" << "\n";
      exit(EXIT_FAILURE);
    }
    
    return data_[size_ - 1];
  }
  
  // Top, const
  template < typename T, size_t N >
  const T& Stack<T,N>::Top() const
  {
    if (size_ == 0)
    {
      std::cerr << "** Stack error: Top called on empty stack" << "\n";
      exit(EXIT_FAILURE);
    }
    
    return data_[size_ - 1];
  }
  
  // Size
  template < typename T, size_t N >
  size_t Stack<T,N>::Size() const
  {
    return size_;
  }
  
  // Capacity
  template < typename T, size_t N >
  size_t Stack<T,N>::Capacity() const
  {
    return capacity_;
  }
  
  // Empty
  template < typename T, size_t N >
  bool Stack<T,N>::Empty() const
  {
    if (size_ == 0)
    {
      return true;
    }else
    {
      return false;
    }
  }
  
  // Clear
  template < typename T, size_t N >
  void Stack<T,N>::Clear()
  {
    size_ = 0;
  }
  
  // Display
  template < typename T, size_t N >
  void Stack<T,N>::Display(std::ostream& os, char ofc) const
  {
    if (ofc == '\0')
    {
      for(size_t i = 0; i < size_; ++i)
      {
        os << data_[i] << ofc;
      }
      
    }else if (ofc != '\0' && size_ != 0) // breaks if size_ = 0
    {
      for (size_t i = 0; i < (size_ - 1); ++i)
      {
        os << data_[i] << ofc;
      }
      os << data_[size_ - 1];
    }
  }
  
  // Dump
  template < typename T, size_t N >
  void Stack<T,N>::Dump(std::ostream& os)
  {
    std::cout << "Capacity: " << capacity_ << "\n";
    std::cout << "Size:     " << size_ << "\n";
    std::cout << "Array:    " << "[";
    for (size_t i = 0; i < (capacity_ - 1); ++i)
    {
      os << data_[i] << ',';
    }
    os << data_[capacity_ - 1];
    std::cout << "]" << "\n";
    std::cout << "Stack:    [";
    Display(std::cout, ',');
    std::cout << "]" << "\n";
  }
}

#endif
