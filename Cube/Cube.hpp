//
//  Cube.hpp
//  Cube
//
//  Created by Sabrina Lokman on 2020-09-26.
//

#ifndef Cube_hpp
#define Cube_hpp

#include <stdio.h>
#pragma once

class Cube
{
public:
    double getVolume();
    double getSurfaceArea();
    void setLength(double length);

private:
    double length_;
};

#endif /* Cube_hpp */
