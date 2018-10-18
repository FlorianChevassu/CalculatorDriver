# This Superbuild script will download and build the CalculatorLibs subproject before building the CalculatorDriver project.

include(ExternalProject)

ExternalProject_Add(CalculatorLibs
                    GIT_REPOSITORY https://github.com/FlorianChevassu/CalculatorLibs.git
                    INSTALL_DIR "${CMAKE_BINARY_DIR}/CalculatorLibs-install"
                    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=<INSTALL_DIR>
                    )

ExternalProject_Add(CalculatorDriver
                    SOURCE_DIR ${CMAKE_SOURCE_DIR}
                    CMAKE_ARGS -DCalculatorLibs_DIR:PATH=${CMAKE_BINARY_DIR}/CalculatorLibs-install/cmake
                    INSTALL_COMMAND ""
                    DEPENDS CalculatorLibs
                    )
