#pragma once
#include <math.h>


struct Vector2
{
public:
	float x;
	float y;
	float magnitude() { return sqrt(x * x + y * y); }
	Vector2 normalized() { return { x / magnitude(), y / magnitude() }; }
	void Set(Vector2 vector)
	{
		Set(vector.x, vector.y);
	}

	void Set(float x, float y)
	{
		this->x = x;
		this->y = y;
	}

	static float dot(Vector2& v1, Vector2 v2 )
	{
		return v1.x * v2.x + v1.y * v2.y;
	}

	Vector2()
	{
		Set(0, 0);
	}

	Vector2(float x, float y)
	{
		Set(x, y);
	}

	friend Vector2 operator -(const Vector2& left, const Vector2& right)
	{
		Vector2 newVector(left.x - right.x, left.y - right.y);
		return newVector;
	}
	friend Vector2 operator -(Vector2& left, Vector2& right)
	{
		Vector2 newVector(left.x - right.x, left.y - right.y);
		return newVector;
	}
	friend Vector2 operator -(Vector2& left, float& right)
	{
		Vector2 newVector(left.x - right, left.y - right);
		return newVector;
	}

	friend Vector2 operator +(Vector2 left, Vector2 right)
	{
		Vector2 newVector(left.x + right.x, left.y + right.y);
		return newVector;
	}
	friend Vector2 operator +(Vector2& left, float right)
	{
		Vector2 newVector(left.x + right, left.y + right);
		return newVector;
	}

	friend Vector2 operator *(Vector2& left, float right)
	{
		Vector2 newVector(left.x * right, left.y * right);
		return newVector;
	}
	friend Vector2 operator *(Vector2& left, Vector2& right)
	{
		Vector2 newVector(left.x * right.x, left.y * right.y);
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
	Vector2* operator *=(float& right)
	{
		this->x *= right;
		this->y *= right;
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