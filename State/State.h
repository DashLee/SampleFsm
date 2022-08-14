#pragma once
#include <memory>

template<typename EntityType>
class IState
{
public:
    virtual ~IState() = default;

    virtual void EnterState(std::shared_ptr<EntityType> InEntity) = 0;
    virtual void Execute(std::shared_ptr<EntityType> InEntity) = 0;
    virtual void ExitState(std::shared_ptr<EntityType> InEntity) = 0;
};
