#include "MinerGlobalState.h"

std::shared_ptr<IState<Miner>> MinerGlobalState::Instance()
{
    static std::shared_ptr<IState<Miner>> s_Instance = std::make_shared<MinerGlobalState>();
    return s_Instance;
}

void MinerGlobalState::EnterState(std::shared_ptr<Miner> InEntity)
{
}

void MinerGlobalState::Execute(std::shared_ptr<Miner> InEntity)
{
}

void MinerGlobalState::ExitState(std::shared_ptr<Miner> InEntity)
{
}
