//
// Created by Shawn Stovall on 4/21/25.
//

#include "EventManager.h"

#include <catch2/catch_test_macros.hpp>

#include "../test_fixtures/headers/DummyEvent.h"

using namespace tests::event_manager;

TEST_CASE("basic initialization through EventManager factory", "[EventManager]") {
  EventManager& em = EventManager::get_instance();
  DummyEvent::Initializer init{2, "test string"};
  EventId id = em.build_event<DummyEvent>(init);

  REQUIRE(em.run_event(id));
}