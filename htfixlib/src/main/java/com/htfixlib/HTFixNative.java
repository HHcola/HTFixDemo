package com.htfixlib;

import java.lang.reflect.Method;

public class HTFixNative {
    private static final String TAG = "HTFixNative";
    static {
        System.loadLibrary("htfix");
    }

    public static int nativeHookMethod(Method targetMethod, Method hookMethod) {
        return htfixHookMethod(targetMethod, hookMethod);
    }

    private static native int htfixHookMethod(Method targetMethod, Method hookMethod);


    private static native void htfixNativeOne();
    private static native void htfixNativeTwo();
}
