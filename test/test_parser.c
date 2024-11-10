#include "../include/vshcfp.h"
#include <stdio.h>

void
test_get(HcfOpts opts, char *field, char *key)
{
    char *res = hcf_get(opts, field, key);
    if (res)
        printf("OPTS[%s][%s] = %s\n", field, key, res);
    else
        printf("OPTS[%s][%s] not found\n", field, key);
}

int
main(void)
{
    HcfOpts opts;

    opts = hcf_load("options.hcf");

    test_get(opts, "field1", "key1");
    test_get(opts, "field1", "key2");

    __hashmap_destroy(&opts);

    return 0;
}
