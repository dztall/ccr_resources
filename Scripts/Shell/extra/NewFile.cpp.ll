; ModuleID = '/var/mobile/Containers/Data/Application/8C6028F1-B11A-49EA-9088-B9AB7F20E70A/Documents/Data/CCR/UserFiles/shells/NewFile.cpp.bc'
source_filename = "/var/mobile/Containers/Data/Application/8C6028F1-B11A-49EA-9088-B9AB7F20E70A/Documents/Data/CCR/UserFiles/shells/NewFile.cpp"
target datalayout = "e-m:o-p:32:32-f64:32:64-v64:32:64-v128:32:128-a:0:32-n32-S32"
target triple = "armv4t-apple-macosx10.4.0"

%struct.line_ = type { i8*, [10 x %"struct.line_::word_"] }
%"struct.line_::word_" = type { i8*, i8* }
%"class.std::__ccr1::basic_ostream" = type { i32 (...)**, %"class.std::__ccr1::basic_ios" }
%"class.std::__ccr1::basic_ios" = type { %"class.std::__ccr1::ios_base", %"class.std::__ccr1::basic_ostream"*, i32 }
%"class.std::__ccr1::ios_base" = type { i32 (...)**, i32, i32, i32, i32, i32, i8*, i8*, void (i32, %"class.std::__ccr1::ios_base"*, i32)**, i32*, i32, i32, i32*, i32, i32, i8**, i32, i32 }
%"class.std::__ccr1::locale::id" = type { %"struct.std::__ccr1::once_flag", i32 }
%"struct.std::__ccr1::once_flag" = type { i32 }
%"class.std::__ccr1::locale" = type { %"class.std::__ccr1::locale::__imp"* }
%"class.std::__ccr1::locale::__imp" = type opaque
%"class.std::__ccr1::locale::facet" = type { %"class.std::__ccr1::__shared_count" }
%"class.std::__ccr1::__shared_count" = type { i32 (...)**, i32 }
%"class.std::__ccr1::ctype" = type <{ %"class.std::__ccr1::locale::facet", i32*, i8, [3 x i8] }>
%"class.std::__ccr1::basic_ostream<char, std::__ccr1::char_traits<char> >::sentry" = type { i8, %"class.std::__ccr1::basic_ostream"* }
%"class.std::__ccr1::basic_streambuf" = type { i32 (...)**, %"class.std::__ccr1::locale", i8*, i8*, i8*, i8*, i8*, i8* }

