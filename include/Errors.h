//
// Created by Arnaud Bernard on 16/09/2025.
//

#ifndef PROJET_CDATAFRAME_ERRORS_H
#define PROJET_CDATAFRAME_ERRORS_H

#include <stdint.h>

void PrintErrorMessage(const char *s_message,
                       const char *s_message2,
                       const char *s_var,
                       const char *s_file,
                       const char *s_function,
                       const uint32_t ui32_line);

#define POINTER_CHECK_AND_RETURN_VALUE(pt, message, retVal)                                                          \
    {                                                                                                        \
        if (!pt) {                                                                                         \
            PrintErrorMessage(                                                                               \
                "Can not allocate ", message, #pt, __FILE__, __FUNCTION__, __LINE__);                                \
        }                                                                                                    \
        return retVal;                                                                                       \
    }
#define POINTER_CHECK_AND_RETURN(pt, message)                                                          \
    {                                                                                                        \
        if (!pt) {                                                                                         \
            PrintErrorMessage(                                                                               \
                "The following point is not allocated: ", message, #pt, __FILE__, __FUNCTION__, __LINE__);                                \
        }                                                                                                    \
        return;                                                                                       \
    }



#endif // PROJET_ERRORS_H
