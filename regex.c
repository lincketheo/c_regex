#include "regex.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void regex_error(const char* msg_fmt, ...)
{
  va_list args;
  va_start(args, msg_fmt);
  printf("csv error: ");
  vprintf(msg_fmt, args);
}

void regex_results_free(regex_results* results)
{
  if (results) {
    if (results->results) {
      for (int i = 0; i < results->length; ++i) {
        regex_result result = results->results[i];
        if (result.captures) {
          for (int i = 0; i < result.captures_len; ++i) {
            if (result.captures[i]) {
              free(result.captures[i]);
            }
          }
          free(result.captures);
        }
      }
      free(results->results);
    }
  }
}

regex_results match_no_strlen(
    const char* str,
    const char* regex,
    size_t str_len,
    size_t regex_len,
    size_t* ret_size)
{
  regex_results ret = { 0 }; 
  return ret;
}

regex_results match(const char* str, const char* regex, size_t* ret_size)
{
  return match_no_strlen(str, regex, strlen(str), strlen(regex), ret_size);
}
