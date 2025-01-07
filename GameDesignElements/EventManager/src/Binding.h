#pragma once

#include "EventDetails.h"
#include "EventInfo.h"
#include "EventTypes.h"

#include <vector>

namespace sfmlgamedev {
typedef std::vector<std::pair<EventType, EventInfo>> EventsT;

struct Binding {
  Binding(const std::string &name)
      : m_name(name), m_details(name), eventCount(0) {}

  EventsT m_events;
  std::string m_name;
  uint32_t eventCount;
  EventDetails m_details;
};
} // namespace sfmlgamedev
