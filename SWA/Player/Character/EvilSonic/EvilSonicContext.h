#pragma once

#include "SWA.inl"
#include "SWA/Player/Character/EvilSonic/Hud/EvilHudGuide.h"

namespace SWA::Player
{
    class CEvilSonicContext // : public CPlayerContext
    {
    public:
        // Unlike the day context (CSonicContext::GetInstance), the werehog's isn't
        // published to a game global. Null whenever the werehog is not loaded.
        static inline std::atomic<uint32_t> s_instance;

        static CEvilSonicContext* GetInstance()
        {
            const uint32_t instance = s_instance.load(std::memory_order_relaxed);
            return instance != 0 ? (CEvilSonicContext*)MmGetHostAddress(instance) : nullptr;
        }

        SWA_INSERT_PADDING(0x688);
        be<float> m_DarkGaiaEnergy;
        SWA_INSERT_PADDING(0x138);
        be<uint32_t> m_AnimationID;
        SWA_INSERT_PADDING(0x38);
        be<float> m_UnkHudGuideF32;
        be<uint32_t> m_UnkHudGuideU32;
        SWA_INSERT_PADDING(0x18);
        be<EGuideType> m_GuideType;
        SWA_INSERT_PADDING(0xA8);
        be<uint32_t> m_OutOfControlCount;
    };
}
