#include <string>
#include "shared/Hello.h"

using namespace std;

int main(int argc, char *argv[])
{
    Hello hi;
    string name = "clang lib";
    hi.print(name);
    return 0;
}
