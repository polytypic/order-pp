#ifndef ORDER_PRELUDE_SEQ_H_VAJK20040620
#define ORDER_PRELUDE_SEQ_H_VAJK20040620

// (C) Copyright Vesa Karvonen 2004.
//
//    Distributed under the Boost Software License, Version 1.0.

// `8vseq_to_seq_of_tuples(vs)' converts the variadic or n-element
// sequence `vs' to a sequence of tuples.
//
// For example,
//
//   8vseq_to_seq_of_tuples(8((1)(2,3)(4,5,6)))
//    ==> ((1))((1,2))((4,5,6))
#define ORDER_PP_DEF_8vseq_to_seq_of_tuples ORDER_PP_FN_CM(1,8VSEQ_TO_SEQ_OF_TUPLES)
#define ORDER_PP_8VSEQ_TO_SEQ_OF_TUPLES(P,s,...) (,ORDER_PP_SEQ_TERMINATE(ORDER_PP_VSEQ_TO_SEQ_OF_TUPLES_A P##s),P##__VA_ARGS__)
#define ORDER_PP_VSEQ_TO_SEQ_OF_TUPLES_A(...) ((__VA_ARGS__))ORDER_PP_VSEQ_TO_SEQ_OF_TUPLES_B
#define ORDER_PP_VSEQ_TO_SEQ_OF_TUPLES_A0
#define ORDER_PP_VSEQ_TO_SEQ_OF_TUPLES_B(...) ((__VA_ARGS__))ORDER_PP_VSEQ_TO_SEQ_OF_TUPLES_A
#define ORDER_PP_VSEQ_TO_SEQ_OF_TUPLES_B0

#define ORDER_PP_DEF_8seq_append ORDER_PP_OP_LEFT_CM(8SEQ_APPEND_2)
#define ORDER_PP_8SEQ_APPEND_2(P,r,l,...) (,ORDER_PP_LEFT(,l##P)P##r,P##__VA_ARGS__)

#define ORDER_PP_DEF_8seq_at ORDER_PP_FN_CM(2,8SEQ_AT)
#define ORDER_PP_8SEQ_AT(P,i,s,...) (,ORDER_PP_FY(SEQ_AT,(,0,ORDER_PP_SEQ_REST_N(,P##i,P##s))),P##__VA_ARGS__)

#define ORDER_PP_DEF_8seq_first ORDER_PP_FN_CM(1,8SEQ_FIRST)
#define ORDER_PP_8SEQ_FIRST(P,s,...) (,ORDER_PP_SEQ_AT(,0,P##s),P##__VA_ARGS__)

#define ORDER_PP_DEF_8seq_first_n ORDER_PP_FN_CM(2,8SEQ_FIRST_N)
#define ORDER_PP_8SEQ_FIRST_N(P,n,s,...) (,ORDER_PP_FX(TUPLE_AT_0,(,ORDER_PP_SEQ_SPLIT_AT(,P##n,P##s),)),P##__VA_ARGS__)

#define ORDER_PP_DEF_8seq_is_nil ORDER_PP_FN_CM(1,8SEQ_IS_NIL)
#define ORDER_PP_8SEQ_IS_NIL(P,s,...) (,ORDER_PP_TEST(,ORDER_PP_IS_EDIBLE_TEST P##s,8false,8true),P##__VA_ARGS__)

#define ORDER_PP_DEF_8seq_isnt_nil ORDER_PP_FN_CM(1,8SEQ_ISNT_NIL)
#define ORDER_PP_8SEQ_ISNT_NIL(P,s,...) (,ORDER_PP_TEST(,ORDER_PP_IS_EDIBLE_TEST P##s,8true,8false),P##__VA_ARGS__)

#define ORDER_PP_DEF_8seq_map_seq ORDER_PP_FN_MACRO_P(1,ORDER_PP_SEQ_MAP_SEQ)

#define ORDER_PP_DEF_8seq_nil 8DEF_CONST,,

#define ORDER_PP_DEF_8seq_pop_at ORDER_PP_FN_CM(2,8SEQ_POP_AT)
#define ORDER_PP_8SEQ_POP_AT(P,i,s,...) (,ORDER_PP_FX(SEQ_POP_AT_B,(,ORDER_PP_SEQ_SPLIT_AT(,P##i,P##s),)),P##__VA_ARGS__)
#define ORDER_PP_SEQ_POP_AT_B(P,l,r,...) ORDER_PP_LEFT(,l##P)ORDER_PP_EAT r##P

#define ORDER_PP_DEF_8seq_pop_back ORDER_PP_FN_CM(1,8SEQ_POP_BACK)
#define ORDER_PP_8SEQ_POP_BACK(P,s,...) (,ORDER_PP_FX(SEQ_POP_BACK_SWAP_A,ORDER_PP_FX(SEQ_POP_BACK_SHIFT,ORDER_PP_SEQ_TO_PSEQ(,P##s)(0,))),P##__VA_ARGS__)

#define ORDER_PP_SEQ_POP_BACK_SHIFT(P,x) (x##P,ORDER_PP_SEQ_POP_BACK_SHIFT_A##P
#define ORDER_PP_SEQ_POP_BACK_SHIFT_A(P,x) P)(x##P,ORDER_PP_SEQ_POP_BACK_SHIFT_B##P
#define ORDER_PP_SEQ_POP_BACK_SHIFT_A0 )
#define ORDER_PP_SEQ_POP_BACK_SHIFT_B(P,x) P)(x##P,ORDER_PP_SEQ_POP_BACK_SHIFT_A##P
#define ORDER_PP_SEQ_POP_BACK_SHIFT_B0 )

#define ORDER_PP_SEQ_POP_BACK_SWAP_A(x,P) ORDER_PP_SEQ_POP_BACK_SWAP_F##P(,P##x,B)
#define ORDER_PP_SEQ_POP_BACK_SWAP_B(x,P) ORDER_PP_SEQ_POP_BACK_SWAP_F##P(,P##x,A)
#define ORDER_PP_SEQ_POP_BACK_SWAP_F(P,x,i) (P##x)ORDER_PP_SEQ_POP_BACK_SWAP_##i
#define ORDER_PP_SEQ_POP_BACK_SWAP_F0(...) ORDER_PP_EAT

#define ORDER_PP_DEF_8seq_pop_front ORDER_PP_FN_CM(1,8SEQ_REST)

#define ORDER_PP_DEF_8seq_push_at ORDER_PP_FN_CM(3,8SEQ_PUSH_AT)
#define ORDER_PP_8SEQ_PUSH_AT(P,i,s,x,...) (,ORDER_PP_FX(SEQ_PUSH_AT_B,(,P##x,ORDER_PP_SEQ_SPLIT_AT(,P##i,P##s),)),P##__VA_ARGS__)
#define ORDER_PP_SEQ_PUSH_AT_B(P,x,l,r,...) l##P(P##x)P##r

#define ORDER_PP_DEF_8seq_push_back ORDER_PP_FN_CM(2,8SEQ_PUSH_BACK)
#define ORDER_PP_8SEQ_PUSH_BACK(P,x,s,...) (,P##s(P##x),P##__VA_ARGS__)

#define ORDER_PP_DEF_8seq_push_front ORDER_PP_FN_CM(2,8SEQ_PUSH_FRONT)
#define ORDER_PP_8SEQ_PUSH_FRONT(P,x,s,...) (,(P##x)P##s,P##__VA_ARGS__)

