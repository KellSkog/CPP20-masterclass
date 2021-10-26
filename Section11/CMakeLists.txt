add_executable(section11
    main.cpp)
set_target_properties(section11 PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/build)
target_compile_features(section11 PUBLIC cxx_std_20)