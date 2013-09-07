//
//  StartGameLayer.h
//  MrDream
//
//  Created by Bing on 13-9-1.
//
//

#ifndef __MrDream__StartGameLayer__
#define __MrDream__StartGameLayer__

#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

class CCBReader;

class StartGameLayer
: public cocos2d:: CCLayer
, public cocos2d::extension::CCBSelectorResolver
, public cocos2d::extension::CCBMemberVariableAssigner
, public cocos2d::extension::CCNodeLoaderListener
, public CCTableViewDataSource
, public CCTableViewDelegate
{
public:
    StartGameLayer();
    ~StartGameLayer();
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(StartGameLayer, create);
    static cocos2d::CCScene* scene();
    
    //loader
    void onNodeLoaded(CCNode * pNode,cocos2d::extension::CCNodeLoader * pNodeLoader);
    
    //CCBMemberVariableAssigner
    bool onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode);
    
        //CCBSelectorResolver
    SEL_MenuHandler onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char* pSelectorName) ;
    cocos2d::extension::SEL_CCControlHandler onResolveCCBCCControlSelector(CCObject * pTarget, const char* pSelectorName);
    
        //
    virtual CCSize tableCellSizeForIndex(CCTableView *table, unsigned int idx);    /**
     * cell height for a given table.
     *
     * @param table table to hold the instances of Class
     * @return cell size
     */
    virtual CCSize cellSizeForTable(CCTableView *table);
   
    virtual unsigned int numberOfCellsInTableView(CCTableView *table);
    /**
     * a cell instance at a given index
     *
     * @param idx index to search for a cell
     * @return cell found at idx
     */
    virtual CCTableViewCell* tableCellAtIndex(CCTableView *table, unsigned int idx);
    /**
     * Returns number of cells in a given table view.
     *
     * @return number of cells
     */
    
    virtual void tableCellTouched(CCTableView* table, CCTableViewCell* cell);
    
    /**
     * Delegate to respond a table cell press event.
     *
     * @param table table contains the given cell
     * @param cell  cell that is pressed
     */
    virtual void tableCellHighlight(CCTableView* table, CCTableViewCell* cell);
    

    virtual void scrollViewDidScroll(CCScrollView* view);
    virtual void scrollViewDidZoom(CCScrollView* view);

    virtual void onEnter();
    
public:
    
    void fuckyouccb(cocos2d::CCObject * pSender, cocos2d::extension::CCControlEvent pCCControlEvent);
    void clickStartGame(cocos2d::CCObject * pSender, cocos2d::extension::CCControlEvent pCCControlEvent);
    void clickSetting(cocos2d::CCObject * pSender, cocos2d::extension::CCControlEvent pCCControlEvent);
    CCControlButton *m_btn;
  
    
public:
    CCNode*         m_tableview_node;
    CCTableView*    m_tableView;
    
    CCArray*        m_tableDataArray;
};


class StartGameLayerLoader
: public cocos2d::extension::CCLayerLoader
{
    
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(StartGameLayerLoader, loader);
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(StartGameLayer);

};

#endif /* defined(__MrDream__StartGameLayer__) */
