//
// Created by Shawn Stovall on 3/26/25.
//

#include <EventManager.h>

EventManager EventManager::event_manager = EventManager();

/**
 * Deletes the Event tied with the EventId.
 * @todo Add a message to all events about deletion of certain event.
 * @param id The \link EventId \endlink of the Event to be deleted
 * @return If any events were deleted.
 */
bool EventManager::kill_event(const EventId& id) {
  return events.erase(id) > 0;
}

/**
 * Takes an \link EventId \endlink and runs the associated Event. If the evnet
 * does not exist or if even fails to run, returns false.
 * @param id The ID of the Event to be run.
 * @return Whether the Event was run successfully or not.
 */
bool EventManager::run_event(const EventId& id) {
  if (auto event = events.find(id); event != events.end()) {
    return event->second->run();
  }

  return false;
}
