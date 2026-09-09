#include <iostream>
#include <vector>

int main() {
    std::vector<int> nums = {0, 0, 0};
    std::vector<bool> flags = {false, false, false};
    //auto n = nums[0];   // copy the first number
    // n = 42;             // change the copy
    auto f = flags[0];   // copy the first flag
    f = true;            // change the copy
    // what if i do n =42 and then nums[0] = n;
    auto n= nums[0];
    n =42;
    nums[0] = n;  // now nums[0] = 42 will be the output
    std::cout << std::boolalpha;
    std::cout << "n = " << n << ", nums[0]  = " << nums[0] << '\n';  // expected ans- n =42, nums_0 = 42 but no
    std::cout << "f = " << f << ", flags[0] = " << flags[0] << '\n';  // expected ans- f = true, flags_0 = true, yea here it works
    /*
    WHY- 
    basically vector bool behaves differently 
    moreover it's the auto key word that is in play here
    auto n= nums[0] basically sees what dt is nums[0] 
    (coz nums[0] ka return type is int& ) and then init's n to that datatype
    so when we do n=42, only n ka value changes

    
    */
}
