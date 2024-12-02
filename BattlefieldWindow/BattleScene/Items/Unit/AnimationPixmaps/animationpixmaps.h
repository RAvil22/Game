#include <QPixmap>
#include <QList>

class AnimationPixmaps{
    QList<QPixmap*> pixmaps;
    uint16_t currentPixmapPos;
public:
    AnimationPixmaps(void) = default;
    ~AnimationPixmaps(void);
    bool appendPixmap(QString pathToSource, qreal width = 50, qreal height = 50, Qt::AspectRatioMode aspectRatio = Qt::KeepAspectRatio);
    bool insertPixmap(QString pathToSource, uint16_t position, qreal width = 50, qreal height = 50, Qt::AspectRatioMode aspectRatio = Qt::KeepAspectRatio);
    QPixmap* getPixmap(uint16_t position);
    QPixmap* nextPixmap(void);
};
