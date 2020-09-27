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
    uiuc::Cube c;
    c.setLength(2.4);
    
    std::cout << "The volume is: " << c.getVolume() << "\n\n";
    
    std::cout << "Surface area is: " << c.getSurfaceArea() << std::endl;

    return 0;
}
