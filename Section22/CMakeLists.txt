add_executable(section22
    main.cpp
    exercise.cpp)
set_target_properties(section22 PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/build)
target_compile_features(section22 PUBLIC cxx_std_20)