#include "unity.h"

#include <stdlib.h>

#include "core.h"

#include <zlog.c>

void setUp(void)
{
}

void tearDown(void)
{
}

void test_core_add(void)
{
  TEST_ASSERT( add(1,2) == 3);
}

void test_core_add_struct(void) {
  addition* calc = calloc(1, sizeof(addition));
  
  TEST_ASSERT(calc);
  
  calc->augend = 3;
  calc->addend = 4;
  add_struct(calc);
  
  TEST_ASSERT(calc->sum == 7);
}