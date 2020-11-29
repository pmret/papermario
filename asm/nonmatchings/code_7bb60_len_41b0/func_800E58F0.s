.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800E58F0
/* 7EDA0 800E58F0 3C018011 */  lui       $at, %hi(D_8010C944)
/* 7EDA4 800E58F4 AC20C944 */  sw        $zero, %lo(D_8010C944)($at)
/* 7EDA8 800E58F8 0000282D */  daddu     $a1, $zero, $zero
/* 7EDAC 800E58FC 240700B4 */  addiu     $a3, $zero, 0xb4
/* 7EDB0 800E5900 3C068000 */  lui       $a2, 0x8000
/* 7EDB4 800E5904 3C048011 */  lui       $a0, %hi(D_8010EF10)
/* 7EDB8 800E5908 2484EF10 */  addiu     $a0, $a0, %lo(D_8010EF10)
/* 7EDBC 800E590C 3C038011 */  lui       $v1, %hi(D_8010F6B8)
/* 7EDC0 800E5910 2463F6B8 */  addiu     $v1, $v1, %lo(D_8010F6B8)
.L800E5914:
/* 7EDC4 800E5914 A4670000 */  sh        $a3, ($v1)
/* 7EDC8 800E5918 AC860000 */  sw        $a2, ($a0)
/* 7EDCC 800E591C 24840004 */  addiu     $a0, $a0, 4
/* 7EDD0 800E5920 24A50001 */  addiu     $a1, $a1, 1
/* 7EDD4 800E5924 28A20005 */  slti      $v0, $a1, 5
/* 7EDD8 800E5928 1440FFFA */  bnez      $v0, .L800E5914
/* 7EDDC 800E592C 24630002 */   addiu    $v1, $v1, 2
/* 7EDE0 800E5930 03E00008 */  jr        $ra
/* 7EDE4 800E5934 00000000 */   nop      
