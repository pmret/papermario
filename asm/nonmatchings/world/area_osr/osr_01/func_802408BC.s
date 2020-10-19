.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802408BC
/* AB08AC 802408BC 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* AB08B0 802408C0 AFB1001C */  sw        $s1, 0x1c($sp)
/* AB08B4 802408C4 0080882D */  daddu     $s1, $a0, $zero
/* AB08B8 802408C8 AFBF0034 */  sw        $ra, 0x34($sp)
/* AB08BC 802408CC AFB60030 */  sw        $s6, 0x30($sp)
/* AB08C0 802408D0 AFB5002C */  sw        $s5, 0x2c($sp)
/* AB08C4 802408D4 AFB40028 */  sw        $s4, 0x28($sp)
/* AB08C8 802408D8 AFB30024 */  sw        $s3, 0x24($sp)
/* AB08CC 802408DC AFB20020 */  sw        $s2, 0x20($sp)
/* AB08D0 802408E0 AFB00018 */  sw        $s0, 0x18($sp)
/* AB08D4 802408E4 F7B60040 */  sdc1      $f22, 0x40($sp)
/* AB08D8 802408E8 F7B40038 */  sdc1      $f20, 0x38($sp)
/* AB08DC 802408EC 8E30000C */  lw        $s0, 0xc($s1)
/* AB08E0 802408F0 8E160000 */  lw        $s6, ($s0)
/* AB08E4 802408F4 26100004 */  addiu     $s0, $s0, 4
/* AB08E8 802408F8 0C0B1EAF */  jal       get_variable
/* AB08EC 802408FC 02C0282D */   daddu    $a1, $s6, $zero
/* AB08F0 80240900 44820000 */  mtc1      $v0, $f0
/* AB08F4 80240904 00000000 */  nop       
/* AB08F8 80240908 46800020 */  cvt.s.w   $f0, $f0
/* AB08FC 8024090C E7A00010 */  swc1      $f0, 0x10($sp)
/* AB0900 80240910 8E140000 */  lw        $s4, ($s0)
/* AB0904 80240914 26100004 */  addiu     $s0, $s0, 4
/* AB0908 80240918 0220202D */  daddu     $a0, $s1, $zero
/* AB090C 8024091C 0C0B1EAF */  jal       get_variable
/* AB0910 80240920 0280282D */   daddu    $a1, $s4, $zero
/* AB0914 80240924 0220202D */  daddu     $a0, $s1, $zero
/* AB0918 80240928 8E150000 */  lw        $s5, ($s0)
/* AB091C 8024092C 4482B000 */  mtc1      $v0, $f22
/* AB0920 80240930 00000000 */  nop       
/* AB0924 80240934 4680B5A0 */  cvt.s.w   $f22, $f22
/* AB0928 80240938 0C0B1EAF */  jal       get_variable
/* AB092C 8024093C 02A0282D */   daddu    $a1, $s5, $zero
/* AB0930 80240940 2404FFFC */  addiu     $a0, $zero, -4
/* AB0934 80240944 44820000 */  mtc1      $v0, $f0
/* AB0938 80240948 00000000 */  nop       
/* AB093C 8024094C 46800020 */  cvt.s.w   $f0, $f0
/* AB0940 80240950 0C00EABB */  jal       get_npc_unsafe
/* AB0944 80240954 E7A00014 */   swc1     $f0, 0x14($sp)
/* AB0948 80240958 3C048007 */  lui       $a0, %hi(gCurrentCameraID)
/* AB094C 8024095C 8C847410 */  lw        $a0, %lo(gCurrentCameraID)($a0)
/* AB0950 80240960 3C014334 */  lui       $at, 0x4334
/* AB0954 80240964 44816000 */  mtc1      $at, $f12
/* AB0958 80240968 00041880 */  sll       $v1, $a0, 2
/* AB095C 8024096C 00641821 */  addu      $v1, $v1, $a0
/* AB0960 80240970 00031880 */  sll       $v1, $v1, 2
/* AB0964 80240974 00641823 */  subu      $v1, $v1, $a0
/* AB0968 80240978 000320C0 */  sll       $a0, $v1, 3
/* AB096C 8024097C 00641821 */  addu      $v1, $v1, $a0
/* AB0970 80240980 000318C0 */  sll       $v1, $v1, 3
/* AB0974 80240984 3C01800B */  lui       $at, 0x800b
/* AB0978 80240988 00230821 */  addu      $at, $at, $v1
/* AB097C 8024098C C4201DEC */  lwc1      $f0, 0x1dec($at)
/* AB0980 80240990 460C0300 */  add.s     $f12, $f0, $f12
/* AB0984 80240994 0C00A6C9 */  jal       clamp_angle
/* AB0988 80240998 0040982D */   daddu    $s3, $v0, $zero
/* AB098C 8024099C 27B00010 */  addiu     $s0, $sp, 0x10
/* AB0990 802409A0 0200202D */  daddu     $a0, $s0, $zero
/* AB0994 802409A4 27B20014 */  addiu     $s2, $sp, 0x14
/* AB0998 802409A8 0240282D */  daddu     $a1, $s2, $zero
/* AB099C 802409AC 3C064170 */  lui       $a2, 0x4170
/* AB09A0 802409B0 8E67000C */  lw        $a3, 0xc($s3)
/* AB09A4 802409B4 0C00A7E7 */  jal       add_vec2D_polar
/* AB09A8 802409B8 46000506 */   mov.s    $f20, $f0
/* AB09AC 802409BC 0200202D */  daddu     $a0, $s0, $zero
/* AB09B0 802409C0 3C064120 */  lui       $a2, 0x4120
/* AB09B4 802409C4 4407A000 */  mfc1      $a3, $f20
/* AB09B8 802409C8 0C00A7E7 */  jal       add_vec2D_polar
/* AB09BC 802409CC 0240282D */   daddu    $a1, $s2, $zero
/* AB09C0 802409D0 0220202D */  daddu     $a0, $s1, $zero
/* AB09C4 802409D4 C7A00010 */  lwc1      $f0, 0x10($sp)
/* AB09C8 802409D8 4600008D */  trunc.w.s $f2, $f0
/* AB09CC 802409DC 44061000 */  mfc1      $a2, $f2
/* AB09D0 802409E0 0C0B2026 */  jal       set_variable
/* AB09D4 802409E4 02C0282D */   daddu    $a1, $s6, $zero
/* AB09D8 802409E8 0220202D */  daddu     $a0, $s1, $zero
/* AB09DC 802409EC 4600B08D */  trunc.w.s $f2, $f22
/* AB09E0 802409F0 44061000 */  mfc1      $a2, $f2
/* AB09E4 802409F4 0C0B2026 */  jal       set_variable
/* AB09E8 802409F8 0280282D */   daddu    $a1, $s4, $zero
/* AB09EC 802409FC 0220202D */  daddu     $a0, $s1, $zero
/* AB09F0 80240A00 C7A00014 */  lwc1      $f0, 0x14($sp)
/* AB09F4 80240A04 4600008D */  trunc.w.s $f2, $f0
/* AB09F8 80240A08 44061000 */  mfc1      $a2, $f2
/* AB09FC 80240A0C 0C0B2026 */  jal       set_variable
/* AB0A00 80240A10 02A0282D */   daddu    $a1, $s5, $zero
/* AB0A04 80240A14 8FBF0034 */  lw        $ra, 0x34($sp)
/* AB0A08 80240A18 8FB60030 */  lw        $s6, 0x30($sp)
/* AB0A0C 80240A1C 8FB5002C */  lw        $s5, 0x2c($sp)
/* AB0A10 80240A20 8FB40028 */  lw        $s4, 0x28($sp)
/* AB0A14 80240A24 8FB30024 */  lw        $s3, 0x24($sp)
/* AB0A18 80240A28 8FB20020 */  lw        $s2, 0x20($sp)
/* AB0A1C 80240A2C 8FB1001C */  lw        $s1, 0x1c($sp)
/* AB0A20 80240A30 8FB00018 */  lw        $s0, 0x18($sp)
/* AB0A24 80240A34 D7B60040 */  ldc1      $f22, 0x40($sp)
/* AB0A28 80240A38 D7B40038 */  ldc1      $f20, 0x38($sp)
/* AB0A2C 80240A3C 24020002 */  addiu     $v0, $zero, 2
/* AB0A30 80240A40 03E00008 */  jr        $ra
/* AB0A34 80240A44 27BD0048 */   addiu    $sp, $sp, 0x48
