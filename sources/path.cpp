#include "path.h"
using namespace intersectables;
using namespace std;

Path::Path(const vector<Vec2>& _points, bool closed) : points { _points } {
    validate(closed);
}

Path::Path(const vector<Vec2>&& _points, bool closed) : points { _points } {
    validate(closed);
}

void Path::validate(bool closed) {
    if (closed)

    if (points.size() < 2) {
        throw invalid_argument("The path has to contain atleast two points.");
    }
    if (isSelfIntersecting()) {
        throw invalid_argument("The path can't intersect itself.");
    }
}

bool Path::visit(const Intersectable &other, IntersectionData &data) const {
    return other.isIntersectingWith(*this, data);
}

bool Path::isIntersectingWith(const Circle &other, IntersectionData &data) const {
    return circlePathTest(other, *this, data);
}

bool Path::isIntersectingWith(const Path &other, IntersectionData &data) const {
    for (int i = 0; i < points.size() - 1; i++) {
        for (int j = 0; j < other.points.size() - 1; j++) {             
            Vec2 intersectionPoint {-1000000, -1000000};    
            bool intersection = areEdgesIntersecting(
                points[i],
                points[i+1],
                other.points[j],
                other.points[j+1],
                intersectionPoint           
            );
            if (intersection) {
                data.pointsOfIntersection.push_back(intersectionPoint);
            }
        }
    }
    if (data.pointsOfIntersection.size() > 0) {
        return true;
    }
    return false;
}

void Path::transform(Vec2 center, float rotation, float scale) {

}

// vector<Vec2>::iterator Path::begin() {
//     return points.begin(); 
// }

// vector<Vec2>::iterator Path::end() {
//     return points.end();
// }

vector<Vec2>::const_iterator Path::begin() const{
    return points.cbegin(); 
}

vector<Vec2>::const_iterator Path::end() const {
    return points.cend();
}

Vec2 Path::operator[](int index) const {
    return points[index];
}

size_t Path::size() const {
    return points.size();
}

bool Path::isSelfIntersecting() const {
    for (int i = 0; i < points.size() - 1; i++) {
        for (int j = 0; j < points.size() - 1; j++) {  
            Vec2 pA = points[i];
            Vec2 pB = points[i+1];
            Vec2 pC = points[j];
            Vec2 pD = points[j+1];
            if (pA == pB || pC == pD) {                
                return true;
            }
            if (pA == pC ||
                pA == pD ||
                pB == pC ||
                pB == pD) {
                continue;
            }            
            bool intersecting = areEdgesIntersecting(pA, pB, pC, pD, Vec2{});        
            if (intersecting) {
                return true;
            }
        }
    }
    return false;
}

bool Path::areEdgesIntersecting(Vec2 pA, Vec2 pB, Vec2 pC, Vec2 pD, Vec2& intersectionPoint) const { 
    Vec2 pAB = pB-pA;
    Vec2 pCD = pD-pC;
    float divisor = pAB.cross(pCD);
    if (divisor == 0) {          
        if (pB.cross(pC) != 0 && pA != pC && pB != pD) {
            return false;
        }
        float a = pA.x+pA.y;
        float b = pB.x+pB.y;
        float c = pC.x+pC.y;
        float d = pD.x+pD.y;
        if (a > b) {
            a = pB.x+pB.y;
            b = pA.x+pA.y;
        }
        if (c > d) {
            c = pD.x+pD.y;
            d = pC.x+pC.y;
        }
        float roll = (float)rand() / (float)RAND_MAX;
        Vec2 tmp = intersectionPoint;
        if (a <= c && c <= b) {             
            intersectionPoint = pC + (pB - pC) * roll;
        }
        else if(c <= a && a <= d) {
            intersectionPoint = pA + (pD - pA) * roll;
        }
        else if(a <= c && d <= b) {
            intersectionPoint = pC + (pD - pC) * roll;
        }
        else if(c <= a && b <= d) {
            intersectionPoint = pA + (pB - pA) * roll;
        }
        if (intersectionPoint != tmp) {
            return true;
        }
        return false;
    }
    if (divisor == 0) {
        throw runtime_error("Can't divide by 0, lines are parallel.");
    }
    Vec2 pCA = pC-pA;
    float t = pCA.cross(pCD) / divisor;
    float u = pCA.cross(pAB) / divisor;
    if (0 <= t && t <= 1 && 0 <= u && u <= 1) {
        intersectionPoint = pA + pAB * t;
        return true;
    }  
    return false;
}