#define ORDER_PP_DEF_8seq_range ORDER_PP_FN_CM(3,8SEQ_RANGE)
#define ORDER_PP_8SEQ_RANGE(P,i,n,s,...) (,ORDER_PP_FX(TUPLE_AT_0,(,ORDER_PP_FX(SEQ_SPLIT_AT,(,P##n,ORDER_PP_FX(TUPLE_AT_1,(,ORDER_PP_SEQ_SPLIT_AT(,P##i,P##s),)))),)),P##__VA_ARGS__)

#define ORDER_PP_DEF_8seq_rest ORDER_PP_FN_CM(1,8SEQ_REST)
#define ORDER_PP_8SEQ_REST(P,s,...) (,ORDER_PP_EAT P##s,P##__VA_ARGS__)

#define ORDER_PP_DEF_8seq_rest_n ORDER_PP_FN_CM(2,8SEQ_REST_N)
#define ORDER_PP_8SEQ_REST_N(P,n,s,...) (,ORDER_PP_SEQ_REST_N(,P##n,P##s),P##__VA_ARGS__)

#define ORDER_PP_DEF_8seq_reverse ORDER_PP_FN_CM(1,8SEQ_REVERSE)
#define ORDER_PP_8SEQ_REVERSE(P,s,...) (,ORDER_PP_SEQ_REVERSE(,P##s),P##__VA_ARGS__)

#define ORDER_PP_SEQ_REVERSE(P,s) ORDER_PP_FX(PSEQ_TO_SEQ,(,ORDER_PP_FX(PSEQ_REVERSE,(,ORDER_PP_SEQ_TO_PSEQ(,P##s)))))
#define ORDER_PP_PSEQ_REVERSE(P,s) ORDER_PP_PM(,ORDER_PP_SEQ_REV_PAIR_A P##s(0,),8SEQ_REV_EXIT,)

#define ORDER_PP_8SEQ_REV_PAIR(P,s,...) (,ORDER_PP_SEQ_REV_PAIR_A P##s(0,),8SEQ_REV_SWAP,P##__VA_ARGS__)
#define ORDER_PP_SEQ_REV_PAIR_A(P,x) ORDER_PP_SEQ_REV_PAIR_B##P(,x##P)
#define ORDER_PP_SEQ_REV_PAIR_B(P,x) (,(,P##x,ORDER_PP_SEQ_REV_PAIR_C
#define ORDER_PP_SEQ_REV_PAIR_B0(...)
#define ORDER_PP_SEQ_REV_PAIR_C(P,x) ORDER_PP_SEQ_REV_PAIR_D##P(,x##P)
#define ORDER_PP_SEQ_REV_PAIR_D(P,x) P##x,))ORDER_PP_SEQ_REV_PAIR_E
#define ORDER_PP_SEQ_REV_PAIR_D0(...) ,0))
#define ORDER_PP_SEQ_REV_PAIR_E(P,x) ORDER_PP_SEQ_REV_PAIR_F##P(,x##P)
#define ORDER_PP_SEQ_REV_PAIR_F(P,x) (,(,P##x,ORDER_PP_SEQ_REV_PAIR_G
#define ORDER_PP_SEQ_REV_PAIR_F0(...)
#define ORDER_PP_SEQ_REV_PAIR_G(P,x) ORDER_PP_SEQ_REV_PAIR_H##P(,x##P)
#define ORDER_PP_SEQ_REV_PAIR_H(P,x) P##x,))ORDER_PP_SEQ_REV_PAIR_I
#define ORDER_PP_SEQ_REV_PAIR_H0(...) ,0)),8SEQ_REV_PAIR
#define ORDER_PP_SEQ_REV_PAIR_I(P,x) ORDER_PP_SEQ_REV_PAIR_J##P(,x##P)
#define ORDER_PP_SEQ_REV_PAIR_J(P,x) (,(,P##x,ORDER_PP_SEQ_REV_PAIR_G
#define ORDER_PP_SEQ_REV_PAIR_J0(...) ,8SEQ_REV_PAIR

#define ORDER_PP_8SEQ_REV_SWAP(P,s,...) (,ORDER_PP_SEQ_TERMINATE(ORDER_PP_SEQ_REV_SWAP_A P##s),P##__VA_ARGS__)
#define ORDER_PP_8SEQ_REV_EXIT(P,s,...) ,ORDER_PP_SEQ_TERMINATE(ORDER_PP_SEQ_REV_SWAP_A P##s))
#define ORDER_PP_SEQ_REV_SWAP_A(P,PxyS) ORDER_PP_SEQ_REV_SWAP_B PxyS##P
#define ORDER_PP_SEQ_REV_SWAP_A0
#define ORDER_PP_SEQ_REV_SWAP_B(P,x,y,S) ORDER_PP_SEQ_REV_SWAP_F##S(,P##y)(,P##x)ORDER_PP_SEQ_REV_SWAP_C
#define ORDER_PP_SEQ_REV_SWAP_C(P,PxyS) ORDER_PP_SEQ_REV_SWAP_D PxyS##P
#define ORDER_PP_SEQ_REV_SWAP_C0
#define ORDER_PP_SEQ_REV_SWAP_D(P,x,y,S) ORDER_PP_SEQ_REV_SWAP_F##S(,P##y)(,P##x)ORDER_PP_SEQ_REV_SWAP_A
#define ORDER_PP_SEQ_REV_SWAP_F
#define ORDER_PP_SEQ_REV_SWAP_F0(...)

#define ORDER_PP_DEF_8seq_set ORDER_PP_FN_CM(3,8SEQ_SET)
#define ORDER_PP_8SEQ_SET(P,i,s,x,...) (,ORDER_PP_FX(SEQ_SET_B,(,P##x,ORDER_PP_SEQ_SPLIT_AT(,P##i,P##s),)),P##__VA_ARGS__)
#define ORDER_PP_SEQ_SET_B(P,x,l,r,...) l##P(P##x)ORDER_PP_EAT r##P

#define ORDER_PP_DEF_8seq_size ORDER_PP_FN_CM(1,8SEQ_SIZE)
#define ORDER_PP_8SEQ_SIZE(P,s,...) (,ORDER_PP_FX(SEQ_SIZE,(,ORDER_PP_SEQ_TO_PSEQ(,P##s))),P##__VA_ARGS__)
#define ORDER_PP_SEQ_SIZE(P,s) ORDER_PP_SCAN(ORDER_PP_SEQ_SIZE_A P##s(0,)()ORDER_PP_PSEQ_CLOSE_A P##s(0,))
#define ORDER_PP_SEQ_SIZE_A(P,x) ORDER_PP_SEQ_SIZE_F ORDER_PP_BLOCK(ORDER_PP_SEQ_SIZE_B##P
#define ORDER_PP_SEQ_SIZE_A0
#define ORDER_PP_SEQ_SIZE_B(P,x) ORDER_PP_SEQ_SIZE_F ORDER_PP_BLOCK(ORDER_PP_SEQ_SIZE_A##P
#define ORDER_PP_SEQ_SIZE_B0
#define ORDER_PP_SEQ_SIZE_F(x) ORDER_PP_NAT_INC x

