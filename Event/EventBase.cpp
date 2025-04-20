//
// Created by Shawn Stovall on 3/26/25.
//

#include <EventBase.h>
#include <EventManager.h>

EventBase::EventBase() : event_manager(EventManager::get_instance()) {}

bool EventBase::register_event(const EventId &id) {

}

EventBase::EventBase(EventBase &&event) noexcept
: event_manager(event.event_manager) {
}

