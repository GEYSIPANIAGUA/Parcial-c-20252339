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
int totalEventos = 0;
int prioridad = 0;
int columnaDestacada = 0;
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

for (i = 0; i < N; i++) {
    totalEventos += eventosFila[i];
}

if (totalEventos > 0) {

    int mejorFila = 0;

    for (i = 1; i < N; i++) {

        if (rachaFila[i] > rachaFila[mejorFila] ||
            (rachaFila[i] == rachaFila[mejorFila] &&
             impactoFila[i] > impactoFila[mejorFila]) ||
            (rachaFila[i] == rachaFila[mejorFila] &&
             impactoFila[i] == impactoFila[mejorFila] &&
             eventosFila[i] > eventosFila[mejorFila])) {

            mejorFila = i;
        }
    }

    prioridad = mejorFila + 1;
}
if (totalEventos > 0) {

    int mejorColumna = 0;

    for (j = 1; j < M; j++) {

        if (eventosColumna[j] > eventosColumna[mejorColumna]) {
            mejorColumna = j;
        }
    }

    columnaDestacada = mejorColumna + 1;
}
for (i = 0; i < N; i++) {
    printf("FILA %d EVENTOS %d IMPACTO %d RACHA %d INICIO %d\n",
           i + 1,
           eventosFila[i],
           impactoFila[i],
           rachaFila[i],
           inicioFila[i]);
}
printf("COLUMNAS");

for (j = 0; j < M; j++) {
    printf(" %d", eventosColumna[j]);
}
printf("\n");
printf("PRIORIDAD %d\n", prioridad);
printf("COLUMNA %d\n", columnaDestacada);
return 0;
}
