#include "Papyrus.h"
#include "ArousalManager.h"

using namespace RE;
using namespace RE::BSScript;
using namespace REL;
using namespace SKSE;
using namespace SLA;

namespace {
    constexpr std::string_view PapyrusClass = "slaInternalModules";
    uint32_t GetStaticEffectCount(StaticFunctionTag* base) { 
        return ArousalManager::GetSingleton().GetStaticEffectCount(); 
    }
    uint32_t RegisterStaticEffect(StaticFunctionTag* base, std::string name) {
        return ArousalManager::GetSingleton().RegisterStaticEffect(name);
    }
    bool UnregisterStaticEffect(StaticFunctionTag* base, std::string name) {
        return ArousalManager::GetSingleton().UnregisterStaticEffect(name);
    }
    bool IsStaticEffectActive(StaticFunctionTag* base, Actor* who, int32_t effectIdx) {
        return ArousalManager::GetSingleton().IsStaticEffectActive(who, effectIdx);
    }
    int32_t GetDynamicEffectCount(StaticFunctionTag* base, Actor* who) {
        return ArousalManager::GetSingleton().GetDynamicEffectCount(who);
    }
    std::string GetDynamicEffect(StaticFunctionTag* base, Actor* who, int32_t number) {
        return ArousalManager::GetSingleton().GetDynamicEffect(who, number);     
    }
    float GetDynamicEffectValueByName(StaticFunctionTag* base, Actor* who, std::string effectId) {
        return ArousalManager::GetSingleton().GetDynamicEffectValueByName(who, effectId);
    }
    float GetDynamicEffectValue(StaticFunctionTag* base, Actor* who, int32_t number) {
        return ArousalManager::GetSingleton().GetDynamicEffectValue(who, number);
    }
    float GetStaticEffectValue(StaticFunctionTag* base, Actor* who, int32_t effectIdx) {
        return ArousalManager::GetSingleton().GetStaticEffectValue(who, effectIdx);     
    }
    float GetStaticEffectParam(StaticFunctionTag* base, Actor* who, int32_t effectIdx) {
        return ArousalManager::GetSingleton().GetStaticEffectParam(who, effectIdx);
    }
    int32_t GetStaticEffectAux(StaticFunctionTag* base, Actor* who, int32_t effectIdx) {
        return ArousalManager::GetSingleton().GetStaticEffectAux(who, effectIdx);
    }
}

bool SLA::RegisterFunctions(IVirtualMachine* vm) {
    vm->RegisterFunction("GetStaticEffectCount", PapyrusClass, GetStaticEffectCount);

	return true;
}