# Programación Para Mecatronicos - Primer Parcial
Matricula: 20252339
Nombre: Geysi Paniagua De Jesus
Reto #14: Riego - aportes inferiores al promedio diario
## Descripcion

El programa analiza una matriz de valores enteros correspondiente al reto de riego.

Para cada posicion se determina si existe un evento utilizando la condicion:

SC - N*x >= N*L && x <= U

Cuando una posicion es un evento, su impacto se calcula mediante:

SC - N*x + 1

El programa determina:

- cantidad de eventos por fila
- impacto total por fila
- mayor racha de eventos consecutivos
- inicio de la mayor racha
- cantidad de eventos por columna
- fila prioritaria
- columna destacada

## Compilacion

El programa fue desarrollado en lenguaje C y compilado utilizando GCC.

```bash 
gcc -std=c11 -Wall -Wextra 20252339.c -o reto.exe
