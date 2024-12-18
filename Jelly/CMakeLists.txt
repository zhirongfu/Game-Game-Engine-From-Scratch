set(SOURCE_FILES
	EntryPoint.h
	include/Jelly.h
	JellyApplication.h
	JellyApplication.cpp
	
)
add_library(Jelly STATIC ${SOURCE_FILES})

target_compile_definitions(Jelly 
			PRIVATE 
				JELLY_LIB
			PUBLIC
				$<$<CONFIG:Debug>:JELLY_DEBUG=2>
				$<$<CONFIG:RelWithDebInfo>:JELLY_DEBUG=1>
				JELLY_OPENGL_STBI
)

if(MSVC)
	target_compile_definitions(Jelly PUBLIC JELLY_MS_COMPILER)
endif()

target_precompile_headers(Jelly PRIVATE pch.h)

target_link_libraries(Jelly glfw)