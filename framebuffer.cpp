#include "framebuffer.h"

QImage FrameBuffer::read()
{
    readState.lock();
    reading = readPart;
    readState.unlock();

    if (access[reading].tryLock()) {
        readResult = buf[reading];
        access[reading].unlock();
    }

    return readResult;
}

void FrameBuffer::write(QImage image)
{
    /* Though loop is potentially infinity
     * actually it runs at most two iterations */
    while (true) {
        readState.lock();
        readPart = writePart;
        writePart = (writePart + 1) % bufferSize;
        readState.unlock();

        if (access[writePart].tryLock())
            break;
    }

    buf[writePart] = image;
    access[writePart].unlock();
}
