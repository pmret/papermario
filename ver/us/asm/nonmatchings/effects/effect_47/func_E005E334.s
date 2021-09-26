.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E005E334
/* 3628F4 E005E334 27BDFEF0 */  addiu     $sp, $sp, -0x110
/* 3628F8 E005E338 AFBF0104 */  sw        $ra, 0x104($sp)
/* 3628FC E005E33C AFBE0100 */  sw        $fp, 0x100($sp)
/* 362900 E005E340 AFB700FC */  sw        $s7, 0xfc($sp)
/* 362904 E005E344 AFB600F8 */  sw        $s6, 0xf8($sp)
/* 362908 E005E348 AFB500F4 */  sw        $s5, 0xf4($sp)
/* 36290C E005E34C AFB400F0 */  sw        $s4, 0xf0($sp)
/* 362910 E005E350 AFB300EC */  sw        $s3, 0xec($sp)
/* 362914 E005E354 AFB200E8 */  sw        $s2, 0xe8($sp)
/* 362918 E005E358 AFB100E4 */  sw        $s1, 0xe4($sp)
/* 36291C E005E35C AFB000E0 */  sw        $s0, 0xe0($sp)
/* 362920 E005E360 F7B40108 */  sdc1      $f20, 0x108($sp)
/* 362924 E005E364 AFA40110 */  sw        $a0, 0x110($sp)
/* 362928 E005E368 8C92000C */  lw        $s2, 0xc($a0)
/* 36292C E005E36C 8E420028 */  lw        $v0, 0x28($s2)
/* 362930 E005E370 104000B2 */  beqz      $v0, .LE005E63C
/* 362934 E005E374 3C07DB06 */   lui      $a3, 0xdb06
/* 362938 E005E378 34E70024 */  ori       $a3, $a3, 0x24
/* 36293C E005E37C 27A40018 */  addiu     $a0, $sp, 0x18
/* 362940 E005E380 3C110001 */  lui       $s1, 1
/* 362944 E005E384 3C16800A */  lui       $s6, %hi(gMasterGfxPos)
/* 362948 E005E388 26D6A66C */  addiu     $s6, $s6, %lo(gMasterGfxPos)
/* 36294C E005E38C 8EC30000 */  lw        $v1, ($s6)
/* 362950 E005E390 36311630 */  ori       $s1, $s1, 0x1630
/* 362954 E005E394 0060282D */  daddu     $a1, $v1, $zero
/* 362958 E005E398 24630008 */  addiu     $v1, $v1, 8
/* 36295C E005E39C AEC30000 */  sw        $v1, ($s6)
/* 362960 E005E3A0 3C08E006 */  lui       $t0, %hi(D_E005E670)
/* 362964 E005E3A4 8D08E670 */  lw        $t0, %lo(D_E005E670)($t0)
/* 362968 E005E3A8 3C06E006 */  lui       $a2, %hi(D_E005E674)
/* 36296C E005E3AC 8CC6E674 */  lw        $a2, %lo(D_E005E674)($a2)
/* 362970 E005E3B0 3C02E700 */  lui       $v0, 0xe700
/* 362974 E005E3B4 AFA800D8 */  sw        $t0, 0xd8($sp)
/* 362978 E005E3B8 ACA20000 */  sw        $v0, ($a1)
/* 36297C E005E3BC 24620008 */  addiu     $v0, $v1, 8
/* 362980 E005E3C0 ACA00004 */  sw        $zero, 4($a1)
/* 362984 E005E3C4 AEC20000 */  sw        $v0, ($s6)
/* 362988 E005E3C8 AC670000 */  sw        $a3, ($v1)
/* 36298C E005E3CC 8FA80110 */  lw        $t0, 0x110($sp)
/* 362990 E005E3D0 8D050010 */  lw        $a1, 0x10($t0)
/* 362994 E005E3D4 24620010 */  addiu     $v0, $v1, 0x10
/* 362998 E005E3D8 AEC20000 */  sw        $v0, ($s6)
/* 36299C E005E3DC 8CA5001C */  lw        $a1, 0x1c($a1)
/* 3629A0 E005E3E0 3C02DE00 */  lui       $v0, 0xde00
/* 3629A4 E005E3E4 AC620008 */  sw        $v0, 8($v1)
/* 3629A8 E005E3E8 3C028000 */  lui       $v0, 0x8000
/* 3629AC E005E3EC AC66000C */  sw        $a2, 0xc($v1)
/* 3629B0 E005E3F0 00A22821 */  addu      $a1, $a1, $v0
/* 3629B4 E005E3F4 AC650004 */  sw        $a1, 4($v1)
/* 3629B8 E005E3F8 8E450004 */  lw        $a1, 4($s2)
/* 3629BC E005E3FC 8E460008 */  lw        $a2, 8($s2)
/* 3629C0 E005E400 8E47000C */  lw        $a3, 0xc($s2)
/* 3629C4 E005E404 4480A000 */  mtc1      $zero, $f20
/* 3629C8 E005E408 0C080108 */  jal       shim_guTranslateF
/* 3629CC E005E40C 24140001 */   addiu    $s4, $zero, 1
/* 3629D0 E005E410 27B30058 */  addiu     $s3, $sp, 0x58
/* 3629D4 E005E414 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 3629D8 E005E418 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 3629DC E005E41C 4406A000 */  mfc1      $a2, $f20
/* 3629E0 E005E420 00031080 */  sll       $v0, $v1, 2
/* 3629E4 E005E424 00431021 */  addu      $v0, $v0, $v1
/* 3629E8 E005E428 00021080 */  sll       $v0, $v0, 2
/* 3629EC E005E42C 00431023 */  subu      $v0, $v0, $v1
/* 3629F0 E005E430 000218C0 */  sll       $v1, $v0, 3
/* 3629F4 E005E434 00431021 */  addu      $v0, $v0, $v1
/* 3629F8 E005E438 000210C0 */  sll       $v0, $v0, 3
/* 3629FC E005E43C 3C01800B */  lui       $at, %hi(gCameras+0x6C)
/* 362A00 E005E440 00220821 */  addu      $at, $at, $v0
/* 362A04 E005E444 C4201DEC */  lwc1      $f0, %lo(gCameras+0x6C)($at)
/* 362A08 E005E448 3C073F80 */  lui       $a3, 0x3f80
/* 362A0C E005E44C 46000007 */  neg.s     $f0, $f0
/* 362A10 E005E450 44050000 */  mfc1      $a1, $f0
/* 362A14 E005E454 0260202D */  daddu     $a0, $s3, $zero
/* 362A18 E005E458 0C080104 */  jal       shim_guRotateF
/* 362A1C E005E45C E7B40010 */   swc1     $f20, 0x10($sp)
/* 362A20 E005E460 0260202D */  daddu     $a0, $s3, $zero
/* 362A24 E005E464 27A50018 */  addiu     $a1, $sp, 0x18
/* 362A28 E005E468 27B00098 */  addiu     $s0, $sp, 0x98
/* 362A2C E005E46C 0C080114 */  jal       shim_guMtxCatF
/* 362A30 E005E470 0200302D */   daddu    $a2, $s0, $zero
/* 362A34 E005E474 0200202D */  daddu     $a0, $s0, $zero
/* 362A38 E005E478 3C108007 */  lui       $s0, %hi(gMatrixListPos)
/* 362A3C E005E47C 261041F0 */  addiu     $s0, $s0, %lo(gMatrixListPos)
/* 362A40 E005E480 3C17800A */  lui       $s7, %hi(gDisplayContext)
/* 362A44 E005E484 26F7A674 */  addiu     $s7, $s7, %lo(gDisplayContext)
/* 362A48 E005E488 96050000 */  lhu       $a1, ($s0)
/* 362A4C E005E48C 8EE20000 */  lw        $v0, ($s7)
/* 362A50 E005E490 00052980 */  sll       $a1, $a1, 6
/* 362A54 E005E494 00B12821 */  addu      $a1, $a1, $s1
/* 362A58 E005E498 0C080118 */  jal       shim_guMtxF2L
/* 362A5C E005E49C 00452821 */   addu     $a1, $v0, $a1
/* 362A60 E005E4A0 3C06DCDC */  lui       $a2, 0xdcdc
/* 362A64 E005E4A4 8EC40000 */  lw        $a0, ($s6)
/* 362A68 E005E4A8 34C628FF */  ori       $a2, $a2, 0x28ff
/* 362A6C E005E4AC 0080282D */  daddu     $a1, $a0, $zero
/* 362A70 E005E4B0 24840008 */  addiu     $a0, $a0, 8
/* 362A74 E005E4B4 AEC40000 */  sw        $a0, ($s6)
/* 362A78 E005E4B8 96020000 */  lhu       $v0, ($s0)
/* 362A7C E005E4BC 3C03DA38 */  lui       $v1, 0xda38
/* 362A80 E005E4C0 ACA30000 */  sw        $v1, ($a1)
/* 362A84 E005E4C4 00541821 */  addu      $v1, $v0, $s4
/* 362A88 E005E4C8 3042FFFF */  andi      $v0, $v0, 0xffff
/* 362A8C E005E4CC 00021180 */  sll       $v0, $v0, 6
/* 362A90 E005E4D0 A6030000 */  sh        $v1, ($s0)
/* 362A94 E005E4D4 8EE30000 */  lw        $v1, ($s7)
/* 362A98 E005E4D8 00511021 */  addu      $v0, $v0, $s1
/* 362A9C E005E4DC 00621821 */  addu      $v1, $v1, $v0
/* 362AA0 E005E4E0 3C02FA00 */  lui       $v0, 0xfa00
/* 362AA4 E005E4E4 ACA30004 */  sw        $v1, 4($a1)
/* 362AA8 E005E4E8 AC820000 */  sw        $v0, ($a0)
/* 362AAC E005E4EC AC860004 */  sw        $a2, 4($a0)
/* 362AB0 E005E4F0 8FA80110 */  lw        $t0, 0x110($sp)
/* 362AB4 E005E4F4 2652002C */  addiu     $s2, $s2, 0x2c
/* 362AB8 E005E4F8 8D020008 */  lw        $v0, 8($t0)
/* 362ABC E005E4FC 24840008 */  addiu     $a0, $a0, 8
/* 362AC0 E005E500 0282102A */  slt       $v0, $s4, $v0
/* 362AC4 E005E504 10400042 */  beqz      $v0, .LE005E610
/* 362AC8 E005E508 AEC40000 */   sw       $a0, ($s6)
/* 362ACC E005E50C 0260A82D */  daddu     $s5, $s3, $zero
/* 362AD0 E005E510 02E0F02D */  daddu     $fp, $s7, $zero
/* 362AD4 E005E514 0200B82D */  daddu     $s7, $s0, $zero
/* 362AD8 E005E518 3C130001 */  lui       $s3, 1
/* 362ADC E005E51C 36731630 */  ori       $s3, $s3, 0x1630
/* 362AE0 E005E520 02C0882D */  daddu     $s1, $s6, $zero
/* 362AE4 E005E524 26500018 */  addiu     $s0, $s2, 0x18
.LE005E528:
/* 362AE8 E005E528 8E05FFEC */  lw        $a1, -0x14($s0)
/* 362AEC E005E52C 8E06FFF0 */  lw        $a2, -0x10($s0)
/* 362AF0 E005E530 8E07FFF4 */  lw        $a3, -0xc($s0)
/* 362AF4 E005E534 0C080108 */  jal       shim_guTranslateF
/* 362AF8 E005E538 27A40018 */   addiu    $a0, $sp, 0x18
/* 362AFC E005E53C 4406A000 */  mfc1      $a2, $f20
/* 362B00 E005E540 4407A000 */  mfc1      $a3, $f20
/* 362B04 E005E544 3C013F80 */  lui       $at, 0x3f80
/* 362B08 E005E548 44810000 */  mtc1      $at, $f0
/* 362B0C E005E54C 26940001 */  addiu     $s4, $s4, 1
/* 362B10 E005E550 E7A00010 */  swc1      $f0, 0x10($sp)
/* 362B14 E005E554 8E050000 */  lw        $a1, ($s0)
/* 362B18 E005E558 0C080104 */  jal       shim_guRotateF
/* 362B1C E005E55C 02A0202D */   daddu    $a0, $s5, $zero
/* 362B20 E005E560 02A0202D */  daddu     $a0, $s5, $zero
/* 362B24 E005E564 27A50018 */  addiu     $a1, $sp, 0x18
/* 362B28 E005E568 0C080114 */  jal       shim_guMtxCatF
/* 362B2C E005E56C 00A0302D */   daddu    $a2, $a1, $zero
/* 362B30 E005E570 27A40018 */  addiu     $a0, $sp, 0x18
/* 362B34 E005E574 96E50000 */  lhu       $a1, ($s7)
/* 362B38 E005E578 8FC20000 */  lw        $v0, ($fp)
/* 362B3C E005E57C 00052980 */  sll       $a1, $a1, 6
/* 362B40 E005E580 00B32821 */  addu      $a1, $a1, $s3
/* 362B44 E005E584 0C080118 */  jal       shim_guMtxF2L
/* 362B48 E005E588 00452821 */   addu     $a1, $v0, $a1
/* 362B4C E005E58C 3C06D838 */  lui       $a2, 0xd838
/* 362B50 E005E590 8E240000 */  lw        $a0, ($s1)
/* 362B54 E005E594 34C60002 */  ori       $a2, $a2, 2
/* 362B58 E005E598 0080282D */  daddu     $a1, $a0, $zero
/* 362B5C E005E59C 24840008 */  addiu     $a0, $a0, 8
/* 362B60 E005E5A0 AE240000 */  sw        $a0, ($s1)
/* 362B64 E005E5A4 96E20000 */  lhu       $v0, ($s7)
/* 362B68 E005E5A8 3C03DA38 */  lui       $v1, 0xda38
/* 362B6C E005E5AC ACA30000 */  sw        $v1, ($a1)
/* 362B70 E005E5B0 24430001 */  addiu     $v1, $v0, 1
/* 362B74 E005E5B4 3042FFFF */  andi      $v0, $v0, 0xffff
/* 362B78 E005E5B8 00021180 */  sll       $v0, $v0, 6
/* 362B7C E005E5BC A6E30000 */  sh        $v1, ($s7)
/* 362B80 E005E5C0 8FC30000 */  lw        $v1, ($fp)
/* 362B84 E005E5C4 00531021 */  addu      $v0, $v0, $s3
/* 362B88 E005E5C8 00621821 */  addu      $v1, $v1, $v0
/* 362B8C E005E5CC 24820008 */  addiu     $v0, $a0, 8
/* 362B90 E005E5D0 ACA30004 */  sw        $v1, 4($a1)
/* 362B94 E005E5D4 AE220000 */  sw        $v0, ($s1)
/* 362B98 E005E5D8 3C02DE00 */  lui       $v0, 0xde00
/* 362B9C E005E5DC AC820000 */  sw        $v0, ($a0)
/* 362BA0 E005E5E0 8FA800D8 */  lw        $t0, 0xd8($sp)
/* 362BA4 E005E5E4 24020040 */  addiu     $v0, $zero, 0x40
/* 362BA8 E005E5E8 AC860008 */  sw        $a2, 8($a0)
/* 362BAC E005E5EC AC82000C */  sw        $v0, 0xc($a0)
/* 362BB0 E005E5F0 AC880004 */  sw        $t0, 4($a0)
/* 362BB4 E005E5F4 8FA80110 */  lw        $t0, 0x110($sp)
/* 362BB8 E005E5F8 2610002C */  addiu     $s0, $s0, 0x2c
/* 362BBC E005E5FC 8D020008 */  lw        $v0, 8($t0)
/* 362BC0 E005E600 24840010 */  addiu     $a0, $a0, 0x10
/* 362BC4 E005E604 0282102A */  slt       $v0, $s4, $v0
/* 362BC8 E005E608 1440FFC7 */  bnez      $v0, .LE005E528
/* 362BCC E005E60C AE240000 */   sw       $a0, ($s1)
.LE005E610:
/* 362BD0 E005E610 3C05D838 */  lui       $a1, 0xd838
/* 362BD4 E005E614 3C03800A */  lui       $v1, %hi(gMasterGfxPos)
/* 362BD8 E005E618 2463A66C */  addiu     $v1, $v1, %lo(gMasterGfxPos)
/* 362BDC E005E61C 8C620000 */  lw        $v0, ($v1)
/* 362BE0 E005E620 34A50002 */  ori       $a1, $a1, 2
/* 362BE4 E005E624 0040202D */  daddu     $a0, $v0, $zero
/* 362BE8 E005E628 24420008 */  addiu     $v0, $v0, 8
/* 362BEC E005E62C AC620000 */  sw        $v0, ($v1)
/* 362BF0 E005E630 24020040 */  addiu     $v0, $zero, 0x40
/* 362BF4 E005E634 AC850000 */  sw        $a1, ($a0)
/* 362BF8 E005E638 AC820004 */  sw        $v0, 4($a0)
.LE005E63C:
/* 362BFC E005E63C 8FBF0104 */  lw        $ra, 0x104($sp)
/* 362C00 E005E640 8FBE0100 */  lw        $fp, 0x100($sp)
/* 362C04 E005E644 8FB700FC */  lw        $s7, 0xfc($sp)
/* 362C08 E005E648 8FB600F8 */  lw        $s6, 0xf8($sp)
/* 362C0C E005E64C 8FB500F4 */  lw        $s5, 0xf4($sp)
/* 362C10 E005E650 8FB400F0 */  lw        $s4, 0xf0($sp)
/* 362C14 E005E654 8FB300EC */  lw        $s3, 0xec($sp)
/* 362C18 E005E658 8FB200E8 */  lw        $s2, 0xe8($sp)
/* 362C1C E005E65C 8FB100E4 */  lw        $s1, 0xe4($sp)
/* 362C20 E005E660 8FB000E0 */  lw        $s0, 0xe0($sp)
/* 362C24 E005E664 D7B40108 */  ldc1      $f20, 0x108($sp)
/* 362C28 E005E668 03E00008 */  jr        $ra
/* 362C2C E005E66C 27BD0110 */   addiu    $sp, $sp, 0x110
