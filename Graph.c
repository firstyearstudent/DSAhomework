#include <stdio.h>
#include <string.h>

#define MAX 7

typedef struct {
    long mssv;
    char name[50];
    float cpa;
    int visited;
} Student;

Student students[MAX];

// Đồ thị danh sách kề (adjacency matrix)
int adj[MAX][MAX] = {
    {0,1,1,1,0,0,0}, // 1
    {0,0,0,0,1,0,0}, // 2
    {0,0,0,0,1,0,0}, // 3
    {0,0,0,0,0,1,0}, // 4
    {0,0,0,0,0,1,1}, // 5
    {0,0,0,0,0,0,0}, // 6
    {0,0,0,0,1,0,0}  // 7
};

// Hàm duyệt DFS
void DFS(int v) {
    students[v].visited = 1;
    printf("MSSV: %ld, Ten: %s, CPA: %.2f\n", students[v].mssv, students[v].name, students[v].cpa);

    for (int i = 0; i < MAX; i++) {
        if (adj[v][i] && !students[i].visited) {
            DFS(i);
        }
    }
}

// Hàm tính CPA trung bình bằng BFS
float BFS_CPA(int start) {
    int queue[MAX];
    int front = 0, rear = 0;
    float sumCPA = 0;
    int count = 0;

    for (int i = 0; i < MAX; i++) students[i].visited = 0;

    queue[rear++] = start;
    students[start].visited = 1;

    while (front < rear) {
        int curr = queue[front++];
        sumCPA += students[curr].cpa;
        count++;

        for (int i = 0; i < MAX; i++) {
            if (adj[curr][i] && !students[i].visited) {
                queue[rear++] = i;
                students[i].visited = 1;
            }
        }
    }

    return count ? (sumCPA / count) : 0;
}

// Khởi tạo dữ liệu mẫu
void initData() {
    students[0] = (Student){1001, "Nguyen Van A", 3.1, 0};
    students[1] = (Student){1002, "Le Thi B",     3.5, 0};
    students[2] = (Student){1003, "Tran Van C",   2.8, 0};
    students[3] = (Student){1004, "Pham Thi D",   3.0, 0};
    students[4] = (Student){1005, "Do Van E",     3.6, 0};
    students[5] = (Student){1006, "Hoang Thi F",  3.3, 0};
    students[6] = (Student){1007, "Mai Van G",    3.9, 0};
}

int main() {
    initData();

    printf("Duyet DFS tu dinh 1:\n");
    DFS(0);

    printf("\nTinh diem trung binh CPA bang BFS:\n");
    float avgCPA = BFS_CPA(0);
    printf("CPA trung binh = %.2f\n", avgCPA);

    return 0;
}
