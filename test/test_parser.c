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

    puts("Loading file... ");
    opts = hcf_load("options.hcf");

    puts("Done.");
    puts("Getting values ...");

    test_get(opts, "field1", "key1");
    test_get(opts, "field1", "key2");
    test_get(opts, "field1", "key3");
    test_get(opts, "field1", "key4");
    test_get(opts, "field1", "//");
    test_get(opts, "field1", "idk");
    test_get(opts, "field1", "comment");
    test_get(opts, "field1", "com");

    puts("Destroying data structure");
    hcf_destroy(&opts);

    return 0;
}
