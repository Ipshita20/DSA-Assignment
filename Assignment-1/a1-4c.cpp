#include<iostream>
using namespace std;

int main() 
{
    int m, n;
    cout << "Enter rows and cols of matrix: ";
    cin >> m >> n;

    int A[m][n], T[n][m];

    cout << "Enter elements of matrix:\n";
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            T[j][i] = A[i][j];

    cout << "Transpose Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << T[i][j] << " ";
        cout << endl;
    }
}
