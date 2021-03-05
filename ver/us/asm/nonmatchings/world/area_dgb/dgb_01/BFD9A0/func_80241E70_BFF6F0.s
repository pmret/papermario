.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241E70_BFF6F0
/* BFF6F0 80241E70 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* BFF6F4 80241E74 AFB00010 */  sw        $s0, 0x10($sp)
/* BFF6F8 80241E78 0080802D */  daddu     $s0, $a0, $zero
/* BFF6FC 80241E7C AFBF0014 */  sw        $ra, 0x14($sp)
/* BFF700 80241E80 8E020148 */  lw        $v0, 0x148($s0)
/* BFF704 80241E84 0C00EABB */  jal       get_npc_unsafe
/* BFF708 80241E88 84440008 */   lh       $a0, 8($v0)
/* BFF70C 80241E8C 0040202D */  daddu     $a0, $v0, $zero
/* BFF710 80241E90 9482008E */  lhu       $v0, 0x8e($a0)
/* BFF714 80241E94 24420001 */  addiu     $v0, $v0, 1
/* BFF718 80241E98 A482008E */  sh        $v0, 0x8e($a0)
/* BFF71C 80241E9C 00021400 */  sll       $v0, $v0, 0x10
/* BFF720 80241EA0 00021403 */  sra       $v0, $v0, 0x10
/* BFF724 80241EA4 28420003 */  slti      $v0, $v0, 3
/* BFF728 80241EA8 1440000D */  bnez      $v0, .L80241EE0
/* BFF72C 80241EAC 24020009 */   addiu    $v0, $zero, 9
/* BFF730 80241EB0 3C038011 */  lui       $v1, %hi(D_8010EBB0+0x3)
/* BFF734 80241EB4 8063EBB3 */  lb        $v1, %lo(D_8010EBB0+0x3)($v1)
/* BFF738 80241EB8 10620003 */  beq       $v1, $v0, .L80241EC8
/* BFF73C 80241EBC 24020064 */   addiu    $v0, $zero, 0x64
/* BFF740 80241EC0 080907B7 */  j         .L80241EDC
/* BFF744 80241EC4 A480008E */   sh       $zero, 0x8e($a0)
.L80241EC8:
/* BFF748 80241EC8 0C038069 */  jal       enable_player_input
/* BFF74C 80241ECC 00000000 */   nop
/* BFF750 80241ED0 0C03BD80 */  jal       func_800EF600
/* BFF754 80241ED4 00000000 */   nop
/* BFF758 80241ED8 24020010 */  addiu     $v0, $zero, 0x10
.L80241EDC:
/* BFF75C 80241EDC AE020070 */  sw        $v0, 0x70($s0)
.L80241EE0:
/* BFF760 80241EE0 8FBF0014 */  lw        $ra, 0x14($sp)
/* BFF764 80241EE4 8FB00010 */  lw        $s0, 0x10($sp)
/* BFF768 80241EE8 03E00008 */  jr        $ra
/* BFF76C 80241EEC 27BD0018 */   addiu    $sp, $sp, 0x18
