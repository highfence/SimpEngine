#pragma once

template <typename T>
class Vector
{
public:

	Vector();
	Vector(T x, T y);
	
	void Set(T x, T y);
	Vector<T>& operator+(const Vector<T>& classObj);
	Vector<T>& operator-(const Vector<T>& classObj);


private :

	T X;
	T Y;
};

template<typename T>
inline Vector<T>::Vector()
	: X(0), Y(0)
{
}

template<typename T>
inline Vector<T>::Vector(T x, T y)
	: X(a), Y(b)
{
}

template<typename T>
inline void Vector<T>::Set(T x, T y)
{
	X = x;
	Y = y;
}

template<typename T>
inline Vector<T>& Vector<T>::operator+(const Vector<T>& classObj)
{
	X += classObj.X;
	Y += classObj.Y;

	return *this;
}

template<typename T>
inline Vector<T>& Vector<T>::operator-(const Vector<T>& classObj)
{
	X -= classObj.X;
	Y -= classObj.Y;

	return *this;
}
