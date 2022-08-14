#include "BaseGameEntity.h"

BaseGameEntity::BaseGameEntity(EntityID InEntityID)
    : m_EntityID(InEntityID)
{
}

EntityID BaseGameEntity::GetEntityID()
{
    return m_EntityID;
}

std::string BaseGameEntity::GetEntityName()
{
    return GlobalDefine::s_MinerName[GetEntityID()];
}
