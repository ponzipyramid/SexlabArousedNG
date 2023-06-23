#include "ArousalManager.h"

namespace SLA {
    ArousalManager& ArousalManager::GetSingleton() noexcept {
        static ArousalManager instance;
        return instance;
    }

    uint32_t ArousalManager::RegisterStaticEffect(std::string name) {
        auto itr = staticEffectIds.find(name);
        if (itr != staticEffectIds.end()) return itr->second;

        int32_t unusedId = GetHighestUnusedEffectId();
        if (unusedId != -1) {
            auto itr = staticEffectIds.find(GetUnusedEffectId(unusedId));
            assert(itr != staticEffectIds.end());
            int32_t effectId = itr->second;
            staticEffectIds.erase(itr);
            staticEffectIds[name] = effectId;
            return effectId;
        }

        staticEffectIds[name] = staticEffectCount;
        for (auto& data : arousalData) data.second.OnRegisterStaticEffect();
        const auto result = staticEffectCount;
        staticEffectCount++;
        return result;
    }

    std::string ArousalManager::GetUnusedEffectId(int32_t id) { return "Unused" + std::to_string(id); }

    int32_t ArousalManager::GetHighestUnusedEffectId() {
        int32_t result = -1;
        while (staticEffectIds.find(GetUnusedEffectId(result + 1)) != staticEffectIds.end()) result += 1;
        return result;
    }

    bool ArousalManager::UnregisterStaticEffect(std::string name) {
        auto itr = staticEffectIds.find(name);
        if (itr != staticEffectIds.end()) {
            uint32_t id = itr->second;
            staticEffectIds.erase(itr);
            int32_t unusedId = GetHighestUnusedEffectId();
            staticEffectIds[GetUnusedEffectId(unusedId + 1)] = id;
            for (auto& data : arousalData) data.second.OnUnregisterStaticEffect(id);
            return true;
        }
        return false;
    }

    ArousalData& ArousalManager::GetArousalData(RE::Actor* who) {
        if (!who) throw std::invalid_argument("Attempt to get arousal data for none actor");
        RE::FormID formId = who->formID;
        if (lastLookup == formId && lastData) return *lastData;
        auto& result = arousalData[formId];
        lastLookup = formId;
        lastData = &result;
        return result;
    }

    bool ArousalManager::IsStaticEffectActive(RE::Actor* who, int32_t effectIdx) {
        try {
            ArousalData& data = GetArousalData(who);
            return data.IsStaticEffectActive(effectIdx);
        } catch (std::exception) {
            return false;
        }
    }

    int32_t ArousalManager::GetDynamicEffectCount(RE::Actor* who) {
        try {
            ArousalData& data = GetArousalData(who);
            return data.GetDynamicEffectCount();
        } catch (std::exception) {
            return 0;
        }
    }

    std::string ArousalManager::GetDynamicEffect(RE::Actor* who, int32_t number) {
        try {
            ArousalData& data = GetArousalData(who);
            return data.GetDynamicEffect(number);
        } catch (std::exception) {
            return "";
        }
    }

    float ArousalManager::GetDynamicEffectValueByName(RE::Actor* who, std::string effectId) {
        try {
            ArousalData& data = GetArousalData(who);
            return data.GetDynamicEffectValueByName(effectId);
        } catch (std::exception) {
            return 0.0;
        }
    }

    float ArousalManager::GetDynamicEffectValue(RE::Actor* who, int32_t number) {
        try {
            ArousalData& data = GetArousalData(who);
            return data.GetDynamicEffectValue(number);
        } catch (std::exception) {
            return std::numeric_limits<float>::lowest();
        }
    }

    float ArousalManager::GetStaticEffectValue(RE::Actor* who, int32_t effectIdx) {
        try {
            ArousalData& data = GetArousalData(who);
            if (auto group = data.GetEffectGroup(effectIdx)) 
                return group->value;
            ArousalEffectData& effect = data.GetStaticArousalEffect(effectIdx);
            return effect.value;
        } catch (std::exception) {
            return 0.f;
        }
    }
}
