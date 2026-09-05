#include <iostream>
int main() {
    int monday = 7, tuesday = 2;   // bugs filed
    double avg = (monday + tuesday) / 2.0;
    std::cout << "bugs per day: " << avg << "\n";   // 9 / 2 = 4.5... right?
    double share = 1.0 / 3;   // one bug split three ways
    std::cout << "share:        " << share << "\n";
    double avgr = static_cast<double>(monday + tuesday) / 2;
    std::cout<< avgr<<std::endl;  // 4.5, same idea
    std::cout<<static_cast<double>((monday + tuesday) / 2)<<std::endl;

}

/*basically, 9/2 = 4 but juss put 2.0 or 9.0-> and the output changes to 4.5, 
the entire right-hand side is evaluated first, in int, and only the finished result is converted,
but, explicit typecasting "THE RESULT" won't help, IT WORKS IFF IT'S IN THE QUESTION, 
static_cast<double>((monday + tuesday) / 2) is still 4,
moreover, truncation is towards 0, so x.5 -> x
*/