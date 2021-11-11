add_executable(section16
    main.cpp
    exercise.cpp)
set_target_properties(section16 PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/build)
target_compile_features(section16 PUBLIC cxx_std_20)