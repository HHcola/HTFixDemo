#include "native_on_load.h"
#include "base.h"

static bool isArt = true;
extern "C" OPEN_API void HTFixNative_htfixNativeOne(JNI_START) {}

extern "C" OPEN_API void HTFixNative_htfixNativeTwo(JNI_START) {}



static jint
HTFixNative_htfixHookMethod(JNI_START, jobject method_target, jobject method_hook) {
    if (isArt) {
        void* target = reinterpret_cast<void *>(env->FromReflectedMethod(method_target));
        void*  hook = reinterpret_cast<void *>(env->FromReflectedMethod(method_hook));
        LOGD("target = %p, hook = &p", target, hook);
        return 1;
    } else {
        return -1;
    }
}


static JNINativeMethod gMethods[] = {
        NATIVE_METHOD(HTFixNative, htfixHookMethod,
                      "(Ljava/lang/reflect/Method;Ljava/lang/reflect/Method;)I"),
        NATIVE_METHOD(HTFixNative, htfixNativeOne, "()V"),
        NATIVE_METHOD(HTFixNative, htfixNativeTwo, "()V")
};

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void *reserved) {
    LOGE("JNI_OnLoad");
    JNIEnv *env = nullptr;
    if (vm->GetEnv(reinterpret_cast<void **>(&env), JNI_VERSION_1_4) != JNI_OK) {
        return -1;
    }
    jclass cl = env->FindClass(CLASS_NAME);
    if (cl == nullptr) {
        LOGE("FindClass failed for %s",CLASS_NAME);
        return JNI_ERR;
    }
    if (env->RegisterNatives(cl, gMethods, NELEM(gMethods)) < 0) {
        LOGE("RegisterNatives failed for %s",CLASS_NAME);
        return JNI_ERR;
    }
    return JNI_VERSION_1_4;
}


JNIEXPORT void JNICALL JNI_OnUnload(JavaVM *vm, void *reserved) {
    JNIEnv *env = nullptr;
    jint ret = vm->GetEnv(reinterpret_cast<void **>(&env), JNI_VERSION_1_4);
    if (ret != JNI_OK) {
        return ;
    }
}