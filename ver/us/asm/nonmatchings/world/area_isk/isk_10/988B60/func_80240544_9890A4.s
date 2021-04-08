.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel isk_10_UnkFunc21
/* 9890A4 80240544 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 9890A8 80240548 AFBF0018 */  sw        $ra, 0x18($sp)
/* 9890AC 8024054C 8C82000C */  lw        $v0, 0xc($a0)
/* 9890B0 80240550 0C0B1EAF */  jal       get_variable
/* 9890B4 80240554 8C450000 */   lw       $a1, ($v0)
/* 9890B8 80240558 0C04417A */  jal       get_entity_by_index
/* 9890BC 8024055C 0040202D */   daddu    $a0, $v0, $zero
/* 9890C0 80240560 3C013F80 */  lui       $at, 0x3f80
/* 9890C4 80240564 44810000 */  mtc1      $at, $f0
/* 9890C8 80240568 C442004C */  lwc1      $f2, 0x4c($v0)
/* 9890CC 8024056C E7A00010 */  swc1      $f0, 0x10($sp)
/* 9890D0 80240570 3C014148 */  lui       $at, 0x4148
/* 9890D4 80240574 44810000 */  mtc1      $at, $f0
/* 9890D8 80240578 2403004B */  addiu     $v1, $zero, 0x4b
/* 9890DC 8024057C AFA30014 */  sw        $v1, 0x14($sp)
/* 9890E0 80240580 46001080 */  add.s     $f2, $f2, $f0
/* 9890E4 80240584 8C450048 */  lw        $a1, 0x48($v0)
/* 9890E8 80240588 8C470050 */  lw        $a3, 0x50($v0)
/* 9890EC 8024058C 44061000 */  mfc1      $a2, $f2
/* 9890F0 80240590 0C01C2EC */  jal       func_80070BB0
/* 9890F4 80240594 24040004 */   addiu    $a0, $zero, 4
/* 9890F8 80240598 8FBF0018 */  lw        $ra, 0x18($sp)
/* 9890FC 8024059C 24020002 */  addiu     $v0, $zero, 2
/* 989100 802405A0 03E00008 */  jr        $ra
/* 989104 802405A4 27BD0020 */   addiu    $sp, $sp, 0x20