#define ORDER_PP_DEF_8seq_to_tuple ORDER_PP_FN_CM(1,8SEQ_TO_TUPLE)
#define ORDER_PP_8SEQ_TO_TUPLE(P,s,...) (,ORDER_PP_SEQ_TO_TUPLE(,P##s),P##__VA_ARGS__)

#define ORDER_PP_SEQ_TO_TUPLE(P,s) ORDER_PP_FX(SEQ_TO_TUPLE_TERMINATE,(ORDER_PP_SEQ_TO_TUPLE_A P##s))
#define ORDER_PP_SEQ_TO_TUPLE_TERMINATE(...) ORDER_PP_SEQ_TO_TUPLE_##__VA_ARGS__##0
#define ORDER_PP_SEQ_TO_TUPLE_ORDER_PP_SEQ_TO_TUPLE_A0
#define ORDER_PP_SEQ_TO_TUPLE_0(P,x) (P##x
#define ORDER_PP_SEQ_TO_TUPLE_A(x) 0(,x)ORDER_PP_SEQ_TO_TUPLE_B
#define ORDER_PP_SEQ_TO_TUPLE_B(x) ORDER_PP_RIGHT(,,x)ORDER_PP_SEQ_TO_TUPLE_C
#define ORDER_PP_SEQ_TO_TUPLE_B0 )
#define ORDER_PP_SEQ_TO_TUPLE_C(x) ORDER_PP_RIGHT(,,x)ORDER_PP_SEQ_TO_TUPLE_B
#define ORDER_PP_SEQ_TO_TUPLE_C0 )

// Higher-order functions

#define ORDER_PP_DEF_8seq_build ORDER_PP_FN_CM(2,8SEQ_BUILD)
#define ORDER_PP_8SEQ_BUILD(P,f,xs,...) (,ORDER_PP_SEQ_IS_NIL(,P##xs)(,,ORDER_PP_SEQ_AT(,0,P##xs),8SEQ_BUILD_3,P##f,ORDER_PP_EAT xs##P),P##__VA_ARGS__)
#define ORDER_PP_8SEQ_BUILD_3(P,y,f,xs,...) (,ORDER_PP_SEQ_IS_NIL(,P##xs)(,P##y,ORDER_PP_SEQ_AT(,0,P##xs),ORDER_PP_OPEN f##P,8AP,ORDER_PP_SEQ_AT(,1,P##xs(P##y)),8SEQ_BUILD_3,P##f,ORDER_PP_EAT_2 xs##P(P##y)),P##__VA_ARGS__)

#define ORDER_PP_DEF_8seq_exists ORDER_PP_FN_CM(2,8SEQ_EXISTS)
#define ORDER_PP_8SEQ_EXISTS(P,f,s,...) (,ORDER_PP_SEQ_IS_NIL(,P##s)(,8false,ORDER_PP_SEQ_AT(,0,P##s),ORDER_PP_OPEN f##P,8SEQ_EXISTS_4,P##f,ORDER_PP_SEQ_AT_1 P##s),P##__VA_ARGS__)
#define ORDER_PP_8SEQ_EXISTS_4(P,b,f,x,xs,...) (,ORDER_PP_SELECT_4(ORDER_PP_IF_##b,ORDER_PP_SEQ_IS_NIL(,P##xs))(,8true,8true,ORDER_PP_LEFT(,P##x,ORDER_PP_OPEN f##P),P##x,ORDER_PP_OPEN f##P,8SEQ_EXISTS_4,P##f,ORDER_PP_SEQ_AT_0 P##xs),P##__VA_ARGS__)

#define ORDER_PP_DEF_8seq_filter ORDER_PP_FN_CM(2,8REMAP_021,,8SEQ_FILTER_3)
#define ORDER_PP_8SEQ_FILTER_3(P,f,out,in,...) (,ORDER_PP_SEQ_IS_NIL(,P##in)(,P##out,ORDER_PP_SEQ_AT(,0,P##in),ORDER_PP_OPEN f##P,8SEQ_FILTER_B,P##f,P##out,ORDER_PP_SEQ_AT_0 in##P),P##__VA_ARGS__)
#define ORDER_PP_8SEQ_FILTER_B(P,b,f,out,x,...) ORDER_PP_CM_INVOKE(8SEQ_FILTER_3,P##f,ORDER_PP_LEFT(,out##P)ORDER_PP_WHEN_##b(,(P##x))),P##__VA_ARGS__)

#define ORDER_PP_DEF_8seq_fold ORDER_PP_FN_CM(3,8REMAP_102,8SEQ_FOLD)
#define ORDER_PP_8SEQ_FOLD(P,x,f,s,...) (,P##x,ORDER_PP_SEQ_IS_NIL(,P##s)(,,ORDER_PP_OPEN f##P,8AP,ORDER_PP_SEQ_AT(,0,P##s),8SEQ_FOLD,P##f,ORDER_PP_EAT s##P,)P##__VA_ARGS__)

#define ORDER_PP_DEF_8seq_for_all ORDER_PP_FN_CM(2,8SEQ_FOR_ALL)
#define ORDER_PP_8SEQ_FOR_ALL(P,f,s,...) (,ORDER_PP_SEQ_IS_NIL(,P##s)(,8true,ORDER_PP_SEQ_AT(,0,P##s),ORDER_PP_OPEN f##P,8SEQ_FOR_ALL_4,P##f,ORDER_PP_SEQ_AT_1 P##s),P##__VA_ARGS__)
#define ORDER_PP_8SEQ_FOR_ALL_4(P,b,f,x,xs,...) (,ORDER_PP_IF_NOT_##b(,8false,P##x,ORDER_PP_OPEN f##P ORDER_PP_SEQ_IS_NIL(,P##xs)(,,,8SEQ_FOR_ALL_4,P##f,ORDER_PP_SEQ_AT_0 P##xs)),P##__VA_ARGS__)

#define ORDER_PP_DEF_8seq_for_each ORDER_PP_FN_CM(2,8REMAP_201,,8SEQ_FOR_EACH_3)
#define ORDER_PP_8SEQ_FOR_EACH_3(P,_,f,s,...) (,ORDER_PP_SEQ_IS_NIL(,P##s)(,,ORDER_PP_SEQ_AT(,0,P##s),ORDER_PP_OPEN f##P,8SEQ_FOR_EACH_3,P##f,ORDER_PP_EAT s##P),P##__VA_ARGS__)

#define ORDER_PP_DEF_8seq_for_each_in_product ORDER_PP_FN_CM(2,8SEQ_FOR_EACH_IN_PRODUCT)
#define ORDER_PP_8SEQ_FOR_EACH_IN_PRODUCT(P,f,s,...) (,ORDER_PP_SEQ_IS_NIL(,P##s)(,,,8SEQ_FOR_EACH_3,(,ORDER_PP_OPEN f##P,8SEQ_FOR_EACH_IN_PRODUCT,ORDER_PP_EAT s##P),ORDER_PP_SEQ_AT(,0,P##s)),P##__VA_ARGS__)

#define ORDER_PP_DEF_8seq_for_each_with_idx ORDER_PP_FN_CM(2,8REMAP_2013,,(00),8SEQ_FOR_EACH_WITH_IDX_4)
#define ORDER_PP_8SEQ_FOR_EACH_WITH_IDX_4(P,_,f,s,i,...) (,ORDER_PP_SEQ_IS_NIL(,P##s)(,,P##i,ORDER_PP_OPEN f##P,8AP,ORDER_PP_SEQ_AT(,0,P##s),8SEQ_FOR_EACH_WITH_IDX_4,P##f,ORDER_PP_EAT s##P,ORDER_PP_NAT_INC P##i),P##__VA_ARGS__)

