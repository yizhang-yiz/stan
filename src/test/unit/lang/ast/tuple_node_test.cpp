#include <stan/lang/ast_def.cpp>
#include <gtest/gtest.h>
#include <sstream>
#include <string>
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

TEST(StanLangAstTupleType, ctor) {
  std::vector<expr_type> elt_types;
  elt_types.push_back(expr_type(int_type()));
  elt_types.push_back(expr_type(double_type()));
  elt_types.push_back(expr_type(vector_type()));
  tuple_type tt(elt_types);
  EXPECT_TRUE(tt.types_.size() == 3);
}

TEST(StanLangAstTupleNode, ctor_0_arg) {
  stan::lang::tuple_expr te;
  EXPECT_TRUE(te.type_.types_.size() == 0);
  EXPECT_TRUE(te.elements_.size() == 0);
}

TEST(StanLangAstTupleNode, ctor_1_arg) {
  std::vector<expr_type> elt_types;
  elt_types.push_back(expr_type(int_type()));
  elt_types.push_back(expr_type(double_type()));
  tuple_type tt(elt_types);
  stan::lang::tuple_expr te(tt);
  EXPECT_TRUE(te.type_.types_.size() == 2);
}

TEST(StanLangAstTupleNode, ctor_2_arg) {
  std::vector<expr_type> elt_types;
  elt_types.push_back(expr_type(int_type()));
  elt_types.push_back(expr_type(double_type()));
  tuple_type tt(elt_types);

  std::vector<expression> elts;
  elts.push_back(stan::lang::expression(stan::lang::int_literal(1)));
  elts.push_back(stan::lang::expression(stan::lang::double_literal(1.3)));
  stan::lang::tuple_expr te(tt,elts);
  EXPECT_TRUE(te.type_.types_.size() == 2);
  EXPECT_TRUE(te.elements_.size() == 2);
}

TEST(StanLangAstTupleNode, nested) {
  std::vector<expr_type> nested_elt_types;
  nested_elt_types.push_back(expr_type(int_type()));
  nested_elt_types.push_back(expr_type(double_type()));
  tuple_type nest_tt(nested_elt_types);
  std::vector<expr_type> elt_types;
  elt_types.push_back(expr_type(int_type()));
  elt_types.push_back(expr_type(nest_tt));
  tuple_type tt(elt_types);
  stan::lang::tuple_expr te(tt);
  EXPECT_TRUE(te.type_.types_.size() == 2);
}
