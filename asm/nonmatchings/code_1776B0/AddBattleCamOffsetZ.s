.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel AddBattleCamOffsetZ
/* 17D378 8024EA98 3C028028 */  lui       $v0, %hi(D_80280CE0)
/* 17D37C 8024EA9C 80420CE0 */  lb        $v0, %lo(D_80280CE0)($v0)
/* 17D380 8024EAA0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 17D384 8024EAA4 AFBF0010 */  sw        $ra, 0x10($sp)
/* 17D388 8024EAA8 8C85000C */  lw        $a1, 0xc($a0)
/* 17D38C 8024EAAC 1440000A */  bnez      $v0, .L8024EAD8
/* 17D390 8024EAB0 24020002 */   addiu    $v0, $zero, 2
/* 17D394 8024EAB4 8CA50000 */  lw        $a1, ($a1)
/* 17D398 8024EAB8 0C0B1EAF */  jal       get_variable
/* 17D39C 8024EABC 00000000 */   nop      
/* 17D3A0 8024EAC0 3C04802A */  lui       $a0, %hi(D_8029F286)
/* 17D3A4 8024EAC4 2484F286 */  addiu     $a0, $a0, %lo(D_8029F286)
/* 17D3A8 8024EAC8 94830000 */  lhu       $v1, ($a0)
/* 17D3AC 8024EACC 00621821 */  addu      $v1, $v1, $v0
/* 17D3B0 8024EAD0 24020002 */  addiu     $v0, $zero, 2
/* 17D3B4 8024EAD4 A4830000 */  sh        $v1, ($a0)
.L8024EAD8:
/* 17D3B8 8024EAD8 8FBF0010 */  lw        $ra, 0x10($sp)
/* 17D3BC 8024EADC 03E00008 */  jr        $ra
/* 17D3C0 8024EAE0 27BD0018 */   addiu    $sp, $sp, 0x18
