add_executable(section20
    main.cpp
    exercise.cpp)
set_target_properties(section20 PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/build)
target_compile_features(section20 PUBLIC cxx_std_20)