#pragma once
#include "../Entity/Miner.h"
#include "../State/State.h"

class GoHomeAndSleepTilRested : public IState<Miner>
{
public:
    static std::shared_ptr<IState<Miner>> Instance();
    
    virtual void EnterState(std::shared_ptr<Miner> InEntity) override;
    virtual void Execute(std::shared_ptr<Miner> InEntity) override;
    virtual void ExitState(std::shared_ptr<Miner> InEntity) override;
};

#define g_GoHomeAndSleepTilRested GoHomeAndSleepTilRested::Instance()
