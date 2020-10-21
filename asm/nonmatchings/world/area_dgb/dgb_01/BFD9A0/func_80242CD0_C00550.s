.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242CD0_C00550
/* C00550 80242CD0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C00554 80242CD4 AFB00010 */  sw        $s0, 0x10($sp)
/* C00558 80242CD8 0080802D */  daddu     $s0, $a0, $zero
/* C0055C 80242CDC AFBF0014 */  sw        $ra, 0x14($sp)
/* C00560 80242CE0 8E020148 */  lw        $v0, 0x148($s0)
/* C00564 80242CE4 0C00EABB */  jal       get_npc_unsafe
/* C00568 80242CE8 84440008 */   lh       $a0, 8($v0)
/* C0056C 80242CEC 0040202D */  daddu     $a0, $v0, $zero
/* C00570 80242CF0 C482003C */  lwc1      $f2, 0x3c($a0)
/* C00574 80242CF4 C480001C */  lwc1      $f0, 0x1c($a0)
/* C00578 80242CF8 46001080 */  add.s     $f2, $f2, $f0
/* C0057C 80242CFC C4840014 */  lwc1      $f4, 0x14($a0)
/* C00580 80242D00 46040001 */  sub.s     $f0, $f0, $f4
/* C00584 80242D04 C4840064 */  lwc1      $f4, 0x64($a0)
/* C00588 80242D08 4602203C */  c.lt.s    $f4, $f2
/* C0058C 80242D0C E482003C */  swc1      $f2, 0x3c($a0)
/* C00590 80242D10 45010009 */  bc1t      .L80242D38
/* C00594 80242D14 E480001C */   swc1     $f0, 0x1c($a0)
/* C00598 80242D18 8C820000 */  lw        $v0, ($a0)
/* C0059C 80242D1C 2403F7FF */  addiu     $v1, $zero, -0x801
/* C005A0 80242D20 E484003C */  swc1      $f4, 0x3c($a0)
/* C005A4 80242D24 AC80001C */  sw        $zero, 0x1c($a0)
/* C005A8 80242D28 00431024 */  and       $v0, $v0, $v1
/* C005AC 80242D2C AC820000 */  sw        $v0, ($a0)
/* C005B0 80242D30 2402000C */  addiu     $v0, $zero, 0xc
/* C005B4 80242D34 AE020070 */  sw        $v0, 0x70($s0)
.L80242D38:
/* C005B8 80242D38 8FBF0014 */  lw        $ra, 0x14($sp)
/* C005BC 80242D3C 8FB00010 */  lw        $s0, 0x10($sp)
/* C005C0 80242D40 03E00008 */  jr        $ra
/* C005C4 80242D44 27BD0018 */   addiu    $sp, $sp, 0x18
