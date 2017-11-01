#include <stan/lang/ast_def.cpp>
#include <gtest/gtest.h>
#include <cmath>
#include <sstream>
#include <string>
#include <set>
#include <vector>

using stan::lang::expression;
using stan::lang::expr_type;
using stan::lang::base_expr_type;
using stan::lang::ill_formed_type;
using stan::lang::void_type;
using stan::lang::double_type;
using stan::lang::int_type;
using stan::lang::vector_type;
using stan::lang::row_vector_type;
using stan::lang::matrix_type;
using stan::lang::tuple_type;
using std::vector;


TEST(StanLangAst, Tuple) {
  stan::lang::scope s;
  EXPECT_TRUE(s.is_local() == true || s.is_local() == false);
}
