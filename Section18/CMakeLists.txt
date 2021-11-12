add_executable(section18
    main.cpp
    exercise.cpp)
set_target_properties(section18 PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/build)
target_compile_features(section18 PUBLIC cxx_std_20)