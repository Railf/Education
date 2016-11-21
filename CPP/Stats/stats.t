/*
	stats.t
	11/11/16
	Ralph McCracken, III
*/

#ifndef STATS_T
#define STATS_T

#include <iostream>
#include <vector>

// ==========================================================================
// = Template Prototypes
// ==========================================================================
template < typename T >
long double Mean (const std::vector<T>& v);	// returns mean of elements of v

template < typename T >
long double Median (std::vector<T>& v);			// returns median of elements of v

template < typename T >
void SelectionSort (std::vector<T>& v);			// implements insertion_sort algorithm

template < typename T >
void Swap (T& x, T& y);											// interchanges values of x and y

// ==========================================================================
// = Template Implementations
// ==========================================================================
template < typename T >
long double Mean(const std::vector<T>& v)
{
	long double mean	= 0.0;
	long double sum		= 0.0;

	for (size_t count = 0; count <= (v.size()-1); ++count)
	{
		sum += v[count];
	}

	mean = sum / v.size();
	return mean;
}

template < typename T >
long double Median(std::vector<T>& v)
{
	SelectionSort(v);
	if ((v.size() % 2) == 0)
	{
		return (v[(v.size() / 2)] + v[(v.size() / 2) - 1]) / 2.0;
	}else
	{
		return (v[((v.size() + 1) / 2) - 1]);
	}
}

template < typename T >
void SelectionSort(std::vector<T>& v)
{
  if (v.size() <= 1)	// if vector is empty or has one element, don't crash [ j = i + 1 ]
	{
    return;
	}

	size_t k;

	for(size_t i = 0; i < v.size(); ++i)
	{
		k = i;

		for(size_t j = i + 1; j < v.size(); ++j)
		{
			if(v[j] < v[k])
			{
				k = j;
			}
		}

		Swap(v[i], v[k]);
	}
}

template < typename T >
void Swap (T& x, T& y)
{
	T holdx = x;
	x = y;
	y = holdx;
}

#endif
