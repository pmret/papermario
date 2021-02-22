.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241768_DF8168
/* DF8168 80241768 27BDFEF0 */  addiu     $sp, $sp, -0x110
/* DF816C 8024176C AFB100CC */  sw        $s1, 0xcc($sp)
/* DF8170 80241770 0080882D */  daddu     $s1, $a0, $zero
/* DF8174 80241774 AFB000C8 */  sw        $s0, 0xc8($sp)
/* DF8178 80241778 00A0802D */  daddu     $s0, $a1, $zero
/* DF817C 8024177C AFBF00E0 */  sw        $ra, 0xe0($sp)
/* DF8180 80241780 AFB500DC */  sw        $s5, 0xdc($sp)
/* DF8184 80241784 AFB400D8 */  sw        $s4, 0xd8($sp)
/* DF8188 80241788 AFB300D4 */  sw        $s3, 0xd4($sp)
/* DF818C 8024178C AFB200D0 */  sw        $s2, 0xd0($sp)
/* DF8190 80241790 F7BC0108 */  sdc1      $f28, 0x108($sp)
/* DF8194 80241794 F7BA0100 */  sdc1      $f26, 0x100($sp)
/* DF8198 80241798 F7B800F8 */  sdc1      $f24, 0xf8($sp)
/* DF819C 8024179C F7B600F0 */  sdc1      $f22, 0xf0($sp)
/* DF81A0 802417A0 F7B400E8 */  sdc1      $f20, 0xe8($sp)
/* DF81A4 802417A4 C6140010 */  lwc1      $f20, 0x10($s0)
/* DF81A8 802417A8 4680A520 */  cvt.s.w   $f20, $f20
/* DF81AC 802417AC 4480B000 */  mtc1      $zero, $f22
/* DF81B0 802417B0 3C05437F */  lui       $a1, 0x437f
/* DF81B4 802417B4 8E220050 */  lw        $v0, 0x50($s1)
/* DF81B8 802417B8 4406B000 */  mfc1      $a2, $f22
/* DF81BC 802417BC C61C0014 */  lwc1      $f28, 0x14($s0)
/* DF81C0 802417C0 4680E720 */  cvt.s.w   $f28, $f28
/* DF81C4 802417C4 AFA20010 */  sw        $v0, 0x10($sp)
/* DF81C8 802417C8 8E070018 */  lw        $a3, 0x18($s0)
/* DF81CC 802417CC 0C00A8ED */  jal       update_lerp
/* DF81D0 802417D0 2404000B */   addiu    $a0, $zero, 0xb
/* DF81D4 802417D4 4600008D */  trunc.w.s $f2, $f0
/* DF81D8 802417D8 E7A20014 */  swc1      $f2, 0x14($sp)
/* DF81DC 802417DC 0000202D */  daddu     $a0, $zero, $zero
/* DF81E0 802417E0 24050007 */  addiu     $a1, $zero, 7
/* DF81E4 802417E4 240600FF */  addiu     $a2, $zero, 0xff
/* DF81E8 802417E8 00C0382D */  daddu     $a3, $a2, $zero
/* DF81EC 802417EC 00C0A82D */  daddu     $s5, $a2, $zero
/* DF81F0 802417F0 AFB50010 */  sw        $s5, 0x10($sp)
/* DF81F4 802417F4 0C04EAA7 */  jal       func_8013AA9C
/* DF81F8 802417F8 AFA00018 */   sw       $zero, 0x18($sp)
/* DF81FC 802417FC 8E220050 */  lw        $v0, 0x50($s1)
/* DF8200 80241800 4405B000 */  mfc1      $a1, $f22
/* DF8204 80241804 3C064270 */  lui       $a2, 0x4270
/* DF8208 80241808 AFA20010 */  sw        $v0, 0x10($sp)
/* DF820C 8024180C 8E070018 */  lw        $a3, 0x18($s0)
/* DF8210 80241810 0C00A8ED */  jal       update_lerp
/* DF8214 80241814 0000202D */   daddu    $a0, $zero, $zero
/* DF8218 80241818 27A20038 */  addiu     $v0, $sp, 0x38
/* DF821C 8024181C AFA20010 */  sw        $v0, 0x10($sp)
/* DF8220 80241820 8E040004 */  lw        $a0, 4($s0)
/* DF8224 80241824 8E050008 */  lw        $a1, 8($s0)
/* DF8228 80241828 8E060000 */  lw        $a2, ($s0)
/* DF822C 8024182C 8E07000C */  lw        $a3, 0xc($s0)
/* DF8230 80241830 0C04BA38 */  jal       func_8012E8E0
/* DF8234 80241834 46000606 */   mov.s    $f24, $f0
/* DF8238 80241838 93A20042 */  lbu       $v0, 0x42($sp)
/* DF823C 8024183C 3C013FE0 */  lui       $at, 0x3fe0
/* DF8240 80241840 4481D800 */  mtc1      $at, $f27
/* DF8244 80241844 4480D000 */  mtc1      $zero, $f26
/* DF8248 80241848 44820000 */  mtc1      $v0, $f0
/* DF824C 8024184C 00000000 */  nop
/* DF8250 80241850 46800021 */  cvt.d.w   $f0, $f0
/* DF8254 80241854 463A0002 */  mul.d     $f0, $f0, $f26
/* DF8258 80241858 00000000 */  nop
/* DF825C 8024185C 3C140001 */  lui       $s4, 1
/* DF8260 80241860 36941630 */  ori       $s4, $s4, 0x1630
/* DF8264 80241864 4600A521 */  cvt.d.s   $f20, $f20
/* DF8268 80241868 27B10048 */  addiu     $s1, $sp, 0x48
/* DF826C 8024186C 4600E707 */  neg.s     $f28, $f28
/* DF8270 80241870 4620A500 */  add.d     $f20, $f20, $f0
/* DF8274 80241874 4406E000 */  mfc1      $a2, $f28
/* DF8278 80241878 4407B000 */  mfc1      $a3, $f22
/* DF827C 8024187C 4620A520 */  cvt.s.d   $f20, $f20
/* DF8280 80241880 4405A000 */  mfc1      $a1, $f20
/* DF8284 80241884 0C019E40 */  jal       guTranslateF
/* DF8288 80241888 0220202D */   daddu    $a0, $s1, $zero
/* DF828C 8024188C 27B00088 */  addiu     $s0, $sp, 0x88
/* DF8290 80241890 4405C000 */  mfc1      $a1, $f24
/* DF8294 80241894 4406B000 */  mfc1      $a2, $f22
/* DF8298 80241898 3C073F80 */  lui       $a3, 0x3f80
/* DF829C 8024189C 0200202D */  daddu     $a0, $s0, $zero
/* DF82A0 802418A0 0C019EC8 */  jal       guRotateF
/* DF82A4 802418A4 AFA60010 */   sw       $a2, 0x10($sp)
/* DF82A8 802418A8 0200202D */  daddu     $a0, $s0, $zero
/* DF82AC 802418AC 0220282D */  daddu     $a1, $s1, $zero
/* DF82B0 802418B0 0C019D80 */  jal       guMtxCatF
/* DF82B4 802418B4 0220302D */   daddu    $a2, $s1, $zero
/* DF82B8 802418B8 0220202D */  daddu     $a0, $s1, $zero
/* DF82BC 802418BC 3C128007 */  lui       $s2, %hi(gMatrixListPos)
/* DF82C0 802418C0 265241F0 */  addiu     $s2, $s2, %lo(gMatrixListPos)
/* DF82C4 802418C4 3C13800A */  lui       $s3, %hi(gDisplayContext)
/* DF82C8 802418C8 2673A674 */  addiu     $s3, $s3, %lo(gDisplayContext)
/* DF82CC 802418CC 96450000 */  lhu       $a1, ($s2)
/* DF82D0 802418D0 8E620000 */  lw        $v0, ($s3)
/* DF82D4 802418D4 00052980 */  sll       $a1, $a1, 6
/* DF82D8 802418D8 00B42821 */  addu      $a1, $a1, $s4
/* DF82DC 802418DC 0C019D40 */  jal       guMtxF2L
/* DF82E0 802418E0 00452821 */   addu     $a1, $v0, $a1
/* DF82E4 802418E4 3C03DA38 */  lui       $v1, 0xda38
/* DF82E8 802418E8 34630002 */  ori       $v1, $v1, 2
/* DF82EC 802418EC 0000202D */  daddu     $a0, $zero, $zero
/* DF82F0 802418F0 27A50020 */  addiu     $a1, $sp, 0x20
/* DF82F4 802418F4 3C060001 */  lui       $a2, 1
/* DF82F8 802418F8 34C60040 */  ori       $a2, $a2, 0x40
/* DF82FC 802418FC 3C10800A */  lui       $s0, %hi(gMasterGfxPos)
/* DF8300 80241900 2610A66C */  addiu     $s0, $s0, %lo(gMasterGfxPos)
/* DF8304 80241904 0220382D */  daddu     $a3, $s1, $zero
/* DF8308 80241908 8E020000 */  lw        $v0, ($s0)
/* DF830C 8024190C 96480000 */  lhu       $t0, ($s2)
/* DF8310 80241910 0040482D */  daddu     $t1, $v0, $zero
/* DF8314 80241914 24420008 */  addiu     $v0, $v0, 8
/* DF8318 80241918 AE020000 */  sw        $v0, ($s0)
/* DF831C 8024191C 3102FFFF */  andi      $v0, $t0, 0xffff
/* DF8320 80241920 00021180 */  sll       $v0, $v0, 6
/* DF8324 80241924 00541021 */  addu      $v0, $v0, $s4
/* DF8328 80241928 AD230000 */  sw        $v1, ($t1)
/* DF832C 8024192C 8E630000 */  lw        $v1, ($s3)
/* DF8330 80241930 25080001 */  addiu     $t0, $t0, 1
/* DF8334 80241934 00621821 */  addu      $v1, $v1, $v0
/* DF8338 80241938 3C028000 */  lui       $v0, 0x8000
/* DF833C 8024193C 00621821 */  addu      $v1, $v1, $v0
/* DF8340 80241940 AD230004 */  sw        $v1, 4($t1)
/* DF8344 80241944 93A20042 */  lbu       $v0, 0x42($sp)
/* DF8348 80241948 8FA3003C */  lw        $v1, 0x3c($sp)
/* DF834C 8024194C 93A90040 */  lbu       $t1, 0x40($sp)
/* DF8350 80241950 93AA0041 */  lbu       $t2, 0x41($sp)
/* DF8354 80241954 44820000 */  mtc1      $v0, $f0
/* DF8358 80241958 00000000 */  nop
/* DF835C 8024195C 46800021 */  cvt.d.w   $f0, $f0
/* DF8360 80241960 8FA20038 */  lw        $v0, 0x38($sp)
/* DF8364 80241964 463A0002 */  mul.d     $f0, $f0, $f26
/* DF8368 80241968 00000000 */  nop
/* DF836C 8024196C A6480000 */  sh        $t0, ($s2)
/* DF8370 80241970 A7A0002E */  sh        $zero, 0x2e($sp)
/* DF8374 80241974 A3B50030 */  sb        $s5, 0x30($sp)
/* DF8378 80241978 AFA30024 */  sw        $v1, 0x24($sp)
/* DF837C 8024197C A7A90028 */  sh        $t1, 0x28($sp)
/* DF8380 80241980 A7AA002A */  sh        $t2, 0x2a($sp)
/* DF8384 80241984 AFA20020 */  sw        $v0, 0x20($sp)
/* DF8388 80241988 46200007 */  neg.d     $f0, $f0
/* DF838C 8024198C 4620008D */  trunc.w.d $f2, $f0
/* DF8390 80241990 44021000 */  mfc1      $v0, $f2
/* DF8394 80241994 0C04EBDC */  jal       func_8013AF70
/* DF8398 80241998 A7A2002C */   sh       $v0, 0x2c($sp)
/* DF839C 8024199C 3C04D838 */  lui       $a0, 0xd838
/* DF83A0 802419A0 8E020000 */  lw        $v0, ($s0)
/* DF83A4 802419A4 34840002 */  ori       $a0, $a0, 2
/* DF83A8 802419A8 0040182D */  daddu     $v1, $v0, $zero
/* DF83AC 802419AC 24420008 */  addiu     $v0, $v0, 8
/* DF83B0 802419B0 AE020000 */  sw        $v0, ($s0)
/* DF83B4 802419B4 24020040 */  addiu     $v0, $zero, 0x40
/* DF83B8 802419B8 AC640000 */  sw        $a0, ($v1)
/* DF83BC 802419BC AC620004 */  sw        $v0, 4($v1)
/* DF83C0 802419C0 8FBF00E0 */  lw        $ra, 0xe0($sp)
/* DF83C4 802419C4 8FB500DC */  lw        $s5, 0xdc($sp)
/* DF83C8 802419C8 8FB400D8 */  lw        $s4, 0xd8($sp)
/* DF83CC 802419CC 8FB300D4 */  lw        $s3, 0xd4($sp)
/* DF83D0 802419D0 8FB200D0 */  lw        $s2, 0xd0($sp)
/* DF83D4 802419D4 8FB100CC */  lw        $s1, 0xcc($sp)
/* DF83D8 802419D8 8FB000C8 */  lw        $s0, 0xc8($sp)
/* DF83DC 802419DC D7BC0108 */  ldc1      $f28, 0x108($sp)
/* DF83E0 802419E0 D7BA0100 */  ldc1      $f26, 0x100($sp)
/* DF83E4 802419E4 D7B800F8 */  ldc1      $f24, 0xf8($sp)
/* DF83E8 802419E8 D7B600F0 */  ldc1      $f22, 0xf0($sp)
/* DF83EC 802419EC D7B400E8 */  ldc1      $f20, 0xe8($sp)
/* DF83F0 802419F0 03E00008 */  jr        $ra
/* DF83F4 802419F4 27BD0110 */   addiu    $sp, $sp, 0x110
