set(SOURCE_FILES
	EntryPoint.h
	include/Jelly.h
	JellyApplication.h
	JellyApplication.cpp
	Image.h
	Image.cpp
	ImageImpl.h
	codeOpenGL/OpenGLImage.h
	codeOpenGL/OpenGLImage.cpp
	Shaders.h
	Shaders.cpp
	ShadersImpl.h
	codeOpenGL/OpenGLShaders.h
	codeOpenGL/OpenGLShaders.cpp
	Renderer.h
	Renderer.cpp
	RendererImpl.h
	codeOpenGL/OpenGLRenderer.h
	codeOpenGL/OpenGLRenderer.cpp
	JellyWindow.h
	JellyWindow.cpp
	WindowImpl.h
	codeGLFW/WindowGLFW.h
	codeGLFW/WindowGLFW.cpp
	KeyCodes.h
	JellyEvents.h
	JellyEvents.cpp
	JellyUtilities.h
	Unit.h
	Unit.cpp
)
add_library(Jelly SHARED ${SOURCE_FILES})

target_compile_definitions(Jelly 
			PRIVATE 
				JELLY_LIB
			PUBLIC
				$<$<CONFIG:Debug>:JELLY_DEBUG=2>
				$<$<CONFIG:RelWithDebInfo>:JELLY_DEBUG=1>
				JELLY_OPENGL_STBI
				JELLY_GLFW
)

if(MSVC)
	target_compile_definitions(Jelly PUBLIC JELLY_MS_COMPILER)
endif()

target_precompile_headers(Jelly PRIVATE pch.h)

target_link_libraries(Jelly glfw glad stbi)

include_directories("../glad/include")
include_directories("../glfw/include")
include_directories("../stbi")
include_directories("../Jelly/")