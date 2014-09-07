LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := cocos2dcpp_shared

LOCAL_MODULE_FILENAME := libcocos2dcpp

LOCAL_SRC_FILES := hellocpp/main.cpp \
                   ../../Classes/AppDelegate.cpp \
                   ../../Classes/GameLayer.cpp \
                   ../../Classes/GameObject.cpp \
                   ../../Classes/Player.cpp \
                   ../../Classes/Background.cpp \
                   ../../Classes/Bullets.cpp \
                   ../../Classes/Ammo.cpp \
                   ../../Classes/Bomb.cpp \
                   ../../Classes/SmallEnemys.cpp \
                   ../../Classes/MiddleEnemys.cpp \
                   ../../Classes/BigEnemys.cpp \
                   ../../Classes/ModelPoint.cpp \
                   ../../Classes/ModelSize.cpp \
                   ../../Classes/GameBoardController.cpp \
                   ../../Classes/GameSceneController.cpp \
                   ../../Classes/GameBoardView.cpp \
                   ../../Classes/GameSceneView.cpp \
                   ../../Classes/PlayerView.cpp \
                   ../../Classes/BackgroundView.cpp \
                   ../../Classes/BulletsView.cpp \
                   ../../Classes/AmmoView.cpp \
                   ../../Classes/BombView.cpp \
                   ../../Classes/SmallEnemysView.cpp \
                   ../../Classes/MiddleEnemysView.cpp \
                   ../../Classes/BigEnemysView.cpp \
                   ../../Classes/GameOverView.cpp

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes

LOCAL_WHOLE_STATIC_LIBRARIES += cocos2dx_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocosdenshion_static
LOCAL_WHOLE_STATIC_LIBRARIES += box2d_static
LOCAL_WHOLE_STATIC_LIBRARIES += chipmunk_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocos_extension_static

include $(BUILD_SHARED_LIBRARY)

$(call import-module,cocos2dx)
$(call import-module,cocos2dx/platform/third_party/android/prebuilt/libcurl)
$(call import-module,CocosDenshion/android)
$(call import-module,extensions)
$(call import-module,external/Box2D)
$(call import-module,external/chipmunk)
