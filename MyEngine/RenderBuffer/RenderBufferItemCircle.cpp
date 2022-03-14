#include <vector>
#include "../RenderBuffer/RenderBufferItem.h"
#include "../GameRenderer.h"

using namespace std;

void RenderBufferItemCircle::render()
{
	SDL_SetRenderDrawColor(renderer->scene, color.r, color.g, color.b, color.a);

    vector<SDL_Point> points;

        int x = radius, y = 0;

        // Printing the initial point on the axes
        // after translation
        SDL_Point asd = { x + (int)center.x, y + (int)center.y };
        points.push_back( { x + (int)center.x, y + (int)center.y } );

        // When radius is zero only a single
        // point will be printed
        if (radius > 0)
        {
            points.push_back({ x + (int)center.x, -y + (int)center.y });
            points.push_back({ y + (int)center.x, x + (int)center.y });
            points.push_back({ -y + (int)center.x, x + (int)center.y });
        }

        // Initialising the value of P
        int P = 1 - radius;
        while (x > y)
        {
            y++;

            // Mid-point is inside or on the perimeter
            if (P <= 0)
                P = P + 2 * y + 1;
            // Mid-point is outside the perimeter
            else
            {
                x--;
                P = P + 2 * y - 2 * x + 1;
            }

            // All the perimeter points have already been printed
            if (x < y)
                break;

            // Printing the generated point and its reflection
            // in the other octants after translation
            points.push_back({ x + (int)center.x, y + (int)center.y });
            points.push_back({ -x + (int)center.x, y + (int)center.y });
            points.push_back({ x + (int)center.x, -y + (int)center.y });
            points.push_back({ -x + (int)center.x, -y + (int)center.y });

            // If the generated point is on the line x = y then
            // the perimeter points have already been printed
            if (x != y)
            {
                points.push_back({ y + (int)center.x, x + (int)center.y });
                points.push_back({ -y + (int)center.x,x + (int)center.y });
                points.push_back({ y + (int)center.x,-x + (int)center.y });
                points.push_back({ -y + (int)center.x, -x + (int)center.y });
            }
        }

        SDL_RenderDrawPoints(renderer->scene, &points[0], points.size());
	delete this;
}