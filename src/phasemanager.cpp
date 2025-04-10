#include "PhaseResourceManager.hpp"

void PhaseResourceManager::LoadPhase(int phase, Character& man, std::vector<Box>& boxes, std::vector<Target>& targets) {
    boxes.clear();
    targets.clear();

    if (phase == 1) {
        man.SetPosition({1, 1});
        boxes = {{2, 2}, {3, 3}};
        targets = {{4, 4}, {5, 5}};
    } else if (phase == 2) {
        man.SetPosition({2, 2});
        boxes = {{3, 3}, {4, 4}};
        targets = {{5, 5}, {6, 6}};
    } else if (phase == 3) {
        man.SetPosition({3, 3});
        boxes = {{4, 4}, {5, 5}};
        targets = {{6, 6}, {7, 7}};
    }
}