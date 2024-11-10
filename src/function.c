#include "../include/vshcfp.h"

inline HcfField *
hcf_get_field(HcfOpts opts, const char *field)
{
    return __hashmap_get(opts, field, NULL);
}

inline char *
hcf_get_value(HcfField field, const char *key)
{
    return __hashmap_get(field, key, NULL);
}

inline char *
hcf_get(HcfOpts opts, const char *field, const char *key)
{
    __HashTable *table = __hashmap_get(opts, field, NULL);
    return __hashmap_get(*table, key, NULL);
}
