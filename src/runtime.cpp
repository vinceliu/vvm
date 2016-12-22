#include <stdio.h>

#include "prims/jvm.h"
#include "jemalloc/jemalloc.h"

#include "runtime.h"

int main(UNUSED int argc, UNUSED char **argv) {
    printf("Hello %p\n", je_malloc(1000));
    return 0;
}

JNIEXPORT jobjectArray JNICALL
JVM_GetMethodParameters(UNUSED JNIEnv *env, UNUSED jobject method) {
    return NULL;
}

JNIEXPORT jint JNICALL
JVM_GetInterfaceVersion() {
    return 0;
}

/*************************************************************************
 PART 1: Functions for Native Libraries
 ************************************************************************/
/*
 * java.lang.Object
 */
JNIEXPORT jint JNICALL
JVM_IHashCode(UNUSED JNIEnv *env, UNUSED jobject obj) {
    return 0;
}

JNIEXPORT void JNICALL
JVM_MonitorWait(UNUSED JNIEnv *env, UNUSED jobject obj, UNUSED UNUSED jlong ms) {
}

JNIEXPORT void JNICALL
JVM_MonitorNotify(UNUSED JNIEnv *env, UNUSED jobject obj) {
}

JNIEXPORT void JNICALL
JVM_MonitorNotifyAll(UNUSED JNIEnv *env, UNUSED jobject obj) {
}

JNIEXPORT jobject JNICALL
JVM_Clone(UNUSED JNIEnv *env, UNUSED jobject obj) {
    return NULL;
}

/*
 * java.lang.String
 */
JNIEXPORT jstring JNICALL
JVM_InternString(UNUSED JNIEnv *env, UNUSED jstring str) {
    return NULL;
}

/*
 * java.lang.System
 */
JNIEXPORT jlong JNICALL
JVM_CurrentTimeMillis(UNUSED JNIEnv *env, UNUSED jclass ignored) {
    return 0L;
}

JNIEXPORT jlong JNICALL
JVM_NanoTime(UNUSED JNIEnv *env,UNUSED jclass ignored) {
    return 0L;
}

JNIEXPORT jlong JNICALL
JVM_GetNanoTimeAdjustment(UNUSED JNIEnv *env, UNUSED jclass ignored, UNUSED UNUSED jlong offset_secs) {
    return 0L;
}

JNIEXPORT void JNICALL
JVM_ArrayCopy(UNUSED JNIEnv *env, UNUSED jclass ignored, UNUSED UNUSED jobject src, UNUSED UNUSED jint src_pos,
              UNUSED jobject dst, UNUSED UNUSED jint dst_pos, UNUSED UNUSED jint length) {
}

JNIEXPORT jobject JNICALL
JVM_InitProperties(UNUSED JNIEnv *env, UNUSED jobject p) {
    return NULL;
}

/*
 * java.lang.Runtime
 */

JNIEXPORT void JNICALL
JVM_Halt(UNUSED jint code) {
}

JNIEXPORT void JNICALL
JVM_GC(void) {
}

/* Returns the number of real-time milliseconds that have elapsed since the
 * least-recently-inspected heap object was last inspected by the garbage
 * collector.
 *
 * For simple stop-the-world collectors this value is just the time
 * since the most recent collection.  For generational collectors it is the
 * time since the oldest generation was most recently collected.  Other
 * collectors are free to return a pessimistic estimate of the elapsed time, or
 * simply the time since the last full collection was performed.
 *
 * Note that in the presence of reference objects, a given object that is no
 * longer strongly reachable may have to be inspected multiple times before it
 * can be reclaimed.
 */
JNIEXPORT jlong JNICALL
JVM_MaxObjectInspectionAge(void) {
    return 0L;
}

JNIEXPORT jlong JNICALL
JVM_TotalMemory(void) {
    return 0L;
}

JNIEXPORT jlong JNICALL
JVM_FreeMemory(void) {
    return 0L;
}

JNIEXPORT jlong JNICALL
JVM_MaxMemory(void) {
    return 0L;
}

JNIEXPORT jint JNICALL
JVM_ActiveProcessorCount(void) {
    return 0;
}

JNIEXPORT void * JNICALL
JVM_LoadLibrary(UNUSED const char *name) {
    return NULL;
}

JNIEXPORT void JNICALL
JVM_UnloadLibrary(UNUSED void *handle) {
}

JNIEXPORT void * JNICALL
JVM_FindLibraryEntry(UNUSED void *handle, UNUSED const char *name) {
    return NULL;
}

JNIEXPORT jboolean JNICALL
JVM_IsSupportedJNIVersion(UNUSED jint version) {
    return JNI_FALSE;
}

JNIEXPORT jobjectArray JNICALL
JVM_GetVmArguments(UNUSED JNIEnv *env) {
    return NULL;
}

/*
 * java.lang.Throwable
 */
JNIEXPORT void JNICALL
JVM_FillInStackTrace(UNUSED JNIEnv *env, UNUSED jobject throwable) {
}

/*
 * java.lang.StackTraceElement
 */
JNIEXPORT void JNICALL
JVM_InitStackTraceElementArray(UNUSED JNIEnv *env, UNUSED jobjectArray elements, UNUSED jobject throwable) {
}

