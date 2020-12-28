.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00B8208
/* 3B7D88 E00B8208 27BDFEF8 */  addiu     $sp, $sp, -0x108
/* 3B7D8C E00B820C 0080302D */  daddu     $a2, $a0, $zero
/* 3B7D90 E00B8210 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 3B7D94 E00B8214 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 3B7D98 E00B8218 3C04800B */  lui       $a0, %hi(gCameras)
/* 3B7D9C E00B821C 24841D80 */  addiu     $a0, $a0, %lo(gCameras)
/* 3B7DA0 E00B8220 AFBF00EC */  sw        $ra, 0xec($sp)
/* 3B7DA4 E00B8224 AFBE00E8 */  sw        $fp, 0xe8($sp)
/* 3B7DA8 E00B8228 AFB700E4 */  sw        $s7, 0xe4($sp)
/* 3B7DAC E00B822C AFB600E0 */  sw        $s6, 0xe0($sp)
/* 3B7DB0 E00B8230 AFB500DC */  sw        $s5, 0xdc($sp)
/* 3B7DB4 E00B8234 AFB400D8 */  sw        $s4, 0xd8($sp)
/* 3B7DB8 E00B8238 AFB300D4 */  sw        $s3, 0xd4($sp)
/* 3B7DBC E00B823C AFB200D0 */  sw        $s2, 0xd0($sp)
/* 3B7DC0 E00B8240 AFB100CC */  sw        $s1, 0xcc($sp)
/* 3B7DC4 E00B8244 AFB000C8 */  sw        $s0, 0xc8($sp)
/* 3B7DC8 E00B8248 F7B80100 */  sdc1      $f24, 0x100($sp)
/* 3B7DCC E00B824C F7B600F8 */  sdc1      $f22, 0xf8($sp)
/* 3B7DD0 E00B8250 F7B400F0 */  sdc1      $f20, 0xf0($sp)
/* 3B7DD4 E00B8254 8CD3000C */  lw        $s3, 0xc($a2)
/* 3B7DD8 E00B8258 00031080 */  sll       $v0, $v1, 2
/* 3B7DDC E00B825C 00431021 */  addu      $v0, $v0, $v1
/* 3B7DE0 E00B8260 00021080 */  sll       $v0, $v0, 2
/* 3B7DE4 E00B8264 00431023 */  subu      $v0, $v0, $v1
/* 3B7DE8 E00B8268 000218C0 */  sll       $v1, $v0, 3
/* 3B7DEC E00B826C 00431021 */  addu      $v0, $v0, $v1
/* 3B7DF0 E00B8270 8E7E0014 */  lw        $fp, 0x14($s3)
/* 3B7DF4 E00B8274 8E6A0010 */  lw        $t2, 0x10($s3)
/* 3B7DF8 E00B8278 000210C0 */  sll       $v0, $v0, 3
/* 3B7DFC E00B827C AFAA0098 */  sw        $t2, 0x98($sp)
/* 3B7E00 E00B8280 8E6A0024 */  lw        $t2, 0x24($s3)
/* 3B7E04 E00B8284 0044B821 */  addu      $s7, $v0, $a0
/* 3B7E08 E00B8288 AFAA00A0 */  sw        $t2, 0xa0($sp)
/* 3B7E0C E00B828C 8E6A0018 */  lw        $t2, 0x18($s3)
/* 3B7E10 E00B8290 8E620000 */  lw        $v0, ($s3)
/* 3B7E14 E00B8294 AFAA00A4 */  sw        $t2, 0xa4($sp)
/* 3B7E18 E00B8298 8E6A001C */  lw        $t2, 0x1c($s3)
/* 3B7E1C E00B829C AFAA00A8 */  sw        $t2, 0xa8($sp)
/* 3B7E20 E00B82A0 8E6A0020 */  lw        $t2, 0x20($s3)
/* 3B7E24 E00B82A4 14400007 */  bnez      $v0, .LE00B82C4
/* 3B7E28 E00B82A8 AFAA00AC */   sw       $t2, 0xac($sp)
/* 3B7E2C E00B82AC 240A0003 */  addiu     $t2, $zero, 3
/* 3B7E30 E00B82B0 AFAA00B0 */  sw        $t2, 0xb0($sp)
/* 3B7E34 E00B82B4 3C0AE00C */  lui       $t2, %hi(D_E00B8900)
/* 3B7E38 E00B82B8 254A8900 */  addiu     $t2, $t2, %lo(D_E00B8900)
/* 3B7E3C E00B82BC 0802E0B6 */  j         .LE00B82D8
/* 3B7E40 E00B82C0 24160014 */   addiu    $s6, $zero, 0x14
.LE00B82C4:
/* 3B7E44 E00B82C4 2416000B */  addiu     $s6, $zero, 0xb
/* 3B7E48 E00B82C8 240A0003 */  addiu     $t2, $zero, 3
/* 3B7E4C E00B82CC AFAA00B0 */  sw        $t2, 0xb0($sp)
/* 3B7E50 E00B82D0 3C0AE00C */  lui       $t2, %hi(D_E00B8B58)
/* 3B7E54 E00B82D4 254A8B58 */  addiu     $t2, $t2, %lo(D_E00B8B58)
.LE00B82D8:
/* 3B7E58 E00B82D8 AFAA00B4 */  sw        $t2, 0xb4($sp)
/* 3B7E5C E00B82DC 3C05DB06 */  lui       $a1, 0xdb06
/* 3B7E60 E00B82E0 34A50024 */  ori       $a1, $a1, 0x24
/* 3B7E64 E00B82E4 27A40018 */  addiu     $a0, $sp, 0x18
/* 3B7E68 E00B82E8 3C14800A */  lui       $s4, %hi(D_8009A66C)
/* 3B7E6C E00B82EC 2694A66C */  addiu     $s4, $s4, %lo(D_8009A66C)
/* 3B7E70 E00B82F0 3C120001 */  lui       $s2, 1
/* 3B7E74 E00B82F4 8E880000 */  lw        $t0, ($s4)
/* 3B7E78 E00B82F8 3C02E700 */  lui       $v0, 0xe700
/* 3B7E7C E00B82FC 0100182D */  daddu     $v1, $t0, $zero
/* 3B7E80 E00B8300 25080008 */  addiu     $t0, $t0, 8
/* 3B7E84 E00B8304 AC620000 */  sw        $v0, ($v1)
/* 3B7E88 E00B8308 AC600004 */  sw        $zero, 4($v1)
/* 3B7E8C E00B830C AD050000 */  sw        $a1, ($t0)
/* 3B7E90 E00B8310 8CC20010 */  lw        $v0, 0x10($a2)
/* 3B7E94 E00B8314 36521630 */  ori       $s2, $s2, 0x1630
/* 3B7E98 E00B8318 AE880000 */  sw        $t0, ($s4)
/* 3B7E9C E00B831C 8C42001C */  lw        $v0, 0x1c($v0)
/* 3B7EA0 E00B8320 3C038000 */  lui       $v1, 0x8000
/* 3B7EA4 E00B8324 00431021 */  addu      $v0, $v0, $v1
/* 3B7EA8 E00B8328 AD020004 */  sw        $v0, 4($t0)
/* 3B7EAC E00B832C 8E650004 */  lw        $a1, 4($s3)
/* 3B7EB0 E00B8330 8E660008 */  lw        $a2, 8($s3)
/* 3B7EB4 E00B8334 8E67000C */  lw        $a3, 0xc($s3)
/* 3B7EB8 E00B8338 25080008 */  addiu     $t0, $t0, 8
/* 3B7EBC E00B833C 0C080108 */  jal       func_E0200420
/* 3B7EC0 E00B8340 AE880000 */   sw       $t0, ($s4)
/* 3B7EC4 E00B8344 27B50058 */  addiu     $s5, $sp, 0x58
/* 3B7EC8 E00B8348 8E650034 */  lw        $a1, 0x34($s3)
/* 3B7ECC E00B834C 02A0202D */  daddu     $a0, $s5, $zero
/* 3B7ED0 E00B8350 00A0302D */  daddu     $a2, $a1, $zero
/* 3B7ED4 E00B8354 0C080110 */  jal       func_E0200440
/* 3B7ED8 E00B8358 00A0382D */   daddu    $a3, $a1, $zero
/* 3B7EDC E00B835C 02A0202D */  daddu     $a0, $s5, $zero
/* 3B7EE0 E00B8360 27A50018 */  addiu     $a1, $sp, 0x18
/* 3B7EE4 E00B8364 0C080114 */  jal       func_E0200450
/* 3B7EE8 E00B8368 00A0302D */   daddu    $a2, $a1, $zero
/* 3B7EEC E00B836C 27A40018 */  addiu     $a0, $sp, 0x18
/* 3B7EF0 E00B8370 3C108007 */  lui       $s0, %hi(D_800741F0)
/* 3B7EF4 E00B8374 261041F0 */  addiu     $s0, $s0, %lo(D_800741F0)
/* 3B7EF8 E00B8378 3C11800A */  lui       $s1, %hi(D_8009A674)
/* 3B7EFC E00B837C 2631A674 */  addiu     $s1, $s1, %lo(D_8009A674)
/* 3B7F00 E00B8380 96050000 */  lhu       $a1, ($s0)
/* 3B7F04 E00B8384 8E220000 */  lw        $v0, ($s1)
/* 3B7F08 E00B8388 00052980 */  sll       $a1, $a1, 6
/* 3B7F0C E00B838C 00B22821 */  addu      $a1, $a1, $s2
/* 3B7F10 E00B8390 0C080118 */  jal       func_E0200460
/* 3B7F14 E00B8394 00452821 */   addu     $a1, $v0, $a1
/* 3B7F18 E00B8398 3C03DA38 */  lui       $v1, 0xda38
/* 3B7F1C E00B839C 34630002 */  ori       $v1, $v1, 2
/* 3B7F20 E00B83A0 3C09DA38 */  lui       $t1, 0xda38
/* 3B7F24 E00B83A4 35290001 */  ori       $t1, $t1, 1
/* 3B7F28 E00B83A8 27A40018 */  addiu     $a0, $sp, 0x18
/* 3B7F2C E00B83AC 4480B000 */  mtc1      $zero, $f22
/* 3B7F30 E00B83B0 8E880000 */  lw        $t0, ($s4)
/* 3B7F34 E00B83B4 96020000 */  lhu       $v0, ($s0)
/* 3B7F38 E00B83B8 3C013F80 */  lui       $at, 0x3f80
/* 3B7F3C E00B83BC 4481A000 */  mtc1      $at, $f20
/* 3B7F40 E00B83C0 0100282D */  daddu     $a1, $t0, $zero
/* 3B7F44 E00B83C4 25080008 */  addiu     $t0, $t0, 8
/* 3B7F48 E00B83C8 AE880000 */  sw        $t0, ($s4)
/* 3B7F4C E00B83CC ACA30000 */  sw        $v1, ($a1)
/* 3B7F50 E00B83D0 24430001 */  addiu     $v1, $v0, 1
/* 3B7F54 E00B83D4 3042FFFF */  andi      $v0, $v0, 0xffff
/* 3B7F58 E00B83D8 00021180 */  sll       $v0, $v0, 6
/* 3B7F5C E00B83DC 4406B000 */  mfc1      $a2, $f22
/* 3B7F60 E00B83E0 00521021 */  addu      $v0, $v0, $s2
/* 3B7F64 E00B83E4 A6030000 */  sh        $v1, ($s0)
/* 3B7F68 E00B83E8 8E230000 */  lw        $v1, ($s1)
/* 3B7F6C E00B83EC 4407B000 */  mfc1      $a3, $f22
/* 3B7F70 E00B83F0 00621821 */  addu      $v1, $v1, $v0
/* 3B7F74 E00B83F4 25020008 */  addiu     $v0, $t0, 8
/* 3B7F78 E00B83F8 ACA30004 */  sw        $v1, 4($a1)
/* 3B7F7C E00B83FC AE820000 */  sw        $v0, ($s4)
/* 3B7F80 E00B8400 AD090000 */  sw        $t1, ($t0)
/* 3B7F84 E00B8404 8EE30204 */  lw        $v1, 0x204($s7)
/* 3B7F88 E00B8408 3C17DE00 */  lui       $s7, 0xde00
/* 3B7F8C E00B840C 3C020900 */  lui       $v0, 0x900
/* 3B7F90 E00B8410 24420280 */  addiu     $v0, $v0, 0x280
/* 3B7F94 E00B8414 AD170008 */  sw        $s7, 8($t0)
/* 3B7F98 E00B8418 AD02000C */  sw        $v0, 0xc($t0)
/* 3B7F9C E00B841C AD030004 */  sw        $v1, 4($t0)
/* 3B7FA0 E00B8420 E7B40010 */  swc1      $f20, 0x10($sp)
/* 3B7FA4 E00B8424 8E650038 */  lw        $a1, 0x38($s3)
/* 3B7FA8 E00B8428 25080010 */  addiu     $t0, $t0, 0x10
/* 3B7FAC E00B842C 0C080104 */  jal       func_E0200410
/* 3B7FB0 E00B8430 AE880000 */   sw       $t0, ($s4)
/* 3B7FB4 E00B8434 8E65003C */  lw        $a1, 0x3c($s3)
/* 3B7FB8 E00B8438 8E660040 */  lw        $a2, 0x40($s3)
/* 3B7FBC E00B843C 4407A000 */  mfc1      $a3, $f20
/* 3B7FC0 E00B8440 0C080110 */  jal       func_E0200440
/* 3B7FC4 E00B8444 02A0202D */   daddu    $a0, $s5, $zero
/* 3B7FC8 E00B8448 02A0202D */  daddu     $a0, $s5, $zero
/* 3B7FCC E00B844C 27A50018 */  addiu     $a1, $sp, 0x18
/* 3B7FD0 E00B8450 0C080114 */  jal       func_E0200450
/* 3B7FD4 E00B8454 00A0302D */   daddu    $a2, $a1, $zero
/* 3B7FD8 E00B8458 27A40018 */  addiu     $a0, $sp, 0x18
/* 3B7FDC E00B845C 96050000 */  lhu       $a1, ($s0)
/* 3B7FE0 E00B8460 8E220000 */  lw        $v0, ($s1)
/* 3B7FE4 E00B8464 00052980 */  sll       $a1, $a1, 6
/* 3B7FE8 E00B8468 00B22821 */  addu      $a1, $a1, $s2
/* 3B7FEC E00B846C 0C080118 */  jal       func_E0200460
/* 3B7FF0 E00B8470 00452821 */   addu     $a1, $v0, $a1
/* 3B7FF4 E00B8474 8E850000 */  lw        $a1, ($s4)
/* 3B7FF8 E00B8478 00A0202D */  daddu     $a0, $a1, $zero
/* 3B7FFC E00B847C 24A50008 */  addiu     $a1, $a1, 8
/* 3B8000 E00B8480 AE850000 */  sw        $a1, ($s4)
/* 3B8004 E00B8484 96020000 */  lhu       $v0, ($s0)
/* 3B8008 E00B8488 3C03DA38 */  lui       $v1, 0xda38
/* 3B800C E00B848C AC830000 */  sw        $v1, ($a0)
/* 3B8010 E00B8490 24430001 */  addiu     $v1, $v0, 1
/* 3B8014 E00B8494 3042FFFF */  andi      $v0, $v0, 0xffff
/* 3B8018 E00B8498 00021180 */  sll       $v0, $v0, 6
/* 3B801C E00B849C A6030000 */  sh        $v1, ($s0)
/* 3B8020 E00B84A0 8E230000 */  lw        $v1, ($s1)
/* 3B8024 E00B84A4 00521021 */  addu      $v0, $v0, $s2
/* 3B8028 E00B84A8 00621821 */  addu      $v1, $v1, $v0
/* 3B802C E00B84AC 24A20008 */  addiu     $v0, $a1, 8
/* 3B8030 E00B84B0 AC830004 */  sw        $v1, 4($a0)
/* 3B8034 E00B84B4 AE820000 */  sw        $v0, ($s4)
/* 3B8038 E00B84B8 3C02FB00 */  lui       $v0, 0xfb00
/* 3B803C E00B84BC ACA20000 */  sw        $v0, ($a1)
/* 3B8040 E00B84C0 9262002B */  lbu       $v0, 0x2b($s3)
/* 3B8044 E00B84C4 9264002F */  lbu       $a0, 0x2f($s3)
/* 3B8048 E00B84C8 92630033 */  lbu       $v1, 0x33($s3)
/* 3B804C E00B84CC 8FAA00A0 */  lw        $t2, 0xa0($sp)
/* 3B8050 E00B84D0 00021600 */  sll       $v0, $v0, 0x18
/* 3B8054 E00B84D4 00042400 */  sll       $a0, $a0, 0x10
/* 3B8058 E00B84D8 00441025 */  or        $v0, $v0, $a0
/* 3B805C E00B84DC 00031A00 */  sll       $v1, $v1, 8
/* 3B8060 E00B84E0 00431025 */  or        $v0, $v0, $v1
/* 3B8064 E00B84E4 314400FF */  andi      $a0, $t2, 0xff
/* 3B8068 E00B84E8 00441025 */  or        $v0, $v0, $a0
/* 3B806C E00B84EC ACA20004 */  sw        $v0, 4($a1)
/* 3B8070 E00B84F0 8FAA009C */  lw        $t2, 0x9c($sp)
/* 3B8074 E00B84F4 25420001 */  addiu     $v0, $t2, 1
/* 3B8078 E00B84F8 8FAA0098 */  lw        $t2, 0x98($sp)
/* 3B807C E00B84FC 02C21023 */  subu      $v0, $s6, $v0
/* 3B8080 E00B8500 0142102A */  slt       $v0, $t2, $v0
/* 3B8084 E00B8504 14400018 */  bnez      $v0, .LE00B8568
/* 3B8088 E00B8508 00161042 */   srl      $v0, $s6, 1
/* 3B808C E00B850C 24A20010 */  addiu     $v0, $a1, 0x10
/* 3B8090 E00B8510 AE820000 */  sw        $v0, ($s4)
/* 3B8094 E00B8514 3C02FA00 */  lui       $v0, 0xfa00
/* 3B8098 E00B8518 ACA20008 */  sw        $v0, 8($a1)
/* 3B809C E00B851C 8FAA00A4 */  lw        $t2, 0xa4($sp)
/* 3B80A0 E00B8520 000A1E00 */  sll       $v1, $t2, 0x18
/* 3B80A4 E00B8524 8FAA00A8 */  lw        $t2, 0xa8($sp)
/* 3B80A8 E00B8528 314200FF */  andi      $v0, $t2, 0xff
/* 3B80AC E00B852C 00021400 */  sll       $v0, $v0, 0x10
/* 3B80B0 E00B8530 8FAA00AC */  lw        $t2, 0xac($sp)
/* 3B80B4 E00B8534 00621825 */  or        $v1, $v1, $v0
/* 3B80B8 E00B8538 314200FF */  andi      $v0, $t2, 0xff
/* 3B80BC E00B853C 00021200 */  sll       $v0, $v0, 8
/* 3B80C0 E00B8540 00621825 */  or        $v1, $v1, $v0
/* 3B80C4 E00B8544 00641825 */  or        $v1, $v1, $a0
/* 3B80C8 E00B8548 24A20018 */  addiu     $v0, $a1, 0x18
/* 3B80CC E00B854C ACA3000C */  sw        $v1, 0xc($a1)
/* 3B80D0 E00B8550 AE820000 */  sw        $v0, ($s4)
/* 3B80D4 E00B8554 3C020900 */  lui       $v0, 0x900
/* 3B80D8 E00B8558 24420348 */  addiu     $v0, $v0, 0x348
/* 3B80DC E00B855C ACB70010 */  sw        $s7, 0x10($a1)
/* 3B80E0 E00B8560 ACA20014 */  sw        $v0, 0x14($a1)
/* 3B80E4 E00B8564 00161042 */  srl       $v0, $s6, 1
.LE00B8568:
/* 3B80E8 E00B8568 184000BF */  blez      $v0, .LE00B8868
/* 3B80EC E00B856C 0000B82D */   daddu    $s7, $zero, $zero
/* 3B80F0 E00B8570 001E1080 */  sll       $v0, $fp, 2
/* 3B80F4 E00B8574 4600B506 */  mov.s     $f20, $f22
/* 3B80F8 E00B8578 3C01E00C */  lui       $at, %hi(D_E00B8CD0)
/* 3B80FC E00B857C D4368CD0 */  ldc1      $f22, %lo(D_E00B8CD0)($at)
/* 3B8100 E00B8580 005E1021 */  addu      $v0, $v0, $fp
/* 3B8104 E00B8584 AFA200BC */  sw        $v0, 0xbc($sp)
/* 3B8108 E00B8588 AFBE00C4 */  sw        $fp, 0xc4($sp)
.LE00B858C:
/* 3B810C E00B858C 8FAA00B0 */  lw        $t2, 0xb0($sp)
/* 3B8110 E00B8590 114000AE */  beqz      $t2, .LE00B884C
/* 3B8114 E00B8594 0000902D */   daddu    $s2, $zero, $zero
/* 3B8118 E00B8598 3C1E0001 */  lui       $fp, 1
/* 3B811C E00B859C 37DE1630 */  ori       $fp, $fp, 0x1630
/* 3B8120 E00B85A0 3C14800A */  lui       $s4, %hi(D_8009A66C)
/* 3B8124 E00B85A4 2694A66C */  addiu     $s4, $s4, %lo(D_8009A66C)
/* 3B8128 E00B85A8 8FAA00C4 */  lw        $t2, 0xc4($sp)
/* 3B812C E00B85AC 0240982D */  daddu     $s3, $s2, $zero
/* 3B8130 E00B85B0 AFAA00B8 */  sw        $t2, 0xb8($sp)
/* 3B8134 E00B85B4 8FAA00A4 */  lw        $t2, 0xa4($sp)
/* 3B8138 E00B85B8 3C013F80 */  lui       $at, 0x3f80
/* 3B813C E00B85BC 4481C000 */  mtc1      $at, $f24
/* 3B8140 E00B85C0 000A5600 */  sll       $t2, $t2, 0x18
/* 3B8144 E00B85C4 AFAA00C0 */  sw        $t2, 0xc0($sp)
.LE00B85C8:
/* 3B8148 E00B85C8 8FAA00B8 */  lw        $t2, 0xb8($sp)
/* 3B814C E00B85CC 16C00002 */  bnez      $s6, .LE00B85D8
/* 3B8150 E00B85D0 0156001A */   div      $zero, $t2, $s6
/* 3B8154 E00B85D4 0007000D */  break     7
.LE00B85D8:
/* 3B8158 E00B85D8 2401FFFF */   addiu    $at, $zero, -1
/* 3B815C E00B85DC 16C10004 */  bne       $s6, $at, .LE00B85F0
/* 3B8160 E00B85E0 3C018000 */   lui      $at, 0x8000
/* 3B8164 E00B85E4 15410002 */  bne       $t2, $at, .LE00B85F0
/* 3B8168 E00B85E8 00000000 */   nop      
/* 3B816C E00B85EC 0006000D */  break     6
.LE00B85F0:
/* 3B8170 E00B85F0 00001810 */   mfhi     $v1
/* 3B8174 E00B85F4 00131080 */  sll       $v0, $s3, 2
/* 3B8178 E00B85F8 00531021 */  addu      $v0, $v0, $s3
/* 3B817C E00B85FC 8FAA00B4 */  lw        $t2, 0xb4($sp)
/* 3B8180 E00B8600 00021040 */  sll       $v0, $v0, 1
/* 3B8184 E00B8604 01422821 */  addu      $a1, $t2, $v0
/* 3B8188 E00B8608 8FAA00BC */  lw        $t2, 0xbc($sp)
/* 3B818C E00B860C 0143102A */  slt       $v0, $t2, $v1
/* 3B8190 E00B8610 14400089 */  bnez      $v0, .LE00B8838
/* 3B8194 E00B8614 24620001 */   addiu    $v0, $v1, 1
/* 3B8198 E00B8618 8FAA0098 */  lw        $t2, 0x98($sp)
/* 3B819C E00B861C 02C21023 */  subu      $v0, $s6, $v0
/* 3B81A0 E00B8620 0142102A */  slt       $v0, $t2, $v0
/* 3B81A4 E00B8624 14400084 */  bnez      $v0, .LE00B8838
/* 3B81A8 E00B8628 00038080 */   sll      $s0, $v1, 2
/* 3B81AC E00B862C 02038021 */  addu      $s0, $s0, $v1
/* 3B81B0 E00B8630 00108040 */  sll       $s0, $s0, 1
/* 3B81B4 E00B8634 02058821 */  addu      $s1, $s0, $a1
/* 3B81B8 E00B8638 82220001 */  lb        $v0, 1($s1)
/* 3B81BC E00B863C 3C014120 */  lui       $at, 0x4120
/* 3B81C0 E00B8640 44811000 */  mtc1      $at, $f2
/* 3B81C4 E00B8644 4407A000 */  mfc1      $a3, $f20
/* 3B81C8 E00B8648 44820000 */  mtc1      $v0, $f0
/* 3B81CC E00B864C 00000000 */  nop       
/* 3B81D0 E00B8650 46800020 */  cvt.s.w   $f0, $f0
/* 3B81D4 E00B8654 82220000 */  lb        $v0, ($s1)
/* 3B81D8 E00B8658 46020000 */  add.s     $f0, $f0, $f2
/* 3B81DC E00B865C 44822000 */  mtc1      $v0, $f4
/* 3B81E0 E00B8660 00000000 */  nop       
/* 3B81E4 E00B8664 46802120 */  cvt.s.w   $f4, $f4
/* 3B81E8 E00B8668 44052000 */  mfc1      $a1, $f4
/* 3B81EC E00B866C 44060000 */  mfc1      $a2, $f0
/* 3B81F0 E00B8670 0C080108 */  jal       func_E0200420
/* 3B81F4 E00B8674 27A40018 */   addiu    $a0, $sp, 0x18
/* 3B81F8 E00B8678 8FAA00B4 */  lw        $t2, 0xb4($sp)
/* 3B81FC E00B867C 020A8021 */  addu      $s0, $s0, $t2
/* 3B8200 E00B8680 86020002 */  lh        $v0, 2($s0)
/* 3B8204 E00B8684 44821000 */  mtc1      $v0, $f2
/* 3B8208 E00B8688 00000000 */  nop       
/* 3B820C E00B868C 468010A0 */  cvt.s.w   $f2, $f2
/* 3B8210 E00B8690 460010A1 */  cvt.d.s   $f2, $f2
/* 3B8214 E00B8694 46361082 */  mul.d     $f2, $f2, $f22
/* 3B8218 E00B8698 00000000 */  nop       
/* 3B821C E00B869C 86020004 */  lh        $v0, 4($s0)
/* 3B8220 E00B86A0 44820000 */  mtc1      $v0, $f0
/* 3B8224 E00B86A4 00000000 */  nop       
/* 3B8228 E00B86A8 46800020 */  cvt.s.w   $f0, $f0
/* 3B822C E00B86AC 46000021 */  cvt.d.s   $f0, $f0
/* 3B8230 E00B86B0 46360002 */  mul.d     $f0, $f0, $f22
/* 3B8234 E00B86B4 00000000 */  nop       
/* 3B8238 E00B86B8 4407C000 */  mfc1      $a3, $f24
/* 3B823C E00B86BC 462010A0 */  cvt.s.d   $f2, $f2
/* 3B8240 E00B86C0 44051000 */  mfc1      $a1, $f2
/* 3B8244 E00B86C4 46200020 */  cvt.s.d   $f0, $f0
/* 3B8248 E00B86C8 44060000 */  mfc1      $a2, $f0
/* 3B824C E00B86CC 0C080110 */  jal       func_E0200440
/* 3B8250 E00B86D0 02A0202D */   daddu    $a0, $s5, $zero
/* 3B8254 E00B86D4 02A0202D */  daddu     $a0, $s5, $zero
/* 3B8258 E00B86D8 27A50018 */  addiu     $a1, $sp, 0x18
/* 3B825C E00B86DC 0C080114 */  jal       func_E0200450
/* 3B8260 E00B86E0 00A0302D */   daddu    $a2, $a1, $zero
/* 3B8264 E00B86E4 86220006 */  lh        $v0, 6($s1)
/* 3B8268 E00B86E8 3C0AE00C */  lui       $t2, %hi(D_E00B8CA4)
/* 3B826C E00B86EC 254A8CA4 */  addiu     $t2, $t2, %lo(D_E00B8CA4)
/* 3B8270 E00B86F0 44821000 */  mtc1      $v0, $f2
/* 3B8274 E00B86F4 00000000 */  nop       
/* 3B8278 E00B86F8 468010A0 */  cvt.s.w   $f2, $f2
/* 3B827C E00B86FC 02571021 */  addu      $v0, $s2, $s7
/* 3B8280 E00B8700 30420007 */  andi      $v0, $v0, 7
/* 3B8284 E00B8704 00021080 */  sll       $v0, $v0, 2
/* 3B8288 E00B8708 004A1021 */  addu      $v0, $v0, $t2
/* 3B828C E00B870C C4400000 */  lwc1      $f0, ($v0)
/* 3B8290 E00B8710 46800020 */  cvt.s.w   $f0, $f0
/* 3B8294 E00B8714 46001080 */  add.s     $f2, $f2, $f0
/* 3B8298 E00B8718 4406A000 */  mfc1      $a2, $f20
/* 3B829C E00B871C 4407A000 */  mfc1      $a3, $f20
/* 3B82A0 E00B8720 44051000 */  mfc1      $a1, $f2
/* 3B82A4 E00B8724 02A0202D */  daddu     $a0, $s5, $zero
/* 3B82A8 E00B8728 0C080104 */  jal       func_E0200410
/* 3B82AC E00B872C E7B80010 */   swc1     $f24, 0x10($sp)
/* 3B82B0 E00B8730 02A0202D */  daddu     $a0, $s5, $zero
/* 3B82B4 E00B8734 27A50018 */  addiu     $a1, $sp, 0x18
/* 3B82B8 E00B8738 0C080114 */  jal       func_E0200450
/* 3B82BC E00B873C 00A0302D */   daddu    $a2, $a1, $zero
/* 3B82C0 E00B8740 27A40018 */  addiu     $a0, $sp, 0x18
/* 3B82C4 E00B8744 3C058007 */  lui       $a1, %hi(D_800741F0)
/* 3B82C8 E00B8748 94A541F0 */  lhu       $a1, %lo(D_800741F0)($a1)
/* 3B82CC E00B874C 3C02800A */  lui       $v0, %hi(D_8009A674)
/* 3B82D0 E00B8750 8C42A674 */  lw        $v0, %lo(D_8009A674)($v0)
/* 3B82D4 E00B8754 00052980 */  sll       $a1, $a1, 6
/* 3B82D8 E00B8758 00BE2821 */  addu      $a1, $a1, $fp
/* 3B82DC E00B875C 0C080118 */  jal       func_E0200460
/* 3B82E0 E00B8760 00452821 */   addu     $a1, $v0, $a1
/* 3B82E4 E00B8764 3C06D838 */  lui       $a2, 0xd838
/* 3B82E8 E00B8768 8E840000 */  lw        $a0, ($s4)
/* 3B82EC E00B876C 34C60002 */  ori       $a2, $a2, 2
/* 3B82F0 E00B8770 0080282D */  daddu     $a1, $a0, $zero
/* 3B82F4 E00B8774 24840008 */  addiu     $a0, $a0, 8
/* 3B82F8 E00B8778 AE840000 */  sw        $a0, ($s4)
/* 3B82FC E00B877C 3C028007 */  lui       $v0, %hi(D_800741F0)
/* 3B8300 E00B8780 944241F0 */  lhu       $v0, %lo(D_800741F0)($v0)
/* 3B8304 E00B8784 3C03DA38 */  lui       $v1, 0xda38
/* 3B8308 E00B8788 ACA30000 */  sw        $v1, ($a1)
/* 3B830C E00B878C 24430001 */  addiu     $v1, $v0, 1
/* 3B8310 E00B8790 3042FFFF */  andi      $v0, $v0, 0xffff
/* 3B8314 E00B8794 00021180 */  sll       $v0, $v0, 6
/* 3B8318 E00B8798 3C018007 */  lui       $at, %hi(D_800741F0)
/* 3B831C E00B879C A42341F0 */  sh        $v1, %lo(D_800741F0)($at)
/* 3B8320 E00B87A0 3C03800A */  lui       $v1, %hi(D_8009A674)
/* 3B8324 E00B87A4 8C63A674 */  lw        $v1, %lo(D_8009A674)($v1)
/* 3B8328 E00B87A8 005E1021 */  addu      $v0, $v0, $fp
/* 3B832C E00B87AC 00621821 */  addu      $v1, $v1, $v0
/* 3B8330 E00B87B0 24820008 */  addiu     $v0, $a0, 8
/* 3B8334 E00B87B4 ACA30004 */  sw        $v1, 4($a1)
/* 3B8338 E00B87B8 AE820000 */  sw        $v0, ($s4)
/* 3B833C E00B87BC 3C02FA00 */  lui       $v0, 0xfa00
/* 3B8340 E00B87C0 AC820000 */  sw        $v0, ($a0)
/* 3B8344 E00B87C4 92050008 */  lbu       $a1, 8($s0)
/* 3B8348 E00B87C8 24820010 */  addiu     $v0, $a0, 0x10
/* 3B834C E00B87CC AE820000 */  sw        $v0, ($s4)
/* 3B8350 E00B87D0 3C02DE00 */  lui       $v0, 0xde00
/* 3B8354 E00B87D4 AC820008 */  sw        $v0, 8($a0)
/* 3B8358 E00B87D8 3C020900 */  lui       $v0, 0x900
/* 3B835C E00B87DC 24420328 */  addiu     $v0, $v0, 0x328
/* 3B8360 E00B87E0 AC82000C */  sw        $v0, 0xc($a0)
/* 3B8364 E00B87E4 24820018 */  addiu     $v0, $a0, 0x18
/* 3B8368 E00B87E8 AE820000 */  sw        $v0, ($s4)
/* 3B836C E00B87EC 24020040 */  addiu     $v0, $zero, 0x40
/* 3B8370 E00B87F0 AC860010 */  sw        $a2, 0x10($a0)
/* 3B8374 E00B87F4 AC820014 */  sw        $v0, 0x14($a0)
/* 3B8378 E00B87F8 8FAA00A8 */  lw        $t2, 0xa8($sp)
/* 3B837C E00B87FC 314300FF */  andi      $v1, $t2, 0xff
/* 3B8380 E00B8800 8FAA00A0 */  lw        $t2, 0xa0($sp)
/* 3B8384 E00B8804 01450018 */  mult      $t2, $a1
/* 3B8388 E00B8808 8FAA00C0 */  lw        $t2, 0xc0($sp)
/* 3B838C E00B880C 00031C00 */  sll       $v1, $v1, 0x10
/* 3B8390 E00B8810 01431825 */  or        $v1, $t2, $v1
/* 3B8394 E00B8814 8FAA00AC */  lw        $t2, 0xac($sp)
/* 3B8398 E00B8818 314200FF */  andi      $v0, $t2, 0xff
/* 3B839C E00B881C 00021200 */  sll       $v0, $v0, 8
/* 3B83A0 E00B8820 00621825 */  or        $v1, $v1, $v0
/* 3B83A4 E00B8824 00005012 */  mflo      $t2
/* 3B83A8 E00B8828 000A1203 */  sra       $v0, $t2, 8
/* 3B83AC E00B882C 304200FF */  andi      $v0, $v0, 0xff
/* 3B83B0 E00B8830 00621825 */  or        $v1, $v1, $v0
/* 3B83B4 E00B8834 AC830004 */  sw        $v1, 4($a0)
.LE00B8838:
/* 3B83B8 E00B8838 8FAA00B0 */  lw        $t2, 0xb0($sp)
/* 3B83BC E00B883C 26520001 */  addiu     $s2, $s2, 1
/* 3B83C0 E00B8840 024A102A */  slt       $v0, $s2, $t2
/* 3B83C4 E00B8844 1440FF60 */  bnez      $v0, .LE00B85C8
/* 3B83C8 E00B8848 02769821 */   addu     $s3, $s3, $s6
.LE00B884C:
/* 3B83CC E00B884C 26F70001 */  addiu     $s7, $s7, 1
/* 3B83D0 E00B8850 00161042 */  srl       $v0, $s6, 1
/* 3B83D4 E00B8854 8FAA00C4 */  lw        $t2, 0xc4($sp)
/* 3B83D8 E00B8858 02E2102A */  slt       $v0, $s7, $v0
/* 3B83DC E00B885C 254A0002 */  addiu     $t2, $t2, 2
/* 3B83E0 E00B8860 1440FF4A */  bnez      $v0, .LE00B858C
/* 3B83E4 E00B8864 AFAA00C4 */   sw       $t2, 0xc4($sp)
.LE00B8868:
/* 3B83E8 E00B8868 3C06D838 */  lui       $a2, 0xd838
/* 3B83EC E00B886C 3C04800A */  lui       $a0, %hi(D_8009A66C)
/* 3B83F0 E00B8870 2484A66C */  addiu     $a0, $a0, %lo(D_8009A66C)
/* 3B83F4 E00B8874 34C60002 */  ori       $a2, $a2, 2
/* 3B83F8 E00B8878 8C820000 */  lw        $v0, ($a0)
/* 3B83FC E00B887C 24050040 */  addiu     $a1, $zero, 0x40
/* 3B8400 E00B8880 0040182D */  daddu     $v1, $v0, $zero
/* 3B8404 E00B8884 24420008 */  addiu     $v0, $v0, 8
/* 3B8408 E00B8888 AC820000 */  sw        $v0, ($a0)
/* 3B840C E00B888C AC660000 */  sw        $a2, ($v1)
/* 3B8410 E00B8890 AC650004 */  sw        $a1, 4($v1)
/* 3B8414 E00B8894 24430008 */  addiu     $v1, $v0, 8
/* 3B8418 E00B8898 AC830000 */  sw        $v1, ($a0)
/* 3B841C E00B889C 24430010 */  addiu     $v1, $v0, 0x10
/* 3B8420 E00B88A0 AC460000 */  sw        $a2, ($v0)
/* 3B8424 E00B88A4 AC450004 */  sw        $a1, 4($v0)
/* 3B8428 E00B88A8 AC830000 */  sw        $v1, ($a0)
/* 3B842C E00B88AC 3C03E700 */  lui       $v1, 0xe700
/* 3B8430 E00B88B0 AC430008 */  sw        $v1, 8($v0)
/* 3B8434 E00B88B4 AC40000C */  sw        $zero, 0xc($v0)
/* 3B8438 E00B88B8 8FBF00EC */  lw        $ra, 0xec($sp)
/* 3B843C E00B88BC 8FBE00E8 */  lw        $fp, 0xe8($sp)
/* 3B8440 E00B88C0 8FB700E4 */  lw        $s7, 0xe4($sp)
/* 3B8444 E00B88C4 8FB600E0 */  lw        $s6, 0xe0($sp)
/* 3B8448 E00B88C8 8FB500DC */  lw        $s5, 0xdc($sp)
/* 3B844C E00B88CC 8FB400D8 */  lw        $s4, 0xd8($sp)
/* 3B8450 E00B88D0 8FB300D4 */  lw        $s3, 0xd4($sp)
/* 3B8454 E00B88D4 8FB200D0 */  lw        $s2, 0xd0($sp)
/* 3B8458 E00B88D8 8FB100CC */  lw        $s1, 0xcc($sp)
/* 3B845C E00B88DC 8FB000C8 */  lw        $s0, 0xc8($sp)
/* 3B8460 E00B88E0 D7B80100 */  ldc1      $f24, 0x100($sp)
/* 3B8464 E00B88E4 D7B600F8 */  ldc1      $f22, 0xf8($sp)
/* 3B8468 E00B88E8 D7B400F0 */  ldc1      $f20, 0xf0($sp)
/* 3B846C E00B88EC 03E00008 */  jr        $ra
