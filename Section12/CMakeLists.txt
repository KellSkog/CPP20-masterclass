add_executable(section12
    main.cpp)
set_target_properties(section12 PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/build)
target_compile_features(section12 PUBLIC cxx_std_20)