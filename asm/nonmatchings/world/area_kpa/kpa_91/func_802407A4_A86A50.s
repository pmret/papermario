.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802407A4_A871F4
/* A871F4 802407A4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A871F8 802407A8 AFB00010 */  sw        $s0, 0x10($sp)
/* A871FC 802407AC 0080802D */  daddu     $s0, $a0, $zero
/* A87200 802407B0 AFBF0014 */  sw        $ra, 0x14($sp)
/* A87204 802407B4 8E020148 */  lw        $v0, 0x148($s0)
/* A87208 802407B8 0C00EABB */  jal       get_npc_unsafe
/* A8720C 802407BC 84440008 */   lh       $a0, 8($v0)
/* A87210 802407C0 0040202D */  daddu     $a0, $v0, $zero
/* A87214 802407C4 C482003C */  lwc1      $f2, 0x3c($a0)
/* A87218 802407C8 C480001C */  lwc1      $f0, 0x1c($a0)
/* A8721C 802407CC 46001080 */  add.s     $f2, $f2, $f0
/* A87220 802407D0 C4840014 */  lwc1      $f4, 0x14($a0)
/* A87224 802407D4 46040001 */  sub.s     $f0, $f0, $f4
/* A87228 802407D8 C4840064 */  lwc1      $f4, 0x64($a0)
/* A8722C 802407DC 4602203C */  c.lt.s    $f4, $f2
/* A87230 802407E0 E482003C */  swc1      $f2, 0x3c($a0)
/* A87234 802407E4 45010009 */  bc1t      .L8024080C
/* A87238 802407E8 E480001C */   swc1     $f0, 0x1c($a0)
/* A8723C 802407EC 8C820000 */  lw        $v0, ($a0)
/* A87240 802407F0 2403F7FF */  addiu     $v1, $zero, -0x801
/* A87244 802407F4 E484003C */  swc1      $f4, 0x3c($a0)
/* A87248 802407F8 AC80001C */  sw        $zero, 0x1c($a0)
/* A8724C 802407FC 00431024 */  and       $v0, $v0, $v1
/* A87250 80240800 AC820000 */  sw        $v0, ($a0)
/* A87254 80240804 2402000C */  addiu     $v0, $zero, 0xc
/* A87258 80240808 AE020070 */  sw        $v0, 0x70($s0)
.L8024080C:
/* A8725C 8024080C 8FBF0014 */  lw        $ra, 0x14($sp)
/* A87260 80240810 8FB00010 */  lw        $s0, 0x10($sp)
/* A87264 80240814 03E00008 */  jr        $ra
/* A87268 80240818 27BD0018 */   addiu    $sp, $sp, 0x18
