#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "circle.h"
#include "rectangle.h"
#include "closed_path.h"
#include "path.h"
using namespace std;
using namespace intersectables;

TEST_CASE( "Circle should throw on radius less than or equal to 0." ) {
    REQUIRE_THROWS_AS(Circle({3,1}, -123), invalid_argument);
    REQUIRE_THROWS_AS(Circle({3,1}, 0), invalid_argument);
}

TEST_CASE( "Rectangle should throw on same points") {
    REQUIRE_THROWS_AS(intersectables::Rectangle({3,1}, {3,1}), invalid_argument);
}

//https://www.wolframalpha.com/input/?i=plot+++++++++++++++++++++++++++%7B0,0%7D,+++++++++%7B2,2%7D,+++++++++%7B3,-1%7D,+++++++++%7B0,+1%7D
TEST_CASE( "Path should throw on self intersection.") {
    REQUIRE_THROWS_AS(
            Path({
                {0,0},
                {2,2},
                {3,-1},
                {0,1}
            }
        ), 
        std::invalid_argument
    );
}

TEST_CASE("Path constructor") {

}

TEST_CASE( "Test path vector behavior") {
    vector<Vec2> points = {
        {0,0},
        {3,4},
        {3,0},
        {1,-51}
    };
    vector<Vec2> tmp = points;
    Path path = Path(tmp);
    REQUIRE(path.size() == 4);
    for (int i = 0; i < points.size(); i++) {
        REQUIRE(points[i] == path[i]);
    }
    vector<Vec2> test;
    for (Vec2 point : path) {
        test.push_back(point);
    }
    REQUIRE(test.size() == 4);
    for (int i = 0; i < test.size(); i++) {
        REQUIRE(test[i] == points[i]);
    }
}

TEST_CASE( "Path should throw on less than 2 points.") {
    REQUIRE_THROWS_AS(
            ClosedPath({}), 
        std::invalid_argument
    );
    REQUIRE_THROWS_AS(
            ClosedPath({
                {0,0},
            }
        ), 
        std::invalid_argument
    );
}

TEST_CASE( "Closed path should throw on less than 3 points.") {
    REQUIRE_THROWS_AS(
            ClosedPath({}), 
        std::invalid_argument
    );
    REQUIRE_THROWS_AS(
            ClosedPath({
                {0,0},
            }
        ), 
        std::invalid_argument
    );
    REQUIRE_THROWS_AS(
            ClosedPath({
                {0,0},
                {2,2},
            }
        ), 
        std::invalid_argument
    );
}
