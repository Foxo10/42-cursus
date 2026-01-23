cd ~/cursus/libft
make fclean
make bonus
make so

cd ../libft-unit-tests
make f

                      First part
.-"-.     .-"-.     .-"-.     .-"-.     .-"-.     .-"-.
     "-.-"     "-.-"     "-.-"     "-.-"     "-.-"    
ft_memset:     [OK] [OK] [OK] [OK] [OK] [OK] [OK] 
ft_bzero:      [OK] [OK] [OK] [OK] 
ft_memcpy:     [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [CRASH] 
[crash]: your memcpy does not behave well with NULL as both params with size

ft_memmove:    [FAILED] [CRASH] [FAILED] [OK] [FAILED] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] 
[fail]: your memmove does not work with basic input
[crash]: your memmove's return is false/does not work with basic input
[fail]: your memmove does not work with \0 and others unsigned char codes
[fail]: your memmove does not support the overlap (test 1)

ft_memchr:     [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] 
ft_memcmp:     [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] 
ft_strlen:     [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] 
ft_isalpha:    [OK] 
ft_isdigit:    [OK] 
ft_isalnum:    [OK] 
ft_isascii:    [OK] 
ft_isprint:    [OK] 
ft_toupper:    [OK] 
ft_tolower:    [OK] 
ft_strchr:     [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] 
ft_strrchr:    [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] 
ft_strncmp:    [OK] [OK] [OK] [OK] [OK] [OK] [FAILED] [OK] [OK] [FAILED] [OK] [OK] [OK] [OK] 
[fail]: your strncmp does not cast in unsigned char the diff
[fail]: your strncmp does not work with non ascii chars

ft_strlcpy:    [OK] [OK] [OK] [OK] [OK] [OK] [OK] 
ft_strlcat:    [OK] [FAILED] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [NO CRASH] [OK] [OK] 
[fail]: your strlcat does not work with basic input
[no crash]: your strlcat does not segfault when null parameter is sent

ft_strnstr:    [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] 
ft_atoi:       [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] 
ft_calloc:     [OK] [OK] [OK] [FAILED] [OK] 
[fail]: your calloc don't work with 0 size

ft_strdup:     [OK] [OK] [OK] [OK] [OK] [OK] [OK] 

In this part, you can choose to protect your function or not to,
a color code will tell you if your function is protected/not BUT stay coherent !
[🛡 ] --> protected
[💥 ] --> not protected
                     Second part
 __)(__  __)(__  __)(__  __)(__  __)(__  __)(__  __)(__  __)
