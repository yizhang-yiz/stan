#ifndef STAN_LANG_AST_TUPLE_TYPE_HPP
#define STAN_LANG_AST_TUPLE_TYPE_HPP

#include <stan/lang/ast/expr_type.hpp>
#include <vector>

namespace stan {
  namespace lang {

    struct expr_type;

    /**
     * Tuple base expression type.
     */
    struct tuple_type {
      static const int ORDER_ID = 7;

      /**
       * Sequence of types for tuple elements.
       */
      std::vector<expr_type> types_;

      /**
       * Construct a tuple type from the specified sequence of
       * expression types.
       *
       * @param types sequence of expression types
       */
      explicit tuple_type(const std::vector<expr_type>& types);
    };

  }
}
#endif
