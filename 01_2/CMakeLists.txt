cmake_minimum_required(VERSION 3.2)

if($ENV{TRAVIS_BUILD_NUMBER})
    project(ip4_filter VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})
else()
    project(ip4_filter VERSION 0.0.1)
endif()

find_package(Boost COMPONENTS unit_test_framework REQUIRED)
add_executable(ip4_filter main.cpp)
add_library(ip4_handler ip4_handler.cpp)
add_executable(test_version test_version.cpp)

set_target_properties(ip4_filter ip4_handler test_version PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)
target_include_directories(ip4_handler
    PRIVATE "${CMAKE_BINARY_DIR}"
)

set_target_properties(test_version PROPERTIES
COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
)

target_link_libraries(ip4_filter PRIVATE
    ip4_handler
)

target_link_libraries(test_version
    ${Boost_LIBRARIES}
    ip4_handler
)

if (MSVC)
    target_compile_options(ip4_filter PRIVATE
        /W4
    )
    target_compile_options(ip4_handler PRIVATE
        /W4
    )
    target_compile_options(test_version PRIVATE
        /W4
    )
else ()
    target_compile_options(ip4_filter PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    target_compile_options(ip4_handler PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    target_compile_options(test_version PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()



install(TARGETS ip4_filter RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT example@example.com)

include(CPack)

enable_testing()

add_test(test_version test_version)
