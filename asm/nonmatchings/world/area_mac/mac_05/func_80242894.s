.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242894
/* 854A04 80242894 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 854A08 80242898 AFB1001C */  sw        $s1, 0x1c($sp)
/* 854A0C 8024289C 0080882D */  daddu     $s1, $a0, $zero
/* 854A10 802428A0 AFBF0034 */  sw        $ra, 0x34($sp)
/* 854A14 802428A4 AFB60030 */  sw        $s6, 0x30($sp)
/* 854A18 802428A8 AFB5002C */  sw        $s5, 0x2c($sp)
/* 854A1C 802428AC AFB40028 */  sw        $s4, 0x28($sp)
/* 854A20 802428B0 AFB30024 */  sw        $s3, 0x24($sp)
/* 854A24 802428B4 AFB20020 */  sw        $s2, 0x20($sp)
/* 854A28 802428B8 AFB00018 */  sw        $s0, 0x18($sp)
/* 854A2C 802428BC F7B60040 */  sdc1      $f22, 0x40($sp)
/* 854A30 802428C0 F7B40038 */  sdc1      $f20, 0x38($sp)
/* 854A34 802428C4 8E30000C */  lw        $s0, 0xc($s1)
/* 854A38 802428C8 8E160000 */  lw        $s6, ($s0)
/* 854A3C 802428CC 26100004 */  addiu     $s0, $s0, 4
/* 854A40 802428D0 0C0B1EAF */  jal       get_variable
/* 854A44 802428D4 02C0282D */   daddu    $a1, $s6, $zero
/* 854A48 802428D8 44820000 */  mtc1      $v0, $f0
/* 854A4C 802428DC 00000000 */  nop       
/* 854A50 802428E0 46800020 */  cvt.s.w   $f0, $f0
/* 854A54 802428E4 E7A00010 */  swc1      $f0, 0x10($sp)
/* 854A58 802428E8 8E140000 */  lw        $s4, ($s0)
/* 854A5C 802428EC 26100004 */  addiu     $s0, $s0, 4
/* 854A60 802428F0 0220202D */  daddu     $a0, $s1, $zero
/* 854A64 802428F4 0C0B1EAF */  jal       get_variable
/* 854A68 802428F8 0280282D */   daddu    $a1, $s4, $zero
/* 854A6C 802428FC 0220202D */  daddu     $a0, $s1, $zero
/* 854A70 80242900 8E150000 */  lw        $s5, ($s0)
/* 854A74 80242904 4482B000 */  mtc1      $v0, $f22
/* 854A78 80242908 00000000 */  nop       
/* 854A7C 8024290C 4680B5A0 */  cvt.s.w   $f22, $f22
/* 854A80 80242910 0C0B1EAF */  jal       get_variable
/* 854A84 80242914 02A0282D */   daddu    $a1, $s5, $zero
/* 854A88 80242918 2404FFFC */  addiu     $a0, $zero, -4
/* 854A8C 8024291C 44820000 */  mtc1      $v0, $f0
/* 854A90 80242920 00000000 */  nop       
/* 854A94 80242924 46800020 */  cvt.s.w   $f0, $f0
/* 854A98 80242928 0C00EABB */  jal       get_npc_unsafe
/* 854A9C 8024292C E7A00014 */   swc1     $f0, 0x14($sp)
/* 854AA0 80242930 3C048007 */  lui       $a0, %hi(gCurrentCameraID)
/* 854AA4 80242934 8C847410 */  lw        $a0, %lo(gCurrentCameraID)($a0)
/* 854AA8 80242938 3C014334 */  lui       $at, 0x4334
/* 854AAC 8024293C 44816000 */  mtc1      $at, $f12
/* 854AB0 80242940 00041880 */  sll       $v1, $a0, 2
/* 854AB4 80242944 00641821 */  addu      $v1, $v1, $a0
/* 854AB8 80242948 00031880 */  sll       $v1, $v1, 2
/* 854ABC 8024294C 00641823 */  subu      $v1, $v1, $a0
/* 854AC0 80242950 000320C0 */  sll       $a0, $v1, 3
/* 854AC4 80242954 00641821 */  addu      $v1, $v1, $a0
/* 854AC8 80242958 000318C0 */  sll       $v1, $v1, 3
/* 854ACC 8024295C 3C01800B */  lui       $at, 0x800b
/* 854AD0 80242960 00230821 */  addu      $at, $at, $v1
/* 854AD4 80242964 C4201DEC */  lwc1      $f0, 0x1dec($at)
/* 854AD8 80242968 460C0300 */  add.s     $f12, $f0, $f12
/* 854ADC 8024296C 0C00A6C9 */  jal       clamp_angle
/* 854AE0 80242970 0040982D */   daddu    $s3, $v0, $zero
/* 854AE4 80242974 27B00010 */  addiu     $s0, $sp, 0x10
/* 854AE8 80242978 0200202D */  daddu     $a0, $s0, $zero
/* 854AEC 8024297C 27B20014 */  addiu     $s2, $sp, 0x14
/* 854AF0 80242980 0240282D */  daddu     $a1, $s2, $zero
/* 854AF4 80242984 3C064170 */  lui       $a2, 0x4170
/* 854AF8 80242988 8E67000C */  lw        $a3, 0xc($s3)
/* 854AFC 8024298C 0C00A7E7 */  jal       add_vec2D_polar
/* 854B00 80242990 46000506 */   mov.s    $f20, $f0
/* 854B04 80242994 0200202D */  daddu     $a0, $s0, $zero
/* 854B08 80242998 3C064120 */  lui       $a2, 0x4120
/* 854B0C 8024299C 4407A000 */  mfc1      $a3, $f20
/* 854B10 802429A0 0C00A7E7 */  jal       add_vec2D_polar
/* 854B14 802429A4 0240282D */   daddu    $a1, $s2, $zero
/* 854B18 802429A8 0220202D */  daddu     $a0, $s1, $zero
/* 854B1C 802429AC C7A00010 */  lwc1      $f0, 0x10($sp)
/* 854B20 802429B0 4600008D */  trunc.w.s $f2, $f0
/* 854B24 802429B4 44061000 */  mfc1      $a2, $f2
/* 854B28 802429B8 0C0B2026 */  jal       set_variable
/* 854B2C 802429BC 02C0282D */   daddu    $a1, $s6, $zero
/* 854B30 802429C0 0220202D */  daddu     $a0, $s1, $zero
/* 854B34 802429C4 4600B08D */  trunc.w.s $f2, $f22
/* 854B38 802429C8 44061000 */  mfc1      $a2, $f2
/* 854B3C 802429CC 0C0B2026 */  jal       set_variable
/* 854B40 802429D0 0280282D */   daddu    $a1, $s4, $zero
/* 854B44 802429D4 0220202D */  daddu     $a0, $s1, $zero
/* 854B48 802429D8 C7A00014 */  lwc1      $f0, 0x14($sp)
/* 854B4C 802429DC 4600008D */  trunc.w.s $f2, $f0
/* 854B50 802429E0 44061000 */  mfc1      $a2, $f2
/* 854B54 802429E4 0C0B2026 */  jal       set_variable
/* 854B58 802429E8 02A0282D */   daddu    $a1, $s5, $zero
/* 854B5C 802429EC 8FBF0034 */  lw        $ra, 0x34($sp)
/* 854B60 802429F0 8FB60030 */  lw        $s6, 0x30($sp)
/* 854B64 802429F4 8FB5002C */  lw        $s5, 0x2c($sp)
/* 854B68 802429F8 8FB40028 */  lw        $s4, 0x28($sp)
/* 854B6C 802429FC 8FB30024 */  lw        $s3, 0x24($sp)
/* 854B70 80242A00 8FB20020 */  lw        $s2, 0x20($sp)
/* 854B74 80242A04 8FB1001C */  lw        $s1, 0x1c($sp)
/* 854B78 80242A08 8FB00018 */  lw        $s0, 0x18($sp)
/* 854B7C 80242A0C D7B60040 */  ldc1      $f22, 0x40($sp)
/* 854B80 80242A10 D7B40038 */  ldc1      $f20, 0x38($sp)
/* 854B84 80242A14 24020002 */  addiu     $v0, $zero, 2
/* 854B88 80242A18 03E00008 */  jr        $ra
/* 854B8C 80242A1C 27BD0048 */   addiu    $sp, $sp, 0x48
