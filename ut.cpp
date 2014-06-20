/**
 *  @author Barry Gackle
 *  @author 20 June 2014
 */

// C Standard Headers
#include <stdio.h>

// Internal Headers
#include "ut.h"

bool g_passed = true;

void nextTest(const char* message)
{
    printf("\nTESTING: %s\n", message);
    printf("------------------------------------------------------------\n");
}

void result(bool result)
{
    static int test_number = 0;

    test_number++;
    printf("Test %2d: %s\n", test_number, result ? "PASS" : "FAIL" );

    if (result != true)
        g_passed = false;
}

int done()
{
    printf("\nDONE\n\n");

    if (g_passed)
        return 0;
    else
        return 1;
}
