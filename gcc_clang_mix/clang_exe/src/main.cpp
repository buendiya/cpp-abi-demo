#include <string>
#include "shared/Hello_gcc_lib.h"
#include "shared/Hello_gcc_lib_2.h"
#include "shared/Hello_clang_lib.h"
#include "shared/Hello_clang_lib_2.h"

using namespace std;

int main(int argc, char *argv[])
{
    string name = "clang exe";

    gcc_lib::Hello gcc_lib_hi;
    gcc_lib_hi.print(name);

    gcc_lib_2::Hello gcc_lib_2_hi;
    gcc_lib_2_hi.print();


    // clang_lib::Hello clang_lib_hi;
    // clang_lib_hi.print(name);

    clang_lib_2::Hello clang_lib_2_hi;
    clang_lib_2_hi.print();

    return 0;
}
