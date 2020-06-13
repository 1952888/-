# -

开心消消乐 项目说明文档
=======

项目信息：
------

项目选题：开心消消乐
-----

项目成员：
---------
	邵卓尔 1952888
	姚亮亮 1951018
	项目Github地址：https://github.com/1952888/-

项目开发文档：
------------
	-选用引擎：cocos2d-x 3.17.2
	-辅助软件：sourcetree，TexturePackerGUI
	-支持平台：Windows
	-小组分工：
		-邵卓尔：欢迎界面，消除算法，判断死地图，增加次数道具，排行榜，音乐，步数限制，音乐暂停，音量的大小调整
		-姚亮亮：

评分项完成度：
------------
	-游戏开始界面、背景音乐、音量控制、暂停恢复功能、退出功能
	-至少4种不同方块
	-同类方块三消及三个以上的消除，超过三个相同方块消除时产生特殊方块，特殊方块消除时产生强力效果
	-随机产生新的方块
	-方块移动动画
	-得分统计
	-关卡步数限制
	-至少两个关卡，每次进入关卡时方块随机分布
  
进阶功能：
----------------
	-本地排行榜（得分排行榜）
	-更多类型的方块（如冰块，是无法移动的）
	-奖励机制：如果游戏结束时分数达到一个程度，会奖励增加次数道具和四消道具，在下次游戏中使用
	-惩罚机制：如果移动方块后发现不能消除，步数会减少
  
其他亮点：
---------------
	-方块成功消除后会有爆炸效果和音效效果（算是很小的正反馈）
	-音效代入感强
	-在游戏场景切换时，会由场景切换效果，画面精致
  
Plist文件的使用：
--------------
	-使用TexturePackerGUI
	-将一张完整的图片通过TexturePackerGUI分割成一个个小块，同时生成每个小图片的plist文件，用来做需要触摸移动功能的
	不同方块

代码亮点：
----------
	GameDefine.h的使用
 	使用GameDefine.h保存了各种常量属性
```c	
#define GAME_SCREEN_WIDTH 480
#define GAME_SCREEN_HEIGHT 800

#define SPRITE_WIDTH 48
#define BOADER_WIDTH 2

#define ROWS 6
#define COLS 6

#define TOTAL_SPRITE 6

#include "SimpleAudioEngine.h"

static const char *spriteNormal[TOTAL_SPRITE] = {
	"icon1.png",
	"icon2.png",
	"icon3.png",
	"icon4.png",
	"icon5.png",
    "icon6.png"
};
```

	Plist文件的使用
```c
 SpriteFrameCache::getInstance()->addSpriteFramesWithFile("icon.plist");
    spriteSheet = SpriteBatchNode::create("icon.png");
    addChild(spriteSheet);
	mapLBX = (GAME_SCREEN_WIDTH - SPRITE_WIDTH * COLS - (COLS - 1) * BOADER_WIDTH) / 2;
	mapLBY = (GAME_SCREEN_HEIGHT - SPRITE_WIDTH * ROWS - (ROWS - 1) * BOADER_WIDTH) / 2;
```
	
	
	isAction和isFillsprite以及isTouch和update函数的使用是整个GameScene的核心
```c
	void GameScene::update(float t)//更新每一帧
{
	if (isAction)//如果正在动作，查看是否有其他精灵正在动作
	{
		isAction = false;
		for (int r = 0; r < ROWS; ++r)
		{
			for (int c = 0; c < COLS; ++c)
			{
				SpriteShape* spr = map[r][c];
				if (spr && spr->getNumberOfRunningActions() > 0)
				{
					isAction = true;
					break;
				}
			}
		}
	}

	// 如果精灵正在移动中，忽视触摸事件
	isTouchEna = !isAction;
	if (!isAction)//如果不在动作，查看是否需要填充精灵，如果不需要填充精灵，查看是否要移除精灵
	{
		if (isFillSprite)
		{
			fillSprite();
			isFillSprite = false;
		}
		else
		{
			checkAndRemoveSprite();
		}
		if (!checkIfDeadMap())
		{
			for (int r = 0; r < ROWS; ++r)
			{
				for (int c = 0; c < COLS; ++c)
				{
					markRemove(map[r][c]);
				}
			}
			removeSprite();
			m_score -= 1080;
		}

	}
	Label* labelScore = (Label*)this->getChildByTag(10);

	labelScore->setString(StringUtils::format("Score: %d ", m_score));
}
```
