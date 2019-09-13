cmake_minimum_required(VERSION 3.6.2)
project(ShapesTest VERSION 1.0.0)

#HEADER DIRS
    set(HEADERS_DIR ${CMAKE_SOURCE_DIR}/headers)
    set(INTERSECTABLE_BASE_DIR_H ${HEADERS_DIR}/base)

    set(INTERSECTABLES_H
        ${HEADERS_DIR}
        ${INTERSECTABLE_BASE_DIR_H}
    )

#SOURCES DIRS
    set(SOURCES_DIR ${CMAKE_SOURCE_DIR}/sources)
    set(INTERSECTABLE_BASE_DIR_CXX ${SOURCES_DIR}/base)
    
    set(INTERSECTABLES_CXX
        ${INTERSECTABLE_BASE_DIR_CXX}/intersectable.cpp
        ${INTERSECTABLE_BASE_DIR_CXX}/path.cpp
        ${SOURCES_DIR}/circle.cpp
        ${SOURCES_DIR}/closed_path.cpp
        ${SOURCES_DIR}/open_path.cpp
        ${SOURCES_DIR}/rectangle.cpp
    )

#EXTERNAL DIRS
    set(EXTERNAL_DIR ${CMAKE_SOURCE_DIR}/external)
    #VEC2
        set(VEC2_DIR ${EXTERNAL_DIR}/vec2)
        set(VEC2_DIR_H ${VEC2_DIR}/include)
        set(VEC2_DIR_LIB ${VEC2_DIR}/lib)

    #SDL
        set(SDL_DIR ${EXTERNAL_DIR}/sdl)
        set(SDL_DIR_H ${SDL_DIR}/include)
        set(SDL_DIR_LIB ${SDL_DIR}/lib)

enable_testing()

#PROPERTIES TEST
    add_executable(
        PropertiesTest 
        properties_test.cpp
        ${INTERSECTABLES_CXX}
    )
    target_include_directories(
        PropertiesTest 
        PUBLIC 
        ${INTERSECTABLES_H}   
        ${VEC2_DIR_H}
    )
    target_link_libraries(
        PropertiesTest 
        ${VEC2_DIR_LIB}/Vec2.lib
    )
    add_test(PropertiesTest PropertiesTest)

#INTERSECTION TEST
    add_executable(
        IntersectionTest 
        intersection_test.cpp
        ${INTERSECTABLES_CXX}
    )
    target_include_directories(
        IntersectionTest 
        PUBLIC 
        ${INTERSECTABLES_H}   
        ${VEC2_DIR_H}
    )
    target_link_libraries(
        IntersectionTest 
        ${VEC2_DIR_LIB}/Vec2.lib
    )
    add_test(IntersectionTest IntersectionTest)