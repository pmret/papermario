.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024268C_B4D0FC
/* B4D0FC 8024268C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B4D100 80242690 AFB00010 */  sw        $s0, 0x10($sp)
/* B4D104 80242694 0080802D */  daddu     $s0, $a0, $zero
/* B4D108 80242698 AFBF0014 */  sw        $ra, 0x14($sp)
/* B4D10C 8024269C 0C00FB5A */  jal       get_enemy_safe
/* B4D110 802426A0 0000202D */   daddu    $a0, $zero, $zero
/* B4D114 802426A4 14400003 */  bnez      $v0, .L802426B4
/* B4D118 802426A8 24020001 */   addiu    $v0, $zero, 1
/* B4D11C 802426AC 080909AE */  j         .L802426B8
/* B4D120 802426B0 AE000084 */   sw       $zero, 0x84($s0)
.L802426B4:
/* B4D124 802426B4 AE020084 */  sw        $v0, 0x84($s0)
.L802426B8:
/* B4D128 802426B8 8FBF0014 */  lw        $ra, 0x14($sp)
/* B4D12C 802426BC 8FB00010 */  lw        $s0, 0x10($sp)
/* B4D130 802426C0 24020002 */  addiu     $v0, $zero, 2
/* B4D134 802426C4 03E00008 */  jr        $ra
/* B4D138 802426C8 27BD0018 */   addiu    $sp, $sp, 0x18
/* B4D13C 802426CC 00000000 */  nop       
