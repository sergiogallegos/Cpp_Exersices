#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ranges>

// Add two integers and returns the sum
int addTwo(int num1, int num2) {
    return num1 + num2;
}

// Prints all elements of an integer vector
void printVector(const std::vector<int>& vector) {
    if (vector.empty()) {
        std::cout << "The vector is empty." << std::endl;
        return;
    }
    for (int number : vector) {
        std::cout << number << " " ;
    }
    std::cout << std::endl;
}

int main() {
    std::cout << "Hello, C++!" << std::endl;
    
    // Test add_two
    int sumResult = addTwo(1, 2);
    std::cout << "Sum: " << sumResult << std::endl;

    // Test printVector
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    printVector(numbers);
    std::cout << "size: " << numbers.size() << std::endl;

    // Test printVector with an empty vector
    std::vector<int> emptyVec;
    printVector(emptyVec);

    // Compute mean and median temperatures
    std::vector<double> temps; // temperatures
    for (double temp; std::cin >> temp;) // read into temp
        temps.push_back(temp); // pump temp into vector
    
    // compute mean temperature:
    double sum = 0;
    for (double x : temps)
        sum += x;
    if(!temps.empty()) {
        std::cout << "Average temperature: " << sum/temps.size() << '\n';
    } else {
        std::cout << "No temperatures were entered.\n";
    }
    // compute median tempreature:
    std::ranges::sort(temps);
    std::cout << "Median tempreature: " << temps[temps.size()/2] << '\n';

    return 0;
}