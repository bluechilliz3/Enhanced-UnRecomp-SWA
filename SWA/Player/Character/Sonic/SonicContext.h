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
        
        // Message actor ID of the object holding the player under external
        // control (bobsleigh, cannon, pole...), or 0 when nothing is.
        SWA_INSERT_PADDING(0x6CC);
        be<uint32_t> m_ExternalControlActorID;
    };
    
    SWA_ASSERT_OFFSETOF(CSonicContext, m_ExternalControlActorID, 0x6CC);
}
