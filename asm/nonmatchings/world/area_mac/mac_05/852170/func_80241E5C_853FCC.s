.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241E5C_853FCC
/* 853FCC 80241E5C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 853FD0 80241E60 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 853FD4 80241E64 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 853FD8 80241E68 3C05FE36 */  lui       $a1, 0xfe36
/* 853FDC 80241E6C AFBF0010 */  sw        $ra, 0x10($sp)
/* 853FE0 80241E70 80460075 */  lb        $a2, 0x75($v0)
/* 853FE4 80241E74 0C0B2026 */  jal       set_variable
/* 853FE8 80241E78 34A53C80 */   ori      $a1, $a1, 0x3c80
/* 853FEC 80241E7C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 853FF0 80241E80 24020002 */  addiu     $v0, $zero, 2
/* 853FF4 80241E84 03E00008 */  jr        $ra
/* 853FF8 80241E88 27BD0018 */   addiu    $sp, $sp, 0x18
