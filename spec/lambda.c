#include "../ç.h"

// TODO:: call compile_time stuffs outside macro in plain code
compile_time
int function_end(ç_ctx ctx, char *str)
{
    return ctx.pairs_level['{'] == 0;
}

//Do nothing because ctx cursos pos is not incremented as there is no match() that succeed
macro
{
    return "42"; 
}

macro 
{
    const char *global_scope,
            function_prototype,
            function_body_head,
                lambda_return_type,
                lambda_arguments,
                lambda_body,
            function_body_footer;
    //Looks like if expr are better outside match
    // i.e 
    // if (match(.... until A))
    //  ....
    // else if (match (... until B))
  /*  auto k = match
    (
        ctx,
        capture global_scope until "{",
        capture function_body_head until "^",
        capture lambda_return_type until "" 
         //  what about ^AMACRO(THATRETURNS_A_TYPE) (int a){}
        capture lambda_arguments until "{",
        capture lambda_body until "}",
        capture function_body_footer until is function_end
    );*/
    return 0;
}

#include "stdio.h"

// todo::   add an intermediate cast to let cedilla compiler known that it were a lambda,
//          as '$ cpp *.ç' will occurs before '$ cedilla *.ç' \

typedef void        __cedilla_lambda_return;
typedef long long   __cedilla_lambda;

#define test(...) 0


    #define __(__a1, __a2, __a3, __a4, __a5) __a1; __a3; __a3; __a4; __a5;
    #define __(__a1, __a2, __a3, __a4) __a1; __a3; __a3; __a4;
    #define __(__a1, __a2, __a3) __a1; __a2; __a3;
    #define __(__a1, __a2) __a1; __a2;

    #define ___(...) __VA_ARGS__


#define lambda(X, Y, ...) ((X(*)(CONCAT(__, Y))) (__cedilla_lambda) ( { \
    CONCAT(_, Y)        \
    (void) ({ __VA_ARGS__}); 0;\
    }))


#define return_structure
#define lambda_return (__cedilla_lambda_return)

int itest()
{
    typedef struct 
    {
        int i;
        int z;
        float f;
    } ks;


    struct 
    {
        int    (*f)();
        void    *d;
    }   binded_lambda;

    int ppz = 5;
    int pp = 4;
    




      binded_lambda.f = lambda (int, _(int x, int y),
           lambda_return x + y;     
        );
   // binded_lambda.d = ();
//    printf("%d", call(binded_lambda)(6));

// todo:: fix structure because clang does not support return in ({ expression })
// BUTT it is an IDE-only issue, clanging the file actually work as the p pointer is initialized to 0
    ks(*ppp)() = lambda (ks, (int x, int y),  
         lambda_return (ks) {0,0,0}; 
    );
// instead a fix would be 
    ks(*p)() = lambda (ks, (int x, int y), 
         lambda_return (ks) {0,0,0}; 
    );


    int(*k)() = lambda (int, (int x, int y), 
     //   dwadwa  // ide error : dwadwa is undefined 
        lambda_return 1; 
    );

    long long ll = lambda (int, (int x),  
        lambda_return 0; 
    )() ;

    long l = lambda(long, (int x),
        lambda_return 0; 
    )(12, 1, 6);
    int i = lambda(int, (int x), 
        lambda_return 0; 
    )();
    short s = lambda(short, (int x),
        lambda_return 0;
    )();
    char c  = lambda(char, (int x), 
        lambda_return 0; 
    )('z');

    unsigned long long ull = lambda(unsigned long long, (int x), 
        lambda_return 0; 
    )('z');
    unsigned long ul = lambda(unsigned long, (int x), 
        lambda_return 0; 
    )('p');
    unsigned  u = lambda(unsigned, (int x),
        lambda_return 0; 
    )('p');
    unsigned short us = lambda(unsigned short, (int x), 
        lambda_return 0; 
    )('p');
    unsigned char uc = lambda(unsigned char, (int x), 
        lambda_return 0; 
    )('p');

    void* v = lambda(void* , (int x),  
        lambda_return 0; 
    )('p');

    float f = lambda(float , (int x),  
        0; 
    )('p');
    double d = lambda(double, (int x),  
        0; 
    )('p');
    long double ld =  lambda(long double, (int x), 
        0; 
    )(42);

    return printf ("%d", _()());
}

int main()
{
    itest();
}