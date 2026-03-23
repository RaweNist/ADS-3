// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
  uint64_t maxnum = num;
  while (num != 1) {
    if (maxnum < num) {
      maxnum = num;
    }
    if (num % 2 == 0) {
      num /= 2;
    } else {
      num = 3 * num + 1;
    }
  }
  return maxnum;
}
unsigned int collatzLen(uint64_t num) {
  uint64_t len = 1;
  while (num != 1) {
    if (num % 2 == 0) {
      num /= 2;
    } else {
      num = 3 * num + 1;
    }
    len++;
  }
  return len;
}
unsigned int seqCollatz(unsigned int* maxlen,
uint64_t lbound, uint64_t rbound) {
  *maxlen = 1;
  uint64_t num = lbound;
  for (; lbound < rbound+1; ++lbound) {
    unsigned int len = 1;
    uint64_t n = lbound;
    while (n != 1) {
      if (n % 2 == 0) {
        n /= 2;
      } else {
        n = 3 * n + 1;
      }
      len++;
    }
    if (len > *maxlen) {
      *maxlen = len;
      num = lbound;
    }
  }
  return num;
}
