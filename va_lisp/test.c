#include "va_lisp.h"

long long   print_5(list **primitives, void*data, va_list *ap)
{
    (void) ap;
    (void) data;
    printf("5\n");
    return 0;
}

long long   print_int(list **primitives, void*data, va_list *ap)
{
    (void) ap;
    (void) data;
    printf("%i\n", va_arg(*ap, int ));
    return 0;
}


int main()
{
    list        *lst = 0;
    int         data = 0;


    list_add(&lst, new_va_function(print_5));
    list_add(&lst, new_va_function(print_int));

    lisp(&lst, &data, "print_5", "print_int", 10, "print_int", 10);

    list_free(lst, free);
/*

   list_add(&lst, f);
   

   va_lang(lst, print_5);*/
   // va
}