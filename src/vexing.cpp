#include <iostream>

struct Timer {
    Timer() { std::cout << "timer started\n"; }
};
// anything that can be parsed as a declaration is a declaration
int main() {
    // issue
    Timer t();
    // resulve
    Timer t1{};
    Timer t2;   
}