JNIEXPORT void JNICALL
JVM_InitStackTraceElement(UNUSED JNIEnv *env, UNUSED jobject element, UNUSED jobject stackFrameInfo) {
}

JNIEXPORT jobject JNICALL
JVM_CallStackWalk(UNUSED JNIEnv *env, UNUSED jobject stackStream, UNUSED jlong mode,
                  UNUSED jint skip_frames, UNUSED jint frame_count, UNUSED jint start_index,
                  UNUSED jobjectArray frames) {
    return NULL;
}

JNIEXPORT jint JNICALL
JVM_MoreStackWalk(UNUSED JNIEnv *env, UNUSED jobject stackStream, UNUSED jlong mode, UNUSED jlong anchor,
                  UNUSED jint frame_count, UNUSED jint start_index,
                  UNUSED jobjectArray frames) {
    return 0;
}

/*
 * java.lang.Thread
 */
JNIEXPORT void JNICALL
JVM_StartThread(UNUSED JNIEnv *env, UNUSED jobject thread) {
}

JNIEXPORT void JNICALL
JVM_StopThread(UNUSED JNIEnv *env, UNUSED jobject thread, UNUSED jobject exception) {
}

JNIEXPORT jboolean JNICALL
JVM_IsThreadAlive(UNUSED JNIEnv *env, UNUSED jobject thread) {
    return JNI_FALSE;
}

JNIEXPORT void JNICALL
JVM_SuspendThread(UNUSED JNIEnv *env, UNUSED jobject thread) {
}

JNIEXPORT void JNICALL
JVM_ResumeThread(UNUSED JNIEnv *env, UNUSED jobject thread) {
}

JNIEXPORT void JNICALL
JVM_SetThreadPriority(UNUSED JNIEnv *env, UNUSED jobject thread, UNUSED jint prio);

JNIEXPORT void JNICALL
JVM_Yield(UNUSED JNIEnv *env, UNUSED jclass threadClass) {
}

JNIEXPORT void JNICALL
JVM_Sleep(UNUSED JNIEnv *env, UNUSED jclass threadClass, UNUSED jlong millis) {
}

JNIEXPORT jobject JNICALL
JVM_CurrentThread(UNUSED JNIEnv *env, UNUSED jclass threadClass) {
    return NULL;
}

JNIEXPORT jint JNICALL
JVM_CountStackFrames(UNUSED JNIEnv *env, UNUSED jobject thread) {
    return 0;
}

JNIEXPORT void JNICALL
JVM_Interrupt(UNUSED JNIEnv *env, UNUSED jobject thread) {
}

JNIEXPORT jboolean JNICALL
JVM_IsInterrupted(UNUSED JNIEnv *env, UNUSED jobject thread, UNUSED jboolean clearInterrupted) {
    return JNI_FALSE;
}

JNIEXPORT jboolean JNICALL
JVM_HoldsLock(UNUSED JNIEnv *env, UNUSED jclass threadClass, UNUSED jobject obj) {
    return JNI_FALSE;
}

JNIEXPORT void JNICALL
JVM_DumpAllStacks(UNUSED JNIEnv *env, UNUSED jclass unused) {
}

JNIEXPORT jobjectArray JNICALL
JVM_GetAllThreads(UNUSED JNIEnv *env, UNUSED jclass dummy) {
    return NULL;
}

JNIEXPORT void JNICALL
JVM_SetNativeThreadName(UNUSED JNIEnv *env, UNUSED jobject jthread, UNUSED jstring name) {
}

/* getStackTrace() and getAllStackTraces() method */
JNIEXPORT jobjectArray JNICALL
JVM_DumpThreads(UNUSED JNIEnv *env, UNUSED jclass threadClass, UNUSED jobjectArray threads) {
    return NULL;
}

/*
 * java.lang.SecurityManager
 */
JNIEXPORT jclass JNICALL
JVM_CurrentLoadedClass(UNUSED JNIEnv *env) {
    return NULL;
}

JNIEXPORT jobject JNICALL
JVM_CurrentClassLoader(UNUSED JNIEnv *env) {
    return NULL;
}

JNIEXPORT jobjectArray JNICALL
JVM_GetClassContext(UNUSED JNIEnv *env) {
    return NULL;
}

JNIEXPORT jint JNICALL
JVM_ClassDepth(UNUSED JNIEnv *env, UNUSED jstring name) {
    return 0;
}

JNIEXPORT jint JNICALL
JVM_ClassLoaderDepth(UNUSED JNIEnv *env) {
    return 0;
}

/*
 * java.lang.Package
 */
JNIEXPORT jstring JNICALL
JVM_GetSystemPackage(UNUSED JNIEnv *env, UNUSED jstring name);

JNIEXPORT jobjectArray JNICALL
JVM_GetSystemPackages(UNUSED JNIEnv *env) {
    return NULL;
}

/*
 * java.lang.ref.Reference
 */
JNIEXPORT jobject JNICALL
JVM_GetAndClearReferencePendingList(UNUSED JNIEnv *env) {
    return NULL;
}

JNIEXPORT jboolean JNICALL
JVM_HasReferencePendingList(UNUSED JNIEnv *env) {
    return JNI_FALSE;
}

JNIEXPORT void JNICALL
JVM_WaitForReferencePendingList(UNUSED JNIEnv *env) {
}

