#include <iostream>
#include <vector>

int main() {
    std::vector<int> tasks{10, 20, 30};
    std::cout << "size " << tasks.size() << ", capacity " << tasks.capacity() << "\n";
    // the problem is that till here the size of tasks is now constrained to 3
    // so, when i run for loop, it runs past the vector of size 3, and the moment i try to push_back a new value,
    // vector reallocation happens, and that means, old vector address gets killed, and so new vector is made
    // but at that point, the for loop is still pointing to the old vector 
    // new vector's address could be 0x200-0x212 [10,20,30,99] if old was 0x100-0x108 [10,20,30]
    // the pointer point's to 10 initially(0x100), but apart from that 0x100, 0x104,108 are filled with garbage values 
    for (int t : tasks) {
        std::cout << "handling " << t << "\n";
        if (t == 10)
            tasks.push_back(99);   // task 10 spawns a follow-up task
    }
    std::cout<<"FIXED:"<<std::endl;
    // the fix- rely on indexes
    const std::size_t n = tasks.size();  // n implies the og nums of tasks
    // for(std::size_t i =0; i<tasks.size();i++ ) implies, keep going as the vector grows
    for(std::size_t i =0; i<n; ++i){ // this implies- only process the tasks that existed when the loop started.
        std::cout<<"handling"<<tasks[i]<<std::endl;
        if(tasks[i]==10){     // tasks[i] asks the vector for the values "again"
            tasks.push_back(99); 
            // 10 is checked, then we pushback 99, then the go back to for loop, and the size is now 4 instead of 3
        }
    }
}