#define ORDER_PP_DEF_8seq_map ORDER_PP_FN_CM(2,8SEQ_MAP)
#define ORDER_PP_8SEQ_MAP(P,f,in,...) (,ORDER_PP_SEQ_IS_NIL(,P##in)(,,ORDER_PP_SEQ_AT(,0,P##in),ORDER_PP_OPEN f##P,8SEQ_MAP_3,P##f,ORDER_PP_EAT in##P,),P##__VA_ARGS__)
#define ORDER_PP_8SEQ_MAP_3(P,x,f,in,out,...) (,ORDER_PP_SEQ_IS_NIL(,P##in)(,,ORDER_PP_SEQ_AT(,0,P##in),ORDER_PP_OPEN f##P,8SEQ_MAP_3,P##f,ORDER_PP_EAT in##P,)P##out(P##x),P##__VA_ARGS__)

#define ORDER_PP_DEF_8seq_merge ORDER_PP_FN_CM(3,8SEQ_MERGE_4,)
#define ORDER_PP_8SEQ_MERGE_4(P,f,ls,rs,out,...) (,ORDER_PP_SELECT_4(ORDER_PP_SEQ_IS_NIL(,P##ls),ORDER_PP_SEQ_IS_NIL(,P##rs))(,P##out,ORDER_PP_OPEN(,out##P)P##rs,ORDER_PP_OPEN(,out##P)P##ls,ORDER_PP_SEQ_AT(,0,P##ls),ORDER_PP_OPEN f##P,8AP,ORDER_PP_SEQ_AT(,0,P##rs),8SEQ_MERGE_B,P##f,ORDER_PP_SEQ_AT_0 ls##P,ORDER_PP_SEQ_AT_0 rs##P,P##out),P##__VA_ARGS__)
#define ORDER_PP_8SEQ_MERGE_B(P,c,f,l,ls,r,rs,out,...) ORDER_PP_CM_INVOKE(8SEQ_MERGE_4,P##f,ORDER_PP_UNLESS_##c(,(P##l))P##ls,ORDER_PP_WHEN_##c(,(P##r))P##rs,out##P(ORDER_PP_IF_##c(,P##l,P##r))),P##__VA_ARGS__)

#define ORDER_PP_DEF_8seq_merge_sort ORDER_PP_FN_CM(2,8SEQ_MERGE_SORT)
#define ORDER_PP_8SEQ_MERGE_SORT(P,f,s,...) (,(,8WAIT_2,8REMAP_2013,(,P##f,,8SEQ_MERGE_4,)),8SEQ_BUILD,ORDER_PP_SEQ_MAP_SEQ(,P##s),P##__VA_ARGS__)

#define ORDER_PP_DEF_8seq_partition ORDER_PP_FN_CM(2,8SEQ_PARTITION_4,,,8PAIR)
#define ORDER_PP_8SEQ_PARTITION_4(P,f,in,ot,of,K,...) (,ORDER_PP_SEQ_IS_NIL(,P##in)(,ORDER_PP_OPEN(,P##ot,P##K,P##of),ORDER_PP_SEQ_AT(,0,P##in),ORDER_PP_OPEN f##P,8SEQ_PARTITION_B,P##f,ORDER_PP_SEQ_AT_0 in##P,P##ot,P##of,P##K),P##__VA_ARGS__)
#define ORDER_PP_8SEQ_PARTITION_B(P,b,f,x,in,ot,of,...) ORDER_PP_CM_INVOKE(8SEQ_PARTITION_4,P##f,P##in,ORDER_PP_LEFT(,ot##P)ORDER_PP_WHEN_##b(,(P##x)),ORDER_PP_LEFT(,of##P)ORDER_PP_UNLESS_##b(,(P##x))),P##__VA_ARGS__)

#define ORDER_PP_DEF_8seq_partition_sort ORDER_PP_FN_CM(2,8SEQ_PARTITION_SORT)
#define ORDER_PP_8SEQ_PARTITION_SORT(P,f,s,...) (,ORDER_PP_SEQ_IS_NIL(,P##s)(,,ORDER_PP_SEQ_AT(,0,P##s),ORDER_PP_OPEN f##P,8SEQ_PARTITION_4,ORDER_PP_EAT s##P,,,8SEQ_PARTITION_SORT_B,ORDER_PP_SEQ_AT(,0,P##s),P##f),P##__VA_ARGS__)
#define ORDER_PP_8SEQ_PARTITION_SORT_B(P,st,sf,m,f,...) (,P##f,8SEQ_PARTITION_SORT,P##st,8SEQ_PARTITION_SORT_C,P##sf,P##m,P##f,P##__VA_ARGS__)
#define ORDER_PP_8SEQ_PARTITION_SORT_C(P,st,sf,m,f,...) (,P##f,8SEQ_PARTITION_SORT,P##sf,8SEQ_PARTITION_SORT_D,P##m,P##st,P##__VA_ARGS__)
#define ORDER_PP_8SEQ_PARTITION_SORT_D(P,sl,m,sr,...) (,P##sl(P##m)P##sr,P##__VA_ARGS__)

#define ORDER_PP_DEF_8seq_select ORDER_PP_FN_CM(3,8REMAP_120,8SEQ_SELECT)
#define ORDER_PP_8SEQ_SELECT(P,y,xs,f,...) (,P##y,ORDER_PP_SEQ_IS_NIL(,P##xs)(,,ORDER_PP_OPEN f##P,8AP,ORDER_PP_SEQ_AT(,0,P##xs),8SEQ_SELECT_B,P##y,ORDER_PP_SEQ_AT_0 xs##P,P##f,)P##__VA_ARGS__)
#define ORDER_PP_8SEQ_SELECT_B(P,b,y,x,...) ORDER_PP_CM_INVOKE(8SEQ_SELECT,ORDER_PP_IF_##b(,P##x,P##y)),P##__VA_ARGS__)

#define ORDER_PP_DEF_8seq_sort ORDER_PP_FN_CM(2,8SEQ_MERGE_SORT)

#define ORDER_PP_DEF_8seq_unfold ORDER_PP_FN_CM(4,8SEQ_UNFOLD_5,)
#define ORDER_PP_8SEQ_UNFOLD_5(P,x,c,...) (,P##x,ORDER_PP_OPEN c##P,8SEQ_UNFOLD_B,P##x,c##P,P##__VA_ARGS__)
#define ORDER_PP_8SEQ_UNFOLD_B(P,b,x,c,s,f,...) (,ORDER_PP_WHEN_##b(,P##x,ORDER_PP_OPEN f##P,8SEQ_UNFOLD_C,P##x,P##c,s##P,f##P,)P##__VA_ARGS__)
#define ORDER_PP_8SEQ_UNFOLD_C(P,y,x,c,s,f,ys,...) (,P##x,ORDER_PP_OPEN s##P,8SEQ_UNFOLD_5,P##c,P##s,P##f,P##ys(P##y),P##__VA_ARGS__)

// Details

#define ORDER_PP_EAT_2(...) ORDER_PP_EAT

