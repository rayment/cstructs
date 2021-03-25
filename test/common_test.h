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

#define FAIL(x,y) if (!(x)) {\
                      fprintf(stdout, "\rFAILURE: %s\n", y);\
                      return EXIT_FAILURE;\
                  } else {\
                      fprintf(stdout, "\rSUCCESS: %s\n", y);\
                  }
#define TEST(x,y,z) fprintf(stdout, "TEST: %s", z); fflush(stdout); x FAIL(y,z)

#endif /* _RAYMENT_FR_CSTRUCTS_TEST_COMMON_TEST_H */

