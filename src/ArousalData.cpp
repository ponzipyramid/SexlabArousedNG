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
}