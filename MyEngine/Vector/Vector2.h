#include <math.h>


struct Vector2
{
public:
	double x;
	double y;
	double magnitude() { return x * x + y * y; }
	Vector2 directionTo(Vector2 target) 
	{
	
	}
	Vector2()
	{
		this->x = 0;
		this->y = 0;
	}

	Vector2(double x, double y)
	{
		this->x = x;
		this->y = y;
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