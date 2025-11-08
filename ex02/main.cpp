#include <cstdlib>
#include <iostream>
#include <ostream>
#include "Array.hpp"


#define MAX_VAL 10

int main()
{
    Array<double> numbers(MAX_VAL);
    double* mirror = new double[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++) {
        const double value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<double> tmp = numbers;
        Array<double> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++) {
        if (mirror[i] != numbers[i]) {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try {
        numbers[-2] = 0;
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    try {
        numbers[MAX_VAL] = 0;
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    for (double i = 0; i < MAX_VAL; i++) {
        numbers[i] = rand();
    }
    for (double i = 0; i < MAX_VAL; i++) {
        std::cout << numbers[i] << std::endl;
    }
    delete [] mirror;
    return 0;
}
