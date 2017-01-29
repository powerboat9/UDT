CMAKE_MINIMUM_REQUIRED(VERSION 3.2.2)
PROJECT(UDT)
INCLUDE(ExternalProject)

ExternalProject_Add(project_libsndfile
    GIT_REPOSITORY      https://github.com/erikd/libsndfile.git
    PREFIX              lib/libsndfile
    CONFIGURE_COMMAND   <SOURCE_DIR>/configure
    BUILD_COMMAND       make
    BUILD_IN_SOURCE     1
    INSTALL_COMMAND     echo Skipping install step for libsndfile
)

ExternalProject_Add_Step(project_libsndfile autogen
   COMMAND              <SOURCE_DIR>/autogen.sh
   DEPENDEES            update
   DEPENDERS            configure
)
