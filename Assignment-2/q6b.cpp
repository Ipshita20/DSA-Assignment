#include<iostream>
using namespace std;

void dispSparse(int sparse[][3], int size) {
    for (int i = 0; i < size; i++) {
        cout << sparse[i][0] << " " << sparse[i][1] << " " << sparse[i][2] << endl;
    }
}

int addSparse(int A[][3], int sizeA, int B[][3], int sizeB, int C[][3]) {
    int i = 0, j = 0, k = 0;
    while (i < sizeA && j < sizeB) {
        if (A[i][0] == B[j][0] && A[i][1] == B[j][1]) { 
            C[k][0] = A[i][0];
            C[k][1] = A[i][1];
            C[k][2] = A[i][2] + B[j][2];
            i++; j++; k++;
        }
        else if (A[i][0] < B[j][0] || (A[i][0] == B[j][0] && A[i][1] < B[j][1])) {
            C[k][0] = A[i][0]; C[k][1] = A[i][1]; C[k][2] = A[i][2];
            i++; k++;
        }
        else {
            C[k][0] = B[j][0]; C[k][1] = B[j][1]; C[k][2] = B[j][2];
            j++; k++;
        }
    }
    while (i < sizeA) { C[k][0] = A[i][0]; C[k][1] = A[i][1]; C[k][2] = A[i][2]; i++; k++; }
    while (j < sizeB) { C[k][0] = B[j][0]; C[k][1] = B[j][1]; C[k][2] = B[j][2]; j++; k++; }
    return k;
}

int main() {
    int m, n;
    cout << "Enter size of matrices (m x n): ";
    cin >> m >> n;

    int a[m][n], b[m][n];
    cout << "Enter elements of Matrix A:\n";
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    cout << "Enter elements of Matrix B:\n";
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> b[i][j];

    // Convert A to sparse
    int sizeA = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (a[i][j] != 0) sizeA++;

    int A[sizeA][3], rowA = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (a[i][j] != 0) {
                A[rowA][0] = i; A[rowA][1] = j; A[rowA][2] = a[i][j];
                rowA++;
            }

    // Convert B to sparse
    int sizeB=0;
    for (int i=0; i<m; i++)
        for (int j=0; j<n; j++)
            if (b[i][j]!=0) sizeB++;

    int B[sizeB][3], rowB=0;
    for (int i=0; i<m; i++)
        for (int j=0; j<n; j++)
            if (b[i][j]!=0) {
                B[rowB][0]=i; 
                B[rowB][1]=j; 
                B[rowB][2]=b[i][j];
                rowB++;
            }
    cout<<"\nSparse Matrix A:\n"; 
    dispSparse(A, rowA);
    cout<<"\nSparse Matrix B:\n"; 
    dispSparse(B, rowB);
    int C[sizeA+sizeB][3];
    int sizeC=addSparse(A, rowA, B, rowB, C);
    cout<<"\nA + B in sparse form:\n";
    dispSparse(C, sizeC);
    return 0;
}
