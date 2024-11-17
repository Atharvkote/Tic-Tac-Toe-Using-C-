#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gamewindow.h"
#include "leaderboardwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
     setFixedSize(500, 600);

    // Initialize GameWindow and LeaderboardWindow
    gameWindow = new GameWindow(this);
    leaderboardWindow = new LeaderboardWindow(this);

    // Add GameWindow to the layout (or QStackedWidget)
    ui->stackedWidget->addWidget(gameWindow);
    ui->stackedWidget->addWidget(leaderboardWindow);

    // Connect buttons to switch between views
    connect(ui->startGameButton, &QPushButton::clicked, this, &MainWindow::startGame);
    connect(ui->leaderboardButton, &QPushButton::clicked, this, &MainWindow::showLeaderboard);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::startGame() {
    // Switch to the GameWindow
    ui->stackedWidget->setCurrentWidget(gameWindow);
}

void MainWindow::showLeaderboard() {
    // Switch to the LeaderboardWindow
    ui->stackedWidget->setCurrentWidget(leaderboardWindow);
}
