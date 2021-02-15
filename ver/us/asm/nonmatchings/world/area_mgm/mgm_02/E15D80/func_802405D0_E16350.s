.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802405D0_E16350
/* E16350 802405D0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* E16354 802405D4 0000202D */  daddu     $a0, $zero, $zero
/* E16358 802405D8 AFBF002C */  sw        $ra, 0x2c($sp)
/* E1635C 802405DC 0C00FB3A */  jal       get_enemy
/* E16360 802405E0 AFB00028 */   sw       $s0, 0x28($sp)
/* E16364 802405E4 3C04802F */  lui       $a0, %hi(D_802EAFDC)
/* E16368 802405E8 2484AFDC */  addiu     $a0, $a0, %lo(D_802EAFDC)
/* E1636C 802405EC 8C50006C */  lw        $s0, 0x6c($v0)
/* E16370 802405F0 3C028000 */  lui       $v0, 0x8000
/* E16374 802405F4 24050163 */  addiu     $a1, $zero, 0x163
/* E16378 802405F8 24060014 */  addiu     $a2, $zero, 0x14
/* E1637C 802405FC 2407FF4C */  addiu     $a3, $zero, -0xb4
/* E16380 80240600 AFA00010 */  sw        $zero, 0x10($sp)
/* E16384 80240604 AFA00014 */  sw        $zero, 0x14($sp)
/* E16388 80240608 AFA00018 */  sw        $zero, 0x18($sp)
/* E1638C 8024060C AFA0001C */  sw        $zero, 0x1c($sp)
/* E16390 80240610 0C044631 */  jal       create_entity
/* E16394 80240614 AFA20020 */   sw       $v0, 0x20($sp)
/* E16398 80240618 0040202D */  daddu     $a0, $v0, $zero
/* E1639C 8024061C 0C04417A */  jal       get_entity_by_index
/* E163A0 80240620 AE04001C */   sw       $a0, 0x1c($s0)
/* E163A4 80240624 3C038024 */  lui       $v1, %hi(D_80242A3C_E187BC)
/* E163A8 80240628 24632A3C */  addiu     $v1, $v1, %lo(D_80242A3C_E187BC)
/* E163AC 8024062C AC430028 */  sw        $v1, 0x28($v0)
/* E163B0 80240630 8FBF002C */  lw        $ra, 0x2c($sp)
/* E163B4 80240634 8FB00028 */  lw        $s0, 0x28($sp)
/* E163B8 80240638 24020002 */  addiu     $v0, $zero, 2
/* E163BC 8024063C 03E00008 */  jr        $ra
/* E163C0 80240640 27BD0030 */   addiu    $sp, $sp, 0x30
