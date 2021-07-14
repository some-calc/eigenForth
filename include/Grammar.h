#pragma once

#include <map>
#include <string>
#include <functional>
#include <string>

class State;

class Grammar
{
private:
  std::map<std::string, std::function<void(State &)>> builtins_;

  enum class WordType { FUNCTION, INTEGER };
  static WordType determineType();

public:
  Grammar();
  std::function<void(State &)> parse(const std::string &input, State &state);
  static bool is_structural(std::function<void(State &)>);
};
