#include <iostream>
#include "my_vector.h"

int main() {
    my_vector::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    std::cout << "size: " << vec.size() << std::endl;
    std::cout << "capacity: " << vec.capacity() << std::endl;

    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << "vector[" << i << "] = " << vec[i] << std::endl;
    }

    return 0;
}