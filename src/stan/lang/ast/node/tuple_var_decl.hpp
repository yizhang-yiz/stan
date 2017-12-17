#ifndef STAN_LANG_AST_NODE_TUPLE_VAR_DECL_HPP
#define STAN_LANG_AST_NODE_TUPLE_VAR_DECL_HPP

#include <stan/lang/ast/node/base_var_decl.hpp>
#include <stan/lang/ast/node/expression.hpp>
#include <string>
#include <vector>

namespace stan {
  namespace lang {

    /**
     * Structure to hold a tuple variable declaration.
     */
    struct tuple_var_decl : public base_var_decl {
      /**
       * Sequence of variable declarations for contained elements.
       */ 
      std::vector<base_var_decl> element_decls_;
      
      /**
       * Construct a tuple variable declaration with default values.
       */
      tuple_var_decl();

      /**
       * Construct a tuple variable declaration with the specified
       * sequence of tuple element types, name, number of array dimensions,
       * and definition.
       *
       * @param types
       * @param name variable name
       * @param dims array dimension sizes
       * @param def defition of variable
       */
      tuple_var_decl(const std::vector<base_var_decl>& element_decls,
                     const std::string& name,
                     const std::vector<expression>& dims,
                     const expression& def);
    };
  }
}
#endif
