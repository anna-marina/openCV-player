#ifndef FRAMETHREAD_H
#define FRAMETHREAD_H

#include <QThread>
#include <string>
#include "framebuffer.h"
#include "opencv2/opencv.hpp"

class FrameThread : public QThread
{
public:
    FrameThread(std::string file, FrameBuffer *buf);
    void run();
    void end();
    int getDelay();

private:
    bool running;
    FrameBuffer *buf;
    cv::VideoCapture capture;
};

#endif // FRAMETHREAD_H
