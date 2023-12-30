#ifndef UTILS_H
#define UTILS_H
////////////////////////////////////////////////////////////////////////////////
#include<unordered_map>
////////////////////////////////////////////////////////////////////////////////

enum class DIR{
  LEFT,
  RIGHT,
  UP,
  DOWN,
  NOTHING
};

extern std::unordered_map<DIR, std::pair<short, short>> dir_indirection;

#endif //UTILS_H
