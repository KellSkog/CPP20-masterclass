add_executable(section3
    main.cpp)
set_target_properties(section3 PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/build)
target_compile_features(section3 PUBLIC cxx_std_20)