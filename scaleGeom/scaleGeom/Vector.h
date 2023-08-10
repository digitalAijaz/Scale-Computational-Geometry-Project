/*
	Vector.h - Computational Geometry Vector Utilities

	Overview:
	The Vector.h header file is a core component of the computational geometry suite, providing
	robust support for vector operations in N-dimensional spaces. It is designed to be flexible,
	accommodating various data types and dimensions, making it a versatile tool for various
	geometric computations.

	Features:
	- Representation of vectors in 2D, 3D, and N-dimensional spaces.
	- Support for different coordinate data types, including integer and floating-point types.
	- Overloaded operators facilitating vector arithmetic and comparisons.
	- Geometric query functions like dot product and cross product.
	- Utility functions such as normalization and magnitude computation.
	- Strong encapsulation using the scaleGeom namespace to avoid naming conflicts.
	- Forward declarations and friend functions to maintain a clean and modular structure.

	Dependencies:
	- Requires the "Core.h" for certain utility functions and definitions.

	Usage:
	The utility can be directly included in computational geometry projects, and the vectors can be
	instantiated using the defined typedefs like Vector2f and Vector3f or using the generic Vector template.

	Author: Aijaz, Scale Lab IISc
	Date: 10/08/2022
	Version: 1.0

*/


#pragma once

#include <iostream>
#include <array>
#include <type_traits>
#include "Core.h"

// This header provides the definition for the Vector class within the scaleGeom namespace.
// The scaleGeom namespace encapsulates all geometric constructs and related utilities.
namespace scaleGeom {

	// Constants for specifying the number of dimensions in 2D and 3D vectors.
#define DIM2 2
#define DIM3 3

// Define index constants for easier access to vector components.
#define X 0
#define Y 1
#define Z 2

	// Forward declaration of the Vector template class without its default argument.
	template <class coordDataType, size_t dimension>
	class Vector;  

	// Forward declaration of the stream insertion operator for the Vector class.
	template<class coordDataType, size_t dimension>
	std::ostream& operator<<(std::ostream& os, const Vector<coordDataType, dimension>& vec);

	// Template class for a vector, allowing for different coordinate data types (like int, float) and dimensions.
	template <class coordDataType, size_t dimension = DIM3>
	class Vector 
	{
		// Allow the stream insertion operator to access private members of the Vector class.
		friend std::ostream& operator<< <>(std::ostream& os, const Vector& vec);

		// Ensure the coordinate type is either an integer or a floating-point type.
		static_assert(std::is_arithmetic<coordDataType>::value, "Coordinate type must be arithmetic or float");

		// Ensure the dimension specified is either 2D or higher.
		static_assert(dimension >= DIM2, "Vector Dimensions must be atleast 2D");

		// Array to store the coordinates of the vector.
		std::array<coordDataType, dimension> coords;

		//Dot product of two vectors
		template<class coordDataType, size_t dimension>
		friend coordDataType dotProduct(const Vector<coordDataType, dimension>&, const Vector<coordDataType, dimension>&);


	public:

		// Default constructor.
		Vector() {}

		// Constructor that initializes the vector with an array of coordinates.
		Vector(std::array<coordDataType, dimension> _coords) : coords(_coords) {}

		// Constructor for a 3D vector, initializes the vector with x, y, and z coordinates.
		Vector(coordDataType _x, coordDataType _y, coordDataType _z) : coords({ _x, _y, _z }) {}

		// Constructor for a 2D vector, initializes the vector with x and y coordinates.
		Vector(coordDataType _x, coordDataType _y) : coords({ _x, _y }) {}

		
		// Equality check
		bool operator==(const Vector<coordDataType, dimension>&) const;
		
		// Not Equal
		bool operator!=(const Vector<coordDataType, dimension>&) const;

		// Addition
		Vector <coordDataType, dimension> operator+(const Vector<coordDataType, dimension>&) const;

		// Subtraction
		Vector <coordDataType, dimension> operator-(const Vector<coordDataType, dimension>&) const;

		// Less than
		bool operator<(const Vector<coordDataType, dimension>&) const;

		// Greater than
		bool operator>(const Vector<coordDataType, dimension>&) const;
		
		// Index operator to access the vector's coordinates by index.
		coordDataType operator[](size_t ) const;

		//Assign a specific value to a given dimension (coordinate) of the Vector.
		void assign(int dim, coordDataType value);

		// Get the magnitude of the vector.
		float magnitude() const;

		//Normalize the vector
		void normalize();


};

	typedef Vector<float, DIM2> Vector2f;
	typedef Vector<float, DIM3> Vector3f;

	// Implementation for the overloaded << (stream insertion) operator for the Vector class
	template<class coordDataType, size_t dimension>
	std::ostream& operator<<(std::ostream& os, const Vector<coordDataType, dimension>& vec) {
		os << "(";
		for (size_t i = 0; i < dimension; ++i) {
			os << vec[i];
			if (i != dimension - 1) {
				os << ", ";
			}
		}
		os << ")";
		return os;
	}


	// Overloaded '==' operator to compare two Vectors for equality.
	template<class coordDataType, size_t dimension>
	inline bool Vector<coordDataType, dimension>::operator==(const Vector<coordDataType, dimension>& _other) const
	{
		// Iterate through each coordinate of the Vector.
		for (size_t i = 0; i < dimension; i++)
		{
			// Use the IsEqualD function to check for approximate equality 
			// (useful for float/double types to account for precision issues).
			if (!IsEqualD(coords[i], _other.coords[i]))
			{
				// If any coordinate does not match, the Vectors are not equal.
				return false;
			}
		}
		// If all coordinates match, the Vectors are equal.
		return true;
	}

