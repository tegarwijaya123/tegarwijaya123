#include <iostream>
using namespace std;

int main() {
    int row1, col1, row2, col2;

    // Input ukuran matriks pertama
    cout << "Masukkan jumlah baris matriks pertama: ";
    cin >> row1;
    cout << "Masukkan jumlah kolom matriks pertama: ";
    cin >> col1;

    // Input ukuran matriks kedua
    cout << "Masukkan jumlah baris matriks kedua: ";
    cin >> row2;
    cout << "Masukkan jumlah kolom matriks kedua: ";
    cin >> col2;

    // Periksa apakah perkalian matriks dapat dilakukan
    if (col1 != row2) {
        cout << "Perkalian matriks tidak dapat dilakukan karena jumlah kolom matriks pertama tidak sama dengan jumlah baris matriks kedua." << endl;
        return 1;
    }

    // Inisialisasi matriks pertama
    int matrix1[row1][col1];
    cout << "Masukkan elemen-elemen matriks pertama:" << endl;
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col1; j++) {
            cin >> matrix1[i][j];
        }
    }

    // Inisialisasi matriks kedua
    int matrix2[row2][col2];
    cout << "Masukkan elemen-elemen matriks kedua:" << endl;
    for (int i = 0; i < row2; i++) {
        for (int j = 0; j < col2; j++) {
            cin >> matrix2[i][j];
        }
    }

    // Matriks hasil perkalian
    int result[row1][col2];

    // Melakukan perkalian matriks
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < col1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }


    // Menampilkan matriks hasil perkalian
    cout << "Matriks hasil perkalian:" << endl;
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}


