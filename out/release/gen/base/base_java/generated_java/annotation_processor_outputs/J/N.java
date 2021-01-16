package J;

import java.lang.Object;
import java.lang.String;
import java.lang.Throwable;
import javax.annotation.Generated;

@Generated("org.chromium.jni_generator.JniProcessor")
public final class N {
  public static boolean TESTING_ENABLED;

  public static boolean REQUIRE_MOCK;

  /**
   * org.chromium.base.AnimationFrameTimeHistogram.saveHistogram
   * @param histogramName (java.lang.String)
   * @param frameTimesMs (long[])
   * @param count (int)
   * @return (void)
   */
  public static final native void M7xB0tc0(String histogramName, long[] frameTimesMs, int count);

  /**
   * org.chromium.base.ApplicationStatus.onApplicationStateChange
   * @param newState (int)
   * @return (void)
   */
  public static final native void MiAkQ_SU(int newState);

  /**
   * org.chromium.base.CommandLine.appendSwitch
   * @param switchString (java.lang.String)
   * @return (void)
   */
  public static final native void M5K_ewhl(String switchString);

  /**
   * org.chromium.base.CommandLine.appendSwitchWithValue
   * @param switchString (java.lang.String)
   * @param value (java.lang.String)
   * @return (void)
   */
  public static final native void MUoYiNbY(String switchString, String value);

  /**
   * org.chromium.base.CommandLine.appendSwitchesAndArguments
   * @param array (java.lang.String[])
   * @return (void)
   */
  public static final native void MPquHBNa(String[] array);

  /**
   * org.chromium.base.CommandLine.getSwitchValue
   * @param switchString (java.lang.String)
   * @return (java.lang.String)
   */
  public static final native String MZJ2lrZY(String switchString);

  /**
   * org.chromium.base.CommandLine.hasSwitch
   * @param switchString (java.lang.String)
   * @return (boolean)
   */
  public static final native boolean MsCvypjU(String switchString);

  /**
   * org.chromium.base.CommandLine.init
   * @param args (java.lang.String[])
   * @return (void)
   */
  public static final native void MDkrKi31(String[] args);

  /**
   * org.chromium.base.CommandLine.removeSwitch
   * @param switchString (java.lang.String)
   * @return (void)
   */
  public static final native void M1cMYXGO(String switchString);

  /**
   * org.chromium.base.CpuFeatures.getCoreCount
   * @return (int)
   */
  public static final native int MOiBJ1qS();

  /**
   * org.chromium.base.CpuFeatures.getCpuFeatures
   * @return (long)
   */
  public static final native long ML0T8q1U();

  /**
   * org.chromium.base.EarlyTraceEvent.recordEarlyEvent
   * @param name (java.lang.String)
   * @param beginTimNanos (long)
   * @param endTimeNanos (long)
   * @param threadId (int)
   * @param threadDurationMillis (long)
   * @return (void)
   */
  public static final native void MDy_VEWN(String name, long beginTimNanos, long endTimeNanos,
      int threadId, long threadDurationMillis);

  /**
   * org.chromium.base.EarlyTraceEvent.recordEarlyFinishAsyncEvent
   * @param name (java.lang.String)
   * @param id (long)
   * @param timestamp (long)
   * @return (void)
   */
  public static final native void MCm4GHjn(String name, long id, long timestamp);

  /**
   * org.chromium.base.EarlyTraceEvent.recordEarlyStartAsyncEvent
   * @param name (java.lang.String)
   * @param id (long)
   * @param timestamp (long)
   * @return (void)
   */
  public static final native void M8HhsiE6(String name, long id, long timestamp);

  /**
   * org.chromium.base.FieldTrialList.findFullName
   * @param trialName (java.lang.String)
   * @return (java.lang.String)
   */
  public static final native String MdC43qwX(String trialName);

  /**
   * org.chromium.base.FieldTrialList.getVariationParameter
   * @param trialName (java.lang.String)
   * @param parameterKey (java.lang.String)
   * @return (java.lang.String)
   */
  public static final native String MZWMOP4I(String trialName, String parameterKey);

  /**
   * org.chromium.base.FieldTrialList.logActiveTrials
   * @return (void)
   */
  public static final native void MHz6Fn06();

  /**
   * org.chromium.base.FieldTrialList.trialExists
   * @param trialName (java.lang.String)
   * @return (boolean)
   */
  public static final native boolean Mmqqda9c(String trialName);

  /**
   * org.chromium.base.ImportantFileWriterAndroid.writeFileAtomically
   * @param fileName (java.lang.String)
   * @param data (byte[])
   * @return (boolean)
   */
  public static final native boolean MsOKBrZ5(String fileName, byte[] data);

  /**
   * org.chromium.base.JavaExceptionReporter.reportJavaException
   * @param crashAfterReport (boolean)
   * @param e (java.lang.Throwable)
   * @return (void)
   */
  public static final native void MLlibBXh(boolean crashAfterReport, Throwable e);

