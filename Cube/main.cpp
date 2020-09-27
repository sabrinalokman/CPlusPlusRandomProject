//
//  main.cpp
//  Cube
//
//  Created by Sabrina Lokman on 2020-09-26.
//

#include <iostream>
#include "Cube.hpp"

int main()
{
    Cube c;
    c.setLength(3.48);
    double volume = c.getVolume();
    std::cout << "The volume is: " << volume << "\n\n";

    return 0;
}
