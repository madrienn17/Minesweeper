#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "welcomewindow.h"

MainWindow::MainWindow(int xDim, int yDim)
    : ui(new Ui::MainWindow),
      xDim(xDim), yDim(yDim)
{
    ui->setupUi(this);
    start();
    connectAll();
}

MainWindow::MainWindow(int xDim, int yDim, int nrBomb)
    : ui(new Ui::MainWindow),
      xDim(xDim), yDim(yDim), nrBomb(nrBomb)
{
    ui->setupUi(this);
    start();
    connectAll();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::connectAll() {
    connect(this, SIGNAL(win()),this, SLOT(winmsg()));
    connect(this, SIGNAL (lose()), this, SLOT(losemsg()));

    //handling the menu items
    connect(ui->actionNew_Game, &QAction::triggered, [this]{newGame();});
    connect(ui->actionRestart, &QAction::triggered, [this]{restart();});
    connect(ui->actionExit, &QAction::triggered, []{QApplication::quit();});
}

void MainWindow::setIcons(int x, int y) {
    switch (fields[x][y].value) {
        case 1: {
            newBtns[x][y]->setIcon(*myicons->getImgOne());
            break;
        }
        case 2: {
            newBtns[x][y]->setIcon(*myicons->getImgTwo());
            break;
        }
        case 3: {
            newBtns[x][y]->setIcon(*myicons->getImgThree());
            break;
        }
        case 4: {
            newBtns[x][y]->setIcon(*myicons->getImgFour());
            break;
        }
        case 5: {
            newBtns[x][y]->setIcon(*myicons->getImgFive());
            break;
        }
        case 6: {
            newBtns[x][y]->setIcon(*myicons->getImgSix());
            break;
        }
        case 7: {
            newBtns[x][y]->setIcon(*myicons->getImgSeven());
            break;
        }
        case 8: {
            newBtns[x][y]->setIcon(*myicons->getImgEight());
            break;
        }
    }
}

void MainWindow::start() {
    myicons = new icons;
    timer = new QTimer();
    elapsedt = new QElapsedTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(refreshTime()));

    QVBoxLayout* layout = new QVBoxLayout();
    btnLay = new QGridLayout();
    btnLay->setSpacing(1);
    QHBoxLayout* labelLay =new QHBoxLayout();
    bombsLabel = new QLabel(QString::number(nrBomb));
    timeLabel = new QLabel("");
    QLabel* minetxt = new QLabel("mines left: ");

    minetxt->setAlignment(Qt::AlignLeft);
    timeLabel->setAlignment(Qt::AlignRight);

    labelLay->addWidget(minetxt);
    labelLay->addWidget(bombsLabel);
    labelLay->addWidget(timeLabel);

    layout->addLayout(labelLay);
    layout->addLayout(btnLay);

    newBtns = new RightClickBtn**[xDim];
    fields = new Field*[xDim];
    for (int i=0; i<xDim; ++i) {
        newBtns[i] = new RightClickBtn*[yDim];
        fields[i] = new Field[yDim];
    }
    fill();
    generate();
    for (int i = 0; i < xDim; ++i)
    {
        for (int j = 0; j < yDim; ++j)
        {
            newBtns[i][j] = new RightClickBtn();
            newBtns[i][j]->setMinimumSize(40, 40);
            newBtns[i][j]->setIconSize(QSize(40, 40));

            connect(newBtns[i][j], &RightClickBtn::clicked, [this, i, j]{
                actionBtn(i, j);
            });

            connect(newBtns[i][j], &RightClickBtn::rightClick, [this, i, j]{
                onRightClick(i, j);
            });

            btnLay->addWidget(newBtns[i][j], i, j);
        }
    }
    ui->centralwidget->setLayout(layout);
    timer->start();
    elapsedt->start();
}

void MainWindow::newGame() {
    this->close();
    WelcomeWindow *w = new WelcomeWindow();
    w->show();
}

void MainWindow::generate() {
    srand(time(NULL));
    int x, y;
    int currMine = 0;

    while(currMine != nrBomb) {
        x = rand() % xDim;
        y = rand() % yDim;

        if(fields[x][y].value != -1) {
            fields[x][y].value = -1;
            ++currMine;
            count(x,y);
        }
    }
}

void MainWindow::increment(int a, int b) {
    if(fields[a][b].value != -1) {
        ++fields[a][b].value;
    }
}

void MainWindow::count(int i, int j) {
    if (i-1 >= 0 && j-1 >= 0) {
        increment(i-1, j-1);
    }
    if (i-1 >= 0){
        increment(i-1, j);
    }
    if (i-1 >= 0 && j+1 < yDim){
        increment(i-1, j+1);
    }
    if (j-1 >= 0){
        increment(i, j-1);
    }
    if (j+1 < yDim){
        increment(i, j+1);
    }
    if (i+1 < xDim&& j-1 >= 0){
        increment(i+1, j-1);
    }
    if (i+1 < xDim){
        increment(i+1, j);
    }
    if (i+1 < xDim&& j+1 < yDim){
        increment(i+1, j+1);
    }
}


