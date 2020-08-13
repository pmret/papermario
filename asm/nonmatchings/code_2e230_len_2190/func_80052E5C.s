.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80052E5C
/* 02E25C 80052E5C 27BDFFB8 */  addiu $sp, $sp, -0x48
/* 02E260 80052E60 AFB60040 */  sw    $s6, 0x40($sp)
/* 02E264 80052E64 0080B02D */  daddu $s6, $a0, $zero
/* 02E268 80052E68 24050001 */  addiu $a1, $zero, 1
/* 02E26C 80052E6C 3C028008 */  lui   $v0, 0x8008
/* 02E270 80052E70 8C428E54 */  lw    $v0, -0x71ac($v0)
/* 02E274 80052E74 240619E0 */  addiu $a2, $zero, 0x19e0
/* 02E278 80052E78 AFBF0044 */  sw    $ra, 0x44($sp)
/* 02E27C 80052E7C AFB5003C */  sw    $s5, 0x3c($sp)
/* 02E280 80052E80 AFB40038 */  sw    $s4, 0x38($sp)
/* 02E284 80052E84 AFB30034 */  sw    $s3, 0x34($sp)
/* 02E288 80052E88 AFB20030 */  sw    $s2, 0x30($sp)
/* 02E28C 80052E8C AFB1002C */  sw    $s1, 0x2c($sp)
/* 02E290 80052E90 AFB00028 */  sw    $s0, 0x28($sp)
/* 02E294 80052E94 8C550018 */  lw    $s5, 0x18($v0)
/* 02E298 80052E98 0000982D */  daddu $s3, $zero, $zero
/* 02E29C 80052E9C 0C015FE4 */  jal   alHeapAlloc
/* 02E2A0 80052EA0 02A0202D */   daddu $a0, $s5, $zero
/* 02E2A4 80052EA4 02A0202D */  daddu $a0, $s5, $zero
/* 02E2A8 80052EA8 24050001 */  addiu $a1, $zero, 1
/* 02E2AC 80052EAC 24060A9C */  addiu $a2, $zero, 0xa9c
/* 02E2B0 80052EB0 3C12800A */  lui   $s2, 0x800a
/* 02E2B4 80052EB4 2652A5C0 */  addiu $s2, $s2, -0x5a40
/* 02E2B8 80052EB8 0C015FE4 */  jal   alHeapAlloc
/* 02E2BC 80052EBC AE420000 */   sw    $v0, ($s2)
/* 02E2C0 80052EC0 02A0202D */  daddu $a0, $s5, $zero
/* 02E2C4 80052EC4 24050001 */  addiu $a1, $zero, 1
/* 02E2C8 80052EC8 24060A9C */  addiu $a2, $zero, 0xa9c
/* 02E2CC 80052ECC 3C11800A */  lui   $s1, 0x800a
/* 02E2D0 80052ED0 2631A664 */  addiu $s1, $s1, -0x599c
/* 02E2D4 80052ED4 0C015FE4 */  jal   alHeapAlloc
/* 02E2D8 80052ED8 AE220000 */   sw    $v0, ($s1)
/* 02E2DC 80052EDC 02A0202D */  daddu $a0, $s5, $zero
/* 02E2E0 80052EE0 24050001 */  addiu $a1, $zero, 1
/* 02E2E4 80052EE4 3C01800A */  lui   $at, 0x800a
/* 02E2E8 80052EE8 AC22A5FC */  sw    $v0, -0x5a04($at)
/* 02E2EC 80052EEC 0C015FE4 */  jal   alHeapAlloc
/* 02E2F0 80052EF0 24060A9C */   addiu $a2, $zero, 0xa9c
/* 02E2F4 80052EF4 02A0202D */  daddu $a0, $s5, $zero
/* 02E2F8 80052EF8 24050001 */  addiu $a1, $zero, 1
/* 02E2FC 80052EFC 3C01800A */  lui   $at, 0x800a
/* 02E300 80052F00 AC22A5CC */  sw    $v0, -0x5a34($at)
/* 02E304 80052F04 0C015FE4 */  jal   alHeapAlloc
/* 02E308 80052F08 240606CC */   addiu $a2, $zero, 0x6cc
/* 02E30C 80052F0C 02A0202D */  daddu $a0, $s5, $zero
/* 02E310 80052F10 24050001 */  addiu $a1, $zero, 1
/* 02E314 80052F14 24060834 */  addiu $a2, $zero, 0x834
/* 02E318 80052F18 3C10800A */  lui   $s0, 0x800a
/* 02E31C 80052F1C 2610A640 */  addiu $s0, $s0, -0x59c0
/* 02E320 80052F20 0C015FE4 */  jal   alHeapAlloc
/* 02E324 80052F24 AE020000 */   sw    $v0, ($s0)
/* 02E328 80052F28 02A0202D */  daddu $a0, $s5, $zero
/* 02E32C 80052F2C 24050001 */  addiu $a1, $zero, 1
/* 02E330 80052F30 8E280000 */  lw    $t0, ($s1)
/* 02E334 80052F34 8E070000 */  lw    $a3, ($s0)
/* 02E338 80052F38 8E430000 */  lw    $v1, ($s2)
/* 02E33C 80052F3C 34068000 */  ori   $a2, $zero, 0x8000
/* 02E340 80052F40 3C01800A */  lui   $at, 0x800a
/* 02E344 80052F44 AC22A628 */  sw    $v0, -0x59d8($at)
/* 02E348 80052F48 0060A02D */  daddu $s4, $v1, $zero
/* 02E34C 80052F4C AD070004 */  sw    $a3, 4($t0)
/* 02E350 80052F50 0C015FE4 */  jal   alHeapAlloc
/* 02E354 80052F54 AC430000 */   sw    $v1, ($v0)
/* 02E358 80052F58 0280802D */  daddu $s0, $s4, $zero
/* 02E35C 80052F5C 24435000 */  addiu $v1, $v0, 0x5000
/* 02E360 80052F60 AE82005C */  sw    $v0, 0x5c($s4)
/* 02E364 80052F64 24427000 */  addiu $v0, $v0, 0x7000
/* 02E368 80052F68 AE830060 */  sw    $v1, 0x60($s4)
/* 02E36C 80052F6C AE820064 */  sw    $v0, 0x64($s4)
/* 02E370 80052F70 AE830068 */  sw    $v1, 0x68($s4)
.L80052F74:
/* 02E374 80052F74 02A0202D */  daddu $a0, $s5, $zero
/* 02E378 80052F78 24050001 */  addiu $a1, $zero, 1
/* 02E37C 80052F7C 0C015FE4 */  jal   alHeapAlloc
/* 02E380 80052F80 24060A9C */   addiu $a2, $zero, 0xa9c
/* 02E384 80052F84 AE02006C */  sw    $v0, 0x6c($s0)
/* 02E388 80052F88 26730001 */  addiu $s3, $s3, 1
/* 02E38C 80052F8C 1260FFF9 */  beqz  $s3, .L80052F74
/* 02E390 80052F90 26100008 */   addiu $s0, $s0, 8
/* 02E394 80052F94 02A0202D */  daddu $a0, $s5, $zero
/* 02E398 80052F98 24050001 */  addiu $a1, $zero, 1
/* 02E39C 80052F9C 0C015FE4 */  jal   alHeapAlloc
/* 02E3A0 80052FA0 24065200 */   addiu $a2, $zero, 0x5200
/* 02E3A4 80052FA4 02A0202D */  daddu $a0, $s5, $zero
/* 02E3A8 80052FA8 24050001 */  addiu $a1, $zero, 1
/* 02E3AC 80052FAC 24060030 */  addiu $a2, $zero, 0x30
/* 02E3B0 80052FB0 0C015FE4 */  jal   alHeapAlloc
/* 02E3B4 80052FB4 AE8200A0 */   sw    $v0, 0xa0($s4)
/* 02E3B8 80052FB8 02A0202D */  daddu $a0, $s5, $zero
/* 02E3BC 80052FBC 24050001 */  addiu $a1, $zero, 1
/* 02E3C0 80052FC0 24060360 */  addiu $a2, $zero, 0x360
/* 02E3C4 80052FC4 0C015FE4 */  jal   alHeapAlloc
/* 02E3C8 80052FC8 AE820004 */   sw    $v0, 4($s4)
/* 02E3CC 80052FCC 02A0202D */  daddu $a0, $s5, $zero
/* 02E3D0 80052FD0 24050001 */  addiu $a1, $zero, 1
/* 02E3D4 80052FD4 24060200 */  addiu $a2, $zero, 0x200
/* 02E3D8 80052FD8 0C015FE4 */  jal   alHeapAlloc
/* 02E3DC 80052FDC AE820054 */   sw    $v0, 0x54($s4)
/* 02E3E0 80052FE0 02A0202D */  daddu $a0, $s5, $zero
/* 02E3E4 80052FE4 24050001 */  addiu $a1, $zero, 1
/* 02E3E8 80052FE8 24060040 */  addiu $a2, $zero, 0x40
/* 02E3EC 80052FEC 0C015FE4 */  jal   alHeapAlloc
/* 02E3F0 80052FF0 AE820058 */   sw    $v0, 0x58($s4)
/* 02E3F4 80052FF4 0000982D */  daddu $s3, $zero, $zero
/* 02E3F8 80052FF8 8E840004 */  lw    $a0, 4($s4)
/* 02E3FC 80052FFC 44960000 */  mtc1  $s6, $f0
/* 02E400 80053000 00000000 */  nop   
/* 02E404 80053004 46800020 */  cvt.s.w $f0, $f0
/* 02E408 80053008 AE820094 */  sw    $v0, 0x94($s4)
/* 02E40C 8005300C 0C014CBD */  jal   func_800532F4
/* 02E410 80053010 E6800000 */   swc1  $f0, ($s4)
/* 02E414 80053014 0C014CDC */  jal   func_80053370
/* 02E418 80053018 26840008 */   addiu $a0, $s4, 8
/* 02E41C 8005301C 0C014CEA */  jal   func_800533A8
/* 02E420 80053020 26840014 */   addiu $a0, $s4, 0x14
/* 02E424 80053024 0C015843 */  jal   func_8005610C
/* 02E428 80053028 00000000 */   nop   
/* 02E42C 8005302C 0280102D */  daddu $v0, $s4, $zero
/* 02E430 80053030 AE8000A4 */  sw    $zero, 0xa4($s4)
/* 02E434 80053034 AE8000A8 */  sw    $zero, 0xa8($s4)
.L80053038:
/* 02E438 80053038 A0400070 */  sb    $zero, 0x70($v0)
/* 02E43C 8005303C A0400071 */  sb    $zero, 0x71($v0)
/* 02E440 80053040 26730001 */  addiu $s3, $s3, 1
/* 02E444 80053044 1260FFFC */  beqz  $s3, .L80053038
/* 02E448 80053048 24420008 */   addiu $v0, $v0, 8
/* 02E44C 8005304C 0000982D */  daddu $s3, $zero, $zero
/* 02E450 80053050 0280182D */  daddu $v1, $s4, $zero
.L80053054:
/* 02E454 80053054 A0600040 */  sb    $zero, 0x40($v1)
/* 02E458 80053058 A0600041 */  sb    $zero, 0x41($v1)
/* 02E45C 8005305C 26730001 */  addiu $s3, $s3, 1
/* 02E460 80053060 2E620004 */  sltiu $v0, $s3, 4
/* 02E464 80053064 1440FFFB */  bnez  $v0, .L80053054
/* 02E468 80053068 24630004 */   addiu $v1, $v1, 4
/* 02E46C 8005306C 0000982D */  daddu $s3, $zero, $zero
/* 02E470 80053070 2416FFFF */  addiu $s6, $zero, -1
/* 02E474 80053074 241200FF */  addiu $s2, $zero, 0xff
/* 02E478 80053078 24111320 */  addiu $s1, $zero, 0x1320
.L8005307C:
/* 02E47C 8005307C 327000FF */  andi  $s0, $s3, 0xff
/* 02E480 80053080 0200202D */  daddu $a0, $s0, $zero
/* 02E484 80053084 0C015BB0 */  jal   func_80056EC0
/* 02E488 80053088 0000282D */   daddu $a1, $zero, $zero
/* 02E48C 8005308C 0200202D */  daddu $a0, $s0, $zero
/* 02E490 80053090 8E850004 */  lw    $a1, 4($s4)
/* 02E494 80053094 0C015C89 */  jal   func_80057224
/* 02E498 80053098 26730001 */   addiu $s3, $s3, 1
/* 02E49C 8005309C 02911021 */  addu  $v0, $s4, $s1
/* 02E4A0 800530A0 AC400000 */  sw    $zero, ($v0)
/* 02E4A4 800530A4 AC400004 */  sw    $zero, 4($v0)
/* 02E4A8 800530A8 A456000C */  sh    $s6, 0xc($v0)
/* 02E4AC 800530AC A052000E */  sb    $s2, 0xe($v0)
/* 02E4B0 800530B0 A052000F */  sb    $s2, 0xf($v0)
/* 02E4B4 800530B4 A0400010 */  sb    $zero, 0x10($v0)
/* 02E4B8 800530B8 A0400042 */  sb    $zero, 0x42($v0)
/* 02E4BC 800530BC A0400043 */  sb    $zero, 0x43($v0)
/* 02E4C0 800530C0 A0400044 */  sb    $zero, 0x44($v0)
/* 02E4C4 800530C4 A0400045 */  sb    $zero, 0x45($v0)
/* 02E4C8 800530C8 2E620018 */  sltiu $v0, $s3, 0x18
/* 02E4CC 800530CC 1440FFEB */  bnez  $v0, .L8005307C
/* 02E4D0 800530D0 26310048 */   addiu $s1, $s1, 0x48
/* 02E4D4 800530D4 0280202D */  daddu $a0, $s4, $zero
/* 02E4D8 800530D8 3C0500F0 */  lui   $a1, 0xf0
/* 02E4DC 800530DC 0C0150AF */  jal   al_LoadINIT
/* 02E4E0 800530E0 02A0302D */   daddu $a2, $s5, $zero
/* 02E4E4 800530E4 0000982D */  daddu $s3, $zero, $zero
/* 02E4E8 800530E8 0280802D */  daddu $s0, $s4, $zero
.L800530EC:
/* 02E4EC 800530EC 02A0202D */  daddu $a0, $s5, $zero
/* 02E4F0 800530F0 24050001 */  addiu $a1, $zero, 1
/* 02E4F4 800530F4 0C015FE4 */  jal   alHeapAlloc
/* 02E4F8 800530F8 24060840 */   addiu $a2, $zero, 0x840
/* 02E4FC 800530FC AE021310 */  sw    $v0, 0x1310($s0)
/* 02E500 80053100 26730001 */  addiu $s3, $s3, 1
/* 02E504 80053104 2E620003 */  sltiu $v0, $s3, 3
/* 02E508 80053108 1440FFF8 */  bnez  $v0, .L800530EC
/* 02E50C 8005310C 26100004 */   addiu $s0, $s0, 4
/* 02E510 80053110 24050001 */  addiu $a1, $zero, 1
/* 02E514 80053114 0000302D */  daddu $a2, $zero, $zero
/* 02E518 80053118 3C10800A */  lui   $s0, 0x800a
/* 02E51C 8005311C 2610A664 */  addiu $s0, $s0, -0x599c
/* 02E520 80053120 8E040000 */  lw    $a0, ($s0)
/* 02E524 80053124 0C013856 */  jal   func_8004E158
/* 02E528 80053128 0280382D */   daddu $a3, $s4, $zero
/* 02E52C 8005312C 27B20020 */  addiu $s2, $sp, 0x20
/* 02E530 80053130 0240282D */  daddu $a1, $s2, $zero
/* 02E534 80053134 24020003 */  addiu $v0, $zero, 3
/* 02E538 80053138 8E040000 */  lw    $a0, ($s0)
/* 02E53C 8005313C 241000FF */  addiu $s0, $zero, 0xff
/* 02E540 80053140 A3A00020 */  sb    $zero, 0x20($sp)
/* 02E544 80053144 A3A20021 */  sb    $v0, 0x21($sp)
/* 02E548 80053148 A3B00022 */  sb    $s0, 0x22($sp)
/* 02E54C 8005314C 0C0138D1 */  jal   func_8004E344
/* 02E550 80053150 A3B00023 */   sb    $s0, 0x23($sp)
/* 02E554 80053154 24050002 */  addiu $a1, $zero, 2
/* 02E558 80053158 00A0302D */  daddu $a2, $a1, $zero
/* 02E55C 8005315C 3C11800A */  lui   $s1, 0x800a
/* 02E560 80053160 2631A5FC */  addiu $s1, $s1, -0x5a04
/* 02E564 80053164 8E240000 */  lw    $a0, ($s1)
/* 02E568 80053168 0C013856 */  jal   func_8004E158
/* 02E56C 8005316C 0280382D */   daddu $a3, $s4, $zero
/* 02E570 80053170 0240282D */  daddu $a1, $s2, $zero
/* 02E574 80053174 8E240000 */  lw    $a0, ($s1)
/* 02E578 80053178 24020002 */  addiu $v0, $zero, 2
/* 02E57C 8005317C A3A20020 */  sb    $v0, 0x20($sp)
/* 02E580 80053180 A3B00021 */  sb    $s0, 0x21($sp)
/* 02E584 80053184 A3B00022 */  sb    $s0, 0x22($sp)
/* 02E588 80053188 0C0138D1 */  jal   func_8004E344
/* 02E58C 8005318C A3B00023 */   sb    $s0, 0x23($sp)
/* 02E590 80053190 24050004 */  addiu $a1, $zero, 4
/* 02E594 80053194 24060001 */  addiu $a2, $zero, 1
/* 02E598 80053198 0280382D */  daddu $a3, $s4, $zero
/* 02E59C 8005319C 3C10800A */  lui   $s0, 0x800a
/* 02E5A0 800531A0 2610A640 */  addiu $s0, $s0, -0x59c0
/* 02E5A4 800531A4 8E040000 */  lw    $a0, ($s0)
/* 02E5A8 800531A8 24020010 */  addiu $v0, $zero, 0x10
/* 02E5AC 800531AC 0C012D10 */  jal   func_8004B440
/* 02E5B0 800531B0 AFA20010 */   sw    $v0, 0x10($sp)
/* 02E5B4 800531B4 24050006 */  addiu $a1, $zero, 6
/* 02E5B8 800531B8 24060001 */  addiu $a2, $zero, 1
/* 02E5BC 800531BC 3C04800A */  lui   $a0, 0x800a
/* 02E5C0 800531C0 8C84A628 */  lw    $a0, -0x59d8($a0)
/* 02E5C4 800531C4 0C0142E4 */  jal   func_80050B90
/* 02E5C8 800531C8 0280382D */   daddu $a3, $s4, $zero
/* 02E5CC 800531CC 0C014985 */  jal   func_80052614
/* 02E5D0 800531D0 0280202D */   daddu $a0, $s4, $zero
/* 02E5D4 800531D4 0280202D */  daddu $a0, $s4, $zero
/* 02E5D8 800531D8 0C0153F0 */  jal   al_LoadBKHeaders
/* 02E5DC 800531DC 02A0282D */   daddu $a1, $s5, $zero
/* 02E5E0 800531E0 8E82003C */  lw    $v0, 0x3c($s4)
/* 02E5E4 800531E4 24050020 */  addiu $a1, $zero, 0x20
/* 02E5E8 800531E8 94440000 */  lhu   $a0, ($v0)
/* 02E5EC 800531EC 0C01511F */  jal   al_CopyFileTableEntry
/* 02E5F0 800531F0 27A60018 */   addiu $a2, $sp, 0x18
/* 02E5F4 800531F4 14400007 */  bnez  $v0, .L80053214
/* 02E5F8 800531F8 3C0200FF */   lui   $v0, 0xff
/* 02E5FC 800531FC 3442FFFF */  ori   $v0, $v0, 0xffff
/* 02E600 80053200 8FA40018 */  lw    $a0, 0x18($sp)
/* 02E604 80053204 8FA6001C */  lw    $a2, 0x1c($sp)
/* 02E608 80053208 8E8500A0 */  lw    $a1, 0xa0($s4)
/* 02E60C 8005320C 0C015380 */  jal   al_DmaCopy
/* 02E610 80053210 00C23024 */   and   $a2, $a2, $v0
.L80053214:
/* 02E614 80053214 8E040000 */  lw    $a0, ($s0)
/* 02E618 80053218 0C012D8B */  jal   func_8004B62C
/* 02E61C 8005321C 00000000 */   nop   
/* 02E620 80053220 8E82003C */  lw    $v0, 0x3c($s4)
/* 02E624 80053224 24050040 */  addiu $a1, $zero, 0x40
/* 02E628 80053228 94440002 */  lhu   $a0, 2($v0)
/* 02E62C 8005322C 0C01511F */  jal   al_CopyFileTableEntry
/* 02E630 80053230 27A60018 */   addiu $a2, $sp, 0x18
/* 02E634 80053234 14400004 */  bnez  $v0, .L80053248
/* 02E638 80053238 00000000 */   nop   
/* 02E63C 8005323C 8FA50018 */  lw    $a1, 0x18($sp)
/* 02E640 80053240 0C01513E */  jal   al_LoadPER
/* 02E644 80053244 0280202D */   daddu $a0, $s4, $zero
.L80053248:
/* 02E648 80053248 8E82003C */  lw    $v0, 0x3c($s4)
/* 02E64C 8005324C 24050040 */  addiu $a1, $zero, 0x40
/* 02E650 80053250 94440004 */  lhu   $a0, 4($v0)
/* 02E654 80053254 0C01511F */  jal   al_CopyFileTableEntry
/* 02E658 80053258 27A60018 */   addiu $a2, $sp, 0x18
/* 02E65C 8005325C 54400005 */  bnel  $v0, $zero, .L80053274
/* 02E660 80053260 0000202D */   daddu $a0, $zero, $zero
/* 02E664 80053264 8FA50018 */  lw    $a1, 0x18($sp)
/* 02E668 80053268 0C01516D */  jal   al_LoadPRG
/* 02E66C 8005326C 0280202D */   daddu $a0, $s4, $zero
/* 02E670 80053270 0000202D */  daddu $a0, $zero, $zero
.L80053274:
/* 02E674 80053274 268304EC */  addiu $v1, $s4, 0x4ec
/* 02E678 80053278 268205EC */  addiu $v0, $s4, 0x5ec
/* 02E67C 8005327C AE8212F0 */  sw    $v0, 0x12f0($s4)
/* 02E680 80053280 268200AC */  addiu $v0, $s4, 0xac
/* 02E684 80053284 AE8212F4 */  sw    $v0, 0x12f4($s4)
/* 02E688 80053288 268200EC */  addiu $v0, $s4, 0xec
/* 02E68C 8005328C AE8212F8 */  sw    $v0, 0x12f8($s4)
/* 02E690 80053290 268209EC */  addiu $v0, $s4, 0x9ec
/* 02E694 80053294 AE8212FC */  sw    $v0, 0x12fc($s4)
/* 02E698 80053298 26820DEC */  addiu $v0, $s4, 0xdec
/* 02E69C 8005329C AE821300 */  sw    $v0, 0x1300($s4)
/* 02E6A0 800532A0 268211EC */  addiu $v0, $s4, 0x11ec
/* 02E6A4 800532A4 AE8312EC */  sw    $v1, 0x12ec($s4)
/* 02E6A8 800532A8 AE821304 */  sw    $v0, 0x1304($s4)
/* 02E6AC 800532AC AE831308 */  sw    $v1, 0x1308($s4)
/* 02E6B0 800532B0 A2800053 */  sb    $zero, 0x53($s4)
/* 02E6B4 800532B4 A2800052 */  sb    $zero, 0x52($s4)
/* 02E6B8 800532B8 A2800051 */  sb    $zero, 0x51($s4)
/* 02E6BC 800532BC 0C015FB4 */  jal   func_80057ED0
/* 02E6C0 800532C0 A2800050 */   sb    $zero, 0x50($s4)
/* 02E6C4 800532C4 0C015414 */  jal   func_80055050
/* 02E6C8 800532C8 02A0202D */   daddu $a0, $s5, $zero
/* 02E6CC 800532CC 8FBF0044 */  lw    $ra, 0x44($sp)
/* 02E6D0 800532D0 8FB60040 */  lw    $s6, 0x40($sp)
/* 02E6D4 800532D4 8FB5003C */  lw    $s5, 0x3c($sp)
/* 02E6D8 800532D8 8FB40038 */  lw    $s4, 0x38($sp)
/* 02E6DC 800532DC 8FB30034 */  lw    $s3, 0x34($sp)
/* 02E6E0 800532E0 8FB20030 */  lw    $s2, 0x30($sp)
/* 02E6E4 800532E4 8FB1002C */  lw    $s1, 0x2c($sp)
/* 02E6E8 800532E8 8FB00028 */  lw    $s0, 0x28($sp)
/* 02E6EC 800532EC 03E00008 */  jr    $ra
/* 02E6F0 800532F0 27BD0048 */   addiu $sp, $sp, 0x48

