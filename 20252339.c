# include <stdio.h> 
int main(void) {
int N, M, L, U;
int matriz [30][30]; 
int i, j;
int sumaColumna[30] = {0};
int eventosFila[30] = {0};
int impactoFila[30] = {0};
int eventosColumna[30] = {0};
int rachaFila[30] = {0};
int inicioFila[30] = {0};
int rachaActual;
int inicioActual;
int x;
int SC;
int impacto;
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
for (j = 0; j < M; j++) {
    for (i = 0; i < N; i++) {
        sumaColumna[j] += matriz[i][j];
    }
}
for (i = 0; i < N; i++) {

    rachaActual = 0;
    inicioActual = 0;

    for (j = 0; j < M; j++) {

        x = matriz[i][j];
        SC = sumaColumna[j];

        if (SC - N * x >= N * L && x <= U) {

            impacto = SC - N * x + 1;

            eventosFila[i]++;
            impactoFila[i] += impacto;
            eventosColumna[j]++;

            rachaActual++;

            if (rachaActual == 1) {
                inicioActual = j + 1;
            }

            if (rachaActual > rachaFila[i]) {
                rachaFila[i] = rachaActual;
                inicioFila[i] = inicioActual;
            }

        } else {
            rachaActual = 0;
            inicioActual = 0;
        }
    }
}
return 0;
}