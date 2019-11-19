#include <iostream>


#include "shared/Hello_clang_lib.h"

namespace clang_lib {
    void Hello::print(std::string name)
    {
        // Create a string variable
        std::cout << "I am clang lib! " << "Welcome: " << name << std::endl;
    }

}