set (TARGET_NAME doxygen-lua)

set (SOURCE_FILES
	Lexer.cpp
	String.cpp
	File.cpp)

# enable_precompiled_header ()

if (WIN32)
	add_executable (${TARGET_NAME} WIN32 ${SOURCE_FILES})
else (WIN32)
	add_executable (${TARGET_NAME} ${SOURCE_FILES})
endif (WIN32)

INSTALL(TARGETS doxygen-lua DESTINATION ${PROJECT_BINARY_DIR}/Bin)