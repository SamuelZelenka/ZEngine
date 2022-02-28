#include "Component.h";
#include "SDL.h"

class RectRenderer : Component
{
public :
	RectRenderer(double x, double y, double width, double height)
	{
		this->x = x;
		this->y = y;
		this->width = width;
		this->height = height;
	}
	~RectRenderer();

	void update() override
	{

	}
private:
	double x;
	double y;
	double width;
	double height;
};