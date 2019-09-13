#pragma once
#include "path.h"

namespace intersectables {
	class Rectangle : public Path {
	public:
		Rectangle(Vec2, Vec2);
	};
}