#ifndef GENUM_GENUM_H
#define GENUM_GENUM_H

// __VA_ARGS__ size calculation

#ifdef __unix__
#define _GENUM_NTH_ARG(_101, _100, _99, _98, _97, _96, _95, _94, _93, _92, _91, _90, \
    _89, _88, _87, _86, _85, _84, _83, _82, _81, _80, \
    _79, _78, _77, _76, _75, _74, _73, _72, _71, _70, \
    _69, _68, _67, _66, _65, _64, _63, _62, _61, _60, \
    _59, _58, _57, _56, _55, _54, _53, _52, _51, _50, \
    _49, _48, _47, _46, _45, _44, _43, _42, _41, _40, \
    _39, _38, _37, _36, _35, _34, _33, _32, _31, _30, \
    _29, _28, _27, _26, _25, _24, _23, _22, _21, _20, \
    _19, _18, _17, _16, _15, _14, _13, _12, _11, _10, \
    _9, _8, _7, _6, _5, _4, _3, _2, _1, n, ...) n
// ## deletes preceding comma if _VA_ARGS__ is empty (GCC, Clang)
#define _GENUM_VA_NARGS(...) _GENUM_NTH_ARG(_, ##__VA_ARGS__, \
    100, 99, 98, 97, 96, 95, 94, 93, 92, 91, 90, \
    89, 88, 87, 86, 85, 84, 83, 82, 81, 80, \
    79, 78, 77, 76, 75, 74, 73, 72, 71, 70, \
    69, 68, 67, 66, 65, 64, 63, 62, 61, 60, \
    59, 58, 57, 56, 55, 54, 53, 52, 51, 50, \
    49, 48, 47, 46, 45, 44, 43, 42, 41, 40, \
    39, 38, 37, 36, 35, 34, 33, 32, 31, 30, \
    29, 28, 27, 26, 25, 24, 23, 22, 21, 20, \
    19, 18, 17, 16, 15, 14, 13, 12, 11, 10, \
    9, 8, 7, 6, 5, 4, 3, 2, 1, 0)
#elif defined(_WIN32) || defined(_WIN64)
#define _GENUM_E_PAND(x) x
#define _GENUM_NTH_ARG(_101, _100, _99, _98, _97, _96, _95, _94, _93, _92, _91, _90, \
    _89, _88, _87, _86, _85, _84, _83, _82, _81, _80, \
    _79, _78, _77, _76, _75, _74, _73, _72, _71, _70, \
    _69, _68, _67, _66, _65, _64, _63, _62, _61, _60, \
    _59, _58, _57, _56, _55, _54, _53, _52, _51, _50, \
    _49, _48, _47, _46, _45, _44, _43, _42, _41, _40, \
    _39, _38, _37, _36, _35, _34, _33, _32, _31, _30, \
    _29, _28, _27, _26, _25, _24, _23, _22, _21, _20, \
    _19, _18, _17, _16, _15, _14, _13, _12, _11, _10, \
    _9, _8, _7, _6, _5, _4, _3, _2, _1, n, ...) n
#define _GENUM_NARGS_1(...) _GENUM_E_PAND(_GENUM_NTH_ARG(__VA_ARGS__, \
    100, 99, 98, 97, 96, 95, 94, 93, 92, 91, 90, \
    89, 88, 87, 86, 85, 84, 83, 82, 81, 80, \
    79, 78, 77, 76, 75, 74, 73, 72, 71, 70, \
    69, 68, 67, 66, 65, 64, 63, 62, 61, 60, \
    59, 58, 57, 56, 55, 54, 53, 52, 51, 50, \
    49, 48, 47, 46, 45, 44, 43, 42, 41, 40, \
    39, 38, 37, 36, 35, 34, 33, 32, 31, 30, \
    29, 28, 27, 26, 25, 24, 23, 22, 21, 20, \
    19, 18, 17, 16, 15, 14, 13, 12, 11, 10, \
    9, 8, 7, 6, 5, 4, 3, 2, 1, 0))
#define _GENUM_AUGMENT(...) unused, __VA_ARGS__

#define _GENUM_VA_NARGS(...) _GENUM_NARGS_1(_GENUM_AUGMENT(__VA_ARGS__))
#endif


// Applaying unary function on each argument in __VA_ARGS__

