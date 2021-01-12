.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241570_A87FC0
/* A87FC0 80241570 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A87FC4 80241574 AFB10014 */  sw        $s1, 0x14($sp)
/* A87FC8 80241578 0080882D */  daddu     $s1, $a0, $zero
/* A87FCC 8024157C AFBF0018 */  sw        $ra, 0x18($sp)
/* A87FD0 80241580 AFB00010 */  sw        $s0, 0x10($sp)
/* A87FD4 80241584 8E30000C */  lw        $s0, 0xc($s1)
/* A87FD8 80241588 8E050000 */  lw        $a1, ($s0)
/* A87FDC 8024158C 0C0B1EAF */  jal       get_variable
/* A87FE0 80241590 26100004 */   addiu    $s0, $s0, 4
/* A87FE4 80241594 0220202D */  daddu     $a0, $s1, $zero
/* A87FE8 80241598 8E050000 */  lw        $a1, ($s0)
/* A87FEC 8024159C 0C0B1EAF */  jal       get_variable
/* A87FF0 802415A0 0040882D */   daddu    $s1, $v0, $zero
/* A87FF4 802415A4 0000202D */  daddu     $a0, $zero, $zero
/* A87FF8 802415A8 0080282D */  daddu     $a1, $a0, $zero
/* A87FFC 802415AC 0040802D */  daddu     $s0, $v0, $zero
/* A88000 802415B0 240600BE */  addiu     $a2, $zero, 0xbe
/* A88004 802415B4 0C04DF93 */  jal       func_80137E4C
/* A88008 802415B8 24070091 */   addiu    $a3, $zero, 0x91
/* A8800C 802415BC 44900000 */  mtc1      $s0, $f0
/* A88010 802415C0 00000000 */  nop
/* A88014 802415C4 46800020 */  cvt.s.w   $f0, $f0
/* A88018 802415C8 44050000 */  mfc1      $a1, $f0
/* A8801C 802415CC 0C04DF62 */  jal       func_80137D88
/* A88020 802415D0 322400FF */   andi     $a0, $s1, 0xff
/* A88024 802415D4 8FBF0018 */  lw        $ra, 0x18($sp)
/* A88028 802415D8 8FB10014 */  lw        $s1, 0x14($sp)
/* A8802C 802415DC 8FB00010 */  lw        $s0, 0x10($sp)
/* A88030 802415E0 24020002 */  addiu     $v0, $zero, 2
/* A88034 802415E4 03E00008 */  jr        $ra
/* A88038 802415E8 27BD0020 */   addiu    $sp, $sp, 0x20
