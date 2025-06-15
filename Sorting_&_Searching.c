#include <stdio.h>
#define N 10

// Sắp xếp chèn (Insertion Sort)
void insertionSort(int a[], int n) {
    for(int i=1; i<n; i++) {
        int key = a[i], j = i-1;
        while(j>=0 && a[j]>key) {
            a[j+1]=a[j]; j--;
        }
        a[j+1]=key;
    }
}

// Sắp xếp chọn (Selection Sort)
void selectionSort(int a[], int n) {
    for(int i=0; i<n-1; i++) {
        int min=i;
        for(int j=i+1; j<n; j++)
            if(a[j]<a[min]) min=j;
        int t=a[i]; a[i]=a[min]; a[min]=t;
    }
}

// Sắp xếp nổi bọt (Bubble Sort)
void bubbleSort(int a[], int n) {
    for(int i=0; i<n-1; i++)
        for(int j=0; j<n-i-1; j++)
            if(a[j]>a[j+1]) {
                int t=a[j]; a[j]=a[j+1]; a[j+1]=t;
            }
}

// Sắp xếp nổi bọt cải tiến
void improvedBubbleSort(int a[], int n) {
    int swapped;
    for(int i=0; i<n-1; i++) {
        swapped=0;
        for(int j=0; j<n-i-1; j++)
            if(a[j]>a[j+1]) {
                int t=a[j]; a[j]=a[j+1]; a[j+1]=t;
                swapped=1;
            }
        if(!swapped) break;
    }
}

// Sắp xếp nhanh (Quick Sort)
void quickSort(int a[], int l, int r) {
    if(l>=r) return;
    int pivot=a[l], i=l, j=r;
    while(i<j) {
        while(i<j && a[j]>=pivot) j--;
        if(i<j) a[i++]=a[j];
        while(i<j && a[i]<=pivot) i++;
        if(i<j) a[j--]=a[i];
    }
    a[i]=pivot;
    quickSort(a,l,i-1);
    quickSort(a,i+1,r);
}

// Sắp xếp vun đống (Heap Sort)
void heapify(int a[], int n, int i) {
    int largest=i, l=2*i+1, r=2*i+2;
    if(l<n && a[l]>a[largest]) largest=l;
    if(r<n && a[r]>a[largest]) largest=r;
    if(largest!=i) {
        int t=a[i]; a[i]=a[largest]; a[largest]=t;
        heapify(a,n,largest);
    }
}
void heapSort(int a[], int n) {
    for(int i=n/2-1;i>=0;i--) heapify(a,n,i);
    for(int i=n-1;i>0;i--) {
        int t=a[0]; a[0]=a[i]; a[i]=t;
        heapify(a,i,0);
    }
}

// Sắp xếp trộn (Merge Sort)
void merge(int a[], int l, int m, int r) {
    int n1=m-l+1, n2=r-m;
    int L[n1], R[n2];
    for(int i=0;i<n1;i++) L[i]=a[l+i];
    for(int i=0;i<n2;i++) R[i]=a[m+1+i];
    int i=0,j=0,k=l;
    while(i<n1 && j<n2) a[k++]=L[i]<R[j]?L[i++]:R[j++];
    while(i<n1) a[k++]=L[i++];
    while(j<n2) a[k++]=R[j++];
}
void mergeSort(int a[], int l, int r) {
    if(l<r) {
        int m=(l+r)/2;
        mergeSort(a,l,m);
        mergeSort(a,m+1,r);
        merge(a,l,m,r);
    }
}

// Tìm kiếm nhị phân
int binarySearch(int a[], int n, int x) {
    int l=0, r=n-1;
    while(l<=r) {
        int m=(l+r)/2;
        if(a[m]==x) return m;
        if(a[m]<x) l=m+1; else r=m-1;
    }
    return -1;
}

// In mảng
void printArray(int a[], int n) {
    for(int i=0;i<n;i++) printf("%d ",a[i]);
    printf("\n");
}

// Chương trình chính
int main() {
    int a[N] = {58, 22, 76, 11, 18, 54, 7, 9, 21, 8};
    printf("Mang ban dau:\n"); printArray(a,N);

    // Sử dụng từng giải thuật:
    int b[N];
    // Insertion Sort
    for(int i=0;i<N;i++) b[i]=a[i];
    insertionSort(b,N); printf("Insertion Sort: "); printArray(b,N);

    // Selection Sort
    for(int i=0;i<N;i++) b[i]=a[i];
    selectionSort(b,N); printf("Selection Sort: "); printArray(b,N);

    // Bubble Sort
    for(int i=0;i<N;i++) b[i]=a[i];
    bubbleSort(b,N); printf("Bubble Sort: "); printArray(b,N);

    // Improved Bubble Sort
    for(int i=0;i<N;i++) b[i]=a[i];
    improvedBubbleSort(b,N); printf("Improved Bubble Sort: "); printArray(b,N);

    // Quick Sort
    for(int i=0;i<N;i++) b[i]=a[i];
    quickSort(b,0,N-1); printf("Quick Sort: "); printArray(b,N);

    // Heap Sort
    for(int i=0;i<N;i++) b[i]=a[i];
    heapSort(b,N); printf("Heap Sort: "); printArray(b,N);

    // Merge Sort
    for(int i=0;i<N;i++) b[i]=a[i];
    mergeSort(b,0,N-1); printf("Merge Sort: "); printArray(b,N);

    // Binary Search (trên mảng đã sắp xếp)
    int idx = binarySearch(b,N,54);
    printf("Tim 54 trong mang da sap xep: %s\n", idx!=-1?"Tim thay":"Khong tim thay");

    return 0;
}