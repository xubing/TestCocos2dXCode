//
//  StartGameLayer.cpp
//  MrDream
//
//  Created by Bing on 13-9-1.
//
//

#include "StartGameLayer.h"
#include "MyTableViewCell.h"


USING_NS_CC;
USING_NS_CC_EXT;

CCScene * StartGameLayer::scene()
{
    CCScene *scene =  CCScene::create();
    
    cocos2d::extension::CCNodeLoaderLibrary *ccNodeLoaderLibrary = cocos2d::extension::CCNodeLoaderLibrary::newDefaultCCNodeLoaderLibrary();
    
    ccNodeLoaderLibrary->registerCCNodeLoader("StartGameLayer",StartGameLayerLoader::loader());
    
    cocos2d::extension::CCBReader *ccBReader = new cocos2d::extension::CCBReader(ccNodeLoaderLibrary);
    ccBReader->autorelease();
    CCNode *node =ccBReader->readNodeGraphFromFile("startgame.ccbi");
    if(node != NULL)
    {
        scene->addChild(node);
    }
    
    return scene;
}

StartGameLayer::StartGameLayer()
: m_btn(NULL)
, m_tableDataArray(NULL)
{
    
}


StartGameLayer::~StartGameLayer()
{
    
}

    //CCBMemberVariableAssigner
bool StartGameLayer::onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode)
{
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "btn", CCControlButton*, this->m_btn);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "m_tableview_node", CCNode*, this->m_tableview_node);
    return true;
}

    //CCBSelectorResolver
SEL_MenuHandler StartGameLayer::onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char* pSelectorName)
{
//    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "onPressButton", StartGameLayer::onPressButton);
    
    return NULL;
}
SEL_CCControlHandler StartGameLayer::onResolveCCBCCControlSelector(CCObject * pTarget, const char* pSelectorName)
{
    CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "fuckyouccb", StartGameLayer::fuckyouccb);
//    CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "clickStartGame", StartGameLayer::clickStartGame);
//    CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "clickSetting", StartGameLayer::clickSetting);
    return NULL;
}

void StartGameLayer::onNodeLoaded(CCNode * pNode,cocos2d::extension::CCNodeLoader * pNodeLoader)
{
    CCLOG("load start Game layer Successfully.");
}


void StartGameLayer::onEnter()
{
    CCLayer::onEnter();
    
    m_tableDataArray = CCArray::createWithCapacity(0);
    m_tableDataArray->retain();
    
    m_tableView = CCTableView::create(this, CCSizeMake(300, 220));
    m_tableView->setPosition(ccp(50, 50));
    m_tableView->setAnchorPoint(ccp(0, 0));
    m_tableView->setDelegate(this);
    m_tableView->setDataSource(this);
    m_tableView->setVerticalFillOrder(kCCTableViewFillTopDown);
    this->addChild(m_tableView);
}

void StartGameLayer::fuckyouccb(cocos2d::CCObject * pSender, cocos2d::extension::CCControlEvent pCCControlEvent)
{
    CCLOG("click me");
    
    for (int i=0; i<15;i++)
    {
        m_tableDataArray->addObject(CCString::createWithFormat("Title: %i",i));
    }
    m_tableView->reloadData();
    
}
void StartGameLayer::clickStartGame(cocos2d::CCObject * pSender, cocos2d::extension::CCControlEvent pCCControlEvent)
{
    CCLOG("start GameLayer");
    
}

void StartGameLayer::clickSetting(cocos2d::CCObject * pSender, cocos2d::extension::CCControlEvent pCCControlEvent)
{
    CCLOG("clickSetting");
}

#pragma mark - TableView DataSource & Delegate
    //
CCSize StartGameLayer::tableCellSizeForIndex(CCTableView *table, unsigned int idx)
{
    return CCSizeMake(300, 35);
}

CCSize StartGameLayer::cellSizeForTable(CCTableView *table)
{
    return CCSizeMake(300, 35);
}

unsigned int StartGameLayer::numberOfCellsInTableView(CCTableView *table)
{
    return m_tableDataArray->count();
}

/**
 * a cell instance at a given index
 *
 * @param idx index to search for a cell
 * @return cell found at idx
 */
CCTableViewCell* StartGameLayer::tableCellAtIndex(CCTableView *table, unsigned int idx)
{
    MyTableViewCell *cell = dynamic_cast<MyTableViewCell*>(table->dequeueCell());
    if (cell == NULL)
    {
        cell = MyTableViewCell::create();
    }
    CCString *strname = static_cast<CCString*>(m_tableDataArray->objectAtIndex(idx));
    cell->m_tile->setString(strname->m_sString.c_str());
    
    return cell;
}

/**
 * Returns number of cells in a given table view.
 *
 * @return number of cells
 */

void StartGameLayer::tableCellTouched(CCTableView* table, CCTableViewCell* cell)
{
    CCLOG("tableCellTouched");
}

/**
 * Delegate to respond a table cell press event.
 *
 * @param table table contains the given cell
 * @param cell  cell that is pressed
 */
void StartGameLayer::tableCellHighlight(CCTableView* table, CCTableViewCell* cell)
{
    CCLOG("tableCellHighlight");    
}


void StartGameLayer::scrollViewDidScroll(CCScrollView* view)
{
       CCLOG("scrollViewDidScroll"); 
}
void StartGameLayer::scrollViewDidZoom(CCScrollView* view)
{
        CCLOG("scrollViewDidZoom");
}
