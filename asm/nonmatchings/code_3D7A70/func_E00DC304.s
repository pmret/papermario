.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00DC304
/* 3D7D74 E00DC304 27BDFF38 */  addiu     $sp, $sp, -0xc8
/* 3D7D78 E00DC308 0080302D */  daddu     $a2, $a0, $zero
/* 3D7D7C E00DC30C 3C07DB06 */  lui       $a3, 0xdb06
/* 3D7D80 E00DC310 34E70024 */  ori       $a3, $a3, 0x24
/* 3D7D84 E00DC314 27A40018 */  addiu     $a0, $sp, 0x18
/* 3D7D88 E00DC318 AFB400B0 */  sw        $s4, 0xb0($sp)
/* 3D7D8C E00DC31C 3C14800A */  lui       $s4, %hi(gMasterGfxPos)
/* 3D7D90 E00DC320 2694A66C */  addiu     $s4, $s4, %lo(gMasterGfxPos)
/* 3D7D94 E00DC324 AFBF00C4 */  sw        $ra, 0xc4($sp)
/* 3D7D98 E00DC328 AFBE00C0 */  sw        $fp, 0xc0($sp)
/* 3D7D9C E00DC32C AFB700BC */  sw        $s7, 0xbc($sp)
/* 3D7DA0 E00DC330 AFB600B8 */  sw        $s6, 0xb8($sp)
/* 3D7DA4 E00DC334 AFB500B4 */  sw        $s5, 0xb4($sp)
/* 3D7DA8 E00DC338 AFB300AC */  sw        $s3, 0xac($sp)
/* 3D7DAC E00DC33C AFB200A8 */  sw        $s2, 0xa8($sp)
/* 3D7DB0 E00DC340 AFB100A4 */  sw        $s1, 0xa4($sp)
/* 3D7DB4 E00DC344 AFB000A0 */  sw        $s0, 0xa0($sp)
/* 3D7DB8 E00DC348 8E850000 */  lw        $a1, ($s4)
/* 3D7DBC E00DC34C 8CD2000C */  lw        $s2, 0xc($a2)
/* 3D7DC0 E00DC350 3C014080 */  lui       $at, 0x4080
/* 3D7DC4 E00DC354 44810000 */  mtc1      $at, $f0
/* 3D7DC8 E00DC358 00A0182D */  daddu     $v1, $a1, $zero
/* 3D7DCC E00DC35C 24A50008 */  addiu     $a1, $a1, 8
/* 3D7DD0 E00DC360 AE850000 */  sw        $a1, ($s4)
/* 3D7DD4 E00DC364 8E570024 */  lw        $s7, 0x24($s2)
/* 3D7DD8 E00DC368 8E4A0000 */  lw        $t2, ($s2)
/* 3D7DDC E00DC36C 3C1E0001 */  lui       $fp, 1
/* 3D7DE0 E00DC370 AFAA0098 */  sw        $t2, 0x98($sp)
/* 3D7DE4 E00DC374 C6420038 */  lwc1      $f2, 0x38($s2)
/* 3D7DE8 E00DC378 C6440040 */  lwc1      $f4, 0x40($s2)
/* 3D7DEC E00DC37C 3C02E700 */  lui       $v0, 0xe700
/* 3D7DF0 E00DC380 AC620000 */  sw        $v0, ($v1)
/* 3D7DF4 E00DC384 AC600004 */  sw        $zero, 4($v1)
/* 3D7DF8 E00DC388 ACA70000 */  sw        $a3, ($a1)
/* 3D7DFC E00DC38C 8CC30010 */  lw        $v1, 0x10($a2)
/* 3D7E00 E00DC390 46001082 */  mul.s     $f2, $f2, $f0
/* 3D7E04 E00DC394 00000000 */  nop       
/* 3D7E08 E00DC398 24A20008 */  addiu     $v0, $a1, 8
/* 3D7E0C E00DC39C AE820000 */  sw        $v0, ($s4)
/* 3D7E10 E00DC3A0 8C62001C */  lw        $v0, 0x1c($v1)
/* 3D7E14 E00DC3A4 3C038000 */  lui       $v1, 0x8000
/* 3D7E18 E00DC3A8 46002102 */  mul.s     $f4, $f4, $f0
/* 3D7E1C E00DC3AC 00000000 */  nop       
/* 3D7E20 E00DC3B0 00431021 */  addu      $v0, $v0, $v1
/* 3D7E24 E00DC3B4 3C03800B */  lui       $v1, %hi(gCameras)
/* 3D7E28 E00DC3B8 24631D80 */  addiu     $v1, $v1, %lo(gCameras)
/* 3D7E2C E00DC3BC ACA20004 */  sw        $v0, 4($a1)
/* 3D7E30 E00DC3C0 8E450004 */  lw        $a1, 4($s2)
/* 3D7E34 E00DC3C4 8E460008 */  lw        $a2, 8($s2)
/* 3D7E38 E00DC3C8 3C028007 */  lui       $v0, %hi(gCurrentCameraID)
/* 3D7E3C E00DC3CC 8C427410 */  lw        $v0, %lo(gCurrentCameraID)($v0)
/* 3D7E40 E00DC3D0 8E47000C */  lw        $a3, 0xc($s2)
/* 3D7E44 E00DC3D4 00028880 */  sll       $s1, $v0, 2
/* 3D7E48 E00DC3D8 02228821 */  addu      $s1, $s1, $v0
/* 3D7E4C E00DC3DC 00118880 */  sll       $s1, $s1, 2
/* 3D7E50 E00DC3E0 02228823 */  subu      $s1, $s1, $v0
/* 3D7E54 E00DC3E4 001110C0 */  sll       $v0, $s1, 3
/* 3D7E58 E00DC3E8 02228821 */  addu      $s1, $s1, $v0
/* 3D7E5C E00DC3EC 001188C0 */  sll       $s1, $s1, 3
/* 3D7E60 E00DC3F0 4600118D */  trunc.w.s $f6, $f2
/* 3D7E64 E00DC3F4 44133000 */  mfc1      $s3, $f6
/* 3D7E68 E00DC3F8 4600218D */  trunc.w.s $f6, $f4
/* 3D7E6C E00DC3FC 44163000 */  mfc1      $s6, $f6
/* 3D7E70 E00DC400 0C080108 */  jal       func_E0200420
/* 3D7E74 E00DC404 02238821 */   addu     $s1, $s1, $v1
/* 3D7E78 E00DC408 37DE1630 */  ori       $fp, $fp, 0x1630
/* 3D7E7C E00DC40C 3C013F80 */  lui       $at, 0x3f80
/* 3D7E80 E00DC410 44810000 */  mtc1      $at, $f0
/* 3D7E84 E00DC414 27B00058 */  addiu     $s0, $sp, 0x58
/* 3D7E88 E00DC418 E7A00010 */  swc1      $f0, 0x10($sp)
/* 3D7E8C E00DC41C 44800000 */  mtc1      $zero, $f0
/* 3D7E90 E00DC420 0200202D */  daddu     $a0, $s0, $zero
/* 3D7E94 E00DC424 44060000 */  mfc1      $a2, $f0
/* 3D7E98 E00DC428 8E450048 */  lw        $a1, 0x48($s2)
/* 3D7E9C E00DC42C 0C080104 */  jal       func_E0200410
/* 3D7EA0 E00DC430 00C0382D */   daddu    $a3, $a2, $zero
/* 3D7EA4 E00DC434 0200202D */  daddu     $a0, $s0, $zero
/* 3D7EA8 E00DC438 27A50018 */  addiu     $a1, $sp, 0x18
/* 3D7EAC E00DC43C 0C080114 */  jal       func_E0200450
/* 3D7EB0 E00DC440 00A0302D */   daddu    $a2, $a1, $zero
/* 3D7EB4 E00DC444 8E45004C */  lw        $a1, 0x4c($s2)
/* 3D7EB8 E00DC448 0200202D */  daddu     $a0, $s0, $zero
/* 3D7EBC E00DC44C 00A0302D */  daddu     $a2, $a1, $zero
/* 3D7EC0 E00DC450 0C080110 */  jal       func_E0200440
/* 3D7EC4 E00DC454 00A0382D */   daddu    $a3, $a1, $zero
/* 3D7EC8 E00DC458 0200202D */  daddu     $a0, $s0, $zero
/* 3D7ECC E00DC45C 27A50018 */  addiu     $a1, $sp, 0x18
/* 3D7ED0 E00DC460 0C080114 */  jal       func_E0200450
/* 3D7ED4 E00DC464 00A0302D */   daddu    $a2, $a1, $zero
/* 3D7ED8 E00DC468 27A40018 */  addiu     $a0, $sp, 0x18
/* 3D7EDC E00DC46C 3C108007 */  lui       $s0, %hi(gMatrixListPos)
/* 3D7EE0 E00DC470 261041F0 */  addiu     $s0, $s0, %lo(gMatrixListPos)
/* 3D7EE4 E00DC474 3C15800A */  lui       $s5, %hi(gDisplayContext)
/* 3D7EE8 E00DC478 26B5A674 */  addiu     $s5, $s5, %lo(gDisplayContext)
/* 3D7EEC E00DC47C 96050000 */  lhu       $a1, ($s0)
/* 3D7EF0 E00DC480 8EA20000 */  lw        $v0, ($s5)
/* 3D7EF4 E00DC484 00052980 */  sll       $a1, $a1, 6
/* 3D7EF8 E00DC488 00BE2821 */  addu      $a1, $a1, $fp
/* 3D7EFC E00DC48C 0C080118 */  jal       func_E0200460
/* 3D7F00 E00DC490 00452821 */   addu     $a1, $v0, $a1
/* 3D7F04 E00DC494 3C03DA38 */  lui       $v1, 0xda38
/* 3D7F08 E00DC498 34630002 */  ori       $v1, $v1, 2
/* 3D7F0C E00DC49C 3C06DA38 */  lui       $a2, 0xda38
/* 3D7F10 E00DC4A0 34C60001 */  ori       $a2, $a2, 1
/* 3D7F14 E00DC4A4 3C09D838 */  lui       $t1, 0xd838
/* 3D7F18 E00DC4A8 35290002 */  ori       $t1, $t1, 2
/* 3D7F1C E00DC4AC 32F700FF */  andi      $s7, $s7, 0xff
/* 3D7F20 E00DC4B0 3C08DE00 */  lui       $t0, 0xde00
/* 3D7F24 E00DC4B4 8E850000 */  lw        $a1, ($s4)
/* 3D7F28 E00DC4B8 96020000 */  lhu       $v0, ($s0)
/* 3D7F2C E00DC4BC 00A0202D */  daddu     $a0, $a1, $zero
/* 3D7F30 E00DC4C0 24A50008 */  addiu     $a1, $a1, 8
/* 3D7F34 E00DC4C4 AE850000 */  sw        $a1, ($s4)
/* 3D7F38 E00DC4C8 AC830000 */  sw        $v1, ($a0)
/* 3D7F3C E00DC4CC 24430001 */  addiu     $v1, $v0, 1
/* 3D7F40 E00DC4D0 3042FFFF */  andi      $v0, $v0, 0xffff
/* 3D7F44 E00DC4D4 00021180 */  sll       $v0, $v0, 6
/* 3D7F48 E00DC4D8 A6030000 */  sh        $v1, ($s0)
/* 3D7F4C E00DC4DC 8EA30000 */  lw        $v1, ($s5)
/* 3D7F50 E00DC4E0 005E1021 */  addu      $v0, $v0, $fp
/* 3D7F54 E00DC4E4 00621821 */  addu      $v1, $v1, $v0
/* 3D7F58 E00DC4E8 24A20008 */  addiu     $v0, $a1, 8
/* 3D7F5C E00DC4EC AC830004 */  sw        $v1, 4($a0)
/* 3D7F60 E00DC4F0 AE820000 */  sw        $v0, ($s4)
/* 3D7F64 E00DC4F4 24A20010 */  addiu     $v0, $a1, 0x10
/* 3D7F68 E00DC4F8 ACA60000 */  sw        $a2, ($a1)
/* 3D7F6C E00DC4FC AE820000 */  sw        $v0, ($s4)
/* 3D7F70 E00DC500 8E230204 */  lw        $v1, 0x204($s1)
/* 3D7F74 E00DC504 3C02FA00 */  lui       $v0, 0xfa00
/* 3D7F78 E00DC508 ACA20008 */  sw        $v0, 8($a1)
/* 3D7F7C E00DC50C ACA30004 */  sw        $v1, 4($a1)
/* 3D7F80 E00DC510 9242001B */  lbu       $v0, 0x1b($s2)
/* 3D7F84 E00DC514 9244001F */  lbu       $a0, 0x1f($s2)
/* 3D7F88 E00DC518 92460023 */  lbu       $a2, 0x23($s2)
/* 3D7F8C E00DC51C 24A30018 */  addiu     $v1, $a1, 0x18
/* 3D7F90 E00DC520 AE830000 */  sw        $v1, ($s4)
/* 3D7F94 E00DC524 3C03FB00 */  lui       $v1, 0xfb00
/* 3D7F98 E00DC528 ACA30010 */  sw        $v1, 0x10($a1)
/* 3D7F9C E00DC52C 00021600 */  sll       $v0, $v0, 0x18
/* 3D7FA0 E00DC530 00042400 */  sll       $a0, $a0, 0x10
/* 3D7FA4 E00DC534 00441025 */  or        $v0, $v0, $a0
/* 3D7FA8 E00DC538 00063200 */  sll       $a2, $a2, 8
/* 3D7FAC E00DC53C 00461025 */  or        $v0, $v0, $a2
/* 3D7FB0 E00DC540 00571025 */  or        $v0, $v0, $s7
/* 3D7FB4 E00DC544 ACA2000C */  sw        $v0, 0xc($a1)
/* 3D7FB8 E00DC548 9243002B */  lbu       $v1, 0x2b($s2)
/* 3D7FBC E00DC54C 9244002F */  lbu       $a0, 0x2f($s2)
/* 3D7FC0 E00DC550 92460033 */  lbu       $a2, 0x33($s2)
/* 3D7FC4 E00DC554 92470037 */  lbu       $a3, 0x37($s2)
/* 3D7FC8 E00DC558 24A20020 */  addiu     $v0, $a1, 0x20
/* 3D7FCC E00DC55C AE820000 */  sw        $v0, ($s4)
/* 3D7FD0 E00DC560 24A20028 */  addiu     $v0, $a1, 0x28
/* 3D7FD4 E00DC564 ACA80018 */  sw        $t0, 0x18($a1)
/* 3D7FD8 E00DC568 AE820000 */  sw        $v0, ($s4)
/* 3D7FDC E00DC56C 32C20FFF */  andi      $v0, $s6, 0xfff
/* 3D7FE0 E00DC570 26D6003C */  addiu     $s6, $s6, 0x3c
/* 3D7FE4 E00DC574 32D60FFF */  andi      $s6, $s6, 0xfff
/* 3D7FE8 E00DC578 00031E00 */  sll       $v1, $v1, 0x18
/* 3D7FEC E00DC57C 00042400 */  sll       $a0, $a0, 0x10
/* 3D7FF0 E00DC580 00641825 */  or        $v1, $v1, $a0
/* 3D7FF4 E00DC584 00063200 */  sll       $a2, $a2, 8
/* 3D7FF8 E00DC588 00661825 */  or        $v1, $v1, $a2
/* 3D7FFC E00DC58C 00671825 */  or        $v1, $v1, $a3
/* 3D8000 E00DC590 32640FFF */  andi      $a0, $s3, 0xfff
/* 3D8004 E00DC594 00042300 */  sll       $a0, $a0, 0xc
/* 3D8008 E00DC598 ACA30014 */  sw        $v1, 0x14($a1)
/* 3D800C E00DC59C 3C03F200 */  lui       $v1, 0xf200
/* 3D8010 E00DC5A0 00431025 */  or        $v0, $v0, $v1
/* 3D8014 E00DC5A4 00822025 */  or        $a0, $a0, $v0
/* 3D8018 E00DC5A8 2673007C */  addiu     $s3, $s3, 0x7c
/* 3D801C E00DC5AC 32730FFF */  andi      $s3, $s3, 0xfff
/* 3D8020 E00DC5B0 8FAA0098 */  lw        $t2, 0x98($sp)
/* 3D8024 E00DC5B4 00139B00 */  sll       $s3, $s3, 0xc
/* 3D8028 E00DC5B8 000A9080 */  sll       $s2, $t2, 2
/* 3D802C E00DC5BC 3C03E00E */  lui       $v1, %hi(D_E00DC648)
/* 3D8030 E00DC5C0 00721821 */  addu      $v1, $v1, $s2
/* 3D8034 E00DC5C4 8C63C648 */  lw        $v1, %lo(D_E00DC648)($v1)
/* 3D8038 E00DC5C8 02769825 */  or        $s3, $s3, $s6
/* 3D803C E00DC5CC ACA40020 */  sw        $a0, 0x20($a1)
/* 3D8040 E00DC5D0 ACB30024 */  sw        $s3, 0x24($a1)
/* 3D8044 E00DC5D4 ACA80028 */  sw        $t0, 0x28($a1)
/* 3D8048 E00DC5D8 ACA3001C */  sw        $v1, 0x1c($a1)
/* 3D804C E00DC5DC 3C03E00E */  lui       $v1, %hi(D_E00DC640)
/* 3D8050 E00DC5E0 00721821 */  addu      $v1, $v1, $s2
/* 3D8054 E00DC5E4 8C63C640 */  lw        $v1, %lo(D_E00DC640)($v1)
/* 3D8058 E00DC5E8 24A20030 */  addiu     $v0, $a1, 0x30
/* 3D805C E00DC5EC AE820000 */  sw        $v0, ($s4)
/* 3D8060 E00DC5F0 24A20038 */  addiu     $v0, $a1, 0x38
/* 3D8064 E00DC5F4 ACA3002C */  sw        $v1, 0x2c($a1)
/* 3D8068 E00DC5F8 AE820000 */  sw        $v0, ($s4)
/* 3D806C E00DC5FC 24020040 */  addiu     $v0, $zero, 0x40
/* 3D8070 E00DC600 ACA90030 */  sw        $t1, 0x30($a1)
/* 3D8074 E00DC604 ACA20034 */  sw        $v0, 0x34($a1)
/* 3D8078 E00DC608 8FBF00C4 */  lw        $ra, 0xc4($sp)
/* 3D807C E00DC60C 8FBE00C0 */  lw        $fp, 0xc0($sp)
/* 3D8080 E00DC610 8FB700BC */  lw        $s7, 0xbc($sp)
/* 3D8084 E00DC614 8FB600B8 */  lw        $s6, 0xb8($sp)
/* 3D8088 E00DC618 8FB500B4 */  lw        $s5, 0xb4($sp)
/* 3D808C E00DC61C 8FB400B0 */  lw        $s4, 0xb0($sp)
/* 3D8090 E00DC620 8FB300AC */  lw        $s3, 0xac($sp)
/* 3D8094 E00DC624 8FB200A8 */  lw        $s2, 0xa8($sp)
/* 3D8098 E00DC628 8FB100A4 */  lw        $s1, 0xa4($sp)
/* 3D809C E00DC62C 8FB000A0 */  lw        $s0, 0xa0($sp)
/* 3D80A0 E00DC630 03E00008 */  jr        $ra
/* 3D80A4 E00DC634 27BD00C8 */   addiu    $sp, $sp, 0xc8
/* 3D80A8 E00DC638 00000000 */  nop       
/* 3D80AC E00DC63C 00000000 */  nop       
