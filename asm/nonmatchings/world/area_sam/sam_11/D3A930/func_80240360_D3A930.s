.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240360_D3A930
/* D3A930 80240360 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D3A934 80240364 AFB00018 */  sw        $s0, 0x18($sp)
/* D3A938 80240368 0080802D */  daddu     $s0, $a0, $zero
/* D3A93C 8024036C 10A00018 */  beqz      $a1, .L802403D0
/* D3A940 80240370 AFBF001C */   sw       $ra, 0x1c($sp)
/* D3A944 80240374 2405FFFF */  addiu     $a1, $zero, -1
/* D3A948 80240378 24060001 */  addiu     $a2, $zero, 1
/* D3A94C 8024037C 9604008A */  lhu       $a0, 0x8a($s0)
/* D3A950 80240380 0C046E54 */  jal       func_8011B950
/* D3A954 80240384 00C0382D */   daddu    $a3, $a2, $zero
/* D3A958 80240388 27A40010 */  addiu     $a0, $sp, 0x10
/* D3A95C 8024038C 27A50011 */  addiu     $a1, $sp, 0x11
/* D3A960 80240390 27A60012 */  addiu     $a2, $sp, 0x12
/* D3A964 80240394 27A70013 */  addiu     $a3, $sp, 0x13
/* D3A968 80240398 0C046FA0 */  jal       get_background_color_blend
/* D3A96C 8024039C AE000070 */   sw       $zero, 0x70($s0)
/* D3A970 802403A0 8E040084 */  lw        $a0, 0x84($s0)
/* D3A974 802403A4 14800005 */  bnez      $a0, .L802403BC
/* D3A978 802403A8 24020001 */   addiu    $v0, $zero, 1
/* D3A97C 802403AC 93A30013 */  lbu       $v1, 0x13($sp)
/* D3A980 802403B0 240200FF */  addiu     $v0, $zero, 0xff
/* D3A984 802403B4 10620058 */  beq       $v1, $v0, .L80240518
/* D3A988 802403B8 24020001 */   addiu    $v0, $zero, 1
.L802403BC:
/* D3A98C 802403BC 14820004 */  bne       $a0, $v0, .L802403D0
/* D3A990 802403C0 00000000 */   nop
/* D3A994 802403C4 93A20013 */  lbu       $v0, 0x13($sp)
/* D3A998 802403C8 10400054 */  beqz      $v0, .L8024051C
/* D3A99C 802403CC 24020002 */   addiu    $v0, $zero, 2
.L802403D0:
/* D3A9A0 802403D0 8E020070 */  lw        $v0, 0x70($s0)
/* D3A9A4 802403D4 8E03008C */  lw        $v1, 0x8c($s0)
/* D3A9A8 802403D8 00431021 */  addu      $v0, $v0, $v1
/* D3A9AC 802403DC AE020070 */  sw        $v0, 0x70($s0)
/* D3A9B0 802403E0 28420100 */  slti      $v0, $v0, 0x100
/* D3A9B4 802403E4 14400002 */  bnez      $v0, .L802403F0
/* D3A9B8 802403E8 240200FF */   addiu    $v0, $zero, 0xff
/* D3A9BC 802403EC AE020070 */  sw        $v0, 0x70($s0)
.L802403F0:
/* D3A9C0 802403F0 8E020084 */  lw        $v0, 0x84($s0)
/* D3A9C4 802403F4 14400004 */  bnez      $v0, .L80240408
/* D3A9C8 802403F8 0000202D */   daddu    $a0, $zero, $zero
/* D3A9CC 802403FC 92020073 */  lbu       $v0, 0x73($s0)
/* D3A9D0 80240400 08090105 */  j         .L80240414
/* D3A9D4 80240404 0080282D */   daddu    $a1, $a0, $zero
.L80240408:
/* D3A9D8 80240408 92020073 */  lbu       $v0, 0x73($s0)
/* D3A9DC 8024040C 00021027 */  nor       $v0, $zero, $v0
/* D3A9E0 80240410 0080282D */  daddu     $a1, $a0, $zero
.L80240414:
/* D3A9E4 80240414 A3A20013 */  sb        $v0, 0x13($sp)
/* D3A9E8 80240418 304700FF */  andi      $a3, $v0, 0xff
/* D3A9EC 8024041C 0C046F97 */  jal       set_background_color_blend
/* D3A9F0 80240420 0080302D */   daddu    $a2, $a0, $zero
/* D3A9F4 80240424 240600FF */  addiu     $a2, $zero, 0xff
/* D3A9F8 80240428 93A20013 */  lbu       $v0, 0x13($sp)
/* D3A9FC 8024042C 3C038024 */  lui       $v1, %hi(D_80243CC0_D3E290)
/* D3AA00 80240430 8C633CC0 */  lw        $v1, %lo(D_80243CC0_D3E290)($v1)
/* D3AA04 80240434 00C23023 */  subu      $a2, $a2, $v0
/* D3AA08 80240438 00660018 */  mult      $v1, $a2
/* D3AA0C 8024043C 00001812 */  mflo      $v1
/* D3AA10 80240440 3C058024 */  lui       $a1, %hi(D_80243CC4_D3E294)
/* D3AA14 80240444 8CA53CC4 */  lw        $a1, %lo(D_80243CC4_D3E294)($a1)
/* D3AA18 80240448 00A60018 */  mult      $a1, $a2
/* D3AA1C 8024044C 00002812 */  mflo      $a1
/* D3AA20 80240450 3C078080 */  lui       $a3, 0x8080
/* D3AA24 80240454 34E78081 */  ori       $a3, $a3, 0x8081
/* D3AA28 80240458 00670018 */  mult      $v1, $a3
/* D3AA2C 8024045C 00005010 */  mfhi      $t2
/* D3AA30 80240460 00000000 */  nop
/* D3AA34 80240464 00000000 */  nop
/* D3AA38 80240468 00A70018 */  mult      $a1, $a3
/* D3AA3C 8024046C 00004010 */  mfhi      $t0
/* D3AA40 80240470 3C048024 */  lui       $a0, %hi(D_80243CC8_D3E298)
/* D3AA44 80240474 8C843CC8 */  lw        $a0, %lo(D_80243CC8_D3E298)($a0)
/* D3AA48 80240478 00860018 */  mult      $a0, $a2
/* D3AA4C 8024047C 01431021 */  addu      $v0, $t2, $v1
/* D3AA50 80240480 000211C3 */  sra       $v0, $v0, 7
/* D3AA54 80240484 00031FC3 */  sra       $v1, $v1, 0x1f
/* D3AA58 80240488 00431023 */  subu      $v0, $v0, $v1
/* D3AA5C 8024048C 00002012 */  mflo      $a0
/* D3AA60 80240490 A3A20010 */  sb        $v0, 0x10($sp)
/* D3AA64 80240494 01051021 */  addu      $v0, $t0, $a1
/* D3AA68 80240498 00870018 */  mult      $a0, $a3
/* D3AA6C 8024049C 000211C3 */  sra       $v0, $v0, 7
/* D3AA70 802404A0 00052FC3 */  sra       $a1, $a1, 0x1f
/* D3AA74 802404A4 00451023 */  subu      $v0, $v0, $a1
/* D3AA78 802404A8 A3A20011 */  sb        $v0, 0x11($sp)
/* D3AA7C 802404AC 00001810 */  mfhi      $v1
/* D3AA80 802404B0 00641021 */  addu      $v0, $v1, $a0
/* D3AA84 802404B4 000211C3 */  sra       $v0, $v0, 7
/* D3AA88 802404B8 000427C3 */  sra       $a0, $a0, 0x1f
/* D3AA8C 802404BC 00441023 */  subu      $v0, $v0, $a0
/* D3AA90 802404C0 A3A20012 */  sb        $v0, 0x12($sp)
/* D3AA94 802404C4 304500FF */  andi      $a1, $v0, 0xff
/* D3AA98 802404C8 93A30010 */  lbu       $v1, 0x10($sp)
/* D3AA9C 802404CC 93A40011 */  lbu       $a0, 0x11($sp)
/* D3AAA0 802404D0 3C02800B */  lui       $v0, %hi(gCameras)
/* D3AAA4 802404D4 24421D80 */  addiu     $v0, $v0, %lo(gCameras)
/* D3AAA8 802404D8 A4450030 */  sh        $a1, 0x30($v0)
/* D3AAAC 802404DC A443002C */  sh        $v1, 0x2c($v0)
/* D3AAB0 802404E0 A444002E */  sh        $a0, 0x2e($v0)
/* D3AAB4 802404E4 8E020070 */  lw        $v0, 0x70($s0)
/* D3AAB8 802404E8 284200FF */  slti      $v0, $v0, 0xff
/* D3AABC 802404EC 1440000B */  bnez      $v0, .L8024051C
/* D3AAC0 802404F0 0000102D */   daddu    $v0, $zero, $zero
/* D3AAC4 802404F4 8E030084 */  lw        $v1, 0x84($s0)
/* D3AAC8 802404F8 24020001 */  addiu     $v0, $zero, 1
/* D3AACC 802404FC 54620007 */  bnel      $v1, $v0, .L8024051C
/* D3AAD0 80240500 24020002 */   addiu    $v0, $zero, 2
/* D3AAD4 80240504 9604008A */  lhu       $a0, 0x8a($s0)
/* D3AAD8 80240508 2405FFFF */  addiu     $a1, $zero, -1
/* D3AADC 8024050C 0000302D */  daddu     $a2, $zero, $zero
/* D3AAE0 80240510 0C046E54 */  jal       func_8011B950
/* D3AAE4 80240514 0040382D */   daddu    $a3, $v0, $zero
.L80240518:
/* D3AAE8 80240518 24020002 */  addiu     $v0, $zero, 2
.L8024051C:
/* D3AAEC 8024051C 8FBF001C */  lw        $ra, 0x1c($sp)
/* D3AAF0 80240520 8FB00018 */  lw        $s0, 0x18($sp)
/* D3AAF4 80240524 03E00008 */  jr        $ra
/* D3AAF8 80240528 27BD0020 */   addiu    $sp, $sp, 0x20
