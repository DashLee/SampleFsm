#include "VisitBankAndDepositGoid.h"

#include <iostream>

std::shared_ptr<IState<Miner>> VisitBankAndDepositGoid::Instance()
{
    static auto s_Instance = std::make_shared<VisitBankAndDepositGoid>();
    return s_Instance;
}

void VisitBankAndDepositGoid::EnterState(std::shared_ptr<Miner> InEntity)
{
    std::cout << InEntity->GetEntityName() << "는 가방이 금으로 가득 찼다." << std::endl;

    const ELocationType LocalDestination = ELocationType::Bank;
    if(false == InEntity->IsEqualLocation(LocalDestination))
    {
        InEntity->SetLocation(LocalDestination);
        std::cout << InEntity->GetEntityName() << "는 은행으로 갔다." << std::endl;
    }
}

void VisitBankAndDepositGoid::Execute(std::shared_ptr<Miner> InEntity)
{
    const int LocalGoldCarried = InEntity->GetGoldCarried();
    InEntity->SetGoldCarried(0);
    std::cout << InEntity->GetEntityName() << "는 은행에 금" << LocalGoldCarried << "을 맡겼다." << std::endl;

    const int LocalGoldToMoney = LocalGoldCarried * 2;
    InEntity->AddMoneyInBank(LocalGoldToMoney);
    std::cout << InEntity->GetEntityName() << "의 계좌에는" << LocalGoldToMoney << "원이 저축됐다." << std::endl;

    InEntity->EndTurn();
}

void VisitBankAndDepositGoid::ExitState(std::shared_ptr<Miner> InEntity)
{
    std::cout << InEntity->GetEntityName() << "는 은행을 나섰다.." << std::endl;
}
