#pragma once
#include "precompilehead.h"

#ifdef WWR_LIB
	#define WWR_API __declspec(dllexport)
#else 
	#define WWR_API __declspec(dllimport)
#endif


#ifdef WWR_DEBUG  
	#define WWR_LOG(x) std::cout<<x<<std::endl;
#else 
	#define WWR_LOG(x)
#endif