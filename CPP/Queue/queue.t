/*
	queue.t
	December 03, 2016
	Ralph McCracken, III
	mccracke
*/

#ifndef _QUEUE_T
#define _QUEUE_T

#include <iostream>

// =================================================================================
// = fsu::
// =================================================================================
namespace fsu
{
  // Queue Implementation Plan
  template < typename T >
  class Queue
  {
  private:
    // Queue Data
    class Link
    {
      Link ( const T& t ) : element_(t), nextLink_(0) {}
      T      element_;
      Link * nextLink_;
      friend class Queue<T>;
    };
    Link * firstLink_;
    Link * lastLink_;
    
  public:
    // Queue < T > API
    void     Push     (const T& t);
    T        Pop      ();
    T&       Front    ();
    const T& Front    () const;
    size_t   Size     () const;
    bool     Empty    () const;
    void     Clear    ();
    void     Append   (const Queue& q);
    void     Release  ();
    void     Display  (std::ostream& os, char ofc = '\0') const;
    void     Dump     (std::ostream& os, char ofc = '\0') const;
    size_t   Capacity () const;
    
    // Queue Constructors
    Queue             ();              // default constructor
    Queue             (const Queue&);  // copy constructor
    ~Queue            ();              // destructor
    Queue& operator = (const Queue&);  // assignment operator
  };
  
  // Provided By Instructor ========================================================
  // Output Operator Overloading
  
  // Output Operator Overloading
  template < typename T >
  std::ostream& operator << (std::ostream& os, const Queue<T>& q)
  {
    q.Display (os, '\0');
    return os;
  }
  
  // ===============================================================================
  // = Queue Template Implementation
  // ===============================================================================
  
  // -tors =========================================================================
  // Default Constructor
  // Copy Constructor
  // Destructor
  // Assignment Operator
  
  // Default Constructor
  template < typename T >
  Queue<T>::Queue()
  : firstLink_(0), lastLink_(0)
  {}
  
  // Copy Constructor
  template < typename T >
  Queue<T>::Queue(const Queue& thisQueue)
  : firstLink_(0), lastLink_(0)
  {
    if (!thisQueue.Empty())
    {
      Append(thisQueue);
    }else
    {
      return;
    }
  }
  
  // Destructor
  template < typename T >
  Queue<T>::~Queue()
  {
    Release();
  }
  
  // Assignment Operator
  template < typename T >
  Queue<T>& Queue<T>::operator = (const Queue& originQueue)
  {
    if (&originQueue != this)
    {
      if (!originQueue.Empty())
      {
        Append(originQueue);
      }
    }
    return *this;
  }
  
  // Queue Method Implementations ==================================================
  // Push
  // Pop
  // Front
  // Front, const
  // Size
  // Empty
  // Clear
  // Append
  // Release
  // Display
  // Dump
	// Capacity
  
  // Push
  template < typename T >
  void Queue<T>::Push (const T& t)
  {
    Queue<T>::Link* subLink		= new Link(t);
    if(!Empty())
    {
      lastLink_->nextLink_		= subLink;
      lastLink_								= subLink;
    }else
    {
      lastLink_								= subLink;
      firstLink_							= subLink;
    }
  }
  
  // Pop
  template < typename T >
  T Queue<T>::Pop()
  {
    if (!Empty())
    {
      Queue<T>::Link * temp = firstLink_;
      
      if (firstLink_ == lastLink_)
      {
        lastLink_			= 0;
        firstLink_		= 0;
      }else
      {
        firstLink_		= firstLink_->nextLink_;
      }
      
      T queueElement	= temp->element_;
      delete temp;
      
      return queueElement;
    }else
    {
      std::cerr << "** Queue error: Pop called on empty queue" << "\n";
      exit(EXIT_FAILURE);
    }
  }
  
  // Front
  template < typename T >
  T& Queue<T>::Front()
  {
    if (!Empty())
    {
      return firstLink_->element_;
    }else
    {
      std::cerr << "** Queue error: Front called on empty queue" << "\n";
      exit(EXIT_FAILURE);
    }
  }
  
  // Front, const
  template < typename T >
  const T& Queue<T>::Front() const
  {
    if (!Empty())
    {
      return firstLink_->element_;
    }else
    {
      std::cerr << "** Queue error: Front called on empty queue" << "\n";
      exit(EXIT_FAILURE);
    }
  }
  
  // Size
  template < typename T >
  size_t Queue<T>::Size() const
  {
    size_t size = 0;
    
    if (!Empty())
    {
      Queue<T>::Link* currLink = firstLink_;
      while (currLink != 0)
      {
        currLink = currLink->nextLink_;
        ++size;
      }
    }else
    {
      return size;
    }
    
    return size;
  }
  
  // Empty
  template < typename T >
  bool Queue<T>::Empty() const
  {
    bool empty;
    
    if ( firstLink_ == 0 )
    {
      empty = true;
    }else
    {
      empty = false;
    }
    
    return empty;
  }
  
  // Clear
  template < typename T >
  void Queue<T>::Clear()
  {
    Release();
  }
  
  // Append
  template < typename T >
  void Queue<T>::Append (const Queue& q)
  {
    Queue<T>::Link* thisLink	= q.firstLink_;
    T queueElement						= thisLink->element_;
    Queue<T>::Link* subLink		= new Link(queueElement);
    lastLink_									= subLink;
    firstLink_								= subLink;
    thisLink									= thisLink->nextLink_;
    
    while (thisLink != 0)
    {
      T queueElement					= thisLink->element_;
      Queue<T>::Link* subLink = new Link(queueElement);
      lastLink_->nextLink_		= subLink;
      lastLink_								= subLink;
      thisLink								= thisLink->nextLink_;
    }
  }
  
  // Release
  template < typename T >
  void Queue<T>::Release ()
  {
    if (!Empty())
    {
      Queue<T>::Link* thisLink	= firstLink_;
      Queue<T>::Link* temp;
      
      while (thisLink != 0)
      {
        temp										= thisLink;
        thisLink								= thisLink->nextLink_;
        delete temp;
      }
    }
    lastLink_		= 0;
    firstLink_	= 0;
  }
  
  // Display
  template < typename T >
  void Queue<T>::Display (std::ostream& os, char ofc) const
  {
    if (!Empty())
    {
      Queue<T>::Link* currLink = firstLink_;
      if (ofc == '\0')
      {
        while (currLink != 0)
        {
          os << currLink->element_;
          currLink = currLink->nextLink_;
        }
      }else
      {
        while (currLink != 0)
        {
          os << currLink->element_ << ofc;
          currLink = currLink->nextLink_;
        }
      }
    }else
    {
      return;
    }
  }
  
  // Dump
  template < typename T >
  void Queue<T>::Dump (std::ostream& os, char ofc) const
  {
    Display(os, ofc);
  }
  
  // Capacity
  template < typename T >
  size_t Queue<T>::Capacity () const
  {
    return Size();
  }
}

#endif
