#ifndef STAN_LANG_AST_NODE_TUPLE_EXPR_HPP
#define STAN_LANG_AST_NODE_TUPLE_EXPR_HPP

#include <stan/lang/ast/tuple_type.hpp>
#include <stan/lang/ast/scope.hpp>
#include <stan/lang/ast/node/expression.hpp>
#include <vector>

namespace stan {
  namespace lang {

    struct expresssion;

    /**
     * Structure to hold a tuple expression.
     */
    struct tuple_expr {
      /**
       * Type of tuple.
       */
      tuple_type type_;

      /**
       * Sequence of expressions for tuple values.
       */
      std::vector<expression> elements_;

      /**
       * True if there is a variable within any of the expressions
       * that is a parameter, transformed parameter, or non-integer
       * local variable.
       */
      bool has_var_;

      /**
       * Scope of this tuple expression.
       *
       */
      scope tuple_expr_scope_;

      /**
       * Construct a default tuple expression.
       */
      tuple_expr();

      /**
       * Construct a tuple expression from a specified type
       * and sequence of expressions.
       *
       * @param type tuple type
       * @param elements sequence of expressions
       */
      explicit tuple_expr(const tuple_type& type,
                          const std::vector<expression>& elements);
    };

  }
}
#endif
