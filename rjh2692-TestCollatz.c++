// --------------------------------
// projects/collatz/TestCollatz.c++
// Copyright (C) 2016
// Glenn P. Downing
// --------------------------------

// https://code.google.com/p/googletest/wiki/V1_7_Primer#Basic_Assertions

// --------
// includes
// --------

#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // string

#include "gtest/gtest.h"

#include "Collatz.h"

using namespace std;

// ----
// read
// ----

TEST(CollatzFixture, read) {
  istringstream r("1 10\n");
  int i;
  int j;
  const bool b = collatz_read(r, i, j);
  ASSERT_TRUE(b);
  ASSERT_EQ(1, i);
  ASSERT_EQ(10, j);
}

// -----------------
// compute_cycle_len
// -----------------

TEST(CollatzFixture, compute_cycle_len_1) {
  const int v = compute_cycle_len(1);
  ASSERT_EQ(1, v);
}

TEST(CollatzFixture, compute_cycle_len_2) {
  const int v = compute_cycle_len(400);
  ASSERT_EQ(28, v);
}

TEST(CollatzFixture, compute_cycle_len_3) {
  const int v = compute_cycle_len(666);
  ASSERT_EQ(114, v);
}

// ----
// eval
// ----

TEST(CollatzFixture, eval_1) {
  const int v = collatz_eval(1, 10);
  ASSERT_EQ(20, v);
}

TEST(CollatzFixture, eval_2) {
  const int v = collatz_eval(100, 200);
  ASSERT_EQ(125, v);
}

TEST(CollatzFixture, eval_3) {
  const int v = collatz_eval(666, 666);
  ASSERT_EQ(114, v);
}

TEST(CollatzFixture, eval_4) {
  const int v = collatz_eval(900, 1000);
  ASSERT_EQ(174, v);
}

TEST(CollatzFixture, eval_5) {
  const int v = collatz_eval(1, 320);
  ASSERT_EQ(131, v);
}

TEST(CollatzFixture, eval_6) {
  const int v = collatz_eval(3, 3);
  ASSERT_EQ(8, v);
}

TEST(CollatzFixture, eval_7) {
  const int v = collatz_eval(1738, 2000);
  ASSERT_EQ(180, v);
}

TEST(CollatzFixture, eval_8) {
  const int v = collatz_eval(9999, 1);
  ASSERT_EQ(262, v);
}

// -----
// print
// -----

TEST(CollatzFixture, print) {
  ostringstream w;
  collatz_print(w, 1, 10, 20);
  ASSERT_EQ("1 10 20\n", w.str());
}

// -----
// solve
// -----

TEST(CollatzFixture, solve) {
  istringstream r("1 10\n100 200\n201 210\n900 1000\n");
  ostringstream w;
  collatz_solve(r, w);
  ASSERT_EQ("1 10 20\n100 200 125\n201 210 89\n900 1000 174\n", w.str());
}
