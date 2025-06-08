#include <stdio.h>
#define SIZE 10

int hash(int k) { return k % SIZE; }

void insert(int table[], int k) {
    int idx = hash(k);
    int start = idx;
    while(table[idx]!=-1) {
        idx = (idx+1)%SIZE;
        if(idx==start) { printf("Bang day!\n"); return; }
    }
    table[idx]=k;
}

int search(int table[], int k) {
    int idx = hash(k), start = idx;
    while(table[idx]!=-1) {
        if(table[idx]==k) return idx;
        idx = (idx+1)%SIZE;
        if(idx==start) break;
    }
    return -1;
}

int main() {
    int D[] = {23, 43, 13, 27, 34, 54, 21, 33};
    int table[SIZE];
    for(int i=0;i<SIZE;i++) table[i]=-1;

    for(int i=0;i<8;i++) insert(table, D[i]);

    printf("Bang bam:\n");
    for(int i=0;i<SIZE;i++) printf("%2d: %2d\n",i,table[i]);

    int x=34;
    int idx = search(table,x);
    if(idx!=-1) printf("Tim thay %d o vi tri %d\n",x,idx);
    else printf("Khong tim thay %d\n",x);

    return 0;
}