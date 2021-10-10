add_executable(section7
    main.cpp)
set_target_properties(section7 PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/build)
target_compile_features(section7 PUBLIC cxx_std_20)