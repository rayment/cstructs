/*
 * common_test.h
 * Common test suite defines.
 *
 * Author       : Finn Rayment <finn@rayment.fr>
 * Date created : 25/03/2021
 */

#ifndef _RAYMENT_FR_CSTRUCTS_TEST_COMMON_TEST_H
#define _RAYMENT_FR_CSTRUCTS_TEST_COMMON_TEST_H 1

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RED    "\x1b[1;31m"
#define YELLOW "\x1b[1;33m"
#define GREEN  "\x1b[1;32m"
#define BOLD  "\x1b[1m"
#define RESET  "\x1b[0m"

#define INIT() clock_t tic, toc;

#define FAIL(x,y) if (!(x)) {\
                      fprintf(stdout, "\r" RED "FAILURE: " RESET "%s\n", y);\
                      return EXIT_FAILURE;\
                  } else {\
                      fprintf(stdout, "\r" GREEN "SUCCESS: " RESET "%s\n", y);\
                  }
#define TEST(x,y,z) fprintf(stdout, "TEST: %s", z); fflush(stdout); x FAIL(y,z)

#define TIME(x,y) tic = clock(); x toc = clock(); \
                  fprintf(stdout, YELLOW "BENCHMARK " RESET \
                          "(%s): " BOLD "%fs\n" RESET, y, \
                          (double) (toc - tic) / CLOCKS_PER_SEC);

#endif /* _RAYMENT_FR_CSTRUCTS_TEST_COMMON_TEST_H */

