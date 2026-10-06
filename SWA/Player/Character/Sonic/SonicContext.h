#pragma once

#include "SWA.inl"

namespace SWA::Player
{
    class CSonicContext // : public CPlayerContext
    {
    public:
        static CSonicContext* GetInstance()
        {
            return *(xpointer<CSonicContext>*)MmGetHostAddress(0x83362F98);
        }
    };
}
