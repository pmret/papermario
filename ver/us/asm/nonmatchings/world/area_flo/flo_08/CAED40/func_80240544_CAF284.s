.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240544_CAF284
/* CAF284 80240544 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* CAF288 80240548 AFBF0018 */  sw        $ra, 0x18($sp)
/* CAF28C 8024054C 8C82000C */  lw        $v0, 0xc($a0)
/* CAF290 80240550 0C0B1EAF */  jal       get_variable
/* CAF294 80240554 8C450000 */   lw       $a1, ($v0)
/* CAF298 80240558 0C04417A */  jal       get_entity_by_index
/* CAF29C 8024055C 0040202D */   daddu    $a0, $v0, $zero
/* CAF2A0 80240560 3C013F80 */  lui       $at, 0x3f80
/* CAF2A4 80240564 44810000 */  mtc1      $at, $f0
/* CAF2A8 80240568 C442004C */  lwc1      $f2, 0x4c($v0)
/* CAF2AC 8024056C E7A00010 */  swc1      $f0, 0x10($sp)
/* CAF2B0 80240570 3C014148 */  lui       $at, 0x4148
/* CAF2B4 80240574 44810000 */  mtc1      $at, $f0
/* CAF2B8 80240578 2403004B */  addiu     $v1, $zero, 0x4b
/* CAF2BC 8024057C AFA30014 */  sw        $v1, 0x14($sp)
/* CAF2C0 80240580 46001080 */  add.s     $f2, $f2, $f0
/* CAF2C4 80240584 8C450048 */  lw        $a1, 0x48($v0)
/* CAF2C8 80240588 8C470050 */  lw        $a3, 0x50($v0)
/* CAF2CC 8024058C 44061000 */  mfc1      $a2, $f2
/* CAF2D0 80240590 0C01C2EC */  jal       func_80070BB0
/* CAF2D4 80240594 24040004 */   addiu    $a0, $zero, 4
/* CAF2D8 80240598 8FBF0018 */  lw        $ra, 0x18($sp)
/* CAF2DC 8024059C 24020002 */  addiu     $v0, $zero, 2
/* CAF2E0 802405A0 03E00008 */  jr        $ra
/* CAF2E4 802405A4 27BD0020 */   addiu    $sp, $sp, 0x20
