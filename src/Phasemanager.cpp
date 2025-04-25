#include "PhaseResourceManger.hpp"
#include "Util/Logger.hpp"

PhaseResourceManger::PhaseResourceManger() {
}

void PhaseResourceManger::NextPhase() {
    if (m_Phase <= 3)
    {
        m_Phase++;
    }
    else return;
        LOG_DEBUG("Passed! Next phase: {}", m_Phase);
}
int PhaseResourceManger::GetPhase() const {
    return m_Phase;
}