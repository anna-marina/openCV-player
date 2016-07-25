#include <QApplication>
#include "opencv2/opencv.hpp"
#include <player.h>
#include "framethread.h"

using namespace cv;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Player p(argv[1], argv[2]);
    p.show();

    return app.exec();
}
