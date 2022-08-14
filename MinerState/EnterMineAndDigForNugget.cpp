#include "EnterMineAndDigForNugget.h"

#include <iostream>

std::shared_ptr<IState<Miner>> EnterMineAndDigForNugget::Instance()
{
    static std::shared_ptr<IState<Miner>> s_Instance = std::make_shared<EnterMineAndDigForNugget>();
    return s_Instance;
}

void EnterMineAndDigForNugget::EnterState(std::shared_ptr<Miner> InEntity)
{
    if(nullptr == InEntity)
        return;

    const ELocationType LocalDestination = ELocationType::Goldmine;
    if(false == InEntity->IsEqualLocation(LocalDestination))
    {
        std::cout << InEntity->GetEntityName() << "는 광산으로 향했다." << std::endl;
        InEntity->SetLocation(LocalDestination);
    }
}

void EnterMineAndDigForNugget::Execute(std::shared_ptr<Miner> InEntity)
{
    GetGold(InEntity);
    InEntity->AddFatigue(1);
    InEntity->EndTurn();
}

void EnterMineAndDigForNugget::ExitState(std::shared_ptr<Miner> InEntity)
{
    std::cout << InEntity->GetEntityName() << "는 광산을 떠났다." << std::endl;
}

void EnterMineAndDigForNugget::GetGold(std::shared_ptr<Miner> InEntity)
{
    const int LocalGetGold = 1;
    InEntity->AddGoldCarried(LocalGetGold);
    std::cout << InEntity->GetEntityName() << "는 금광을" << LocalGetGold << "만큼 캤다." << std::endl;
}
