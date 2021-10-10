add_executable(section6
    main.cpp)
set_target_properties(section6 PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/build)
target_compile_features(section6 PUBLIC cxx_std_20)