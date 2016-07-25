#ifndef FRAMEBUFFER_H
#define FRAMEBUFFER_H

#include <QImage>
#include <QMutex>

/* Big enough to guarantee exclusive
   access for reader and writer */
const int bufferSize = 5;

class FrameBuffer
{
public:
    QImage read();
    void write(QImage);

private:
    QImage buf[bufferSize], readResult;
    QMutex access[bufferSize], readState;
    int reading;
    int readPart = 0, writePart = 0;
};

#endif // FRAMEBUFFER_H
