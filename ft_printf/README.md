*Este proyecto ha sido creado como parte del currículo de 42 por odiez-gu.*

# Printf
## Descripción
***
Este proyecto consiste en reimplementar la función `printf()` de la libc en C, creando una librería propia llamada `libftprintf.a`.  
La función principal es:
```c
int	ft_printf(const char *format, ...);
```
La función **ft_printf**, como la función original, recorre la cadena `format` carácter a carácter. Cuando encuentra un '%', interpreta el especificador y escriber el resultado por stdout. Además, devuelve el número total de caracteres impresos.

### Conversiones implementadas (parte obligatoria)
***
* %c → carácter
* %s → string
* %p → puntero (formato 0x... en hexadecimal)
* %d / %i → entero con signo en base 10
* %u → entero sin signo en base 10
* %x → hexadecimal en minúsculas
* %X → hexadecimal en mayúsculas
* %% → imprime el símbolo %

### Estructura del proyecto
***
Archivos principales:
* *ft_printf.c* → parser principal del format y control del flujo
* *ft_print_conversion.c* / *ft_print_conversion_2.c* → funciones de impresión por conversión
* *printf.h* → cabecera con prototipos y includes
Dependencia:
* *libft/* → se usa libft como librería auxiliar (incluida como subcarpeta).

## Descripción
***
Compilar la librería:
```bash
make
```
Limpiar objetos:
```bash
make clean
```
Borrado total (incluye la librería generada):
```bash
make fclean
```
Recompilar todo:
```bash
make re
```
El *Makefile* compila primero libft dentro de libft/ y luego genera **libftprintf.a**.

### Uso
***
1. Incluye el header:
```c
#include "printf.h"
```
2. Compila tu programa enlazando con la librería::
```bash
cc -Wall -Wextra -Werror main.c libftprintf.a -o program
```
3. Ejemplo mínimo:
```c
#include "printf.h"

int	main(void)
{
	int x = 42;

	ft_printf("Hola %s %c | n=%d | u=%u | hex=%x | HEX=%X | ptr=%p | %%\n",
		"mundo", '!', -42, 42u, 42, 42, &x);
	return (0);
}

```

### Detalles de implementación
#### Algoritmo (parser + dispatcher)
***
El flujo general es:
1. Parser: se recorre *format*
2. Si el carácter actual no es '%', se imprime tal cual.
3. Si el carácter actual es '%', se lee el siguiente carácter como *conversión*:
    * Se llama a un dispatcher →
    ```c 
    ft_print_conversion(char conversion, va_list args)
    ```
    * Este dispatcher decide qué función usar según el especificador.
4. Se acumula el número de caracteres impresos para devolverlo al final.

### Decisiones y casos borde
***
* *%s*:
    * Si el puntero es *NULL*, se imprime *"(null)"* para imitar el comportamiento habitual de printf.
* *%p*:
    * 
    * 
* *%d/%i*:
    * Se maneja el signo y se imprime en base 10.
* Conteo:
    * Cada función de impresión devuelve los caracteres que ha escrito.
    * ft_printf suma todos esos retornos para devolver el total final.

## Recursos
### Referencias útiles
***
* Manuales
    * man 3 printf
    * man 3 stdarg (para va_start, va_arg, va_end)
* Conceptos clave
    * Funciones variádicas en C
    * Conversión de números a diferentes bases (decimal/hex): https://www.youtube.com/watch?v=FFDMzbrEXaE&t=463s
    * Manejo de punteros y representación en hexadecimal

## Uso de IA
He utilizado IA como apoyo para:
* Detectar casos borde comunes (NULL en %s, formato de %p, etc.).
* Ayuda en depuración a partir de logs/errores aportados por mí.
El código final y las decisiones de implementación han sido comprendidos y verificados mediante pruebas propias.
