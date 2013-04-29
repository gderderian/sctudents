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
#include "player.h"
#include "skateboarder.h"
#include "coffee.h"
#include "grades.h"
#include "food.h"
#include "extracredit.h"

#define WINDOW_MAX_X 750
#define WINDOW_MAX_Y 550

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
    QVBoxLayout *ecreditLayout;
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
    QLabel *ecredit;
    QLabel *ecreditnameLabel;
    QLabel *ecreditinfoLabel;
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
		int levelTimer;
		int timerRuns;
		int cols_with_sboarders;
		int cols_with_food;
		bool goUp;
		bool goDown;
		bool goLeft;
		bool goRight;
		bool gameStarted;
		bool paused;
		string levelname;
		QGraphicsPixmapItem *bg_img;
		Player *character;
		Grades *grade;
		Skateboarder *boarder;
		Coffee *starbucks;
		Food *eat;
		ExtraCredit *ec;
		vector<Thing*> objects;
public:

protected:
		void keyPressEvent(QKeyEvent *event);
		void keyReleaseEvent(QKeyEvent *event);
public slots:
		void startGame();
		void pauseGame();
		void handleTimer();
		void restartGame();
};

#endif // MAINWINDOW_H
