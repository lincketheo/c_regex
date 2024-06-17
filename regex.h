#ifndef _CSV_H
#define _CSV_H

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#if defined(__cplusplus)
extern "C" {
#endif

typedef struct {
  size_t index_start;
  size_t index_end_nic;
  char** captures;
  size_t captures_len;
} regex_result;

typedef struct {
  regex_result* results;
  size_t length;
} regex_results;

void regex_results_free(regex_results* results);

regex_results match(const char* str, const char* regex, size_t* ret_size);

#if defined(__cplusplus)
}
#endif

#endif