/*
 * java.io.ObjectInputStream
 */
JNIEXPORT jobject JNICALL
JVM_LatestUserDefinedLoader(UNUSED JNIEnv *env) {
    return NULL;
}

/*
 * java.lang.reflect.Array
 */
JNIEXPORT jint JNICALL
JVM_GetArrayLength(UNUSED JNIEnv *env, UNUSED jobject arr) {
    return 0;
}

JNIEXPORT jobject JNICALL
JVM_GetArrayElement(UNUSED JNIEnv *env, UNUSED jobject arr, UNUSED jint index) {
    return NULL;
}

JNIEXPORT jvalue JNICALL
JVM_GetPrimitiveArrayElement(UNUSED JNIEnv *env, UNUSED jobject arr, UNUSED jint index, UNUSED jint wCode);

JNIEXPORT void JNICALL
JVM_SetArrayElement(UNUSED JNIEnv *env, UNUSED jobject arr, UNUSED jint index, UNUSED jobject val) {
}

JNIEXPORT void JNICALL
JVM_SetPrimitiveArrayElement(UNUSED JNIEnv *env, UNUSED jobject arr, UNUSED jint index, UNUSED jvalue v,
                             UNUSED unsigned char vCode) {
}

JNIEXPORT jobject JNICALL
JVM_NewArray(UNUSED JNIEnv *env, UNUSED jclass eltClass, UNUSED jint length) {
    return NULL;
}

JNIEXPORT jobject JNICALL
JVM_NewMultiArray(UNUSED JNIEnv *env, UNUSED jclass eltClass, UNUSED jintArray dim) {
    return NULL;
}

/*
 * java.lang.Class and java.lang.ClassLoader
 */

#define JVM_CALLER_DEPTH -1

/*
 * Returns the class in which the code invoking the native method
 * belongs.
 *
 * Note that in JDK 1.1, native methods did not create a frame.
 * In 1.2, they do. Therefore native methods like Class.forName
 * can no longer look at the current frame for the caller class.
 */
JNIEXPORT jclass JNICALL
JVM_GetCallerClass(UNUSED JNIEnv *env, UNUSED int n) {
    return NULL;
}

/*
 * Find primitive classes
 * utf: class name
 */
JNIEXPORT jclass JNICALL
JVM_FindPrimitiveClass(UNUSED JNIEnv *env, UNUSED const char *utf) {
    return NULL;
}

/*
 * Find a class from a boot class loader. Returns NULL if class not found.
 */
JNIEXPORT jclass JNICALL
JVM_FindClassFromBootLoader(UNUSED JNIEnv *env, UNUSED const char *name) {
    return NULL;
}

/*
 * Find a class from a given class loader.  Throws ClassNotFoundException.
 *  name:   name of class
 *  init:   whether initialization is done
 *  loader: class loader to look up the class. This may not be the same as the caller's
 *          class loader.
 *  caller: initiating class. The initiating class may be null when a security
 *          manager is not installed.
 */
JNIEXPORT jclass JNICALL
JVM_FindClassFromCaller(UNUSED JNIEnv *env, UNUSED const char *name, UNUSED jboolean init,
                        UNUSED jobject loader, UNUSED jclass caller) {
    return NULL;
}

/*
 * Find a class from a given class.
 */
JNIEXPORT jclass JNICALL
JVM_FindClassFromClass(UNUSED JNIEnv *env, UNUSED const char *name, UNUSED jboolean init,
                             UNUSED jclass from) {
    return NULL;
}

/* Find a loaded class cached by the VM */
JNIEXPORT jclass JNICALL
JVM_FindLoadedClass(UNUSED JNIEnv *env, UNUSED jobject loader, UNUSED jstring name) {
    return NULL;
}

/* Define a class */
JNIEXPORT jclass JNICALL
JVM_DefineClass(UNUSED JNIEnv *env, UNUSED const char *name, UNUSED jobject loader, UNUSED const jbyte *buf,
                UNUSED jsize len, UNUSED jobject pd) {

    return NULL;
}
/* Define a class with a source (added in JDK1.5) */
JNIEXPORT jclass JNICALL
JVM_DefineClassWithSource(UNUSED JNIEnv *env, UNUSED const char *name, UNUSED jobject loader,
                          UNUSED const jbyte *buf, UNUSED jsize len, UNUSED jobject pd,
                          UNUSED const char *source) {
    return NULL;
}

/*
 * Module support funcions
 */

JNIEXPORT void JNICALL
JVM_DefineModule(UNUSED JNIEnv *env, UNUSED jobject module, UNUSED jboolean is_open, UNUSED jstring version,
                 UNUSED jstring location, UNUSED jobjectArray packages) {
}

JNIEXPORT void JNICALL
JVM_SetBootLoaderUnnamedModule(UNUSED JNIEnv *env, UNUSED jobject module) {
}

JNIEXPORT void JNICALL
JVM_AddModuleExports(UNUSED JNIEnv *env, UNUSED jobject from_module, UNUSED jstring package, UNUSED jobject to_module) {
}

JNIEXPORT void JNICALL
JVM_AddModuleExportsToAllUnnamed(UNUSED JNIEnv *env, UNUSED jobject from_module, UNUSED jstring package) {
}

