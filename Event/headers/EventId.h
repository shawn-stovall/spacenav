//
// Created by Shawn Stovall on 3/26/25.

#ifndef EVENTID_H
#define EVENTID_H
#include <boost/functional/hash.hpp>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <functional>

/**
 * Acts as a primary key for EventBase
 */
class EventId {
 private:
  boost::uuids::uuid id;

 public:
  EventId() : id(boost::uuids::random_generator()()) {}

  bool operator==(const EventId& id) const { return this->id == id.id; }
  bool operator!=(const EventId& id) const { return this->id != id.id; }

  friend std::hash<EventId>;
};

/**
 * Acts as the hash function for EventId
 */
namespace std {
template <>
struct hash<EventId> {
  size_t operator()(const EventId& id) const noexcept {
    return boost::hash<boost::uuids::uuid>()(id.id);
  }
};
}  // namespace std

#endif  // EVENTID_H
