/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_eyer_eyerplayer_EyerPlayerJNI */

#ifndef _Included_com_eyer_eyerplayer_EyerPlayerJNI
#define _Included_com_eyer_eyerplayer_EyerPlayerJNI
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_eyer_eyerplayer_EyerPlayerJNI
 * Method:    player_init
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_com_eyer_eyerplayer_EyerPlayerJNI_player_1init
  (JNIEnv *, jclass);

/*
 * Class:     com_eyer_eyerplayer_EyerPlayerJNI
 * Method:    player_uninit
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_com_eyer_eyerplayer_EyerPlayerJNI_player_1uninit
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_eyer_eyerplayer_EyerPlayerJNI
 * Method:    player_set_surface
 * Signature: (JLandroid/view/Surface;)I
 */
JNIEXPORT jint JNICALL Java_com_eyer_eyerplayer_EyerPlayerJNI_player_1set_1surface
  (JNIEnv *, jclass, jlong, jobject);

/*
 * Class:     com_eyer_eyerplayer_EyerPlayerJNI
 * Method:    player_set_callback
 * Signature: (JLcom/eyer/eyerplayer/callback/EyerCallback;)I
 */
JNIEXPORT jint JNICALL Java_com_eyer_eyerplayer_EyerPlayerJNI_player_1set_1callback
  (JNIEnv *, jclass, jlong, jobject);

/*
 * Class:     com_eyer_eyerplayer_EyerPlayerJNI
 * Method:    player_open
 * Signature: (JLjava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_com_eyer_eyerplayer_EyerPlayerJNI_player_1open
  (JNIEnv *, jclass, jlong, jstring);

/*
 * Class:     com_eyer_eyerplayer_EyerPlayerJNI
 * Method:    player_play
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_com_eyer_eyerplayer_EyerPlayerJNI_player_1play
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_eyer_eyerplayer_EyerPlayerJNI
 * Method:    player_pause
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_com_eyer_eyerplayer_EyerPlayerJNI_player_1pause
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_eyer_eyerplayer_EyerPlayerJNI
 * Method:    player_stop
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_com_eyer_eyerplayer_EyerPlayerJNI_player_1stop
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_eyer_eyerplayer_EyerPlayerJNI
 * Method:    player_seek
 * Signature: (JD)I
 */
JNIEXPORT jint JNICALL Java_com_eyer_eyerplayer_EyerPlayerJNI_player_1seek
  (JNIEnv *, jclass, jlong, jdouble);

/*
 * Class:     com_eyer_eyerplayer_EyerPlayerJNI
 * Method:    player_gl_init
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_com_eyer_eyerplayer_EyerPlayerJNI_player_1gl_1init
  (JNIEnv *, jclass);

/*
 * Class:     com_eyer_eyerplayer_EyerPlayerJNI
 * Method:    player_gl_draw
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_com_eyer_eyerplayer_EyerPlayerJNI_player_1gl_1draw
  (JNIEnv *, jclass, jint);

/*
 * Class:     com_eyer_eyerplayer_EyerPlayerJNI
 * Method:    player_gl_viewport
 * Signature: (II)I
 */
JNIEXPORT jint JNICALL Java_com_eyer_eyerplayer_EyerPlayerJNI_player_1gl_1viewport
  (JNIEnv *, jclass, jint, jint);

#ifdef __cplusplus
}
#endif
#endif
