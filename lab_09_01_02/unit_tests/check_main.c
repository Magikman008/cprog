#include "../inc/unit.h"

int main(void)
{
    int no_failed = 0;
    Suite *s[2] = { sort_suite() };
    SRunner *runner;

    for (size_t i = 0; i < 1; i++)
    {
        runner = srunner_create(s[i]);
        srunner_run_all(runner, CK_VERBOSE);
        no_failed = srunner_ntests_failed(runner);
        srunner_free(runner);
    }

    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
