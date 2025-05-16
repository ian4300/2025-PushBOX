#ifndef PHASE_MANGER_HPP
#define PHASE_MANGER_HPP

#include "Util/GameObject.hpp"
//#include "BackgroundImage.hpp"

class PhaseResourceManger {
public:
    PhaseResourceManger();

/*    [[nodiscard]] std::vector<std::shared_ptr<Util::GameObject>> GetChildren() const {
        return {m_TaskText, m_Background};
    }
*/
    void NextPhase();
    void Reset();
    int GetPhase() const;

private:
   /* std::shared_ptr<TaskText> m_TaskText;
    std::shared_ptr<BackgroundImage> m_Background;
 */
    int m_Phase = 0;
};


#endif //PHASE_MANGER_HPP