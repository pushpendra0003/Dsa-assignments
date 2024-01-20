#include <bits/stdc++.h>
using namespace std;

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;  
}

void print(int a[], int l, int h){
    for(int i=l; i<=h; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

int partitionArray(int a[], int l, int h, int pivotIndex, int n){
    swap(a[pivotIndex], a[h]);
    int x = a[h];
    int idx = l-1;
    for(int j=l; j<h; j++){

        if(a[j] <= x){
            idx++;
            swap(&a[j], &a[idx]);
        }
    }
    swap(&a[idx+1], &a[h]);
    return idx+1;
}

void quickSort(int a[], int low, int high, int b[], int n) {
    if (low < high) {
        int pivotIndex;
        for (pivotIndex = low; pivotIndex <= high; ++pivotIndex) {
            for(int i=0; i<n; i++){
                a[i] = b[i];
            }

            cout << a[pivotIndex] <<"->";

            int partitionIndex = partitionArray(a, low, high, pivotIndex, n-1);

            int c[n];
            for(int i=0; i<n; i++){
                c[i] = a[i];
            }
            
            print(a, low, high);

            quickSort(a, low, partitionIndex - 1, c ,n);
            quickSort(a, partitionIndex + 1, high, c ,n);
        }
    }
    else if(low==high) {
        cout<<a[low]<<"->"<<endl;
    }
}

int main(){
    cout << "Enter the size of the Array" << endl;
    int n;
    cin >> n;
    int a[n];
    int b[n];
    cout << "Enter the elements of the Array" << endl;
    for(int i=0; i<n; i++){
        cin >> a[i];
        b[i]=a[i];

    }
    quickSort(a, 0, n-1, b, n);
    print(a, 0, n-1);
    return 0;
}
