.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242150_B2E5C0
/* B2E5C0 80242150 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B2E5C4 80242154 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* B2E5C8 80242158 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* B2E5CC 8024215C 3C05FE36 */  lui       $a1, 0xfe36
/* B2E5D0 80242160 AFBF0010 */  sw        $ra, 0x10($sp)
/* B2E5D4 80242164 80460075 */  lb        $a2, 0x75($v0)
/* B2E5D8 80242168 0C0B2026 */  jal       set_variable
/* B2E5DC 8024216C 34A53C80 */   ori      $a1, $a1, 0x3c80
/* B2E5E0 80242170 8FBF0010 */  lw        $ra, 0x10($sp)
/* B2E5E4 80242174 24020002 */  addiu     $v0, $zero, 2
/* B2E5E8 80242178 03E00008 */  jr        $ra
/* B2E5EC 8024217C 27BD0018 */   addiu    $sp, $sp, 0x18
