# Analisis inicial del problema
Mi programa debe analizar una matriz de valores enteros,
N: Representa la cantidad de filas.
M: representa la cantidad de columnas. 
L: limite utilizado para determinar cuanto debe estar por debajo del promedio.
U: valor máximo permitido.

Primero se deben validar las dimensiones N y M y tambien los valores de L y U. 
Luego se deben leer todos los valores de la matriz.
Para cada columna sera necesario calcular su suma.
Un evento ocurre cuando un valor de la matriz cumple la condicion: SC - N*x >= N*L && x <= U
Donde:
SC: es la suma de la columna.
N: es la cantidad de filas.
x: es el valor que se esta evaluando.
L: es la diferencia minima con respecto al promedio.
U: es el limite maximo permitido para que el valor pueda ser considerado un evento.
Si una posicion es un evento, su impacto se calcula con:
SC - N*x + 1
Para cada fila sera necesario el calcular:
- cantidad de eventos.
- suma de impactos.
- mayor racha de eventos consecutivos.
- posicion donde comienza la mayor racha.
Al igual se deben contar cuantos eventos existen en cada columna.
Al finalizar se debe determinar la fila prioritaria y la columna destacada. 