#pragma once

#include <memory>

#include "BaseGameEntity.h"
#include "C:\Users\leesa\source\repos\WestWorld1\MineWestWorld\Define\GlobalDefine.h"

template <typename EntityType>
class StateMachine;

class Miner : public BaseGameEntity, public std::enable_shared_from_this<Miner>
{
public:
    Miner(EntityID InEntityID);
    virtual ~Miner() override;
    
    void Init();

    void EndTurn();

    bool IsEqualLocation(const ELocationType InLocation) const;
    bool IsOverMaxGoldCarried() const;
    bool IsOverMaxThirst() const;
    bool IsOverMaxFatigue() const;
    
    ELocationType GetLocation() const;
    int GetGoldCarried() const;
    int GetMoneyInBank() const;
    int GetThirst() const;
    int GetFatigue() const;
    
    void SetLocation(const ELocationType InDestinationLocation);
    void AddGoldCarried(const int InAddGold);
    void AddMoneyInBank(const int InAddMoney);
    void AddThirst(const int InAddThirst);
    void AddFatigue(const int InAddFatigue);

    void SetGoldCarried(const int InGold);
    void SetMoneyInBank(const int InMoney);
    void SetThirst(const int InThirst);
    void SetFatigue(const int InFatigue);
    
protected:
    virtual void Update() override;

private:
    void UpdateThirst();
    void UpdateStateMachine();
    
private:
    std::shared_ptr<StateMachine<Miner>> m_StateMachine;

    ELocationType m_Location;
    int m_GoldCarried;
    int m_MoneyInBank;
    int m_Thirst;
    int m_Fatigue;

    int m_MaxGoldCarried;
    int m_MaxThirst;
    int m_MaxFatigue;
};
