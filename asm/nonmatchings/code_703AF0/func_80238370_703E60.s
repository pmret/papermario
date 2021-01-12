.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80238370_703E60
/* 703E60 80238370 3C048024 */  lui       $a0, %hi(D_8023C1CC)
/* 703E64 80238374 8C84C1CC */  lw        $a0, %lo(D_8023C1CC)($a0)
/* 703E68 80238378 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 703E6C 8023837C AFBF0010 */  sw        $ra, 0x10($sp)
/* 703E70 80238380 3C018024 */  lui       $at, %hi(D_8023C1B8)
/* 703E74 80238384 AC20C1B8 */  sw        $zero, %lo(D_8023C1B8)($at)
/* 703E78 80238388 10800003 */  beqz      $a0, .L80238398
/* 703E7C 8023838C 00000000 */   nop
/* 703E80 80238390 0C016914 */  jal       remove_effect
/* 703E84 80238394 00000000 */   nop
.L80238398:
/* 703E88 80238398 3C048024 */  lui       $a0, %hi(D_8023C1D0)
/* 703E8C 8023839C 8C84C1D0 */  lw        $a0, %lo(D_8023C1D0)($a0)
/* 703E90 802383A0 10800003 */  beqz      $a0, .L802383B0
/* 703E94 802383A4 00000000 */   nop
/* 703E98 802383A8 0C016914 */  jal       remove_effect
/* 703E9C 802383AC 00000000 */   nop
.L802383B0:
/* 703EA0 802383B0 8FBF0010 */  lw        $ra, 0x10($sp)
/* 703EA4 802383B4 24020002 */  addiu     $v0, $zero, 2
/* 703EA8 802383B8 03E00008 */  jr        $ra
/* 703EAC 802383BC 27BD0018 */   addiu    $sp, $sp, 0x18
