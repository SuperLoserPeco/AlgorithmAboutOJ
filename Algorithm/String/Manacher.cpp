#include <cstring>
#include <iostream>
#include <algorithm>

#include "Manacher.h"

namespace Algorithm::String
{

class Manacher
{
private:
    int* p;
    char* str;

    int strLen;
    int manacherLen;
public: 
    Manacher() {

    }

    int ManacherInitTest(char* s) {
        std::cout << strlen(s) << std::endl;
        int sz = strlen(s);
        str = new char[sz];
        strncpy(str, s, sz);
        std::cout << strlen(str) << std::endl;



        return 0;
    }

    int ManacherInit(char* s) {
        strLen = strlen(s);
        manacherLen = (strLen + 1) * 2 + 1;

        str = new char[manacherLen];
        p = new int[manacherLen];

        for(int i = 0; i < manacherLen; i++) p[i] = 0;

        for(int i = 1; i <= strLen; i++) {
            str[i * 2] = s[i - 1];
            str[i * 2 + 1] = '#';
        }

        str[0] = '?'; str[1] = '#'; str[manacherLen - 1] = '\0';

        int res = 0, k = 0, maxk = 0;
        for(int i = 2; i < manacherLen; i++) {
            p[i] = i < maxk ? std::min(maxk - i, p[2 * k - i]) : 1;
            while((i - p[i] >= 0) && (i + p[i] < manacherLen)
                    && str[i - p[i]] == str[i + p[i]]) p[i]++;
            if(p[i] + i > maxk) {
                k = i;
                maxk = p[i] + i;
            }
            res = std::max(res, p[i]);
        }
        return res - 1;
    }

    int LengthOfGivenLocation(int locate, bool isOdd) {
        int manacherLocate = (locate + 1) * 2;
        if(isOdd) {
            return ((p[manacherLocate] / 2) * 2 - 1);
        }
        else {
            return ((p[manacherLocate + 1] / 2) * 2);
        }
    }

    void Print() {
        for(int i = 0; i < strLen; i++) {
            std::cout << "odd " << i << " = " << LengthOfGivenLocation(i, true) << std::endl;
            std::cout << "not odd " << i << " = " << LengthOfGivenLocation(i, false) << std::endl;
        }
    }
};

}


/*****************main start***********************/
// #include <iostream>
// using namespace std;

// int main() {
//     char* s = "qseswseaae";
//     Algorithm::String::Manacher m;
//     m.ManacherInit(s);
//     m.Print();
//     return 0;
// }
/*****************main   end***********************/