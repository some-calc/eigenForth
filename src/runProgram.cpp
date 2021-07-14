#include "runProgram.h"

#include "ProgramState.h"
#include "Grammar.h"
#include "Builtins.h"

#include <giac/config.h>
#include <giac/giac.h>

void run(std::istream& input, std::ostream& output, std::ostream& error) {
  Grammar grammar{};
  State state{};

  while (not input.eof()) {
    std::string word;
    input >> word;

    std::function<void(State &)> to_execute = grammar.parse(word, state);

    if (not state.disabled_block_depth_ or Grammar::is_structural(to_execute)) {
      to_execute(state);
      Builtins::print_stack(state);
    }
  }
}
