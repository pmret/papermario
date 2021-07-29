.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8013E2F0
/* D49F0 8013E2F0 3C028007 */  lui       $v0, %hi(gCurrentDisplayContextIndex)
/* D49F4 8013E2F4 8C4241F4 */  lw        $v0, %lo(gCurrentDisplayContextIndex)($v0)
/* D49F8 8013E2F8 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* D49FC 8013E2FC AFB3002C */  sw        $s3, 0x2c($sp)
/* D4A00 8013E300 0080982D */  daddu     $s3, $a0, $zero
/* D4A04 8013E304 AFBF0034 */  sw        $ra, 0x34($sp)
/* D4A08 8013E308 AFB40030 */  sw        $s4, 0x30($sp)
/* D4A0C 8013E30C AFB20028 */  sw        $s2, 0x28($sp)
/* D4A10 8013E310 AFB10024 */  sw        $s1, 0x24($sp)
/* D4A14 8013E314 AFB00020 */  sw        $s0, 0x20($sp)
/* D4A18 8013E318 00021080 */  sll       $v0, $v0, 2
/* D4A1C 8013E31C 02621821 */  addu      $v1, $s3, $v0
/* D4A20 8013E320 8C620068 */  lw        $v0, 0x68($v1)
/* D4A24 8013E324 1040016F */  beqz      $v0, .L8013E8E4
/* D4A28 8013E328 00A0A02D */   daddu    $s4, $a1, $zero
/* D4A2C 8013E32C 8C620070 */  lw        $v0, 0x70($v1)
/* D4A30 8013E330 1040016C */  beqz      $v0, .L8013E8E4
/* D4A34 8013E334 3C120001 */   lui      $s2, 1
/* D4A38 8013E338 36521630 */  ori       $s2, $s2, 0x1630
/* D4A3C 8013E33C 3C108007 */  lui       $s0, %hi(gMatrixListPos)
/* D4A40 8013E340 261041F0 */  addiu     $s0, $s0, %lo(gMatrixListPos)
/* D4A44 8013E344 3C11800A */  lui       $s1, %hi(gDisplayContext)
/* D4A48 8013E348 2631A674 */  addiu     $s1, $s1, %lo(gDisplayContext)
/* D4A4C 8013E34C 3C013DCC */  lui       $at, 0x3dcc
/* D4A50 8013E350 3421CCCD */  ori       $at, $at, 0xcccd
/* D4A54 8013E354 44810000 */  mtc1      $at, $f0
/* D4A58 8013E358 96040000 */  lhu       $a0, ($s0)
/* D4A5C 8013E35C 8E220000 */  lw        $v0, ($s1)
/* D4A60 8013E360 00042180 */  sll       $a0, $a0, 6
/* D4A64 8013E364 00922021 */  addu      $a0, $a0, $s2
/* D4A68 8013E368 44050000 */  mfc1      $a1, $f0
/* D4A6C 8013E36C 00442021 */  addu      $a0, $v0, $a0
/* D4A70 8013E370 00A0302D */  daddu     $a2, $a1, $zero
/* D4A74 8013E374 0C019DC0 */  jal       guScale
/* D4A78 8013E378 00A0382D */   daddu    $a3, $a1, $zero
/* D4A7C 8013E37C 3C08800A */  lui       $t0, %hi(gMasterGfxPos)
/* D4A80 8013E380 2508A66C */  addiu     $t0, $t0, %lo(gMasterGfxPos)
/* D4A84 8013E384 8D070000 */  lw        $a3, ($t0)
/* D4A88 8013E388 00E0282D */  daddu     $a1, $a3, $zero
/* D4A8C 8013E38C 24E70008 */  addiu     $a3, $a3, 8
/* D4A90 8013E390 AD070000 */  sw        $a3, ($t0)
/* D4A94 8013E394 96040000 */  lhu       $a0, ($s0)
/* D4A98 8013E398 3C02DA38 */  lui       $v0, 0xda38
/* D4A9C 8013E39C ACA20000 */  sw        $v0, ($a1)
/* D4AA0 8013E3A0 8E230000 */  lw        $v1, ($s1)
/* D4AA4 8013E3A4 3082FFFF */  andi      $v0, $a0, 0xffff
/* D4AA8 8013E3A8 00021180 */  sll       $v0, $v0, 6
/* D4AAC 8013E3AC 00521021 */  addu      $v0, $v0, $s2
/* D4AB0 8013E3B0 00621821 */  addu      $v1, $v1, $v0
/* D4AB4 8013E3B4 3C028000 */  lui       $v0, 0x8000
/* D4AB8 8013E3B8 00621821 */  addu      $v1, $v1, $v0
/* D4ABC 8013E3BC ACA30004 */  sw        $v1, 4($a1)
/* D4AC0 8013E3C0 8E620014 */  lw        $v0, 0x14($s3)
/* D4AC4 8013E3C4 24840001 */  addiu     $a0, $a0, 1
/* D4AC8 8013E3C8 30420020 */  andi      $v0, $v0, 0x20
/* D4ACC 8013E3CC 14400130 */  bnez      $v0, .L8013E890
/* D4AD0 8013E3D0 A6040000 */   sh       $a0, ($s0)
/* D4AD4 8013E3D4 3C03E300 */  lui       $v1, 0xe300
/* D4AD8 8013E3D8 34631001 */  ori       $v1, $v1, 0x1001
/* D4ADC 8013E3DC 3C05F500 */  lui       $a1, 0xf500
/* D4AE0 8013E3E0 34A50100 */  ori       $a1, $a1, 0x100
/* D4AE4 8013E3E4 3C060703 */  lui       $a2, 0x703
/* D4AE8 8013E3E8 34C6C000 */  ori       $a2, $a2, 0xc000
/* D4AEC 8013E3EC 24E20008 */  addiu     $v0, $a3, 8
/* D4AF0 8013E3F0 AD020000 */  sw        $v0, ($t0)
/* D4AF4 8013E3F4 34028000 */  ori       $v0, $zero, 0x8000
/* D4AF8 8013E3F8 ACE20004 */  sw        $v0, 4($a3)
/* D4AFC 8013E3FC 24E20010 */  addiu     $v0, $a3, 0x10
/* D4B00 8013E400 ACE30000 */  sw        $v1, ($a3)
/* D4B04 8013E404 AD020000 */  sw        $v0, ($t0)
/* D4B08 8013E408 3C02FD10 */  lui       $v0, 0xfd10
/* D4B0C 8013E40C ACE20008 */  sw        $v0, 8($a3)
/* D4B10 8013E410 24E20018 */  addiu     $v0, $a3, 0x18
/* D4B14 8013E414 AD020000 */  sw        $v0, ($t0)
/* D4B18 8013E418 24E20020 */  addiu     $v0, $a3, 0x20
/* D4B1C 8013E41C AD020000 */  sw        $v0, ($t0)
/* D4B20 8013E420 24E20028 */  addiu     $v0, $a3, 0x28
/* D4B24 8013E424 AD020000 */  sw        $v0, ($t0)
/* D4B28 8013E428 3C038015 */  lui       $v1, %hi(D_8014EE10)
/* D4B2C 8013E42C 8C63EE10 */  lw        $v1, %lo(D_8014EE10)($v1)
/* D4B30 8013E430 24E20030 */  addiu     $v0, $a3, 0x30
/* D4B34 8013E434 AD020000 */  sw        $v0, ($t0)
/* D4B38 8013E438 8C640004 */  lw        $a0, 4($v1)
/* D4B3C 8013E43C 3C038015 */  lui       $v1, %hi(D_80151328)
/* D4B40 8013E440 8C631328 */  lw        $v1, %lo(D_80151328)($v1)
/* D4B44 8013E444 3C02E800 */  lui       $v0, 0xe800
/* D4B48 8013E448 ACE20010 */  sw        $v0, 0x10($a3)
/* D4B4C 8013E44C 3C020700 */  lui       $v0, 0x700
/* D4B50 8013E450 ACE2001C */  sw        $v0, 0x1c($a3)
/* D4B54 8013E454 3C02E600 */  lui       $v0, 0xe600
/* D4B58 8013E458 ACE20020 */  sw        $v0, 0x20($a3)
/* D4B5C 8013E45C 3C02F000 */  lui       $v0, 0xf000
/* D4B60 8013E460 ACE20028 */  sw        $v0, 0x28($a3)
/* D4B64 8013E464 3C02E700 */  lui       $v0, 0xe700
/* D4B68 8013E468 ACE00014 */  sw        $zero, 0x14($a3)
/* D4B6C 8013E46C ACE50018 */  sw        $a1, 0x18($a3)
/* D4B70 8013E470 ACE00024 */  sw        $zero, 0x24($a3)
/* D4B74 8013E474 ACE6002C */  sw        $a2, 0x2c($a3)
/* D4B78 8013E478 ACE20030 */  sw        $v0, 0x30($a3)
/* D4B7C 8013E47C ACE00034 */  sw        $zero, 0x34($a3)
/* D4B80 8013E480 ACE4000C */  sw        $a0, 0xc($a3)
/* D4B84 8013E484 94620000 */  lhu       $v0, ($v1)
/* D4B88 8013E488 24E30038 */  addiu     $v1, $a3, 0x38
/* D4B8C 8013E48C 30420001 */  andi      $v0, $v0, 1
/* D4B90 8013E490 104000A7 */  beqz      $v0, .L8013E730
/* D4B94 8013E494 AD030000 */   sw       $v1, ($t0)
/* D4B98 8013E498 8E620014 */  lw        $v0, 0x14($s3)
/* D4B9C 8013E49C 3C030018 */  lui       $v1, 0x18
/* D4BA0 8013E4A0 00431024 */  and       $v0, $v0, $v1
/* D4BA4 8013E4A4 504000A3 */  beql      $v0, $zero, .L8013E734
/* D4BA8 8013E4A8 3C08070A */   lui      $t0, 0x70a
/* D4BAC 8013E4AC 92630002 */  lbu       $v1, 2($s3)
/* D4BB0 8013E4B0 10600007 */  beqz      $v1, .L8013E4D0
/* D4BB4 8013E4B4 24020002 */   addiu    $v0, $zero, 2
/* D4BB8 8013E4B8 10620005 */  beq       $v1, $v0, .L8013E4D0
/* D4BBC 8013E4BC 24020007 */   addiu    $v0, $zero, 7
/* D4BC0 8013E4C0 10620003 */  beq       $v1, $v0, .L8013E4D0
/* D4BC4 8013E4C4 2402000B */   addiu    $v0, $zero, 0xb
/* D4BC8 8013E4C8 1462009A */  bne       $v1, $v0, .L8013E734
/* D4BCC 8013E4CC 3C08070A */   lui      $t0, 0x70a
.L8013E4D0:
/* D4BD0 8013E4D0 240E00FF */  addiu     $t6, $zero, 0xff
/* D4BD4 8013E4D4 3C08070A */  lui       $t0, 0x70a
/* D4BD8 8013E4D8 35080280 */  ori       $t0, $t0, 0x280
/* D4BDC 8013E4DC 3C0A010A */  lui       $t2, 0x10a
/* D4BE0 8013E4E0 354A0280 */  ori       $t2, $t2, 0x280
/* D4BE4 8013E4E4 3C09F240 */  lui       $t1, 0xf240
/* D4BE8 8013E4E8 35290400 */  ori       $t1, $t1, 0x400
/* D4BEC 8013E4EC 3C0B001A */  lui       $t3, 0x1a
/* D4BF0 8013E4F0 356B0280 */  ori       $t3, $t3, 0x280
/* D4BF4 8013E4F4 3C0CF510 */  lui       $t4, 0xf510
/* D4BF8 8013E4F8 358C0900 */  ori       $t4, $t4, 0x900
/* D4BFC 8013E4FC 3C0D020F */  lui       $t5, 0x20f
/* D4C00 8013E500 3C07800A */  lui       $a3, %hi(gMasterGfxPos)
/* D4C04 8013E504 24E7A66C */  addiu     $a3, $a3, %lo(gMasterGfxPos)
/* D4C08 8013E508 8CE50000 */  lw        $a1, ($a3)
/* D4C0C 8013E50C 35ADC000 */  ori       $t5, $t5, 0xc000
/* D4C10 8013E510 00A0202D */  daddu     $a0, $a1, $zero
/* D4C14 8013E514 24A50008 */  addiu     $a1, $a1, 8
/* D4C18 8013E518 ACE50000 */  sw        $a1, ($a3)
/* D4C1C 8013E51C 3C068015 */  lui       $a2, %hi(D_8014EE10)
/* D4C20 8013E520 8CC6EE10 */  lw        $a2, %lo(D_8014EE10)($a2)
/* D4C24 8013E524 24A20008 */  addiu     $v0, $a1, 8
/* D4C28 8013E528 ACE20000 */  sw        $v0, ($a3)
/* D4C2C 8013E52C 94C20008 */  lhu       $v0, 8($a2)
/* D4C30 8013E530 24A30010 */  addiu     $v1, $a1, 0x10
/* D4C34 8013E534 ACE30000 */  sw        $v1, ($a3)
/* D4C38 8013E538 3C03FD48 */  lui       $v1, 0xfd48
/* D4C3C 8013E53C 00021042 */  srl       $v0, $v0, 1
/* D4C40 8013E540 2442FFFF */  addiu     $v0, $v0, -1
/* D4C44 8013E544 30420FFF */  andi      $v0, $v0, 0xfff
/* D4C48 8013E548 00431025 */  or        $v0, $v0, $v1
/* D4C4C 8013E54C AC820000 */  sw        $v0, ($a0)
/* D4C50 8013E550 8CC30000 */  lw        $v1, ($a2)
/* D4C54 8013E554 24A20018 */  addiu     $v0, $a1, 0x18
/* D4C58 8013E558 ACE20000 */  sw        $v0, ($a3)
/* D4C5C 8013E55C AC830004 */  sw        $v1, 4($a0)
/* D4C60 8013E560 94C20008 */  lhu       $v0, 8($a2)
/* D4C64 8013E564 24A30020 */  addiu     $v1, $a1, 0x20
/* D4C68 8013E568 ACE30000 */  sw        $v1, ($a3)
/* D4C6C 8013E56C 3C03E600 */  lui       $v1, 0xe600
/* D4C70 8013E570 ACA30008 */  sw        $v1, 8($a1)
/* D4C74 8013E574 3C03F400 */  lui       $v1, 0xf400
/* D4C78 8013E578 ACA30010 */  sw        $v1, 0x10($a1)
/* D4C7C 8013E57C 3C03F548 */  lui       $v1, 0xf548
/* D4C80 8013E580 3C04E700 */  lui       $a0, 0xe700
/* D4C84 8013E584 ACA80004 */  sw        $t0, 4($a1)
/* D4C88 8013E588 ACA0000C */  sw        $zero, 0xc($a1)
/* D4C8C 8013E58C 00021042 */  srl       $v0, $v0, 1
/* D4C90 8013E590 24420007 */  addiu     $v0, $v0, 7
/* D4C94 8013E594 000210C3 */  sra       $v0, $v0, 3
/* D4C98 8013E598 304201FF */  andi      $v0, $v0, 0x1ff
/* D4C9C 8013E59C 00021240 */  sll       $v0, $v0, 9
/* D4CA0 8013E5A0 00431025 */  or        $v0, $v0, $v1
/* D4CA4 8013E5A4 ACA20000 */  sw        $v0, ($a1)
/* D4CA8 8013E5A8 94C20008 */  lhu       $v0, 8($a2)
/* D4CAC 8013E5AC 94C3000A */  lhu       $v1, 0xa($a2)
/* D4CB0 8013E5B0 3C08F540 */  lui       $t0, 0xf540
/* D4CB4 8013E5B4 ACA40018 */  sw        $a0, 0x18($a1)
/* D4CB8 8013E5B8 3C040700 */  lui       $a0, 0x700
/* D4CBC 8013E5BC ACA0001C */  sw        $zero, 0x1c($a1)
/* D4CC0 8013E5C0 2442FFFF */  addiu     $v0, $v0, -1
/* D4CC4 8013E5C4 00021040 */  sll       $v0, $v0, 1
/* D4CC8 8013E5C8 30420FFF */  andi      $v0, $v0, 0xfff
/* D4CCC 8013E5CC 00021300 */  sll       $v0, $v0, 0xc
/* D4CD0 8013E5D0 2463FFFF */  addiu     $v1, $v1, -1
/* D4CD4 8013E5D4 00031880 */  sll       $v1, $v1, 2
/* D4CD8 8013E5D8 30630FFF */  andi      $v1, $v1, 0xfff
/* D4CDC 8013E5DC 00641825 */  or        $v1, $v1, $a0
/* D4CE0 8013E5E0 00431025 */  or        $v0, $v0, $v1
/* D4CE4 8013E5E4 24A30028 */  addiu     $v1, $a1, 0x28
/* D4CE8 8013E5E8 ACA20014 */  sw        $v0, 0x14($a1)
/* D4CEC 8013E5EC 94C20008 */  lhu       $v0, 8($a2)
/* D4CF0 8013E5F0 3C040100 */  lui       $a0, 0x100
/* D4CF4 8013E5F4 ACE30000 */  sw        $v1, ($a3)
/* D4CF8 8013E5F8 ACAA0024 */  sw        $t2, 0x24($a1)
/* D4CFC 8013E5FC ACA90028 */  sw        $t1, 0x28($a1)
/* D4D00 8013E600 00021042 */  srl       $v0, $v0, 1
/* D4D04 8013E604 24420007 */  addiu     $v0, $v0, 7
/* D4D08 8013E608 000210C3 */  sra       $v0, $v0, 3
/* D4D0C 8013E60C 304201FF */  andi      $v0, $v0, 0x1ff
/* D4D10 8013E610 00021240 */  sll       $v0, $v0, 9
/* D4D14 8013E614 00481025 */  or        $v0, $v0, $t0
/* D4D18 8013E618 ACA20020 */  sw        $v0, 0x20($a1)
/* D4D1C 8013E61C 94C30008 */  lhu       $v1, 8($a2)
/* D4D20 8013E620 24A20030 */  addiu     $v0, $a1, 0x30
/* D4D24 8013E624 ACE20000 */  sw        $v0, ($a3)
/* D4D28 8013E628 94C2000A */  lhu       $v0, 0xa($a2)
/* D4D2C 8013E62C 006E1821 */  addu      $v1, $v1, $t6
/* D4D30 8013E630 00031880 */  sll       $v1, $v1, 2
/* D4D34 8013E634 30630FFF */  andi      $v1, $v1, 0xfff
/* D4D38 8013E638 00031B00 */  sll       $v1, $v1, 0xc
/* D4D3C 8013E63C 004E1021 */  addu      $v0, $v0, $t6
/* D4D40 8013E640 00021080 */  sll       $v0, $v0, 2
/* D4D44 8013E644 30420FFF */  andi      $v0, $v0, 0xfff
/* D4D48 8013E648 00441025 */  or        $v0, $v0, $a0
/* D4D4C 8013E64C 00621825 */  or        $v1, $v1, $v0
/* D4D50 8013E650 ACA3002C */  sw        $v1, 0x2c($a1)
/* D4D54 8013E654 94C20008 */  lhu       $v0, 8($a2)
/* D4D58 8013E658 24A30038 */  addiu     $v1, $a1, 0x38
/* D4D5C 8013E65C ACE30000 */  sw        $v1, ($a3)
/* D4D60 8013E660 00021042 */  srl       $v0, $v0, 1
/* D4D64 8013E664 24420007 */  addiu     $v0, $v0, 7
/* D4D68 8013E668 000210C3 */  sra       $v0, $v0, 3
/* D4D6C 8013E66C 304201FF */  andi      $v0, $v0, 0x1ff
/* D4D70 8013E670 00021240 */  sll       $v0, $v0, 9
/* D4D74 8013E674 00481025 */  or        $v0, $v0, $t0
/* D4D78 8013E678 ACA20030 */  sw        $v0, 0x30($a1)
/* D4D7C 8013E67C 24A20040 */  addiu     $v0, $a1, 0x40
/* D4D80 8013E680 ACAB0034 */  sw        $t3, 0x34($a1)
/* D4D84 8013E684 ACE20000 */  sw        $v0, ($a3)
/* D4D88 8013E688 3C020200 */  lui       $v0, 0x200
/* D4D8C 8013E68C ACA2003C */  sw        $v0, 0x3c($a1)
/* D4D90 8013E690 24A20048 */  addiu     $v0, $a1, 0x48
/* D4D94 8013E694 ACAC0038 */  sw        $t4, 0x38($a1)
/* D4D98 8013E698 ACE20000 */  sw        $v0, ($a3)
/* D4D9C 8013E69C 3C02F200 */  lui       $v0, 0xf200
/* D4DA0 8013E6A0 ACA20040 */  sw        $v0, 0x40($a1)
/* D4DA4 8013E6A4 ACAD0044 */  sw        $t5, 0x44($a1)
/* D4DA8 8013E6A8 92630002 */  lbu       $v1, 2($s3)
/* D4DAC 8013E6AC 24020002 */  addiu     $v0, $zero, 2
/* D4DB0 8013E6B0 1062000D */  beq       $v1, $v0, .L8013E6E8
/* D4DB4 8013E6B4 28620003 */   slti     $v0, $v1, 3
/* D4DB8 8013E6B8 10400005 */  beqz      $v0, .L8013E6D0
/* D4DBC 8013E6BC 24020007 */   addiu    $v0, $zero, 7
/* D4DC0 8013E6C0 1060000D */  beqz      $v1, .L8013E6F8
/* D4DC4 8013E6C4 00000000 */   nop
/* D4DC8 8013E6C8 0804F9BE */  j         .L8013E6F8
/* D4DCC 8013E6CC 00000000 */   nop
.L8013E6D0:
/* D4DD0 8013E6D0 10620008 */  beq       $v1, $v0, .L8013E6F4
/* D4DD4 8013E6D4 2402000B */   addiu    $v0, $zero, 0xb
/* D4DD8 8013E6D8 14620007 */  bne       $v1, $v0, .L8013E6F8
/* D4DDC 8013E6DC 00000000 */   nop
/* D4DE0 8013E6E0 0804F9BE */  j         .L8013E6F8
/* D4DE4 8013E6E4 240E00FF */   addiu    $t6, $zero, 0xff
.L8013E6E8:
/* D4DE8 8013E6E8 8E6E0038 */  lw        $t6, 0x38($s3)
/* D4DEC 8013E6EC 0804F9BE */  j         .L8013E6F8
/* D4DF0 8013E6F0 00000000 */   nop
.L8013E6F4:
/* D4DF4 8013E6F4 240EFFFF */  addiu     $t6, $zero, -1
.L8013E6F8:
/* D4DF8 8013E6F8 3C028015 */  lui       $v0, %hi(D_8014EE10)
/* D4DFC 8013E6FC 8C42EE10 */  lw        $v0, %lo(D_8014EE10)($v0)
/* D4E00 8013E700 0280202D */  daddu     $a0, $s4, $zero
/* D4E04 8013E704 94470008 */  lhu       $a3, 8($v0)
/* D4E08 8013E708 9442000A */  lhu       $v0, 0xa($v0)
/* D4E0C 8013E70C 0000282D */  daddu     $a1, $zero, $zero
/* D4E10 8013E710 AFAE0014 */  sw        $t6, 0x14($sp)
/* D4E14 8013E714 AFA20010 */  sw        $v0, 0x10($sp)
/* D4E18 8013E718 8E620078 */  lw        $v0, 0x78($s3)
/* D4E1C 8013E71C 00A0302D */  daddu     $a2, $a1, $zero
/* D4E20 8013E720 0C052071 */  jal       render_shaded_sprite
/* D4E24 8013E724 AFA20018 */   sw       $v0, 0x18($sp)
/* D4E28 8013E728 0804FA25 */  j         .L8013E894
/* D4E2C 8013E72C 3C07D838 */   lui      $a3, 0xd838
.L8013E730:
/* D4E30 8013E730 3C08070A */  lui       $t0, 0x70a
.L8013E734:
/* D4E34 8013E734 35080280 */  ori       $t0, $t0, 0x280
/* D4E38 8013E738 3C0A000A */  lui       $t2, 0xa
/* D4E3C 8013E73C 354A0280 */  ori       $t2, $t2, 0x280
/* D4E40 8013E740 3C09F240 */  lui       $t1, 0xf240
/* D4E44 8013E744 3C07800A */  lui       $a3, %hi(gMasterGfxPos)
/* D4E48 8013E748 24E7A66C */  addiu     $a3, $a3, %lo(gMasterGfxPos)
/* D4E4C 8013E74C 8CE50000 */  lw        $a1, ($a3)
/* D4E50 8013E750 35290400 */  ori       $t1, $t1, 0x400
/* D4E54 8013E754 00A0202D */  daddu     $a0, $a1, $zero
/* D4E58 8013E758 24A50008 */  addiu     $a1, $a1, 8
/* D4E5C 8013E75C ACE50000 */  sw        $a1, ($a3)
/* D4E60 8013E760 3C068015 */  lui       $a2, %hi(D_8014EE10)
/* D4E64 8013E764 8CC6EE10 */  lw        $a2, %lo(D_8014EE10)($a2)
/* D4E68 8013E768 24A20008 */  addiu     $v0, $a1, 8
/* D4E6C 8013E76C ACE20000 */  sw        $v0, ($a3)
/* D4E70 8013E770 94C20008 */  lhu       $v0, 8($a2)
/* D4E74 8013E774 24A30010 */  addiu     $v1, $a1, 0x10
/* D4E78 8013E778 ACE30000 */  sw        $v1, ($a3)
/* D4E7C 8013E77C 3C03FD48 */  lui       $v1, 0xfd48
/* D4E80 8013E780 00021042 */  srl       $v0, $v0, 1
/* D4E84 8013E784 2442FFFF */  addiu     $v0, $v0, -1
/* D4E88 8013E788 30420FFF */  andi      $v0, $v0, 0xfff
/* D4E8C 8013E78C 00431025 */  or        $v0, $v0, $v1
/* D4E90 8013E790 AC820000 */  sw        $v0, ($a0)
/* D4E94 8013E794 8CC30000 */  lw        $v1, ($a2)
/* D4E98 8013E798 24A20018 */  addiu     $v0, $a1, 0x18
/* D4E9C 8013E79C ACE20000 */  sw        $v0, ($a3)
/* D4EA0 8013E7A0 AC830004 */  sw        $v1, 4($a0)
/* D4EA4 8013E7A4 94C20008 */  lhu       $v0, 8($a2)
/* D4EA8 8013E7A8 24A30020 */  addiu     $v1, $a1, 0x20
/* D4EAC 8013E7AC ACE30000 */  sw        $v1, ($a3)
/* D4EB0 8013E7B0 3C03E600 */  lui       $v1, 0xe600
/* D4EB4 8013E7B4 ACA30008 */  sw        $v1, 8($a1)
/* D4EB8 8013E7B8 3C03F400 */  lui       $v1, 0xf400
/* D4EBC 8013E7BC ACA30010 */  sw        $v1, 0x10($a1)
/* D4EC0 8013E7C0 3C03F548 */  lui       $v1, 0xf548
/* D4EC4 8013E7C4 ACA80004 */  sw        $t0, 4($a1)
/* D4EC8 8013E7C8 ACA0000C */  sw        $zero, 0xc($a1)
/* D4ECC 8013E7CC 00021042 */  srl       $v0, $v0, 1
/* D4ED0 8013E7D0 24420007 */  addiu     $v0, $v0, 7
/* D4ED4 8013E7D4 000210C3 */  sra       $v0, $v0, 3
/* D4ED8 8013E7D8 304201FF */  andi      $v0, $v0, 0x1ff
/* D4EDC 8013E7DC 00021240 */  sll       $v0, $v0, 9
/* D4EE0 8013E7E0 00431025 */  or        $v0, $v0, $v1
/* D4EE4 8013E7E4 ACA20000 */  sw        $v0, ($a1)
/* D4EE8 8013E7E8 94C20008 */  lhu       $v0, 8($a2)
/* D4EEC 8013E7EC 94C3000A */  lhu       $v1, 0xa($a2)
/* D4EF0 8013E7F0 3C04E700 */  lui       $a0, 0xe700
/* D4EF4 8013E7F4 ACA40018 */  sw        $a0, 0x18($a1)
/* D4EF8 8013E7F8 3C040700 */  lui       $a0, 0x700
/* D4EFC 8013E7FC ACA0001C */  sw        $zero, 0x1c($a1)
/* D4F00 8013E800 2442FFFF */  addiu     $v0, $v0, -1
/* D4F04 8013E804 00021040 */  sll       $v0, $v0, 1
/* D4F08 8013E808 30420FFF */  andi      $v0, $v0, 0xfff
/* D4F0C 8013E80C 00021300 */  sll       $v0, $v0, 0xc
/* D4F10 8013E810 2463FFFF */  addiu     $v1, $v1, -1
/* D4F14 8013E814 00031880 */  sll       $v1, $v1, 2
/* D4F18 8013E818 30630FFF */  andi      $v1, $v1, 0xfff
/* D4F1C 8013E81C 00641825 */  or        $v1, $v1, $a0
/* D4F20 8013E820 00431025 */  or        $v0, $v0, $v1
/* D4F24 8013E824 ACA20014 */  sw        $v0, 0x14($a1)
/* D4F28 8013E828 94C20008 */  lhu       $v0, 8($a2)
/* D4F2C 8013E82C 24A30028 */  addiu     $v1, $a1, 0x28
/* D4F30 8013E830 ACE30000 */  sw        $v1, ($a3)
/* D4F34 8013E834 3C03F540 */  lui       $v1, 0xf540
/* D4F38 8013E838 ACAA0024 */  sw        $t2, 0x24($a1)
/* D4F3C 8013E83C ACA90028 */  sw        $t1, 0x28($a1)
/* D4F40 8013E840 00021042 */  srl       $v0, $v0, 1
/* D4F44 8013E844 24420007 */  addiu     $v0, $v0, 7
/* D4F48 8013E848 000210C3 */  sra       $v0, $v0, 3
/* D4F4C 8013E84C 304201FF */  andi      $v0, $v0, 0x1ff
/* D4F50 8013E850 00021240 */  sll       $v0, $v0, 9
/* D4F54 8013E854 00431025 */  or        $v0, $v0, $v1
/* D4F58 8013E858 ACA20020 */  sw        $v0, 0x20($a1)
/* D4F5C 8013E85C 94C30008 */  lhu       $v1, 8($a2)
/* D4F60 8013E860 24A20030 */  addiu     $v0, $a1, 0x30
/* D4F64 8013E864 ACE20000 */  sw        $v0, ($a3)
/* D4F68 8013E868 94C2000A */  lhu       $v0, 0xa($a2)
/* D4F6C 8013E86C 246300FF */  addiu     $v1, $v1, 0xff
/* D4F70 8013E870 00031880 */  sll       $v1, $v1, 2
/* D4F74 8013E874 30630FFF */  andi      $v1, $v1, 0xfff
/* D4F78 8013E878 00031B00 */  sll       $v1, $v1, 0xc
/* D4F7C 8013E87C 244200FF */  addiu     $v0, $v0, 0xff
/* D4F80 8013E880 00021080 */  sll       $v0, $v0, 2
/* D4F84 8013E884 30420FFF */  andi      $v0, $v0, 0xfff
/* D4F88 8013E888 00621825 */  or        $v1, $v1, $v0
/* D4F8C 8013E88C ACA3002C */  sw        $v1, 0x2c($a1)
.L8013E890:
/* D4F90 8013E890 3C07D838 */  lui       $a3, 0xd838
.L8013E894:
/* D4F94 8013E894 3C05800A */  lui       $a1, %hi(gMasterGfxPos)
/* D4F98 8013E898 24A5A66C */  addiu     $a1, $a1, %lo(gMasterGfxPos)
/* D4F9C 8013E89C 8CA40000 */  lw        $a0, ($a1)
/* D4FA0 8013E8A0 34E70002 */  ori       $a3, $a3, 2
/* D4FA4 8013E8A4 0080302D */  daddu     $a2, $a0, $zero
/* D4FA8 8013E8A8 24840008 */  addiu     $a0, $a0, 8
/* D4FAC 8013E8AC ACA40000 */  sw        $a0, ($a1)
/* D4FB0 8013E8B0 3C028007 */  lui       $v0, %hi(gCurrentDisplayContextIndex)
/* D4FB4 8013E8B4 8C4241F4 */  lw        $v0, %lo(gCurrentDisplayContextIndex)($v0)
/* D4FB8 8013E8B8 3C03DE00 */  lui       $v1, 0xde00
/* D4FBC 8013E8BC ACC30000 */  sw        $v1, ($a2)
/* D4FC0 8013E8C0 00021080 */  sll       $v0, $v0, 2
/* D4FC4 8013E8C4 02621021 */  addu      $v0, $s3, $v0
/* D4FC8 8013E8C8 8C430070 */  lw        $v1, 0x70($v0)
/* D4FCC 8013E8CC 24820008 */  addiu     $v0, $a0, 8
/* D4FD0 8013E8D0 ACA20000 */  sw        $v0, ($a1)
/* D4FD4 8013E8D4 24020040 */  addiu     $v0, $zero, 0x40
/* D4FD8 8013E8D8 ACC30004 */  sw        $v1, 4($a2)
/* D4FDC 8013E8DC AC870000 */  sw        $a3, ($a0)
/* D4FE0 8013E8E0 AC820004 */  sw        $v0, 4($a0)
.L8013E8E4:
/* D4FE4 8013E8E4 8FBF0034 */  lw        $ra, 0x34($sp)
/* D4FE8 8013E8E8 8FB40030 */  lw        $s4, 0x30($sp)
/* D4FEC 8013E8EC 8FB3002C */  lw        $s3, 0x2c($sp)
/* D4FF0 8013E8F0 8FB20028 */  lw        $s2, 0x28($sp)
/* D4FF4 8013E8F4 8FB10024 */  lw        $s1, 0x24($sp)
/* D4FF8 8013E8F8 8FB00020 */  lw        $s0, 0x20($sp)
/* D4FFC 8013E8FC 03E00008 */  jr        $ra
/* D5000 8013E900 27BD0038 */   addiu    $sp, $sp, 0x38
