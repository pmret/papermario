.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240D84
/* 95BF84 80240D84 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 95BF88 80240D88 AFB00010 */  sw        $s0, 0x10($sp)
/* 95BF8C 80240D8C 0080802D */  daddu     $s0, $a0, $zero
/* 95BF90 80240D90 AFBF0014 */  sw        $ra, 0x14($sp)
/* 95BF94 80240D94 8E020148 */  lw        $v0, 0x148($s0)
/* 95BF98 80240D98 0C00EABB */  jal       get_npc_unsafe
/* 95BF9C 80240D9C 84440008 */   lh       $a0, 8($v0)
/* 95BFA0 80240DA0 0040202D */  daddu     $a0, $v0, $zero
/* 95BFA4 80240DA4 C482003C */  lwc1      $f2, 0x3c($a0)
/* 95BFA8 80240DA8 C480001C */  lwc1      $f0, 0x1c($a0)
/* 95BFAC 80240DAC 46001080 */  add.s     $f2, $f2, $f0
/* 95BFB0 80240DB0 C4840014 */  lwc1      $f4, 0x14($a0)
/* 95BFB4 80240DB4 46040001 */  sub.s     $f0, $f0, $f4
/* 95BFB8 80240DB8 C4840064 */  lwc1      $f4, 0x64($a0)
/* 95BFBC 80240DBC 4602203C */  c.lt.s    $f4, $f2
/* 95BFC0 80240DC0 E482003C */  swc1      $f2, 0x3c($a0)
/* 95BFC4 80240DC4 45010009 */  bc1t      .L80240DEC
/* 95BFC8 80240DC8 E480001C */   swc1     $f0, 0x1c($a0)
/* 95BFCC 80240DCC 8C820000 */  lw        $v0, ($a0)
/* 95BFD0 80240DD0 2403F7FF */  addiu     $v1, $zero, -0x801
/* 95BFD4 80240DD4 E484003C */  swc1      $f4, 0x3c($a0)
/* 95BFD8 80240DD8 AC80001C */  sw        $zero, 0x1c($a0)
/* 95BFDC 80240DDC 00431024 */  and       $v0, $v0, $v1
/* 95BFE0 80240DE0 AC820000 */  sw        $v0, ($a0)
/* 95BFE4 80240DE4 2402000C */  addiu     $v0, $zero, 0xc
/* 95BFE8 80240DE8 AE020070 */  sw        $v0, 0x70($s0)
.L80240DEC:
/* 95BFEC 80240DEC 8FBF0014 */  lw        $ra, 0x14($sp)
/* 95BFF0 80240DF0 8FB00010 */  lw        $s0, 0x10($sp)
/* 95BFF4 80240DF4 03E00008 */  jr        $ra
/* 95BFF8 80240DF8 27BD0018 */   addiu    $sp, $sp, 0x18
