.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240544_D301C4
/* D301C4 80240544 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D301C8 80240548 AFBF0018 */  sw        $ra, 0x18($sp)
/* D301CC 8024054C 8C82000C */  lw        $v0, 0xc($a0)
/* D301D0 80240550 0C0B1EAF */  jal       get_variable
/* D301D4 80240554 8C450000 */   lw       $a1, ($v0)
/* D301D8 80240558 0C04417A */  jal       get_entity_by_index
/* D301DC 8024055C 0040202D */   daddu    $a0, $v0, $zero
/* D301E0 80240560 3C013F80 */  lui       $at, 0x3f80
/* D301E4 80240564 44810000 */  mtc1      $at, $f0
/* D301E8 80240568 C442004C */  lwc1      $f2, 0x4c($v0)
/* D301EC 8024056C E7A00010 */  swc1      $f0, 0x10($sp)
/* D301F0 80240570 3C014148 */  lui       $at, 0x4148
/* D301F4 80240574 44810000 */  mtc1      $at, $f0
/* D301F8 80240578 2403004B */  addiu     $v1, $zero, 0x4b
/* D301FC 8024057C AFA30014 */  sw        $v1, 0x14($sp)
/* D30200 80240580 46001080 */  add.s     $f2, $f2, $f0
/* D30204 80240584 8C450048 */  lw        $a1, 0x48($v0)
/* D30208 80240588 8C470050 */  lw        $a3, 0x50($v0)
/* D3020C 8024058C 44061000 */  mfc1      $a2, $f2
/* D30210 80240590 0C01C2EC */  jal       func_80070BB0
/* D30214 80240594 24040004 */   addiu    $a0, $zero, 4
/* D30218 80240598 8FBF0018 */  lw        $ra, 0x18($sp)
/* D3021C 8024059C 24020002 */  addiu     $v0, $zero, 2
/* D30220 802405A0 03E00008 */  jr        $ra
/* D30224 802405A4 27BD0020 */   addiu    $sp, $sp, 0x20
