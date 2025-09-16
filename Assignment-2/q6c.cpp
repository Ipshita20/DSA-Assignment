#include<iostream>
using namespace std;
void dispSparse(int sparse[][3], int size) {
    for (int i=0; i<size; i++) {
        cout<<sparse[i][0]<<" "<<sparse[i][1]<< " "<<sparse[i][2]<<endl;
    }
}
int multiplySparse(int A[][3], int sizeA, int B[][3], int sizeB, int C[][3], int m, int n, int p) {
    int k=0;
    for (int i=0; i<m; i++) {
        for (int j=0; j<p; j++) {
            int sum=0;
            for (int x=0; x<sizeA; x++) {
                if (A[x][0]==i) {
                    for (int y=0; y<sizeB; y++) {
                        if (B[y][0]==A[x][1] && B[y][1]==j) {
                            sum += A[x][2]*B[y][2];
                        }
                    }
                }
            }
            if (sum!=0) {
                C[k][0]=i; 
                C[k][1]=j; 
                C[k][2]=sum;
                k++;
            }
        }
    }
    return k;
}
int main() {
    int m, n, p, q;
    cout<<"Enter size of Matrix A (m x n): ";
    cin>>m>>n;
    int a[m][n];
    cout<<"Enter elements of Matrix A:\n";
    for (int i=0; i<m; i++)
        for (int j=0; j<n; j++)
            cin>>a[i][j];
    cout<<"Enter size of Matrix B (p x q): ";
    cin>>p>>q;
    int b[p][q];
    cout<<"Enter elements of Matrix B:\n";
    for (int i=0; i<p; i++)
        for (int j=0; j<q; j++)
            cin>>b[i][j];
    if (n!=p) {
        cout<<"Multiplication not possible (incompatible dimensions)."<<endl;
        return 0;
    }
    int sizeA=0;
    for (int i=0; i<m; i++)
        for (int j=0; j<n; j++)
            if (a[i][j]!=0) 
            sizeA++;
    int A[sizeA][3], rowA=0;
    for (int i=0; i<m; i++)
        for (int j=0; j<n; j++)
            if (a[i][j]!=0) {
                A[rowA][0]=i;
                 A[rowA][1]=j;
                  A[rowA][2]=a[i][j];
                rowA++;
            }
    int sizeB=0;
    for (int i=0; i<p; i++)
        for (int j=0; j<q; j++)
            if (b[i][j]!=0) 
            sizeB++;
    int B[sizeB][3], rowB=0;
    for (int i=0; i<p; i++)
        for (int j=0; j<q; j++)
            if (b[i][j]!=0) {
                B[rowB][0]=i; B[rowB][1]=j; B[rowB][2]=b[i][j];
                rowB++;
            }
    cout<<"\nSparse Matrix A:\n"; 
    dispSparse(A, rowA);
    cout<<"\nSparse Matrix B:\n";
    dispSparse(B, rowB);
    int C[m*q][3];
    int sizeC = multiplySparse(A, rowA, B, rowB, C, m, n, q);
    cout<<"\nA*B in sparse form:\n";
    dispSparse(C, sizeC);
    return 0;
}
