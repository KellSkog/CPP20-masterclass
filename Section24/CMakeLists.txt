add_executable(section24
    main.cpp
    exercise.cpp)
set_target_properties(section24 PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/build)
target_compile_features(section24 PUBLIC cxx_std_20)
target_compile_options(section24 PUBLIC -g)