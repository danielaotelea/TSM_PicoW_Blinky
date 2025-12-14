/*
 * Copyright (c) 2023-2024, Erich Styger
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef GCOV_TEST_H_
#define GCOV_TEST_H_

#ifdef __cplusplus
extern "C" {

#endif

int Calc(int i, int j);
void Test2(int* p);
int Value(int i);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* GCOV_TEST_H_ */
