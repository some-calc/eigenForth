#pragma once

#include <giac/config.h>
#include <giac/giac.h>

#include <stack>
#include <vector>

class State
{
public:
  std::stack<giac::gen, std::vector<giac::gen>> stack_;
  std::size_t disabled_block_depth_;
  giac::context context_;
};
