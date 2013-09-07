//
//  MyTableViewCell.h
//  TestTableVIew
//
//  Created by Bing on 13-9-7.
//
//

#ifndef __TestTableVIew__MyTableViewCell__
#define __TestTableVIew__MyTableViewCell__

#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;
class MyTableViewCell
: public CCTableViewCell
{

public:
    MyTableViewCell();
    ~MyTableViewCell();
    
public:
    CREATE_FUNC(MyTableViewCell);
    virtual bool init();
public:
    CCLabelTTF *m_tile;
};


#endif /* defined(__TestTableVIew__MyTableViewCell__) */
