#include <iostream>


#include "shared/Hello.h"

void Hello::print(std::string name)
{
    // Create a string variable
    std::cout << "Hello Shared Library! " << "name: " << name << std::endl;
}
