# amoamo

- require
 - cocos2d-x 3.2 or above

## usage

- on cocos2dx project directory

````
cd <cocos2d-x project directory>
git submodule add git@github.com:masuhajime/amoamo.git
git submodule update --init
````

````
cd <cocos2d-x project directory>
ln -s `pwd`/amoamo/amoamo/ Classes/amoamo
````

### iOS

1. `TARGETS` -> `<ProjectName> iOS` -> `Build Settings` -> `Search Paths` -> `Header Search Paths`
2. Add `$(SRCROOT)/../Classes` (non-recursive)
3. `Add Files To "<ProjectName>"` select `amoamo/amoamo` directory into `Classes`

### Android (only google play store)

- add to `proj.android/jni/Android.mk`

````
CPP_FILES := $(shell find $(LOCAL_PATH)/../../Classes -name *.cpp)
CPP_FILES += $(shell find $(LOCAL_PATH)/../../amoamo/amoamo -name *.cpp)
 
LOCAL_SRC_FILES := hellocpp/main.cpp
LOCAL_SRC_FILES += $(CPP_FILES:$(LOCAL_PATH)/%=%)
````

