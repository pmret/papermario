.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E003C244
/* 34F704 E003C244 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 34F708 E003C248 AFBF0010 */  sw        $ra, 0x10($sp)
/* 34F70C E003C24C F7B40018 */  sdc1      $f20, 0x18($sp)
/* 34F710 E003C250 8C85000C */  lw        $a1, 0xc($a0)
/* 34F714 E003C254 8CA30030 */  lw        $v1, 0x30($a1)
/* 34F718 E003C258 28620064 */  slti      $v0, $v1, 0x64
/* 34F71C E003C25C 10400002 */  beqz      $v0, .LE003C268
/* 34F720 E003C260 2462FFFF */   addiu    $v0, $v1, -1
/* 34F724 E003C264 ACA20030 */  sw        $v0, 0x30($a1)
.LE003C268:
/* 34F728 E003C268 8CA60034 */  lw        $a2, 0x34($a1)
/* 34F72C E003C26C 8CA30030 */  lw        $v1, 0x30($a1)
/* 34F730 E003C270 24C80001 */  addiu     $t0, $a2, 1
/* 34F734 E003C274 04610005 */  bgez      $v1, .LE003C28C
/* 34F738 E003C278 ACA80034 */   sw       $t0, 0x34($a1)
/* 34F73C E003C27C 0C080128 */  jal       func_E02004A0
/* 34F740 E003C280 00000000 */   nop
/* 34F744 E003C284 0800F119 */  j         .LE003C464
/* 34F748 E003C288 00000000 */   nop
.LE003C28C:
/* 34F74C E003C28C 8C820008 */  lw        $v0, 8($a0)
/* 34F750 E003C290 24070001 */  addiu     $a3, $zero, 1
/* 34F754 E003C294 00E2102A */  slt       $v0, $a3, $v0
/* 34F758 E003C298 10400072 */  beqz      $v0, .LE003C464
/* 34F75C E003C29C 24A50040 */   addiu    $a1, $a1, 0x40
/* 34F760 E003C2A0 286C0006 */  slti      $t4, $v1, 6
/* 34F764 E003C2A4 286B0005 */  slti      $t3, $v1, 5
/* 34F768 E003C2A8 28CA0009 */  slti      $t2, $a2, 9
/* 34F76C E003C2AC 3C02E004 */  lui       $v0, %hi(D_E003CD1C)
/* 34F770 E003C2B0 2442CD1C */  addiu     $v0, $v0, %lo(D_E003CD1C)
/* 34F774 E003C2B4 00061880 */  sll       $v1, $a2, 2
/* 34F778 E003C2B8 00624821 */  addu      $t1, $v1, $v0
/* 34F77C E003C2BC 29080029 */  slti      $t0, $t0, 0x29
/* 34F780 E003C2C0 3C02E004 */  lui       $v0, %hi(D_E003CCD0)
/* 34F784 E003C2C4 2442CCD0 */  addiu     $v0, $v0, %lo(D_E003CCD0)
/* 34F788 E003C2C8 00C21821 */  addu      $v1, $a2, $v0
/* 34F78C E003C2CC 24A50038 */  addiu     $a1, $a1, 0x38
/* 34F790 E003C2D0 3C013FE8 */  lui       $at, 0x3fe8
/* 34F794 E003C2D4 44818800 */  mtc1      $at, $f17
/* 34F798 E003C2D8 44808000 */  mtc1      $zero, $f16
/* 34F79C E003C2DC 3C01E004 */  lui       $at, %hi(D_E003CD40)
/* 34F7A0 E003C2E0 D432CD40 */  ldc1      $f18, %lo(D_E003CD40)($at)
/* 34F7A4 E003C2E4 3C01E004 */  lui       $at, %hi(D_E003CD48)
/* 34F7A8 E003C2E8 D42ECD48 */  ldc1      $f14, %lo(D_E003CD48)($at)
.LE003C2EC:
/* 34F7AC E003C2EC 15800013 */  bnez      $t4, .LE003C33C
/* 34F7B0 E003C2F0 00000000 */   nop
/* 34F7B4 E003C2F4 C4A4FFE4 */  lwc1      $f4, -0x1c($a1)
/* 34F7B8 E003C2F8 46002121 */  cvt.d.s   $f4, $f4
/* 34F7BC E003C2FC 46302102 */  mul.d     $f4, $f4, $f16
/* 34F7C0 E003C300 00000000 */  nop
/* 34F7C4 E003C304 C4A2FFE8 */  lwc1      $f2, -0x18($a1)
/* 34F7C8 E003C308 460010A1 */  cvt.d.s   $f2, $f2
/* 34F7CC E003C30C 46301082 */  mul.d     $f2, $f2, $f16
/* 34F7D0 E003C310 00000000 */  nop
/* 34F7D4 E003C314 C4A0FFEC */  lwc1      $f0, -0x14($a1)
/* 34F7D8 E003C318 46000021 */  cvt.d.s   $f0, $f0
/* 34F7DC E003C31C 46300002 */  mul.d     $f0, $f0, $f16
/* 34F7E0 E003C320 00000000 */  nop
/* 34F7E4 E003C324 46202120 */  cvt.s.d   $f4, $f4
/* 34F7E8 E003C328 462010A0 */  cvt.s.d   $f2, $f2
/* 34F7EC E003C32C 46200020 */  cvt.s.d   $f0, $f0
/* 34F7F0 E003C330 E4A4FFE4 */  swc1      $f4, -0x1c($a1)
/* 34F7F4 E003C334 E4A2FFE8 */  swc1      $f2, -0x18($a1)
/* 34F7F8 E003C338 E4A0FFEC */  swc1      $f0, -0x14($a1)
.LE003C33C:
/* 34F7FC E003C33C 11600019 */  beqz      $t3, .LE003C3A4
/* 34F800 E003C340 00000000 */   nop
/* 34F804 E003C344 C4A6FFF4 */  lwc1      $f6, -0xc($a1)
/* 34F808 E003C348 468031A1 */  cvt.d.w   $f6, $f6
/* 34F80C E003C34C 46323182 */  mul.d     $f6, $f6, $f18
/* 34F810 E003C350 00000000 */  nop
/* 34F814 E003C354 C4A4FFE4 */  lwc1      $f4, -0x1c($a1)
/* 34F818 E003C358 46002121 */  cvt.d.s   $f4, $f4
/* 34F81C E003C35C 462E2102 */  mul.d     $f4, $f4, $f14
/* 34F820 E003C360 00000000 */  nop
/* 34F824 E003C364 C4A2FFE8 */  lwc1      $f2, -0x18($a1)
/* 34F828 E003C368 460010A1 */  cvt.d.s   $f2, $f2
/* 34F82C E003C36C 462E1082 */  mul.d     $f2, $f2, $f14
/* 34F830 E003C370 00000000 */  nop
/* 34F834 E003C374 C4A0FFEC */  lwc1      $f0, -0x14($a1)
/* 34F838 E003C378 46000021 */  cvt.d.s   $f0, $f0
/* 34F83C E003C37C 462E0002 */  mul.d     $f0, $f0, $f14
/* 34F840 E003C380 00000000 */  nop
/* 34F844 E003C384 4620350D */  trunc.w.d $f20, $f6
/* 34F848 E003C388 E4B4FFF4 */  swc1      $f20, -0xc($a1)
/* 34F84C E003C38C 46202120 */  cvt.s.d   $f4, $f4
/* 34F850 E003C390 462010A0 */  cvt.s.d   $f2, $f2
/* 34F854 E003C394 46200020 */  cvt.s.d   $f0, $f0
/* 34F858 E003C398 E4A4FFE4 */  swc1      $f4, -0x1c($a1)
/* 34F85C E003C39C E4A2FFE8 */  swc1      $f2, -0x18($a1)
/* 34F860 E003C3A0 E4A0FFEC */  swc1      $f0, -0x14($a1)
.LE003C3A4:
/* 34F864 E003C3A4 3C013F80 */  lui       $at, 0x3f80
/* 34F868 E003C3A8 44816000 */  mtc1      $at, $f12
/* 34F86C E003C3AC 11400002 */  beqz      $t2, .LE003C3B8
/* 34F870 E003C3B0 00000000 */   nop
/* 34F874 E003C3B4 C52C0000 */  lwc1      $f12, ($t1)
.LE003C3B8:
/* 34F878 E003C3B8 C4AAFFCC */  lwc1      $f10, -0x34($a1)
/* 34F87C E003C3BC 460C5282 */  mul.s     $f10, $f10, $f12
/* 34F880 E003C3C0 00000000 */  nop
/* 34F884 E003C3C4 C4A8FFD0 */  lwc1      $f8, -0x30($a1)
/* 34F888 E003C3C8 460C4202 */  mul.s     $f8, $f8, $f12
/* 34F88C E003C3CC 00000000 */  nop
/* 34F890 E003C3D0 C4A6FFCC */  lwc1      $f6, -0x34($a1)
/* 34F894 E003C3D4 C4A0FFE4 */  lwc1      $f0, -0x1c($a1)
/* 34F898 E003C3D8 C4A4FFD0 */  lwc1      $f4, -0x30($a1)
/* 34F89C E003C3DC 46003180 */  add.s     $f6, $f6, $f0
/* 34F8A0 E003C3E0 C4A0FFE8 */  lwc1      $f0, -0x18($a1)
/* 34F8A4 E003C3E4 C4A2FFD4 */  lwc1      $f2, -0x2c($a1)
/* 34F8A8 E003C3E8 46002100 */  add.s     $f4, $f4, $f0
/* 34F8AC E003C3EC C4A0FFEC */  lwc1      $f0, -0x14($a1)
/* 34F8B0 E003C3F0 46001080 */  add.s     $f2, $f2, $f0
/* 34F8B4 E003C3F4 C4A0FFD4 */  lwc1      $f0, -0x2c($a1)
/* 34F8B8 E003C3F8 E4A6FFCC */  swc1      $f6, -0x34($a1)
/* 34F8BC E003C3FC 460C0002 */  mul.s     $f0, $f0, $f12
/* 34F8C0 E003C400 00000000 */  nop
/* 34F8C4 E003C404 E4A4FFD0 */  swc1      $f4, -0x30($a1)
/* 34F8C8 E003C408 E4A2FFD4 */  swc1      $f2, -0x2c($a1)
/* 34F8CC E003C40C E4AAFFD8 */  swc1      $f10, -0x28($a1)
/* 34F8D0 E003C410 E4A8FFDC */  swc1      $f8, -0x24($a1)
/* 34F8D4 E003C414 1100000D */  beqz      $t0, .LE003C44C
/* 34F8D8 E003C418 E4A0FFE0 */   swc1     $f0, -0x20($a1)
/* 34F8DC E003C41C 90620000 */  lbu       $v0, ($v1)
/* 34F8E0 E003C420 3C01E004 */  lui       $at, %hi(D_E003CD50)
/* 34F8E4 E003C424 D422CD50 */  ldc1      $f2, %lo(D_E003CD50)($at)
/* 34F8E8 E003C428 44820000 */  mtc1      $v0, $f0
/* 34F8EC E003C42C 00000000 */  nop
/* 34F8F0 E003C430 46800020 */  cvt.s.w   $f0, $f0
/* 34F8F4 E003C434 46000021 */  cvt.d.s   $f0, $f0
/* 34F8F8 E003C438 46220002 */  mul.d     $f0, $f0, $f2
/* 34F8FC E003C43C 00000000 */  nop
/* 34F900 E003C440 46200020 */  cvt.s.d   $f0, $f0
/* 34F904 E003C444 0800F114 */  j         .LE003C450
/* 34F908 E003C448 E4A00000 */   swc1     $f0, ($a1)
.LE003C44C:
/* 34F90C E003C44C ACA00000 */  sw        $zero, ($a1)
.LE003C450:
/* 34F910 E003C450 24E70001 */  addiu     $a3, $a3, 1
/* 34F914 E003C454 8C820008 */  lw        $v0, 8($a0)
/* 34F918 E003C458 00E2102A */  slt       $v0, $a3, $v0
/* 34F91C E003C45C 1440FFA3 */  bnez      $v0, .LE003C2EC
/* 34F920 E003C460 24A50040 */   addiu    $a1, $a1, 0x40
.LE003C464:
/* 34F924 E003C464 8FBF0010 */  lw        $ra, 0x10($sp)
/* 34F928 E003C468 D7B40018 */  ldc1      $f20, 0x18($sp)
/* 34F92C E003C46C 03E00008 */  jr        $ra
/* 34F930 E003C470 27BD0020 */   addiu    $sp, $sp, 0x20
