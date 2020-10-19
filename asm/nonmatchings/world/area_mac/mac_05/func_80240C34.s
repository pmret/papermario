.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240C34
/* 852DA4 80240C34 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 852DA8 80240C38 AFB00010 */  sw        $s0, 0x10($sp)
/* 852DAC 80240C3C 0080802D */  daddu     $s0, $a0, $zero
/* 852DB0 80240C40 AFBF0014 */  sw        $ra, 0x14($sp)
/* 852DB4 80240C44 8E020148 */  lw        $v0, 0x148($s0)
/* 852DB8 80240C48 0C00EABB */  jal       get_npc_unsafe
/* 852DBC 80240C4C 84440008 */   lh       $a0, 8($v0)
/* 852DC0 80240C50 0040202D */  daddu     $a0, $v0, $zero
/* 852DC4 80240C54 C482003C */  lwc1      $f2, 0x3c($a0)
/* 852DC8 80240C58 C480001C */  lwc1      $f0, 0x1c($a0)
/* 852DCC 80240C5C 46001080 */  add.s     $f2, $f2, $f0
/* 852DD0 80240C60 C4840014 */  lwc1      $f4, 0x14($a0)
/* 852DD4 80240C64 46040001 */  sub.s     $f0, $f0, $f4
/* 852DD8 80240C68 C4840064 */  lwc1      $f4, 0x64($a0)
/* 852DDC 80240C6C 4602203C */  c.lt.s    $f4, $f2
/* 852DE0 80240C70 E482003C */  swc1      $f2, 0x3c($a0)
/* 852DE4 80240C74 45010009 */  bc1t      .L80240C9C
/* 852DE8 80240C78 E480001C */   swc1     $f0, 0x1c($a0)
/* 852DEC 80240C7C 8C820000 */  lw        $v0, ($a0)
/* 852DF0 80240C80 2403F7FF */  addiu     $v1, $zero, -0x801
/* 852DF4 80240C84 E484003C */  swc1      $f4, 0x3c($a0)
/* 852DF8 80240C88 AC80001C */  sw        $zero, 0x1c($a0)
/* 852DFC 80240C8C 00431024 */  and       $v0, $v0, $v1
/* 852E00 80240C90 AC820000 */  sw        $v0, ($a0)
/* 852E04 80240C94 2402000C */  addiu     $v0, $zero, 0xc
/* 852E08 80240C98 AE020070 */  sw        $v0, 0x70($s0)
.L80240C9C:
/* 852E0C 80240C9C 8FBF0014 */  lw        $ra, 0x14($sp)
/* 852E10 80240CA0 8FB00010 */  lw        $s0, 0x10($sp)
/* 852E14 80240CA4 03E00008 */  jr        $ra
/* 852E18 80240CA8 27BD0018 */   addiu    $sp, $sp, 0x18
