.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004D01C
/* 2841C 8004D01C 8CA60000 */  lw        $a2, ($a1)
/* 28420 8004D020 90C20000 */  lbu       $v0, ($a2)
/* 28424 8004D024 90C30001 */  lbu       $v1, 1($a2)
/* 28428 8004D028 00021200 */  sll       $v0, $v0, 8
/* 2842C 8004D02C 00431821 */  addu      $v1, $v0, $v1
/* 28430 8004D030 50600004 */  beql      $v1, $zero, .L8004D044
/* 28434 8004D034 ACA00018 */   sw       $zero, 0x18($a1)
/* 28438 8004D038 8C820008 */  lw        $v0, 8($a0)
/* 2843C 8004D03C 00621021 */  addu      $v0, $v1, $v0
/* 28440 8004D040 ACA20018 */  sw        $v0, 0x18($a1)
.L8004D044:
/* 28444 8004D044 24C20002 */  addiu     $v0, $a2, 2
/* 28448 8004D048 03E00008 */  jr        $ra
/* 2844C 8004D04C ACA20000 */   sw       $v0, ($a1)
