// (C) Copyright Vesa Karvonen 2004.
//
//    Distributed under the Boost Software License, Version 1.0.

#include "error.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

void error(const char* msg, ...) {
  va_list args;
  va_start(args, msg);
  vfprintf(stderr, msg, args);
  va_end(args);
  exit(EXIT_FAILURE);
}