JNIEXPORT void JNICALL
JVM_AddModuleExportsToAll(UNUSED JNIEnv *env, UNUSED jobject from_module, UNUSED jstring package) {
}

JNIEXPORT void JNICALL
JVM_AddReadsModule(UNUSED JNIEnv *env, UNUSED jobject from_module, UNUSED jobject source_module) {
}

JNIEXPORT void JNICALL
JVM_AddModulePackage(UNUSED JNIEnv *env,  UNUSED jobject module, UNUSED jstring package) {
}

JNIEXPORT jobject JNICALL
JVM_GetModuleByPackageName(UNUSED JNIEnv *env, UNUSED jobject loader, UNUSED jstring package) {
    return NULL;
}

/*
 * Reflection support functions
 */

JNIEXPORT jstring JNICALL
JVM_GetClassName(UNUSED JNIEnv *env, UNUSED jclass cls) {
    return NULL;
}

JNIEXPORT jobjectArray JNICALL
JVM_GetClassInterfaces(UNUSED JNIEnv *env, UNUSED jclass cls) {
    return NULL;
}

JNIEXPORT jboolean JNICALL
JVM_IsInterface(UNUSED JNIEnv *env, UNUSED jclass cls) {
    return JNI_FALSE;
}

JNIEXPORT jobjectArray JNICALL
JVM_GetClassSigners(UNUSED JNIEnv *env, UNUSED jclass cls) {
    return NULL;
}

JNIEXPORT void JNICALL
JVM_SetClassSigners(UNUSED JNIEnv *env, UNUSED jclass cls, UNUSED jobjectArray signers) {
}

JNIEXPORT jobject JNICALL
JVM_GetProtectionDomain(UNUSED JNIEnv *env, UNUSED jclass cls) {
    return NULL;
}

JNIEXPORT jboolean JNICALL
JVM_IsArrayClass(UNUSED JNIEnv *env, UNUSED jclass cls) {
    return JNI_FALSE;
}

JNIEXPORT jboolean JNICALL
JVM_IsPrimitiveClass(UNUSED JNIEnv *env, UNUSED jclass cls) {
    return JNI_FALSE;
}

JNIEXPORT jint JNICALL
JVM_GetClassModifiers(UNUSED JNIEnv *env, UNUSED jclass cls) {
    return 0;
}

JNIEXPORT jobjectArray JNICALL
JVM_GetDeclaredClasses(UNUSED JNIEnv *env, UNUSED jclass ofClass) {
    return NULL;
}

JNIEXPORT jclass JNICALL
JVM_GetDeclaringClass(UNUSED JNIEnv *env, UNUSED jclass ofClass) {
    return NULL;
}

JNIEXPORT jstring JNICALL
JVM_GetSimpleBinaryName(UNUSED JNIEnv *env, UNUSED jclass ofClass) {
    return NULL;
}

/* Generics support (JDK 1.5) */
JNIEXPORT jstring JNICALL
JVM_GetClassSignature(UNUSED JNIEnv *env, UNUSED jclass cls) {
    return NULL;
}

/* Annotations support (JDK 1.5) */
JNIEXPORT jbyteArray JNICALL
JVM_GetClassAnnotations(UNUSED JNIEnv *env, UNUSED jclass cls) {
    return NULL;
}

/* Annotations support (JDK 1.6) */

/* Type use annotations support (JDK 1.8) */

JNIEXPORT jbyteArray JNICALL
JVM_GetClassTypeAnnotations(UNUSED JNIEnv *env, UNUSED jclass cls) {
    return NULL;
}

// field is a handle to a java.lang.reflect.Field object
JNIEXPORT jbyteArray JNICALL
JVM_GetFieldTypeAnnotations(UNUSED JNIEnv *env, UNUSED jobject field) {
    return NULL;
}

// method is a handle to a java.lang.reflect.Method object
JNIEXPORT jbyteArray JNICALL
JVM_GetMethodTypeAnnotations(UNUSED JNIEnv *env, UNUSED jobject method) {
    return NULL;
}

/*
 * New (JDK 1.4) reflection implementation
 */

JNIEXPORT jobjectArray JNICALL
JVM_GetClassDeclaredMethods(UNUSED JNIEnv *env, UNUSED jclass ofClass, UNUSED jboolean publicOnly) {
    return NULL;
}

JNIEXPORT jobjectArray JNICALL
JVM_GetClassDeclaredFields(UNUSED JNIEnv *env, UNUSED jclass ofClass, UNUSED jboolean publicOnly) {
    return NULL;
}

JNIEXPORT jobjectArray JNICALL
JVM_GetClassDeclaredConstructors(UNUSED JNIEnv *env, UNUSED jclass ofClass, UNUSED jboolean publicOnly) {
    return NULL;
}

/* Differs from JVM_GetClassModifiers in treatment of inner classes.
   This returns the access flags for the class as specified in the
   class file rather than searching the InnerClasses attribute (if
   present) to find the source-level access flags. Only the values of
   the low 13 bits (i.e., a mask of 0x1FFF) are guaranteed to be
   valid. */
JNIEXPORT jint JNICALL
JVM_GetClassAccessFlags(UNUSED JNIEnv *env, UNUSED jclass cls) {
    return 0;
}

