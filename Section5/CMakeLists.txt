add_executable(section5
    main.cpp)
set_target_properties(section5 PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/build)
target_compile_features(section5 PUBLIC cxx_std_20)