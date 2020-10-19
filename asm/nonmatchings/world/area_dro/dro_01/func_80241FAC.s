.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241FAC
/* 95D1AC 80241FAC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 95D1B0 80241FB0 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 95D1B4 80241FB4 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 95D1B8 80241FB8 3C05FE36 */  lui       $a1, 0xfe36
/* 95D1BC 80241FBC AFBF0010 */  sw        $ra, 0x10($sp)
/* 95D1C0 80241FC0 80460075 */  lb        $a2, 0x75($v0)
/* 95D1C4 80241FC4 0C0B2026 */  jal       set_variable
/* 95D1C8 80241FC8 34A53C80 */   ori      $a1, $a1, 0x3c80
/* 95D1CC 80241FCC 8FBF0010 */  lw        $ra, 0x10($sp)
/* 95D1D0 80241FD0 24020002 */  addiu     $v0, $zero, 2
/* 95D1D4 80241FD4 03E00008 */  jr        $ra
/* 95D1D8 80241FD8 27BD0018 */   addiu    $sp, $sp, 0x18
