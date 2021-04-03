#include <iostream>
#include "Maschine.hpp"

int main() {
    int snum = 0;
    int dnum = 0;
    int bnum = 0;
    int knum = 0;
   //TODO это важные строки

    std::cout << "Enter kmin, quantity of sources, devices und size of buffer\n";
    std::cin >> knum >> snum >> dnum >> bnum;
    Maschine maschine(knum, snum, dnum, bnum);
    std::cout << "Bibop\n";

    return 0;
}