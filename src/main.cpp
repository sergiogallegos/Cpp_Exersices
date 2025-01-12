#include <iostream>
#include <string>

using namespace std;

int add_two(int a, int b) {
    return a + b;
}


int main() {
    cout << "Hello, Cross-Platform C++!" << endl;
    int result = add_two(1, 2);
    cout << result << endl;
    return 0;
}