@line = global [10 x %struct.line_] zeroinitializer, align 4 ; [#uses=6 type=[10 x %struct.line_]*]
@.str = private unnamed_addr constant [10 x i8] c"test line\00", align 1 ; [#uses=1 type=[10 x i8]*]
@.str.1 = private unnamed_addr constant [5 x i8] c"test\00", align 1 ; [#uses=1 type=[5 x i8]*]
@.str.2 = private unnamed_addr constant [5 x i8] c"line\00", align 1 ; [#uses=1 type=[5 x i8]*]
@_ZNSt6__ccr14coutE = external global %"class.std::__ccr1::basic_ostream", align 4 ; [#uses=1 type=%"class.std::__ccr1::basic_ostream"*]
@.str.3 = private unnamed_addr constant [16 x i8] c"line[0].line = \00", align 1 ; [#uses=1 type=[16 x i8]*]
@.str.4 = private unnamed_addr constant [26 x i8] c", line[0].word[0].word = \00", align 1 ; [#uses=1 type=[26 x i8]*]
@.str.5 = private unnamed_addr constant [27 x i8] c", line[0].word[0].ch[0] = \00", align 1 ; [#uses=1 type=[27 x i8]*]
@_ZNSt6__ccr15ctypeIcE2idE = external global %"class.std::__ccr1::locale::id", align 4 ; [#uses=2 type=%"class.std::__ccr1::locale::id"*]
@llvm.global_ctors = appending global [1 x { i32, void ()*, i8* }] [{ i32, void ()*, i8* } { i32 65535, void ()* @_GLOBAL__sub_I_NewFile.cpp, i8* null }] ; [#uses=0 type=[1 x { i32, void ()*, i8* }]*]

; [#uses=0]
; Function Attrs: norecurse optsize
define i32 @main() local_unnamed_addr #0 personality i32 (...)* @__gxx_personality_sj0 {
  %1 = alloca %"class.std::__ccr1::locale", align 4 ; [#uses=5 type=%"class.std::__ccr1::locale"*]
  %2 = alloca i8, align 1                         ; [#uses=4 type=i8*]
  store i8* getelementptr inbounds ([10 x i8], [10 x i8]* @.str, i32 0, i32 0), i8** getelementptr inbounds ([10 x %struct.line_], [10 x %struct.line_]* @line, i32 0, i32 0, i32 0), align 4, !tbaa !4
  store i8* getelementptr inbounds ([5 x i8], [5 x i8]* @.str.1, i32 0, i32 0), i8** getelementptr inbounds ([10 x %struct.line_], [10 x %struct.line_]* @line, i32 0, i32 0, i32 1, i32 0, i32 0), align 4, !tbaa !9
  store i8* getelementptr inbounds ([5 x i8], [5 x i8]* @.str.2, i32 0, i32 0), i8** getelementptr inbounds ([10 x %struct.line_], [10 x %struct.line_]* @line, i32 0, i32 0, i32 1, i32 1, i32 0), align 4, !tbaa !9
  %3 = tail call dereferenceable(84) %"class.std::__ccr1::basic_ostream"* @_ZNSt6__ccr124__put_character_sequenceIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m(%"class.std::__ccr1::basic_ostream"* nonnull dereferenceable(84) @_ZNSt6__ccr14coutE, i8* getelementptr inbounds ([16 x i8], [16 x i8]* @.str.3, i32 0, i32 0), i32 15) #9 ; [#uses=1 type=%"class.std::__ccr1::basic_ostream"*]
  %4 = load i8*, i8** getelementptr inbounds ([10 x %struct.line_], [10 x %struct.line_]* @line, i32 0, i32 0, i32 0), align 4, !tbaa !4 ; [#uses=2 type=i8*]
  %5 = tail call i32 @strlen(i8* %4) #10          ; [#uses=1 type=i32]
  %6 = tail call dereferenceable(84) %"class.std::__ccr1::basic_ostream"* @_ZNSt6__ccr124__put_character_sequenceIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m(%"class.std::__ccr1::basic_ostream"* nonnull dereferenceable(84) %3, i8* %4, i32 %5) #9 ; [#uses=1 type=%"class.std::__ccr1::basic_ostream"*]
  %7 = tail call dereferenceable(84) %"class.std::__ccr1::basic_ostream"* @_ZNSt6__ccr124__put_character_sequenceIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m(%"class.std::__ccr1::basic_ostream"* nonnull dereferenceable(84) %6, i8* getelementptr inbounds ([26 x i8], [26 x i8]* @.str.4, i32 0, i32 0), i32 25) #9 ; [#uses=1 type=%"class.std::__ccr1::basic_ostream"*]
  %8 = load i8*, i8** getelementptr inbounds ([10 x %struct.line_], [10 x %struct.line_]* @line, i32 0, i32 0, i32 1, i32 0, i32 0), align 4, !tbaa !9 ; [#uses=2 type=i8*]
  %9 = tail call i32 @strlen(i8* %8) #10          ; [#uses=1 type=i32]
  %10 = tail call dereferenceable(84) %"class.std::__ccr1::basic_ostream"* @_ZNSt6__ccr124__put_character_sequenceIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m(%"class.std::__ccr1::basic_ostream"* nonnull dereferenceable(84) %7, i8* %8, i32 %9) #9 ; [#uses=1 type=%"class.std::__ccr1::basic_ostream"*]
  %11 = tail call dereferenceable(84) %"class.std::__ccr1::basic_ostream"* @_ZNSt6__ccr124__put_character_sequenceIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m(%"class.std::__ccr1::basic_ostream"* nonnull dereferenceable(84) %10, i8* getelementptr inbounds ([27 x i8], [27 x i8]* @.str.5, i32 0, i32 0), i32 26) #9 ; [#uses=1 type=%"class.std::__ccr1::basic_ostream"*]
  %12 = load i8*, i8** getelementptr inbounds ([10 x %struct.line_], [10 x %struct.line_]* @line, i32 0, i32 0, i32 1, i32 0, i32 1), align 4, !tbaa !11 ; [#uses=1 type=i8*]
  %13 = load i8, i8* %12, align 1, !tbaa !12      ; [#uses=1 type=i8]
  call void @llvm.lifetime.start.p0i8(i64 1, i8* nonnull %2)
  store i8 %13, i8* %2, align 1, !tbaa !12
  %14 = call dereferenceable(84) %"class.std::__ccr1::basic_ostream"* @_ZNSt6__ccr124__put_character_sequenceIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m(%"class.std::__ccr1::basic_ostream"* nonnull dereferenceable(84) %11, i8* nonnull %2, i32 1) #9 ; [#uses=4 type=%"class.std::__ccr1::basic_ostream"*]
  call void @llvm.lifetime.end.p0i8(i64 1, i8* nonnull %2)
  %15 = bitcast %"class.std::__ccr1::basic_ostream"* %14 to i8** ; [#uses=1 type=i8**]
  %16 = load i8*, i8** %15, align 4, !tbaa !13    ; [#uses=1 type=i8*]
  %17 = getelementptr i8, i8* %16, i32 -12        ; [#uses=1 type=i8*]
  %18 = bitcast i8* %17 to i32*                   ; [#uses=1 type=i32*]
  %19 = load i32, i32* %18, align 4               ; [#uses=1 type=i32]
  %20 = bitcast %"class.std::__ccr1::basic_ostream"* %14 to i8* ; [#uses=1 type=i8*]
  %21 = getelementptr inbounds i8, i8* %20, i32 %19 ; [#uses=1 type=i8*]
  %22 = bitcast %"class.std::__ccr1::locale"* %1 to i8* ; [#uses=3 type=i8*]
  call void @llvm.lifetime.start.p0i8(i64 4, i8* nonnull %22) #11
  %23 = bitcast i8* %21 to %"class.std::__ccr1::ios_base"* ; [#uses=1 type=%"class.std::__ccr1::ios_base"*]
  call void @_ZNKSt6__ccr18ios_base6getlocEv(%"class.std::__ccr1::locale"* nonnull sret %1, %"class.std::__ccr1::ios_base"* %23) #9
  %24 = invoke %"class.std::__ccr1::locale::facet"* @_ZNKSt6__ccr16locale9use_facetERNS0_2idE(%"class.std::__ccr1::locale"* nonnull %1, %"class.std::__ccr1::locale::id"* nonnull dereferenceable(8) @_ZNSt6__ccr15ctypeIcE2idE) #9
          to label %25 unwind label %32           ; [#uses=2 type=%"class.std::__ccr1::locale::facet"*]

; <label>:25:                                     ; preds = %0
  %26 = bitcast %"class.std::__ccr1::locale::facet"* %24 to %"class.std::__ccr1::ctype"* ; [#uses=1 type=%"class.std::__ccr1::ctype"*]
  %27 = bitcast %"class.std::__ccr1::locale::facet"* %24 to i8 (%"class.std::__ccr1::ctype"*, i8)*** ; [#uses=1 type=i8 (%"class.std::__ccr1::ctype"*, i8)***]
  %28 = load i8 (%"class.std::__ccr1::ctype"*, i8)**, i8 (%"class.std::__ccr1::ctype"*, i8)*** %27, align 4, !tbaa !13 ; [#uses=1 type=i8 (%"class.std::__ccr1::ctype"*, i8)**]
  %29 = getelementptr inbounds i8 (%"class.std::__ccr1::ctype"*, i8)*, i8 (%"class.std::__ccr1::ctype"*, i8)** %28, i32 7 ; [#uses=1 type=i8 (%"class.std::__ccr1::ctype"*, i8)**]
  %30 = load i8 (%"class.std::__ccr1::ctype"*, i8)*, i8 (%"class.std::__ccr1::ctype"*, i8)** %29, align 4 ; [#uses=1 type=i8 (%"class.std::__ccr1::ctype"*, i8)*]
  %31 = invoke signext i8 %30(%"class.std::__ccr1::ctype"* %26, i8 signext 10) #9
          to label %35 unwind label %32           ; [#uses=1 type=i8]

; <label>:32:                                     ; preds = %25, %0
  %33 = landingpad { i8*, i32 }
          cleanup                                 ; [#uses=1 type={ i8*, i32 }]
  %34 = call %"class.std::__ccr1::locale"* @_ZNSt6__ccr16localeD1Ev(%"class.std::__ccr1::locale"* nonnull %1) #10 ; [#uses=0 type=%"class.std::__ccr1::locale"*]
  call void @llvm.lifetime.end.p0i8(i64 4, i8* nonnull %22) #11
  resume { i8*, i32 } %33

; <label>:35:                                     ; preds = %25
  %36 = call %"class.std::__ccr1::locale"* @_ZNSt6__ccr16localeD1Ev(%"class.std::__ccr1::locale"* nonnull %1) #10 ; [#uses=0 type=%"class.std::__ccr1::locale"*]
  call void @llvm.lifetime.end.p0i8(i64 4, i8* nonnull %22) #11
  %37 = call dereferenceable(84) %"class.std::__ccr1::basic_ostream"* @_ZNSt6__ccr113basic_ostreamIcNS_11char_traitsIcEEE3putEc(%"class.std::__ccr1::basic_ostream"* nonnull %14, i8 signext %31) #9 ; [#uses=0 type=%"class.std::__ccr1::basic_ostream"*]
  %38 = call dereferenceable(84) %"class.std::__ccr1::basic_ostream"* @_ZNSt6__ccr113basic_ostreamIcNS_11char_traitsIcEEE5flushEv(%"class.std::__ccr1::basic_ostream"* nonnull %14) #9 ; [#uses=0 type=%"class.std::__ccr1::basic_ostream"*]
  ret i32 0
}

; [#uses=6]
; Function Attrs: optsize
define linkonce_odr dereferenceable(84) %"class.std::__ccr1::basic_ostream"* @_ZNSt6__ccr124__put_character_sequenceIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m(%"class.std::__ccr1::basic_ostream"* dereferenceable(84), i8*, i32) local_unnamed_addr #1 personality i8* bitcast (i32 (...)* @__gxx_personality_sj0 to i8*) {
  %4 = alloca %"class.std::__ccr1::locale", align 4 ; [#uses=5 type=%"class.std::__ccr1::locale"*]
  %5 = alloca %"class.std::__ccr1::basic_ostream<char, std::__ccr1::char_traits<char> >::sentry", align 4 ; [#uses=4 type=%"class.std::__ccr1::basic_ostream<char, std::__ccr1::char_traits<char> >::sentry"*]
  %6 = getelementptr inbounds %"class.std::__ccr1::basic_ostream<char, std::__ccr1::char_traits<char> >::sentry", %"class.std::__ccr1::basic_ostream<char, std::__ccr1::char_traits<char> >::sentry"* %5, i32 0, i32 0 ; [#uses=5 type=i8*]
  call void @llvm.lifetime.start.p0i8(i64 8, i8* nonnull %6) #11
  store i8 0, i8* %6, align 4, !tbaa !15
  %7 = getelementptr inbounds %"class.std::__ccr1::basic_ostream<char, std::__ccr1::char_traits<char> >::sentry", %"class.std::__ccr1::basic_ostream<char, std::__ccr1::char_traits<char> >::sentry"* %5, i32 0, i32 1 ; [#uses=1 type=%"class.std::__ccr1::basic_ostream"**]
  store %"class.std::__ccr1::basic_ostream"* %0, %"class.std::__ccr1::basic_ostream"** %7, align 4, !tbaa !12
  %8 = bitcast %"class.std::__ccr1::basic_ostream"* %0 to i8** ; [#uses=4 type=i8**]
  %9 = load i8*, i8** %8, align 4, !tbaa !13      ; [#uses=2 type=i8*]
  %10 = getelementptr i8, i8* %9, i32 -12         ; [#uses=1 type=i8*]
  %11 = bitcast i8* %10 to i32*                   ; [#uses=1 type=i32*]
  %12 = load i32, i32* %11, align 4               ; [#uses=1 type=i32]
  %13 = bitcast %"class.std::__ccr1::basic_ostream"* %0 to i8* ; [#uses=5 type=i8*]
  %14 = getelementptr inbounds i8, i8* %13, i32 %12 ; [#uses=2 type=i8*]
  %15 = getelementptr inbounds i8, i8* %14, i32 16 ; [#uses=1 type=i8*]
  %16 = bitcast i8* %15 to i32*                   ; [#uses=1 type=i32*]
  %17 = load i32, i32* %16, align 4, !tbaa !18    ; [#uses=1 type=i32]
  %18 = icmp eq i32 %17, 0                        ; [#uses=1 type=i1]
  br i1 %18, label %19, label %94

; <label>:19:                                     ; preds = %3
  %20 = getelementptr inbounds i8, i8* %14, i32 72 ; [#uses=1 type=i8*]
  %21 = bitcast i8* %20 to %"class.std::__ccr1::basic_ostream"** ; [#uses=1 type=%"class.std::__ccr1::basic_ostream"**]
  %22 = load %"class.std::__ccr1::basic_ostream"*, %"class.std::__ccr1::basic_ostream"** %21, align 4, !tbaa !22 ; [#uses=2 type=%"class.std::__ccr1::basic_ostream"*]
  %23 = icmp eq %"class.std::__ccr1::basic_ostream"* %22, null ; [#uses=1 type=i1]
  br i1 %23, label %28, label %24

; <label>:24:                                     ; preds = %19
  %25 = invoke dereferenceable(84) %"class.std::__ccr1::basic_ostream"* @_ZNSt6__ccr113basic_ostreamIcNS_11char_traitsIcEEE5flushEv(%"class.std::__ccr1::basic_ostream"* nonnull %22) #9
          to label %26 unwind label %87           ; [#uses=0 type=%"class.std::__ccr1::basic_ostream"*]

; <label>:26:                                     ; preds = %24
  %27 = load i8*, i8** %8, align 4, !tbaa !13     ; [#uses=1 type=i8*]
  br label %28

; <label>:28:                                     ; preds = %19, %26
  %29 = phi i8* [ %27, %26 ], [ %9, %19 ]         ; [#uses=1 type=i8*]
  store i8 1, i8* %6, align 4, !tbaa !15
  %30 = getelementptr i8, i8* %29, i32 -12        ; [#uses=1 type=i8*]
  %31 = bitcast i8* %30 to i32*                   ; [#uses=1 type=i32*]
  %32 = load i32, i32* %31, align 4               ; [#uses=2 type=i32]
  %33 = getelementptr inbounds i8, i8* %13, i32 %32 ; [#uses=3 type=i8*]
  %34 = getelementptr inbounds i8, i8* %33, i32 24 ; [#uses=1 type=i8*]
  %35 = bitcast i8* %34 to i32*                   ; [#uses=1 type=i32*]
  %36 = load i32, i32* %35, align 4, !tbaa !24    ; [#uses=1 type=i32]
  %37 = getelementptr inbounds i8, i8* %33, i32 4 ; [#uses=1 type=i8*]
  %38 = bitcast i8* %37 to i32*                   ; [#uses=1 type=i32*]
  %39 = load i32, i32* %38, align 4, !tbaa !25    ; [#uses=1 type=i32]
  %40 = getelementptr inbounds i8, i8* %33, i32 76 ; [#uses=1 type=i8*]
  %41 = bitcast i8* %40 to i32*                   ; [#uses=1 type=i32*]
  %42 = load i32, i32* %41, align 4, !tbaa !26    ; [#uses=2 type=i32]
  %43 = and i32 %39, 176                          ; [#uses=1 type=i32]
  %44 = getelementptr inbounds i8, i8* %13, i32 %32 ; [#uses=2 type=i8*]
  %45 = bitcast i8* %44 to %"class.std::__ccr1::ios_base"* ; [#uses=2 type=%"class.std::__ccr1::ios_base"*]
  %46 = getelementptr inbounds i8, i8* %1, i32 %2 ; [#uses=2 type=i8*]
  %47 = getelementptr inbounds i8, i8* %44, i32 76 ; [#uses=1 type=i8*]
  %48 = bitcast i8* %47 to i32*                   ; [#uses=1 type=i32*]
  %49 = icmp eq i32 %42, -1                       ; [#uses=1 type=i1]
  br i1 %49, label %50, label %67

; <label>:50:                                     ; preds = %28
  %51 = bitcast %"class.std::__ccr1::locale"* %4 to i8* ; [#uses=3 type=i8*]
  call void @llvm.lifetime.start.p0i8(i64 4, i8* nonnull %51) #11
  invoke void @_ZNKSt6__ccr18ios_base6getlocEv(%"class.std::__ccr1::locale"* nonnull sret %4, %"class.std::__ccr1::ios_base"* %45) #9
          to label %52 unwind label %92

; <label>:52:                                     ; preds = %50
  %53 = invoke %"class.std::__ccr1::locale::facet"* @_ZNKSt6__ccr16locale9use_facetERNS0_2idE(%"class.std::__ccr1::locale"* nonnull %4, %"class.std::__ccr1::locale::id"* nonnull dereferenceable(8) @_ZNSt6__ccr15ctypeIcE2idE) #9
          to label %54 unwind label %61           ; [#uses=2 type=%"class.std::__ccr1::locale::facet"*]

; <label>:54:                                     ; preds = %52
  %55 = bitcast %"class.std::__ccr1::locale::facet"* %53 to %"class.std::__ccr1::ctype"* ; [#uses=1 type=%"class.std::__ccr1::ctype"*]
  %56 = bitcast %"class.std::__ccr1::locale::facet"* %53 to i8 (%"class.std::__ccr1::ctype"*, i8)*** ; [#uses=1 type=i8 (%"class.std::__ccr1::ctype"*, i8)***]
  %57 = load i8 (%"class.std::__ccr1::ctype"*, i8)**, i8 (%"class.std::__ccr1::ctype"*, i8)*** %56, align 4, !tbaa !13 ; [#uses=1 type=i8 (%"class.std::__ccr1::ctype"*, i8)**]
  %58 = getelementptr inbounds i8 (%"class.std::__ccr1::ctype"*, i8)*, i8 (%"class.std::__ccr1::ctype"*, i8)** %57, i32 7 ; [#uses=1 type=i8 (%"class.std::__ccr1::ctype"*, i8)**]
  %59 = load i8 (%"class.std::__ccr1::ctype"*, i8)*, i8 (%"class.std::__ccr1::ctype"*, i8)** %58, align 4 ; [#uses=1 type=i8 (%"class.std::__ccr1::ctype"*, i8)*]
  %60 = invoke signext i8 %59(%"class.std::__ccr1::ctype"* %55, i8 signext 32) #9
          to label %64 unwind label %61           ; [#uses=1 type=i8]

; <label>:61:                                     ; preds = %54, %52
  %62 = landingpad { i8*, i32 }
          catch i8* null                          ; [#uses=1 type={ i8*, i32 }]
  %63 = call %"class.std::__ccr1::locale"* @_ZNSt6__ccr16localeD1Ev(%"class.std::__ccr1::locale"* nonnull %4) #10 ; [#uses=0 type=%"class.std::__ccr1::locale"*]
  call void @llvm.lifetime.end.p0i8(i64 4, i8* nonnull %51) #11
  br label %96

; <label>:64:                                     ; preds = %54
  %65 = call %"class.std::__ccr1::locale"* @_ZNSt6__ccr16localeD1Ev(%"class.std::__ccr1::locale"* nonnull %4) #10 ; [#uses=0 type=%"class.std::__ccr1::locale"*]
  call void @llvm.lifetime.end.p0i8(i64 4, i8* nonnull %51) #11
  %66 = sext i8 %60 to i32                        ; [#uses=2 type=i32]
  store i32 %66, i32* %48, align 4, !tbaa !26
  br label %67

; <label>:67:                                     ; preds = %64, %28
  %68 = phi i32 [ %66, %64 ], [ %42, %28 ]        ; [#uses=1 type=i32]
  %69 = trunc i32 %68 to i8                       ; [#uses=1 type=i8]
  %70 = icmp eq i32 %43, 32                       ; [#uses=1 type=i1]
  %71 = select i1 %70, i8* %46, i8* %1            ; [#uses=1 type=i8*]
  %72 = insertvalue [1 x i32] undef, i32 %36, 0   ; [#uses=1 type=[1 x i32]]
  %73 = invoke i32 @_ZNSt6__ccr116__pad_and_outputIcNS_19ostreambuf_iteratorIcNS_11char_traitsIcEEEEEET0_S5_PKT_S8_S8_RNS_8ios_baseES6_([1 x i32] %72, i8* %1, i8* %71, i8* %46, %"class.std::__ccr1::ios_base"* dereferenceable(72) %45, i8 signext %69) #9
          to label %74 unwind label %92           ; [#uses=1 type=i32]

; <label>:74:                                     ; preds = %67
  %75 = icmp eq i32 %73, 0                        ; [#uses=1 type=i1]
  br i1 %75, label %76, label %94

; <label>:76:                                     ; preds = %74
  %77 = load i8*, i8** %8, align 4, !tbaa !13     ; [#uses=1 type=i8*]
  %78 = getelementptr i8, i8* %77, i32 -12        ; [#uses=1 type=i8*]
  %79 = bitcast i8* %78 to i32*                   ; [#uses=1 type=i32*]
  %80 = load i32, i32* %79, align 4               ; [#uses=1 type=i32]
  %81 = getelementptr inbounds i8, i8* %13, i32 %80 ; [#uses=2 type=i8*]
  %82 = bitcast i8* %81 to %"class.std::__ccr1::ios_base"* ; [#uses=1 type=%"class.std::__ccr1::ios_base"*]
  %83 = getelementptr inbounds i8, i8* %81, i32 16 ; [#uses=1 type=i8*]
  %84 = bitcast i8* %83 to i32*                   ; [#uses=1 type=i32*]
  %85 = load i32, i32* %84, align 4, !tbaa !18    ; [#uses=1 type=i32]
  %86 = or i32 %85, 5                             ; [#uses=1 type=i32]
  invoke void @_ZNSt6__ccr18ios_base5clearEj(%"class.std::__ccr1::ios_base"* %82, i32 %86) #9
          to label %94 unwind label %90

; <label>:87:                                     ; preds = %24
  %88 = landingpad { i8*, i32 }
          catch i8* null                          ; [#uses=1 type={ i8*, i32 }]
  %89 = extractvalue { i8*, i32 } %88, 0          ; [#uses=1 type=i8*]
  br label %100

; <label>:90:                                     ; preds = %76
  %91 = landingpad { i8*, i32 }
          catch i8* null                          ; [#uses=1 type={ i8*, i32 }]
  br label %96

; <label>:92:                                     ; preds = %50, %67
  %93 = landingpad { i8*, i32 }
          catch i8* null                          ; [#uses=1 type={ i8*, i32 }]
  br label %96

; <label>:94:                                     ; preds = %3, %76, %74
  %95 = call %"class.std::__ccr1::basic_ostream<char, std::__ccr1::char_traits<char> >::sentry"* @_ZNSt6__ccr113basic_ostreamIcNS_11char_traitsIcEEE6sentryD2Ev(%"class.std::__ccr1::basic_ostream<char, std::__ccr1::char_traits<char> >::sentry"* nonnull %5) #10 ; [#uses=0 type=%"class.std::__ccr1::basic_ostream<char, std::__ccr1::char_traits<char> >::sentry"*]
  call void @llvm.lifetime.end.p0i8(i64 8, i8* nonnull %6) #11
  br label %110

; <label>:96:                                     ; preds = %92, %61, %90
  %97 = phi { i8*, i32 } [ %91, %90 ], [ %93, %92 ], [ %62, %61 ] ; [#uses=1 type={ i8*, i32 }]
  %98 = extractvalue { i8*, i32 } %97, 0          ; [#uses=1 type=i8*]
  %99 = call %"class.std::__ccr1::basic_ostream<char, std::__ccr1::char_traits<char> >::sentry"* @_ZNSt6__ccr113basic_ostreamIcNS_11char_traitsIcEEE6sentryD2Ev(%"class.std::__ccr1::basic_ostream<char, std::__ccr1::char_traits<char> >::sentry"* nonnull %5) #10 ; [#uses=0 type=%"class.std::__ccr1::basic_ostream<char, std::__ccr1::char_traits<char> >::sentry"*]
  br label %100

; <label>:100:                                    ; preds = %96, %87
  %101 = phi i8* [ %98, %96 ], [ %89, %87 ]       ; [#uses=1 type=i8*]
  call void @llvm.lifetime.end.p0i8(i64 8, i8* nonnull %6) #11
  %102 = call i8* @__cxa_begin_catch(i8* %101) #11 ; [#uses=0 type=i8*]
  %103 = load i8*, i8** %8, align 4, !tbaa !13    ; [#uses=1 type=i8*]
  %104 = getelementptr i8, i8* %103, i32 -12      ; [#uses=1 type=i8*]
  %105 = bitcast i8* %104 to i32*                 ; [#uses=1 type=i32*]
  %106 = load i32, i32* %105, align 4             ; [#uses=1 type=i32]
  %107 = getelementptr inbounds i8, i8* %13, i32 %106 ; [#uses=1 type=i8*]
  %108 = bitcast i8* %107 to %"class.std::__ccr1::ios_base"* ; [#uses=1 type=%"class.std::__ccr1::ios_base"*]
  invoke void @_ZNSt6__ccr18ios_base33__set_badbit_and_consider_rethrowEv(%"class.std::__ccr1::ios_base"* %108) #9
          to label %109 unwind label %111

; <label>:109:                                    ; preds = %100
  call void @__cxa_end_catch()
  br label %110

; <label>:110:                                    ; preds = %109, %94
  ret %"class.std::__ccr1::basic_ostream"* %0

; <label>:111:                                    ; preds = %100
  %112 = landingpad { i8*, i32 }
          cleanup                                 ; [#uses=1 type={ i8*, i32 }]
  invoke void @__cxa_end_catch()
          to label %113 unwind label %114

; <label>:113:                                    ; preds = %111
  resume { i8*, i32 } %112

; <label>:114:                                    ; preds = %111
  %115 = landingpad { i8*, i32 }
          catch i8* null                          ; [#uses=1 type={ i8*, i32 }]
  %116 = extractvalue { i8*, i32 } %115, 0        ; [#uses=1 type=i8*]
  call void @__clang_call_terminate(i8* %116) #12
  unreachable
}

; [#uses=6]
; Function Attrs: argmemonly nounwind
declare void @llvm.lifetime.start.p0i8(i64, i8* nocapture) #2

; [#uses=2]
declare i32 @__gxx_personality_sj0(...)

; [#uses=1]
; Function Attrs: optsize
define linkonce_odr hidden i32 @_ZNSt6__ccr116__pad_and_outputIcNS_19ostreambuf_iteratorIcNS_11char_traitsIcEEEEEET0_S5_PKT_S8_S8_RNS_8ios_baseES6_([1 x i32], i8*, i8*, i8*, %"class.std::__ccr1::ios_base"* dereferenceable(72), i8 signext) local_unnamed_addr #1 {
  %7 = extractvalue [1 x i32] %0, 0               ; [#uses=2 type=i32]
  %8 = ptrtoint i8* %3 to i32                     ; [#uses=1 type=i32]
  %9 = ptrtoint i8* %1 to i32                     ; [#uses=1 type=i32]
  %10 = sub i32 %8, %9                            ; [#uses=2 type=i32]
  %11 = getelementptr inbounds %"class.std::__ccr1::ios_base", %"class.std::__ccr1::ios_base"* %4, i32 0, i32 3 ; [#uses=2 type=i32*]
  %12 = load i32, i32* %11, align 4, !tbaa !27    ; [#uses=2 type=i32]
  %13 = icmp sle i32 %12, %10                     ; [#uses=1 type=i1]
  %14 = sub nsw i32 %12, %10                      ; [#uses=2 type=i32]
  %15 = icmp ult i8* %1, %2                       ; [#uses=1 type=i1]
  br i1 %15, label %16, label %44

; <label>:16:                                     ; preds = %6
  br label %17

; <label>:17:                                     ; preds = %16, %40
  %18 = phi i8* [ %42, %40 ], [ %1, %16 ]         ; [#uses=2 type=i8*]
  %19 = phi i32 [ %41, %40 ], [ %7, %16 ]         ; [#uses=5 type=i32]
  %20 = load i8, i8* %18, align 1, !tbaa !12      ; [#uses=2 type=i8]
  %21 = inttoptr i32 %19 to %"class.std::__ccr1::basic_streambuf"* ; [#uses=3 type=%"class.std::__ccr1::basic_streambuf"*]
  %22 = icmp eq i32 %19, 0                        ; [#uses=1 type=i1]
  br i1 %22, label %40, label %23

; <label>:23:                                     ; preds = %17
  %24 = getelementptr inbounds %"class.std::__ccr1::basic_streambuf", %"class.std::__ccr1::basic_streambuf"* %21, i32 0, i32 6 ; [#uses=2 type=i8**]
  %25 = load i8*, i8** %24, align 4, !tbaa !28    ; [#uses=3 type=i8*]
  %26 = getelementptr inbounds %"class.std::__ccr1::basic_streambuf", %"class.std::__ccr1::basic_streambuf"* %21, i32 0, i32 7 ; [#uses=1 type=i8**]
  %27 = load i8*, i8** %26, align 4, !tbaa !31    ; [#uses=1 type=i8*]
  %28 = icmp eq i8* %25, %27                      ; [#uses=1 type=i1]
  br i1 %28, label %31, label %29

; <label>:29:                                     ; preds = %23
  %30 = getelementptr inbounds i8, i8* %25, i32 1 ; [#uses=1 type=i8*]
  store i8* %30, i8** %24, align 4, !tbaa !28
  store i8 %20, i8* %25, align 1, !tbaa !12
  br label %40

; <label>:31:                                     ; preds = %23
  %32 = inttoptr i32 %19 to i32 (%"class.std::__ccr1::basic_streambuf"*, i32)*** ; [#uses=1 type=i32 (%"class.std::__ccr1::basic_streambuf"*, i32)***]
  %33 = load i32 (%"class.std::__ccr1::basic_streambuf"*, i32)**, i32 (%"class.std::__ccr1::basic_streambuf"*, i32)*** %32, align 4, !tbaa !13 ; [#uses=1 type=i32 (%"class.std::__ccr1::basic_streambuf"*, i32)**]
  %34 = getelementptr inbounds i32 (%"class.std::__ccr1::basic_streambuf"*, i32)*, i32 (%"class.std::__ccr1::basic_streambuf"*, i32)** %33, i32 13 ; [#uses=1 type=i32 (%"class.std::__ccr1::basic_streambuf"*, i32)**]
  %35 = load i32 (%"class.std::__ccr1::basic_streambuf"*, i32)*, i32 (%"class.std::__ccr1::basic_streambuf"*, i32)** %34, align 4 ; [#uses=1 type=i32 (%"class.std::__ccr1::basic_streambuf"*, i32)*]
  %36 = zext i8 %20 to i32                        ; [#uses=1 type=i32]
  %37 = tail call i32 %35(%"class.std::__ccr1::basic_streambuf"* nonnull %21, i32 %36) #9 ; [#uses=1 type=i32]
  %38 = icmp eq i32 %37, -1                       ; [#uses=1 type=i1]
  %39 = select i1 %38, i32 0, i32 %19             ; [#uses=1 type=i32]
  br label %40

; <label>:40:                                     ; preds = %31, %17, %29
  %41 = phi i32 [ 0, %17 ], [ %19, %29 ], [ %39, %31 ] ; [#uses=2 type=i32]
  %42 = getelementptr inbounds i8, i8* %18, i32 1 ; [#uses=2 type=i8*]
  %43 = icmp eq i8* %42, %2                       ; [#uses=1 type=i1]
  br i1 %43, label %44, label %17

; <label>:44:                                     ; preds = %40, %6
  %45 = phi i32 [ %7, %6 ], [ %41, %40 ]          ; [#uses=2 type=i32]
  %46 = phi i8* [ %1, %6 ], [ %2, %40 ]           ; [#uses=2 type=i8*]
  %47 = icmp eq i32 %14, 0                        ; [#uses=1 type=i1]
  %48 = or i1 %47, %13                            ; [#uses=1 type=i1]
  br i1 %48, label %76, label %49

; <label>:49:                                     ; preds = %44
  %50 = zext i8 %5 to i32                         ; [#uses=1 type=i32]
  br label %51

; <label>:51:                                     ; preds = %49, %72
  %52 = phi i32 [ %14, %49 ], [ %74, %72 ]        ; [#uses=1 type=i32]
  %53 = phi i32 [ %45, %49 ], [ %73, %72 ]        ; [#uses=5 type=i32]
  %54 = inttoptr i32 %53 to %"class.std::__ccr1::basic_streambuf"* ; [#uses=3 type=%"class.std::__ccr1::basic_streambuf"*]
  %55 = icmp eq i32 %53, 0                        ; [#uses=1 type=i1]
  br i1 %55, label %72, label %56

; <label>:56:                                     ; preds = %51
  %57 = getelementptr inbounds %"class.std::__ccr1::basic_streambuf", %"class.std::__ccr1::basic_streambuf"* %54, i32 0, i32 6 ; [#uses=2 type=i8**]
  %58 = load i8*, i8** %57, align 4, !tbaa !28    ; [#uses=3 type=i8*]
  %59 = getelementptr inbounds %"class.std::__ccr1::basic_streambuf", %"class.std::__ccr1::basic_streambuf"* %54, i32 0, i32 7 ; [#uses=1 type=i8**]
  %60 = load i8*, i8** %59, align 4, !tbaa !31    ; [#uses=1 type=i8*]
  %61 = icmp eq i8* %58, %60                      ; [#uses=1 type=i1]
  br i1 %61, label %64, label %62

; <label>:62:                                     ; preds = %56
  %63 = getelementptr inbounds i8, i8* %58, i32 1 ; [#uses=1 type=i8*]
  store i8* %63, i8** %57, align 4, !tbaa !28
  store i8 %5, i8* %58, align 1, !tbaa !12
  br label %72

; <label>:64:                                     ; preds = %56
  %65 = inttoptr i32 %53 to i32 (%"class.std::__ccr1::basic_streambuf"*, i32)*** ; [#uses=1 type=i32 (%"class.std::__ccr1::basic_streambuf"*, i32)***]
  %66 = load i32 (%"class.std::__ccr1::basic_streambuf"*, i32)**, i32 (%"class.std::__ccr1::basic_streambuf"*, i32)*** %65, align 4, !tbaa !13 ; [#uses=1 type=i32 (%"class.std::__ccr1::basic_streambuf"*, i32)**]
  %67 = getelementptr inbounds i32 (%"class.std::__ccr1::basic_streambuf"*, i32)*, i32 (%"class.std::__ccr1::basic_streambuf"*, i32)** %66, i32 13 ; [#uses=1 type=i32 (%"class.std::__ccr1::basic_streambuf"*, i32)**]
  %68 = load i32 (%"class.std::__ccr1::basic_streambuf"*, i32)*, i32 (%"class.std::__ccr1::basic_streambuf"*, i32)** %67, align 4 ; [#uses=1 type=i32 (%"class.std::__ccr1::basic_streambuf"*, i32)*]
  %69 = tail call i32 %68(%"class.std::__ccr1::basic_streambuf"* nonnull %54, i32 %50) #9 ; [#uses=1 type=i32]
  %70 = icmp eq i32 %69, -1                       ; [#uses=1 type=i1]
  %71 = select i1 %70, i32 0, i32 %53             ; [#uses=1 type=i32]
  br label %72

; <label>:72:                                     ; preds = %64, %51, %62
  %73 = phi i32 [ 0, %51 ], [ %53, %62 ], [ %71, %64 ] ; [#uses=2 type=i32]
  %74 = add nsw i32 %52, -1                       ; [#uses=2 type=i32]
  %75 = icmp eq i32 %74, 0                        ; [#uses=1 type=i1]
  br i1 %75, label %76, label %51

; <label>:76:                                     ; preds = %72, %44
  %77 = phi i32 [ %45, %44 ], [ %73, %72 ]        ; [#uses=2 type=i32]
  %78 = icmp ult i8* %46, %3                      ; [#uses=1 type=i1]
  br i1 %78, label %79, label %107

; <label>:79:                                     ; preds = %76
  br label %80

; <label>:80:                                     ; preds = %79, %103
  %81 = phi i8* [ %105, %103 ], [ %46, %79 ]      ; [#uses=2 type=i8*]
  %82 = phi i32 [ %104, %103 ], [ %77, %79 ]      ; [#uses=5 type=i32]
  %83 = load i8, i8* %81, align 1, !tbaa !12      ; [#uses=2 type=i8]
  %84 = inttoptr i32 %82 to %"class.std::__ccr1::basic_streambuf"* ; [#uses=3 type=%"class.std::__ccr1::basic_streambuf"*]
  %85 = icmp eq i32 %82, 0                        ; [#uses=1 type=i1]
  br i1 %85, label %103, label %86

; <label>:86:                                     ; preds = %80
  %87 = getelementptr inbounds %"class.std::__ccr1::basic_streambuf", %"class.std::__ccr1::basic_streambuf"* %84, i32 0, i32 6 ; [#uses=2 type=i8**]
  %88 = load i8*, i8** %87, align 4, !tbaa !28    ; [#uses=3 type=i8*]
  %89 = getelementptr inbounds %"class.std::__ccr1::basic_streambuf", %"class.std::__ccr1::basic_streambuf"* %84, i32 0, i32 7 ; [#uses=1 type=i8**]
  %90 = load i8*, i8** %89, align 4, !tbaa !31    ; [#uses=1 type=i8*]
  %91 = icmp eq i8* %88, %90                      ; [#uses=1 type=i1]
  br i1 %91, label %94, label %92

; <label>:92:                                     ; preds = %86
  %93 = getelementptr inbounds i8, i8* %88, i32 1 ; [#uses=1 type=i8*]
  store i8* %93, i8** %87, align 4, !tbaa !28
  store i8 %83, i8* %88, align 1, !tbaa !12
  br label %103

; <label>:94:                                     ; preds = %86
  %95 = inttoptr i32 %82 to i32 (%"class.std::__ccr1::basic_streambuf"*, i32)*** ; [#uses=1 type=i32 (%"class.std::__ccr1::basic_streambuf"*, i32)***]
  %96 = load i32 (%"class.std::__ccr1::basic_streambuf"*, i32)**, i32 (%"class.std::__ccr1::basic_streambuf"*, i32)*** %95, align 4, !tbaa !13 ; [#uses=1 type=i32 (%"class.std::__ccr1::basic_streambuf"*, i32)**]
  %97 = getelementptr inbounds i32 (%"class.std::__ccr1::basic_streambuf"*, i32)*, i32 (%"class.std::__ccr1::basic_streambuf"*, i32)** %96, i32 13 ; [#uses=1 type=i32 (%"class.std::__ccr1::basic_streambuf"*, i32)**]
  %98 = load i32 (%"class.std::__ccr1::basic_streambuf"*, i32)*, i32 (%"class.std::__ccr1::basic_streambuf"*, i32)** %97, align 4 ; [#uses=1 type=i32 (%"class.std::__ccr1::basic_streambuf"*, i32)*]
  %99 = zext i8 %83 to i32                        ; [#uses=1 type=i32]
  %100 = tail call i32 %98(%"class.std::__ccr1::basic_streambuf"* nonnull %84, i32 %99) #9 ; [#uses=1 type=i32]
  %101 = icmp eq i32 %100, -1                     ; [#uses=1 type=i1]
  %102 = select i1 %101, i32 0, i32 %82           ; [#uses=1 type=i32]
  br label %103

; <label>:103:                                    ; preds = %94, %80, %92
  %104 = phi i32 [ 0, %80 ], [ %82, %92 ], [ %102, %94 ] ; [#uses=2 type=i32]
  %105 = getelementptr inbounds i8, i8* %81, i32 1 ; [#uses=2 type=i8*]
  %106 = icmp eq i8* %105, %3                     ; [#uses=1 type=i1]
  br i1 %106, label %107, label %80

; <label>:107:                                    ; preds = %103, %76
  %108 = phi i32 [ %77, %76 ], [ %104, %103 ]     ; [#uses=1 type=i32]
  store i32 0, i32* %11, align 4, !tbaa !27
  ret i32 %108
}

; [#uses=11]
; Function Attrs: argmemonly nounwind
declare void @llvm.lifetime.end.p0i8(i64, i8* nocapture) #2

; [#uses=5]
declare i8* @__cxa_begin_catch(i8*) local_unnamed_addr

; [#uses=3]
; Function Attrs: optsize
declare void @_ZNSt6__ccr18ios_base33__set_badbit_and_consider_rethrowEv(%"class.std::__ccr1::ios_base"*) local_unnamed_addr #3

; [#uses=7]
declare void @__cxa_end_catch() local_unnamed_addr

; [#uses=4]
; Function Attrs: noinline noreturn nounwind
define linkonce_odr hidden void @__clang_call_terminate(i8*) local_unnamed_addr #4 {
  %2 = tail call i8* @__cxa_begin_catch(i8* %0) #11 ; [#uses=0 type=i8*]
  tail call void @_ZSt9terminatev() #12
  unreachable
}

; [#uses=1]
declare void @_ZSt9terminatev() local_unnamed_addr

; [#uses=1]
; Function Attrs: optsize
define linkonce_odr %"class.std::__ccr1::basic_ostream<char, std::__ccr1::char_traits<char> >::sentry"* @_ZNSt6__ccr113basic_ostreamIcNS_11char_traitsIcEEE6sentryC2ERS3_(%"class.std::__ccr1::basic_ostream<char, std::__ccr1::char_traits<char> >::sentry"* returned, %"class.std::__ccr1::basic_ostream"* dereferenceable(84)) unnamed_addr #1 align 2 {
  %3 = getelementptr inbounds %"class.std::__ccr1::basic_ostream<char, std::__ccr1::char_traits<char> >::sentry", %"class.std::__ccr1::basic_ostream<char, std::__ccr1::char_traits<char> >::sentry"* %0, i32 0, i32 0 ; [#uses=2 type=i8*]
  store i8 0, i8* %3, align 4, !tbaa !15
  %4 = getelementptr inbounds %"class.std::__ccr1::basic_ostream<char, std::__ccr1::char_traits<char> >::sentry", %"class.std::__ccr1::basic_ostream<char, std::__ccr1::char_traits<char> >::sentry"* %0, i32 0, i32 1 ; [#uses=1 type=%"class.std::__ccr1::basic_ostream"**]
  store %"class.std::__ccr1::basic_ostream"* %1, %"class.std::__ccr1::basic_ostream"** %4, align 4, !tbaa !12
  %5 = bitcast %"class.std::__ccr1::basic_ostream"* %1 to i8** ; [#uses=1 type=i8**]
  %6 = load i8*, i8** %5, align 4, !tbaa !13      ; [#uses=1 type=i8*]
  %7 = getelementptr i8, i8* %6, i32 -12          ; [#uses=1 type=i8*]
  %8 = bitcast i8* %7 to i32*                     ; [#uses=1 type=i32*]
  %9 = load i32, i32* %8, align 4                 ; [#uses=1 type=i32]
  %10 = bitcast %"class.std::__ccr1::basic_ostream"* %1 to i8* ; [#uses=1 type=i8*]
  %11 = getelementptr inbounds i8, i8* %10, i32 %9 ; [#uses=2 type=i8*]
  %12 = getelementptr inbounds i8, i8* %11, i32 16 ; [#uses=1 type=i8*]
  %13 = bitcast i8* %12 to i32*                   ; [#uses=1 type=i32*]
  %14 = load i32, i32* %13, align 4, !tbaa !18    ; [#uses=1 type=i32]
  %15 = icmp eq i32 %14, 0                        ; [#uses=1 type=i1]
  br i1 %15, label %16, label %24

; <label>:16:                                     ; preds = %2
  %17 = getelementptr inbounds i8, i8* %11, i32 72 ; [#uses=1 type=i8*]
  %18 = bitcast i8* %17 to %"class.std::__ccr1::basic_ostream"** ; [#uses=1 type=%"class.std::__ccr1::basic_ostream"**]
  %19 = load %"class.std::__ccr1::basic_ostream"*, %"class.std::__ccr1::basic_ostream"** %18, align 4, !tbaa !22 ; [#uses=2 type=%"class.std::__ccr1::basic_ostream"*]
  %20 = icmp eq %"class.std::__ccr1::basic_ostream"* %19, null ; [#uses=1 type=i1]
  br i1 %20, label %23, label %21

; <label>:21:                                     ; preds = %16
  %22 = tail call dereferenceable(84) %"class.std::__ccr1::basic_ostream"* @_ZNSt6__ccr113basic_ostreamIcNS_11char_traitsIcEEE5flushEv(%"class.std::__ccr1::basic_ostream"* nonnull %19) #9 ; [#uses=0 type=%"class.std::__ccr1::basic_ostream"*]
  br label %23

; <label>:23:                                     ; preds = %16, %21
  store i8 1, i8* %3, align 4, !tbaa !15
  br label %24

; <label>:24:                                     ; preds = %23, %2
  ret %"class.std::__ccr1::basic_ostream<char, std::__ccr1::char_traits<char> >::sentry"* %0
}

; [#uses=4]
; Function Attrs: optsize
define linkonce_odr dereferenceable(84) %"class.std::__ccr1::basic_ostream"* @_ZNSt6__ccr113basic_ostreamIcNS_11char_traitsIcEEE5flushEv(%"class.std::__ccr1::basic_ostream"*) local_unnamed_addr #1 align 2 personality i8* bitcast (i32 (...)* @__gxx_personality_sj0 to i8*) {
  %2 = alloca %"class.std::__ccr1::basic_ostream<char, std::__ccr1::char_traits<char> >::sentry", align 4 ; [#uses=4 type=%"class.std::__ccr1::basic_ostream<char, std::__ccr1::char_traits<char> >::sentry"*]
  %3 = bitcast %"class.std::__ccr1::basic_ostream"* %0 to i8** ; [#uses=4 type=i8**]
  %4 = load i8*, i8** %3, align 4, !tbaa !13      ; [#uses=1 type=i8*]
  %5 = getelementptr i8, i8* %4, i32 -12          ; [#uses=1 type=i8*]
  %6 = bitcast i8* %5 to i32*                     ; [#uses=1 type=i32*]
  %7 = load i32, i32* %6, align 4                 ; [#uses=1 type=i32]
  %8 = bitcast %"class.std::__ccr1::basic_ostream"* %0 to i8* ; [#uses=4 type=i8*]
  %9 = getelementptr inbounds i8, i8* %8, i32 %7  ; [#uses=1 type=i8*]
  %10 = getelementptr inbounds i8, i8* %9, i32 24 ; [#uses=1 type=i8*]
  %11 = bitcast i8* %10 to %"class.std::__ccr1::basic_streambuf"** ; [#uses=1 type=%"class.std::__ccr1::basic_streambuf"**]
  %12 = load %"class.std::__ccr1::basic_streambuf"*, %"class.std::__ccr1::basic_streambuf"** %11, align 4, !tbaa !24 ; [#uses=1 type=%"class.std::__ccr1::basic_streambuf"*]
  %13 = icmp eq %"class.std::__ccr1::basic_streambuf"* %12, null ; [#uses=1 type=i1]
  br i1 %13, label %66, label %14

; <label>:14:                                     ; preds = %1
  %15 = getelementptr inbounds %"class.std::__ccr1::basic_ostream<char, std::__ccr1::char_traits<char> >::sentry", %"class.std::__ccr1::basic_ostream<char, std::__ccr1::char_traits<char> >::sentry"* %2, i32 0, i32 0 ; [#uses=4 type=i8*]
  call void @llvm.lifetime.start.p0i8(i64 8, i8* nonnull %15) #11
  %16 = invoke %"class.std::__ccr1::basic_ostream<char, std::__ccr1::char_traits<char> >::sentry"* @_ZNSt6__ccr113basic_ostreamIcNS_11char_traitsIcEEE6sentryC2ERS3_(%"class.std::__ccr1::basic_ostream<char, std::__ccr1::char_traits<char> >::sentry"* nonnull %2, %"class.std::__ccr1::basic_ostream"* nonnull dereferenceable(84) %0) #9
          to label %17 unwind label %47           ; [#uses=0 type=%"class.std::__ccr1::basic_ostream<char, std::__ccr1::char_traits<char> >::sentry"*]

; <label>:17:                                     ; preds = %14
  %18 = load i8, i8* %15, align 4, !tbaa !15, !range !32 ; [#uses=1 type=i8]
  %19 = icmp eq i8 %18, 0                         ; [#uses=1 type=i1]
  br i1 %19, label %54, label %20

; <label>:20:                                     ; preds = %17
  %21 = load i8*, i8** %3, align 4, !tbaa !13     ; [#uses=1 type=i8*]
  %22 = getelementptr i8, i8* %21, i32 -12        ; [#uses=1 type=i8*]
  %23 = bitcast i8* %22 to i32*                   ; [#uses=1 type=i32*]
  %24 = load i32, i32* %23, align 4               ; [#uses=1 type=i32]
  %25 = getelementptr inbounds i8, i8* %8, i32 %24 ; [#uses=1 type=i8*]
  %26 = getelementptr inbounds i8, i8* %25, i32 24 ; [#uses=1 type=i8*]
  %27 = bitcast i8* %26 to %"class.std::__ccr1::basic_streambuf"** ; [#uses=1 type=%"class.std::__ccr1::basic_streambuf"**]
  %28 = load %"class.std::__ccr1::basic_streambuf"*, %"class.std::__ccr1::basic_streambuf"** %27, align 4, !tbaa !24 ; [#uses=2 type=%"class.std::__ccr1::basic_streambuf"*]
  %29 = bitcast %"class.std::__ccr1::basic_streambuf"* %28 to i32 (%"class.std::__ccr1::basic_streambuf"*)*** ; [#uses=1 type=i32 (%"class.std::__ccr1::basic_streambuf"*)***]
  %30 = load i32 (%"class.std::__ccr1::basic_streambuf"*)**, i32 (%"class.std::__ccr1::basic_streambuf"*)*** %29, align 4, !tbaa !13 ; [#uses=1 type=i32 (%"class.std::__ccr1::basic_streambuf"*)**]
  %31 = getelementptr inbounds i32 (%"class.std::__ccr1::basic_streambuf"*)*, i32 (%"class.std::__ccr1::basic_streambuf"*)** %30, i32 6 ; [#uses=1 type=i32 (%"class.std::__ccr1::basic_streambuf"*)**]
  %32 = load i32 (%"class.std::__ccr1::basic_streambuf"*)*, i32 (%"class.std::__ccr1::basic_streambuf"*)** %31, align 4 ; [#uses=1 type=i32 (%"class.std::__ccr1::basic_streambuf"*)*]
  %33 = invoke i32 %32(%"class.std::__ccr1::basic_streambuf"* %28) #9
          to label %34 unwind label %50           ; [#uses=1 type=i32]

; <label>:34:                                     ; preds = %20
  %35 = icmp eq i32 %33, -1                       ; [#uses=1 type=i1]
  br i1 %35, label %36, label %54

; <label>:36:                                     ; preds = %34
  %37 = load i8*, i8** %3, align 4, !tbaa !13     ; [#uses=1 type=i8*]
  %38 = getelementptr i8, i8* %37, i32 -12        ; [#uses=1 type=i8*]
  %39 = bitcast i8* %38 to i32*                   ; [#uses=1 type=i32*]
  %40 = load i32, i32* %39, align 4               ; [#uses=1 type=i32]
  %41 = getelementptr inbounds i8, i8* %8, i32 %40 ; [#uses=2 type=i8*]
  %42 = bitcast i8* %41 to %"class.std::__ccr1::ios_base"* ; [#uses=1 type=%"class.std::__ccr1::ios_base"*]
  %43 = getelementptr inbounds i8, i8* %41, i32 16 ; [#uses=1 type=i8*]
  %44 = bitcast i8* %43 to i32*                   ; [#uses=1 type=i32*]
  %45 = load i32, i32* %44, align 4, !tbaa !18    ; [#uses=1 type=i32]
  %46 = or i32 %45, 1                             ; [#uses=1 type=i32]
  invoke void @_ZNSt6__ccr18ios_base5clearEj(%"class.std::__ccr1::ios_base"* %42, i32 %46) #9
          to label %54 unwind label %50

; <label>:47:                                     ; preds = %14
  %48 = landingpad { i8*, i32 }
          catch i8* null                          ; [#uses=1 type={ i8*, i32 }]
  %49 = extractvalue { i8*, i32 } %48, 0          ; [#uses=1 type=i8*]
  br label %56

; <label>:50:                                     ; preds = %36, %20
  %51 = landingpad { i8*, i32 }
          catch i8* null                          ; [#uses=1 type={ i8*, i32 }]
  %52 = extractvalue { i8*, i32 } %51, 0          ; [#uses=1 type=i8*]
  %53 = call %"class.std::__ccr1::basic_ostream<char, std::__ccr1::char_traits<char> >::sentry"* @_ZNSt6__ccr113basic_ostreamIcNS_11char_traitsIcEEE6sentryD2Ev(%"class.std::__ccr1::basic_ostream<char, std::__ccr1::char_traits<char> >::sentry"* nonnull %2) #10 ; [#uses=0 type=%"class.std::__ccr1::basic_ostream<char, std::__ccr1::char_traits<char> >::sentry"*]
  br label %56

; <label>:54:                                     ; preds = %17, %36, %34
  %55 = call %"class.std::__ccr1::basic_ostream<char, std::__ccr1::char_traits<char> >::sentry"* @_ZNSt6__ccr113basic_ostreamIcNS_11char_traitsIcEEE6sentryD2Ev(%"class.std::__ccr1::basic_ostream<char, std::__ccr1::char_traits<char> >::sentry"* nonnull %2) #10 ; [#uses=0 type=%"class.std::__ccr1::basic_ostream<char, std::__ccr1::char_traits<char> >::sentry"*]
  call void @llvm.lifetime.end.p0i8(i64 8, i8* nonnull %15) #11
  br label %66

; <label>:56:                                     ; preds = %47, %50
  %57 = phi i8* [ %52, %50 ], [ %49, %47 ]        ; [#uses=1 type=i8*]
  call void @llvm.lifetime.end.p0i8(i64 8, i8* nonnull %15) #11
  %58 = call i8* @__cxa_begin_catch(i8* %57) #11  ; [#uses=0 type=i8*]
  %59 = load i8*, i8** %3, align 4, !tbaa !13     ; [#uses=1 type=i8*]
  %60 = getelementptr i8, i8* %59, i32 -12        ; [#uses=1 type=i8*]
  %61 = bitcast i8* %60 to i32*                   ; [#uses=1 type=i32*]
  %62 = load i32, i32* %61, align 4               ; [#uses=1 type=i32]
  %63 = getelementptr inbounds i8, i8* %8, i32 %62 ; [#uses=1 type=i8*]
  %64 = bitcast i8* %63 to %"class.std::__ccr1::ios_base"* ; [#uses=1 type=%"class.std::__ccr1::ios_base"*]
  invoke void @_ZNSt6__ccr18ios_base33__set_badbit_and_consider_rethrowEv(%"class.std::__ccr1::ios_base"* %64) #9
          to label %65 unwind label %67

; <label>:65:                                     ; preds = %56
  call void @__cxa_end_catch()
  br label %66

; <label>:66:                                     ; preds = %1, %54, %65
  ret %"class.std::__ccr1::basic_ostream"* %0

; <label>:67:                                     ; preds = %56
  %68 = landingpad { i8*, i32 }
          cleanup                                 ; [#uses=1 type={ i8*, i32 }]
  invoke void @__cxa_end_catch()
          to label %69 unwind label %70

; <label>:69:                                     ; preds = %67
  resume { i8*, i32 } %68

; <label>:70:                                     ; preds = %67
  %71 = landingpad { i8*, i32 }
          catch i8* null                          ; [#uses=1 type={ i8*, i32 }]
  %72 = extractvalue { i8*, i32 } %71, 0          ; [#uses=1 type=i8*]
  call void @__clang_call_terminate(i8* %72) #12
  unreachable
}

; [#uses=2]
; Function Attrs: optsize
declare void @_ZNKSt6__ccr18ios_base6getlocEv(%"class.std::__ccr1::locale"* sret, %"class.std::__ccr1::ios_base"*) local_unnamed_addr #3

; [#uses=4]
; Function Attrs: nounwind optsize
declare %"class.std::__ccr1::locale"* @_ZNSt6__ccr16localeD1Ev(%"class.std::__ccr1::locale"* returned) unnamed_addr #5

; [#uses=2]
; Function Attrs: optsize
declare %"class.std::__ccr1::locale::facet"* @_ZNKSt6__ccr16locale9use_facetERNS0_2idE(%"class.std::__ccr1::locale"*, %"class.std::__ccr1::locale::id"* dereferenceable(8)) local_unnamed_addr #3

; [#uses=4]
; Function Attrs: optsize
declare void @_ZNSt6__ccr18ios_base5clearEj(%"class.std::__ccr1::ios_base"*, i32) local_unnamed_addr #3

; [#uses=6]
; Function Attrs: nounwind optsize
define linkonce_odr %"class.std::__ccr1::basic_ostream<char, std::__ccr1::char_traits<char> >::sentry"* @_ZNSt6__ccr113basic_ostreamIcNS_11char_traitsIcEEE6sentryD2Ev(%"class.std::__ccr1::basic_ostream<char, std::__ccr1::char_traits<char> >::sentry"* returned) unnamed_addr #6 align 2 personality i8* bitcast (i32 (...)* @__gxx_personality_sj0 to i8*) {
  %2 = getelementptr inbounds %"class.std::__ccr1::basic_ostream<char, std::__ccr1::char_traits<char> >::sentry", %"class.std::__ccr1::basic_ostream<char, std::__ccr1::char_traits<char> >::sentry"* %0, i32 0, i32 1 ; [#uses=3 type=%"class.std::__ccr1::basic_ostream"**]
  %3 = load %"class.std::__ccr1::basic_ostream"*, %"class.std::__ccr1::basic_ostream"** %2, align 4, !tbaa !12 ; [#uses=2 type=%"class.std::__ccr1::basic_ostream"*]
  %4 = bitcast %"class.std::__ccr1::basic_ostream"* %3 to i8** ; [#uses=1 type=i8**]
  %5 = load i8*, i8** %4, align 4, !tbaa !13      ; [#uses=1 type=i8*]
  %6 = getelementptr i8, i8* %5, i32 -12          ; [#uses=1 type=i8*]
  %7 = bitcast i8* %6 to i32*                     ; [#uses=1 type=i32*]
  %8 = load i32, i32* %7, align 4                 ; [#uses=1 type=i32]
  %9 = bitcast %"class.std::__ccr1::basic_ostream"* %3 to i8* ; [#uses=1 type=i8*]
  %10 = getelementptr inbounds i8, i8* %9, i32 %8 ; [#uses=3 type=i8*]
  %11 = getelementptr inbounds i8, i8* %10, i32 24 ; [#uses=1 type=i8*]
  %12 = bitcast i8* %11 to %"class.std::__ccr1::basic_streambuf"** ; [#uses=1 type=%"class.std::__ccr1::basic_streambuf"**]
  %13 = load %"class.std::__ccr1::basic_streambuf"*, %"class.std::__ccr1::basic_streambuf"** %12, align 4, !tbaa !24 ; [#uses=1 type=%"class.std::__ccr1::basic_streambuf"*]
  %14 = icmp eq %"class.std::__ccr1::basic_streambuf"* %13, null ; [#uses=1 type=i1]
  br i1 %14, label %65, label %15

; <label>:15:                                     ; preds = %1
  %16 = getelementptr inbounds i8, i8* %10, i32 16 ; [#uses=1 type=i8*]
  %17 = bitcast i8* %16 to i32*                   ; [#uses=1 type=i32*]
  %18 = load i32, i32* %17, align 4, !tbaa !18    ; [#uses=1 type=i32]
  %19 = icmp eq i32 %18, 0                        ; [#uses=1 type=i1]
  br i1 %19, label %20, label %65

; <label>:20:                                     ; preds = %15
  %21 = getelementptr inbounds i8, i8* %10, i32 4 ; [#uses=1 type=i8*]
  %22 = bitcast i8* %21 to i32*                   ; [#uses=1 type=i32*]
  %23 = load i32, i32* %22, align 4, !tbaa !25    ; [#uses=1 type=i32]
  %24 = and i32 %23, 8192                         ; [#uses=1 type=i32]
  %25 = icmp eq i32 %24, 0                        ; [#uses=1 type=i1]
  br i1 %25, label %65, label %26

; <label>:26:                                     ; preds = %20
  %27 = tail call zeroext i1 @_ZSt18uncaught_exceptionv() #10 ; [#uses=1 type=i1]
  br i1 %27, label %65, label %28

; <label>:28:                                     ; preds = %26
  %29 = load %"class.std::__ccr1::basic_ostream"*, %"class.std::__ccr1::basic_ostream"** %2, align 4, !tbaa !12 ; [#uses=2 type=%"class.std::__ccr1::basic_ostream"*]
  %30 = bitcast %"class.std::__ccr1::basic_ostream"* %29 to i8** ; [#uses=1 type=i8**]
  %31 = load i8*, i8** %30, align 4, !tbaa !13    ; [#uses=1 type=i8*]
  %32 = getelementptr i8, i8* %31, i32 -12        ; [#uses=1 type=i8*]
  %33 = bitcast i8* %32 to i32*                   ; [#uses=1 type=i32*]
  %34 = load i32, i32* %33, align 4               ; [#uses=1 type=i32]
  %35 = bitcast %"class.std::__ccr1::basic_ostream"* %29 to i8* ; [#uses=1 type=i8*]
  %36 = getelementptr inbounds i8, i8* %35, i32 %34 ; [#uses=1 type=i8*]
  %37 = getelementptr inbounds i8, i8* %36, i32 24 ; [#uses=1 type=i8*]
  %38 = bitcast i8* %37 to %"class.std::__ccr1::basic_streambuf"** ; [#uses=1 type=%"class.std::__ccr1::basic_streambuf"**]
  %39 = load %"class.std::__ccr1::basic_streambuf"*, %"class.std::__ccr1::basic_streambuf"** %38, align 4, !tbaa !24 ; [#uses=2 type=%"class.std::__ccr1::basic_streambuf"*]
  %40 = bitcast %"class.std::__ccr1::basic_streambuf"* %39 to i32 (%"class.std::__ccr1::basic_streambuf"*)*** ; [#uses=1 type=i32 (%"class.std::__ccr1::basic_streambuf"*)***]
  %41 = load i32 (%"class.std::__ccr1::basic_streambuf"*)**, i32 (%"class.std::__ccr1::basic_streambuf"*)*** %40, align 4, !tbaa !13 ; [#uses=1 type=i32 (%"class.std::__ccr1::basic_streambuf"*)**]
  %42 = getelementptr inbounds i32 (%"class.std::__ccr1::basic_streambuf"*)*, i32 (%"class.std::__ccr1::basic_streambuf"*)** %41, i32 6 ; [#uses=1 type=i32 (%"class.std::__ccr1::basic_streambuf"*)**]
  %43 = load i32 (%"class.std::__ccr1::basic_streambuf"*)*, i32 (%"class.std::__ccr1::basic_streambuf"*)** %42, align 4 ; [#uses=1 type=i32 (%"class.std::__ccr1::basic_streambuf"*)*]
  %44 = invoke i32 %43(%"class.std::__ccr1::basic_streambuf"* %39) #9
          to label %45 unwind label %61           ; [#uses=1 type=i32]

; <label>:45:                                     ; preds = %28
  %46 = icmp eq i32 %44, -1                       ; [#uses=1 type=i1]
  br i1 %46, label %47, label %65

; <label>:47:                                     ; preds = %45
  %48 = load %"class.std::__ccr1::basic_ostream"*, %"class.std::__ccr1::basic_ostream"** %2, align 4, !tbaa !12 ; [#uses=2 type=%"class.std::__ccr1::basic_ostream"*]
  %49 = bitcast %"class.std::__ccr1::basic_ostream"* %48 to i8** ; [#uses=1 type=i8**]
  %50 = load i8*, i8** %49, align 4, !tbaa !13    ; [#uses=1 type=i8*]
  %51 = getelementptr i8, i8* %50, i32 -12        ; [#uses=1 type=i8*]
  %52 = bitcast i8* %51 to i32*                   ; [#uses=1 type=i32*]
  %53 = load i32, i32* %52, align 4               ; [#uses=1 type=i32]
  %54 = bitcast %"class.std::__ccr1::basic_ostream"* %48 to i8* ; [#uses=1 type=i8*]
  %55 = getelementptr inbounds i8, i8* %54, i32 %53 ; [#uses=2 type=i8*]
  %56 = bitcast i8* %55 to %"class.std::__ccr1::ios_base"* ; [#uses=1 type=%"class.std::__ccr1::ios_base"*]
  %57 = getelementptr inbounds i8, i8* %55, i32 16 ; [#uses=1 type=i8*]
  %58 = bitcast i8* %57 to i32*                   ; [#uses=1 type=i32*]
  %59 = load i32, i32* %58, align 4, !tbaa !18    ; [#uses=1 type=i32]
  %60 = or i32 %59, 1                             ; [#uses=1 type=i32]
  invoke void @_ZNSt6__ccr18ios_base5clearEj(%"class.std::__ccr1::ios_base"* %56, i32 %60) #9
          to label %65 unwind label %61

; <label>:61:                                     ; preds = %28, %47
  %62 = landingpad { i8*, i32 }
          catch i8* null                          ; [#uses=1 type={ i8*, i32 }]
  %63 = extractvalue { i8*, i32 } %62, 0          ; [#uses=1 type=i8*]
  %64 = tail call i8* @__cxa_begin_catch(i8* %63) #11 ; [#uses=0 type=i8*]
  invoke void @__cxa_end_catch()
          to label %65 unwind label %66

; <label>:65:                                     ; preds = %47, %20, %1, %45, %61, %26, %15
  ret %"class.std::__ccr1::basic_ostream<char, std::__ccr1::char_traits<char> >::sentry"* %0

; <label>:66:                                     ; preds = %61
  %67 = landingpad { i8*, i32 }
          catch i8* null                          ; [#uses=1 type={ i8*, i32 }]
  %68 = extractvalue { i8*, i32 } %67, 0          ; [#uses=1 type=i8*]
  tail call void @__clang_call_terminate(i8* %68) #12
  unreachable
}

; [#uses=1]
; Function Attrs: nounwind optsize
declare zeroext i1 @_ZSt18uncaught_exceptionv() local_unnamed_addr #5

; [#uses=2]
; Function Attrs: argmemonly nounwind optsize readonly
declare i32 @strlen(i8* nocapture) local_unnamed_addr #7

; [#uses=1]
; Function Attrs: optsize
define linkonce_odr dereferenceable(84) %"class.std::__ccr1::basic_ostream"* @_ZNSt6__ccr113basic_ostreamIcNS_11char_traitsIcEEE3putEc(%"class.std::__ccr1::basic_ostream"*, i8 signext) local_unnamed_addr #1 align 2 personality i8* bitcast (i32 (...)* @__gxx_personality_sj0 to i8*) {
  %3 = alloca %"class.std::__ccr1::basic_ostream<char, std::__ccr1::char_traits<char> >::sentry", align 4 ; [#uses=4 type=%"class.std::__ccr1::basic_ostream<char, std::__ccr1::char_traits<char> >::sentry"*]
  %4 = getelementptr inbounds %"class.std::__ccr1::basic_ostream<char, std::__ccr1::char_traits<char> >::sentry", %"class.std::__ccr1::basic_ostream<char, std::__ccr1::char_traits<char> >::sentry"* %3, i32 0, i32 0 ; [#uses=5 type=i8*]
  call void @llvm.lifetime.start.p0i8(i64 8, i8* nonnull %4) #11
  store i8 0, i8* %4, align 4, !tbaa !15
  %5 = getelementptr inbounds %"class.std::__ccr1::basic_ostream<char, std::__ccr1::char_traits<char> >::sentry", %"class.std::__ccr1::basic_ostream<char, std::__ccr1::char_traits<char> >::sentry"* %3, i32 0, i32 1 ; [#uses=1 type=%"class.std::__ccr1::basic_ostream"**]
  store %"class.std::__ccr1::basic_ostream"* %0, %"class.std::__ccr1::basic_ostream"** %5, align 4, !tbaa !12
  %6 = bitcast %"class.std::__ccr1::basic_ostream"* %0 to i8** ; [#uses=4 type=i8**]
  %7 = load i8*, i8** %6, align 4, !tbaa !13      ; [#uses=2 type=i8*]
  %8 = getelementptr i8, i8* %7, i32 -12          ; [#uses=1 type=i8*]
  %9 = bitcast i8* %8 to i32*                     ; [#uses=1 type=i32*]
  %10 = load i32, i32* %9, align 4                ; [#uses=1 type=i32]
  %11 = bitcast %"class.std::__ccr1::basic_ostream"* %0 to i8* ; [#uses=4 type=i8*]
  %12 = getelementptr inbounds i8, i8* %11, i32 %10 ; [#uses=2 type=i8*]
  %13 = getelementptr inbounds i8, i8* %12, i32 16 ; [#uses=1 type=i8*]
  %14 = bitcast i8* %13 to i32*                   ; [#uses=1 type=i32*]
  %15 = load i32, i32* %14, align 4, !tbaa !18    ; [#uses=1 type=i32]
  %16 = icmp eq i32 %15, 0                        ; [#uses=1 type=i1]
  br i1 %16, label %17, label %72

; <label>:17:                                     ; preds = %2
  %18 = getelementptr inbounds i8, i8* %12, i32 72 ; [#uses=1 type=i8*]
  %19 = bitcast i8* %18 to %"class.std::__ccr1::basic_ostream"** ; [#uses=1 type=%"class.std::__ccr1::basic_ostream"**]
  %20 = load %"class.std::__ccr1::basic_ostream"*, %"class.std::__ccr1::basic_ostream"** %19, align 4, !tbaa !22 ; [#uses=2 type=%"class.std::__ccr1::basic_ostream"*]
  %21 = icmp eq %"class.std::__ccr1::basic_ostream"* %20, null ; [#uses=1 type=i1]
  br i1 %21, label %26, label %22

; <label>:22:                                     ; preds = %17
  %23 = invoke dereferenceable(84) %"class.std::__ccr1::basic_ostream"* @_ZNSt6__ccr113basic_ostreamIcNS_11char_traitsIcEEE5flushEv(%"class.std::__ccr1::basic_ostream"* nonnull %20) #9
          to label %24 unwind label %65           ; [#uses=0 type=%"class.std::__ccr1::basic_ostream"*]

; <label>:24:                                     ; preds = %22
  %25 = load i8*, i8** %6, align 4, !tbaa !13     ; [#uses=1 type=i8*]
  br label %26

; <label>:26:                                     ; preds = %17, %24
  %27 = phi i8* [ %25, %24 ], [ %7, %17 ]         ; [#uses=1 type=i8*]
  store i8 1, i8* %4, align 4, !tbaa !15
  %28 = getelementptr i8, i8* %27, i32 -12        ; [#uses=1 type=i8*]
  %29 = bitcast i8* %28 to i32*                   ; [#uses=1 type=i32*]
  %30 = load i32, i32* %29, align 4               ; [#uses=1 type=i32]
  %31 = getelementptr inbounds i8, i8* %11, i32 %30 ; [#uses=1 type=i8*]
  %32 = getelementptr inbounds i8, i8* %31, i32 24 ; [#uses=1 type=i8*]
  %33 = bitcast i8* %32 to i32*                   ; [#uses=1 type=i32*]
  %34 = load i32, i32* %33, align 4, !tbaa !24    ; [#uses=3 type=i32]
  %35 = inttoptr i32 %34 to %"class.std::__ccr1::basic_streambuf"* ; [#uses=3 type=%"class.std::__ccr1::basic_streambuf"*]
  %36 = icmp eq i32 %34, 0                        ; [#uses=1 type=i1]
  br i1 %36, label %54, label %37

; <label>:37:                                     ; preds = %26
  %38 = getelementptr inbounds %"class.std::__ccr1::basic_streambuf", %"class.std::__ccr1::basic_streambuf"* %35, i32 0, i32 6 ; [#uses=2 type=i8**]
  %39 = load i8*, i8** %38, align 4, !tbaa !28    ; [#uses=3 type=i8*]
  %40 = getelementptr inbounds %"class.std::__ccr1::basic_streambuf", %"class.std::__ccr1::basic_streambuf"* %35, i32 0, i32 7 ; [#uses=1 type=i8**]
  %41 = load i8*, i8** %40, align 4, !tbaa !31    ; [#uses=1 type=i8*]
  %42 = icmp eq i8* %39, %41                      ; [#uses=1 type=i1]
  br i1 %42, label %45, label %43

; <label>:43:                                     ; preds = %37
  %44 = getelementptr inbounds i8, i8* %39, i32 1 ; [#uses=1 type=i8*]
  store i8* %44, i8** %38, align 4, !tbaa !28
  store i8 %1, i8* %39, align 1, !tbaa !12
  br label %72

; <label>:45:                                     ; preds = %37
  %46 = inttoptr i32 %34 to i32 (%"class.std::__ccr1::basic_streambuf"*, i32)*** ; [#uses=1 type=i32 (%"class.std::__ccr1::basic_streambuf"*, i32)***]
  %47 = load i32 (%"class.std::__ccr1::basic_streambuf"*, i32)**, i32 (%"class.std::__ccr1::basic_streambuf"*, i32)*** %46, align 4, !tbaa !13 ; [#uses=1 type=i32 (%"class.std::__ccr1::basic_streambuf"*, i32)**]
  %48 = getelementptr inbounds i32 (%"class.std::__ccr1::basic_streambuf"*, i32)*, i32 (%"class.std::__ccr1::basic_streambuf"*, i32)** %47, i32 13 ; [#uses=1 type=i32 (%"class.std::__ccr1::basic_streambuf"*, i32)**]
  %49 = load i32 (%"class.std::__ccr1::basic_streambuf"*, i32)*, i32 (%"class.std::__ccr1::basic_streambuf"*, i32)** %48, align 4 ; [#uses=1 type=i32 (%"class.std::__ccr1::basic_streambuf"*, i32)*]
  %50 = zext i8 %1 to i32                         ; [#uses=1 type=i32]
  %51 = invoke i32 %49(%"class.std::__ccr1::basic_streambuf"* nonnull %35, i32 %50) #9
          to label %52 unwind label %68           ; [#uses=1 type=i32]

; <label>:52:                                     ; preds = %45
  %53 = icmp eq i32 %51, -1                       ; [#uses=1 type=i1]
  br i1 %53, label %54, label %72

; <label>:54:                                     ; preds = %52, %26
  %55 = load i8*, i8** %6, align 4, !tbaa !13     ; [#uses=1 type=i8*]
  %56 = getelementptr i8, i8* %55, i32 -12        ; [#uses=1 type=i8*]
  %57 = bitcast i8* %56 to i32*                   ; [#uses=1 type=i32*]
  %58 = load i32, i32* %57, align 4               ; [#uses=1 type=i32]
  %59 = getelementptr inbounds i8, i8* %11, i32 %58 ; [#uses=2 type=i8*]
  %60 = bitcast i8* %59 to %"class.std::__ccr1::ios_base"* ; [#uses=1 type=%"class.std::__ccr1::ios_base"*]
  %61 = getelementptr inbounds i8, i8* %59, i32 16 ; [#uses=1 type=i8*]
  %62 = bitcast i8* %61 to i32*                   ; [#uses=1 type=i32*]
  %63 = load i32, i32* %62, align 4, !tbaa !18    ; [#uses=1 type=i32]
  %64 = or i32 %63, 1                             ; [#uses=1 type=i32]
  invoke void @_ZNSt6__ccr18ios_base5clearEj(%"class.std::__ccr1::ios_base"* %60, i32 %64) #9
          to label %72 unwind label %68

; <label>:65:                                     ; preds = %22
  %66 = landingpad { i8*, i32 }
          catch i8* null                          ; [#uses=1 type={ i8*, i32 }]
  %67 = extractvalue { i8*, i32 } %66, 0          ; [#uses=1 type=i8*]
  br label %74

; <label>:68:                                     ; preds = %54, %45
  %69 = landingpad { i8*, i32 }
          catch i8* null                          ; [#uses=1 type={ i8*, i32 }]
  %70 = extractvalue { i8*, i32 } %69, 0          ; [#uses=1 type=i8*]
  %71 = call %"class.std::__ccr1::basic_ostream<char, std::__ccr1::char_traits<char> >::sentry"* @_ZNSt6__ccr113basic_ostreamIcNS_11char_traitsIcEEE6sentryD2Ev(%"class.std::__ccr1::basic_ostream<char, std::__ccr1::char_traits<char> >::sentry"* nonnull %3) #10 ; [#uses=0 type=%"class.std::__ccr1::basic_ostream<char, std::__ccr1::char_traits<char> >::sentry"*]
  br label %74

; <label>:72:                                     ; preds = %43, %52, %2, %54
  %73 = call %"class.std::__ccr1::basic_ostream<char, std::__ccr1::char_traits<char> >::sentry"* @_ZNSt6__ccr113basic_ostreamIcNS_11char_traitsIcEEE6sentryD2Ev(%"class.std::__ccr1::basic_ostream<char, std::__ccr1::char_traits<char> >::sentry"* nonnull %3) #10 ; [#uses=0 type=%"class.std::__ccr1::basic_ostream<char, std::__ccr1::char_traits<char> >::sentry"*]
  call void @llvm.lifetime.end.p0i8(i64 8, i8* nonnull %4) #11
  br label %84

; <label>:74:                                     ; preds = %68, %65
  %75 = phi i8* [ %70, %68 ], [ %67, %65 ]        ; [#uses=1 type=i8*]
  call void @llvm.lifetime.end.p0i8(i64 8, i8* nonnull %4) #11
  %76 = call i8* @__cxa_begin_catch(i8* %75) #11  ; [#uses=0 type=i8*]
  %77 = load i8*, i8** %6, align 4, !tbaa !13     ; [#uses=1 type=i8*]
  %78 = getelementptr i8, i8* %77, i32 -12        ; [#uses=1 type=i8*]
  %79 = bitcast i8* %78 to i32*                   ; [#uses=1 type=i32*]
  %80 = load i32, i32* %79, align 4               ; [#uses=1 type=i32]
  %81 = getelementptr inbounds i8, i8* %11, i32 %80 ; [#uses=1 type=i8*]
  %82 = bitcast i8* %81 to %"class.std::__ccr1::ios_base"* ; [#uses=1 type=%"class.std::__ccr1::ios_base"*]
  invoke void @_ZNSt6__ccr18ios_base33__set_badbit_and_consider_rethrowEv(%"class.std::__ccr1::ios_base"* %82) #9
          to label %83 unwind label %85

; <label>:83:                                     ; preds = %74
  call void @__cxa_end_catch()
  br label %84

; <label>:84:                                     ; preds = %83, %72
  ret %"class.std::__ccr1::basic_ostream"* %0

; <label>:85:                                     ; preds = %74
  %86 = landingpad { i8*, i32 }
          cleanup                                 ; [#uses=1 type={ i8*, i32 }]
  invoke void @__cxa_end_catch()
          to label %87 unwind label %88

; <label>:87:                                     ; preds = %85
  resume { i8*, i32 } %86

; <label>:88:                                     ; preds = %85
  %89 = landingpad { i8*, i32 }
          catch i8* null                          ; [#uses=1 type={ i8*, i32 }]
  %90 = extractvalue { i8*, i32 } %89, 0          ; [#uses=1 type=i8*]
  call void @__clang_call_terminate(i8* %90) #12
  unreachable
}

; [#uses=1]
; Function Attrs: norecurse nounwind optsize
define internal void @_GLOBAL__sub_I_NewFile.cpp() #8 section "__TEXT,__StaticInit,regular,pure_instructions" {
  br label %1

; <label>:1:                                      ; preds = %13, %0
  %2 = phi %struct.line_* [ getelementptr inbounds ([10 x %struct.line_], [10 x %struct.line_]* @line, i32 0, i32 0), %0 ], [ %14, %13 ] ; [#uses=3 type=%struct.line_*]
  %3 = getelementptr inbounds %struct.line_, %struct.line_* %2, i32 0, i32 1, i32 0 ; [#uses=1 type=%"struct.line_::word_"*]
  %4 = getelementptr inbounds %struct.line_, %struct.line_* %2, i32 0, i32 1, i32 10 ; [#uses=1 type=%"struct.line_::word_"*]
  br label %5

; <label>:5:                                      ; preds = %5, %1
  %6 = phi %"struct.line_::word_"* [ %3, %1 ], [ %11, %5 ] ; [#uses=3 type=%"struct.line_::word_"*]
  %7 = getelementptr inbounds %"struct.line_::word_", %"struct.line_::word_"* %6, i32 0, i32 1 ; [#uses=1 type=i8**]
  %8 = bitcast %"struct.line_::word_"* %6 to i32* ; [#uses=1 type=i32*]
  %9 = load i32, i32* %8, align 4, !tbaa !9       ; [#uses=1 type=i32]
  %10 = bitcast i8** %7 to i32*                   ; [#uses=1 type=i32*]
  store i32 %9, i32* %10, align 4, !tbaa !11
  %11 = getelementptr inbounds %"struct.line_::word_", %"struct.line_::word_"* %6, i32 1 ; [#uses=2 type=%"struct.line_::word_"*]
  %12 = icmp eq %"struct.line_::word_"* %11, %4   ; [#uses=1 type=i1]
  br i1 %12, label %13, label %5

; <label>:13:                                     ; preds = %5
  %14 = getelementptr inbounds %struct.line_, %struct.line_* %2, i32 1 ; [#uses=2 type=%struct.line_*]
  %15 = icmp eq %struct.line_* %14, getelementptr inbounds ([10 x %struct.line_], [10 x %struct.line_]* @line, i32 1, i32 0) ; [#uses=1 type=i1]
  br i1 %15, label %16, label %1

; <label>:16:                                     ; preds = %13
  ret void
}

attributes #0 = { norecurse optsize "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="arm7tdmi" "target-features"="+soft-float,+strict-align,-crypto,-neon,-thumb-mode" "unsafe-fp-math"="false" "use-soft-float"="true" }
attributes #1 = { optsize "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="arm7tdmi" "target-features"="+soft-float,+strict-align,-crypto,-neon,-thumb-mode" "unsafe-fp-math"="false" "use-soft-float"="true" }
attributes #2 = { argmemonly nounwind }
attributes #3 = { optsize "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="arm7tdmi" "target-features"="+soft-float,+strict-align,-crypto,-neon,-thumb-mode" "unsafe-fp-math"="false" "use-soft-float"="true" }
attributes #4 = { noinline noreturn nounwind }
attributes #5 = { nounwind optsize "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="arm7tdmi" "target-features"="+soft-float,+strict-align,-crypto,-neon,-thumb-mode" "unsafe-fp-math"="false" "use-soft-float"="true" }
attributes #6 = { nounwind optsize "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="arm7tdmi" "target-features"="+soft-float,+strict-align,-crypto,-neon,-thumb-mode" "unsafe-fp-math"="false" "use-soft-float"="true" }
attributes #7 = { argmemonly nounwind optsize readonly "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="arm7tdmi" "target-features"="+soft-float,+strict-align,-crypto,-neon,-thumb-mode" "unsafe-fp-math"="false" "use-soft-float"="true" }
attributes #8 = { norecurse nounwind optsize "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="arm7tdmi" "target-features"="+soft-float,+strict-align,-crypto,-neon,-thumb-mode" "unsafe-fp-math"="false" "use-soft-float"="true" }
attributes #9 = { optsize }
attributes #10 = { nounwind optsize }
attributes #11 = { nounwind }
attributes #12 = { noreturn nounwind }

!llvm.module.flags = !{!0, !1, !2}
!llvm.ident = !{!3}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{i32 1, !"min_enum_size", i32 4}
!2 = !{i32 7, !"PIC Level", i32 2}
!3 = !{!"clang version 5.0.0 (tags/RELEASE_500/final)"}
!4 = !{!5, !6, i64 0}
!5 = !{!"_ZTS5line_", !6, i64 0, !7, i64 4}
!6 = !{!"any pointer", !7, i64 0}
!7 = !{!"omnipotent char", !8, i64 0}
!8 = !{!"Simple C++ TBAA"}
!9 = !{!10, !6, i64 0}
!10 = !{!"_ZTSN5line_5word_E", !6, i64 0, !6, i64 4}
!11 = !{!10, !6, i64 4}
!12 = !{!7, !7, i64 0}
!13 = !{!14, !14, i64 0}
!14 = !{!"vtable pointer", !8, i64 0}
!15 = !{!16, !17, i64 0}
!16 = !{!"_ZTSNSt6__ccr113basic_ostreamIcNS_11char_traitsIcEEE6sentryE", !17, i64 0, !7, i64 4}
!17 = !{!"bool", !7, i64 0}
!18 = !{!19, !20, i64 16}
!19 = !{!"_ZTSNSt6__ccr18ios_baseE", !20, i64 4, !20, i64 8, !20, i64 12, !20, i64 16, !20, i64 20, !6, i64 24, !6, i64 28, !6, i64 32, !6, i64 36, !21, i64 40, !21, i64 44, !6, i64 48, !21, i64 52, !21, i64 56, !6, i64 60, !21, i64 64, !21, i64 68}
!20 = !{!"int", !7, i64 0}
!21 = !{!"long", !7, i64 0}
!22 = !{!23, !6, i64 72}
!23 = !{!"_ZTSNSt6__ccr19basic_iosIcNS_11char_traitsIcEEEE", !6, i64 72, !20, i64 76}
!24 = !{!19, !6, i64 24}
!25 = !{!19, !20, i64 4}
!26 = !{!23, !20, i64 76}
!27 = !{!19, !20, i64 12}
!28 = !{!29, !6, i64 24}
!29 = !{!"_ZTSNSt6__ccr115basic_streambufIcNS_11char_traitsIcEEEE", !30, i64 4, !6, i64 8, !6, i64 12, !6, i64 16, !6, i64 20, !6, i64 24, !6, i64 28}
!30 = !{!"_ZTSNSt6__ccr16localeE", !6, i64 0}
!31 = !{!29, !6, i64 28}
!32 = !{i8 0, i8 2}
