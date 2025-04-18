#include "PhaseResourceManger.hpp"

#include "Util/Logger.hpp"

void PhaseResourceManger::NextPhase() {
    if (m_Phase == 3) return;
    LOG_DEBUG("Passed! Next phase: {}", m_Phase);
}