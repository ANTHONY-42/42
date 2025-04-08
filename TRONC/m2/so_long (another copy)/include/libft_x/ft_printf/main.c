#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

// Codes couleurs ANSI
#define FUCHSIA   "\033[1;35m"  // Titres des tests
#define TURQUOISE "\033[1;36m"  // ft_printf et printf
#define YELLOW_BRIGHT "\033[1;93m"  // Valeurs de retour
#define RESET     "\033[0m"     // Réinitialisation des couleurs

// Définition d'un séparateur large
#define SEPARATOR "-----------------------------------"

// Macro pour centrer le titre (corrigée)
#define CENTERED_TITLE(title) printf(FUCHSIA SEPARATOR "\n            " title "\n" SEPARATOR "\n" RESET);

int main()
{
    int return_ft, return_std;

    // ==================== %%c : CHAR ====================
    CENTERED_TITLE("%%c : CHAR");
    char c = 'A';
    return_ft = ft_printf(TURQUOISE "ft_printf : %%c = %c\n" RESET, c);
    printf(YELLOW_BRIGHT "return    : %d\n\n" RESET, return_ft);
    return_std = printf(TURQUOISE "printf    : %%c = %c\n" RESET, c);
    printf(YELLOW_BRIGHT "return    : %d\n" RESET, return_std);

    // ==================== %%s : STRING ====================
    CENTERED_TITLE("%%s : STRING");
    char *s = "Hello, world!";
    return_ft = ft_printf(TURQUOISE "ft_printf : %%s = %s\n" RESET, s);
    printf(YELLOW_BRIGHT "return    : %d\n\n" RESET, return_ft);
    return_std = printf(TURQUOISE "printf    : %%s = %s\n" RESET, s);
    printf(YELLOW_BRIGHT "return    : %d\n" RESET, return_std);

    // ==================== %%p : POINTER ====================
    CENTERED_TITLE("%%p : POINTER");
    void *p = &s;
    return_ft = ft_printf(TURQUOISE "ft_printf : %%p = %p\n" RESET, p);
    printf(YELLOW_BRIGHT "return    : %d\n\n" RESET, return_ft);
    return_std = printf(TURQUOISE "printf    : %%p = %p\n" RESET, p);
    printf(YELLOW_BRIGHT "return    : %d\n" RESET, return_std);

    // ==================== %%d : INTEGER ====================
    CENTERED_TITLE("%%d : INTEGER");
    int d = 1234;
    return_ft = ft_printf(TURQUOISE "ft_printf : %%d = %d\n" RESET, d);
    printf(YELLOW_BRIGHT "return    : %d\n\n" RESET, return_ft);
    return_std = printf(TURQUOISE "printf    : %%d = %d\n" RESET, d);
    printf(YELLOW_BRIGHT "return    : %d\n" RESET, return_std);

    // ==================== %%i : INTEGER ====================
    CENTERED_TITLE("%%i : INTEGER");
    int i = -5678;
    return_ft = ft_printf(TURQUOISE "ft_printf : %%i = %i\n" RESET, i);
    printf(YELLOW_BRIGHT "return    : %d\n\n" RESET, return_ft);
    return_std = printf(TURQUOISE "printf    : %%i = %i\n" RESET, i);
    printf(YELLOW_BRIGHT "return    : %d\n" RESET, return_std);

    // ==================== %%u : UNSIGNED ====================
    CENTERED_TITLE("%%u : UNSIGNED");
    unsigned int u = 4294967295;
    return_ft = ft_printf(TURQUOISE "ft_printf : %%u = %u\n" RESET, u);
    printf(YELLOW_BRIGHT "return    : %d\n\n" RESET, return_ft);
    return_std = printf(TURQUOISE "printf    : %%u = %u\n" RESET, u);
    printf(YELLOW_BRIGHT "return    : %d\n" RESET, return_std);

    // ==================== %%x : HEXADECIMAL ====================
    CENTERED_TITLE("%%x : HEXADECIMAL");
    int x = 255;
    return_ft = ft_printf(TURQUOISE "ft_printf : %%x = %x\n" RESET, x);
    printf(YELLOW_BRIGHT "return    : %d\n\n" RESET, return_ft);
    return_std = printf(TURQUOISE "printf    : %%x = %x\n" RESET, x);
    printf(YELLOW_BRIGHT "return    : %d\n" RESET, return_std);

    // ==================== %%X : HEXADECIMAL ====================
    CENTERED_TITLE("%%X : HEXADECIMAL");
    return_ft = ft_printf(TURQUOISE "ft_printf : %%X = %X\n" RESET, x);
    printf(YELLOW_BRIGHT "return    : %d\n\n" RESET, return_ft);
    return_std = printf(TURQUOISE "printf    : %%X = %X\n" RESET, x);
    printf(YELLOW_BRIGHT "return    : %d\n" RESET, return_std);

    // ==================== %%%% : PERCENT ====================
    CENTERED_TITLE("%%%% : PERCENT");
    return_ft = ft_printf(TURQUOISE "ft_printf : %%%% = %%\n" RESET);
    printf(YELLOW_BRIGHT "return    : %d\n\n" RESET, return_ft);
    return_std = printf(TURQUOISE "printf    : %%%% = %%\n" RESET);
    printf(YELLOW_BRIGHT "return    : %d\n" RESET, return_std);

    return 0;
}
