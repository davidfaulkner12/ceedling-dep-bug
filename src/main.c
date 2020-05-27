#include <stdio.h>
#include <stdlib.h>
#include <jemalloc.h>
#include <zlog.h>
#include "core.h"

int main(int argc, char* argv[]) {
  zlog_init_stdout();
  atexit(zlog_finish);
  
  zlogf_time(ZLOG_INFO_LOG_MSG, " The magic number is %d\n", add(1, 2));

  addition* calc = jecalloc(1, sizeof(addition));
  if (!calc) {
    printf("Something went horribly wrong\n");
  }
    
  calc->augend = 17;
  calc->addend = 25;
  
  add_struct(calc);
  
  zlogf_time(ZLOG_INFO_LOG_MSG, " An even more magic number is %d\n", calc->sum);
  
  return 0;
}