#ifndef ICONS_H
#define ICONS_H

#include <QIcon>

class icons
{
private:
    QIcon* imgOne;
    QIcon* imgTwo;
    QIcon* imgThree;
    QIcon* imgFour;
    QIcon* imgFive;
    QIcon* imgSix;
    QIcon* imgSeven;
    QIcon* imgEight;
    QIcon* imgFlag;
    QIcon* imgMine;
    QIcon* imgMineRed;
public:
    icons();
    ~icons();
    QIcon *getImgOne() const;
    QIcon *getImgTwo() const;
    QIcon *getImgThree() const;
    QIcon *getImgFour() const;
    QIcon *getImgFive() const;
    QIcon *getImgSix() const;
    QIcon *getImgSeven() const;
    QIcon *getImgEight() const;
    QIcon *getImgFlag() const;
    QIcon *getImgMine() const;
    QIcon *getImgMineRed() const;

};

#endif // ICONS_H
