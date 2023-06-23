#include "ArousalData.h"

namespace SLA {
    void ArousalData::OnRegisterStaticEffect() {}
    void ArousalData::OnUnregisterStaticEffect(uint32_t id) {}
    bool ArousalData::IsStaticEffectActive(int32_t effectIdx) { return false; }
    int32_t ArousalData::GetDynamicEffectCount() { return 0; }
    std::string ArousalData::GetDynamicEffect(int32_t number) { return ""; }
    float ArousalData::GetDynamicEffectValue(int32_t number) { return 0.0f; }
    float ArousalData::GetDynamicEffectValueByName(std::string number) { return 0.0f; }
    ArousalEffectGroupPtr ArousalData::GetEffectGroup(int32_t effectIdx) { return nullptr; }
    ArousalEffectData& ArousalData::GetStaticArousalEffect(int32_t effectIdx) { 
        ArousalEffectData data;
        return data; 
    }
    void ArousalData::SetStaticArousalEffect(int32_t effectIdx, int32_t functionId, float param, float limit,
                                             int32_t auxilliary) {}
    void ArousalData::SetDynamicArousalEffect(std::string effectId, float initialValue, int32_t functionId, float param,
                                 float limit) {}
    void ArousalData::ModDynamicArousalEffect(std::string effectId, float modifier, float limit) {}
    void ArousalData::SetStaticArousalValue(int32_t effectIdx, float value) {}
    float ArousalData::ModStaticArousalValue(int32_t effectIdx, float diff, float limit) { return 0.0f; }

    float ArousalData::GetArousal() { return 0.0f; }
    void ArousalData::UpdateSingleActorArousal(RE::Actor* who, float GameDaysPassed) {}
    bool ArousalData::GroupEffects(RE::Actor* who, int32_t idx, int32_t idx2) { return false; }
    bool ArousalData::RemoveEffectGroup(int32_t idx) { return false; }
    float ArousalData::GetLastUpdate() { return 0.0f; }
}