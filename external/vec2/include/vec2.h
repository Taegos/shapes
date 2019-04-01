#pragma once
#include <ostream>

#define EPSILON 0.0015f
#define PI 3.141592f

struct Vec2 {           
    float x;
    float y;
    Vec2 operator+(Vec2) const;
    Vec2 operator-(Vec2) const;
    Vec2 operator*(float) const;
    void operator=(Vec2);
    void operator+=(Vec2);
    void operator-=(Vec2);
    void operator*=(float);
    bool operator==(Vec2) const;
    bool operator!=(Vec2) const;
    bool operator<(Vec2) const;
    bool operator<=(Vec2) const;
    bool operator>(Vec2) const;
    bool operator>=(Vec2) const;    
    void normalize();
    Vec2 normalized() const;
    void rotate(Vec2, float);
    Vec2 rotated(Vec2, float) const;
    float cross(Vec2) const;
    float distance(Vec2) const;
    float magnitude() const;
    float dot(Vec2) const;
};

std::ostream& operator<<(std::ostream&, Vec2);