#include "animationpixmaps.h"

AnimationPixmaps::~AnimationPixmaps()
{
    auto iter{this->pixmaps.begin()};
    while(iter != pixmaps.end())delete *iter;
}

bool AnimationPixmaps::appendPixmap(QString pathToSource, qreal width, qreal height, Qt::AspectRatioMode aspectRatio){
    QPixmap* newPixmap = new QPixmap(pathToSource);
    if(!newPixmap)return false;
    newPixmap->scaled(width, height, aspectRatio);
    pixmaps.append(newPixmap);
    if(pixmaps.size() == 1)currentPixmapPos = 0;
    return true;
}

bool AnimationPixmaps::insertPixmap(QString pathToSource, uint16_t position, qreal width, qreal height, Qt::AspectRatioMode aspectRatio){
    QPixmap* newPixmap = new QPixmap(pathToSource);
    if(!newPixmap)return false;
    newPixmap->scaled(width, height, aspectRatio);
    pixmaps.insert(position, newPixmap);
    if(pixmaps.size() == 1)currentPixmapPos = 0;
    return true;
}

QPixmap* AnimationPixmaps::getPixmap(uint16_t position){
    if(position >= pixmaps.size())return nullptr;
    return pixmaps.at(position);
}

QPixmap* AnimationPixmaps::nextPixmap(void){
    if(!pixmaps.size())return nullptr;
    if(pixmaps.at(currentPixmapPos) && currentPixmapPos < pixmaps.size())return pixmaps.at(currentPixmapPos++);
    else if(currentPixmapPos >= pixmaps.size()){
        currentPixmapPos = 0;
        return pixmaps.at(currentPixmapPos++);
    }
    else return nullptr;
}
