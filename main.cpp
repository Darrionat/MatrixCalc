#include <iostream>
#include "Matrix.h"
#include <ctime>

using namespace std;

int main() {
    cout << "Type the size of the nxn matrix you want." << endl;
    cout << "For n < 11" << endl;

    int m;
    cin >> m;
    if (m > 10) {
        main();
        return 0;
    }

    int n = m;
    cout << "Generating random matrix" << endl;
    long start = time(NULL);
    Matrix matrix(m, n);
    // Seeds the random
    srand(start);

    for (int col = 0; col < n; col++) {
        Vector vec(m);
        for (int row = 0; row < m; row++) {
            int min = -10;
            int max = 10;
            int randNum = rand() % (max - min + 1) + min;

            vec.setCoord(row + 1, randNum);
        }
        matrix.setColVector(col, vec);
    }

    matrix.print();
    //cout << time(NULL) << endl;
    cout << "Determinant =" << matrix.det() << endl;
    cout << "Time taken: " << time(NULL) - start << "s" << endl;
    return 0;
}