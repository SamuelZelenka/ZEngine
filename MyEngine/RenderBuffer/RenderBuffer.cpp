#include "RenderBuffer.h"

void RenderBuffer::queue(RenderBufferItem* renderItem)
{
	if (buffer.size() < renderItem->layer + 1)
	{
		buffer.resize(renderItem->layer + 1);
	}
	buffer[renderItem->layer].push_back(renderItem);
};
void RenderBuffer::render()
{
	for (vector<RenderBufferItem*> layer : buffer)
	{
		for (RenderBufferItem* item : layer)
		{
			item->render();
		}
		layer.clear();
	}
	buffer.clear();
}