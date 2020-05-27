#ifndef CORE_H
#define CORE_H

int add(int num1, int num2);

typedef struct {
  int augend;
  int addend;
  int sum;
} addition;

void add_struct(addition* calc);

#endif