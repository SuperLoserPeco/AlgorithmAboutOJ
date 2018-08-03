/*****************main start***********************/
#include <iostream>
#include "Algorithm.h"

using namespace std;


int main() {
    char* s = "qseswseaae";
    Algorithm::String::Manacher m;
    m.ManacherInit(s);
    m.Print();
    return 0;
}
/*****************main   end***********************/