#include <iostream>
#include <string>

using namespace std;

bool isValidIP(string ip) {
    int num = 0;
    int dotCount = 0;
    int length = ip.length();

    for (int i = 0; i < length; i++) {
        char c = ip[i];

        if (c == '.') {
            if (num < 0 || num > 255 || (i > 0 && ip[i - 1] == '.')) {
                return false;
            }
            dotCount++;
            num = -1;
        } else if (c >= '0' && c <= '9') {
            if (num == -1) {
                num = 0;
            }
            num = num * 10 + (c - '0');
        } else {
            return false;
        }
    }

    if (num < 0 || num > 255 || dotCount != 3) {
        return false;
    }

    return true;
}

int main() {
    string ip;
    cout << "Введите IP-адрес для проверки: ";
    cin >> ip;

    if (isValidIP(ip)) {
        cout << "Valid" << endl;
    } else {
        cout << "Invalid" << endl;
    }

    return 0;
}