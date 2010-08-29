
cmake_minimum_required (VERSION 2.6)

IF(CMAKE_COMPILER_IS_GNUCC)
        set(CMAKE_C_FLAGS "-g -Wall -ansi -pedantic -W -Wconversion -Wshadow -Wcast-qual -Wwrite-strings")
ENDIF()

IF(MSVC)
        set(CMAKE_C_FLAGS "/Wall")
        # We don't want to use MSVC's more secure versions of functions. So suppressing the warnings
        add_definitions(-DWIN32 -D_CRT_SECURE_NO_WARNINGS)
ENDIF()
    
add_subdirectory(avl-tree)


