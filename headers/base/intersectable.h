#pragma once
#include "intersection_data.h"

namespace intersectables {
	class Circle;
	class Path;

	class Intersectable {
	public:
		virtual bool visit(const Intersectable &, IntersectionData &) const = 0;
		virtual void transform(Vec2, float, float) = 0;
		virtual bool isIntersectingWith(const Circle &, IntersectionData &) const = 0;
		virtual bool isIntersectingWith(const Path &, IntersectionData &) const = 0;
	protected:
		bool circlePathTest(const Circle &, const Path &, IntersectionData &) const;
	};
}