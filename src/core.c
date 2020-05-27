#include "core.h"
#include <stdlib.h>
#include <jemalloc.h>
#include <zlog.h>

int add(int num1, int num2) {
  
  zlogf_time(ZLOG_INFO_LOG_MSG, " No escaping allocs here! Ha!\n");
  
  addition* calc = jecalloc(1, sizeof(addition));
  
  if (!calc) { return 0; }
  
  calc->augend = num1;
  calc->addend = num2;
    
  add_struct(calc);
  int sum = calc->sum;
  
  jefree(calc);
  
  return sum;
}

void add_struct(addition* calc) {
  calc->sum = calc->augend + calc->addend;
}