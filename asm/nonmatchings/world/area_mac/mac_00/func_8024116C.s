.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024116C
/* 7EBE7C 8024116C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 7EBE80 80241170 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 7EBE84 80241174 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 7EBE88 80241178 3C05FE36 */  lui       $a1, 0xfe36
/* 7EBE8C 8024117C AFBF0010 */  sw        $ra, 0x10($sp)
/* 7EBE90 80241180 80460075 */  lb        $a2, 0x75($v0)
/* 7EBE94 80241184 0C0B2026 */  jal       set_variable
/* 7EBE98 80241188 34A53C80 */   ori      $a1, $a1, 0x3c80
/* 7EBE9C 8024118C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 7EBEA0 80241190 24020002 */  addiu     $v0, $zero, 2
/* 7EBEA4 80241194 03E00008 */  jr        $ra
/* 7EBEA8 80241198 27BD0018 */   addiu    $sp, $sp, 0x18
