//
// Created by OEYBuisson on 18/09/2024.
//
#include "../include/Errors.h"

#include <stdio.h>
#include <stdlib.h>

void PrintErrorMessage(const char *s_message,
                       const char *s_message2,
                       const char *s_var,
                       const char *s_file,
                       const char *s_function,
                       const uint32_t ui32_line)
{
    fprintf(stderr, "\n\nERROR=\n");
    fprintf(stderr, "\t message=%s %s", s_message, s_message2);
    fprintf(stderr, "\t var=%s\n", s_var);
    fprintf(stderr, "\t file=%s\n", s_file);
    fprintf(stderr, "\t function=%s\n", s_function);
    fprintf(stderr, "\t line=%u\n", ui32_line);
    fprintf(stderr, "\n\n");
}
