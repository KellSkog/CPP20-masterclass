add_executable(section21
    main.cpp
    exercise.cpp)
set_target_properties(section21 PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/build)
target_compile_features(section21 PUBLIC cxx_std_20)