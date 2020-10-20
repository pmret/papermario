.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240544_C77224
/* C77224 80240544 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C77228 80240548 AFBF0018 */  sw        $ra, 0x18($sp)
/* C7722C 8024054C 8C82000C */  lw        $v0, 0xc($a0)
/* C77230 80240550 0C0B1EAF */  jal       get_variable
/* C77234 80240554 8C450000 */   lw       $a1, ($v0)
/* C77238 80240558 0C04417A */  jal       get_entity_by_index
/* C7723C 8024055C 0040202D */   daddu    $a0, $v0, $zero
/* C77240 80240560 3C013F80 */  lui       $at, 0x3f80
/* C77244 80240564 44810000 */  mtc1      $at, $f0
/* C77248 80240568 C442004C */  lwc1      $f2, 0x4c($v0)
/* C7724C 8024056C E7A00010 */  swc1      $f0, 0x10($sp)
/* C77250 80240570 3C014148 */  lui       $at, 0x4148
/* C77254 80240574 44810000 */  mtc1      $at, $f0
/* C77258 80240578 2403004B */  addiu     $v1, $zero, 0x4b
/* C7725C 8024057C AFA30014 */  sw        $v1, 0x14($sp)
/* C77260 80240580 46001080 */  add.s     $f2, $f2, $f0
/* C77264 80240584 8C450048 */  lw        $a1, 0x48($v0)
/* C77268 80240588 8C470050 */  lw        $a3, 0x50($v0)
/* C7726C 8024058C 44061000 */  mfc1      $a2, $f2
/* C77270 80240590 0C01C2EC */  jal       func_80070BB0
/* C77274 80240594 24040004 */   addiu    $a0, $zero, 4
/* C77278 80240598 8FBF0018 */  lw        $ra, 0x18($sp)
/* C7727C 8024059C 24020002 */  addiu     $v0, $zero, 2
/* C77280 802405A0 03E00008 */  jr        $ra
/* C77284 802405A4 27BD0020 */   addiu    $sp, $sp, 0x20