#define ORDER_PP_SEQ_AT(P,i,s) ORDER_PP_SEQ_AT_B(ORDER_PP_SEQ_AT_##i P##s)
#define ORDER_PP_SEQ_AT_B(xs) ORDER_PP_TUPLE_AT_0(,xs)
#define ORDER_PP_SEQ_AT_0(x) x,
#define ORDER_PP_SEQ_AT_1(...) ORDER_PP_SEQ_AT_0

#define ORDER_PP_PSEQ_CLOSE(P,s) ORDER_PP_PSEQ_CLOSE_A P##s(0,)
#define ORDER_PP_PSEQ_CLOSE_A(P,x) )ORDER_PP_PSEQ_CLOSE_B##P
#define ORDER_PP_PSEQ_CLOSE_A0
#define ORDER_PP_PSEQ_CLOSE_B(P,x) )ORDER_PP_PSEQ_CLOSE_A##P
#define ORDER_PP_PSEQ_CLOSE_B0

#define ORDER_PP_SEQ_IS_NIL(P,s) ORDER_PP_TEST(ORDER_PP_IF_,ORDER_PP_IS_EDIBLE_TEST P##s,8false,8true)

#define ORDER_PP_IS_SEQ_SIZE_LESS_EQ_1(P,s) ORDER_PP_TEST(ORDER_PP_IF_,ORDER_PP_IS_EDIBLE_TWICE_TEST P##s,8false,8true)
#define ORDER_PP_IS_EDIBLE_TWICE_TEST(...) ORDER_PP_IS_EDIBLE_TEST

#define ORDER_PP_SEQ_MAP_SEQ(P,s) ORDER_PP_SEQ_TERMINATE(ORDER_PP_SEQ_MAP_SEQ_A P##s)
#define ORDER_PP_SEQ_MAP_SEQ_A(x) ((x))ORDER_PP_SEQ_MAP_SEQ_B
#define ORDER_PP_SEQ_MAP_SEQ_A0
#define ORDER_PP_SEQ_MAP_SEQ_B(x) ((x))ORDER_PP_SEQ_MAP_SEQ_A
#define ORDER_PP_SEQ_MAP_SEQ_B0

#define ORDER_PP_SEQ_TERMINATE(...) ORDER_PP_SEQ_TERMINATE_B(__VA_ARGS__)
#define ORDER_PP_SEQ_TERMINATE_B(...) __VA_ARGS__##0

#define ORDER_PP_SEQ_TO_PSEQ(P,s) ORDER_PP_SEQ_TERMINATE(ORDER_PP_SEQ_TO_PSEQ_A P##s)
#define ORDER_PP_SEQ_TO_PSEQ_A(x) (,x)ORDER_PP_SEQ_TO_PSEQ_B
#define ORDER_PP_SEQ_TO_PSEQ_A0
#define ORDER_PP_SEQ_TO_PSEQ_B(x) (,x)ORDER_PP_SEQ_TO_PSEQ_A
#define ORDER_PP_SEQ_TO_PSEQ_B0

#define ORDER_PP_PSEQ_TO_SEQ(P,s) ORDER_PP_SEQ_TERMINATE(ORDER_PP_PSEQ_TO_SEQ_A P##s)
#define ORDER_PP_PSEQ_TO_SEQ_A(P,x) (P##x)ORDER_PP_PSEQ_TO_SEQ_B
#define ORDER_PP_PSEQ_TO_SEQ_A0
#define ORDER_PP_PSEQ_TO_SEQ_B(P,x) (P##x)ORDER_PP_PSEQ_TO_SEQ_A
#define ORDER_PP_PSEQ_TO_SEQ_B0

#define ORDER_PP_SEQ_REST_N(P,n,s) ORDER_PP_FX(OVERLOAD(SEQ_REST,ORDER_PP_SCAN(ORDER_PP_NAT_MOD_100_LIT P##n)),ORDER_PP_PM(,ORDER_PP_NAT_DIV_100 P##n,8SEQ_REST_100N,P##s,))
#define ORDER_PP_8SEQ_REST_100N(P,n,s,...) ORDER_PP_NAT_IS_0 P##n(,ORDER_PP_8SEQ_REST_100N_EXIT,)(,ORDER_PP_NAT_DEC P##n,8SEQ_REST_100N,ORDER_PP_SEQ_REST_100 P##s,)
#define ORDER_PP_8SEQ_REST_100N_EXIT(P,n,seq_rest_100n,s,...) ,ORDER_PP_##s)

#define ORDER_PP_ORDER_PP_SEQ_REST_100

