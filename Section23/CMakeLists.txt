add_executable(section23
    main.cpp
    exercise.cpp)
set_target_properties(section23 PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/build)
target_compile_features(section23 PUBLIC cxx_std_20)
target_compile_options(section23 BEFORE PUBLIC -g)