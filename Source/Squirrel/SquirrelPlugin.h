#ifndef RMLUI_SQ_SQPLUGIN_H
#define RMLUI_SQ_SQPLUGIN_H

#include <RmlUi/Core/Plugin.h>
#include <RmlUi/Squirrel/Header.h>

typedef struct SQVM SQVM;
typedef struct SQVM* HSQUIRRELVM;

namespace Rml {
namespace Squirrel {

class SqDocumentElementInstancer;
class SqEventListenerInstancer;

class RMLUISQ_API SquirrelPlugin : public Plugin {
public:
	SquirrelPlugin(HSQUIRRELVM sqvm);

	static HSQUIRRELVM GetSQVM();

private:
	int GetEventClasses() override;

	void OnInitialise() override;

	void OnShutdown() override;

	SqDocumentElementInstancer* sq_document_element_instancer = nullptr;
	SqEventListenerInstancer* sq_event_listener_instancer = nullptr;
	bool owns_sqvm = false;
};

} // namespace Squirrel
} // namespace Rml
#endif
