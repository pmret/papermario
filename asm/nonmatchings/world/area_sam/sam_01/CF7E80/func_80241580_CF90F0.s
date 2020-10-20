.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241580_CF90F0
/* CF90F0 80241580 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* CF90F4 80241584 AFB10014 */  sw        $s1, 0x14($sp)
/* CF90F8 80241588 0080882D */  daddu     $s1, $a0, $zero
/* CF90FC 8024158C AFB00010 */  sw        $s0, 0x10($sp)
/* CF9100 80241590 00A0802D */  daddu     $s0, $a1, $zero
/* CF9104 80241594 AFBF0018 */  sw        $ra, 0x18($sp)
/* CF9108 80241598 0C00EABB */  jal       get_npc_unsafe
/* CF910C 8024159C 2404FFFC */   addiu    $a0, $zero, -4
/* CF9110 802415A0 12000003 */  beqz      $s0, .L802415B0
/* CF9114 802415A4 0040182D */   daddu    $v1, $v0, $zero
/* CF9118 802415A8 2402003C */  addiu     $v0, $zero, 0x3c
/* CF911C 802415AC AE220070 */  sw        $v0, 0x70($s1)
.L802415B0:
/* CF9120 802415B0 C462000C */  lwc1      $f2, 0xc($v1)
/* CF9124 802415B4 3C0141F0 */  lui       $at, 0x41f0
/* CF9128 802415B8 44810000 */  mtc1      $at, $f0
/* CF912C 802415BC 00000000 */  nop       
/* CF9130 802415C0 46001000 */  add.s     $f0, $f2, $f0
/* CF9134 802415C4 3C0143B4 */  lui       $at, 0x43b4
/* CF9138 802415C8 44811000 */  mtc1      $at, $f2
/* CF913C 802415CC 00000000 */  nop       
/* CF9140 802415D0 4600103E */  c.le.s    $f2, $f0
/* CF9144 802415D4 00000000 */  nop       
/* CF9148 802415D8 45000003 */  bc1f      .L802415E8
/* CF914C 802415DC E460000C */   swc1     $f0, 0xc($v1)
/* CF9150 802415E0 46020001 */  sub.s     $f0, $f0, $f2
/* CF9154 802415E4 E460000C */  swc1      $f0, 0xc($v1)
.L802415E8:
/* CF9158 802415E8 8E230070 */  lw        $v1, 0x70($s1)
/* CF915C 802415EC 2463FFFF */  addiu     $v1, $v1, -1
/* CF9160 802415F0 000317C3 */  sra       $v0, $v1, 0x1f
/* CF9164 802415F4 AE230070 */  sw        $v1, 0x70($s1)
/* CF9168 802415F8 8FBF0018 */  lw        $ra, 0x18($sp)
/* CF916C 802415FC 8FB10014 */  lw        $s1, 0x14($sp)
/* CF9170 80241600 8FB00010 */  lw        $s0, 0x10($sp)
/* CF9174 80241604 30420002 */  andi      $v0, $v0, 2
/* CF9178 80241608 03E00008 */  jr        $ra
/* CF917C 8024160C 27BD0020 */   addiu    $sp, $sp, 0x20