/*
 * Constant pool access; currently used to implement reflective access to annotations (JDK 1.5)
 */

JNIEXPORT jobject JNICALL
JVM_GetClassConstantPool(UNUSED JNIEnv *env, UNUSED jclass cls) {
    return NULL;
}

JNIEXPORT jint JNICALL JVM_ConstantPoolGetSize
(UNUSED JNIEnv *env, UNUSED jobject obj, UNUSED jobject unused) {
    return 0;
}

JNIEXPORT jclass JNICALL JVM_ConstantPoolGetClassAt
(UNUSED JNIEnv *env, UNUSED jobject obj, UNUSED jobject unused, UNUSED jint index) {
    return NULL;
}

JNIEXPORT jclass JNICALL JVM_ConstantPoolGetClassAtIfLoaded
(UNUSED JNIEnv *env, UNUSED jobject obj, UNUSED jobject unused, UNUSED jint index) {
    return NULL;
}

JNIEXPORT jobject JNICALL JVM_ConstantPoolGetMethodAt
(UNUSED JNIEnv *env, UNUSED jobject obj, UNUSED jobject unused, UNUSED jint index) {
    return NULL;
}

JNIEXPORT jobject JNICALL JVM_ConstantPoolGetMethodAtIfLoaded
(UNUSED JNIEnv *env, UNUSED jobject obj, UNUSED jobject unused, UNUSED jint index) {
    return NULL;
}

JNIEXPORT jobject JNICALL JVM_ConstantPoolGetFieldAt
(UNUSED JNIEnv *env, UNUSED jobject obj, UNUSED jobject unused, UNUSED jint index) {
    return NULL;
}

JNIEXPORT jobject JNICALL JVM_ConstantPoolGetFieldAtIfLoaded
(UNUSED JNIEnv *env, UNUSED jobject obj, UNUSED jobject unused, UNUSED jint index) {
    return NULL;
}

JNIEXPORT jobjectArray JNICALL JVM_ConstantPoolGetMemberRefInfoAt
(UNUSED JNIEnv *env, UNUSED jobject obj, UNUSED jobject unused, UNUSED jint index) {
    return NULL;
}

JNIEXPORT jobjectArray JNICALL JVM_ConstantPoolGetNameAndTypeRefInfoAt
(UNUSED JNIEnv *env, UNUSED jobject obj, UNUSED jobject unused, UNUSED jint index) {
    return NULL;
}

JNIEXPORT jint JNICALL JVM_ConstantPoolGetNameAndTypeRefIndexAt
(UNUSED JNIEnv *env, UNUSED jobject obj, UNUSED jobject unused, UNUSED jint index) {
    return 0;
}

JNIEXPORT jint JNICALL JVM_ConstantPoolGetClassRefIndexAt
(UNUSED JNIEnv *env, UNUSED jobject obj, UNUSED jobject unused, UNUSED jint index) {
    return 0;
}

JNIEXPORT jint JNICALL JVM_ConstantPoolGetIntAt
(UNUSED JNIEnv *env, UNUSED jobject obj, UNUSED jobject unused, UNUSED jint index) {
    return 0;
}

JNIEXPORT jlong JNICALL JVM_ConstantPoolGetLongAt
(UNUSED JNIEnv *env, UNUSED jobject obj, UNUSED jobject unused, UNUSED jint index) {
    return 0L;
}

JNIEXPORT jfloat JNICALL JVM_ConstantPoolGetFloatAt
(UNUSED JNIEnv *env, UNUSED jobject obj, UNUSED jobject unused, UNUSED jint index) {
    return 0;
}

JNIEXPORT jdouble JNICALL JVM_ConstantPoolGetDoubleAt
(UNUSED JNIEnv *env, UNUSED jobject obj, UNUSED jobject unused, UNUSED jint index) {
    return 0;
}

JNIEXPORT jstring JNICALL JVM_ConstantPoolGetStringAt
(UNUSED JNIEnv *env, UNUSED jobject obj, UNUSED jobject unused, UNUSED jint index) {
    return NULL;
}

JNIEXPORT jstring JNICALL JVM_ConstantPoolGetUTF8At
(UNUSED JNIEnv *env, UNUSED jobject obj, UNUSED jobject unused, UNUSED jint index) {
    return NULL;
}

JNIEXPORT jbyte JNICALL JVM_ConstantPoolGetTagAt
(UNUSED JNIEnv *env, UNUSED jobject unused, UNUSED jobject jcpool, UNUSED jint index) {
    return 0;
}

/*
 * java.security.*
 */

JNIEXPORT jobject JNICALL
JVM_DoPrivileged(UNUSED JNIEnv *env, UNUSED jclass cls,
                 UNUSED jobject action, UNUSED jobject context, UNUSED jboolean wrapException) {
    return NULL;
}

JNIEXPORT jobject JNICALL
JVM_GetInheritedAccessControlContext(UNUSED JNIEnv *env, UNUSED jclass cls) {
    return NULL;
}

JNIEXPORT jobject JNICALL
JVM_GetStackAccessControlContext(UNUSED JNIEnv *env, UNUSED jclass cls) {
    return NULL;
}

