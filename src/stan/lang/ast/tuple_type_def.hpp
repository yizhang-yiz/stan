#ifndef STAN_LANG_AST_TUPLE_TYPE_DEF_HPP
#define STAN_LANG_AST_TUPLE_TYPE_DEF_HPP

#include <stan/lang/ast/tuple_type.hpp>
#include <vector>

namespace stan {
  namespace lang {

    tuple_type::tuple_type()
      : types_() { }
    
    tuple_type::tuple_type(const std::vector<expr_type>& types)
      : types_(types) { }

  }
}
#endif
