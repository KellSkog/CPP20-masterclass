add_executable(section10
    main.cpp)
set_target_properties(section10 PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/build)
target_compile_features(section10 PUBLIC cxx_std_20)