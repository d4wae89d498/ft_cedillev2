#ifndef MATCH_H
# define MATCH_H
# include "object_list.h"
# include "stdarg.h"
const char *limit = "__CEDILLA_LIMIT";
const char *token = "__CEDILLA_STATE_PARSE"; 
const char *call  = "__CEDILLA_STATE_CALL";

const char *skip  = "__CEDILLA_SKIP";
const char *oskip = "__CEDILLA_OSKIP";
const char *until = "__CEDILLA__UNTIL";
const char *capture  
                  = "__CEDILLA__CAPTURE";
# define _          ,

# define limit      ,limit,
# define token      token,
# define call       call,
# define skip       skip,
# define oskip      oskip,
# define until      ,until,
# define capture    capture,
# define _          ,

char    *match(object_list **, const char **str, ...);
char    *vmatch(object_list **, const char **str, va_list);
#endif