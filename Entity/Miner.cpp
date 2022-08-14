#include "Miner.h"

#include "../MinerState/EnterMineAndDigForNugget.h"
#include "../MinerState/GoHomeAndSleepTilRested.h"
#include "../MinerState/MinerGlobalState.h"
#include "../MinerState/QuenchThirst.h"
#include "../MinerState/VisitBankAndDepositGoid.h"
#include "C:\Users\leesa\source\repos\WestWorld1\MineWestWorld\StateMachine\StateMachine.h"

Miner::Miner(EntityID InEntityID)
    : BaseGameEntity(InEntityID)
    , m_StateMachine(nullptr)
    , m_Location(ELocationType::Shack)
    , m_GoldCarried(0)
    , m_MoneyInBank(0)
    , m_Thirst(0)
    , m_Fatigue(0)
    , m_MaxGoldCarried(12)
    , m_MaxThirst(5)
    , m_MaxFatigue(20)
{
}

Miner::~Miner()
{
    m_StateMachine.reset();
}

void Miner::Init()
{
    m_StateMachine = std::make_shared<StateMachine<Miner>>();
    m_StateMachine->Init(shared_from_this());

    m_StateMachine->SetGlobalState(g_MinerGlobalState);
    m_StateMachine->SetCurrentState(g_GoHomeAndSleepTilRested);
}

void Miner::EndTurn()
{
    // 술이 마렵다
    if(IsOverMaxThirst())
        m_StateMachine->ChangeState(g_QuenchThirst);
    // 피곤하다
    else if(IsOverMaxFatigue())
        m_StateMachine->ChangeState(g_GoHomeAndSleepTilRested);
    // 골드가 가득찼다.
    else if(IsOverMaxGoldCarried())
        m_StateMachine->ChangeState(g_VisitBankAndDepositGoid);
    // 부지런하게 광산으로 가서 금광을 캔다. 
    else
        m_StateMachine->ChangeState(g_EnterMineAndDigForNugget);
}

bool Miner::IsEqualLocation(const ELocationType InLocation) const
{
    return GetLocation() == InLocation;
}

bool Miner::IsOverMaxGoldCarried() const
{
    return GetGoldCarried() >= m_MaxGoldCarried;
}

bool Miner::IsOverMaxThirst() const
{
    return GetThirst() >= m_MaxThirst;
}

bool Miner::IsOverMaxFatigue() const
{
    return GetFatigue() >= m_MaxFatigue;
}

ELocationType Miner::GetLocation() const
{
    return m_Location;
}

int Miner::GetGoldCarried() const
{
    return m_GoldCarried;
}

int Miner::GetMoneyInBank() const
{
    return m_MoneyInBank;
}

int Miner::GetThirst() const
{
    return m_Thirst;
}

int Miner::GetFatigue() const
{
    return m_Fatigue;
}

void Miner::SetLocation(const ELocationType InDestinationLocation)
{
    m_Location = InDestinationLocation;
}

void Miner::AddGoldCarried(const int InAddGold)
{
    SetGoldCarried(GetGoldCarried() + InAddGold);
}

void Miner::AddMoneyInBank(const int InAddMoney)
{
    SetMoneyInBank(GetMoneyInBank() + InAddMoney);
}

void Miner::AddThirst(const int InAddThirst)
{
    SetThirst(GetThirst() + InAddThirst);
}

void Miner::AddFatigue(const int InAddFatigue)
{
    SetFatigue(GetFatigue() + InAddFatigue);
}

void Miner::SetGoldCarried(const int InGold)
{
    m_GoldCarried = InGold;
}

void Miner::SetMoneyInBank(const int InMoney)
{
    m_MoneyInBank = InMoney;
}

void Miner::SetThirst(const int InThirst)
{
    m_Thirst = InThirst;
}

void Miner::SetFatigue(const int InFatigue)
{
    m_Fatigue = InFatigue;
}

void Miner::Update()
{
    UpdateThirst();
    UpdateStateMachine();
}

void Miner::UpdateThirst()
{
    ++m_Thirst;
}

void Miner::UpdateStateMachine()
{
    if(nullptr != m_StateMachine)
        m_StateMachine->Update();
}
