#ifndef PHASE_RESOURCE_MANAGER_HPP
#define PHASE_RESOURCE_MANAGER_HPP

#include <vector>
#include "Character.hpp"
#include "Box.hpp"
#include "Target.hpp"

class PhaseResourceManager {
public:
    static void LoadPhase(int phase, Character& man, std::vector<Box>& boxes, std::vector<Target>& targets);
};

#endif // PHASE_RESOURCE_MANAGER_HPP