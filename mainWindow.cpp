#include "mainWindow.h"
// #include "ui_mainwindow.h"
// #include "desktop.h"

#include <QProcessEnvironment>
#include <QHeaderView>

void MainWindow::InitializeTable() {
  QTableWidget *table = new QTableWidget();
  table->setObjectName("table");
  this->setCentralWidget(table);
  QStringList labels = {"Name", "Active Window Title"};
  table->setColumnCount(labels.size());
  table->setHorizontalHeaderLabels(labels);
  table->setSelectionBehavior(QAbstractItemView::SelectRows);
  table->setEditTriggers(QAbstractItemView::NoEditTriggers);
  table->horizontalHeader()->setStretchLastSection(true);
  table->setContextMenuPolicy(Qt::CustomContextMenu);
  connect(table, &QWidget::customContextMenuRequested, this, &MainWindow::tableContextMenuRequested);
  this->table = table;
}

void MainWindow::tableContextMenuRequested(const QPoint &pos) {
    this->selectedClientName = this->table->itemAt(QPoint(0, pos.y()))->text();
    QMenu *menu = new QMenu(this->table);
    QAction *desktopAction = new QAction("Desktop");
    connect(desktopAction, &QAction::triggered, this, &MainWindow::desktopRequested);
    menu->addAction(desktopAction);
    menu->exec(QCursor::pos());
}

MainWindow::~MainWindow() { delete ui; }
