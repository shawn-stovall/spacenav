//
// Created by Shawn Stovall on 3/26/25.
//

#ifndef EVENTBASE_H
#define EVENTBASE_H
#include <unordered_set>

#include <EventId.h>

class EventManager;

class EventBase {
private:
    const EventManager& event_manager;

    EventId id{};
    std::unordered_set<EventId> registered_events;
protected:
    EventBase();
public:
    virtual ~EventBase() = default;

    bool register_event(const EventId& id);
    bool unregister_event(const EventId& id);

    [[nodiscard]] EventId get_id() const { return id; }

    virtual bool run() = 0;

    EventBase(EventBase&& event) noexcept;

    class Initializer {
    protected:
        Initializer() = default;
    };
};

template<typename T>
concept Event = std::is_base_of_v<EventBase, T>;

#endif //EVENTBASE_H
