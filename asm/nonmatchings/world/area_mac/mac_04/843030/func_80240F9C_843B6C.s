.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240F9C_843B6C
/* 843B6C 80240F9C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 843B70 80240FA0 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 843B74 80240FA4 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 843B78 80240FA8 3C05FE36 */  lui       $a1, 0xfe36
/* 843B7C 80240FAC AFBF0010 */  sw        $ra, 0x10($sp)
/* 843B80 80240FB0 80460075 */  lb        $a2, 0x75($v0)
/* 843B84 80240FB4 0C0B2026 */  jal       set_variable
/* 843B88 80240FB8 34A53C80 */   ori      $a1, $a1, 0x3c80
/* 843B8C 80240FBC 8FBF0010 */  lw        $ra, 0x10($sp)
/* 843B90 80240FC0 24020002 */  addiu     $v0, $zero, 2
/* 843B94 80240FC4 03E00008 */  jr        $ra
/* 843B98 80240FC8 27BD0018 */   addiu    $sp, $sp, 0x18
