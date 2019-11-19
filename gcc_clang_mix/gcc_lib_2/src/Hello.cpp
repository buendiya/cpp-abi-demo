#include <iostream>


#include "shared/Hello_gcc_lib_2.h"

namespace gcc_lib_2 {
void Hello::print()
{
    std::string name = "gcc lib 2";
    std::cout << "I am " << name << "!" << std::endl;
}

}