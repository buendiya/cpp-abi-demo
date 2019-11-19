#include <iostream>


#include "shared/Hello_clang_lib_2.h"

namespace clang_lib_2 {
    void Hello::print()
    {
        std::string name = "clang lib 2";
        std::cout << "I am " << name << "!"<< std::endl;
    }

}