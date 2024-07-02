add_library(rmlui_squirrel
	# Colourb.cpp
	# Colourb.h
	# Colourf.cpp
	# Colourf.h
	# Context.cpp
	# Context.h
	# ContextDocumentsProxy.cpp
	# ContextDocumentsProxy.h
	# Document.cpp
	# Document.h
	# Element.cpp
	# Element.h
	# ElementAttributesProxy.cpp
	# ElementAttributesProxy.h
	# ElementChildNodesProxy.cpp
	# ElementChildNodesProxy.h
	# ElementInstancer.cpp
	# ElementInstancer.h
	# ElementStyleProxy.cpp
	# ElementStyleProxy.h
	# ElementText.cpp
	# ElementText.h
	# Event.cpp
	# Event.h
	# EventParametersProxy.cpp
	# EventParametersProxy.h
	# GlobalSquirrelFunctions.cpp
	# GlobalSquirrelFunctions.h
	# Interpreter.cpp
	# Log.cpp
	# Log.h
	Squirrel.cpp
	# SquirrelDataModel.cpp
	# SquirrelDataModel.h
	# SquirrelDocument.cpp
	# SquirrelDocument.h
	# SquirrelDocumentElementInstancer.cpp
	# SquirrelDocumentElementInstancer.h
	# SquirrelElementInstancer.cpp
	# SquirrelElementInstancer.h
	# SquirrelEventListener.cpp
	# SquirrelEventListener.h
	# SquirrelEventListenerInstancer.cpp
	# SquirrelEventListenerInstancer.h
	SquirrelPlugin.cpp
	SquirrelPlugin.h
	# SquirrelType.cpp
	# Pairs.h
	# RmlUi.cpp
	# RmlUi.h
	# RmlUiContextsProxy.cpp
	# RmlUiContextsProxy.h
	# Utilities.cpp
	# Vector2f.cpp
	# Vector2f.h
	# Vector2i.cpp
	# Vector2i.h
)

target_sources(rmlui_squirrel PRIVATE
	"${PROJECT_SOURCE_DIR}/Include/RmlUi/Squirrel/Header.h"
	"${PROJECT_SOURCE_DIR}/Include/RmlUi/Squirrel/IncludeSquirrel.h"
	"${PROJECT_SOURCE_DIR}/Include/RmlUi/Squirrel/SqType.h"
	"${PROJECT_SOURCE_DIR}/Include/RmlUi/Squirrel.h"
)

set_common_target_options(rmlui_squirrel)

target_include_directories(rmlui_squirrel PRIVATE "${PROJECT_SOURCE_DIR}/Include")
target_include_directories(rmlui_squirrel INTERFACE
	"$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/Include>"
	"$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>"
)

add_library(RmlUi::Squirrel ALIAS rmlui_squirrel)

target_link_libraries(rmlui_squirrel PUBLIC rmlui_core)

# Use public linking, as some of our public headers require Lua. However, in principle the Lua bindings can be used
# without the Lua header files, in particular `RmlUi/Lua/Lua.h` does not require Lua.
target_link_libraries(rmlui_squirrel PUBLIC RmlUi::External::Squirrel)

# Set additional target properties
set_target_properties(rmlui_squirrel PROPERTIES
	# Add export name so that it can be exported with a namespaced name instead
	# of using the name we actually used to declare the target
	EXPORT_NAME "Squirrel"
)

get_target_property(rmlui_squirrel_TYPE rmlui_squirrel "TYPE")
if(rmlui_squirrel_TYPE STREQUAL "SHARED_LIBRARY")
	# If RmlUi lua is being compiled as a shared library, notify code to export functions using __dllspec()
	# For applications consuming the library, the headers will automatically use dllimport
	# Platform and compiler handling is already done by code via pre-processor macros
	target_compile_definitions(rmlui_squirrel PRIVATE "RMLUI_SQ_EXPORTS")
endif()

# add_subdirectory("Elements")

install(TARGETS rmlui_squirrel
	EXPORT RmlUiTargets
	${RMLUI_RUNTIME_DEPENDENCY_SET_ARG}
	RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
	LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
	ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
install_target_pdb(rmlui_squirrel)
