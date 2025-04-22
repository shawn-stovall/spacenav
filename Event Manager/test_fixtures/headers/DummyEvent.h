//
// Created by Shawn Stovall on 4/21/25.
//

#ifndef DUMMYEVENT_H
#define DUMMYEVENT_H
#include <utility>

#include "EventBase.h"

namespace tests {
namespace event_manager {

class DummyEvent : public EventBase {
  int test_int;
  std::string test_string;

 public:
  bool run() override;

  class Initializer : public EventBase::Initializer {
    int test_int;
    std::string test_string;

   public:
    Initializer(int test_int, const std::string& test_string)
        : test_int(test_int), test_string(test_string) {}

    [[nodiscard]] int get_test_int() const { return test_int; }
    [[nodiscard]] std::string get_test_string() const { return test_string; }
  };

  explicit DummyEvent(const Initializer& initializer);
};

}  // namespace event_manager
}  // namespace tests

#endif  // DUMMYEVENT_H
