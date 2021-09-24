.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E0030A68
/* 342BA8 E0030A68 27BDFF20 */  addiu     $sp, $sp, -0xe0
/* 342BAC E0030A6C 3C05DB06 */  lui       $a1, 0xdb06
/* 342BB0 E0030A70 34A50024 */  ori       $a1, $a1, 0x24
/* 342BB4 E0030A74 3C09800A */  lui       $t1, %hi(gMasterGfxPos)
/* 342BB8 E0030A78 2529A66C */  addiu     $t1, $t1, %lo(gMasterGfxPos)
/* 342BBC E0030A7C 3C0638E3 */  lui       $a2, 0x38e3
/* 342BC0 E0030A80 3C02E700 */  lui       $v0, 0xe700
/* 342BC4 E0030A84 AFBF00CC */  sw        $ra, 0xcc($sp)
/* 342BC8 E0030A88 AFBE00C8 */  sw        $fp, 0xc8($sp)
/* 342BCC E0030A8C AFB700C4 */  sw        $s7, 0xc4($sp)
/* 342BD0 E0030A90 AFB600C0 */  sw        $s6, 0xc0($sp)
/* 342BD4 E0030A94 AFB500BC */  sw        $s5, 0xbc($sp)
/* 342BD8 E0030A98 AFB400B8 */  sw        $s4, 0xb8($sp)
/* 342BDC E0030A9C AFB300B4 */  sw        $s3, 0xb4($sp)
/* 342BE0 E0030AA0 AFB200B0 */  sw        $s2, 0xb0($sp)
/* 342BE4 E0030AA4 AFB100AC */  sw        $s1, 0xac($sp)
/* 342BE8 E0030AA8 AFB000A8 */  sw        $s0, 0xa8($sp)
/* 342BEC E0030AAC F7B600D8 */  sdc1      $f22, 0xd8($sp)
/* 342BF0 E0030AB0 F7B400D0 */  sdc1      $f20, 0xd0($sp)
/* 342BF4 E0030AB4 AFA400E0 */  sw        $a0, 0xe0($sp)
/* 342BF8 E0030AB8 8D240000 */  lw        $a0, ($t1)
/* 342BFC E0030ABC 8FAA00E0 */  lw        $t2, 0xe0($sp)
/* 342C00 E0030AC0 0080182D */  daddu     $v1, $a0, $zero
/* 342C04 E0030AC4 8D47000C */  lw        $a3, 0xc($t2)
/* 342C08 E0030AC8 24840008 */  addiu     $a0, $a0, 8
/* 342C0C E0030ACC AC620000 */  sw        $v0, ($v1)
/* 342C10 E0030AD0 AC600004 */  sw        $zero, 4($v1)
/* 342C14 E0030AD4 AC850000 */  sw        $a1, ($a0)
/* 342C18 E0030AD8 8D420010 */  lw        $v0, 0x10($t2)
/* 342C1C E0030ADC 34C68E39 */  ori       $a2, $a2, 0x8e39
/* 342C20 E0030AE0 8C43001C */  lw        $v1, 0x1c($v0)
/* 342C24 E0030AE4 3C02DE00 */  lui       $v0, 0xde00
/* 342C28 E0030AE8 AC820008 */  sw        $v0, 8($a0)
/* 342C2C E0030AEC 3C020900 */  lui       $v0, 0x900
/* 342C30 E0030AF0 244204C0 */  addiu     $v0, $v0, 0x4c0
/* 342C34 E0030AF4 AC82000C */  sw        $v0, 0xc($a0)
/* 342C38 E0030AF8 3C028000 */  lui       $v0, 0x8000
/* 342C3C E0030AFC 00621821 */  addu      $v1, $v1, $v0
/* 342C40 E0030B00 AC830004 */  sw        $v1, 4($a0)
/* 342C44 E0030B04 8CE2002C */  lw        $v0, 0x2c($a3)
/* 342C48 E0030B08 0000A82D */  daddu     $s5, $zero, $zero
/* 342C4C E0030B0C AD240000 */  sw        $a0, ($t1)
/* 342C50 E0030B10 2442FFFF */  addiu     $v0, $v0, -1
/* 342C54 E0030B14 00021840 */  sll       $v1, $v0, 1
/* 342C58 E0030B18 0062A021 */  addu      $s4, $v1, $v0
/* 342C5C E0030B1C 24820008 */  addiu     $v0, $a0, 8
/* 342C60 E0030B20 02860018 */  mult      $s4, $a2
/* 342C64 E0030B24 24840010 */  addiu     $a0, $a0, 0x10
/* 342C68 E0030B28 AD220000 */  sw        $v0, ($t1)
/* 342C6C E0030B2C 001417C3 */  sra       $v0, $s4, 0x1f
/* 342C70 E0030B30 AD240000 */  sw        $a0, ($t1)
/* 342C74 E0030B34 00005010 */  mfhi      $t2
/* 342C78 E0030B38 000A18C3 */  sra       $v1, $t2, 3
/* 342C7C E0030B3C 00621823 */  subu      $v1, $v1, $v0
/* 342C80 E0030B40 000310C0 */  sll       $v0, $v1, 3
/* 342C84 E0030B44 00431021 */  addu      $v0, $v0, $v1
/* 342C88 E0030B48 8FAA00E0 */  lw        $t2, 0xe0($sp)
/* 342C8C E0030B4C 00021080 */  sll       $v0, $v0, 2
/* 342C90 E0030B50 8D430008 */  lw        $v1, 8($t2)
/* 342C94 E0030B54 186000BE */  blez      $v1, .LE0030E50
/* 342C98 E0030B58 0282A023 */   subu     $s4, $s4, $v0
/* 342C9C E0030B5C 0120882D */  daddu     $s1, $t1, $zero
/* 342CA0 E0030B60 3C0A38E3 */  lui       $t2, 0x38e3
/* 342CA4 E0030B64 354A8E39 */  ori       $t2, $t2, 0x8e39
/* 342CA8 E0030B68 AFAA0098 */  sw        $t2, 0x98($sp)
/* 342CAC E0030B6C 27AA0058 */  addiu     $t2, $sp, 0x58
/* 342CB0 E0030B70 3C168007 */  lui       $s6, %hi(gMatrixListPos)
/* 342CB4 E0030B74 26D641F0 */  addiu     $s6, $s6, %lo(gMatrixListPos)
/* 342CB8 E0030B78 3C130001 */  lui       $s3, 1
/* 342CBC E0030B7C 36731630 */  ori       $s3, $s3, 0x1630
/* 342CC0 E0030B80 AFAA009C */  sw        $t2, 0x9c($sp)
/* 342CC4 E0030B84 3C0AD838 */  lui       $t2, 0xd838
/* 342CC8 E0030B88 354A0002 */  ori       $t2, $t2, 2
/* 342CCC E0030B8C 24F0001C */  addiu     $s0, $a3, 0x1c
/* 342CD0 E0030B90 241E0002 */  addiu     $fp, $zero, 2
/* 342CD4 E0030B94 24170001 */  addiu     $s7, $zero, 1
/* 342CD8 E0030B98 4480A000 */  mtc1      $zero, $f20
/* 342CDC E0030B9C 3C013F80 */  lui       $at, 0x3f80
/* 342CE0 E0030BA0 4481B000 */  mtc1      $at, $f22
/* 342CE4 E0030BA4 0280902D */  daddu     $s2, $s4, $zero
/* 342CE8 E0030BA8 AFAA00A0 */  sw        $t2, 0xa0($sp)
.LE0030BAC:
/* 342CEC E0030BAC 27A40018 */  addiu     $a0, $sp, 0x18
/* 342CF0 E0030BB0 029E3821 */  addu      $a3, $s4, $fp
/* 342CF4 E0030BB4 02973021 */  addu      $a2, $s4, $s7
/* 342CF8 E0030BB8 8E220000 */  lw        $v0, ($s1)
/* 342CFC E0030BBC 8FAA0098 */  lw        $t2, 0x98($sp)
/* 342D00 E0030BC0 0040402D */  daddu     $t0, $v0, $zero
/* 342D04 E0030BC4 24420008 */  addiu     $v0, $v0, 8
/* 342D08 E0030BC8 024A0018 */  mult      $s2, $t2
/* 342D0C E0030BCC AE220000 */  sw        $v0, ($s1)
/* 342D10 E0030BD0 3C02FA00 */  lui       $v0, 0xfa00
/* 342D14 E0030BD4 AD020000 */  sw        $v0, ($t0)
/* 342D18 E0030BD8 001217C3 */  sra       $v0, $s2, 0x1f
/* 342D1C E0030BDC 00005010 */  mfhi      $t2
/* 342D20 E0030BE0 000A18C3 */  sra       $v1, $t2, 3
/* 342D24 E0030BE4 00621823 */  subu      $v1, $v1, $v0
/* 342D28 E0030BE8 000328C0 */  sll       $a1, $v1, 3
/* 342D2C E0030BEC 00A32821 */  addu      $a1, $a1, $v1
/* 342D30 E0030BF0 00052880 */  sll       $a1, $a1, 2
/* 342D34 E0030BF4 8FAA0098 */  lw        $t2, 0x98($sp)
/* 342D38 E0030BF8 02452823 */  subu      $a1, $s2, $a1
/* 342D3C E0030BFC 00CA0018 */  mult      $a2, $t2
/* 342D40 E0030C00 000617C3 */  sra       $v0, $a2, 0x1f
/* 342D44 E0030C04 3C0AE003 */  lui       $t2, %hi(D_E0030E90)
/* 342D48 E0030C08 254A0E90 */  addiu     $t2, $t2, %lo(D_E0030E90)
/* 342D4C E0030C0C 00AA2821 */  addu      $a1, $a1, $t2
/* 342D50 E0030C10 90A50000 */  lbu       $a1, ($a1)
/* 342D54 E0030C14 00005010 */  mfhi      $t2
/* 342D58 E0030C18 000A18C3 */  sra       $v1, $t2, 3
/* 342D5C E0030C1C 00621823 */  subu      $v1, $v1, $v0
/* 342D60 E0030C20 000310C0 */  sll       $v0, $v1, 3
/* 342D64 E0030C24 00431021 */  addu      $v0, $v0, $v1
/* 342D68 E0030C28 00021080 */  sll       $v0, $v0, 2
/* 342D6C E0030C2C 00C23023 */  subu      $a2, $a2, $v0
/* 342D70 E0030C30 3C0AE003 */  lui       $t2, %hi(D_E0030E90)
/* 342D74 E0030C34 254A0E90 */  addiu     $t2, $t2, %lo(D_E0030E90)
/* 342D78 E0030C38 00CA3021 */  addu      $a2, $a2, $t2
/* 342D7C E0030C3C 8FAA0098 */  lw        $t2, 0x98($sp)
/* 342D80 E0030C40 00052E00 */  sll       $a1, $a1, 0x18
/* 342D84 E0030C44 00EA0018 */  mult      $a3, $t2
/* 342D88 E0030C48 90C60000 */  lbu       $a2, ($a2)
/* 342D8C E0030C4C 000717C3 */  sra       $v0, $a3, 0x1f
/* 342D90 E0030C50 00063400 */  sll       $a2, $a2, 0x10
/* 342D94 E0030C54 00A62825 */  or        $a1, $a1, $a2
/* 342D98 E0030C58 00005010 */  mfhi      $t2
/* 342D9C E0030C5C 000A18C3 */  sra       $v1, $t2, 3
/* 342DA0 E0030C60 00621823 */  subu      $v1, $v1, $v0
/* 342DA4 E0030C64 000310C0 */  sll       $v0, $v1, 3
/* 342DA8 E0030C68 00431021 */  addu      $v0, $v0, $v1
/* 342DAC E0030C6C 00021080 */  sll       $v0, $v0, 2
/* 342DB0 E0030C70 00E23823 */  subu      $a3, $a3, $v0
/* 342DB4 E0030C74 3C0AE003 */  lui       $t2, %hi(D_E0030E90)
/* 342DB8 E0030C78 254A0E90 */  addiu     $t2, $t2, %lo(D_E0030E90)
/* 342DBC E0030C7C 00EA3821 */  addu      $a3, $a3, $t2
/* 342DC0 E0030C80 90E20000 */  lbu       $v0, ($a3)
/* 342DC4 E0030C84 9203000B */  lbu       $v1, 0xb($s0)
/* 342DC8 E0030C88 00021200 */  sll       $v0, $v0, 8
/* 342DCC E0030C8C 00A22825 */  or        $a1, $a1, $v0
/* 342DD0 E0030C90 00A32825 */  or        $a1, $a1, $v1
/* 342DD4 E0030C94 AD050004 */  sw        $a1, 4($t0)
/* 342DD8 E0030C98 8E05FFE8 */  lw        $a1, -0x18($s0)
/* 342DDC E0030C9C 8E06FFEC */  lw        $a2, -0x14($s0)
/* 342DE0 E0030CA0 8E07FFF0 */  lw        $a3, -0x10($s0)
/* 342DE4 E0030CA4 0C080108 */  jal       shim_guTranslateF
/* 342DE8 E0030CA8 27DE0003 */   addiu    $fp, $fp, 3
/* 342DEC E0030CAC 3C0A800B */  lui       $t2, %hi(gCameras)
/* 342DF0 E0030CB0 254A1D80 */  addiu     $t2, $t2, %lo(gCameras)
/* 342DF4 E0030CB4 4406A000 */  mfc1      $a2, $f20
/* 342DF8 E0030CB8 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 342DFC E0030CBC 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 342E00 E0030CC0 4407B000 */  mfc1      $a3, $f22
/* 342E04 E0030CC4 00031080 */  sll       $v0, $v1, 2
/* 342E08 E0030CC8 00431021 */  addu      $v0, $v0, $v1
/* 342E0C E0030CCC 00021080 */  sll       $v0, $v0, 2
/* 342E10 E0030CD0 00431023 */  subu      $v0, $v0, $v1
/* 342E14 E0030CD4 000218C0 */  sll       $v1, $v0, 3
/* 342E18 E0030CD8 00431021 */  addu      $v0, $v0, $v1
/* 342E1C E0030CDC 000210C0 */  sll       $v0, $v0, 3
/* 342E20 E0030CE0 004A1021 */  addu      $v0, $v0, $t2
/* 342E24 E0030CE4 C440006C */  lwc1      $f0, 0x6c($v0)
/* 342E28 E0030CE8 8FA4009C */  lw        $a0, 0x9c($sp)
/* 342E2C E0030CEC 46000007 */  neg.s     $f0, $f0
/* 342E30 E0030CF0 44050000 */  mfc1      $a1, $f0
/* 342E34 E0030CF4 26F70003 */  addiu     $s7, $s7, 3
/* 342E38 E0030CF8 0C080104 */  jal       shim_guRotateF
/* 342E3C E0030CFC E7B40010 */   swc1     $f20, 0x10($sp)
/* 342E40 E0030D00 27A50018 */  addiu     $a1, $sp, 0x18
/* 342E44 E0030D04 8FA4009C */  lw        $a0, 0x9c($sp)
/* 342E48 E0030D08 0C080114 */  jal       shim_guMtxCatF
/* 342E4C E0030D0C 00A0302D */   daddu    $a2, $a1, $zero
/* 342E50 E0030D10 27A40018 */  addiu     $a0, $sp, 0x18
/* 342E54 E0030D14 96C50000 */  lhu       $a1, ($s6)
/* 342E58 E0030D18 3C02800A */  lui       $v0, %hi(gDisplayContext)
/* 342E5C E0030D1C 8C42A674 */  lw        $v0, %lo(gDisplayContext)($v0)
/* 342E60 E0030D20 00052980 */  sll       $a1, $a1, 6
/* 342E64 E0030D24 00B32821 */  addu      $a1, $a1, $s3
/* 342E68 E0030D28 0C080118 */  jal       shim_guMtxF2L
/* 342E6C E0030D2C 00452821 */   addu     $a1, $v0, $a1
/* 342E70 E0030D30 27A40018 */  addiu     $a0, $sp, 0x18
/* 342E74 E0030D34 8E290000 */  lw        $t1, ($s1)
/* 342E78 E0030D38 4406A000 */  mfc1      $a2, $f20
/* 342E7C E0030D3C 4407A000 */  mfc1      $a3, $f20
/* 342E80 E0030D40 96C80000 */  lhu       $t0, ($s6)
/* 342E84 E0030D44 3C03800A */  lui       $v1, %hi(gDisplayContext)
/* 342E88 E0030D48 8C63A674 */  lw        $v1, %lo(gDisplayContext)($v1)
/* 342E8C E0030D4C 0120282D */  daddu     $a1, $t1, $zero
/* 342E90 E0030D50 3C0ADA38 */  lui       $t2, 0xda38
/* 342E94 E0030D54 3102FFFF */  andi      $v0, $t0, 0xffff
/* 342E98 E0030D58 00021180 */  sll       $v0, $v0, 6
/* 342E9C E0030D5C 00531021 */  addu      $v0, $v0, $s3
/* 342EA0 E0030D60 00621821 */  addu      $v1, $v1, $v0
/* 342EA4 E0030D64 25290008 */  addiu     $t1, $t1, 8
/* 342EA8 E0030D68 ACAA0000 */  sw        $t2, ($a1)
/* 342EAC E0030D6C ACA30004 */  sw        $v1, 4($a1)
/* 342EB0 E0030D70 E7B60010 */  swc1      $f22, 0x10($sp)
/* 342EB4 E0030D74 8E050000 */  lw        $a1, ($s0)
/* 342EB8 E0030D78 25080001 */  addiu     $t0, $t0, 1
/* 342EBC E0030D7C AE290000 */  sw        $t1, ($s1)
/* 342EC0 E0030D80 0C080104 */  jal       shim_guRotateF
/* 342EC4 E0030D84 A6C80000 */   sh       $t0, ($s6)
/* 342EC8 E0030D88 27A40018 */  addiu     $a0, $sp, 0x18
/* 342ECC E0030D8C 96C50000 */  lhu       $a1, ($s6)
/* 342ED0 E0030D90 3C02800A */  lui       $v0, %hi(gDisplayContext)
/* 342ED4 E0030D94 8C42A674 */  lw        $v0, %lo(gDisplayContext)($v0)
/* 342ED8 E0030D98 00052980 */  sll       $a1, $a1, 6
/* 342EDC E0030D9C 00B32821 */  addu      $a1, $a1, $s3
/* 342EE0 E0030DA0 0C080118 */  jal       shim_guMtxF2L
/* 342EE4 E0030DA4 00452821 */   addu     $a1, $v0, $a1
/* 342EE8 E0030DA8 8E240000 */  lw        $a0, ($s1)
/* 342EEC E0030DAC 96C30000 */  lhu       $v1, ($s6)
/* 342EF0 E0030DB0 0080282D */  daddu     $a1, $a0, $zero
/* 342EF4 E0030DB4 24840008 */  addiu     $a0, $a0, 8
/* 342EF8 E0030DB8 3C0ADA38 */  lui       $t2, 0xda38
/* 342EFC E0030DBC 24620001 */  addiu     $v0, $v1, 1
/* 342F00 E0030DC0 3063FFFF */  andi      $v1, $v1, 0xffff
/* 342F04 E0030DC4 00031980 */  sll       $v1, $v1, 6
/* 342F08 E0030DC8 AE240000 */  sw        $a0, ($s1)
/* 342F0C E0030DCC ACAA0000 */  sw        $t2, ($a1)
/* 342F10 E0030DD0 A6C20000 */  sh        $v0, ($s6)
/* 342F14 E0030DD4 3C02800A */  lui       $v0, %hi(gDisplayContext)
/* 342F18 E0030DD8 8C42A674 */  lw        $v0, %lo(gDisplayContext)($v0)
/* 342F1C E0030DDC 00731821 */  addu      $v1, $v1, $s3
/* 342F20 E0030DE0 00431021 */  addu      $v0, $v0, $v1
/* 342F24 E0030DE4 ACA20004 */  sw        $v0, 4($a1)
/* 342F28 E0030DE8 24820008 */  addiu     $v0, $a0, 8
/* 342F2C E0030DEC AE220000 */  sw        $v0, ($s1)
/* 342F30 E0030DF0 3C02DE00 */  lui       $v0, 0xde00
/* 342F34 E0030DF4 AC820000 */  sw        $v0, ($a0)
/* 342F38 E0030DF8 3C020900 */  lui       $v0, 0x900
/* 342F3C E0030DFC 244205E0 */  addiu     $v0, $v0, 0x5e0
/* 342F40 E0030E00 AC820004 */  sw        $v0, 4($a0)
/* 342F44 E0030E04 24820010 */  addiu     $v0, $a0, 0x10
/* 342F48 E0030E08 AE220000 */  sw        $v0, ($s1)
/* 342F4C E0030E0C 8FAA00A0 */  lw        $t2, 0xa0($sp)
/* 342F50 E0030E10 26B50001 */  addiu     $s5, $s5, 1
/* 342F54 E0030E14 AC8A0008 */  sw        $t2, 8($a0)
/* 342F58 E0030E18 240A0040 */  addiu     $t2, $zero, 0x40
/* 342F5C E0030E1C AC8A000C */  sw        $t2, 0xc($a0)
/* 342F60 E0030E20 8FAA00A0 */  lw        $t2, 0xa0($sp)
/* 342F64 E0030E24 26520003 */  addiu     $s2, $s2, 3
/* 342F68 E0030E28 AC8A0010 */  sw        $t2, 0x10($a0)
/* 342F6C E0030E2C 240A0040 */  addiu     $t2, $zero, 0x40
/* 342F70 E0030E30 AC8A0014 */  sw        $t2, 0x14($a0)
/* 342F74 E0030E34 8FAA00E0 */  lw        $t2, 0xe0($sp)
/* 342F78 E0030E38 26100030 */  addiu     $s0, $s0, 0x30
/* 342F7C E0030E3C 8D420008 */  lw        $v0, 8($t2)
/* 342F80 E0030E40 24840018 */  addiu     $a0, $a0, 0x18
/* 342F84 E0030E44 02A2102A */  slt       $v0, $s5, $v0
/* 342F88 E0030E48 1440FF58 */  bnez      $v0, .LE0030BAC
/* 342F8C E0030E4C AE240000 */   sw       $a0, ($s1)
.LE0030E50:
/* 342F90 E0030E50 8FBF00CC */  lw        $ra, 0xcc($sp)
/* 342F94 E0030E54 8FBE00C8 */  lw        $fp, 0xc8($sp)
/* 342F98 E0030E58 8FB700C4 */  lw        $s7, 0xc4($sp)
/* 342F9C E0030E5C 8FB600C0 */  lw        $s6, 0xc0($sp)
/* 342FA0 E0030E60 8FB500BC */  lw        $s5, 0xbc($sp)
/* 342FA4 E0030E64 8FB400B8 */  lw        $s4, 0xb8($sp)
/* 342FA8 E0030E68 8FB300B4 */  lw        $s3, 0xb4($sp)
/* 342FAC E0030E6C 8FB200B0 */  lw        $s2, 0xb0($sp)
/* 342FB0 E0030E70 8FB100AC */  lw        $s1, 0xac($sp)
/* 342FB4 E0030E74 8FB000A8 */  lw        $s0, 0xa8($sp)
/* 342FB8 E0030E78 D7B600D8 */  ldc1      $f22, 0xd8($sp)
/* 342FBC E0030E7C D7B400D0 */  ldc1      $f20, 0xd0($sp)
/* 342FC0 E0030E80 03E00008 */  jr        $ra
/* 342FC4 E0030E84 27BD00E0 */   addiu    $sp, $sp, 0xe0
/* 342FC8 E0030E88 00000000 */  nop
/* 342FCC E0030E8C 00000000 */  nop
