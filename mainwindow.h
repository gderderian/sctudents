#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QTimer>
#include <QTimeLine>
#include <QGraphicsItemAnimation>
#include <QPushButton>
#include <QTextEdit>
#include <QLineEdit>
#include <QRadioButton>
#include <QListView>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <cstdlib>
#include <deque>
#include <cmath>
#include <vector>
#include <QFormLayout>
#include <QStringList>
#include <QStringListModel>
#include <string>
#include "thing.h"
#include "graphicwindow.h"
#include "player.h"
#include "skateboarder.h"
#include "coffee.h"
#include "grades.h"
#include "food.h"

#define WINDOW_MAX_X 650
#define WINDOW_MAX_Y 450

using namespace std;

class MainWindow : public QWidget {
    Q_OBJECT
    
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void show();
private:
		QWidget *window;
    QGraphicsScene *menuScene;
    QGraphicsView *menuView;
    QGraphicsScene *gameScene;
    QGraphicsView *gameView;
    QVBoxLayout *gameStackables;
    QVBoxLayout *mainStackables;
    QHBoxLayout *iconStackables;
    QHBoxLayout *gameBar;
    QHBoxLayout *menuBar;
    QVBoxLayout *skateboarderLayout;
    QVBoxLayout *trogroLayout;
    QVBoxLayout *gradesLayout;
    QVBoxLayout *foodLayout;
    QFormLayout *nameLayout;
    QLabel *gametitleLabel;
    QLabel *instructionsLabel;
    QLabel *directionsLabel;
    QLabel *skateboarder;
    QLabel *skateboardernameLabel;
    QLabel *skateboarderinfoLabel;
    QLabel *trogro;
    QLabel *trogronameLabel;
    QLabel *trogroinfoLabel;
    QLabel *grades;
    QLabel *gradesnameLabel;
    QLabel *gradesinfoLabel;
    QLabel *food;
    QLabel *foodnameLabel;
    QLabel *foodinfoLabel;
    QLabel *nameInstructions;
    QLineEdit *nameBox;
    QPushButton *startgameButton;
    QPushButton *ingamestartButton;
    QPushButton *ingamepauseButton;
    QPushButton *ingamequitButton;
		string userName;
		QLabel *usernameLabel;
		QLabel *levelnameLabel;
		QLabel *scoreLabel;
		QLabel *livesLabel;
		QTimer *gameTimer;
		int score;
		int lives;
		int level;
		int timerRuns;
		Player *character;
		Grades *grade;
		vector<Thing*> objects;
public:

protected:
		void keyPressEvent(QKeyEvent *event);
public slots:
		void startGame();
		void handleTimer();
};

#endif // MAINWINDOW_H
