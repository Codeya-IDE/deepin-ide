file(GLOB SUPPORTFILES "${CMAKE_CURRENT_SOURCE_DIR}/*.support")
file(GLOB DESKTOPFILES "${CMAKE_CURRENT_SOURCE_DIR}/*.desktop")

# Icon installation according to freedesktop.org standards
install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/ide.svg"
        DESTINATION "/usr/share/icons/hicolor/scalable/apps")
install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/ide_32px.svg"
        DESTINATION "/usr/share/icons/hicolor/32x32/apps"
        RENAME "ide.svg")

install(FILES ${SUPPORTFILES} DESTINATION "${SOURCES_INSTALL_RPEFIX}/configures")
install(FILES ${DESKTOPFILES} DESTINATION "/usr/share/applications")