  /**
   * org.chromium.base.JavaExceptionReporter.reportJavaStackTrace
   * @param stackTrace (java.lang.String)
   * @return (void)
   */
  public static final native void MmS4zlEt(String stackTrace);

  /**
   * org.chromium.base.JavaHandlerThread.initializeThread
   * @param nativeJavaHandlerThread (long)
   * @param nativeEvent (long)
   * @return (void)
   */
  public static final native void MJcct7gJ(long nativeJavaHandlerThread, long nativeEvent);

  /**
   * org.chromium.base.JavaHandlerThread.onLooperStopped
   * @param nativeJavaHandlerThread (long)
   * @return (void)
   */
  public static final native void MYwg$x8E(long nativeJavaHandlerThread);

  /**
   * org.chromium.base.MemoryPressureListener.onMemoryPressure
   * @param pressure (int)
   * @return (void)
   */
  public static final native void MZJzyjAa(int pressure);

  /**
   * org.chromium.base.PathService.override
   * @param what (int)
   * @param path (java.lang.String)
   * @return (void)
   */
  public static final native void M6H_IiaF(int what, String path);

  /**
   * org.chromium.base.PowerMonitor.onBatteryChargingChanged
   * @return (void)
   */
  public static final native void MCImhGql();

  /**
   * org.chromium.base.SysUtils.logPageFaultCountToTracing
   * @return (void)
   */
  public static final native void MOXOasS5();

  /**
   * org.chromium.base.TimeUtils.getTimeTicksNowUs
   * @return (long)
   */
  public static final native long MklbOJun();

  /**
   * org.chromium.base.TraceEvent.begin
   * @param name (java.lang.String)
   * @param arg (java.lang.String)
   * @return (void)
   */
  public static final native void M9XfPu17(String name, String arg);

  /**
   * org.chromium.base.TraceEvent.beginToplevel
   * @param target (java.lang.String)
   * @return (void)
   */
  public static final native void M_y76mct(String target);

  /**
   * org.chromium.base.TraceEvent.end
   * @param name (java.lang.String)
   * @param arg (java.lang.String)
   * @return (void)
   */
  public static final native void Mw73xTww(String name, String arg);

  /**
   * org.chromium.base.TraceEvent.endToplevel
   * @param target (java.lang.String)
   * @return (void)
   */
  public static final native void MLJecZJ9(String target);

  /**
   * org.chromium.base.TraceEvent.finishAsync
   * @param name (java.lang.String)
   * @param id (long)
   * @return (void)
   */
  public static final native void MffNhCLU(String name, long id);

  /**
   * org.chromium.base.TraceEvent.instant
   * @param name (java.lang.String)
   * @param arg (java.lang.String)
   * @return (void)
   */
  public static final native void ML40H8ed(String name, String arg);

  /**
   * org.chromium.base.TraceEvent.registerEnabledObserver
   * @return (void)
   */
  public static final native void MFFzPOVw();

  /**
   * org.chromium.base.TraceEvent.startATrace
   * @return (void)
   */
  public static final native void MRN$Vid3();

  /**
   * org.chromium.base.TraceEvent.startAsync
   * @param name (java.lang.String)
   * @param id (long)
   * @return (void)
   */
  public static final native void MHopMqLX(String name, long id);

  /**
   * org.chromium.base.TraceEvent.stopATrace
   * @return (void)
   */
  public static final native void MOgCa3d$();

  /**
   * org.chromium.base.library_loader.LibraryLoader.getVersionNumber
   * @return (java.lang.String)
   */
  public static final native String M$HdV9JM();

  /**
   * org.chromium.base.library_loader.LibraryLoader.libraryLoaded
   * @param processType (int)
   * @return (boolean)
   */
  public static final native boolean M81WqFvs(int processType);

  /**
   * org.chromium.base.library_loader.LibraryLoader.recordRendererLibraryLoadTime
   * @param libraryLoadTime (long)
   * @return (void)
   */
  public static final native void MiAWbgCC(long libraryLoadTime);

  /**
   * org.chromium.base.library_loader.LibraryLoader.registerNonMainDexJni
   * @return (void)
   */
  public static final native void MIOj213u();

  /**
   * org.chromium.base.library_loader.LibraryPrefetcher.forkAndPrefetchNativeLibrary
   * @return (void)
   */
  public static final native void MUjpxN8d();

  /**
   * org.chromium.base.library_loader.LibraryPrefetcher.percentageOfResidentNativeLibraryCode
   * @return (int)
   */
  public static final native int MdFgVRJJ();

  /**
   * org.chromium.base.library_loader.LibraryPrefetcher.periodicallyCollectResidency
   * @return (void)
   */
  public static final native void MLXZo1U6();

  /**
   * org.chromium.base.metrics.NativeUmaRecorder.recordBooleanHistogram
   * @param name (java.lang.String)
   * @param nativeHint (long)
   * @param sample (boolean)
   * @return (long)
   */
  public static final native long MtKTTHie(String name, long nativeHint, boolean sample);

