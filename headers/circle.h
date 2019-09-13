#pragma once
#include "intersectable.h"

namespace intersectables {
	class Circle : public Intersectable {
	public:
		Circle(Vec2 center, float radius);
		bool visit(const Intersectable &, IntersectionData &) const override;
		bool isIntersectingWith(const Circle &, IntersectionData &) const override;
        bool isIntersectingWith(const Path &, IntersectionData &) const override;
		void transform(Vec2, float, float) override;
	private:
		const Vec2 center;
		const float radius;
	};
}