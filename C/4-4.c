#include <stdio.h>

int main() {
    int N, M;
    int arr[100][100];
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            arr[i][j] = 0;
        }
    }
    
    int cnt = 1;
    int row = 0,col=0; 
    while (row < N || col < M) {
        if (col < M) {
            int i = row, j = col;
            while (j >= 0 && i < N) {
                arr[i][j] = cnt++;
                --j;
                ++i;
            }
            ++col;
        }
        else {
            ++row;
            int i = row, j = col-1;
            while (j >= 0 && i < N) {
                arr[i][j] = cnt++;
                --j;
                ++i;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf(" %d", arr[i][j]);

        }
        printf("\n");
    }
}
