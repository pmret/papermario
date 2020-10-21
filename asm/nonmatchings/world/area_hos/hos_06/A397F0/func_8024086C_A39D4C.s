.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024086C_A39D4C
/* A39D4C 8024086C 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* A39D50 80240870 AFB1001C */  sw        $s1, 0x1c($sp)
/* A39D54 80240874 0080882D */  daddu     $s1, $a0, $zero
/* A39D58 80240878 AFBF0034 */  sw        $ra, 0x34($sp)
/* A39D5C 8024087C AFB60030 */  sw        $s6, 0x30($sp)
/* A39D60 80240880 AFB5002C */  sw        $s5, 0x2c($sp)
/* A39D64 80240884 AFB40028 */  sw        $s4, 0x28($sp)
/* A39D68 80240888 AFB30024 */  sw        $s3, 0x24($sp)
/* A39D6C 8024088C AFB20020 */  sw        $s2, 0x20($sp)
/* A39D70 80240890 AFB00018 */  sw        $s0, 0x18($sp)
/* A39D74 80240894 F7B60040 */  sdc1      $f22, 0x40($sp)
/* A39D78 80240898 F7B40038 */  sdc1      $f20, 0x38($sp)
/* A39D7C 8024089C 8E30000C */  lw        $s0, 0xc($s1)
/* A39D80 802408A0 8E160000 */  lw        $s6, ($s0)
/* A39D84 802408A4 26100004 */  addiu     $s0, $s0, 4
/* A39D88 802408A8 0C0B1EAF */  jal       get_variable
/* A39D8C 802408AC 02C0282D */   daddu    $a1, $s6, $zero
/* A39D90 802408B0 44820000 */  mtc1      $v0, $f0
/* A39D94 802408B4 00000000 */  nop       
/* A39D98 802408B8 46800020 */  cvt.s.w   $f0, $f0
/* A39D9C 802408BC E7A00010 */  swc1      $f0, 0x10($sp)
/* A39DA0 802408C0 8E140000 */  lw        $s4, ($s0)
/* A39DA4 802408C4 26100004 */  addiu     $s0, $s0, 4
/* A39DA8 802408C8 0220202D */  daddu     $a0, $s1, $zero
/* A39DAC 802408CC 0C0B1EAF */  jal       get_variable
/* A39DB0 802408D0 0280282D */   daddu    $a1, $s4, $zero
/* A39DB4 802408D4 0220202D */  daddu     $a0, $s1, $zero
/* A39DB8 802408D8 8E150000 */  lw        $s5, ($s0)
/* A39DBC 802408DC 4482B000 */  mtc1      $v0, $f22
/* A39DC0 802408E0 00000000 */  nop       
/* A39DC4 802408E4 4680B5A0 */  cvt.s.w   $f22, $f22
/* A39DC8 802408E8 0C0B1EAF */  jal       get_variable
/* A39DCC 802408EC 02A0282D */   daddu    $a1, $s5, $zero
/* A39DD0 802408F0 2404FFFC */  addiu     $a0, $zero, -4
/* A39DD4 802408F4 44820000 */  mtc1      $v0, $f0
/* A39DD8 802408F8 00000000 */  nop       
/* A39DDC 802408FC 46800020 */  cvt.s.w   $f0, $f0
/* A39DE0 80240900 0C00EABB */  jal       get_npc_unsafe
/* A39DE4 80240904 E7A00014 */   swc1     $f0, 0x14($sp)
/* A39DE8 80240908 3C048007 */  lui       $a0, %hi(gCurrentCameraID)
/* A39DEC 8024090C 8C847410 */  lw        $a0, %lo(gCurrentCameraID)($a0)
/* A39DF0 80240910 3C014334 */  lui       $at, 0x4334
/* A39DF4 80240914 44816000 */  mtc1      $at, $f12
/* A39DF8 80240918 00041880 */  sll       $v1, $a0, 2
/* A39DFC 8024091C 00641821 */  addu      $v1, $v1, $a0
/* A39E00 80240920 00031880 */  sll       $v1, $v1, 2
/* A39E04 80240924 00641823 */  subu      $v1, $v1, $a0
/* A39E08 80240928 000320C0 */  sll       $a0, $v1, 3
/* A39E0C 8024092C 00641821 */  addu      $v1, $v1, $a0
/* A39E10 80240930 000318C0 */  sll       $v1, $v1, 3
/* A39E14 80240934 3C01800B */  lui       $at, 0x800b
/* A39E18 80240938 00230821 */  addu      $at, $at, $v1
/* A39E1C 8024093C C4201DEC */  lwc1      $f0, 0x1dec($at)
/* A39E20 80240940 460C0300 */  add.s     $f12, $f0, $f12
/* A39E24 80240944 0C00A6C9 */  jal       clamp_angle
/* A39E28 80240948 0040982D */   daddu    $s3, $v0, $zero
/* A39E2C 8024094C 27B00010 */  addiu     $s0, $sp, 0x10
/* A39E30 80240950 0200202D */  daddu     $a0, $s0, $zero
/* A39E34 80240954 27B20014 */  addiu     $s2, $sp, 0x14
/* A39E38 80240958 0240282D */  daddu     $a1, $s2, $zero
/* A39E3C 8024095C 3C064170 */  lui       $a2, 0x4170
/* A39E40 80240960 8E67000C */  lw        $a3, 0xc($s3)
/* A39E44 80240964 0C00A7E7 */  jal       add_vec2D_polar
/* A39E48 80240968 46000506 */   mov.s    $f20, $f0
/* A39E4C 8024096C 0200202D */  daddu     $a0, $s0, $zero
/* A39E50 80240970 3C064120 */  lui       $a2, 0x4120
/* A39E54 80240974 4407A000 */  mfc1      $a3, $f20
/* A39E58 80240978 0C00A7E7 */  jal       add_vec2D_polar
/* A39E5C 8024097C 0240282D */   daddu    $a1, $s2, $zero
/* A39E60 80240980 0220202D */  daddu     $a0, $s1, $zero
/* A39E64 80240984 C7A00010 */  lwc1      $f0, 0x10($sp)
/* A39E68 80240988 4600008D */  trunc.w.s $f2, $f0
/* A39E6C 8024098C 44061000 */  mfc1      $a2, $f2
/* A39E70 80240990 0C0B2026 */  jal       set_variable
/* A39E74 80240994 02C0282D */   daddu    $a1, $s6, $zero
/* A39E78 80240998 0220202D */  daddu     $a0, $s1, $zero
/* A39E7C 8024099C 4600B08D */  trunc.w.s $f2, $f22
/* A39E80 802409A0 44061000 */  mfc1      $a2, $f2
/* A39E84 802409A4 0C0B2026 */  jal       set_variable
/* A39E88 802409A8 0280282D */   daddu    $a1, $s4, $zero
/* A39E8C 802409AC 0220202D */  daddu     $a0, $s1, $zero
/* A39E90 802409B0 C7A00014 */  lwc1      $f0, 0x14($sp)
/* A39E94 802409B4 4600008D */  trunc.w.s $f2, $f0
/* A39E98 802409B8 44061000 */  mfc1      $a2, $f2
/* A39E9C 802409BC 0C0B2026 */  jal       set_variable
/* A39EA0 802409C0 02A0282D */   daddu    $a1, $s5, $zero
/* A39EA4 802409C4 8FBF0034 */  lw        $ra, 0x34($sp)
/* A39EA8 802409C8 8FB60030 */  lw        $s6, 0x30($sp)
/* A39EAC 802409CC 8FB5002C */  lw        $s5, 0x2c($sp)
/* A39EB0 802409D0 8FB40028 */  lw        $s4, 0x28($sp)
/* A39EB4 802409D4 8FB30024 */  lw        $s3, 0x24($sp)
/* A39EB8 802409D8 8FB20020 */  lw        $s2, 0x20($sp)
/* A39EBC 802409DC 8FB1001C */  lw        $s1, 0x1c($sp)
/* A39EC0 802409E0 8FB00018 */  lw        $s0, 0x18($sp)
/* A39EC4 802409E4 D7B60040 */  ldc1      $f22, 0x40($sp)
/* A39EC8 802409E8 D7B40038 */  ldc1      $f20, 0x38($sp)
/* A39ECC 802409EC 24020002 */  addiu     $v0, $zero, 2
/* A39ED0 802409F0 03E00008 */  jr        $ra
/* A39ED4 802409F4 27BD0048 */   addiu    $sp, $sp, 0x48