void MainWindow::showAll(int x, int y) {
    for (int i = 0; i < xDim; ++i)
    {
        for (int j = 0; j < yDim; ++j)
        {
            if (fields[i][j].value == -1)
            {
                if (i == x && j == y)
                {
                    newBtns[x][y]->setIcon(*myicons->getImgMineRed());
                } else
                {
                    if (!fields[i][j].flagged) {
                        newBtns[i][j]->setIcon(*myicons->getImgMine());
                    }
                }
            }
        }
    }
}

void MainWindow::clear(int x, int y) {
    if (fields[x][y].value == 0 && !fields[x][y].visited)
    {
        newBtns[x][y]->setStyleSheet("border: none;");

        fields[x][y].visited = true;

        if ((x-1) > -1) clear(x-1, y);

        if ((y-1) > -1) clear(x, y-1);

        if ((x+1) < xDim) clear(x+1, y);

        if ((y+1) < yDim) clear(x, y+1);
    }
    else
    {
        if (fields[x][y].value != 0)
        {
            newBtns[x][y]->setStyleSheet("border: none;");
            fields[x][y].visited = true;
            setIcons(x, y);
        }
    }
}


void MainWindow::fill() {
    for (int i = 0; i < xDim; ++i) {
        for (int j = 0; j < yDim; ++j) {
            fields[i][j].value = 0;
            fields[i][j].visited = false;
            fields[i][j].flagged = false;
        }
    }
}

void MainWindow::actionBtn(int x, int y){
    if (!fields[x][y].flagged) {
        auto isMine = fields[x][y].value;
        switch (isMine)
        {
        case -1:
        {
            timer->stop();
            showAll(x, y);
            emit lose();
            break;
        }
        case 0:
        {
            clear(x, y);
            break;
        }
        default:
        {
            if (!fields[x][y].visited) {
                setIcons(x, y);
                fields[x][y].visited = true;
            }
        }
        }
    }

    if (btnsLeft() == nrBomb) {
        emit win();
    }
}

void MainWindow::refreshTime() {
    qint64 totalNumberOfSeconds = elapsedt->elapsed() / 1000;

    int seconds = totalNumberOfSeconds % 60;
    int minutes = (totalNumberOfSeconds / 60) % 60;
    int hours = (totalNumberOfSeconds / 60 / 60);

    QString timeString = QString("%1:%2:%3")
      .arg(hours, 2, 10, QChar('0'))
      .arg(minutes, 2, 10, QChar('0'))
      .arg(seconds, 2, 10, QChar('0'));

    timeLabel->setText(timeString);
}

void MainWindow::onRightClick(int x, int y) {
    if (!fields[x][y].visited) {
        int bombsLeft = bombsLabel->text().toInt();
        if (bombsLeft > 0 && !fields[x][y].flagged)
        {
            bombsLabel->setText(QString::number(--bombsLeft));
            newBtns[x][y]->setIcon(*myicons->getImgFlag());
            fields[x][y].flagged = true;
        }
        else
        {
            if (fields[x][y].flagged)
            {
                bombsLabel->setText(QString::number(++bombsLeft));
                newBtns[x][y]->setIcon(QIcon());
                fields[x][y].flagged = false;
            }
        }
        if (bombsLeft == 0) {
            if (btnsLeft() == nrBomb) {
                emit win();
            }
        }
    }
}

void MainWindow::winmsg() {
    timer->stop();
    QMessageBox messageBox;
    QMessageBox::StandardButton reply;
    reply = messageBox.warning(this, "Congrats","You Win!\nYour time: " + timeLabel->text(), QMessageBox::Retry | QMessageBox::Close);
    messageBox.setFixedSize(500,200);

    if (reply == QMessageBox::Retry) {
        newGame();
    } else {
        QApplication::quit();
    }
}

void MainWindow::losemsg() {
    QMessageBox messageBox;
    QMessageBox::StandardButton reply;
    reply = messageBox.critical(this, "Game over", "You lost the game :( !", QMessageBox::Retry | QMessageBox::Close);
    messageBox.setFixedSize(500,200);

    if (reply == QMessageBox::Retry) {
        restart();
    } else {
        QApplication::quit();
    }
}


void MainWindow::restart() {
    fields = new Field*[xDim];
    for (int i = 0; i < xDim; ++i) {
        fields[i] = new Field[yDim];
    }
    fill();
    for (int i = 0; i < xDim; ++i)
    {
        for (int j = 0; j < yDim; ++j)
        {
            newBtns[i][j]->setText("");
            fields[i][j].visited = false;
            newBtns[i][j]->setIcon(QIcon()); // basically remove the icon
            newBtns[i][j]->setStyleSheet("border-bottom: 2px solid #7B7B7B; \
                                         border-left: 2px solid #ffffff;    \
                                         border-top: 2px solid #ffffff;     \
                                         border-right: 2px solid #7B7B7B;");
        }
    }

    generate();
    timer->start();
    elapsedt->start();
    bombsLabel->setText(QString::number(nrBomb));
}

int MainWindow::btnsLeft() {
    int temp = 0;
    for (int i = 0; i < xDim; ++i) {
        for (int j = 0; j < yDim; ++j) {
            if (!fields[i][j].visited) {
                ++temp;
                if (temp > nrBomb) {
                    return temp;
                }
            }
        }
    }

    return temp;
}
