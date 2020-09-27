//
//  Cube.cpp
//  Cube
//
//  Created by Sabrina Lokman on 2020-09-26.
//

#include "Cube.hpp"

double Cube::getSurfaceArea()
{
    return 6 * length_ * length_;
}

double Cube::getVolume()
{
    return length_ * length_ * length_;
}

void Cube::setLength(double length)
{
    length_ = length;
}
