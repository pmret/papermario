.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80259A48
/* 188328 80259A48 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 18832C 80259A4C 0080402D */  daddu     $t0, $a0, $zero
/* 188330 80259A50 00A0202D */  daddu     $a0, $a1, $zero
/* 188334 80259A54 AFBF0010 */  sw        $ra, 0x10($sp)
/* 188338 80259A58 8C8300C0 */  lw        $v1, 0xc0($a0)
/* 18833C 80259A5C 00C0282D */  daddu     $a1, $a2, $zero
/* 188340 80259A60 806206C1 */  lb        $v0, 0x6c1($v1)
/* 188344 80259A64 10400006 */  beqz      $v0, .L80259A80
/* 188348 80259A68 00E0302D */   daddu    $a2, $a3, $zero
/* 18834C 80259A6C 24020001 */  addiu     $v0, $zero, 1
/* 188350 80259A70 A0820074 */  sb        $v0, 0x74($a0)
/* 188354 80259A74 A4800068 */  sh        $zero, 0x68($a0)
/* 188358 80259A78 A480006A */  sh        $zero, 0x6a($a0)
/* 18835C 80259A7C A06006C1 */  sb        $zero, 0x6c1($v1)
.L80259A80:
/* 188360 80259A80 15000005 */  bnez      $t0, .L80259A98
/* 188364 80259A84 00000000 */   nop      
/* 188368 80259A88 0C0965EC */  jal       func_802597B0
/* 18836C 80259A8C 00000000 */   nop      
/* 188370 80259A90 080966A8 */  j         .L80259AA0
/* 188374 80259A94 00000000 */   nop      
.L80259A98:
/* 188378 80259A98 0C096543 */  jal       func_8025950C
/* 18837C 80259A9C 00000000 */   nop      
.L80259AA0:
/* 188380 80259AA0 8FBF0010 */  lw        $ra, 0x10($sp)
/* 188384 80259AA4 03E00008 */  jr        $ra
/* 188388 80259AA8 27BD0018 */   addiu    $sp, $sp, 0x18
