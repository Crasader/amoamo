# amoamo

- require
-- cocos2dx 3.2 or above

## usage

````
git submodule add git@github.com:masuhajime/amoamo.git
git submodule update --init
````

- on cocos2dx project directory
````
ln -s `pwd`/amoamo/amoamo/ Classes/amoamo
````

### iOS

- TARGETS -> <ProjectName> iOS -> Build Settings -> Search Paths -> Header Search Paths
- Add `$(SRCROOT)/../Classes` (non-recursive)
- `Add Files To "<ProjectName>"` select `amoamo/amoamo` directory into `Classes`

### Android(only google play store)

- add to jni/Android.mk
````
CPP_FILES := $(shell find $(LOCAL_PATH)/../../Classes -name *.cpp)
CPP_FILES += $(shell find $(LOCAL_PATH)/../../amoamo/amoamo -name *.cpp)
 
LOCAL_SRC_FILES := hellocpp/main.cpp
LOCAL_SRC_FILES += $(CPP_FILES:$(LOCAL_PATH)/%=%)
````

