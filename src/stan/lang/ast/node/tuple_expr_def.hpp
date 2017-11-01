#ifndef STAN_LANG_AST_NODE_TUPLE_EXPR_DEF_HPP
#define STAN_LANG_AST_NODE_TUPLE_EXPR_DEF_HPP

#include <stan/lang/ast.hpp>
#include <vector>

namespace stan {
  namespace lang {

    tuple_expr::tuple_expr()
      : has_var_(false), tuple_expr_scope_() { }

    tuple_expr::tuple_expr(const tuple_type& type,
                           const std::vector<expression>& elements)
      : type_(type), elements_(elements), has_var_(false),
        tuple_expr_scope_() { }

  }
}
#endif
