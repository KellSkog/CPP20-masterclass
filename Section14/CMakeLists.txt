add_executable(section14
    main.cpp)
set_target_properties(section14 PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/build)
target_compile_features(section14 PUBLIC cxx_std_20)