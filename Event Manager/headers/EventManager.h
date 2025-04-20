//
// Created by Shawn Stovall on 3/26/25.
//

#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H
#include <unordered_map>
#include <EventBase.h>
#include <EventInitializer.h>

class EventManager {
private:
    static EventManager event_manager;

    std::unordered_map<EventId, std::unique_ptr<EventBase>> events;

    EventManager() = default;
public:
    static EventManager& get_instance();

    template<Event E>
    EventId build_event(const typename E::Initializer& initializer);
    bool kill_event(const EventId& id);

    void run_event(const EventId& id);

    EventManager(const EventManager&) = delete;
    EventManager& operator=(const EventManager&) = delete;
    EventManager& operator=(EventManager&&) = delete;
    EventManager(EventManager&&) = delete;
};



#endif //EVENTMANAGER_H
