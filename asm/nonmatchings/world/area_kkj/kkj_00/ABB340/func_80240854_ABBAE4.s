.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240854_ABBAE4
/* ABBAE4 80240854 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* ABBAE8 80240858 AFB00010 */  sw        $s0, 0x10($sp)
/* ABBAEC 8024085C 0080802D */  daddu     $s0, $a0, $zero
/* ABBAF0 80240860 AFBF0014 */  sw        $ra, 0x14($sp)
/* ABBAF4 80240864 8E020148 */  lw        $v0, 0x148($s0)
/* ABBAF8 80240868 0C00EABB */  jal       get_npc_unsafe
/* ABBAFC 8024086C 84440008 */   lh       $a0, 8($v0)
/* ABBB00 80240870 0040202D */  daddu     $a0, $v0, $zero
/* ABBB04 80240874 C482003C */  lwc1      $f2, 0x3c($a0)
/* ABBB08 80240878 C480001C */  lwc1      $f0, 0x1c($a0)
/* ABBB0C 8024087C 46001080 */  add.s     $f2, $f2, $f0
/* ABBB10 80240880 C4840014 */  lwc1      $f4, 0x14($a0)
/* ABBB14 80240884 46040001 */  sub.s     $f0, $f0, $f4
/* ABBB18 80240888 C4840064 */  lwc1      $f4, 0x64($a0)
/* ABBB1C 8024088C 4602203C */  c.lt.s    $f4, $f2
/* ABBB20 80240890 E482003C */  swc1      $f2, 0x3c($a0)
/* ABBB24 80240894 45010009 */  bc1t      .L802408BC
/* ABBB28 80240898 E480001C */   swc1     $f0, 0x1c($a0)
/* ABBB2C 8024089C 8C820000 */  lw        $v0, ($a0)
/* ABBB30 802408A0 2403F7FF */  addiu     $v1, $zero, -0x801
/* ABBB34 802408A4 E484003C */  swc1      $f4, 0x3c($a0)
/* ABBB38 802408A8 AC80001C */  sw        $zero, 0x1c($a0)
/* ABBB3C 802408AC 00431024 */  and       $v0, $v0, $v1
/* ABBB40 802408B0 AC820000 */  sw        $v0, ($a0)
/* ABBB44 802408B4 2402000C */  addiu     $v0, $zero, 0xc
/* ABBB48 802408B8 AE020070 */  sw        $v0, 0x70($s0)
.L802408BC:
/* ABBB4C 802408BC 8FBF0014 */  lw        $ra, 0x14($sp)
/* ABBB50 802408C0 8FB00010 */  lw        $s0, 0x10($sp)
/* ABBB54 802408C4 03E00008 */  jr        $ra
/* ABBB58 802408C8 27BD0018 */   addiu    $sp, $sp, 0x18
