//
// Created by Shawn Stovall on 3/26/25.
//

#include <EventManager.h>

EventManager EventManager::event_manager = EventManager();

template<Event E>
EventId EventManager::build_event(const typename E::Initializer& initializer) {
    std::unique_ptr<E> event = std::make_unique<E>(initializer);
    EventId id = event->get_id();
    events.emplace(id, std::move(event));
    return id;
}

bool EventManager::kill_event(const EventId &id) {
    return events.erase(id) > 0;
}

