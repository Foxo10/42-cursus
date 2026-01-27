*Este proyecto ha sido creado como parte del currículo de 42 por odiez-gu.*

# Libft

## Descripción
**Libft** es una librería en C que reimplementa un conjunto de funciones clásicas de la libc y añade funciones extra (manejo de strings, memoria, conversiones y descriptor de archivos).  
El objetivo es comprender en profundidad el comportamiento de estas funciones, practicar punteros/memoria dinámica y construir una base reutilizable para proyectos posteriores.

## Instrucciones

### Compilación
- Compilar la parte obligatoria y la parte bonus:
```bash
make
```
- Limpiar:
```bash
make clean
make fclean
make re
```
Al compilar se genera libft.a en la raíz del repositorio.

### Uso en otros proyectos

```#include "libft.h"```

- Ejemplo de compilación:
```bash
cc -Wall -Wextra -Werror main.c libft.a -o libft
```

## Descripción detallada
La librería está organizada en 3 bloques (parte 1, parte 2 y bonus). En este caso, el bonus es una sección mandatoria del proyecto. La implementación busca reproducir el comportamiento descrito en las páginas del manual (man) de cada función, con el prefijo ft_.

### Funciones de libc (reimplementación)

*Clasificación de caracteres*
* ft_isalpha, ft_isdigit, ft_isalnum, ft_isascii, ft_isprint

*Conversión de caracteres*
* ft_toupper, ft_tolower

*Strings*
* ft_strlen, ft_strchr, ft_strrchr, ft_strncmp, ft_strnstr, ft_strlcpy, ft_strlcat

*Memoria*
* ft_memset, ft_bzero, ft_memcpy, ft_memmove, ft_memchr, ft_memcmp

*Conversión*
* ft_atoi

*Asignación dinámica*
* ft_calloc, ft_strdup

### Funciones adicionales
Funciones útiles para trabajar con strings y salida por descriptor de archivo:
* ft_substr, ft_strjoin, ft_strtrim, ft_split
* ft_itoa
* ft_strmapi, ft_striteri
* ft_putchar_fd, ft_putstr_fd, ft_putendl_fd, ft_putnbr_fd

### Listas enlazadas (t_list)
Incluye la estructura t_list y funciones para crear, iterar, modificar y liberar listas enlazadas:
* ft_lstnew, ft_lstadd_front, ft_lstsize, ft_lstlast, ft_lstadd_back
* ft_lstdelone, ft_lstclear, ft_lstiter, ft_lstmap

## Recursos
* Linux man pages (https://linux.die.net/man/)
* C Programming Tutorials (Portfolio Courses)
* Short introduction to linked lists in C (CodeVaul)
* Repositorio propio de la piscina (Foxo10/42-igerilekua)

### Uso de IA
La IA se ha utilizado como apoyo de aprendizaje, principalmente para:
* Aclarar el comportamiento esperado y casos límite de funciones tipo libc.
* Revisar ideas de diseño para estructurar una librería de C.
* Sugerir estrategias de depuración y testeo (segfaults, leaks, uso de herramientas, etc.).