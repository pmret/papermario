.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_800E0208
/* 0796B8 800E0208 3C038007 */  lui   $v1, 0x8007
/* 0796BC 800E020C 8C63419C */  lw    $v1, 0x419c($v1)
/* 0796C0 800E0210 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0796C4 800E0214 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0796C8 800E0218 80620078 */  lb    $v0, 0x78($v1)
/* 0796CC 800E021C 1040000C */  beqz  $v0, .L800E0250
/* 0796D0 800E0220 0000202D */   daddu $a0, $zero, $zero
/* 0796D4 800E0224 8C620000 */  lw    $v0, ($v1)
/* 0796D8 800E0228 30420010 */  andi  $v0, $v0, 0x10
/* 0796DC 800E022C 10400008 */  beqz  $v0, .L800E0250
/* 0796E0 800E0230 00000000 */   nop   
/* 0796E4 800E0234 3C028011 */  lui   $v0, 0x8011
/* 0796E8 800E0238 8042EBB0 */  lb    $v0, -0x1450($v0)
/* 0796EC 800E023C 54400004 */  bnezl $v0, .L800E0250
/* 0796F0 800E0240 24040001 */   addiu $a0, $zero, 1
/* 0796F4 800E0244 0C039769 */  jal   set_action_state
/* 0796F8 800E0248 00000000 */   nop   
/* 0796FC 800E024C 24040001 */  addiu $a0, $zero, 1
.L800E0250:
/* 079700 800E0250 8FBF0010 */  lw    $ra, 0x10($sp)
/* 079704 800E0254 0080102D */  daddu $v0, $a0, $zero
/* 079708 800E0258 03E00008 */  jr    $ra
/* 07970C 800E025C 27BD0018 */   addiu $sp, $sp, 0x18

