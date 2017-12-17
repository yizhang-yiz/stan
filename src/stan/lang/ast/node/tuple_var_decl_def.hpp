#ifndef STAN_LANG_AST_NODE_TUPLE_VAR_DECL_DEF_HPP
#define STAN_LANG_AST_NODE_TUPLE_VAR_DECL_DEF_HPP

#include <stan/lang/ast.hpp>
#include <string>
#include <vector>

namespace stan {
  namespace lang {

    tuple_var_decl::tuple_var_decl() : base_var_decl(tuple_type()) { }

    tuple_var_decl::tuple_var_decl(const std::vector<base_var_decl>& element_decls,
                                   const std::string& name,
                                   const std::vector<expression>& dims,
                                   const expression& def)
      : base_var_decl(name, dims, tuple_type(), def), element_decls_(element_decls) {
    }

  }
}
#endif
