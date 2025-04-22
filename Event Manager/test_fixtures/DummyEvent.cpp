//
// Created by Shawn Stovall on 4/21/25.
//

#include "headers/DummyEvent.h"

namespace tests::event_manager {

DummyEvent::DummyEvent(const Initializer& initializer) {
  test_int = initializer.get_test_int();
  test_string = initializer.get_test_string();
}

bool DummyEvent::run() { return test_int == 2 && test_string == "test string"; }

}  // namespace tests::event_manager
// tests