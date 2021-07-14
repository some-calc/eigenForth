#pragma once

#include "ProgramState.h"

#include <functional>

namespace Builtins
{

template <typename T> class PushAny {
private:
  T to_push_;
public:
  PushAny(T to_push) : to_push_(to_push) {}
  void operator()(State &state) { state.stack_.push(to_push_); }
};

void plus(State &state);
void minus(State &state);
void multiply(State &state);
void divide(State &state);

void dup(State &state);
void drop(State &state);
void dropN(State &state);

void print_stack(State& state);

void exec_if(State& state);
void end_block(State& state);
// namespace Builtins
}
