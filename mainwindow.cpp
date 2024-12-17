#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "customitem.h"
#include <QFile>
#include <QDomDocument>
#include <QMessageBox>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("Workplace Planner");
    resize(1200, 800);

    // Initialize the scene
    scene = new QGraphicsScene(this);
    ui->graphicsViewCanvas->setScene(scene);
    ui->graphicsViewCanvas->setFocus();
    ui->graphicsViewCanvas->setInteractive(true);

    setupUI();
    drawGrid();
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Initialize the UI
void MainWindow::setupUI()
{
    QStringList items = {"Chair", "Table", "Work Zone", "Office Zone", "Storage Zone"};
    for (const QString &item : items) {
        ui->listWidgetItems->addItem(item);
    }

    connect(ui->listWidgetItems, &QListWidget::itemClicked, this, &MainWindow::addItemToScene);
    connect(ui->buttonExport, &QPushButton::clicked, this, &MainWindow::exportToXML);
    connect(ui->buttonImport, &QPushButton::clicked, this, &MainWindow::importFromXML);
}

// Draw grid lines for alignment
void MainWindow::drawGrid()
{
    const int gridSize = 50;
    const int sceneSize = 2000;
    QPen gridPen(QColor(200, 200, 200, 50), 1, Qt::DotLine);

    for (int x = 0; x < sceneSize; x += gridSize)
        scene->addLine(x, 0, x, sceneSize, gridPen)->setZValue(-10);

    for (int y = 0; y < sceneSize; y += gridSize)
        scene->addLine(0, y, sceneSize, y, gridPen)->setZValue(-10);

    scene->setSceneRect(0, 0, sceneSize, sceneSize);
}

// Add an item to the workspace
void MainWindow::addItemToScene(QListWidgetItem *item)
{
    CustomItem *customItem = nullptr;

    if (item->text() == "Chair") {
        customItem = new CustomItem("Chair", ":/images/chair.jpg");
    } else if (item->text() == "Table") {
        customItem = new CustomItem("Table", ":/images/table.png");
    } else if (item->text() == "Work Zone") {
        customItem = new CustomItem("Work Zone", ":/images/workzone.png");
    } else if (item->text() == "Office Zone") {
        customItem = new CustomItem("Office Zone", ":/images/officezone.png");
    } else if (item->text() == "Storage Zone") {
        customItem = new CustomItem("Storage Zone", ":/images/storagezone.png");
    }

    if (customItem) {
        scene->addItem(customItem);
        customItem->setPos(100, 100); // Default position
    }
}

// Export the workspace to an XML file
void MainWindow::exportToXML()
{
    QDomDocument doc;
    QDomElement root = doc.createElement("workspace");
    doc.appendChild(root);

    for (QGraphicsItem *item : scene->items()) {
        CustomItem *customItem = dynamic_cast<CustomItem *>(item);
        if (customItem) {
            QDomElement element = doc.createElement("Object");
            element.setAttribute("name", customItem->getName());
            element.setAttribute("x", customItem->x());
            element.setAttribute("y", customItem->y());
            element.setAttribute("width", customItem->pixmap().width());
            element.setAttribute("height", customItem->pixmap().height());
            element.setAttribute("rotation", customItem->rotation());
            root.appendChild(element);
        }
    }

    QString fileName = QFileDialog::getSaveFileName(this, "Export Plan", "", "XML Files (*.xml)");
    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (file.open(QIODevice::WriteOnly)) {
            QTextStream stream(&file);
            doc.save(stream, 4);
            file.close();
            QMessageBox::information(this, "Success", "Plan exported successfully!");
        }
    }
}

// Import a workspace from an XML file
void MainWindow::importFromXML()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Import Plan", "", "XML Files (*.xml)");
    if (fileName.isEmpty()) return;

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::critical(this, "Error", "Failed to open XML file.");
        return;
    }

    QDomDocument doc;
    if (!doc.setContent(&file)) {
        QMessageBox::critical(this, "Error", "Failed to parse XML file.");
        file.close();
        return;
    }
    file.close();

    scene->clear();
    drawGrid();

    QDomNodeList objects = doc.documentElement().elementsByTagName("Object");

    for (int i = 0; i < objects.count(); ++i) {
        QDomElement element = objects.at(i).toElement();

        QString name = element.attribute("name");
        qreal x = element.attribute("x").toDouble();
        qreal y = element.attribute("y").toDouble();
        QString imagePath;

        if (name == "Chair") imagePath = ":/Resources/Images/chair.jpg";
        else if (name == "Table") imagePath = ":/images/table.png";
        else if (name == "Work Zone") imagePath = ":/images/workzone.png";
        else if (name == "Office Zone") imagePath = ":/images/officezone.png";
        else if (name == "Storage Zone") imagePath = ":/images/storagezone.png";

        CustomItem *item = new CustomItem(name, imagePath);
        item->setPos(x, y);
        scene->addItem(item);
    }

    QMessageBox::information(this, "Success", "Plan imported successfully!");
}
