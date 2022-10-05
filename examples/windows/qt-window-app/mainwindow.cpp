#include "mainwindow.hpp"
#include "./ui_mainwindow.h"

#include <QDebug>
#include <QDir>
#include <QFile>
#include <QFileDialog>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

#include "backtrace.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    loadState();

    connect(ui->loadButton, &QPushButton::clicked,
        this, &MainWindow::loadState);
    connect(ui->saveButton, &QPushButton::clicked,
        this, &MainWindow::saveState);

    connect(ui->selectHandlerPath, &QPushButton::clicked,
        this, &MainWindow::selectHandlerPath);

    connect(ui->initializeCrashpadButton, &QPushButton::clicked,
        this, &MainWindow::initializeCrashpad);

    connect(ui->crashMemsetButton, &QPushButton::clicked,
        [](){ backtrace::crash_memset(); });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initializeCrashpad()
{
    auto url = ui->uploadURL->text().toStdString();
    if (backtrace::initialize_crashpad(url)) {
        ui->crashMemsetButton->setEnabled(true);
    }
}

void MainWindow::selectHandlerPath()
{
    auto f = QFileDialog::getOpenFileName(this, "Select handler executable",
        QDir::current().path());

    if (!f.isNull()) {
        ui->handlerPath->setText(f);
    }
}

void MainWindow::saveState()
{
    QJsonDocument doc;

    QJsonObject root, obj;
    for(QLineEdit* le : findChildren<QLineEdit*>()) {
        obj[le->objectName()] = le->text();
    }

    root["QLineEdit"] = obj;

    doc.setObject(root);
    auto data = doc.toJson();

    QFile f("qt-window-app.settings.json");
    if (f.open(QFile::WriteOnly | QFile::Text)) {
        f.write(data);
    }
}

void MainWindow::loadState()
{
    QFile f("qt-window-app.settings.json");
    if (!f.open(QFile::ReadOnly | QFile::Text))
        return;

    auto doc = QJsonDocument::fromJson(f.readAll());

    auto obj = doc.object()["QLineEdit"].toObject();

    for (auto const& key : obj.keys()) {
        auto* le = findChild<QLineEdit*>(key);
        if (!le)
            continue;
        le->setText(obj[key].toString());
    }
}
