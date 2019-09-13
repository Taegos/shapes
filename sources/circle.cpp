#include "circle.h"
using namespace intersectables;
using namespace std;

Circle::Circle(Vec2 _center, float radius) : center { _center }, radius { radius } {
	if (radius <= 0) {
		throw invalid_argument("The radius have to be larger than 0.");
	}
}

bool Circle::visit(const Intersectable &other, IntersectionData &data) const {
	return other.isIntersectingWith(*this, data);
}

bool Circle::isIntersectingWith(const Circle &other, IntersectionData &data) const {
	throw std::exception("not implemented");
}

bool Circle::isIntersectingWith(const Path &other, IntersectionData &data) const {
	return circlePathTest(*this, other, data);
}

void Circle::transform(Vec2 center, float rotation, float scale) {

}