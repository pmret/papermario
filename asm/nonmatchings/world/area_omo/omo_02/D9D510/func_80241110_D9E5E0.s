.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241110_D9E5E0
/* D9E5E0 80241110 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D9E5E4 80241114 AFB00010 */  sw        $s0, 0x10($sp)
/* D9E5E8 80241118 0080802D */  daddu     $s0, $a0, $zero
/* D9E5EC 8024111C AFBF0014 */  sw        $ra, 0x14($sp)
/* D9E5F0 80241120 8E020148 */  lw        $v0, 0x148($s0)
/* D9E5F4 80241124 0C00EABB */  jal       get_npc_unsafe
/* D9E5F8 80241128 84440008 */   lh       $a0, 8($v0)
/* D9E5FC 8024112C 0040202D */  daddu     $a0, $v0, $zero
/* D9E600 80241130 C482003C */  lwc1      $f2, 0x3c($a0)
/* D9E604 80241134 C480001C */  lwc1      $f0, 0x1c($a0)
/* D9E608 80241138 46001080 */  add.s     $f2, $f2, $f0
/* D9E60C 8024113C C4840014 */  lwc1      $f4, 0x14($a0)
/* D9E610 80241140 46040001 */  sub.s     $f0, $f0, $f4
/* D9E614 80241144 C4840064 */  lwc1      $f4, 0x64($a0)
/* D9E618 80241148 4602203C */  c.lt.s    $f4, $f2
/* D9E61C 8024114C E482003C */  swc1      $f2, 0x3c($a0)
/* D9E620 80241150 45010009 */  bc1t      .L80241178
/* D9E624 80241154 E480001C */   swc1     $f0, 0x1c($a0)
/* D9E628 80241158 8C820000 */  lw        $v0, ($a0)
/* D9E62C 8024115C 2403F7FF */  addiu     $v1, $zero, -0x801
/* D9E630 80241160 E484003C */  swc1      $f4, 0x3c($a0)
/* D9E634 80241164 AC80001C */  sw        $zero, 0x1c($a0)
/* D9E638 80241168 00431024 */  and       $v0, $v0, $v1
/* D9E63C 8024116C AC820000 */  sw        $v0, ($a0)
/* D9E640 80241170 2402000C */  addiu     $v0, $zero, 0xc
/* D9E644 80241174 AE020070 */  sw        $v0, 0x70($s0)
.L80241178:
/* D9E648 80241178 8FBF0014 */  lw        $ra, 0x14($sp)
/* D9E64C 8024117C 8FB00010 */  lw        $s0, 0x10($sp)
/* D9E650 80241180 03E00008 */  jr        $ra
/* D9E654 80241184 27BD0018 */   addiu    $sp, $sp, 0x18
