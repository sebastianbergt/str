add_library(str lower.cpp upper.cpp strip.cpp)

target_link_libraries(str PUBLIC project_options project_warnings)

#target_include_directories(str PUBLIC ${PROJECT_SOURCE_DIR}/include)

target_include_directories(str PUBLIC  
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>  
    $<INSTALL_INTERFACE:include>  # <prefix>/include/str
)


target_include_directories(str PRIVATE "${CMAKE_BINARY_DIR}/configured_files/include")

install(TARGETS str)

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
        FILES_MATCHING
        PATTERN "*.h*"
)