.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240DF8_99D788
/* 99D788 80240DF8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 99D78C 80240DFC AFB00010 */  sw        $s0, 0x10($sp)
/* 99D790 80240E00 0080802D */  daddu     $s0, $a0, $zero
/* 99D794 80240E04 AFBF0014 */  sw        $ra, 0x14($sp)
/* 99D798 80240E08 8E020148 */  lw        $v0, 0x148($s0)
/* 99D79C 80240E0C 0C00EABB */  jal       get_npc_unsafe
/* 99D7A0 80240E10 84440008 */   lh       $a0, 8($v0)
/* 99D7A4 80240E14 0040202D */  daddu     $a0, $v0, $zero
/* 99D7A8 80240E18 C482003C */  lwc1      $f2, 0x3c($a0)
/* 99D7AC 80240E1C C480001C */  lwc1      $f0, 0x1c($a0)
/* 99D7B0 80240E20 46001080 */  add.s     $f2, $f2, $f0
/* 99D7B4 80240E24 C4840014 */  lwc1      $f4, 0x14($a0)
/* 99D7B8 80240E28 46040001 */  sub.s     $f0, $f0, $f4
/* 99D7BC 80240E2C C4840064 */  lwc1      $f4, 0x64($a0)
/* 99D7C0 80240E30 4602203C */  c.lt.s    $f4, $f2
/* 99D7C4 80240E34 E482003C */  swc1      $f2, 0x3c($a0)
/* 99D7C8 80240E38 45010009 */  bc1t      .L80240E60
/* 99D7CC 80240E3C E480001C */   swc1     $f0, 0x1c($a0)
/* 99D7D0 80240E40 8C820000 */  lw        $v0, ($a0)
/* 99D7D4 80240E44 2403F7FF */  addiu     $v1, $zero, -0x801
/* 99D7D8 80240E48 E484003C */  swc1      $f4, 0x3c($a0)
/* 99D7DC 80240E4C AC80001C */  sw        $zero, 0x1c($a0)
/* 99D7E0 80240E50 00431024 */  and       $v0, $v0, $v1
/* 99D7E4 80240E54 AC820000 */  sw        $v0, ($a0)
/* 99D7E8 80240E58 2402000C */  addiu     $v0, $zero, 0xc
/* 99D7EC 80240E5C AE020070 */  sw        $v0, 0x70($s0)
.L80240E60:
/* 99D7F0 80240E60 8FBF0014 */  lw        $ra, 0x14($sp)
/* 99D7F4 80240E64 8FB00010 */  lw        $s0, 0x10($sp)
/* 99D7F8 80240E68 03E00008 */  jr        $ra
/* 99D7FC 80240E6C 27BD0018 */   addiu    $sp, $sp, 0x18
