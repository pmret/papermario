.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80052E5C
/* 2E25C 80052E5C 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 2E260 80052E60 AFB60040 */  sw        $s6, 0x40($sp)
/* 2E264 80052E64 0080B02D */  daddu     $s6, $a0, $zero
/* 2E268 80052E68 24050001 */  addiu     $a1, $zero, 1
/* 2E26C 80052E6C 3C028008 */  lui       $v0, 0x8008
/* 2E270 80052E70 8C428E54 */  lw        $v0, -0x71ac($v0)
/* 2E274 80052E74 240619E0 */  addiu     $a2, $zero, 0x19e0
/* 2E278 80052E78 AFBF0044 */  sw        $ra, 0x44($sp)
/* 2E27C 80052E7C AFB5003C */  sw        $s5, 0x3c($sp)
/* 2E280 80052E80 AFB40038 */  sw        $s4, 0x38($sp)
/* 2E284 80052E84 AFB30034 */  sw        $s3, 0x34($sp)
/* 2E288 80052E88 AFB20030 */  sw        $s2, 0x30($sp)
/* 2E28C 80052E8C AFB1002C */  sw        $s1, 0x2c($sp)
/* 2E290 80052E90 AFB00028 */  sw        $s0, 0x28($sp)
/* 2E294 80052E94 8C550018 */  lw        $s5, 0x18($v0)
/* 2E298 80052E98 0000982D */  daddu     $s3, $zero, $zero
/* 2E29C 80052E9C 0C015FE4 */  jal       alHeapAlloc
/* 2E2A0 80052EA0 02A0202D */   daddu    $a0, $s5, $zero
/* 2E2A4 80052EA4 02A0202D */  daddu     $a0, $s5, $zero
/* 2E2A8 80052EA8 24050001 */  addiu     $a1, $zero, 1
/* 2E2AC 80052EAC 24060A9C */  addiu     $a2, $zero, 0xa9c
/* 2E2B0 80052EB0 3C12800A */  lui       $s2, 0x800a
/* 2E2B4 80052EB4 2652A5C0 */  addiu     $s2, $s2, -0x5a40
/* 2E2B8 80052EB8 0C015FE4 */  jal       alHeapAlloc
/* 2E2BC 80052EBC AE420000 */   sw       $v0, ($s2)
/* 2E2C0 80052EC0 02A0202D */  daddu     $a0, $s5, $zero
/* 2E2C4 80052EC4 24050001 */  addiu     $a1, $zero, 1
/* 2E2C8 80052EC8 24060A9C */  addiu     $a2, $zero, 0xa9c
/* 2E2CC 80052ECC 3C11800A */  lui       $s1, 0x800a
/* 2E2D0 80052ED0 2631A664 */  addiu     $s1, $s1, -0x599c
/* 2E2D4 80052ED4 0C015FE4 */  jal       alHeapAlloc
/* 2E2D8 80052ED8 AE220000 */   sw       $v0, ($s1)
/* 2E2DC 80052EDC 02A0202D */  daddu     $a0, $s5, $zero
/* 2E2E0 80052EE0 24050001 */  addiu     $a1, $zero, 1
/* 2E2E4 80052EE4 3C01800A */  lui       $at, 0x800a
/* 2E2E8 80052EE8 AC22A5FC */  sw        $v0, -0x5a04($at)
/* 2E2EC 80052EEC 0C015FE4 */  jal       alHeapAlloc
/* 2E2F0 80052EF0 24060A9C */   addiu    $a2, $zero, 0xa9c
/* 2E2F4 80052EF4 02A0202D */  daddu     $a0, $s5, $zero
/* 2E2F8 80052EF8 24050001 */  addiu     $a1, $zero, 1
/* 2E2FC 80052EFC 3C01800A */  lui       $at, 0x800a
/* 2E300 80052F00 AC22A5CC */  sw        $v0, -0x5a34($at)
/* 2E304 80052F04 0C015FE4 */  jal       alHeapAlloc
/* 2E308 80052F08 240606CC */   addiu    $a2, $zero, 0x6cc
/* 2E30C 80052F0C 02A0202D */  daddu     $a0, $s5, $zero
/* 2E310 80052F10 24050001 */  addiu     $a1, $zero, 1
/* 2E314 80052F14 24060834 */  addiu     $a2, $zero, 0x834
/* 2E318 80052F18 3C10800A */  lui       $s0, 0x800a
/* 2E31C 80052F1C 2610A640 */  addiu     $s0, $s0, -0x59c0
/* 2E320 80052F20 0C015FE4 */  jal       alHeapAlloc
/* 2E324 80052F24 AE020000 */   sw       $v0, ($s0)
/* 2E328 80052F28 02A0202D */  daddu     $a0, $s5, $zero
/* 2E32C 80052F2C 24050001 */  addiu     $a1, $zero, 1
/* 2E330 80052F30 8E280000 */  lw        $t0, ($s1)
/* 2E334 80052F34 8E070000 */  lw        $a3, ($s0)
/* 2E338 80052F38 8E430000 */  lw        $v1, ($s2)
/* 2E33C 80052F3C 34068000 */  ori       $a2, $zero, 0x8000
/* 2E340 80052F40 3C01800A */  lui       $at, 0x800a
/* 2E344 80052F44 AC22A628 */  sw        $v0, -0x59d8($at)
/* 2E348 80052F48 0060A02D */  daddu     $s4, $v1, $zero
/* 2E34C 80052F4C AD070004 */  sw        $a3, 4($t0)
/* 2E350 80052F50 0C015FE4 */  jal       alHeapAlloc
/* 2E354 80052F54 AC430000 */   sw       $v1, ($v0)
/* 2E358 80052F58 0280802D */  daddu     $s0, $s4, $zero
/* 2E35C 80052F5C 24435000 */  addiu     $v1, $v0, 0x5000
/* 2E360 80052F60 AE82005C */  sw        $v0, 0x5c($s4)
/* 2E364 80052F64 24427000 */  addiu     $v0, $v0, 0x7000
/* 2E368 80052F68 AE830060 */  sw        $v1, 0x60($s4)
/* 2E36C 80052F6C AE820064 */  sw        $v0, 0x64($s4)
/* 2E370 80052F70 AE830068 */  sw        $v1, 0x68($s4)
.L80052F74:
/* 2E374 80052F74 02A0202D */  daddu     $a0, $s5, $zero
/* 2E378 80052F78 24050001 */  addiu     $a1, $zero, 1
/* 2E37C 80052F7C 0C015FE4 */  jal       alHeapAlloc
/* 2E380 80052F80 24060A9C */   addiu    $a2, $zero, 0xa9c
/* 2E384 80052F84 AE02006C */  sw        $v0, 0x6c($s0)
/* 2E388 80052F88 26730001 */  addiu     $s3, $s3, 1
/* 2E38C 80052F8C 1260FFF9 */  beqz      $s3, .L80052F74
/* 2E390 80052F90 26100008 */   addiu    $s0, $s0, 8
/* 2E394 80052F94 02A0202D */  daddu     $a0, $s5, $zero
/* 2E398 80052F98 24050001 */  addiu     $a1, $zero, 1
/* 2E39C 80052F9C 0C015FE4 */  jal       alHeapAlloc
/* 2E3A0 80052FA0 24065200 */   addiu    $a2, $zero, 0x5200
/* 2E3A4 80052FA4 02A0202D */  daddu     $a0, $s5, $zero
/* 2E3A8 80052FA8 24050001 */  addiu     $a1, $zero, 1
/* 2E3AC 80052FAC 24060030 */  addiu     $a2, $zero, 0x30
/* 2E3B0 80052FB0 0C015FE4 */  jal       alHeapAlloc
/* 2E3B4 80052FB4 AE8200A0 */   sw       $v0, 0xa0($s4)
/* 2E3B8 80052FB8 02A0202D */  daddu     $a0, $s5, $zero
/* 2E3BC 80052FBC 24050001 */  addiu     $a1, $zero, 1
/* 2E3C0 80052FC0 24060360 */  addiu     $a2, $zero, 0x360
/* 2E3C4 80052FC4 0C015FE4 */  jal       alHeapAlloc
/* 2E3C8 80052FC8 AE820004 */   sw       $v0, 4($s4)
/* 2E3CC 80052FCC 02A0202D */  daddu     $a0, $s5, $zero
/* 2E3D0 80052FD0 24050001 */  addiu     $a1, $zero, 1
/* 2E3D4 80052FD4 24060200 */  addiu     $a2, $zero, 0x200
/* 2E3D8 80052FD8 0C015FE4 */  jal       alHeapAlloc
/* 2E3DC 80052FDC AE820054 */   sw       $v0, 0x54($s4)
/* 2E3E0 80052FE0 02A0202D */  daddu     $a0, $s5, $zero
/* 2E3E4 80052FE4 24050001 */  addiu     $a1, $zero, 1
/* 2E3E8 80052FE8 24060040 */  addiu     $a2, $zero, 0x40
/* 2E3EC 80052FEC 0C015FE4 */  jal       alHeapAlloc
/* 2E3F0 80052FF0 AE820058 */   sw       $v0, 0x58($s4)
/* 2E3F4 80052FF4 0000982D */  daddu     $s3, $zero, $zero
/* 2E3F8 80052FF8 8E840004 */  lw        $a0, 4($s4)
/* 2E3FC 80052FFC 44960000 */  mtc1      $s6, $f0
/* 2E400 80053000 00000000 */  nop       
/* 2E404 80053004 46800020 */  cvt.s.w   $f0, $f0
/* 2E408 80053008 AE820094 */  sw        $v0, 0x94($s4)
/* 2E40C 8005300C 0C014CBD */  jal       func_800532F4
/* 2E410 80053010 E6800000 */   swc1     $f0, ($s4)
/* 2E414 80053014 0C014CDC */  jal       func_80053370
/* 2E418 80053018 26840008 */   addiu    $a0, $s4, 8
/* 2E41C 8005301C 0C014CEA */  jal       func_800533A8
/* 2E420 80053020 26840014 */   addiu    $a0, $s4, 0x14
/* 2E424 80053024 0C015843 */  jal       func_8005610C
/* 2E428 80053028 00000000 */   nop      
/* 2E42C 8005302C 0280102D */  daddu     $v0, $s4, $zero
/* 2E430 80053030 AE8000A4 */  sw        $zero, 0xa4($s4)
/* 2E434 80053034 AE8000A8 */  sw        $zero, 0xa8($s4)
.L80053038:
/* 2E438 80053038 A0400070 */  sb        $zero, 0x70($v0)
/* 2E43C 8005303C A0400071 */  sb        $zero, 0x71($v0)
/* 2E440 80053040 26730001 */  addiu     $s3, $s3, 1
/* 2E444 80053044 1260FFFC */  beqz      $s3, .L80053038
/* 2E448 80053048 24420008 */   addiu    $v0, $v0, 8
/* 2E44C 8005304C 0000982D */  daddu     $s3, $zero, $zero
/* 2E450 80053050 0280182D */  daddu     $v1, $s4, $zero
.L80053054:
/* 2E454 80053054 A0600040 */  sb        $zero, 0x40($v1)
/* 2E458 80053058 A0600041 */  sb        $zero, 0x41($v1)
/* 2E45C 8005305C 26730001 */  addiu     $s3, $s3, 1
/* 2E460 80053060 2E620004 */  sltiu     $v0, $s3, 4
/* 2E464 80053064 1440FFFB */  bnez      $v0, .L80053054
/* 2E468 80053068 24630004 */   addiu    $v1, $v1, 4
/* 2E46C 8005306C 0000982D */  daddu     $s3, $zero, $zero
/* 2E470 80053070 2416FFFF */  addiu     $s6, $zero, -1
/* 2E474 80053074 241200FF */  addiu     $s2, $zero, 0xff
/* 2E478 80053078 24111320 */  addiu     $s1, $zero, 0x1320
.L8005307C:
/* 2E47C 8005307C 327000FF */  andi      $s0, $s3, 0xff
/* 2E480 80053080 0200202D */  daddu     $a0, $s0, $zero
/* 2E484 80053084 0C015BB0 */  jal       func_80056EC0
/* 2E488 80053088 0000282D */   daddu    $a1, $zero, $zero
/* 2E48C 8005308C 0200202D */  daddu     $a0, $s0, $zero
/* 2E490 80053090 8E850004 */  lw        $a1, 4($s4)
/* 2E494 80053094 0C015C89 */  jal       func_80057224
/* 2E498 80053098 26730001 */   addiu    $s3, $s3, 1
/* 2E49C 8005309C 02911021 */  addu      $v0, $s4, $s1
/* 2E4A0 800530A0 AC400000 */  sw        $zero, ($v0)
/* 2E4A4 800530A4 AC400004 */  sw        $zero, 4($v0)
/* 2E4A8 800530A8 A456000C */  sh        $s6, 0xc($v0)
/* 2E4AC 800530AC A052000E */  sb        $s2, 0xe($v0)
/* 2E4B0 800530B0 A052000F */  sb        $s2, 0xf($v0)
/* 2E4B4 800530B4 A0400010 */  sb        $zero, 0x10($v0)
/* 2E4B8 800530B8 A0400042 */  sb        $zero, 0x42($v0)
/* 2E4BC 800530BC A0400043 */  sb        $zero, 0x43($v0)
/* 2E4C0 800530C0 A0400044 */  sb        $zero, 0x44($v0)
/* 2E4C4 800530C4 A0400045 */  sb        $zero, 0x45($v0)
/* 2E4C8 800530C8 2E620018 */  sltiu     $v0, $s3, 0x18
/* 2E4CC 800530CC 1440FFEB */  bnez      $v0, .L8005307C
/* 2E4D0 800530D0 26310048 */   addiu    $s1, $s1, 0x48
/* 2E4D4 800530D4 0280202D */  daddu     $a0, $s4, $zero
/* 2E4D8 800530D8 3C0500F0 */  lui       $a1, 0xf0
/* 2E4DC 800530DC 0C0150AF */  jal       al_LoadINIT
/* 2E4E0 800530E0 02A0302D */   daddu    $a2, $s5, $zero
/* 2E4E4 800530E4 0000982D */  daddu     $s3, $zero, $zero
/* 2E4E8 800530E8 0280802D */  daddu     $s0, $s4, $zero
.L800530EC:
/* 2E4EC 800530EC 02A0202D */  daddu     $a0, $s5, $zero
/* 2E4F0 800530F0 24050001 */  addiu     $a1, $zero, 1
/* 2E4F4 800530F4 0C015FE4 */  jal       alHeapAlloc
/* 2E4F8 800530F8 24060840 */   addiu    $a2, $zero, 0x840
/* 2E4FC 800530FC AE021310 */  sw        $v0, 0x1310($s0)
/* 2E500 80053100 26730001 */  addiu     $s3, $s3, 1
/* 2E504 80053104 2E620003 */  sltiu     $v0, $s3, 3
/* 2E508 80053108 1440FFF8 */  bnez      $v0, .L800530EC
/* 2E50C 8005310C 26100004 */   addiu    $s0, $s0, 4
/* 2E510 80053110 24050001 */  addiu     $a1, $zero, 1
/* 2E514 80053114 0000302D */  daddu     $a2, $zero, $zero
/* 2E518 80053118 3C10800A */  lui       $s0, 0x800a
/* 2E51C 8005311C 2610A664 */  addiu     $s0, $s0, -0x599c
/* 2E520 80053120 8E040000 */  lw        $a0, ($s0)
/* 2E524 80053124 0C013856 */  jal       func_8004E158
/* 2E528 80053128 0280382D */   daddu    $a3, $s4, $zero
/* 2E52C 8005312C 27B20020 */  addiu     $s2, $sp, 0x20
/* 2E530 80053130 0240282D */  daddu     $a1, $s2, $zero
/* 2E534 80053134 24020003 */  addiu     $v0, $zero, 3
/* 2E538 80053138 8E040000 */  lw        $a0, ($s0)
/* 2E53C 8005313C 241000FF */  addiu     $s0, $zero, 0xff
/* 2E540 80053140 A3A00020 */  sb        $zero, 0x20($sp)
/* 2E544 80053144 A3A20021 */  sb        $v0, 0x21($sp)
/* 2E548 80053148 A3B00022 */  sb        $s0, 0x22($sp)
/* 2E54C 8005314C 0C0138D1 */  jal       func_8004E344
/* 2E550 80053150 A3B00023 */   sb       $s0, 0x23($sp)
/* 2E554 80053154 24050002 */  addiu     $a1, $zero, 2
/* 2E558 80053158 00A0302D */  daddu     $a2, $a1, $zero
/* 2E55C 8005315C 3C11800A */  lui       $s1, 0x800a
/* 2E560 80053160 2631A5FC */  addiu     $s1, $s1, -0x5a04
/* 2E564 80053164 8E240000 */  lw        $a0, ($s1)
/* 2E568 80053168 0C013856 */  jal       func_8004E158
/* 2E56C 8005316C 0280382D */   daddu    $a3, $s4, $zero
/* 2E570 80053170 0240282D */  daddu     $a1, $s2, $zero
/* 2E574 80053174 8E240000 */  lw        $a0, ($s1)
/* 2E578 80053178 24020002 */  addiu     $v0, $zero, 2
/* 2E57C 8005317C A3A20020 */  sb        $v0, 0x20($sp)
/* 2E580 80053180 A3B00021 */  sb        $s0, 0x21($sp)
/* 2E584 80053184 A3B00022 */  sb        $s0, 0x22($sp)
/* 2E588 80053188 0C0138D1 */  jal       func_8004E344
/* 2E58C 8005318C A3B00023 */   sb       $s0, 0x23($sp)
/* 2E590 80053190 24050004 */  addiu     $a1, $zero, 4
/* 2E594 80053194 24060001 */  addiu     $a2, $zero, 1
/* 2E598 80053198 0280382D */  daddu     $a3, $s4, $zero
/* 2E59C 8005319C 3C10800A */  lui       $s0, 0x800a
/* 2E5A0 800531A0 2610A640 */  addiu     $s0, $s0, -0x59c0
/* 2E5A4 800531A4 8E040000 */  lw        $a0, ($s0)
/* 2E5A8 800531A8 24020010 */  addiu     $v0, $zero, 0x10
/* 2E5AC 800531AC 0C012D10 */  jal       func_8004B440
/* 2E5B0 800531B0 AFA20010 */   sw       $v0, 0x10($sp)
/* 2E5B4 800531B4 24050006 */  addiu     $a1, $zero, 6
/* 2E5B8 800531B8 24060001 */  addiu     $a2, $zero, 1
/* 2E5BC 800531BC 3C04800A */  lui       $a0, 0x800a
/* 2E5C0 800531C0 8C84A628 */  lw        $a0, -0x59d8($a0)
/* 2E5C4 800531C4 0C0142E4 */  jal       func_80050B90
/* 2E5C8 800531C8 0280382D */   daddu    $a3, $s4, $zero
/* 2E5CC 800531CC 0C014985 */  jal       func_80052614
/* 2E5D0 800531D0 0280202D */   daddu    $a0, $s4, $zero
/* 2E5D4 800531D4 0280202D */  daddu     $a0, $s4, $zero
/* 2E5D8 800531D8 0C0153F0 */  jal       al_LoadBKHeaders
/* 2E5DC 800531DC 02A0282D */   daddu    $a1, $s5, $zero
/* 2E5E0 800531E0 8E82003C */  lw        $v0, 0x3c($s4)
/* 2E5E4 800531E4 24050020 */  addiu     $a1, $zero, 0x20
/* 2E5E8 800531E8 94440000 */  lhu       $a0, ($v0)
/* 2E5EC 800531EC 0C01511F */  jal       al_CopyFileTableEntry
/* 2E5F0 800531F0 27A60018 */   addiu    $a2, $sp, 0x18
/* 2E5F4 800531F4 14400007 */  bnez      $v0, .L80053214
/* 2E5F8 800531F8 3C0200FF */   lui      $v0, 0xff
/* 2E5FC 800531FC 3442FFFF */  ori       $v0, $v0, 0xffff
/* 2E600 80053200 8FA40018 */  lw        $a0, 0x18($sp)
/* 2E604 80053204 8FA6001C */  lw        $a2, 0x1c($sp)
/* 2E608 80053208 8E8500A0 */  lw        $a1, 0xa0($s4)
/* 2E60C 8005320C 0C015380 */  jal       al_DmaCopy
/* 2E610 80053210 00C23024 */   and      $a2, $a2, $v0
.L80053214:
/* 2E614 80053214 8E040000 */  lw        $a0, ($s0)
/* 2E618 80053218 0C012D8B */  jal       func_8004B62C
/* 2E61C 8005321C 00000000 */   nop      
/* 2E620 80053220 8E82003C */  lw        $v0, 0x3c($s4)
/* 2E624 80053224 24050040 */  addiu     $a1, $zero, 0x40
/* 2E628 80053228 94440002 */  lhu       $a0, 2($v0)
/* 2E62C 8005322C 0C01511F */  jal       al_CopyFileTableEntry
/* 2E630 80053230 27A60018 */   addiu    $a2, $sp, 0x18
/* 2E634 80053234 14400004 */  bnez      $v0, .L80053248
/* 2E638 80053238 00000000 */   nop      
/* 2E63C 8005323C 8FA50018 */  lw        $a1, 0x18($sp)
/* 2E640 80053240 0C01513E */  jal       al_LoadPER
/* 2E644 80053244 0280202D */   daddu    $a0, $s4, $zero
.L80053248:
/* 2E648 80053248 8E82003C */  lw        $v0, 0x3c($s4)
/* 2E64C 8005324C 24050040 */  addiu     $a1, $zero, 0x40
/* 2E650 80053250 94440004 */  lhu       $a0, 4($v0)
/* 2E654 80053254 0C01511F */  jal       al_CopyFileTableEntry
/* 2E658 80053258 27A60018 */   addiu    $a2, $sp, 0x18
/* 2E65C 8005325C 54400005 */  bnel      $v0, $zero, .L80053274
/* 2E660 80053260 0000202D */   daddu    $a0, $zero, $zero
/* 2E664 80053264 8FA50018 */  lw        $a1, 0x18($sp)
/* 2E668 80053268 0C01516D */  jal       al_LoadPRG
/* 2E66C 8005326C 0280202D */   daddu    $a0, $s4, $zero
/* 2E670 80053270 0000202D */  daddu     $a0, $zero, $zero
.L80053274:
/* 2E674 80053274 268304EC */  addiu     $v1, $s4, 0x4ec
/* 2E678 80053278 268205EC */  addiu     $v0, $s4, 0x5ec
/* 2E67C 8005327C AE8212F0 */  sw        $v0, 0x12f0($s4)
/* 2E680 80053280 268200AC */  addiu     $v0, $s4, 0xac
/* 2E684 80053284 AE8212F4 */  sw        $v0, 0x12f4($s4)
/* 2E688 80053288 268200EC */  addiu     $v0, $s4, 0xec
/* 2E68C 8005328C AE8212F8 */  sw        $v0, 0x12f8($s4)
/* 2E690 80053290 268209EC */  addiu     $v0, $s4, 0x9ec
/* 2E694 80053294 AE8212FC */  sw        $v0, 0x12fc($s4)
/* 2E698 80053298 26820DEC */  addiu     $v0, $s4, 0xdec
/* 2E69C 8005329C AE821300 */  sw        $v0, 0x1300($s4)
/* 2E6A0 800532A0 268211EC */  addiu     $v0, $s4, 0x11ec
/* 2E6A4 800532A4 AE8312EC */  sw        $v1, 0x12ec($s4)
/* 2E6A8 800532A8 AE821304 */  sw        $v0, 0x1304($s4)
/* 2E6AC 800532AC AE831308 */  sw        $v1, 0x1308($s4)
/* 2E6B0 800532B0 A2800053 */  sb        $zero, 0x53($s4)
/* 2E6B4 800532B4 A2800052 */  sb        $zero, 0x52($s4)
/* 2E6B8 800532B8 A2800051 */  sb        $zero, 0x51($s4)
/* 2E6BC 800532BC 0C015FB4 */  jal       func_80057ED0
/* 2E6C0 800532C0 A2800050 */   sb       $zero, 0x50($s4)
/* 2E6C4 800532C4 0C015414 */  jal       func_80055050
/* 2E6C8 800532C8 02A0202D */   daddu    $a0, $s5, $zero
/* 2E6CC 800532CC 8FBF0044 */  lw        $ra, 0x44($sp)
/* 2E6D0 800532D0 8FB60040 */  lw        $s6, 0x40($sp)
/* 2E6D4 800532D4 8FB5003C */  lw        $s5, 0x3c($sp)
/* 2E6D8 800532D8 8FB40038 */  lw        $s4, 0x38($sp)
/* 2E6DC 800532DC 8FB30034 */  lw        $s3, 0x34($sp)
/* 2E6E0 800532E0 8FB20030 */  lw        $s2, 0x30($sp)
/* 2E6E4 800532E4 8FB1002C */  lw        $s1, 0x2c($sp)
/* 2E6E8 800532E8 8FB00028 */  lw        $s0, 0x28($sp)
/* 2E6EC 800532EC 03E00008 */  jr        $ra
/* 2E6F0 800532F0 27BD0048 */   addiu    $sp, $sp, 0x48
