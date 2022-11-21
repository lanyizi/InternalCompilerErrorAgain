# source file list
target_sources(${PROJECT_NAME} PRIVATE
    the_module.ixx
    utils.ixx
)
target_sources("${PROJECT_NAME}_Preprocessed" PRIVATE
    the_module.ixx
    utils.ixx
)
