#include <iostream>
#include <random>

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1, 100);

    for (int i = 0; i < 5; ++i) {
        int randomNum = dist(gen);
        std::cout << randomNum << std::endl;
    }

    return 0;
}
