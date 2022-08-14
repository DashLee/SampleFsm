#pragma once

#include <memory>

template<typename EntityType>
class IState;

template <typename EntityType>
class StateMachine
{
public:
    StateMachine();

    void Init(std::shared_ptr<EntityType> InOwner);
    
    void SetGlobalState(std::shared_ptr<IState<EntityType>> InState);
    void ChangeState(std::shared_ptr<IState<EntityType>> InState);
    void ExitCurrentState();
    void SetCurrentState(std::shared_ptr<IState<EntityType>> InState);
    void Update();
    void RevertToPreviousState();
    
private:
    std::shared_ptr<IState<EntityType>> m_GlobalState;
    std::shared_ptr<IState<EntityType>> m_CurrentState;
    std::shared_ptr<IState<EntityType>> m_PrevState;

    std::shared_ptr<EntityType> m_Owner;
};

#include "StateMachine.hpp"