#define ORDER_PP_SEQ_REST_0
#define ORDER_PP_SEQ_REST_1(x)
#define ORDER_PP_SEQ_REST_2(x) ORDER_PP_SEQ_REST_1
#define ORDER_PP_SEQ_REST_3(x) ORDER_PP_SEQ_REST_2
#define ORDER_PP_SEQ_REST_4(x) ORDER_PP_SEQ_REST_3
#define ORDER_PP_SEQ_REST_5(x) ORDER_PP_SEQ_REST_4
#define ORDER_PP_SEQ_REST_6(x) ORDER_PP_SEQ_REST_5
#define ORDER_PP_SEQ_REST_7(x) ORDER_PP_SEQ_REST_6
#define ORDER_PP_SEQ_REST_8(x) ORDER_PP_SEQ_REST_7
#define ORDER_PP_SEQ_REST_9(x) ORDER_PP_SEQ_REST_8
#define ORDER_PP_SEQ_REST_10(x) ORDER_PP_SEQ_REST_9
#define ORDER_PP_SEQ_REST_11(x) ORDER_PP_SEQ_REST_10
#define ORDER_PP_SEQ_REST_12(x) ORDER_PP_SEQ_REST_11
#define ORDER_PP_SEQ_REST_13(x) ORDER_PP_SEQ_REST_12
#define ORDER_PP_SEQ_REST_14(x) ORDER_PP_SEQ_REST_13
#define ORDER_PP_SEQ_REST_15(x) ORDER_PP_SEQ_REST_14
#define ORDER_PP_SEQ_REST_16(x) ORDER_PP_SEQ_REST_15
#define ORDER_PP_SEQ_REST_17(x) ORDER_PP_SEQ_REST_16
#define ORDER_PP_SEQ_REST_18(x) ORDER_PP_SEQ_REST_17
#define ORDER_PP_SEQ_REST_19(x) ORDER_PP_SEQ_REST_18
#define ORDER_PP_SEQ_REST_20(x) ORDER_PP_SEQ_REST_19
#define ORDER_PP_SEQ_REST_21(x) ORDER_PP_SEQ_REST_20
#define ORDER_PP_SEQ_REST_22(x) ORDER_PP_SEQ_REST_21
#define ORDER_PP_SEQ_REST_23(x) ORDER_PP_SEQ_REST_22
#define ORDER_PP_SEQ_REST_24(x) ORDER_PP_SEQ_REST_23
#define ORDER_PP_SEQ_REST_25(x) ORDER_PP_SEQ_REST_24
#define ORDER_PP_SEQ_REST_26(x) ORDER_PP_SEQ_REST_25
#define ORDER_PP_SEQ_REST_27(x) ORDER_PP_SEQ_REST_26
#define ORDER_PP_SEQ_REST_28(x) ORDER_PP_SEQ_REST_27
#define ORDER_PP_SEQ_REST_29(x) ORDER_PP_SEQ_REST_28
#define ORDER_PP_SEQ_REST_30(x) ORDER_PP_SEQ_REST_29
#define ORDER_PP_SEQ_REST_31(x) ORDER_PP_SEQ_REST_30
#define ORDER_PP_SEQ_REST_32(x) ORDER_PP_SEQ_REST_31
#define ORDER_PP_SEQ_REST_33(x) ORDER_PP_SEQ_REST_32
#define ORDER_PP_SEQ_REST_34(x) ORDER_PP_SEQ_REST_33
#define ORDER_PP_SEQ_REST_35(x) ORDER_PP_SEQ_REST_34
#define ORDER_PP_SEQ_REST_36(x) ORDER_PP_SEQ_REST_35
#define ORDER_PP_SEQ_REST_37(x) ORDER_PP_SEQ_REST_36
#define ORDER_PP_SEQ_REST_38(x) ORDER_PP_SEQ_REST_37
#define ORDER_PP_SEQ_REST_39(x) ORDER_PP_SEQ_REST_38
#define ORDER_PP_SEQ_REST_40(x) ORDER_PP_SEQ_REST_39
#define ORDER_PP_SEQ_REST_41(x) ORDER_PP_SEQ_REST_40
#define ORDER_PP_SEQ_REST_42(x) ORDER_PP_SEQ_REST_41
#define ORDER_PP_SEQ_REST_43(x) ORDER_PP_SEQ_REST_42
#define ORDER_PP_SEQ_REST_44(x) ORDER_PP_SEQ_REST_43
#define ORDER_PP_SEQ_REST_45(x) ORDER_PP_SEQ_REST_44
#define ORDER_PP_SEQ_REST_46(x) ORDER_PP_SEQ_REST_45
#define ORDER_PP_SEQ_REST_47(x) ORDER_PP_SEQ_REST_46
#define ORDER_PP_SEQ_REST_48(x) ORDER_PP_SEQ_REST_47
#define ORDER_PP_SEQ_REST_49(x) ORDER_PP_SEQ_REST_48
#define ORDER_PP_SEQ_REST_50(x) ORDER_PP_SEQ_REST_49
#define ORDER_PP_SEQ_REST_51(x) ORDER_PP_SEQ_REST_50
#define ORDER_PP_SEQ_REST_52(x) ORDER_PP_SEQ_REST_51
#define ORDER_PP_SEQ_REST_53(x) ORDER_PP_SEQ_REST_52
#define ORDER_PP_SEQ_REST_54(x) ORDER_PP_SEQ_REST_53
#define ORDER_PP_SEQ_REST_55(x) ORDER_PP_SEQ_REST_54
#define ORDER_PP_SEQ_REST_56(x) ORDER_PP_SEQ_REST_55
#define ORDER_PP_SEQ_REST_57(x) ORDER_PP_SEQ_REST_56
#define ORDER_PP_SEQ_REST_58(x) ORDER_PP_SEQ_REST_57
#define ORDER_PP_SEQ_REST_59(x) ORDER_PP_SEQ_REST_58
#define ORDER_PP_SEQ_REST_60(x) ORDER_PP_SEQ_REST_59
#define ORDER_PP_SEQ_REST_61(x) ORDER_PP_SEQ_REST_60
#define ORDER_PP_SEQ_REST_62(x) ORDER_PP_SEQ_REST_61
#define ORDER_PP_SEQ_REST_63(x) ORDER_PP_SEQ_REST_62
#define ORDER_PP_SEQ_REST_64(x) ORDER_PP_SEQ_REST_63
#define ORDER_PP_SEQ_REST_65(x) ORDER_PP_SEQ_REST_64
#define ORDER_PP_SEQ_REST_66(x) ORDER_PP_SEQ_REST_65
#define ORDER_PP_SEQ_REST_67(x) ORDER_PP_SEQ_REST_66
#define ORDER_PP_SEQ_REST_68(x) ORDER_PP_SEQ_REST_67
#define ORDER_PP_SEQ_REST_69(x) ORDER_PP_SEQ_REST_68
#define ORDER_PP_SEQ_REST_70(x) ORDER_PP_SEQ_REST_69
#define ORDER_PP_SEQ_REST_71(x) ORDER_PP_SEQ_REST_70
#define ORDER_PP_SEQ_REST_72(x) ORDER_PP_SEQ_REST_71
#define ORDER_PP_SEQ_REST_73(x) ORDER_PP_SEQ_REST_72
#define ORDER_PP_SEQ_REST_74(x) ORDER_PP_SEQ_REST_73
#define ORDER_PP_SEQ_REST_75(x) ORDER_PP_SEQ_REST_74
#define ORDER_PP_SEQ_REST_76(x) ORDER_PP_SEQ_REST_75
#define ORDER_PP_SEQ_REST_77(x) ORDER_PP_SEQ_REST_76
#define ORDER_PP_SEQ_REST_78(x) ORDER_PP_SEQ_REST_77
#define ORDER_PP_SEQ_REST_79(x) ORDER_PP_SEQ_REST_78
#define ORDER_PP_SEQ_REST_80(x) ORDER_PP_SEQ_REST_79
#define ORDER_PP_SEQ_REST_81(x) ORDER_PP_SEQ_REST_80
#define ORDER_PP_SEQ_REST_82(x) ORDER_PP_SEQ_REST_81
#define ORDER_PP_SEQ_REST_83(x) ORDER_PP_SEQ_REST_82
#define ORDER_PP_SEQ_REST_84(x) ORDER_PP_SEQ_REST_83
#define ORDER_PP_SEQ_REST_85(x) ORDER_PP_SEQ_REST_84
#define ORDER_PP_SEQ_REST_86(x) ORDER_PP_SEQ_REST_85
#define ORDER_PP_SEQ_REST_87(x) ORDER_PP_SEQ_REST_86
#define ORDER_PP_SEQ_REST_88(x) ORDER_PP_SEQ_REST_87
#define ORDER_PP_SEQ_REST_89(x) ORDER_PP_SEQ_REST_88
#define ORDER_PP_SEQ_REST_90(x) ORDER_PP_SEQ_REST_89
#define ORDER_PP_SEQ_REST_91(x) ORDER_PP_SEQ_REST_90
#define ORDER_PP_SEQ_REST_92(x) ORDER_PP_SEQ_REST_91
#define ORDER_PP_SEQ_REST_93(x) ORDER_PP_SEQ_REST_92
#define ORDER_PP_SEQ_REST_94(x) ORDER_PP_SEQ_REST_93
#define ORDER_PP_SEQ_REST_95(x) ORDER_PP_SEQ_REST_94
#define ORDER_PP_SEQ_REST_96(x) ORDER_PP_SEQ_REST_95
#define ORDER_PP_SEQ_REST_97(x) ORDER_PP_SEQ_REST_96
#define ORDER_PP_SEQ_REST_98(x) ORDER_PP_SEQ_REST_97
#define ORDER_PP_SEQ_REST_99(x) ORDER_PP_SEQ_REST_98
#define ORDER_PP_SEQ_REST_100(x) ORDER_PP_SEQ_REST_99

