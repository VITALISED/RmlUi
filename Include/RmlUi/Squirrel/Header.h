#ifndef RMLUI_SQ_HEADER_H
#define RMLUI_SQ_HEADER_H

#include <RmlUi/Core/Platform.h>

#ifdef RMLUISQ_API
	#undef RMLUISQ_API
#endif

#if !defined RMLUI_STATIC_LIB
	#ifdef RMLUI_PLATFORM_WIN32
		#if defined RMLUI_SQ_EXPORTS
			#define RMLUISQ_API __declspec(dllexport)
		#else
			#define RMLUISQ_API __declspec(dllimport)
		#endif
	#else
		#define RMLUISQ_API __attribute__((visibility("default")))
	#endif
#else
	#define RMLUISQ_API
#endif

#endif