#define _GENUM_EXPAND_TO_ARG(x) x,
#define _GENUM_FIRST(x, ...) (x)
#define _GENUM_REST(x, ...) (__VA_ARGS__)
#define _GENUM_APPLY_1(unary, args) unary args
#define _GENUM_APPLY_2(unary, args) _GENUM_EXPAND_TO_ARG(unary _GENUM_FIRST args) _GENUM_APPLY_1(unary, _GENUM_REST args)
#define _GENUM_APPLY_3(unary, args) _GENUM_EXPAND_TO_ARG(unary _GENUM_FIRST args) _GENUM_APPLY_2(unary, _GENUM_REST args)
#define _GENUM_APPLY_4(unary, args) _GENUM_EXPAND_TO_ARG(unary _GENUM_FIRST args) _GENUM_APPLY_3(unary, _GENUM_REST args)
#define _GENUM_APPLY_5(unary, args) _GENUM_EXPAND_TO_ARG(unary _GENUM_FIRST args) _GENUM_APPLY_4(unary, _GENUM_REST args)
#define _GENUM_APPLY_6(unary, args) _GENUM_EXPAND_TO_ARG(unary _GENUM_FIRST args) _GENUM_APPLY_5(unary, _GENUM_REST args)
#define _GENUM_APPLY_7(unary, args) _GENUM_EXPAND_TO_ARG(unary _GENUM_FIRST args) _GENUM_APPLY_6(unary, _GENUM_REST args)
#define _GENUM_APPLY_8(unary, args) _GENUM_EXPAND_TO_ARG(unary _GENUM_FIRST args) _GENUM_APPLY_7(unary, _GENUM_REST args)
#define _GENUM_APPLY_9(unary, args) _GENUM_EXPAND_TO_ARG(unary _GENUM_FIRST args) _GENUM_APPLY_8(unary, _GENUM_REST args)
#define _GENUM_APPLY_10(unary, args) _GENUM_EXPAND_TO_ARG(unary _GENUM_FIRST args) _GENUM_APPLY_9(unary, _GENUM_REST args)
#define _GENUM_APPLY_11(unary, args) _GENUM_EXPAND_TO_ARG(unary _GENUM_FIRST args) _GENUM_APPLY_10(unary, _GENUM_REST args)
#define _GENUM_APPLY_12(unary, args) _GENUM_EXPAND_TO_ARG(unary _GENUM_FIRST args) _GENUM_APPLY_11(unary, _GENUM_REST args)
#define _GENUM_APPLY_13(unary, args) _GENUM_EXPAND_TO_ARG(unary _GENUM_FIRST args) _GENUM_APPLY_12(unary, _GENUM_REST args)
#define _GENUM_APPLY_14(unary, args) _GENUM_EXPAND_TO_ARG(unary _GENUM_FIRST args) _GENUM_APPLY_13(unary, _GENUM_REST args)
#define _GENUM_APPLY_15(unary, args) _GENUM_EXPAND_TO_ARG(unary _GENUM_FIRST args) _GENUM_APPLY_14(unary, _GENUM_REST args)
#define _GENUM_APPLY_16(unary, args) _GENUM_EXPAND_TO_ARG(unary _GENUM_FIRST args) _GENUM_APPLY_15(unary, _GENUM_REST args)
#define _GENUM_APPLY_17(unary, args) _GENUM_EXPAND_TO_ARG(unary _GENUM_FIRST args) _GENUM_APPLY_16(unary, _GENUM_REST args)
#define _GENUM_APPLY_18(unary, args) _GENUM_EXPAND_TO_ARG(unary _GENUM_FIRST args) _GENUM_APPLY_17(unary, _GENUM_REST args)
#define _GENUM_APPLY_19(unary, args) _GENUM_EXPAND_TO_ARG(unary _GENUM_FIRST args) _GENUM_APPLY_18(unary, _GENUM_REST args)
#define _GENUM_APPLY_20(unary, args) _GENUM_EXPAND_TO_ARG(unary _GENUM_FIRST args) _GENUM_APPLY_19(unary, _GENUM_REST args)
#define _GENUM_APPLY_21(unary, args) _GENUM_EXPAND_TO_ARG(unary _GENUM_FIRST args) _GENUM_APPLY_20(unary, _GENUM_REST args)
#define _GENUM_APPLY_22(unary, args) _GENUM_EXPAND_TO_ARG(unary _GENUM_FIRST args) _GENUM_APPLY_21(unary, _GENUM_REST args)
#define _GENUM_APPLY_23(unary, args) _GENUM_EXPAND_TO_ARG(unary _GENUM_FIRST args) _GENUM_APPLY_22(unary, _GENUM_REST args)
#define _GENUM_APPLY_24(unary, args) _GENUM_EXPAND_TO_ARG(unary _GENUM_FIRST args) _GENUM_APPLY_23(unary, _GENUM_REST args)
#define _GENUM_APPLY_25(unary, args) _GENUM_EXPAND_TO_ARG(unary _GENUM_FIRST args) _GENUM_APPLY_24(unary, _GENUM_REST args)
#define _GENUM_APPLY_26(unary, args) _GENUM_EXPAND_TO_ARG(unary _GENUM_FIRST args) _GENUM_APPLY_25(unary, _GENUM_REST args)
#define _GENUM_APPLY_27(unary, args) _GENUM_EXPAND_TO_ARG(unary _GENUM_FIRST args) _GENUM_APPLY_26(unary, _GENUM_REST args)
#define _GENUM_APPLY_28(unary, args) _GENUM_EXPAND_TO_ARG(unary _GENUM_FIRST args) _GENUM_APPLY_27(unary, _GENUM_REST args)
#define _GENUM_APPLY_29(unary, args) _GENUM_EXPAND_TO_ARG(unary _GENUM_FIRST args) _GENUM_APPLY_28(unary, _GENUM_REST args)
#define _GENUM_APPLY_30(unary, args) _GENUM_EXPAND_TO_ARG(unary _GENUM_FIRST args) _GENUM_APPLY_29(unary, _GENUM_REST args)
#define _GENUM_APPLY_31(unary, args) _GENUM_EXPAND_TO_ARG(unary _GENUM_FIRST args) _GENUM_APPLY_30(unary, _GENUM_REST args)
#define _GENUM_APPLY_32(unary, args) _GENUM_EXPAND_TO_ARG(unary _GENUM_FIRST args) _GENUM_APPLY_31(unary, _GENUM_REST args)
#define _GENUM_APPLY_33(unary, args) _GENUM_EXPAND_TO_ARG(unary _GENUM_FIRST args) _GENUM_APPLY_32(unary, _GENUM_REST args)
#define _GENUM_APPLY_34(unary, args) _GENUM_EXPAND_TO_ARG(unary _GENUM_FIRST args) _GENUM_APPLY_33(unary, _GENUM_REST args)
#define _GENUM_APPLY_35(unary, args) _GENUM_EXPAND_TO_ARG(unary _GENUM_FIRST args) _GENUM_APPLY_34(unary, _GENUM_REST args)
#define _GENUM_APPLY_36(unary, args) _GENUM_EXPAND_TO_ARG(unary _GENUM_FIRST args) _GENUM_APPLY_35(unary, _GENUM_REST args)
#define _GENUM_APPLY_37(unary, args) _GENUM_EXPAND_TO_ARG(unary _GENUM_FIRST args) _GENUM_APPLY_36(unary, _GENUM_REST args)
#define _GENUM_APPLY_38(unary, args) _GENUM_EXPAND_TO_ARG(unary _GENUM_FIRST args) _GENUM_APPLY_37(unary, _GENUM_REST args)
#define _GENUM_APPLY_39(unary, args) _GENUM_EXPAND_TO_ARG(unary _GENUM_FIRST args) _GENUM_APPLY_38(unary, _GENUM_REST args)
#define _GENUM_APPLY_40(unary, args) _GENUM_EXPAND_TO_ARG(unary _GENUM_FIRST args) _GENUM_APPLY_39(unary, _GENUM_REST args)
#define _GENUM_APPLY_41(unary, args) _GENUM_EXPAND_TO_ARG(unary _GENUM_FIRST args) _GENUM_APPLY_40(unary, _GENUM_REST args)
#define _GENUM_APPLY_42(unary, args) _GENUM_EXPAND_TO_ARG(unary _GENUM_FIRST args) _GENUM_APPLY_41(unary, _GENUM_REST args)
#define _GENUM_APPLY_43(unary, args) _GENUM_EXPAND_TO_ARG(unary _GENUM_FIRST args) _GENUM_APPLY_42(unary, _GENUM_REST args)
#define _GENUM_APPLY_44(unary, args) _GENUM_EXPAND_TO_ARG(unary _GENUM_FIRST args) _GENUM_APPLY_43(unary, _GENUM_REST args)
#define _GENUM_APPLY_45(unary, args) _GENUM_EXPAND_TO_ARG(unary _GENUM_FIRST args) _GENUM_APPLY_44(unary, _GENUM_REST args)
#define _GENUM_APPLY_46(unary, args) _GENUM_EXPAND_TO_ARG(unary _GENUM_FIRST args) _GENUM_APPLY_45(unary, _GENUM_REST args)
#define _GENUM_APPLY_47(unary, args) _GENUM_EXPAND_TO_ARG(unary _GENUM_FIRST args) _GENUM_APPLY_46(unary, _GENUM_REST args)
#define _GENUM_APPLY_48(unary, args) _GENUM_EXPAND_TO_ARG(unary _GENUM_FIRST args) _GENUM_APPLY_47(unary, _GENUM_REST args)
#define _GENUM_APPLY_49(unary, args) _GENUM_EXPAND_TO_ARG(unary _GENUM_FIRST args) _GENUM_APPLY_48(unary, _GENUM_REST args)
#define _GENUM_APPLY_50(unary, args) _GENUM_EXPAND_TO_ARG(unary _GENUM_FIRST args) _GENUM_APPLY_49(unary, _GENUM_REST args)
#define _GENUM_APPLY_51(unary, args) _GENUM_EXPAND_TO_ARG(unary _GENUM_FIRST args) _GENUM_APPLY_50(unary, _GENUM_REST args)
#define _GENUM_APPLY_52(unary, args) _GENUM_EXPAND_TO_ARG(unary _GENUM_FIRST args) _GENUM_APPLY_51(unary, _GENUM_REST args)
#define _GENUM_APPLY_53(unary, args) _GENUM_EXPAND_TO_ARG(unary _GENUM_FIRST args) _GENUM_APPLY_52(unary, _GENUM_REST args)
#define _GENUM_APPLY_54(unary, args) _GENUM_EXPAND_TO_ARG(unary _GENUM_FIRST args) _GENUM_APPLY_53(unary, _GENUM_REST args)
#define _GENUM_APPLY_55(unary, args) _GENUM_EXPAND_TO_ARG(unary _GENUM_FIRST args) _GENUM_APPLY_54(unary, _GENUM_REST args)
#define _GENUM_APPLY_56(unary, args) _GENUM_EXPAND_TO_ARG(unary _GENUM_FIRST args) _GENUM_APPLY_55(unary, _GENUM_REST args)
#define _GENUM_APPLY_57(unary, args) _GENUM_EXPAND_TO_ARG(unary _GENUM_FIRST args) _GENUM_APPLY_56(unary, _GENUM_REST args)
#define _GENUM_APPLY_58(unary, args) _GENUM_EXPAND_TO_ARG(unary _GENUM_FIRST args) _GENUM_APPLY_57(unary, _GENUM_REST args)
#define _GENUM_APPLY_59(unary, args) _GENUM_EXPAND_TO_ARG(unary _GENUM_FIRST args) _GENUM_APPLY_58(unary, _GENUM_REST args)
#define _GENUM_APPLY_60(unary, args) _GENUM_EXPAND_TO_ARG(unary _GENUM_FIRST args) _GENUM_APPLY_59(unary, _GENUM_REST args)
#define _GENUM_APPLY_61(unary, args) _GENUM_EXPAND_TO_ARG(unary _GENUM_FIRST args) _GENUM_APPLY_60(unary, _GENUM_REST args)
#define _GENUM_APPLY_62(unary, args) _GENUM_EXPAND_TO_ARG(unary _GENUM_FIRST args) _GENUM_APPLY_61(unary, _GENUM_REST args)
#define _GENUM_APPLY_63(unary, args) _GENUM_EXPAND_TO_ARG(unary _GENUM_FIRST args) _GENUM_APPLY_62(unary, _GENUM_REST args)
#define _GENUM_APPLY_64(unary, args) _GENUM_EXPAND_TO_ARG(unary _GENUM_FIRST args) _GENUM_APPLY_63(unary, _GENUM_REST args)
#define _GENUM_APPLY_65(unary, args) _GENUM_EXPAND_TO_ARG(unary _GENUM_FIRST args) _GENUM_APPLY_64(unary, _GENUM_REST args)
#define _GENUM_APPLY_66(unary, args) _GENUM_EXPAND_TO_ARG(unary _GENUM_FIRST args) _GENUM_APPLY_65(unary, _GENUM_REST args)
#define _GENUM_APPLY_67(unary, args) _GENUM_EXPAND_TO_ARG(unary _GENUM_FIRST args) _GENUM_APPLY_66(unary, _GENUM_REST args)
#define _GENUM_APPLY_68(unary, args) _GENUM_EXPAND_TO_ARG(unary _GENUM_FIRST args) _GENUM_APPLY_67(unary, _GENUM_REST args)
#define _GENUM_APPLY_69(unary, args) _GENUM_EXPAND_TO_ARG(unary _GENUM_FIRST args) _GENUM_APPLY_68(unary, _GENUM_REST args)
#define _GENUM_APPLY_70(unary, args) _GENUM_EXPAND_TO_ARG(unary _GENUM_FIRST args) _GENUM_APPLY_69(unary, _GENUM_REST args)
#define _GENUM_APPLY_71(unary, args) _GENUM_EXPAND_TO_ARG(unary _GENUM_FIRST args) _GENUM_APPLY_70(unary, _GENUM_REST args)
#define _GENUM_APPLY_72(unary, args) _GENUM_EXPAND_TO_ARG(unary _GENUM_FIRST args) _GENUM_APPLY_71(unary, _GENUM_REST args)
#define _GENUM_APPLY_73(unary, args) _GENUM_EXPAND_TO_ARG(unary _GENUM_FIRST args) _GENUM_APPLY_72(unary, _GENUM_REST args)
#define _GENUM_APPLY_74(unary, args) _GENUM_EXPAND_TO_ARG(unary _GENUM_FIRST args) _GENUM_APPLY_73(unary, _GENUM_REST args)
#define _GENUM_APPLY_75(unary, args) _GENUM_EXPAND_TO_ARG(unary _GENUM_FIRST args) _GENUM_APPLY_74(unary, _GENUM_REST args)
#define _GENUM_APPLY_76(unary, args) _GENUM_EXPAND_TO_ARG(unary _GENUM_FIRST args) _GENUM_APPLY_75(unary, _GENUM_REST args)
#define _GENUM_APPLY_77(unary, args) _GENUM_EXPAND_TO_ARG(unary _GENUM_FIRST args) _GENUM_APPLY_76(unary, _GENUM_REST args)
#define _GENUM_APPLY_78(unary, args) _GENUM_EXPAND_TO_ARG(unary _GENUM_FIRST args) _GENUM_APPLY_77(unary, _GENUM_REST args)
#define _GENUM_APPLY_79(unary, args) _GENUM_EXPAND_TO_ARG(unary _GENUM_FIRST args) _GENUM_APPLY_78(unary, _GENUM_REST args)
#define _GENUM_APPLY_80(unary, args) _GENUM_EXPAND_TO_ARG(unary _GENUM_FIRST args) _GENUM_APPLY_79(unary, _GENUM_REST args)
#define _GENUM_APPLY_81(unary, args) _GENUM_EXPAND_TO_ARG(unary _GENUM_FIRST args) _GENUM_APPLY_80(unary, _GENUM_REST args)
#define _GENUM_APPLY_82(unary, args) _GENUM_EXPAND_TO_ARG(unary _GENUM_FIRST args) _GENUM_APPLY_81(unary, _GENUM_REST args)
#define _GENUM_APPLY_83(unary, args) _GENUM_EXPAND_TO_ARG(unary _GENUM_FIRST args) _GENUM_APPLY_82(unary, _GENUM_REST args)
#define _GENUM_APPLY_84(unary, args) _GENUM_EXPAND_TO_ARG(unary _GENUM_FIRST args) _GENUM_APPLY_83(unary, _GENUM_REST args)
#define _GENUM_APPLY_85(unary, args) _GENUM_EXPAND_TO_ARG(unary _GENUM_FIRST args) _GENUM_APPLY_84(unary, _GENUM_REST args)
#define _GENUM_APPLY_86(unary, args) _GENUM_EXPAND_TO_ARG(unary _GENUM_FIRST args) _GENUM_APPLY_85(unary, _GENUM_REST args)
#define _GENUM_APPLY_87(unary, args) _GENUM_EXPAND_TO_ARG(unary _GENUM_FIRST args) _GENUM_APPLY_86(unary, _GENUM_REST args)
#define _GENUM_APPLY_88(unary, args) _GENUM_EXPAND_TO_ARG(unary _GENUM_FIRST args) _GENUM_APPLY_87(unary, _GENUM_REST args)
#define _GENUM_APPLY_89(unary, args) _GENUM_EXPAND_TO_ARG(unary _GENUM_FIRST args) _GENUM_APPLY_88(unary, _GENUM_REST args)
#define _GENUM_APPLY_90(unary, args) _GENUM_EXPAND_TO_ARG(unary _GENUM_FIRST args) _GENUM_APPLY_89(unary, _GENUM_REST args)
#define _GENUM_APPLY_91(unary, args) _GENUM_EXPAND_TO_ARG(unary _GENUM_FIRST args) _GENUM_APPLY_90(unary, _GENUM_REST args)
#define _GENUM_APPLY_92(unary, args) _GENUM_EXPAND_TO_ARG(unary _GENUM_FIRST args) _GENUM_APPLY_91(unary, _GENUM_REST args)
#define _GENUM_APPLY_93(unary, args) _GENUM_EXPAND_TO_ARG(unary _GENUM_FIRST args) _GENUM_APPLY_92(unary, _GENUM_REST args)
#define _GENUM_APPLY_94(unary, args) _GENUM_EXPAND_TO_ARG(unary _GENUM_FIRST args) _GENUM_APPLY_93(unary, _GENUM_REST args)
#define _GENUM_APPLY_95(unary, args) _GENUM_EXPAND_TO_ARG(unary _GENUM_FIRST args) _GENUM_APPLY_94(unary, _GENUM_REST args)
#define _GENUM_APPLY_96(unary, args) _GENUM_EXPAND_TO_ARG(unary _GENUM_FIRST args) _GENUM_APPLY_95(unary, _GENUM_REST args)
#define _GENUM_APPLY_97(unary, args) _GENUM_EXPAND_TO_ARG(unary _GENUM_FIRST args) _GENUM_APPLY_96(unary, _GENUM_REST args)
#define _GENUM_APPLY_98(unary, args) _GENUM_EXPAND_TO_ARG(unary _GENUM_FIRST args) _GENUM_APPLY_97(unary, _GENUM_REST args)
#define _GENUM_APPLY_99(unary, args) _GENUM_EXPAND_TO_ARG(unary _GENUM_FIRST args) _GENUM_APPLY_98(unary, _GENUM_REST args)
#define _GENUM_APPLY_100(unary, args) _GENUM_EXPAND_TO_ARG(unary _GENUM_FIRST args) _GENUM_APPLY_99(unary, _GENUM_REST args)
#define _GENUM_APPLY__(nargs, unary, args) _GENUM_APPLY_##nargs(unary, args)
#define _GENUM_APPLY_(nargs, unary, args) _GENUM_APPLY__(nargs, unary, args)

