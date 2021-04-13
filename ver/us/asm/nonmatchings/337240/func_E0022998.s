.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E0022998
/* 337BD8 E0022998 27BDFF00 */  addiu     $sp, $sp, -0x100
/* 337BDC E002299C 3C06DB06 */  lui       $a2, 0xdb06
/* 337BE0 E00229A0 34C60024 */  ori       $a2, $a2, 0x24
/* 337BE4 E00229A4 AFA40100 */  sw        $a0, 0x100($sp)
/* 337BE8 E00229A8 27A40018 */  addiu     $a0, $sp, 0x18
/* 337BEC E00229AC AFB300E4 */  sw        $s3, 0xe4($sp)
/* 337BF0 E00229B0 3C13800A */  lui       $s3, %hi(gMasterGfxPos)
/* 337BF4 E00229B4 2673A66C */  addiu     $s3, $s3, %lo(gMasterGfxPos)
/* 337BF8 E00229B8 3C02E700 */  lui       $v0, 0xe700
/* 337BFC E00229BC AFBF00FC */  sw        $ra, 0xfc($sp)
/* 337C00 E00229C0 AFBE00F8 */  sw        $fp, 0xf8($sp)
/* 337C04 E00229C4 AFB700F4 */  sw        $s7, 0xf4($sp)
/* 337C08 E00229C8 AFB600F0 */  sw        $s6, 0xf0($sp)
/* 337C0C E00229CC AFB500EC */  sw        $s5, 0xec($sp)
/* 337C10 E00229D0 AFB400E8 */  sw        $s4, 0xe8($sp)
/* 337C14 E00229D4 AFB200E0 */  sw        $s2, 0xe0($sp)
/* 337C18 E00229D8 AFB100DC */  sw        $s1, 0xdc($sp)
/* 337C1C E00229DC AFB000D8 */  sw        $s0, 0xd8($sp)
/* 337C20 E00229E0 8E630000 */  lw        $v1, ($s3)
/* 337C24 E00229E4 8FAA0100 */  lw        $t2, 0x100($sp)
/* 337C28 E00229E8 0060282D */  daddu     $a1, $v1, $zero
/* 337C2C E00229EC 8D50000C */  lw        $s0, 0xc($t2)
/* 337C30 E00229F0 24630008 */  addiu     $v1, $v1, 8
/* 337C34 E00229F4 AE630000 */  sw        $v1, ($s3)
/* 337C38 E00229F8 ACA20000 */  sw        $v0, ($a1)
/* 337C3C E00229FC 24620008 */  addiu     $v0, $v1, 8
/* 337C40 E0022A00 ACA00004 */  sw        $zero, 4($a1)
/* 337C44 E0022A04 AE620000 */  sw        $v0, ($s3)
/* 337C48 E0022A08 AC660000 */  sw        $a2, ($v1)
/* 337C4C E0022A0C 8D450010 */  lw        $a1, 0x10($t2)
/* 337C50 E0022A10 24620010 */  addiu     $v0, $v1, 0x10
/* 337C54 E0022A14 AE620000 */  sw        $v0, ($s3)
/* 337C58 E0022A18 8CA5001C */  lw        $a1, 0x1c($a1)
/* 337C5C E0022A1C 3C02DE00 */  lui       $v0, 0xde00
/* 337C60 E0022A20 AC620008 */  sw        $v0, 8($v1)
/* 337C64 E0022A24 3C020900 */  lui       $v0, 0x900
/* 337C68 E0022A28 24420F20 */  addiu     $v0, $v0, 0xf20
/* 337C6C E0022A2C AC62000C */  sw        $v0, 0xc($v1)
/* 337C70 E0022A30 3C028000 */  lui       $v0, 0x8000
/* 337C74 E0022A34 00A22821 */  addu      $a1, $a1, $v0
/* 337C78 E0022A38 AC650004 */  sw        $a1, 4($v1)
/* 337C7C E0022A3C 8E050004 */  lw        $a1, 4($s0)
/* 337C80 E0022A40 8E060008 */  lw        $a2, 8($s0)
/* 337C84 E0022A44 8E020020 */  lw        $v0, 0x20($s0)
/* 337C88 E0022A48 8E07000C */  lw        $a3, 0xc($s0)
/* 337C8C E0022A4C 2442FFFF */  addiu     $v0, $v0, -1
/* 337C90 E0022A50 00021840 */  sll       $v1, $v0, 1
/* 337C94 E0022A54 0C080108 */  jal       func_E0200420
/* 337C98 E0022A58 00628821 */   addu     $s1, $v1, $v0
/* 337C9C E0022A5C 27B20058 */  addiu     $s2, $sp, 0x58
/* 337CA0 E0022A60 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 337CA4 E0022A64 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 337CA8 E0022A68 44800000 */  mtc1      $zero, $f0
/* 337CAC E0022A6C 00031080 */  sll       $v0, $v1, 2
/* 337CB0 E0022A70 00431021 */  addu      $v0, $v0, $v1
/* 337CB4 E0022A74 00021080 */  sll       $v0, $v0, 2
/* 337CB8 E0022A78 00431023 */  subu      $v0, $v0, $v1
/* 337CBC E0022A7C 000218C0 */  sll       $v1, $v0, 3
/* 337CC0 E0022A80 00431021 */  addu      $v0, $v0, $v1
/* 337CC4 E0022A84 000210C0 */  sll       $v0, $v0, 3
/* 337CC8 E0022A88 44060000 */  mfc1      $a2, $f0
/* 337CCC E0022A8C 3C01800B */  lui       $at, %hi(gCameras+0x6C)
/* 337CD0 E0022A90 00220821 */  addu      $at, $at, $v0
/* 337CD4 E0022A94 C4201DEC */  lwc1      $f0, %lo(gCameras+0x6C)($at)
/* 337CD8 E0022A98 3C073F80 */  lui       $a3, 0x3f80
/* 337CDC E0022A9C 46000007 */  neg.s     $f0, $f0
/* 337CE0 E0022AA0 44050000 */  mfc1      $a1, $f0
/* 337CE4 E0022AA4 0240202D */  daddu     $a0, $s2, $zero
/* 337CE8 E0022AA8 0C080104 */  jal       func_E0200410
/* 337CEC E0022AAC AFA60010 */   sw       $a2, 0x10($sp)
/* 337CF0 E0022AB0 0240202D */  daddu     $a0, $s2, $zero
/* 337CF4 E0022AB4 27A50018 */  addiu     $a1, $sp, 0x18
/* 337CF8 E0022AB8 0C080114 */  jal       func_E0200450
/* 337CFC E0022ABC 27A60098 */   addiu    $a2, $sp, 0x98
/* 337D00 E0022AC0 8FAA0100 */  lw        $t2, 0x100($sp)
/* 337D04 E0022AC4 0000A02D */  daddu     $s4, $zero, $zero
/* 337D08 E0022AC8 8D420008 */  lw        $v0, 8($t2)
/* 337D0C E0022ACC 2442FFFF */  addiu     $v0, $v0, -1
/* 337D10 E0022AD0 18400069 */  blez      $v0, .LE0022C78
/* 337D14 E0022AD4 26100030 */   addiu    $s0, $s0, 0x30
/* 337D18 E0022AD8 0240B02D */  daddu     $s6, $s2, $zero
/* 337D1C E0022ADC 3C1E8007 */  lui       $fp, %hi(gMatrixListPos)
/* 337D20 E0022AE0 27DE41F0 */  addiu     $fp, $fp, %lo(gMatrixListPos)
/* 337D24 E0022AE4 3C150001 */  lui       $s5, 1
/* 337D28 E0022AE8 36B51630 */  ori       $s5, $s5, 0x1630
/* 337D2C E0022AEC 0260902D */  daddu     $s2, $s3, $zero
/* 337D30 E0022AF0 3C17E002 */  lui       $s7, %hi(D_E0022CF0)
/* 337D34 E0022AF4 26F72CF0 */  addiu     $s7, $s7, %lo(D_E0022CF0)
/* 337D38 E0022AF8 2610001C */  addiu     $s0, $s0, 0x1c
.LE0022AFC:
/* 337D3C E0022AFC 8E130010 */  lw        $s3, 0x10($s0)
/* 337D40 E0022B00 06600056 */  bltz      $s3, .LE0022C5C
/* 337D44 E0022B04 02C0202D */   daddu    $a0, $s6, $zero
/* 337D48 E0022B08 8E05FFE8 */  lw        $a1, -0x18($s0)
/* 337D4C E0022B0C 8E06FFEC */  lw        $a2, -0x14($s0)
/* 337D50 E0022B10 8E07FFF0 */  lw        $a3, -0x10($s0)
/* 337D54 E0022B14 0C080108 */  jal       func_E0200420
/* 337D58 E0022B18 26310003 */   addiu    $s1, $s1, 3
/* 337D5C E0022B1C C6000000 */  lwc1      $f0, ($s0)
/* 337D60 E0022B20 02C0202D */  daddu     $a0, $s6, $zero
/* 337D64 E0022B24 E7A00058 */  swc1      $f0, 0x58($sp)
/* 337D68 E0022B28 C6000000 */  lwc1      $f0, ($s0)
/* 337D6C E0022B2C 27A50098 */  addiu     $a1, $sp, 0x98
/* 337D70 E0022B30 E7A0006C */  swc1      $f0, 0x6c($sp)
/* 337D74 E0022B34 C6000000 */  lwc1      $f0, ($s0)
/* 337D78 E0022B38 27A60018 */  addiu     $a2, $sp, 0x18
/* 337D7C E0022B3C 0C080114 */  jal       func_E0200450
/* 337D80 E0022B40 E7A00080 */   swc1     $f0, 0x80($sp)
/* 337D84 E0022B44 27A40018 */  addiu     $a0, $sp, 0x18
/* 337D88 E0022B48 97C50000 */  lhu       $a1, ($fp)
/* 337D8C E0022B4C 3C02800A */  lui       $v0, %hi(gDisplayContext)
/* 337D90 E0022B50 8C42A674 */  lw        $v0, %lo(gDisplayContext)($v0)
/* 337D94 E0022B54 00052980 */  sll       $a1, $a1, 6
/* 337D98 E0022B58 00B52821 */  addu      $a1, $a1, $s5
/* 337D9C E0022B5C 0C080118 */  jal       func_E0200460
/* 337DA0 E0022B60 00452821 */   addu     $a1, $v0, $a1
/* 337DA4 E0022B64 3C0238E3 */  lui       $v0, 0x38e3
/* 337DA8 E0022B68 34428E39 */  ori       $v0, $v0, 0x8e39
/* 337DAC E0022B6C 3C09D838 */  lui       $t1, 0xd838
/* 337DB0 E0022B70 35290002 */  ori       $t1, $t1, 2
/* 337DB4 E0022B74 02220018 */  mult      $s1, $v0
/* 337DB8 E0022B78 8E470000 */  lw        $a3, ($s2)
/* 337DBC E0022B7C 3C02FA00 */  lui       $v0, 0xfa00
/* 337DC0 E0022B80 00E0402D */  daddu     $t0, $a3, $zero
/* 337DC4 E0022B84 24E70008 */  addiu     $a3, $a3, 8
/* 337DC8 E0022B88 AE470000 */  sw        $a3, ($s2)
/* 337DCC E0022B8C AD020000 */  sw        $v0, ($t0)
/* 337DD0 E0022B90 001117C3 */  sra       $v0, $s1, 0x1f
/* 337DD4 E0022B94 00005010 */  mfhi      $t2
/* 337DD8 E0022B98 000A18C3 */  sra       $v1, $t2, 3
/* 337DDC E0022B9C 00621823 */  subu      $v1, $v1, $v0
/* 337DE0 E0022BA0 000310C0 */  sll       $v0, $v1, 3
/* 337DE4 E0022BA4 00431021 */  addu      $v0, $v0, $v1
/* 337DE8 E0022BA8 00021080 */  sll       $v0, $v0, 2
/* 337DEC E0022BAC 02228823 */  subu      $s1, $s1, $v0
/* 337DF0 E0022BB0 02371021 */  addu      $v0, $s1, $s7
/* 337DF4 E0022BB4 0040202D */  daddu     $a0, $v0, $zero
/* 337DF8 E0022BB8 0040282D */  daddu     $a1, $v0, $zero
/* 337DFC E0022BBC 90430000 */  lbu       $v1, ($v0)
/* 337E00 E0022BC0 24E20008 */  addiu     $v0, $a3, 8
/* 337E04 E0022BC4 90860001 */  lbu       $a2, 1($a0)
/* 337E08 E0022BC8 90A50002 */  lbu       $a1, 2($a1)
/* 337E0C E0022BCC 97C40000 */  lhu       $a0, ($fp)
/* 337E10 E0022BD0 3C0AE002 */  lui       $t2, %hi(D_E0022CD0)
/* 337E14 E0022BD4 254A2CD0 */  addiu     $t2, $t2, %lo(D_E0022CD0)
/* 337E18 E0022BD8 AE420000 */  sw        $v0, ($s2)
/* 337E1C E0022BDC 24820001 */  addiu     $v0, $a0, 1
/* 337E20 E0022BE0 A7C20000 */  sh        $v0, ($fp)
/* 337E24 E0022BE4 24E20010 */  addiu     $v0, $a3, 0x10
/* 337E28 E0022BE8 00031E00 */  sll       $v1, $v1, 0x18
/* 337E2C E0022BEC 00063400 */  sll       $a2, $a2, 0x10
/* 337E30 E0022BF0 00661825 */  or        $v1, $v1, $a2
/* 337E34 E0022BF4 00052A00 */  sll       $a1, $a1, 8
/* 337E38 E0022BF8 00651825 */  or        $v1, $v1, $a1
/* 337E3C E0022BFC 346300FF */  ori       $v1, $v1, 0xff
/* 337E40 E0022C00 AE420000 */  sw        $v0, ($s2)
/* 337E44 E0022C04 3C02DA38 */  lui       $v0, 0xda38
/* 337E48 E0022C08 3084FFFF */  andi      $a0, $a0, 0xffff
/* 337E4C E0022C0C 00042180 */  sll       $a0, $a0, 6
/* 337E50 E0022C10 AD030004 */  sw        $v1, 4($t0)
/* 337E54 E0022C14 ACE20000 */  sw        $v0, ($a3)
/* 337E58 E0022C18 3C02800A */  lui       $v0, %hi(gDisplayContext)
/* 337E5C E0022C1C 8C42A674 */  lw        $v0, %lo(gDisplayContext)($v0)
/* 337E60 E0022C20 00952021 */  addu      $a0, $a0, $s5
/* 337E64 E0022C24 00441021 */  addu      $v0, $v0, $a0
/* 337E68 E0022C28 ACE20004 */  sw        $v0, 4($a3)
/* 337E6C E0022C2C 3C02DE00 */  lui       $v0, 0xde00
/* 337E70 E0022C30 ACE20008 */  sw        $v0, 8($a3)
/* 337E74 E0022C34 32620007 */  andi      $v0, $s3, 7
/* 337E78 E0022C38 00021080 */  sll       $v0, $v0, 2
/* 337E7C E0022C3C 004A1021 */  addu      $v0, $v0, $t2
/* 337E80 E0022C40 8C430000 */  lw        $v1, ($v0)
/* 337E84 E0022C44 24E20018 */  addiu     $v0, $a3, 0x18
/* 337E88 E0022C48 AE420000 */  sw        $v0, ($s2)
/* 337E8C E0022C4C 24020040 */  addiu     $v0, $zero, 0x40
/* 337E90 E0022C50 ACE90010 */  sw        $t1, 0x10($a3)
/* 337E94 E0022C54 ACE20014 */  sw        $v0, 0x14($a3)
/* 337E98 E0022C58 ACE3000C */  sw        $v1, 0xc($a3)
.LE0022C5C:
/* 337E9C E0022C5C 8FAA0100 */  lw        $t2, 0x100($sp)
/* 337EA0 E0022C60 26940001 */  addiu     $s4, $s4, 1
/* 337EA4 E0022C64 8D420008 */  lw        $v0, 8($t2)
/* 337EA8 E0022C68 2442FFFF */  addiu     $v0, $v0, -1
/* 337EAC E0022C6C 0282102A */  slt       $v0, $s4, $v0
/* 337EB0 E0022C70 1440FFA2 */  bnez      $v0, .LE0022AFC
/* 337EB4 E0022C74 26100030 */   addiu    $s0, $s0, 0x30
.LE0022C78:
/* 337EB8 E0022C78 3C03800A */  lui       $v1, %hi(gMasterGfxPos)
/* 337EBC E0022C7C 2463A66C */  addiu     $v1, $v1, %lo(gMasterGfxPos)
/* 337EC0 E0022C80 8C620000 */  lw        $v0, ($v1)
/* 337EC4 E0022C84 0040202D */  daddu     $a0, $v0, $zero
/* 337EC8 E0022C88 24420008 */  addiu     $v0, $v0, 8
/* 337ECC E0022C8C AC620000 */  sw        $v0, ($v1)
/* 337ED0 E0022C90 3C02E700 */  lui       $v0, 0xe700
/* 337ED4 E0022C94 AC820000 */  sw        $v0, ($a0)
/* 337ED8 E0022C98 AC800004 */  sw        $zero, 4($a0)
/* 337EDC E0022C9C 8FBF00FC */  lw        $ra, 0xfc($sp)
/* 337EE0 E0022CA0 8FBE00F8 */  lw        $fp, 0xf8($sp)
/* 337EE4 E0022CA4 8FB700F4 */  lw        $s7, 0xf4($sp)
/* 337EE8 E0022CA8 8FB600F0 */  lw        $s6, 0xf0($sp)
/* 337EEC E0022CAC 8FB500EC */  lw        $s5, 0xec($sp)
/* 337EF0 E0022CB0 8FB400E8 */  lw        $s4, 0xe8($sp)
/* 337EF4 E0022CB4 8FB300E4 */  lw        $s3, 0xe4($sp)
/* 337EF8 E0022CB8 8FB200E0 */  lw        $s2, 0xe0($sp)
/* 337EFC E0022CBC 8FB100DC */  lw        $s1, 0xdc($sp)
/* 337F00 E0022CC0 8FB000D8 */  lw        $s0, 0xd8($sp)
/* 337F04 E0022CC4 03E00008 */  jr        $ra
/* 337F08 E0022CC8 27BD0100 */   addiu    $sp, $sp, 0x100
/* 337F0C E0022CCC 00000000 */  nop
