; ModuleID = '/var/mobile/Containers/Data/Application/D306DF46-6C9B-4E6D-90C4-D19B1DA7868D/Documents/Data/CCR/UserFiles/ccr_resources/Scripts/Shell/Thread/pthread_Copy.cpp.bc'
source_filename = "/var/mobile/Containers/Data/Application/D306DF46-6C9B-4E6D-90C4-D19B1DA7868D/Documents/Data/CCR/UserFiles/ccr_resources/Scripts/Shell/Thread/pthread_Copy.cpp"
target datalayout = "e-m:o-p:32:32-f64:32:64-v64:32:64-v128:32:128-a:0:32-n32-S32"
target triple = "armv4t-apple-macosx10.4.0"

%struct._opaque_pthread_t = type { i32, %struct.__darwin_pthread_handler_rec*, [4088 x i8] }
%struct.__darwin_pthread_handler_rec = type { void (i8*)*, i8*, %struct.__darwin_pthread_handler_rec* }
%struct._opaque_pthread_attr_t = type { i32, [36 x i8] }

@threads = global [5 x %struct._opaque_pthread_t*] zeroinitializer, align 4 ; [#uses=2 type=[5 x %struct._opaque_pthread_t*]*]
@done = local_unnamed_addr global [5 x i32] zeroinitializer, align 4 ; [#uses=3 type=[5 x i32]*]
@.str = private unnamed_addr constant [8 x i8] c"pid=%d\0A\00", align 1 ; [#uses=1 type=[8 x i8]*]
@.str.1 = private unnamed_addr constant [8 x i8] c"%d, %d\0A\00", align 1 ; [#uses=1 type=[8 x i8]*]
@.str.2 = private unnamed_addr constant [42 x i8] c"Completed join with thread %d status= %d\0A\00", align 1 ; [#uses=1 type=[42 x i8]*]
@.str.3 = private unnamed_addr constant [57 x i8] c"ERROR; return code from pthread_join() is %d, thread %d\0A\00", align 1 ; [#uses=1 type=[57 x i8]*]
@.str.4 = private unnamed_addr constant [16 x i8] c"thread: %d, %d\0A\00", align 1 ; [#uses=1 type=[16 x i8]*]
@.str.5 = private unnamed_addr constant [23 x i8] c"thread: %d while loop\0A\00", align 1 ; [#uses=1 type=[23 x i8]*]
@.str.6 = private unnamed_addr constant [21 x i8] c"thread: %d sleeping\0A\00", align 1 ; [#uses=1 type=[21 x i8]*]
@.str.7 = private unnamed_addr constant [20 x i8] c"thread: %d exiting\0A\00", align 1 ; [#uses=1 type=[20 x i8]*]

; [#uses=0]
; Function Attrs: norecurse optsize
define i32 @main() local_unnamed_addr #0 {
  %1 = alloca i32, align 4                        ; [#uses=3 type=i32*]
  %2 = bitcast i32* %1 to i8*                     ; [#uses=2 type=i8*]
  call void @llvm.lifetime.start.p0i8(i64 4, i8* nonnull %2) #6
  %3 = tail call i32 @getpid() #7                 ; [#uses=1 type=i32]
  %4 = tail call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([8 x i8], [8 x i8]* @.str, i32 0, i32 0), i32 %3) #7 ; [#uses=0 type=i32]
  br label %5

; <label>:5:                                      ; preds = %5, %0
  %6 = phi i32 [ 0, %0 ], [ %14, %5 ]             ; [#uses=5 type=i32]
  %7 = getelementptr inbounds [5 x i32], [5 x i32]* @done, i32 0, i32 %6 ; [#uses=1 type=i32*]
  store i32 0, i32* %7, align 4, !tbaa !4
  %8 = getelementptr inbounds [5 x %struct._opaque_pthread_t*], [5 x %struct._opaque_pthread_t*]* @threads, i32 0, i32 %6 ; [#uses=2 type=%struct._opaque_pthread_t**]
  %9 = inttoptr i32 %6 to i8*                     ; [#uses=1 type=i8*]
  %10 = tail call i32 @pthread_create(%struct._opaque_pthread_t** nonnull %8, %struct._opaque_pthread_attr_t* null, i8* (i8*)* nonnull @_Z11thread_mainPv, i8* %9) #7 ; [#uses=0 type=i32]
  %11 = bitcast %struct._opaque_pthread_t** %8 to i32* ; [#uses=1 type=i32*]
  %12 = load i32, i32* %11, align 4, !tbaa !4     ; [#uses=1 type=i32]
  %13 = tail call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([8 x i8], [8 x i8]* @.str.1, i32 0, i32 0), i32 %6, i32 %12) #7 ; [#uses=0 type=i32]
  %14 = add nuw nsw i32 %6, 1                     ; [#uses=2 type=i32]
  %15 = icmp eq i32 %14, 5                        ; [#uses=1 type=i1]
  br i1 %15, label %16, label %5

; <label>:16:                                     ; preds = %5
  %17 = bitcast i32* %1 to i8**                   ; [#uses=1 type=i8**]
  br label %18

; <label>:18:                                     ; preds = %25, %16
  %19 = phi i32 [ 4, %16 ], [ %28, %25 ]          ; [#uses=6 type=i32]
  %20 = getelementptr inbounds [5 x i32], [5 x i32]* @done, i32 0, i32 %19 ; [#uses=1 type=i32*]
  store i32 1, i32* %20, align 4, !tbaa !4
  %21 = getelementptr inbounds [5 x %struct._opaque_pthread_t*], [5 x %struct._opaque_pthread_t*]* @threads, i32 0, i32 %19 ; [#uses=1 type=%struct._opaque_pthread_t**]
  %22 = load %struct._opaque_pthread_t*, %struct._opaque_pthread_t** %21, align 4, !tbaa !8 ; [#uses=1 type=%struct._opaque_pthread_t*]
  %23 = call i32 @"\01_pthread_join"(%struct._opaque_pthread_t* %22, i8** nonnull %17) #7 ; [#uses=2 type=i32]
  %24 = icmp eq i32 %23, 0                        ; [#uses=1 type=i1]
  br i1 %24, label %25, label %30

; <label>:25:                                     ; preds = %18
  %26 = load i32, i32* %1, align 4, !tbaa !4      ; [#uses=1 type=i32]
  %27 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([42 x i8], [42 x i8]* @.str.2, i32 0, i32 0), i32 %19, i32 %26) #7 ; [#uses=0 type=i32]
  %28 = add nsw i32 %19, -1                       ; [#uses=1 type=i32]
  %29 = icmp eq i32 %19, 0                        ; [#uses=1 type=i1]
  br i1 %29, label %32, label %18

; <label>:30:                                     ; preds = %18
  %31 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([57 x i8], [57 x i8]* @.str.3, i32 0, i32 0), i32 %23, i32 %19) #7 ; [#uses=0 type=i32]
  br label %32

; <label>:32:                                     ; preds = %25, %30
  %33 = phi i32 [ -1, %30 ], [ 0, %25 ]           ; [#uses=1 type=i32]
  call void @llvm.lifetime.end.p0i8(i64 4, i8* nonnull %2) #6
  ret i32 %33
}

; [#uses=1]
; Function Attrs: argmemonly nounwind
declare void @llvm.lifetime.start.p0i8(i64, i8* nocapture) #1

; [#uses=8]
; Function Attrs: nounwind optsize
declare i32 @printf(i8* nocapture readonly, ...) local_unnamed_addr #2

; [#uses=2]
; Function Attrs: optsize
declare i32 @getpid() local_unnamed_addr #3

; [#uses=1]
; Function Attrs: optsize
declare i32 @pthread_create(%struct._opaque_pthread_t**, %struct._opaque_pthread_attr_t*, i8* (i8*)*, i8*) local_unnamed_addr #3

; [#uses=1]
; Function Attrs: noreturn optsize
define noalias nonnull i8* @_Z11thread_mainPv(i8*) #4 {
  %2 = ptrtoint i8* %0 to i32                     ; [#uses=5 type=i32]
  %3 = tail call i32 @getpid() #7                 ; [#uses=1 type=i32]
  %4 = tail call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([16 x i8], [16 x i8]* @.str.4, i32 0, i32 0), i32 %2, i32 %3) #7 ; [#uses=0 type=i32]
  %5 = tail call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([23 x i8], [23 x i8]* @.str.5, i32 0, i32 0), i32 %2) #7 ; [#uses=0 type=i32]
  %6 = getelementptr inbounds [5 x i32], [5 x i32]* @done, i32 0, i32 %2 ; [#uses=1 type=i32*]
  %7 = load i32, i32* %6, align 4, !tbaa !4       ; [#uses=1 type=i32]
  %8 = icmp eq i32 %7, 0                          ; [#uses=1 type=i1]
  br i1 %8, label %9, label %11

; <label>:9:                                      ; preds = %1
  br label %10

; <label>:10:                                     ; preds = %9, %10
  br label %10

; <label>:11:                                     ; preds = %1
  %12 = tail call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([21 x i8], [21 x i8]* @.str.6, i32 0, i32 0), i32 %2) #7 ; [#uses=0 type=i32]
  %13 = tail call i32 @"\01_sleep"(i32 5) #7      ; [#uses=0 type=i32]
  %14 = tail call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([20 x i8], [20 x i8]* @.str.7, i32 0, i32 0), i32 %2) #7 ; [#uses=0 type=i32]
  tail call void @pthread_exit(i8* inttoptr (i32 2 to i8*)) #8
  unreachable
}

; [#uses=1]
; Function Attrs: optsize
declare i32 @"\01_pthread_join"(%struct._opaque_pthread_t*, i8**) local_unnamed_addr #3

; [#uses=1]
; Function Attrs: argmemonly nounwind
declare void @llvm.lifetime.end.p0i8(i64, i8* nocapture) #1

; [#uses=1]
; Function Attrs: optsize
declare i32 @"\01_sleep"(i32) local_unnamed_addr #3

; [#uses=1]
; Function Attrs: noreturn optsize
declare void @pthread_exit(i8*) local_unnamed_addr #5

attributes #0 = { norecurse optsize "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="arm7tdmi" "target-features"="+soft-float,+strict-align,-crypto,-neon,-thumb-mode" "unsafe-fp-math"="false" "use-soft-float"="true" }
attributes #1 = { argmemonly nounwind }
attributes #2 = { nounwind optsize "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="arm7tdmi" "target-features"="+soft-float,+strict-align,-crypto,-neon,-thumb-mode" "unsafe-fp-math"="false" "use-soft-float"="true" }
attributes #3 = { optsize "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="arm7tdmi" "target-features"="+soft-float,+strict-align,-crypto,-neon,-thumb-mode" "unsafe-fp-math"="false" "use-soft-float"="true" }
attributes #4 = { noreturn optsize "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="arm7tdmi" "target-features"="+soft-float,+strict-align,-crypto,-neon,-thumb-mode" "unsafe-fp-math"="false" "use-soft-float"="true" }
attributes #5 = { noreturn optsize "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="arm7tdmi" "target-features"="+soft-float,+strict-align,-crypto,-neon,-thumb-mode" "unsafe-fp-math"="false" "use-soft-float"="true" }
attributes #6 = { nounwind }
attributes #7 = { optsize }
attributes #8 = { noreturn optsize }

!llvm.module.flags = !{!0, !1, !2}
!llvm.ident = !{!3}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{i32 1, !"min_enum_size", i32 4}
!2 = !{i32 7, !"PIC Level", i32 2}
!3 = !{!"clang version 6.0.0 (tags/RELEASE_600/final)"}
!4 = !{!5, !5, i64 0}
!5 = !{!"int", !6, i64 0}
!6 = !{!"omnipotent char", !7, i64 0}
!7 = !{!"Simple C++ TBAA"}
!8 = !{!9, !9, i64 0}
!9 = !{!"any pointer", !6, i64 0}
