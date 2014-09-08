Fighter
=======

## Introduction

This is a repository of a famous game named "打飞机", it was extremely pervasive in Wechat platform last year. I implement it with MVC architecture based on Cocos2dx.

## MVC in Cocos2dx

As we all know, MVC is popular in front-end development, since it allows the software to extend easily. However, in C++, or more precisely in Cocos2dx, MVC is not fully supported. This is because the primitive objective of Cocos2dx is to help developer build game easily, so it does not support MVC inside the engine. 

Let's recall the process in implementing a game with Cocos2dx.

1. Create a CCScene and run it.
2. Create a CCLayer as the child of CCScene.
3. Create CCSprite on the CCLayer.
4. Define CCAction for the sprites.
5. Collision detection of these sprites.

This process is easy to use when the game scale is small. But if the logics in the game become complex, simple design like this is not acceptable any more. This is because CCLayer does TOO MUCH things, it is reposible for displaying, logic control, events handling and other issues. When game becomes complicated, the codes become lengthy and UGLY! Hence, in this respository, I try to implement the game with MVC.

Let's get started!
The picture below show the MVC architecture I used in cocos2dx game.
![Example](https://github.com/zhouyizirui/Fighter/blob/master/Pictures/mvc.png)

As we can see in the picture, there are three types of elements in MVC, controller, view and model. 

1. Controller: the controller is reponsible for the game control, it acts as the key center in the game. Specifically, it handle events from View, pass them to models and control the running logic of the game.
2. View: the view is reponsible for the game displaying, it receives refreshing events from model and update the sprites or actions in the game.
3. Model: the models represent entity in the game. It receives control from controller and do corresponding actions. Also, the collision detection is implemented in models.

In this picture, the solid line means the strong connection and the dotted line means the weak connection. More precisely, in cocos2dx, the VIEW can be implemented by CCLayer, since it should receive the touch events and do the displaying.But how can it pass the touch events to CONTROLLER? In this game, I use delegate to achieve this. When the CONTROLLER initializes the VIEW and MODEL, it passes the delegate of itself to VIEW and the VIEW hence uses this delegate to pass events. The CONTROLLER has the instance pointer of VIEW and MODEL, it gets the status of both models and views and decide what to do. You may ask, then how can we build connection between MODEL and VIEW, since the VIEW should update the displaying when MODEL changes. I use CCNotificationCenter to achieve this. CCNotificationCenter and post notifications from the MODEL to the VIEW, it works efficiently.

## For ios users

1. Open proj.ios
2. Double click the .xcodeproj
3. Run the project in Xcode
4. That's it

## For Android usrs

1. Open proj.android
2. Follow the steps in README step by step
3. Get it work

## Fighter test
#### Testing Environment
	* HTC Incredible S(G11)
	* Android 4.0.4
	* Resolution 480*800

#### Play it
![Example](https://github.com/zhouyizirui/Fighter/blob/master/Pictures/begin.png)

This scene includes "开始游戏" and "退出游戏", of course we should press the former one~

#### In the scene
![Example](https://github.com/zhouyizirui/Fighter/blob/master/Pictures/score.png)

In this play scene, when we crash one small enemy, we hear "boom" and get 1000 scores~

#### Hit the big enemy
![Example](https://github.com/zhouyizirui/Fighter/blob/master/Pictures/hit.png)

When we hit the big enemy, it does not crash immediately. But after hitten by enough bullets, it crashes, just the same as Weixin.

#### Get the bomb
![Example](https://github.com/zhouyizirui/Fighter/blob/master/Pictures/bomb.png)

When we get a bomb, it appears on the left bottom of the scene. If we hit it, all the enemys in the scene will crash. :)

##### Game over

![Example](https://github.com/zhouyizirui/Fighter/blob/master/Pictures/over.png)

We got double laser in the game, which significantly boost our fire. But unfortunately, we are hitten by an enemy. Game over, good luck the next time.

That's all, enjoy it~
## References

1. [Cocos2d中的MVC实现](http://xperienced.com.pl/blog/how-to-implement-mvc-pattern-in-cocos2d-game)
2. [王选易的MVC实现](http://www.cnblogs.com/neverdie/p/3754931.html)
