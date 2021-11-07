add_executable(section15
    main.cpp)
set_target_properties(section15 PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/build)
target_compile_features(section15 PUBLIC cxx_std_20)