#define _GENUM_APPLY(unary, args) _GENUM_APPLY_(_GENUM_VA_NARGS args, unary, args)


// Enum generation auxiliary

#define _GENUM_STRINGIFY(x) #x

#define _GENUM_START_NS(ns) namespace ns {
#define _GENUM_END_NS() }

#define _GENUM_GENERATE_ENUM_CLASS(name, ...) enum class name { __VA_ARGS__, size };

#define _GENUM_GENERATE_ENUM_STRINGS(ns, name, ...) constexpr const char* name##_strings[static_cast<int>(name::size)] { \
    _GENUM_APPLY(_GENUM_STRINGIFY(ns::name::) _GENUM_STRINGIFY, (__VA_ARGS__)) };

#define _GENUM_GENERATE_ENUM_TO_STRING(ns, name, ...) [[nodiscard]] inline constexpr const char* to_string(name field) noexcept { \
    _GENUM_GENERATE_ENUM_STRINGS(ns, name, __VA_ARGS__) \
    return name##_strings[static_cast<int>(field)]; }

#define _GENUM_GENERATE_EXPORT(ns, name) \
    using ns::name; \
    using ns::to_string;


// Enum generation API

/**
* Generates an enum class with the name <name> in a given namespace <ns> (nested namespace should in the format <ns1>::<ns2>::...).
*/
#define GENUM_GENERATE(ns, name, ...) \
    _GENUM_START_NS(ns) \
        _GENUM_START_NS(details) \
            _GENUM_GENERATE_ENUM_CLASS(name, __VA_ARGS__) \
            _GENUM_GENERATE_ENUM_TO_STRING(ns, name, __VA_ARGS__) \
        _GENUM_END_NS() \
        _GENUM_GENERATE_EXPORT(details, name) \
    _GENUM_END_NS()

#endif // GENUM_GENUM_H
