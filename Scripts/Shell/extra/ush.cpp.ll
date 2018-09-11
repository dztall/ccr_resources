; ModuleID = '/var/mobile/Containers/Data/Application/D306DF46-6C9B-4E6D-90C4-D19B1DA7868D/Documents/Data/CCR/UserFiles/ccr_resources/Scripts/Shell/extra/ush.cpp.bc'
source_filename = "/var/mobile/Containers/Data/Application/D306DF46-6C9B-4E6D-90C4-D19B1DA7868D/Documents/Data/CCR/UserFiles/ccr_resources/Scripts/Shell/extra/ush.cpp"
target datalayout = "e-m:o-p:32:32-f64:32:64-v64:32:64-v128:32:128-a:0:32-n32-S32"
target triple = "armv4t-apple-macosx10.4.0"

%"class.std::__ccr1::basic_string" = type { %"class.std::__ccr1::__compressed_pair" }
%"class.std::__ccr1::__compressed_pair" = type { %"struct.std::__ccr1::__compressed_pair_elem" }
%"struct.std::__ccr1::__compressed_pair_elem" = type { %"struct.std::__ccr1::basic_string<char, std::__ccr1::char_traits<char>, std::__ccr1::allocator<char> >::__rep" }
%"struct.std::__ccr1::basic_string<char, std::__ccr1::char_traits<char>, std::__ccr1::allocator<char> >::__rep" = type { %union.anon }
%union.anon = type { %"struct.std::__ccr1::basic_string<char, std::__ccr1::char_traits<char>, std::__ccr1::allocator<char> >::__long" }
%"struct.std::__ccr1::basic_string<char, std::__ccr1::char_traits<char>, std::__ccr1::allocator<char> >::__long" = type { i32, i32, i8* }
%"class.std::__ccr1::map" = type { %"class.std::__ccr1::__tree" }
%"class.std::__ccr1::__tree" = type { %"class.std::__ccr1::__tree_end_node"*, %"class.std::__ccr1::__compressed_pair.2", %"class.std::__ccr1::__compressed_pair.7" }
%"class.std::__ccr1::__tree_end_node" = type { %"class.std::__ccr1::__tree_node_base"* }
%"class.std::__ccr1::__tree_node_base" = type <{ %"class.std::__ccr1::__tree_end_node", %"class.std::__ccr1::__tree_node_base"*, %"class.std::__ccr1::__tree_end_node"*, i8, [3 x i8] }>
%"class.std::__ccr1::__compressed_pair.2" = type { %"struct.std::__ccr1::__compressed_pair_elem.3" }
%"struct.std::__ccr1::__compressed_pair_elem.3" = type { %"class.std::__ccr1::__tree_end_node" }
%"class.std::__ccr1::__compressed_pair.7" = type { %"struct.std::__ccr1::__compressed_pair_elem.8" }
%"struct.std::__ccr1::__compressed_pair_elem.8" = type { i32 }
%struct.__sFILE = type { i8*, i32, i32, i16, i16, %struct.__sbuf, i32, i8*, i32 (i8*)*, i32 (i8*, i8*, i32)*, i64 (i8*, i64, i32)*, i32 (i8*, i8*, i32)*, %struct.__sbuf, %struct.__sFILEX*, i32, [3 x i8], [1 x i8], %struct.__sbuf, i32, i64 }
%struct.__sFILEX = type opaque
%struct.__sbuf = type { i8*, i32 }
%"class.std::__ccr1::basic_ostream" = type { i32 (...)**, %"class.std::__ccr1::basic_ios" }
%"class.std::__ccr1::basic_ios" = type { %"class.std::__ccr1::ios_base", %"class.std::__ccr1::basic_ostream"*, i32 }
%"class.std::__ccr1::ios_base" = type { i32 (...)**, i32, i32, i32, i32, i32, i8*, i8*, void (i32, %"class.std::__ccr1::ios_base"*, i32)**, i32*, i32, i32, i32*, i32, i32, i8**, i32, i32 }
%"class.std::__ccr1::locale::id" = type { %"struct.std::__ccr1::once_flag", i32 }
%"struct.std::__ccr1::once_flag" = type { i32 }
%struct._RuneLocale = type { [8 x i8], [32 x i8], i32 (i8*, i32, i8**)*, i32 (i32, i8*, i32, i8**)*, i32, [256 x i32], [256 x i32], [256 x i32], %struct._RuneRange, %struct._RuneRange, %struct._RuneRange, i8*, i32, i32, %struct._RuneCharClass* }
%struct._RuneRange = type { i32, %struct._RuneEntry* }
%struct._RuneEntry = type { i32, i32, i32, i32* }
%struct._RuneCharClass = type { [14 x i8], i32 }
%"struct.std::__ccr1::piecewise_construct_t" = type { i8 }
%"class.std::__ccr1::__tree_node" = type { %"class.std::__ccr1::__tree_node_base.base", %"union.std::__ccr1::__value_type" }
%"class.std::__ccr1::__tree_node_base.base" = type <{ %"class.std::__ccr1::__tree_end_node", %"class.std::__ccr1::__tree_node_base"*, %"class.std::__ccr1::__tree_end_node"*, i8 }>
%"union.std::__ccr1::__value_type" = type { %"struct.std::__ccr1::pair" }
%"struct.std::__ccr1::pair" = type { i8, i32 }
%"class.std::__ccr1::locale" = type { %"class.std::__ccr1::locale::__imp"* }
%"class.std::__ccr1::locale::__imp" = type opaque
%"class.std::__ccr1::vector" = type { %"class.std::__ccr1::__vector_base" }
%"class.std::__ccr1::__vector_base" = type { %"class.std::__ccr1::basic_string"*, %"class.std::__ccr1::basic_string"*, %"class.std::__ccr1::__compressed_pair.16" }
%"class.std::__ccr1::__compressed_pair.16" = type { %"struct.std::__ccr1::__compressed_pair_elem.17" }
%"struct.std::__ccr1::__compressed_pair_elem.17" = type { %"class.std::__ccr1::basic_string"* }
%"class.std::__ccr1::unique_ptr.22" = type { %"class.std::__ccr1::__compressed_pair.23" }
%"class.std::__ccr1::__compressed_pair.23" = type { %"struct.std::__ccr1::__compressed_pair_elem.24" }
%"struct.std::__ccr1::__compressed_pair_elem.24" = type { %"class.(anonymous namespace)::ExprAST"* }
%"class.(anonymous namespace)::ExprAST" = type { i32 (...)** }
%"class.std::__ccr1::unique_ptr.13" = type { %"class.std::__ccr1::__compressed_pair.14" }
%"class.std::__ccr1::__compressed_pair.14" = type { %"struct.std::__ccr1::__compressed_pair_elem.15" }
%"struct.std::__ccr1::__compressed_pair_elem.15" = type { %"class.(anonymous namespace)::PrototypeAST"* }
%"class.(anonymous namespace)::PrototypeAST" = type { %"class.std::__ccr1::basic_string", %"class.std::__ccr1::vector" }
%"struct.std::__ccr1::pair.74" = type <{ %"class.std::__ccr1::__tree_iterator", i8, [3 x i8] }>
%"class.std::__ccr1::__tree_iterator" = type { %"class.std::__ccr1::__tree_end_node"* }
%"class.std::__ccr1::tuple" = type { %"struct.std::__ccr1::__tuple_impl" }
%"struct.std::__ccr1::__tuple_impl" = type { %"class.std::__ccr1::__tuple_leaf" }
%"class.std::__ccr1::__tuple_leaf" = type { i8* }
%"class.std::__ccr1::tuple.75" = type { i8 }
%"struct.std::__ccr1::basic_string<char, std::__ccr1::char_traits<char>, std::__ccr1::allocator<char> >::__short" = type { %union.anon.0, [11 x i8] }
%union.anon.0 = type { i8 }
%"class.std::__ccr1::locale::facet" = type { %"class.std::__ccr1::__shared_count" }
%"class.std::__ccr1::__shared_count" = type { i32 (...)**, i32 }
%"class.std::__ccr1::ctype" = type <{ %"class.std::__ccr1::locale::facet", i32*, i8, [3 x i8] }>
%"class.std::__ccr1::basic_ostream<char, std::__ccr1::char_traits<char> >::sentry" = type { i8, %"class.std::__ccr1::basic_ostream"* }
%"class.std::__ccr1::basic_streambuf" = type { i32 (...)**, %"class.std::__ccr1::locale", i8*, i8*, i8*, i8*, i8*, i8* }
%"struct.std::__ccr1::__split_buffer" = type { %"class.std::__ccr1::basic_string"*, %"class.std::__ccr1::basic_string"*, %"class.std::__ccr1::basic_string"*, %"class.std::__ccr1::__compressed_pair.33" }
%"class.std::__ccr1::__compressed_pair.33" = type { %"struct.std::__ccr1::__compressed_pair_elem.17", %"struct.std::__ccr1::__compressed_pair_elem.34" }
%"struct.std::__ccr1::__compressed_pair_elem.34" = type { %"class.std::__ccr1::allocator.19"* }
%"class.std::__ccr1::allocator.19" = type { i8 }
%"class.std::__ccr1::__vector_base_common" = type { i8 }
%"class.std::logic_error" = type { %"class.std::exception", %"class.std::__ccr1::__libcpp_refstring" }
%"class.std::exception" = type { i32 (...)** }
%"class.std::__ccr1::__libcpp_refstring" = type { i8* }
%"class.std::length_error" = type { %"class.std::logic_error" }
%"class.std::__ccr1::vector.42" = type { %"class.std::__ccr1::__vector_base.43" }
%"class.std::__ccr1::__vector_base.43" = type { %"class.std::__ccr1::unique_ptr.22"*, %"class.std::__ccr1::unique_ptr.22"*, %"class.std::__ccr1::__compressed_pair.44" }
%"class.std::__ccr1::__compressed_pair.44" = type { %"struct.std::__ccr1::__compressed_pair_elem.45" }
%"struct.std::__ccr1::__compressed_pair_elem.45" = type { %"class.std::__ccr1::unique_ptr.22"* }
%"class.(anonymous namespace)::NumberExprAST" = type { %"class.(anonymous namespace)::ExprAST", double }
%"class.(anonymous namespace)::VariableExprAST" = type { %"class.(anonymous namespace)::ExprAST", %"class.std::__ccr1::basic_string" }
%"class.(anonymous namespace)::CallExprAST" = type { %"class.(anonymous namespace)::ExprAST", %"class.std::__ccr1::basic_string", %"class.std::__ccr1::vector.42" }
%"class.(anonymous namespace)::BinaryExprAST" = type { %"class.(anonymous namespace)::ExprAST", i8, %"class.std::__ccr1::unique_ptr.22", %"class.std::__ccr1::unique_ptr.22" }

@prompt = global %"class.std::__ccr1::basic_string" zeroinitializer, align 4 ; [#uses=5 type=%"class.std::__ccr1::basic_string"*]
@.str = private unnamed_addr constant [19 x i8] c"type q to exit > \0A\00", align 1 ; [#uses=1 type=[19 x i8]*]
@_ZL13IdentifierStr = internal global %"class.std::__ccr1::basic_string" zeroinitializer, align 4 ; [#uses=17 type=%"class.std::__ccr1::basic_string"*]
@_ZL15BinopPrecedence = internal global %"class.std::__ccr1::map" zeroinitializer, align 4 ; [#uses=5 type=%"class.std::__ccr1::map"*]
@__stderrp = external local_unnamed_addr global %struct.__sFILE*, align 4 ; [#uses=23 type=%struct.__sFILE**]
@.str.3 = private unnamed_addr constant [34 x i8] c"->called %s() at line %d from %s\0A\00", align 1 ; [#uses=1 type=[34 x i8]*]
@__func__.main = private unnamed_addr constant [5 x i8] c"main\00", align 1 ; [#uses=1 type=[5 x i8]*]
@.str.4 = private unnamed_addr constant [148 x i8] c"/var/mobile/Containers/Data/Application/D306DF46-6C9B-4E6D-90C4-D19B1DA7868D/Documents/Data/CCR/UserFiles/ccr_resources/Scripts/Shell/extra/ush.cpp\00", align 1 ; [#uses=1 type=[148 x i8]*]
@_ZNSt6__ccr14cerrE = external global %"class.std::__ccr1::basic_ostream", align 4 ; [#uses=26 type=%"class.std::__ccr1::basic_ostream"*]
@_ZL6CurTok = internal unnamed_addr global i32 0, align 4 ; [#uses=30 type=i32*]
@_ZL8LastChar = internal unnamed_addr global i32 0, align 4 ; [#uses=18 type=i32*]
@.str.5 = private unnamed_addr constant [12 x i8] c"LastChar = \00", align 1 ; [#uses=1 type=[12 x i8]*]
@__func__._ZL6gettokv = private unnamed_addr constant [7 x i8] c"gettok\00", align 1 ; [#uses=1 type=[7 x i8]*]
@.str.6 = private unnamed_addr constant [8 x i8] c"#define\00", align 1 ; [#uses=1 type=[8 x i8]*]
@.str.7 = private unnamed_addr constant [38 x i8] c"recognized token Identifier/Keyword: \00", align 1 ; [#uses=1 type=[38 x i8]*]
@.str.8 = private unnamed_addr constant [4 x i8] c"def\00", align 1 ; [#uses=1 type=[4 x i8]*]
@.str.9 = private unnamed_addr constant [7 x i8] c"extern\00", align 1 ; [#uses=1 type=[7 x i8]*]
@.str.10 = private unnamed_addr constant [2 x i8] c"q\00", align 1 ; [#uses=1 type=[2 x i8]*]
@.str.11 = private unnamed_addr constant [22 x i8] c", exiting application\00", align 1 ; [#uses=1 type=[22 x i8]*]
@_ZL6NumVal = internal unnamed_addr global double 0.000000e+00, align 8 ; [#uses=2 type=double*]
@.str.12 = private unnamed_addr constant [19 x i8] c"recognized comment\00", align 1 ; [#uses=1 type=[19 x i8]*]
@.str.13 = private unnamed_addr constant [32 x i8] c"passed %s() at line %d from %s\0A\00", align 1 ; [#uses=1 type=[32 x i8]*]
@_ZNSt6__ccr15ctypeIcE2idE = external global %"class.std::__ccr1::locale::id", align 4 ; [#uses=15 type=%"class.std::__ccr1::locale::id"*]
@_DefaultRuneLocale = external local_unnamed_addr global %struct._RuneLocale, align 4 ; [#uses=6 type=%struct._RuneLocale*]
@__func__._ZL8MainLoopv = private unnamed_addr constant [9 x i8] c"MainLoop\00", align 1 ; [#uses=1 type=[9 x i8]*]
@__func__._ZL17HandleCDefinitionv = private unnamed_addr constant [18 x i8] c"HandleCDefinition\00", align 1 ; [#uses=1 type=[18 x i8]*]
@.str.14 = private unnamed_addr constant [31 x i8] c"Parsed a function definition.\0A\00", align 1 ; [#uses=1 type=[31 x i8]*]
@__func__._ZL16ParseCDefinitionv = private unnamed_addr constant [17 x i8] c"ParseCDefinition\00", align 1 ; [#uses=1 type=[17 x i8]*]
@.str.15 = private unnamed_addr constant [14 x i8] c"definition = \00", align 1 ; [#uses=1 type=[14 x i8]*]
@.str.16 = private unnamed_addr constant [13 x i8] c"defstring = \00", align 1 ; [#uses=1 type=[13 x i8]*]
@__func__._ZL16HandleDefinitionv = private unnamed_addr constant [17 x i8] c"HandleDefinition\00", align 1 ; [#uses=1 type=[17 x i8]*]
@__func__._ZL15ParseDefinitionv = private unnamed_addr constant [16 x i8] c"ParseDefinition\00", align 1 ; [#uses=1 type=[16 x i8]*]
@__func__._ZL14ParsePrototypev = private unnamed_addr constant [15 x i8] c"ParsePrototype\00", align 1 ; [#uses=1 type=[15 x i8]*]
@.str.17 = private unnamed_addr constant [36 x i8] c"Expected function name in prototype\00", align 1 ; [#uses=1 type=[36 x i8]*]
@.str.18 = private unnamed_addr constant [26 x i8] c"Expected '(' in prototype\00", align 1 ; [#uses=1 type=[26 x i8]*]
@.str.19 = private unnamed_addr constant [26 x i8] c"Expected ')' in prototype\00", align 1 ; [#uses=1 type=[26 x i8]*]
@__func__._Z9LogErrorPPKc = private unnamed_addr constant [10 x i8] c"LogErrorP\00", align 1 ; [#uses=1 type=[10 x i8]*]
@__func__._Z8LogErrorPKc = private unnamed_addr constant [9 x i8] c"LogError\00", align 1 ; [#uses=1 type=[9 x i8]*]
@.str.20 = private unnamed_addr constant [11 x i8] c"LogError: \00", align 1 ; [#uses=1 type=[11 x i8]*]
@.str.21 = private unnamed_addr constant [68 x i8] c"allocator<T>::allocate(size_t n) 'n' exceeds maximum supported size\00", align 1 ; [#uses=1 type=[68 x i8]*]
@_ZTISt12length_error = external constant i8*     ; [#uses=1 type=i8**]
@_ZTVSt12length_error = external unnamed_addr constant { [5 x i8*] }, align 4 ; [#uses=1 type={ [5 x i8*] }*]
@__func__._ZL15ParseExpressionv = private unnamed_addr constant [16 x i8] c"ParseExpression\00", align 1 ; [#uses=1 type=[16 x i8]*]
@__func__._ZL12ParsePrimaryv = private unnamed_addr constant [13 x i8] c"ParsePrimary\00", align 1 ; [#uses=1 type=[13 x i8]*]
@.str.22 = private unnamed_addr constant [43 x i8] c"unknown token when expecting an expression\00", align 1 ; [#uses=1 type=[43 x i8]*]
@__func__._ZL19ParseIdentifierExprv = private unnamed_addr constant [20 x i8] c"ParseIdentifierExpr\00", align 1 ; [#uses=1 type=[20 x i8]*]
@.str.23 = private unnamed_addr constant [37 x i8] c"Expected ')' or ',' in argument list\00", align 1 ; [#uses=1 type=[37 x i8]*]
@_ZTVN12_GLOBAL__N_115VariableExprASTE = internal unnamed_addr constant { [4 x i8*] } { [4 x i8*] [i8* null, i8* bitcast ({ i8*, i8*, i8* }* @_ZTIN12_GLOBAL__N_115VariableExprASTE to i8*), i8* bitcast (%"class.(anonymous namespace)::VariableExprAST"* (%"class.(anonymous namespace)::VariableExprAST"*)* @_ZN12_GLOBAL__N_115VariableExprASTD1Ev to i8*), i8* bitcast (void (%"class.(anonymous namespace)::VariableExprAST"*)* @_ZN12_GLOBAL__N_115VariableExprASTD0Ev to i8*)] }, align 4 ; [#uses=1 type={ [4 x i8*] }*]
@_ZTVN10__cxxabiv120__si_class_type_infoE = external global i8* ; [#uses=1 type=i8**]
@_ZTSN12_GLOBAL__N_115VariableExprASTE = internal constant [34 x i8] c"N12_GLOBAL__N_115VariableExprASTE\00" ; [#uses=1 type=[34 x i8]*]
@_ZTVN10__cxxabiv117__class_type_infoE = external global i8* ; [#uses=1 type=i8**]
@_ZTSN12_GLOBAL__N_17ExprASTE = internal constant [25 x i8] c"N12_GLOBAL__N_17ExprASTE\00" ; [#uses=1 type=[25 x i8]*]
@_ZTIN12_GLOBAL__N_17ExprASTE = internal constant { i8*, i8* } { i8* bitcast (i8** getelementptr inbounds (i8*, i8** @_ZTVN10__cxxabiv117__class_type_infoE, i32 2) to i8*), i8* getelementptr inbounds ([25 x i8], [25 x i8]* @_ZTSN12_GLOBAL__N_17ExprASTE, i32 0, i32 0) } ; [#uses=1 type={ i8*, i8* }*]
@_ZTIN12_GLOBAL__N_115VariableExprASTE = internal constant { i8*, i8*, i8* } { i8* bitcast (i8** getelementptr inbounds (i8*, i8** @_ZTVN10__cxxabiv120__si_class_type_infoE, i32 2) to i8*), i8* getelementptr inbounds ([34 x i8], [34 x i8]* @_ZTSN12_GLOBAL__N_115VariableExprASTE, i32 0, i32 0), i8* bitcast ({ i8*, i8* }* @_ZTIN12_GLOBAL__N_17ExprASTE to i8*) } ; [#uses=1 type={ i8*, i8*, i8* }*]
@_ZTVN12_GLOBAL__N_111CallExprASTE = internal unnamed_addr constant { [4 x i8*] } { [4 x i8*] [i8* null, i8* bitcast ({ i8*, i8*, i8* }* @_ZTIN12_GLOBAL__N_111CallExprASTE to i8*), i8* bitcast (%"class.(anonymous namespace)::CallExprAST"* (%"class.(anonymous namespace)::CallExprAST"*)* @_ZN12_GLOBAL__N_111CallExprASTD1Ev to i8*), i8* bitcast (void (%"class.(anonymous namespace)::CallExprAST"*)* @_ZN12_GLOBAL__N_111CallExprASTD0Ev to i8*)] }, align 4 ; [#uses=1 type={ [4 x i8*] }*]
@_ZTSN12_GLOBAL__N_111CallExprASTE = internal constant [30 x i8] c"N12_GLOBAL__N_111CallExprASTE\00" ; [#uses=1 type=[30 x i8]*]
@_ZTIN12_GLOBAL__N_111CallExprASTE = internal constant { i8*, i8*, i8* } { i8* bitcast (i8** getelementptr inbounds (i8*, i8** @_ZTVN10__cxxabiv120__si_class_type_infoE, i32 2) to i8*), i8* getelementptr inbounds ([30 x i8], [30 x i8]* @_ZTSN12_GLOBAL__N_111CallExprASTE, i32 0, i32 0), i8* bitcast ({ i8*, i8* }* @_ZTIN12_GLOBAL__N_17ExprASTE to i8*) } ; [#uses=1 type={ i8*, i8*, i8* }*]
@__func__._ZL15ParseNumberExprv = private unnamed_addr constant [16 x i8] c"ParseNumberExpr\00", align 1 ; [#uses=1 type=[16 x i8]*]
@_ZTVN12_GLOBAL__N_113NumberExprASTE = internal unnamed_addr constant { [4 x i8*] } { [4 x i8*] [i8* null, i8* bitcast ({ i8*, i8*, i8* }* @_ZTIN12_GLOBAL__N_113NumberExprASTE to i8*), i8* bitcast (%"class.(anonymous namespace)::NumberExprAST"* (%"class.(anonymous namespace)::NumberExprAST"*)* @_ZN12_GLOBAL__N_113NumberExprASTD1Ev to i8*), i8* bitcast (void (%"class.(anonymous namespace)::NumberExprAST"*)* @_ZN12_GLOBAL__N_113NumberExprASTD0Ev to i8*)] }, align 4 ; [#uses=1 type={ [4 x i8*] }*]
@_ZTSN12_GLOBAL__N_113NumberExprASTE = internal constant [32 x i8] c"N12_GLOBAL__N_113NumberExprASTE\00" ; [#uses=1 type=[32 x i8]*]
@_ZTIN12_GLOBAL__N_113NumberExprASTE = internal constant { i8*, i8*, i8* } { i8* bitcast (i8** getelementptr inbounds (i8*, i8** @_ZTVN10__cxxabiv120__si_class_type_infoE, i32 2) to i8*), i8* getelementptr inbounds ([32 x i8], [32 x i8]* @_ZTSN12_GLOBAL__N_113NumberExprASTE, i32 0, i32 0), i8* bitcast ({ i8*, i8* }* @_ZTIN12_GLOBAL__N_17ExprASTE to i8*) } ; [#uses=1 type={ i8*, i8*, i8* }*]
@__func__._ZL14ParseParenExprv = private unnamed_addr constant [15 x i8] c"ParseParenExpr\00", align 1 ; [#uses=1 type=[15 x i8]*]
@.str.24 = private unnamed_addr constant [13 x i8] c"expected ')'\00", align 1 ; [#uses=1 type=[13 x i8]*]
@__func__._ZL13ParseBinOpRHSiNSt6__ccr110unique_ptrIN12_GLOBAL__N_17ExprASTENS_14default_deleteIS2_EEEE = private unnamed_addr constant [14 x i8] c"ParseBinOpRHS\00", align 1 ; [#uses=1 type=[14 x i8]*]
@__func__._ZL16GetTokPrecedencev = private unnamed_addr constant [17 x i8] c"GetTokPrecedence\00", align 1 ; [#uses=1 type=[17 x i8]*]
@_ZTVN12_GLOBAL__N_113BinaryExprASTE = internal unnamed_addr constant { [4 x i8*] } { [4 x i8*] [i8* null, i8* bitcast ({ i8*, i8*, i8* }* @_ZTIN12_GLOBAL__N_113BinaryExprASTE to i8*), i8* bitcast (%"class.(anonymous namespace)::BinaryExprAST"* (%"class.(anonymous namespace)::BinaryExprAST"*)* @_ZN12_GLOBAL__N_113BinaryExprASTD1Ev to i8*), i8* bitcast (void (%"class.(anonymous namespace)::BinaryExprAST"*)* @_ZN12_GLOBAL__N_113BinaryExprASTD0Ev to i8*)] }, align 4 ; [#uses=1 type={ [4 x i8*] }*]
@_ZTSN12_GLOBAL__N_113BinaryExprASTE = internal constant [32 x i8] c"N12_GLOBAL__N_113BinaryExprASTE\00" ; [#uses=1 type=[32 x i8]*]
@_ZTIN12_GLOBAL__N_113BinaryExprASTE = internal constant { i8*, i8*, i8* } { i8* bitcast (i8** getelementptr inbounds (i8*, i8** @_ZTVN10__cxxabiv120__si_class_type_infoE, i32 2) to i8*), i8* getelementptr inbounds ([32 x i8], [32 x i8]* @_ZTSN12_GLOBAL__N_113BinaryExprASTE, i32 0, i32 0), i8* bitcast ({ i8*, i8* }* @_ZTIN12_GLOBAL__N_17ExprASTE to i8*) } ; [#uses=1 type={ i8*, i8*, i8* }*]
@__func__._ZL12HandleExternv = private unnamed_addr constant [13 x i8] c"HandleExtern\00", align 1 ; [#uses=1 type=[13 x i8]*]
@.str.25 = private unnamed_addr constant [18 x i8] c"Parsed an extern\0A\00", align 1 ; [#uses=1 type=[18 x i8]*]
@__func__._ZL11ParseExternv = private unnamed_addr constant [12 x i8] c"ParseExtern\00", align 1 ; [#uses=1 type=[12 x i8]*]
@__func__._ZL24HandleTopLevelExpressionv = private unnamed_addr constant [25 x i8] c"HandleTopLevelExpression\00", align 1 ; [#uses=1 type=[25 x i8]*]
@.str.26 = private unnamed_addr constant [25 x i8] c"Parsed a top-level expr\0A\00", align 1 ; [#uses=1 type=[25 x i8]*]
@__func__._ZL17ParseTopLevelExprv = private unnamed_addr constant [18 x i8] c"ParseTopLevelExpr\00", align 1 ; [#uses=1 type=[18 x i8]*]
@.str.27 = private unnamed_addr constant [12 x i8] c"__anon_expr\00", align 1 ; [#uses=1 type=[12 x i8]*]
@_ZNSt6__ccr1L19piecewise_constructE = internal constant %"struct.std::__ccr1::piecewise_construct_t" undef, align 1 ; [#uses=5 type=%"struct.std::__ccr1::piecewise_construct_t"*]
@llvm.global_ctors = appending global [1 x { i32, void ()*, i8* }] [{ i32, void ()*, i8* } { i32 65535, void ()* @_GLOBAL__sub_I_ush.cpp, i8* null }] ; [#uses=0 type=[1 x { i32, void ()*, i8* }]*]

; [#uses=1]
; Function Attrs: nounwind optsize
define internal void @__dtor_prompt() #0 section "__TEXT,__StaticInit,regular,pure_instructions" personality i32 (...)* @__gxx_personality_sj0 {
  %1 = load i8, i8* bitcast (%"class.std::__ccr1::basic_string"* @prompt to i8*), align 4, !tbaa !4 ; [#uses=1 type=i8]
  %2 = and i8 %1, 1                               ; [#uses=1 type=i8]
  %3 = icmp eq i8 %2, 0                           ; [#uses=1 type=i1]
  br i1 %3, label %6, label %4

; <label>:4:                                      ; preds = %0
  %5 = load i8*, i8** getelementptr inbounds (%"class.std::__ccr1::basic_string", %"class.std::__ccr1::basic_string"* @prompt, i32 0, i32 0, i32 0, i32 0, i32 0, i32 0, i32 2), align 4, !tbaa !4 ; [#uses=1 type=i8*]
  tail call void @_ZdlPv(i8* %5) #15
  br label %6

; <label>:6:                                      ; preds = %0, %4
  ret void
}

; [#uses=3]
; Function Attrs: nounwind
declare i32 @atexit(void ()*) local_unnamed_addr #1

; [#uses=1]
; Function Attrs: nounwind optsize
define internal void @__dtor__ZL13IdentifierStr() #0 section "__TEXT,__StaticInit,regular,pure_instructions" personality i32 (...)* @__gxx_personality_sj0 {
  %1 = load i8, i8* bitcast (%"class.std::__ccr1::basic_string"* @_ZL13IdentifierStr to i8*), align 4, !tbaa !4 ; [#uses=1 type=i8]
  %2 = and i8 %1, 1                               ; [#uses=1 type=i8]
  %3 = icmp eq i8 %2, 0                           ; [#uses=1 type=i1]
  br i1 %3, label %6, label %4

; <label>:4:                                      ; preds = %0
  %5 = load i8*, i8** getelementptr inbounds (%"class.std::__ccr1::basic_string", %"class.std::__ccr1::basic_string"* @_ZL13IdentifierStr, i32 0, i32 0, i32 0, i32 0, i32 0, i32 0, i32 2), align 4, !tbaa !4 ; [#uses=1 type=i8*]
  tail call void @_ZdlPv(i8* %5) #15
  br label %6

; <label>:6:                                      ; preds = %0, %4
  ret void
}

; [#uses=1]
; Function Attrs: nounwind optsize
define internal void @__dtor__ZL15BinopPrecedence() #0 section "__TEXT,__StaticInit,regular,pure_instructions" {
  %1 = load %"class.std::__ccr1::__tree_node"*, %"class.std::__ccr1::__tree_node"** bitcast (%"class.std::__ccr1::__tree_end_node"* getelementptr inbounds (%"class.std::__ccr1::map", %"class.std::__ccr1::map"* @_ZL15BinopPrecedence, i32 0, i32 0, i32 1, i32 0, i32 0) to %"class.std::__ccr1::__tree_node"**), align 4, !tbaa !7 ; [#uses=1 type=%"class.std::__ccr1::__tree_node"*]
  tail call void @_ZNSt6__ccr16__treeINS_12__value_typeIciEENS_19__map_value_compareIcS2_NS_4lessIcEELb1EEENS_9allocatorIS2_EEE7destroyEPNS_11__tree_nodeIS2_PvEE(%"class.std::__ccr1::__tree"* getelementptr inbounds (%"class.std::__ccr1::map", %"class.std::__ccr1::map"* @_ZL15BinopPrecedence, i32 0, i32 0), %"class.std::__ccr1::__tree_node"* %1) #16
  ret void
}

; [#uses=0]
; Function Attrs: norecurse optsize
define i32 @main() local_unnamed_addr #2 personality i32 (...)* @__gxx_personality_sj0 {
  %1 = alloca %"class.std::__ccr1::locale", align 4 ; [#uses=5 type=%"class.std::__ccr1::locale"*]
  %2 = alloca %"class.std::__ccr1::basic_string", align 4 ; [#uses=5 type=%"class.std::__ccr1::basic_string"*]
  %3 = alloca %"class.std::__ccr1::vector", align 4 ; [#uses=6 type=%"class.std::__ccr1::vector"*]
  %4 = alloca %"class.std::__ccr1::unique_ptr.22", align 4 ; [#uses=3 type=%"class.std::__ccr1::unique_ptr.22"*]
  %5 = alloca %"class.std::__ccr1::vector", align 4 ; [#uses=5 type=%"class.std::__ccr1::vector"*]
  %6 = alloca %"class.std::__ccr1::locale", align 4 ; [#uses=5 type=%"class.std::__ccr1::locale"*]
  %7 = alloca %"class.std::__ccr1::unique_ptr.13", align 4 ; [#uses=3 type=%"class.std::__ccr1::unique_ptr.13"*]
  %8 = alloca %"class.std::__ccr1::locale", align 4 ; [#uses=5 type=%"class.std::__ccr1::locale"*]
  %9 = alloca %"class.std::__ccr1::unique_ptr.13", align 4 ; [#uses=3 type=%"class.std::__ccr1::unique_ptr.13"*]
  %10 = alloca %"class.std::__ccr1::unique_ptr.22", align 4 ; [#uses=3 type=%"class.std::__ccr1::unique_ptr.22"*]
  %11 = alloca %"class.std::__ccr1::locale", align 4 ; [#uses=5 type=%"class.std::__ccr1::locale"*]
  %12 = alloca %"class.std::__ccr1::locale", align 4 ; [#uses=5 type=%"class.std::__ccr1::locale"*]
  %13 = alloca %"class.std::__ccr1::locale", align 4 ; [#uses=5 type=%"class.std::__ccr1::locale"*]
  %14 = alloca %"class.std::__ccr1::basic_string", align 4 ; [#uses=5 type=%"class.std::__ccr1::basic_string"*]
  %15 = alloca %"class.std::__ccr1::basic_string", align 4 ; [#uses=5 type=%"class.std::__ccr1::basic_string"*]
  %16 = alloca %"struct.std::__ccr1::pair.74", align 4 ; [#uses=3 type=%"struct.std::__ccr1::pair.74"*]
  %17 = alloca %"class.std::__ccr1::tuple", align 4 ; [#uses=3 type=%"class.std::__ccr1::tuple"*]
  %18 = alloca %"class.std::__ccr1::tuple.75", align 1 ; [#uses=2 type=%"class.std::__ccr1::tuple.75"*]
  %19 = alloca %"struct.std::__ccr1::pair.74", align 4 ; [#uses=3 type=%"struct.std::__ccr1::pair.74"*]
  %20 = alloca %"class.std::__ccr1::tuple", align 4 ; [#uses=3 type=%"class.std::__ccr1::tuple"*]
  %21 = alloca %"class.std::__ccr1::tuple.75", align 1 ; [#uses=2 type=%"class.std::__ccr1::tuple.75"*]
  %22 = alloca %"struct.std::__ccr1::pair.74", align 4 ; [#uses=3 type=%"struct.std::__ccr1::pair.74"*]
  %23 = alloca %"class.std::__ccr1::tuple", align 4 ; [#uses=3 type=%"class.std::__ccr1::tuple"*]
  %24 = alloca %"class.std::__ccr1::tuple.75", align 1 ; [#uses=2 type=%"class.std::__ccr1::tuple.75"*]
  %25 = alloca %"struct.std::__ccr1::pair.74", align 4 ; [#uses=3 type=%"struct.std::__ccr1::pair.74"*]
  %26 = alloca %"class.std::__ccr1::tuple", align 4 ; [#uses=3 type=%"class.std::__ccr1::tuple"*]
  %27 = alloca %"class.std::__ccr1::tuple.75", align 1 ; [#uses=2 type=%"class.std::__ccr1::tuple.75"*]
  %28 = alloca i8, align 1                        ; [#uses=5 type=i8*]
  %29 = alloca i8, align 1                        ; [#uses=5 type=i8*]
  %30 = alloca i8, align 1                        ; [#uses=5 type=i8*]
  %31 = alloca i8, align 1                        ; [#uses=5 type=i8*]
  %32 = load %struct.__sFILE*, %struct.__sFILE** @__stderrp, align 4, !tbaa !10 ; [#uses=1 type=%struct.__sFILE*]
  %33 = tail call i32 (%struct.__sFILE*, i8*, ...) @fprintf(%struct.__sFILE* %32, i8* getelementptr inbounds ([34 x i8], [34 x i8]* @.str.3, i32 0, i32 0), i8* getelementptr inbounds ([5 x i8], [5 x i8]* @__func__.main, i32 0, i32 0), i32 904, i8* getelementptr inbounds ([148 x i8], [148 x i8]* @.str.4, i32 0, i32 0)) #17 ; [#uses=0 type=i32]
  call void @llvm.lifetime.start.p0i8(i64 1, i8* nonnull %28) #1
  store i8 60, i8* %28, align 1, !tbaa !4
  %34 = bitcast %"struct.std::__ccr1::pair.74"* %25 to i8* ; [#uses=2 type=i8*]
  call void @llvm.lifetime.start.p0i8(i64 8, i8* nonnull %34) #1
  %35 = bitcast %"class.std::__ccr1::tuple"* %26 to i8* ; [#uses=2 type=i8*]
  call void @llvm.lifetime.start.p0i8(i64 4, i8* nonnull %35) #1
  %36 = getelementptr inbounds %"class.std::__ccr1::tuple", %"class.std::__ccr1::tuple"* %26, i32 0, i32 0, i32 0, i32 0 ; [#uses=1 type=i8**]
  store i8* %28, i8** %36, align 4
  %37 = getelementptr inbounds %"class.std::__ccr1::tuple.75", %"class.std::__ccr1::tuple.75"* %27, i32 0, i32 0 ; [#uses=2 type=i8*]
  call void @llvm.lifetime.start.p0i8(i64 1, i8* nonnull %37) #1
  call void @_ZNSt6__ccr16__treeINS_12__value_typeIciEENS_19__map_value_compareIcS2_NS_4lessIcEELb1EEENS_9allocatorIS2_EEE25__emplace_unique_key_argsIcJRKNS_21piecewise_construct_tENS_5tupleIJOcEEENSE_IJEEEEEENS_4pairINS_15__tree_iteratorIS2_PNS_11__tree_nodeIS2_PvEEiEEbEERKT_DpOT0_(%"struct.std::__ccr1::pair.74"* nonnull sret %25, %"class.std::__ccr1::__tree"* getelementptr inbounds (%"class.std::__ccr1::map", %"class.std::__ccr1::map"* @_ZL15BinopPrecedence, i32 0, i32 0), i8* nonnull dereferenceable(1) %28, %"struct.std::__ccr1::piecewise_construct_t"* nonnull dereferenceable(1) @_ZNSt6__ccr1L19piecewise_constructE, %"class.std::__ccr1::tuple"* nonnull dereferenceable(4) %26, %"class.std::__ccr1::tuple.75"* nonnull dereferenceable(1) %27) #17
  %38 = bitcast %"struct.std::__ccr1::pair.74"* %25 to %"class.std::__ccr1::__tree_node"** ; [#uses=1 type=%"class.std::__ccr1::__tree_node"**]
  %39 = load %"class.std::__ccr1::__tree_node"*, %"class.std::__ccr1::__tree_node"** %38, align 4, !tbaa !11 ; [#uses=1 type=%"class.std::__ccr1::__tree_node"*]
  %40 = getelementptr inbounds %"class.std::__ccr1::__tree_node", %"class.std::__ccr1::__tree_node"* %39, i32 0, i32 1, i32 0, i32 1 ; [#uses=1 type=i32*]
  call void @llvm.lifetime.end.p0i8(i64 1, i8* nonnull %37) #1
  call void @llvm.lifetime.end.p0i8(i64 4, i8* nonnull %35) #1
  call void @llvm.lifetime.end.p0i8(i64 8, i8* nonnull %34) #1
  store i32 10, i32* %40, align 4, !tbaa !13
  call void @llvm.lifetime.end.p0i8(i64 1, i8* nonnull %28) #1
  call void @llvm.lifetime.start.p0i8(i64 1, i8* nonnull %29) #1
  store i8 43, i8* %29, align 1, !tbaa !4
  %41 = bitcast %"struct.std::__ccr1::pair.74"* %22 to i8* ; [#uses=2 type=i8*]
  call void @llvm.lifetime.start.p0i8(i64 8, i8* nonnull %41) #1
  %42 = bitcast %"class.std::__ccr1::tuple"* %23 to i8* ; [#uses=2 type=i8*]
  call void @llvm.lifetime.start.p0i8(i64 4, i8* nonnull %42) #1
  %43 = getelementptr inbounds %"class.std::__ccr1::tuple", %"class.std::__ccr1::tuple"* %23, i32 0, i32 0, i32 0, i32 0 ; [#uses=1 type=i8**]
  store i8* %29, i8** %43, align 4
  %44 = getelementptr inbounds %"class.std::__ccr1::tuple.75", %"class.std::__ccr1::tuple.75"* %24, i32 0, i32 0 ; [#uses=2 type=i8*]
  call void @llvm.lifetime.start.p0i8(i64 1, i8* nonnull %44) #1
  call void @_ZNSt6__ccr16__treeINS_12__value_typeIciEENS_19__map_value_compareIcS2_NS_4lessIcEELb1EEENS_9allocatorIS2_EEE25__emplace_unique_key_argsIcJRKNS_21piecewise_construct_tENS_5tupleIJOcEEENSE_IJEEEEEENS_4pairINS_15__tree_iteratorIS2_PNS_11__tree_nodeIS2_PvEEiEEbEERKT_DpOT0_(%"struct.std::__ccr1::pair.74"* nonnull sret %22, %"class.std::__ccr1::__tree"* getelementptr inbounds (%"class.std::__ccr1::map", %"class.std::__ccr1::map"* @_ZL15BinopPrecedence, i32 0, i32 0), i8* nonnull dereferenceable(1) %29, %"struct.std::__ccr1::piecewise_construct_t"* nonnull dereferenceable(1) @_ZNSt6__ccr1L19piecewise_constructE, %"class.std::__ccr1::tuple"* nonnull dereferenceable(4) %23, %"class.std::__ccr1::tuple.75"* nonnull dereferenceable(1) %24) #17
  %45 = bitcast %"struct.std::__ccr1::pair.74"* %22 to %"class.std::__ccr1::__tree_node"** ; [#uses=1 type=%"class.std::__ccr1::__tree_node"**]
  %46 = load %"class.std::__ccr1::__tree_node"*, %"class.std::__ccr1::__tree_node"** %45, align 4, !tbaa !11 ; [#uses=1 type=%"class.std::__ccr1::__tree_node"*]
  %47 = getelementptr inbounds %"class.std::__ccr1::__tree_node", %"class.std::__ccr1::__tree_node"* %46, i32 0, i32 1, i32 0, i32 1 ; [#uses=1 type=i32*]
  call void @llvm.lifetime.end.p0i8(i64 1, i8* nonnull %44) #1
  call void @llvm.lifetime.end.p0i8(i64 4, i8* nonnull %42) #1
  call void @llvm.lifetime.end.p0i8(i64 8, i8* nonnull %41) #1
  store i32 20, i32* %47, align 4, !tbaa !13
  call void @llvm.lifetime.end.p0i8(i64 1, i8* nonnull %29) #1
  call void @llvm.lifetime.start.p0i8(i64 1, i8* nonnull %30) #1
  store i8 45, i8* %30, align 1, !tbaa !4
  %48 = bitcast %"struct.std::__ccr1::pair.74"* %19 to i8* ; [#uses=2 type=i8*]
  call void @llvm.lifetime.start.p0i8(i64 8, i8* nonnull %48) #1
  %49 = bitcast %"class.std::__ccr1::tuple"* %20 to i8* ; [#uses=2 type=i8*]
  call void @llvm.lifetime.start.p0i8(i64 4, i8* nonnull %49) #1
  %50 = getelementptr inbounds %"class.std::__ccr1::tuple", %"class.std::__ccr1::tuple"* %20, i32 0, i32 0, i32 0, i32 0 ; [#uses=1 type=i8**]
  store i8* %30, i8** %50, align 4
  %51 = getelementptr inbounds %"class.std::__ccr1::tuple.75", %"class.std::__ccr1::tuple.75"* %21, i32 0, i32 0 ; [#uses=2 type=i8*]
  call void @llvm.lifetime.start.p0i8(i64 1, i8* nonnull %51) #1
  call void @_ZNSt6__ccr16__treeINS_12__value_typeIciEENS_19__map_value_compareIcS2_NS_4lessIcEELb1EEENS_9allocatorIS2_EEE25__emplace_unique_key_argsIcJRKNS_21piecewise_construct_tENS_5tupleIJOcEEENSE_IJEEEEEENS_4pairINS_15__tree_iteratorIS2_PNS_11__tree_nodeIS2_PvEEiEEbEERKT_DpOT0_(%"struct.std::__ccr1::pair.74"* nonnull sret %19, %"class.std::__ccr1::__tree"* getelementptr inbounds (%"class.std::__ccr1::map", %"class.std::__ccr1::map"* @_ZL15BinopPrecedence, i32 0, i32 0), i8* nonnull dereferenceable(1) %30, %"struct.std::__ccr1::piecewise_construct_t"* nonnull dereferenceable(1) @_ZNSt6__ccr1L19piecewise_constructE, %"class.std::__ccr1::tuple"* nonnull dereferenceable(4) %20, %"class.std::__ccr1::tuple.75"* nonnull dereferenceable(1) %21) #17
  %52 = bitcast %"struct.std::__ccr1::pair.74"* %19 to %"class.std::__ccr1::__tree_node"** ; [#uses=1 type=%"class.std::__ccr1::__tree_node"**]
  %53 = load %"class.std::__ccr1::__tree_node"*, %"class.std::__ccr1::__tree_node"** %52, align 4, !tbaa !11 ; [#uses=1 type=%"class.std::__ccr1::__tree_node"*]
  %54 = getelementptr inbounds %"class.std::__ccr1::__tree_node", %"class.std::__ccr1::__tree_node"* %53, i32 0, i32 1, i32 0, i32 1 ; [#uses=1 type=i32*]
  call void @llvm.lifetime.end.p0i8(i64 1, i8* nonnull %51) #1
  call void @llvm.lifetime.end.p0i8(i64 4, i8* nonnull %49) #1
  call void @llvm.lifetime.end.p0i8(i64 8, i8* nonnull %48) #1
  store i32 20, i32* %54, align 4, !tbaa !13
  call void @llvm.lifetime.end.p0i8(i64 1, i8* nonnull %30) #1
  call void @llvm.lifetime.start.p0i8(i64 1, i8* nonnull %31) #1
  store i8 42, i8* %31, align 1, !tbaa !4
  %55 = bitcast %"struct.std::__ccr1::pair.74"* %16 to i8* ; [#uses=2 type=i8*]
  call void @llvm.lifetime.start.p0i8(i64 8, i8* nonnull %55) #1
  %56 = bitcast %"class.std::__ccr1::tuple"* %17 to i8* ; [#uses=2 type=i8*]
  call void @llvm.lifetime.start.p0i8(i64 4, i8* nonnull %56) #1
  %57 = getelementptr inbounds %"class.std::__ccr1::tuple", %"class.std::__ccr1::tuple"* %17, i32 0, i32 0, i32 0, i32 0 ; [#uses=1 type=i8**]
  store i8* %31, i8** %57, align 4
  %58 = getelementptr inbounds %"class.std::__ccr1::tuple.75", %"class.std::__ccr1::tuple.75"* %18, i32 0, i32 0 ; [#uses=2 type=i8*]
  call void @llvm.lifetime.start.p0i8(i64 1, i8* nonnull %58) #1
  call void @_ZNSt6__ccr16__treeINS_12__value_typeIciEENS_19__map_value_compareIcS2_NS_4lessIcEELb1EEENS_9allocatorIS2_EEE25__emplace_unique_key_argsIcJRKNS_21piecewise_construct_tENS_5tupleIJOcEEENSE_IJEEEEEENS_4pairINS_15__tree_iteratorIS2_PNS_11__tree_nodeIS2_PvEEiEEbEERKT_DpOT0_(%"struct.std::__ccr1::pair.74"* nonnull sret %16, %"class.std::__ccr1::__tree"* getelementptr inbounds (%"class.std::__ccr1::map", %"class.std::__ccr1::map"* @_ZL15BinopPrecedence, i32 0, i32 0), i8* nonnull dereferenceable(1) %31, %"struct.std::__ccr1::piecewise_construct_t"* nonnull dereferenceable(1) @_ZNSt6__ccr1L19piecewise_constructE, %"class.std::__ccr1::tuple"* nonnull dereferenceable(4) %17, %"class.std::__ccr1::tuple.75"* nonnull dereferenceable(1) %18) #17
  %59 = bitcast %"struct.std::__ccr1::pair.74"* %16 to %"class.std::__ccr1::__tree_node"** ; [#uses=1 type=%"class.std::__ccr1::__tree_node"**]
  %60 = load %"class.std::__ccr1::__tree_node"*, %"class.std::__ccr1::__tree_node"** %59, align 4, !tbaa !11 ; [#uses=1 type=%"class.std::__ccr1::__tree_node"*]
  %61 = getelementptr inbounds %"class.std::__ccr1::__tree_node", %"class.std::__ccr1::__tree_node"* %60, i32 0, i32 1, i32 0, i32 1 ; [#uses=1 type=i32*]
  call void @llvm.lifetime.end.p0i8(i64 1, i8* nonnull %58) #1
  call void @llvm.lifetime.end.p0i8(i64 4, i8* nonnull %56) #1
  call void @llvm.lifetime.end.p0i8(i64 8, i8* nonnull %55) #1
  store i32 40, i32* %61, align 4, !tbaa !13
  call void @llvm.lifetime.end.p0i8(i64 1, i8* nonnull %31) #1
  %62 = load i8, i8* bitcast (%"class.std::__ccr1::basic_string"* @prompt to i8*), align 4, !tbaa !4 ; [#uses=2 type=i8]
  %63 = and i8 %62, 1                             ; [#uses=1 type=i8]
  %64 = icmp eq i8 %63, 0                         ; [#uses=2 type=i1]
  %65 = load i8*, i8** getelementptr inbounds (%"class.std::__ccr1::basic_string", %"class.std::__ccr1::basic_string"* @prompt, i32 0, i32 0, i32 0, i32 0, i32 0, i32 0, i32 2), align 4 ; [#uses=1 type=i8*]
  %66 = load i32, i32* getelementptr inbounds (%"class.std::__ccr1::basic_string", %"class.std::__ccr1::basic_string"* @prompt, i32 0, i32 0, i32 0, i32 0, i32 0, i32 0, i32 1), align 4 ; [#uses=1 type=i32]
  %67 = zext i8 %62 to i32                        ; [#uses=1 type=i32]
  %68 = lshr i32 %67, 1                           ; [#uses=1 type=i32]
  %69 = select i1 %64, i8* getelementptr (%"struct.std::__ccr1::basic_string<char, std::__ccr1::char_traits<char>, std::__ccr1::allocator<char> >::__short", %"struct.std::__ccr1::basic_string<char, std::__ccr1::char_traits<char>, std::__ccr1::allocator<char> >::__short"* bitcast (%"class.std::__ccr1::basic_string"* @prompt to %"struct.std::__ccr1::basic_string<char, std::__ccr1::char_traits<char>, std::__ccr1::allocator<char> >::__short"*), i32 0, i32 1, i32 0), i8* %65 ; [#uses=1 type=i8*]
  %70 = select i1 %64, i32 %68, i32 %66           ; [#uses=1 type=i32]
  %71 = call dereferenceable(84) %"class.std::__ccr1::basic_ostream"* @_ZNSt6__ccr124__put_character_sequenceIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m(%"class.std::__ccr1::basic_ostream"* nonnull dereferenceable(84) @_ZNSt6__ccr14cerrE, i8* %69, i32 %70) #17 ; [#uses=0 type=%"class.std::__ccr1::basic_ostream"*]
  %72 = call fastcc i32 @_ZL6gettokv() #17        ; [#uses=1 type=i32]
  store i32 %72, i32* @_ZL6CurTok, align 4, !tbaa !13
  %73 = load %struct.__sFILE*, %struct.__sFILE** @__stderrp, align 4, !tbaa !10 ; [#uses=1 type=%struct.__sFILE*]
  %74 = call i32 (%struct.__sFILE*, i8*, ...) @fprintf(%struct.__sFILE* %73, i8* getelementptr inbounds ([34 x i8], [34 x i8]* @.str.3, i32 0, i32 0), i8* getelementptr inbounds ([9 x i8], [9 x i8]* @__func__._ZL8MainLoopv, i32 0, i32 0), i32 868, i8* getelementptr inbounds ([148 x i8], [148 x i8]* @.str.4, i32 0, i32 0)) #17 ; [#uses=0 type=i32]
  %75 = load i32, i32* @_ZL6CurTok, align 4, !tbaa !13 ; [#uses=1 type=i32]
  %76 = icmp eq i32 %75, -1                       ; [#uses=1 type=i1]
  br i1 %76, label %563, label %77

; <label>:77:                                     ; preds = %0
  %78 = bitcast %"class.std::__ccr1::locale"* %1 to i8* ; [#uses=3 type=i8*]
  %79 = bitcast %"class.std::__ccr1::locale"* %11 to i8* ; [#uses=3 type=i8*]
  %80 = bitcast %"class.std::__ccr1::locale"* %8 to i8* ; [#uses=3 type=i8*]
  %81 = bitcast %"class.std::__ccr1::unique_ptr.13"* %7 to i8* ; [#uses=2 type=i8*]
  %82 = bitcast %"class.std::__ccr1::locale"* %6 to i8* ; [#uses=3 type=i8*]
  %83 = bitcast %"class.std::__ccr1::unique_ptr.22"* %4 to i8* ; [#uses=4 type=i8*]
  %84 = getelementptr inbounds %"class.std::__ccr1::unique_ptr.22", %"class.std::__ccr1::unique_ptr.22"* %4, i32 0, i32 0, i32 0, i32 0 ; [#uses=1 type=%"class.(anonymous namespace)::ExprAST"**]
  %85 = bitcast %"class.std::__ccr1::basic_string"* %14 to i8* ; [#uses=7 type=i8*]
  %86 = bitcast %"class.std::__ccr1::basic_string"* %15 to i8* ; [#uses=7 type=i8*]
  %87 = bitcast %"class.std::__ccr1::unique_ptr.13"* %9 to i8* ; [#uses=4 type=i8*]
  %88 = getelementptr inbounds %"class.std::__ccr1::unique_ptr.13", %"class.std::__ccr1::unique_ptr.13"* %9, i32 0, i32 0, i32 0, i32 0 ; [#uses=4 type=%"class.(anonymous namespace)::PrototypeAST"**]
  %89 = getelementptr inbounds %"class.std::__ccr1::unique_ptr.13", %"class.std::__ccr1::unique_ptr.13"* %7, i32 0, i32 0, i32 0, i32 0 ; [#uses=2 type=%"class.(anonymous namespace)::PrototypeAST"**]
  %90 = bitcast %"class.std::__ccr1::vector"* %5 to i8* ; [#uses=3 type=i8*]
  %91 = getelementptr inbounds %"class.std::__ccr1::vector", %"class.std::__ccr1::vector"* %5, i32 0, i32 0, i32 0 ; [#uses=2 type=%"class.std::__ccr1::basic_string"**]
  %92 = getelementptr inbounds %"class.std::__ccr1::vector", %"class.std::__ccr1::vector"* %5, i32 0, i32 0, i32 1 ; [#uses=2 type=%"class.std::__ccr1::basic_string"**]
  %93 = getelementptr inbounds %"class.std::__ccr1::vector", %"class.std::__ccr1::vector"* %5, i32 0, i32 0, i32 2, i32 0, i32 0 ; [#uses=2 type=%"class.std::__ccr1::basic_string"**]
  %94 = bitcast %"class.std::__ccr1::vector"* %3 to i8* ; [#uses=2 type=i8*]
  %95 = bitcast %"class.std::__ccr1::unique_ptr.22"* %10 to i8* ; [#uses=4 type=i8*]
  %96 = bitcast %"class.std::__ccr1::basic_string"* %2 to i8* ; [#uses=6 type=i8*]
  %97 = getelementptr inbounds %"class.std::__ccr1::unique_ptr.22", %"class.std::__ccr1::unique_ptr.22"* %10, i32 0, i32 0, i32 0, i32 0 ; [#uses=2 type=%"class.(anonymous namespace)::ExprAST"**]
  %98 = getelementptr inbounds %"class.std::__ccr1::basic_string", %"class.std::__ccr1::basic_string"* %2, i32 0, i32 0, i32 0, i32 0, i32 0, i32 0, i32 2 ; [#uses=3 type=i8**]
  %99 = getelementptr inbounds %"class.std::__ccr1::basic_string", %"class.std::__ccr1::basic_string"* %2, i32 0, i32 0, i32 0, i32 0, i32 0, i32 0, i32 0 ; [#uses=1 type=i32*]
  %100 = getelementptr inbounds %"class.std::__ccr1::basic_string", %"class.std::__ccr1::basic_string"* %2, i32 0, i32 0, i32 0, i32 0, i32 0, i32 0, i32 1 ; [#uses=1 type=i32*]
  %101 = getelementptr inbounds %"class.std::__ccr1::vector", %"class.std::__ccr1::vector"* %3, i32 0, i32 0, i32 1 ; [#uses=2 type=%"class.std::__ccr1::basic_string"**]
  %102 = getelementptr inbounds %"class.std::__ccr1::vector", %"class.std::__ccr1::vector"* %3, i32 0, i32 0, i32 2, i32 0, i32 0 ; [#uses=2 type=%"class.std::__ccr1::basic_string"**]
  %103 = bitcast %"class.std::__ccr1::vector"* %3 to i32* ; [#uses=2 type=i32*]
  %104 = bitcast %"class.std::__ccr1::basic_string"** %101 to i32* ; [#uses=2 type=i32*]
  %105 = bitcast %"class.std::__ccr1::basic_string"** %102 to i32* ; [#uses=2 type=i32*]
  %106 = getelementptr inbounds %"class.std::__ccr1::vector", %"class.std::__ccr1::vector"* %3, i32 0, i32 0, i32 0 ; [#uses=1 type=%"class.std::__ccr1::basic_string"**]
  %107 = getelementptr inbounds %"class.std::__ccr1::vector", %"class.std::__ccr1::vector"* %3, i32 0, i32 0 ; [#uses=2 type=%"class.std::__ccr1::__vector_base"*]
  %108 = getelementptr inbounds %"class.std::__ccr1::vector", %"class.std::__ccr1::vector"* %5, i32 0, i32 0 ; [#uses=2 type=%"class.std::__ccr1::__vector_base"*]
  %109 = getelementptr inbounds %"class.std::__ccr1::basic_string", %"class.std::__ccr1::basic_string"* %14, i32 0, i32 0, i32 0, i32 0, i32 0, i32 0, i32 2 ; [#uses=3 type=i8**]
  %110 = getelementptr inbounds %"class.std::__ccr1::basic_string", %"class.std::__ccr1::basic_string"* %14, i32 0, i32 0, i32 0, i32 0, i32 0, i32 0, i32 1 ; [#uses=1 type=i32*]
  %111 = bitcast %"class.std::__ccr1::basic_string"* %14 to %"struct.std::__ccr1::basic_string<char, std::__ccr1::char_traits<char>, std::__ccr1::allocator<char> >::__short"* ; [#uses=1 type=%"struct.std::__ccr1::basic_string<char, std::__ccr1::char_traits<char>, std::__ccr1::allocator<char> >::__short"*]
  %112 = getelementptr inbounds %"struct.std::__ccr1::basic_string<char, std::__ccr1::char_traits<char>, std::__ccr1::allocator<char> >::__short", %"struct.std::__ccr1::basic_string<char, std::__ccr1::char_traits<char>, std::__ccr1::allocator<char> >::__short"* %111, i32 0, i32 1, i32 0 ; [#uses=1 type=i8*]
  %113 = bitcast %"class.std::__ccr1::locale"* %13 to i8* ; [#uses=3 type=i8*]
  %114 = getelementptr inbounds %"class.std::__ccr1::basic_string", %"class.std::__ccr1::basic_string"* %15, i32 0, i32 0, i32 0, i32 0, i32 0, i32 0, i32 2 ; [#uses=3 type=i8**]
  %115 = getelementptr inbounds %"class.std::__ccr1::basic_string", %"class.std::__ccr1::basic_string"* %15, i32 0, i32 0, i32 0, i32 0, i32 0, i32 0, i32 1 ; [#uses=1 type=i32*]
  %116 = bitcast %"class.std::__ccr1::basic_string"* %15 to %"struct.std::__ccr1::basic_string<char, std::__ccr1::char_traits<char>, std::__ccr1::allocator<char> >::__short"* ; [#uses=1 type=%"struct.std::__ccr1::basic_string<char, std::__ccr1::char_traits<char>, std::__ccr1::allocator<char> >::__short"*]
  %117 = getelementptr inbounds %"struct.std::__ccr1::basic_string<char, std::__ccr1::char_traits<char>, std::__ccr1::allocator<char> >::__short", %"struct.std::__ccr1::basic_string<char, std::__ccr1::char_traits<char>, std::__ccr1::allocator<char> >::__short"* %116, i32 0, i32 1, i32 0 ; [#uses=1 type=i8*]
  %118 = bitcast %"class.std::__ccr1::locale"* %12 to i8* ; [#uses=3 type=i8*]
  br label %119

; <label>:119:                                    ; preds = %560, %77
  %120 = load i8, i8* bitcast (%"class.std::__ccr1::basic_string"* @prompt to i8*), align 4, !tbaa !4 ; [#uses=2 type=i8]
  %121 = and i8 %120, 1                           ; [#uses=1 type=i8]
  %122 = icmp eq i8 %121, 0                       ; [#uses=2 type=i1]
  %123 = load i8*, i8** getelementptr inbounds (%"class.std::__ccr1::basic_string", %"class.std::__ccr1::basic_string"* @prompt, i32 0, i32 0, i32 0, i32 0, i32 0, i32 0, i32 2), align 4 ; [#uses=1 type=i8*]
  %124 = load i32, i32* getelementptr inbounds (%"class.std::__ccr1::basic_string", %"class.std::__ccr1::basic_string"* @prompt, i32 0, i32 0, i32 0, i32 0, i32 0, i32 0, i32 1), align 4 ; [#uses=1 type=i32]
  %125 = zext i8 %120 to i32                      ; [#uses=1 type=i32]
  %126 = lshr i32 %125, 1                         ; [#uses=1 type=i32]
  %127 = select i1 %122, i8* getelementptr (%"struct.std::__ccr1::basic_string<char, std::__ccr1::char_traits<char>, std::__ccr1::allocator<char> >::__short", %"struct.std::__ccr1::basic_string<char, std::__ccr1::char_traits<char>, std::__ccr1::allocator<char> >::__short"* bitcast (%"class.std::__ccr1::basic_string"* @prompt to %"struct.std::__ccr1::basic_string<char, std::__ccr1::char_traits<char>, std::__ccr1::allocator<char> >::__short"*), i32 0, i32 1, i32 0), i8* %123 ; [#uses=1 type=i8*]
  %128 = select i1 %122, i32 %126, i32 %124       ; [#uses=1 type=i32]
  %129 = call dereferenceable(84) %"class.std::__ccr1::basic_ostream"* @_ZNSt6__ccr124__put_character_sequenceIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m(%"class.std::__ccr1::basic_ostream"* nonnull dereferenceable(84) @_ZNSt6__ccr14cerrE, i8* %127, i32 %128) #17 ; [#uses=0 type=%"class.std::__ccr1::basic_ostream"*]
  %130 = load i32, i32* @_ZL6CurTok, align 4, !tbaa !13 ; [#uses=1 type=i32]
  switch i32 %130, label %427 [
    i32 59, label %131
    i32 -6, label %133
    i32 -2, label %282
    i32 -3, label %383
  ]

; <label>:131:                                    ; preds = %119
  %132 = call fastcc i32 @_ZL6gettokv() #17       ; [#uses=2 type=i32]
  store i32 %132, i32* @_ZL6CurTok, align 4, !tbaa !13
  br label %560

; <label>:133:                                    ; preds = %119
  %134 = load i8*, i8** bitcast (%"class.std::__ccr1::basic_ostream"* @_ZNSt6__ccr14cerrE to i8**), align 4, !tbaa !15 ; [#uses=1 type=i8*]
  %135 = getelementptr i8, i8* %134, i32 -12      ; [#uses=1 type=i8*]
  %136 = bitcast i8* %135 to i32*                 ; [#uses=1 type=i32*]
  %137 = load i32, i32* %136, align 4             ; [#uses=1 type=i32]
  %138 = getelementptr inbounds i8, i8* bitcast (%"class.std::__ccr1::basic_ostream"* @_ZNSt6__ccr14cerrE to i8*), i32 %137 ; [#uses=1 type=i8*]
  call void @llvm.lifetime.start.p0i8(i64 4, i8* nonnull %79) #1
  %139 = bitcast i8* %138 to %"class.std::__ccr1::ios_base"* ; [#uses=1 type=%"class.std::__ccr1::ios_base"*]
  call void @_ZNKSt6__ccr18ios_base6getlocEv(%"class.std::__ccr1::locale"* nonnull sret %11, %"class.std::__ccr1::ios_base"* %139) #17
  %140 = invoke %"class.std::__ccr1::locale::facet"* @_ZNKSt6__ccr16locale9use_facetERNS0_2idE(%"class.std::__ccr1::locale"* nonnull %11, %"class.std::__ccr1::locale::id"* nonnull dereferenceable(8) @_ZNSt6__ccr15ctypeIcE2idE) #17
          to label %141 unwind label %148         ; [#uses=2 type=%"class.std::__ccr1::locale::facet"*]

; <label>:141:                                    ; preds = %133
  %142 = bitcast %"class.std::__ccr1::locale::facet"* %140 to %"class.std::__ccr1::ctype"* ; [#uses=1 type=%"class.std::__ccr1::ctype"*]
  %143 = bitcast %"class.std::__ccr1::locale::facet"* %140 to i8 (%"class.std::__ccr1::ctype"*, i8)*** ; [#uses=1 type=i8 (%"class.std::__ccr1::ctype"*, i8)***]
  %144 = load i8 (%"class.std::__ccr1::ctype"*, i8)**, i8 (%"class.std::__ccr1::ctype"*, i8)*** %143, align 4, !tbaa !15 ; [#uses=1 type=i8 (%"class.std::__ccr1::ctype"*, i8)**]
  %145 = getelementptr inbounds i8 (%"class.std::__ccr1::ctype"*, i8)*, i8 (%"class.std::__ccr1::ctype"*, i8)** %144, i32 7 ; [#uses=1 type=i8 (%"class.std::__ccr1::ctype"*, i8)**]
  %146 = load i8 (%"class.std::__ccr1::ctype"*, i8)*, i8 (%"class.std::__ccr1::ctype"*, i8)** %145, align 4 ; [#uses=1 type=i8 (%"class.std::__ccr1::ctype"*, i8)*]
  %147 = invoke signext i8 %146(%"class.std::__ccr1::ctype"* %142, i8 signext 10) #17
          to label %151 unwind label %148         ; [#uses=1 type=i8]

; <label>:148:                                    ; preds = %141, %133
  %149 = landingpad { i8*, i32 }
          cleanup                                 ; [#uses=1 type={ i8*, i32 }]
  %150 = call %"class.std::__ccr1::locale"* @_ZNSt6__ccr16localeD1Ev(%"class.std::__ccr1::locale"* nonnull %11) #16 ; [#uses=0 type=%"class.std::__ccr1::locale"*]
  call void @llvm.lifetime.end.p0i8(i64 4, i8* nonnull %79) #1
  resume { i8*, i32 } %149

; <label>:151:                                    ; preds = %141
  %152 = call %"class.std::__ccr1::locale"* @_ZNSt6__ccr16localeD1Ev(%"class.std::__ccr1::locale"* nonnull %11) #16 ; [#uses=0 type=%"class.std::__ccr1::locale"*]
  call void @llvm.lifetime.end.p0i8(i64 4, i8* nonnull %79) #1
  %153 = call dereferenceable(84) %"class.std::__ccr1::basic_ostream"* @_ZNSt6__ccr113basic_ostreamIcNS_11char_traitsIcEEE3putEc(%"class.std::__ccr1::basic_ostream"* nonnull @_ZNSt6__ccr14cerrE, i8 signext %147) #17 ; [#uses=0 type=%"class.std::__ccr1::basic_ostream"*]
  %154 = call dereferenceable(84) %"class.std::__ccr1::basic_ostream"* @_ZNSt6__ccr113basic_ostreamIcNS_11char_traitsIcEEE5flushEv(%"class.std::__ccr1::basic_ostream"* nonnull @_ZNSt6__ccr14cerrE) #17 ; [#uses=0 type=%"class.std::__ccr1::basic_ostream"*]
  %155 = load %struct.__sFILE*, %struct.__sFILE** @__stderrp, align 4, !tbaa !10 ; [#uses=1 type=%struct.__sFILE*]
  %156 = call i32 (%struct.__sFILE*, i8*, ...) @fprintf(%struct.__sFILE* %155, i8* getelementptr inbounds ([34 x i8], [34 x i8]* @.str.3, i32 0, i32 0), i8* getelementptr inbounds ([18 x i8], [18 x i8]* @__func__._ZL17HandleCDefinitionv, i32 0, i32 0), i32 832, i8* getelementptr inbounds ([148 x i8], [148 x i8]* @.str.4, i32 0, i32 0)) #17 ; [#uses=0 type=i32]
  %157 = load %struct.__sFILE*, %struct.__sFILE** @__stderrp, align 4, !tbaa !10, !noalias !17 ; [#uses=1 type=%struct.__sFILE*]
  %158 = call i32 (%struct.__sFILE*, i8*, ...) @fprintf(%struct.__sFILE* %157, i8* getelementptr inbounds ([34 x i8], [34 x i8]* @.str.3, i32 0, i32 0), i8* getelementptr inbounds ([17 x i8], [17 x i8]* @__func__._ZL16ParseCDefinitionv, i32 0, i32 0), i32 735, i8* getelementptr inbounds ([148 x i8], [148 x i8]* @.str.4, i32 0, i32 0)) #17, !noalias !17 ; [#uses=0 type=i32]
  call void @llvm.lifetime.start.p0i8(i64 12, i8* nonnull %85) #1, !noalias !17
  call void @llvm.memset.p0i8.i64(i8* nonnull %85, i8 0, i64 12, i32 4, i1 false) #1, !noalias !17
  call void @llvm.lifetime.start.p0i8(i64 12, i8* nonnull %86) #1, !noalias !17
  call void @llvm.memset.p0i8.i64(i8* nonnull %86, i8 0, i64 12, i32 4, i1 false) #1, !noalias !17
  br label %159

; <label>:159:                                    ; preds = %162, %151
  %160 = call i32 @getchar() #17, !noalias !17    ; [#uses=3 type=i32]
  store i32 %160, i32* @_ZL8LastChar, align 4, !tbaa !13, !noalias !17
  store i32 %160, i32* @_ZL6CurTok, align 4, !tbaa !13, !noalias !17
  %161 = trunc i32 %160 to i8                     ; [#uses=1 type=i8]
  invoke void @_ZNSt6__ccr112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE9push_backEc(%"class.std::__ccr1::basic_string"* nonnull %14, i8 signext %161) #17
          to label %162 unwind label %262, !noalias !17

; <label>:162:                                    ; preds = %159
  %163 = load i32, i32* @_ZL8LastChar, align 4, !tbaa !13, !noalias !17 ; [#uses=1 type=i32]
  switch i32 %163, label %159 [
    i32 -1, label %164
    i32 32, label %164
    i32 13, label %164
    i32 10, label %164
  ]

; <label>:164:                                    ; preds = %162, %162, %162, %162
  br label %165

; <label>:165:                                    ; preds = %164, %168
  %166 = call i32 @getchar() #17, !noalias !17    ; [#uses=3 type=i32]
  store i32 %166, i32* @_ZL8LastChar, align 4, !tbaa !13, !noalias !17
  store i32 %166, i32* @_ZL6CurTok, align 4, !tbaa !13, !noalias !17
  %167 = trunc i32 %166 to i8                     ; [#uses=1 type=i8]
  invoke void @_ZNSt6__ccr112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE9push_backEc(%"class.std::__ccr1::basic_string"* nonnull %15, i8 signext %167) #17
          to label %168 unwind label %260, !noalias !17

; <label>:168:                                    ; preds = %165
  %169 = load i32, i32* @_ZL8LastChar, align 4, !tbaa !13, !noalias !17 ; [#uses=1 type=i32]
  switch i32 %169, label %165 [
    i32 -1, label %170
    i32 13, label %170
    i32 10, label %170
  ]

; <label>:170:                                    ; preds = %168, %168, %168
  %171 = invoke dereferenceable(84) %"class.std::__ccr1::basic_ostream"* @_ZNSt6__ccr124__put_character_sequenceIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m(%"class.std::__ccr1::basic_ostream"* nonnull dereferenceable(84) @_ZNSt6__ccr14cerrE, i8* getelementptr inbounds ([14 x i8], [14 x i8]* @.str.15, i32 0, i32 0), i32 13) #17
          to label %172 unwind label %264, !noalias !17 ; [#uses=1 type=%"class.std::__ccr1::basic_ostream"*]

; <label>:172:                                    ; preds = %170
  %173 = load i8, i8* %85, align 4, !tbaa !4, !noalias !17 ; [#uses=2 type=i8]
  %174 = and i8 %173, 1                           ; [#uses=1 type=i8]
  %175 = icmp eq i8 %174, 0                       ; [#uses=2 type=i1]
  %176 = load i8*, i8** %109, align 4, !noalias !17 ; [#uses=1 type=i8*]
  %177 = load i32, i32* %110, align 4, !noalias !17 ; [#uses=1 type=i32]
  %178 = zext i8 %173 to i32                      ; [#uses=1 type=i32]
  %179 = lshr i32 %178, 1                         ; [#uses=1 type=i32]
  %180 = select i1 %175, i8* %112, i8* %176       ; [#uses=1 type=i8*]
  %181 = select i1 %175, i32 %179, i32 %177       ; [#uses=1 type=i32]
  %182 = invoke dereferenceable(84) %"class.std::__ccr1::basic_ostream"* @_ZNSt6__ccr124__put_character_sequenceIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m(%"class.std::__ccr1::basic_ostream"* nonnull dereferenceable(84) %171, i8* %180, i32 %181) #17
          to label %183 unwind label %264, !noalias !17 ; [#uses=4 type=%"class.std::__ccr1::basic_ostream"*]

; <label>:183:                                    ; preds = %172
  %184 = bitcast %"class.std::__ccr1::basic_ostream"* %182 to i8** ; [#uses=1 type=i8**]
  %185 = load i8*, i8** %184, align 4, !tbaa !15, !noalias !17 ; [#uses=1 type=i8*]
  %186 = getelementptr i8, i8* %185, i32 -12      ; [#uses=1 type=i8*]
  %187 = bitcast i8* %186 to i32*                 ; [#uses=1 type=i32*]
  %188 = load i32, i32* %187, align 4, !noalias !17 ; [#uses=1 type=i32]
  %189 = bitcast %"class.std::__ccr1::basic_ostream"* %182 to i8* ; [#uses=1 type=i8*]
  %190 = getelementptr inbounds i8, i8* %189, i32 %188 ; [#uses=1 type=i8*]
  call void @llvm.lifetime.start.p0i8(i64 4, i8* nonnull %113) #1, !noalias !17
  %191 = bitcast i8* %190 to %"class.std::__ccr1::ios_base"* ; [#uses=1 type=%"class.std::__ccr1::ios_base"*]
  invoke void @_ZNKSt6__ccr18ios_base6getlocEv(%"class.std::__ccr1::locale"* nonnull sret %13, %"class.std::__ccr1::ios_base"* %191) #17
          to label %192 unwind label %264, !noalias !17

; <label>:192:                                    ; preds = %183
  %193 = invoke %"class.std::__ccr1::locale::facet"* @_ZNKSt6__ccr16locale9use_facetERNS0_2idE(%"class.std::__ccr1::locale"* nonnull %13, %"class.std::__ccr1::locale::id"* nonnull dereferenceable(8) @_ZNSt6__ccr15ctypeIcE2idE) #17
          to label %194 unwind label %201, !noalias !17 ; [#uses=2 type=%"class.std::__ccr1::locale::facet"*]

; <label>:194:                                    ; preds = %192
  %195 = bitcast %"class.std::__ccr1::locale::facet"* %193 to %"class.std::__ccr1::ctype"* ; [#uses=1 type=%"class.std::__ccr1::ctype"*]
  %196 = bitcast %"class.std::__ccr1::locale::facet"* %193 to i8 (%"class.std::__ccr1::ctype"*, i8)*** ; [#uses=1 type=i8 (%"class.std::__ccr1::ctype"*, i8)***]
  %197 = load i8 (%"class.std::__ccr1::ctype"*, i8)**, i8 (%"class.std::__ccr1::ctype"*, i8)*** %196, align 4, !tbaa !15, !noalias !17 ; [#uses=1 type=i8 (%"class.std::__ccr1::ctype"*, i8)**]
  %198 = getelementptr inbounds i8 (%"class.std::__ccr1::ctype"*, i8)*, i8 (%"class.std::__ccr1::ctype"*, i8)** %197, i32 7 ; [#uses=1 type=i8 (%"class.std::__ccr1::ctype"*, i8)**]
  %199 = load i8 (%"class.std::__ccr1::ctype"*, i8)*, i8 (%"class.std::__ccr1::ctype"*, i8)** %198, align 4, !noalias !17 ; [#uses=1 type=i8 (%"class.std::__ccr1::ctype"*, i8)*]
  %200 = invoke signext i8 %199(%"class.std::__ccr1::ctype"* %195, i8 signext 10) #17
          to label %204 unwind label %201, !noalias !17 ; [#uses=1 type=i8]

; <label>:201:                                    ; preds = %194, %192
  %202 = landingpad { i8*, i32 }
          cleanup                                 ; [#uses=1 type={ i8*, i32 }]
  %203 = call %"class.std::__ccr1::locale"* @_ZNSt6__ccr16localeD1Ev(%"class.std::__ccr1::locale"* nonnull %13) #16, !noalias !17 ; [#uses=0 type=%"class.std::__ccr1::locale"*]
  call void @llvm.lifetime.end.p0i8(i64 4, i8* nonnull %113) #1, !noalias !17
  br label %266

; <label>:204:                                    ; preds = %194
  %205 = call %"class.std::__ccr1::locale"* @_ZNSt6__ccr16localeD1Ev(%"class.std::__ccr1::locale"* nonnull %13) #16, !noalias !17 ; [#uses=0 type=%"class.std::__ccr1::locale"*]
  call void @llvm.lifetime.end.p0i8(i64 4, i8* nonnull %113) #1, !noalias !17
  %206 = invoke dereferenceable(84) %"class.std::__ccr1::basic_ostream"* @_ZNSt6__ccr113basic_ostreamIcNS_11char_traitsIcEEE3putEc(%"class.std::__ccr1::basic_ostream"* nonnull %182, i8 signext %200) #17
          to label %207 unwind label %264, !noalias !17 ; [#uses=0 type=%"class.std::__ccr1::basic_ostream"*]

; <label>:207:                                    ; preds = %204
  %208 = invoke dereferenceable(84) %"class.std::__ccr1::basic_ostream"* @_ZNSt6__ccr113basic_ostreamIcNS_11char_traitsIcEEE5flushEv(%"class.std::__ccr1::basic_ostream"* nonnull %182) #17
          to label %209 unwind label %264, !noalias !17 ; [#uses=0 type=%"class.std::__ccr1::basic_ostream"*]

; <label>:209:                                    ; preds = %207
  %210 = invoke dereferenceable(84) %"class.std::__ccr1::basic_ostream"* @_ZNSt6__ccr124__put_character_sequenceIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m(%"class.std::__ccr1::basic_ostream"* nonnull dereferenceable(84) @_ZNSt6__ccr14cerrE, i8* getelementptr inbounds ([13 x i8], [13 x i8]* @.str.16, i32 0, i32 0), i32 12) #17
          to label %211 unwind label %264, !noalias !17 ; [#uses=1 type=%"class.std::__ccr1::basic_ostream"*]

; <label>:211:                                    ; preds = %209
  %212 = load i8, i8* %86, align 4, !tbaa !4, !noalias !17 ; [#uses=2 type=i8]
  %213 = and i8 %212, 1                           ; [#uses=1 type=i8]
  %214 = icmp eq i8 %213, 0                       ; [#uses=2 type=i1]
  %215 = load i8*, i8** %114, align 4, !noalias !17 ; [#uses=1 type=i8*]
  %216 = load i32, i32* %115, align 4, !noalias !17 ; [#uses=1 type=i32]
  %217 = zext i8 %212 to i32                      ; [#uses=1 type=i32]
  %218 = lshr i32 %217, 1                         ; [#uses=1 type=i32]
  %219 = select i1 %214, i8* %117, i8* %215       ; [#uses=1 type=i8*]
  %220 = select i1 %214, i32 %218, i32 %216       ; [#uses=1 type=i32]
  %221 = invoke dereferenceable(84) %"class.std::__ccr1::basic_ostream"* @_ZNSt6__ccr124__put_character_sequenceIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m(%"class.std::__ccr1::basic_ostream"* nonnull dereferenceable(84) %210, i8* %219, i32 %220) #17
          to label %222 unwind label %264, !noalias !17 ; [#uses=4 type=%"class.std::__ccr1::basic_ostream"*]

; <label>:222:                                    ; preds = %211
  %223 = bitcast %"class.std::__ccr1::basic_ostream"* %221 to i8** ; [#uses=1 type=i8**]
  %224 = load i8*, i8** %223, align 4, !tbaa !15, !noalias !17 ; [#uses=1 type=i8*]
  %225 = getelementptr i8, i8* %224, i32 -12      ; [#uses=1 type=i8*]
  %226 = bitcast i8* %225 to i32*                 ; [#uses=1 type=i32*]
  %227 = load i32, i32* %226, align 4, !noalias !17 ; [#uses=1 type=i32]
  %228 = bitcast %"class.std::__ccr1::basic_ostream"* %221 to i8* ; [#uses=1 type=i8*]
  %229 = getelementptr inbounds i8, i8* %228, i32 %227 ; [#uses=1 type=i8*]
  call void @llvm.lifetime.start.p0i8(i64 4, i8* nonnull %118) #1, !noalias !17
  %230 = bitcast i8* %229 to %"class.std::__ccr1::ios_base"* ; [#uses=1 type=%"class.std::__ccr1::ios_base"*]
  invoke void @_ZNKSt6__ccr18ios_base6getlocEv(%"class.std::__ccr1::locale"* nonnull sret %12, %"class.std::__ccr1::ios_base"* %230) #17
          to label %231 unwind label %264, !noalias !17

; <label>:231:                                    ; preds = %222
  %232 = invoke %"class.std::__ccr1::locale::facet"* @_ZNKSt6__ccr16locale9use_facetERNS0_2idE(%"class.std::__ccr1::locale"* nonnull %12, %"class.std::__ccr1::locale::id"* nonnull dereferenceable(8) @_ZNSt6__ccr15ctypeIcE2idE) #17
          to label %233 unwind label %240, !noalias !17 ; [#uses=2 type=%"class.std::__ccr1::locale::facet"*]

; <label>:233:                                    ; preds = %231
  %234 = bitcast %"class.std::__ccr1::locale::facet"* %232 to %"class.std::__ccr1::ctype"* ; [#uses=1 type=%"class.std::__ccr1::ctype"*]
  %235 = bitcast %"class.std::__ccr1::locale::facet"* %232 to i8 (%"class.std::__ccr1::ctype"*, i8)*** ; [#uses=1 type=i8 (%"class.std::__ccr1::ctype"*, i8)***]
  %236 = load i8 (%"class.std::__ccr1::ctype"*, i8)**, i8 (%"class.std::__ccr1::ctype"*, i8)*** %235, align 4, !tbaa !15, !noalias !17 ; [#uses=1 type=i8 (%"class.std::__ccr1::ctype"*, i8)**]
  %237 = getelementptr inbounds i8 (%"class.std::__ccr1::ctype"*, i8)*, i8 (%"class.std::__ccr1::ctype"*, i8)** %236, i32 7 ; [#uses=1 type=i8 (%"class.std::__ccr1::ctype"*, i8)**]
  %238 = load i8 (%"class.std::__ccr1::ctype"*, i8)*, i8 (%"class.std::__ccr1::ctype"*, i8)** %237, align 4, !noalias !17 ; [#uses=1 type=i8 (%"class.std::__ccr1::ctype"*, i8)*]
  %239 = invoke signext i8 %238(%"class.std::__ccr1::ctype"* %234, i8 signext 10) #17
          to label %243 unwind label %240, !noalias !17 ; [#uses=1 type=i8]

; <label>:240:                                    ; preds = %233, %231
  %241 = landingpad { i8*, i32 }
          cleanup                                 ; [#uses=1 type={ i8*, i32 }]
  %242 = call %"class.std::__ccr1::locale"* @_ZNSt6__ccr16localeD1Ev(%"class.std::__ccr1::locale"* nonnull %12) #16, !noalias !17 ; [#uses=0 type=%"class.std::__ccr1::locale"*]
  call void @llvm.lifetime.end.p0i8(i64 4, i8* nonnull %118) #1, !noalias !17
  br label %266

; <label>:243:                                    ; preds = %233
  %244 = call %"class.std::__ccr1::locale"* @_ZNSt6__ccr16localeD1Ev(%"class.std::__ccr1::locale"* nonnull %12) #16, !noalias !17 ; [#uses=0 type=%"class.std::__ccr1::locale"*]
  call void @llvm.lifetime.end.p0i8(i64 4, i8* nonnull %118) #1, !noalias !17
  %245 = invoke dereferenceable(84) %"class.std::__ccr1::basic_ostream"* @_ZNSt6__ccr113basic_ostreamIcNS_11char_traitsIcEEE3putEc(%"class.std::__ccr1::basic_ostream"* nonnull %221, i8 signext %239) #17
          to label %246 unwind label %264, !noalias !17 ; [#uses=0 type=%"class.std::__ccr1::basic_ostream"*]

; <label>:246:                                    ; preds = %243
  %247 = invoke dereferenceable(84) %"class.std::__ccr1::basic_ostream"* @_ZNSt6__ccr113basic_ostreamIcNS_11char_traitsIcEEE5flushEv(%"class.std::__ccr1::basic_ostream"* nonnull %221) #17
          to label %248 unwind label %264, !noalias !17 ; [#uses=0 type=%"class.std::__ccr1::basic_ostream"*]

; <label>:248:                                    ; preds = %246
  %249 = load i8, i8* %86, align 4, !tbaa !4, !noalias !17 ; [#uses=1 type=i8]
  %250 = and i8 %249, 1                           ; [#uses=1 type=i8]
  %251 = icmp eq i8 %250, 0                       ; [#uses=1 type=i1]
  br i1 %251, label %254, label %252

; <label>:252:                                    ; preds = %248
  %253 = load i8*, i8** %114, align 4, !tbaa !4, !noalias !17 ; [#uses=1 type=i8*]
  call void @_ZdlPv(i8* %253) #15, !noalias !17
  br label %254

; <label>:254:                                    ; preds = %252, %248
  call void @llvm.lifetime.end.p0i8(i64 12, i8* nonnull %86) #1, !noalias !17
  %255 = load i8, i8* %85, align 4, !tbaa !4, !noalias !17 ; [#uses=1 type=i8]
  %256 = and i8 %255, 1                           ; [#uses=1 type=i8]
  %257 = icmp eq i8 %256, 0                       ; [#uses=1 type=i1]
  br i1 %257, label %280, label %258

; <label>:258:                                    ; preds = %254
  %259 = load i8*, i8** %109, align 4, !tbaa !4, !noalias !17 ; [#uses=1 type=i8*]
  call void @_ZdlPv(i8* %259) #15, !noalias !17
  br label %280

; <label>:260:                                    ; preds = %165
  %261 = landingpad { i8*, i32 }
          cleanup                                 ; [#uses=1 type={ i8*, i32 }]
  br label %266

; <label>:262:                                    ; preds = %159
  %263 = landingpad { i8*, i32 }
          cleanup                                 ; [#uses=1 type={ i8*, i32 }]
  br label %266

; <label>:264:                                    ; preds = %246, %243, %222, %211, %209, %207, %204, %183, %172, %170
  %265 = landingpad { i8*, i32 }
          cleanup                                 ; [#uses=1 type={ i8*, i32 }]
  br label %266

; <label>:266:                                    ; preds = %264, %262, %260, %240, %201
  %267 = phi { i8*, i32 } [ %202, %201 ], [ %241, %240 ], [ %261, %260 ], [ %263, %262 ], [ %265, %264 ] ; [#uses=1 type={ i8*, i32 }]
  %268 = load i8, i8* %86, align 4, !tbaa !4, !noalias !17 ; [#uses=1 type=i8]
  %269 = and i8 %268, 1                           ; [#uses=1 type=i8]
  %270 = icmp eq i8 %269, 0                       ; [#uses=1 type=i1]
  br i1 %270, label %273, label %271

; <label>:271:                                    ; preds = %266
  %272 = load i8*, i8** %114, align 4, !tbaa !4, !noalias !17 ; [#uses=1 type=i8*]
  call void @_ZdlPv(i8* %272) #15, !noalias !17
  br label %273

; <label>:273:                                    ; preds = %271, %266
  call void @llvm.lifetime.end.p0i8(i64 12, i8* nonnull %86) #1, !noalias !17
  %274 = load i8, i8* %85, align 4, !tbaa !4, !noalias !17 ; [#uses=1 type=i8]
  %275 = and i8 %274, 1                           ; [#uses=1 type=i8]
  %276 = icmp eq i8 %275, 0                       ; [#uses=1 type=i1]
  br i1 %276, label %279, label %277

; <label>:277:                                    ; preds = %273
  %278 = load i8*, i8** %109, align 4, !tbaa !4, !noalias !17 ; [#uses=1 type=i8*]
  call void @_ZdlPv(i8* %278) #15, !noalias !17
  br label %279

; <label>:279:                                    ; preds = %277, %273
  call void @llvm.lifetime.end.p0i8(i64 12, i8* nonnull %85) #1, !noalias !17
  resume { i8*, i32 } %267

; <label>:280:                                    ; preds = %258, %254
  call void @llvm.lifetime.end.p0i8(i64 12, i8* nonnull %85) #1, !noalias !17
  %281 = call fastcc i32 @_ZL6gettokv() #17       ; [#uses=2 type=i32]
  store i32 %281, i32* @_ZL6CurTok, align 4, !tbaa !13
  br label %560

; <label>:282:                                    ; preds = %119
  %283 = load i8*, i8** bitcast (%"class.std::__ccr1::basic_ostream"* @_ZNSt6__ccr14cerrE to i8**), align 4, !tbaa !15 ; [#uses=1 type=i8*]
  %284 = getelementptr i8, i8* %283, i32 -12      ; [#uses=1 type=i8*]
  %285 = bitcast i8* %284 to i32*                 ; [#uses=1 type=i32*]
  %286 = load i32, i32* %285, align 4             ; [#uses=1 type=i32]
  %287 = getelementptr inbounds i8, i8* bitcast (%"class.std::__ccr1::basic_ostream"* @_ZNSt6__ccr14cerrE to i8*), i32 %286 ; [#uses=1 type=i8*]
  call void @llvm.lifetime.start.p0i8(i64 4, i8* nonnull %80) #1
  %288 = bitcast i8* %287 to %"class.std::__ccr1::ios_base"* ; [#uses=1 type=%"class.std::__ccr1::ios_base"*]
  call void @_ZNKSt6__ccr18ios_base6getlocEv(%"class.std::__ccr1::locale"* nonnull sret %8, %"class.std::__ccr1::ios_base"* %288) #17
  %289 = invoke %"class.std::__ccr1::locale::facet"* @_ZNKSt6__ccr16locale9use_facetERNS0_2idE(%"class.std::__ccr1::locale"* nonnull %8, %"class.std::__ccr1::locale::id"* nonnull dereferenceable(8) @_ZNSt6__ccr15ctypeIcE2idE) #17
          to label %290 unwind label %297         ; [#uses=2 type=%"class.std::__ccr1::locale::facet"*]

; <label>:290:                                    ; preds = %282
  %291 = bitcast %"class.std::__ccr1::locale::facet"* %289 to %"class.std::__ccr1::ctype"* ; [#uses=1 type=%"class.std::__ccr1::ctype"*]
  %292 = bitcast %"class.std::__ccr1::locale::facet"* %289 to i8 (%"class.std::__ccr1::ctype"*, i8)*** ; [#uses=1 type=i8 (%"class.std::__ccr1::ctype"*, i8)***]
  %293 = load i8 (%"class.std::__ccr1::ctype"*, i8)**, i8 (%"class.std::__ccr1::ctype"*, i8)*** %292, align 4, !tbaa !15 ; [#uses=1 type=i8 (%"class.std::__ccr1::ctype"*, i8)**]
  %294 = getelementptr inbounds i8 (%"class.std::__ccr1::ctype"*, i8)*, i8 (%"class.std::__ccr1::ctype"*, i8)** %293, i32 7 ; [#uses=1 type=i8 (%"class.std::__ccr1::ctype"*, i8)**]
  %295 = load i8 (%"class.std::__ccr1::ctype"*, i8)*, i8 (%"class.std::__ccr1::ctype"*, i8)** %294, align 4 ; [#uses=1 type=i8 (%"class.std::__ccr1::ctype"*, i8)*]
  %296 = invoke signext i8 %295(%"class.std::__ccr1::ctype"* %291, i8 signext 10) #17
          to label %300 unwind label %297         ; [#uses=1 type=i8]

; <label>:297:                                    ; preds = %290, %282
  %298 = landingpad { i8*, i32 }
          cleanup                                 ; [#uses=1 type={ i8*, i32 }]
  %299 = call %"class.std::__ccr1::locale"* @_ZNSt6__ccr16localeD1Ev(%"class.std::__ccr1::locale"* nonnull %8) #16 ; [#uses=0 type=%"class.std::__ccr1::locale"*]
  call void @llvm.lifetime.end.p0i8(i64 4, i8* nonnull %80) #1
  resume { i8*, i32 } %298

; <label>:300:                                    ; preds = %290
  %301 = call %"class.std::__ccr1::locale"* @_ZNSt6__ccr16localeD1Ev(%"class.std::__ccr1::locale"* nonnull %8) #16 ; [#uses=0 type=%"class.std::__ccr1::locale"*]
  call void @llvm.lifetime.end.p0i8(i64 4, i8* nonnull %80) #1
  %302 = call dereferenceable(84) %"class.std::__ccr1::basic_ostream"* @_ZNSt6__ccr113basic_ostreamIcNS_11char_traitsIcEEE3putEc(%"class.std::__ccr1::basic_ostream"* nonnull @_ZNSt6__ccr14cerrE, i8 signext %296) #17 ; [#uses=0 type=%"class.std::__ccr1::basic_ostream"*]
  %303 = call dereferenceable(84) %"class.std::__ccr1::basic_ostream"* @_ZNSt6__ccr113basic_ostreamIcNS_11char_traitsIcEEE5flushEv(%"class.std::__ccr1::basic_ostream"* nonnull @_ZNSt6__ccr14cerrE) #17 ; [#uses=0 type=%"class.std::__ccr1::basic_ostream"*]
  %304 = load %struct.__sFILE*, %struct.__sFILE** @__stderrp, align 4, !tbaa !10 ; [#uses=1 type=%struct.__sFILE*]
  %305 = call i32 (%struct.__sFILE*, i8*, ...) @fprintf(%struct.__sFILE* %304, i8* getelementptr inbounds ([34 x i8], [34 x i8]* @.str.3, i32 0, i32 0), i8* getelementptr inbounds ([17 x i8], [17 x i8]* @__func__._ZL16HandleDefinitionv, i32 0, i32 0), i32 821, i8* getelementptr inbounds ([148 x i8], [148 x i8]* @.str.4, i32 0, i32 0)) #17 ; [#uses=0 type=i32]
  %306 = load %struct.__sFILE*, %struct.__sFILE** @__stderrp, align 4, !tbaa !10, !noalias !20 ; [#uses=1 type=%struct.__sFILE*]
  %307 = call i32 (%struct.__sFILE*, i8*, ...) @fprintf(%struct.__sFILE* %306, i8* getelementptr inbounds ([34 x i8], [34 x i8]* @.str.3, i32 0, i32 0), i8* getelementptr inbounds ([16 x i8], [16 x i8]* @__func__._ZL15ParseDefinitionv, i32 0, i32 0), i32 779, i8* getelementptr inbounds ([148 x i8], [148 x i8]* @.str.4, i32 0, i32 0)) #17, !noalias !20 ; [#uses=0 type=i32]
  %308 = call fastcc i32 @_ZL6gettokv() #17, !noalias !20 ; [#uses=1 type=i32]
  store i32 %308, i32* @_ZL6CurTok, align 4, !tbaa !13, !noalias !20
  call void @llvm.lifetime.start.p0i8(i64 4, i8* nonnull %87) #1, !noalias !20
  call fastcc void @_ZL14ParsePrototypev(%"class.std::__ccr1::unique_ptr.13"* nonnull sret %9) #17, !noalias !20
  %309 = load %"class.(anonymous namespace)::PrototypeAST"*, %"class.(anonymous namespace)::PrototypeAST"** %88, align 4, !tbaa !10, !noalias !20 ; [#uses=8 type=%"class.(anonymous namespace)::PrototypeAST"*]
  %310 = icmp eq %"class.(anonymous namespace)::PrototypeAST"* %309, null ; [#uses=1 type=i1]
  %311 = ptrtoint %"class.(anonymous namespace)::PrototypeAST"* %309 to i32 ; [#uses=1 type=i32]
  br i1 %310, label %312, label %313

; <label>:312:                                    ; preds = %300
  store %"class.(anonymous namespace)::PrototypeAST"* null, %"class.(anonymous namespace)::PrototypeAST"** %88, align 4, !tbaa !10, !noalias !20
  br label %381

; <label>:313:                                    ; preds = %300
  call void @llvm.lifetime.start.p0i8(i64 4, i8* nonnull %95) #1, !noalias !20
  invoke fastcc void @_ZL15ParseExpressionv(%"class.std::__ccr1::unique_ptr.22"* nonnull sret %10) #17
          to label %314 unwind label %319, !noalias !20

; <label>:314:                                    ; preds = %313
  %315 = load %"class.(anonymous namespace)::ExprAST"*, %"class.(anonymous namespace)::ExprAST"** %97, align 4, !tbaa !10, !noalias !20 ; [#uses=5 type=%"class.(anonymous namespace)::ExprAST"*]
  %316 = icmp eq %"class.(anonymous namespace)::ExprAST"* %315, null ; [#uses=1 type=i1]
  br i1 %316, label %346, label %317

; <label>:317:                                    ; preds = %314
  %318 = invoke i8* @_Znwm(i32 8) #18
          to label %357 unwind label %323, !noalias !20 ; [#uses=4 type=i8*]

; <label>:319:                                    ; preds = %313
  %320 = landingpad { i8*, i32 }
          cleanup                                 ; [#uses=2 type={ i8*, i32 }]
  %321 = extractvalue { i8*, i32 } %320, 0        ; [#uses=1 type=i8*]
  %322 = extractvalue { i8*, i32 } %320, 1        ; [#uses=1 type=i32]
  br label %331

; <label>:323:                                    ; preds = %317
  %324 = landingpad { i8*, i32 }
          cleanup                                 ; [#uses=2 type={ i8*, i32 }]
  %325 = extractvalue { i8*, i32 } %324, 0        ; [#uses=1 type=i8*]
  %326 = extractvalue { i8*, i32 } %324, 1        ; [#uses=1 type=i32]
  store %"class.(anonymous namespace)::ExprAST"* null, %"class.(anonymous namespace)::ExprAST"** %97, align 4, !tbaa !10, !noalias !20
  %327 = bitcast %"class.(anonymous namespace)::ExprAST"* %315 to void (%"class.(anonymous namespace)::ExprAST"*)*** ; [#uses=1 type=void (%"class.(anonymous namespace)::ExprAST"*)***]
  %328 = load void (%"class.(anonymous namespace)::ExprAST"*)**, void (%"class.(anonymous namespace)::ExprAST"*)*** %327, align 4, !tbaa !15, !noalias !20 ; [#uses=1 type=void (%"class.(anonymous namespace)::ExprAST"*)**]
  %329 = getelementptr inbounds void (%"class.(anonymous namespace)::ExprAST"*)*, void (%"class.(anonymous namespace)::ExprAST"*)** %328, i32 1 ; [#uses=1 type=void (%"class.(anonymous namespace)::ExprAST"*)**]
  %330 = load void (%"class.(anonymous namespace)::ExprAST"*)*, void (%"class.(anonymous namespace)::ExprAST"*)** %329, align 4, !noalias !20 ; [#uses=1 type=void (%"class.(anonymous namespace)::ExprAST"*)*]
  call void %330(%"class.(anonymous namespace)::ExprAST"* nonnull %315) #16, !noalias !20
  br label %331

; <label>:331:                                    ; preds = %323, %319
  %332 = phi i8* [ %325, %323 ], [ %321, %319 ]   ; [#uses=1 type=i8*]
  %333 = phi i32 [ %326, %323 ], [ %322, %319 ]   ; [#uses=1 type=i32]
  call void @llvm.lifetime.end.p0i8(i64 4, i8* nonnull %95) #1, !noalias !20
  store %"class.(anonymous namespace)::PrototypeAST"* null, %"class.(anonymous namespace)::PrototypeAST"** %88, align 4, !tbaa !10, !noalias !20
  %334 = getelementptr inbounds %"class.(anonymous namespace)::PrototypeAST", %"class.(anonymous namespace)::PrototypeAST"* %309, i32 0, i32 1, i32 0 ; [#uses=1 type=%"class.std::__ccr1::__vector_base"*]
  %335 = call %"class.std::__ccr1::__vector_base"* @_ZNSt6__ccr113__vector_baseINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEENS4_IS6_EEED2Ev(%"class.std::__ccr1::__vector_base"* nonnull %334) #16, !noalias !20 ; [#uses=0 type=%"class.std::__ccr1::__vector_base"*]
  %336 = bitcast %"class.(anonymous namespace)::PrototypeAST"* %309 to i8* ; [#uses=2 type=i8*]
  %337 = load i8, i8* %336, align 4, !tbaa !4, !noalias !20 ; [#uses=1 type=i8]
  %338 = and i8 %337, 1                           ; [#uses=1 type=i8]
  %339 = icmp eq i8 %338, 0                       ; [#uses=1 type=i1]
  br i1 %339, label %343, label %340

; <label>:340:                                    ; preds = %331
  %341 = getelementptr inbounds %"class.(anonymous namespace)::PrototypeAST", %"class.(anonymous namespace)::PrototypeAST"* %309, i32 0, i32 0, i32 0, i32 0, i32 0, i32 0, i32 0, i32 2 ; [#uses=1 type=i8**]
  %342 = load i8*, i8** %341, align 4, !tbaa !4, !noalias !20 ; [#uses=1 type=i8*]
  call void @_ZdlPv(i8* %342) #15, !noalias !20
  br label %343

; <label>:343:                                    ; preds = %340, %331
  call void @_ZdlPv(i8* %336) #15, !noalias !20
  call void @llvm.lifetime.end.p0i8(i64 4, i8* nonnull %87) #1, !noalias !20
  %344 = insertvalue { i8*, i32 } undef, i8* %332, 0 ; [#uses=1 type={ i8*, i32 }]
  %345 = insertvalue { i8*, i32 } %344, i32 %333, 1 ; [#uses=1 type={ i8*, i32 }]
  resume { i8*, i32 } %345

; <label>:346:                                    ; preds = %314
  call void @llvm.lifetime.end.p0i8(i64 4, i8* nonnull %95) #1, !noalias !20
  store %"class.(anonymous namespace)::PrototypeAST"* null, %"class.(anonymous namespace)::PrototypeAST"** %88, align 4, !tbaa !10, !noalias !20
  %347 = getelementptr inbounds %"class.(anonymous namespace)::PrototypeAST", %"class.(anonymous namespace)::PrototypeAST"* %309, i32 0, i32 1, i32 0 ; [#uses=1 type=%"class.std::__ccr1::__vector_base"*]
  %348 = call %"class.std::__ccr1::__vector_base"* @_ZNSt6__ccr113__vector_baseINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEENS4_IS6_EEED2Ev(%"class.std::__ccr1::__vector_base"* nonnull %347) #16, !noalias !20 ; [#uses=0 type=%"class.std::__ccr1::__vector_base"*]
  %349 = bitcast %"class.(anonymous namespace)::PrototypeAST"* %309 to i8* ; [#uses=2 type=i8*]
  %350 = load i8, i8* %349, align 4, !tbaa !4, !noalias !20 ; [#uses=1 type=i8]
  %351 = and i8 %350, 1                           ; [#uses=1 type=i8]
  %352 = icmp eq i8 %351, 0                       ; [#uses=1 type=i1]
  br i1 %352, label %356, label %353

; <label>:353:                                    ; preds = %346
  %354 = getelementptr inbounds %"class.(anonymous namespace)::PrototypeAST", %"class.(anonymous namespace)::PrototypeAST"* %309, i32 0, i32 0, i32 0, i32 0, i32 0, i32 0, i32 0, i32 2 ; [#uses=1 type=i8**]
  %355 = load i8*, i8** %354, align 4, !tbaa !4, !noalias !20 ; [#uses=1 type=i8*]
  call void @_ZdlPv(i8* %355) #15, !noalias !20
  br label %356

; <label>:356:                                    ; preds = %353, %346
  call void @_ZdlPv(i8* %349) #15, !noalias !20
  br label %381

; <label>:357:                                    ; preds = %317
  %358 = bitcast i8* %318 to i32*                 ; [#uses=1 type=i32*]
  store i32 %311, i32* %358, align 4, !tbaa !23, !noalias !25
  %359 = getelementptr inbounds i8, i8* %318, i32 4 ; [#uses=1 type=i8*]
  call void @llvm.lifetime.end.p0i8(i64 4, i8* nonnull %95) #1, !noalias !20
  call void @llvm.lifetime.end.p0i8(i64 4, i8* nonnull %87) #1, !noalias !20
  %360 = bitcast i8* %359 to %"class.(anonymous namespace)::ExprAST"** ; [#uses=1 type=%"class.(anonymous namespace)::ExprAST"**]
  store %"class.(anonymous namespace)::ExprAST"* null, %"class.(anonymous namespace)::ExprAST"** %360, align 4, !tbaa !10
  %361 = bitcast %"class.(anonymous namespace)::ExprAST"* %315 to void (%"class.(anonymous namespace)::ExprAST"*)*** ; [#uses=1 type=void (%"class.(anonymous namespace)::ExprAST"*)***]
  %362 = load void (%"class.(anonymous namespace)::ExprAST"*)**, void (%"class.(anonymous namespace)::ExprAST"*)*** %361, align 4, !tbaa !15 ; [#uses=1 type=void (%"class.(anonymous namespace)::ExprAST"*)**]
  %363 = getelementptr inbounds void (%"class.(anonymous namespace)::ExprAST"*)*, void (%"class.(anonymous namespace)::ExprAST"*)** %362, i32 1 ; [#uses=1 type=void (%"class.(anonymous namespace)::ExprAST"*)**]
  %364 = load void (%"class.(anonymous namespace)::ExprAST"*)*, void (%"class.(anonymous namespace)::ExprAST"*)** %363, align 4 ; [#uses=1 type=void (%"class.(anonymous namespace)::ExprAST"*)*]
  call void %364(%"class.(anonymous namespace)::ExprAST"* nonnull %315) #16
  %365 = bitcast i8* %318 to %"class.(anonymous namespace)::PrototypeAST"** ; [#uses=2 type=%"class.(anonymous namespace)::PrototypeAST"**]
  %366 = load %"class.(anonymous namespace)::PrototypeAST"*, %"class.(anonymous namespace)::PrototypeAST"** %365, align 4, !tbaa !10 ; [#uses=4 type=%"class.(anonymous namespace)::PrototypeAST"*]
  store %"class.(anonymous namespace)::PrototypeAST"* null, %"class.(anonymous namespace)::PrototypeAST"** %365, align 4, !tbaa !10
  %367 = icmp eq %"class.(anonymous namespace)::PrototypeAST"* %366, null ; [#uses=1 type=i1]
  br i1 %367, label %379, label %368

; <label>:368:                                    ; preds = %357
  %369 = getelementptr inbounds %"class.(anonymous namespace)::PrototypeAST", %"class.(anonymous namespace)::PrototypeAST"* %366, i32 0, i32 1, i32 0 ; [#uses=1 type=%"class.std::__ccr1::__vector_base"*]
  %370 = call %"class.std::__ccr1::__vector_base"* @_ZNSt6__ccr113__vector_baseINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEENS4_IS6_EEED2Ev(%"class.std::__ccr1::__vector_base"* nonnull %369) #16 ; [#uses=0 type=%"class.std::__ccr1::__vector_base"*]
  %371 = bitcast %"class.(anonymous namespace)::PrototypeAST"* %366 to i8* ; [#uses=2 type=i8*]
  %372 = load i8, i8* %371, align 4, !tbaa !4     ; [#uses=1 type=i8]
  %373 = and i8 %372, 1                           ; [#uses=1 type=i8]
  %374 = icmp eq i8 %373, 0                       ; [#uses=1 type=i1]
  br i1 %374, label %378, label %375

; <label>:375:                                    ; preds = %368
  %376 = getelementptr inbounds %"class.(anonymous namespace)::PrototypeAST", %"class.(anonymous namespace)::PrototypeAST"* %366, i32 0, i32 0, i32 0, i32 0, i32 0, i32 0, i32 0, i32 2 ; [#uses=1 type=i8**]
  %377 = load i8*, i8** %376, align 4, !tbaa !4   ; [#uses=1 type=i8*]
  call void @_ZdlPv(i8* %377) #15
  br label %378

; <label>:378:                                    ; preds = %375, %368
  call void @_ZdlPv(i8* %371) #15
  br label %379

; <label>:379:                                    ; preds = %378, %357
  call void @_ZdlPv(i8* nonnull %318) #15
  %380 = call dereferenceable(84) %"class.std::__ccr1::basic_ostream"* @_ZNSt6__ccr124__put_character_sequenceIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m(%"class.std::__ccr1::basic_ostream"* nonnull dereferenceable(84) @_ZNSt6__ccr14cerrE, i8* getelementptr inbounds ([31 x i8], [31 x i8]* @.str.14, i32 0, i32 0), i32 30) #17 ; [#uses=0 type=%"class.std::__ccr1::basic_ostream"*]
  br label %558

; <label>:381:                                    ; preds = %356, %312
  call void @llvm.lifetime.end.p0i8(i64 4, i8* nonnull %87) #1, !noalias !20
  %382 = call fastcc i32 @_ZL6gettokv() #17       ; [#uses=2 type=i32]
  store i32 %382, i32* @_ZL6CurTok, align 4, !tbaa !13
  br label %560

; <label>:383:                                    ; preds = %119
  call void @llvm.lifetime.start.p0i8(i64 4, i8* nonnull %81)
  %384 = load i8*, i8** bitcast (%"class.std::__ccr1::basic_ostream"* @_ZNSt6__ccr14cerrE to i8**), align 4, !tbaa !15 ; [#uses=1 type=i8*]
  %385 = getelementptr i8, i8* %384, i32 -12      ; [#uses=1 type=i8*]
  %386 = bitcast i8* %385 to i32*                 ; [#uses=1 type=i32*]
  %387 = load i32, i32* %386, align 4             ; [#uses=1 type=i32]
  %388 = getelementptr inbounds i8, i8* bitcast (%"class.std::__ccr1::basic_ostream"* @_ZNSt6__ccr14cerrE to i8*), i32 %387 ; [#uses=1 type=i8*]
  call void @llvm.lifetime.start.p0i8(i64 4, i8* nonnull %82) #1
  %389 = bitcast i8* %388 to %"class.std::__ccr1::ios_base"* ; [#uses=1 type=%"class.std::__ccr1::ios_base"*]
  call void @_ZNKSt6__ccr18ios_base6getlocEv(%"class.std::__ccr1::locale"* nonnull sret %6, %"class.std::__ccr1::ios_base"* %389) #17
  %390 = invoke %"class.std::__ccr1::locale::facet"* @_ZNKSt6__ccr16locale9use_facetERNS0_2idE(%"class.std::__ccr1::locale"* nonnull %6, %"class.std::__ccr1::locale::id"* nonnull dereferenceable(8) @_ZNSt6__ccr15ctypeIcE2idE) #17
          to label %391 unwind label %398         ; [#uses=2 type=%"class.std::__ccr1::locale::facet"*]

; <label>:391:                                    ; preds = %383
  %392 = bitcast %"class.std::__ccr1::locale::facet"* %390 to %"class.std::__ccr1::ctype"* ; [#uses=1 type=%"class.std::__ccr1::ctype"*]
  %393 = bitcast %"class.std::__ccr1::locale::facet"* %390 to i8 (%"class.std::__ccr1::ctype"*, i8)*** ; [#uses=1 type=i8 (%"class.std::__ccr1::ctype"*, i8)***]
  %394 = load i8 (%"class.std::__ccr1::ctype"*, i8)**, i8 (%"class.std::__ccr1::ctype"*, i8)*** %393, align 4, !tbaa !15 ; [#uses=1 type=i8 (%"class.std::__ccr1::ctype"*, i8)**]
  %395 = getelementptr inbounds i8 (%"class.std::__ccr1::ctype"*, i8)*, i8 (%"class.std::__ccr1::ctype"*, i8)** %394, i32 7 ; [#uses=1 type=i8 (%"class.std::__ccr1::ctype"*, i8)**]
  %396 = load i8 (%"class.std::__ccr1::ctype"*, i8)*, i8 (%"class.std::__ccr1::ctype"*, i8)** %395, align 4 ; [#uses=1 type=i8 (%"class.std::__ccr1::ctype"*, i8)*]
  %397 = invoke signext i8 %396(%"class.std::__ccr1::ctype"* %392, i8 signext 10) #17
          to label %401 unwind label %398         ; [#uses=1 type=i8]

; <label>:398:                                    ; preds = %391, %383
  %399 = landingpad { i8*, i32 }
          cleanup                                 ; [#uses=1 type={ i8*, i32 }]
  %400 = call %"class.std::__ccr1::locale"* @_ZNSt6__ccr16localeD1Ev(%"class.std::__ccr1::locale"* nonnull %6) #16 ; [#uses=0 type=%"class.std::__ccr1::locale"*]
  call void @llvm.lifetime.end.p0i8(i64 4, i8* nonnull %82) #1
  resume { i8*, i32 } %399

; <label>:401:                                    ; preds = %391
  %402 = call %"class.std::__ccr1::locale"* @_ZNSt6__ccr16localeD1Ev(%"class.std::__ccr1::locale"* nonnull %6) #16 ; [#uses=0 type=%"class.std::__ccr1::locale"*]
  call void @llvm.lifetime.end.p0i8(i64 4, i8* nonnull %82) #1
  %403 = call dereferenceable(84) %"class.std::__ccr1::basic_ostream"* @_ZNSt6__ccr113basic_ostreamIcNS_11char_traitsIcEEE3putEc(%"class.std::__ccr1::basic_ostream"* nonnull @_ZNSt6__ccr14cerrE, i8 signext %397) #17 ; [#uses=0 type=%"class.std::__ccr1::basic_ostream"*]
  %404 = call dereferenceable(84) %"class.std::__ccr1::basic_ostream"* @_ZNSt6__ccr113basic_ostreamIcNS_11char_traitsIcEEE5flushEv(%"class.std::__ccr1::basic_ostream"* nonnull @_ZNSt6__ccr14cerrE) #17 ; [#uses=0 type=%"class.std::__ccr1::basic_ostream"*]
  %405 = load %struct.__sFILE*, %struct.__sFILE** @__stderrp, align 4, !tbaa !10 ; [#uses=1 type=%struct.__sFILE*]
  %406 = call i32 (%struct.__sFILE*, i8*, ...) @fprintf(%struct.__sFILE* %405, i8* getelementptr inbounds ([34 x i8], [34 x i8]* @.str.3, i32 0, i32 0), i8* getelementptr inbounds ([13 x i8], [13 x i8]* @__func__._ZL12HandleExternv, i32 0, i32 0), i32 843, i8* getelementptr inbounds ([148 x i8], [148 x i8]* @.str.4, i32 0, i32 0)) #17 ; [#uses=0 type=i32]
  %407 = load %struct.__sFILE*, %struct.__sFILE** @__stderrp, align 4, !tbaa !10, !noalias !28 ; [#uses=1 type=%struct.__sFILE*]
  %408 = call i32 (%struct.__sFILE*, i8*, ...) @fprintf(%struct.__sFILE* %407, i8* getelementptr inbounds ([34 x i8], [34 x i8]* @.str.3, i32 0, i32 0), i8* getelementptr inbounds ([12 x i8], [12 x i8]* @__func__._ZL11ParseExternv, i32 0, i32 0), i32 794, i8* getelementptr inbounds ([148 x i8], [148 x i8]* @.str.4, i32 0, i32 0)) #17, !noalias !28 ; [#uses=0 type=i32]
  %409 = call fastcc i32 @_ZL6gettokv() #17, !noalias !28 ; [#uses=1 type=i32]
  store i32 %409, i32* @_ZL6CurTok, align 4, !tbaa !13, !noalias !28
  call fastcc void @_ZL14ParsePrototypev(%"class.std::__ccr1::unique_ptr.13"* nonnull sret %7) #17
  %410 = load %"class.(anonymous namespace)::PrototypeAST"*, %"class.(anonymous namespace)::PrototypeAST"** %89, align 4, !tbaa !10 ; [#uses=4 type=%"class.(anonymous namespace)::PrototypeAST"*]
  %411 = icmp eq %"class.(anonymous namespace)::PrototypeAST"* %410, null ; [#uses=1 type=i1]
  store %"class.(anonymous namespace)::PrototypeAST"* null, %"class.(anonymous namespace)::PrototypeAST"** %89, align 4, !tbaa !10
  br i1 %411, label %424, label %412

; <label>:412:                                    ; preds = %401
  %413 = getelementptr inbounds %"class.(anonymous namespace)::PrototypeAST", %"class.(anonymous namespace)::PrototypeAST"* %410, i32 0, i32 1, i32 0 ; [#uses=1 type=%"class.std::__ccr1::__vector_base"*]
  %414 = call %"class.std::__ccr1::__vector_base"* @_ZNSt6__ccr113__vector_baseINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEENS4_IS6_EEED2Ev(%"class.std::__ccr1::__vector_base"* nonnull %413) #16 ; [#uses=0 type=%"class.std::__ccr1::__vector_base"*]
  %415 = bitcast %"class.(anonymous namespace)::PrototypeAST"* %410 to i8* ; [#uses=2 type=i8*]
  %416 = load i8, i8* %415, align 4, !tbaa !4     ; [#uses=1 type=i8]
  %417 = and i8 %416, 1                           ; [#uses=1 type=i8]
  %418 = icmp eq i8 %417, 0                       ; [#uses=1 type=i1]
  br i1 %418, label %422, label %419

; <label>:419:                                    ; preds = %412
  %420 = getelementptr inbounds %"class.(anonymous namespace)::PrototypeAST", %"class.(anonymous namespace)::PrototypeAST"* %410, i32 0, i32 0, i32 0, i32 0, i32 0, i32 0, i32 0, i32 2 ; [#uses=1 type=i8**]
  %421 = load i8*, i8** %420, align 4, !tbaa !4   ; [#uses=1 type=i8*]
  call void @_ZdlPv(i8* %421) #15
  br label %422

; <label>:422:                                    ; preds = %419, %412
  call void @_ZdlPv(i8* %415) #15
  %423 = call dereferenceable(84) %"class.std::__ccr1::basic_ostream"* @_ZNSt6__ccr124__put_character_sequenceIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m(%"class.std::__ccr1::basic_ostream"* nonnull dereferenceable(84) @_ZNSt6__ccr14cerrE, i8* getelementptr inbounds ([18 x i8], [18 x i8]* @.str.25, i32 0, i32 0), i32 17) #17 ; [#uses=0 type=%"class.std::__ccr1::basic_ostream"*]
  br label %426

; <label>:424:                                    ; preds = %401
  %425 = call fastcc i32 @_ZL6gettokv() #17       ; [#uses=1 type=i32]
  store i32 %425, i32* @_ZL6CurTok, align 4, !tbaa !13
  br label %426

; <label>:426:                                    ; preds = %424, %422
  call void @llvm.lifetime.end.p0i8(i64 4, i8* nonnull %81)
  br label %558

; <label>:427:                                    ; preds = %119
  %428 = load i8*, i8** bitcast (%"class.std::__ccr1::basic_ostream"* @_ZNSt6__ccr14cerrE to i8**), align 4, !tbaa !15 ; [#uses=1 type=i8*]
  %429 = getelementptr i8, i8* %428, i32 -12      ; [#uses=1 type=i8*]
  %430 = bitcast i8* %429 to i32*                 ; [#uses=1 type=i32*]
  %431 = load i32, i32* %430, align 4             ; [#uses=1 type=i32]
  %432 = getelementptr inbounds i8, i8* bitcast (%"class.std::__ccr1::basic_ostream"* @_ZNSt6__ccr14cerrE to i8*), i32 %431 ; [#uses=1 type=i8*]
  call void @llvm.lifetime.start.p0i8(i64 4, i8* nonnull %78) #1
  %433 = bitcast i8* %432 to %"class.std::__ccr1::ios_base"* ; [#uses=1 type=%"class.std::__ccr1::ios_base"*]
  call void @_ZNKSt6__ccr18ios_base6getlocEv(%"class.std::__ccr1::locale"* nonnull sret %1, %"class.std::__ccr1::ios_base"* %433) #17
  %434 = invoke %"class.std::__ccr1::locale::facet"* @_ZNKSt6__ccr16locale9use_facetERNS0_2idE(%"class.std::__ccr1::locale"* nonnull %1, %"class.std::__ccr1::locale::id"* nonnull dereferenceable(8) @_ZNSt6__ccr15ctypeIcE2idE) #17
          to label %435 unwind label %442         ; [#uses=2 type=%"class.std::__ccr1::locale::facet"*]

; <label>:435:                                    ; preds = %427
  %436 = bitcast %"class.std::__ccr1::locale::facet"* %434 to %"class.std::__ccr1::ctype"* ; [#uses=1 type=%"class.std::__ccr1::ctype"*]
  %437 = bitcast %"class.std::__ccr1::locale::facet"* %434 to i8 (%"class.std::__ccr1::ctype"*, i8)*** ; [#uses=1 type=i8 (%"class.std::__ccr1::ctype"*, i8)***]
  %438 = load i8 (%"class.std::__ccr1::ctype"*, i8)**, i8 (%"class.std::__ccr1::ctype"*, i8)*** %437, align 4, !tbaa !15 ; [#uses=1 type=i8 (%"class.std::__ccr1::ctype"*, i8)**]
  %439 = getelementptr inbounds i8 (%"class.std::__ccr1::ctype"*, i8)*, i8 (%"class.std::__ccr1::ctype"*, i8)** %438, i32 7 ; [#uses=1 type=i8 (%"class.std::__ccr1::ctype"*, i8)**]
  %440 = load i8 (%"class.std::__ccr1::ctype"*, i8)*, i8 (%"class.std::__ccr1::ctype"*, i8)** %439, align 4 ; [#uses=1 type=i8 (%"class.std::__ccr1::ctype"*, i8)*]
  %441 = invoke signext i8 %440(%"class.std::__ccr1::ctype"* %436, i8 signext 10) #17
          to label %445 unwind label %442         ; [#uses=1 type=i8]

; <label>:442:                                    ; preds = %435, %427
  %443 = landingpad { i8*, i32 }
          cleanup                                 ; [#uses=1 type={ i8*, i32 }]
  %444 = call %"class.std::__ccr1::locale"* @_ZNSt6__ccr16localeD1Ev(%"class.std::__ccr1::locale"* nonnull %1) #16 ; [#uses=0 type=%"class.std::__ccr1::locale"*]
  call void @llvm.lifetime.end.p0i8(i64 4, i8* nonnull %78) #1
  resume { i8*, i32 } %443

; <label>:445:                                    ; preds = %435
  %446 = call %"class.std::__ccr1::locale"* @_ZNSt6__ccr16localeD1Ev(%"class.std::__ccr1::locale"* nonnull %1) #16 ; [#uses=0 type=%"class.std::__ccr1::locale"*]
  call void @llvm.lifetime.end.p0i8(i64 4, i8* nonnull %78) #1
  %447 = call dereferenceable(84) %"class.std::__ccr1::basic_ostream"* @_ZNSt6__ccr113basic_ostreamIcNS_11char_traitsIcEEE3putEc(%"class.std::__ccr1::basic_ostream"* nonnull @_ZNSt6__ccr14cerrE, i8 signext %441) #17 ; [#uses=0 type=%"class.std::__ccr1::basic_ostream"*]
  %448 = call dereferenceable(84) %"class.std::__ccr1::basic_ostream"* @_ZNSt6__ccr113basic_ostreamIcNS_11char_traitsIcEEE5flushEv(%"class.std::__ccr1::basic_ostream"* nonnull @_ZNSt6__ccr14cerrE) #17 ; [#uses=0 type=%"class.std::__ccr1::basic_ostream"*]
  %449 = load %struct.__sFILE*, %struct.__sFILE** @__stderrp, align 4, !tbaa !10 ; [#uses=1 type=%struct.__sFILE*]
  %450 = call i32 (%struct.__sFILE*, i8*, ...) @fprintf(%struct.__sFILE* %449, i8* getelementptr inbounds ([34 x i8], [34 x i8]* @.str.3, i32 0, i32 0), i8* getelementptr inbounds ([25 x i8], [25 x i8]* @__func__._ZL24HandleTopLevelExpressionv, i32 0, i32 0), i32 854, i8* getelementptr inbounds ([148 x i8], [148 x i8]* @.str.4, i32 0, i32 0)) #17 ; [#uses=0 type=i32]
  %451 = load %struct.__sFILE*, %struct.__sFILE** @__stderrp, align 4, !tbaa !10, !noalias !31 ; [#uses=1 type=%struct.__sFILE*]
  %452 = call i32 (%struct.__sFILE*, i8*, ...) @fprintf(%struct.__sFILE* %451, i8* getelementptr inbounds ([34 x i8], [34 x i8]* @.str.3, i32 0, i32 0), i8* getelementptr inbounds ([18 x i8], [18 x i8]* @__func__._ZL17ParseTopLevelExprv, i32 0, i32 0), i32 803, i8* getelementptr inbounds ([148 x i8], [148 x i8]* @.str.4, i32 0, i32 0)) #17, !noalias !31 ; [#uses=0 type=i32]
  call void @llvm.lifetime.start.p0i8(i64 4, i8* nonnull %83) #1, !noalias !31
  call fastcc void @_ZL15ParseExpressionv(%"class.std::__ccr1::unique_ptr.22"* nonnull sret %4) #17, !noalias !31
  %453 = load %"class.(anonymous namespace)::ExprAST"*, %"class.(anonymous namespace)::ExprAST"** %84, align 4, !tbaa !10, !noalias !31 ; [#uses=5 type=%"class.(anonymous namespace)::ExprAST"*]
  %454 = icmp eq %"class.(anonymous namespace)::ExprAST"* %453, null ; [#uses=1 type=i1]
  br i1 %454, label %556, label %455

; <label>:455:                                    ; preds = %445
  call void @llvm.lifetime.start.p0i8(i64 12, i8* nonnull %90) #1, !noalias !31
  store %"class.std::__ccr1::basic_string"* null, %"class.std::__ccr1::basic_string"** %91, align 4, !tbaa !34, !noalias !31
  store %"class.std::__ccr1::basic_string"* null, %"class.std::__ccr1::basic_string"** %92, align 4, !tbaa !37, !noalias !31
  store %"class.std::__ccr1::basic_string"* null, %"class.std::__ccr1::basic_string"** %93, align 4, !tbaa !38, !noalias !31
  call void @llvm.lifetime.start.p0i8(i64 12, i8* nonnull %94), !noalias !31
  %456 = invoke i8* @_Znwm(i32 24) #18
          to label %457 unwind label %502, !noalias !31 ; [#uses=9 type=i8*]

; <label>:457:                                    ; preds = %455
  call void @llvm.lifetime.start.p0i8(i64 12, i8* nonnull %96) #1, !noalias !40
  call void @llvm.memset.p0i8.i32(i8* nonnull %96, i8 0, i32 12, i32 4, i1 false) #1, !noalias !40
  %458 = invoke i8* @_Znwm(i32 16) #18
          to label %459 unwind label %480, !noalias !40 ; [#uses=3 type=i8*]

; <label>:459:                                    ; preds = %457
  store i8* %458, i8** %98, align 4, !tbaa !4, !noalias !40
  store i32 17, i32* %99, align 4, !tbaa !4, !noalias !40
  store i32 11, i32* %100, align 4, !tbaa !4, !noalias !40
  call void @llvm.memcpy.p0i8.p0i8.i32(i8* nonnull %458, i8* getelementptr inbounds ([12 x i8], [12 x i8]* @.str.27, i32 0, i32 0), i32 11, i32 1, i1 false) #1, !noalias !40
  %460 = getelementptr inbounds i8, i8* %458, i32 11 ; [#uses=1 type=i8*]
  store i8 0, i8* %460, align 1, !tbaa !4, !noalias !40
  store i32 0, i32* %103, align 4, !tbaa !34, !noalias !40
  store i32 0, i32* %104, align 4, !tbaa !37, !noalias !40
  store i32 0, i32* %105, align 4, !tbaa !10, !noalias !40
  store %"class.std::__ccr1::basic_string"* null, %"class.std::__ccr1::basic_string"** %93, align 4, !tbaa !10, !noalias !40
  store %"class.std::__ccr1::basic_string"* null, %"class.std::__ccr1::basic_string"** %92, align 4, !tbaa !37, !noalias !40
  store %"class.std::__ccr1::basic_string"* null, %"class.std::__ccr1::basic_string"** %91, align 4, !tbaa !34, !noalias !40
  %461 = bitcast i8* %456 to %"class.std::__ccr1::basic_string"* ; [#uses=1 type=%"class.std::__ccr1::basic_string"*]
  %462 = invoke %"class.std::__ccr1::basic_string"* @_ZNSt6__ccr112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEC1ERKS5_(%"class.std::__ccr1::basic_string"* nonnull %461, %"class.std::__ccr1::basic_string"* nonnull dereferenceable(12) %2) #17
          to label %463 unwind label %484, !noalias !40 ; [#uses=0 type=%"class.std::__ccr1::basic_string"*]

; <label>:463:                                    ; preds = %459
  %464 = getelementptr inbounds i8, i8* %456, i32 12 ; [#uses=2 type=i8*]
  %465 = getelementptr inbounds i8, i8* %456, i32 16 ; [#uses=1 type=i8*]
  %466 = getelementptr inbounds i8, i8* %456, i32 20 ; [#uses=1 type=i8*]
  %467 = load i32, i32* %103, align 4, !tbaa !34, !noalias !40 ; [#uses=1 type=i32]
  %468 = bitcast i8* %464 to i32*                 ; [#uses=1 type=i32*]
  store i32 %467, i32* %468, align 4, !tbaa !34, !noalias !40
  %469 = load i32, i32* %104, align 4, !tbaa !37, !noalias !40 ; [#uses=1 type=i32]
  %470 = bitcast i8* %465 to i32*                 ; [#uses=1 type=i32*]
  store i32 %469, i32* %470, align 4, !tbaa !37, !noalias !40
  %471 = load i32, i32* %105, align 4, !tbaa !10, !noalias !40 ; [#uses=1 type=i32]
  %472 = bitcast i8* %466 to i32*                 ; [#uses=1 type=i32*]
  store i32 %471, i32* %472, align 4, !tbaa !10, !noalias !40
  store %"class.std::__ccr1::basic_string"* null, %"class.std::__ccr1::basic_string"** %102, align 4, !tbaa !10, !noalias !40
  store %"class.std::__ccr1::basic_string"* null, %"class.std::__ccr1::basic_string"** %101, align 4, !tbaa !37, !noalias !40
  store %"class.std::__ccr1::basic_string"* null, %"class.std::__ccr1::basic_string"** %106, align 4, !tbaa !34, !noalias !40
  %473 = ptrtoint i8* %456 to i32                 ; [#uses=1 type=i32]
  %474 = call %"class.std::__ccr1::__vector_base"* @_ZNSt6__ccr113__vector_baseINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEENS4_IS6_EEED2Ev(%"class.std::__ccr1::__vector_base"* nonnull %107) #16, !noalias !40 ; [#uses=0 type=%"class.std::__ccr1::__vector_base"*]
  %475 = load i8, i8* %96, align 4, !tbaa !4, !noalias !40 ; [#uses=1 type=i8]
  %476 = and i8 %475, 1                           ; [#uses=1 type=i8]
  %477 = icmp eq i8 %476, 0                       ; [#uses=1 type=i1]
  br i1 %477, label %499, label %478

; <label>:478:                                    ; preds = %463
  %479 = load i8*, i8** %98, align 4, !tbaa !4, !noalias !40 ; [#uses=1 type=i8*]
  call void @_ZdlPv(i8* %479) #15, !noalias !40
  br label %499

; <label>:480:                                    ; preds = %457
  %481 = landingpad { i8*, i32 }
          cleanup                                 ; [#uses=2 type={ i8*, i32 }]
  %482 = extractvalue { i8*, i32 } %481, 0        ; [#uses=1 type=i8*]
  %483 = extractvalue { i8*, i32 } %481, 1        ; [#uses=1 type=i32]
  br label %494

; <label>:484:                                    ; preds = %459
  %485 = landingpad { i8*, i32 }
          cleanup                                 ; [#uses=2 type={ i8*, i32 }]
  %486 = extractvalue { i8*, i32 } %485, 0        ; [#uses=2 type=i8*]
  %487 = extractvalue { i8*, i32 } %485, 1        ; [#uses=2 type=i32]
  %488 = call %"class.std::__ccr1::__vector_base"* @_ZNSt6__ccr113__vector_baseINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEENS4_IS6_EEED2Ev(%"class.std::__ccr1::__vector_base"* nonnull %107) #16, !noalias !40 ; [#uses=0 type=%"class.std::__ccr1::__vector_base"*]
  %489 = load i8, i8* %96, align 4, !tbaa !4, !noalias !40 ; [#uses=1 type=i8]
  %490 = and i8 %489, 1                           ; [#uses=1 type=i8]
  %491 = icmp eq i8 %490, 0                       ; [#uses=1 type=i1]
  br i1 %491, label %494, label %492

; <label>:492:                                    ; preds = %484
  %493 = load i8*, i8** %98, align 4, !tbaa !4, !noalias !40 ; [#uses=1 type=i8*]
  call void @_ZdlPv(i8* %493) #15, !noalias !40
  br label %494

; <label>:494:                                    ; preds = %492, %484, %480
  %495 = phi i8* [ %482, %480 ], [ %486, %484 ], [ %486, %492 ] ; [#uses=1 type=i8*]
  %496 = phi i32 [ %483, %480 ], [ %487, %484 ], [ %487, %492 ] ; [#uses=1 type=i32]
  call void @llvm.lifetime.end.p0i8(i64 12, i8* nonnull %96) #1, !noalias !40
  call void @_ZdlPv(i8* nonnull %456) #15, !noalias !40
  %497 = insertvalue { i8*, i32 } undef, i8* %495, 0 ; [#uses=1 type={ i8*, i32 }]
  %498 = insertvalue { i8*, i32 } %497, i32 %496, 1 ; [#uses=1 type={ i8*, i32 }]
  br label %504

; <label>:499:                                    ; preds = %478, %463
  call void @llvm.lifetime.end.p0i8(i64 12, i8* nonnull %96) #1, !noalias !40
  call void @llvm.lifetime.end.p0i8(i64 12, i8* nonnull %94), !noalias !31
  %500 = call %"class.std::__ccr1::__vector_base"* @_ZNSt6__ccr113__vector_baseINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEENS4_IS6_EEED2Ev(%"class.std::__ccr1::__vector_base"* nonnull %108) #16, !noalias !31 ; [#uses=0 type=%"class.std::__ccr1::__vector_base"*]
  call void @llvm.lifetime.end.p0i8(i64 12, i8* nonnull %90) #1, !noalias !31
  %501 = invoke i8* @_Znwm(i32 8) #18
          to label %532 unwind label %509, !noalias !31 ; [#uses=4 type=i8*]

; <label>:502:                                    ; preds = %455
  %503 = landingpad { i8*, i32 }
          cleanup                                 ; [#uses=1 type={ i8*, i32 }]
  br label %504

; <label>:504:                                    ; preds = %502, %494
  %505 = phi { i8*, i32 } [ %503, %502 ], [ %498, %494 ] ; [#uses=2 type={ i8*, i32 }]
  %506 = extractvalue { i8*, i32 } %505, 0        ; [#uses=1 type=i8*]
  %507 = extractvalue { i8*, i32 } %505, 1        ; [#uses=1 type=i32]
  %508 = call %"class.std::__ccr1::__vector_base"* @_ZNSt6__ccr113__vector_baseINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEENS4_IS6_EEED2Ev(%"class.std::__ccr1::__vector_base"* nonnull %108) #16, !noalias !31 ; [#uses=0 type=%"class.std::__ccr1::__vector_base"*]
  call void @llvm.lifetime.end.p0i8(i64 12, i8* nonnull %90) #1, !noalias !31
  br label %523

; <label>:509:                                    ; preds = %499
  %510 = landingpad { i8*, i32 }
          cleanup                                 ; [#uses=2 type={ i8*, i32 }]
  %511 = extractvalue { i8*, i32 } %510, 0        ; [#uses=1 type=i8*]
  %512 = extractvalue { i8*, i32 } %510, 1        ; [#uses=1 type=i32]
  %513 = bitcast i8* %464 to %"class.std::__ccr1::__vector_base"* ; [#uses=1 type=%"class.std::__ccr1::__vector_base"*]
  %514 = call %"class.std::__ccr1::__vector_base"* @_ZNSt6__ccr113__vector_baseINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEENS4_IS6_EEED2Ev(%"class.std::__ccr1::__vector_base"* nonnull %513) #16, !noalias !31 ; [#uses=0 type=%"class.std::__ccr1::__vector_base"*]
  %515 = load i8, i8* %456, align 4, !tbaa !4, !noalias !31 ; [#uses=1 type=i8]
  %516 = and i8 %515, 1                           ; [#uses=1 type=i8]
  %517 = icmp eq i8 %516, 0                       ; [#uses=1 type=i1]
  br i1 %517, label %522, label %518

; <label>:518:                                    ; preds = %509
  %519 = getelementptr inbounds i8, i8* %456, i32 8 ; [#uses=1 type=i8*]
  %520 = bitcast i8* %519 to i8**                 ; [#uses=1 type=i8**]
  %521 = load i8*, i8** %520, align 4, !tbaa !4, !noalias !31 ; [#uses=1 type=i8*]
  call void @_ZdlPv(i8* %521) #15, !noalias !31
  br label %522

; <label>:522:                                    ; preds = %518, %509
  call void @_ZdlPv(i8* nonnull %456) #15, !noalias !31
  br label %523

; <label>:523:                                    ; preds = %522, %504
  %524 = phi i8* [ %506, %504 ], [ %511, %522 ]   ; [#uses=1 type=i8*]
  %525 = phi i32 [ %507, %504 ], [ %512, %522 ]   ; [#uses=1 type=i32]
  %526 = bitcast %"class.(anonymous namespace)::ExprAST"* %453 to void (%"class.(anonymous namespace)::ExprAST"*)*** ; [#uses=1 type=void (%"class.(anonymous namespace)::ExprAST"*)***]
  %527 = load void (%"class.(anonymous namespace)::ExprAST"*)**, void (%"class.(anonymous namespace)::ExprAST"*)*** %526, align 4, !tbaa !15, !noalias !31 ; [#uses=1 type=void (%"class.(anonymous namespace)::ExprAST"*)**]
  %528 = getelementptr inbounds void (%"class.(anonymous namespace)::ExprAST"*)*, void (%"class.(anonymous namespace)::ExprAST"*)** %527, i32 1 ; [#uses=1 type=void (%"class.(anonymous namespace)::ExprAST"*)**]
  %529 = load void (%"class.(anonymous namespace)::ExprAST"*)*, void (%"class.(anonymous namespace)::ExprAST"*)** %528, align 4, !noalias !31 ; [#uses=1 type=void (%"class.(anonymous namespace)::ExprAST"*)*]
  call void %529(%"class.(anonymous namespace)::ExprAST"* nonnull %453) #16, !noalias !31
  call void @llvm.lifetime.end.p0i8(i64 4, i8* nonnull %83) #1, !noalias !31
  %530 = insertvalue { i8*, i32 } undef, i8* %524, 0 ; [#uses=1 type={ i8*, i32 }]
  %531 = insertvalue { i8*, i32 } %530, i32 %525, 1 ; [#uses=1 type={ i8*, i32 }]
  resume { i8*, i32 } %531

; <label>:532:                                    ; preds = %499
  %533 = bitcast i8* %501 to i32*                 ; [#uses=1 type=i32*]
  store i32 %473, i32* %533, align 4, !tbaa !23, !noalias !43
  %534 = getelementptr inbounds i8, i8* %501, i32 4 ; [#uses=1 type=i8*]
  call void @llvm.lifetime.end.p0i8(i64 4, i8* nonnull %83) #1, !noalias !31
  %535 = bitcast i8* %534 to %"class.(anonymous namespace)::ExprAST"** ; [#uses=1 type=%"class.(anonymous namespace)::ExprAST"**]
  store %"class.(anonymous namespace)::ExprAST"* null, %"class.(anonymous namespace)::ExprAST"** %535, align 4, !tbaa !10
  %536 = bitcast %"class.(anonymous namespace)::ExprAST"* %453 to void (%"class.(anonymous namespace)::ExprAST"*)*** ; [#uses=1 type=void (%"class.(anonymous namespace)::ExprAST"*)***]
  %537 = load void (%"class.(anonymous namespace)::ExprAST"*)**, void (%"class.(anonymous namespace)::ExprAST"*)*** %536, align 4, !tbaa !15 ; [#uses=1 type=void (%"class.(anonymous namespace)::ExprAST"*)**]
  %538 = getelementptr inbounds void (%"class.(anonymous namespace)::ExprAST"*)*, void (%"class.(anonymous namespace)::ExprAST"*)** %537, i32 1 ; [#uses=1 type=void (%"class.(anonymous namespace)::ExprAST"*)**]
  %539 = load void (%"class.(anonymous namespace)::ExprAST"*)*, void (%"class.(anonymous namespace)::ExprAST"*)** %538, align 4 ; [#uses=1 type=void (%"class.(anonymous namespace)::ExprAST"*)*]
  call void %539(%"class.(anonymous namespace)::ExprAST"* nonnull %453) #16
  %540 = bitcast i8* %501 to %"class.(anonymous namespace)::PrototypeAST"** ; [#uses=2 type=%"class.(anonymous namespace)::PrototypeAST"**]
  %541 = load %"class.(anonymous namespace)::PrototypeAST"*, %"class.(anonymous namespace)::PrototypeAST"** %540, align 4, !tbaa !10 ; [#uses=4 type=%"class.(anonymous namespace)::PrototypeAST"*]
  store %"class.(anonymous namespace)::PrototypeAST"* null, %"class.(anonymous namespace)::PrototypeAST"** %540, align 4, !tbaa !10
  %542 = icmp eq %"class.(anonymous namespace)::PrototypeAST"* %541, null ; [#uses=1 type=i1]
  br i1 %542, label %554, label %543

; <label>:543:                                    ; preds = %532
  %544 = getelementptr inbounds %"class.(anonymous namespace)::PrototypeAST", %"class.(anonymous namespace)::PrototypeAST"* %541, i32 0, i32 1, i32 0 ; [#uses=1 type=%"class.std::__ccr1::__vector_base"*]
  %545 = call %"class.std::__ccr1::__vector_base"* @_ZNSt6__ccr113__vector_baseINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEENS4_IS6_EEED2Ev(%"class.std::__ccr1::__vector_base"* nonnull %544) #16 ; [#uses=0 type=%"class.std::__ccr1::__vector_base"*]
  %546 = bitcast %"class.(anonymous namespace)::PrototypeAST"* %541 to i8* ; [#uses=2 type=i8*]
  %547 = load i8, i8* %546, align 4, !tbaa !4     ; [#uses=1 type=i8]
  %548 = and i8 %547, 1                           ; [#uses=1 type=i8]
  %549 = icmp eq i8 %548, 0                       ; [#uses=1 type=i1]
  br i1 %549, label %553, label %550

; <label>:550:                                    ; preds = %543
  %551 = getelementptr inbounds %"class.(anonymous namespace)::PrototypeAST", %"class.(anonymous namespace)::PrototypeAST"* %541, i32 0, i32 0, i32 0, i32 0, i32 0, i32 0, i32 0, i32 2 ; [#uses=1 type=i8**]
  %552 = load i8*, i8** %551, align 4, !tbaa !4   ; [#uses=1 type=i8*]
  call void @_ZdlPv(i8* %552) #15
  br label %553

; <label>:553:                                    ; preds = %550, %543
  call void @_ZdlPv(i8* %546) #15
  br label %554

; <label>:554:                                    ; preds = %553, %532
  call void @_ZdlPv(i8* nonnull %501) #15
  %555 = call dereferenceable(84) %"class.std::__ccr1::basic_ostream"* @_ZNSt6__ccr124__put_character_sequenceIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m(%"class.std::__ccr1::basic_ostream"* nonnull dereferenceable(84) @_ZNSt6__ccr14cerrE, i8* getelementptr inbounds ([25 x i8], [25 x i8]* @.str.26, i32 0, i32 0), i32 24) #17 ; [#uses=0 type=%"class.std::__ccr1::basic_ostream"*]
  br label %558

; <label>:556:                                    ; preds = %445
  call void @llvm.lifetime.end.p0i8(i64 4, i8* nonnull %83) #1, !noalias !31
  %557 = call fastcc i32 @_ZL6gettokv() #17       ; [#uses=2 type=i32]
  store i32 %557, i32* @_ZL6CurTok, align 4, !tbaa !13
  br label %560

; <label>:558:                                    ; preds = %554, %426, %379
  %559 = load i32, i32* @_ZL6CurTok, align 4, !tbaa !13 ; [#uses=1 type=i32]
  br label %560

; <label>:560:                                    ; preds = %558, %556, %381, %280, %131
  %561 = phi i32 [ %559, %558 ], [ %557, %556 ], [ %382, %381 ], [ %281, %280 ], [ %132, %131 ] ; [#uses=1 type=i32]
  %562 = icmp eq i32 %561, -1                     ; [#uses=1 type=i1]
  br i1 %562, label %563, label %119

; <label>:563:                                    ; preds = %560, %0
  ret i32 0
}

; [#uses=23]
; Function Attrs: nounwind optsize
declare i32 @fprintf(%struct.__sFILE* nocapture, i8* nocapture readonly, ...) local_unnamed_addr #3

; [#uses=59]
; Function Attrs: argmemonly nounwind
declare void @llvm.lifetime.start.p0i8(i64, i8* nocapture) #4

; [#uses=100]
; Function Attrs: argmemonly nounwind
declare void @llvm.lifetime.end.p0i8(i64, i8* nocapture) #4

; [#uses=3]
; Function Attrs: nounwind optsize
define linkonce_odr void @_ZNSt6__ccr16__treeINS_12__value_typeIciEENS_19__map_value_compareIcS2_NS_4lessIcEELb1EEENS_9allocatorIS2_EEE7destroyEPNS_11__tree_nodeIS2_PvEE(%"class.std::__ccr1::__tree"*, %"class.std::__ccr1::__tree_node"*) local_unnamed_addr #0 align 2 personality i8* bitcast (i32 (...)* @__gxx_personality_sj0 to i8*) {
  %3 = icmp eq %"class.std::__ccr1::__tree_node"* %1, null ; [#uses=1 type=i1]
  br i1 %3, label %11, label %4

; <label>:4:                                      ; preds = %2
  %5 = bitcast %"class.std::__ccr1::__tree_node"* %1 to %"class.std::__ccr1::__tree_node"** ; [#uses=1 type=%"class.std::__ccr1::__tree_node"**]
  %6 = load %"class.std::__ccr1::__tree_node"*, %"class.std::__ccr1::__tree_node"** %5, align 4, !tbaa !7 ; [#uses=1 type=%"class.std::__ccr1::__tree_node"*]
  tail call void @_ZNSt6__ccr16__treeINS_12__value_typeIciEENS_19__map_value_compareIcS2_NS_4lessIcEELb1EEENS_9allocatorIS2_EEE7destroyEPNS_11__tree_nodeIS2_PvEE(%"class.std::__ccr1::__tree"* %0, %"class.std::__ccr1::__tree_node"* %6) #16
  %7 = getelementptr inbounds %"class.std::__ccr1::__tree_node", %"class.std::__ccr1::__tree_node"* %1, i32 0, i32 0, i32 1 ; [#uses=1 type=%"class.std::__ccr1::__tree_node_base"**]
  %8 = bitcast %"class.std::__ccr1::__tree_node_base"** %7 to %"class.std::__ccr1::__tree_node"** ; [#uses=1 type=%"class.std::__ccr1::__tree_node"**]
  %9 = load %"class.std::__ccr1::__tree_node"*, %"class.std::__ccr1::__tree_node"** %8, align 4, !tbaa !46 ; [#uses=1 type=%"class.std::__ccr1::__tree_node"*]
  tail call void @_ZNSt6__ccr16__treeINS_12__value_typeIciEENS_19__map_value_compareIcS2_NS_4lessIcEELb1EEENS_9allocatorIS2_EEE7destroyEPNS_11__tree_nodeIS2_PvEE(%"class.std::__ccr1::__tree"* %0, %"class.std::__ccr1::__tree_node"* %9) #16
  %10 = bitcast %"class.std::__ccr1::__tree_node"* %1 to i8* ; [#uses=1 type=i8*]
  tail call void @_ZdlPv(i8* %10) #15
  ret void

; <label>:11:                                     ; preds = %2
  ret void
}

; [#uses=14]
declare i32 @__gxx_personality_sj0(...)

; [#uses=8]
; Function Attrs: noinline noreturn nounwind
define linkonce_odr hidden void @__clang_call_terminate(i8*) local_unnamed_addr #5 {
  %2 = tail call i8* @__cxa_begin_catch(i8* %0) #1 ; [#uses=0 type=i8*]
  tail call void @_ZSt9terminatev() #19
  unreachable
}

; [#uses=5]
declare i8* @__cxa_begin_catch(i8*) local_unnamed_addr

; [#uses=1]
declare void @_ZSt9terminatev() local_unnamed_addr

; [#uses=51]
; Function Attrs: nobuiltin nounwind optsize
declare void @_ZdlPv(i8*) local_unnamed_addr #6

; [#uses=20]
; Function Attrs: optsize
define internal fastcc i32 @_ZL6gettokv() unnamed_addr #7 personality i8* bitcast (i32 (...)* @__gxx_personality_sj0 to i8*) {
  %1 = alloca %"class.std::__ccr1::locale", align 4 ; [#uses=5 type=%"class.std::__ccr1::locale"*]
  %2 = alloca %"class.std::__ccr1::locale", align 4 ; [#uses=5 type=%"class.std::__ccr1::locale"*]
  %3 = alloca %"class.std::__ccr1::locale", align 4 ; [#uses=5 type=%"class.std::__ccr1::locale"*]
  %4 = alloca %"class.std::__ccr1::locale", align 4 ; [#uses=5 type=%"class.std::__ccr1::locale"*]
  %5 = alloca %"class.std::__ccr1::locale", align 4 ; [#uses=5 type=%"class.std::__ccr1::locale"*]
  %6 = alloca %"class.std::__ccr1::locale", align 4 ; [#uses=5 type=%"class.std::__ccr1::locale"*]
  %7 = alloca %"class.std::__ccr1::basic_string", align 4 ; [#uses=5 type=%"class.std::__ccr1::basic_string"*]
  %8 = load i32, i32* @_ZL8LastChar, align 4, !tbaa !13 ; [#uses=1 type=i32]
  %9 = trunc i32 %8 to i8                         ; [#uses=1 type=i8]
  tail call void @_ZNSt6__ccr112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE9push_backEc(%"class.std::__ccr1::basic_string"* nonnull @_ZL13IdentifierStr, i8 signext %9) #17
  %10 = tail call dereferenceable(84) %"class.std::__ccr1::basic_ostream"* @_ZNSt6__ccr124__put_character_sequenceIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m(%"class.std::__ccr1::basic_ostream"* nonnull dereferenceable(84) @_ZNSt6__ccr14cerrE, i8* getelementptr inbounds ([12 x i8], [12 x i8]* @.str.5, i32 0, i32 0), i32 11) #17 ; [#uses=1 type=%"class.std::__ccr1::basic_ostream"*]
  %11 = load i8, i8* bitcast (%"class.std::__ccr1::basic_string"* @_ZL13IdentifierStr to i8*), align 4, !tbaa !4 ; [#uses=2 type=i8]
  %12 = and i8 %11, 1                             ; [#uses=1 type=i8]
  %13 = icmp eq i8 %12, 0                         ; [#uses=2 type=i1]
  %14 = load i8*, i8** getelementptr inbounds (%"class.std::__ccr1::basic_string", %"class.std::__ccr1::basic_string"* @_ZL13IdentifierStr, i32 0, i32 0, i32 0, i32 0, i32 0, i32 0, i32 2), align 4 ; [#uses=1 type=i8*]
  %15 = load i32, i32* getelementptr inbounds (%"class.std::__ccr1::basic_string", %"class.std::__ccr1::basic_string"* @_ZL13IdentifierStr, i32 0, i32 0, i32 0, i32 0, i32 0, i32 0, i32 1), align 4 ; [#uses=1 type=i32]
  %16 = zext i8 %11 to i32                        ; [#uses=1 type=i32]
  %17 = lshr i32 %16, 1                           ; [#uses=1 type=i32]
  %18 = select i1 %13, i8* getelementptr (%"struct.std::__ccr1::basic_string<char, std::__ccr1::char_traits<char>, std::__ccr1::allocator<char> >::__short", %"struct.std::__ccr1::basic_string<char, std::__ccr1::char_traits<char>, std::__ccr1::allocator<char> >::__short"* bitcast (%"class.std::__ccr1::basic_string"* @_ZL13IdentifierStr to %"struct.std::__ccr1::basic_string<char, std::__ccr1::char_traits<char>, std::__ccr1::allocator<char> >::__short"*), i32 0, i32 1, i32 0), i8* %14 ; [#uses=1 type=i8*]
  %19 = select i1 %13, i32 %17, i32 %15           ; [#uses=1 type=i32]
  %20 = tail call dereferenceable(84) %"class.std::__ccr1::basic_ostream"* @_ZNSt6__ccr124__put_character_sequenceIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m(%"class.std::__ccr1::basic_ostream"* nonnull dereferenceable(84) %10, i8* %18, i32 %19) #17 ; [#uses=4 type=%"class.std::__ccr1::basic_ostream"*]
  %21 = bitcast %"class.std::__ccr1::basic_ostream"* %20 to i8** ; [#uses=1 type=i8**]
  %22 = load i8*, i8** %21, align 4, !tbaa !15    ; [#uses=1 type=i8*]
  %23 = getelementptr i8, i8* %22, i32 -12        ; [#uses=1 type=i8*]
  %24 = bitcast i8* %23 to i32*                   ; [#uses=1 type=i32*]
  %25 = load i32, i32* %24, align 4               ; [#uses=1 type=i32]
  %26 = bitcast %"class.std::__ccr1::basic_ostream"* %20 to i8* ; [#uses=1 type=i8*]
  %27 = getelementptr inbounds i8, i8* %26, i32 %25 ; [#uses=1 type=i8*]
  %28 = bitcast %"class.std::__ccr1::locale"* %5 to i8* ; [#uses=3 type=i8*]
  call void @llvm.lifetime.start.p0i8(i64 4, i8* nonnull %28) #1
  %29 = bitcast i8* %27 to %"class.std::__ccr1::ios_base"* ; [#uses=1 type=%"class.std::__ccr1::ios_base"*]
  call void @_ZNKSt6__ccr18ios_base6getlocEv(%"class.std::__ccr1::locale"* nonnull sret %5, %"class.std::__ccr1::ios_base"* %29) #17
  %30 = invoke %"class.std::__ccr1::locale::facet"* @_ZNKSt6__ccr16locale9use_facetERNS0_2idE(%"class.std::__ccr1::locale"* nonnull %5, %"class.std::__ccr1::locale::id"* nonnull dereferenceable(8) @_ZNSt6__ccr15ctypeIcE2idE) #17
          to label %31 unwind label %38           ; [#uses=2 type=%"class.std::__ccr1::locale::facet"*]

; <label>:31:                                     ; preds = %0
  %32 = bitcast %"class.std::__ccr1::locale::facet"* %30 to %"class.std::__ccr1::ctype"* ; [#uses=1 type=%"class.std::__ccr1::ctype"*]
  %33 = bitcast %"class.std::__ccr1::locale::facet"* %30 to i8 (%"class.std::__ccr1::ctype"*, i8)*** ; [#uses=1 type=i8 (%"class.std::__ccr1::ctype"*, i8)***]
  %34 = load i8 (%"class.std::__ccr1::ctype"*, i8)**, i8 (%"class.std::__ccr1::ctype"*, i8)*** %33, align 4, !tbaa !15 ; [#uses=1 type=i8 (%"class.std::__ccr1::ctype"*, i8)**]
  %35 = getelementptr inbounds i8 (%"class.std::__ccr1::ctype"*, i8)*, i8 (%"class.std::__ccr1::ctype"*, i8)** %34, i32 7 ; [#uses=1 type=i8 (%"class.std::__ccr1::ctype"*, i8)**]
  %36 = load i8 (%"class.std::__ccr1::ctype"*, i8)*, i8 (%"class.std::__ccr1::ctype"*, i8)** %35, align 4 ; [#uses=1 type=i8 (%"class.std::__ccr1::ctype"*, i8)*]
  %37 = invoke signext i8 %36(%"class.std::__ccr1::ctype"* %32, i8 signext 10) #17
          to label %41 unwind label %38           ; [#uses=1 type=i8]

; <label>:38:                                     ; preds = %31, %0
  %39 = landingpad { i8*, i32 }
          cleanup                                 ; [#uses=1 type={ i8*, i32 }]
  %40 = call %"class.std::__ccr1::locale"* @_ZNSt6__ccr16localeD1Ev(%"class.std::__ccr1::locale"* nonnull %5) #16 ; [#uses=0 type=%"class.std::__ccr1::locale"*]
  call void @llvm.lifetime.end.p0i8(i64 4, i8* nonnull %28) #1
  resume { i8*, i32 } %39

; <label>:41:                                     ; preds = %31
  %42 = call %"class.std::__ccr1::locale"* @_ZNSt6__ccr16localeD1Ev(%"class.std::__ccr1::locale"* nonnull %5) #16 ; [#uses=0 type=%"class.std::__ccr1::locale"*]
  call void @llvm.lifetime.end.p0i8(i64 4, i8* nonnull %28) #1
  %43 = call dereferenceable(84) %"class.std::__ccr1::basic_ostream"* @_ZNSt6__ccr113basic_ostreamIcNS_11char_traitsIcEEE3putEc(%"class.std::__ccr1::basic_ostream"* nonnull %20, i8 signext %37) #17 ; [#uses=0 type=%"class.std::__ccr1::basic_ostream"*]
  %44 = call dereferenceable(84) %"class.std::__ccr1::basic_ostream"* @_ZNSt6__ccr113basic_ostreamIcNS_11char_traitsIcEEE5flushEv(%"class.std::__ccr1::basic_ostream"* nonnull %20) #17 ; [#uses=0 type=%"class.std::__ccr1::basic_ostream"*]
  %45 = load %struct.__sFILE*, %struct.__sFILE** @__stderrp, align 4, !tbaa !10 ; [#uses=1 type=%struct.__sFILE*]
  %46 = call i32 (%struct.__sFILE*, i8*, ...) @fprintf(%struct.__sFILE* %45, i8* getelementptr inbounds ([34 x i8], [34 x i8]* @.str.3, i32 0, i32 0), i8* getelementptr inbounds ([7 x i8], [7 x i8]* @__func__._ZL6gettokv, i32 0, i32 0), i32 53, i8* getelementptr inbounds ([148 x i8], [148 x i8]* @.str.4, i32 0, i32 0)) #17 ; [#uses=0 type=i32]
  br label %47

; <label>:47:                                     ; preds = %59, %41
  %48 = phi i32 [ 32, %41 ], [ %60, %59 ]         ; [#uses=4 type=i32]
  store i32 %48, i32* @_ZL8LastChar, align 4, !tbaa !13
  %49 = icmp ugt i32 %48, 127                     ; [#uses=1 type=i1]
  br i1 %49, label %54, label %50

; <label>:50:                                     ; preds = %47
  %51 = getelementptr inbounds %struct._RuneLocale, %struct._RuneLocale* @_DefaultRuneLocale, i32 0, i32 5, i32 %48 ; [#uses=1 type=i32*]
  %52 = load i32, i32* %51, align 4, !tbaa !13    ; [#uses=1 type=i32]
  %53 = and i32 %52, 16384                        ; [#uses=1 type=i32]
  br label %56

; <label>:54:                                     ; preds = %47
  %55 = call i32 @__maskrune(i32 %48, i32 16384) #17 ; [#uses=1 type=i32]
  br label %56

; <label>:56:                                     ; preds = %50, %54
  %57 = phi i32 [ %53, %50 ], [ %55, %54 ]        ; [#uses=1 type=i32]
  %58 = icmp eq i32 %57, 0                        ; [#uses=1 type=i1]
  br i1 %58, label %61, label %59

; <label>:59:                                     ; preds = %56
  %60 = call i32 @getchar() #17                   ; [#uses=1 type=i32]
  br label %47

; <label>:61:                                     ; preds = %56
  %62 = load i32, i32* @_ZL8LastChar, align 4, !tbaa !13 ; [#uses=2 type=i32]
  %63 = icmp eq i32 %62, 35                       ; [#uses=1 type=i1]
  br i1 %63, label %64, label %135

; <label>:64:                                     ; preds = %61
  %65 = call dereferenceable(12) %"class.std::__ccr1::basic_string"* @_ZNSt6__ccr112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEaSEc(%"class.std::__ccr1::basic_string"* nonnull @_ZL13IdentifierStr, i8 signext 35) #17 ; [#uses=0 type=%"class.std::__ccr1::basic_string"*]
  br label %66

; <label>:66:                                     ; preds = %78, %64
  %67 = call i32 @getchar() #17                   ; [#uses=4 type=i32]
  store i32 %67, i32* @_ZL8LastChar, align 4, !tbaa !13
  %68 = icmp ugt i32 %67, 127                     ; [#uses=1 type=i1]
  br i1 %68, label %73, label %69

; <label>:69:                                     ; preds = %66
  %70 = getelementptr inbounds %struct._RuneLocale, %struct._RuneLocale* @_DefaultRuneLocale, i32 0, i32 5, i32 %67 ; [#uses=1 type=i32*]
  %71 = load i32, i32* %70, align 4, !tbaa !13    ; [#uses=1 type=i32]
  %72 = and i32 %71, 1280                         ; [#uses=1 type=i32]
  br label %75

; <label>:73:                                     ; preds = %66
  %74 = call i32 @__maskrune(i32 %67, i32 1280) #17 ; [#uses=1 type=i32]
  br label %75

; <label>:75:                                     ; preds = %69, %73
  %76 = phi i32 [ %72, %69 ], [ %74, %73 ]        ; [#uses=1 type=i32]
  %77 = icmp eq i32 %76, 0                        ; [#uses=1 type=i1]
  br i1 %77, label %81, label %78

; <label>:78:                                     ; preds = %75
  %79 = load i32, i32* @_ZL8LastChar, align 4, !tbaa !13 ; [#uses=1 type=i32]
  %80 = trunc i32 %79 to i8                       ; [#uses=1 type=i8]
  call void @_ZNSt6__ccr112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE9push_backEc(%"class.std::__ccr1::basic_string"* nonnull @_ZL13IdentifierStr, i8 signext %80) #17
  br label %66

; <label>:81:                                     ; preds = %75
  %82 = load i8, i8* bitcast (%"class.std::__ccr1::basic_string"* @_ZL13IdentifierStr to i8*), align 4, !tbaa !4 ; [#uses=2 type=i8]
  %83 = and i8 %82, 1                             ; [#uses=1 type=i8]
  %84 = icmp eq i8 %83, 0                         ; [#uses=1 type=i1]
  %85 = load i32, i32* getelementptr inbounds (%"class.std::__ccr1::basic_string", %"class.std::__ccr1::basic_string"* @_ZL13IdentifierStr, i32 0, i32 0, i32 0, i32 0, i32 0, i32 0, i32 1), align 4 ; [#uses=1 type=i32]
  %86 = zext i8 %82 to i32                        ; [#uses=1 type=i32]
  %87 = lshr i32 %86, 1                           ; [#uses=1 type=i32]
  %88 = select i1 %84, i32 %87, i32 %85           ; [#uses=1 type=i32]
  %89 = icmp eq i32 %88, 7                        ; [#uses=1 type=i1]
  br i1 %89, label %90, label %133

; <label>:90:                                     ; preds = %81
  %91 = invoke i32 @_ZNKSt6__ccr112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE7compareEmmPKcm(%"class.std::__ccr1::basic_string"* nonnull @_ZL13IdentifierStr, i32 0, i32 -1, i8* getelementptr inbounds ([8 x i8], [8 x i8]* @.str.6, i32 0, i32 0), i32 7) #17
          to label %95 unwind label %92           ; [#uses=1 type=i32]

; <label>:92:                                     ; preds = %90
  %93 = landingpad { i8*, i32 }
          catch i8* null                          ; [#uses=1 type={ i8*, i32 }]
  %94 = extractvalue { i8*, i32 } %93, 0          ; [#uses=1 type=i8*]
  call void @__clang_call_terminate(i8* %94) #19
  unreachable

; <label>:95:                                     ; preds = %90
  %96 = icmp eq i32 %91, 0                        ; [#uses=1 type=i1]
  br i1 %96, label %97, label %133

; <label>:97:                                     ; preds = %95
  %98 = call dereferenceable(84) %"class.std::__ccr1::basic_ostream"* @_ZNSt6__ccr124__put_character_sequenceIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m(%"class.std::__ccr1::basic_ostream"* nonnull dereferenceable(84) @_ZNSt6__ccr14cerrE, i8* getelementptr inbounds ([38 x i8], [38 x i8]* @.str.7, i32 0, i32 0), i32 37) #17 ; [#uses=1 type=%"class.std::__ccr1::basic_ostream"*]
  %99 = load i8, i8* bitcast (%"class.std::__ccr1::basic_string"* @_ZL13IdentifierStr to i8*), align 4, !tbaa !4 ; [#uses=2 type=i8]
  %100 = and i8 %99, 1                            ; [#uses=1 type=i8]
  %101 = icmp eq i8 %100, 0                       ; [#uses=2 type=i1]
  %102 = load i8*, i8** getelementptr inbounds (%"class.std::__ccr1::basic_string", %"class.std::__ccr1::basic_string"* @_ZL13IdentifierStr, i32 0, i32 0, i32 0, i32 0, i32 0, i32 0, i32 2), align 4 ; [#uses=1 type=i8*]
  %103 = load i32, i32* getelementptr inbounds (%"class.std::__ccr1::basic_string", %"class.std::__ccr1::basic_string"* @_ZL13IdentifierStr, i32 0, i32 0, i32 0, i32 0, i32 0, i32 0, i32 1), align 4 ; [#uses=1 type=i32]
  %104 = zext i8 %99 to i32                       ; [#uses=1 type=i32]
  %105 = lshr i32 %104, 1                         ; [#uses=1 type=i32]
  %106 = select i1 %101, i8* getelementptr (%"struct.std::__ccr1::basic_string<char, std::__ccr1::char_traits<char>, std::__ccr1::allocator<char> >::__short", %"struct.std::__ccr1::basic_string<char, std::__ccr1::char_traits<char>, std::__ccr1::allocator<char> >::__short"* bitcast (%"class.std::__ccr1::basic_string"* @_ZL13IdentifierStr to %"struct.std::__ccr1::basic_string<char, std::__ccr1::char_traits<char>, std::__ccr1::allocator<char> >::__short"*), i32 0, i32 1, i32 0), i8* %102 ; [#uses=1 type=i8*]
  %107 = select i1 %101, i32 %105, i32 %103       ; [#uses=1 type=i32]
  %108 = call dereferenceable(84) %"class.std::__ccr1::basic_ostream"* @_ZNSt6__ccr124__put_character_sequenceIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m(%"class.std::__ccr1::basic_ostream"* nonnull dereferenceable(84) %98, i8* %106, i32 %107) #17 ; [#uses=4 type=%"class.std::__ccr1::basic_ostream"*]
  %109 = bitcast %"class.std::__ccr1::basic_ostream"* %108 to i8** ; [#uses=1 type=i8**]
  %110 = load i8*, i8** %109, align 4, !tbaa !15  ; [#uses=1 type=i8*]
  %111 = getelementptr i8, i8* %110, i32 -12      ; [#uses=1 type=i8*]
  %112 = bitcast i8* %111 to i32*                 ; [#uses=1 type=i32*]
  %113 = load i32, i32* %112, align 4             ; [#uses=1 type=i32]
  %114 = bitcast %"class.std::__ccr1::basic_ostream"* %108 to i8* ; [#uses=1 type=i8*]
  %115 = getelementptr inbounds i8, i8* %114, i32 %113 ; [#uses=1 type=i8*]
  %116 = bitcast %"class.std::__ccr1::locale"* %4 to i8* ; [#uses=3 type=i8*]
  call void @llvm.lifetime.start.p0i8(i64 4, i8* nonnull %116) #1
  %117 = bitcast i8* %115 to %"class.std::__ccr1::ios_base"* ; [#uses=1 type=%"class.std::__ccr1::ios_base"*]
  call void @_ZNKSt6__ccr18ios_base6getlocEv(%"class.std::__ccr1::locale"* nonnull sret %4, %"class.std::__ccr1::ios_base"* %117) #17
  %118 = invoke %"class.std::__ccr1::locale::facet"* @_ZNKSt6__ccr16locale9use_facetERNS0_2idE(%"class.std::__ccr1::locale"* nonnull %4, %"class.std::__ccr1::locale::id"* nonnull dereferenceable(8) @_ZNSt6__ccr15ctypeIcE2idE) #17
          to label %119 unwind label %126         ; [#uses=2 type=%"class.std::__ccr1::locale::facet"*]

; <label>:119:                                    ; preds = %97
  %120 = bitcast %"class.std::__ccr1::locale::facet"* %118 to %"class.std::__ccr1::ctype"* ; [#uses=1 type=%"class.std::__ccr1::ctype"*]
  %121 = bitcast %"class.std::__ccr1::locale::facet"* %118 to i8 (%"class.std::__ccr1::ctype"*, i8)*** ; [#uses=1 type=i8 (%"class.std::__ccr1::ctype"*, i8)***]
  %122 = load i8 (%"class.std::__ccr1::ctype"*, i8)**, i8 (%"class.std::__ccr1::ctype"*, i8)*** %121, align 4, !tbaa !15 ; [#uses=1 type=i8 (%"class.std::__ccr1::ctype"*, i8)**]
  %123 = getelementptr inbounds i8 (%"class.std::__ccr1::ctype"*, i8)*, i8 (%"class.std::__ccr1::ctype"*, i8)** %122, i32 7 ; [#uses=1 type=i8 (%"class.std::__ccr1::ctype"*, i8)**]
  %124 = load i8 (%"class.std::__ccr1::ctype"*, i8)*, i8 (%"class.std::__ccr1::ctype"*, i8)** %123, align 4 ; [#uses=1 type=i8 (%"class.std::__ccr1::ctype"*, i8)*]
  %125 = invoke signext i8 %124(%"class.std::__ccr1::ctype"* %120, i8 signext 10) #17
          to label %129 unwind label %126         ; [#uses=1 type=i8]

; <label>:126:                                    ; preds = %119, %97
  %127 = landingpad { i8*, i32 }
          cleanup                                 ; [#uses=1 type={ i8*, i32 }]
  %128 = call %"class.std::__ccr1::locale"* @_ZNSt6__ccr16localeD1Ev(%"class.std::__ccr1::locale"* nonnull %4) #16 ; [#uses=0 type=%"class.std::__ccr1::locale"*]
  call void @llvm.lifetime.end.p0i8(i64 4, i8* nonnull %116) #1
  resume { i8*, i32 } %127

; <label>:129:                                    ; preds = %119
  %130 = call %"class.std::__ccr1::locale"* @_ZNSt6__ccr16localeD1Ev(%"class.std::__ccr1::locale"* nonnull %4) #16 ; [#uses=0 type=%"class.std::__ccr1::locale"*]
  call void @llvm.lifetime.end.p0i8(i64 4, i8* nonnull %116) #1
  %131 = call dereferenceable(84) %"class.std::__ccr1::basic_ostream"* @_ZNSt6__ccr113basic_ostreamIcNS_11char_traitsIcEEE3putEc(%"class.std::__ccr1::basic_ostream"* nonnull %108, i8 signext %125) #17 ; [#uses=0 type=%"class.std::__ccr1::basic_ostream"*]
  %132 = call dereferenceable(84) %"class.std::__ccr1::basic_ostream"* @_ZNSt6__ccr113basic_ostreamIcNS_11char_traitsIcEEE5flushEv(%"class.std::__ccr1::basic_ostream"* nonnull %108) #17 ; [#uses=0 type=%"class.std::__ccr1::basic_ostream"*]
  br label %440

; <label>:133:                                    ; preds = %81, %95
  %134 = load i32, i32* @_ZL8LastChar, align 4, !tbaa !13 ; [#uses=1 type=i32]
  br label %135

; <label>:135:                                    ; preds = %133, %61
  %136 = phi i32 [ %134, %133 ], [ %62, %61 ]     ; [#uses=4 type=i32]
  %137 = icmp ugt i32 %136, 127                   ; [#uses=1 type=i1]
  br i1 %137, label %142, label %138

; <label>:138:                                    ; preds = %135
  %139 = getelementptr inbounds %struct._RuneLocale, %struct._RuneLocale* @_DefaultRuneLocale, i32 0, i32 5, i32 %136 ; [#uses=1 type=i32*]
  %140 = load i32, i32* %139, align 4, !tbaa !13  ; [#uses=1 type=i32]
  %141 = and i32 %140, 256                        ; [#uses=1 type=i32]
  br label %145

; <label>:142:                                    ; preds = %135
  %143 = call i32 @__maskrune(i32 %136, i32 256) #17 ; [#uses=1 type=i32]
  %144 = load i32, i32* @_ZL8LastChar, align 4, !tbaa !13 ; [#uses=1 type=i32]
  br label %145

; <label>:145:                                    ; preds = %138, %142
  %146 = phi i32 [ %136, %138 ], [ %144, %142 ]   ; [#uses=7 type=i32]
  %147 = phi i32 [ %141, %138 ], [ %143, %142 ]   ; [#uses=1 type=i32]
  %148 = icmp eq i32 %147, 0                      ; [#uses=1 type=i1]
  br i1 %148, label %332, label %149

; <label>:149:                                    ; preds = %145
  %150 = trunc i32 %146 to i8                     ; [#uses=1 type=i8]
  %151 = call dereferenceable(12) %"class.std::__ccr1::basic_string"* @_ZNSt6__ccr112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEaSEc(%"class.std::__ccr1::basic_string"* nonnull @_ZL13IdentifierStr, i8 signext %150) #17 ; [#uses=0 type=%"class.std::__ccr1::basic_string"*]
  br label %152

; <label>:152:                                    ; preds = %164, %149
  %153 = call i32 @getchar() #17                  ; [#uses=4 type=i32]
  store i32 %153, i32* @_ZL8LastChar, align 4, !tbaa !13
  %154 = icmp ugt i32 %153, 127                   ; [#uses=1 type=i1]
  br i1 %154, label %159, label %155

; <label>:155:                                    ; preds = %152
  %156 = getelementptr inbounds %struct._RuneLocale, %struct._RuneLocale* @_DefaultRuneLocale, i32 0, i32 5, i32 %153 ; [#uses=1 type=i32*]
  %157 = load i32, i32* %156, align 4, !tbaa !13  ; [#uses=1 type=i32]
  %158 = and i32 %157, 1280                       ; [#uses=1 type=i32]
  br label %161

; <label>:159:                                    ; preds = %152
  %160 = call i32 @__maskrune(i32 %153, i32 1280) #17 ; [#uses=1 type=i32]
  br label %161

; <label>:161:                                    ; preds = %155, %159
  %162 = phi i32 [ %158, %155 ], [ %160, %159 ]   ; [#uses=1 type=i32]
  %163 = icmp eq i32 %162, 0                      ; [#uses=1 type=i1]
  br i1 %163, label %167, label %164

; <label>:164:                                    ; preds = %161
  %165 = load i32, i32* @_ZL8LastChar, align 4, !tbaa !13 ; [#uses=1 type=i32]
  %166 = trunc i32 %165 to i8                     ; [#uses=1 type=i8]
  call void @_ZNSt6__ccr112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE9push_backEc(%"class.std::__ccr1::basic_string"* nonnull @_ZL13IdentifierStr, i8 signext %166) #17
  br label %152

; <label>:167:                                    ; preds = %161
  %168 = load i8, i8* bitcast (%"class.std::__ccr1::basic_string"* @_ZL13IdentifierStr to i8*), align 4, !tbaa !4 ; [#uses=2 type=i8]
  %169 = and i8 %168, 1                           ; [#uses=2 type=i8]
  %170 = icmp eq i8 %169, 0                       ; [#uses=1 type=i1]
  %171 = load i32, i32* getelementptr inbounds (%"class.std::__ccr1::basic_string", %"class.std::__ccr1::basic_string"* @_ZL13IdentifierStr, i32 0, i32 0, i32 0, i32 0, i32 0, i32 0, i32 1), align 4 ; [#uses=2 type=i32]
  %172 = zext i8 %168 to i32                      ; [#uses=1 type=i32]
  %173 = lshr i32 %172, 1                         ; [#uses=2 type=i32]
  %174 = select i1 %170, i32 %173, i32 %171       ; [#uses=1 type=i32]
  %175 = icmp eq i32 %174, 3                      ; [#uses=1 type=i1]
  br i1 %175, label %176, label %225

; <label>:176:                                    ; preds = %167
  %177 = invoke i32 @_ZNKSt6__ccr112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE7compareEmmPKcm(%"class.std::__ccr1::basic_string"* nonnull @_ZL13IdentifierStr, i32 0, i32 -1, i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str.8, i32 0, i32 0), i32 3) #17
          to label %181 unwind label %178         ; [#uses=1 type=i32]

; <label>:178:                                    ; preds = %176
  %179 = landingpad { i8*, i32 }
          catch i8* null                          ; [#uses=1 type={ i8*, i32 }]
  %180 = extractvalue { i8*, i32 } %179, 0        ; [#uses=1 type=i8*]
  call void @__clang_call_terminate(i8* %180) #19
  unreachable

; <label>:181:                                    ; preds = %176
  %182 = icmp eq i32 %177, 0                      ; [#uses=1 type=i1]
  br i1 %182, label %189, label %183

; <label>:183:                                    ; preds = %181
  %184 = load i8, i8* bitcast (%"class.std::__ccr1::basic_string"* @_ZL13IdentifierStr to i8*), align 4, !tbaa !4 ; [#uses=2 type=i8]
  %185 = load i32, i32* getelementptr inbounds (%"class.std::__ccr1::basic_string", %"class.std::__ccr1::basic_string"* @_ZL13IdentifierStr, i32 0, i32 0, i32 0, i32 0, i32 0, i32 0, i32 1), align 4 ; [#uses=1 type=i32]
  %186 = and i8 %184, 1                           ; [#uses=1 type=i8]
  %187 = zext i8 %184 to i32                      ; [#uses=1 type=i32]
  %188 = lshr i32 %187, 1                         ; [#uses=1 type=i32]
  br label %225

; <label>:189:                                    ; preds = %181
  %190 = call dereferenceable(84) %"class.std::__ccr1::basic_ostream"* @_ZNSt6__ccr124__put_character_sequenceIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m(%"class.std::__ccr1::basic_ostream"* nonnull dereferenceable(84) @_ZNSt6__ccr14cerrE, i8* getelementptr inbounds ([38 x i8], [38 x i8]* @.str.7, i32 0, i32 0), i32 37) #17 ; [#uses=1 type=%"class.std::__ccr1::basic_ostream"*]
  %191 = load i8, i8* bitcast (%"class.std::__ccr1::basic_string"* @_ZL13IdentifierStr to i8*), align 4, !tbaa !4 ; [#uses=2 type=i8]
  %192 = and i8 %191, 1                           ; [#uses=1 type=i8]
  %193 = icmp eq i8 %192, 0                       ; [#uses=2 type=i1]
  %194 = load i8*, i8** getelementptr inbounds (%"class.std::__ccr1::basic_string", %"class.std::__ccr1::basic_string"* @_ZL13IdentifierStr, i32 0, i32 0, i32 0, i32 0, i32 0, i32 0, i32 2), align 4 ; [#uses=1 type=i8*]
  %195 = load i32, i32* getelementptr inbounds (%"class.std::__ccr1::basic_string", %"class.std::__ccr1::basic_string"* @_ZL13IdentifierStr, i32 0, i32 0, i32 0, i32 0, i32 0, i32 0, i32 1), align 4 ; [#uses=1 type=i32]
  %196 = zext i8 %191 to i32                      ; [#uses=1 type=i32]
  %197 = lshr i32 %196, 1                         ; [#uses=1 type=i32]
  %198 = select i1 %193, i8* getelementptr (%"struct.std::__ccr1::basic_string<char, std::__ccr1::char_traits<char>, std::__ccr1::allocator<char> >::__short", %"struct.std::__ccr1::basic_string<char, std::__ccr1::char_traits<char>, std::__ccr1::allocator<char> >::__short"* bitcast (%"class.std::__ccr1::basic_string"* @_ZL13IdentifierStr to %"struct.std::__ccr1::basic_string<char, std::__ccr1::char_traits<char>, std::__ccr1::allocator<char> >::__short"*), i32 0, i32 1, i32 0), i8* %194 ; [#uses=1 type=i8*]
  %199 = select i1 %193, i32 %197, i32 %195       ; [#uses=1 type=i32]
  %200 = call dereferenceable(84) %"class.std::__ccr1::basic_ostream"* @_ZNSt6__ccr124__put_character_sequenceIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m(%"class.std::__ccr1::basic_ostream"* nonnull dereferenceable(84) %190, i8* %198, i32 %199) #17 ; [#uses=4 type=%"class.std::__ccr1::basic_ostream"*]
  %201 = bitcast %"class.std::__ccr1::basic_ostream"* %200 to i8** ; [#uses=1 type=i8**]
  %202 = load i8*, i8** %201, align 4, !tbaa !15  ; [#uses=1 type=i8*]
  %203 = getelementptr i8, i8* %202, i32 -12      ; [#uses=1 type=i8*]
  %204 = bitcast i8* %203 to i32*                 ; [#uses=1 type=i32*]
  %205 = load i32, i32* %204, align 4             ; [#uses=1 type=i32]
  %206 = bitcast %"class.std::__ccr1::basic_ostream"* %200 to i8* ; [#uses=1 type=i8*]
  %207 = getelementptr inbounds i8, i8* %206, i32 %205 ; [#uses=1 type=i8*]
  %208 = bitcast %"class.std::__ccr1::locale"* %3 to i8* ; [#uses=3 type=i8*]
  call void @llvm.lifetime.start.p0i8(i64 4, i8* nonnull %208) #1
  %209 = bitcast i8* %207 to %"class.std::__ccr1::ios_base"* ; [#uses=1 type=%"class.std::__ccr1::ios_base"*]
  call void @_ZNKSt6__ccr18ios_base6getlocEv(%"class.std::__ccr1::locale"* nonnull sret %3, %"class.std::__ccr1::ios_base"* %209) #17
  %210 = invoke %"class.std::__ccr1::locale::facet"* @_ZNKSt6__ccr16locale9use_facetERNS0_2idE(%"class.std::__ccr1::locale"* nonnull %3, %"class.std::__ccr1::locale::id"* nonnull dereferenceable(8) @_ZNSt6__ccr15ctypeIcE2idE) #17
          to label %211 unwind label %218         ; [#uses=2 type=%"class.std::__ccr1::locale::facet"*]

; <label>:211:                                    ; preds = %189
  %212 = bitcast %"class.std::__ccr1::locale::facet"* %210 to %"class.std::__ccr1::ctype"* ; [#uses=1 type=%"class.std::__ccr1::ctype"*]
  %213 = bitcast %"class.std::__ccr1::locale::facet"* %210 to i8 (%"class.std::__ccr1::ctype"*, i8)*** ; [#uses=1 type=i8 (%"class.std::__ccr1::ctype"*, i8)***]
  %214 = load i8 (%"class.std::__ccr1::ctype"*, i8)**, i8 (%"class.std::__ccr1::ctype"*, i8)*** %213, align 4, !tbaa !15 ; [#uses=1 type=i8 (%"class.std::__ccr1::ctype"*, i8)**]
  %215 = getelementptr inbounds i8 (%"class.std::__ccr1::ctype"*, i8)*, i8 (%"class.std::__ccr1::ctype"*, i8)** %214, i32 7 ; [#uses=1 type=i8 (%"class.std::__ccr1::ctype"*, i8)**]
  %216 = load i8 (%"class.std::__ccr1::ctype"*, i8)*, i8 (%"class.std::__ccr1::ctype"*, i8)** %215, align 4 ; [#uses=1 type=i8 (%"class.std::__ccr1::ctype"*, i8)*]
  %217 = invoke signext i8 %216(%"class.std::__ccr1::ctype"* %212, i8 signext 10) #17
          to label %221 unwind label %218         ; [#uses=1 type=i8]

; <label>:218:                                    ; preds = %211, %189
  %219 = landingpad { i8*, i32 }
          cleanup                                 ; [#uses=1 type={ i8*, i32 }]
  %220 = call %"class.std::__ccr1::locale"* @_ZNSt6__ccr16localeD1Ev(%"class.std::__ccr1::locale"* nonnull %3) #16 ; [#uses=0 type=%"class.std::__ccr1::locale"*]
  call void @llvm.lifetime.end.p0i8(i64 4, i8* nonnull %208) #1
  resume { i8*, i32 } %219

; <label>:221:                                    ; preds = %211
  %222 = call %"class.std::__ccr1::locale"* @_ZNSt6__ccr16localeD1Ev(%"class.std::__ccr1::locale"* nonnull %3) #16 ; [#uses=0 type=%"class.std::__ccr1::locale"*]
  call void @llvm.lifetime.end.p0i8(i64 4, i8* nonnull %208) #1
  %223 = call dereferenceable(84) %"class.std::__ccr1::basic_ostream"* @_ZNSt6__ccr113basic_ostreamIcNS_11char_traitsIcEEE3putEc(%"class.std::__ccr1::basic_ostream"* nonnull %200, i8 signext %217) #17 ; [#uses=0 type=%"class.std::__ccr1::basic_ostream"*]
  %224 = call dereferenceable(84) %"class.std::__ccr1::basic_ostream"* @_ZNSt6__ccr113basic_ostreamIcNS_11char_traitsIcEEE5flushEv(%"class.std::__ccr1::basic_ostream"* nonnull %200) #17 ; [#uses=0 type=%"class.std::__ccr1::basic_ostream"*]
  br label %440

; <label>:225:                                    ; preds = %183, %167
  %226 = phi i32 [ %188, %183 ], [ %173, %167 ]   ; [#uses=2 type=i32]
  %227 = phi i8 [ %186, %183 ], [ %169, %167 ]    ; [#uses=2 type=i8]
  %228 = phi i32 [ %185, %183 ], [ %171, %167 ]   ; [#uses=2 type=i32]
  %229 = icmp eq i8 %227, 0                       ; [#uses=1 type=i1]
  %230 = select i1 %229, i32 %226, i32 %228       ; [#uses=1 type=i32]
  %231 = icmp eq i32 %230, 6                      ; [#uses=1 type=i1]
  br i1 %231, label %232, label %281

; <label>:232:                                    ; preds = %225
  %233 = invoke i32 @_ZNKSt6__ccr112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE7compareEmmPKcm(%"class.std::__ccr1::basic_string"* nonnull @_ZL13IdentifierStr, i32 0, i32 -1, i8* getelementptr inbounds ([7 x i8], [7 x i8]* @.str.9, i32 0, i32 0), i32 6) #17
          to label %237 unwind label %234         ; [#uses=1 type=i32]

; <label>:234:                                    ; preds = %232
  %235 = landingpad { i8*, i32 }
          catch i8* null                          ; [#uses=1 type={ i8*, i32 }]
  %236 = extractvalue { i8*, i32 } %235, 0        ; [#uses=1 type=i8*]
  call void @__clang_call_terminate(i8* %236) #19
  unreachable

; <label>:237:                                    ; preds = %232
  %238 = icmp eq i32 %233, 0                      ; [#uses=1 type=i1]
  br i1 %238, label %245, label %239

; <label>:239:                                    ; preds = %237
  %240 = load i8, i8* bitcast (%"class.std::__ccr1::basic_string"* @_ZL13IdentifierStr to i8*), align 4, !tbaa !4 ; [#uses=2 type=i8]
  %241 = load i32, i32* getelementptr inbounds (%"class.std::__ccr1::basic_string", %"class.std::__ccr1::basic_string"* @_ZL13IdentifierStr, i32 0, i32 0, i32 0, i32 0, i32 0, i32 0, i32 1), align 4 ; [#uses=1 type=i32]
  %242 = and i8 %240, 1                           ; [#uses=1 type=i8]
  %243 = zext i8 %240 to i32                      ; [#uses=1 type=i32]
  %244 = lshr i32 %243, 1                         ; [#uses=1 type=i32]
  br label %281

; <label>:245:                                    ; preds = %237
  %246 = call dereferenceable(84) %"class.std::__ccr1::basic_ostream"* @_ZNSt6__ccr124__put_character_sequenceIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m(%"class.std::__ccr1::basic_ostream"* nonnull dereferenceable(84) @_ZNSt6__ccr14cerrE, i8* getelementptr inbounds ([38 x i8], [38 x i8]* @.str.7, i32 0, i32 0), i32 37) #17 ; [#uses=1 type=%"class.std::__ccr1::basic_ostream"*]
  %247 = load i8, i8* bitcast (%"class.std::__ccr1::basic_string"* @_ZL13IdentifierStr to i8*), align 4, !tbaa !4 ; [#uses=2 type=i8]
  %248 = and i8 %247, 1                           ; [#uses=1 type=i8]
  %249 = icmp eq i8 %248, 0                       ; [#uses=2 type=i1]
  %250 = load i8*, i8** getelementptr inbounds (%"class.std::__ccr1::basic_string", %"class.std::__ccr1::basic_string"* @_ZL13IdentifierStr, i32 0, i32 0, i32 0, i32 0, i32 0, i32 0, i32 2), align 4 ; [#uses=1 type=i8*]
  %251 = load i32, i32* getelementptr inbounds (%"class.std::__ccr1::basic_string", %"class.std::__ccr1::basic_string"* @_ZL13IdentifierStr, i32 0, i32 0, i32 0, i32 0, i32 0, i32 0, i32 1), align 4 ; [#uses=1 type=i32]
  %252 = zext i8 %247 to i32                      ; [#uses=1 type=i32]
  %253 = lshr i32 %252, 1                         ; [#uses=1 type=i32]
  %254 = select i1 %249, i8* getelementptr (%"struct.std::__ccr1::basic_string<char, std::__ccr1::char_traits<char>, std::__ccr1::allocator<char> >::__short", %"struct.std::__ccr1::basic_string<char, std::__ccr1::char_traits<char>, std::__ccr1::allocator<char> >::__short"* bitcast (%"class.std::__ccr1::basic_string"* @_ZL13IdentifierStr to %"struct.std::__ccr1::basic_string<char, std::__ccr1::char_traits<char>, std::__ccr1::allocator<char> >::__short"*), i32 0, i32 1, i32 0), i8* %250 ; [#uses=1 type=i8*]
  %255 = select i1 %249, i32 %253, i32 %251       ; [#uses=1 type=i32]
  %256 = call dereferenceable(84) %"class.std::__ccr1::basic_ostream"* @_ZNSt6__ccr124__put_character_sequenceIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m(%"class.std::__ccr1::basic_ostream"* nonnull dereferenceable(84) %246, i8* %254, i32 %255) #17 ; [#uses=4 type=%"class.std::__ccr1::basic_ostream"*]
  %257 = bitcast %"class.std::__ccr1::basic_ostream"* %256 to i8** ; [#uses=1 type=i8**]
  %258 = load i8*, i8** %257, align 4, !tbaa !15  ; [#uses=1 type=i8*]
  %259 = getelementptr i8, i8* %258, i32 -12      ; [#uses=1 type=i8*]
  %260 = bitcast i8* %259 to i32*                 ; [#uses=1 type=i32*]
  %261 = load i32, i32* %260, align 4             ; [#uses=1 type=i32]
  %262 = bitcast %"class.std::__ccr1::basic_ostream"* %256 to i8* ; [#uses=1 type=i8*]
  %263 = getelementptr inbounds i8, i8* %262, i32 %261 ; [#uses=1 type=i8*]
  %264 = bitcast %"class.std::__ccr1::locale"* %2 to i8* ; [#uses=3 type=i8*]
  call void @llvm.lifetime.start.p0i8(i64 4, i8* nonnull %264) #1
  %265 = bitcast i8* %263 to %"class.std::__ccr1::ios_base"* ; [#uses=1 type=%"class.std::__ccr1::ios_base"*]
  call void @_ZNKSt6__ccr18ios_base6getlocEv(%"class.std::__ccr1::locale"* nonnull sret %2, %"class.std::__ccr1::ios_base"* %265) #17
  %266 = invoke %"class.std::__ccr1::locale::facet"* @_ZNKSt6__ccr16locale9use_facetERNS0_2idE(%"class.std::__ccr1::locale"* nonnull %2, %"class.std::__ccr1::locale::id"* nonnull dereferenceable(8) @_ZNSt6__ccr15ctypeIcE2idE) #17
          to label %267 unwind label %274         ; [#uses=2 type=%"class.std::__ccr1::locale::facet"*]

; <label>:267:                                    ; preds = %245
  %268 = bitcast %"class.std::__ccr1::locale::facet"* %266 to %"class.std::__ccr1::ctype"* ; [#uses=1 type=%"class.std::__ccr1::ctype"*]
  %269 = bitcast %"class.std::__ccr1::locale::facet"* %266 to i8 (%"class.std::__ccr1::ctype"*, i8)*** ; [#uses=1 type=i8 (%"class.std::__ccr1::ctype"*, i8)***]
  %270 = load i8 (%"class.std::__ccr1::ctype"*, i8)**, i8 (%"class.std::__ccr1::ctype"*, i8)*** %269, align 4, !tbaa !15 ; [#uses=1 type=i8 (%"class.std::__ccr1::ctype"*, i8)**]
  %271 = getelementptr inbounds i8 (%"class.std::__ccr1::ctype"*, i8)*, i8 (%"class.std::__ccr1::ctype"*, i8)** %270, i32 7 ; [#uses=1 type=i8 (%"class.std::__ccr1::ctype"*, i8)**]
  %272 = load i8 (%"class.std::__ccr1::ctype"*, i8)*, i8 (%"class.std::__ccr1::ctype"*, i8)** %271, align 4 ; [#uses=1 type=i8 (%"class.std::__ccr1::ctype"*, i8)*]
  %273 = invoke signext i8 %272(%"class.std::__ccr1::ctype"* %268, i8 signext 10) #17
          to label %277 unwind label %274         ; [#uses=1 type=i8]

; <label>:274:                                    ; preds = %267, %245
  %275 = landingpad { i8*, i32 }
          cleanup                                 ; [#uses=1 type={ i8*, i32 }]
  %276 = call %"class.std::__ccr1::locale"* @_ZNSt6__ccr16localeD1Ev(%"class.std::__ccr1::locale"* nonnull %2) #16 ; [#uses=0 type=%"class.std::__ccr1::locale"*]
  call void @llvm.lifetime.end.p0i8(i64 4, i8* nonnull %264) #1
  resume { i8*, i32 } %275

; <label>:277:                                    ; preds = %267
  %278 = call %"class.std::__ccr1::locale"* @_ZNSt6__ccr16localeD1Ev(%"class.std::__ccr1::locale"* nonnull %2) #16 ; [#uses=0 type=%"class.std::__ccr1::locale"*]
  call void @llvm.lifetime.end.p0i8(i64 4, i8* nonnull %264) #1
  %279 = call dereferenceable(84) %"class.std::__ccr1::basic_ostream"* @_ZNSt6__ccr113basic_ostreamIcNS_11char_traitsIcEEE3putEc(%"class.std::__ccr1::basic_ostream"* nonnull %256, i8 signext %273) #17 ; [#uses=0 type=%"class.std::__ccr1::basic_ostream"*]
  %280 = call dereferenceable(84) %"class.std::__ccr1::basic_ostream"* @_ZNSt6__ccr113basic_ostreamIcNS_11char_traitsIcEEE5flushEv(%"class.std::__ccr1::basic_ostream"* nonnull %256) #17 ; [#uses=0 type=%"class.std::__ccr1::basic_ostream"*]
  br label %440

; <label>:281:                                    ; preds = %239, %225
  %282 = phi i32 [ %244, %239 ], [ %226, %225 ]   ; [#uses=1 type=i32]
  %283 = phi i8 [ %242, %239 ], [ %227, %225 ]    ; [#uses=1 type=i8]
  %284 = phi i32 [ %241, %239 ], [ %228, %225 ]   ; [#uses=1 type=i32]
  %285 = icmp eq i8 %283, 0                       ; [#uses=1 type=i1]
  %286 = select i1 %285, i32 %282, i32 %284       ; [#uses=1 type=i32]
  %287 = icmp eq i32 %286, 1                      ; [#uses=1 type=i1]
  br i1 %287, label %288, label %440

; <label>:288:                                    ; preds = %281
  %289 = invoke i32 @_ZNKSt6__ccr112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE7compareEmmPKcm(%"class.std::__ccr1::basic_string"* nonnull @_ZL13IdentifierStr, i32 0, i32 -1, i8* getelementptr inbounds ([2 x i8], [2 x i8]* @.str.10, i32 0, i32 0), i32 1) #17
          to label %293 unwind label %290         ; [#uses=1 type=i32]

; <label>:290:                                    ; preds = %288
  %291 = landingpad { i8*, i32 }
          catch i8* null                          ; [#uses=1 type={ i8*, i32 }]
  %292 = extractvalue { i8*, i32 } %291, 0        ; [#uses=1 type=i8*]
  call void @__clang_call_terminate(i8* %292) #19
  unreachable

; <label>:293:                                    ; preds = %288
  %294 = icmp eq i32 %289, 0                      ; [#uses=1 type=i1]
  br i1 %294, label %295, label %440

; <label>:295:                                    ; preds = %293
  %296 = call dereferenceable(84) %"class.std::__ccr1::basic_ostream"* @_ZNSt6__ccr124__put_character_sequenceIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m(%"class.std::__ccr1::basic_ostream"* nonnull dereferenceable(84) @_ZNSt6__ccr14cerrE, i8* getelementptr inbounds ([38 x i8], [38 x i8]* @.str.7, i32 0, i32 0), i32 37) #17 ; [#uses=1 type=%"class.std::__ccr1::basic_ostream"*]
  %297 = load i8, i8* bitcast (%"class.std::__ccr1::basic_string"* @_ZL13IdentifierStr to i8*), align 4, !tbaa !4 ; [#uses=2 type=i8]
  %298 = and i8 %297, 1                           ; [#uses=1 type=i8]
  %299 = icmp eq i8 %298, 0                       ; [#uses=2 type=i1]
  %300 = load i8*, i8** getelementptr inbounds (%"class.std::__ccr1::basic_string", %"class.std::__ccr1::basic_string"* @_ZL13IdentifierStr, i32 0, i32 0, i32 0, i32 0, i32 0, i32 0, i32 2), align 4 ; [#uses=1 type=i8*]
  %301 = load i32, i32* getelementptr inbounds (%"class.std::__ccr1::basic_string", %"class.std::__ccr1::basic_string"* @_ZL13IdentifierStr, i32 0, i32 0, i32 0, i32 0, i32 0, i32 0, i32 1), align 4 ; [#uses=1 type=i32]
  %302 = zext i8 %297 to i32                      ; [#uses=1 type=i32]
  %303 = lshr i32 %302, 1                         ; [#uses=1 type=i32]
  %304 = select i1 %299, i8* getelementptr (%"struct.std::__ccr1::basic_string<char, std::__ccr1::char_traits<char>, std::__ccr1::allocator<char> >::__short", %"struct.std::__ccr1::basic_string<char, std::__ccr1::char_traits<char>, std::__ccr1::allocator<char> >::__short"* bitcast (%"class.std::__ccr1::basic_string"* @_ZL13IdentifierStr to %"struct.std::__ccr1::basic_string<char, std::__ccr1::char_traits<char>, std::__ccr1::allocator<char> >::__short"*), i32 0, i32 1, i32 0), i8* %300 ; [#uses=1 type=i8*]
  %305 = select i1 %299, i32 %303, i32 %301       ; [#uses=1 type=i32]
  %306 = call dereferenceable(84) %"class.std::__ccr1::basic_ostream"* @_ZNSt6__ccr124__put_character_sequenceIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m(%"class.std::__ccr1::basic_ostream"* nonnull dereferenceable(84) %296, i8* %304, i32 %305) #17 ; [#uses=1 type=%"class.std::__ccr1::basic_ostream"*]
  %307 = call dereferenceable(84) %"class.std::__ccr1::basic_ostream"* @_ZNSt6__ccr124__put_character_sequenceIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m(%"class.std::__ccr1::basic_ostream"* nonnull dereferenceable(84) %306, i8* getelementptr inbounds ([22 x i8], [22 x i8]* @.str.11, i32 0, i32 0), i32 21) #17 ; [#uses=4 type=%"class.std::__ccr1::basic_ostream"*]
  %308 = bitcast %"class.std::__ccr1::basic_ostream"* %307 to i8** ; [#uses=1 type=i8**]
  %309 = load i8*, i8** %308, align 4, !tbaa !15  ; [#uses=1 type=i8*]
  %310 = getelementptr i8, i8* %309, i32 -12      ; [#uses=1 type=i8*]
  %311 = bitcast i8* %310 to i32*                 ; [#uses=1 type=i32*]
  %312 = load i32, i32* %311, align 4             ; [#uses=1 type=i32]
  %313 = bitcast %"class.std::__ccr1::basic_ostream"* %307 to i8* ; [#uses=1 type=i8*]
  %314 = getelementptr inbounds i8, i8* %313, i32 %312 ; [#uses=1 type=i8*]
  %315 = bitcast %"class.std::__ccr1::locale"* %6 to i8* ; [#uses=3 type=i8*]
  call void @llvm.lifetime.start.p0i8(i64 4, i8* nonnull %315) #1
  %316 = bitcast i8* %314 to %"class.std::__ccr1::ios_base"* ; [#uses=1 type=%"class.std::__ccr1::ios_base"*]
  call void @_ZNKSt6__ccr18ios_base6getlocEv(%"class.std::__ccr1::locale"* nonnull sret %6, %"class.std::__ccr1::ios_base"* %316) #17
  %317 = invoke %"class.std::__ccr1::locale::facet"* @_ZNKSt6__ccr16locale9use_facetERNS0_2idE(%"class.std::__ccr1::locale"* nonnull %6, %"class.std::__ccr1::locale::id"* nonnull dereferenceable(8) @_ZNSt6__ccr15ctypeIcE2idE) #17
          to label %318 unwind label %325         ; [#uses=2 type=%"class.std::__ccr1::locale::facet"*]

; <label>:318:                                    ; preds = %295
  %319 = bitcast %"class.std::__ccr1::locale::facet"* %317 to %"class.std::__ccr1::ctype"* ; [#uses=1 type=%"class.std::__ccr1::ctype"*]
  %320 = bitcast %"class.std::__ccr1::locale::facet"* %317 to i8 (%"class.std::__ccr1::ctype"*, i8)*** ; [#uses=1 type=i8 (%"class.std::__ccr1::ctype"*, i8)***]
  %321 = load i8 (%"class.std::__ccr1::ctype"*, i8)**, i8 (%"class.std::__ccr1::ctype"*, i8)*** %320, align 4, !tbaa !15 ; [#uses=1 type=i8 (%"class.std::__ccr1::ctype"*, i8)**]
  %322 = getelementptr inbounds i8 (%"class.std::__ccr1::ctype"*, i8)*, i8 (%"class.std::__ccr1::ctype"*, i8)** %321, i32 7 ; [#uses=1 type=i8 (%"class.std::__ccr1::ctype"*, i8)**]
  %323 = load i8 (%"class.std::__ccr1::ctype"*, i8)*, i8 (%"class.std::__ccr1::ctype"*, i8)** %322, align 4 ; [#uses=1 type=i8 (%"class.std::__ccr1::ctype"*, i8)*]
  %324 = invoke signext i8 %323(%"class.std::__ccr1::ctype"* %319, i8 signext 10) #17
          to label %328 unwind label %325         ; [#uses=1 type=i8]

; <label>:325:                                    ; preds = %318, %295
  %326 = landingpad { i8*, i32 }
          cleanup                                 ; [#uses=1 type={ i8*, i32 }]
  %327 = call %"class.std::__ccr1::locale"* @_ZNSt6__ccr16localeD1Ev(%"class.std::__ccr1::locale"* nonnull %6) #16 ; [#uses=0 type=%"class.std::__ccr1::locale"*]
  call void @llvm.lifetime.end.p0i8(i64 4, i8* nonnull %315) #1
  resume { i8*, i32 } %326

; <label>:328:                                    ; preds = %318
  %329 = call %"class.std::__ccr1::locale"* @_ZNSt6__ccr16localeD1Ev(%"class.std::__ccr1::locale"* nonnull %6) #16 ; [#uses=0 type=%"class.std::__ccr1::locale"*]
  call void @llvm.lifetime.end.p0i8(i64 4, i8* nonnull %315) #1
  %330 = call dereferenceable(84) %"class.std::__ccr1::basic_ostream"* @_ZNSt6__ccr113basic_ostreamIcNS_11char_traitsIcEEE3putEc(%"class.std::__ccr1::basic_ostream"* nonnull %307, i8 signext %324) #17 ; [#uses=0 type=%"class.std::__ccr1::basic_ostream"*]
  %331 = call dereferenceable(84) %"class.std::__ccr1::basic_ostream"* @_ZNSt6__ccr113basic_ostreamIcNS_11char_traitsIcEEE5flushEv(%"class.std::__ccr1::basic_ostream"* nonnull %307) #17 ; [#uses=0 type=%"class.std::__ccr1::basic_ostream"*]
  br label %440

; <label>:332:                                    ; preds = %145
  %333 = icmp ugt i32 %146, 255                   ; [#uses=1 type=i1]
  br i1 %333, label %339, label %334

; <label>:334:                                    ; preds = %332
  %335 = getelementptr inbounds %struct._RuneLocale, %struct._RuneLocale* @_DefaultRuneLocale, i32 0, i32 5, i32 %146 ; [#uses=1 type=i32*]
  %336 = load i32, i32* %335, align 4, !tbaa !13  ; [#uses=1 type=i32]
  %337 = and i32 %336, 1024                       ; [#uses=1 type=i32]
  %338 = icmp ne i32 %337, 0                      ; [#uses=1 type=i1]
  br label %339

; <label>:339:                                    ; preds = %332, %334
  %340 = phi i1 [ %338, %334 ], [ false, %332 ]   ; [#uses=1 type=i1]
  %341 = icmp eq i32 %146, 46                     ; [#uses=1 type=i1]
  %342 = or i1 %341, %340                         ; [#uses=1 type=i1]
  br i1 %342, label %343, label %391

; <label>:343:                                    ; preds = %339
  %344 = bitcast %"class.std::__ccr1::basic_string"* %7 to i8* ; [#uses=7 type=i8*]
  call void @llvm.lifetime.start.p0i8(i64 12, i8* nonnull %344) #1
  call void @llvm.memset.p0i8.i64(i8* nonnull %344, i8 0, i64 12, i32 4, i1 false) #1
  br label %345

; <label>:345:                                    ; preds = %356, %343
  %346 = phi i32 [ %349, %356 ], [ %146, %343 ]   ; [#uses=1 type=i32]
  %347 = trunc i32 %346 to i8                     ; [#uses=1 type=i8]
  invoke void @_ZNSt6__ccr112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE9push_backEc(%"class.std::__ccr1::basic_string"* nonnull %7, i8 signext %347) #17
          to label %348 unwind label %378

; <label>:348:                                    ; preds = %345
  %349 = call i32 @getchar() #17                  ; [#uses=5 type=i32]
  store i32 %349, i32* @_ZL8LastChar, align 4, !tbaa !13
  %350 = icmp ugt i32 %349, 255                   ; [#uses=1 type=i1]
  br i1 %350, label %356, label %351

; <label>:351:                                    ; preds = %348
  %352 = getelementptr inbounds %struct._RuneLocale, %struct._RuneLocale* @_DefaultRuneLocale, i32 0, i32 5, i32 %349 ; [#uses=1 type=i32*]
  %353 = load i32, i32* %352, align 4, !tbaa !13  ; [#uses=1 type=i32]
  %354 = lshr i32 %353, 10                        ; [#uses=1 type=i32]
  %355 = and i32 %354, 1                          ; [#uses=1 type=i32]
  br label %356

; <label>:356:                                    ; preds = %351, %348
  %357 = phi i32 [ %355, %351 ], [ 0, %348 ]      ; [#uses=1 type=i32]
  %358 = icmp ne i32 %357, 0                      ; [#uses=1 type=i1]
  %359 = icmp eq i32 %349, 46                     ; [#uses=1 type=i1]
  %360 = or i1 %359, %358                         ; [#uses=1 type=i1]
  br i1 %360, label %345, label %361

; <label>:361:                                    ; preds = %356
  %362 = load i8, i8* %344, align 4, !tbaa !4     ; [#uses=1 type=i8]
  %363 = and i8 %362, 1                           ; [#uses=1 type=i8]
  %364 = icmp eq i8 %363, 0                       ; [#uses=1 type=i1]
  %365 = getelementptr inbounds %"class.std::__ccr1::basic_string", %"class.std::__ccr1::basic_string"* %7, i32 0, i32 0, i32 0, i32 0, i32 0, i32 0, i32 2 ; [#uses=2 type=i8**]
  %366 = load i8*, i8** %365, align 4             ; [#uses=1 type=i8*]
  %367 = bitcast %"class.std::__ccr1::basic_string"* %7 to %"struct.std::__ccr1::basic_string<char, std::__ccr1::char_traits<char>, std::__ccr1::allocator<char> >::__short"* ; [#uses=1 type=%"struct.std::__ccr1::basic_string<char, std::__ccr1::char_traits<char>, std::__ccr1::allocator<char> >::__short"*]
  %368 = getelementptr inbounds %"struct.std::__ccr1::basic_string<char, std::__ccr1::char_traits<char>, std::__ccr1::allocator<char> >::__short", %"struct.std::__ccr1::basic_string<char, std::__ccr1::char_traits<char>, std::__ccr1::allocator<char> >::__short"* %367, i32 0, i32 1, i32 0 ; [#uses=1 type=i8*]
  %369 = select i1 %364, i8* %368, i8* %366       ; [#uses=1 type=i8*]
  %370 = invoke double @"\01_strtod"(i8* %369, i8** null) #17
          to label %371 unwind label %380         ; [#uses=1 type=double]

; <label>:371:                                    ; preds = %361
  store double %370, double* @_ZL6NumVal, align 8, !tbaa !49
  %372 = load i8, i8* %344, align 4, !tbaa !4     ; [#uses=1 type=i8]
  %373 = and i8 %372, 1                           ; [#uses=1 type=i8]
  %374 = icmp eq i8 %373, 0                       ; [#uses=1 type=i1]
  br i1 %374, label %377, label %375

; <label>:375:                                    ; preds = %371
  %376 = load i8*, i8** %365, align 4, !tbaa !4   ; [#uses=1 type=i8*]
  call void @_ZdlPv(i8* %376) #15
  br label %377

; <label>:377:                                    ; preds = %371, %375
  call void @llvm.lifetime.end.p0i8(i64 12, i8* nonnull %344) #1
  br label %440

; <label>:378:                                    ; preds = %345
  %379 = landingpad { i8*, i32 }
          cleanup                                 ; [#uses=1 type={ i8*, i32 }]
  br label %382

; <label>:380:                                    ; preds = %361
  %381 = landingpad { i8*, i32 }
          cleanup                                 ; [#uses=1 type={ i8*, i32 }]
  br label %382

; <label>:382:                                    ; preds = %380, %378
  %383 = phi { i8*, i32 } [ %379, %378 ], [ %381, %380 ] ; [#uses=1 type={ i8*, i32 }]
  %384 = load i8, i8* %344, align 4, !tbaa !4     ; [#uses=1 type=i8]
  %385 = and i8 %384, 1                           ; [#uses=1 type=i8]
  %386 = icmp eq i8 %385, 0                       ; [#uses=1 type=i1]
  br i1 %386, label %390, label %387

; <label>:387:                                    ; preds = %382
  %388 = getelementptr inbounds %"class.std::__ccr1::basic_string", %"class.std::__ccr1::basic_string"* %7, i32 0, i32 0, i32 0, i32 0, i32 0, i32 0, i32 2 ; [#uses=1 type=i8**]
  %389 = load i8*, i8** %388, align 4, !tbaa !4   ; [#uses=1 type=i8*]
  call void @_ZdlPv(i8* %389) #15
  br label %390

; <label>:390:                                    ; preds = %382, %387
  call void @llvm.lifetime.end.p0i8(i64 12, i8* nonnull %344) #1
  resume { i8*, i32 } %383

; <label>:391:                                    ; preds = %339
  %392 = icmp eq i32 %146, 47                     ; [#uses=1 type=i1]
  br i1 %392, label %393, label %435

; <label>:393:                                    ; preds = %391
  %394 = call i32 @getchar() #17                  ; [#uses=1 type=i32]
  %395 = icmp eq i32 %394, 47                     ; [#uses=1 type=i1]
  br i1 %395, label %398, label %396

; <label>:396:                                    ; preds = %393
  %397 = load i32, i32* @_ZL8LastChar, align 4, !tbaa !13 ; [#uses=1 type=i32]
  br label %435

; <label>:398:                                    ; preds = %393
  %399 = call dereferenceable(84) %"class.std::__ccr1::basic_ostream"* @_ZNSt6__ccr124__put_character_sequenceIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m(%"class.std::__ccr1::basic_ostream"* nonnull dereferenceable(84) @_ZNSt6__ccr14cerrE, i8* getelementptr inbounds ([19 x i8], [19 x i8]* @.str.12, i32 0, i32 0), i32 18) #17 ; [#uses=4 type=%"class.std::__ccr1::basic_ostream"*]
  %400 = bitcast %"class.std::__ccr1::basic_ostream"* %399 to i8** ; [#uses=1 type=i8**]
  %401 = load i8*, i8** %400, align 4, !tbaa !15  ; [#uses=1 type=i8*]
  %402 = getelementptr i8, i8* %401, i32 -12      ; [#uses=1 type=i8*]
  %403 = bitcast i8* %402 to i32*                 ; [#uses=1 type=i32*]
  %404 = load i32, i32* %403, align 4             ; [#uses=1 type=i32]
  %405 = bitcast %"class.std::__ccr1::basic_ostream"* %399 to i8* ; [#uses=1 type=i8*]
  %406 = getelementptr inbounds i8, i8* %405, i32 %404 ; [#uses=1 type=i8*]
  %407 = bitcast %"class.std::__ccr1::locale"* %1 to i8* ; [#uses=3 type=i8*]
  call void @llvm.lifetime.start.p0i8(i64 4, i8* nonnull %407) #1
  %408 = bitcast i8* %406 to %"class.std::__ccr1::ios_base"* ; [#uses=1 type=%"class.std::__ccr1::ios_base"*]
  call void @_ZNKSt6__ccr18ios_base6getlocEv(%"class.std::__ccr1::locale"* nonnull sret %1, %"class.std::__ccr1::ios_base"* %408) #17
  %409 = invoke %"class.std::__ccr1::locale::facet"* @_ZNKSt6__ccr16locale9use_facetERNS0_2idE(%"class.std::__ccr1::locale"* nonnull %1, %"class.std::__ccr1::locale::id"* nonnull dereferenceable(8) @_ZNSt6__ccr15ctypeIcE2idE) #17
          to label %410 unwind label %417         ; [#uses=2 type=%"class.std::__ccr1::locale::facet"*]

; <label>:410:                                    ; preds = %398
  %411 = bitcast %"class.std::__ccr1::locale::facet"* %409 to %"class.std::__ccr1::ctype"* ; [#uses=1 type=%"class.std::__ccr1::ctype"*]
  %412 = bitcast %"class.std::__ccr1::locale::facet"* %409 to i8 (%"class.std::__ccr1::ctype"*, i8)*** ; [#uses=1 type=i8 (%"class.std::__ccr1::ctype"*, i8)***]
  %413 = load i8 (%"class.std::__ccr1::ctype"*, i8)**, i8 (%"class.std::__ccr1::ctype"*, i8)*** %412, align 4, !tbaa !15 ; [#uses=1 type=i8 (%"class.std::__ccr1::ctype"*, i8)**]
  %414 = getelementptr inbounds i8 (%"class.std::__ccr1::ctype"*, i8)*, i8 (%"class.std::__ccr1::ctype"*, i8)** %413, i32 7 ; [#uses=1 type=i8 (%"class.std::__ccr1::ctype"*, i8)**]
  %415 = load i8 (%"class.std::__ccr1::ctype"*, i8)*, i8 (%"class.std::__ccr1::ctype"*, i8)** %414, align 4 ; [#uses=1 type=i8 (%"class.std::__ccr1::ctype"*, i8)*]
  %416 = invoke signext i8 %415(%"class.std::__ccr1::ctype"* %411, i8 signext 10) #17
          to label %420 unwind label %417         ; [#uses=1 type=i8]

; <label>:417:                                    ; preds = %410, %398
  %418 = landingpad { i8*, i32 }
          cleanup                                 ; [#uses=1 type={ i8*, i32 }]
  %419 = call %"class.std::__ccr1::locale"* @_ZNSt6__ccr16localeD1Ev(%"class.std::__ccr1::locale"* nonnull %1) #16 ; [#uses=0 type=%"class.std::__ccr1::locale"*]
  call void @llvm.lifetime.end.p0i8(i64 4, i8* nonnull %407) #1
  resume { i8*, i32 } %418

; <label>:420:                                    ; preds = %410
  %421 = call %"class.std::__ccr1::locale"* @_ZNSt6__ccr16localeD1Ev(%"class.std::__ccr1::locale"* nonnull %1) #16 ; [#uses=0 type=%"class.std::__ccr1::locale"*]
  call void @llvm.lifetime.end.p0i8(i64 4, i8* nonnull %407) #1
  %422 = call dereferenceable(84) %"class.std::__ccr1::basic_ostream"* @_ZNSt6__ccr113basic_ostreamIcNS_11char_traitsIcEEE3putEc(%"class.std::__ccr1::basic_ostream"* nonnull %399, i8 signext %416) #17 ; [#uses=0 type=%"class.std::__ccr1::basic_ostream"*]
  %423 = call dereferenceable(84) %"class.std::__ccr1::basic_ostream"* @_ZNSt6__ccr113basic_ostreamIcNS_11char_traitsIcEEE5flushEv(%"class.std::__ccr1::basic_ostream"* nonnull %399) #17 ; [#uses=0 type=%"class.std::__ccr1::basic_ostream"*]
  %424 = load %struct.__sFILE*, %struct.__sFILE** @__stderrp, align 4, !tbaa !10 ; [#uses=1 type=%struct.__sFILE*]
  %425 = call i32 (%struct.__sFILE*, i8*, ...) @fprintf(%struct.__sFILE* %424, i8* getelementptr inbounds ([32 x i8], [32 x i8]* @.str.13, i32 0, i32 0), i8* getelementptr inbounds ([7 x i8], [7 x i8]* @__func__._ZL6gettokv, i32 0, i32 0), i32 115, i8* getelementptr inbounds ([148 x i8], [148 x i8]* @.str.4, i32 0, i32 0)) #17 ; [#uses=0 type=i32]
  br label %426

; <label>:426:                                    ; preds = %426, %420
  %427 = call i32 @getchar() #17                  ; [#uses=2 type=i32]
  store i32 %427, i32* @_ZL8LastChar, align 4, !tbaa !13
  switch i32 %427, label %426 [
    i32 -1, label %428
    i32 13, label %428
    i32 10, label %428
  ]

; <label>:428:                                    ; preds = %426, %426, %426
  %429 = load %struct.__sFILE*, %struct.__sFILE** @__stderrp, align 4, !tbaa !10 ; [#uses=1 type=%struct.__sFILE*]
  %430 = call i32 (%struct.__sFILE*, i8*, ...) @fprintf(%struct.__sFILE* %429, i8* getelementptr inbounds ([32 x i8], [32 x i8]* @.str.13, i32 0, i32 0), i8* getelementptr inbounds ([7 x i8], [7 x i8]* @__func__._ZL6gettokv, i32 0, i32 0), i32 119, i8* getelementptr inbounds ([148 x i8], [148 x i8]* @.str.4, i32 0, i32 0)) #17 ; [#uses=0 type=i32]
  %431 = load i32, i32* @_ZL8LastChar, align 4, !tbaa !13 ; [#uses=1 type=i32]
  %432 = icmp eq i32 %431, -1                     ; [#uses=1 type=i1]
  br i1 %432, label %440, label %433

; <label>:433:                                    ; preds = %428
  %434 = call fastcc i32 @_ZL6gettokv() #17       ; [#uses=1 type=i32]
  br label %440

; <label>:435:                                    ; preds = %396, %391
  %436 = phi i32 [ %397, %396 ], [ %146, %391 ]   ; [#uses=2 type=i32]
  %437 = icmp eq i32 %436, -1                     ; [#uses=1 type=i1]
  br i1 %437, label %440, label %438

; <label>:438:                                    ; preds = %435
  %439 = call i32 @getchar() #17                  ; [#uses=1 type=i32]
  store i32 %439, i32* @_ZL8LastChar, align 4, !tbaa !13
  br label %440

; <label>:440:                                    ; preds = %428, %281, %435, %293, %438, %433, %377, %328, %277, %221, %129
  %441 = phi i32 [ -6, %129 ], [ -2, %221 ], [ -3, %277 ], [ -1, %328 ], [ -5, %377 ], [ %434, %433 ], [ %436, %438 ], [ -4, %293 ], [ -1, %435 ], [ -4, %281 ], [ -1, %428 ] ; [#uses=1 type=i32]
  ret i32 %441
}

; [#uses=9]
; Function Attrs: nounwind optsize
declare i32 @getchar() local_unnamed_addr #3

; [#uses=2]
; Function Attrs: optsize
declare dereferenceable(12) %"class.std::__ccr1::basic_string"* @_ZNSt6__ccr112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEaSEc(%"class.std::__ccr1::basic_string"*, i8 signext) local_unnamed_addr #8

; [#uses=1]
; Function Attrs: optsize
declare double @"\01_strtod"(i8*, i8**) local_unnamed_addr #8

; [#uses=6]
; Function Attrs: optsize
declare void @_ZNSt6__ccr112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE9push_backEc(%"class.std::__ccr1::basic_string"*, i8 signext) local_unnamed_addr #8

; [#uses=23]
; Function Attrs: optsize
define linkonce_odr dereferenceable(84) %"class.std::__ccr1::basic_ostream"* @_ZNSt6__ccr124__put_character_sequenceIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m(%"class.std::__ccr1::basic_ostream"* dereferenceable(84), i8*, i32) local_unnamed_addr #7 personality i8* bitcast (i32 (...)* @__gxx_personality_sj0 to i8*) {
  %4 = alloca %"class.std::__ccr1::locale", align 4 ; [#uses=5 type=%"class.std::__ccr1::locale"*]
  %5 = alloca %"class.std::__ccr1::basic_ostream<char, std::__ccr1::char_traits<char> >::sentry", align 4 ; [#uses=4 type=%"class.std::__ccr1::basic_ostream<char, std::__ccr1::char_traits<char> >::sentry"*]
  %6 = getelementptr inbounds %"class.std::__ccr1::basic_ostream<char, std::__ccr1::char_traits<char> >::sentry", %"class.std::__ccr1::basic_ostream<char, std::__ccr1::char_traits<char> >::sentry"* %5, i32 0, i32 0 ; [#uses=5 type=i8*]
  call void @llvm.lifetime.start.p0i8(i64 8, i8* nonnull %6) #1
  store i8 0, i8* %6, align 4, !tbaa !51
  %7 = getelementptr inbounds %"class.std::__ccr1::basic_ostream<char, std::__ccr1::char_traits<char> >::sentry", %"class.std::__ccr1::basic_ostream<char, std::__ccr1::char_traits<char> >::sentry"* %5, i32 0, i32 1 ; [#uses=1 type=%"class.std::__ccr1::basic_ostream"**]
  store %"class.std::__ccr1::basic_ostream"* %0, %"class.std::__ccr1::basic_ostream"** %7, align 4, !tbaa !10
  %8 = bitcast %"class.std::__ccr1::basic_ostream"* %0 to i8** ; [#uses=4 type=i8**]
  %9 = load i8*, i8** %8, align 4, !tbaa !15      ; [#uses=1 type=i8*]
  %10 = getelementptr i8, i8* %9, i32 -12         ; [#uses=1 type=i8*]
  %11 = bitcast i8* %10 to i32*                   ; [#uses=2 type=i32*]
  %12 = load i32, i32* %11, align 4               ; [#uses=1 type=i32]
  %13 = bitcast %"class.std::__ccr1::basic_ostream"* %0 to i8* ; [#uses=4 type=i8*]
  %14 = getelementptr inbounds i8, i8* %13, i32 %12 ; [#uses=2 type=i8*]
  %15 = getelementptr inbounds i8, i8* %14, i32 16 ; [#uses=1 type=i8*]
  %16 = bitcast i8* %15 to i32*                   ; [#uses=1 type=i32*]
  %17 = load i32, i32* %16, align 4, !tbaa !53    ; [#uses=1 type=i32]
  %18 = icmp eq i32 %17, 0                        ; [#uses=1 type=i1]
  br i1 %18, label %19, label %91

; <label>:19:                                     ; preds = %3
  %20 = getelementptr inbounds i8, i8* %14, i32 72 ; [#uses=1 type=i8*]
  %21 = bitcast i8* %20 to %"class.std::__ccr1::basic_ostream"** ; [#uses=1 type=%"class.std::__ccr1::basic_ostream"**]
  %22 = load %"class.std::__ccr1::basic_ostream"*, %"class.std::__ccr1::basic_ostream"** %21, align 4, !tbaa !56 ; [#uses=2 type=%"class.std::__ccr1::basic_ostream"*]
  %23 = icmp eq %"class.std::__ccr1::basic_ostream"* %22, null ; [#uses=1 type=i1]
  br i1 %23, label %30, label %24

; <label>:24:                                     ; preds = %19
  %25 = invoke dereferenceable(84) %"class.std::__ccr1::basic_ostream"* @_ZNSt6__ccr113basic_ostreamIcNS_11char_traitsIcEEE5flushEv(%"class.std::__ccr1::basic_ostream"* nonnull %22) #17
          to label %26 unwind label %84           ; [#uses=0 type=%"class.std::__ccr1::basic_ostream"*]

; <label>:26:                                     ; preds = %24
  %27 = load i8*, i8** %8, align 4, !tbaa !15     ; [#uses=1 type=i8*]
  %28 = getelementptr i8, i8* %27, i32 -12        ; [#uses=1 type=i8*]
  %29 = bitcast i8* %28 to i32*                   ; [#uses=1 type=i32*]
  br label %30

; <label>:30:                                     ; preds = %19, %26
  %31 = phi i32* [ %29, %26 ], [ %11, %19 ]       ; [#uses=1 type=i32*]
  store i8 1, i8* %6, align 4, !tbaa !51
  %32 = load i32, i32* %31, align 4               ; [#uses=1 type=i32]
  %33 = getelementptr inbounds i8, i8* %13, i32 %32 ; [#uses=4 type=i8*]
  %34 = getelementptr inbounds i8, i8* %33, i32 24 ; [#uses=1 type=i8*]
  %35 = bitcast i8* %34 to i32*                   ; [#uses=1 type=i32*]
  %36 = load i32, i32* %35, align 4, !tbaa !58    ; [#uses=1 type=i32]
  %37 = getelementptr inbounds i8, i8* %33, i32 4 ; [#uses=1 type=i8*]
  %38 = bitcast i8* %37 to i32*                   ; [#uses=1 type=i32*]
  %39 = load i32, i32* %38, align 4, !tbaa !59    ; [#uses=1 type=i32]
  %40 = getelementptr inbounds i8, i8* %33, i32 76 ; [#uses=1 type=i8*]
  %41 = bitcast i8* %40 to i32*                   ; [#uses=2 type=i32*]
  %42 = load i32, i32* %41, align 4, !tbaa !60    ; [#uses=2 type=i32]
  %43 = and i32 %39, 176                          ; [#uses=1 type=i32]
  %44 = bitcast i8* %33 to %"class.std::__ccr1::ios_base"* ; [#uses=2 type=%"class.std::__ccr1::ios_base"*]
  %45 = getelementptr inbounds i8, i8* %1, i32 %2 ; [#uses=2 type=i8*]
  %46 = icmp eq i32 %42, -1                       ; [#uses=1 type=i1]
  br i1 %46, label %47, label %64

; <label>:47:                                     ; preds = %30
  %48 = bitcast %"class.std::__ccr1::locale"* %4 to i8* ; [#uses=3 type=i8*]
  call void @llvm.lifetime.start.p0i8(i64 4, i8* nonnull %48) #1
  invoke void @_ZNKSt6__ccr18ios_base6getlocEv(%"class.std::__ccr1::locale"* nonnull sret %4, %"class.std::__ccr1::ios_base"* %44) #17
          to label %49 unwind label %89

; <label>:49:                                     ; preds = %47
  %50 = invoke %"class.std::__ccr1::locale::facet"* @_ZNKSt6__ccr16locale9use_facetERNS0_2idE(%"class.std::__ccr1::locale"* nonnull %4, %"class.std::__ccr1::locale::id"* nonnull dereferenceable(8) @_ZNSt6__ccr15ctypeIcE2idE) #17
          to label %51 unwind label %58           ; [#uses=2 type=%"class.std::__ccr1::locale::facet"*]

; <label>:51:                                     ; preds = %49
  %52 = bitcast %"class.std::__ccr1::locale::facet"* %50 to %"class.std::__ccr1::ctype"* ; [#uses=1 type=%"class.std::__ccr1::ctype"*]
  %53 = bitcast %"class.std::__ccr1::locale::facet"* %50 to i8 (%"class.std::__ccr1::ctype"*, i8)*** ; [#uses=1 type=i8 (%"class.std::__ccr1::ctype"*, i8)***]
  %54 = load i8 (%"class.std::__ccr1::ctype"*, i8)**, i8 (%"class.std::__ccr1::ctype"*, i8)*** %53, align 4, !tbaa !15 ; [#uses=1 type=i8 (%"class.std::__ccr1::ctype"*, i8)**]
  %55 = getelementptr inbounds i8 (%"class.std::__ccr1::ctype"*, i8)*, i8 (%"class.std::__ccr1::ctype"*, i8)** %54, i32 7 ; [#uses=1 type=i8 (%"class.std::__ccr1::ctype"*, i8)**]
  %56 = load i8 (%"class.std::__ccr1::ctype"*, i8)*, i8 (%"class.std::__ccr1::ctype"*, i8)** %55, align 4 ; [#uses=1 type=i8 (%"class.std::__ccr1::ctype"*, i8)*]
  %57 = invoke signext i8 %56(%"class.std::__ccr1::ctype"* %52, i8 signext 32) #17
          to label %61 unwind label %58           ; [#uses=1 type=i8]

; <label>:58:                                     ; preds = %51, %49
  %59 = landingpad { i8*, i32 }
          catch i8* null                          ; [#uses=1 type={ i8*, i32 }]
  %60 = call %"class.std::__ccr1::locale"* @_ZNSt6__ccr16localeD1Ev(%"class.std::__ccr1::locale"* nonnull %4) #16 ; [#uses=0 type=%"class.std::__ccr1::locale"*]
  call void @llvm.lifetime.end.p0i8(i64 4, i8* nonnull %48) #1
  br label %93

; <label>:61:                                     ; preds = %51
  %62 = call %"class.std::__ccr1::locale"* @_ZNSt6__ccr16localeD1Ev(%"class.std::__ccr1::locale"* nonnull %4) #16 ; [#uses=0 type=%"class.std::__ccr1::locale"*]
  call void @llvm.lifetime.end.p0i8(i64 4, i8* nonnull %48) #1
  %63 = sext i8 %57 to i32                        ; [#uses=2 type=i32]
  store i32 %63, i32* %41, align 4, !tbaa !60
  br label %64

; <label>:64:                                     ; preds = %61, %30
  %65 = phi i32 [ %63, %61 ], [ %42, %30 ]        ; [#uses=1 type=i32]
  %66 = trunc i32 %65 to i8                       ; [#uses=1 type=i8]
  %67 = icmp eq i32 %43, 32                       ; [#uses=1 type=i1]
  %68 = select i1 %67, i8* %45, i8* %1            ; [#uses=1 type=i8*]
  %69 = insertvalue [1 x i32] undef, i32 %36, 0   ; [#uses=1 type=[1 x i32]]
  %70 = invoke i32 @_ZNSt6__ccr116__pad_and_outputIcNS_19ostreambuf_iteratorIcNS_11char_traitsIcEEEEEET0_S5_PKT_S8_S8_RNS_8ios_baseES6_([1 x i32] %69, i8* %1, i8* %68, i8* %45, %"class.std::__ccr1::ios_base"* dereferenceable(72) %44, i8 signext %66) #17
          to label %71 unwind label %89           ; [#uses=1 type=i32]

; <label>:71:                                     ; preds = %64
  %72 = icmp eq i32 %70, 0                        ; [#uses=1 type=i1]
  br i1 %72, label %73, label %91

; <label>:73:                                     ; preds = %71
  %74 = load i8*, i8** %8, align 4, !tbaa !15     ; [#uses=1 type=i8*]
  %75 = getelementptr i8, i8* %74, i32 -12        ; [#uses=1 type=i8*]
  %76 = bitcast i8* %75 to i32*                   ; [#uses=1 type=i32*]
  %77 = load i32, i32* %76, align 4               ; [#uses=1 type=i32]
  %78 = getelementptr inbounds i8, i8* %13, i32 %77 ; [#uses=2 type=i8*]
  %79 = bitcast i8* %78 to %"class.std::__ccr1::ios_base"* ; [#uses=1 type=%"class.std::__ccr1::ios_base"*]
  %80 = getelementptr inbounds i8, i8* %78, i32 16 ; [#uses=1 type=i8*]
  %81 = bitcast i8* %80 to i32*                   ; [#uses=1 type=i32*]
  %82 = load i32, i32* %81, align 4, !tbaa !53    ; [#uses=1 type=i32]
  %83 = or i32 %82, 5                             ; [#uses=1 type=i32]
  invoke void @_ZNSt6__ccr18ios_base5clearEj(%"class.std::__ccr1::ios_base"* %79, i32 %83) #17
          to label %91 unwind label %87

; <label>:84:                                     ; preds = %24
  %85 = landingpad { i8*, i32 }
          catch i8* null                          ; [#uses=1 type={ i8*, i32 }]
  %86 = extractvalue { i8*, i32 } %85, 0          ; [#uses=1 type=i8*]
  br label %97

; <label>:87:                                     ; preds = %73
  %88 = landingpad { i8*, i32 }
          catch i8* null                          ; [#uses=1 type={ i8*, i32 }]
  br label %93

; <label>:89:                                     ; preds = %47, %64
  %90 = landingpad { i8*, i32 }
          catch i8* null                          ; [#uses=1 type={ i8*, i32 }]
  br label %93

; <label>:91:                                     ; preds = %3, %73, %71
  %92 = call %"class.std::__ccr1::basic_ostream<char, std::__ccr1::char_traits<char> >::sentry"* @_ZNSt6__ccr113basic_ostreamIcNS_11char_traitsIcEEE6sentryD2Ev(%"class.std::__ccr1::basic_ostream<char, std::__ccr1::char_traits<char> >::sentry"* nonnull %5) #16 ; [#uses=0 type=%"class.std::__ccr1::basic_ostream<char, std::__ccr1::char_traits<char> >::sentry"*]
  call void @llvm.lifetime.end.p0i8(i64 8, i8* nonnull %6) #1
  br label %107

; <label>:93:                                     ; preds = %89, %58, %87
  %94 = phi { i8*, i32 } [ %88, %87 ], [ %90, %89 ], [ %59, %58 ] ; [#uses=1 type={ i8*, i32 }]
  %95 = extractvalue { i8*, i32 } %94, 0          ; [#uses=1 type=i8*]
  %96 = call %"class.std::__ccr1::basic_ostream<char, std::__ccr1::char_traits<char> >::sentry"* @_ZNSt6__ccr113basic_ostreamIcNS_11char_traitsIcEEE6sentryD2Ev(%"class.std::__ccr1::basic_ostream<char, std::__ccr1::char_traits<char> >::sentry"* nonnull %5) #16 ; [#uses=0 type=%"class.std::__ccr1::basic_ostream<char, std::__ccr1::char_traits<char> >::sentry"*]
  br label %97

; <label>:97:                                     ; preds = %93, %84
  %98 = phi i8* [ %95, %93 ], [ %86, %84 ]        ; [#uses=1 type=i8*]
  call void @llvm.lifetime.end.p0i8(i64 8, i8* nonnull %6) #1
  %99 = call i8* @__cxa_begin_catch(i8* %98) #1   ; [#uses=0 type=i8*]
  %100 = load i8*, i8** %8, align 4, !tbaa !15    ; [#uses=1 type=i8*]
  %101 = getelementptr i8, i8* %100, i32 -12      ; [#uses=1 type=i8*]
  %102 = bitcast i8* %101 to i32*                 ; [#uses=1 type=i32*]
  %103 = load i32, i32* %102, align 4             ; [#uses=1 type=i32]
  %104 = getelementptr inbounds i8, i8* %13, i32 %103 ; [#uses=1 type=i8*]
  %105 = bitcast i8* %104 to %"class.std::__ccr1::ios_base"* ; [#uses=1 type=%"class.std::__ccr1::ios_base"*]
  invoke void @_ZNSt6__ccr18ios_base33__set_badbit_and_consider_rethrowEv(%"class.std::__ccr1::ios_base"* %105) #17
          to label %106 unwind label %108

; <label>:106:                                    ; preds = %97
  call void @__cxa_end_catch()
  br label %107

; <label>:107:                                    ; preds = %106, %91
  ret %"class.std::__ccr1::basic_ostream"* %0

; <label>:108:                                    ; preds = %97
  %109 = landingpad { i8*, i32 }
          cleanup                                 ; [#uses=1 type={ i8*, i32 }]
  invoke void @__cxa_end_catch()
          to label %110 unwind label %111

; <label>:110:                                    ; preds = %108
  resume { i8*, i32 } %109

; <label>:111:                                    ; preds = %108
  %112 = landingpad { i8*, i32 }
          catch i8* null                          ; [#uses=1 type={ i8*, i32 }]
  %113 = extractvalue { i8*, i32 } %112, 0        ; [#uses=1 type=i8*]
  call void @__clang_call_terminate(i8* %113) #19
  unreachable
}

; [#uses=1]
; Function Attrs: optsize
define linkonce_odr hidden i32 @_ZNSt6__ccr116__pad_and_outputIcNS_19ostreambuf_iteratorIcNS_11char_traitsIcEEEEEET0_S5_PKT_S8_S8_RNS_8ios_baseES6_([1 x i32], i8*, i8*, i8*, %"class.std::__ccr1::ios_base"* dereferenceable(72), i8 signext) local_unnamed_addr #7 {
  %7 = extractvalue [1 x i32] %0, 0               ; [#uses=2 type=i32]
  %8 = ptrtoint i8* %3 to i32                     ; [#uses=1 type=i32]
  %9 = ptrtoint i8* %1 to i32                     ; [#uses=1 type=i32]
  %10 = sub i32 %8, %9                            ; [#uses=2 type=i32]
  %11 = getelementptr inbounds %"class.std::__ccr1::ios_base", %"class.std::__ccr1::ios_base"* %4, i32 0, i32 3 ; [#uses=2 type=i32*]
  %12 = load i32, i32* %11, align 4, !tbaa !61    ; [#uses=2 type=i32]
  %13 = icmp sle i32 %12, %10                     ; [#uses=1 type=i1]
  %14 = sub nsw i32 %12, %10                      ; [#uses=2 type=i32]
  %15 = icmp ult i8* %1, %2                       ; [#uses=1 type=i1]
  br i1 %15, label %16, label %44

; <label>:16:                                     ; preds = %6
  br label %17

; <label>:17:                                     ; preds = %16, %40
  %18 = phi i8* [ %42, %40 ], [ %1, %16 ]         ; [#uses=2 type=i8*]
  %19 = phi i32 [ %41, %40 ], [ %7, %16 ]         ; [#uses=5 type=i32]
  %20 = load i8, i8* %18, align 1, !tbaa !4       ; [#uses=2 type=i8]
  %21 = inttoptr i32 %19 to %"class.std::__ccr1::basic_streambuf"* ; [#uses=3 type=%"class.std::__ccr1::basic_streambuf"*]
  %22 = icmp eq i32 %19, 0                        ; [#uses=1 type=i1]
  br i1 %22, label %40, label %23

; <label>:23:                                     ; preds = %17
  %24 = getelementptr inbounds %"class.std::__ccr1::basic_streambuf", %"class.std::__ccr1::basic_streambuf"* %21, i32 0, i32 6 ; [#uses=2 type=i8**]
  %25 = load i8*, i8** %24, align 4, !tbaa !62    ; [#uses=3 type=i8*]
  %26 = getelementptr inbounds %"class.std::__ccr1::basic_streambuf", %"class.std::__ccr1::basic_streambuf"* %21, i32 0, i32 7 ; [#uses=1 type=i8**]
  %27 = load i8*, i8** %26, align 4, !tbaa !65    ; [#uses=1 type=i8*]
  %28 = icmp eq i8* %25, %27                      ; [#uses=1 type=i1]
  br i1 %28, label %31, label %29

; <label>:29:                                     ; preds = %23
  %30 = getelementptr inbounds i8, i8* %25, i32 1 ; [#uses=1 type=i8*]
  store i8* %30, i8** %24, align 4, !tbaa !62
  store i8 %20, i8* %25, align 1, !tbaa !4
  br label %40

; <label>:31:                                     ; preds = %23
  %32 = inttoptr i32 %19 to i32 (%"class.std::__ccr1::basic_streambuf"*, i32)*** ; [#uses=1 type=i32 (%"class.std::__ccr1::basic_streambuf"*, i32)***]
  %33 = load i32 (%"class.std::__ccr1::basic_streambuf"*, i32)**, i32 (%"class.std::__ccr1::basic_streambuf"*, i32)*** %32, align 4, !tbaa !15 ; [#uses=1 type=i32 (%"class.std::__ccr1::basic_streambuf"*, i32)**]
  %34 = getelementptr inbounds i32 (%"class.std::__ccr1::basic_streambuf"*, i32)*, i32 (%"class.std::__ccr1::basic_streambuf"*, i32)** %33, i32 13 ; [#uses=1 type=i32 (%"class.std::__ccr1::basic_streambuf"*, i32)**]
  %35 = load i32 (%"class.std::__ccr1::basic_streambuf"*, i32)*, i32 (%"class.std::__ccr1::basic_streambuf"*, i32)** %34, align 4 ; [#uses=1 type=i32 (%"class.std::__ccr1::basic_streambuf"*, i32)*]
  %36 = zext i8 %20 to i32                        ; [#uses=1 type=i32]
  %37 = tail call i32 %35(%"class.std::__ccr1::basic_streambuf"* nonnull %21, i32 %36) #17 ; [#uses=1 type=i32]
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
  %58 = load i8*, i8** %57, align 4, !tbaa !62    ; [#uses=3 type=i8*]
  %59 = getelementptr inbounds %"class.std::__ccr1::basic_streambuf", %"class.std::__ccr1::basic_streambuf"* %54, i32 0, i32 7 ; [#uses=1 type=i8**]
  %60 = load i8*, i8** %59, align 4, !tbaa !65    ; [#uses=1 type=i8*]
  %61 = icmp eq i8* %58, %60                      ; [#uses=1 type=i1]
  br i1 %61, label %64, label %62

; <label>:62:                                     ; preds = %56
  %63 = getelementptr inbounds i8, i8* %58, i32 1 ; [#uses=1 type=i8*]
  store i8* %63, i8** %57, align 4, !tbaa !62
  store i8 %5, i8* %58, align 1, !tbaa !4
  br label %72

; <label>:64:                                     ; preds = %56
  %65 = inttoptr i32 %53 to i32 (%"class.std::__ccr1::basic_streambuf"*, i32)*** ; [#uses=1 type=i32 (%"class.std::__ccr1::basic_streambuf"*, i32)***]
  %66 = load i32 (%"class.std::__ccr1::basic_streambuf"*, i32)**, i32 (%"class.std::__ccr1::basic_streambuf"*, i32)*** %65, align 4, !tbaa !15 ; [#uses=1 type=i32 (%"class.std::__ccr1::basic_streambuf"*, i32)**]
  %67 = getelementptr inbounds i32 (%"class.std::__ccr1::basic_streambuf"*, i32)*, i32 (%"class.std::__ccr1::basic_streambuf"*, i32)** %66, i32 13 ; [#uses=1 type=i32 (%"class.std::__ccr1::basic_streambuf"*, i32)**]
  %68 = load i32 (%"class.std::__ccr1::basic_streambuf"*, i32)*, i32 (%"class.std::__ccr1::basic_streambuf"*, i32)** %67, align 4 ; [#uses=1 type=i32 (%"class.std::__ccr1::basic_streambuf"*, i32)*]
  %69 = tail call i32 %68(%"class.std::__ccr1::basic_streambuf"* nonnull %54, i32 %50) #17 ; [#uses=1 type=i32]
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
  %83 = load i8, i8* %81, align 1, !tbaa !4       ; [#uses=2 type=i8]
  %84 = inttoptr i32 %82 to %"class.std::__ccr1::basic_streambuf"* ; [#uses=3 type=%"class.std::__ccr1::basic_streambuf"*]
  %85 = icmp eq i32 %82, 0                        ; [#uses=1 type=i1]
  br i1 %85, label %103, label %86

; <label>:86:                                     ; preds = %80
  %87 = getelementptr inbounds %"class.std::__ccr1::basic_streambuf", %"class.std::__ccr1::basic_streambuf"* %84, i32 0, i32 6 ; [#uses=2 type=i8**]
  %88 = load i8*, i8** %87, align 4, !tbaa !62    ; [#uses=3 type=i8*]
  %89 = getelementptr inbounds %"class.std::__ccr1::basic_streambuf", %"class.std::__ccr1::basic_streambuf"* %84, i32 0, i32 7 ; [#uses=1 type=i8**]
  %90 = load i8*, i8** %89, align 4, !tbaa !65    ; [#uses=1 type=i8*]
  %91 = icmp eq i8* %88, %90                      ; [#uses=1 type=i1]
  br i1 %91, label %94, label %92

; <label>:92:                                     ; preds = %86
  %93 = getelementptr inbounds i8, i8* %88, i32 1 ; [#uses=1 type=i8*]
  store i8* %93, i8** %87, align 4, !tbaa !62
  store i8 %83, i8* %88, align 1, !tbaa !4
  br label %103

; <label>:94:                                     ; preds = %86
  %95 = inttoptr i32 %82 to i32 (%"class.std::__ccr1::basic_streambuf"*, i32)*** ; [#uses=1 type=i32 (%"class.std::__ccr1::basic_streambuf"*, i32)***]
  %96 = load i32 (%"class.std::__ccr1::basic_streambuf"*, i32)**, i32 (%"class.std::__ccr1::basic_streambuf"*, i32)*** %95, align 4, !tbaa !15 ; [#uses=1 type=i32 (%"class.std::__ccr1::basic_streambuf"*, i32)**]
  %97 = getelementptr inbounds i32 (%"class.std::__ccr1::basic_streambuf"*, i32)*, i32 (%"class.std::__ccr1::basic_streambuf"*, i32)** %96, i32 13 ; [#uses=1 type=i32 (%"class.std::__ccr1::basic_streambuf"*, i32)**]
  %98 = load i32 (%"class.std::__ccr1::basic_streambuf"*, i32)*, i32 (%"class.std::__ccr1::basic_streambuf"*, i32)** %97, align 4 ; [#uses=1 type=i32 (%"class.std::__ccr1::basic_streambuf"*, i32)*]
  %99 = zext i8 %83 to i32                        ; [#uses=1 type=i32]
  %100 = tail call i32 %98(%"class.std::__ccr1::basic_streambuf"* nonnull %84, i32 %99) #17 ; [#uses=1 type=i32]
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
  store i32 0, i32* %11, align 4, !tbaa !61
  ret i32 %108
}

; [#uses=3]
; Function Attrs: optsize
declare void @_ZNSt6__ccr18ios_base33__set_badbit_and_consider_rethrowEv(%"class.std::__ccr1::ios_base"*) local_unnamed_addr #8

; [#uses=7]
declare void @__cxa_end_catch() local_unnamed_addr

; [#uses=1]
; Function Attrs: optsize
define linkonce_odr %"class.std::__ccr1::basic_ostream<char, std::__ccr1::char_traits<char> >::sentry"* @_ZNSt6__ccr113basic_ostreamIcNS_11char_traitsIcEEE6sentryC2ERS3_(%"class.std::__ccr1::basic_ostream<char, std::__ccr1::char_traits<char> >::sentry"* returned, %"class.std::__ccr1::basic_ostream"* dereferenceable(84)) unnamed_addr #7 align 2 {
  %3 = getelementptr inbounds %"class.std::__ccr1::basic_ostream<char, std::__ccr1::char_traits<char> >::sentry", %"class.std::__ccr1::basic_ostream<char, std::__ccr1::char_traits<char> >::sentry"* %0, i32 0, i32 0 ; [#uses=2 type=i8*]
  store i8 0, i8* %3, align 4, !tbaa !51
  %4 = getelementptr inbounds %"class.std::__ccr1::basic_ostream<char, std::__ccr1::char_traits<char> >::sentry", %"class.std::__ccr1::basic_ostream<char, std::__ccr1::char_traits<char> >::sentry"* %0, i32 0, i32 1 ; [#uses=1 type=%"class.std::__ccr1::basic_ostream"**]
  store %"class.std::__ccr1::basic_ostream"* %1, %"class.std::__ccr1::basic_ostream"** %4, align 4, !tbaa !10
  %5 = bitcast %"class.std::__ccr1::basic_ostream"* %1 to i8** ; [#uses=1 type=i8**]
  %6 = load i8*, i8** %5, align 4, !tbaa !15      ; [#uses=1 type=i8*]
  %7 = getelementptr i8, i8* %6, i32 -12          ; [#uses=1 type=i8*]
  %8 = bitcast i8* %7 to i32*                     ; [#uses=1 type=i32*]
  %9 = load i32, i32* %8, align 4                 ; [#uses=1 type=i32]
  %10 = bitcast %"class.std::__ccr1::basic_ostream"* %1 to i8* ; [#uses=1 type=i8*]
  %11 = getelementptr inbounds i8, i8* %10, i32 %9 ; [#uses=2 type=i8*]
  %12 = getelementptr inbounds i8, i8* %11, i32 16 ; [#uses=1 type=i8*]
  %13 = bitcast i8* %12 to i32*                   ; [#uses=1 type=i32*]
  %14 = load i32, i32* %13, align 4, !tbaa !53    ; [#uses=1 type=i32]
  %15 = icmp eq i32 %14, 0                        ; [#uses=1 type=i1]
  br i1 %15, label %16, label %24

; <label>:16:                                     ; preds = %2
  %17 = getelementptr inbounds i8, i8* %11, i32 72 ; [#uses=1 type=i8*]
  %18 = bitcast i8* %17 to %"class.std::__ccr1::basic_ostream"** ; [#uses=1 type=%"class.std::__ccr1::basic_ostream"**]
  %19 = load %"class.std::__ccr1::basic_ostream"*, %"class.std::__ccr1::basic_ostream"** %18, align 4, !tbaa !56 ; [#uses=2 type=%"class.std::__ccr1::basic_ostream"*]
  %20 = icmp eq %"class.std::__ccr1::basic_ostream"* %19, null ; [#uses=1 type=i1]
  br i1 %20, label %23, label %21

; <label>:21:                                     ; preds = %16
  %22 = tail call dereferenceable(84) %"class.std::__ccr1::basic_ostream"* @_ZNSt6__ccr113basic_ostreamIcNS_11char_traitsIcEEE5flushEv(%"class.std::__ccr1::basic_ostream"* nonnull %19) #17 ; [#uses=0 type=%"class.std::__ccr1::basic_ostream"*]
  br label %23

; <label>:23:                                     ; preds = %16, %21
  store i8 1, i8* %3, align 4, !tbaa !51
  br label %24

; <label>:24:                                     ; preds = %23, %2
  ret %"class.std::__ccr1::basic_ostream<char, std::__ccr1::char_traits<char> >::sentry"* %0
}

; [#uses=17]
; Function Attrs: optsize
define linkonce_odr dereferenceable(84) %"class.std::__ccr1::basic_ostream"* @_ZNSt6__ccr113basic_ostreamIcNS_11char_traitsIcEEE5flushEv(%"class.std::__ccr1::basic_ostream"*) local_unnamed_addr #7 align 2 personality i8* bitcast (i32 (...)* @__gxx_personality_sj0 to i8*) {
  %2 = alloca %"class.std::__ccr1::basic_ostream<char, std::__ccr1::char_traits<char> >::sentry", align 4 ; [#uses=4 type=%"class.std::__ccr1::basic_ostream<char, std::__ccr1::char_traits<char> >::sentry"*]
  %3 = bitcast %"class.std::__ccr1::basic_ostream"* %0 to i8** ; [#uses=4 type=i8**]
  %4 = load i8*, i8** %3, align 4, !tbaa !15      ; [#uses=1 type=i8*]
  %5 = getelementptr i8, i8* %4, i32 -12          ; [#uses=1 type=i8*]
  %6 = bitcast i8* %5 to i32*                     ; [#uses=1 type=i32*]
  %7 = load i32, i32* %6, align 4                 ; [#uses=1 type=i32]
  %8 = bitcast %"class.std::__ccr1::basic_ostream"* %0 to i8* ; [#uses=4 type=i8*]
  %9 = getelementptr inbounds i8, i8* %8, i32 %7  ; [#uses=1 type=i8*]
  %10 = getelementptr inbounds i8, i8* %9, i32 24 ; [#uses=1 type=i8*]
  %11 = bitcast i8* %10 to %"class.std::__ccr1::basic_streambuf"** ; [#uses=1 type=%"class.std::__ccr1::basic_streambuf"**]
  %12 = load %"class.std::__ccr1::basic_streambuf"*, %"class.std::__ccr1::basic_streambuf"** %11, align 4, !tbaa !58 ; [#uses=1 type=%"class.std::__ccr1::basic_streambuf"*]
  %13 = icmp eq %"class.std::__ccr1::basic_streambuf"* %12, null ; [#uses=1 type=i1]
  br i1 %13, label %66, label %14

; <label>:14:                                     ; preds = %1
  %15 = getelementptr inbounds %"class.std::__ccr1::basic_ostream<char, std::__ccr1::char_traits<char> >::sentry", %"class.std::__ccr1::basic_ostream<char, std::__ccr1::char_traits<char> >::sentry"* %2, i32 0, i32 0 ; [#uses=4 type=i8*]
  call void @llvm.lifetime.start.p0i8(i64 8, i8* nonnull %15) #1
  %16 = invoke %"class.std::__ccr1::basic_ostream<char, std::__ccr1::char_traits<char> >::sentry"* @_ZNSt6__ccr113basic_ostreamIcNS_11char_traitsIcEEE6sentryC2ERS3_(%"class.std::__ccr1::basic_ostream<char, std::__ccr1::char_traits<char> >::sentry"* nonnull %2, %"class.std::__ccr1::basic_ostream"* nonnull dereferenceable(84) %0) #17
          to label %17 unwind label %47           ; [#uses=0 type=%"class.std::__ccr1::basic_ostream<char, std::__ccr1::char_traits<char> >::sentry"*]

; <label>:17:                                     ; preds = %14
  %18 = load i8, i8* %15, align 4, !tbaa !51, !range !66 ; [#uses=1 type=i8]
  %19 = icmp eq i8 %18, 0                         ; [#uses=1 type=i1]
  br i1 %19, label %54, label %20

; <label>:20:                                     ; preds = %17
  %21 = load i8*, i8** %3, align 4, !tbaa !15     ; [#uses=1 type=i8*]
  %22 = getelementptr i8, i8* %21, i32 -12        ; [#uses=1 type=i8*]
  %23 = bitcast i8* %22 to i32*                   ; [#uses=1 type=i32*]
  %24 = load i32, i32* %23, align 4               ; [#uses=1 type=i32]
  %25 = getelementptr inbounds i8, i8* %8, i32 %24 ; [#uses=1 type=i8*]
  %26 = getelementptr inbounds i8, i8* %25, i32 24 ; [#uses=1 type=i8*]
  %27 = bitcast i8* %26 to %"class.std::__ccr1::basic_streambuf"** ; [#uses=1 type=%"class.std::__ccr1::basic_streambuf"**]
  %28 = load %"class.std::__ccr1::basic_streambuf"*, %"class.std::__ccr1::basic_streambuf"** %27, align 4, !tbaa !58 ; [#uses=2 type=%"class.std::__ccr1::basic_streambuf"*]
  %29 = bitcast %"class.std::__ccr1::basic_streambuf"* %28 to i32 (%"class.std::__ccr1::basic_streambuf"*)*** ; [#uses=1 type=i32 (%"class.std::__ccr1::basic_streambuf"*)***]
  %30 = load i32 (%"class.std::__ccr1::basic_streambuf"*)**, i32 (%"class.std::__ccr1::basic_streambuf"*)*** %29, align 4, !tbaa !15 ; [#uses=1 type=i32 (%"class.std::__ccr1::basic_streambuf"*)**]
  %31 = getelementptr inbounds i32 (%"class.std::__ccr1::basic_streambuf"*)*, i32 (%"class.std::__ccr1::basic_streambuf"*)** %30, i32 6 ; [#uses=1 type=i32 (%"class.std::__ccr1::basic_streambuf"*)**]
  %32 = load i32 (%"class.std::__ccr1::basic_streambuf"*)*, i32 (%"class.std::__ccr1::basic_streambuf"*)** %31, align 4 ; [#uses=1 type=i32 (%"class.std::__ccr1::basic_streambuf"*)*]
  %33 = invoke i32 %32(%"class.std::__ccr1::basic_streambuf"* %28) #17
          to label %34 unwind label %50           ; [#uses=1 type=i32]

; <label>:34:                                     ; preds = %20
  %35 = icmp eq i32 %33, -1                       ; [#uses=1 type=i1]
  br i1 %35, label %36, label %54

; <label>:36:                                     ; preds = %34
  %37 = load i8*, i8** %3, align 4, !tbaa !15     ; [#uses=1 type=i8*]
  %38 = getelementptr i8, i8* %37, i32 -12        ; [#uses=1 type=i8*]
  %39 = bitcast i8* %38 to i32*                   ; [#uses=1 type=i32*]
  %40 = load i32, i32* %39, align 4               ; [#uses=1 type=i32]
  %41 = getelementptr inbounds i8, i8* %8, i32 %40 ; [#uses=2 type=i8*]
  %42 = bitcast i8* %41 to %"class.std::__ccr1::ios_base"* ; [#uses=1 type=%"class.std::__ccr1::ios_base"*]
  %43 = getelementptr inbounds i8, i8* %41, i32 16 ; [#uses=1 type=i8*]
  %44 = bitcast i8* %43 to i32*                   ; [#uses=1 type=i32*]
  %45 = load i32, i32* %44, align 4, !tbaa !53    ; [#uses=1 type=i32]
  %46 = or i32 %45, 1                             ; [#uses=1 type=i32]
  invoke void @_ZNSt6__ccr18ios_base5clearEj(%"class.std::__ccr1::ios_base"* %42, i32 %46) #17
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
  %53 = call %"class.std::__ccr1::basic_ostream<char, std::__ccr1::char_traits<char> >::sentry"* @_ZNSt6__ccr113basic_ostreamIcNS_11char_traitsIcEEE6sentryD2Ev(%"class.std::__ccr1::basic_ostream<char, std::__ccr1::char_traits<char> >::sentry"* nonnull %2) #16 ; [#uses=0 type=%"class.std::__ccr1::basic_ostream<char, std::__ccr1::char_traits<char> >::sentry"*]
  br label %56

; <label>:54:                                     ; preds = %17, %36, %34
  %55 = call %"class.std::__ccr1::basic_ostream<char, std::__ccr1::char_traits<char> >::sentry"* @_ZNSt6__ccr113basic_ostreamIcNS_11char_traitsIcEEE6sentryD2Ev(%"class.std::__ccr1::basic_ostream<char, std::__ccr1::char_traits<char> >::sentry"* nonnull %2) #16 ; [#uses=0 type=%"class.std::__ccr1::basic_ostream<char, std::__ccr1::char_traits<char> >::sentry"*]
  call void @llvm.lifetime.end.p0i8(i64 8, i8* nonnull %15) #1
  br label %66

; <label>:56:                                     ; preds = %47, %50
  %57 = phi i8* [ %52, %50 ], [ %49, %47 ]        ; [#uses=1 type=i8*]
  call void @llvm.lifetime.end.p0i8(i64 8, i8* nonnull %15) #1
  %58 = call i8* @__cxa_begin_catch(i8* %57) #1   ; [#uses=0 type=i8*]
  %59 = load i8*, i8** %3, align 4, !tbaa !15     ; [#uses=1 type=i8*]
  %60 = getelementptr i8, i8* %59, i32 -12        ; [#uses=1 type=i8*]
  %61 = bitcast i8* %60 to i32*                   ; [#uses=1 type=i32*]
  %62 = load i32, i32* %61, align 4               ; [#uses=1 type=i32]
  %63 = getelementptr inbounds i8, i8* %8, i32 %62 ; [#uses=1 type=i8*]
  %64 = bitcast i8* %63 to %"class.std::__ccr1::ios_base"* ; [#uses=1 type=%"class.std::__ccr1::ios_base"*]
  invoke void @_ZNSt6__ccr18ios_base33__set_badbit_and_consider_rethrowEv(%"class.std::__ccr1::ios_base"* %64) #17
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
  call void @__clang_call_terminate(i8* %72) #19
  unreachable
}

; [#uses=3]
; Function Attrs: argmemonly nounwind
declare void @llvm.memcpy.p0i8.p0i8.i32(i8* nocapture writeonly, i8* nocapture readonly, i32, i32, i1) #4

; [#uses=15]
; Function Attrs: optsize
declare void @_ZNKSt6__ccr18ios_base6getlocEv(%"class.std::__ccr1::locale"* sret, %"class.std::__ccr1::ios_base"*) local_unnamed_addr #8

; [#uses=30]
; Function Attrs: nounwind optsize
declare %"class.std::__ccr1::locale"* @_ZNSt6__ccr16localeD1Ev(%"class.std::__ccr1::locale"* returned) unnamed_addr #3

; [#uses=15]
; Function Attrs: optsize
declare %"class.std::__ccr1::locale::facet"* @_ZNKSt6__ccr16locale9use_facetERNS0_2idE(%"class.std::__ccr1::locale"*, %"class.std::__ccr1::locale::id"* dereferenceable(8)) local_unnamed_addr #8

; [#uses=4]
; Function Attrs: optsize
declare void @_ZNSt6__ccr18ios_base5clearEj(%"class.std::__ccr1::ios_base"*, i32) local_unnamed_addr #8

; [#uses=6]
; Function Attrs: nounwind optsize
define linkonce_odr %"class.std::__ccr1::basic_ostream<char, std::__ccr1::char_traits<char> >::sentry"* @_ZNSt6__ccr113basic_ostreamIcNS_11char_traitsIcEEE6sentryD2Ev(%"class.std::__ccr1::basic_ostream<char, std::__ccr1::char_traits<char> >::sentry"* returned) unnamed_addr #0 align 2 personality i8* bitcast (i32 (...)* @__gxx_personality_sj0 to i8*) {
  %2 = getelementptr inbounds %"class.std::__ccr1::basic_ostream<char, std::__ccr1::char_traits<char> >::sentry", %"class.std::__ccr1::basic_ostream<char, std::__ccr1::char_traits<char> >::sentry"* %0, i32 0, i32 1 ; [#uses=3 type=%"class.std::__ccr1::basic_ostream"**]
  %3 = load %"class.std::__ccr1::basic_ostream"*, %"class.std::__ccr1::basic_ostream"** %2, align 4, !tbaa !67 ; [#uses=2 type=%"class.std::__ccr1::basic_ostream"*]
  %4 = bitcast %"class.std::__ccr1::basic_ostream"* %3 to i8** ; [#uses=1 type=i8**]
  %5 = load i8*, i8** %4, align 4, !tbaa !15      ; [#uses=1 type=i8*]
  %6 = getelementptr i8, i8* %5, i32 -12          ; [#uses=1 type=i8*]
  %7 = bitcast i8* %6 to i32*                     ; [#uses=1 type=i32*]
  %8 = load i32, i32* %7, align 4                 ; [#uses=1 type=i32]
  %9 = bitcast %"class.std::__ccr1::basic_ostream"* %3 to i8* ; [#uses=1 type=i8*]
  %10 = getelementptr inbounds i8, i8* %9, i32 %8 ; [#uses=3 type=i8*]
  %11 = getelementptr inbounds i8, i8* %10, i32 24 ; [#uses=1 type=i8*]
  %12 = bitcast i8* %11 to %"class.std::__ccr1::basic_streambuf"** ; [#uses=1 type=%"class.std::__ccr1::basic_streambuf"**]
  %13 = load %"class.std::__ccr1::basic_streambuf"*, %"class.std::__ccr1::basic_streambuf"** %12, align 4, !tbaa !58 ; [#uses=1 type=%"class.std::__ccr1::basic_streambuf"*]
  %14 = icmp eq %"class.std::__ccr1::basic_streambuf"* %13, null ; [#uses=1 type=i1]
  br i1 %14, label %65, label %15

; <label>:15:                                     ; preds = %1
  %16 = getelementptr inbounds i8, i8* %10, i32 16 ; [#uses=1 type=i8*]
  %17 = bitcast i8* %16 to i32*                   ; [#uses=1 type=i32*]
  %18 = load i32, i32* %17, align 4, !tbaa !53    ; [#uses=1 type=i32]
  %19 = icmp eq i32 %18, 0                        ; [#uses=1 type=i1]
  br i1 %19, label %20, label %65

; <label>:20:                                     ; preds = %15
  %21 = getelementptr inbounds i8, i8* %10, i32 4 ; [#uses=1 type=i8*]
  %22 = bitcast i8* %21 to i32*                   ; [#uses=1 type=i32*]
  %23 = load i32, i32* %22, align 4, !tbaa !59    ; [#uses=1 type=i32]
  %24 = and i32 %23, 8192                         ; [#uses=1 type=i32]
  %25 = icmp eq i32 %24, 0                        ; [#uses=1 type=i1]
  br i1 %25, label %65, label %26

; <label>:26:                                     ; preds = %20
  %27 = tail call zeroext i1 @_ZSt18uncaught_exceptionv() #16 ; [#uses=1 type=i1]
  br i1 %27, label %65, label %28

; <label>:28:                                     ; preds = %26
  %29 = load %"class.std::__ccr1::basic_ostream"*, %"class.std::__ccr1::basic_ostream"** %2, align 4, !tbaa !67 ; [#uses=2 type=%"class.std::__ccr1::basic_ostream"*]
  %30 = bitcast %"class.std::__ccr1::basic_ostream"* %29 to i8** ; [#uses=1 type=i8**]
  %31 = load i8*, i8** %30, align 4, !tbaa !15    ; [#uses=1 type=i8*]
  %32 = getelementptr i8, i8* %31, i32 -12        ; [#uses=1 type=i8*]
  %33 = bitcast i8* %32 to i32*                   ; [#uses=1 type=i32*]
  %34 = load i32, i32* %33, align 4               ; [#uses=1 type=i32]
  %35 = bitcast %"class.std::__ccr1::basic_ostream"* %29 to i8* ; [#uses=1 type=i8*]
  %36 = getelementptr inbounds i8, i8* %35, i32 %34 ; [#uses=1 type=i8*]
  %37 = getelementptr inbounds i8, i8* %36, i32 24 ; [#uses=1 type=i8*]
  %38 = bitcast i8* %37 to %"class.std::__ccr1::basic_streambuf"** ; [#uses=1 type=%"class.std::__ccr1::basic_streambuf"**]
  %39 = load %"class.std::__ccr1::basic_streambuf"*, %"class.std::__ccr1::basic_streambuf"** %38, align 4, !tbaa !58 ; [#uses=2 type=%"class.std::__ccr1::basic_streambuf"*]
  %40 = bitcast %"class.std::__ccr1::basic_streambuf"* %39 to i32 (%"class.std::__ccr1::basic_streambuf"*)*** ; [#uses=1 type=i32 (%"class.std::__ccr1::basic_streambuf"*)***]
  %41 = load i32 (%"class.std::__ccr1::basic_streambuf"*)**, i32 (%"class.std::__ccr1::basic_streambuf"*)*** %40, align 4, !tbaa !15 ; [#uses=1 type=i32 (%"class.std::__ccr1::basic_streambuf"*)**]
  %42 = getelementptr inbounds i32 (%"class.std::__ccr1::basic_streambuf"*)*, i32 (%"class.std::__ccr1::basic_streambuf"*)** %41, i32 6 ; [#uses=1 type=i32 (%"class.std::__ccr1::basic_streambuf"*)**]
  %43 = load i32 (%"class.std::__ccr1::basic_streambuf"*)*, i32 (%"class.std::__ccr1::basic_streambuf"*)** %42, align 4 ; [#uses=1 type=i32 (%"class.std::__ccr1::basic_streambuf"*)*]
  %44 = invoke i32 %43(%"class.std::__ccr1::basic_streambuf"* %39) #17
          to label %45 unwind label %61           ; [#uses=1 type=i32]

; <label>:45:                                     ; preds = %28
  %46 = icmp eq i32 %44, -1                       ; [#uses=1 type=i1]
  br i1 %46, label %47, label %65

; <label>:47:                                     ; preds = %45
  %48 = load %"class.std::__ccr1::basic_ostream"*, %"class.std::__ccr1::basic_ostream"** %2, align 4, !tbaa !67 ; [#uses=2 type=%"class.std::__ccr1::basic_ostream"*]
  %49 = bitcast %"class.std::__ccr1::basic_ostream"* %48 to i8** ; [#uses=1 type=i8**]
  %50 = load i8*, i8** %49, align 4, !tbaa !15    ; [#uses=1 type=i8*]
  %51 = getelementptr i8, i8* %50, i32 -12        ; [#uses=1 type=i8*]
  %52 = bitcast i8* %51 to i32*                   ; [#uses=1 type=i32*]
  %53 = load i32, i32* %52, align 4               ; [#uses=1 type=i32]
  %54 = bitcast %"class.std::__ccr1::basic_ostream"* %48 to i8* ; [#uses=1 type=i8*]
  %55 = getelementptr inbounds i8, i8* %54, i32 %53 ; [#uses=2 type=i8*]
  %56 = bitcast i8* %55 to %"class.std::__ccr1::ios_base"* ; [#uses=1 type=%"class.std::__ccr1::ios_base"*]
  %57 = getelementptr inbounds i8, i8* %55, i32 16 ; [#uses=1 type=i8*]
  %58 = bitcast i8* %57 to i32*                   ; [#uses=1 type=i32*]
  %59 = load i32, i32* %58, align 4, !tbaa !53    ; [#uses=1 type=i32]
  %60 = or i32 %59, 1                             ; [#uses=1 type=i32]
  invoke void @_ZNSt6__ccr18ios_base5clearEj(%"class.std::__ccr1::ios_base"* %56, i32 %60) #17
          to label %65 unwind label %61

; <label>:61:                                     ; preds = %28, %47
  %62 = landingpad { i8*, i32 }
          catch i8* null                          ; [#uses=1 type={ i8*, i32 }]
  %63 = extractvalue { i8*, i32 } %62, 0          ; [#uses=1 type=i8*]
  %64 = tail call i8* @__cxa_begin_catch(i8* %63) #1 ; [#uses=0 type=i8*]
  invoke void @__cxa_end_catch()
          to label %65 unwind label %66

; <label>:65:                                     ; preds = %47, %20, %1, %45, %61, %26, %15
  ret %"class.std::__ccr1::basic_ostream<char, std::__ccr1::char_traits<char> >::sentry"* %0

; <label>:66:                                     ; preds = %61
  %67 = landingpad { i8*, i32 }
          catch i8* null                          ; [#uses=1 type={ i8*, i32 }]
  %68 = extractvalue { i8*, i32 } %67, 0          ; [#uses=1 type=i8*]
  tail call void @__clang_call_terminate(i8* %68) #19
  unreachable
}

; [#uses=1]
; Function Attrs: nounwind optsize
declare zeroext i1 @_ZSt18uncaught_exceptionv() local_unnamed_addr #3

; [#uses=1]
; Function Attrs: argmemonly nounwind optsize readonly
declare i32 @strlen(i8* nocapture) local_unnamed_addr #9

; [#uses=14]
; Function Attrs: optsize
define linkonce_odr dereferenceable(84) %"class.std::__ccr1::basic_ostream"* @_ZNSt6__ccr113basic_ostreamIcNS_11char_traitsIcEEE3putEc(%"class.std::__ccr1::basic_ostream"*, i8 signext) local_unnamed_addr #7 align 2 personality i8* bitcast (i32 (...)* @__gxx_personality_sj0 to i8*) {
  %3 = alloca %"class.std::__ccr1::basic_ostream<char, std::__ccr1::char_traits<char> >::sentry", align 4 ; [#uses=4 type=%"class.std::__ccr1::basic_ostream<char, std::__ccr1::char_traits<char> >::sentry"*]
  %4 = getelementptr inbounds %"class.std::__ccr1::basic_ostream<char, std::__ccr1::char_traits<char> >::sentry", %"class.std::__ccr1::basic_ostream<char, std::__ccr1::char_traits<char> >::sentry"* %3, i32 0, i32 0 ; [#uses=5 type=i8*]
  call void @llvm.lifetime.start.p0i8(i64 8, i8* nonnull %4) #1
  store i8 0, i8* %4, align 4, !tbaa !51
  %5 = getelementptr inbounds %"class.std::__ccr1::basic_ostream<char, std::__ccr1::char_traits<char> >::sentry", %"class.std::__ccr1::basic_ostream<char, std::__ccr1::char_traits<char> >::sentry"* %3, i32 0, i32 1 ; [#uses=1 type=%"class.std::__ccr1::basic_ostream"**]
  store %"class.std::__ccr1::basic_ostream"* %0, %"class.std::__ccr1::basic_ostream"** %5, align 4, !tbaa !10
  %6 = bitcast %"class.std::__ccr1::basic_ostream"* %0 to i8** ; [#uses=4 type=i8**]
  %7 = load i8*, i8** %6, align 4, !tbaa !15      ; [#uses=1 type=i8*]
  %8 = getelementptr i8, i8* %7, i32 -12          ; [#uses=1 type=i8*]
  %9 = bitcast i8* %8 to i32*                     ; [#uses=2 type=i32*]
  %10 = load i32, i32* %9, align 4                ; [#uses=1 type=i32]
  %11 = bitcast %"class.std::__ccr1::basic_ostream"* %0 to i8* ; [#uses=4 type=i8*]
  %12 = getelementptr inbounds i8, i8* %11, i32 %10 ; [#uses=2 type=i8*]
  %13 = getelementptr inbounds i8, i8* %12, i32 16 ; [#uses=1 type=i8*]
  %14 = bitcast i8* %13 to i32*                   ; [#uses=1 type=i32*]
  %15 = load i32, i32* %14, align 4, !tbaa !53    ; [#uses=1 type=i32]
  %16 = icmp eq i32 %15, 0                        ; [#uses=1 type=i1]
  br i1 %16, label %17, label %72

; <label>:17:                                     ; preds = %2
  %18 = getelementptr inbounds i8, i8* %12, i32 72 ; [#uses=1 type=i8*]
  %19 = bitcast i8* %18 to %"class.std::__ccr1::basic_ostream"** ; [#uses=1 type=%"class.std::__ccr1::basic_ostream"**]
  %20 = load %"class.std::__ccr1::basic_ostream"*, %"class.std::__ccr1::basic_ostream"** %19, align 4, !tbaa !56 ; [#uses=2 type=%"class.std::__ccr1::basic_ostream"*]
  %21 = icmp eq %"class.std::__ccr1::basic_ostream"* %20, null ; [#uses=1 type=i1]
  br i1 %21, label %28, label %22

; <label>:22:                                     ; preds = %17
  %23 = invoke dereferenceable(84) %"class.std::__ccr1::basic_ostream"* @_ZNSt6__ccr113basic_ostreamIcNS_11char_traitsIcEEE5flushEv(%"class.std::__ccr1::basic_ostream"* nonnull %20) #17
          to label %24 unwind label %65           ; [#uses=0 type=%"class.std::__ccr1::basic_ostream"*]

; <label>:24:                                     ; preds = %22
  %25 = load i8*, i8** %6, align 4, !tbaa !15     ; [#uses=1 type=i8*]
  %26 = getelementptr i8, i8* %25, i32 -12        ; [#uses=1 type=i8*]
  %27 = bitcast i8* %26 to i32*                   ; [#uses=1 type=i32*]
  br label %28

; <label>:28:                                     ; preds = %17, %24
  %29 = phi i32* [ %27, %24 ], [ %9, %17 ]        ; [#uses=1 type=i32*]
  store i8 1, i8* %4, align 4, !tbaa !51
  %30 = load i32, i32* %29, align 4               ; [#uses=1 type=i32]
  %31 = getelementptr inbounds i8, i8* %11, i32 %30 ; [#uses=1 type=i8*]
  %32 = getelementptr inbounds i8, i8* %31, i32 24 ; [#uses=1 type=i8*]
  %33 = bitcast i8* %32 to i32*                   ; [#uses=1 type=i32*]
  %34 = load i32, i32* %33, align 4, !tbaa !58    ; [#uses=3 type=i32]
  %35 = inttoptr i32 %34 to %"class.std::__ccr1::basic_streambuf"* ; [#uses=3 type=%"class.std::__ccr1::basic_streambuf"*]
  %36 = icmp eq i32 %34, 0                        ; [#uses=1 type=i1]
  br i1 %36, label %54, label %37

; <label>:37:                                     ; preds = %28
  %38 = getelementptr inbounds %"class.std::__ccr1::basic_streambuf", %"class.std::__ccr1::basic_streambuf"* %35, i32 0, i32 6 ; [#uses=2 type=i8**]
  %39 = load i8*, i8** %38, align 4, !tbaa !62    ; [#uses=3 type=i8*]
  %40 = getelementptr inbounds %"class.std::__ccr1::basic_streambuf", %"class.std::__ccr1::basic_streambuf"* %35, i32 0, i32 7 ; [#uses=1 type=i8**]
  %41 = load i8*, i8** %40, align 4, !tbaa !65    ; [#uses=1 type=i8*]
  %42 = icmp eq i8* %39, %41                      ; [#uses=1 type=i1]
  br i1 %42, label %45, label %43

; <label>:43:                                     ; preds = %37
  %44 = getelementptr inbounds i8, i8* %39, i32 1 ; [#uses=1 type=i8*]
  store i8* %44, i8** %38, align 4, !tbaa !62
  store i8 %1, i8* %39, align 1, !tbaa !4
  br label %72

; <label>:45:                                     ; preds = %37
  %46 = inttoptr i32 %34 to i32 (%"class.std::__ccr1::basic_streambuf"*, i32)*** ; [#uses=1 type=i32 (%"class.std::__ccr1::basic_streambuf"*, i32)***]
  %47 = load i32 (%"class.std::__ccr1::basic_streambuf"*, i32)**, i32 (%"class.std::__ccr1::basic_streambuf"*, i32)*** %46, align 4, !tbaa !15 ; [#uses=1 type=i32 (%"class.std::__ccr1::basic_streambuf"*, i32)**]
  %48 = getelementptr inbounds i32 (%"class.std::__ccr1::basic_streambuf"*, i32)*, i32 (%"class.std::__ccr1::basic_streambuf"*, i32)** %47, i32 13 ; [#uses=1 type=i32 (%"class.std::__ccr1::basic_streambuf"*, i32)**]
  %49 = load i32 (%"class.std::__ccr1::basic_streambuf"*, i32)*, i32 (%"class.std::__ccr1::basic_streambuf"*, i32)** %48, align 4 ; [#uses=1 type=i32 (%"class.std::__ccr1::basic_streambuf"*, i32)*]
  %50 = zext i8 %1 to i32                         ; [#uses=1 type=i32]
  %51 = invoke i32 %49(%"class.std::__ccr1::basic_streambuf"* nonnull %35, i32 %50) #17
          to label %52 unwind label %68           ; [#uses=1 type=i32]

; <label>:52:                                     ; preds = %45
  %53 = icmp eq i32 %51, -1                       ; [#uses=1 type=i1]
  br i1 %53, label %54, label %72

; <label>:54:                                     ; preds = %52, %28
  %55 = load i8*, i8** %6, align 4, !tbaa !15     ; [#uses=1 type=i8*]
  %56 = getelementptr i8, i8* %55, i32 -12        ; [#uses=1 type=i8*]
  %57 = bitcast i8* %56 to i32*                   ; [#uses=1 type=i32*]
  %58 = load i32, i32* %57, align 4               ; [#uses=1 type=i32]
  %59 = getelementptr inbounds i8, i8* %11, i32 %58 ; [#uses=2 type=i8*]
  %60 = bitcast i8* %59 to %"class.std::__ccr1::ios_base"* ; [#uses=1 type=%"class.std::__ccr1::ios_base"*]
  %61 = getelementptr inbounds i8, i8* %59, i32 16 ; [#uses=1 type=i8*]
  %62 = bitcast i8* %61 to i32*                   ; [#uses=1 type=i32*]
  %63 = load i32, i32* %62, align 4, !tbaa !53    ; [#uses=1 type=i32]
  %64 = or i32 %63, 1                             ; [#uses=1 type=i32]
  invoke void @_ZNSt6__ccr18ios_base5clearEj(%"class.std::__ccr1::ios_base"* %60, i32 %64) #17
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
  %71 = call %"class.std::__ccr1::basic_ostream<char, std::__ccr1::char_traits<char> >::sentry"* @_ZNSt6__ccr113basic_ostreamIcNS_11char_traitsIcEEE6sentryD2Ev(%"class.std::__ccr1::basic_ostream<char, std::__ccr1::char_traits<char> >::sentry"* nonnull %3) #16 ; [#uses=0 type=%"class.std::__ccr1::basic_ostream<char, std::__ccr1::char_traits<char> >::sentry"*]
  br label %74

; <label>:72:                                     ; preds = %43, %52, %2, %54
  %73 = call %"class.std::__ccr1::basic_ostream<char, std::__ccr1::char_traits<char> >::sentry"* @_ZNSt6__ccr113basic_ostreamIcNS_11char_traitsIcEEE6sentryD2Ev(%"class.std::__ccr1::basic_ostream<char, std::__ccr1::char_traits<char> >::sentry"* nonnull %3) #16 ; [#uses=0 type=%"class.std::__ccr1::basic_ostream<char, std::__ccr1::char_traits<char> >::sentry"*]
  call void @llvm.lifetime.end.p0i8(i64 8, i8* nonnull %4) #1
  br label %84

; <label>:74:                                     ; preds = %68, %65
  %75 = phi i8* [ %70, %68 ], [ %67, %65 ]        ; [#uses=1 type=i8*]
  call void @llvm.lifetime.end.p0i8(i64 8, i8* nonnull %4) #1
  %76 = call i8* @__cxa_begin_catch(i8* %75) #1   ; [#uses=0 type=i8*]
  %77 = load i8*, i8** %6, align 4, !tbaa !15     ; [#uses=1 type=i8*]
  %78 = getelementptr i8, i8* %77, i32 -12        ; [#uses=1 type=i8*]
  %79 = bitcast i8* %78 to i32*                   ; [#uses=1 type=i32*]
  %80 = load i32, i32* %79, align 4               ; [#uses=1 type=i32]
  %81 = getelementptr inbounds i8, i8* %11, i32 %80 ; [#uses=1 type=i8*]
  %82 = bitcast i8* %81 to %"class.std::__ccr1::ios_base"* ; [#uses=1 type=%"class.std::__ccr1::ios_base"*]
  invoke void @_ZNSt6__ccr18ios_base33__set_badbit_and_consider_rethrowEv(%"class.std::__ccr1::ios_base"* %82) #17
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
  call void @__clang_call_terminate(i8* %90) #19
  unreachable
}

; [#uses=4]
; Function Attrs: optsize
declare i32 @__maskrune(i32, i32) local_unnamed_addr #8

; [#uses=4]
; Function Attrs: optsize
declare i32 @_ZNKSt6__ccr112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE7compareEmmPKcm(%"class.std::__ccr1::basic_string"*, i32, i32, i8*, i32) local_unnamed_addr #8

; [#uses=14]
; Function Attrs: nounwind optsize
define linkonce_odr %"class.std::__ccr1::__vector_base"* @_ZNSt6__ccr113__vector_baseINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEENS4_IS6_EEED2Ev(%"class.std::__ccr1::__vector_base"* returned) unnamed_addr #0 align 2 personality i32 (...)* @__gxx_personality_sj0 {
  %2 = getelementptr inbounds %"class.std::__ccr1::__vector_base", %"class.std::__ccr1::__vector_base"* %0, i32 0, i32 0 ; [#uses=1 type=%"class.std::__ccr1::basic_string"**]
  %3 = load %"class.std::__ccr1::basic_string"*, %"class.std::__ccr1::basic_string"** %2, align 4, !tbaa !34 ; [#uses=5 type=%"class.std::__ccr1::basic_string"*]
  %4 = icmp eq %"class.std::__ccr1::basic_string"* %3, null ; [#uses=1 type=i1]
  br i1 %4, label %28, label %5

; <label>:5:                                      ; preds = %1
  %6 = bitcast %"class.std::__ccr1::basic_string"* %3 to i8* ; [#uses=1 type=i8*]
  %7 = getelementptr inbounds %"class.std::__ccr1::__vector_base", %"class.std::__ccr1::__vector_base"* %0, i32 0, i32 1 ; [#uses=2 type=%"class.std::__ccr1::basic_string"**]
  %8 = load %"class.std::__ccr1::basic_string"*, %"class.std::__ccr1::basic_string"** %7, align 4, !tbaa !37 ; [#uses=2 type=%"class.std::__ccr1::basic_string"*]
  %9 = icmp eq %"class.std::__ccr1::basic_string"* %8, %3 ; [#uses=1 type=i1]
  br i1 %9, label %26, label %10

; <label>:10:                                     ; preds = %5
  br label %11

; <label>:11:                                     ; preds = %10, %21
  %12 = phi %"class.std::__ccr1::basic_string"* [ %13, %21 ], [ %8, %10 ] ; [#uses=2 type=%"class.std::__ccr1::basic_string"*]
  %13 = getelementptr inbounds %"class.std::__ccr1::basic_string", %"class.std::__ccr1::basic_string"* %12, i32 -1 ; [#uses=3 type=%"class.std::__ccr1::basic_string"*]
  %14 = bitcast %"class.std::__ccr1::basic_string"* %13 to i8* ; [#uses=1 type=i8*]
  %15 = load i8, i8* %14, align 4, !tbaa !4       ; [#uses=1 type=i8]
  %16 = and i8 %15, 1                             ; [#uses=1 type=i8]
  %17 = icmp eq i8 %16, 0                         ; [#uses=1 type=i1]
  br i1 %17, label %21, label %18

; <label>:18:                                     ; preds = %11
  %19 = getelementptr inbounds %"class.std::__ccr1::basic_string", %"class.std::__ccr1::basic_string"* %12, i32 -1, i32 0, i32 0, i32 0, i32 0, i32 0, i32 2 ; [#uses=1 type=i8**]
  %20 = load i8*, i8** %19, align 4, !tbaa !4     ; [#uses=1 type=i8*]
  tail call void @_ZdlPv(i8* %20) #15
  br label %21

; <label>:21:                                     ; preds = %18, %11
  %22 = icmp eq %"class.std::__ccr1::basic_string"* %13, %3 ; [#uses=1 type=i1]
  br i1 %22, label %23, label %11

; <label>:23:                                     ; preds = %21
  %24 = bitcast %"class.std::__ccr1::__vector_base"* %0 to i8** ; [#uses=1 type=i8**]
  %25 = load i8*, i8** %24, align 4, !tbaa !34    ; [#uses=1 type=i8*]
  br label %26

; <label>:26:                                     ; preds = %5, %23
  %27 = phi i8* [ %25, %23 ], [ %6, %5 ]          ; [#uses=1 type=i8*]
  store %"class.std::__ccr1::basic_string"* %3, %"class.std::__ccr1::basic_string"** %7, align 4, !tbaa !37
  tail call void @_ZdlPv(i8* %27) #15
  br label %28

; <label>:28:                                     ; preds = %1, %26
  ret %"class.std::__ccr1::__vector_base"* %0
}

; [#uses=2]
; Function Attrs: norecurse optsize
define internal fastcc void @_ZL14ParsePrototypev(%"class.std::__ccr1::unique_ptr.13"* noalias nocapture sret) unnamed_addr #2 personality i8* bitcast (i32 (...)* @__gxx_personality_sj0 to i8*) {
  %2 = alloca %"class.std::__ccr1::vector", align 4 ; [#uses=7 type=%"class.std::__ccr1::vector"*]
  %3 = alloca %"class.std::__ccr1::basic_string", align 4 ; [#uses=5 type=%"class.std::__ccr1::basic_string"*]
  %4 = alloca %"class.std::__ccr1::vector", align 4 ; [#uses=8 type=%"class.std::__ccr1::vector"*]
  %5 = load %struct.__sFILE*, %struct.__sFILE** @__stderrp, align 4, !tbaa !10 ; [#uses=1 type=%struct.__sFILE*]
  %6 = tail call i32 (%struct.__sFILE*, i8*, ...) @fprintf(%struct.__sFILE* %5, i8* getelementptr inbounds ([34 x i8], [34 x i8]* @.str.3, i32 0, i32 0), i8* getelementptr inbounds ([15 x i8], [15 x i8]* @__func__._ZL14ParsePrototypev, i32 0, i32 0), i32 753, i8* getelementptr inbounds ([148 x i8], [148 x i8]* @.str.4, i32 0, i32 0)) #17 ; [#uses=0 type=i32]
  %7 = load i32, i32* @_ZL6CurTok, align 4, !tbaa !13 ; [#uses=1 type=i32]
  %8 = icmp eq i32 %7, -4                         ; [#uses=1 type=i1]
  br i1 %8, label %10, label %9

; <label>:9:                                      ; preds = %1
  tail call fastcc void @_Z9LogErrorPPKc(%"class.std::__ccr1::unique_ptr.13"* sret %0, i8* getelementptr inbounds ([36 x i8], [36 x i8]* @.str.17, i32 0, i32 0)) #17
  br label %112

; <label>:10:                                     ; preds = %1
  %11 = bitcast %"class.std::__ccr1::basic_string"* %3 to i8* ; [#uses=5 type=i8*]
  call void @llvm.lifetime.start.p0i8(i64 12, i8* nonnull %11) #1
  %12 = call %"class.std::__ccr1::basic_string"* @_ZNSt6__ccr112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEC1ERKS5_(%"class.std::__ccr1::basic_string"* nonnull %3, %"class.std::__ccr1::basic_string"* nonnull dereferenceable(12) @_ZL13IdentifierStr) #17 ; [#uses=0 type=%"class.std::__ccr1::basic_string"*]
  %13 = invoke fastcc i32 @_ZL6gettokv() #17
          to label %14 unwind label %17           ; [#uses=2 type=i32]

; <label>:14:                                     ; preds = %10
  store i32 %13, i32* @_ZL6CurTok, align 4, !tbaa !13
  %15 = icmp eq i32 %13, 40                       ; [#uses=1 type=i1]
  br i1 %15, label %21, label %16

; <label>:16:                                     ; preds = %14
  invoke fastcc void @_Z9LogErrorPPKc(%"class.std::__ccr1::unique_ptr.13"* sret %0, i8* getelementptr inbounds ([26 x i8], [26 x i8]* @.str.18, i32 0, i32 0)) #17
          to label %92 unwind label %17

; <label>:17:                                     ; preds = %10, %16
  %18 = landingpad { i8*, i32 }
          cleanup                                 ; [#uses=2 type={ i8*, i32 }]
  %19 = extractvalue { i8*, i32 } %18, 0          ; [#uses=1 type=i8*]
  %20 = extractvalue { i8*, i32 } %18, 1          ; [#uses=1 type=i32]
  br label %100

; <label>:21:                                     ; preds = %14
  %22 = bitcast %"class.std::__ccr1::vector"* %4 to i8* ; [#uses=3 type=i8*]
  call void @llvm.lifetime.start.p0i8(i64 12, i8* nonnull %22) #1
  %23 = getelementptr inbounds %"class.std::__ccr1::vector", %"class.std::__ccr1::vector"* %4, i32 0, i32 0, i32 0 ; [#uses=2 type=%"class.std::__ccr1::basic_string"**]
  store %"class.std::__ccr1::basic_string"* null, %"class.std::__ccr1::basic_string"** %23, align 4, !tbaa !34
  %24 = getelementptr inbounds %"class.std::__ccr1::vector", %"class.std::__ccr1::vector"* %4, i32 0, i32 0, i32 1 ; [#uses=6 type=%"class.std::__ccr1::basic_string"**]
  store %"class.std::__ccr1::basic_string"* null, %"class.std::__ccr1::basic_string"** %24, align 4, !tbaa !37
  %25 = getelementptr inbounds %"class.std::__ccr1::vector", %"class.std::__ccr1::vector"* %4, i32 0, i32 0, i32 2, i32 0, i32 0 ; [#uses=4 type=%"class.std::__ccr1::basic_string"**]
  store %"class.std::__ccr1::basic_string"* null, %"class.std::__ccr1::basic_string"** %25, align 4, !tbaa !38
  br label %26

; <label>:26:                                     ; preds = %38, %21
  %27 = invoke fastcc i32 @_ZL6gettokv() #17
          to label %28 unwind label %40           ; [#uses=2 type=i32]

; <label>:28:                                     ; preds = %26
  store i32 %27, i32* @_ZL6CurTok, align 4, !tbaa !13
  switch i32 %27, label %50 [
    i32 -4, label %29
    i32 41, label %51
  ]

; <label>:29:                                     ; preds = %28
  %30 = load %"class.std::__ccr1::basic_string"*, %"class.std::__ccr1::basic_string"** %24, align 4, !tbaa !37 ; [#uses=2 type=%"class.std::__ccr1::basic_string"*]
  %31 = load %"class.std::__ccr1::basic_string"*, %"class.std::__ccr1::basic_string"** %25, align 4, !tbaa !10 ; [#uses=1 type=%"class.std::__ccr1::basic_string"*]
  %32 = icmp eq %"class.std::__ccr1::basic_string"* %30, %31 ; [#uses=1 type=i1]
  br i1 %32, label %39, label %33

; <label>:33:                                     ; preds = %29
  %34 = invoke %"class.std::__ccr1::basic_string"* @_ZNSt6__ccr112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEC1ERKS5_(%"class.std::__ccr1::basic_string"* %30, %"class.std::__ccr1::basic_string"* nonnull dereferenceable(12) @_ZL13IdentifierStr) #17
          to label %35 unwind label %40           ; [#uses=0 type=%"class.std::__ccr1::basic_string"*]

; <label>:35:                                     ; preds = %33
  %36 = load %"class.std::__ccr1::basic_string"*, %"class.std::__ccr1::basic_string"** %24, align 4, !tbaa !37 ; [#uses=1 type=%"class.std::__ccr1::basic_string"*]
  %37 = getelementptr inbounds %"class.std::__ccr1::basic_string", %"class.std::__ccr1::basic_string"* %36, i32 1 ; [#uses=1 type=%"class.std::__ccr1::basic_string"*]
  store %"class.std::__ccr1::basic_string"* %37, %"class.std::__ccr1::basic_string"** %24, align 4, !tbaa !37
  br label %38

; <label>:38:                                     ; preds = %35, %39
  br label %26

; <label>:39:                                     ; preds = %29
  invoke void @_ZNSt6__ccr16vectorINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEENS4_IS6_EEE21__push_back_slow_pathIRKS6_EEvOT_(%"class.std::__ccr1::vector"* nonnull %4, %"class.std::__ccr1::basic_string"* nonnull dereferenceable(12) @_ZL13IdentifierStr) #17
          to label %38 unwind label %40

; <label>:40:                                     ; preds = %26, %33, %39
  %41 = landingpad { i8*, i32 }
          cleanup                                 ; [#uses=1 type={ i8*, i32 }]
  br label %44

; <label>:42:                                     ; preds = %50, %51, %53
  %43 = landingpad { i8*, i32 }
          cleanup                                 ; [#uses=1 type={ i8*, i32 }]
  br label %44

; <label>:44:                                     ; preds = %40, %42, %70
  %45 = phi { i8*, i32 } [ %71, %70 ], [ %41, %40 ], [ %43, %42 ] ; [#uses=2 type={ i8*, i32 }]
  %46 = extractvalue { i8*, i32 } %45, 0          ; [#uses=1 type=i8*]
  %47 = extractvalue { i8*, i32 } %45, 1          ; [#uses=1 type=i32]
  %48 = getelementptr inbounds %"class.std::__ccr1::vector", %"class.std::__ccr1::vector"* %4, i32 0, i32 0 ; [#uses=1 type=%"class.std::__ccr1::__vector_base"*]
  %49 = call %"class.std::__ccr1::__vector_base"* @_ZNSt6__ccr113__vector_baseINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEENS4_IS6_EEED2Ev(%"class.std::__ccr1::__vector_base"* nonnull %48) #16 ; [#uses=0 type=%"class.std::__ccr1::__vector_base"*]
  call void @llvm.lifetime.end.p0i8(i64 12, i8* nonnull %22) #1
  br label %100

; <label>:50:                                     ; preds = %28
  invoke fastcc void @_Z9LogErrorPPKc(%"class.std::__ccr1::unique_ptr.13"* sret %0, i8* getelementptr inbounds ([26 x i8], [26 x i8]* @.str.19, i32 0, i32 0)) #17
          to label %89 unwind label %42

; <label>:51:                                     ; preds = %28
  %52 = invoke fastcc i32 @_ZL6gettokv() #17
          to label %53 unwind label %42           ; [#uses=1 type=i32]

; <label>:53:                                     ; preds = %51
  store i32 %52, i32* @_ZL6CurTok, align 4, !tbaa !13
  %54 = bitcast %"class.std::__ccr1::vector"* %2 to i8* ; [#uses=2 type=i8*]
  call void @llvm.lifetime.start.p0i8(i64 12, i8* nonnull %54)
  %55 = invoke i8* @_Znwm(i32 24) #18
          to label %56 unwind label %42           ; [#uses=6 type=i8*]

; <label>:56:                                     ; preds = %53
  %57 = getelementptr inbounds %"class.std::__ccr1::vector", %"class.std::__ccr1::vector"* %2, i32 0, i32 0, i32 1 ; [#uses=2 type=%"class.std::__ccr1::basic_string"**]
  %58 = getelementptr inbounds %"class.std::__ccr1::vector", %"class.std::__ccr1::vector"* %2, i32 0, i32 0, i32 2, i32 0, i32 0 ; [#uses=2 type=%"class.std::__ccr1::basic_string"**]
  %59 = bitcast %"class.std::__ccr1::vector"* %4 to i32* ; [#uses=1 type=i32*]
  %60 = load i32, i32* %59, align 4, !tbaa !34, !noalias !68 ; [#uses=1 type=i32]
  %61 = bitcast %"class.std::__ccr1::vector"* %2 to i32* ; [#uses=2 type=i32*]
  store i32 %60, i32* %61, align 4, !tbaa !34, !noalias !68
  %62 = bitcast %"class.std::__ccr1::basic_string"** %24 to i32* ; [#uses=1 type=i32*]
  %63 = load i32, i32* %62, align 4, !tbaa !37, !noalias !68 ; [#uses=1 type=i32]
  %64 = bitcast %"class.std::__ccr1::basic_string"** %57 to i32* ; [#uses=2 type=i32*]
  store i32 %63, i32* %64, align 4, !tbaa !37, !noalias !68
  %65 = bitcast %"class.std::__ccr1::basic_string"** %25 to i32* ; [#uses=1 type=i32*]
  %66 = load i32, i32* %65, align 4, !tbaa !10, !noalias !68 ; [#uses=1 type=i32]
  %67 = bitcast %"class.std::__ccr1::basic_string"** %58 to i32* ; [#uses=2 type=i32*]
  store i32 %66, i32* %67, align 4, !tbaa !10, !noalias !68
  store %"class.std::__ccr1::basic_string"* null, %"class.std::__ccr1::basic_string"** %25, align 4, !tbaa !10, !noalias !68
  store %"class.std::__ccr1::basic_string"* null, %"class.std::__ccr1::basic_string"** %24, align 4, !tbaa !37, !noalias !68
  store %"class.std::__ccr1::basic_string"* null, %"class.std::__ccr1::basic_string"** %23, align 4, !tbaa !34, !noalias !68
  %68 = bitcast i8* %55 to %"class.std::__ccr1::basic_string"* ; [#uses=1 type=%"class.std::__ccr1::basic_string"*]
  %69 = invoke %"class.std::__ccr1::basic_string"* @_ZNSt6__ccr112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEC1ERKS5_(%"class.std::__ccr1::basic_string"* nonnull %68, %"class.std::__ccr1::basic_string"* nonnull dereferenceable(12) %3) #17
          to label %74 unwind label %70, !noalias !68 ; [#uses=0 type=%"class.std::__ccr1::basic_string"*]

; <label>:70:                                     ; preds = %56
  %71 = landingpad { i8*, i32 }
          cleanup                                 ; [#uses=1 type={ i8*, i32 }]
  %72 = getelementptr inbounds %"class.std::__ccr1::vector", %"class.std::__ccr1::vector"* %2, i32 0, i32 0 ; [#uses=1 type=%"class.std::__ccr1::__vector_base"*]
  %73 = call %"class.std::__ccr1::__vector_base"* @_ZNSt6__ccr113__vector_baseINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEENS4_IS6_EEED2Ev(%"class.std::__ccr1::__vector_base"* nonnull %72) #16, !noalias !68 ; [#uses=0 type=%"class.std::__ccr1::__vector_base"*]
  call void @_ZdlPv(i8* nonnull %55) #15, !noalias !68
  br label %44

; <label>:74:                                     ; preds = %56
  %75 = getelementptr inbounds %"class.std::__ccr1::vector", %"class.std::__ccr1::vector"* %2, i32 0, i32 0, i32 0 ; [#uses=1 type=%"class.std::__ccr1::basic_string"**]
  %76 = getelementptr inbounds i8, i8* %55, i32 12 ; [#uses=1 type=i8*]
  %77 = getelementptr inbounds i8, i8* %55, i32 16 ; [#uses=1 type=i8*]
  %78 = getelementptr inbounds i8, i8* %55, i32 20 ; [#uses=1 type=i8*]
  %79 = load i32, i32* %61, align 4, !tbaa !34, !noalias !68 ; [#uses=1 type=i32]
  %80 = bitcast i8* %76 to i32*                   ; [#uses=1 type=i32*]
  store i32 %79, i32* %80, align 4, !tbaa !34, !noalias !68
  %81 = load i32, i32* %64, align 4, !tbaa !37, !noalias !68 ; [#uses=1 type=i32]
  %82 = bitcast i8* %77 to i32*                   ; [#uses=1 type=i32*]
  store i32 %81, i32* %82, align 4, !tbaa !37, !noalias !68
  %83 = load i32, i32* %67, align 4, !tbaa !10, !noalias !68 ; [#uses=1 type=i32]
  %84 = bitcast i8* %78 to i32*                   ; [#uses=1 type=i32*]
  store i32 %83, i32* %84, align 4, !tbaa !10, !noalias !68
  store %"class.std::__ccr1::basic_string"* null, %"class.std::__ccr1::basic_string"** %58, align 4, !tbaa !10, !noalias !68
  store %"class.std::__ccr1::basic_string"* null, %"class.std::__ccr1::basic_string"** %57, align 4, !tbaa !37, !noalias !68
  store %"class.std::__ccr1::basic_string"* null, %"class.std::__ccr1::basic_string"** %75, align 4, !tbaa !34, !noalias !68
  %85 = ptrtoint i8* %55 to i32                   ; [#uses=1 type=i32]
  %86 = bitcast %"class.std::__ccr1::unique_ptr.13"* %0 to i32* ; [#uses=1 type=i32*]
  store i32 %85, i32* %86, align 4, !tbaa !23, !alias.scope !68
  %87 = getelementptr inbounds %"class.std::__ccr1::vector", %"class.std::__ccr1::vector"* %2, i32 0, i32 0 ; [#uses=1 type=%"class.std::__ccr1::__vector_base"*]
  %88 = call %"class.std::__ccr1::__vector_base"* @_ZNSt6__ccr113__vector_baseINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEENS4_IS6_EEED2Ev(%"class.std::__ccr1::__vector_base"* nonnull %87) #16, !noalias !68 ; [#uses=0 type=%"class.std::__ccr1::__vector_base"*]
  call void @llvm.lifetime.end.p0i8(i64 12, i8* nonnull %54)
  br label %89

; <label>:89:                                     ; preds = %74, %50
  %90 = getelementptr inbounds %"class.std::__ccr1::vector", %"class.std::__ccr1::vector"* %4, i32 0, i32 0 ; [#uses=1 type=%"class.std::__ccr1::__vector_base"*]
  %91 = call %"class.std::__ccr1::__vector_base"* @_ZNSt6__ccr113__vector_baseINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEENS4_IS6_EEED2Ev(%"class.std::__ccr1::__vector_base"* nonnull %90) #16 ; [#uses=0 type=%"class.std::__ccr1::__vector_base"*]
  call void @llvm.lifetime.end.p0i8(i64 12, i8* nonnull %22) #1
  br label %92

; <label>:92:                                     ; preds = %16, %89
  %93 = load i8, i8* %11, align 4, !tbaa !4       ; [#uses=1 type=i8]
  %94 = and i8 %93, 1                             ; [#uses=1 type=i8]
  %95 = icmp eq i8 %94, 0                         ; [#uses=1 type=i1]
  br i1 %95, label %99, label %96

; <label>:96:                                     ; preds = %92
  %97 = getelementptr inbounds %"class.std::__ccr1::basic_string", %"class.std::__ccr1::basic_string"* %3, i32 0, i32 0, i32 0, i32 0, i32 0, i32 0, i32 2 ; [#uses=1 type=i8**]
  %98 = load i8*, i8** %97, align 4, !tbaa !4     ; [#uses=1 type=i8*]
  call void @_ZdlPv(i8* %98) #15
  br label %99

; <label>:99:                                     ; preds = %92, %96
  call void @llvm.lifetime.end.p0i8(i64 12, i8* nonnull %11) #1
  br label %112

; <label>:100:                                    ; preds = %44, %17
  %101 = phi i8* [ %19, %17 ], [ %46, %44 ]       ; [#uses=1 type=i8*]
  %102 = phi i32 [ %20, %17 ], [ %47, %44 ]       ; [#uses=1 type=i32]
  %103 = load i8, i8* %11, align 4, !tbaa !4      ; [#uses=1 type=i8]
  %104 = and i8 %103, 1                           ; [#uses=1 type=i8]
  %105 = icmp eq i8 %104, 0                       ; [#uses=1 type=i1]
  br i1 %105, label %109, label %106

; <label>:106:                                    ; preds = %100
  %107 = getelementptr inbounds %"class.std::__ccr1::basic_string", %"class.std::__ccr1::basic_string"* %3, i32 0, i32 0, i32 0, i32 0, i32 0, i32 0, i32 2 ; [#uses=1 type=i8**]
  %108 = load i8*, i8** %107, align 4, !tbaa !4   ; [#uses=1 type=i8*]
  call void @_ZdlPv(i8* %108) #15
  br label %109

; <label>:109:                                    ; preds = %100, %106
  call void @llvm.lifetime.end.p0i8(i64 12, i8* nonnull %11) #1
  %110 = insertvalue { i8*, i32 } undef, i8* %101, 0 ; [#uses=1 type={ i8*, i32 }]
  %111 = insertvalue { i8*, i32 } %110, i32 %102, 1 ; [#uses=1 type={ i8*, i32 }]
  resume { i8*, i32 } %111

; <label>:112:                                    ; preds = %99, %9
  ret void
}

; [#uses=4]
; Function Attrs: optsize
define internal fastcc void @_ZL15ParseExpressionv(%"class.std::__ccr1::unique_ptr.22"* noalias nocapture sret) unnamed_addr #7 personality i8* bitcast (i32 (...)* @__gxx_personality_sj0 to i8*) {
  %2 = alloca %"class.std::__ccr1::unique_ptr.22", align 4 ; [#uses=3 type=%"class.std::__ccr1::unique_ptr.22"*]
  %3 = alloca %"class.std::__ccr1::unique_ptr.22", align 4 ; [#uses=4 type=%"class.std::__ccr1::unique_ptr.22"*]
  %4 = load %struct.__sFILE*, %struct.__sFILE** @__stderrp, align 4, !tbaa !10 ; [#uses=1 type=%struct.__sFILE*]
  %5 = tail call i32 (%struct.__sFILE*, i8*, ...) @fprintf(%struct.__sFILE* %4, i8* getelementptr inbounds ([34 x i8], [34 x i8]* @.str.3, i32 0, i32 0), i8* getelementptr inbounds ([16 x i8], [16 x i8]* @__func__._ZL15ParseExpressionv, i32 0, i32 0), i32 643, i8* getelementptr inbounds ([148 x i8], [148 x i8]* @.str.4, i32 0, i32 0)) #17 ; [#uses=0 type=i32]
  %6 = bitcast %"class.std::__ccr1::unique_ptr.22"* %2 to i8* ; [#uses=3 type=i8*]
  call void @llvm.lifetime.start.p0i8(i64 4, i8* nonnull %6) #1
  call fastcc void @_ZL12ParsePrimaryv(%"class.std::__ccr1::unique_ptr.22"* nonnull sret %2) #17
  %7 = getelementptr inbounds %"class.std::__ccr1::unique_ptr.22", %"class.std::__ccr1::unique_ptr.22"* %2, i32 0, i32 0, i32 0, i32 0 ; [#uses=2 type=%"class.(anonymous namespace)::ExprAST"**]
  %8 = load %"class.(anonymous namespace)::ExprAST"*, %"class.(anonymous namespace)::ExprAST"** %7, align 4, !tbaa !10 ; [#uses=2 type=%"class.(anonymous namespace)::ExprAST"*]
  %9 = icmp eq %"class.(anonymous namespace)::ExprAST"* %8, null ; [#uses=1 type=i1]
  br i1 %9, label %10, label %12

; <label>:10:                                     ; preds = %1
  %11 = bitcast %"class.std::__ccr1::unique_ptr.22"* %0 to i32* ; [#uses=1 type=i32*]
  store i32 0, i32* %11, align 4, !tbaa !71
  br label %35

; <label>:12:                                     ; preds = %1
  %13 = ptrtoint %"class.(anonymous namespace)::ExprAST"* %8 to i32 ; [#uses=1 type=i32]
  store %"class.(anonymous namespace)::ExprAST"* null, %"class.(anonymous namespace)::ExprAST"** %7, align 4, !tbaa !10
  %14 = bitcast %"class.std::__ccr1::unique_ptr.22"* %3 to i32* ; [#uses=1 type=i32*]
  store i32 %13, i32* %14, align 4, !tbaa !71
  invoke fastcc void @_ZL13ParseBinOpRHSiNSt6__ccr110unique_ptrIN12_GLOBAL__N_17ExprASTENS_14default_deleteIS2_EEEE(%"class.std::__ccr1::unique_ptr.22"* sret %0, i32 0, %"class.std::__ccr1::unique_ptr.22"* nonnull %3) #17
          to label %15 unwind label %24

; <label>:15:                                     ; preds = %12
  %16 = getelementptr inbounds %"class.std::__ccr1::unique_ptr.22", %"class.std::__ccr1::unique_ptr.22"* %3, i32 0, i32 0, i32 0, i32 0 ; [#uses=2 type=%"class.(anonymous namespace)::ExprAST"**]
  %17 = load %"class.(anonymous namespace)::ExprAST"*, %"class.(anonymous namespace)::ExprAST"** %16, align 4, !tbaa !10 ; [#uses=3 type=%"class.(anonymous namespace)::ExprAST"*]
  store %"class.(anonymous namespace)::ExprAST"* null, %"class.(anonymous namespace)::ExprAST"** %16, align 4, !tbaa !10
  %18 = icmp eq %"class.(anonymous namespace)::ExprAST"* %17, null ; [#uses=1 type=i1]
  br i1 %18, label %35, label %19

; <label>:19:                                     ; preds = %15
  %20 = bitcast %"class.(anonymous namespace)::ExprAST"* %17 to void (%"class.(anonymous namespace)::ExprAST"*)*** ; [#uses=1 type=void (%"class.(anonymous namespace)::ExprAST"*)***]
  %21 = load void (%"class.(anonymous namespace)::ExprAST"*)**, void (%"class.(anonymous namespace)::ExprAST"*)*** %20, align 4, !tbaa !15 ; [#uses=1 type=void (%"class.(anonymous namespace)::ExprAST"*)**]
  %22 = getelementptr inbounds void (%"class.(anonymous namespace)::ExprAST"*)*, void (%"class.(anonymous namespace)::ExprAST"*)** %21, i32 1 ; [#uses=1 type=void (%"class.(anonymous namespace)::ExprAST"*)**]
  %23 = load void (%"class.(anonymous namespace)::ExprAST"*)*, void (%"class.(anonymous namespace)::ExprAST"*)** %22, align 4 ; [#uses=1 type=void (%"class.(anonymous namespace)::ExprAST"*)*]
  tail call void %23(%"class.(anonymous namespace)::ExprAST"* nonnull %17) #16
  br label %35

; <label>:24:                                     ; preds = %12
  %25 = landingpad { i8*, i32 }
          cleanup                                 ; [#uses=1 type={ i8*, i32 }]
  %26 = getelementptr inbounds %"class.std::__ccr1::unique_ptr.22", %"class.std::__ccr1::unique_ptr.22"* %3, i32 0, i32 0, i32 0, i32 0 ; [#uses=2 type=%"class.(anonymous namespace)::ExprAST"**]
  %27 = load %"class.(anonymous namespace)::ExprAST"*, %"class.(anonymous namespace)::ExprAST"** %26, align 4, !tbaa !10 ; [#uses=3 type=%"class.(anonymous namespace)::ExprAST"*]
  store %"class.(anonymous namespace)::ExprAST"* null, %"class.(anonymous namespace)::ExprAST"** %26, align 4, !tbaa !10
  %28 = icmp eq %"class.(anonymous namespace)::ExprAST"* %27, null ; [#uses=1 type=i1]
  br i1 %28, label %34, label %29

; <label>:29:                                     ; preds = %24
  %30 = bitcast %"class.(anonymous namespace)::ExprAST"* %27 to void (%"class.(anonymous namespace)::ExprAST"*)*** ; [#uses=1 type=void (%"class.(anonymous namespace)::ExprAST"*)***]
  %31 = load void (%"class.(anonymous namespace)::ExprAST"*)**, void (%"class.(anonymous namespace)::ExprAST"*)*** %30, align 4, !tbaa !15 ; [#uses=1 type=void (%"class.(anonymous namespace)::ExprAST"*)**]
  %32 = getelementptr inbounds void (%"class.(anonymous namespace)::ExprAST"*)*, void (%"class.(anonymous namespace)::ExprAST"*)** %31, i32 1 ; [#uses=1 type=void (%"class.(anonymous namespace)::ExprAST"*)**]
  %33 = load void (%"class.(anonymous namespace)::ExprAST"*)*, void (%"class.(anonymous namespace)::ExprAST"*)** %32, align 4 ; [#uses=1 type=void (%"class.(anonymous namespace)::ExprAST"*)*]
  tail call void %33(%"class.(anonymous namespace)::ExprAST"* nonnull %27) #16
  br label %34

; <label>:34:                                     ; preds = %29, %24
  call void @llvm.lifetime.end.p0i8(i64 4, i8* nonnull %6) #1
  resume { i8*, i32 } %25

; <label>:35:                                     ; preds = %15, %19, %10
  call void @llvm.lifetime.end.p0i8(i64 4, i8* nonnull %6) #1
  ret void
}

; [#uses=3]
; Function Attrs: norecurse optsize
define internal fastcc void @_Z9LogErrorPPKc(%"class.std::__ccr1::unique_ptr.13"* noalias nocapture sret, i8*) unnamed_addr #2 personality i32 (...)* @__gxx_personality_sj0 {
  %3 = alloca %"class.std::__ccr1::unique_ptr.22", align 4 ; [#uses=2 type=%"class.std::__ccr1::unique_ptr.22"*]
  %4 = load %struct.__sFILE*, %struct.__sFILE** @__stderrp, align 4, !tbaa !10 ; [#uses=1 type=%struct.__sFILE*]
  %5 = tail call i32 (%struct.__sFILE*, i8*, ...) @fprintf(%struct.__sFILE* %4, i8* getelementptr inbounds ([34 x i8], [34 x i8]* @.str.3, i32 0, i32 0), i8* getelementptr inbounds ([10 x i8], [10 x i8]* @__func__._Z9LogErrorPPKc, i32 0, i32 0), i32 395, i8* getelementptr inbounds ([148 x i8], [148 x i8]* @.str.4, i32 0, i32 0)) #17 ; [#uses=0 type=i32]
  call fastcc void @_Z8LogErrorPKc(%"class.std::__ccr1::unique_ptr.22"* nonnull sret %3, i8* %1) #17
  %6 = getelementptr inbounds %"class.std::__ccr1::unique_ptr.22", %"class.std::__ccr1::unique_ptr.22"* %3, i32 0, i32 0, i32 0, i32 0 ; [#uses=2 type=%"class.(anonymous namespace)::ExprAST"**]
  %7 = load %"class.(anonymous namespace)::ExprAST"*, %"class.(anonymous namespace)::ExprAST"** %6, align 4, !tbaa !10 ; [#uses=3 type=%"class.(anonymous namespace)::ExprAST"*]
  store %"class.(anonymous namespace)::ExprAST"* null, %"class.(anonymous namespace)::ExprAST"** %6, align 4, !tbaa !10
  %8 = icmp eq %"class.(anonymous namespace)::ExprAST"* %7, null ; [#uses=1 type=i1]
  br i1 %8, label %14, label %9

; <label>:9:                                      ; preds = %2
  %10 = bitcast %"class.(anonymous namespace)::ExprAST"* %7 to void (%"class.(anonymous namespace)::ExprAST"*)*** ; [#uses=1 type=void (%"class.(anonymous namespace)::ExprAST"*)***]
  %11 = load void (%"class.(anonymous namespace)::ExprAST"*)**, void (%"class.(anonymous namespace)::ExprAST"*)*** %10, align 4, !tbaa !15 ; [#uses=1 type=void (%"class.(anonymous namespace)::ExprAST"*)**]
  %12 = getelementptr inbounds void (%"class.(anonymous namespace)::ExprAST"*)*, void (%"class.(anonymous namespace)::ExprAST"*)** %11, i32 1 ; [#uses=1 type=void (%"class.(anonymous namespace)::ExprAST"*)**]
  %13 = load void (%"class.(anonymous namespace)::ExprAST"*)*, void (%"class.(anonymous namespace)::ExprAST"*)** %12, align 4 ; [#uses=1 type=void (%"class.(anonymous namespace)::ExprAST"*)*]
  tail call void %13(%"class.(anonymous namespace)::ExprAST"* nonnull %7) #16
  br label %14

; <label>:14:                                     ; preds = %2, %9
  %15 = bitcast %"class.std::__ccr1::unique_ptr.13"* %0 to i32* ; [#uses=1 type=i32*]
  store i32 0, i32* %15, align 4, !tbaa !23
  ret void
}

; [#uses=8]
; Function Attrs: optsize
declare %"class.std::__ccr1::basic_string"* @_ZNSt6__ccr112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEC1ERKS5_(%"class.std::__ccr1::basic_string"* returned, %"class.std::__ccr1::basic_string"* dereferenceable(12)) unnamed_addr #8

; [#uses=4]
; Function Attrs: optsize
define internal fastcc void @_Z8LogErrorPKc(%"class.std::__ccr1::unique_ptr.22"* noalias nocapture sret, i8*) unnamed_addr #7 personality i32 (...)* @__gxx_personality_sj0 {
  %3 = alloca %"class.std::__ccr1::locale", align 4 ; [#uses=5 type=%"class.std::__ccr1::locale"*]
  %4 = alloca %"class.std::__ccr1::locale", align 4 ; [#uses=5 type=%"class.std::__ccr1::locale"*]
  %5 = load %struct.__sFILE*, %struct.__sFILE** @__stderrp, align 4, !tbaa !10 ; [#uses=1 type=%struct.__sFILE*]
  %6 = tail call i32 (%struct.__sFILE*, i8*, ...) @fprintf(%struct.__sFILE* %5, i8* getelementptr inbounds ([34 x i8], [34 x i8]* @.str.3, i32 0, i32 0), i8* getelementptr inbounds ([9 x i8], [9 x i8]* @__func__._Z8LogErrorPKc, i32 0, i32 0), i32 390, i8* getelementptr inbounds ([148 x i8], [148 x i8]* @.str.4, i32 0, i32 0)) #17 ; [#uses=0 type=i32]
  %7 = load i8*, i8** bitcast (%"class.std::__ccr1::basic_ostream"* @_ZNSt6__ccr14cerrE to i8**), align 4, !tbaa !15 ; [#uses=1 type=i8*]
  %8 = getelementptr i8, i8* %7, i32 -12          ; [#uses=1 type=i8*]
  %9 = bitcast i8* %8 to i32*                     ; [#uses=1 type=i32*]
  %10 = load i32, i32* %9, align 4                ; [#uses=1 type=i32]
  %11 = getelementptr inbounds i8, i8* bitcast (%"class.std::__ccr1::basic_ostream"* @_ZNSt6__ccr14cerrE to i8*), i32 %10 ; [#uses=1 type=i8*]
  %12 = bitcast %"class.std::__ccr1::locale"* %4 to i8* ; [#uses=3 type=i8*]
  call void @llvm.lifetime.start.p0i8(i64 4, i8* nonnull %12) #1
  %13 = bitcast i8* %11 to %"class.std::__ccr1::ios_base"* ; [#uses=1 type=%"class.std::__ccr1::ios_base"*]
  call void @_ZNKSt6__ccr18ios_base6getlocEv(%"class.std::__ccr1::locale"* nonnull sret %4, %"class.std::__ccr1::ios_base"* %13) #17
  %14 = invoke %"class.std::__ccr1::locale::facet"* @_ZNKSt6__ccr16locale9use_facetERNS0_2idE(%"class.std::__ccr1::locale"* nonnull %4, %"class.std::__ccr1::locale::id"* nonnull dereferenceable(8) @_ZNSt6__ccr15ctypeIcE2idE) #17
          to label %15 unwind label %22           ; [#uses=2 type=%"class.std::__ccr1::locale::facet"*]

; <label>:15:                                     ; preds = %2
  %16 = bitcast %"class.std::__ccr1::locale::facet"* %14 to %"class.std::__ccr1::ctype"* ; [#uses=1 type=%"class.std::__ccr1::ctype"*]
  %17 = bitcast %"class.std::__ccr1::locale::facet"* %14 to i8 (%"class.std::__ccr1::ctype"*, i8)*** ; [#uses=1 type=i8 (%"class.std::__ccr1::ctype"*, i8)***]
  %18 = load i8 (%"class.std::__ccr1::ctype"*, i8)**, i8 (%"class.std::__ccr1::ctype"*, i8)*** %17, align 4, !tbaa !15 ; [#uses=1 type=i8 (%"class.std::__ccr1::ctype"*, i8)**]
  %19 = getelementptr inbounds i8 (%"class.std::__ccr1::ctype"*, i8)*, i8 (%"class.std::__ccr1::ctype"*, i8)** %18, i32 7 ; [#uses=1 type=i8 (%"class.std::__ccr1::ctype"*, i8)**]
  %20 = load i8 (%"class.std::__ccr1::ctype"*, i8)*, i8 (%"class.std::__ccr1::ctype"*, i8)** %19, align 4 ; [#uses=1 type=i8 (%"class.std::__ccr1::ctype"*, i8)*]
  %21 = invoke signext i8 %20(%"class.std::__ccr1::ctype"* %16, i8 signext 10) #17
          to label %25 unwind label %22           ; [#uses=1 type=i8]

; <label>:22:                                     ; preds = %15, %2
  %23 = landingpad { i8*, i32 }
          cleanup                                 ; [#uses=1 type={ i8*, i32 }]
  %24 = call %"class.std::__ccr1::locale"* @_ZNSt6__ccr16localeD1Ev(%"class.std::__ccr1::locale"* nonnull %4) #16 ; [#uses=0 type=%"class.std::__ccr1::locale"*]
  call void @llvm.lifetime.end.p0i8(i64 4, i8* nonnull %12) #1
  resume { i8*, i32 } %23

; <label>:25:                                     ; preds = %15
  %26 = call %"class.std::__ccr1::locale"* @_ZNSt6__ccr16localeD1Ev(%"class.std::__ccr1::locale"* nonnull %4) #16 ; [#uses=0 type=%"class.std::__ccr1::locale"*]
  call void @llvm.lifetime.end.p0i8(i64 4, i8* nonnull %12) #1
  %27 = call dereferenceable(84) %"class.std::__ccr1::basic_ostream"* @_ZNSt6__ccr113basic_ostreamIcNS_11char_traitsIcEEE3putEc(%"class.std::__ccr1::basic_ostream"* nonnull @_ZNSt6__ccr14cerrE, i8 signext %21) #17 ; [#uses=0 type=%"class.std::__ccr1::basic_ostream"*]
  %28 = call dereferenceable(84) %"class.std::__ccr1::basic_ostream"* @_ZNSt6__ccr113basic_ostreamIcNS_11char_traitsIcEEE5flushEv(%"class.std::__ccr1::basic_ostream"* nonnull @_ZNSt6__ccr14cerrE) #17 ; [#uses=0 type=%"class.std::__ccr1::basic_ostream"*]
  %29 = call dereferenceable(84) %"class.std::__ccr1::basic_ostream"* @_ZNSt6__ccr124__put_character_sequenceIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m(%"class.std::__ccr1::basic_ostream"* nonnull dereferenceable(84) @_ZNSt6__ccr14cerrE, i8* getelementptr inbounds ([11 x i8], [11 x i8]* @.str.20, i32 0, i32 0), i32 10) #17 ; [#uses=1 type=%"class.std::__ccr1::basic_ostream"*]
  %30 = call i32 @strlen(i8* %1) #16              ; [#uses=1 type=i32]
  %31 = call dereferenceable(84) %"class.std::__ccr1::basic_ostream"* @_ZNSt6__ccr124__put_character_sequenceIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m(%"class.std::__ccr1::basic_ostream"* nonnull dereferenceable(84) %29, i8* %1, i32 %30) #17 ; [#uses=4 type=%"class.std::__ccr1::basic_ostream"*]
  %32 = bitcast %"class.std::__ccr1::basic_ostream"* %31 to i8** ; [#uses=1 type=i8**]
  %33 = load i8*, i8** %32, align 4, !tbaa !15    ; [#uses=1 type=i8*]
  %34 = getelementptr i8, i8* %33, i32 -12        ; [#uses=1 type=i8*]
  %35 = bitcast i8* %34 to i32*                   ; [#uses=1 type=i32*]
  %36 = load i32, i32* %35, align 4               ; [#uses=1 type=i32]
  %37 = bitcast %"class.std::__ccr1::basic_ostream"* %31 to i8* ; [#uses=1 type=i8*]
  %38 = getelementptr inbounds i8, i8* %37, i32 %36 ; [#uses=1 type=i8*]
  %39 = bitcast %"class.std::__ccr1::locale"* %3 to i8* ; [#uses=3 type=i8*]
  call void @llvm.lifetime.start.p0i8(i64 4, i8* nonnull %39) #1
  %40 = bitcast i8* %38 to %"class.std::__ccr1::ios_base"* ; [#uses=1 type=%"class.std::__ccr1::ios_base"*]
  call void @_ZNKSt6__ccr18ios_base6getlocEv(%"class.std::__ccr1::locale"* nonnull sret %3, %"class.std::__ccr1::ios_base"* %40) #17
  %41 = invoke %"class.std::__ccr1::locale::facet"* @_ZNKSt6__ccr16locale9use_facetERNS0_2idE(%"class.std::__ccr1::locale"* nonnull %3, %"class.std::__ccr1::locale::id"* nonnull dereferenceable(8) @_ZNSt6__ccr15ctypeIcE2idE) #17
          to label %42 unwind label %49           ; [#uses=2 type=%"class.std::__ccr1::locale::facet"*]

; <label>:42:                                     ; preds = %25
  %43 = bitcast %"class.std::__ccr1::locale::facet"* %41 to %"class.std::__ccr1::ctype"* ; [#uses=1 type=%"class.std::__ccr1::ctype"*]
  %44 = bitcast %"class.std::__ccr1::locale::facet"* %41 to i8 (%"class.std::__ccr1::ctype"*, i8)*** ; [#uses=1 type=i8 (%"class.std::__ccr1::ctype"*, i8)***]
  %45 = load i8 (%"class.std::__ccr1::ctype"*, i8)**, i8 (%"class.std::__ccr1::ctype"*, i8)*** %44, align 4, !tbaa !15 ; [#uses=1 type=i8 (%"class.std::__ccr1::ctype"*, i8)**]
  %46 = getelementptr inbounds i8 (%"class.std::__ccr1::ctype"*, i8)*, i8 (%"class.std::__ccr1::ctype"*, i8)** %45, i32 7 ; [#uses=1 type=i8 (%"class.std::__ccr1::ctype"*, i8)**]
  %47 = load i8 (%"class.std::__ccr1::ctype"*, i8)*, i8 (%"class.std::__ccr1::ctype"*, i8)** %46, align 4 ; [#uses=1 type=i8 (%"class.std::__ccr1::ctype"*, i8)*]
  %48 = invoke signext i8 %47(%"class.std::__ccr1::ctype"* %43, i8 signext 10) #17
          to label %52 unwind label %49           ; [#uses=1 type=i8]

; <label>:49:                                     ; preds = %42, %25
  %50 = landingpad { i8*, i32 }
          cleanup                                 ; [#uses=1 type={ i8*, i32 }]
  %51 = call %"class.std::__ccr1::locale"* @_ZNSt6__ccr16localeD1Ev(%"class.std::__ccr1::locale"* nonnull %3) #16 ; [#uses=0 type=%"class.std::__ccr1::locale"*]
  call void @llvm.lifetime.end.p0i8(i64 4, i8* nonnull %39) #1
  resume { i8*, i32 } %50

; <label>:52:                                     ; preds = %42
  %53 = call %"class.std::__ccr1::locale"* @_ZNSt6__ccr16localeD1Ev(%"class.std::__ccr1::locale"* nonnull %3) #16 ; [#uses=0 type=%"class.std::__ccr1::locale"*]
  call void @llvm.lifetime.end.p0i8(i64 4, i8* nonnull %39) #1
  %54 = call dereferenceable(84) %"class.std::__ccr1::basic_ostream"* @_ZNSt6__ccr113basic_ostreamIcNS_11char_traitsIcEEE3putEc(%"class.std::__ccr1::basic_ostream"* nonnull %31, i8 signext %48) #17 ; [#uses=0 type=%"class.std::__ccr1::basic_ostream"*]
  %55 = call dereferenceable(84) %"class.std::__ccr1::basic_ostream"* @_ZNSt6__ccr113basic_ostreamIcNS_11char_traitsIcEEE5flushEv(%"class.std::__ccr1::basic_ostream"* nonnull %31) #17 ; [#uses=0 type=%"class.std::__ccr1::basic_ostream"*]
  %56 = bitcast %"class.std::__ccr1::unique_ptr.22"* %0 to i32* ; [#uses=1 type=i32*]
  store i32 0, i32* %56, align 4, !tbaa !71
  ret void
}

; [#uses=1]
; Function Attrs: optsize
define linkonce_odr void @_ZNSt6__ccr16vectorINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEENS4_IS6_EEE21__push_back_slow_pathIRKS6_EEvOT_(%"class.std::__ccr1::vector"*, %"class.std::__ccr1::basic_string"* dereferenceable(12)) local_unnamed_addr #7 align 2 personality i8* bitcast (i32 (...)* @__gxx_personality_sj0 to i8*) {
  %3 = alloca %"struct.std::__ccr1::__split_buffer", align 4 ; [#uses=8 type=%"struct.std::__ccr1::__split_buffer"*]
  %4 = getelementptr inbounds %"class.std::__ccr1::vector", %"class.std::__ccr1::vector"* %0, i32 0, i32 0, i32 2 ; [#uses=1 type=%"class.std::__ccr1::__compressed_pair.16"*]
  %5 = bitcast %"class.std::__ccr1::__compressed_pair.16"* %4 to %"class.std::__ccr1::allocator.19"* ; [#uses=1 type=%"class.std::__ccr1::allocator.19"*]
  %6 = bitcast %"struct.std::__ccr1::__split_buffer"* %3 to i8* ; [#uses=3 type=i8*]
  call void @llvm.lifetime.start.p0i8(i64 20, i8* nonnull %6) #1
  %7 = getelementptr inbounds %"class.std::__ccr1::vector", %"class.std::__ccr1::vector"* %0, i32 0, i32 0, i32 1 ; [#uses=2 type=%"class.std::__ccr1::basic_string"**]
  %8 = bitcast %"class.std::__ccr1::basic_string"** %7 to i32* ; [#uses=3 type=i32*]
  %9 = load i32, i32* %8, align 4, !tbaa !37      ; [#uses=1 type=i32]
  %10 = bitcast %"class.std::__ccr1::vector"* %0 to i32* ; [#uses=3 type=i32*]
  %11 = load i32, i32* %10, align 4, !tbaa !34    ; [#uses=2 type=i32]
  %12 = sub i32 %9, %11                           ; [#uses=1 type=i32]
  %13 = sdiv exact i32 %12, 12                    ; [#uses=2 type=i32]
  %14 = add nsw i32 %13, 1                        ; [#uses=3 type=i32]
  %15 = icmp ugt i32 %14, 357913941               ; [#uses=1 type=i1]
  br i1 %15, label %16, label %18

; <label>:16:                                     ; preds = %2
  %17 = bitcast %"class.std::__ccr1::vector"* %0 to %"class.std::__ccr1::__vector_base_common"* ; [#uses=1 type=%"class.std::__ccr1::__vector_base_common"*]
  tail call void @_ZNKSt6__ccr120__vector_base_commonILb1EE20__throw_length_errorEv(%"class.std::__ccr1::__vector_base_common"* %17) #20
  unreachable

; <label>:18:                                     ; preds = %2
  %19 = getelementptr inbounds %"class.std::__ccr1::vector", %"class.std::__ccr1::vector"* %0, i32 0, i32 0, i32 2, i32 0, i32 0 ; [#uses=1 type=%"class.std::__ccr1::basic_string"**]
  %20 = bitcast %"class.std::__ccr1::basic_string"** %19 to i32* ; [#uses=3 type=i32*]
  %21 = load i32, i32* %20, align 4, !tbaa !10    ; [#uses=1 type=i32]
  %22 = sub i32 %21, %11                          ; [#uses=1 type=i32]
  %23 = sdiv exact i32 %22, 12                    ; [#uses=2 type=i32]
  %24 = icmp ult i32 %23, 178956970               ; [#uses=1 type=i1]
  br i1 %24, label %25, label %29

; <label>:25:                                     ; preds = %18
  %26 = shl nsw i32 %23, 1                        ; [#uses=2 type=i32]
  %27 = icmp ult i32 %26, %14                     ; [#uses=1 type=i1]
  %28 = select i1 %27, i32 %14, i32 %26           ; [#uses=1 type=i32]
  br label %29

; <label>:29:                                     ; preds = %18, %25
  %30 = phi i32 [ %28, %25 ], [ 357913941, %18 ]  ; [#uses=1 type=i32]
  %31 = call %"struct.std::__ccr1::__split_buffer"* @_ZNSt6__ccr114__split_bufferINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEERNS4_IS6_EEEC2EmmS8_(%"struct.std::__ccr1::__split_buffer"* nonnull %3, i32 %30, i32 %13, %"class.std::__ccr1::allocator.19"* nonnull dereferenceable(1) %5) #17 ; [#uses=0 type=%"struct.std::__ccr1::__split_buffer"*]
  %32 = getelementptr inbounds %"struct.std::__ccr1::__split_buffer", %"struct.std::__ccr1::__split_buffer"* %3, i32 0, i32 2 ; [#uses=5 type=%"class.std::__ccr1::basic_string"**]
  %33 = load %"class.std::__ccr1::basic_string"*, %"class.std::__ccr1::basic_string"** %32, align 4, !tbaa !73 ; [#uses=1 type=%"class.std::__ccr1::basic_string"*]
  %34 = invoke %"class.std::__ccr1::basic_string"* @_ZNSt6__ccr112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEC1ERKS5_(%"class.std::__ccr1::basic_string"* %33, %"class.std::__ccr1::basic_string"* nonnull dereferenceable(12) %1) #17
          to label %35 unwind label %82           ; [#uses=0 type=%"class.std::__ccr1::basic_string"*]

; <label>:35:                                     ; preds = %29
  %36 = load %"class.std::__ccr1::basic_string"*, %"class.std::__ccr1::basic_string"** %32, align 4, !tbaa !73 ; [#uses=1 type=%"class.std::__ccr1::basic_string"*]
  %37 = getelementptr inbounds %"class.std::__ccr1::basic_string", %"class.std::__ccr1::basic_string"* %36, i32 1 ; [#uses=2 type=%"class.std::__ccr1::basic_string"*]
  store %"class.std::__ccr1::basic_string"* %37, %"class.std::__ccr1::basic_string"** %32, align 4, !tbaa !73
  %38 = getelementptr inbounds %"class.std::__ccr1::vector", %"class.std::__ccr1::vector"* %0, i32 0, i32 0, i32 0 ; [#uses=1 type=%"class.std::__ccr1::basic_string"**]
  %39 = load %"class.std::__ccr1::basic_string"*, %"class.std::__ccr1::basic_string"** %38, align 4, !tbaa !34 ; [#uses=3 type=%"class.std::__ccr1::basic_string"*]
  %40 = load %"class.std::__ccr1::basic_string"*, %"class.std::__ccr1::basic_string"** %7, align 4, !tbaa !37 ; [#uses=3 type=%"class.std::__ccr1::basic_string"*]
  %41 = getelementptr inbounds %"struct.std::__ccr1::__split_buffer", %"struct.std::__ccr1::__split_buffer"* %3, i32 0, i32 1 ; [#uses=5 type=%"class.std::__ccr1::basic_string"**]
  %42 = icmp eq %"class.std::__ccr1::basic_string"* %40, %39 ; [#uses=1 type=i1]
  br i1 %42, label %43, label %50

; <label>:43:                                     ; preds = %35
  %44 = ptrtoint %"class.std::__ccr1::basic_string"* %37 to i32 ; [#uses=1 type=i32]
  %45 = ptrtoint %"class.std::__ccr1::basic_string"* %40 to i32 ; [#uses=1 type=i32]
  %46 = ptrtoint %"class.std::__ccr1::basic_string"* %39 to i32 ; [#uses=1 type=i32]
  %47 = bitcast %"class.std::__ccr1::basic_string"** %41 to i32* ; [#uses=2 type=i32*]
  %48 = load i32, i32* %47, align 4, !tbaa !10    ; [#uses=1 type=i32]
  %49 = bitcast %"class.std::__ccr1::basic_string"** %32 to i32* ; [#uses=1 type=i32*]
  br label %69

; <label>:50:                                     ; preds = %35
  %51 = load %"class.std::__ccr1::basic_string"*, %"class.std::__ccr1::basic_string"** %41, align 4, !tbaa !10 ; [#uses=1 type=%"class.std::__ccr1::basic_string"*]
  br label %52

; <label>:52:                                     ; preds = %52, %50
  %53 = phi %"class.std::__ccr1::basic_string"* [ %51, %50 ], [ %60, %52 ] ; [#uses=1 type=%"class.std::__ccr1::basic_string"*]
  %54 = phi %"class.std::__ccr1::basic_string"* [ %40, %50 ], [ %56, %52 ] ; [#uses=1 type=%"class.std::__ccr1::basic_string"*]
  %55 = getelementptr inbounds %"class.std::__ccr1::basic_string", %"class.std::__ccr1::basic_string"* %53, i32 -1 ; [#uses=1 type=%"class.std::__ccr1::basic_string"*]
  %56 = getelementptr inbounds %"class.std::__ccr1::basic_string", %"class.std::__ccr1::basic_string"* %54, i32 -1 ; [#uses=3 type=%"class.std::__ccr1::basic_string"*]
  %57 = bitcast %"class.std::__ccr1::basic_string"* %55 to i8* ; [#uses=1 type=i8*]
  %58 = bitcast %"class.std::__ccr1::basic_string"* %56 to i8* ; [#uses=2 type=i8*]
  call void @llvm.memcpy.p0i8.p0i8.i32(i8* nonnull %57, i8* nonnull %58, i32 12, i32 4, i1 false) #1
  call void @llvm.memset.p0i8.i32(i8* nonnull %58, i8 0, i32 12, i32 4, i1 false) #1
  %59 = load %"class.std::__ccr1::basic_string"*, %"class.std::__ccr1::basic_string"** %41, align 4, !tbaa !10 ; [#uses=1 type=%"class.std::__ccr1::basic_string"*]
  %60 = getelementptr inbounds %"class.std::__ccr1::basic_string", %"class.std::__ccr1::basic_string"* %59, i32 -1 ; [#uses=3 type=%"class.std::__ccr1::basic_string"*]
  store %"class.std::__ccr1::basic_string"* %60, %"class.std::__ccr1::basic_string"** %41, align 4, !tbaa !10
  %61 = icmp eq %"class.std::__ccr1::basic_string"* %56, %39 ; [#uses=1 type=i1]
  br i1 %61, label %62, label %52

; <label>:62:                                     ; preds = %52
  %63 = ptrtoint %"class.std::__ccr1::basic_string"* %60 to i32 ; [#uses=1 type=i32]
  %64 = load i32, i32* %10, align 4, !tbaa !10    ; [#uses=1 type=i32]
  %65 = bitcast %"class.std::__ccr1::basic_string"** %41 to i32* ; [#uses=1 type=i32*]
  %66 = load i32, i32* %8, align 4, !tbaa !10     ; [#uses=1 type=i32]
  %67 = bitcast %"class.std::__ccr1::basic_string"** %32 to i32* ; [#uses=2 type=i32*]
  %68 = load i32, i32* %67, align 4, !tbaa !10    ; [#uses=1 type=i32]
  br label %69

; <label>:69:                                     ; preds = %62, %43
  %70 = phi i32* [ %67, %62 ], [ %49, %43 ]       ; [#uses=1 type=i32*]
  %71 = phi i32 [ %68, %62 ], [ %44, %43 ]        ; [#uses=1 type=i32]
  %72 = phi i32 [ %66, %62 ], [ %45, %43 ]        ; [#uses=1 type=i32]
  %73 = phi i32* [ %65, %62 ], [ %47, %43 ]       ; [#uses=1 type=i32*]
  %74 = phi i32 [ %63, %62 ], [ %48, %43 ]        ; [#uses=1 type=i32]
  %75 = phi i32 [ %64, %62 ], [ %46, %43 ]        ; [#uses=2 type=i32]
  store i32 %74, i32* %10, align 4, !tbaa !10
  store i32 %75, i32* %73, align 4, !tbaa !10
  store i32 %71, i32* %8, align 4, !tbaa !10
  store i32 %72, i32* %70, align 4, !tbaa !10
  %76 = getelementptr inbounds %"struct.std::__ccr1::__split_buffer", %"struct.std::__ccr1::__split_buffer"* %3, i32 0, i32 3, i32 0, i32 0 ; [#uses=1 type=%"class.std::__ccr1::basic_string"**]
  %77 = load i32, i32* %20, align 4, !tbaa !10    ; [#uses=1 type=i32]
  %78 = bitcast %"class.std::__ccr1::basic_string"** %76 to i32* ; [#uses=2 type=i32*]
  %79 = load i32, i32* %78, align 4, !tbaa !10    ; [#uses=1 type=i32]
  store i32 %79, i32* %20, align 4, !tbaa !10
  store i32 %77, i32* %78, align 4, !tbaa !10
  %80 = bitcast %"struct.std::__ccr1::__split_buffer"* %3 to i32* ; [#uses=1 type=i32*]
  store i32 %75, i32* %80, align 4, !tbaa !76
  %81 = call %"struct.std::__ccr1::__split_buffer"* @_ZNSt6__ccr114__split_bufferINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEERNS4_IS6_EEED2Ev(%"struct.std::__ccr1::__split_buffer"* nonnull %3) #16 ; [#uses=0 type=%"struct.std::__ccr1::__split_buffer"*]
  call void @llvm.lifetime.end.p0i8(i64 20, i8* nonnull %6) #1
  ret void

; <label>:82:                                     ; preds = %29
  %83 = landingpad { i8*, i32 }
          cleanup                                 ; [#uses=1 type={ i8*, i32 }]
  %84 = call %"struct.std::__ccr1::__split_buffer"* @_ZNSt6__ccr114__split_bufferINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEERNS4_IS6_EEED2Ev(%"struct.std::__ccr1::__split_buffer"* nonnull %3) #16 ; [#uses=0 type=%"struct.std::__ccr1::__split_buffer"*]
  call void @llvm.lifetime.end.p0i8(i64 20, i8* nonnull %6) #1
  resume { i8*, i32 } %83
}

; [#uses=2]
; Function Attrs: noreturn optsize
declare void @_ZNKSt6__ccr120__vector_base_commonILb1EE20__throw_length_errorEv(%"class.std::__ccr1::__vector_base_common"*) local_unnamed_addr #10

; [#uses=1]
; Function Attrs: optsize
define linkonce_odr %"struct.std::__ccr1::__split_buffer"* @_ZNSt6__ccr114__split_bufferINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEERNS4_IS6_EEEC2EmmS8_(%"struct.std::__ccr1::__split_buffer"* returned, i32, i32, %"class.std::__ccr1::allocator.19"* dereferenceable(1)) unnamed_addr #7 align 2 personality i32 (...)* @__gxx_personality_sj0 {
  %5 = getelementptr inbounds %"struct.std::__ccr1::__split_buffer", %"struct.std::__ccr1::__split_buffer"* %0, i32 0, i32 3, i32 0, i32 0 ; [#uses=2 type=%"class.std::__ccr1::basic_string"**]
  store %"class.std::__ccr1::basic_string"* null, %"class.std::__ccr1::basic_string"** %5, align 4, !tbaa !38
  %6 = getelementptr inbounds %"struct.std::__ccr1::__split_buffer", %"struct.std::__ccr1::__split_buffer"* %0, i32 0, i32 3, i32 1, i32 0 ; [#uses=1 type=%"class.std::__ccr1::allocator.19"**]
  store %"class.std::__ccr1::allocator.19"* %3, %"class.std::__ccr1::allocator.19"** %6, align 4, !tbaa !10
  %7 = icmp eq i32 %1, 0                          ; [#uses=1 type=i1]
  br i1 %7, label %22, label %8

; <label>:8:                                      ; preds = %4
  %9 = icmp ugt i32 %1, 357913941                 ; [#uses=1 type=i1]
  br i1 %9, label %10, label %18

; <label>:10:                                     ; preds = %8
  %11 = tail call i8* @__cxa_allocate_exception(i32 8) #1 ; [#uses=4 type=i8*]
  %12 = bitcast i8* %11 to %"class.std::logic_error"* ; [#uses=1 type=%"class.std::logic_error"*]
  %13 = invoke %"class.std::logic_error"* @_ZNSt11logic_errorC2EPKc(%"class.std::logic_error"* %12, i8* getelementptr inbounds ([68 x i8], [68 x i8]* @.str.21, i32 0, i32 0)) #17
          to label %14 unwind label %16           ; [#uses=0 type=%"class.std::logic_error"*]

; <label>:14:                                     ; preds = %10
  %15 = bitcast i8* %11 to i32 (...)***           ; [#uses=1 type=i32 (...)***]
  store i32 (...)** bitcast (i8** getelementptr inbounds ({ [5 x i8*] }, { [5 x i8*] }* @_ZTVSt12length_error, i32 0, inrange i32 0, i32 2) to i32 (...)**), i32 (...)*** %15, align 4, !tbaa !15
  tail call void @__cxa_throw(i8* %11, i8* bitcast (i8** @_ZTISt12length_error to i8*), i8* bitcast (%"class.std::length_error"* (%"class.std::length_error"*)* @_ZNSt12length_errorD1Ev to i8*)) #21
  unreachable

; <label>:16:                                     ; preds = %10
  %17 = landingpad { i8*, i32 }
          cleanup                                 ; [#uses=1 type={ i8*, i32 }]
  tail call void @__cxa_free_exception(i8* %11) #1
  resume { i8*, i32 } %17

; <label>:18:                                     ; preds = %8
  %19 = mul i32 %1, 12                            ; [#uses=1 type=i32]
  %20 = tail call i8* @_Znwm(i32 %19) #18         ; [#uses=1 type=i8*]
  %21 = bitcast i8* %20 to %"class.std::__ccr1::basic_string"* ; [#uses=1 type=%"class.std::__ccr1::basic_string"*]
  br label %22

; <label>:22:                                     ; preds = %4, %18
  %23 = phi %"class.std::__ccr1::basic_string"* [ %21, %18 ], [ null, %4 ] ; [#uses=3 type=%"class.std::__ccr1::basic_string"*]
  %24 = getelementptr inbounds %"struct.std::__ccr1::__split_buffer", %"struct.std::__ccr1::__split_buffer"* %0, i32 0, i32 0 ; [#uses=1 type=%"class.std::__ccr1::basic_string"**]
  store %"class.std::__ccr1::basic_string"* %23, %"class.std::__ccr1::basic_string"** %24, align 4, !tbaa !76
  %25 = getelementptr inbounds %"class.std::__ccr1::basic_string", %"class.std::__ccr1::basic_string"* %23, i32 %2 ; [#uses=2 type=%"class.std::__ccr1::basic_string"*]
  %26 = getelementptr inbounds %"struct.std::__ccr1::__split_buffer", %"struct.std::__ccr1::__split_buffer"* %0, i32 0, i32 2 ; [#uses=1 type=%"class.std::__ccr1::basic_string"**]
  store %"class.std::__ccr1::basic_string"* %25, %"class.std::__ccr1::basic_string"** %26, align 4, !tbaa !73
  %27 = getelementptr inbounds %"struct.std::__ccr1::__split_buffer", %"struct.std::__ccr1::__split_buffer"* %0, i32 0, i32 1 ; [#uses=1 type=%"class.std::__ccr1::basic_string"**]
  store %"class.std::__ccr1::basic_string"* %25, %"class.std::__ccr1::basic_string"** %27, align 4, !tbaa !77
  %28 = getelementptr inbounds %"class.std::__ccr1::basic_string", %"class.std::__ccr1::basic_string"* %23, i32 %1 ; [#uses=1 type=%"class.std::__ccr1::basic_string"*]
  store %"class.std::__ccr1::basic_string"* %28, %"class.std::__ccr1::basic_string"** %5, align 4, !tbaa !10
  ret %"struct.std::__ccr1::__split_buffer"* %0
}

; [#uses=2]
declare i8* @__cxa_allocate_exception(i32) local_unnamed_addr

; [#uses=2]
declare void @__cxa_free_exception(i8*) local_unnamed_addr

; [#uses=1]
; Function Attrs: nounwind optsize
declare %"class.std::length_error"* @_ZNSt12length_errorD1Ev(%"class.std::length_error"* returned) unnamed_addr #3

; [#uses=2]
declare void @__cxa_throw(i8*, i8*, i8*) local_unnamed_addr

; [#uses=2]
; Function Attrs: optsize
declare %"class.std::logic_error"* @_ZNSt11logic_errorC2EPKc(%"class.std::logic_error"* returned, i8*) unnamed_addr #8

; [#uses=13]
; Function Attrs: nobuiltin optsize
declare noalias nonnull i8* @_Znwm(i32) local_unnamed_addr #11

; [#uses=2]
; Function Attrs: nounwind optsize
define linkonce_odr %"struct.std::__ccr1::__split_buffer"* @_ZNSt6__ccr114__split_bufferINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEERNS4_IS6_EEED2Ev(%"struct.std::__ccr1::__split_buffer"* returned) unnamed_addr #0 align 2 personality i8* bitcast (i32 (...)* @__gxx_personality_sj0 to i8*) {
  %2 = getelementptr inbounds %"struct.std::__ccr1::__split_buffer", %"struct.std::__ccr1::__split_buffer"* %0, i32 0, i32 1 ; [#uses=1 type=%"class.std::__ccr1::basic_string"**]
  %3 = load %"class.std::__ccr1::basic_string"*, %"class.std::__ccr1::basic_string"** %2, align 4, !tbaa !77 ; [#uses=2 type=%"class.std::__ccr1::basic_string"*]
  %4 = getelementptr inbounds %"struct.std::__ccr1::__split_buffer", %"struct.std::__ccr1::__split_buffer"* %0, i32 0, i32 2 ; [#uses=3 type=%"class.std::__ccr1::basic_string"**]
  %5 = load %"class.std::__ccr1::basic_string"*, %"class.std::__ccr1::basic_string"** %4, align 4, !tbaa !73 ; [#uses=2 type=%"class.std::__ccr1::basic_string"*]
  %6 = icmp eq %"class.std::__ccr1::basic_string"* %5, %3 ; [#uses=1 type=i1]
  br i1 %6, label %22, label %7

; <label>:7:                                      ; preds = %1
  br label %8

; <label>:8:                                      ; preds = %7, %19
  %9 = phi %"class.std::__ccr1::basic_string"* [ %20, %19 ], [ %5, %7 ] ; [#uses=2 type=%"class.std::__ccr1::basic_string"*]
  %10 = getelementptr inbounds %"class.std::__ccr1::basic_string", %"class.std::__ccr1::basic_string"* %9, i32 -1 ; [#uses=3 type=%"class.std::__ccr1::basic_string"*]
  store %"class.std::__ccr1::basic_string"* %10, %"class.std::__ccr1::basic_string"** %4, align 4, !tbaa !73
  %11 = bitcast %"class.std::__ccr1::basic_string"* %10 to i8* ; [#uses=1 type=i8*]
  %12 = load i8, i8* %11, align 4, !tbaa !4       ; [#uses=1 type=i8]
  %13 = and i8 %12, 1                             ; [#uses=1 type=i8]
  %14 = icmp eq i8 %13, 0                         ; [#uses=1 type=i1]
  br i1 %14, label %19, label %15

; <label>:15:                                     ; preds = %8
  %16 = getelementptr inbounds %"class.std::__ccr1::basic_string", %"class.std::__ccr1::basic_string"* %9, i32 -1, i32 0, i32 0, i32 0, i32 0, i32 0, i32 2 ; [#uses=1 type=i8**]
  %17 = load i8*, i8** %16, align 4, !tbaa !4     ; [#uses=1 type=i8*]
  tail call void @_ZdlPv(i8* %17) #15
  %18 = load %"class.std::__ccr1::basic_string"*, %"class.std::__ccr1::basic_string"** %4, align 4, !tbaa !73 ; [#uses=1 type=%"class.std::__ccr1::basic_string"*]
  br label %19

; <label>:19:                                     ; preds = %15, %8
  %20 = phi %"class.std::__ccr1::basic_string"* [ %18, %15 ], [ %10, %8 ] ; [#uses=2 type=%"class.std::__ccr1::basic_string"*]
  %21 = icmp eq %"class.std::__ccr1::basic_string"* %20, %3 ; [#uses=1 type=i1]
  br i1 %21, label %22, label %8

; <label>:22:                                     ; preds = %19, %1
  %23 = getelementptr inbounds %"struct.std::__ccr1::__split_buffer", %"struct.std::__ccr1::__split_buffer"* %0, i32 0, i32 0 ; [#uses=1 type=%"class.std::__ccr1::basic_string"**]
  %24 = load %"class.std::__ccr1::basic_string"*, %"class.std::__ccr1::basic_string"** %23, align 4, !tbaa !76 ; [#uses=2 type=%"class.std::__ccr1::basic_string"*]
  %25 = icmp eq %"class.std::__ccr1::basic_string"* %24, null ; [#uses=1 type=i1]
  br i1 %25, label %28, label %26

; <label>:26:                                     ; preds = %22
  %27 = bitcast %"class.std::__ccr1::basic_string"* %24 to i8* ; [#uses=1 type=i8*]
  tail call void @_ZdlPv(i8* %27) #15
  br label %28

; <label>:28:                                     ; preds = %22, %26
  ret %"struct.std::__ccr1::__split_buffer"* %0
}

; [#uses=2]
; Function Attrs: optsize
define internal fastcc void @_ZL12ParsePrimaryv(%"class.std::__ccr1::unique_ptr.22"* noalias nocapture sret) unnamed_addr #7 personality i32 (...)* @__gxx_personality_sj0 {
  %2 = alloca %"class.std::__ccr1::basic_string", align 4 ; [#uses=6 type=%"class.std::__ccr1::basic_string"*]
  %3 = alloca %"class.std::__ccr1::vector.42", align 4 ; [#uses=9 type=%"class.std::__ccr1::vector.42"*]
  %4 = alloca %"class.std::__ccr1::unique_ptr.22", align 4 ; [#uses=3 type=%"class.std::__ccr1::unique_ptr.22"*]
  %5 = alloca %"class.std::__ccr1::unique_ptr.22", align 4 ; [#uses=3 type=%"class.std::__ccr1::unique_ptr.22"*]
  %6 = load %struct.__sFILE*, %struct.__sFILE** @__stderrp, align 4, !tbaa !10 ; [#uses=1 type=%struct.__sFILE*]
  %7 = tail call i32 (%struct.__sFILE*, i8*, ...) @fprintf(%struct.__sFILE* %6, i8* getelementptr inbounds ([34 x i8], [34 x i8]* @.str.3, i32 0, i32 0), i8* getelementptr inbounds ([13 x i8], [13 x i8]* @__func__._ZL12ParsePrimaryv, i32 0, i32 0), i32 493, i8* getelementptr inbounds ([148 x i8], [148 x i8]* @.str.4, i32 0, i32 0)) #17 ; [#uses=0 type=i32]
  %8 = load i32, i32* @_ZL6CurTok, align 4, !tbaa !13 ; [#uses=1 type=i32]
  switch i32 %8, label %9 [
    i32 -4, label %10
    i32 -5, label %332
    i32 40, label %351
  ]

; <label>:9:                                      ; preds = %1
  tail call fastcc void @_Z8LogErrorPKc(%"class.std::__ccr1::unique_ptr.22"* sret %0, i8* getelementptr inbounds ([43 x i8], [43 x i8]* @.str.22, i32 0, i32 0)) #17
  br label %382

; <label>:10:                                     ; preds = %1
  %11 = load %struct.__sFILE*, %struct.__sFILE** @__stderrp, align 4, !tbaa !10, !noalias !78 ; [#uses=1 type=%struct.__sFILE*]
  %12 = tail call i32 (%struct.__sFILE*, i8*, ...) @fprintf(%struct.__sFILE* %11, i8* getelementptr inbounds ([34 x i8], [34 x i8]* @.str.3, i32 0, i32 0), i8* getelementptr inbounds ([20 x i8], [20 x i8]* @__func__._ZL19ParseIdentifierExprv, i32 0, i32 0), i32 451, i8* getelementptr inbounds ([148 x i8], [148 x i8]* @.str.4, i32 0, i32 0)) #17, !noalias !78 ; [#uses=0 type=i32]
  %13 = bitcast %"class.std::__ccr1::basic_string"* %2 to i8* ; [#uses=5 type=i8*]
  call void @llvm.lifetime.start.p0i8(i64 12, i8* nonnull %13) #1, !noalias !78
  %14 = call %"class.std::__ccr1::basic_string"* @_ZNSt6__ccr112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEC1ERKS5_(%"class.std::__ccr1::basic_string"* nonnull %2, %"class.std::__ccr1::basic_string"* nonnull dereferenceable(12) @_ZL13IdentifierStr) #17, !noalias !78 ; [#uses=0 type=%"class.std::__ccr1::basic_string"*]
  %15 = invoke fastcc i32 @_ZL6gettokv() #17
          to label %16 unwind label %30, !noalias !78 ; [#uses=2 type=i32]

; <label>:16:                                     ; preds = %10
  store i32 %15, i32* @_ZL6CurTok, align 4, !tbaa !13, !noalias !78
  %17 = icmp eq i32 %15, 40                       ; [#uses=1 type=i1]
  br i1 %17, label %40, label %18

; <label>:18:                                     ; preds = %16
  %19 = invoke i8* @_Znwm(i32 16) #18
          to label %20 unwind label %34, !noalias !78 ; [#uses=4 type=i8*]

; <label>:20:                                     ; preds = %18
  %21 = bitcast i8* %19 to i32 (...)***           ; [#uses=1 type=i32 (...)***]
  store i32 (...)** bitcast (i8** getelementptr inbounds ({ [4 x i8*] }, { [4 x i8*] }* @_ZTVN12_GLOBAL__N_115VariableExprASTE, i32 0, inrange i32 0, i32 2) to i32 (...)**), i32 (...)*** %21, align 4, !tbaa !15, !noalias !81
  %22 = getelementptr inbounds i8, i8* %19, i32 4 ; [#uses=1 type=i8*]
  %23 = bitcast i8* %22 to %"class.std::__ccr1::basic_string"* ; [#uses=1 type=%"class.std::__ccr1::basic_string"*]
  %24 = invoke %"class.std::__ccr1::basic_string"* @_ZNSt6__ccr112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEC1ERKS5_(%"class.std::__ccr1::basic_string"* nonnull %23, %"class.std::__ccr1::basic_string"* nonnull dereferenceable(12) %2) #17
          to label %27 unwind label %25, !noalias !81 ; [#uses=0 type=%"class.std::__ccr1::basic_string"*]

; <label>:25:                                     ; preds = %20
  %26 = landingpad { i8*, i32 }
          cleanup                                 ; [#uses=1 type={ i8*, i32 }]
  call void @_ZdlPv(i8* nonnull %19) #15, !noalias !81
  br label %36

; <label>:27:                                     ; preds = %20
  %28 = ptrtoint i8* %19 to i32                   ; [#uses=1 type=i32]
  %29 = bitcast %"class.std::__ccr1::unique_ptr.22"* %0 to i32* ; [#uses=1 type=i32*]
  store i32 %28, i32* %29, align 4, !tbaa !71, !alias.scope !78
  br label %312

; <label>:30:                                     ; preds = %40, %10
  %31 = landingpad { i8*, i32 }
          cleanup                                 ; [#uses=2 type={ i8*, i32 }]
  %32 = extractvalue { i8*, i32 } %31, 0          ; [#uses=1 type=i8*]
  %33 = extractvalue { i8*, i32 } %31, 1          ; [#uses=1 type=i32]
  br label %319

; <label>:34:                                     ; preds = %18
  %35 = landingpad { i8*, i32 }
          cleanup                                 ; [#uses=1 type={ i8*, i32 }]
  br label %36

; <label>:36:                                     ; preds = %34, %25
  %37 = phi { i8*, i32 } [ %35, %34 ], [ %26, %25 ] ; [#uses=2 type={ i8*, i32 }]
  %38 = extractvalue { i8*, i32 } %37, 0          ; [#uses=1 type=i8*]
  %39 = extractvalue { i8*, i32 } %37, 1          ; [#uses=1 type=i32]
  br label %319

; <label>:40:                                     ; preds = %16
  %41 = invoke fastcc i32 @_ZL6gettokv() #17
          to label %42 unwind label %30, !noalias !78 ; [#uses=2 type=i32]

; <label>:42:                                     ; preds = %40
  store i32 %41, i32* @_ZL6CurTok, align 4, !tbaa !13, !noalias !78
  %43 = bitcast %"class.std::__ccr1::vector.42"* %3 to i8* ; [#uses=3 type=i8*]
  call void @llvm.lifetime.start.p0i8(i64 12, i8* nonnull %43) #1, !noalias !78
  %44 = getelementptr inbounds %"class.std::__ccr1::vector.42", %"class.std::__ccr1::vector.42"* %3, i32 0, i32 0, i32 0 ; [#uses=4 type=%"class.std::__ccr1::unique_ptr.22"**]
  store %"class.std::__ccr1::unique_ptr.22"* null, %"class.std::__ccr1::unique_ptr.22"** %44, align 4, !tbaa !84, !noalias !78
  %45 = getelementptr inbounds %"class.std::__ccr1::vector.42", %"class.std::__ccr1::vector.42"* %3, i32 0, i32 0, i32 1 ; [#uses=11 type=%"class.std::__ccr1::unique_ptr.22"**]
  store %"class.std::__ccr1::unique_ptr.22"* null, %"class.std::__ccr1::unique_ptr.22"** %45, align 4, !tbaa !87, !noalias !78
  %46 = getelementptr inbounds %"class.std::__ccr1::vector.42", %"class.std::__ccr1::vector.42"* %3, i32 0, i32 0, i32 2, i32 0, i32 0 ; [#uses=5 type=%"class.std::__ccr1::unique_ptr.22"**]
  store %"class.std::__ccr1::unique_ptr.22"* null, %"class.std::__ccr1::unique_ptr.22"** %46, align 4, !tbaa !88, !noalias !78
  %47 = icmp eq i32 %41, 41                       ; [#uses=1 type=i1]
  br i1 %47, label %202, label %48

; <label>:48:                                     ; preds = %42
  %49 = bitcast %"class.std::__ccr1::unique_ptr.22"* %4 to i8* ; [#uses=4 type=i8*]
  %50 = getelementptr inbounds %"class.std::__ccr1::unique_ptr.22", %"class.std::__ccr1::unique_ptr.22"* %4, i32 0, i32 0, i32 0, i32 0 ; [#uses=6 type=%"class.(anonymous namespace)::ExprAST"**]
  %51 = bitcast %"class.std::__ccr1::unique_ptr.22"** %45 to i32* ; [#uses=2 type=i32*]
  %52 = bitcast %"class.std::__ccr1::vector.42"* %3 to i32* ; [#uses=4 type=i32*]
  %53 = bitcast %"class.std::__ccr1::unique_ptr.22"** %46 to i32* ; [#uses=2 type=i32*]
  br label %54

; <label>:54:                                     ; preds = %201, %48
  call void @llvm.lifetime.start.p0i8(i64 4, i8* nonnull %49) #1, !noalias !78
  invoke fastcc void @_ZL15ParseExpressionv(%"class.std::__ccr1::unique_ptr.22"* nonnull sret %4) #17
          to label %55 unwind label %162, !noalias !78

; <label>:55:                                     ; preds = %54
  %56 = load %"class.(anonymous namespace)::ExprAST"*, %"class.(anonymous namespace)::ExprAST"** %50, align 4, !tbaa !10, !noalias !78 ; [#uses=4 type=%"class.(anonymous namespace)::ExprAST"*]
  %57 = icmp eq %"class.(anonymous namespace)::ExprAST"* %56, null ; [#uses=1 type=i1]
  %58 = ptrtoint %"class.(anonymous namespace)::ExprAST"* %56 to i32 ; [#uses=2 type=i32]
  br i1 %57, label %178, label %59

; <label>:59:                                     ; preds = %55
  %60 = load %"class.std::__ccr1::unique_ptr.22"*, %"class.std::__ccr1::unique_ptr.22"** %45, align 4, !tbaa !87, !noalias !78 ; [#uses=7 type=%"class.std::__ccr1::unique_ptr.22"*]
  %61 = load %"class.std::__ccr1::unique_ptr.22"*, %"class.std::__ccr1::unique_ptr.22"** %46, align 4, !tbaa !10, !noalias !78 ; [#uses=2 type=%"class.std::__ccr1::unique_ptr.22"*]
  %62 = icmp ult %"class.std::__ccr1::unique_ptr.22"* %60, %61 ; [#uses=1 type=i1]
  %63 = ptrtoint %"class.std::__ccr1::unique_ptr.22"* %61 to i32 ; [#uses=1 type=i32]
  br i1 %62, label %64, label %67

; <label>:64:                                     ; preds = %59
  %65 = bitcast %"class.std::__ccr1::unique_ptr.22"* %60 to i32* ; [#uses=1 type=i32*]
  store i32 %58, i32* %65, align 4, !tbaa !71, !noalias !78
  %66 = getelementptr inbounds %"class.std::__ccr1::unique_ptr.22", %"class.std::__ccr1::unique_ptr.22"* %60, i32 1 ; [#uses=1 type=%"class.std::__ccr1::unique_ptr.22"*]
  store %"class.std::__ccr1::unique_ptr.22"* %66, %"class.std::__ccr1::unique_ptr.22"** %45, align 4, !tbaa !87, !noalias !78
  store %"class.(anonymous namespace)::ExprAST"* null, %"class.(anonymous namespace)::ExprAST"** %50, align 4, !tbaa !10, !noalias !78
  br label %185

; <label>:67:                                     ; preds = %59
  %68 = ptrtoint %"class.std::__ccr1::unique_ptr.22"* %60 to i32 ; [#uses=1 type=i32]
  %69 = load i32, i32* %52, align 4, !tbaa !84, !noalias !78 ; [#uses=5 type=i32]
  %70 = sub i32 %68, %69                          ; [#uses=1 type=i32]
  %71 = ashr exact i32 %70, 2                     ; [#uses=3 type=i32]
  %72 = add nsw i32 %71, 1                        ; [#uses=3 type=i32]
  %73 = icmp ugt i32 %72, 1073741823              ; [#uses=1 type=i1]
  %74 = inttoptr i32 %69 to %"class.std::__ccr1::unique_ptr.22"* ; [#uses=2 type=%"class.std::__ccr1::unique_ptr.22"*]
  br i1 %73, label %75, label %78

; <label>:75:                                     ; preds = %67
  %76 = bitcast %"class.std::__ccr1::vector.42"* %3 to %"class.std::__ccr1::__vector_base_common"* ; [#uses=1 type=%"class.std::__ccr1::__vector_base_common"*]
  invoke void @_ZNKSt6__ccr120__vector_base_commonILb1EE20__throw_length_errorEv(%"class.std::__ccr1::__vector_base_common"* nonnull %76) #20
          to label %77 unwind label %168, !noalias !78

; <label>:77:                                     ; preds = %75
  unreachable

; <label>:78:                                     ; preds = %67
  %79 = sub i32 %63, %69                          ; [#uses=2 type=i32]
  %80 = ashr exact i32 %79, 2                     ; [#uses=1 type=i32]
  %81 = icmp ult i32 %80, 536870911               ; [#uses=1 type=i1]
  br i1 %81, label %82, label %98

; <label>:82:                                     ; preds = %78
  %83 = ashr exact i32 %79, 1                     ; [#uses=2 type=i32]
  %84 = icmp ult i32 %83, %72                     ; [#uses=1 type=i1]
  %85 = select i1 %84, i32 %72, i32 %83           ; [#uses=3 type=i32]
  %86 = icmp eq i32 %85, 0                        ; [#uses=1 type=i1]
  br i1 %86, label %104, label %87

; <label>:87:                                     ; preds = %82
  %88 = icmp ugt i32 %85, 1073741823              ; [#uses=1 type=i1]
  br i1 %88, label %89, label %98

; <label>:89:                                     ; preds = %87
  %90 = call i8* @__cxa_allocate_exception(i32 8) #1, !noalias !78 ; [#uses=4 type=i8*]
  %91 = bitcast i8* %90 to %"class.std::logic_error"* ; [#uses=1 type=%"class.std::logic_error"*]
  %92 = invoke %"class.std::logic_error"* @_ZNSt11logic_errorC2EPKc(%"class.std::logic_error"* %91, i8* getelementptr inbounds ([68 x i8], [68 x i8]* @.str.21, i32 0, i32 0)) #17
          to label %93 unwind label %96, !noalias !78 ; [#uses=0 type=%"class.std::logic_error"*]

; <label>:93:                                     ; preds = %89
  %94 = bitcast i8* %90 to i32 (...)***           ; [#uses=1 type=i32 (...)***]
  store i32 (...)** bitcast (i8** getelementptr inbounds ({ [5 x i8*] }, { [5 x i8*] }* @_ZTVSt12length_error, i32 0, inrange i32 0, i32 2) to i32 (...)**), i32 (...)*** %94, align 4, !tbaa !15, !noalias !78
  invoke void @__cxa_throw(i8* %90, i8* bitcast (i8** @_ZTISt12length_error to i8*), i8* bitcast (%"class.std::length_error"* (%"class.std::length_error"*)* @_ZNSt12length_errorD1Ev to i8*)) #21
          to label %95 unwind label %168, !noalias !78

; <label>:95:                                     ; preds = %93
  unreachable

; <label>:96:                                     ; preds = %89
  %97 = landingpad { i8*, i32 }
          cleanup                                 ; [#uses=1 type={ i8*, i32 }]
  call void @__cxa_free_exception(i8* %90) #1, !noalias !78
  br label %170

; <label>:98:                                     ; preds = %87, %78
  %99 = phi i32 [ %85, %87 ], [ 1073741823, %78 ] ; [#uses=2 type=i32]
  %100 = shl i32 %99, 2                           ; [#uses=1 type=i32]
  %101 = invoke i8* @_Znwm(i32 %100) #18
          to label %102 unwind label %166, !noalias !78 ; [#uses=1 type=i8*]

; <label>:102:                                    ; preds = %98
  %103 = bitcast i8* %101 to %"class.std::__ccr1::unique_ptr.22"* ; [#uses=1 type=%"class.std::__ccr1::unique_ptr.22"*]
  br label %104

; <label>:104:                                    ; preds = %102, %82
  %105 = phi i32 [ %99, %102 ], [ 0, %82 ]        ; [#uses=1 type=i32]
  %106 = phi %"class.std::__ccr1::unique_ptr.22"* [ %103, %102 ], [ null, %82 ] ; [#uses=3 type=%"class.std::__ccr1::unique_ptr.22"*]
  %107 = getelementptr inbounds %"class.std::__ccr1::unique_ptr.22", %"class.std::__ccr1::unique_ptr.22"* %106, i32 %71 ; [#uses=4 type=%"class.std::__ccr1::unique_ptr.22"*]
  %108 = getelementptr inbounds %"class.std::__ccr1::unique_ptr.22", %"class.std::__ccr1::unique_ptr.22"* %106, i32 %105 ; [#uses=1 type=%"class.std::__ccr1::unique_ptr.22"*]
  %109 = ptrtoint %"class.std::__ccr1::unique_ptr.22"* %108 to i32 ; [#uses=2 type=i32]
  store %"class.(anonymous namespace)::ExprAST"* null, %"class.(anonymous namespace)::ExprAST"** %50, align 4, !tbaa !10, !noalias !78
  %110 = bitcast %"class.std::__ccr1::unique_ptr.22"* %107 to i32* ; [#uses=1 type=i32*]
  store i32 %58, i32* %110, align 4, !tbaa !71, !noalias !78
  %111 = getelementptr inbounds %"class.std::__ccr1::unique_ptr.22", %"class.std::__ccr1::unique_ptr.22"* %107, i32 1 ; [#uses=1 type=%"class.std::__ccr1::unique_ptr.22"*]
  %112 = ptrtoint %"class.std::__ccr1::unique_ptr.22"* %111 to i32 ; [#uses=2 type=i32]
  %113 = icmp eq %"class.std::__ccr1::unique_ptr.22"* %60, %74 ; [#uses=1 type=i1]
  br i1 %113, label %114, label %116

; <label>:114:                                    ; preds = %104
  %115 = ptrtoint %"class.std::__ccr1::unique_ptr.22"* %107 to i32 ; [#uses=1 type=i32]
  store i32 %115, i32* %52, align 4, !tbaa !10, !noalias !78
  store i32 %112, i32* %51, align 4, !tbaa !10, !noalias !78
  store i32 %109, i32* %53, align 4, !tbaa !10, !noalias !78
  br label %154

; <label>:116:                                    ; preds = %104
  %117 = getelementptr %"class.std::__ccr1::unique_ptr.22", %"class.std::__ccr1::unique_ptr.22"* %60, i32 -1, i32 0, i32 0, i32 0 ; [#uses=1 type=%"class.(anonymous namespace)::ExprAST"**]
  %118 = ptrtoint %"class.(anonymous namespace)::ExprAST"** %117 to i32 ; [#uses=1 type=i32]
  br label %119

; <label>:119:                                    ; preds = %119, %116
  %120 = phi %"class.std::__ccr1::unique_ptr.22"* [ %107, %116 ], [ %122, %119 ] ; [#uses=1 type=%"class.std::__ccr1::unique_ptr.22"*]
  %121 = phi %"class.std::__ccr1::unique_ptr.22"* [ %60, %116 ], [ %123, %119 ] ; [#uses=1 type=%"class.std::__ccr1::unique_ptr.22"*]
  %122 = getelementptr inbounds %"class.std::__ccr1::unique_ptr.22", %"class.std::__ccr1::unique_ptr.22"* %120, i32 -1 ; [#uses=2 type=%"class.std::__ccr1::unique_ptr.22"*]
  %123 = getelementptr inbounds %"class.std::__ccr1::unique_ptr.22", %"class.std::__ccr1::unique_ptr.22"* %121, i32 -1 ; [#uses=4 type=%"class.std::__ccr1::unique_ptr.22"*]
  %124 = getelementptr inbounds %"class.std::__ccr1::unique_ptr.22", %"class.std::__ccr1::unique_ptr.22"* %123, i32 0, i32 0, i32 0, i32 0 ; [#uses=1 type=%"class.(anonymous namespace)::ExprAST"**]
  %125 = bitcast %"class.std::__ccr1::unique_ptr.22"* %123 to i32* ; [#uses=1 type=i32*]
  %126 = load i32, i32* %125, align 4, !tbaa !10, !noalias !78 ; [#uses=1 type=i32]
  store %"class.(anonymous namespace)::ExprAST"* null, %"class.(anonymous namespace)::ExprAST"** %124, align 4, !tbaa !10, !noalias !78
  %127 = bitcast %"class.std::__ccr1::unique_ptr.22"* %122 to i32* ; [#uses=1 type=i32*]
  store i32 %126, i32* %127, align 4, !tbaa !71, !noalias !78
  %128 = icmp eq %"class.std::__ccr1::unique_ptr.22"* %123, %74 ; [#uses=1 type=i1]
  br i1 %128, label %129, label %119

; <label>:129:                                    ; preds = %119
  %130 = sub i32 %118, %69                        ; [#uses=1 type=i32]
  %131 = lshr i32 %130, 2                         ; [#uses=1 type=i32]
  %132 = add nsw i32 %71, -1                      ; [#uses=1 type=i32]
  %133 = sub nsw i32 %132, %131                   ; [#uses=1 type=i32]
  %134 = getelementptr %"class.std::__ccr1::unique_ptr.22", %"class.std::__ccr1::unique_ptr.22"* %106, i32 %133 ; [#uses=1 type=%"class.std::__ccr1::unique_ptr.22"*]
  %135 = load i32, i32* %52, align 4, !tbaa !10, !noalias !78 ; [#uses=3 type=i32]
  %136 = load %"class.std::__ccr1::unique_ptr.22"*, %"class.std::__ccr1::unique_ptr.22"** %45, align 4, !tbaa !10, !noalias !78 ; [#uses=2 type=%"class.std::__ccr1::unique_ptr.22"*]
  %137 = inttoptr i32 %135 to %"class.std::__ccr1::unique_ptr.22"* ; [#uses=2 type=%"class.std::__ccr1::unique_ptr.22"*]
  %138 = ptrtoint %"class.std::__ccr1::unique_ptr.22"* %134 to i32 ; [#uses=1 type=i32]
  store i32 %138, i32* %52, align 4, !tbaa !10, !noalias !78
  store i32 %112, i32* %51, align 4, !tbaa !10, !noalias !78
  store i32 %109, i32* %53, align 4, !tbaa !10, !noalias !78
  %139 = icmp eq %"class.std::__ccr1::unique_ptr.22"* %136, %137 ; [#uses=1 type=i1]
  br i1 %139, label %154, label %140

; <label>:140:                                    ; preds = %129
  br label %141

; <label>:141:                                    ; preds = %140, %152
  %142 = phi %"class.std::__ccr1::unique_ptr.22"* [ %143, %152 ], [ %136, %140 ] ; [#uses=1 type=%"class.std::__ccr1::unique_ptr.22"*]
  %143 = getelementptr inbounds %"class.std::__ccr1::unique_ptr.22", %"class.std::__ccr1::unique_ptr.22"* %142, i32 -1 ; [#uses=3 type=%"class.std::__ccr1::unique_ptr.22"*]
  %144 = getelementptr inbounds %"class.std::__ccr1::unique_ptr.22", %"class.std::__ccr1::unique_ptr.22"* %143, i32 0, i32 0, i32 0, i32 0 ; [#uses=2 type=%"class.(anonymous namespace)::ExprAST"**]
  %145 = load %"class.(anonymous namespace)::ExprAST"*, %"class.(anonymous namespace)::ExprAST"** %144, align 4, !tbaa !10, !noalias !78 ; [#uses=3 type=%"class.(anonymous namespace)::ExprAST"*]
  store %"class.(anonymous namespace)::ExprAST"* null, %"class.(anonymous namespace)::ExprAST"** %144, align 4, !tbaa !10, !noalias !78
  %146 = icmp eq %"class.(anonymous namespace)::ExprAST"* %145, null ; [#uses=1 type=i1]
  br i1 %146, label %152, label %147

; <label>:147:                                    ; preds = %141
  %148 = bitcast %"class.(anonymous namespace)::ExprAST"* %145 to void (%"class.(anonymous namespace)::ExprAST"*)*** ; [#uses=1 type=void (%"class.(anonymous namespace)::ExprAST"*)***]
  %149 = load void (%"class.(anonymous namespace)::ExprAST"*)**, void (%"class.(anonymous namespace)::ExprAST"*)*** %148, align 4, !tbaa !15, !noalias !78 ; [#uses=1 type=void (%"class.(anonymous namespace)::ExprAST"*)**]
  %150 = getelementptr inbounds void (%"class.(anonymous namespace)::ExprAST"*)*, void (%"class.(anonymous namespace)::ExprAST"*)** %149, i32 1 ; [#uses=1 type=void (%"class.(anonymous namespace)::ExprAST"*)**]
  %151 = load void (%"class.(anonymous namespace)::ExprAST"*)*, void (%"class.(anonymous namespace)::ExprAST"*)** %150, align 4, !noalias !78 ; [#uses=1 type=void (%"class.(anonymous namespace)::ExprAST"*)*]
  call void %151(%"class.(anonymous namespace)::ExprAST"* nonnull %145) #16, !noalias !78
  br label %152

; <label>:152:                                    ; preds = %147, %141
  %153 = icmp eq %"class.std::__ccr1::unique_ptr.22"* %143, %137 ; [#uses=1 type=i1]
  br i1 %153, label %154, label %141

; <label>:154:                                    ; preds = %152, %114, %129
  %155 = phi i32 [ %69, %114 ], [ %135, %129 ], [ %135, %152 ] ; [#uses=2 type=i32]
  %156 = icmp eq i32 %155, 0                      ; [#uses=1 type=i1]
  br i1 %156, label %159, label %157

; <label>:157:                                    ; preds = %154
  %158 = inttoptr i32 %155 to i8*                 ; [#uses=1 type=i8*]
  call void @_ZdlPv(i8* %158) #15, !noalias !78
  br label %159

; <label>:159:                                    ; preds = %157, %154
  %160 = load %"class.(anonymous namespace)::ExprAST"*, %"class.(anonymous namespace)::ExprAST"** %50, align 4, !tbaa !10, !noalias !78 ; [#uses=3 type=%"class.(anonymous namespace)::ExprAST"*]
  store %"class.(anonymous namespace)::ExprAST"* null, %"class.(anonymous namespace)::ExprAST"** %50, align 4, !tbaa !10, !noalias !78
  %161 = icmp eq %"class.(anonymous namespace)::ExprAST"* %160, null ; [#uses=1 type=i1]
  br i1 %161, label %185, label %180

; <label>:162:                                    ; preds = %54
  %163 = landingpad { i8*, i32 }
          cleanup                                 ; [#uses=2 type={ i8*, i32 }]
  %164 = extractvalue { i8*, i32 } %163, 0        ; [#uses=1 type=i8*]
  %165 = extractvalue { i8*, i32 } %163, 1        ; [#uses=1 type=i32]
  br label %187

; <label>:166:                                    ; preds = %98
  %167 = landingpad { i8*, i32 }
          cleanup                                 ; [#uses=1 type={ i8*, i32 }]
  br label %170

; <label>:168:                                    ; preds = %75, %93
  %169 = landingpad { i8*, i32 }
          cleanup                                 ; [#uses=1 type={ i8*, i32 }]
  br label %170

; <label>:170:                                    ; preds = %166, %168, %96
  %171 = phi { i8*, i32 } [ %97, %96 ], [ %167, %166 ], [ %169, %168 ] ; [#uses=2 type={ i8*, i32 }]
  %172 = extractvalue { i8*, i32 } %171, 0        ; [#uses=1 type=i8*]
  %173 = extractvalue { i8*, i32 } %171, 1        ; [#uses=1 type=i32]
  store %"class.(anonymous namespace)::ExprAST"* null, %"class.(anonymous namespace)::ExprAST"** %50, align 4, !tbaa !10, !noalias !78
  %174 = bitcast %"class.(anonymous namespace)::ExprAST"* %56 to void (%"class.(anonymous namespace)::ExprAST"*)*** ; [#uses=1 type=void (%"class.(anonymous namespace)::ExprAST"*)***]
  %175 = load void (%"class.(anonymous namespace)::ExprAST"*)**, void (%"class.(anonymous namespace)::ExprAST"*)*** %174, align 4, !tbaa !15, !noalias !78 ; [#uses=1 type=void (%"class.(anonymous namespace)::ExprAST"*)**]
  %176 = getelementptr inbounds void (%"class.(anonymous namespace)::ExprAST"*)*, void (%"class.(anonymous namespace)::ExprAST"*)** %175, i32 1 ; [#uses=1 type=void (%"class.(anonymous namespace)::ExprAST"*)**]
  %177 = load void (%"class.(anonymous namespace)::ExprAST"*)*, void (%"class.(anonymous namespace)::ExprAST"*)** %176, align 4, !noalias !78 ; [#uses=1 type=void (%"class.(anonymous namespace)::ExprAST"*)*]
  call void %177(%"class.(anonymous namespace)::ExprAST"* nonnull %56) #16, !noalias !78
  br label %187

; <label>:178:                                    ; preds = %55
  %179 = bitcast %"class.std::__ccr1::unique_ptr.22"* %0 to i32* ; [#uses=1 type=i32*]
  store i32 0, i32* %179, align 4, !tbaa !71, !alias.scope !78
  call void @llvm.lifetime.end.p0i8(i64 4, i8* nonnull %49) #1, !noalias !78
  br label %256

; <label>:180:                                    ; preds = %159
  %181 = bitcast %"class.(anonymous namespace)::ExprAST"* %160 to void (%"class.(anonymous namespace)::ExprAST"*)*** ; [#uses=1 type=void (%"class.(anonymous namespace)::ExprAST"*)***]
  %182 = load void (%"class.(anonymous namespace)::ExprAST"*)**, void (%"class.(anonymous namespace)::ExprAST"*)*** %181, align 4, !tbaa !15, !noalias !78 ; [#uses=1 type=void (%"class.(anonymous namespace)::ExprAST"*)**]
  %183 = getelementptr inbounds void (%"class.(anonymous namespace)::ExprAST"*)*, void (%"class.(anonymous namespace)::ExprAST"*)** %182, i32 1 ; [#uses=1 type=void (%"class.(anonymous namespace)::ExprAST"*)**]
  %184 = load void (%"class.(anonymous namespace)::ExprAST"*)*, void (%"class.(anonymous namespace)::ExprAST"*)** %183, align 4, !noalias !78 ; [#uses=1 type=void (%"class.(anonymous namespace)::ExprAST"*)*]
  call void %184(%"class.(anonymous namespace)::ExprAST"* nonnull %160) #16, !noalias !78
  br label %185

; <label>:185:                                    ; preds = %64, %180, %159
  call void @llvm.lifetime.end.p0i8(i64 4, i8* nonnull %49) #1, !noalias !78
  %186 = load i32, i32* @_ZL6CurTok, align 4, !tbaa !13, !noalias !78 ; [#uses=1 type=i32]
  switch i32 %186, label %190 [
    i32 41, label %202
    i32 44, label %199
  ]

; <label>:187:                                    ; preds = %170, %162
  %188 = phi i8* [ %172, %170 ], [ %164, %162 ]   ; [#uses=1 type=i8*]
  %189 = phi i32 [ %173, %170 ], [ %165, %162 ]   ; [#uses=1 type=i32]
  call void @llvm.lifetime.end.p0i8(i64 4, i8* nonnull %49) #1, !noalias !78
  br label %283

; <label>:190:                                    ; preds = %185
  invoke fastcc void @_Z8LogErrorPKc(%"class.std::__ccr1::unique_ptr.22"* sret %0, i8* getelementptr inbounds ([37 x i8], [37 x i8]* @.str.23, i32 0, i32 0)) #17
          to label %256 unwind label %193

; <label>:191:                                    ; preds = %199
  %192 = landingpad { i8*, i32 }
          cleanup                                 ; [#uses=1 type={ i8*, i32 }]
  br label %195

; <label>:193:                                    ; preds = %190, %202
  %194 = landingpad { i8*, i32 }
          cleanup                                 ; [#uses=1 type={ i8*, i32 }]
  br label %195

; <label>:195:                                    ; preds = %193, %191
  %196 = phi { i8*, i32 } [ %192, %191 ], [ %194, %193 ] ; [#uses=2 type={ i8*, i32 }]
  %197 = extractvalue { i8*, i32 } %196, 0        ; [#uses=1 type=i8*]
  %198 = extractvalue { i8*, i32 } %196, 1        ; [#uses=1 type=i32]
  br label %283

; <label>:199:                                    ; preds = %185
  %200 = invoke fastcc i32 @_ZL6gettokv() #17
          to label %201 unwind label %191, !noalias !78 ; [#uses=1 type=i32]

; <label>:201:                                    ; preds = %199
  store i32 %200, i32* @_ZL6CurTok, align 4, !tbaa !13, !noalias !78
  br label %54

; <label>:202:                                    ; preds = %185, %42
  %203 = invoke fastcc i32 @_ZL6gettokv() #17
          to label %204 unwind label %193, !noalias !78 ; [#uses=1 type=i32]

; <label>:204:                                    ; preds = %202
  store i32 %203, i32* @_ZL6CurTok, align 4, !tbaa !13, !noalias !78
  %205 = invoke i8* @_Znwm(i32 28) #18
          to label %206 unwind label %250, !noalias !78 ; [#uses=7 type=i8*]

; <label>:206:                                    ; preds = %204
  %207 = bitcast %"class.std::__ccr1::vector.42"* %3 to i32* ; [#uses=1 type=i32*]
  %208 = load i32, i32* %207, align 4, !tbaa !84, !noalias !90 ; [#uses=4 type=i32]
  %209 = bitcast %"class.std::__ccr1::unique_ptr.22"** %45 to i32* ; [#uses=1 type=i32*]
  %210 = load i32, i32* %209, align 4, !tbaa !87, !noalias !90 ; [#uses=2 type=i32]
  %211 = bitcast %"class.std::__ccr1::unique_ptr.22"** %46 to i32* ; [#uses=1 type=i32*]
  %212 = load i32, i32* %211, align 4, !tbaa !10, !noalias !90 ; [#uses=1 type=i32]
  store %"class.std::__ccr1::unique_ptr.22"* null, %"class.std::__ccr1::unique_ptr.22"** %46, align 4, !tbaa !10, !noalias !90
  store %"class.std::__ccr1::unique_ptr.22"* null, %"class.std::__ccr1::unique_ptr.22"** %45, align 4, !tbaa !87, !noalias !90
  store %"class.std::__ccr1::unique_ptr.22"* null, %"class.std::__ccr1::unique_ptr.22"** %44, align 4, !tbaa !84, !noalias !90
  %213 = bitcast i8* %205 to i32 (...)***         ; [#uses=1 type=i32 (...)***]
  store i32 (...)** bitcast (i8** getelementptr inbounds ({ [4 x i8*] }, { [4 x i8*] }* @_ZTVN12_GLOBAL__N_111CallExprASTE, i32 0, inrange i32 0, i32 2) to i32 (...)**), i32 (...)*** %213, align 4, !tbaa !15, !noalias !90
  %214 = getelementptr inbounds i8, i8* %205, i32 4 ; [#uses=1 type=i8*]
  %215 = bitcast i8* %214 to %"class.std::__ccr1::basic_string"* ; [#uses=1 type=%"class.std::__ccr1::basic_string"*]
  %216 = invoke %"class.std::__ccr1::basic_string"* @_ZNSt6__ccr112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEC1ERKS5_(%"class.std::__ccr1::basic_string"* nonnull %215, %"class.std::__ccr1::basic_string"* nonnull dereferenceable(12) %2) #17
          to label %241 unwind label %217, !noalias !90 ; [#uses=0 type=%"class.std::__ccr1::basic_string"*]

; <label>:217:                                    ; preds = %206
  %218 = landingpad { i8*, i32 }
          cleanup                                 ; [#uses=1 type={ i8*, i32 }]
  %219 = inttoptr i32 %208 to %"class.std::__ccr1::unique_ptr.22"* ; [#uses=2 type=%"class.std::__ccr1::unique_ptr.22"*]
  %220 = icmp eq i32 %208, 0                      ; [#uses=1 type=i1]
  br i1 %220, label %240, label %221

; <label>:221:                                    ; preds = %217
  %222 = inttoptr i32 %210 to %"class.std::__ccr1::unique_ptr.22"* ; [#uses=2 type=%"class.std::__ccr1::unique_ptr.22"*]
  %223 = icmp eq %"class.std::__ccr1::unique_ptr.22"* %222, %219 ; [#uses=1 type=i1]
  br i1 %223, label %238, label %224

; <label>:224:                                    ; preds = %221
  br label %225

; <label>:225:                                    ; preds = %224, %236
  %226 = phi %"class.std::__ccr1::unique_ptr.22"* [ %227, %236 ], [ %222, %224 ] ; [#uses=1 type=%"class.std::__ccr1::unique_ptr.22"*]
  %227 = getelementptr inbounds %"class.std::__ccr1::unique_ptr.22", %"class.std::__ccr1::unique_ptr.22"* %226, i32 -1 ; [#uses=3 type=%"class.std::__ccr1::unique_ptr.22"*]
  %228 = getelementptr inbounds %"class.std::__ccr1::unique_ptr.22", %"class.std::__ccr1::unique_ptr.22"* %227, i32 0, i32 0, i32 0, i32 0 ; [#uses=2 type=%"class.(anonymous namespace)::ExprAST"**]
  %229 = load %"class.(anonymous namespace)::ExprAST"*, %"class.(anonymous namespace)::ExprAST"** %228, align 4, !tbaa !10, !noalias !90 ; [#uses=3 type=%"class.(anonymous namespace)::ExprAST"*]
  store %"class.(anonymous namespace)::ExprAST"* null, %"class.(anonymous namespace)::ExprAST"** %228, align 4, !tbaa !10, !noalias !90
  %230 = icmp eq %"class.(anonymous namespace)::ExprAST"* %229, null ; [#uses=1 type=i1]
  br i1 %230, label %236, label %231

; <label>:231:                                    ; preds = %225
  %232 = bitcast %"class.(anonymous namespace)::ExprAST"* %229 to void (%"class.(anonymous namespace)::ExprAST"*)*** ; [#uses=1 type=void (%"class.(anonymous namespace)::ExprAST"*)***]
  %233 = load void (%"class.(anonymous namespace)::ExprAST"*)**, void (%"class.(anonymous namespace)::ExprAST"*)*** %232, align 4, !tbaa !15, !noalias !90 ; [#uses=1 type=void (%"class.(anonymous namespace)::ExprAST"*)**]
  %234 = getelementptr inbounds void (%"class.(anonymous namespace)::ExprAST"*)*, void (%"class.(anonymous namespace)::ExprAST"*)** %233, i32 1 ; [#uses=1 type=void (%"class.(anonymous namespace)::ExprAST"*)**]
  %235 = load void (%"class.(anonymous namespace)::ExprAST"*)*, void (%"class.(anonymous namespace)::ExprAST"*)** %234, align 4, !noalias !90 ; [#uses=1 type=void (%"class.(anonymous namespace)::ExprAST"*)*]
  call void %235(%"class.(anonymous namespace)::ExprAST"* nonnull %229) #16, !noalias !90
  br label %236

; <label>:236:                                    ; preds = %231, %225
  %237 = icmp eq %"class.std::__ccr1::unique_ptr.22"* %227, %219 ; [#uses=1 type=i1]
  br i1 %237, label %238, label %225

; <label>:238:                                    ; preds = %236, %221
  %239 = inttoptr i32 %208 to i8*                 ; [#uses=1 type=i8*]
  call void @_ZdlPv(i8* %239) #15, !noalias !90
  br label %240

; <label>:240:                                    ; preds = %238, %217
  call void @_ZdlPv(i8* nonnull %205) #15, !noalias !90
  br label %252

; <label>:241:                                    ; preds = %206
  %242 = getelementptr inbounds i8, i8* %205, i32 16 ; [#uses=1 type=i8*]
  %243 = getelementptr inbounds i8, i8* %205, i32 20 ; [#uses=1 type=i8*]
  %244 = getelementptr inbounds i8, i8* %205, i32 24 ; [#uses=1 type=i8*]
  %245 = bitcast i8* %242 to i32*                 ; [#uses=1 type=i32*]
  store i32 %208, i32* %245, align 4, !tbaa !84, !noalias !90
  %246 = bitcast i8* %243 to i32*                 ; [#uses=1 type=i32*]
  store i32 %210, i32* %246, align 4, !tbaa !87, !noalias !90
  %247 = bitcast i8* %244 to i32*                 ; [#uses=1 type=i32*]
  store i32 %212, i32* %247, align 4, !tbaa !10, !noalias !90
  %248 = ptrtoint i8* %205 to i32                 ; [#uses=1 type=i32]
  %249 = bitcast %"class.std::__ccr1::unique_ptr.22"* %0 to i32* ; [#uses=1 type=i32*]
  store i32 %248, i32* %249, align 4, !tbaa !71, !alias.scope !78
  br label %256

; <label>:250:                                    ; preds = %204
  %251 = landingpad { i8*, i32 }
          cleanup                                 ; [#uses=1 type={ i8*, i32 }]
  br label %252

; <label>:252:                                    ; preds = %250, %240
  %253 = phi { i8*, i32 } [ %251, %250 ], [ %218, %240 ] ; [#uses=2 type={ i8*, i32 }]
  %254 = extractvalue { i8*, i32 } %253, 0        ; [#uses=1 type=i8*]
  %255 = extractvalue { i8*, i32 } %253, 1        ; [#uses=1 type=i32]
  br label %283

; <label>:256:                                    ; preds = %241, %190, %178
  %257 = load %"class.std::__ccr1::unique_ptr.22"*, %"class.std::__ccr1::unique_ptr.22"** %44, align 4, !tbaa !84, !noalias !78 ; [#uses=5 type=%"class.std::__ccr1::unique_ptr.22"*]
  %258 = icmp eq %"class.std::__ccr1::unique_ptr.22"* %257, null ; [#uses=1 type=i1]
  br i1 %258, label %282, label %259

; <label>:259:                                    ; preds = %256
  %260 = bitcast %"class.std::__ccr1::unique_ptr.22"* %257 to i8* ; [#uses=1 type=i8*]
  %261 = load %"class.std::__ccr1::unique_ptr.22"*, %"class.std::__ccr1::unique_ptr.22"** %45, align 4, !tbaa !87, !noalias !78 ; [#uses=2 type=%"class.std::__ccr1::unique_ptr.22"*]
  %262 = icmp eq %"class.std::__ccr1::unique_ptr.22"* %261, %257 ; [#uses=1 type=i1]
  br i1 %262, label %280, label %263

; <label>:263:                                    ; preds = %259
  br label %264

; <label>:264:                                    ; preds = %263, %275
  %265 = phi %"class.std::__ccr1::unique_ptr.22"* [ %266, %275 ], [ %261, %263 ] ; [#uses=1 type=%"class.std::__ccr1::unique_ptr.22"*]
  %266 = getelementptr inbounds %"class.std::__ccr1::unique_ptr.22", %"class.std::__ccr1::unique_ptr.22"* %265, i32 -1 ; [#uses=3 type=%"class.std::__ccr1::unique_ptr.22"*]
  %267 = getelementptr inbounds %"class.std::__ccr1::unique_ptr.22", %"class.std::__ccr1::unique_ptr.22"* %266, i32 0, i32 0, i32 0, i32 0 ; [#uses=2 type=%"class.(anonymous namespace)::ExprAST"**]
  %268 = load %"class.(anonymous namespace)::ExprAST"*, %"class.(anonymous namespace)::ExprAST"** %267, align 4, !tbaa !10, !noalias !78 ; [#uses=3 type=%"class.(anonymous namespace)::ExprAST"*]
  store %"class.(anonymous namespace)::ExprAST"* null, %"class.(anonymous namespace)::ExprAST"** %267, align 4, !tbaa !10, !noalias !78
  %269 = icmp eq %"class.(anonymous namespace)::ExprAST"* %268, null ; [#uses=1 type=i1]
  br i1 %269, label %275, label %270

; <label>:270:                                    ; preds = %264
  %271 = bitcast %"class.(anonymous namespace)::ExprAST"* %268 to void (%"class.(anonymous namespace)::ExprAST"*)*** ; [#uses=1 type=void (%"class.(anonymous namespace)::ExprAST"*)***]
  %272 = load void (%"class.(anonymous namespace)::ExprAST"*)**, void (%"class.(anonymous namespace)::ExprAST"*)*** %271, align 4, !tbaa !15, !noalias !78 ; [#uses=1 type=void (%"class.(anonymous namespace)::ExprAST"*)**]
  %273 = getelementptr inbounds void (%"class.(anonymous namespace)::ExprAST"*)*, void (%"class.(anonymous namespace)::ExprAST"*)** %272, i32 1 ; [#uses=1 type=void (%"class.(anonymous namespace)::ExprAST"*)**]
  %274 = load void (%"class.(anonymous namespace)::ExprAST"*)*, void (%"class.(anonymous namespace)::ExprAST"*)** %273, align 4, !noalias !78 ; [#uses=1 type=void (%"class.(anonymous namespace)::ExprAST"*)*]
  call void %274(%"class.(anonymous namespace)::ExprAST"* nonnull %268) #16, !noalias !78
  br label %275

; <label>:275:                                    ; preds = %270, %264
  %276 = icmp eq %"class.std::__ccr1::unique_ptr.22"* %266, %257 ; [#uses=1 type=i1]
  br i1 %276, label %277, label %264

; <label>:277:                                    ; preds = %275
  %278 = bitcast %"class.std::__ccr1::vector.42"* %3 to i8** ; [#uses=1 type=i8**]
  %279 = load i8*, i8** %278, align 4, !tbaa !84, !noalias !78 ; [#uses=1 type=i8*]
  br label %280

; <label>:280:                                    ; preds = %277, %259
  %281 = phi i8* [ %279, %277 ], [ %260, %259 ]   ; [#uses=1 type=i8*]
  store %"class.std::__ccr1::unique_ptr.22"* %257, %"class.std::__ccr1::unique_ptr.22"** %45, align 4, !tbaa !87, !noalias !78
  call void @_ZdlPv(i8* %281) #15, !noalias !78
  br label %282

; <label>:282:                                    ; preds = %280, %256
  call void @llvm.lifetime.end.p0i8(i64 12, i8* nonnull %43) #1, !noalias !78
  br label %312

; <label>:283:                                    ; preds = %252, %195, %187
  %284 = phi i8* [ %254, %252 ], [ %197, %195 ], [ %188, %187 ] ; [#uses=1 type=i8*]
  %285 = phi i32 [ %255, %252 ], [ %198, %195 ], [ %189, %187 ] ; [#uses=1 type=i32]
  %286 = load %"class.std::__ccr1::unique_ptr.22"*, %"class.std::__ccr1::unique_ptr.22"** %44, align 4, !tbaa !84, !noalias !78 ; [#uses=5 type=%"class.std::__ccr1::unique_ptr.22"*]
  %287 = icmp eq %"class.std::__ccr1::unique_ptr.22"* %286, null ; [#uses=1 type=i1]
  br i1 %287, label %311, label %288

; <label>:288:                                    ; preds = %283
  %289 = bitcast %"class.std::__ccr1::unique_ptr.22"* %286 to i8* ; [#uses=1 type=i8*]
  %290 = load %"class.std::__ccr1::unique_ptr.22"*, %"class.std::__ccr1::unique_ptr.22"** %45, align 4, !tbaa !87, !noalias !78 ; [#uses=2 type=%"class.std::__ccr1::unique_ptr.22"*]
  %291 = icmp eq %"class.std::__ccr1::unique_ptr.22"* %290, %286 ; [#uses=1 type=i1]
  br i1 %291, label %309, label %292

; <label>:292:                                    ; preds = %288
  br label %293

; <label>:293:                                    ; preds = %292, %304
  %294 = phi %"class.std::__ccr1::unique_ptr.22"* [ %295, %304 ], [ %290, %292 ] ; [#uses=1 type=%"class.std::__ccr1::unique_ptr.22"*]
  %295 = getelementptr inbounds %"class.std::__ccr1::unique_ptr.22", %"class.std::__ccr1::unique_ptr.22"* %294, i32 -1 ; [#uses=3 type=%"class.std::__ccr1::unique_ptr.22"*]
  %296 = getelementptr inbounds %"class.std::__ccr1::unique_ptr.22", %"class.std::__ccr1::unique_ptr.22"* %295, i32 0, i32 0, i32 0, i32 0 ; [#uses=2 type=%"class.(anonymous namespace)::ExprAST"**]
  %297 = load %"class.(anonymous namespace)::ExprAST"*, %"class.(anonymous namespace)::ExprAST"** %296, align 4, !tbaa !10, !noalias !78 ; [#uses=3 type=%"class.(anonymous namespace)::ExprAST"*]
  store %"class.(anonymous namespace)::ExprAST"* null, %"class.(anonymous namespace)::ExprAST"** %296, align 4, !tbaa !10, !noalias !78
  %298 = icmp eq %"class.(anonymous namespace)::ExprAST"* %297, null ; [#uses=1 type=i1]
  br i1 %298, label %304, label %299

; <label>:299:                                    ; preds = %293
  %300 = bitcast %"class.(anonymous namespace)::ExprAST"* %297 to void (%"class.(anonymous namespace)::ExprAST"*)*** ; [#uses=1 type=void (%"class.(anonymous namespace)::ExprAST"*)***]
  %301 = load void (%"class.(anonymous namespace)::ExprAST"*)**, void (%"class.(anonymous namespace)::ExprAST"*)*** %300, align 4, !tbaa !15, !noalias !78 ; [#uses=1 type=void (%"class.(anonymous namespace)::ExprAST"*)**]
  %302 = getelementptr inbounds void (%"class.(anonymous namespace)::ExprAST"*)*, void (%"class.(anonymous namespace)::ExprAST"*)** %301, i32 1 ; [#uses=1 type=void (%"class.(anonymous namespace)::ExprAST"*)**]
  %303 = load void (%"class.(anonymous namespace)::ExprAST"*)*, void (%"class.(anonymous namespace)::ExprAST"*)** %302, align 4, !noalias !78 ; [#uses=1 type=void (%"class.(anonymous namespace)::ExprAST"*)*]
  call void %303(%"class.(anonymous namespace)::ExprAST"* nonnull %297) #16, !noalias !78
  br label %304

; <label>:304:                                    ; preds = %299, %293
  %305 = icmp eq %"class.std::__ccr1::unique_ptr.22"* %295, %286 ; [#uses=1 type=i1]
  br i1 %305, label %306, label %293

; <label>:306:                                    ; preds = %304
  %307 = bitcast %"class.std::__ccr1::vector.42"* %3 to i8** ; [#uses=1 type=i8**]
  %308 = load i8*, i8** %307, align 4, !tbaa !84, !noalias !78 ; [#uses=1 type=i8*]
  br label %309

; <label>:309:                                    ; preds = %306, %288
  %310 = phi i8* [ %308, %306 ], [ %289, %288 ]   ; [#uses=1 type=i8*]
  store %"class.std::__ccr1::unique_ptr.22"* %286, %"class.std::__ccr1::unique_ptr.22"** %45, align 4, !tbaa !87, !noalias !78
  call void @_ZdlPv(i8* %310) #15, !noalias !78
  br label %311

; <label>:311:                                    ; preds = %309, %283
  call void @llvm.lifetime.end.p0i8(i64 12, i8* nonnull %43) #1, !noalias !78
  br label %319

; <label>:312:                                    ; preds = %282, %27
  %313 = load i8, i8* %13, align 4, !tbaa !4, !noalias !78 ; [#uses=1 type=i8]
  %314 = and i8 %313, 1                           ; [#uses=1 type=i8]
  %315 = icmp eq i8 %314, 0                       ; [#uses=1 type=i1]
  br i1 %315, label %331, label %316

; <label>:316:                                    ; preds = %312
  %317 = getelementptr inbounds %"class.std::__ccr1::basic_string", %"class.std::__ccr1::basic_string"* %2, i32 0, i32 0, i32 0, i32 0, i32 0, i32 0, i32 2 ; [#uses=1 type=i8**]
  %318 = load i8*, i8** %317, align 4, !tbaa !4, !noalias !78 ; [#uses=1 type=i8*]
  call void @_ZdlPv(i8* %318) #15, !noalias !78
  br label %331

; <label>:319:                                    ; preds = %311, %36, %30
  %320 = phi i8* [ %38, %36 ], [ %284, %311 ], [ %32, %30 ] ; [#uses=1 type=i8*]
  %321 = phi i32 [ %39, %36 ], [ %285, %311 ], [ %33, %30 ] ; [#uses=1 type=i32]
  %322 = load i8, i8* %13, align 4, !tbaa !4, !noalias !78 ; [#uses=1 type=i8]
  %323 = and i8 %322, 1                           ; [#uses=1 type=i8]
  %324 = icmp eq i8 %323, 0                       ; [#uses=1 type=i1]
  br i1 %324, label %328, label %325

; <label>:325:                                    ; preds = %319
  %326 = getelementptr inbounds %"class.std::__ccr1::basic_string", %"class.std::__ccr1::basic_string"* %2, i32 0, i32 0, i32 0, i32 0, i32 0, i32 0, i32 2 ; [#uses=1 type=i8**]
  %327 = load i8*, i8** %326, align 4, !tbaa !4, !noalias !78 ; [#uses=1 type=i8*]
  call void @_ZdlPv(i8* %327) #15, !noalias !78
  br label %328

; <label>:328:                                    ; preds = %325, %319
  call void @llvm.lifetime.end.p0i8(i64 12, i8* nonnull %13) #1, !noalias !78
  %329 = insertvalue { i8*, i32 } undef, i8* %320, 0 ; [#uses=1 type={ i8*, i32 }]
  %330 = insertvalue { i8*, i32 } %329, i32 %321, 1 ; [#uses=1 type={ i8*, i32 }]
  resume { i8*, i32 } %330

; <label>:331:                                    ; preds = %312, %316
  call void @llvm.lifetime.end.p0i8(i64 12, i8* nonnull %13) #1, !noalias !78
  br label %382

; <label>:332:                                    ; preds = %1
  %333 = load %struct.__sFILE*, %struct.__sFILE** @__stderrp, align 4, !tbaa !10, !noalias !93 ; [#uses=1 type=%struct.__sFILE*]
  %334 = tail call i32 (%struct.__sFILE*, i8*, ...) @fprintf(%struct.__sFILE* %333, i8* getelementptr inbounds ([34 x i8], [34 x i8]* @.str.3, i32 0, i32 0), i8* getelementptr inbounds ([16 x i8], [16 x i8]* @__func__._ZL15ParseNumberExprv, i32 0, i32 0), i32 414, i8* getelementptr inbounds ([148 x i8], [148 x i8]* @.str.4, i32 0, i32 0)) #17, !noalias !93 ; [#uses=0 type=i32]
  %335 = tail call i8* @_Znwm(i32 12) #18, !noalias !96 ; [#uses=5 type=i8*]
  %336 = load double, double* @_ZL6NumVal, align 8, !tbaa !49, !noalias !96 ; [#uses=1 type=double]
  %337 = bitcast i8* %335 to i32 (...)***         ; [#uses=1 type=i32 (...)***]
  store i32 (...)** bitcast (i8** getelementptr inbounds ({ [4 x i8*] }, { [4 x i8*] }* @_ZTVN12_GLOBAL__N_113NumberExprASTE, i32 0, inrange i32 0, i32 2) to i32 (...)**), i32 (...)*** %337, align 4, !tbaa !15, !noalias !96
  %338 = getelementptr inbounds i8, i8* %335, i32 4 ; [#uses=1 type=i8*]
  %339 = bitcast i8* %338 to double*              ; [#uses=1 type=double*]
  store double %336, double* %339, align 4, !tbaa !99, !noalias !96
  %340 = invoke fastcc i32 @_ZL6gettokv() #17
          to label %348 unwind label %341, !noalias !93 ; [#uses=1 type=i32]

; <label>:341:                                    ; preds = %332
  %342 = landingpad { i8*, i32 }
          cleanup                                 ; [#uses=1 type={ i8*, i32 }]
  %343 = bitcast i8* %335 to %"class.(anonymous namespace)::NumberExprAST"* ; [#uses=1 type=%"class.(anonymous namespace)::NumberExprAST"*]
  %344 = bitcast i8* %335 to void (%"class.(anonymous namespace)::NumberExprAST"*)*** ; [#uses=1 type=void (%"class.(anonymous namespace)::NumberExprAST"*)***]
  %345 = load void (%"class.(anonymous namespace)::NumberExprAST"*)**, void (%"class.(anonymous namespace)::NumberExprAST"*)*** %344, align 4, !tbaa !15, !noalias !93 ; [#uses=1 type=void (%"class.(anonymous namespace)::NumberExprAST"*)**]
  %346 = getelementptr inbounds void (%"class.(anonymous namespace)::NumberExprAST"*)*, void (%"class.(anonymous namespace)::NumberExprAST"*)** %345, i32 1 ; [#uses=1 type=void (%"class.(anonymous namespace)::NumberExprAST"*)**]
  %347 = load void (%"class.(anonymous namespace)::NumberExprAST"*)*, void (%"class.(anonymous namespace)::NumberExprAST"*)** %346, align 4, !noalias !93 ; [#uses=1 type=void (%"class.(anonymous namespace)::NumberExprAST"*)*]
  tail call void %347(%"class.(anonymous namespace)::NumberExprAST"* nonnull %343) #16, !noalias !93
  resume { i8*, i32 } %342

; <label>:348:                                    ; preds = %332
  %349 = ptrtoint i8* %335 to i32                 ; [#uses=1 type=i32]
  store i32 %340, i32* @_ZL6CurTok, align 4, !tbaa !13, !noalias !93
  %350 = bitcast %"class.std::__ccr1::unique_ptr.22"* %0 to i32* ; [#uses=1 type=i32*]
  store i32 %349, i32* %350, align 4, !tbaa !71, !alias.scope !93
  br label %382

; <label>:351:                                    ; preds = %1
  %352 = load %struct.__sFILE*, %struct.__sFILE** @__stderrp, align 4, !tbaa !10, !noalias !101 ; [#uses=1 type=%struct.__sFILE*]
  %353 = tail call i32 (%struct.__sFILE*, i8*, ...) @fprintf(%struct.__sFILE* %352, i8* getelementptr inbounds ([34 x i8], [34 x i8]* @.str.3, i32 0, i32 0), i8* getelementptr inbounds ([15 x i8], [15 x i8]* @__func__._ZL14ParseParenExprv, i32 0, i32 0), i32 426, i8* getelementptr inbounds ([148 x i8], [148 x i8]* @.str.4, i32 0, i32 0)) #17, !noalias !101 ; [#uses=0 type=i32]
  %354 = tail call fastcc i32 @_ZL6gettokv() #17, !noalias !101 ; [#uses=1 type=i32]
  store i32 %354, i32* @_ZL6CurTok, align 4, !tbaa !13, !noalias !101
  %355 = bitcast %"class.std::__ccr1::unique_ptr.22"* %5 to i8* ; [#uses=3 type=i8*]
  call void @llvm.lifetime.start.p0i8(i64 4, i8* nonnull %355) #1, !noalias !101
  call fastcc void @_ZL15ParseExpressionv(%"class.std::__ccr1::unique_ptr.22"* nonnull sret %5) #17, !noalias !101
  %356 = getelementptr inbounds %"class.std::__ccr1::unique_ptr.22", %"class.std::__ccr1::unique_ptr.22"* %5, i32 0, i32 0, i32 0, i32 0 ; [#uses=4 type=%"class.(anonymous namespace)::ExprAST"**]
  %357 = load %"class.(anonymous namespace)::ExprAST"*, %"class.(anonymous namespace)::ExprAST"** %356, align 4, !tbaa !10, !noalias !101 ; [#uses=6 type=%"class.(anonymous namespace)::ExprAST"*]
  %358 = icmp eq %"class.(anonymous namespace)::ExprAST"* %357, null ; [#uses=1 type=i1]
  %359 = ptrtoint %"class.(anonymous namespace)::ExprAST"* %357 to i32 ; [#uses=1 type=i32]
  br i1 %358, label %373, label %360

; <label>:360:                                    ; preds = %351
  %361 = load i32, i32* @_ZL6CurTok, align 4, !tbaa !13, !noalias !101 ; [#uses=1 type=i32]
  %362 = icmp eq i32 %361, 41                     ; [#uses=1 type=i1]
  br i1 %362, label %370, label %363

; <label>:363:                                    ; preds = %360
  invoke fastcc void @_Z8LogErrorPKc(%"class.std::__ccr1::unique_ptr.22"* sret %0, i8* getelementptr inbounds ([13 x i8], [13 x i8]* @.str.24, i32 0, i32 0)) #17
          to label %376 unwind label %364

; <label>:364:                                    ; preds = %370, %363
  %365 = landingpad { i8*, i32 }
          cleanup                                 ; [#uses=1 type={ i8*, i32 }]
  %366 = bitcast %"class.(anonymous namespace)::ExprAST"* %357 to void (%"class.(anonymous namespace)::ExprAST"*)*** ; [#uses=1 type=void (%"class.(anonymous namespace)::ExprAST"*)***]
  %367 = load void (%"class.(anonymous namespace)::ExprAST"*)**, void (%"class.(anonymous namespace)::ExprAST"*)*** %366, align 4, !tbaa !15, !noalias !101 ; [#uses=1 type=void (%"class.(anonymous namespace)::ExprAST"*)**]
  %368 = getelementptr inbounds void (%"class.(anonymous namespace)::ExprAST"*)*, void (%"class.(anonymous namespace)::ExprAST"*)** %367, i32 1 ; [#uses=1 type=void (%"class.(anonymous namespace)::ExprAST"*)**]
  %369 = load void (%"class.(anonymous namespace)::ExprAST"*)*, void (%"class.(anonymous namespace)::ExprAST"*)** %368, align 4, !noalias !101 ; [#uses=1 type=void (%"class.(anonymous namespace)::ExprAST"*)*]
  tail call void %369(%"class.(anonymous namespace)::ExprAST"* nonnull %357) #16, !noalias !101
  call void @llvm.lifetime.end.p0i8(i64 4, i8* nonnull %355) #1, !noalias !101
  resume { i8*, i32 } %365

; <label>:370:                                    ; preds = %360
  %371 = invoke fastcc i32 @_ZL6gettokv() #17
          to label %372 unwind label %364, !noalias !101 ; [#uses=1 type=i32]

; <label>:372:                                    ; preds = %370
  store i32 %371, i32* @_ZL6CurTok, align 4, !tbaa !13, !noalias !101
  store %"class.(anonymous namespace)::ExprAST"* null, %"class.(anonymous namespace)::ExprAST"** %356, align 4, !tbaa !10, !noalias !101
  br label %373

; <label>:373:                                    ; preds = %351, %372
  %374 = phi i32 [ %359, %372 ], [ 0, %351 ]      ; [#uses=1 type=i32]
  %375 = bitcast %"class.std::__ccr1::unique_ptr.22"* %0 to i32* ; [#uses=1 type=i32*]
  store i32 %374, i32* %375, align 4, !tbaa !71, !alias.scope !101
  store %"class.(anonymous namespace)::ExprAST"* null, %"class.(anonymous namespace)::ExprAST"** %356, align 4, !tbaa !10, !noalias !101
  br label %381

; <label>:376:                                    ; preds = %363
  store %"class.(anonymous namespace)::ExprAST"* null, %"class.(anonymous namespace)::ExprAST"** %356, align 4, !tbaa !10, !noalias !101
  %377 = bitcast %"class.(anonymous namespace)::ExprAST"* %357 to void (%"class.(anonymous namespace)::ExprAST"*)*** ; [#uses=1 type=void (%"class.(anonymous namespace)::ExprAST"*)***]
  %378 = load void (%"class.(anonymous namespace)::ExprAST"*)**, void (%"class.(anonymous namespace)::ExprAST"*)*** %377, align 4, !tbaa !15, !noalias !101 ; [#uses=1 type=void (%"class.(anonymous namespace)::ExprAST"*)**]
  %379 = getelementptr inbounds void (%"class.(anonymous namespace)::ExprAST"*)*, void (%"class.(anonymous namespace)::ExprAST"*)** %378, i32 1 ; [#uses=1 type=void (%"class.(anonymous namespace)::ExprAST"*)**]
  %380 = load void (%"class.(anonymous namespace)::ExprAST"*)*, void (%"class.(anonymous namespace)::ExprAST"*)** %379, align 4, !noalias !101 ; [#uses=1 type=void (%"class.(anonymous namespace)::ExprAST"*)*]
  tail call void %380(%"class.(anonymous namespace)::ExprAST"* nonnull %357) #16, !noalias !101
  br label %381

; <label>:381:                                    ; preds = %373, %376
  call void @llvm.lifetime.end.p0i8(i64 4, i8* nonnull %355) #1, !noalias !101
  br label %382

; <label>:382:                                    ; preds = %381, %348, %331, %9
  ret void
}

; [#uses=2]
; Function Attrs: optsize
define internal fastcc void @_ZL13ParseBinOpRHSiNSt6__ccr110unique_ptrIN12_GLOBAL__N_17ExprASTENS_14default_deleteIS2_EEEE(%"class.std::__ccr1::unique_ptr.22"* noalias nocapture sret, i32, %"class.std::__ccr1::unique_ptr.22"* nocapture) unnamed_addr #7 personality i8* bitcast (i32 (...)* @__gxx_personality_sj0 to i8*) {
  %4 = alloca %"class.std::__ccr1::unique_ptr.22", align 4 ; [#uses=4 type=%"class.std::__ccr1::unique_ptr.22"*]
  %5 = alloca %"class.std::__ccr1::unique_ptr.22", align 4 ; [#uses=4 type=%"class.std::__ccr1::unique_ptr.22"*]
  %6 = alloca %"class.std::__ccr1::unique_ptr.22", align 4 ; [#uses=3 type=%"class.std::__ccr1::unique_ptr.22"*]
  %7 = load %struct.__sFILE*, %struct.__sFILE** @__stderrp, align 4, !tbaa !10 ; [#uses=1 type=%struct.__sFILE*]
  %8 = tail call i32 (%struct.__sFILE*, i8*, ...) @fprintf(%struct.__sFILE* %7, i8* getelementptr inbounds ([34 x i8], [34 x i8]* @.str.3, i32 0, i32 0), i8* getelementptr inbounds ([14 x i8], [14 x i8]* @__func__._ZL13ParseBinOpRHSiNSt6__ccr110unique_ptrIN12_GLOBAL__N_17ExprASTENS_14default_deleteIS2_EEEE, i32 0, i32 0), i32 571, i8* getelementptr inbounds ([148 x i8], [148 x i8]* @.str.4, i32 0, i32 0)) #17 ; [#uses=0 type=i32]
  %9 = tail call fastcc i32 @_ZL16GetTokPrecedencev() #17 ; [#uses=2 type=i32]
  %10 = icmp slt i32 %9, %1                       ; [#uses=1 type=i1]
  br i1 %10, label %11, label %13

; <label>:11:                                     ; preds = %3
  %12 = bitcast %"class.std::__ccr1::unique_ptr.22"* %2 to i32* ; [#uses=1 type=i32*]
  br label %24

; <label>:13:                                     ; preds = %3
  %14 = bitcast %"class.std::__ccr1::unique_ptr.22"* %4 to i8* ; [#uses=4 type=i8*]
  %15 = getelementptr inbounds %"class.std::__ccr1::unique_ptr.22", %"class.std::__ccr1::unique_ptr.22"* %4, i32 0, i32 0, i32 0, i32 0 ; [#uses=5 type=%"class.(anonymous namespace)::ExprAST"**]
  %16 = bitcast %"class.std::__ccr1::unique_ptr.22"* %5 to i8* ; [#uses=3 type=i8*]
  %17 = bitcast %"class.std::__ccr1::unique_ptr.22"* %4 to i32* ; [#uses=1 type=i32*]
  %18 = bitcast %"class.std::__ccr1::unique_ptr.22"* %6 to i32* ; [#uses=1 type=i32*]
  %19 = getelementptr inbounds %"class.std::__ccr1::unique_ptr.22", %"class.std::__ccr1::unique_ptr.22"* %5, i32 0, i32 0, i32 0, i32 0 ; [#uses=1 type=%"class.(anonymous namespace)::ExprAST"**]
  %20 = bitcast %"class.std::__ccr1::unique_ptr.22"* %5 to i32* ; [#uses=1 type=i32*]
  %21 = getelementptr inbounds %"class.std::__ccr1::unique_ptr.22", %"class.std::__ccr1::unique_ptr.22"* %6, i32 0, i32 0, i32 0, i32 0 ; [#uses=4 type=%"class.(anonymous namespace)::ExprAST"**]
  %22 = bitcast %"class.std::__ccr1::unique_ptr.22"* %2 to i32* ; [#uses=2 type=i32*]
  %23 = bitcast %"class.std::__ccr1::unique_ptr.22"* %2 to i8** ; [#uses=1 type=i8**]
  br label %29

; <label>:24:                                     ; preds = %76, %11
  %25 = phi i32* [ %12, %11 ], [ %22, %76 ]       ; [#uses=1 type=i32*]
  %26 = getelementptr inbounds %"class.std::__ccr1::unique_ptr.22", %"class.std::__ccr1::unique_ptr.22"* %2, i32 0, i32 0, i32 0, i32 0 ; [#uses=1 type=%"class.(anonymous namespace)::ExprAST"**]
  %27 = load i32, i32* %25, align 4, !tbaa !10    ; [#uses=1 type=i32]
  store %"class.(anonymous namespace)::ExprAST"* null, %"class.(anonymous namespace)::ExprAST"** %26, align 4, !tbaa !10
  %28 = bitcast %"class.std::__ccr1::unique_ptr.22"* %0 to i32* ; [#uses=1 type=i32*]
  store i32 %27, i32* %28, align 4, !tbaa !71
  br label %105

; <label>:29:                                     ; preds = %13, %76
  %30 = phi i32 [ %9, %13 ], [ %85, %76 ]         ; [#uses=2 type=i32]
  %31 = load i32, i32* @_ZL6CurTok, align 4, !tbaa !13 ; [#uses=1 type=i32]
  %32 = tail call fastcc i32 @_ZL6gettokv() #17   ; [#uses=1 type=i32]
  store i32 %32, i32* @_ZL6CurTok, align 4, !tbaa !13
  call void @llvm.lifetime.start.p0i8(i64 4, i8* nonnull %14) #1
  call fastcc void @_ZL12ParsePrimaryv(%"class.std::__ccr1::unique_ptr.22"* nonnull sret %4) #17
  %33 = load %"class.(anonymous namespace)::ExprAST"*, %"class.(anonymous namespace)::ExprAST"** %15, align 4, !tbaa !10 ; [#uses=4 type=%"class.(anonymous namespace)::ExprAST"*]
  %34 = icmp eq %"class.(anonymous namespace)::ExprAST"* %33, null ; [#uses=1 type=i1]
  %35 = ptrtoint %"class.(anonymous namespace)::ExprAST"* %33 to i32 ; [#uses=2 type=i32]
  br i1 %34, label %74, label %36

; <label>:36:                                     ; preds = %29
  %37 = invoke fastcc i32 @_ZL16GetTokPrecedencev() #17
          to label %38 unwind label %54           ; [#uses=1 type=i32]

; <label>:38:                                     ; preds = %36
  %39 = icmp slt i32 %30, %37                     ; [#uses=1 type=i1]
  br i1 %39, label %40, label %70

; <label>:40:                                     ; preds = %38
  call void @llvm.lifetime.start.p0i8(i64 4, i8* nonnull %16) #1
  %41 = add nsw i32 %30, 1                        ; [#uses=1 type=i32]
  store %"class.(anonymous namespace)::ExprAST"* null, %"class.(anonymous namespace)::ExprAST"** %15, align 4, !tbaa !10
  store i32 %35, i32* %18, align 4, !tbaa !71
  invoke fastcc void @_ZL13ParseBinOpRHSiNSt6__ccr110unique_ptrIN12_GLOBAL__N_17ExprASTENS_14default_deleteIS2_EEEE(%"class.std::__ccr1::unique_ptr.22"* nonnull sret %5, i32 %41, %"class.std::__ccr1::unique_ptr.22"* nonnull %6) #17
          to label %42 unwind label %58

; <label>:42:                                     ; preds = %40
  %43 = load i32, i32* %20, align 4, !tbaa !10    ; [#uses=4 type=i32]
  store i32 %43, i32* %17, align 4, !tbaa !10
  store %"class.(anonymous namespace)::ExprAST"* null, %"class.(anonymous namespace)::ExprAST"** %19, align 4, !tbaa !10
  %44 = load %"class.(anonymous namespace)::ExprAST"*, %"class.(anonymous namespace)::ExprAST"** %21, align 4, !tbaa !10 ; [#uses=3 type=%"class.(anonymous namespace)::ExprAST"*]
  store %"class.(anonymous namespace)::ExprAST"* null, %"class.(anonymous namespace)::ExprAST"** %21, align 4, !tbaa !10
  %45 = icmp eq %"class.(anonymous namespace)::ExprAST"* %44, null ; [#uses=1 type=i1]
  %46 = inttoptr i32 %43 to %"class.(anonymous namespace)::ExprAST"* ; [#uses=1 type=%"class.(anonymous namespace)::ExprAST"*]
  br i1 %45, label %52, label %47

; <label>:47:                                     ; preds = %42
  %48 = bitcast %"class.(anonymous namespace)::ExprAST"* %44 to void (%"class.(anonymous namespace)::ExprAST"*)*** ; [#uses=1 type=void (%"class.(anonymous namespace)::ExprAST"*)***]
  %49 = load void (%"class.(anonymous namespace)::ExprAST"*)**, void (%"class.(anonymous namespace)::ExprAST"*)*** %48, align 4, !tbaa !15 ; [#uses=1 type=void (%"class.(anonymous namespace)::ExprAST"*)**]
  %50 = getelementptr inbounds void (%"class.(anonymous namespace)::ExprAST"*)*, void (%"class.(anonymous namespace)::ExprAST"*)** %49, i32 1 ; [#uses=1 type=void (%"class.(anonymous namespace)::ExprAST"*)**]
  %51 = load void (%"class.(anonymous namespace)::ExprAST"*)*, void (%"class.(anonymous namespace)::ExprAST"*)** %50, align 4 ; [#uses=1 type=void (%"class.(anonymous namespace)::ExprAST"*)*]
  tail call void %51(%"class.(anonymous namespace)::ExprAST"* nonnull %44) #16
  br label %52

; <label>:52:                                     ; preds = %42, %47
  call void @llvm.lifetime.end.p0i8(i64 4, i8* nonnull %16) #1
  %53 = icmp eq i32 %43, 0                        ; [#uses=1 type=i1]
  br i1 %53, label %74, label %70

; <label>:54:                                     ; preds = %36
  %55 = landingpad { i8*, i32 }
          cleanup                                 ; [#uses=2 type={ i8*, i32 }]
  %56 = extractvalue { i8*, i32 } %55, 0          ; [#uses=1 type=i8*]
  %57 = extractvalue { i8*, i32 } %55, 1          ; [#uses=1 type=i32]
  store %"class.(anonymous namespace)::ExprAST"* null, %"class.(anonymous namespace)::ExprAST"** %15, align 4, !tbaa !10
  br label %92

; <label>:58:                                     ; preds = %40
  %59 = landingpad { i8*, i32 }
          cleanup                                 ; [#uses=2 type={ i8*, i32 }]
  %60 = extractvalue { i8*, i32 } %59, 0          ; [#uses=1 type=i8*]
  %61 = extractvalue { i8*, i32 } %59, 1          ; [#uses=1 type=i32]
  %62 = load %"class.(anonymous namespace)::ExprAST"*, %"class.(anonymous namespace)::ExprAST"** %21, align 4, !tbaa !10 ; [#uses=3 type=%"class.(anonymous namespace)::ExprAST"*]
  store %"class.(anonymous namespace)::ExprAST"* null, %"class.(anonymous namespace)::ExprAST"** %21, align 4, !tbaa !10
  %63 = icmp eq %"class.(anonymous namespace)::ExprAST"* %62, null ; [#uses=1 type=i1]
  br i1 %63, label %69, label %64

; <label>:64:                                     ; preds = %58
  %65 = bitcast %"class.(anonymous namespace)::ExprAST"* %62 to void (%"class.(anonymous namespace)::ExprAST"*)*** ; [#uses=1 type=void (%"class.(anonymous namespace)::ExprAST"*)***]
  %66 = load void (%"class.(anonymous namespace)::ExprAST"*)**, void (%"class.(anonymous namespace)::ExprAST"*)*** %65, align 4, !tbaa !15 ; [#uses=1 type=void (%"class.(anonymous namespace)::ExprAST"*)**]
  %67 = getelementptr inbounds void (%"class.(anonymous namespace)::ExprAST"*)*, void (%"class.(anonymous namespace)::ExprAST"*)** %66, i32 1 ; [#uses=1 type=void (%"class.(anonymous namespace)::ExprAST"*)**]
  %68 = load void (%"class.(anonymous namespace)::ExprAST"*)*, void (%"class.(anonymous namespace)::ExprAST"*)** %67, align 4 ; [#uses=1 type=void (%"class.(anonymous namespace)::ExprAST"*)*]
  tail call void %68(%"class.(anonymous namespace)::ExprAST"* nonnull %62) #16
  br label %69

; <label>:69:                                     ; preds = %64, %58
  call void @llvm.lifetime.end.p0i8(i64 4, i8* nonnull %16) #1
  store %"class.(anonymous namespace)::ExprAST"* null, %"class.(anonymous namespace)::ExprAST"** %15, align 4, !tbaa !10
  br label %100

; <label>:70:                                     ; preds = %52, %38
  %71 = phi i32 [ %43, %52 ], [ %35, %38 ]        ; [#uses=1 type=i32]
  %72 = phi %"class.(anonymous namespace)::ExprAST"* [ %46, %52 ], [ %33, %38 ] ; [#uses=2 type=%"class.(anonymous namespace)::ExprAST"*]
  %73 = invoke i8* @_Znwm(i32 16) #18
          to label %76 unwind label %87           ; [#uses=5 type=i8*]

; <label>:74:                                     ; preds = %52, %29
  %75 = bitcast %"class.std::__ccr1::unique_ptr.22"* %0 to i32* ; [#uses=1 type=i32*]
  store i32 0, i32* %75, align 4, !tbaa !71
  call void @llvm.lifetime.end.p0i8(i64 4, i8* nonnull %14) #1
  br label %105

; <label>:76:                                     ; preds = %70
  %77 = trunc i32 %31 to i8                       ; [#uses=1 type=i8]
  %78 = load i32, i32* %22, align 4, !tbaa !10, !noalias !104 ; [#uses=1 type=i32]
  %79 = bitcast i8* %73 to i32 (...)***           ; [#uses=1 type=i32 (...)***]
  store i32 (...)** bitcast (i8** getelementptr inbounds ({ [4 x i8*] }, { [4 x i8*] }* @_ZTVN12_GLOBAL__N_113BinaryExprASTE, i32 0, inrange i32 0, i32 2) to i32 (...)**), i32 (...)*** %79, align 4, !tbaa !15, !noalias !104
  %80 = getelementptr inbounds i8, i8* %73, i32 4 ; [#uses=1 type=i8*]
  store i8 %77, i8* %80, align 4, !tbaa !107, !noalias !104
  %81 = getelementptr inbounds i8, i8* %73, i32 8 ; [#uses=1 type=i8*]
  %82 = bitcast i8* %81 to i32*                   ; [#uses=1 type=i32*]
  store i32 %78, i32* %82, align 4, !tbaa !71, !noalias !104
  %83 = getelementptr inbounds i8, i8* %73, i32 12 ; [#uses=1 type=i8*]
  %84 = bitcast i8* %83 to i32*                   ; [#uses=1 type=i32*]
  store i32 %71, i32* %84, align 4, !tbaa !71, !noalias !104
  store i8* %73, i8** %23, align 4, !tbaa !10
  call void @llvm.lifetime.end.p0i8(i64 4, i8* nonnull %14) #1
  %85 = tail call fastcc i32 @_ZL16GetTokPrecedencev() #17 ; [#uses=2 type=i32]
  %86 = icmp slt i32 %85, %1                      ; [#uses=1 type=i1]
  br i1 %86, label %24, label %29

; <label>:87:                                     ; preds = %70
  %88 = landingpad { i8*, i32 }
          cleanup                                 ; [#uses=2 type={ i8*, i32 }]
  %89 = extractvalue { i8*, i32 } %88, 0          ; [#uses=2 type=i8*]
  %90 = extractvalue { i8*, i32 } %88, 1          ; [#uses=2 type=i32]
  store %"class.(anonymous namespace)::ExprAST"* null, %"class.(anonymous namespace)::ExprAST"** %15, align 4, !tbaa !10
  %91 = icmp eq %"class.(anonymous namespace)::ExprAST"* %72, null ; [#uses=1 type=i1]
  br i1 %91, label %100, label %92

; <label>:92:                                     ; preds = %54, %87
  %93 = phi i32 [ %57, %54 ], [ %90, %87 ]        ; [#uses=1 type=i32]
  %94 = phi i8* [ %56, %54 ], [ %89, %87 ]        ; [#uses=1 type=i8*]
  %95 = phi %"class.(anonymous namespace)::ExprAST"* [ %33, %54 ], [ %72, %87 ] ; [#uses=2 type=%"class.(anonymous namespace)::ExprAST"*]
  %96 = bitcast %"class.(anonymous namespace)::ExprAST"* %95 to void (%"class.(anonymous namespace)::ExprAST"*)*** ; [#uses=1 type=void (%"class.(anonymous namespace)::ExprAST"*)***]
  %97 = load void (%"class.(anonymous namespace)::ExprAST"*)**, void (%"class.(anonymous namespace)::ExprAST"*)*** %96, align 4, !tbaa !15 ; [#uses=1 type=void (%"class.(anonymous namespace)::ExprAST"*)**]
  %98 = getelementptr inbounds void (%"class.(anonymous namespace)::ExprAST"*)*, void (%"class.(anonymous namespace)::ExprAST"*)** %97, i32 1 ; [#uses=1 type=void (%"class.(anonymous namespace)::ExprAST"*)**]
  %99 = load void (%"class.(anonymous namespace)::ExprAST"*)*, void (%"class.(anonymous namespace)::ExprAST"*)** %98, align 4 ; [#uses=1 type=void (%"class.(anonymous namespace)::ExprAST"*)*]
  tail call void %99(%"class.(anonymous namespace)::ExprAST"* nonnull %95) #16
  br label %100

; <label>:100:                                    ; preds = %69, %87, %92
  %101 = phi i32 [ %61, %69 ], [ %90, %87 ], [ %93, %92 ] ; [#uses=1 type=i32]
  %102 = phi i8* [ %60, %69 ], [ %89, %87 ], [ %94, %92 ] ; [#uses=1 type=i8*]
  call void @llvm.lifetime.end.p0i8(i64 4, i8* nonnull %14) #1
  %103 = insertvalue { i8*, i32 } undef, i8* %102, 0 ; [#uses=1 type={ i8*, i32 }]
  %104 = insertvalue { i8*, i32 } %103, i32 %101, 1 ; [#uses=1 type={ i8*, i32 }]
  resume { i8*, i32 } %104

; <label>:105:                                    ; preds = %74, %24
  ret void
}

; [#uses=1]
; Function Attrs: inlinehint nounwind optsize
define internal %"class.(anonymous namespace)::VariableExprAST"* @_ZN12_GLOBAL__N_115VariableExprASTD1Ev(%"class.(anonymous namespace)::VariableExprAST"* returned) unnamed_addr #12 align 2 personality i32 (...)* @__gxx_personality_sj0 {
  %2 = getelementptr inbounds %"class.(anonymous namespace)::VariableExprAST", %"class.(anonymous namespace)::VariableExprAST"* %0, i32 0, i32 0, i32 0 ; [#uses=1 type=i32 (...)***]
  store i32 (...)** bitcast (i8** getelementptr inbounds ({ [4 x i8*] }, { [4 x i8*] }* @_ZTVN12_GLOBAL__N_115VariableExprASTE, i32 0, inrange i32 0, i32 2) to i32 (...)**), i32 (...)*** %2, align 4, !tbaa !15
  %3 = getelementptr inbounds %"class.(anonymous namespace)::VariableExprAST", %"class.(anonymous namespace)::VariableExprAST"* %0, i32 0, i32 1 ; [#uses=1 type=%"class.std::__ccr1::basic_string"*]
  %4 = bitcast %"class.std::__ccr1::basic_string"* %3 to i8* ; [#uses=1 type=i8*]
  %5 = load i8, i8* %4, align 4, !tbaa !4         ; [#uses=1 type=i8]
  %6 = and i8 %5, 1                               ; [#uses=1 type=i8]
  %7 = icmp eq i8 %6, 0                           ; [#uses=1 type=i1]
  br i1 %7, label %11, label %8

; <label>:8:                                      ; preds = %1
  %9 = getelementptr inbounds %"class.(anonymous namespace)::VariableExprAST", %"class.(anonymous namespace)::VariableExprAST"* %0, i32 0, i32 1, i32 0, i32 0, i32 0, i32 0, i32 0, i32 2 ; [#uses=1 type=i8**]
  %10 = load i8*, i8** %9, align 4, !tbaa !4      ; [#uses=1 type=i8*]
  tail call void @_ZdlPv(i8* %10) #15
  br label %11

; <label>:11:                                     ; preds = %1, %8
  ret %"class.(anonymous namespace)::VariableExprAST"* %0
}

; [#uses=1]
; Function Attrs: inlinehint nounwind optsize
define internal void @_ZN12_GLOBAL__N_115VariableExprASTD0Ev(%"class.(anonymous namespace)::VariableExprAST"*) unnamed_addr #12 align 2 personality i32 (...)* @__gxx_personality_sj0 {
  %2 = getelementptr inbounds %"class.(anonymous namespace)::VariableExprAST", %"class.(anonymous namespace)::VariableExprAST"* %0, i32 0, i32 0, i32 0 ; [#uses=1 type=i32 (...)***]
  store i32 (...)** bitcast (i8** getelementptr inbounds ({ [4 x i8*] }, { [4 x i8*] }* @_ZTVN12_GLOBAL__N_115VariableExprASTE, i32 0, inrange i32 0, i32 2) to i32 (...)**), i32 (...)*** %2, align 4, !tbaa !15
  %3 = getelementptr inbounds %"class.(anonymous namespace)::VariableExprAST", %"class.(anonymous namespace)::VariableExprAST"* %0, i32 0, i32 1 ; [#uses=1 type=%"class.std::__ccr1::basic_string"*]
  %4 = bitcast %"class.std::__ccr1::basic_string"* %3 to i8* ; [#uses=1 type=i8*]
  %5 = load i8, i8* %4, align 4, !tbaa !4         ; [#uses=1 type=i8]
  %6 = and i8 %5, 1                               ; [#uses=1 type=i8]
  %7 = icmp eq i8 %6, 0                           ; [#uses=1 type=i1]
  br i1 %7, label %11, label %8

; <label>:8:                                      ; preds = %1
  %9 = getelementptr inbounds %"class.(anonymous namespace)::VariableExprAST", %"class.(anonymous namespace)::VariableExprAST"* %0, i32 0, i32 1, i32 0, i32 0, i32 0, i32 0, i32 0, i32 2 ; [#uses=1 type=i8**]
  %10 = load i8*, i8** %9, align 4, !tbaa !4      ; [#uses=1 type=i8*]
  tail call void @_ZdlPv(i8* %10) #15
  br label %11

; <label>:11:                                     ; preds = %1, %8
  %12 = bitcast %"class.(anonymous namespace)::VariableExprAST"* %0 to i8* ; [#uses=1 type=i8*]
  tail call void @_ZdlPv(i8* %12) #15
  ret void
}

; [#uses=1]
; Function Attrs: inlinehint nounwind optsize
define internal %"class.(anonymous namespace)::CallExprAST"* @_ZN12_GLOBAL__N_111CallExprASTD1Ev(%"class.(anonymous namespace)::CallExprAST"* returned) unnamed_addr #12 align 2 personality i32 (...)* @__gxx_personality_sj0 {
  %2 = getelementptr inbounds %"class.(anonymous namespace)::CallExprAST", %"class.(anonymous namespace)::CallExprAST"* %0, i32 0, i32 0, i32 0 ; [#uses=1 type=i32 (...)***]
  store i32 (...)** bitcast (i8** getelementptr inbounds ({ [4 x i8*] }, { [4 x i8*] }* @_ZTVN12_GLOBAL__N_111CallExprASTE, i32 0, inrange i32 0, i32 2) to i32 (...)**), i32 (...)*** %2, align 4, !tbaa !15
  %3 = getelementptr inbounds %"class.(anonymous namespace)::CallExprAST", %"class.(anonymous namespace)::CallExprAST"* %0, i32 0, i32 2 ; [#uses=2 type=%"class.std::__ccr1::vector.42"*]
  %4 = getelementptr inbounds %"class.std::__ccr1::vector.42", %"class.std::__ccr1::vector.42"* %3, i32 0, i32 0, i32 0 ; [#uses=1 type=%"class.std::__ccr1::unique_ptr.22"**]
  %5 = load %"class.std::__ccr1::unique_ptr.22"*, %"class.std::__ccr1::unique_ptr.22"** %4, align 4, !tbaa !84 ; [#uses=5 type=%"class.std::__ccr1::unique_ptr.22"*]
  %6 = icmp eq %"class.std::__ccr1::unique_ptr.22"* %5, null ; [#uses=1 type=i1]
  br i1 %6, label %31, label %7

; <label>:7:                                      ; preds = %1
  %8 = bitcast %"class.std::__ccr1::unique_ptr.22"* %5 to i8* ; [#uses=1 type=i8*]
  %9 = getelementptr inbounds %"class.(anonymous namespace)::CallExprAST", %"class.(anonymous namespace)::CallExprAST"* %0, i32 0, i32 2, i32 0, i32 1 ; [#uses=2 type=%"class.std::__ccr1::unique_ptr.22"**]
  %10 = load %"class.std::__ccr1::unique_ptr.22"*, %"class.std::__ccr1::unique_ptr.22"** %9, align 4, !tbaa !87 ; [#uses=2 type=%"class.std::__ccr1::unique_ptr.22"*]
  %11 = icmp eq %"class.std::__ccr1::unique_ptr.22"* %10, %5 ; [#uses=1 type=i1]
  br i1 %11, label %29, label %12

; <label>:12:                                     ; preds = %7
  br label %13

; <label>:13:                                     ; preds = %12, %24
  %14 = phi %"class.std::__ccr1::unique_ptr.22"* [ %15, %24 ], [ %10, %12 ] ; [#uses=1 type=%"class.std::__ccr1::unique_ptr.22"*]
  %15 = getelementptr inbounds %"class.std::__ccr1::unique_ptr.22", %"class.std::__ccr1::unique_ptr.22"* %14, i32 -1 ; [#uses=3 type=%"class.std::__ccr1::unique_ptr.22"*]
  %16 = getelementptr inbounds %"class.std::__ccr1::unique_ptr.22", %"class.std::__ccr1::unique_ptr.22"* %15, i32 0, i32 0, i32 0, i32 0 ; [#uses=2 type=%"class.(anonymous namespace)::ExprAST"**]
  %17 = load %"class.(anonymous namespace)::ExprAST"*, %"class.(anonymous namespace)::ExprAST"** %16, align 4, !tbaa !10 ; [#uses=3 type=%"class.(anonymous namespace)::ExprAST"*]
  store %"class.(anonymous namespace)::ExprAST"* null, %"class.(anonymous namespace)::ExprAST"** %16, align 4, !tbaa !10
  %18 = icmp eq %"class.(anonymous namespace)::ExprAST"* %17, null ; [#uses=1 type=i1]
  br i1 %18, label %24, label %19

; <label>:19:                                     ; preds = %13
  %20 = bitcast %"class.(anonymous namespace)::ExprAST"* %17 to void (%"class.(anonymous namespace)::ExprAST"*)*** ; [#uses=1 type=void (%"class.(anonymous namespace)::ExprAST"*)***]
  %21 = load void (%"class.(anonymous namespace)::ExprAST"*)**, void (%"class.(anonymous namespace)::ExprAST"*)*** %20, align 4, !tbaa !15 ; [#uses=1 type=void (%"class.(anonymous namespace)::ExprAST"*)**]
  %22 = getelementptr inbounds void (%"class.(anonymous namespace)::ExprAST"*)*, void (%"class.(anonymous namespace)::ExprAST"*)** %21, i32 1 ; [#uses=1 type=void (%"class.(anonymous namespace)::ExprAST"*)**]
  %23 = load void (%"class.(anonymous namespace)::ExprAST"*)*, void (%"class.(anonymous namespace)::ExprAST"*)** %22, align 4 ; [#uses=1 type=void (%"class.(anonymous namespace)::ExprAST"*)*]
  tail call void %23(%"class.(anonymous namespace)::ExprAST"* nonnull %17) #16
  br label %24

; <label>:24:                                     ; preds = %19, %13
  %25 = icmp eq %"class.std::__ccr1::unique_ptr.22"* %15, %5 ; [#uses=1 type=i1]
  br i1 %25, label %26, label %13

; <label>:26:                                     ; preds = %24
  %27 = bitcast %"class.std::__ccr1::vector.42"* %3 to i8** ; [#uses=1 type=i8**]
  %28 = load i8*, i8** %27, align 4, !tbaa !84    ; [#uses=1 type=i8*]
  br label %29

; <label>:29:                                     ; preds = %26, %7
  %30 = phi i8* [ %28, %26 ], [ %8, %7 ]          ; [#uses=1 type=i8*]
  store %"class.std::__ccr1::unique_ptr.22"* %5, %"class.std::__ccr1::unique_ptr.22"** %9, align 4, !tbaa !87
  tail call void @_ZdlPv(i8* %30) #15
  br label %31

; <label>:31:                                     ; preds = %29, %1
  %32 = getelementptr inbounds %"class.(anonymous namespace)::CallExprAST", %"class.(anonymous namespace)::CallExprAST"* %0, i32 0, i32 1 ; [#uses=1 type=%"class.std::__ccr1::basic_string"*]
  %33 = bitcast %"class.std::__ccr1::basic_string"* %32 to i8* ; [#uses=1 type=i8*]
  %34 = load i8, i8* %33, align 4, !tbaa !4       ; [#uses=1 type=i8]
  %35 = and i8 %34, 1                             ; [#uses=1 type=i8]
  %36 = icmp eq i8 %35, 0                         ; [#uses=1 type=i1]
  br i1 %36, label %40, label %37

; <label>:37:                                     ; preds = %31
  %38 = getelementptr inbounds %"class.(anonymous namespace)::CallExprAST", %"class.(anonymous namespace)::CallExprAST"* %0, i32 0, i32 1, i32 0, i32 0, i32 0, i32 0, i32 0, i32 2 ; [#uses=1 type=i8**]
  %39 = load i8*, i8** %38, align 4, !tbaa !4     ; [#uses=1 type=i8*]
  tail call void @_ZdlPv(i8* %39) #15
  br label %40

; <label>:40:                                     ; preds = %31, %37
  ret %"class.(anonymous namespace)::CallExprAST"* %0
}

; [#uses=1]
; Function Attrs: inlinehint nounwind optsize
define internal void @_ZN12_GLOBAL__N_111CallExprASTD0Ev(%"class.(anonymous namespace)::CallExprAST"*) unnamed_addr #12 align 2 personality i32 (...)* @__gxx_personality_sj0 {
  %2 = getelementptr inbounds %"class.(anonymous namespace)::CallExprAST", %"class.(anonymous namespace)::CallExprAST"* %0, i32 0, i32 0, i32 0 ; [#uses=1 type=i32 (...)***]
  store i32 (...)** bitcast (i8** getelementptr inbounds ({ [4 x i8*] }, { [4 x i8*] }* @_ZTVN12_GLOBAL__N_111CallExprASTE, i32 0, inrange i32 0, i32 2) to i32 (...)**), i32 (...)*** %2, align 4, !tbaa !15
  %3 = getelementptr inbounds %"class.(anonymous namespace)::CallExprAST", %"class.(anonymous namespace)::CallExprAST"* %0, i32 0, i32 2 ; [#uses=2 type=%"class.std::__ccr1::vector.42"*]
  %4 = getelementptr inbounds %"class.std::__ccr1::vector.42", %"class.std::__ccr1::vector.42"* %3, i32 0, i32 0, i32 0 ; [#uses=1 type=%"class.std::__ccr1::unique_ptr.22"**]
  %5 = load %"class.std::__ccr1::unique_ptr.22"*, %"class.std::__ccr1::unique_ptr.22"** %4, align 4, !tbaa !84 ; [#uses=5 type=%"class.std::__ccr1::unique_ptr.22"*]
  %6 = icmp eq %"class.std::__ccr1::unique_ptr.22"* %5, null ; [#uses=1 type=i1]
  br i1 %6, label %31, label %7

; <label>:7:                                      ; preds = %1
  %8 = bitcast %"class.std::__ccr1::unique_ptr.22"* %5 to i8* ; [#uses=1 type=i8*]
  %9 = getelementptr inbounds %"class.(anonymous namespace)::CallExprAST", %"class.(anonymous namespace)::CallExprAST"* %0, i32 0, i32 2, i32 0, i32 1 ; [#uses=2 type=%"class.std::__ccr1::unique_ptr.22"**]
  %10 = load %"class.std::__ccr1::unique_ptr.22"*, %"class.std::__ccr1::unique_ptr.22"** %9, align 4, !tbaa !87 ; [#uses=2 type=%"class.std::__ccr1::unique_ptr.22"*]
  %11 = icmp eq %"class.std::__ccr1::unique_ptr.22"* %10, %5 ; [#uses=1 type=i1]
  br i1 %11, label %29, label %12

; <label>:12:                                     ; preds = %7
  br label %13

; <label>:13:                                     ; preds = %12, %24
  %14 = phi %"class.std::__ccr1::unique_ptr.22"* [ %15, %24 ], [ %10, %12 ] ; [#uses=1 type=%"class.std::__ccr1::unique_ptr.22"*]
  %15 = getelementptr inbounds %"class.std::__ccr1::unique_ptr.22", %"class.std::__ccr1::unique_ptr.22"* %14, i32 -1 ; [#uses=3 type=%"class.std::__ccr1::unique_ptr.22"*]
  %16 = getelementptr inbounds %"class.std::__ccr1::unique_ptr.22", %"class.std::__ccr1::unique_ptr.22"* %15, i32 0, i32 0, i32 0, i32 0 ; [#uses=2 type=%"class.(anonymous namespace)::ExprAST"**]
  %17 = load %"class.(anonymous namespace)::ExprAST"*, %"class.(anonymous namespace)::ExprAST"** %16, align 4, !tbaa !10 ; [#uses=3 type=%"class.(anonymous namespace)::ExprAST"*]
  store %"class.(anonymous namespace)::ExprAST"* null, %"class.(anonymous namespace)::ExprAST"** %16, align 4, !tbaa !10
  %18 = icmp eq %"class.(anonymous namespace)::ExprAST"* %17, null ; [#uses=1 type=i1]
  br i1 %18, label %24, label %19

; <label>:19:                                     ; preds = %13
  %20 = bitcast %"class.(anonymous namespace)::ExprAST"* %17 to void (%"class.(anonymous namespace)::ExprAST"*)*** ; [#uses=1 type=void (%"class.(anonymous namespace)::ExprAST"*)***]
  %21 = load void (%"class.(anonymous namespace)::ExprAST"*)**, void (%"class.(anonymous namespace)::ExprAST"*)*** %20, align 4, !tbaa !15 ; [#uses=1 type=void (%"class.(anonymous namespace)::ExprAST"*)**]
  %22 = getelementptr inbounds void (%"class.(anonymous namespace)::ExprAST"*)*, void (%"class.(anonymous namespace)::ExprAST"*)** %21, i32 1 ; [#uses=1 type=void (%"class.(anonymous namespace)::ExprAST"*)**]
  %23 = load void (%"class.(anonymous namespace)::ExprAST"*)*, void (%"class.(anonymous namespace)::ExprAST"*)** %22, align 4 ; [#uses=1 type=void (%"class.(anonymous namespace)::ExprAST"*)*]
  tail call void %23(%"class.(anonymous namespace)::ExprAST"* nonnull %17) #16
  br label %24

; <label>:24:                                     ; preds = %19, %13
  %25 = icmp eq %"class.std::__ccr1::unique_ptr.22"* %15, %5 ; [#uses=1 type=i1]
  br i1 %25, label %26, label %13

; <label>:26:                                     ; preds = %24
  %27 = bitcast %"class.std::__ccr1::vector.42"* %3 to i8** ; [#uses=1 type=i8**]
  %28 = load i8*, i8** %27, align 4, !tbaa !84    ; [#uses=1 type=i8*]
  br label %29

; <label>:29:                                     ; preds = %26, %7
  %30 = phi i8* [ %28, %26 ], [ %8, %7 ]          ; [#uses=1 type=i8*]
  store %"class.std::__ccr1::unique_ptr.22"* %5, %"class.std::__ccr1::unique_ptr.22"** %9, align 4, !tbaa !87
  tail call void @_ZdlPv(i8* %30) #15
  br label %31

; <label>:31:                                     ; preds = %29, %1
  %32 = getelementptr inbounds %"class.(anonymous namespace)::CallExprAST", %"class.(anonymous namespace)::CallExprAST"* %0, i32 0, i32 1 ; [#uses=1 type=%"class.std::__ccr1::basic_string"*]
  %33 = bitcast %"class.std::__ccr1::basic_string"* %32 to i8* ; [#uses=1 type=i8*]
  %34 = load i8, i8* %33, align 4, !tbaa !4       ; [#uses=1 type=i8]
  %35 = and i8 %34, 1                             ; [#uses=1 type=i8]
  %36 = icmp eq i8 %35, 0                         ; [#uses=1 type=i1]
  br i1 %36, label %40, label %37

; <label>:37:                                     ; preds = %31
  %38 = getelementptr inbounds %"class.(anonymous namespace)::CallExprAST", %"class.(anonymous namespace)::CallExprAST"* %0, i32 0, i32 1, i32 0, i32 0, i32 0, i32 0, i32 0, i32 2 ; [#uses=1 type=i8**]
  %39 = load i8*, i8** %38, align 4, !tbaa !4     ; [#uses=1 type=i8*]
  tail call void @_ZdlPv(i8* %39) #15
  br label %40

; <label>:40:                                     ; preds = %31, %37
  %41 = bitcast %"class.(anonymous namespace)::CallExprAST"* %0 to i8* ; [#uses=1 type=i8*]
  tail call void @_ZdlPv(i8* %41) #15
  ret void
}

; [#uses=1]
; Function Attrs: inlinehint norecurse nounwind optsize readnone
define internal %"class.(anonymous namespace)::NumberExprAST"* @_ZN12_GLOBAL__N_113NumberExprASTD1Ev(%"class.(anonymous namespace)::NumberExprAST"* readnone returned) unnamed_addr #13 align 2 {
  ret %"class.(anonymous namespace)::NumberExprAST"* %0
}

; [#uses=1]
; Function Attrs: inlinehint nounwind optsize
define internal void @_ZN12_GLOBAL__N_113NumberExprASTD0Ev(%"class.(anonymous namespace)::NumberExprAST"*) unnamed_addr #12 align 2 {
  %2 = bitcast %"class.(anonymous namespace)::NumberExprAST"* %0 to i8* ; [#uses=1 type=i8*]
  tail call void @_ZdlPv(i8* %2) #15
  ret void
}

; [#uses=3]
; Function Attrs: optsize
define internal fastcc i32 @_ZL16GetTokPrecedencev() unnamed_addr #7 {
  %1 = alloca %"struct.std::__ccr1::pair.74", align 4 ; [#uses=3 type=%"struct.std::__ccr1::pair.74"*]
  %2 = alloca %"class.std::__ccr1::tuple", align 4 ; [#uses=3 type=%"class.std::__ccr1::tuple"*]
  %3 = alloca %"class.std::__ccr1::tuple.75", align 1 ; [#uses=2 type=%"class.std::__ccr1::tuple.75"*]
  %4 = alloca i8, align 1                         ; [#uses=5 type=i8*]
  %5 = load %struct.__sFILE*, %struct.__sFILE** @__stderrp, align 4, !tbaa !10 ; [#uses=1 type=%struct.__sFILE*]
  %6 = tail call i32 (%struct.__sFILE*, i8*, ...) @fprintf(%struct.__sFILE* %5, i8* getelementptr inbounds ([34 x i8], [34 x i8]* @.str.3, i32 0, i32 0), i8* getelementptr inbounds ([17 x i8], [17 x i8]* @__func__._ZL16GetTokPrecedencev, i32 0, i32 0), i32 375, i8* getelementptr inbounds ([148 x i8], [148 x i8]* @.str.4, i32 0, i32 0)) #17 ; [#uses=0 type=i32]
  %7 = load i32, i32* @_ZL6CurTok, align 4, !tbaa !13 ; [#uses=2 type=i32]
  %8 = icmp ugt i32 %7, 127                       ; [#uses=1 type=i1]
  br i1 %8, label %21, label %9

; <label>:9:                                      ; preds = %0
  call void @llvm.lifetime.start.p0i8(i64 1, i8* nonnull %4) #1
  %10 = trunc i32 %7 to i8                        ; [#uses=1 type=i8]
  store i8 %10, i8* %4, align 1, !tbaa !4
  %11 = bitcast %"struct.std::__ccr1::pair.74"* %1 to i8* ; [#uses=2 type=i8*]
  call void @llvm.lifetime.start.p0i8(i64 8, i8* nonnull %11) #1
  %12 = bitcast %"class.std::__ccr1::tuple"* %2 to i8* ; [#uses=2 type=i8*]
  call void @llvm.lifetime.start.p0i8(i64 4, i8* nonnull %12) #1
  %13 = getelementptr inbounds %"class.std::__ccr1::tuple", %"class.std::__ccr1::tuple"* %2, i32 0, i32 0, i32 0, i32 0 ; [#uses=1 type=i8**]
  store i8* %4, i8** %13, align 4
  %14 = getelementptr inbounds %"class.std::__ccr1::tuple.75", %"class.std::__ccr1::tuple.75"* %3, i32 0, i32 0 ; [#uses=2 type=i8*]
  call void @llvm.lifetime.start.p0i8(i64 1, i8* nonnull %14) #1
  call void @_ZNSt6__ccr16__treeINS_12__value_typeIciEENS_19__map_value_compareIcS2_NS_4lessIcEELb1EEENS_9allocatorIS2_EEE25__emplace_unique_key_argsIcJRKNS_21piecewise_construct_tENS_5tupleIJOcEEENSE_IJEEEEEENS_4pairINS_15__tree_iteratorIS2_PNS_11__tree_nodeIS2_PvEEiEEbEERKT_DpOT0_(%"struct.std::__ccr1::pair.74"* nonnull sret %1, %"class.std::__ccr1::__tree"* getelementptr inbounds (%"class.std::__ccr1::map", %"class.std::__ccr1::map"* @_ZL15BinopPrecedence, i32 0, i32 0), i8* nonnull dereferenceable(1) %4, %"struct.std::__ccr1::piecewise_construct_t"* nonnull dereferenceable(1) @_ZNSt6__ccr1L19piecewise_constructE, %"class.std::__ccr1::tuple"* nonnull dereferenceable(4) %2, %"class.std::__ccr1::tuple.75"* nonnull dereferenceable(1) %3) #17
  %15 = bitcast %"struct.std::__ccr1::pair.74"* %1 to %"class.std::__ccr1::__tree_node"** ; [#uses=1 type=%"class.std::__ccr1::__tree_node"**]
  %16 = load %"class.std::__ccr1::__tree_node"*, %"class.std::__ccr1::__tree_node"** %15, align 4, !tbaa !11 ; [#uses=1 type=%"class.std::__ccr1::__tree_node"*]
  %17 = getelementptr inbounds %"class.std::__ccr1::__tree_node", %"class.std::__ccr1::__tree_node"* %16, i32 0, i32 1, i32 0, i32 1 ; [#uses=1 type=i32*]
  call void @llvm.lifetime.end.p0i8(i64 1, i8* nonnull %14) #1
  call void @llvm.lifetime.end.p0i8(i64 4, i8* nonnull %12) #1
  call void @llvm.lifetime.end.p0i8(i64 8, i8* nonnull %11) #1
  %18 = load i32, i32* %17, align 4, !tbaa !13    ; [#uses=2 type=i32]
  call void @llvm.lifetime.end.p0i8(i64 1, i8* nonnull %4) #1
  %19 = icmp slt i32 %18, 1                       ; [#uses=1 type=i1]
  %20 = select i1 %19, i32 -1, i32 %18            ; [#uses=1 type=i32]
  br label %21

; <label>:21:                                     ; preds = %0, %9
  %22 = phi i32 [ %20, %9 ], [ -1, %0 ]           ; [#uses=1 type=i32]
  ret i32 %22
}

; [#uses=1]
; Function Attrs: inlinehint nounwind optsize
define internal %"class.(anonymous namespace)::BinaryExprAST"* @_ZN12_GLOBAL__N_113BinaryExprASTD1Ev(%"class.(anonymous namespace)::BinaryExprAST"* returned) unnamed_addr #12 align 2 {
  %2 = getelementptr inbounds %"class.(anonymous namespace)::BinaryExprAST", %"class.(anonymous namespace)::BinaryExprAST"* %0, i32 0, i32 0, i32 0 ; [#uses=1 type=i32 (...)***]
  store i32 (...)** bitcast (i8** getelementptr inbounds ({ [4 x i8*] }, { [4 x i8*] }* @_ZTVN12_GLOBAL__N_113BinaryExprASTE, i32 0, inrange i32 0, i32 2) to i32 (...)**), i32 (...)*** %2, align 4, !tbaa !15
  %3 = getelementptr inbounds %"class.(anonymous namespace)::BinaryExprAST", %"class.(anonymous namespace)::BinaryExprAST"* %0, i32 0, i32 3, i32 0, i32 0, i32 0 ; [#uses=2 type=%"class.(anonymous namespace)::ExprAST"**]
  %4 = load %"class.(anonymous namespace)::ExprAST"*, %"class.(anonymous namespace)::ExprAST"** %3, align 4, !tbaa !10 ; [#uses=3 type=%"class.(anonymous namespace)::ExprAST"*]
  store %"class.(anonymous namespace)::ExprAST"* null, %"class.(anonymous namespace)::ExprAST"** %3, align 4, !tbaa !10
  %5 = icmp eq %"class.(anonymous namespace)::ExprAST"* %4, null ; [#uses=1 type=i1]
  br i1 %5, label %11, label %6

; <label>:6:                                      ; preds = %1
  %7 = bitcast %"class.(anonymous namespace)::ExprAST"* %4 to void (%"class.(anonymous namespace)::ExprAST"*)*** ; [#uses=1 type=void (%"class.(anonymous namespace)::ExprAST"*)***]
  %8 = load void (%"class.(anonymous namespace)::ExprAST"*)**, void (%"class.(anonymous namespace)::ExprAST"*)*** %7, align 4, !tbaa !15 ; [#uses=1 type=void (%"class.(anonymous namespace)::ExprAST"*)**]
  %9 = getelementptr inbounds void (%"class.(anonymous namespace)::ExprAST"*)*, void (%"class.(anonymous namespace)::ExprAST"*)** %8, i32 1 ; [#uses=1 type=void (%"class.(anonymous namespace)::ExprAST"*)**]
  %10 = load void (%"class.(anonymous namespace)::ExprAST"*)*, void (%"class.(anonymous namespace)::ExprAST"*)** %9, align 4 ; [#uses=1 type=void (%"class.(anonymous namespace)::ExprAST"*)*]
  tail call void %10(%"class.(anonymous namespace)::ExprAST"* nonnull %4) #16
  br label %11

; <label>:11:                                     ; preds = %6, %1
  %12 = getelementptr inbounds %"class.(anonymous namespace)::BinaryExprAST", %"class.(anonymous namespace)::BinaryExprAST"* %0, i32 0, i32 2, i32 0, i32 0, i32 0 ; [#uses=2 type=%"class.(anonymous namespace)::ExprAST"**]
  %13 = load %"class.(anonymous namespace)::ExprAST"*, %"class.(anonymous namespace)::ExprAST"** %12, align 4, !tbaa !10 ; [#uses=3 type=%"class.(anonymous namespace)::ExprAST"*]
  store %"class.(anonymous namespace)::ExprAST"* null, %"class.(anonymous namespace)::ExprAST"** %12, align 4, !tbaa !10
  %14 = icmp eq %"class.(anonymous namespace)::ExprAST"* %13, null ; [#uses=1 type=i1]
  br i1 %14, label %20, label %15

; <label>:15:                                     ; preds = %11
  %16 = bitcast %"class.(anonymous namespace)::ExprAST"* %13 to void (%"class.(anonymous namespace)::ExprAST"*)*** ; [#uses=1 type=void (%"class.(anonymous namespace)::ExprAST"*)***]
  %17 = load void (%"class.(anonymous namespace)::ExprAST"*)**, void (%"class.(anonymous namespace)::ExprAST"*)*** %16, align 4, !tbaa !15 ; [#uses=1 type=void (%"class.(anonymous namespace)::ExprAST"*)**]
  %18 = getelementptr inbounds void (%"class.(anonymous namespace)::ExprAST"*)*, void (%"class.(anonymous namespace)::ExprAST"*)** %17, i32 1 ; [#uses=1 type=void (%"class.(anonymous namespace)::ExprAST"*)**]
  %19 = load void (%"class.(anonymous namespace)::ExprAST"*)*, void (%"class.(anonymous namespace)::ExprAST"*)** %18, align 4 ; [#uses=1 type=void (%"class.(anonymous namespace)::ExprAST"*)*]
  tail call void %19(%"class.(anonymous namespace)::ExprAST"* nonnull %13) #16
  br label %20

; <label>:20:                                     ; preds = %11, %15
  ret %"class.(anonymous namespace)::BinaryExprAST"* %0
}

; [#uses=1]
; Function Attrs: inlinehint nounwind optsize
define internal void @_ZN12_GLOBAL__N_113BinaryExprASTD0Ev(%"class.(anonymous namespace)::BinaryExprAST"*) unnamed_addr #12 align 2 {
  %2 = getelementptr inbounds %"class.(anonymous namespace)::BinaryExprAST", %"class.(anonymous namespace)::BinaryExprAST"* %0, i32 0, i32 0, i32 0 ; [#uses=1 type=i32 (...)***]
  store i32 (...)** bitcast (i8** getelementptr inbounds ({ [4 x i8*] }, { [4 x i8*] }* @_ZTVN12_GLOBAL__N_113BinaryExprASTE, i32 0, inrange i32 0, i32 2) to i32 (...)**), i32 (...)*** %2, align 4, !tbaa !15
  %3 = getelementptr inbounds %"class.(anonymous namespace)::BinaryExprAST", %"class.(anonymous namespace)::BinaryExprAST"* %0, i32 0, i32 3, i32 0, i32 0, i32 0 ; [#uses=2 type=%"class.(anonymous namespace)::ExprAST"**]
  %4 = load %"class.(anonymous namespace)::ExprAST"*, %"class.(anonymous namespace)::ExprAST"** %3, align 4, !tbaa !10 ; [#uses=3 type=%"class.(anonymous namespace)::ExprAST"*]
  store %"class.(anonymous namespace)::ExprAST"* null, %"class.(anonymous namespace)::ExprAST"** %3, align 4, !tbaa !10
  %5 = icmp eq %"class.(anonymous namespace)::ExprAST"* %4, null ; [#uses=1 type=i1]
  br i1 %5, label %11, label %6

; <label>:6:                                      ; preds = %1
  %7 = bitcast %"class.(anonymous namespace)::ExprAST"* %4 to void (%"class.(anonymous namespace)::ExprAST"*)*** ; [#uses=1 type=void (%"class.(anonymous namespace)::ExprAST"*)***]
  %8 = load void (%"class.(anonymous namespace)::ExprAST"*)**, void (%"class.(anonymous namespace)::ExprAST"*)*** %7, align 4, !tbaa !15 ; [#uses=1 type=void (%"class.(anonymous namespace)::ExprAST"*)**]
  %9 = getelementptr inbounds void (%"class.(anonymous namespace)::ExprAST"*)*, void (%"class.(anonymous namespace)::ExprAST"*)** %8, i32 1 ; [#uses=1 type=void (%"class.(anonymous namespace)::ExprAST"*)**]
  %10 = load void (%"class.(anonymous namespace)::ExprAST"*)*, void (%"class.(anonymous namespace)::ExprAST"*)** %9, align 4 ; [#uses=1 type=void (%"class.(anonymous namespace)::ExprAST"*)*]
  tail call void %10(%"class.(anonymous namespace)::ExprAST"* nonnull %4) #16
  br label %11

; <label>:11:                                     ; preds = %6, %1
  %12 = getelementptr inbounds %"class.(anonymous namespace)::BinaryExprAST", %"class.(anonymous namespace)::BinaryExprAST"* %0, i32 0, i32 2, i32 0, i32 0, i32 0 ; [#uses=2 type=%"class.(anonymous namespace)::ExprAST"**]
  %13 = load %"class.(anonymous namespace)::ExprAST"*, %"class.(anonymous namespace)::ExprAST"** %12, align 4, !tbaa !10 ; [#uses=3 type=%"class.(anonymous namespace)::ExprAST"*]
  store %"class.(anonymous namespace)::ExprAST"* null, %"class.(anonymous namespace)::ExprAST"** %12, align 4, !tbaa !10
  %14 = icmp eq %"class.(anonymous namespace)::ExprAST"* %13, null ; [#uses=1 type=i1]
  br i1 %14, label %20, label %15

; <label>:15:                                     ; preds = %11
  %16 = bitcast %"class.(anonymous namespace)::ExprAST"* %13 to void (%"class.(anonymous namespace)::ExprAST"*)*** ; [#uses=1 type=void (%"class.(anonymous namespace)::ExprAST"*)***]
  %17 = load void (%"class.(anonymous namespace)::ExprAST"*)**, void (%"class.(anonymous namespace)::ExprAST"*)*** %16, align 4, !tbaa !15 ; [#uses=1 type=void (%"class.(anonymous namespace)::ExprAST"*)**]
  %18 = getelementptr inbounds void (%"class.(anonymous namespace)::ExprAST"*)*, void (%"class.(anonymous namespace)::ExprAST"*)** %17, i32 1 ; [#uses=1 type=void (%"class.(anonymous namespace)::ExprAST"*)**]
  %19 = load void (%"class.(anonymous namespace)::ExprAST"*)*, void (%"class.(anonymous namespace)::ExprAST"*)** %18, align 4 ; [#uses=1 type=void (%"class.(anonymous namespace)::ExprAST"*)*]
  tail call void %19(%"class.(anonymous namespace)::ExprAST"* nonnull %13) #16
  br label %20

; <label>:20:                                     ; preds = %11, %15
  %21 = bitcast %"class.(anonymous namespace)::BinaryExprAST"* %0 to i8* ; [#uses=1 type=i8*]
  tail call void @_ZdlPv(i8* %21) #15
  ret void
}

; [#uses=3]
; Function Attrs: argmemonly nounwind
declare void @llvm.memset.p0i8.i32(i8* nocapture writeonly, i8, i32, i32, i1) #4

; [#uses=5]
; Function Attrs: optsize
define linkonce_odr void @_ZNSt6__ccr16__treeINS_12__value_typeIciEENS_19__map_value_compareIcS2_NS_4lessIcEELb1EEENS_9allocatorIS2_EEE25__emplace_unique_key_argsIcJRKNS_21piecewise_construct_tENS_5tupleIJOcEEENSE_IJEEEEEENS_4pairINS_15__tree_iteratorIS2_PNS_11__tree_nodeIS2_PvEEiEEbEERKT_DpOT0_(%"struct.std::__ccr1::pair.74"* noalias sret, %"class.std::__ccr1::__tree"*, i8* dereferenceable(1), %"struct.std::__ccr1::piecewise_construct_t"* dereferenceable(1), %"class.std::__ccr1::tuple"* dereferenceable(4), %"class.std::__ccr1::tuple.75"* dereferenceable(1)) local_unnamed_addr #7 align 2 personality i8* bitcast (i32 (...)* @__gxx_personality_sj0 to i8*) {
  %7 = getelementptr inbounds %"class.std::__ccr1::__tree", %"class.std::__ccr1::__tree"* %1, i32 0, i32 1, i32 0, i32 0 ; [#uses=3 type=%"class.std::__ccr1::__tree_end_node"*]
  %8 = bitcast %"class.std::__ccr1::__tree_end_node"* %7 to %"class.std::__ccr1::__tree_node"** ; [#uses=1 type=%"class.std::__ccr1::__tree_node"**]
  %9 = load %"class.std::__ccr1::__tree_node"*, %"class.std::__ccr1::__tree_node"** %8, align 4, !tbaa !7 ; [#uses=2 type=%"class.std::__ccr1::__tree_node"*]
  %10 = icmp eq %"class.std::__ccr1::__tree_node"* %9, null ; [#uses=1 type=i1]
  br i1 %10, label %40, label %11

; <label>:11:                                     ; preds = %6
  %12 = getelementptr inbounds %"class.std::__ccr1::__tree", %"class.std::__ccr1::__tree"* %1, i32 0, i32 1, i32 0, i32 0, i32 0 ; [#uses=1 type=%"class.std::__ccr1::__tree_node_base"**]
  %13 = load i8, i8* %2, align 1, !tbaa !4        ; [#uses=2 type=i8]
  br label %14

; <label>:14:                                     ; preds = %36, %11
  %15 = phi %"class.std::__ccr1::__tree_node"* [ %9, %11 ], [ %39, %36 ] ; [#uses=6 type=%"class.std::__ccr1::__tree_node"*]
  %16 = phi %"class.std::__ccr1::__tree_node_base"** [ %12, %11 ], [ %38, %36 ] ; [#uses=1 type=%"class.std::__ccr1::__tree_node_base"**]
  %17 = getelementptr inbounds %"class.std::__ccr1::__tree_node", %"class.std::__ccr1::__tree_node"* %15, i32 0, i32 1, i32 0, i32 0 ; [#uses=1 type=i8*]
  %18 = load i8, i8* %17, align 1, !tbaa !4       ; [#uses=2 type=i8]
  %19 = icmp slt i8 %13, %18                      ; [#uses=1 type=i1]
  br i1 %19, label %20, label %26

; <label>:20:                                     ; preds = %14
  %21 = getelementptr inbounds %"class.std::__ccr1::__tree_node", %"class.std::__ccr1::__tree_node"* %15, i32 0, i32 0, i32 0, i32 0 ; [#uses=3 type=%"class.std::__ccr1::__tree_node_base"**]
  %22 = load %"class.std::__ccr1::__tree_node_base"*, %"class.std::__ccr1::__tree_node_base"** %21, align 4, !tbaa !7 ; [#uses=2 type=%"class.std::__ccr1::__tree_node_base"*]
  %23 = icmp eq %"class.std::__ccr1::__tree_node_base"* %22, null ; [#uses=1 type=i1]
  br i1 %23, label %24, label %36

; <label>:24:                                     ; preds = %20
  %25 = getelementptr inbounds %"class.std::__ccr1::__tree_node", %"class.std::__ccr1::__tree_node"* %15, i32 0, i32 0, i32 0 ; [#uses=1 type=%"class.std::__ccr1::__tree_end_node"*]
  br label %42

; <label>:26:                                     ; preds = %14
  %27 = icmp slt i8 %18, %13                      ; [#uses=1 type=i1]
  br i1 %27, label %28, label %34

; <label>:28:                                     ; preds = %26
  %29 = getelementptr inbounds %"class.std::__ccr1::__tree_node", %"class.std::__ccr1::__tree_node"* %15, i32 0, i32 0, i32 1 ; [#uses=3 type=%"class.std::__ccr1::__tree_node_base"**]
  %30 = load %"class.std::__ccr1::__tree_node_base"*, %"class.std::__ccr1::__tree_node_base"** %29, align 4, !tbaa !46 ; [#uses=2 type=%"class.std::__ccr1::__tree_node_base"*]
  %31 = icmp eq %"class.std::__ccr1::__tree_node_base"* %30, null ; [#uses=1 type=i1]
  br i1 %31, label %32, label %36

; <label>:32:                                     ; preds = %28
  %33 = getelementptr inbounds %"class.std::__ccr1::__tree_node", %"class.std::__ccr1::__tree_node"* %15, i32 0, i32 0, i32 0 ; [#uses=1 type=%"class.std::__ccr1::__tree_end_node"*]
  br label %42

; <label>:34:                                     ; preds = %26
  %35 = getelementptr inbounds %"class.std::__ccr1::__tree_node", %"class.std::__ccr1::__tree_node"* %15, i32 0, i32 0, i32 0 ; [#uses=1 type=%"class.std::__ccr1::__tree_end_node"*]
  br label %42

; <label>:36:                                     ; preds = %28, %20
  %37 = phi %"class.std::__ccr1::__tree_node_base"* [ %22, %20 ], [ %30, %28 ] ; [#uses=1 type=%"class.std::__ccr1::__tree_node_base"*]
  %38 = phi %"class.std::__ccr1::__tree_node_base"** [ %21, %20 ], [ %29, %28 ] ; [#uses=1 type=%"class.std::__ccr1::__tree_node_base"**]
  %39 = bitcast %"class.std::__ccr1::__tree_node_base"* %37 to %"class.std::__ccr1::__tree_node"* ; [#uses=1 type=%"class.std::__ccr1::__tree_node"*]
  br label %14

; <label>:40:                                     ; preds = %6
  %41 = getelementptr inbounds %"class.std::__ccr1::__tree_end_node", %"class.std::__ccr1::__tree_end_node"* %7, i32 0, i32 0 ; [#uses=1 type=%"class.std::__ccr1::__tree_node_base"**]
  br label %42

; <label>:42:                                     ; preds = %24, %32, %34, %40
  %43 = phi %"class.std::__ccr1::__tree_end_node"* [ %7, %40 ], [ %25, %24 ], [ %33, %32 ], [ %35, %34 ] ; [#uses=1 type=%"class.std::__ccr1::__tree_end_node"*]
  %44 = phi %"class.std::__ccr1::__tree_node_base"** [ %41, %40 ], [ %21, %24 ], [ %29, %32 ], [ %16, %34 ] ; [#uses=2 type=%"class.std::__ccr1::__tree_node_base"**]
  %45 = bitcast %"class.std::__ccr1::__tree_node_base"** %44 to %"class.std::__ccr1::__tree_node"** ; [#uses=1 type=%"class.std::__ccr1::__tree_node"**]
  %46 = load %"class.std::__ccr1::__tree_node"*, %"class.std::__ccr1::__tree_node"** %45, align 4, !tbaa !10 ; [#uses=2 type=%"class.std::__ccr1::__tree_node"*]
  %47 = icmp eq %"class.std::__ccr1::__tree_node"* %46, null ; [#uses=1 type=i1]
  br i1 %47, label %48, label %58

; <label>:48:                                     ; preds = %42
  %49 = tail call i8* @_Znwm(i32 24) #18, !noalias !111 ; [#uses=4 type=i8*]
  %50 = getelementptr inbounds %"class.std::__ccr1::tuple", %"class.std::__ccr1::tuple"* %4, i32 0, i32 0, i32 0, i32 0 ; [#uses=1 type=i8**]
  %51 = load i8*, i8** %50, align 4, !noalias !111 ; [#uses=1 type=i8*]
  %52 = getelementptr inbounds i8, i8* %49, i32 16 ; [#uses=1 type=i8*]
  %53 = load i8, i8* %51, align 1, !tbaa !4, !noalias !111 ; [#uses=1 type=i8]
  store i8 %53, i8* %52, align 4, !tbaa !114, !noalias !111
  %54 = getelementptr inbounds i8, i8* %49, i32 20 ; [#uses=1 type=i8*]
  %55 = bitcast i8* %54 to i32*                   ; [#uses=1 type=i32*]
  store i32 0, i32* %55, align 4, !tbaa !116, !noalias !111
  %56 = bitcast i8* %49 to %"class.std::__ccr1::__tree_node"* ; [#uses=1 type=%"class.std::__ccr1::__tree_node"*]
  %57 = bitcast i8* %49 to %"class.std::__ccr1::__tree_node_base"* ; [#uses=1 type=%"class.std::__ccr1::__tree_node_base"*]
  tail call void @_ZNSt6__ccr16__treeINS_12__value_typeIciEENS_19__map_value_compareIcS2_NS_4lessIcEELb1EEENS_9allocatorIS2_EEE16__insert_node_atEPNS_15__tree_end_nodeIPNS_16__tree_node_baseIPvEEEERSE_SE_(%"class.std::__ccr1::__tree"* %1, %"class.std::__ccr1::__tree_end_node"* %43, %"class.std::__ccr1::__tree_node_base"** nonnull dereferenceable(4) %44, %"class.std::__ccr1::__tree_node_base"* nonnull %57) #17
  br label %58

; <label>:58:                                     ; preds = %48, %42
  %59 = phi i8 [ 1, %48 ], [ 0, %42 ]             ; [#uses=1 type=i8]
  %60 = phi %"class.std::__ccr1::__tree_node"* [ %56, %48 ], [ %46, %42 ] ; [#uses=1 type=%"class.std::__ccr1::__tree_node"*]
  %61 = ptrtoint %"class.std::__ccr1::__tree_node"* %60 to i32 ; [#uses=1 type=i32]
  %62 = bitcast %"struct.std::__ccr1::pair.74"* %0 to i32* ; [#uses=1 type=i32*]
  store i32 %61, i32* %62, align 4, !tbaa !10
  %63 = getelementptr inbounds %"struct.std::__ccr1::pair.74", %"struct.std::__ccr1::pair.74"* %0, i32 0, i32 1 ; [#uses=1 type=i8*]
  store i8 %59, i8* %63, align 4, !tbaa !117
  ret void
}

; [#uses=1]
; Function Attrs: norecurse nounwind optsize
define linkonce_odr void @_ZNSt6__ccr16__treeINS_12__value_typeIciEENS_19__map_value_compareIcS2_NS_4lessIcEELb1EEENS_9allocatorIS2_EEE16__insert_node_atEPNS_15__tree_end_nodeIPNS_16__tree_node_baseIPvEEEERSE_SE_(%"class.std::__ccr1::__tree"*, %"class.std::__ccr1::__tree_end_node"*, %"class.std::__ccr1::__tree_node_base"** dereferenceable(4), %"class.std::__ccr1::__tree_node_base"*) local_unnamed_addr #14 align 2 {
  %5 = getelementptr inbounds %"class.std::__ccr1::__tree_node_base", %"class.std::__ccr1::__tree_node_base"* %3, i32 0, i32 0, i32 0 ; [#uses=1 type=%"class.std::__ccr1::__tree_node_base"**]
  store %"class.std::__ccr1::__tree_node_base"* null, %"class.std::__ccr1::__tree_node_base"** %5, align 4, !tbaa !7
  %6 = getelementptr inbounds %"class.std::__ccr1::__tree_node_base", %"class.std::__ccr1::__tree_node_base"* %3, i32 0, i32 1 ; [#uses=1 type=%"class.std::__ccr1::__tree_node_base"**]
  store %"class.std::__ccr1::__tree_node_base"* null, %"class.std::__ccr1::__tree_node_base"** %6, align 4, !tbaa !46
  %7 = getelementptr inbounds %"class.std::__ccr1::__tree_node_base", %"class.std::__ccr1::__tree_node_base"* %3, i32 0, i32 2 ; [#uses=1 type=%"class.std::__ccr1::__tree_end_node"**]
  store %"class.std::__ccr1::__tree_end_node"* %1, %"class.std::__ccr1::__tree_end_node"** %7, align 4, !tbaa !119
  store %"class.std::__ccr1::__tree_node_base"* %3, %"class.std::__ccr1::__tree_node_base"** %2, align 4, !tbaa !10
  %8 = getelementptr inbounds %"class.std::__ccr1::__tree", %"class.std::__ccr1::__tree"* %0, i32 0, i32 0 ; [#uses=1 type=%"class.std::__ccr1::__tree_end_node"**]
  %9 = load %"class.std::__ccr1::__tree_end_node"*, %"class.std::__ccr1::__tree_end_node"** %8, align 4, !tbaa !10 ; [#uses=1 type=%"class.std::__ccr1::__tree_end_node"*]
  %10 = getelementptr inbounds %"class.std::__ccr1::__tree_end_node", %"class.std::__ccr1::__tree_end_node"* %9, i32 0, i32 0 ; [#uses=1 type=%"class.std::__ccr1::__tree_node_base"**]
  %11 = load %"class.std::__ccr1::__tree_node_base"*, %"class.std::__ccr1::__tree_node_base"** %10, align 4, !tbaa !7 ; [#uses=2 type=%"class.std::__ccr1::__tree_node_base"*]
  %12 = icmp eq %"class.std::__ccr1::__tree_node_base"* %11, null ; [#uses=1 type=i1]
  br i1 %12, label %17, label %13

; <label>:13:                                     ; preds = %4
  %14 = ptrtoint %"class.std::__ccr1::__tree_node_base"* %11 to i32 ; [#uses=1 type=i32]
  %15 = bitcast %"class.std::__ccr1::__tree"* %0 to i32* ; [#uses=1 type=i32*]
  store i32 %14, i32* %15, align 4, !tbaa !10
  %16 = load %"class.std::__ccr1::__tree_node_base"*, %"class.std::__ccr1::__tree_node_base"** %2, align 4, !tbaa !10 ; [#uses=1 type=%"class.std::__ccr1::__tree_node_base"*]
  br label %17

; <label>:17:                                     ; preds = %4, %13
  %18 = phi %"class.std::__ccr1::__tree_node_base"* [ %3, %4 ], [ %16, %13 ] ; [#uses=1 type=%"class.std::__ccr1::__tree_node_base"*]
  %19 = getelementptr inbounds %"class.std::__ccr1::__tree", %"class.std::__ccr1::__tree"* %0, i32 0, i32 1, i32 0, i32 0, i32 0 ; [#uses=1 type=%"class.std::__ccr1::__tree_node_base"**]
  %20 = load %"class.std::__ccr1::__tree_node_base"*, %"class.std::__ccr1::__tree_node_base"** %19, align 4, !tbaa !7 ; [#uses=1 type=%"class.std::__ccr1::__tree_node_base"*]
  tail call void @_ZNSt6__ccr127__tree_balance_after_insertIPNS_16__tree_node_baseIPvEEEEvT_S5_(%"class.std::__ccr1::__tree_node_base"* %20, %"class.std::__ccr1::__tree_node_base"* %18) #16
  %21 = getelementptr inbounds %"class.std::__ccr1::__tree", %"class.std::__ccr1::__tree"* %0, i32 0, i32 2, i32 0, i32 0 ; [#uses=2 type=i32*]
  %22 = load i32, i32* %21, align 4, !tbaa !120   ; [#uses=1 type=i32]
  %23 = add i32 %22, 1                            ; [#uses=1 type=i32]
  store i32 %23, i32* %21, align 4, !tbaa !120
  ret void
}

; [#uses=1]
; Function Attrs: norecurse nounwind optsize
define linkonce_odr void @_ZNSt6__ccr127__tree_balance_after_insertIPNS_16__tree_node_baseIPvEEEEvT_S5_(%"class.std::__ccr1::__tree_node_base"*, %"class.std::__ccr1::__tree_node_base"*) local_unnamed_addr #14 personality i8* bitcast (i32 (...)* @__gxx_personality_sj0 to i8*) {
  %3 = icmp eq %"class.std::__ccr1::__tree_node_base"* %1, %0 ; [#uses=2 type=i1]
  %4 = getelementptr inbounds %"class.std::__ccr1::__tree_node_base", %"class.std::__ccr1::__tree_node_base"* %1, i32 0, i32 3 ; [#uses=1 type=i8*]
  %5 = zext i1 %3 to i8                           ; [#uses=1 type=i8]
  store i8 %5, i8* %4, align 4, !tbaa !121
  br i1 %3, label %157, label %6

; <label>:6:                                      ; preds = %2
  br label %7

; <label>:7:                                      ; preds = %6, %150
  %8 = phi %"class.std::__ccr1::__tree_node_base"* [ %21, %150 ], [ %1, %6 ] ; [#uses=8 type=%"class.std::__ccr1::__tree_node_base"*]
  %9 = getelementptr inbounds %"class.std::__ccr1::__tree_node_base", %"class.std::__ccr1::__tree_node_base"* %8, i32 0, i32 2 ; [#uses=2 type=%"class.std::__ccr1::__tree_end_node"**]
  %10 = bitcast %"class.std::__ccr1::__tree_end_node"** %9 to %"class.std::__ccr1::__tree_node_base"** ; [#uses=1 type=%"class.std::__ccr1::__tree_node_base"**]
  %11 = load %"class.std::__ccr1::__tree_node_base"*, %"class.std::__ccr1::__tree_node_base"** %10, align 4, !tbaa !119 ; [#uses=15 type=%"class.std::__ccr1::__tree_node_base"*]
  %12 = getelementptr inbounds %"class.std::__ccr1::__tree_node_base", %"class.std::__ccr1::__tree_node_base"* %11, i32 0, i32 3 ; [#uses=4 type=i8*]
  %13 = load i8, i8* %12, align 4, !tbaa !121, !range !66 ; [#uses=1 type=i8]
  %14 = icmp eq i8 %13, 0                         ; [#uses=1 type=i1]
  br i1 %14, label %15, label %157

; <label>:15:                                     ; preds = %7
  %16 = getelementptr inbounds %"class.std::__ccr1::__tree_node_base", %"class.std::__ccr1::__tree_node_base"* %11, i32 0, i32 2 ; [#uses=1 type=%"class.std::__ccr1::__tree_end_node"**]
  %17 = load %"class.std::__ccr1::__tree_end_node"*, %"class.std::__ccr1::__tree_end_node"** %16, align 4, !tbaa !119 ; [#uses=8 type=%"class.std::__ccr1::__tree_end_node"*]
  %18 = getelementptr inbounds %"class.std::__ccr1::__tree_end_node", %"class.std::__ccr1::__tree_end_node"* %17, i32 0, i32 0 ; [#uses=1 type=%"class.std::__ccr1::__tree_node_base"**]
  %19 = load %"class.std::__ccr1::__tree_node_base"*, %"class.std::__ccr1::__tree_node_base"** %18, align 4, !tbaa !7 ; [#uses=3 type=%"class.std::__ccr1::__tree_node_base"*]
  %20 = icmp eq %"class.std::__ccr1::__tree_node_base"* %19, %11 ; [#uses=1 type=i1]
  %21 = bitcast %"class.std::__ccr1::__tree_end_node"* %17 to %"class.std::__ccr1::__tree_node_base"* ; [#uses=3 type=%"class.std::__ccr1::__tree_node_base"*]
  br i1 %20, label %22, label %88

; <label>:22:                                     ; preds = %15
  %23 = getelementptr inbounds %"class.std::__ccr1::__tree_end_node", %"class.std::__ccr1::__tree_end_node"* %17, i32 1, i32 0 ; [#uses=1 type=%"class.std::__ccr1::__tree_node_base"**]
  %24 = load %"class.std::__ccr1::__tree_node_base"*, %"class.std::__ccr1::__tree_node_base"** %23, align 4, !tbaa !46 ; [#uses=2 type=%"class.std::__ccr1::__tree_node_base"*]
  %25 = icmp eq %"class.std::__ccr1::__tree_node_base"* %24, null ; [#uses=1 type=i1]
  br i1 %25, label %30, label %26

; <label>:26:                                     ; preds = %22
  %27 = getelementptr inbounds %"class.std::__ccr1::__tree_node_base", %"class.std::__ccr1::__tree_node_base"* %24, i32 0, i32 3 ; [#uses=2 type=i8*]
  %28 = load i8, i8* %27, align 4, !tbaa !121, !range !66 ; [#uses=1 type=i8]
  %29 = icmp eq i8 %28, 0                         ; [#uses=1 type=i1]
  br i1 %29, label %150, label %30

; <label>:30:                                     ; preds = %26, %22
  %31 = getelementptr inbounds %"class.std::__ccr1::__tree_node_base", %"class.std::__ccr1::__tree_node_base"* %11, i32 0, i32 2 ; [#uses=3 type=%"class.std::__ccr1::__tree_end_node"**]
  %32 = bitcast %"class.std::__ccr1::__tree_end_node"* %17 to %"class.std::__ccr1::__tree_node_base"* ; [#uses=1 type=%"class.std::__ccr1::__tree_node_base"*]
  %33 = getelementptr inbounds %"class.std::__ccr1::__tree_node_base", %"class.std::__ccr1::__tree_node_base"* %11, i32 0, i32 0, i32 0 ; [#uses=1 type=%"class.std::__ccr1::__tree_node_base"**]
  %34 = load %"class.std::__ccr1::__tree_node_base"*, %"class.std::__ccr1::__tree_node_base"** %33, align 4, !tbaa !7 ; [#uses=1 type=%"class.std::__ccr1::__tree_node_base"*]
  %35 = icmp eq %"class.std::__ccr1::__tree_node_base"* %34, %8 ; [#uses=1 type=i1]
  br i1 %35, label %63, label %36

; <label>:36:                                     ; preds = %30
  %37 = ptrtoint %"class.std::__ccr1::__tree_end_node"* %17 to i32 ; [#uses=1 type=i32]
  %38 = getelementptr inbounds %"class.std::__ccr1::__tree_node_base", %"class.std::__ccr1::__tree_node_base"* %11, i32 0, i32 1 ; [#uses=2 type=%"class.std::__ccr1::__tree_node_base"**]
  %39 = load %"class.std::__ccr1::__tree_node_base"*, %"class.std::__ccr1::__tree_node_base"** %38, align 4, !tbaa !46 ; [#uses=6 type=%"class.std::__ccr1::__tree_node_base"*]
  %40 = getelementptr inbounds %"class.std::__ccr1::__tree_node_base", %"class.std::__ccr1::__tree_node_base"* %39, i32 0, i32 0, i32 0 ; [#uses=2 type=%"class.std::__ccr1::__tree_node_base"**]
  %41 = load %"class.std::__ccr1::__tree_node_base"*, %"class.std::__ccr1::__tree_node_base"** %40, align 4, !tbaa !7 ; [#uses=3 type=%"class.std::__ccr1::__tree_node_base"*]
  store %"class.std::__ccr1::__tree_node_base"* %41, %"class.std::__ccr1::__tree_node_base"** %38, align 4, !tbaa !46
  %42 = icmp eq %"class.std::__ccr1::__tree_node_base"* %41, null ; [#uses=1 type=i1]
  br i1 %42, label %48, label %43

; <label>:43:                                     ; preds = %36
  %44 = getelementptr inbounds %"class.std::__ccr1::__tree_node_base", %"class.std::__ccr1::__tree_node_base"* %11, i32 0, i32 0 ; [#uses=1 type=%"class.std::__ccr1::__tree_end_node"*]
  %45 = getelementptr inbounds %"class.std::__ccr1::__tree_node_base", %"class.std::__ccr1::__tree_node_base"* %41, i32 0, i32 2 ; [#uses=1 type=%"class.std::__ccr1::__tree_end_node"**]
  store %"class.std::__ccr1::__tree_end_node"* %44, %"class.std::__ccr1::__tree_end_node"** %45, align 4, !tbaa !119
  %46 = bitcast %"class.std::__ccr1::__tree_end_node"** %31 to i32* ; [#uses=1 type=i32*]
  %47 = load i32, i32* %46, align 4, !tbaa !119   ; [#uses=1 type=i32]
  br label %48

; <label>:48:                                     ; preds = %36, %43
  %49 = phi i32 [ %47, %43 ], [ %37, %36 ]        ; [#uses=1 type=i32]
  %50 = getelementptr inbounds %"class.std::__ccr1::__tree_node_base", %"class.std::__ccr1::__tree_node_base"* %39, i32 0, i32 2 ; [#uses=1 type=%"class.std::__ccr1::__tree_end_node"**]
  %51 = bitcast %"class.std::__ccr1::__tree_end_node"** %50 to i32* ; [#uses=1 type=i32*]
  store i32 %49, i32* %51, align 4, !tbaa !119
  %52 = load %"class.std::__ccr1::__tree_end_node"*, %"class.std::__ccr1::__tree_end_node"** %31, align 4, !tbaa !119 ; [#uses=2 type=%"class.std::__ccr1::__tree_end_node"*]
  %53 = getelementptr inbounds %"class.std::__ccr1::__tree_end_node", %"class.std::__ccr1::__tree_end_node"* %52, i32 0, i32 0 ; [#uses=2 type=%"class.std::__ccr1::__tree_node_base"**]
  %54 = load %"class.std::__ccr1::__tree_node_base"*, %"class.std::__ccr1::__tree_node_base"** %53, align 4, !tbaa !7 ; [#uses=1 type=%"class.std::__ccr1::__tree_node_base"*]
  %55 = icmp eq %"class.std::__ccr1::__tree_node_base"* %54, %11 ; [#uses=1 type=i1]
  %56 = getelementptr inbounds %"class.std::__ccr1::__tree_end_node", %"class.std::__ccr1::__tree_end_node"* %52, i32 1, i32 0 ; [#uses=1 type=%"class.std::__ccr1::__tree_node_base"**]
  %57 = select i1 %55, %"class.std::__ccr1::__tree_node_base"** %53, %"class.std::__ccr1::__tree_node_base"** %56 ; [#uses=1 type=%"class.std::__ccr1::__tree_node_base"**]
  store %"class.std::__ccr1::__tree_node_base"* %39, %"class.std::__ccr1::__tree_node_base"** %57, align 4, !tbaa !10
  store %"class.std::__ccr1::__tree_node_base"* %11, %"class.std::__ccr1::__tree_node_base"** %40, align 4, !tbaa !7
  %58 = getelementptr inbounds %"class.std::__ccr1::__tree_node_base", %"class.std::__ccr1::__tree_node_base"* %39, i32 0, i32 0 ; [#uses=1 type=%"class.std::__ccr1::__tree_end_node"*]
  store %"class.std::__ccr1::__tree_end_node"* %58, %"class.std::__ccr1::__tree_end_node"** %31, align 4, !tbaa !119
  %59 = getelementptr inbounds %"class.std::__ccr1::__tree_node_base", %"class.std::__ccr1::__tree_node_base"* %39, i32 0, i32 2 ; [#uses=1 type=%"class.std::__ccr1::__tree_end_node"**]
  %60 = bitcast %"class.std::__ccr1::__tree_end_node"** %59 to %"class.std::__ccr1::__tree_node_base"** ; [#uses=1 type=%"class.std::__ccr1::__tree_node_base"**]
  %61 = load %"class.std::__ccr1::__tree_node_base"*, %"class.std::__ccr1::__tree_node_base"** %60, align 4, !tbaa !119 ; [#uses=1 type=%"class.std::__ccr1::__tree_node_base"*]
  %62 = getelementptr inbounds %"class.std::__ccr1::__tree_node_base", %"class.std::__ccr1::__tree_node_base"* %39, i32 0, i32 3 ; [#uses=1 type=i8*]
  br label %63

; <label>:63:                                     ; preds = %48, %30
  %64 = phi i8* [ %62, %48 ], [ %12, %30 ]        ; [#uses=1 type=i8*]
  %65 = phi %"class.std::__ccr1::__tree_node_base"* [ %61, %48 ], [ %32, %30 ] ; [#uses=6 type=%"class.std::__ccr1::__tree_node_base"*]
  store i8 1, i8* %64, align 4, !tbaa !121
  %66 = getelementptr inbounds %"class.std::__ccr1::__tree_node_base", %"class.std::__ccr1::__tree_node_base"* %65, i32 0, i32 3 ; [#uses=1 type=i8*]
  store i8 0, i8* %66, align 4, !tbaa !121
  %67 = getelementptr inbounds %"class.std::__ccr1::__tree_node_base", %"class.std::__ccr1::__tree_node_base"* %65, i32 0, i32 0, i32 0 ; [#uses=2 type=%"class.std::__ccr1::__tree_node_base"**]
  %68 = load %"class.std::__ccr1::__tree_node_base"*, %"class.std::__ccr1::__tree_node_base"** %67, align 4, !tbaa !7 ; [#uses=4 type=%"class.std::__ccr1::__tree_node_base"*]
  %69 = getelementptr inbounds %"class.std::__ccr1::__tree_node_base", %"class.std::__ccr1::__tree_node_base"* %68, i32 0, i32 1 ; [#uses=2 type=%"class.std::__ccr1::__tree_node_base"**]
  %70 = load %"class.std::__ccr1::__tree_node_base"*, %"class.std::__ccr1::__tree_node_base"** %69, align 4, !tbaa !46 ; [#uses=3 type=%"class.std::__ccr1::__tree_node_base"*]
  store %"class.std::__ccr1::__tree_node_base"* %70, %"class.std::__ccr1::__tree_node_base"** %67, align 4, !tbaa !7
  %71 = icmp eq %"class.std::__ccr1::__tree_node_base"* %70, null ; [#uses=1 type=i1]
  br i1 %71, label %75, label %72

; <label>:72:                                     ; preds = %63
  %73 = getelementptr inbounds %"class.std::__ccr1::__tree_node_base", %"class.std::__ccr1::__tree_node_base"* %65, i32 0, i32 0 ; [#uses=1 type=%"class.std::__ccr1::__tree_end_node"*]
  %74 = getelementptr inbounds %"class.std::__ccr1::__tree_node_base", %"class.std::__ccr1::__tree_node_base"* %70, i32 0, i32 2 ; [#uses=1 type=%"class.std::__ccr1::__tree_end_node"**]
  store %"class.std::__ccr1::__tree_end_node"* %73, %"class.std::__ccr1::__tree_end_node"** %74, align 4, !tbaa !119
  br label %75

; <label>:75:                                     ; preds = %72, %63
  %76 = getelementptr inbounds %"class.std::__ccr1::__tree_node_base", %"class.std::__ccr1::__tree_node_base"* %65, i32 0, i32 2 ; [#uses=3 type=%"class.std::__ccr1::__tree_end_node"**]
  %77 = bitcast %"class.std::__ccr1::__tree_end_node"** %76 to i32* ; [#uses=1 type=i32*]
  %78 = load i32, i32* %77, align 4, !tbaa !119   ; [#uses=1 type=i32]
  %79 = getelementptr inbounds %"class.std::__ccr1::__tree_node_base", %"class.std::__ccr1::__tree_node_base"* %68, i32 0, i32 2 ; [#uses=1 type=%"class.std::__ccr1::__tree_end_node"**]
  %80 = bitcast %"class.std::__ccr1::__tree_end_node"** %79 to i32* ; [#uses=1 type=i32*]
  store i32 %78, i32* %80, align 4, !tbaa !119
  %81 = load %"class.std::__ccr1::__tree_end_node"*, %"class.std::__ccr1::__tree_end_node"** %76, align 4, !tbaa !119 ; [#uses=2 type=%"class.std::__ccr1::__tree_end_node"*]
  %82 = getelementptr inbounds %"class.std::__ccr1::__tree_end_node", %"class.std::__ccr1::__tree_end_node"* %81, i32 0, i32 0 ; [#uses=2 type=%"class.std::__ccr1::__tree_node_base"**]
  %83 = load %"class.std::__ccr1::__tree_node_base"*, %"class.std::__ccr1::__tree_node_base"** %82, align 4, !tbaa !7 ; [#uses=1 type=%"class.std::__ccr1::__tree_node_base"*]
  %84 = icmp eq %"class.std::__ccr1::__tree_node_base"* %83, %65 ; [#uses=1 type=i1]
  %85 = getelementptr inbounds %"class.std::__ccr1::__tree_end_node", %"class.std::__ccr1::__tree_end_node"* %81, i32 1, i32 0 ; [#uses=1 type=%"class.std::__ccr1::__tree_node_base"**]
  %86 = select i1 %84, %"class.std::__ccr1::__tree_node_base"** %82, %"class.std::__ccr1::__tree_node_base"** %85 ; [#uses=1 type=%"class.std::__ccr1::__tree_node_base"**]
  store %"class.std::__ccr1::__tree_node_base"* %68, %"class.std::__ccr1::__tree_node_base"** %86, align 4, !tbaa !10
  store %"class.std::__ccr1::__tree_node_base"* %65, %"class.std::__ccr1::__tree_node_base"** %69, align 4, !tbaa !46
  %87 = getelementptr inbounds %"class.std::__ccr1::__tree_node_base", %"class.std::__ccr1::__tree_node_base"* %68, i32 0, i32 0 ; [#uses=1 type=%"class.std::__ccr1::__tree_end_node"*]
  store %"class.std::__ccr1::__tree_end_node"* %87, %"class.std::__ccr1::__tree_end_node"** %76, align 4, !tbaa !119
  br label %157

; <label>:88:                                     ; preds = %15
  %89 = icmp eq %"class.std::__ccr1::__tree_node_base"* %19, null ; [#uses=1 type=i1]
  br i1 %89, label %94, label %90

; <label>:90:                                     ; preds = %88
  %91 = getelementptr inbounds %"class.std::__ccr1::__tree_node_base", %"class.std::__ccr1::__tree_node_base"* %19, i32 0, i32 3 ; [#uses=2 type=i8*]
  %92 = load i8, i8* %91, align 4, !tbaa !121, !range !66 ; [#uses=1 type=i8]
  %93 = icmp eq i8 %92, 0                         ; [#uses=1 type=i1]
  br i1 %93, label %150, label %94

; <label>:94:                                     ; preds = %90, %88
  %95 = getelementptr inbounds %"class.std::__ccr1::__tree_node_base", %"class.std::__ccr1::__tree_node_base"* %11, i32 0, i32 2 ; [#uses=3 type=%"class.std::__ccr1::__tree_end_node"**]
  %96 = bitcast %"class.std::__ccr1::__tree_end_node"* %17 to %"class.std::__ccr1::__tree_node_base"* ; [#uses=1 type=%"class.std::__ccr1::__tree_node_base"*]
  %97 = getelementptr inbounds %"class.std::__ccr1::__tree_node_base", %"class.std::__ccr1::__tree_node_base"* %11, i32 0, i32 0, i32 0 ; [#uses=1 type=%"class.std::__ccr1::__tree_node_base"**]
  %98 = load %"class.std::__ccr1::__tree_node_base"*, %"class.std::__ccr1::__tree_node_base"** %97, align 4, !tbaa !7 ; [#uses=1 type=%"class.std::__ccr1::__tree_node_base"*]
  %99 = icmp eq %"class.std::__ccr1::__tree_node_base"* %98, %8 ; [#uses=1 type=i1]
  br i1 %99, label %100, label %125

; <label>:100:                                    ; preds = %94
  %101 = ptrtoint %"class.std::__ccr1::__tree_end_node"* %17 to i32 ; [#uses=1 type=i32]
  %102 = getelementptr inbounds %"class.std::__ccr1::__tree_node_base", %"class.std::__ccr1::__tree_node_base"* %11, i32 0, i32 0, i32 0 ; [#uses=1 type=%"class.std::__ccr1::__tree_node_base"**]
  %103 = getelementptr inbounds %"class.std::__ccr1::__tree_node_base", %"class.std::__ccr1::__tree_node_base"* %8, i32 0, i32 1 ; [#uses=2 type=%"class.std::__ccr1::__tree_node_base"**]
  %104 = load %"class.std::__ccr1::__tree_node_base"*, %"class.std::__ccr1::__tree_node_base"** %103, align 4, !tbaa !46 ; [#uses=3 type=%"class.std::__ccr1::__tree_node_base"*]
  store %"class.std::__ccr1::__tree_node_base"* %104, %"class.std::__ccr1::__tree_node_base"** %102, align 4, !tbaa !7
  %105 = icmp eq %"class.std::__ccr1::__tree_node_base"* %104, null ; [#uses=1 type=i1]
  br i1 %105, label %111, label %106

; <label>:106:                                    ; preds = %100
  %107 = getelementptr inbounds %"class.std::__ccr1::__tree_node_base", %"class.std::__ccr1::__tree_node_base"* %11, i32 0, i32 0 ; [#uses=1 type=%"class.std::__ccr1::__tree_end_node"*]
  %108 = getelementptr inbounds %"class.std::__ccr1::__tree_node_base", %"class.std::__ccr1::__tree_node_base"* %104, i32 0, i32 2 ; [#uses=1 type=%"class.std::__ccr1::__tree_end_node"**]
  store %"class.std::__ccr1::__tree_end_node"* %107, %"class.std::__ccr1::__tree_end_node"** %108, align 4, !tbaa !119
  %109 = bitcast %"class.std::__ccr1::__tree_end_node"** %95 to i32* ; [#uses=1 type=i32*]
  %110 = load i32, i32* %109, align 4, !tbaa !119 ; [#uses=1 type=i32]
  br label %111

; <label>:111:                                    ; preds = %100, %106
  %112 = phi i32 [ %110, %106 ], [ %101, %100 ]   ; [#uses=1 type=i32]
  %113 = bitcast %"class.std::__ccr1::__tree_end_node"** %9 to i32* ; [#uses=1 type=i32*]
  store i32 %112, i32* %113, align 4, !tbaa !119
  %114 = load %"class.std::__ccr1::__tree_end_node"*, %"class.std::__ccr1::__tree_end_node"** %95, align 4, !tbaa !119 ; [#uses=2 type=%"class.std::__ccr1::__tree_end_node"*]
  %115 = getelementptr inbounds %"class.std::__ccr1::__tree_end_node", %"class.std::__ccr1::__tree_end_node"* %114, i32 0, i32 0 ; [#uses=2 type=%"class.std::__ccr1::__tree_node_base"**]
  %116 = load %"class.std::__ccr1::__tree_node_base"*, %"class.std::__ccr1::__tree_node_base"** %115, align 4, !tbaa !7 ; [#uses=1 type=%"class.std::__ccr1::__tree_node_base"*]
  %117 = icmp eq %"class.std::__ccr1::__tree_node_base"* %116, %11 ; [#uses=1 type=i1]
  %118 = getelementptr inbounds %"class.std::__ccr1::__tree_end_node", %"class.std::__ccr1::__tree_end_node"* %114, i32 1, i32 0 ; [#uses=1 type=%"class.std::__ccr1::__tree_node_base"**]
  %119 = select i1 %117, %"class.std::__ccr1::__tree_node_base"** %115, %"class.std::__ccr1::__tree_node_base"** %118 ; [#uses=1 type=%"class.std::__ccr1::__tree_node_base"**]
  store %"class.std::__ccr1::__tree_node_base"* %8, %"class.std::__ccr1::__tree_node_base"** %119, align 4, !tbaa !10
  store %"class.std::__ccr1::__tree_node_base"* %11, %"class.std::__ccr1::__tree_node_base"** %103, align 4, !tbaa !46
  %120 = getelementptr inbounds %"class.std::__ccr1::__tree_node_base", %"class.std::__ccr1::__tree_node_base"* %8, i32 0, i32 0 ; [#uses=1 type=%"class.std::__ccr1::__tree_end_node"*]
  store %"class.std::__ccr1::__tree_end_node"* %120, %"class.std::__ccr1::__tree_end_node"** %95, align 4, !tbaa !119
  %121 = getelementptr inbounds %"class.std::__ccr1::__tree_node_base", %"class.std::__ccr1::__tree_node_base"* %8, i32 0, i32 2 ; [#uses=1 type=%"class.std::__ccr1::__tree_end_node"**]
  %122 = bitcast %"class.std::__ccr1::__tree_end_node"** %121 to %"class.std::__ccr1::__tree_node_base"** ; [#uses=1 type=%"class.std::__ccr1::__tree_node_base"**]
  %123 = load %"class.std::__ccr1::__tree_node_base"*, %"class.std::__ccr1::__tree_node_base"** %122, align 4, !tbaa !119 ; [#uses=1 type=%"class.std::__ccr1::__tree_node_base"*]
  %124 = getelementptr inbounds %"class.std::__ccr1::__tree_node_base", %"class.std::__ccr1::__tree_node_base"* %8, i32 0, i32 3 ; [#uses=1 type=i8*]
  br label %125

; <label>:125:                                    ; preds = %94, %111
  %126 = phi i8* [ %124, %111 ], [ %12, %94 ]     ; [#uses=1 type=i8*]
  %127 = phi %"class.std::__ccr1::__tree_node_base"* [ %123, %111 ], [ %96, %94 ] ; [#uses=6 type=%"class.std::__ccr1::__tree_node_base"*]
  store i8 1, i8* %126, align 4, !tbaa !121
  %128 = getelementptr inbounds %"class.std::__ccr1::__tree_node_base", %"class.std::__ccr1::__tree_node_base"* %127, i32 0, i32 3 ; [#uses=1 type=i8*]
  store i8 0, i8* %128, align 4, !tbaa !121
  %129 = getelementptr inbounds %"class.std::__ccr1::__tree_node_base", %"class.std::__ccr1::__tree_node_base"* %127, i32 0, i32 1 ; [#uses=2 type=%"class.std::__ccr1::__tree_node_base"**]
  %130 = load %"class.std::__ccr1::__tree_node_base"*, %"class.std::__ccr1::__tree_node_base"** %129, align 4, !tbaa !46 ; [#uses=4 type=%"class.std::__ccr1::__tree_node_base"*]
  %131 = getelementptr inbounds %"class.std::__ccr1::__tree_node_base", %"class.std::__ccr1::__tree_node_base"* %130, i32 0, i32 0, i32 0 ; [#uses=2 type=%"class.std::__ccr1::__tree_node_base"**]
  %132 = load %"class.std::__ccr1::__tree_node_base"*, %"class.std::__ccr1::__tree_node_base"** %131, align 4, !tbaa !7 ; [#uses=3 type=%"class.std::__ccr1::__tree_node_base"*]
  store %"class.std::__ccr1::__tree_node_base"* %132, %"class.std::__ccr1::__tree_node_base"** %129, align 4, !tbaa !46
  %133 = icmp eq %"class.std::__ccr1::__tree_node_base"* %132, null ; [#uses=1 type=i1]
  br i1 %133, label %137, label %134

; <label>:134:                                    ; preds = %125
  %135 = getelementptr inbounds %"class.std::__ccr1::__tree_node_base", %"class.std::__ccr1::__tree_node_base"* %127, i32 0, i32 0 ; [#uses=1 type=%"class.std::__ccr1::__tree_end_node"*]
  %136 = getelementptr inbounds %"class.std::__ccr1::__tree_node_base", %"class.std::__ccr1::__tree_node_base"* %132, i32 0, i32 2 ; [#uses=1 type=%"class.std::__ccr1::__tree_end_node"**]
  store %"class.std::__ccr1::__tree_end_node"* %135, %"class.std::__ccr1::__tree_end_node"** %136, align 4, !tbaa !119
  br label %137

; <label>:137:                                    ; preds = %134, %125
  %138 = getelementptr inbounds %"class.std::__ccr1::__tree_node_base", %"class.std::__ccr1::__tree_node_base"* %127, i32 0, i32 2 ; [#uses=3 type=%"class.std::__ccr1::__tree_end_node"**]
  %139 = bitcast %"class.std::__ccr1::__tree_end_node"** %138 to i32* ; [#uses=1 type=i32*]
  %140 = load i32, i32* %139, align 4, !tbaa !119 ; [#uses=1 type=i32]
  %141 = getelementptr inbounds %"class.std::__ccr1::__tree_node_base", %"class.std::__ccr1::__tree_node_base"* %130, i32 0, i32 2 ; [#uses=1 type=%"class.std::__ccr1::__tree_end_node"**]
  %142 = bitcast %"class.std::__ccr1::__tree_end_node"** %141 to i32* ; [#uses=1 type=i32*]
  store i32 %140, i32* %142, align 4, !tbaa !119
  %143 = load %"class.std::__ccr1::__tree_end_node"*, %"class.std::__ccr1::__tree_end_node"** %138, align 4, !tbaa !119 ; [#uses=2 type=%"class.std::__ccr1::__tree_end_node"*]
  %144 = getelementptr inbounds %"class.std::__ccr1::__tree_end_node", %"class.std::__ccr1::__tree_end_node"* %143, i32 0, i32 0 ; [#uses=2 type=%"class.std::__ccr1::__tree_node_base"**]
  %145 = load %"class.std::__ccr1::__tree_node_base"*, %"class.std::__ccr1::__tree_node_base"** %144, align 4, !tbaa !7 ; [#uses=1 type=%"class.std::__ccr1::__tree_node_base"*]
  %146 = icmp eq %"class.std::__ccr1::__tree_node_base"* %145, %127 ; [#uses=1 type=i1]
  %147 = getelementptr inbounds %"class.std::__ccr1::__tree_end_node", %"class.std::__ccr1::__tree_end_node"* %143, i32 1, i32 0 ; [#uses=1 type=%"class.std::__ccr1::__tree_node_base"**]
  %148 = select i1 %146, %"class.std::__ccr1::__tree_node_base"** %144, %"class.std::__ccr1::__tree_node_base"** %147 ; [#uses=1 type=%"class.std::__ccr1::__tree_node_base"**]
  store %"class.std::__ccr1::__tree_node_base"* %130, %"class.std::__ccr1::__tree_node_base"** %148, align 4, !tbaa !10
  store %"class.std::__ccr1::__tree_node_base"* %127, %"class.std::__ccr1::__tree_node_base"** %131, align 4, !tbaa !7
  %149 = getelementptr inbounds %"class.std::__ccr1::__tree_node_base", %"class.std::__ccr1::__tree_node_base"* %130, i32 0, i32 0 ; [#uses=1 type=%"class.std::__ccr1::__tree_end_node"*]
  store %"class.std::__ccr1::__tree_end_node"* %149, %"class.std::__ccr1::__tree_end_node"** %138, align 4, !tbaa !119
  br label %157

; <label>:150:                                    ; preds = %90, %26
  %151 = phi i8* [ %27, %26 ], [ %91, %90 ]       ; [#uses=1 type=i8*]
  store i8 1, i8* %12, align 4, !tbaa !121
  %152 = icmp eq %"class.std::__ccr1::__tree_node_base"* %21, %0 ; [#uses=1 type=i1]
  %153 = getelementptr inbounds %"class.std::__ccr1::__tree_end_node", %"class.std::__ccr1::__tree_end_node"* %17, i32 3 ; [#uses=1 type=%"class.std::__ccr1::__tree_end_node"*]
  %154 = bitcast %"class.std::__ccr1::__tree_end_node"* %153 to i8* ; [#uses=1 type=i8*]
  %155 = zext i1 %152 to i8                       ; [#uses=1 type=i8]
  store i8 %155, i8* %154, align 4, !tbaa !121
  store i8 1, i8* %151, align 4, !tbaa !121
  %156 = icmp eq %"class.std::__ccr1::__tree_node_base"* %21, %0 ; [#uses=1 type=i1]
  br i1 %156, label %157, label %7

; <label>:157:                                    ; preds = %7, %150, %2, %137, %75
  ret void
}

; [#uses=1]
; Function Attrs: optsize
define internal void @_GLOBAL__sub_I_ush.cpp() #7 section "__TEXT,__StaticInit,regular,pure_instructions" personality i32 (...)* @__gxx_personality_sj0 {
  tail call void @llvm.memset.p0i8.i32(i8* bitcast (%"class.std::__ccr1::basic_string"* @prompt to i8*), i8 0, i32 12, i32 4, i1 false) #1
  %1 = tail call i8* @_Znwm(i32 32) #18           ; [#uses=3 type=i8*]
  store i8* %1, i8** getelementptr inbounds (%"class.std::__ccr1::basic_string", %"class.std::__ccr1::basic_string"* @prompt, i32 0, i32 0, i32 0, i32 0, i32 0, i32 0, i32 2), align 4, !tbaa !4
  store i32 33, i32* getelementptr inbounds (%"class.std::__ccr1::basic_string", %"class.std::__ccr1::basic_string"* @prompt, i32 0, i32 0, i32 0, i32 0, i32 0, i32 0, i32 0), align 4, !tbaa !4
  store i32 18, i32* getelementptr inbounds (%"class.std::__ccr1::basic_string", %"class.std::__ccr1::basic_string"* @prompt, i32 0, i32 0, i32 0, i32 0, i32 0, i32 0, i32 1), align 4, !tbaa !4
  tail call void @llvm.memcpy.p0i8.p0i8.i32(i8* nonnull %1, i8* getelementptr inbounds ([19 x i8], [19 x i8]* @.str, i32 0, i32 0), i32 18, i32 1, i1 false) #1
  %2 = getelementptr inbounds i8, i8* %1, i32 18  ; [#uses=1 type=i8*]
  store i8 0, i8* %2, align 1, !tbaa !4
  %3 = tail call i32 @atexit(void ()* nonnull @__dtor_prompt) #1 ; [#uses=0 type=i32]
  tail call void @llvm.memset.p0i8.i64(i8* bitcast (%"class.std::__ccr1::basic_string"* @_ZL13IdentifierStr to i8*), i8 0, i64 12, i32 4, i1 false) #1
  %4 = tail call i32 @atexit(void ()* nonnull @__dtor__ZL13IdentifierStr) #1 ; [#uses=0 type=i32]
  store %"class.std::__ccr1::__tree_node_base"* null, %"class.std::__ccr1::__tree_node_base"** getelementptr inbounds (%"class.std::__ccr1::map", %"class.std::__ccr1::map"* @_ZL15BinopPrecedence, i32 0, i32 0, i32 1, i32 0, i32 0, i32 0), align 4, !tbaa !7
  store i32 0, i32* getelementptr inbounds (%"class.std::__ccr1::map", %"class.std::__ccr1::map"* @_ZL15BinopPrecedence, i32 0, i32 0, i32 2, i32 0, i32 0), align 4, !tbaa !122
  store %"class.std::__ccr1::__tree_end_node"* getelementptr inbounds (%"class.std::__ccr1::map", %"class.std::__ccr1::map"* @_ZL15BinopPrecedence, i32 0, i32 0, i32 1, i32 0, i32 0), %"class.std::__ccr1::__tree_end_node"** getelementptr inbounds (%"class.std::__ccr1::map", %"class.std::__ccr1::map"* @_ZL15BinopPrecedence, i32 0, i32 0, i32 0), align 4, !tbaa !10
  %5 = tail call i32 @atexit(void ()* nonnull @__dtor__ZL15BinopPrecedence) #1 ; [#uses=0 type=i32]
  ret void
}

; [#uses=4]
; Function Attrs: argmemonly nounwind
declare void @llvm.memset.p0i8.i64(i8* nocapture writeonly, i8, i64, i32, i1) #4

attributes #0 = { nounwind optsize "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="arm7tdmi" "target-features"="+soft-float,+strict-align,-crypto,-neon,-thumb-mode" "unsafe-fp-math"="false" "use-soft-float"="true" }
attributes #1 = { nounwind }
attributes #2 = { norecurse optsize "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="arm7tdmi" "target-features"="+soft-float,+strict-align,-crypto,-neon,-thumb-mode" "unsafe-fp-math"="false" "use-soft-float"="true" }
attributes #3 = { nounwind optsize "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="arm7tdmi" "target-features"="+soft-float,+strict-align,-crypto,-neon,-thumb-mode" "unsafe-fp-math"="false" "use-soft-float"="true" }
attributes #4 = { argmemonly nounwind }
attributes #5 = { noinline noreturn nounwind }
attributes #6 = { nobuiltin nounwind optsize "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="arm7tdmi" "target-features"="+soft-float,+strict-align,-crypto,-neon,-thumb-mode" "unsafe-fp-math"="false" "use-soft-float"="true" }
attributes #7 = { optsize "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="arm7tdmi" "target-features"="+soft-float,+strict-align,-crypto,-neon,-thumb-mode" "unsafe-fp-math"="false" "use-soft-float"="true" }
attributes #8 = { optsize "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="arm7tdmi" "target-features"="+soft-float,+strict-align,-crypto,-neon,-thumb-mode" "unsafe-fp-math"="false" "use-soft-float"="true" }
attributes #9 = { argmemonly nounwind optsize readonly "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="arm7tdmi" "target-features"="+soft-float,+strict-align,-crypto,-neon,-thumb-mode" "unsafe-fp-math"="false" "use-soft-float"="true" }
attributes #10 = { noreturn optsize "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="arm7tdmi" "target-features"="+soft-float,+strict-align,-crypto,-neon,-thumb-mode" "unsafe-fp-math"="false" "use-soft-float"="true" }
attributes #11 = { nobuiltin optsize "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="arm7tdmi" "target-features"="+soft-float,+strict-align,-crypto,-neon,-thumb-mode" "unsafe-fp-math"="false" "use-soft-float"="true" }
attributes #12 = { inlinehint nounwind optsize "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="arm7tdmi" "target-features"="+soft-float,+strict-align,-crypto,-neon,-thumb-mode" "unsafe-fp-math"="false" "use-soft-float"="true" }
attributes #13 = { inlinehint norecurse nounwind optsize readnone "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="arm7tdmi" "target-features"="+soft-float,+strict-align,-crypto,-neon,-thumb-mode" "unsafe-fp-math"="false" "use-soft-float"="true" }
attributes #14 = { norecurse nounwind optsize "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="arm7tdmi" "target-features"="+soft-float,+strict-align,-crypto,-neon,-thumb-mode" "unsafe-fp-math"="false" "use-soft-float"="true" }
attributes #15 = { builtin nounwind optsize }
attributes #16 = { nounwind optsize }
attributes #17 = { optsize }
attributes #18 = { builtin optsize }
attributes #19 = { noreturn nounwind }
attributes #20 = { noreturn optsize }
attributes #21 = { noreturn }

!llvm.module.flags = !{!0, !1, !2}
!llvm.ident = !{!3}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{i32 1, !"min_enum_size", i32 4}
!2 = !{i32 7, !"PIC Level", i32 2}
!3 = !{!"clang version 6.0.0 (tags/RELEASE_600/final)"}
!4 = !{!5, !5, i64 0}
!5 = !{!"omnipotent char", !6, i64 0}
!6 = !{!"Simple C++ TBAA"}
!7 = !{!8, !9, i64 0}
!8 = !{!"_ZTSNSt6__ccr115__tree_end_nodeIPNS_16__tree_node_baseIPvEEEE", !9, i64 0}
!9 = !{!"any pointer", !5, i64 0}
!10 = !{!9, !9, i64 0}
!11 = !{!12, !9, i64 0}
!12 = !{!"_ZTSNSt6__ccr115__tree_iteratorINS_12__value_typeIciEEPNS_11__tree_nodeIS2_PvEEiEE", !9, i64 0}
!13 = !{!14, !14, i64 0}
!14 = !{!"int", !5, i64 0}
!15 = !{!16, !16, i64 0}
!16 = !{!"vtable pointer", !6, i64 0}
!17 = !{!18}
!18 = distinct !{!18, !19, !"_ZL16ParseCDefinitionv: argument 0"}
!19 = distinct !{!19, !"_ZL16ParseCDefinitionv"}
!20 = !{!21}
!21 = distinct !{!21, !22, !"_ZL15ParseDefinitionv: argument 0"}
!22 = distinct !{!22, !"_ZL15ParseDefinitionv"}
!23 = !{!24, !9, i64 0}
!24 = !{!"_ZTSNSt6__ccr122__compressed_pair_elemIPN12_GLOBAL__N_112PrototypeASTELi0ELb0EEE", !9, i64 0}
!25 = !{!26, !21}
!26 = distinct !{!26, !27, !"_ZN4llvm11make_uniqueIN12_GLOBAL__N_111FunctionASTEJNSt6__ccr110unique_ptrINS1_12PrototypeASTENS3_14default_deleteIS5_EEEENS4_INS1_7ExprASTENS6_IS9_EEEEEEENS3_9enable_ifIXntsr3std8is_arrayIT_EE5valueENS4_ISD_NS6_ISD_EEEEE4typeEDpOT0_: argument 0"}
!27 = distinct !{!27, !"_ZN4llvm11make_uniqueIN12_GLOBAL__N_111FunctionASTEJNSt6__ccr110unique_ptrINS1_12PrototypeASTENS3_14default_deleteIS5_EEEENS4_INS1_7ExprASTENS6_IS9_EEEEEEENS3_9enable_ifIXntsr3std8is_arrayIT_EE5valueENS4_ISD_NS6_ISD_EEEEE4typeEDpOT0_"}
!28 = !{!29}
!29 = distinct !{!29, !30, !"_ZL11ParseExternv: argument 0"}
!30 = distinct !{!30, !"_ZL11ParseExternv"}
!31 = !{!32}
!32 = distinct !{!32, !33, !"_ZL17ParseTopLevelExprv: argument 0"}
!33 = distinct !{!33, !"_ZL17ParseTopLevelExprv"}
!34 = !{!35, !9, i64 0}
!35 = !{!"_ZTSNSt6__ccr113__vector_baseINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEENS4_IS6_EEEE", !9, i64 0, !9, i64 4, !36, i64 8}
!36 = !{!"_ZTSNSt6__ccr117__compressed_pairIPNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEENS4_IS6_EEEE"}
!37 = !{!35, !9, i64 4}
!38 = !{!39, !9, i64 0}
!39 = !{!"_ZTSNSt6__ccr122__compressed_pair_elemIPNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEELi0ELb0EEE", !9, i64 0}
!40 = !{!41, !32}
!41 = distinct !{!41, !42, !"_ZN4llvm11make_uniqueIN12_GLOBAL__N_112PrototypeASTEJRA12_KcNSt6__ccr16vectorINS6_12basic_stringIcNS6_11char_traitsIcEENS6_9allocatorIcEEEENSB_ISD_EEEEEEENS6_9enable_ifIXntsr3std8is_arrayIT_EE5valueENS6_10unique_ptrISH_NS6_14default_deleteISH_EEEEE4typeEDpOT0_: argument 0"}
!42 = distinct !{!42, !"_ZN4llvm11make_uniqueIN12_GLOBAL__N_112PrototypeASTEJRA12_KcNSt6__ccr16vectorINS6_12basic_stringIcNS6_11char_traitsIcEENS6_9allocatorIcEEEENSB_ISD_EEEEEEENS6_9enable_ifIXntsr3std8is_arrayIT_EE5valueENS6_10unique_ptrISH_NS6_14default_deleteISH_EEEEE4typeEDpOT0_"}
!43 = !{!44, !32}
!44 = distinct !{!44, !45, !"_ZN4llvm11make_uniqueIN12_GLOBAL__N_111FunctionASTEJNSt6__ccr110unique_ptrINS1_12PrototypeASTENS3_14default_deleteIS5_EEEENS4_INS1_7ExprASTENS6_IS9_EEEEEEENS3_9enable_ifIXntsr3std8is_arrayIT_EE5valueENS4_ISD_NS6_ISD_EEEEE4typeEDpOT0_: argument 0"}
!45 = distinct !{!45, !"_ZN4llvm11make_uniqueIN12_GLOBAL__N_111FunctionASTEJNSt6__ccr110unique_ptrINS1_12PrototypeASTENS3_14default_deleteIS5_EEEENS4_INS1_7ExprASTENS6_IS9_EEEEEEENS3_9enable_ifIXntsr3std8is_arrayIT_EE5valueENS4_ISD_NS6_ISD_EEEEE4typeEDpOT0_"}
!46 = !{!47, !9, i64 4}
!47 = !{!"_ZTSNSt6__ccr116__tree_node_baseIPvEE", !9, i64 4, !9, i64 8, !48, i64 12}
!48 = !{!"bool", !5, i64 0}
!49 = !{!50, !50, i64 0}
!50 = !{!"double", !5, i64 0}
!51 = !{!52, !48, i64 0}
!52 = !{!"_ZTSNSt6__ccr113basic_ostreamIcNS_11char_traitsIcEEE6sentryE", !48, i64 0, !9, i64 4}
!53 = !{!54, !14, i64 16}
!54 = !{!"_ZTSNSt6__ccr18ios_baseE", !14, i64 4, !14, i64 8, !14, i64 12, !14, i64 16, !14, i64 20, !9, i64 24, !9, i64 28, !9, i64 32, !9, i64 36, !55, i64 40, !55, i64 44, !9, i64 48, !55, i64 52, !55, i64 56, !9, i64 60, !55, i64 64, !55, i64 68}
!55 = !{!"long", !5, i64 0}
!56 = !{!57, !9, i64 72}
!57 = !{!"_ZTSNSt6__ccr19basic_iosIcNS_11char_traitsIcEEEE", !9, i64 72, !14, i64 76}
!58 = !{!54, !9, i64 24}
!59 = !{!54, !14, i64 4}
!60 = !{!57, !14, i64 76}
!61 = !{!54, !14, i64 12}
!62 = !{!63, !9, i64 24}
!63 = !{!"_ZTSNSt6__ccr115basic_streambufIcNS_11char_traitsIcEEEE", !64, i64 4, !9, i64 8, !9, i64 12, !9, i64 16, !9, i64 20, !9, i64 24, !9, i64 28}
!64 = !{!"_ZTSNSt6__ccr16localeE", !9, i64 0}
!65 = !{!63, !9, i64 28}
!66 = !{i8 0, i8 2}
!67 = !{!52, !9, i64 4}
!68 = !{!69}
!69 = distinct !{!69, !70, !"_ZN4llvm11make_uniqueIN12_GLOBAL__N_112PrototypeASTEJRNSt6__ccr112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEENS3_6vectorIS9_NS7_IS9_EEEEEEENS3_9enable_ifIXntsr3std8is_arrayIT_EE5valueENS3_10unique_ptrISF_NS3_14default_deleteISF_EEEEE4typeEDpOT0_: argument 0"}
!70 = distinct !{!70, !"_ZN4llvm11make_uniqueIN12_GLOBAL__N_112PrototypeASTEJRNSt6__ccr112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEENS3_6vectorIS9_NS7_IS9_EEEEEEENS3_9enable_ifIXntsr3std8is_arrayIT_EE5valueENS3_10unique_ptrISF_NS3_14default_deleteISF_EEEEE4typeEDpOT0_"}
!71 = !{!72, !9, i64 0}
!72 = !{!"_ZTSNSt6__ccr122__compressed_pair_elemIPN12_GLOBAL__N_17ExprASTELi0ELb0EEE", !9, i64 0}
!73 = !{!74, !9, i64 8}
!74 = !{!"_ZTSNSt6__ccr114__split_bufferINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEERNS4_IS6_EEEE", !9, i64 0, !9, i64 4, !9, i64 8, !75, i64 12}
!75 = !{!"_ZTSNSt6__ccr117__compressed_pairIPNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEERNS4_IS6_EEEE"}
!76 = !{!74, !9, i64 0}
!77 = !{!74, !9, i64 4}
!78 = !{!79}
!79 = distinct !{!79, !80, !"_ZL19ParseIdentifierExprv: argument 0"}
!80 = distinct !{!80, !"_ZL19ParseIdentifierExprv"}
!81 = !{!82, !79}
!82 = distinct !{!82, !83, !"_ZN4llvm11make_uniqueIN12_GLOBAL__N_115VariableExprASTEJRNSt6__ccr112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEEEEENS3_9enable_ifIXntsr3std8is_arrayIT_EE5valueENS3_10unique_ptrISC_NS3_14default_deleteISC_EEEEE4typeEDpOT0_: argument 0"}
!83 = distinct !{!83, !"_ZN4llvm11make_uniqueIN12_GLOBAL__N_115VariableExprASTEJRNSt6__ccr112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEEEEENS3_9enable_ifIXntsr3std8is_arrayIT_EE5valueENS3_10unique_ptrISC_NS3_14default_deleteISC_EEEEE4typeEDpOT0_"}
!84 = !{!85, !9, i64 0}
!85 = !{!"_ZTSNSt6__ccr113__vector_baseINS_10unique_ptrIN12_GLOBAL__N_17ExprASTENS_14default_deleteIS3_EEEENS_9allocatorIS6_EEEE", !9, i64 0, !9, i64 4, !86, i64 8}
!86 = !{!"_ZTSNSt6__ccr117__compressed_pairIPNS_10unique_ptrIN12_GLOBAL__N_17ExprASTENS_14default_deleteIS3_EEEENS_9allocatorIS6_EEEE"}
!87 = !{!85, !9, i64 4}
!88 = !{!89, !9, i64 0}
!89 = !{!"_ZTSNSt6__ccr122__compressed_pair_elemIPNS_10unique_ptrIN12_GLOBAL__N_17ExprASTENS_14default_deleteIS3_EEEELi0ELb0EEE", !9, i64 0}
!90 = !{!91, !79}
!91 = distinct !{!91, !92, !"_ZN4llvm11make_uniqueIN12_GLOBAL__N_111CallExprASTEJRNSt6__ccr112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEENS3_6vectorINS3_10unique_ptrINS1_7ExprASTENS3_14default_deleteISD_EEEENS7_ISG_EEEEEEENS3_9enable_ifIXntsr3std8is_arrayIT_EE5valueENSC_ISK_NSE_ISK_EEEEE4typeEDpOT0_: argument 0"}
!92 = distinct !{!92, !"_ZN4llvm11make_uniqueIN12_GLOBAL__N_111CallExprASTEJRNSt6__ccr112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEENS3_6vectorINS3_10unique_ptrINS1_7ExprASTENS3_14default_deleteISD_EEEENS7_ISG_EEEEEEENS3_9enable_ifIXntsr3std8is_arrayIT_EE5valueENSC_ISK_NSE_ISK_EEEEE4typeEDpOT0_"}
!93 = !{!94}
!94 = distinct !{!94, !95, !"_ZL15ParseNumberExprv: argument 0"}
!95 = distinct !{!95, !"_ZL15ParseNumberExprv"}
!96 = !{!97, !94}
!97 = distinct !{!97, !98, !"_ZN4llvm11make_uniqueIN12_GLOBAL__N_113NumberExprASTEJRdEEENSt6__ccr19enable_ifIXntsr3std8is_arrayIT_EE5valueENS4_10unique_ptrIS6_NS4_14default_deleteIS6_EEEEE4typeEDpOT0_: argument 0"}
!98 = distinct !{!98, !"_ZN4llvm11make_uniqueIN12_GLOBAL__N_113NumberExprASTEJRdEEENSt6__ccr19enable_ifIXntsr3std8is_arrayIT_EE5valueENS4_10unique_ptrIS6_NS4_14default_deleteIS6_EEEEE4typeEDpOT0_"}
!99 = !{!100, !50, i64 4}
!100 = !{!"_ZTSN12_GLOBAL__N_113NumberExprASTE", !50, i64 4}
!101 = !{!102}
!102 = distinct !{!102, !103, !"_ZL14ParseParenExprv: argument 0"}
!103 = distinct !{!103, !"_ZL14ParseParenExprv"}
!104 = !{!105}
!105 = distinct !{!105, !106, !"_ZN4llvm11make_uniqueIN12_GLOBAL__N_113BinaryExprASTEJRiNSt6__ccr110unique_ptrINS1_7ExprASTENS4_14default_deleteIS6_EEEES9_EEENS4_9enable_ifIXntsr3std8is_arrayIT_EE5valueENS5_ISB_NS7_ISB_EEEEE4typeEDpOT0_: argument 0"}
!106 = distinct !{!106, !"_ZN4llvm11make_uniqueIN12_GLOBAL__N_113BinaryExprASTEJRiNSt6__ccr110unique_ptrINS1_7ExprASTENS4_14default_deleteIS6_EEEES9_EEENS4_9enable_ifIXntsr3std8is_arrayIT_EE5valueENS5_ISB_NS7_ISB_EEEEE4typeEDpOT0_"}
!107 = !{!108, !5, i64 4}
!108 = !{!"_ZTSN12_GLOBAL__N_113BinaryExprASTE", !5, i64 4, !109, i64 8, !109, i64 12}
!109 = !{!"_ZTSNSt6__ccr110unique_ptrIN12_GLOBAL__N_17ExprASTENS_14default_deleteIS2_EEEE", !110, i64 0}
!110 = !{!"_ZTSNSt6__ccr117__compressed_pairIPN12_GLOBAL__N_17ExprASTENS_14default_deleteIS2_EEEE"}
!111 = !{!112}
!112 = distinct !{!112, !113, !"_ZNSt6__ccr16__treeINS_12__value_typeIciEENS_19__map_value_compareIcS2_NS_4lessIcEELb1EEENS_9allocatorIS2_EEE16__construct_nodeIJRKNS_21piecewise_construct_tENS_5tupleIJOcEEENSE_IJEEEEEENS_10unique_ptrINS_11__tree_nodeIS2_PvEENS_22__tree_node_destructorINS7_ISL_EEEEEEDpOT_: argument 0"}
!113 = distinct !{!113, !"_ZNSt6__ccr16__treeINS_12__value_typeIciEENS_19__map_value_compareIcS2_NS_4lessIcEELb1EEENS_9allocatorIS2_EEE16__construct_nodeIJRKNS_21piecewise_construct_tENS_5tupleIJOcEEENSE_IJEEEEEENS_10unique_ptrINS_11__tree_nodeIS2_PvEENS_22__tree_node_destructorINS7_ISL_EEEEEEDpOT_"}
!114 = !{!115, !5, i64 0}
!115 = !{!"_ZTSNSt6__ccr14pairIKciEE", !5, i64 0, !14, i64 4}
!116 = !{!115, !14, i64 4}
!117 = !{!118, !48, i64 4}
!118 = !{!"_ZTSNSt6__ccr14pairINS_15__tree_iteratorINS_12__value_typeIciEEPNS_11__tree_nodeIS3_PvEEiEEbEE", !12, i64 0, !48, i64 4}
!119 = !{!47, !9, i64 8}
!120 = !{!55, !55, i64 0}
!121 = !{!47, !48, i64 12}
!122 = !{!123, !55, i64 0}
!123 = !{!"_ZTSNSt6__ccr122__compressed_pair_elemImLi0ELb0EEE", !55, i64 0}
