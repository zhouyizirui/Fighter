Fighter
=======

## Introduction

This is a repository of a famous game named "打飞机", it was extremely pervasive in Wechat platform last year. I reimplement it with MVC architecture based on Cocos2dx.

## MVC based on Cocos2dx

As we all know, MVC is popular in front-end development, since it allows the software to extend easily. However, in C++, or more precisely in Cocos2dx, MVC is not fully supported. This is because the primitive objective of Cocos2dx is to help developer build game easily, so it does not support MVC inside the engine. 

Let's recall the process in implementing a game with Cocos2dx.

1. Create a CCScene and run it.
2. Create a CCLayer as the child of CCScene.
3. Create CCSprite on the CCLayer.
4. Define CCAction for the sprites.
5. Collision detection of these sprites.

This process is easy to use when the game scale is small. But if the logics in the game become complex, simple design like this is not acceptable any more. This is because CCLayer does TOO MUCH things, it is reposible for displaying, logic control, events handling and other issues. When game becomes complicated, the codes become lenthy and UGLY! Hence, in this respository, I try to implement the game with MVC.

Let's get started!

