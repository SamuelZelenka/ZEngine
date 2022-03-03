#pragma once
#include <vector>
#include "RenderBufferItem.h"

using namespace std;

class RenderBuffer
{
public :
	void queue(RenderBufferItem* renderItem);
	void render();
private :
	vector<vector<RenderBufferItem*>> buffer;
};
