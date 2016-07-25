#include "player.h"
#include <QPainter>

Player::Player(std::string fa, std::string fb, QWidget *parent) : QWidget(parent)
{
    ta = new FrameThread(fa, &a);
    tb = new FrameThread(fb, &b);

    ta->start();
    tb->start();

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(repaint()));
    timer->start(min(ta->getDelay(), tb->getDelay()));
}

Player::~Player()
{
    ta->end();
    tb->end();
    ta->wait();
    tb->wait();
    delete ta;
    delete tb;
}

void Player::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.fillRect(rect(), Qt::black);

    drawFrame(painter, a.read());
    drawCornerFrame(painter, b.read());

    painter.end();
}

void Player::drawFrame(QPainter& p, QImage image)
{
    QRect r(QPoint(0, 0),
            image.size().scaled(size(), Qt::KeepAspectRatio));

    r.moveCenter(rect().center());
    p.drawImage(r, image);
}

void Player::drawCornerFrame(QPainter& p, QImage image)
{
    QSize third = QSize(size().width() / 3, size().height() / 3);
    QRect r(QPoint(size().width() - third.width(),
                   size().height() - third.height()),
            image.size().scaled(third, Qt::KeepAspectRatio));

    p.drawImage(r, image);
}

