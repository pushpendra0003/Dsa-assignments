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
    ofstream MyFile("filename.txt");
    double u = 0;
    clock_t start, end;
    int n = 10000;
    int a[n];
    int b[n];

    for(int j=0;j<n;j++){
      a[j]=rand()%1000000;
      b[j] = a[j];
    }
    for(int j=0; j<10000; j++){
    start = clock();
    quicksort(a, 0, n-1);
    end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);

    MyFile << time_taken<<endl;
    
    for(int j=0; j<n; j++){
        a[j] = b[j];
    }
    }

    return 0;
    }
    
