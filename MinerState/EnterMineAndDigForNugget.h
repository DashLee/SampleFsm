#pragma once
#include "../Entity/Miner.h"
#include "../State/State.h"

class EnterMineAndDigForNugget : public IState<Miner>
{
public:
    static std::shared_ptr<IState<Miner>> Instance();
    
    virtual void EnterState(std::shared_ptr<Miner> InEntity) override;
    virtual void Execute(std::shared_ptr<Miner> InEntity) override;
    virtual void ExitState(std::shared_ptr<Miner> InEntity) override;

private:
    void GetGold(std::shared_ptr<Miner> InEntity);
};

#define g_EnterMineAndDigForNugget EnterMineAndDigForNugget::Instance()
