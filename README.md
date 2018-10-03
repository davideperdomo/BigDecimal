# Descripción sistema:
El tipo de dato está implementando como una clase llamada BigInteger, la cual se compone de un arreglo de enteros, cada posición del arreglo tiene un entero del 0 al 9, representando un dígito del número en sistema decimal, tambien tiene un atributo de entero, que representa la posición del arreglo en donde se encuentra el punto decimal.
# Manual :
Los métodos de la clase son:
### *sum():
Parametros: 

- int arr1[] : Primer numero 
- int arr2[] : Segundo numero
- int n : Tamaño de los arreglos

La suma es implementada sumando posición mas posición, con una variable auxiliar que indica la unidad de arrastre, utilizada en el algoritmo tradicional de la suma.

### *res():
Parametros: 

- int arr1[] : Primer numero 
- int arr2[] : Segundo numero
- int n : Tamaño de los arreglos

La resta es implementada restando posición menos posición, con una variable auxiliar que indica la unidad de arrastre, utilizada en el algoritmo tradicional de la resta.
### *mult():
Parametros: 

- int arr1[] : Primer numero 
- int arr2[] : Segundo numero
- int n : Tamaño de los arreglos

Se implementa el algoritmo de la multiplicación hindú, para informacion de la tabla hindú: https://es.m.wikipedia.org/wiki/Algoritmo_de_multiplicación#Multiplicación_hindú_o_de_Fibonacci
### *div():
Parametros: 

- int arr1[] : Numerador 
- int dvs : Denominador
- int n : Tamaño del numerador

Se utiliza el método mult, multiplicando el numarr1 por 1/den.
### *calcpi()
Parametros: 

- int n : numero de terminos en la sumatoria

Se utilizan los métodos de la clase para implementar la sumatoria de la serie de Leibniz: .

#### Importante : Para los métodos que operan con dos arreglos, los tamaños de estos deben ser iguales.

# Notas de la versión 0.1
- Suma, Resta y multiplicación implementada correctamente.
- Actualmente, para la division se utiliza el tipo de dato Long double, por lo cual, su cálculo no es virtualmente infinito.
- Aunque la mayor parte de los métodos de la clase son funcionales, no se ha utilizado el objeto como se esperaba, se trabajará en su utilización.
- Se espera mejorar la utilización de arreglos y punteros, y la conversión con strings, con fin de mejorar la usabilidad del sistema.

Sistema desarrollado completamente por David Esteban Perdomo
