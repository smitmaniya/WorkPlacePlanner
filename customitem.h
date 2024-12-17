#ifndef CUSTOMITEM_H
#define CUSTOMITEM_H

#include <QGraphicsPixmapItem>
#include <QString>

class CustomItem : public QGraphicsPixmapItem
{
public:
    explicit CustomItem(const QString &name, const QString &imagePath,
                        QGraphicsItem *parent = nullptr);

    QString getName() const { return itemName; }

private:
    QString itemName;
};

#endif // CUSTOMITEM_H
