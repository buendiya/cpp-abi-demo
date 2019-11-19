#include <iostream>


#include "shared/Hello_gcc_lib.h"

namespace gcc_lib {
void Hello::print(std::string name)
{
    std::cout << "I am gcc lib! " << "Welcome: " << name << std::endl;
}

}