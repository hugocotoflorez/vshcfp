#include "../include/vshcfp.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINEMAX 100

HcfField *field_table    = NULL;
char      key[LINEMAX]   = { '\0' };
char      value[LINEMAX] = { '\0' };
char      field[LINEMAX] = { '\0' };


#if !defined(_GNU_SOURCE)
char* strchrnul(const char* str, char c)
{
    char* ret;
    ret = strchr(str,c);

    return (char*)(ret?: str + strlen(str));
}
#endif


int
__is_valid_c(char c)
{
    /* If c is space or some control char as \n or \0
     * it returns false */
    return c > ' ' && c != ':';
}

char *
__get_word(char *line, char *buffer)
{
    do
    {
        *buffer = *line;
        ++line;
        ++buffer;
    } while (__is_valid_c(line[-1]));

    buffer[-1] = '\0';
    return line - 1;
}

char *
__remove_spaces(char *str)
{
    while (*str == ' ' || *str == '\t')
    {
        ++str;
    }
    return str;
}

void
__parse_line(HcfOpts *opts, char *line)
{
    char  buffer[LINEMAX];
    char *c;

    /* Allow identation */
    line = __remove_spaces(line);

    if (!*line)
    {
        //puts("[EMTY]");
        return;
    }


    c = __get_word(line, buffer);

    // printf("[C] \'%c\'\n", *c);
    // printf("[BUF] \"%s\"\n", buffer);

    switch (*c)
    {
        case ':':
            /* If word last char is ':', it is a field name
             * and the colon is removed from the fieldname.
             * Then a field hashmap is created and it is added
             * to the options hashmap. */
            strcpy(field, buffer);
            //printf("Adding field: %s\n", field);
            field_table = malloc(sizeof(HcfField));
            __hashmap_new(field_table, OPTS_N);
            __hashmap_add(opts, field, field_table);
            __hashmap_add(field_table, "key", "value");
            //puts("adding test key-value to field hashmap");
            break;

        case '/':
            /* first character is invalid */
            //puts("[C=/] Comment line");
            break;

        default:

            if (c == buffer)
            {
                /* first character is invalid */
                //puts("[C=BUF] empty line");
                break;
            }

            if (!field_table)
            {
                //puts("[FTBLE] field table not created");
                break;
            }

            strcpy(key, buffer);

            c = __remove_spaces(c);

            *strchrnul(c, '/') = '\0';
            strcpy(value, c);

            //printf("Adding entry [%s] (%s): (%s)\n", field, key, value);
            __hashmap_add(field_table, key, strdup(value));
    }
}

void
__parse(HcfOpts *opts, FILE *f)
{
    char line[LINEMAX + 1];
    line[LINEMAX] = 0;

    while (fgets(line, LINEMAX, f))
    {
        *strchrnul(line, '\n') = '\0';
        // printf("[LINE] \"%s\"\n", line);
        __parse_line(opts, line);
    }
}

HcfOpts
hcf_load(const char *file)
{
    FILE   *f;
    HcfOpts opts;

    f = fopen(file, "r");

    if (!f)
    {
        perror("File not found");
        return (__HashTable) { 0 };
    }

    __hashmap_new(&opts, FIELDS_N);
    __parse(&opts, f);

    return opts;
}
