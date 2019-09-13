#pragma once
#include "intersectable.h"

namespace intersectables {
	class Path: public Intersectable {
	public:
		Path(const std::vector<Vec2>&, bool = false);	
		Path(const std::vector<Vec2>&&, bool = false);	
		bool visit(const Intersectable &, IntersectionData &) const override;	
		bool isIntersectingWith(const Circle &, IntersectionData &) const override;
        bool isIntersectingWith(const Path &, IntersectionData &) const override;
		void transform(Vec2, float, float) override;
		Vec2 operator[](int) const;
		size_t size() const;
		std::vector<Vec2>::const_iterator begin() const;
		std::vector<Vec2>::const_iterator end() const; 
	private:  
		void validate(bool);
        bool areEdgesIntersecting(Vec2, Vec2, Vec2, Vec2, Vec2 &) const;      
		bool isSelfIntersecting() const;
		std::vector<Vec2> points;
	};
}