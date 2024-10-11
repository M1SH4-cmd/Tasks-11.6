#include <iostream>
using namespace std;

string encrypt_caesar(string text, int code){
    for(int i = 0; i < text.length(); i++){
        if(!isalpha(text[i])){
            continue;
        }else if(text[i] >= 'A' && text[i] <= 'Z'){
            text[i] = ((text[i] - 'A' + code) % 26) + 'A';
        }else if(text[i] >= 'a' && text[i] <= 'z'){
            text[i] = ((text[i] - 'a' + code) % 26) + 'a';
        }
    }
    return text;
}

// Almoust working :(

// string decrypt_caesar(string text, int code){
//     for (int i = 0; i < text.length(); i++) {
//         if (!isalpha(text[i])) {
//             continue;
//         } else if (text[i] >= 'A' && text[i] <= 'Z') {
//             text[i] = ((text[i] - 'A' - code + 26) % 26) + 'A';
//         } else if (text[i] >= 'a' && text[i] <= 'z') {
//             text[i] = ((text[i] - 'a' - code + 26) % 26) + 'a';
//         }
//     }
//     return text;
// }



int main(){

    string text = "The quick brown fox jumps over the lazy dog*";
    int code = 29;
    cout << encrypt_caesar(text, code) << endl;

    cout << decrypt_caesar(encrypt_caesar(text, code), code) << endl;
}
