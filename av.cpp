#include <iostream>
using namespace std;

void towerOfHanoi(int n, char source, char destination, char auxiliary) {
    if (n == 1) {
        cout << "Di chuyen dia 1 tu " << source << " toi " << destination << endl;
    }
    else {
        towerOfHanoi(n - 1, source, auxiliary, destination);
        cout << "Di chuyen dia " << n << " tu " << source << " toi " << destination << endl;
        towerOfHanoi(n - 1, auxiliary, destination, source);
    }
}

int main() {
    int n = 3;  // Số lượng đĩa ban đầu
    towerOfHanoi(n, 'A', 'C', 'B');  // A là nguồn, C là đích, B là cọc trung gian

    return 0;
}