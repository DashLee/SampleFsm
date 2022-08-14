#pragma once

#include "../State/State.h"

template <typename EntityType>
StateMachine<EntityType>::StateMachine()
    : m_GlobalState(nullptr) 
    , m_CurrentState(nullptr)
    , m_PrevState(nullptr)
    , m_Owner(nullptr)
{
}

template <typename EntityType>
void StateMachine<EntityType>::Init(std::shared_ptr<EntityType> InOwner)
{
    m_Owner = InOwner;
}

template <typename EntityType>
void StateMachine<EntityType>::SetGlobalState(std::shared_ptr<IState<EntityType>> InState)
{
    m_GlobalState = InState;
}

template <typename EntityType>
void StateMachine<EntityType>::ChangeState(std::shared_ptr<IState<EntityType>> InState)
{
    ExitCurrentState();
    SetCurrentState(InState);
}

template <typename EntityType>
void StateMachine<EntityType>::ExitCurrentState()
{
    if(nullptr == m_CurrentState)
        return;
    
    m_PrevState = m_CurrentState;
    m_CurrentState->ExitState(m_Owner);
}

template <typename EntityType>
void StateMachine<EntityType>::SetCurrentState(std::shared_ptr<IState<EntityType>> InState)
{
    m_CurrentState = InState;
    m_CurrentState->EnterState(m_Owner);
}

template <typename EntityType>
void StateMachine<EntityType>::Update()
{
    if(m_GlobalState)
        m_GlobalState->Execute(m_Owner);
    
    if(m_CurrentState)
        m_CurrentState->Execute(m_Owner);
}

template <typename EntityType>
void StateMachine<EntityType>::RevertToPreviousState()
{
    m_CurrentState->ExitState(m_Owner);
    SetCurrentState(m_PrevState);
}
