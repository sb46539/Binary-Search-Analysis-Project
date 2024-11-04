#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <algorithm>

int recursiveBinarySearch(const std::vector<int>& vec, int target, int left, int right) {
    if (left > right) return -1;
    int mid = (left + right) / 2;
    if (vec[mid] == target)
        return mid;
    else if (vec[mid] > target)
        return recursiveBinarySearch(vec, target, left, mid - 1);
    else
        return recursiveBinarySearch(vec, target, mid + 1, right);
}

int iterativeBinarySearch(const std::vector<int>& vec, int target) {
    int left = 0, right = vec.size() - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (vec[mid] == target)
            return mid;
        else if (vec[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int sequentialSearch(const std::vector<int>& vec, int target) {
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] == target)
            return i;
    }
    return -1;
}

int main() {
    int N = 1000000;
    double SumRBS = 0.0, SumIBS = 0.0, SumSeqS = 0.0;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1, 100000);

    for (int i = 0; i < 10; ++i) {
        std::vector<int> numbers(N);
        for (int& num : numbers) num = dist(gen);
        std::sort(numbers.begin(), numbers.end());

        int target = dist(gen);

        auto start = std::chrono::high_resolution_clock::now();
        recursiveBinarySearch(numbers, target, 0, numbers.size() - 1);
        auto end = std::chrono::high_resolution_clock::now();
        SumRBS += static_cast<double>(std::chrono::duration_cast<std::chrono::microseconds>(end - start).count());

        start = std::chrono::high_resolution_clock::now();
        iterativeBinarySearch(numbers, target);
        end = std::chrono::high_resolution_clock::now();
        SumIBS += static_cast<double>(std::chrono::duration_cast<std::chrono::microseconds>(end - start).count());

        start = std::chrono::high_resolution_clock::now();
        sequentialSearch(numbers, target);
        end = std::chrono::high_resolution_clock::now();
        SumSeqS += static_cast<double>(std::chrono::duration_cast<std::chrono::microseconds>(end - start).count());
    }

    std::cout << "Average Running Time for Recursive Binary Search in microseconds is  " << SumRBS / 10 << std::endl;
    std::cout << "Average Running Time for Iterative Binary Search in microseconds is " << SumIBS / 10 << std::endl;
    std::cout << "Average Running Time for Sequential Search in microseconds is " << SumSeqS / 10 << std::endl;

    return 0;
}
