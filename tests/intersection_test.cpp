#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "circle.h"
#include "rectangle.h"
#include "open_path.h"
#include "closed_path.h"
using namespace std;
using namespace intersectables;

//CIRCLE
TEST_CASE( "Circle VS Circle" ) {
    Circle a {{4,-4}, 3};
    //Circle b {{}}
}

TEST_CASE( "Circle VS Path" ) {

}

TEST_CASE ( "Path VS Path" ){

}