//
// Created by Shawn Stovall on 3/26/25.
//

#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H
#include <EventBase.h>

#include <unordered_map>

class EventManager {
 private:
  static EventManager event_manager;

  std::unordered_map<EventId, std::unique_ptr<EventBase>> events;

  EventManager() = default;

 public:
  static EventManager& get_instance() { return event_manager; }

  /**
   * Constructs an event
   * @tparam E The derived Event class that will be built.
   * @param initializer The internal \link EventBase::Initializer \endlink used
   * to initialize the Event being built.
   * @return The \link EventId \endlink of the constructed Event.
   */
  template <Event E>
  EventId build_event(const typename E::Initializer& initializer) {
    std::unique_ptr<E> event = std::make_unique<E>(initializer);
    EventId id = event->get_id();
    events.emplace(id, std::move(event));
    return id;
  }

  bool kill_event(const EventId& id);

  bool run_event(const EventId& id);

  EventManager(const EventManager&) = delete;
  EventManager& operator=(const EventManager&) = delete;
  EventManager& operator=(EventManager&&) = delete;
  EventManager(EventManager&&) = delete;
};

#endif  // EVENTMANAGER_H
