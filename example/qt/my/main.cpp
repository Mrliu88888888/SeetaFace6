#include <qapplication.h>
#include <qmainwindow.h>
#include <qpushbutton.h>
#include <qtimer.h>
#include <qlabel.h>
#include <qmessagebox.h>
#include <qlayout.h>
#include <qdebug.h>

#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/imgproc.hpp>

#include <seeta/FaceDetector.h>

class CameraApp : public QWidget
{
	Q_OBJECT

public:
	CameraApp(QWidget* parent = nullptr) : QWidget(parent)
	{
		QVBoxLayout* layout = new QVBoxLayout(this);

		videoLabel = new QLabel(this);
		startButton = new QPushButton("Start", this);
		stopButton = new QPushButton("Stop", this);

		layout->addWidget(videoLabel);
		layout->addWidget(startButton);
		layout->addWidget(stopButton);

		timer = new QTimer(this);

		connect(startButton, &QPushButton::clicked, this, &CameraApp::startCamera);
		connect(stopButton, &QPushButton::clicked, this, &CameraApp::stopCamera);
		connect(timer, &QTimer::timeout, this, &CameraApp::updateFrame);

		seeta::ModelSetting model;
		model.append("models/face_detector.csta");
		model.set_device(seeta::ModelSetting::CPU);
		model.set_id(0);
		fd = new seeta::FaceDetector(model);
	}

public slots:
	void startCamera()
	{
		cap.open(R"(D:\App\Download\1578807038-1-192.mp4)");
		if (!cap.isOpened()) {
			videoLabel->setText("Error: Unable to access the camera");
			return;
		}
		timer->start(33); // approximately 30 frames per second
	}

	void stopCamera()
	{
		timer->stop();
		cap.release();
		videoLabel->clear();
	}

	void updateFrame()
	{
		cv::Mat frame;
		cap >> frame;
		if (frame.empty()) return;

		SeetaImageData data = { 0 };
		data.height = frame.rows;
		data.width = frame.cols;
		data.channels = frame.channels();
		data.data = frame.data;

		auto faces = fd->detect(data);
		qDebug() << faces.size;

		cv::cvtColor(frame, frame, cv::COLOR_BGR2RGB);
		QImage image(frame.data, frame.cols, frame.rows, frame.step, QImage::Format_RGB888);
		videoLabel->setPixmap(QPixmap::fromImage(image));
	}

private:
	QLabel* videoLabel;
	QPushButton* startButton;
	QPushButton* stopButton;
	QTimer* timer;
	cv::VideoCapture cap;

private:
	seeta::FaceDetector* fd;
};
#include "main.moc"

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);

	CameraApp w;
	w.show();

	return app.exec();
}