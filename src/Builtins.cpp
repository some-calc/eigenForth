#include "Builtins.h"

#include "ProgramState.h"

#include <iostream>

namespace Builtins
{
void plus(State &state) {
  auto a = state.stack_.top();
  state.stack_.pop();
  auto b = state.stack_.top();
  state.stack_.pop();

  state.stack_.push(giac::operator_plus(a, b, &state.context_));
}

void minus(State &state) {
  auto a = state.stack_.top();
  state.stack_.pop();
  auto b = state.stack_.top();
  state.stack_.pop();

  state.stack_.push(giac::operator_minus(a, b, &state.context_));
}

void multiply(State &state) {
  auto a = state.stack_.top();
  state.stack_.pop();
  auto b = state.stack_.top();
  state.stack_.pop();

  state.stack_.push(giac::operator_times(a, b, &state.context_));
}

void divide(State &state) {
  auto b = state.stack_.top();
  state.stack_.pop();
  auto a = state.stack_.top();
  state.stack_.pop();

  assert(false and "Not implemented yet,");
  // state.stack_.push(giac::operator_div(a, b, &state.context_));
}

void dup(State &state) { state.stack_.push(state.stack_.top()); }

void drop(State &state) { state.stack_.pop(); }

void dropN(State &state) {
  auto n = state.stack_.top();

  for (std::size_t i = 0; i < n; i++) {
    state.stack_.pop();
  }
}

void print_stack(State &state) {
  std::vector<giac::gen> buffer{};

  for (int i = std::min(state.stack_.size(), 9lu) - 1; i >= 0; i--) {
    buffer.insert(buffer.begin(), state.stack_.top());
    state.stack_.pop();
  }

  for (auto a : buffer) {
    std::cout << ": " << a << std::endl;
    state.stack_.push(a);
  }
}

void exec_if(State &state) {
  if (state.disabled_block_depth_) {
    state.disabled_block_depth_++;
    return;
  }

  auto cond = state.stack_.top();
  state.stack_.pop();

  if (giac::is_zero(cond))
    state.disabled_block_depth_++;
}

void end_block(State &state) {
  if (state.disabled_block_depth_ >= 1)
    state.disabled_block_depth_--;
}
} // namespace Builtins
