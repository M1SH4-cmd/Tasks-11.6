#include <iostream>
using namespace std;

bool isFirstPartValid(string firstPart){
    for(int i = 0; i < firstPart.length(); i++){
        if((firstPart[i] < 'A' && firstPart[i] > 'Z') || (firstPart[i] < 'a' && firstPart[i] > 'z') || (firstPart[i] != '.' || firstPart[i] != '-' || firstPart[i] != '_')){
            return false;
        }else if(firstPart[i] == '.' && firstPart[i + 1] == '.'){
                return false;
        }else if(firstPart[i] == '@' && firstPart[i + 1] == '@'){
            return false;
        }
    }
    return true;
}


bool isSecondPartValid(string secondPart){
    for(int i = 0; i < secondPart.length(); i++){
        if((secondPart[i] < 'a' && secondPart[i] > 'z') || (secondPart[i] != '.' || secondPart[i] != '-' || secondPart[i] != '_')){
            return false;
        }else if(secondPart[i] == '.' && secondPart[i + 1] == '.'){
                return false;
        }
    }
    return true;
}




bool isValidEmail(string email) {
    int dogPos = email.find('@');
    if(email.find('@', dogPos)){
        return false;
    }
    string firstPart = email.substr(0, dogPos);
    string secondPart = email.substr(dogPos, email.length());
    int frstLen = firstPart.length();


    if(frstLen > 64){
        return false;
    }

    bool valid = isFirstPartValid(firstPart) && isSecondPartValid(secondPart);
    if(valid){
        return true;
    }
    return false;
}








int main() {
    string email;
    cout << "Enter your email for validation:" << endl;
    cin >> email;
    
    if (isValidEmail(email)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    
    return 0;
}