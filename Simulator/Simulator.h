#pragma once

class ISimulator
{
public:
    virtual ~ISimulator() = default;
    
    virtual void Init() = 0;
    virtual void Update() = 0;
    virtual void Release() = 0;
    virtual bool IsRunning() = 0;
    virtual void PrevUpdateEvent() = 0;
    virtual void PostUpdateEvent() = 0;
    virtual void FinishUpdateEvent() = 0;
};
