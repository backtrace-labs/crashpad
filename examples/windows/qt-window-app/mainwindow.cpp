#include "mainwindow.hpp"
#include "./ui_mainwindow.h"

#include "backtrace.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

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
