# PCL Library CMAKE file

CMAKE_MINIMUM_REQUIRED(VERSION 3.14 FATAL_ERROR)

PROJECT(PCL)

SET(CMAKE_CXX_STANDARD 20)
SET(CMAKE_CXX_STANDARD_REQUIRED True)

set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/${PROJECT_NAME})

set(SOURCES
  source/common.cpp
  source/distance.cpp
  source/mass.cpp
  source/pressure.cpp
  source/temperature.cpp
  source/velocity.cpp
  )
set(HEADERS
  include/common.h
  include/constants.h
  include/distance.h
  include/mass.h
  include/pressure.h
  include/temperature.h
  include/velocity.h
  PCL
  )
  
set(DIRECTORIES  
  ${CMAKE_SOURCE_DIR}/GCL
  ${CMAKE_SOURCE_DIR}/SCL    
  ${CMAKE_SOURCE_DIR}/fmt/include
  ${Boost_INCLUDE_DIRS}
  ${CMAKE_SOURCE_DIR}/xlnt/include
  )


add_library(${PROJECT_NAME} STATIC ${SOURCES} ${HEADERS})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} PRIVATE ${DIRECTORIES})
