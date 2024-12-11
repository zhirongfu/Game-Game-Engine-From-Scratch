#pragma once

#ifdef JELLY_MS_COMPILER
	#ifdef JELLY_LIB
		#define JELLY_API __declspec(dllexport)
	#else
		#define JELLY_API __declspec(dllimport)
	#endif
#else
	#define JELLY_API
#endif

#if JELLY_DEBUG==2
	#define JELLY_LOG(x) std::cout<<x<<std::endl;
	#define JELLY_ERROR(x) std::cout<<x<<std::endl;
#elif defined JELLY_DEBUG == 1
	#define JELLY_LOG(x) 
	#define JELLY_ERROR(x) std::cout<<x<<std::endl;
#else
	#define JELLY_LOG(x)
	#define JELLY_ERROR(x)
#endif //  JELLY_DEBUG
