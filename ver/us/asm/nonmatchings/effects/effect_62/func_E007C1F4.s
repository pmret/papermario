.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E007C1F4
/* 37D684 E007C1F4 27BDFEF0 */  addiu     $sp, $sp, -0x110
/* 37D688 E007C1F8 0080302D */  daddu     $a2, $a0, $zero
/* 37D68C E007C1FC 3C07DB06 */  lui       $a3, 0xdb06
/* 37D690 E007C200 34E70024 */  ori       $a3, $a3, 0x24
/* 37D694 E007C204 27A40018 */  addiu     $a0, $sp, 0x18
/* 37D698 E007C208 AFB300E4 */  sw        $s3, 0xe4($sp)
/* 37D69C E007C20C 3C130001 */  lui       $s3, 1
/* 37D6A0 E007C210 AFB400E8 */  sw        $s4, 0xe8($sp)
/* 37D6A4 E007C214 3C14800A */  lui       $s4, %hi(gMasterGfxPos)
/* 37D6A8 E007C218 2694A66C */  addiu     $s4, $s4, %lo(gMasterGfxPos)
/* 37D6AC E007C21C AFBF00F0 */  sw        $ra, 0xf0($sp)
/* 37D6B0 E007C220 AFB500EC */  sw        $s5, 0xec($sp)
/* 37D6B4 E007C224 AFB200E0 */  sw        $s2, 0xe0($sp)
/* 37D6B8 E007C228 AFB100DC */  sw        $s1, 0xdc($sp)
/* 37D6BC E007C22C AFB000D8 */  sw        $s0, 0xd8($sp)
/* 37D6C0 E007C230 F7B80108 */  sdc1      $f24, 0x108($sp)
/* 37D6C4 E007C234 F7B60100 */  sdc1      $f22, 0x100($sp)
/* 37D6C8 E007C238 F7B400F8 */  sdc1      $f20, 0xf8($sp)
/* 37D6CC E007C23C 8E830000 */  lw        $v1, ($s4)
/* 37D6D0 E007C240 8CD1000C */  lw        $s1, 0xc($a2)
/* 37D6D4 E007C244 3C014380 */  lui       $at, 0x4380
/* 37D6D8 E007C248 4481C000 */  mtc1      $at, $f24
/* 37D6DC E007C24C 0060282D */  daddu     $a1, $v1, $zero
/* 37D6E0 E007C250 24630008 */  addiu     $v1, $v1, 8
/* 37D6E4 E007C254 AE830000 */  sw        $v1, ($s4)
/* 37D6E8 E007C258 C6220020 */  lwc1      $f2, 0x20($s1)
/* 37D6EC E007C25C 3C02E700 */  lui       $v0, 0xe700
/* 37D6F0 E007C260 ACA20000 */  sw        $v0, ($a1)
/* 37D6F4 E007C264 24620008 */  addiu     $v0, $v1, 8
/* 37D6F8 E007C268 ACA00004 */  sw        $zero, 4($a1)
/* 37D6FC E007C26C AE820000 */  sw        $v0, ($s4)
/* 37D700 E007C270 24620010 */  addiu     $v0, $v1, 0x10
/* 37D704 E007C274 AC670000 */  sw        $a3, ($v1)
/* 37D708 E007C278 AE820000 */  sw        $v0, ($s4)
/* 37D70C E007C27C 24620018 */  addiu     $v0, $v1, 0x18
/* 37D710 E007C280 8CC50010 */  lw        $a1, 0x10($a2)
/* 37D714 E007C284 3C06DE00 */  lui       $a2, 0xde00
/* 37D718 E007C288 AE820000 */  sw        $v0, ($s4)
/* 37D71C E007C28C 8CA5001C */  lw        $a1, 0x1c($a1)
/* 37D720 E007C290 3C020900 */  lui       $v0, 0x900
/* 37D724 E007C294 24421300 */  addiu     $v0, $v0, 0x1300
/* 37D728 E007C298 AC62000C */  sw        $v0, 0xc($v1)
/* 37D72C E007C29C 3C028000 */  lui       $v0, 0x8000
/* 37D730 E007C2A0 AC660008 */  sw        $a2, 8($v1)
/* 37D734 E007C2A4 AC660010 */  sw        $a2, 0x10($v1)
/* 37D738 E007C2A8 00A22821 */  addu      $a1, $a1, $v0
/* 37D73C E007C2AC 4600110D */  trunc.w.s $f4, $f2
/* 37D740 E007C2B0 44022000 */  mfc1      $v0, $f4
/* 37D744 E007C2B4 00000000 */  nop
/* 37D748 E007C2B8 44820000 */  mtc1      $v0, $f0
/* 37D74C E007C2BC 00000000 */  nop
/* 37D750 E007C2C0 46800020 */  cvt.s.w   $f0, $f0
/* 37D754 E007C2C4 00021080 */  sll       $v0, $v0, 2
/* 37D758 E007C2C8 46001081 */  sub.s     $f2, $f2, $f0
/* 37D75C E007C2CC AC650004 */  sw        $a1, 4($v1)
/* 37D760 E007C2D0 3C01E008 */  lui       $at, %hi(D_E007C510)
/* 37D764 E007C2D4 00220821 */  addu      $at, $at, $v0
/* 37D768 E007C2D8 8C22C510 */  lw        $v0, %lo(D_E007C510)($at)
/* 37D76C E007C2DC 46181082 */  mul.s     $f2, $f2, $f24
/* 37D770 E007C2E0 00000000 */  nop
/* 37D774 E007C2E4 AC620014 */  sw        $v0, 0x14($v1)
/* 37D778 E007C2E8 8E250004 */  lw        $a1, 4($s1)
/* 37D77C E007C2EC 8E260008 */  lw        $a2, 8($s1)
/* 37D780 E007C2F0 8E27000C */  lw        $a3, 0xc($s1)
/* 37D784 E007C2F4 4600110D */  trunc.w.s $f4, $f2
/* 37D788 E007C2F8 44152000 */  mfc1      $s5, $f4
/* 37D78C E007C2FC 0C080108 */  jal       func_E0200420
/* 37D790 E007C300 36731630 */   ori      $s3, $s3, 0x1630
/* 37D794 E007C304 27B00058 */  addiu     $s0, $sp, 0x58
/* 37D798 E007C308 4480B000 */  mtc1      $zero, $f22
/* 37D79C E007C30C 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 37D7A0 E007C310 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 37D7A4 E007C314 3C013F80 */  lui       $at, 0x3f80
/* 37D7A8 E007C318 4481A000 */  mtc1      $at, $f20
/* 37D7AC E007C31C 00031080 */  sll       $v0, $v1, 2
/* 37D7B0 E007C320 00431021 */  addu      $v0, $v0, $v1
/* 37D7B4 E007C324 00021080 */  sll       $v0, $v0, 2
/* 37D7B8 E007C328 00431023 */  subu      $v0, $v0, $v1
/* 37D7BC E007C32C 000218C0 */  sll       $v1, $v0, 3
/* 37D7C0 E007C330 00431021 */  addu      $v0, $v0, $v1
/* 37D7C4 E007C334 000210C0 */  sll       $v0, $v0, 3
/* 37D7C8 E007C338 4406B000 */  mfc1      $a2, $f22
/* 37D7CC E007C33C 3C01800B */  lui       $at, %hi(gCameras+0x6C)
/* 37D7D0 E007C340 00220821 */  addu      $at, $at, $v0
/* 37D7D4 E007C344 C4201DEC */  lwc1      $f0, %lo(gCameras+0x6C)($at)
/* 37D7D8 E007C348 4407A000 */  mfc1      $a3, $f20
/* 37D7DC E007C34C 46000007 */  neg.s     $f0, $f0
/* 37D7E0 E007C350 44050000 */  mfc1      $a1, $f0
/* 37D7E4 E007C354 0200202D */  daddu     $a0, $s0, $zero
/* 37D7E8 E007C358 0C080104 */  jal       func_E0200410
/* 37D7EC E007C35C E7B60010 */   swc1     $f22, 0x10($sp)
/* 37D7F0 E007C360 0200202D */  daddu     $a0, $s0, $zero
/* 37D7F4 E007C364 27A50018 */  addiu     $a1, $sp, 0x18
/* 37D7F8 E007C368 27B00098 */  addiu     $s0, $sp, 0x98
/* 37D7FC E007C36C 0C080114 */  jal       func_E0200450
/* 37D800 E007C370 0200302D */   daddu    $a2, $s0, $zero
/* 37D804 E007C374 27A40018 */  addiu     $a0, $sp, 0x18
/* 37D808 E007C378 8E250010 */  lw        $a1, 0x10($s1)
/* 37D80C E007C37C 4407A000 */  mfc1      $a3, $f20
/* 37D810 E007C380 0C080110 */  jal       func_E0200440
/* 37D814 E007C384 00A0302D */   daddu    $a2, $a1, $zero
/* 37D818 E007C388 27A40018 */  addiu     $a0, $sp, 0x18
/* 37D81C E007C38C 0200282D */  daddu     $a1, $s0, $zero
/* 37D820 E007C390 0C080114 */  jal       func_E0200450
/* 37D824 E007C394 0200302D */   daddu    $a2, $s0, $zero
/* 37D828 E007C398 4406B000 */  mfc1      $a2, $f22
/* 37D82C E007C39C 27A40018 */  addiu     $a0, $sp, 0x18
/* 37D830 E007C3A0 E7B40010 */  swc1      $f20, 0x10($sp)
/* 37D834 E007C3A4 8E250024 */  lw        $a1, 0x24($s1)
/* 37D838 E007C3A8 0C080104 */  jal       func_E0200410
/* 37D83C E007C3AC 00C0382D */   daddu    $a3, $a2, $zero
/* 37D840 E007C3B0 27A40018 */  addiu     $a0, $sp, 0x18
/* 37D844 E007C3B4 0200282D */  daddu     $a1, $s0, $zero
/* 37D848 E007C3B8 0C080114 */  jal       func_E0200450
/* 37D84C E007C3BC 0200302D */   daddu    $a2, $s0, $zero
/* 37D850 E007C3C0 0200202D */  daddu     $a0, $s0, $zero
/* 37D854 E007C3C4 3C108007 */  lui       $s0, %hi(gMatrixListPos)
/* 37D858 E007C3C8 261041F0 */  addiu     $s0, $s0, %lo(gMatrixListPos)
/* 37D85C E007C3CC 3C12800A */  lui       $s2, %hi(gDisplayContext)
/* 37D860 E007C3D0 2652A674 */  addiu     $s2, $s2, %lo(gDisplayContext)
/* 37D864 E007C3D4 96050000 */  lhu       $a1, ($s0)
/* 37D868 E007C3D8 8E420000 */  lw        $v0, ($s2)
/* 37D86C E007C3DC 00052980 */  sll       $a1, $a1, 6
/* 37D870 E007C3E0 00B32821 */  addu      $a1, $a1, $s3
/* 37D874 E007C3E4 0C080118 */  jal       func_E0200460
/* 37D878 E007C3E8 00452821 */   addu     $a1, $v0, $a1
/* 37D87C E007C3EC 8E850000 */  lw        $a1, ($s4)
/* 37D880 E007C3F0 3C014080 */  lui       $at, 0x4080
/* 37D884 E007C3F4 44810000 */  mtc1      $at, $f0
/* 37D888 E007C3F8 00A0202D */  daddu     $a0, $a1, $zero
/* 37D88C E007C3FC 24A50008 */  addiu     $a1, $a1, 8
/* 37D890 E007C400 AE850000 */  sw        $a1, ($s4)
/* 37D894 E007C404 96020000 */  lhu       $v0, ($s0)
/* 37D898 E007C408 3C03DA38 */  lui       $v1, 0xda38
/* 37D89C E007C40C AC830000 */  sw        $v1, ($a0)
/* 37D8A0 E007C410 24430001 */  addiu     $v1, $v0, 1
/* 37D8A4 E007C414 3042FFFF */  andi      $v0, $v0, 0xffff
/* 37D8A8 E007C418 00021180 */  sll       $v0, $v0, 6
/* 37D8AC E007C41C A6030000 */  sh        $v1, ($s0)
/* 37D8B0 E007C420 8E430000 */  lw        $v1, ($s2)
/* 37D8B4 E007C424 00531021 */  addu      $v0, $v0, $s3
/* 37D8B8 E007C428 00621821 */  addu      $v1, $v1, $v0
/* 37D8BC E007C42C AC830004 */  sw        $v1, 4($a0)
/* 37D8C0 E007C430 C6220020 */  lwc1      $f2, 0x20($s1)
/* 37D8C4 E007C434 4602003C */  c.lt.s    $f0, $f2
/* 37D8C8 E007C438 00000000 */  nop
/* 37D8CC E007C43C 45000006 */  bc1f      .LE007C458
/* 37D8D0 E007C440 24A20008 */   addiu    $v0, $a1, 8
/* 37D8D4 E007C444 AE820000 */  sw        $v0, ($s4)
/* 37D8D8 E007C448 3C02FA00 */  lui       $v0, 0xfa00
/* 37D8DC E007C44C ACA20000 */  sw        $v0, ($a1)
/* 37D8E0 E007C450 0801F11A */  j         .LE007C468
/* 37D8E4 E007C454 2402FF7F */   addiu    $v0, $zero, -0x81
.LE007C458:
/* 37D8E8 E007C458 AE820000 */  sw        $v0, ($s4)
/* 37D8EC E007C45C 3C02FA00 */  lui       $v0, 0xfa00
/* 37D8F0 E007C460 ACA20000 */  sw        $v0, ($a1)
/* 37D8F4 E007C464 2402807F */  addiu     $v0, $zero, -0x7f81
.LE007C468:
/* 37D8F8 E007C468 ACA20004 */  sw        $v0, 4($a1)
/* 37D8FC E007C46C 3C07D838 */  lui       $a3, 0xd838
/* 37D900 E007C470 3C05800A */  lui       $a1, %hi(gMasterGfxPos)
/* 37D904 E007C474 24A5A66C */  addiu     $a1, $a1, %lo(gMasterGfxPos)
/* 37D908 E007C478 34E70002 */  ori       $a3, $a3, 2
/* 37D90C E007C47C 3C02FB00 */  lui       $v0, 0xfb00
/* 37D910 E007C480 8CA40000 */  lw        $a0, ($a1)
/* 37D914 E007C484 24038B00 */  addiu     $v1, $zero, -0x7500
/* 37D918 E007C488 0080302D */  daddu     $a2, $a0, $zero
/* 37D91C E007C48C 24840008 */  addiu     $a0, $a0, 8
/* 37D920 E007C490 ACA40000 */  sw        $a0, ($a1)
/* 37D924 E007C494 ACC20000 */  sw        $v0, ($a2)
/* 37D928 E007C498 32A200FF */  andi      $v0, $s5, 0xff
/* 37D92C E007C49C 00431025 */  or        $v0, $v0, $v1
/* 37D930 E007C4A0 ACC20004 */  sw        $v0, 4($a2)
/* 37D934 E007C4A4 24820008 */  addiu     $v0, $a0, 8
/* 37D938 E007C4A8 ACA20000 */  sw        $v0, ($a1)
/* 37D93C E007C4AC 3C02DE00 */  lui       $v0, 0xde00
/* 37D940 E007C4B0 AC820000 */  sw        $v0, ($a0)
/* 37D944 E007C4B4 3C020900 */  lui       $v0, 0x900
/* 37D948 E007C4B8 244217B0 */  addiu     $v0, $v0, 0x17b0
/* 37D94C E007C4BC AC820004 */  sw        $v0, 4($a0)
/* 37D950 E007C4C0 24820010 */  addiu     $v0, $a0, 0x10
/* 37D954 E007C4C4 ACA20000 */  sw        $v0, ($a1)
/* 37D958 E007C4C8 24020040 */  addiu     $v0, $zero, 0x40
/* 37D95C E007C4CC AC870008 */  sw        $a3, 8($a0)
/* 37D960 E007C4D0 AC82000C */  sw        $v0, 0xc($a0)
/* 37D964 E007C4D4 8FBF00F0 */  lw        $ra, 0xf0($sp)
/* 37D968 E007C4D8 8FB500EC */  lw        $s5, 0xec($sp)
/* 37D96C E007C4DC 8FB400E8 */  lw        $s4, 0xe8($sp)
/* 37D970 E007C4E0 8FB300E4 */  lw        $s3, 0xe4($sp)
/* 37D974 E007C4E4 8FB200E0 */  lw        $s2, 0xe0($sp)
/* 37D978 E007C4E8 8FB100DC */  lw        $s1, 0xdc($sp)
/* 37D97C E007C4EC 8FB000D8 */  lw        $s0, 0xd8($sp)
/* 37D980 E007C4F0 D7B80108 */  ldc1      $f24, 0x108($sp)
/* 37D984 E007C4F4 D7B60100 */  ldc1      $f22, 0x100($sp)
/* 37D988 E007C4F8 D7B400F8 */  ldc1      $f20, 0xf8($sp)
/* 37D98C E007C4FC 03E00008 */  jr        $ra
/* 37D990 E007C500 27BD0110 */   addiu    $sp, $sp, 0x110
/* 37D994 E007C504 00000000 */  nop
/* 37D998 E007C508 00000000 */  nop
/* 37D99C E007C50C 00000000 */  nop
