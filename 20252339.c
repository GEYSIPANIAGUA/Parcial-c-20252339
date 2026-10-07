# include <stdio.h> 
int main(void) {
int N, M, L, U;
int matriz [30][30]; 
int i, j;
scanf("%d %d %d %d", &N, &M, &L, &U);
if (N < 1 || N > 30 || M < 1 || M > 30) {
    printf("ERROR\n");
    return 0;
}
if (L < 0 || L > U || U > 1000) {
    printf("ERROR\n");
    return 0;
}
for (i = 0; i < N; i++) {
    for (j = 0; j < M; j++) {
        scanf("%d", &matriz[i][j]);
        if (matriz[i][j] < 0 || matriz[i][j] > 1000) {
            printf("ERROR\n");
            return 0;
        }
    }
}
return 0;
}