.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240D10_DBDFC0
/* DBDFC0 80240D10 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* DBDFC4 80240D14 AFB00010 */  sw        $s0, 0x10($sp)
/* DBDFC8 80240D18 0080802D */  daddu     $s0, $a0, $zero
/* DBDFCC 80240D1C AFBF0014 */  sw        $ra, 0x14($sp)
/* DBDFD0 80240D20 8E020148 */  lw        $v0, 0x148($s0)
/* DBDFD4 80240D24 0C00EABB */  jal       get_npc_unsafe
/* DBDFD8 80240D28 84440008 */   lh       $a0, 8($v0)
/* DBDFDC 80240D2C 0040202D */  daddu     $a0, $v0, $zero
/* DBDFE0 80240D30 C482003C */  lwc1      $f2, 0x3c($a0)
/* DBDFE4 80240D34 C480001C */  lwc1      $f0, 0x1c($a0)
/* DBDFE8 80240D38 46001080 */  add.s     $f2, $f2, $f0
/* DBDFEC 80240D3C C4840014 */  lwc1      $f4, 0x14($a0)
/* DBDFF0 80240D40 46040001 */  sub.s     $f0, $f0, $f4
/* DBDFF4 80240D44 C4840064 */  lwc1      $f4, 0x64($a0)
/* DBDFF8 80240D48 4602203C */  c.lt.s    $f4, $f2
/* DBDFFC 80240D4C E482003C */  swc1      $f2, 0x3c($a0)
/* DBE000 80240D50 45010009 */  bc1t      .L80240D78
/* DBE004 80240D54 E480001C */   swc1     $f0, 0x1c($a0)
/* DBE008 80240D58 8C820000 */  lw        $v0, ($a0)
/* DBE00C 80240D5C 2403F7FF */  addiu     $v1, $zero, -0x801
/* DBE010 80240D60 E484003C */  swc1      $f4, 0x3c($a0)
/* DBE014 80240D64 AC80001C */  sw        $zero, 0x1c($a0)
/* DBE018 80240D68 00431024 */  and       $v0, $v0, $v1
/* DBE01C 80240D6C AC820000 */  sw        $v0, ($a0)
/* DBE020 80240D70 2402000C */  addiu     $v0, $zero, 0xc
/* DBE024 80240D74 AE020070 */  sw        $v0, 0x70($s0)
.L80240D78:
/* DBE028 80240D78 8FBF0014 */  lw        $ra, 0x14($sp)
/* DBE02C 80240D7C 8FB00010 */  lw        $s0, 0x10($sp)
/* DBE030 80240D80 03E00008 */  jr        $ra
/* DBE034 80240D84 27BD0018 */   addiu    $sp, $sp, 0x18
