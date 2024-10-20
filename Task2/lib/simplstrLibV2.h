// simplstr.h
#include <string>
using namespace std;


namespace simplstr {
    string reversed(string str);
    string find(string str, string substr);
    bool is_match(string str, string substr, int startPos);
    int rfind(string str, string substr);
}