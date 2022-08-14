#include "Simulator/Simulator.h"
#include "Simulator/MinerSimulator/MinerSimulator.h"

int main()
{
    std::shared_ptr<ISimulator> LocalSimulator = std::make_shared<MinerSimulator>();
    if(nullptr == LocalSimulator)
        return 0;

    LocalSimulator->Init();
    
    while(LocalSimulator->IsRunning())
    {
        LocalSimulator->PrevUpdateEvent();
        LocalSimulator->Update();
        LocalSimulator->PostUpdateEvent();
        LocalSimulator->FinishUpdateEvent();
    }

    LocalSimulator->Release();
    LocalSimulator.reset();
}
