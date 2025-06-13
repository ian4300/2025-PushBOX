#ifndef PHASE_MANGER_HPP
#define PHASE_MANGER_HPP

#include <memory>
#include "App.hpp"

class man;

class PhaseResourceManger {
public:
    PhaseResourceManger();

/*    [[nodiscard]] std::vector<std::shared_ptr<Util::GameObject>> GetChildren() const {
        return {m_TaskText, m_Background};
    }
*/
    void NextPhase();
    void Reset();
    void Jump();
    void Fail();
    void Victory();
    int GetPhase() const;

private:
   /* std::shared_ptr<TaskText> m_TaskText;
    std::shared_ptr<BackgroundImage> m_Background;
 */
    int m_Phase = 0;
    std::shared_ptr<man> m_man;
};


#endif //PHASE_MANGER_HPP