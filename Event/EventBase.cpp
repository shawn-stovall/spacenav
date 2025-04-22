//
// Created by Shawn Stovall on 3/26/25.
//

#include <EventBase.h>
#include <EventManager.h>

/**
 * A constructor
 * The default constructor for \link EventBase \endlink sets up the
 * \link EventManager \endlink instance reference for usage in the derived
 * class.
 */
EventBase::EventBase() : event_manager(EventManager::get_instance()) {}

/**
 * This method registers an \link EventId \endlink with the calling Event. These
 * IDs will be stored in an unordered fashion, and will be processed by the
 * internal Tasks.
 * @param id The ID of the event which needs to be connected.
 * @return If the registration was successful or not.
 */
bool EventBase::register_event(const EventId &id) {
  return registered_events.insert(id).second;
}

/**
 * This method unregisters an \link EventId \endlink with the calling Event. If
 * the event ID exists and was unregistered successfully, returns true.
 * @param id The ID of the event which needs to be disconnected.
 * @return If the unregistration unregistered anything.
 */
bool EventBase::unregister_event(const EventId &id) {
  return registered_events.erase(id) > 0;
}

/**
 * A constructor
 * This is the move constructor for Events. The primary concern is moving the
 * internal event list, as copying this could be quite a heavy operation.
 * @param event The event from which to move.
 */
EventBase::EventBase(EventBase &&event) noexcept
    : event_manager{EventManager::get_instance()},
      registered_events{std::move(event.registered_events)} {}
