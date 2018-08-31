; ModuleID = '/var/mobile/Containers/Data/Application/8C6028F1-B11A-49EA-9088-B9AB7F20E70A/Documents/Data/CCR/UserFiles/shells/constructortest.c.bc'
source_filename = "/var/mobile/Containers/Data/Application/8C6028F1-B11A-49EA-9088-B9AB7F20E70A/Documents/Data/CCR/UserFiles/shells/constructortest.c"
target datalayout = "e-m:o-p:32:32-f64:32:64-v64:32:64-v128:32:128-a:0:32-n32-S32"
target triple = "armv4t-apple-macosx10.4.0"

@llvm.global_ctors = appending global [1 x { i32, void ()*, i8* }] [{ i32, void ()*, i8* } { i32 0, void ()* @initstd, i8* null }] ; [#uses=0 type=[1 x { i32, void ()*, i8* }]*]
@str = private unnamed_addr constant [5 x i8] c"test\00" ; [#uses=1 type=[5 x i8]*]

; [#uses=1]
; Function Attrs: nounwind optsize
define void @initstd() #0 {
  %1 = tail call i32 @puts(i8* getelementptr inbounds ([5 x i8], [5 x i8]* @str, i32 0, i32 0)) ; [#uses=0 type=i32]
  ret void
}

; [#uses=1]
; Function Attrs: nounwind
declare i32 @puts(i8* nocapture readonly) #1

attributes #0 = { nounwind optsize "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="arm7tdmi" "target-features"="+soft-float,+strict-align,-crypto,-neon,-thumb-mode" "unsafe-fp-math"="false" "use-soft-float"="true" }
attributes #1 = { nounwind }

!llvm.module.flags = !{!0, !1, !2}
!llvm.ident = !{!3}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{i32 1, !"min_enum_size", i32 4}
!2 = !{i32 7, !"PIC Level", i32 2}
!3 = !{!"clang version 5.0.0 (tags/RELEASE_500/final)"}
