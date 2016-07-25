#include "framethread.h"

FrameThread::FrameThread(std::string file, FrameBuffer *buf)
{
    capture = cv::VideoCapture(file);
    this->buf = buf;
}

void FrameThread::run()
{
    cv::Mat frame, tmp;
    QImage image;
    int delay = getDelay();
    running = true;

    while (running) {
        capture >> frame;
        if (frame.empty()) {
            capture.set(CV_CAP_PROP_POS_FRAMES, 0);
            continue;
        }
        //cvtColor(frame, tmp, CV_BGR2RGB);
        image = QImage(tmp.data, tmp.cols, tmp.rows,
                       tmp.cols * 3, QImage::Format_RGB888);
        buf->write(image);
        QThread::msleep(delay);
    }
}

void FrameThread::end()
{
    running = false;
}

int FrameThread::getDelay()
{
    int fps = capture.get(CV_CAP_PROP_FPS);
    return 1000 / fps;
}
