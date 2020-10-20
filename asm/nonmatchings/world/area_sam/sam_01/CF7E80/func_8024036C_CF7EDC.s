.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024036C_CF7EDC
/* CF7EDC 8024036C 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* CF7EE0 80240370 AFB10014 */  sw        $s1, 0x14($sp)
/* CF7EE4 80240374 0080882D */  daddu     $s1, $a0, $zero
/* CF7EE8 80240378 AFBF0024 */  sw        $ra, 0x24($sp)
/* CF7EEC 8024037C AFB40020 */  sw        $s4, 0x20($sp)
/* CF7EF0 80240380 AFB3001C */  sw        $s3, 0x1c($sp)
/* CF7EF4 80240384 AFB20018 */  sw        $s2, 0x18($sp)
/* CF7EF8 80240388 AFB00010 */  sw        $s0, 0x10($sp)
/* CF7EFC 8024038C F7BC0048 */  sdc1      $f28, 0x48($sp)
/* CF7F00 80240390 F7BA0040 */  sdc1      $f26, 0x40($sp)
/* CF7F04 80240394 F7B80038 */  sdc1      $f24, 0x38($sp)
/* CF7F08 80240398 F7B60030 */  sdc1      $f22, 0x30($sp)
/* CF7F0C 8024039C F7B40028 */  sdc1      $f20, 0x28($sp)
/* CF7F10 802403A0 8E30000C */  lw        $s0, 0xc($s1)
/* CF7F14 802403A4 8E130000 */  lw        $s3, ($s0)
/* CF7F18 802403A8 26100004 */  addiu     $s0, $s0, 4
/* CF7F1C 802403AC 0C0B1EAF */  jal       get_variable
/* CF7F20 802403B0 0260282D */   daddu    $a1, $s3, $zero
/* CF7F24 802403B4 4482E000 */  mtc1      $v0, $f28
/* CF7F28 802403B8 00000000 */  nop       
/* CF7F2C 802403BC 4680E720 */  cvt.s.w   $f28, $f28
/* CF7F30 802403C0 8E140000 */  lw        $s4, ($s0)
/* CF7F34 802403C4 26100004 */  addiu     $s0, $s0, 4
/* CF7F38 802403C8 0220202D */  daddu     $a0, $s1, $zero
/* CF7F3C 802403CC 0C0B1EAF */  jal       get_variable
/* CF7F40 802403D0 0280282D */   daddu    $a1, $s4, $zero
/* CF7F44 802403D4 4482D000 */  mtc1      $v0, $f26
/* CF7F48 802403D8 00000000 */  nop       
/* CF7F4C 802403DC 4680D6A0 */  cvt.s.w   $f26, $f26
/* CF7F50 802403E0 8E100000 */  lw        $s0, ($s0)
/* CF7F54 802403E4 0220202D */  daddu     $a0, $s1, $zero
/* CF7F58 802403E8 0C0B1EAF */  jal       get_variable
/* CF7F5C 802403EC 0200282D */   daddu    $a1, $s0, $zero
/* CF7F60 802403F0 4482C000 */  mtc1      $v0, $f24
/* CF7F64 802403F4 00000000 */  nop       
/* CF7F68 802403F8 4680C620 */  cvt.s.w   $f24, $f24
/* CF7F6C 802403FC 3C128011 */  lui       $s2, %hi(gPlayerStatus)
/* CF7F70 80240400 2652EFC8 */  addiu     $s2, $s2, %lo(gPlayerStatus)
/* CF7F74 80240404 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* CF7F78 80240408 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* CF7F7C 8024040C C64200A8 */  lwc1      $f2, 0xa8($s2)
/* CF7F80 80240410 44800000 */  mtc1      $zero, $f0
/* CF7F84 80240414 00031080 */  sll       $v0, $v1, 2
/* CF7F88 80240418 00431021 */  addu      $v0, $v0, $v1
/* CF7F8C 8024041C 00021080 */  sll       $v0, $v0, 2
/* CF7F90 80240420 00431023 */  subu      $v0, $v0, $v1
/* CF7F94 80240424 000218C0 */  sll       $v1, $v0, 3
/* CF7F98 80240428 00431021 */  addu      $v0, $v0, $v1
/* CF7F9C 8024042C 000210C0 */  sll       $v0, $v0, 3
/* CF7FA0 80240430 46001032 */  c.eq.s    $f2, $f0
/* CF7FA4 80240434 3C01800B */  lui       $at, 0x800b
/* CF7FA8 80240438 00220821 */  addu      $at, $at, $v0
/* CF7FAC 8024043C C4361DEC */  lwc1      $f22, 0x1dec($at)
/* CF7FB0 80240440 45000005 */  bc1f      .L80240458
/* CF7FB4 80240444 00000000 */   nop      
/* CF7FB8 80240448 3C0142C8 */  lui       $at, 0x42c8
/* CF7FBC 8024044C 44810000 */  mtc1      $at, $f0
/* CF7FC0 80240450 0809011A */  j         .L80240468
/* CF7FC4 80240454 4600B581 */   sub.s    $f22, $f22, $f0
.L80240458:
/* CF7FC8 80240458 3C0142C8 */  lui       $at, 0x42c8
/* CF7FCC 8024045C 44810000 */  mtc1      $at, $f0
/* CF7FD0 80240460 00000000 */  nop       
/* CF7FD4 80240464 4600B580 */  add.s     $f22, $f22, $f0
.L80240468:
/* CF7FD8 80240468 0C00A6C9 */  jal       clamp_angle
/* CF7FDC 8024046C 4600B306 */   mov.s    $f12, $f22
/* CF7FE0 80240470 46000586 */  mov.s     $f22, $f0
/* CF7FE4 80240474 3C014170 */  lui       $at, 0x4170
/* CF7FE8 80240478 4481A000 */  mtc1      $at, $f20
/* CF7FEC 8024047C 0C00A8BB */  jal       sin_deg
/* CF7FF0 80240480 4600B306 */   mov.s    $f12, $f22
/* CF7FF4 80240484 46140002 */  mul.s     $f0, $f0, $f20
/* CF7FF8 80240488 00000000 */  nop       
/* CF7FFC 8024048C 864200B0 */  lh        $v0, 0xb0($s2)
/* CF8000 80240490 3C013F00 */  lui       $at, 0x3f00
/* CF8004 80240494 44812000 */  mtc1      $at, $f4
/* CF8008 80240498 44821000 */  mtc1      $v0, $f2
/* CF800C 8024049C 00000000 */  nop       
/* CF8010 802404A0 468010A0 */  cvt.s.w   $f2, $f2
/* CF8014 802404A4 46041082 */  mul.s     $f2, $f2, $f4
/* CF8018 802404A8 00000000 */  nop       
/* CF801C 802404AC 4600E700 */  add.s     $f28, $f28, $f0
/* CF8020 802404B0 4602D680 */  add.s     $f26, $f26, $f2
/* CF8024 802404B4 0C00A8D4 */  jal       cos_deg
/* CF8028 802404B8 4600B306 */   mov.s    $f12, $f22
/* CF802C 802404BC 46140002 */  mul.s     $f0, $f0, $f20
/* CF8030 802404C0 00000000 */  nop       
/* CF8034 802404C4 0220202D */  daddu     $a0, $s1, $zero
/* CF8038 802404C8 0260282D */  daddu     $a1, $s3, $zero
/* CF803C 802404CC 4600E18D */  trunc.w.s $f6, $f28
/* CF8040 802404D0 44063000 */  mfc1      $a2, $f6
/* CF8044 802404D4 0C0B2026 */  jal       set_variable
/* CF8048 802404D8 4600C601 */   sub.s    $f24, $f24, $f0
/* CF804C 802404DC 0220202D */  daddu     $a0, $s1, $zero
/* CF8050 802404E0 4600D18D */  trunc.w.s $f6, $f26
/* CF8054 802404E4 44063000 */  mfc1      $a2, $f6
/* CF8058 802404E8 0C0B2026 */  jal       set_variable
/* CF805C 802404EC 0280282D */   daddu    $a1, $s4, $zero
/* CF8060 802404F0 0220202D */  daddu     $a0, $s1, $zero
/* CF8064 802404F4 4600C18D */  trunc.w.s $f6, $f24
/* CF8068 802404F8 44063000 */  mfc1      $a2, $f6
/* CF806C 802404FC 0C0B2026 */  jal       set_variable
/* CF8070 80240500 0200282D */   daddu    $a1, $s0, $zero
/* CF8074 80240504 8FBF0024 */  lw        $ra, 0x24($sp)
/* CF8078 80240508 8FB40020 */  lw        $s4, 0x20($sp)
/* CF807C 8024050C 8FB3001C */  lw        $s3, 0x1c($sp)
/* CF8080 80240510 8FB20018 */  lw        $s2, 0x18($sp)
/* CF8084 80240514 8FB10014 */  lw        $s1, 0x14($sp)
/* CF8088 80240518 8FB00010 */  lw        $s0, 0x10($sp)
/* CF808C 8024051C D7BC0048 */  ldc1      $f28, 0x48($sp)
/* CF8090 80240520 D7BA0040 */  ldc1      $f26, 0x40($sp)
/* CF8094 80240524 D7B80038 */  ldc1      $f24, 0x38($sp)
/* CF8098 80240528 D7B60030 */  ldc1      $f22, 0x30($sp)
/* CF809C 8024052C D7B40028 */  ldc1      $f20, 0x28($sp)
/* CF80A0 80240530 24020002 */  addiu     $v0, $zero, 2
/* CF80A4 80240534 03E00008 */  jr        $ra
/* CF80A8 80240538 27BD0050 */   addiu    $sp, $sp, 0x50
