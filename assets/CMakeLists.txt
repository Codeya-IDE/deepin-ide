# install templates.
install(DIRECTORY templates/
    DESTINATION "${SOURCES_INSTALL_RPEFIX}/templates")
install(DIRECTORY models/
    DESTINATION "${SOURCES_INSTALL_RPEFIX}/models")

find_package(Qt${QT_VERSION_MAJOR} COMPONENTS LinguistTools REQUIRED)

# Set up translation files
set(TS_DIR "${CMAKE_CURRENT_SOURCE_DIR}/translations")
file(GLOB TS_FILES "${TS_DIR}/*.ts")
set_source_files_properties(${TS_FILES} PROPERTIES OUTPUT_LOCATION "${TS_DIR}")

if (QT_VERSION_MAJOR EQUAL 6)
    qt6_add_translation(QM_FILES ${TS_FILES})
else()
    qt5_add_translation(QM_FILES ${TS_FILES})
endif()

add_custom_target(${PROJECT_NAME}_translations ALL DEPENDS ${QM_FILES})
add_dependencies(${PROJECT_NAME} ${PROJECT_NAME}_translations)

# install translation.
install(FILES ${QM_FILES} DESTINATION "${SOURCES_INSTALL_RPEFIX}/translations")

# install tools
set(TOOL_INSTALL_PATH "/usr/lib/${CMAKE_LIBRARY_ARCHITECTURE}/${CMAKE_PROJECT_NAME}/tools/env")
message("tool install path: ${TOOL_INSTALL_PATH}")
file(GLOB TOOL_FILES "${CMAKE_SOURCE_DIR}/assets/tools/*.tar.gz")
message(STATUS "TOOL_FILES ${TOOL_FILES}")
install(FILES ${TOOL_FILES} DESTINATION ${TOOL_INSTALL_PATH})

# install configure files.
file(GLOB SUPPORTFILES "${CMAKE_CURRENT_SOURCE_DIR}/configures/*.support")
file(GLOB DESKTOPFILES "${CMAKE_CURRENT_SOURCE_DIR}/configures/*.desktop")

# Icon installation according to freedesktop.org standards
install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/configures/ide.svg"
        DESTINATION "/usr/share/icons/hicolor/scalable/apps")
install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/configures/ide_32px.svg"
        DESTINATION "/usr/share/icons/hicolor/32x32/apps"
        RENAME "ide.svg")

install(FILES ${SUPPORTFILES} DESTINATION "${SOURCES_INSTALL_RPEFIX}/configures")
install(FILES ${DESKTOPFILES} DESTINATION "/usr/share/applications")