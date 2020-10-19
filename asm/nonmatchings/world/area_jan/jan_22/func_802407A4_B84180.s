.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802407A4_B84924
/* B84924 802407A4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B84928 802407A8 AFB00010 */  sw        $s0, 0x10($sp)
/* B8492C 802407AC 0080802D */  daddu     $s0, $a0, $zero
/* B84930 802407B0 AFBF0014 */  sw        $ra, 0x14($sp)
/* B84934 802407B4 8E020148 */  lw        $v0, 0x148($s0)
/* B84938 802407B8 0C00EABB */  jal       get_npc_unsafe
/* B8493C 802407BC 84440008 */   lh       $a0, 8($v0)
/* B84940 802407C0 0040202D */  daddu     $a0, $v0, $zero
/* B84944 802407C4 C482003C */  lwc1      $f2, 0x3c($a0)
/* B84948 802407C8 C480001C */  lwc1      $f0, 0x1c($a0)
/* B8494C 802407CC 46001080 */  add.s     $f2, $f2, $f0
/* B84950 802407D0 C4840014 */  lwc1      $f4, 0x14($a0)
/* B84954 802407D4 46040001 */  sub.s     $f0, $f0, $f4
/* B84958 802407D8 C4840064 */  lwc1      $f4, 0x64($a0)
/* B8495C 802407DC 4602203C */  c.lt.s    $f4, $f2
/* B84960 802407E0 E482003C */  swc1      $f2, 0x3c($a0)
/* B84964 802407E4 45010009 */  bc1t      .L8024080C
/* B84968 802407E8 E480001C */   swc1     $f0, 0x1c($a0)
/* B8496C 802407EC 8C820000 */  lw        $v0, ($a0)
/* B84970 802407F0 2403F7FF */  addiu     $v1, $zero, -0x801
/* B84974 802407F4 E484003C */  swc1      $f4, 0x3c($a0)
/* B84978 802407F8 AC80001C */  sw        $zero, 0x1c($a0)
/* B8497C 802407FC 00431024 */  and       $v0, $v0, $v1
/* B84980 80240800 AC820000 */  sw        $v0, ($a0)
/* B84984 80240804 2402000C */  addiu     $v0, $zero, 0xc
/* B84988 80240808 AE020070 */  sw        $v0, 0x70($s0)
.L8024080C:
/* B8498C 8024080C 8FBF0014 */  lw        $ra, 0x14($sp)
/* B84990 80240810 8FB00010 */  lw        $s0, 0x10($sp)
/* B84994 80240814 03E00008 */  jr        $ra
/* B84998 80240818 27BD0018 */   addiu    $sp, $sp, 0x18
