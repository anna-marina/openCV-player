#ifndef PLAYER_H
#define PLAYER_H

#include <QWidget>
#include <QTimer>
#include "framebuffer.h"
#include "framethread.h"
#include "opencv2/opencv.hpp"
using namespace cv;

class Player : public QWidget
{
    Q_OBJECT
public:
    //explicit Player(FrameBuffer *a, FrameBuffer *b, QWidget *parent = 0);
    explicit Player(std::string a, std::string b, QWidget *parent = 0);
    ~Player();

protected:
    void paintEvent(QPaintEvent *);

private:
    FrameThread *ta, *tb;
    FrameBuffer a, b;
    QTimer *timer;

    void drawFrame(QPainter& p, QImage image);
    void drawCornerFrame(QPainter& p, QImage image);
};

#endif // PLAYER_H
