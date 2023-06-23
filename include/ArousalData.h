#pragma once

namespace SLA {
    struct ArousalEffectGroup {
        ArousalEffectGroup() : value(0.f) {}
        std::vector<uint32_t> staticEffectIds;
        float value;
    };

    using ArousalEffectGroupPtr = std::shared_ptr<ArousalEffectGroup>;
   
    static float GetEffectLimitOffset(uint32_t effectIdx) {
        if (effectIdx == 1) return 0.5;
        return 0.0;
    }

    struct ArousalEffectData {
        ArousalEffectData() : value(0.f), function(0), param(0.f), limit(0.f), intAux(0) {}

        float value;
        int32_t function;
        float param;
        float limit;
        union {
            float floatAux;
            int32_t intAux;
        };

        void Set(int32_t functionId, float param, float limit, int32_t auxilliary) {
            this->function = functionId;
            this->param = param;

            this->limit = limit + GetEffectLimitOffset(functionId);
            this->intAux = auxilliary;
        }
    };

    class ArousalData {
    public:
        void OnRegisterStaticEffect();
        void OnUnregisterStaticEffect(uint32_t id);
        bool IsStaticEffectActive(int32_t effectIdx);
        int32_t GetDynamicEffectCount();
        std::string GetDynamicEffect(int32_t number);
        float GetDynamicEffectValue(int32_t number);
        float GetDynamicEffectValueByName(std::string number);
        ArousalEffectGroupPtr GetEffectGroup(int32_t effectIdx);
        ArousalEffectData& GetStaticArousalEffect(int32_t effectIdx);
    };
}
