#pragma once
#include <math.h>


struct Vector2
{
public:
	int x;
	int y;
	double magnitude() { return sqrt(x * x + y * y); }
	Vector2 directionTo(Vector2 target) 
	{
	
	}
	void Set(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	Vector2()
	{
		Set(0, 0);
	}

	Vector2(double x, double y)
	{
		Set(x, y);
	}

	friend Vector2 operator -(Vector2& left, Vector2& right)
	{
		Vector2 newVector(left.x - right.x, left.y - right.y);
		return newVector;
	}
	friend Vector2 operator +(Vector2& left, Vector2& right)
	{
		Vector2 newVector(left.x + right.x, left.y + right.y);
		return newVector;
	}
	 Vector2* operator -=(Vector2& right)
	{
		 this->x -= right.x;
		 this->y -= right.y;
		return this;
	}
	Vector2* operator +=(Vector2& right)
	{
		this->x += right.x;
		this->y += right.y;
		return this;
	}
	Vector2* operator *=(Vector2& right)
	{
		this->x *= right.x;
		this->y *= right.y;
		return this;
	}
	Vector2* operator /=(Vector2& right)
	{
		this->x /= right.x;
		this->y /= right.y;
		return this;
	}
private:


};