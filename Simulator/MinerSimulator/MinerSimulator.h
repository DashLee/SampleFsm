#pragma once

#include <memory>

#include "../Simulator.h"

class BaseGameEntity;

class MinerSimulator : public ISimulator
{
public:
    MinerSimulator();
    
protected:
    virtual void Init() override;
    virtual void Update() override;
    virtual void Release() override;
    virtual bool IsRunning() override;
    virtual void PrevUpdateEvent() override;
    virtual void PostUpdateEvent() override;
    virtual void FinishUpdateEvent() override;

private:
    std::shared_ptr<BaseGameEntity> m_Miner;
};
