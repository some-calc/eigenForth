#include "Grammar.h"

#include "Builtins.h"
#include "ProgramState.h"

#include <giac/giac.h>
#include <giac/config.h>

#include <stdexcept>
#include <iostream>

Grammar::Grammar()
    : builtins_({{"DROP", Builtins::drop},
                 {"DROPN", Builtins::dropN},
                 {"DUP", Builtins::dup},
                 {"+", Builtins::plus},
                 {"-", Builtins::minus},
                 {"*", Builtins::multiply},
                 {"/", Builtins::divide},
                 {"P", Builtins::print_stack},
                 {"IF", Builtins::exec_if},
                 {"END", Builtins::end_block}}) {}

bool Grammar::is_structural(std::function<void(State &)> builtin_function) {
  auto builtin_address = builtin_function.target<void (*)(State &)>();

  if (not builtin_address) return false;
  if (*builtin_address == Builtins::exec_if) return true;
  if (*builtin_address == Builtins::end_block) return true;

  return false;
}

std::function<void(State &)> Grammar::parse(const std::string &input,
                                            State &state) {
  // Case 1: Looking up the input in out keyword list
  auto symbol_iter = builtins_.find(input);
  if (symbol_iter != builtins_.end()) {
    return symbol_iter->second;
  }

  // Case 2: Parse the input as a giac expression
  giac::gen giac_expr{input.c_str(), &state.context_};
  giac::eval(giac_expr, &state.context_);
  return Builtins::PushAny<giac::gen>(giac_expr);
}
