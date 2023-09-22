#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <stdint.h>
#include <cmocka.h>

int val;

static void set_val(int v)
{
 val=v;
}
/* A test case that does nothing and succeeds. */
static void null_test_success(void **state) {
    (void) state; /* unused */
}

static void set_val_test(void **state);
static void set_val_test(void **state)
{
    (void)state; /* unused */

    val = 0u;
    //set_val(1);
    assert_int_equal(val, 1u);
}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(null_test_success),
		cmocka_unit_test(set_val_test),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}