/*
 * Signal support, used to implement the shutdown sequence.  Every VM must
 * support JVM_SIGINT and JVM_SIGTERM, raising the former for user interrupts
 * (^C) and the latter for external termination (kill, system shutdown, etc.).
 * Other platform-dependent signal values may also be supported.
 */

JNIEXPORT void * JNICALL
JVM_RegisterSignal(UNUSED jint sig, UNUSED void *handler) {
    return NULL;
}

JNIEXPORT jboolean JNICALL
JVM_RaiseSignal(UNUSED jint sig) {
    return JNI_FALSE;
}

JNIEXPORT jint JNICALL
JVM_FindSignal(UNUSED const char *name) {
    return 0;
}

/*
 * Retrieve the assertion directives for the specified class.
 */
JNIEXPORT jboolean JNICALL
JVM_DesiredAssertionStatus(UNUSED JNIEnv *env, UNUSED jclass unused, UNUSED jclass cls) {
    return JNI_FALSE;
}

/*
 * Retrieve the assertion directives from the VM.
 */
JNIEXPORT jobject JNICALL
JVM_AssertionStatusDirectives(UNUSED JNIEnv *env, UNUSED jclass unused) {
    return NULL;
}

/*
 * java.util.concurrent.atomic.AtomicLong
 */
JNIEXPORT jboolean JNICALL
JVM_SupportsCX8(void) {
    return JNI_FALSE;
}

/*************************************************************************
 PART 2: Support for the Verifier and Class File Format Checker
 ************************************************************************/
/*
 * Return the class name in UTF format. The result is valid
 * until JVM_ReleaseUTf is called.
 *
 * The caller must treat the string as a constant and not modify it
 * in any way.
 */
JNIEXPORT const char * JNICALL
JVM_GetClassNameUTF(UNUSED JNIEnv *env, UNUSED jclass cb) {
    return NULL;
}

/*
 * Returns the constant pool types in the buffer provided by "types."
 */
JNIEXPORT void JNICALL
JVM_GetClassCPTypes(UNUSED JNIEnv *env, UNUSED jclass cb, UNUSED unsigned char *types) {
}

/*
 * Returns the number of Constant Pool entries.
 */
JNIEXPORT jint JNICALL
JVM_GetClassCPEntriesCount(UNUSED JNIEnv *env, UNUSED jclass cb) {
    return 0;
}

/*
 * Returns the number of *declared* fields or methods.
 */
JNIEXPORT jint JNICALL
JVM_GetClassFieldsCount(UNUSED JNIEnv *env, UNUSED jclass cb) {
    return 0;
}

JNIEXPORT jint JNICALL
JVM_GetClassMethodsCount(UNUSED JNIEnv *env, UNUSED jclass cb) {
    return 0;
}

/*
 * Returns the CP indexes of exceptions raised by a given method.
 * Places the result in the given buffer.
 *
 * The method is identified by method_index.
 */
JNIEXPORT void JNICALL
JVM_GetMethodIxExceptionIndexes(UNUSED JNIEnv *env, UNUSED jclass cb, UNUSED jint method_index,
                                UNUSED unsigned short *exceptions) {
}
/*
 * Returns the number of exceptions raised by a given method.
 * The method is identified by method_index.
 */
JNIEXPORT jint JNICALL
JVM_GetMethodIxExceptionsCount(UNUSED JNIEnv *env, UNUSED jclass cb, UNUSED jint method_index) {
    return 0;
}

/*
 * Returns the byte code sequence of a given method.
 * Places the result in the given buffer.
 *
 * The method is identified by method_index.
 */
JNIEXPORT void JNICALL
JVM_GetMethodIxByteCode(UNUSED JNIEnv *env, UNUSED jclass cb, UNUSED jint method_index,
                        UNUSED unsigned char *code) {
}

/*
 * Returns the length of the byte code sequence of a given method.
 * The method is identified by method_index.
 */
JNIEXPORT jint JNICALL
JVM_GetMethodIxByteCodeLength(UNUSED JNIEnv *env, UNUSED jclass cb, UNUSED jint method_index) {
    return 0;
}

/*
 * Returns the exception table entry at entry_index of a given method.
 * Places the result in the given buffer.
 *
 * The method is identified by method_index.
 */
JNIEXPORT void JNICALL
JVM_GetMethodIxExceptionTableEntry(UNUSED JNIEnv *env, UNUSED jclass cb, UNUSED jint method_index,
                                   UNUSED jint entry_index,
                                   UNUSED JVM_ExceptionTableEntryType *entry) {
}

/*
 * Returns the length of the exception table of a given method.
 * The method is identified by method_index.
 */
JNIEXPORT jint JNICALL
JVM_GetMethodIxExceptionTableLength(UNUSED JNIEnv *env, UNUSED jclass cb, UNUSED int index) {
    return 0;
}

/*
 * Returns the modifiers of a given field.
 * The field is identified by field_index.
 */
JNIEXPORT jint JNICALL
JVM_GetFieldIxModifiers(UNUSED JNIEnv *env, UNUSED jclass cb, UNUSED int index) {
    return 0;
}

/*
 * Returns the modifiers of a given method.
 * The method is identified by method_index.
 */
JNIEXPORT jint JNICALL
JVM_GetMethodIxModifiers(UNUSED JNIEnv *env, UNUSED jclass cb, UNUSED int index) {
    return 0;
}

