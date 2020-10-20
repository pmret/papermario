.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241074
/* C50584 80241074 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C50588 80241078 AFB00010 */  sw        $s0, 0x10($sp)
/* C5058C 8024107C 0080802D */  daddu     $s0, $a0, $zero
/* C50590 80241080 AFBF0014 */  sw        $ra, 0x14($sp)
/* C50594 80241084 8E020148 */  lw        $v0, 0x148($s0)
/* C50598 80241088 0C00EABB */  jal       get_npc_unsafe
/* C5059C 8024108C 84440008 */   lh       $a0, 8($v0)
/* C505A0 80241090 0040202D */  daddu     $a0, $v0, $zero
/* C505A4 80241094 C482003C */  lwc1      $f2, 0x3c($a0)
/* C505A8 80241098 C480001C */  lwc1      $f0, 0x1c($a0)
/* C505AC 8024109C 46001080 */  add.s     $f2, $f2, $f0
/* C505B0 802410A0 C4840014 */  lwc1      $f4, 0x14($a0)
/* C505B4 802410A4 46040001 */  sub.s     $f0, $f0, $f4
/* C505B8 802410A8 C4840064 */  lwc1      $f4, 0x64($a0)
/* C505BC 802410AC 4602203C */  c.lt.s    $f4, $f2
/* C505C0 802410B0 E482003C */  swc1      $f2, 0x3c($a0)
/* C505C4 802410B4 45010009 */  bc1t      .L802410DC
/* C505C8 802410B8 E480001C */   swc1     $f0, 0x1c($a0)
/* C505CC 802410BC 8C820000 */  lw        $v0, ($a0)
/* C505D0 802410C0 2403F7FF */  addiu     $v1, $zero, -0x801
/* C505D4 802410C4 E484003C */  swc1      $f4, 0x3c($a0)
/* C505D8 802410C8 AC80001C */  sw        $zero, 0x1c($a0)
/* C505DC 802410CC 00431024 */  and       $v0, $v0, $v1
/* C505E0 802410D0 AC820000 */  sw        $v0, ($a0)
/* C505E4 802410D4 2402000C */  addiu     $v0, $zero, 0xc
/* C505E8 802410D8 AE020070 */  sw        $v0, 0x70($s0)
.L802410DC:
/* C505EC 802410DC 8FBF0014 */  lw        $ra, 0x14($sp)
/* C505F0 802410E0 8FB00010 */  lw        $s0, 0x10($sp)
/* C505F4 802410E4 03E00008 */  jr        $ra
/* C505F8 802410E8 27BD0018 */   addiu    $sp, $sp, 0x18
