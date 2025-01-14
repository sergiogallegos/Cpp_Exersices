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

// Test Exceptions
class Bad_area {};

int area(int length, int width) {
  if (length <= 0 || width <= 0)
	throw Bad_area{};
  return length * width;
}

constexpr int frame_width = 2;

int framed_area(int x, int y) {
  return area(x-frame_width, y-frame_width);
}

void test(int x, int y, int z) {
  int area1 = area(x, y);
  //int area2 = framed_area(1, z);
  int area3 = framed_area(y, z);
  double ratio = area1 / area3;
}

int main() {
    std::cout << "Hello, C++!" << std::endl;
	
	// Test Exceptions
	try {
	  test(-1, 2, 4);
	}
	catch(Bad_area) {
	  std::cout << "Oops! bad arguments to area()\n"; 
	}

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
	std::vector<double>::size_type max_values = 5; // Match std::vector::size_type
    for (double temp; temps.size() < max_values && std::cin >> temp;) { // read into temp
        temps.push_back(temp); // pump temp into vector
	}
    
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
