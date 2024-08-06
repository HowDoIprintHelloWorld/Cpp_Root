#include <iostream>
#include <string>
#include <cmath>
using namespace std;

string get_input() {
    string s;
    cout << "Please enter a number to root: ";
    getline(cin, s);
    return s;
}

int string_to_int(string s) {
    int i = 0;
    try {
       i = stoi(s);
    } catch (...) {
        cout << "[E] Problem converting! Number must be >= 0\n";
        i = -1;
    }
    return i;
}

bool verify_number(int number) {
    return number < 0;
}

float find_root(int number, float* minimum, float* maximum) {
    float middle_number = (*maximum + *minimum)/2;
    if (middle_number*middle_number > number) {
        *maximum = middle_number;
    } else {
        *minimum = middle_number;
    }
    return middle_number;
}

int get_number() {
    bool to_convert = true;
    string s = "";
    int number = 0;

    while (to_convert) {
        s = get_input();
        number = string_to_int(s);
        to_convert = verify_number(number);
    }
    return number;
}

int main() {
    int number = get_number();
    float minimum = 0;
    float maximum = number;
    float root = 0;

    for (int i = 0; i < 20; i++) {
        root = find_root(number, &minimum, &maximum);
    }
    root = round(root*100)/100;
    cout << "The string was: " << root << endl;
    return 1;
}