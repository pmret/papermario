.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel AddBattleCamZoom
/* 17D58C 8024ECAC 3C028028 */  lui       $v0, %hi(D_80280CE0)
/* 17D590 8024ECB0 80420CE0 */  lb        $v0, %lo(D_80280CE0)($v0)
/* 17D594 8024ECB4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 17D598 8024ECB8 AFBF0010 */  sw        $ra, 0x10($sp)
/* 17D59C 8024ECBC 8C85000C */  lw        $a1, 0xc($a0)
/* 17D5A0 8024ECC0 1440000A */  bnez      $v0, .L8024ECEC
/* 17D5A4 8024ECC4 24020002 */   addiu    $v0, $zero, 2
/* 17D5A8 8024ECC8 8CA50000 */  lw        $a1, ($a1)
/* 17D5AC 8024ECCC 0C0B1EAF */  jal       get_variable
/* 17D5B0 8024ECD0 00000000 */   nop
/* 17D5B4 8024ECD4 3C04802A */  lui       $a0, %hi(D_8029F280)
/* 17D5B8 8024ECD8 2484F280 */  addiu     $a0, $a0, %lo(D_8029F280)
/* 17D5BC 8024ECDC 94830000 */  lhu       $v1, ($a0)
/* 17D5C0 8024ECE0 00621821 */  addu      $v1, $v1, $v0
/* 17D5C4 8024ECE4 24020002 */  addiu     $v0, $zero, 2
/* 17D5C8 8024ECE8 A4830000 */  sh        $v1, ($a0)
.L8024ECEC:
/* 17D5CC 8024ECEC 8FBF0010 */  lw        $ra, 0x10($sp)
/* 17D5D0 8024ECF0 03E00008 */  jr        $ra
/* 17D5D4 8024ECF4 27BD0018 */   addiu    $sp, $sp, 0x18
