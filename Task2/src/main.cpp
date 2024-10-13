#include <iostream>
#include <regex>
using namespace std;

int main(){
    cout << "Enter your email for validation:" << endl;
    string email;
    cin >> email;

    regex r ("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
    regex_match(email, r) ? cout << "Email is valid" << endl : cout << "Email is not valid" << endl;
}