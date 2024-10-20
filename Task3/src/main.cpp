#include <iostream>
#include <regex>
using namespace std;

int main(){
    cout << "Enter your IP address for validation:" << endl;
    string ip;
    cin >> ip;

    regex r("^((25[0-5]|(2[0-4]|1\d|[1-9]|)\d)\.?\b){4}$");

    regex_match(ip, r) ? cout << "IP is valid" << endl : cout << "Invalid IP" << endl;
}
