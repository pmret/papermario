.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242A4C_8032CC
/* 8032CC 80242A4C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8032D0 80242A50 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 8032D4 80242A54 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 8032D8 80242A58 3C05FE36 */  lui       $a1, 0xfe36
/* 8032DC 80242A5C AFBF0010 */  sw        $ra, 0x10($sp)
/* 8032E0 80242A60 80460075 */  lb        $a2, 0x75($v0)
/* 8032E4 80242A64 0C0B2026 */  jal       set_variable
/* 8032E8 80242A68 34A53C80 */   ori      $a1, $a1, 0x3c80
/* 8032EC 80242A6C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 8032F0 80242A70 24020002 */  addiu     $v0, $zero, 2
/* 8032F4 80242A74 03E00008 */  jr        $ra
/* 8032F8 80242A78 27BD0018 */   addiu    $sp, $sp, 0x18
