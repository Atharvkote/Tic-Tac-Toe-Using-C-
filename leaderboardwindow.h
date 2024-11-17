#ifndef LEADERBOARDWINDOW_H
#define LEADERBOARDWINDOW_H

#include <QWidget>
#include <QTableWidget>
#include <QVBoxLayout>

class LeaderboardWindow : public QWidget {
    Q_OBJECT

public:
    explicit LeaderboardWindow(QWidget *parent = nullptr);
    ~LeaderboardWindow();

    void addPlayer(const QString &name, int wins, int rank);  // Method to add players to the leaderboard

private:
    QTableWidget *tableWidget;
    void setupTable();
    void clearTable();
};

#endif // LEADERBOARDWINDOW_H
