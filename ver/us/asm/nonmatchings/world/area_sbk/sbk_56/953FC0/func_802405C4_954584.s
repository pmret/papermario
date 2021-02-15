.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802405C4_954584
/* 954584 802405C4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 954588 802405C8 AFBF0018 */  sw        $ra, 0x18($sp)
/* 95458C 802405CC 8C82000C */  lw        $v0, 0xc($a0)
/* 954590 802405D0 0C0B1EAF */  jal       get_variable
/* 954594 802405D4 8C450000 */   lw       $a1, ($v0)
/* 954598 802405D8 0C04417A */  jal       get_entity_by_index
/* 95459C 802405DC 0040202D */   daddu    $a0, $v0, $zero
/* 9545A0 802405E0 3C013F80 */  lui       $at, 0x3f80
/* 9545A4 802405E4 44810000 */  mtc1      $at, $f0
/* 9545A8 802405E8 C442004C */  lwc1      $f2, 0x4c($v0)
/* 9545AC 802405EC E7A00010 */  swc1      $f0, 0x10($sp)
/* 9545B0 802405F0 3C014148 */  lui       $at, 0x4148
/* 9545B4 802405F4 44810000 */  mtc1      $at, $f0
/* 9545B8 802405F8 2403004B */  addiu     $v1, $zero, 0x4b
/* 9545BC 802405FC AFA30014 */  sw        $v1, 0x14($sp)
/* 9545C0 80240600 46001080 */  add.s     $f2, $f2, $f0
/* 9545C4 80240604 8C450048 */  lw        $a1, 0x48($v0)
/* 9545C8 80240608 8C470050 */  lw        $a3, 0x50($v0)
/* 9545CC 8024060C 44061000 */  mfc1      $a2, $f2
/* 9545D0 80240610 0C01C2EC */  jal       func_80070BB0
/* 9545D4 80240614 24040004 */   addiu    $a0, $zero, 4
/* 9545D8 80240618 8FBF0018 */  lw        $ra, 0x18($sp)
/* 9545DC 8024061C 24020002 */  addiu     $v0, $zero, 2
/* 9545E0 80240620 03E00008 */  jr        $ra
/* 9545E4 80240624 27BD0020 */   addiu    $sp, $sp, 0x20
