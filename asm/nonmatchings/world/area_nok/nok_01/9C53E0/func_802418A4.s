.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802418A4
/* 9C6C84 802418A4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 9C6C88 802418A8 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 9C6C8C 802418AC 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 9C6C90 802418B0 3C05FE36 */  lui       $a1, 0xfe36
/* 9C6C94 802418B4 AFBF0010 */  sw        $ra, 0x10($sp)
/* 9C6C98 802418B8 80460075 */  lb        $a2, 0x75($v0)
/* 9C6C9C 802418BC 0C0B2026 */  jal       set_variable
/* 9C6CA0 802418C0 34A53C80 */   ori      $a1, $a1, 0x3c80
/* 9C6CA4 802418C4 8FBF0010 */  lw        $ra, 0x10($sp)
/* 9C6CA8 802418C8 24020002 */  addiu     $v0, $zero, 2
/* 9C6CAC 802418CC 03E00008 */  jr        $ra
/* 9C6CB0 802418D0 27BD0018 */   addiu    $sp, $sp, 0x18
