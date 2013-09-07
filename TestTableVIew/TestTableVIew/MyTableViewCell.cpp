//
//  MyTableViewCell.cpp
//  TestTableVIew
//
//  Created by Bing on 13-9-7.
//
//

#include "MyTableViewCell.h"

USING_NS_CC;
USING_NS_CC_EXT;


MyTableViewCell::MyTableViewCell()
: m_tile(NULL)
{
    
}

MyTableViewCell::~MyTableViewCell()
{
    
}

bool MyTableViewCell::init()
{
    
    m_tile = CCLabelTTF::create("", "Mar", 25);
    m_tile->setColor(ccRED);
    m_tile->setAnchorPoint(CCPointZero);
    m_tile->setPosition(CCPointZero);
    this->addChild(m_tile);
    return true;    
}