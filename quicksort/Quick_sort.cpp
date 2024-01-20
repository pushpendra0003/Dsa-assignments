#include <bits/stdc++.h>
using namespace std;

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;  
}

int partionArray(int a[], int l, int h){
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

int random_pivot(int a[], int l, int h){
    int pvt, n, indx;
    n = rand();
    pvt = l + n%(h-l+1);
    swap(&a[pvt], &a[h]);
    return partionArray(a, l, h);
}

void quicksort(int a[], int l, int h){
    int stack[h-l+1];
    int top = -1;
    stack[++top] = l;
    stack[++top] = h;

    while(top>=0){
        h = stack[top--];
        l = stack[top--];


        int p = random_pivot(a, l, h);

        if(p-1>l){
            stack[++top] = l;
            stack[++top] = p-1;
        }

        if(p+1<h){
            stack[++top] = p+1;
            stack[++top] = h;
        }
    }
}

void print(int a[], int n){
    cout << "Sorted Array" << endl;
    for(int i=0; i<n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

int main(){
    cout << "Enter the size of the Array" << endl;
    int n;
    cin >> n;
    int a[n];
    cout << "Enter the elements of the Array" << endl;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    for(int i=0; i<1000; i++){
    quicksort(a, 0, n-1);
    }
    print(a, n);
    return 0;
}