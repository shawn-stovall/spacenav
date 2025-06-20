cmake_minimum_required(VERSION 3.30)
project(spacenav)
include_directories(Event/headers)
include_directories("Event Manager/headers")

message(STATUS ${CMAKE_CURRENT_SOURCE_DIR})

set(CMAKE_CXX_STANDARD 20)
set(EVENT_SRCS Event/EventBase.cpp
        Event/EventId.cpp
        "Event Manager/EventManager.cpp")
set(EVENT_HDRS Event/headers/EventBase.h
        Event/headers/EventId.h
        "Event Manager/headers/EventManager.h")

find_package(Boost REQUIRED)
find_package(Catch2 3 REQUIRED)

if (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
endif ()

add_executable(tests test.cpp
        test.h
        "Event Manager/test_fixtures/DummyEvent.cpp"
        "Event Manager/test_fixtures/headers/DummyEvent.h"
        "Event Manager/test/EventManager_test.cpp"
)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)
add_executable(spacenav main.cpp
        Event/EventBase.cpp
        Event/headers/EventBase.h
        Event/EventId.cpp
        Event/headers/EventId.h
        "Event Manager/EventManager.cpp"
        "Event Manager/headers/EventManager.h"
)

add_executable(event_manager_tests
        "Event Manager/test_fixtures/DummyEvent.cpp"
        "Event Manager/test/EventManager_test.cpp"
        "Event Manager/test_fixtures/headers/DummyEvent.h"
        ${EVENT_SRCS}
        ${EVENT_HDRS}
)
target_link_libraries(event_manager_tests PRIVATE Catch2::Catch2WithMain)


include(CTest)
include(Catch)