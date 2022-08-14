#include "MinerSimulator.h"

#include <windows.h>
#include "../../Entity/Miner.h"
#include "../../Entity/BaseGameEntity.h"

MinerSimulator::MinerSimulator()
    : m_Miner(nullptr)
{
}

void MinerSimulator::Init()
{
    auto LocalNewMiner = std::make_shared<Miner>(static_cast<EntityID>(EMinerID::Bob));
    LocalNewMiner->Init();
    
    m_Miner = LocalNewMiner; 
}

void MinerSimulator::Update()
{
    m_Miner->Update();
}

void MinerSimulator::Release()
{
    m_Miner.reset();
}

bool MinerSimulator::IsRunning()
{
    return true;
}

void MinerSimulator::PrevUpdateEvent()
{
}

void MinerSimulator::PostUpdateEvent()
{
}

void MinerSimulator::FinishUpdateEvent()
{
    Sleep(1200);
}
