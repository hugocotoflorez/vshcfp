#include "../include/vshcfp.h"
#include <stdio.h>
#include <string.h>

int
main(void)
{
        __HashTable table;
        char *value;

        printf("%s\n", "Creating hash");
        __hashmap_new(&table, 10);

        printf("%s\n", "Getting Hugo");
        __hashmap_get(table, "Hugo", (void *) &value);

        printf("%s\n", "Adding Hugo");
        __hashmap_add(&table, "Hugo", strdup("Value for Hugo"));

        printf("%s\n", "Adding Other");
        __hashmap_add(&table, "Other", strdup("Value for Other"));

        printf("%s\n", "Getting Hugo");
        __hashmap_get(table, "Hugo", (void *) &value);

        printf("%s\n", "Getting Other");
        __hashmap_get(table, "Other", (void *) &value);

        printf("%s\n", "Poping Hugo");
        // __hashmap_pop(&table, "Hugo");

        printf("%s\n", "Getting Hugo");
        __hashmap_get(table, "Hugo", (void *) &value);

        printf("%s\n", "Poping Other");
        // __hashmap_pop(&table, "Other");

        __hashmap_destroy(&table);

        return 0;
}
