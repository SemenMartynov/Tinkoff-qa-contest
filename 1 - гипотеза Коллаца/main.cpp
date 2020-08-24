
#include <iostream>

unsigned collatz(int num, unsigned counter = 0) {
    if (num == 1)
        return counter;

    if(num % 2 == 0)
        return collatz(num / 2, ++counter);
    return collatz(3 * num + 1, ++counter);
}

int main(int argc, char** argv) {
    int l = 0;
    int r = 0;
    std::cin >> l >> r;
    unsigned long accum = 0;

    for (int i = l; i <= r; i++) {
        accum += collatz(i);
    }

    std::cout << accum << std::endl;
}