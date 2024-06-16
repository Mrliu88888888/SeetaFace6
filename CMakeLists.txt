cmake_minimum_required(VERSION 3.12)

project(SeetaFace6)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/${PROJECT_NAME}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/${PROJECT_NAME}/lib)
set(ARCHIVE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/${PROJECT_NAME}/lib)

set(SeetaFaceDir ${CMAKE_CURRENT_SOURCE_DIR})
set(CONFIGURATION ${CMAKE_BUILD_TYPE})
if ("${CONFIGURATION}" STREQUAL "Debug")
	set(LIB_SUFFIX "d")
endif ()

set(ORZ_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/OpenRoleZoo/include")
set(SeetaAuthorize_INCLUDE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/SeetaAuthorize/include")
set(TenniS_INCLUDE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/TenniS/include")
set(SeetaPoseEstimation_INCLUDE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/PoseEstimator6/PoseEstimation/include")
set(SeetaFaceDetector_INCLUDE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/FaceBoxes/FaceDetector/include")
set(SeetaAuthorize_LIBRARIES ${LIBRARY_OUTPUT_PATH}/SeetaAuthorize${LIB_SUFFIX}.lib)
set(TenniS_LIBRARIES ${LIBRARY_OUTPUT_PATH}/tennis${LIB_SUFFIX}.lib)
set(SeetaPoseEstimation_LIBRARIES ${LIBRARY_OUTPUT_PATH}/SeetaPoseEstimation600${LIB_SUFFIX}.lib)
set(SeetaFaceDetector_LIBRARIES ${LIBRARY_OUTPUT_PATH}/SeetaFaceDetector600${LIB_SUFFIX}.lib)



add_subdirectory(OpenRoleZoo)

add_subdirectory(SeetaAuthorize)
add_subdirectory(TenniS)
add_subdirectory(FaceAntiSpoofingX6)
add_subdirectory(FaceRecognizer6)
add_subdirectory(Landmarker)
add_subdirectory(PoseEstimator6)
add_subdirectory(SeetaAgePredictor)
add_subdirectory(SeetaEyeStateDetector)
add_subdirectory(SeetaGenderPredictor)
add_subdirectory(SeetaMaskDetector)
add_subdirectory(FaceBoxes)
add_subdirectory(QualityAssessor3)
add_subdirectory(FaceTracker6)

add_subdirectory(example/qt/seetaface_demo)
add_subdirectory(example/qt/my)
