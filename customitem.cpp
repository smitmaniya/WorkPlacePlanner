#include "customitem.h"
#include <QPixmap>

CustomItem::CustomItem(const QString &name, const QString &imagePath, QGraphicsItem *parent)
    : QGraphicsPixmapItem(parent), itemName(name)
{
    setPixmap(QPixmap(imagePath).scaled(100, 100, Qt::KeepAspectRatio));
    setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsMovable);
}


// // Mouse press: Initiate resizing or moving
// void CustomItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
// {
//     QRectF rect = this->boundingRect();
//     QPointF clickPos = event->pos();

//     // Detect bottom-right corner for resizing
//     if (qAbs(clickPos.x() - rect.width()) < 10 && qAbs(clickPos.y() - rect.height()) < 10) {
//         resizing = true;
//         lastMousePos = event->scenePos();
//         setCursor(Qt::SizeFDiagCursor);
//     } else {
//         QGraphicsPixmapItem::mousePressEvent(event); // Call base class implementation
//     }
// }

// // Mouse move: Handle resizing or moving
// void CustomItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
// {
//     if (resizing) {
//         QPointF delta = event->scenePos() - lastMousePos;

//         // Update pixmap size while maintaining aspect ratio
//         QPixmap pixmap = this->pixmap();
//         QSize newSize = pixmap.size() + QSize(delta.x(), delta.y());

//         if (newSize.width() > 20 && newSize.height() > 20) {
//             setPixmap(pixmap.scaled(newSize, Qt::KeepAspectRatio));
//         }

//         lastMousePos = event->scenePos();
//     } else {
//         QGraphicsPixmapItem::mouseMoveEvent(event); // Call base class implementation
//     }
// }

// // Mouse release: Stop resizing
// void CustomItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
// {
//     if (resizing) {
//         resizing = false;
//         setCursor(Qt::ArrowCursor);
//     }
//     QGraphicsPixmapItem::mouseReleaseEvent(event); // Call base class implementation
// }

// // Context menu: Handle rotate and delete actions
// void CustomItem::contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
// {
//     QMenu menu;
//     QAction *rotateAction = menu.addAction("Rotate 45°");
//     QAction *deleteAction = menu.addAction("Delete");

//     QAction *selectedAction = menu.exec(event->screenPos());

//     if (selectedAction == rotateAction) {
//         setRotation(rotation() + 45);
//     } else if (selectedAction == deleteAction) {
//         delete this;
//     }
// }
