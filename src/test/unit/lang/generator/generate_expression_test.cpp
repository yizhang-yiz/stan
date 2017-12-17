#include <stan/lang/ast.hpp>
#include <stan/lang/ast_def.cpp>
#include <stan/lang/generator.hpp>
#include <ostream>
#include <iostream>
#include <sstream>
#include <vector>
#include <test/unit/lang/utility.hpp>
#include <gtest/gtest.h>


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
using stan::lang::tuple_expr;

TEST(langGenerator, genTupleExpr) {
  std::stringstream o;

  std::vector<expr_type> nested_elt_types;
  nested_elt_types.push_back(expr_type(double_type()));
  nested_elt_types.push_back(expr_type(row_vector_type()));
  tuple_type nest_tt(nested_elt_types);
  std::vector<expr_type> elt_types;
  elt_types.push_back(expr_type(int_type()));
  elt_types.push_back(expr_type(nest_tt));
  tuple_type tt(elt_types);
  tuple_expr te(tt);
  
  stan::lang::generate_expression(te, true, o);
  std::cout << "generated: " << o.str() << std::endl;
  EXPECT_EQ(1,1);
}
