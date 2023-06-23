#include "Papyrus.h"
#include <functional>
#include <algorithm>

using namespace RE;
using namespace RE::BSScript;
using namespace REL;
using namespace SKSE;
namespace {
    constexpr std::string_view PapyrusClass = "slaInternalModules";

}

bool SLA::RegisterFunctions(IVirtualMachine* vm) {
	return true;
}