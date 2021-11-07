add_executable(section13
    main.cpp)
set_target_properties(section13 PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/build)
target_compile_features(section13 PUBLIC cxx_std_20)