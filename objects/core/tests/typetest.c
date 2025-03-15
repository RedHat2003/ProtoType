#include <stdio.h>
#include <stdbool.h>
#include <string.h>
// Pull in the definitions of TypeObject, Object, and your global type objects.
#include "typeobject.h"
#include "coreObjects/uintarrobejct.h"
#include "coreObjects/arrobejct.h"
// We expect that both TypeObject_Type and UintArrObject_Type
// have .ob_base.ob_base.ob_type = &TypeObject_Type
extern TypeObject TypeObject_Type;       // 'type of all types'
extern TypeObject UintArrObject_Type;    // Another type object
extern TypeObject intArrObject_Type;
// ANSI color codes for pass/fail highlight
#define COLOR_GREEN  "\033[32m"
#define COLOR_RED    "\033[31m"
#define COLOR_RESET  "\033[0m"


// Holds data for each test: name + pointer to your type object
typedef struct {
    const char   *label;
    TypeObject   *type_ptr;
} TestCase;

// This function actually checks if, after casting to Object,
// the object's ob_type matches &TypeObject_Type. 
// If so, prints [pass]; otherwise, prints [fail].
static bool run_test_case(const TestCase *tc)
{
    // Cast the type object down to a base Object
    Object *ob = CAST_TYPE_OBJ(tc->type_ptr);

    // Condition: "all types is object of type TypeObject_Type"
    // i.e., ob->ob_type must be &TypeObject_Type
    bool pass = (ob->ob_type == &TypeObject_Type);
    if (pass) {
        printf(COLOR_GREEN "[pass]" COLOR_RESET
               " %s => ob->ob_type == &TypeObject_Type\n",
               tc->label);
    } else {
        // Show what we found vs. what we wanted
        printf(COLOR_RED "[fail]" COLOR_RESET
               " %s => ob->ob_type != &TypeObject_Type\n",
               tc->label);
    }
    return pass;
}

int main(void)
{
    // Define the test list: each item has a label + a pointer
    // to the global "type object" we want to check.
    TestCase tests[] = {
        { "TypeObject_Type",      &TypeObject_Type    },
        { "UintArrObject_Type",   &UintArrObject_Type },
        { "intArrObject_Type",   &intArrObject_Type }
    };
    const size_t num_tests = sizeof(tests)/sizeof(tests[0]);
    
    size_t pass_count = 0;
    for (size_t i = 0; i < num_tests; i++) {
        if (run_test_case(&tests[i])) {
            pass_count++;
        }
    }

    // Print a final summary
    printf("\nTest summary: %zu/%zu passed.\n", pass_count, num_tests);
    return (pass_count == num_tests) ? 0 : 1;
}

