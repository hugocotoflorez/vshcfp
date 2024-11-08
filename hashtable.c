#include "vshcfp.h"
#include <stddef.h>
#include <string.h>
/*
        // The idea is to store values using strdup for strings and  be able
        // to store pointers to hash tables
        typedef struct __hash_table_node
        {
            struct __hash_table_node *next;  // allow collisions
            char                     *key;   // current element key
            void                     *value; // current element value
        } HashTableNode;

        typedef struct
        {
            size_t         size;     // elements in node_arr
            HashTableNode *node_arr; // array of nodes
        } __HashTable;
 */

/* Initialize a hashmap of a given size */
void hashmap_new(__HashTable *table, size_t size);

/* Add a value to a hashmap */
void hashmap_add(__HashTable *table, const char *key, char *value);

/* Remove a key-value pair from a hashmap */
void hashmap_pop(__HashTable *table, const char *key);

/* Get the value of a key in a hashmap or null if key not found*/
char *
hashmap_get(__HashTable table, const char *key, char **value)
{
    int index = hashmap_key(table, key);

    for (HashTableNode *node = table.node_arr + index; node != NULL;
         node                = node->next)

        if (!strcmp(node->key, key))
        {
            *value = node->value;
            return *value;
        }

    *value = NULL;
    return *value;
}

/* Get the numeric key given a string key and a hash table */
int
hashmap_key(__HashTable table, const char *key)
{
    /* Total sum algorithm */
    int sum = 0;

    while (*key)
        sum += *key;

    return sum % table.size;
}
