#pragma once

#include "ArousalData.h"

namespace SLA {
#pragma warning(push)
#pragma warning(disable : 4251)

    class __declspec(dllexport) ArousalManager {
    public:
        [[nodiscard]] static ArousalManager& GetSingleton() noexcept;
        [[nodiscard]] inline int GetStaticEffectCount() { return staticEffectCount; }
        uint32_t RegisterStaticEffect(std::string name);
        bool UnregisterStaticEffect(std::string name);
        bool IsStaticEffectActive(RE::Actor* who, int32_t effectIdx);
        int32_t GetDynamicEffectCount(RE::Actor* who);
        std::string GetDynamicEffect(RE::Actor* who, int32_t number);
        float GetDynamicEffectValueByName(RE::Actor* who, std::string effectId);
        float GetDynamicEffectValue(RE::Actor* who, int32_t number);
        float GetStaticEffectValue(RE::Actor* who, int32_t number);
        float GetStaticEffectParam(RE::Actor* who, int32_t effectIdx);
        int32_t GetStaticEffectAux(RE::Actor* who, int32_t effectIdx);

    private:
        int32_t GetHighestUnusedEffectId();
        std::string GetUnusedEffectId(int32_t id);
        ArousalEffectData& GetStaticArousalEffect(RE::Actor* who, int32_t effectIdx);
        ArousalData& GetArousalData(RE::Actor* who);

        ArousalManager() = default;
        mutable std::mutex _lock;
        std::unordered_map<std::string, uint32_t> staticEffectIds;
        std::unordered_map<uint32_t, ArousalData> arousalData;

        uint32_t lastLookup;
        ArousalData* lastData = nullptr;

        int staticEffectCount;
    };

#pragma warning(pop)
}

