#include "GoHomeAndSleepTilRested.h"

#include <iostream>

std::shared_ptr<IState<Miner>> GoHomeAndSleepTilRested::Instance()
{
    static std::shared_ptr<IState<Miner>> s_Instance = std::make_shared<GoHomeAndSleepTilRested>();
    return s_Instance;
}

void GoHomeAndSleepTilRested::EnterState(std::shared_ptr<Miner> InEntity)
{
    std::cout << InEntity->GetEntityName() << "는 너무나도 피곤하다." << std::endl;

    const ELocationType LocalDestination = ELocationType::Shack;
    if(false == InEntity->IsEqualLocation(LocalDestination))
    {
        InEntity->SetLocation(LocalDestination);
        std::cout << InEntity->GetEntityName() << "는 집으로 왔다." << std::endl;
    }
}

void GoHomeAndSleepTilRested::Execute(std::shared_ptr<Miner> InEntity)
{
    InEntity->SetFatigue(0);
    std::cout << InEntity->GetEntityName() << "는 집에서 푹 쉬었다." << std::endl;
    InEntity->EndTurn();
}

void GoHomeAndSleepTilRested::ExitState(std::shared_ptr<Miner> InEntity)
{
    std::cout << InEntity->GetEntityName() << "는 집을 떠났다." << std::endl;    
}
