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

int main(){
    int arr[9] = {10, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
    for(int i=0; i<=8; i++){
    clock_t start, end;
    int n = arr[i];
    int a[n];
    int b[n];
    double sum = 0;
    for(int j=0;j<n;j++){
      a[j]=rand()%1000000;
      b[j] = a[j];
    }
    for(int j=0; j<10000; j++){
    start = clock();
    quicksort(a, 0, n-1);
    end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    sum += time_taken;
    for(int j=0; j<n; j++){
        a[j] = b[j];
    }
    }
    sum = sum/10000;
    cout << "Average time taken by randomised quick sort : ";
    cout << "Size " << n << " , " << "Time taken "<< sum << endl << endl;
    }
    return 0;
}