	// Overloaded '!=' operator to compare two Vectors for inequality.
	template<class coordDataType, size_t dimension>
	inline bool Vector<coordDataType, dimension>::operator!=(const Vector<coordDataType, dimension>& _other) const
	{
		// Use the previously defined '==' operator to check for inequality.
		return !(*this == _other);
	}

	// Overloaded '+' operator to add two Vectors.
	template<class coordDataType, size_t dimension>
	inline Vector<coordDataType, dimension> Vector<coordDataType, dimension>::operator+(const Vector<coordDataType, dimension>& _other) const
	{
		// Create an array to store the result of the addition.
		std::array<coordDataType, dimension> result;
		// Iterate through each coordinate.
		for (size_t i = 0; i < dimension; i++)
		{
			// Add corresponding coordinates of the two Vectors.
			result[i] = coords[i] + _other.coords[i];
		}
		// Return a new Vector initialized with the result.
		return Vector<coordDataType, dimension>(result);
	}

	// Overloaded '-' operator to subtract one Vector from another.
	template<class coordDataType, size_t dimension>
	inline Vector<coordDataType, dimension> Vector<coordDataType, dimension>::operator-(const Vector<coordDataType, dimension>& _other) const
	{
		// Create an array to store the result of the subtraction.
		std::array<coordDataType, dimension> result;
		// Iterate through each coordinate.
		for (size_t i = 0; i < dimension; i++)
		{
			// Subtract corresponding coordinates of the two Vectors.
			result[i] = coords[i] - _other.coords[i];
		}
		// Return a new Vector initialized with the result.
		return Vector<coordDataType, dimension>(result);
	}


	// Overloaded '<' operator for the Vector class to determine if one vector is "less than" another.
	template<class coordDataType, size_t dimension>
	inline bool Vector<coordDataType, dimension>::operator<(const Vector<coordDataType, dimension>& _other) const
	{
		// Iterate through each dimension of the vector.
		for (size_t i = 0; i < dimension; i++)
		{
			// If the coordinate of the current vector is greater than or equal to
			// the corresponding coordinate of the other vector, then the current vector
			// cannot be considered "less than" the other vector.
			if (coords[i] >= _other.coords[i])
			{
				return false;
			}
		}

		// If the loop completes without returning false, it means every coordinate of the
		// current vector is strictly less than the corresponding coordinate of the other vector.
		return true;
	}

	// Overloaded '>' operator for the Vector class to determine if one vector is "greater than" another.
	template<class coordDataType, size_t dimension>
	inline bool Vector<coordDataType, dimension>::operator>(const Vector<coordDataType, dimension>& _other) const
	{
		// Iterate through each dimension of the vector.
		for (size_t i = 0; i < dimension; i++)
		{
			// If the coordinate of the current vector is less than or equal to
			// the corresponding coordinate of the other vector, then the current vector
			// cannot be considered "greater than" the other vector.
			if (coords[i] <= _other.coords[i])
			{
				return false;
			}
		}

		// If the loop completes without returning false, it means every coordinate of the
		// current vector is strictly greater than the corresponding coordinate of the other vector.
		return true;
	}


	// Overloaded '[]' operator to access the coordinates of the Vector by index.
	template<class coordDataType, size_t dimension>
	inline coordDataType Vector<coordDataType, dimension>::operator[](size_t _index) const
	{
		// Check if the provided index is within the valid range [0, dimension).
		if (_index >= dimension)
		{
			// If the index is out of range, throw an exception.
			throw std::out_of_range("Index out of range\n");
			// The return statement below can be used as an alternative to throwing an exception.
			// It would return a default-constructed value of the coordDataType (e.g., 0 for int).
			// return coordDataType();
		}

		// If the index is valid, return the coordinate at the specified index.
		return coords[_index];
	}

	// Method to assign a specific value to a given dimension (coordinate) of the Vector.
	template<class coordDataType, size_t dimension>
	inline void Vector<coordDataType, dimension>::assign(int dim, coordDataType value)
	{
		if(dim>=dimension)
			throw std::out_of_range("Index out of range\n");

		// Set the value of the specified dimension (coordinate) to the provided value.
		coords[dim] = value;
	}

	template<class coordDataType, size_t dimension>
	inline float Vector<coordDataType, dimension>::magnitude() const
	{
		float result = 0;
		for (size_t i = 0; i < dimension; i++)
		{
			result += coords[i] * coords[i];
		}
		return sqrt(result);
	}

	template<class coordDataType, size_t dimension>
	inline void Vector<coordDataType, dimension>::normalize()
	{
		float mag = magnitude();
		for (size_t i = 0; i < dimension; i++)
		{
			coords[i] /= mag;
		}
	}

	
	// Template function to calculate the dot product of two vectors.
    // The vectors can be of any dimension and the coordinate data type can be any arithmetic type (e.g., int, float, double).
	template<class coordDataType, size_t dimension>
	coordDataType dotProduct(const Vector<coordDataType, dimension>& v1, const Vector<coordDataType, dimension>& v2)
	{		
		// Initialize the dot product result to zero. 
		// The type of the result is the same as the coordinate type of the vectors.
		coordDataType dotProduct = 0;

		// Iterate over each dimension (or coordinate) of the vectors.
		for (size_t i = 0; i < dimension; i++)
		{
			// Multiply the corresponding coordinates of the two vectors 
			// and add the product to the accumulated result.
			dotProduct += v1[i] * v2[i];
		}

		// Return the final calculated dot product.
		return dotProduct;
	}

	//Cross Product in 2D
	float crossProduct2D(Vector2f v1, Vector2f v2);
	//Cross Product in 3D
	Vector3f crossProduct3D(Vector3f v1, Vector3f v2);




	

} // Closing the scaleGeom namespace.
