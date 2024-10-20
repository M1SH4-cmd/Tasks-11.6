#include <iostream>
using namespace std;

bool isFirstPartValid(string firstPart) {
    if (firstPart.length() < 1 || firstPart.length() > 64) return false;

    bool lastWasDot = false;

    for (int i = 0; i < firstPart.length(); i++) {
        char c = firstPart[i];

        if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || 
              (c >= '0' && c <= '9') || c == '.' || c == '-' || 
              c == '!' || c == '#' || c == '$' || c == '%' || 
              c == '&' || c == '\'' || c == '*' || c == '+' || 
              c == '/' || c == '=' || c == '?' || c == '^' || 
              c == '_' || c == '`' || c == '{' || c == '|' || c == '}' || c == '~')) {
            return false;
        }

        if (c == '.') {
            if (lastWasDot) {
                return false;
            }
            lastWasDot = true;
        } else {
            lastWasDot = false;
        }
    }

    if (firstPart.front() == '.' || firstPart.back() == '.') {
        return false;
    }

    return true;
}

bool isSecondPartValid(string secondPart) {
    if (secondPart.length() < 1 || secondPart.length() > 63) return false;

    bool lastWasDot = false; 

    for (int i = 0; i < secondPart.length(); i++) {
        char c = secondPart[i];

        if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || 
              (c >= '0' && c <= '9') || c == '.' || c == '-')) {
            return false;
        }

        if (c == '.') {
            if (lastWasDot) {
                return false;
            }
            lastWasDot = true;
        } else {
            lastWasDot = false;
        }
    }

    if (secondPart.front() == '.' || secondPart.back() == '.') {
        return false;
    }

    return true;
}

bool isValidEmail(string email) {
    int dogPos = -1;

    
    for (int i = 0; i < email.length(); i++) {
        if (email[i] == '@') {
            if (dogPos != -1) {
                return false;
            }
            dogPos = i;
        }
    }

    
    if (dogPos == -1 || dogPos == 0 || dogPos == email.length() - 1) {
        return false;
    }

    string firstPart = email.substr(0, dogPos);
    string secondPart = email.substr(dogPos + 1); 

    return isFirstPartValid(firstPart) && isSecondPartValid(secondPart);
}

int main() {
    string email;
    cout << "Enter email for validation:" << endl;
    cin >> email;

    if (isValidEmail(email)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}