#define ORDER_PP_SEQ_SPLIT_AT(P,i,s) ORDER_PP_PM(,ORDER_PP_NAT_DIV_100 P##i,8SEQ_SPLIT_AT_B,ORDER_PP_OVERLOAD(SEQ_SPLIT_AT,ORDER_PP_SCAN(ORDER_PP_NAT_MOD_100_LIT P##i))P##s,)
#define ORDER_PP_8SEQ_SPLIT_AT_B(P,n,first_n,rest,...) ORDER_PP_NAT_IS_0 P##n(ORDER_PP_,8SEQ_SPLIT_AT_C,8SEQ_SPLIT_AT_D)(,P##n,P##first_n,P##rest)
#define ORDER_PP_8SEQ_SPLIT_AT_C(P,n,first_n,rest) ,P##first_n,P##rest)
#define ORDER_PP_8SEQ_SPLIT_AT_D(P,n,first_n,rest) (,ORDER_PP_NAT_DEC P##n,8SEQ_SPLIT_AT_B,P##first_n ORDER_PP_SEQ_SPLIT_AT_100 P##rest,)

#define ORDER_PP_SEQ_SPLIT_AT_0 ,
#define ORDER_PP_SEQ_SPLIT_AT_1(x) (x),
#define ORDER_PP_SEQ_SPLIT_AT_2(x) (x)ORDER_PP_SEQ_SPLIT_AT_1
#define ORDER_PP_SEQ_SPLIT_AT_3(x) (x)ORDER_PP_SEQ_SPLIT_AT_2
#define ORDER_PP_SEQ_SPLIT_AT_4(x) (x)ORDER_PP_SEQ_SPLIT_AT_3
#define ORDER_PP_SEQ_SPLIT_AT_5(x) (x)ORDER_PP_SEQ_SPLIT_AT_4
#define ORDER_PP_SEQ_SPLIT_AT_6(x) (x)ORDER_PP_SEQ_SPLIT_AT_5
#define ORDER_PP_SEQ_SPLIT_AT_7(x) (x)ORDER_PP_SEQ_SPLIT_AT_6
#define ORDER_PP_SEQ_SPLIT_AT_8(x) (x)ORDER_PP_SEQ_SPLIT_AT_7
#define ORDER_PP_SEQ_SPLIT_AT_9(x) (x)ORDER_PP_SEQ_SPLIT_AT_8
#define ORDER_PP_SEQ_SPLIT_AT_10(x) (x)ORDER_PP_SEQ_SPLIT_AT_9
#define ORDER_PP_SEQ_SPLIT_AT_11(x) (x)ORDER_PP_SEQ_SPLIT_AT_10
#define ORDER_PP_SEQ_SPLIT_AT_12(x) (x)ORDER_PP_SEQ_SPLIT_AT_11
#define ORDER_PP_SEQ_SPLIT_AT_13(x) (x)ORDER_PP_SEQ_SPLIT_AT_12
#define ORDER_PP_SEQ_SPLIT_AT_14(x) (x)ORDER_PP_SEQ_SPLIT_AT_13
#define ORDER_PP_SEQ_SPLIT_AT_15(x) (x)ORDER_PP_SEQ_SPLIT_AT_14
#define ORDER_PP_SEQ_SPLIT_AT_16(x) (x)ORDER_PP_SEQ_SPLIT_AT_15
#define ORDER_PP_SEQ_SPLIT_AT_17(x) (x)ORDER_PP_SEQ_SPLIT_AT_16
#define ORDER_PP_SEQ_SPLIT_AT_18(x) (x)ORDER_PP_SEQ_SPLIT_AT_17
#define ORDER_PP_SEQ_SPLIT_AT_19(x) (x)ORDER_PP_SEQ_SPLIT_AT_18
#define ORDER_PP_SEQ_SPLIT_AT_20(x) (x)ORDER_PP_SEQ_SPLIT_AT_19
#define ORDER_PP_SEQ_SPLIT_AT_21(x) (x)ORDER_PP_SEQ_SPLIT_AT_20
#define ORDER_PP_SEQ_SPLIT_AT_22(x) (x)ORDER_PP_SEQ_SPLIT_AT_21
#define ORDER_PP_SEQ_SPLIT_AT_23(x) (x)ORDER_PP_SEQ_SPLIT_AT_22
#define ORDER_PP_SEQ_SPLIT_AT_24(x) (x)ORDER_PP_SEQ_SPLIT_AT_23
#define ORDER_PP_SEQ_SPLIT_AT_25(x) (x)ORDER_PP_SEQ_SPLIT_AT_24
#define ORDER_PP_SEQ_SPLIT_AT_26(x) (x)ORDER_PP_SEQ_SPLIT_AT_25
#define ORDER_PP_SEQ_SPLIT_AT_27(x) (x)ORDER_PP_SEQ_SPLIT_AT_26
#define ORDER_PP_SEQ_SPLIT_AT_28(x) (x)ORDER_PP_SEQ_SPLIT_AT_27
#define ORDER_PP_SEQ_SPLIT_AT_29(x) (x)ORDER_PP_SEQ_SPLIT_AT_28
#define ORDER_PP_SEQ_SPLIT_AT_30(x) (x)ORDER_PP_SEQ_SPLIT_AT_29
#define ORDER_PP_SEQ_SPLIT_AT_31(x) (x)ORDER_PP_SEQ_SPLIT_AT_30
#define ORDER_PP_SEQ_SPLIT_AT_32(x) (x)ORDER_PP_SEQ_SPLIT_AT_31
#define ORDER_PP_SEQ_SPLIT_AT_33(x) (x)ORDER_PP_SEQ_SPLIT_AT_32
#define ORDER_PP_SEQ_SPLIT_AT_34(x) (x)ORDER_PP_SEQ_SPLIT_AT_33
#define ORDER_PP_SEQ_SPLIT_AT_35(x) (x)ORDER_PP_SEQ_SPLIT_AT_34
#define ORDER_PP_SEQ_SPLIT_AT_36(x) (x)ORDER_PP_SEQ_SPLIT_AT_35
#define ORDER_PP_SEQ_SPLIT_AT_37(x) (x)ORDER_PP_SEQ_SPLIT_AT_36
#define ORDER_PP_SEQ_SPLIT_AT_38(x) (x)ORDER_PP_SEQ_SPLIT_AT_37
#define ORDER_PP_SEQ_SPLIT_AT_39(x) (x)ORDER_PP_SEQ_SPLIT_AT_38
#define ORDER_PP_SEQ_SPLIT_AT_40(x) (x)ORDER_PP_SEQ_SPLIT_AT_39
#define ORDER_PP_SEQ_SPLIT_AT_41(x) (x)ORDER_PP_SEQ_SPLIT_AT_40
#define ORDER_PP_SEQ_SPLIT_AT_42(x) (x)ORDER_PP_SEQ_SPLIT_AT_41
#define ORDER_PP_SEQ_SPLIT_AT_43(x) (x)ORDER_PP_SEQ_SPLIT_AT_42
#define ORDER_PP_SEQ_SPLIT_AT_44(x) (x)ORDER_PP_SEQ_SPLIT_AT_43
#define ORDER_PP_SEQ_SPLIT_AT_45(x) (x)ORDER_PP_SEQ_SPLIT_AT_44
#define ORDER_PP_SEQ_SPLIT_AT_46(x) (x)ORDER_PP_SEQ_SPLIT_AT_45
#define ORDER_PP_SEQ_SPLIT_AT_47(x) (x)ORDER_PP_SEQ_SPLIT_AT_46
#define ORDER_PP_SEQ_SPLIT_AT_48(x) (x)ORDER_PP_SEQ_SPLIT_AT_47
#define ORDER_PP_SEQ_SPLIT_AT_49(x) (x)ORDER_PP_SEQ_SPLIT_AT_48
#define ORDER_PP_SEQ_SPLIT_AT_50(x) (x)ORDER_PP_SEQ_SPLIT_AT_49
#define ORDER_PP_SEQ_SPLIT_AT_51(x) (x)ORDER_PP_SEQ_SPLIT_AT_50
#define ORDER_PP_SEQ_SPLIT_AT_52(x) (x)ORDER_PP_SEQ_SPLIT_AT_51
#define ORDER_PP_SEQ_SPLIT_AT_53(x) (x)ORDER_PP_SEQ_SPLIT_AT_52
#define ORDER_PP_SEQ_SPLIT_AT_54(x) (x)ORDER_PP_SEQ_SPLIT_AT_53
#define ORDER_PP_SEQ_SPLIT_AT_55(x) (x)ORDER_PP_SEQ_SPLIT_AT_54
#define ORDER_PP_SEQ_SPLIT_AT_56(x) (x)ORDER_PP_SEQ_SPLIT_AT_55
#define ORDER_PP_SEQ_SPLIT_AT_57(x) (x)ORDER_PP_SEQ_SPLIT_AT_56
#define ORDER_PP_SEQ_SPLIT_AT_58(x) (x)ORDER_PP_SEQ_SPLIT_AT_57
#define ORDER_PP_SEQ_SPLIT_AT_59(x) (x)ORDER_PP_SEQ_SPLIT_AT_58
#define ORDER_PP_SEQ_SPLIT_AT_60(x) (x)ORDER_PP_SEQ_SPLIT_AT_59
#define ORDER_PP_SEQ_SPLIT_AT_61(x) (x)ORDER_PP_SEQ_SPLIT_AT_60
#define ORDER_PP_SEQ_SPLIT_AT_62(x) (x)ORDER_PP_SEQ_SPLIT_AT_61
#define ORDER_PP_SEQ_SPLIT_AT_63(x) (x)ORDER_PP_SEQ_SPLIT_AT_62
#define ORDER_PP_SEQ_SPLIT_AT_64(x) (x)ORDER_PP_SEQ_SPLIT_AT_63
#define ORDER_PP_SEQ_SPLIT_AT_65(x) (x)ORDER_PP_SEQ_SPLIT_AT_64
#define ORDER_PP_SEQ_SPLIT_AT_66(x) (x)ORDER_PP_SEQ_SPLIT_AT_65
#define ORDER_PP_SEQ_SPLIT_AT_67(x) (x)ORDER_PP_SEQ_SPLIT_AT_66
#define ORDER_PP_SEQ_SPLIT_AT_68(x) (x)ORDER_PP_SEQ_SPLIT_AT_67
#define ORDER_PP_SEQ_SPLIT_AT_69(x) (x)ORDER_PP_SEQ_SPLIT_AT_68
#define ORDER_PP_SEQ_SPLIT_AT_70(x) (x)ORDER_PP_SEQ_SPLIT_AT_69
#define ORDER_PP_SEQ_SPLIT_AT_71(x) (x)ORDER_PP_SEQ_SPLIT_AT_70
#define ORDER_PP_SEQ_SPLIT_AT_72(x) (x)ORDER_PP_SEQ_SPLIT_AT_71
#define ORDER_PP_SEQ_SPLIT_AT_73(x) (x)ORDER_PP_SEQ_SPLIT_AT_72
#define ORDER_PP_SEQ_SPLIT_AT_74(x) (x)ORDER_PP_SEQ_SPLIT_AT_73
#define ORDER_PP_SEQ_SPLIT_AT_75(x) (x)ORDER_PP_SEQ_SPLIT_AT_74
#define ORDER_PP_SEQ_SPLIT_AT_76(x) (x)ORDER_PP_SEQ_SPLIT_AT_75
#define ORDER_PP_SEQ_SPLIT_AT_77(x) (x)ORDER_PP_SEQ_SPLIT_AT_76
#define ORDER_PP_SEQ_SPLIT_AT_78(x) (x)ORDER_PP_SEQ_SPLIT_AT_77
#define ORDER_PP_SEQ_SPLIT_AT_79(x) (x)ORDER_PP_SEQ_SPLIT_AT_78
#define ORDER_PP_SEQ_SPLIT_AT_80(x) (x)ORDER_PP_SEQ_SPLIT_AT_79
#define ORDER_PP_SEQ_SPLIT_AT_81(x) (x)ORDER_PP_SEQ_SPLIT_AT_80
#define ORDER_PP_SEQ_SPLIT_AT_82(x) (x)ORDER_PP_SEQ_SPLIT_AT_81
#define ORDER_PP_SEQ_SPLIT_AT_83(x) (x)ORDER_PP_SEQ_SPLIT_AT_82
#define ORDER_PP_SEQ_SPLIT_AT_84(x) (x)ORDER_PP_SEQ_SPLIT_AT_83
#define ORDER_PP_SEQ_SPLIT_AT_85(x) (x)ORDER_PP_SEQ_SPLIT_AT_84
#define ORDER_PP_SEQ_SPLIT_AT_86(x) (x)ORDER_PP_SEQ_SPLIT_AT_85
#define ORDER_PP_SEQ_SPLIT_AT_87(x) (x)ORDER_PP_SEQ_SPLIT_AT_86
#define ORDER_PP_SEQ_SPLIT_AT_88(x) (x)ORDER_PP_SEQ_SPLIT_AT_87
#define ORDER_PP_SEQ_SPLIT_AT_89(x) (x)ORDER_PP_SEQ_SPLIT_AT_88
#define ORDER_PP_SEQ_SPLIT_AT_90(x) (x)ORDER_PP_SEQ_SPLIT_AT_89
#define ORDER_PP_SEQ_SPLIT_AT_91(x) (x)ORDER_PP_SEQ_SPLIT_AT_90
#define ORDER_PP_SEQ_SPLIT_AT_92(x) (x)ORDER_PP_SEQ_SPLIT_AT_91
#define ORDER_PP_SEQ_SPLIT_AT_93(x) (x)ORDER_PP_SEQ_SPLIT_AT_92
#define ORDER_PP_SEQ_SPLIT_AT_94(x) (x)ORDER_PP_SEQ_SPLIT_AT_93
#define ORDER_PP_SEQ_SPLIT_AT_95(x) (x)ORDER_PP_SEQ_SPLIT_AT_94
#define ORDER_PP_SEQ_SPLIT_AT_96(x) (x)ORDER_PP_SEQ_SPLIT_AT_95
#define ORDER_PP_SEQ_SPLIT_AT_97(x) (x)ORDER_PP_SEQ_SPLIT_AT_96
#define ORDER_PP_SEQ_SPLIT_AT_98(x) (x)ORDER_PP_SEQ_SPLIT_AT_97
#define ORDER_PP_SEQ_SPLIT_AT_99(x) (x)ORDER_PP_SEQ_SPLIT_AT_98
#define ORDER_PP_SEQ_SPLIT_AT_100(x) (x)ORDER_PP_SEQ_SPLIT_AT_99

#endif
