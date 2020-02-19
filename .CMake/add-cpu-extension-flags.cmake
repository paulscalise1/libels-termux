if(ARCH STREQUAL "x86" OR
   ARCH STREQUAL "x86_64")
    try_run(RUN_RESULT COMPILE_RESULT
            "${CMAKE_BINARY_DIR}" "${PROJECT_SOURCE_DIR}/.CMake/list-cpu-extensions.c"
            RUN_OUTPUT_VARIABLE RUN_OUTPUT)
    foreach(CPU_EXTENSION ${RUN_OUTPUT})
        set(USE_${CPU_EXTENSION}_INSTRUCTIONS TRUE)
    endforeach()
endif()
