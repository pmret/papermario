.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241058_9A2038
/* 9A2038 80241058 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 9A203C 8024105C AFB00010 */  sw        $s0, 0x10($sp)
/* 9A2040 80241060 0080802D */  daddu     $s0, $a0, $zero
/* 9A2044 80241064 AFBF0014 */  sw        $ra, 0x14($sp)
/* 9A2048 80241068 8E020148 */  lw        $v0, 0x148($s0)
/* 9A204C 8024106C 0C00EABB */  jal       get_npc_unsafe
/* 9A2050 80241070 84440008 */   lh       $a0, 8($v0)
/* 9A2054 80241074 0040202D */  daddu     $a0, $v0, $zero
/* 9A2058 80241078 C482003C */  lwc1      $f2, 0x3c($a0)
/* 9A205C 8024107C C480001C */  lwc1      $f0, 0x1c($a0)
/* 9A2060 80241080 46001080 */  add.s     $f2, $f2, $f0
/* 9A2064 80241084 C4840014 */  lwc1      $f4, 0x14($a0)
/* 9A2068 80241088 46040001 */  sub.s     $f0, $f0, $f4
/* 9A206C 8024108C C4840064 */  lwc1      $f4, 0x64($a0)
/* 9A2070 80241090 4602203C */  c.lt.s    $f4, $f2
/* 9A2074 80241094 E482003C */  swc1      $f2, 0x3c($a0)
/* 9A2078 80241098 45010009 */  bc1t      .L802410C0
/* 9A207C 8024109C E480001C */   swc1     $f0, 0x1c($a0)
/* 9A2080 802410A0 8C820000 */  lw        $v0, ($a0)
/* 9A2084 802410A4 2403F7FF */  addiu     $v1, $zero, -0x801
/* 9A2088 802410A8 E484003C */  swc1      $f4, 0x3c($a0)
/* 9A208C 802410AC AC80001C */  sw        $zero, 0x1c($a0)
/* 9A2090 802410B0 00431024 */  and       $v0, $v0, $v1
/* 9A2094 802410B4 AC820000 */  sw        $v0, ($a0)
/* 9A2098 802410B8 2402000C */  addiu     $v0, $zero, 0xc
/* 9A209C 802410BC AE020070 */  sw        $v0, 0x70($s0)
.L802410C0:
/* 9A20A0 802410C0 8FBF0014 */  lw        $ra, 0x14($sp)
/* 9A20A4 802410C4 8FB00010 */  lw        $s0, 0x10($sp)
/* 9A20A8 802410C8 03E00008 */  jr        $ra
/* 9A20AC 802410CC 27BD0018 */   addiu    $sp, $sp, 0x18
