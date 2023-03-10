#include <iostream>
#include <chrono>
#include <math.h>
#include <map>

std::map <int, int> experimentalMap;


/**Writes 10^n pairs into the map and writes how much time & memory does it take*/
void memory_allocation(int power){
    int maxElements = pow(10, power);
    auto tStart = std::chrono::high_resolution_clock::now();

    for(int j = 0; j < maxElements; j++){
        experimentalMap.insert( { j, j } );
    }
    auto tEnd = std::chrono::high_resolution_clock::now();
    experimentalMap.clear();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(tEnd - tStart).count() << " " << 2 * sizeof(int) * maxElements / 1024.0 << " ";
}

/**The main function*/
int main(){
    for (int power = 0; power <= 7; power++){
        memory_allocation(power);
    }
    return 0;
}
