
// cunit includes
#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void test_regex() {
  CU_ASSERT(1);
}

int main()
{
  CU_initialize_registry();
  CU_pSuite suite = CU_add_suite("Regex Test", 0, 0);
  CU_add_test(suite, "Regex Test main", test_regex);
  CU_basic_set_mode(CU_BRM_VERBOSE);
  CU_basic_run_tests();
  CU_cleanup_registry();
  return 0;
}
