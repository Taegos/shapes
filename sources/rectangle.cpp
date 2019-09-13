#include "rectangle.h"
using namespace std;
using namespace intersectables;

Rectangle::Rectangle(Vec2 topLeft, Vec2 bottomRight) : 
	Path (
		vector<Vec2> { 
			topLeft, 
			{bottomRight.x, topLeft.y}, 
			bottomRight, 
			{topLeft.x, bottomRight.y},
			topLeft
		}
	){
}