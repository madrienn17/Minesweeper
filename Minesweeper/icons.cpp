#include "icons.h"

icons::icons()
{
    imgOne = new QIcon(":/imgs/one.png");
    imgTwo = new QIcon(":/imgs/two.png");
    imgThree = new QIcon(":/imgs/three.png");
    imgFour =  new QIcon(":/imgs/four.png");
    imgFive =  new QIcon(":/imgs/five.png");
    imgSix =  new QIcon(":/imgs/six.png");
    imgSeven =  new QIcon(":/imgs/seven.png");
    imgEight =  new QIcon(":/imgs/eight.png");
    imgFlag =  new QIcon(":/imgs/flag.png");
    imgMine =  new QIcon(":/imgs/mine.jpg");
    imgMineRed = new QIcon(":/imgs/mine_red.jpg");
}

icons::~icons()
{
    delete imgOne;
    delete imgTwo;
    delete imgThree;
    delete imgFour;
    delete imgFive;
    delete imgSix;
    delete imgSeven;
    delete imgEight;
    delete imgFlag;
    delete imgMine;
    delete imgMineRed;
}

QIcon *icons::getImgOne() const
{
    return imgOne;
}

QIcon * icons::getImgTwo() const
{
    return imgTwo;
}

QIcon *icons::getImgThree() const
{
    return imgThree;
}

QIcon *icons::getImgFour() const
{
    return imgFour;
}

QIcon *icons::getImgFive() const
{
    return imgFive;
}

QIcon *icons::getImgSix() const
{
    return imgSix;
}

QIcon *icons::getImgSeven() const
{
    return imgSeven;
}

QIcon *icons::getImgEight() const
{
    return imgEight;
}

QIcon *icons::getImgFlag() const
{
    return imgFlag;
}

QIcon *icons::getImgMine() const
{
    return imgMine;
}

QIcon *icons::getImgMineRed() const
{
    return imgMineRed;
}