/*
 * Returns the number of local variables of a given method.
 * The method is identified by method_index.
 */
JNIEXPORT jint JNICALL
JVM_GetMethodIxLocalsCount(UNUSED JNIEnv *env, UNUSED jclass cb, UNUSED int index) {
    return 0;
}

/*
 * Returns the number of arguments (including this pointer) of a given method.
 * The method is identified by method_index.
 */
JNIEXPORT jint JNICALL
JVM_GetMethodIxArgsSize(UNUSED JNIEnv *env, UNUSED jclass cb, UNUSED int index) {
    return 0;
}

/*
 * Returns the maximum amount of stack (in words) used by a given method.
 * The method is identified by method_index.
 */
JNIEXPORT jint JNICALL
JVM_GetMethodIxMaxStack(UNUSED JNIEnv *env, UNUSED jclass cb, UNUSED int index) {
    return 0;
}

/*
 * Is a given method a constructor.
 * The method is identified by method_index.
 */
JNIEXPORT jboolean JNICALL
JVM_IsConstructorIx(UNUSED JNIEnv *env, UNUSED jclass cb, UNUSED int index) {
    return JNI_FALSE;
}

/*
 * Is the given method generated by the VM.
 * The method is identified by method_index.
 */
JNIEXPORT jboolean JNICALL
JVM_IsVMGeneratedMethodIx(UNUSED JNIEnv *env, UNUSED jclass cb, UNUSED int index);

/*
 * Returns the name of a given method in UTF format.
 * The result remains valid until JVM_ReleaseUTF is called.
 *
 * The caller must treat the string as a constant and not modify it
 * in any way.
 */
JNIEXPORT const char * JNICALL
JVM_GetMethodIxNameUTF(UNUSED JNIEnv *env, UNUSED jclass cb, UNUSED jint index) {
    return NULL;
}

/*
 * Returns the signature of a given method in UTF format.
 * The result remains valid until JVM_ReleaseUTF is called.
 *
 * The caller must treat the string as a constant and not modify it
 * in any way.
 */
JNIEXPORT const char * JNICALL
JVM_GetMethodIxSignatureUTF(UNUSED JNIEnv *env, UNUSED jclass cb, UNUSED jint index) {
    return NULL;
}

/*
 * Returns the name of the field refered to at a given constant pool
 * index.
 *
 * The result is in UTF format and remains valid until JVM_ReleaseUTF
 * is called.
 *
 * The caller must treat the string as a constant and not modify it
 * in any way.
 */
JNIEXPORT const char * JNICALL
JVM_GetCPFieldNameUTF(UNUSED JNIEnv *env, UNUSED jclass cb, UNUSED jint index) {
    return NULL;
}

/*
 * Returns the name of the method refered to at a given constant pool
 * index.
 *
 * The result is in UTF format and remains valid until JVM_ReleaseUTF
 * is called.
 *
 * The caller must treat the string as a constant and not modify it
 * in any way.
 */
JNIEXPORT const char * JNICALL
JVM_GetCPMethodNameUTF(UNUSED JNIEnv *env, UNUSED jclass cb, UNUSED jint index) {
    return NULL;
}

/*
 * Returns the signature of the method refered to at a given constant pool
 * index.
 *
 * The result is in UTF format and remains valid until JVM_ReleaseUTF
 * is called.
 *
 * The caller must treat the string as a constant and not modify it
 * in any way.
 */
JNIEXPORT const char * JNICALL
JVM_GetCPMethodSignatureUTF(UNUSED JNIEnv *env, UNUSED jclass cb, UNUSED jint index) {
    return NULL;
}

/*
 * Returns the signature of the field refered to at a given constant pool
 * index.
 *
 * The result is in UTF format and remains valid until JVM_ReleaseUTF
 * is called.
 *
 * The caller must treat the string as a constant and not modify it
 * in any way.
 */
JNIEXPORT const char * JNICALL
JVM_GetCPFieldSignatureUTF(UNUSED JNIEnv *env, UNUSED jclass cb, UNUSED jint index) {
    return NULL;
}

/*
 * Returns the class name refered to at a given constant pool index.
 *
 * The result is in UTF format and remains valid until JVM_ReleaseUTF
 * is called.
 *
 * The caller must treat the string as a constant and not modify it
 * in any way.
 */
JNIEXPORT const char * JNICALL
JVM_GetCPClassNameUTF(UNUSED JNIEnv *env, UNUSED jclass cb, UNUSED jint index) {
    return NULL;
}

/*
 * Returns the class name refered to at a given constant pool index.
 *
 * The constant pool entry must refer to a CONSTANT_Fieldref.
 *
 * The result is in UTF format and remains valid until JVM_ReleaseUTF
 * is called.
 *
 * The caller must treat the string as a constant and not modify it
 * in any way.
 */
JNIEXPORT const char * JNICALL
JVM_GetCPFieldClassNameUTF(UNUSED JNIEnv *env, UNUSED jclass cb, UNUSED jint index) {
    return NULL;
}

/*
 * Returns the class name refered to at a given constant pool index.
 *
 * The constant pool entry must refer to CONSTANT_Methodref or
 * CONSTANT_InterfaceMethodref.
 *
 * The result is in UTF format and remains valid until JVM_ReleaseUTF
 * is called.
 *
 * The caller must treat the string as a constant and not modify it
 * in any way.
 */
