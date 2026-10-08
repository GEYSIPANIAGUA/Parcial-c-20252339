# Evidencias de pruebas

## Prueba de escritorio

Para comprobar manualmente el funcionamiento del algoritmo se utiliza el siguiente caso:

### Entrada

3 5 5 15

8 18 34 12 28  
28 12 8 23 34  
12 23 18 8 38

Donde:

- N = 3 filas
- M = 5 columnas
- L = 5
- U = 15

### 1. Suma de cada columna

Columna 1:

8 + 28 + 12 = 48

Columna 2:

18 + 12 + 23 = 53

Columna 3:

34 + 8 + 18 = 60

Columna 4:

12 + 23 + 8 = 43

Columna 5:

28 + 34 + 38 = 100

Por tanto:

SC = [48, 53, 60, 43, 100]

### 2. Evaluacion de eventos

La condicion utilizada es:

SC - N*x >= N*L && x <= U

Y el impacto de un evento se calcula con:

SC - N*x + 1

| Fila | Columna | x | SC | Evento | Impacto |
|---|---|---:|---:|---|---:|
| 1 | 1 | 8 | 48 | Si | 25 |
| 1 | 2 | 18 | 53 | No | 0 |
| 1 | 3 | 34 | 60 | No | 0 |
| 1 | 4 | 12 | 43 | No | 0 |
| 1 | 5 | 28 | 100 | No | 0 |
| 2 | 1 | 28 | 48 | No | 0 |
| 2 | 2 | 12 | 53 | Si | 18 |
| 2 | 3 | 8 | 60 | Si | 37 |
| 2 | 4 | 23 | 43 | No | 0 |
| 2 | 5 | 34 | 100 | No | 0 |
| 3 | 1 | 12 | 48 | No | 0 |
| 3 | 2 | 23 | 53 | No | 0 |
| 3 | 3 | 18 | 60 | No | 0 |
| 3 | 4 | 8 | 43 | Si | 20 |
| 3 | 5 | 38 | 100 | No | 0 |

### 3. Resultados por fila

Fila 1:

- Eventos = 1
- Impacto = 25
- Racha = 1
- Inicio = 1

Fila 2:

- Eventos = 2
- Impacto = 55
- Racha = 2
- Inicio = 2

Fila 3:

- Eventos = 1
- Impacto = 20
- Racha = 1
- Inicio = 4

Eventos por columna:

1 1 1 1 0

La fila prioritaria es la fila 2 porque tiene la mayor racha.

La columna destacada es la columna 1. Todas las columnas 1, 2, 3 y 4 tienen un evento, por lo que se selecciona la de menor numero.

### Salida esperada

FILA 1 EVENTOS 1 IMPACTO 25 RACHA 1 INICIO 1  
FILA 2 EVENTOS 2 IMPACTO 55 RACHA 2 INICIO 2  
FILA 3 EVENTOS 1 IMPACTO 20 RACHA 1 INICIO 4  
COLUMNAS 1 1 1 1 0  
PRIORIDAD 2  
COLUMNA 1


# Casos oficiales

Se ejecutaron los 17 casos de prueba suministrados por el profesor.

El programa fue compilado utilizando:

gcc -std=c11 -Wall -Wextra 20252339.c -o reto.exe

Los resultados generados por el programa fueron comparados con los archivos .out proporcionados.

Resultado:

17 de 17 casos correctos.


# Prueba propia 1

## Objetivo

Comprobar el funcionamiento cuando existen varios eventos, pero no todos son consecutivos.

## Entrada

2 3 2 10

4 10 8  
8 6 12

### Calculos

Suma de columnas:

Columna 1:

4 + 8 = 12

Columna 2:

10 + 6 = 16

Columna 3:

8 + 12 = 20

Por tanto:

SC = [12, 16, 20]

Para este caso:

N*L = 2*2 = 4

Fila 1:

- Columna 1: 12 - 2(4) = 4. Es evento.
- Columna 2: 16 - 2(10) = -4. No es evento.
- Columna 3: 20 - 2(8) = 4. Es evento.

Fila 2:

- Columna 1: 12 - 2(8) = -4. No es evento.
- Columna 2: 16 - 2(6) = 4. Es evento.
- Columna 3: 20 - 2(12) = -4. No es evento.

### Salida esperada

FILA 1 EVENTOS 2 IMPACTO 10 RACHA 1 INICIO 1  
FILA 2 EVENTOS 1 IMPACTO 5 RACHA 1 INICIO 2  
COLUMNAS 1 1 1  
PRIORIDAD 1  
COLUMNA 1

## Justificacion

Esta prueba permite verificar que el programa cuenta correctamente varios eventos separados y que conserva como inicio de la racha maxima la primera posicion cuando existen rachas del mismo tamaño.


# Prueba propia 2

## Objetivo

Comprobar el comportamiento cuando no existe ningun evento.

## Entrada

2 2 5 10

10 10  
10 10

### Calculos

Las dos columnas tienen suma:

10 + 10 = 20

Para cada posicion:

SC - N*x = 20 - 2(10) = 0

Mientras que:

N*L = 2(5) = 10

Como:

0 >= 10

es falso, ninguna posicion es un evento.

### Salida esperada

FILA 1 EVENTOS 0 IMPACTO 0 RACHA 0 INICIO 0  
FILA 2 EVENTOS 0 IMPACTO 0 RACHA 0 INICIO 0  
COLUMNAS 0 0  
PRIORIDAD 0  
COLUMNA 0

## Justificacion

Esta prueba verifica el caso especial donde toda la matriz tiene cero eventos. En esa situacion la prioridad y la columna destacada deben ser 0