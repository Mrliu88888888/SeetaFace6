project(seetaface_demo)

find_package(Qt5 COMPONENTS Core Gui Widgets Sql REQUIRED)
find_package(OpenCV REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

add_executable(${PROJECT_NAME}
	face_resource.qrc
	main.cpp
	mainwindow.cpp
	videocapturethread.cpp
	inputfilesprocessdialog.cpp
	resetmodelprocessdialog.cpp
)
target_include_directories(${PROJECT_NAME} PRIVATE
	"${SeetaFaceDir}/build/include"
)
target_link_directories(${PROJECT_NAME} PRIVATE
	"${SeetaFaceDir}/build/lib"
)
target_link_libraries(${PROJECT_NAME} PRIVATE
	Qt5::Core Qt5::Gui Qt5::Widgets Qt5::Sql
	opencv_core opencv_imgproc opencv_highgui opencv_videoio opencv_imgcodecs
	SeetaFaceDetector600${LIB_SUFFIX} SeetaFaceLandmarker600${LIB_SUFFIX}
	SeetaFaceAntiSpoofingX600${LIB_SUFFIX} SeetaFaceTracking600${LIB_SUFFIX}
	SeetaFaceRecognizer610${LIB_SUFFIX} SeetaQualityAssessor300${LIB_SUFFIX}
	SeetaPoseEstimation600${LIB_SUFFIX} SeetaAuthorize tennis${LIB_SUFFIX}
)