JNIEXPORT const char * JNICALL
JVM_GetCPMethodClassNameUTF(UNUSED JNIEnv *env, UNUSED jclass cb, UNUSED jint index) {
    return NULL;
}

/*
 * Returns the modifiers of a field in calledClass. The field is
 * referred to in class cb at constant pool entry index.
 *
 * The caller must treat the string as a constant and not modify it
 * in any way.
 *
 * Returns -1 if the field does not exist in calledClass.
 */
JNIEXPORT jint JNICALL
JVM_GetCPFieldModifiers(UNUSED JNIEnv *env, UNUSED jclass cb, UNUSED int index, UNUSED jclass calledClass) {
    return 0;
}

/*
 * Returns the modifiers of a method in calledClass. The method is
 * referred to in class cb at constant pool entry index.
 *
 * Returns -1 if the method does not exist in calledClass.
 */
JNIEXPORT jint JNICALL
JVM_GetCPMethodModifiers(UNUSED JNIEnv *env, UNUSED jclass cb, UNUSED int index, UNUSED jclass calledClass) {
    return 0;
}

/*
 * Releases the UTF string obtained from the VM.
 */
JNIEXPORT void JNICALL
JVM_ReleaseUTF(UNUSED const char *utf) {
}

/*
 * Compare if two classes are in the same package.
 */
JNIEXPORT jboolean JNICALL
JVM_IsSameClassPackage(UNUSED JNIEnv *env, UNUSED jclass class1, UNUSED jclass class2) {
    return JNI_FALSE;
}

JNIEXPORT char * JNICALL
JVM_NativePath(char *) {
    return NULL;
}

/*
 * The standard printing functions supported by the Java VM. (Should they
 * be renamed to JVM_* in the future?
 */

/* jio_snprintf() and jio_vsnprintf() behave like snprintf(3) and vsnprintf(3),
 *  respectively, with the following differences:
 * - The string written to str is always zero-terminated, also in case of
 *   truncation (count is too small to hold the result string), unless count
 *   is 0. In case of truncation count-1 characters are written and '\0'
 *   appendend.
 * - If count is too small to hold the whole string, -1 is returned across
 *   all platforms. */
JNIEXPORT int
jio_vsnprintf(UNUSED char *str, UNUSED size_t count, UNUSED const char *fmt, UNUSED va_list args) {
    return 0;
}

JNIEXPORT int
jio_snprintf(UNUSED char *str, UNUSED size_t count, UNUSED const char *fmt, ...) {
    return 0;
}

JNIEXPORT int
jio_fprintf(UNUSED FILE *, UNUSED const char *fmt, ...) {
    return 0;
}

JNIEXPORT int
jio_vfprintf(UNUSED FILE *, UNUSED const char *fmt, UNUSED va_list args) {
    return 0;
}


JNIEXPORT void * JNICALL
JVM_RawMonitorCreate(void) {
    return NULL;
}

JNIEXPORT void JNICALL
JVM_RawMonitorDestroy(UNUSED void *mon) {
}

JNIEXPORT jint JNICALL
JVM_RawMonitorEnter(UNUSED void *mon) {
    return 0;
}

JNIEXPORT void JNICALL
JVM_RawMonitorExit(UNUSED void *mon) {
}

/*
 * java.lang.reflect.Method
 */
JNIEXPORT jobject JNICALL
JVM_InvokeMethod(UNUSED JNIEnv *env, UNUSED jobject method, UNUSED jobject obj, UNUSED jobjectArray args0) {
    return NULL;
}

/*
 * java.lang.reflect.Constructor
 */
JNIEXPORT jobject JNICALL
JVM_NewInstanceFromConstructor(UNUSED JNIEnv *env, UNUSED jobject c, UNUSED jobjectArray args0) {
    return NULL;
}

/*
 * java.lang.management support
 */
JNIEXPORT void* JNICALL
JVM_GetManagement(UNUSED jint version) {
    return NULL;
}

/*
 * com.sun.tools.attach.VirtualMachine support
 *
 * Initialize the agent properties with the properties maintained in the VM.
 */
JNIEXPORT jobject JNICALL
JVM_InitAgentProperties(UNUSED JNIEnv *env, UNUSED jobject agent_props) {
    return NULL;
}

JNIEXPORT jstring JNICALL
JVM_GetTemporaryDirectory(UNUSED JNIEnv *env) {
    return NULL;
}

/* Generics reflection support.
 *
 * Returns information about the given class's EnclosingMethod
 * attribute, if present, or null if the class had no enclosing
 * method.
 *
 * If non-null, the returned array contains three elements. Element 0
 * is the java.lang.Class of which the enclosing method is a member,
 * and elements 1 and 2 are the java.lang.Strings for the enclosing
 * method's name and descriptor, respectively.
 */
JNIEXPORT jobjectArray JNICALL
JVM_GetEnclosingMethodInfo(UNUSED JNIEnv *env, UNUSED jclass ofClass) {
    return NULL;
}

JNIEXPORT void JNICALL
JVM_GetVersionInfo(UNUSED JNIEnv *env, UNUSED jvm_version_info* info, UNUSED size_t info_size) {
}
