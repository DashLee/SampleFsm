#pragma once

#include <string>

using EntityID = int;

enum class EMinerID
{
    None = -1,
    Bob,
    Elsa,
    Max
};

enum class ELocationType
{
    None = -1,
    Shack,
    Goldmine,
    Bank,
    Saloon,
    Max
};

class GlobalDefine
{
public:
    static std::string s_MinerName[static_cast<int>(EMinerID::Max)];
};