  /**
   * org.chromium.base.metrics.NativeUmaRecorder.recordExponentialHistogram
   * @param name (java.lang.String)
   * @param nativeHint (long)
   * @param sample (int)
   * @param min (int)
   * @param max (int)
   * @param numBuckets (int)
   * @return (long)
   */
  public static final native long MILRV9Ch(String name, long nativeHint, int sample, int min,
      int max, int numBuckets);

  /**
   * org.chromium.base.metrics.NativeUmaRecorder.recordLinearHistogram
   * @param name (java.lang.String)
   * @param nativeHint (long)
   * @param sample (int)
   * @param min (int)
   * @param max (int)
   * @param numBuckets (int)
   * @return (long)
   */
  public static final native long M$oMD214(String name, long nativeHint, int sample, int min,
      int max, int numBuckets);

  /**
   * org.chromium.base.metrics.NativeUmaRecorder.recordSparseHistogram
   * @param name (java.lang.String)
   * @param nativeHint (long)
   * @param sample (int)
   * @return (long)
   */
  public static final native long Mk1ai9mx(String name, long nativeHint, int sample);

  /**
   * org.chromium.base.metrics.RecordHistogram.getHistogramTotalCountForTesting
   * @param name (java.lang.String)
   * @return (int)
   */
  public static final native int M4mrObfZ(String name);

  /**
   * org.chromium.base.metrics.RecordHistogram.getHistogramValueCountForTesting
   * @param name (java.lang.String)
   * @param sample (int)
   * @return (int)
   */
  public static final native int M1gJHszj(String name, int sample);

  /**
   * org.chromium.base.metrics.RecordUserAction.addActionCallbackForTesting
   * @param callback (org.chromium.base.metrics.RecordUserAction.UserActionCallback)
   * @return (long)
   */
  public static final native long MH0bOwlk(Object callback);

  /**
   * org.chromium.base.metrics.RecordUserAction.recordUserAction
   * @param action (java.lang.String)
   * @return (void)
   */
  public static final native void MlFl3ytt(String action);

  /**
   * org.chromium.base.metrics.RecordUserAction.removeActionCallbackForTesting
   * @param callbackId (long)
   * @return (void)
   */
  public static final native void MJl0LdjQ(long callbackId);

  /**
   * org.chromium.base.metrics.StatisticsRecorderAndroid.toJson
   * @param verbosityLevel (int)
   * @return (java.lang.String)
   */
  public static final native String MvO$oy3r(int verbosityLevel);

  /**
   * org.chromium.base.process_launcher.ChildProcessService.dumpProcessStack
   * @return (void)
   */
  public static final native void M6Y7Jzgj();

  /**
   * org.chromium.base.process_launcher.ChildProcessService.exitChildProcess
   * @return (void)
   */
  public static final native void McvJWQ0j();

  /**
   * org.chromium.base.process_launcher.ChildProcessService.registerFileDescriptors
   * @param keys (java.lang.String[])
   * @param id (int[])
   * @param fd (int[])
   * @param offset (long[])
   * @param size (long[])
   * @return (void)
   */
  public static final native void Ma6rsNQO(String[] keys, int[] id, int[] fd, long[] offset,
      long[] size);

  /**
   * org.chromium.base.task.PostTask.postDelayedTask
   * @param prioritySetExplicitly (boolean)
   * @param priority (int)
   * @param mayBlock (boolean)
   * @param useThreadPool (boolean)
   * @param extensionId (byte)
   * @param extensionData (byte[])
   * @param task (java.lang.Runnable)
   * @param delay (long)
   * @return (void)
   */
  public static final native void MTILOhAQ(boolean prioritySetExplicitly, int priority,
      boolean mayBlock, boolean useThreadPool, byte extensionId, byte[] extensionData, Object task,
      long delay);

  /**
   * org.chromium.base.task.TaskRunnerImpl.belongsToCurrentThread
   * @param nativeTaskRunnerAndroid (long)
   * @return (boolean)
   */
  public static final native boolean MdFi6sVQ(long nativeTaskRunnerAndroid);

  /**
   * org.chromium.base.task.TaskRunnerImpl.destroy
   * @param nativeTaskRunnerAndroid (long)
   * @return (void)
   */
  public static final native void MERCiIV8(long nativeTaskRunnerAndroid);

  /**
   * org.chromium.base.task.TaskRunnerImpl.init
   * @param taskRunnerType (int)
   * @param prioritySetExplicitly (boolean)
   * @param priority (int)
   * @param mayBlock (boolean)
   * @param useThreadPool (boolean)
   * @param extensionId (byte)
   * @param extensionData (byte[])
   * @return (long)
   */
  public static final native long M5_IQXaH(int taskRunnerType, boolean prioritySetExplicitly,
      int priority, boolean mayBlock, boolean useThreadPool, byte extensionId,
      byte[] extensionData);

  /**
   * org.chromium.base.task.TaskRunnerImpl.postDelayedTask
   * @param nativeTaskRunnerAndroid (long)
   * @param task (java.lang.Runnable)
   * @param delay (long)
   * @return (void)
   */
  public static final native void MGnQU$47(long nativeTaskRunnerAndroid, Object task, long delay);
}
