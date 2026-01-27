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
ft_memcpy:     [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] 
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
ft_strncmp:    [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] 
ft_strlcpy:    [OK] [OK] [OK] [OK] [OK] [OK] [OK] 
ft_strlcat:    [OK] [FAILED] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] 
[fail]: your strlcat does not work with basic input

ft_strnstr:    [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] 
ft_atoi:       [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [OK] 
ft_calloc:     [OK] [OK] [OK] [OK] [OK] 
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
See result.log for more informations !

+---------------------+
|   COMPILE LIBRARY   |
+---------------------+
Library compiled successfully!
+---------------------+
|   CHECK SYMBOLS     |
+---------------------+
All required functions found!
No forbidden functions!
No global variables!
+-------------------+
|   COMPILE TESTS   |
+-------------------+
Tests compiled successfully!
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
[OK][OK][OK][OK][OK][OK][OK]
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
[OK][OK][OK][OK][OK][OK][KO][OK][KO][OK][OK][OK][KO][OK][OK][OK]
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
+-----------------------+
|   libft: BONUS PART   |
+-----------------------+
+-----------------------------+
|   COMPILE LIBRARY (BONUS)   |
+-----------------------------+
Library compiled successfully!
+-----------------------------+
|   CHECK SYMBOLS (BONUS)     |
+-----------------------------+
All required functions found!
No forbidden functions!
No global variables!
+---------------------------+
|   COMPILE TESTS (BONUS)   |
+---------------------------+
Tests compiled successfully!
+-------------------+
|   TESTS (BONUS)   |
+-------------------+
--- lstnew ---
[OK][OK][OK][OK][OK][OK][OK][OK][OK]
--- lstadd_front ---
[OK][OK][OK][OK]
--- lstsize ---
[OK][OK][OK]
--- lstlast ---
[OK][OK][OK]
--- lstadd_back ---
[OK][OK][OK][OK]
--- lstdelone ---
[OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK]
--- lstclear ---
[OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK]
--- lstiter ---
[OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK]
--- lstmap ---
[OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK][OK]
--- FINAL RESULT ---
All tests OK!
