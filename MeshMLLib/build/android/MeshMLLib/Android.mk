LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := MeshMLLib
LOCAL_SRC_FILES := ../../../lib/android_$(TARGET_ARCH_ABI)/libMeshMLLib_gcc.a
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/../../../include
LOCAL_EXPORT_LDLIBS := -llog

include $(PREBUILT_STATIC_LIBRARY)