(______)(______)(______)(______)(______)(______)(______)(___

ft_substr:     [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [🛡 ] [OK] 
ft_strjoin:    [OK] [OK] [OK] [OK] [OK] [🛡 ] 
ft_strtrim:    [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [🛡 ] 
ft_split:      [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [🛡 ] 
ft_itoa:       [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] 
ft_strmapi:    [OK] [OK] [OK] [OK] [OK] [🛡 ] 
ft_putchar_fd: [OK] [OK] 
ft_putstr_fd:  [OK] [OK] [🛡 ] 
ft_putendl_fd: [OK] [OK] [🛡 ] 
ft_putnbr_fd:  [OK] [OK] [OK] [OK] [OK] 

 /~~~\/~~\/~~~\/~~~\/~~\/~~~\                    /~~~\/~~\/~~~\/~~~\/~~\/~~~\
 | /\/ /\/ /\ || /\/ /\/ /\ |                    | /\ \/\ \/\ || /\ \/\ \/\ |
  \ \/ /\/ /\/ /\ \/ /\/ /\/ /     Bonus part     \ \/\ \/\ \/ /\ \/\ \/\ \/ /
   \ \/\ \/\ \/  \ \/\ \/\ \/                      \/ /\/ /\/ /  \/ /\/ /\/ /
,_/\ \/\ \/\ \__/\ \/\ \/\ \______________________/ /\/ /\/ /\__/ /\/ /\/ /\_,
(__/\__/\__/\____/\__/\__/\________________________/\__/\__/\____/\__/\__/\__)

ft_lstnew:     [OK] [OK] [OK] [OK] 
ft_lstadd_front: [OK] [OK] [OK] 
ft_lstsize:    [OK] [OK] 
ft_lstlast:    [OK] [OK] 
ft_lstadd_back:[OK] [OK] [OK] 
ft_lstdelone:  [OK] [🛡 ] 
ft_lstclear:   [OK] [OK] [OK] [🛡 ] 
ft_lstiter:    [OK] [🛡 ] 
ft_lstmap:     [OK] [🛡 ] 
ft_striteri:   [OK] [OK] [🛡 ] 

-------------------------------------------------------------
+-----------+
|   TESTS   |
+-----------+
--- isalpha ---
[OK][OK][OK][OK][OK][OK]
--- isdigit ---
[OK][OK][OK][OK]
--- isalnum ---
[OK][OK][OK][OK][OK]
--- isascii ---
[OK][OK][OK][OK][OK]
--- isprint ---
[OK][OK][OK][OK][OK][OK][OK][OK][OK]
--- tolower ---
[OK][OK][OK][OK][OK][OK][OK]
--- toupper ---
[OK][OK][OK][OK][OK][OK][OK]
--- bzero ---
[OK][OK]
--- memset ---
[OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK]
--- memcpy ---
[OK][OK][SEGFAULT][OK][OK]
--- memmove ---
[OK][KO][OK][OK][OK][KO][OK][KO][SEGFAULT][OK][OK]
--- memchr ---
[OK][OK][OK][OK][OK][OK][OK][OK][OK][OK]
--- memcmp ---
[OK][OK][OK][OK][OK][OK][OK][OK][OK][OK]
--- atoi ---
[OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK]
--- calloc ---
[OK][OK][OK][OK]
--- strlen ---
[OK][OK][OK][OK]
--- strchr ---
[OK][OK][OK][OK][OK][OK][OK]
--- strrchr ---
[OK][OK][OK][OK][OK][OK][OK]
--- strncmp ---
[OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK]
--- strdup ---
[OK][OK][OK][OK][OK][OK]
--- strlcpy ---
[OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK]
--- strlcat ---
[OK][OK][OK][OK][OK][OK][OK][OK][OK][KO][KO][OK][OK][OK][OK][OK]
--- strnstr ---
[OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK]
--- substr ---
[OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK]
--- strjoin ---
[OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK]
--- strtrim ---
[OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK]
--- split ---
[OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK]
--- itoa ---
[OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK]
--- strmapi ---
[OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK]
--- striteri ---
[OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK]
--- putchar_fd ---
[OK][OK][OK]
--- putstr_fd ---
[OK][OK][OK]
--- putendl_fd ---
[OK][OK][OK]
--- putnbr_fd ---
[OK][OK][OK][OK][OK][OK]
--- FINAL RESULT ---
Errors detected; for detailed error messages, see ~/42zeus/errors.log

--- memcpy ---

A function call caused a segmentation fault

--- memmove ---

ft_memmove(0x63e9e0623020, "HOLA MUNDO" (0x63e9e061d3f4), 11) returned an incorrect string
- (expected: "HOLA MUNDO", returned: "")
ft_memmove(0x63e9e0623023, "MULAULANDO" (0x63e9e0623020), 4) returned an incorrect string
- (expected: "MULMULANDO", returned: "MULAULANDO")
ft_memmove(0x63e9e0623027, "MULAULANUL" (0x63e9e0623020), 3) returned an incorrect string
- (expected: "MULMULAMUL", returned: "MULAULANUL")
A function call caused a segmentation fault

--- strlcat ---

ft_strlcat("", "MUNDO", 4) returned an incorrect string
- (expected: "MUN", returned: "")
ft_strlcat("HOLA", " MUNDO", 3) returned an incorrect value
- (expected: 9, returned: 6)
