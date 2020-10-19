.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240FB0
/* 91F520 80240FB0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 91F524 80240FB4 AFBF0018 */  sw        $ra, 0x18($sp)
/* 91F528 80240FB8 0C00EAD2 */  jal       get_npc_safe
/* 91F52C 80240FBC 2404FFFC */   addiu    $a0, $zero, -4
/* 91F530 80240FC0 3C0141F0 */  lui       $at, 0x41f0
/* 91F534 80240FC4 44810000 */  mtc1      $at, $f0
/* 91F538 80240FC8 C442003C */  lwc1      $f2, 0x3c($v0)
/* 91F53C 80240FCC 46001080 */  add.s     $f2, $f2, $f0
/* 91F540 80240FD0 E7A00010 */  swc1      $f0, 0x10($sp)
/* 91F544 80240FD4 8C450038 */  lw        $a1, 0x38($v0)
/* 91F548 80240FD8 8C470040 */  lw        $a3, 0x40($v0)
/* 91F54C 80240FDC 44061000 */  mfc1      $a2, $f2
/* 91F550 80240FE0 0C01BFBC */  jal       func_8006FEF0
/* 91F554 80240FE4 24040004 */   addiu    $a0, $zero, 4
/* 91F558 80240FE8 8FBF0018 */  lw        $ra, 0x18($sp)
/* 91F55C 80240FEC 24020002 */  addiu     $v0, $zero, 2
/* 91F560 80240FF0 03E00008 */  jr        $ra
/* 91F564 80240FF4 27BD0020 */   addiu    $sp, $sp, 0x20
