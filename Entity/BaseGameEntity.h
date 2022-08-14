#pragma once

#include <string>

#include "C:\Users\leesa\source\repos\WestWorld1\MineWestWorld\Define\GlobalDefine.h"

class BaseGameEntity
{
public:
    virtual ~BaseGameEntity() = default;
    BaseGameEntity(EntityID InEntityID);

    virtual void Update() = 0;

    EntityID GetEntityID();

    std::string GetEntityName();
    
private:
    EntityID m_EntityID;
};
