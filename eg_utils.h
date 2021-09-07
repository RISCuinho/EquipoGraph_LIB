#ifndef UTILS_H
#define UTILS_H

#include <stdexcept>

namespace eg_utils {
class NullPointer : public std::runtime_error {
public:
  NullPointer() : std::runtime_error("MyException") { }
};

}

#endif // UTILS_H
