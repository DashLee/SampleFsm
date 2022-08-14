#include "QuenchThirst.h"

#include <iostream>

std::shared_ptr<IState<Miner>> QuenchThirst::Instance()
{
    static auto s_Instance = std::make_shared<QuenchThirst>();
    return s_Instance;
}

void QuenchThirst::EnterState(std::shared_ptr<Miner> InEntity)
{
    std::cout << InEntity->GetEntityName() << "는 위스키 한 잔이 간절하다.." << std::endl;

    const ELocationType LocalDestination = ELocationType::Saloon;
    if(false == InEntity->IsEqualLocation(LocalDestination))
    {
        InEntity->SetLocation(LocalDestination);
        std::cout << InEntity->GetEntityName() << "는 술집으로 갔다." << std::endl;
    }
}

void QuenchThirst::Execute(std::shared_ptr<Miner> InEntity)
{
    std::cout << "적셔!" << std::endl;
    std::cout << InEntity->GetEntityName() << "는 위스키 한 잔을 비웠다." << std::endl;

    InEntity->AddThirst(-2);
    InEntity->EndTurn();
}

void QuenchThirst::ExitState(std::shared_ptr<Miner> InEntity)
{
    std::cout << InEntity->GetEntityName() << "는 얼큰하게 취기가 올라왔고 술집을 나섰다.." << std::endl;    
}
