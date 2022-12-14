#ifndef SRC_CHECK_TEST_H_
#define SRC_CHECK_TEST_H_

#include <check.h>

#include "./../backend/viewer.h"

#define TEST_PRECISION 1e-6

Suite* suite_open_file(void);
Suite* suite_count_data(void);


#endif  // SRC_CHECK_TEST_H_