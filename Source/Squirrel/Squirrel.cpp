#include "SquirrelPlugin.h"
#include <RmlUi/Core/Core.h>
#include <RmlUi/Squirrel/Squirrel.h>

namespace Rml {
namespace Squirrel {

void Initialise()
{
	::Rml::Squirrel::Initialise(nullptr);
}

void Initialise(HSQUIRRELVM lua_state)
{
	::Rml::RegisterPlugin(new SquirrelPlugin(lua_state));
}

} // namespace Lua
} // namespace Rml
