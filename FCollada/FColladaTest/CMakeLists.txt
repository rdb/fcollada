file(GLOB SOURCE_FILES
    "FCTestExportImport/*.cpp"
    "FCTestXRef/*.cpp"
    "FCTestAssetManagement/*.cpp"
    "*.cpp"
)

add_executable(FColladaTest ${SOURCE_FILES})

target_link_libraries(FColladaTest ${LIBRARY_NAME})
