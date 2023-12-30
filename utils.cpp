#include "utils.h"

std::unordered_map<DIR, std::pair<short, short>> dir_indirection{
  {DIR::LEFT, {-1, 0}},
  {DIR::RIGHT, {1, 0}},
  {DIR::UP, {0, -1}},
  {DIR::DOWN, {0, 1}},
  {DIR::NOTHING, {0, 0}}
};
