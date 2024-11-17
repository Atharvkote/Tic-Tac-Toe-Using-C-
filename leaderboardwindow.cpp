#include "leaderboardwindow.h"
#include <QHeaderView>

LeaderboardWindow::LeaderboardWindow(QWidget *parent) : QWidget(parent) {
    QVBoxLayout *layout = new QVBoxLayout(this);

    // Set up the table widget
    tableWidget = new QTableWidget(this);
    tableWidget->setColumnCount(3);  // Columns: Player Name, Wins, Rank
    QStringList headers{"Player Name", "Wins", "Rank"};
    tableWidget->setHorizontalHeaderLabels(headers);

    setupTable();  // Configure table settings

    layout->addWidget(tableWidget);
    setLayout(layout);
    setWindowTitle("Leaderboard");
}

LeaderboardWindow::~LeaderboardWindow() {}

void LeaderboardWindow::setupTable() {
    tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);   // Make cells non-editable
    tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);  // Select entire rows
    tableWidget->setSelectionMode(QAbstractItemView::SingleSelection); // Only one row at a time
    tableWidget->horizontalHeader()->setStretchLastSection(true);      // Stretch last column to fit window
    tableWidget->verticalHeader()->setVisible(false);                  // Hide row numbers
}

// Add player to the leaderboard table
void LeaderboardWindow::addPlayer(const QString &name, int wins, int rank) {
    int row = tableWidget->rowCount();
    tableWidget->insertRow(row);

    // Add player details to the leaderboard
    tableWidget->setItem(row, 0, new QTableWidgetItem(name));
    tableWidget->setItem(row, 1, new QTableWidgetItem(QString::number(wins)));
    tableWidget->setItem(row, 2, new QTableWidgetItem(QString::number(rank)));
}

// Clear the table (remove all rows)
void LeaderboardWindow::clearTable() {
    tableWidget->setRowCount(0);  // Set the row count to 0 to clear all rows
}
