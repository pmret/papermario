.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8006A9E0
/* 45DE0 8006A9E0 3C1A800B */  lui       $k0, %hi(D_800B0CE8)
/* 45DE4 8006A9E4 275A0CE8 */  addiu     $k0, $k0, %lo(D_800B0CE8)
/* 45DE8 8006A9E8 FF410020 */  sd        $at, 0x20($k0)
/* 45DEC 8006A9EC 401B6000 */  mfc0      $k1, $12
/* 45DF0 8006A9F0 AF5B0118 */  sw        $k1, 0x118($k0)
/* 45DF4 8006A9F4 2401FFFC */  addiu     $at, $zero, -4
/* 45DF8 8006A9F8 0361D824 */  and       $k1, $k1, $at
/* 45DFC 8006A9FC 409B6000 */  mtc0      $k1, $12
/* 45E00 8006AA00 FF480058 */  sd        $t0, 0x58($k0)
/* 45E04 8006AA04 FF490060 */  sd        $t1, 0x60($k0)
/* 45E08 8006AA08 FF4A0068 */  sd        $t2, 0x68($k0)
/* 45E0C 8006AA0C AF400018 */  sw        $zero, 0x18($k0)
/* 45E10 8006AA10 40086800 */  mfc0      $t0, $13
/* 45E14 8006AA14 03404021 */  addu      $t0, $k0, $zero
/* 45E18 8006AA18 3C1A8009 */  lui       $k0, %hi(D_80094640)
/* 45E1C 8006AA1C 8F5A4640 */  lw        $k0, %lo(D_80094640)($k0)
/* 45E20 8006AA20 DD090020 */  ld        $t1, 0x20($t0)
/* 45E24 8006AA24 FF490020 */  sd        $t1, 0x20($k0)
/* 45E28 8006AA28 DD090118 */  ld        $t1, 0x118($t0)
/* 45E2C 8006AA2C FF490118 */  sd        $t1, 0x118($k0)
/* 45E30 8006AA30 DD090058 */  ld        $t1, 0x58($t0)
/* 45E34 8006AA34 FF490058 */  sd        $t1, 0x58($k0)
/* 45E38 8006AA38 DD090060 */  ld        $t1, 0x60($t0)
/* 45E3C 8006AA3C FF490060 */  sd        $t1, 0x60($k0)
/* 45E40 8006AA40 DD090068 */  ld        $t1, 0x68($t0)
/* 45E44 8006AA44 FF490068 */  sd        $t1, 0x68($k0)
/* 45E48 8006AA48 FF420028 */  sd        $v0, 0x28($k0)
/* 45E4C 8006AA4C FF430030 */  sd        $v1, 0x30($k0)
/* 45E50 8006AA50 FF440038 */  sd        $a0, 0x38($k0)
/* 45E54 8006AA54 FF450040 */  sd        $a1, 0x40($k0)
/* 45E58 8006AA58 FF460048 */  sd        $a2, 0x48($k0)
/* 45E5C 8006AA5C FF470050 */  sd        $a3, 0x50($k0)
/* 45E60 8006AA60 FF4B0070 */  sd        $t3, 0x70($k0)
/* 45E64 8006AA64 FF4C0078 */  sd        $t4, 0x78($k0)
/* 45E68 8006AA68 FF4D0080 */  sd        $t5, 0x80($k0)
/* 45E6C 8006AA6C FF4E0088 */  sd        $t6, 0x88($k0)
/* 45E70 8006AA70 FF4F0090 */  sd        $t7, 0x90($k0)
/* 45E74 8006AA74 FF500098 */  sd        $s0, 0x98($k0)
/* 45E78 8006AA78 FF5100A0 */  sd        $s1, 0xa0($k0)
/* 45E7C 8006AA7C FF5200A8 */  sd        $s2, 0xa8($k0)
/* 45E80 8006AA80 FF5300B0 */  sd        $s3, 0xb0($k0)
/* 45E84 8006AA84 FF5400B8 */  sd        $s4, 0xb8($k0)
/* 45E88 8006AA88 FF5500C0 */  sd        $s5, 0xc0($k0)
/* 45E8C 8006AA8C FF5600C8 */  sd        $s6, 0xc8($k0)
/* 45E90 8006AA90 FF5700D0 */  sd        $s7, 0xd0($k0)
/* 45E94 8006AA94 FF5800D8 */  sd        $t8, 0xd8($k0)
/* 45E98 8006AA98 FF5900E0 */  sd        $t9, 0xe0($k0)
/* 45E9C 8006AA9C FF5C00E8 */  sd        $gp, 0xe8($k0)
/* 45EA0 8006AAA0 FF5D00F0 */  sd        $sp, 0xf0($k0)
/* 45EA4 8006AAA4 FF5E00F8 */  sd        $fp, 0xf8($k0)
/* 45EA8 8006AAA8 FF5F0100 */  sd        $ra, 0x100($k0)
/* 45EAC 8006AAAC 00004012 */  mflo      $t0
/* 45EB0 8006AAB0 FF480108 */  sd        $t0, 0x108($k0)
/* 45EB4 8006AAB4 00004010 */  mfhi      $t0
/* 45EB8 8006AAB8 FF480110 */  sd        $t0, 0x110($k0)
/* 45EBC 8006AABC 8F5B0118 */  lw        $k1, 0x118($k0)
/* 45EC0 8006AAC0 3369FF00 */  andi      $t1, $k1, 0xff00
/* 45EC4 8006AAC4 11200013 */  beqz      $t1, .L8006AB14
/* 45EC8 8006AAC8 00000000 */   nop
/* 45ECC 8006AACC 3C088009 */  lui       $t0, %hi(D_80095890)
/* 45ED0 8006AAD0 25085890 */  addiu     $t0, $t0, %lo(D_80095890)
/* 45ED4 8006AAD4 8D080000 */  lw        $t0, ($t0)
/* 45ED8 8006AAD8 2401FFFF */  addiu     $at, $zero, -1
/* 45EDC 8006AADC 01015026 */  xor       $t2, $t0, $at
/* 45EE0 8006AAE0 314AFF00 */  andi      $t2, $t2, 0xff00
/* 45EE4 8006AAE4 012A6025 */  or        $t4, $t1, $t2
/* 45EE8 8006AAE8 3C01FFFF */  lui       $at, 0xffff
/* 45EEC 8006AAEC 342100FF */  ori       $at, $at, 0xff
/* 45EF0 8006AAF0 03615824 */  and       $t3, $k1, $at
/* 45EF4 8006AAF4 016C5825 */  or        $t3, $t3, $t4
/* 45EF8 8006AAF8 AF4B0118 */  sw        $t3, 0x118($k0)
/* 45EFC 8006AAFC 3108FF00 */  andi      $t0, $t0, 0xff00
/* 45F00 8006AB00 01284824 */  and       $t1, $t1, $t0
/* 45F04 8006AB04 3C01FFFF */  lui       $at, 0xffff
/* 45F08 8006AB08 342100FF */  ori       $at, $at, 0xff
/* 45F0C 8006AB0C 0361D824 */  and       $k1, $k1, $at
/* 45F10 8006AB10 0369D825 */  or        $k1, $k1, $t1
.L8006AB14:
/* 45F14 8006AB14 3C09A430 */  lui       $t1, %hi(D_A430000C)
/* 45F18 8006AB18 8D29000C */  lw        $t1, %lo(D_A430000C)($t1)
/* 45F1C 8006AB1C 1120000B */  beqz      $t1, .L8006AB4C
/* 45F20 8006AB20 00000000 */   nop
/* 45F24 8006AB24 3C088009 */  lui       $t0, %hi(D_80095890)
/* 45F28 8006AB28 25085890 */  addiu     $t0, $t0, %lo(D_80095890)
/* 45F2C 8006AB2C 8D080000 */  lw        $t0, ($t0)
/* 45F30 8006AB30 00084402 */  srl       $t0, $t0, 0x10
/* 45F34 8006AB34 2401FFFF */  addiu     $at, $zero, -1
/* 45F38 8006AB38 01014026 */  xor       $t0, $t0, $at
/* 45F3C 8006AB3C 3108003F */  andi      $t0, $t0, 0x3f
/* 45F40 8006AB40 8F4C0128 */  lw        $t4, 0x128($k0)
/* 45F44 8006AB44 010C4024 */  and       $t0, $t0, $t4
/* 45F48 8006AB48 01284825 */  or        $t1, $t1, $t0
.L8006AB4C:
/* 45F4C 8006AB4C AF490128 */  sw        $t1, 0x128($k0)
/* 45F50 8006AB50 40087000 */  mfc0      $t0, $14
/* 45F54 8006AB54 AF48011C */  sw        $t0, 0x11c($k0)
/* 45F58 8006AB58 8F480018 */  lw        $t0, 0x18($k0)
/* 45F5C 8006AB5C 11000014 */  beqz      $t0, .L8006ABB0
/* 45F60 8006AB60 00000000 */   nop
/* 45F64 8006AB64 4448F800 */  cfc1      $t0, $31
/* 45F68 8006AB68 00000000 */  nop
/* 45F6C 8006AB6C AF48012C */  sw        $t0, 0x12c($k0)
/* 45F70 8006AB70 F7400130 */  sdc1      $f0, 0x130($k0)
/* 45F74 8006AB74 F7420138 */  sdc1      $f2, 0x138($k0)
/* 45F78 8006AB78 F7440140 */  sdc1      $f4, 0x140($k0)
/* 45F7C 8006AB7C F7460148 */  sdc1      $f6, 0x148($k0)
/* 45F80 8006AB80 F7480150 */  sdc1      $f8, 0x150($k0)
/* 45F84 8006AB84 F74A0158 */  sdc1      $f10, 0x158($k0)
/* 45F88 8006AB88 F74C0160 */  sdc1      $f12, 0x160($k0)
/* 45F8C 8006AB8C F74E0168 */  sdc1      $f14, 0x168($k0)
/* 45F90 8006AB90 F7500170 */  sdc1      $f16, 0x170($k0)
/* 45F94 8006AB94 F7520178 */  sdc1      $f18, 0x178($k0)
/* 45F98 8006AB98 F7540180 */  sdc1      $f20, 0x180($k0)
/* 45F9C 8006AB9C F7560188 */  sdc1      $f22, 0x188($k0)
/* 45FA0 8006ABA0 F7580190 */  sdc1      $f24, 0x190($k0)
/* 45FA4 8006ABA4 F75A0198 */  sdc1      $f26, 0x198($k0)
/* 45FA8 8006ABA8 F75C01A0 */  sdc1      $f28, 0x1a0($k0)
/* 45FAC 8006ABAC F75E01A8 */  sdc1      $f30, 0x1a8($k0)
.L8006ABB0:
/* 45FB0 8006ABB0 40086800 */  mfc0      $t0, $13
/* 45FB4 8006ABB4 AF480120 */  sw        $t0, 0x120($k0)
/* 45FB8 8006ABB8 24090002 */  addiu     $t1, $zero, 2
/* 45FBC 8006ABBC A7490010 */  sh        $t1, 0x10($k0)
/* 45FC0 8006ABC0 3109007C */  andi      $t1, $t0, 0x7c
/* 45FC4 8006ABC4 240A0024 */  addiu     $t2, $zero, 0x24
/* 45FC8 8006ABC8 112A00BF */  beq       $t1, $t2, .L8006AEC8
/* 45FCC 8006ABCC 00000000 */   nop
/* 45FD0 8006ABD0 240A002C */  addiu     $t2, $zero, 0x2c
/* 45FD4 8006ABD4 112A0110 */  beq       $t1, $t2, .L8006B018
/* 45FD8 8006ABD8 00000000 */   nop
/* 45FDC 8006ABDC 240A0000 */  addiu     $t2, $zero, 0
/* 45FE0 8006ABE0 152A00D2 */  bne       $t1, $t2, .L8006AF2C
/* 45FE4 8006ABE4 00000000 */   nop
/* 45FE8 8006ABE8 03688024 */  and       $s0, $k1, $t0
.L8006ABEC:
/* 45FEC 8006ABEC 3209FF00 */  andi      $t1, $s0, 0xff00
/* 45FF0 8006ABF0 00095302 */  srl       $t2, $t1, 0xc
/* 45FF4 8006ABF4 15400003 */  bnez      $t2, .L8006AC04
/* 45FF8 8006ABF8 00000000 */   nop
/* 45FFC 8006ABFC 00095202 */  srl       $t2, $t1, 8
/* 46000 8006AC00 214A0010 */  addi      $t2, $t2, 0x10
.L8006AC04:
/* 46004 8006AC04 3C01800A */  lui       $at, %hi(D_80099D60)
/* 46008 8006AC08 002A0821 */  addu      $at, $at, $t2
/* 4600C 8006AC0C 902A9D60 */  lbu       $t2, %lo(D_80099D60)($at)
/* 46010 8006AC10 3C01800A */  lui       $at, %hi(D_80099D80)
/* 46014 8006AC14 002A0821 */  addu      $at, $at, $t2
/* 46018 8006AC18 8C2A9D80 */  lw        $t2, %lo(D_80099D80)($at)
/* 4601C 8006AC1C 01400008 */  jr        $t2
/* 46020 8006AC20 00000000 */   nop
/* 46024 8006AC24 2401DFFF */  addiu     $at, $zero, -0x2001
/* 46028 8006AC28 1000FFF0 */  b         .L8006ABEC
/* 4602C 8006AC2C 02018024 */   and      $s0, $s0, $at
/* 46030 8006AC30 2401BFFF */  addiu     $at, $zero, -0x4001
/* 46034 8006AC34 1000FFED */  b         .L8006ABEC
/* 46038 8006AC38 02018024 */   and      $s0, $s0, $at
/* 4603C 8006AC3C 40095800 */  mfc0      $t1, $11
/* 46040 8006AC40 40895800 */  mtc0      $t1, $11
/* 46044 8006AC44 24040018 */  addiu     $a0, $zero, 0x18
/* 46048 8006AC48 0C01ABD7 */  jal       func_8006AF5C
/* 4604C 8006AC4C 00000000 */   nop
/* 46050 8006AC50 3C01FFFF */  lui       $at, 0xffff
/* 46054 8006AC54 34217FFF */  ori       $at, $at, 0x7fff
/* 46058 8006AC58 1000FFE4 */  b         .L8006ABEC
/* 4605C 8006AC5C 02018024 */   and      $s0, $s0, $at
/* 46060 8006AC60 2401F7FF */  addiu     $at, $zero, -0x801
/* 46064 8006AC64 02018024 */  and       $s0, $s0, $at
/* 46068 8006AC68 3C098009 */  lui       $t1, %hi(D_800958A0)
/* 4606C 8006AC6C 252958A0 */  addiu     $t1, $t1, %lo(D_800958A0)
/* 46070 8006AC70 21290008 */  addi      $t1, $t1, 8
/* 46074 8006AC74 8D2A0000 */  lw        $t2, ($t1)
/* 46078 8006AC78 11400007 */  beqz      $t2, .L8006AC98
/* 4607C 8006AC7C 00000000 */   nop
/* 46080 8006AC80 0140F809 */  jalr      $t2
/* 46084 8006AC84 8D3D0004 */   lw       $sp, 4($t1)
/* 46088 8006AC88 10400003 */  beqz      $v0, .L8006AC98
/* 4608C 8006AC8C 00000000 */   nop
/* 46090 8006AC90 10000093 */  b         .L8006AEE0
/* 46094 8006AC94 00000000 */   nop
.L8006AC98:
/* 46098 8006AC98 0C01ABD7 */  jal       func_8006AF5C
/* 4609C 8006AC9C 24040010 */   addiu    $a0, $zero, 0x10
/* 460A0 8006ACA0 1000FFD2 */  b         .L8006ABEC
/* 460A4 8006ACA4 00000000 */   nop
/* 460A8 8006ACA8 3C11A430 */  lui       $s1, %hi(D_A4300008)
/* 460AC 8006ACAC 8E310008 */  lw        $s1, %lo(D_A4300008)($s1)
/* 460B0 8006ACB0 3C088009 */  lui       $t0, %hi(D_80095890)
/* 460B4 8006ACB4 25085890 */  addiu     $t0, $t0, %lo(D_80095890)
/* 460B8 8006ACB8 8D080000 */  lw        $t0, ($t0)
/* 460BC 8006ACBC 00084402 */  srl       $t0, $t0, 0x10
/* 460C0 8006ACC0 02288824 */  and       $s1, $s1, $t0
/* 460C4 8006ACC4 32290001 */  andi      $t1, $s1, 1
/* 460C8 8006ACC8 11200014 */  beqz      $t1, .L8006AD1C
/* 460CC 8006ACCC 00000000 */   nop
/* 460D0 8006ACD0 3231003E */  andi      $s1, $s1, 0x3e
/* 460D4 8006ACD4 3C0CA404 */  lui       $t4, %hi(D_A4040010)
/* 460D8 8006ACD8 8D8C0010 */  lw        $t4, %lo(D_A4040010)($t4)
/* 460DC 8006ACDC 34098008 */  ori       $t1, $zero, 0x8008
/* 460E0 8006ACE0 3C01A404 */  lui       $at, %hi(D_A4040010)
/* 460E4 8006ACE4 AC290010 */  sw        $t1, %lo(D_A4040010)($at)
/* 460E8 8006ACE8 318C0300 */  andi      $t4, $t4, 0x300
/* 460EC 8006ACEC 11800007 */  beqz      $t4, .L8006AD0C
/* 460F0 8006ACF0 00000000 */   nop
/* 460F4 8006ACF4 0C01ABD7 */  jal       func_8006AF5C
/* 460F8 8006ACF8 24040020 */   addiu    $a0, $zero, 0x20
/* 460FC 8006ACFC 12200044 */  beqz      $s1, .L8006AE10
/* 46100 8006AD00 00000000 */   nop
/* 46104 8006AD04 10000005 */  b         .L8006AD1C
/* 46108 8006AD08 00000000 */   nop
.L8006AD0C:
/* 4610C 8006AD0C 0C01ABD7 */  jal       func_8006AF5C
/* 46110 8006AD10 24040058 */   addiu    $a0, $zero, 0x58
/* 46114 8006AD14 1220003E */  beqz      $s1, .L8006AE10
/* 46118 8006AD18 00000000 */   nop
.L8006AD1C:
/* 4611C 8006AD1C 32290008 */  andi      $t1, $s1, 8
/* 46120 8006AD20 11200008 */  beqz      $t1, .L8006AD44
/* 46124 8006AD24 00000000 */   nop
/* 46128 8006AD28 32310037 */  andi      $s1, $s1, 0x37
/* 4612C 8006AD2C 3C01A440 */  lui       $at, %hi(D_A4400010)
/* 46130 8006AD30 AC200010 */  sw        $zero, %lo(D_A4400010)($at)
/* 46134 8006AD34 0C01ABD7 */  jal       func_8006AF5C
/* 46138 8006AD38 24040038 */   addiu    $a0, $zero, 0x38
/* 4613C 8006AD3C 12200034 */  beqz      $s1, .L8006AE10
/* 46140 8006AD40 00000000 */   nop
.L8006AD44:
/* 46144 8006AD44 32290004 */  andi      $t1, $s1, 4
/* 46148 8006AD48 11200009 */  beqz      $t1, .L8006AD70
/* 4614C 8006AD4C 00000000 */   nop
/* 46150 8006AD50 3231003B */  andi      $s1, $s1, 0x3b
/* 46154 8006AD54 24090001 */  addiu     $t1, $zero, 1
/* 46158 8006AD58 3C01A450 */  lui       $at, %hi(D_A450000C)
/* 4615C 8006AD5C AC29000C */  sw        $t1, %lo(D_A450000C)($at)
/* 46160 8006AD60 0C01ABD7 */  jal       func_8006AF5C
/* 46164 8006AD64 24040030 */   addiu    $a0, $zero, 0x30
/* 46168 8006AD68 12200029 */  beqz      $s1, .L8006AE10
/* 4616C 8006AD6C 00000000 */   nop
.L8006AD70:
/* 46170 8006AD70 32290002 */  andi      $t1, $s1, 2
/* 46174 8006AD74 11200008 */  beqz      $t1, .L8006AD98
/* 46178 8006AD78 00000000 */   nop
/* 4617C 8006AD7C 3231003D */  andi      $s1, $s1, 0x3d
/* 46180 8006AD80 3C01A480 */  lui       $at, %hi(D_A4800018)
/* 46184 8006AD84 AC200018 */  sw        $zero, %lo(D_A4800018)($at)
/* 46188 8006AD88 0C01ABD7 */  jal       func_8006AF5C
/* 4618C 8006AD8C 24040028 */   addiu    $a0, $zero, 0x28
/* 46190 8006AD90 1220001F */  beqz      $s1, .L8006AE10
/* 46194 8006AD94 00000000 */   nop
.L8006AD98:
/* 46198 8006AD98 32290010 */  andi      $t1, $s1, 0x10
/* 4619C 8006AD9C 11200013 */  beqz      $t1, .L8006ADEC
/* 461A0 8006ADA0 00000000 */   nop
/* 461A4 8006ADA4 3231002F */  andi      $s1, $s1, 0x2f
/* 461A8 8006ADA8 24090002 */  addiu     $t1, $zero, 2
/* 461AC 8006ADAC 3C01A460 */  lui       $at, %hi(D_A4600010)
/* 461B0 8006ADB0 AC290010 */  sw        $t1, %lo(D_A4600010)($at)
/* 461B4 8006ADB4 3C098009 */  lui       $t1, %hi(D_800958C8)
/* 461B8 8006ADB8 252958C8 */  addiu     $t1, $t1, %lo(D_800958C8)
/* 461BC 8006ADBC 8D2A0000 */  lw        $t2, ($t1)
/* 461C0 8006ADC0 11400006 */  beqz      $t2, .L8006ADDC
/* 461C4 8006ADC4 00000000 */   nop
/* 461C8 8006ADC8 8D3D0004 */  lw        $sp, 4($t1)
/* 461CC 8006ADCC 0140F809 */  jalr      $t2
/* 461D0 8006ADD0 00402021 */   addu     $a0, $v0, $zero
/* 461D4 8006ADD4 14400003 */  bnez      $v0, .L8006ADE4
/* 461D8 8006ADD8 00000000 */   nop
.L8006ADDC:
/* 461DC 8006ADDC 0C01ABD7 */  jal       func_8006AF5C
/* 461E0 8006ADE0 24040040 */   addiu    $a0, $zero, 0x40
.L8006ADE4:
/* 461E4 8006ADE4 1220000A */  beqz      $s1, .L8006AE10
/* 461E8 8006ADE8 00000000 */   nop
.L8006ADEC:
/* 461EC 8006ADEC 32290020 */  andi      $t1, $s1, 0x20
/* 461F0 8006ADF0 11200007 */  beqz      $t1, .L8006AE10
/* 461F4 8006ADF4 00000000 */   nop
/* 461F8 8006ADF8 3231001F */  andi      $s1, $s1, 0x1f
/* 461FC 8006ADFC 24090800 */  addiu     $t1, $zero, 0x800
/* 46200 8006AE00 3C01A430 */  lui       $at, 0xa430
/* 46204 8006AE04 AC290000 */  sw        $t1, ($at)
/* 46208 8006AE08 0C01ABD7 */  jal       func_8006AF5C
/* 4620C 8006AE0C 24040048 */   addiu    $a0, $zero, 0x48
.L8006AE10:
/* 46210 8006AE10 2401FBFF */  addiu     $at, $zero, -0x401
/* 46214 8006AE14 1000FF75 */  b         .L8006ABEC
/* 46218 8006AE18 02018024 */   and      $s0, $s0, $at
/* 4621C 8006AE1C 8F5B0118 */  lw        $k1, 0x118($k0)
/* 46220 8006AE20 2401EFFF */  addiu     $at, $zero, -0x1001
/* 46224 8006AE24 0361D824 */  and       $k1, $k1, $at
/* 46228 8006AE28 AF5B0118 */  sw        $k1, 0x118($k0)
/* 4622C 8006AE2C 3C098009 */  lui       $t1, %hi(D_8009588C)
/* 46230 8006AE30 2529588C */  addiu     $t1, $t1, %lo(D_8009588C)
/* 46234 8006AE34 8D2A0000 */  lw        $t2, ($t1)
/* 46238 8006AE38 11400004 */  beqz      $t2, .L8006AE4C
/* 4623C 8006AE3C 00000000 */   nop
/* 46240 8006AE40 2401EFFF */  addiu     $at, $zero, -0x1001
/* 46244 8006AE44 10000026 */  b         .L8006AEE0
/* 46248 8006AE48 02018024 */   and      $s0, $s0, $at
.L8006AE4C:
/* 4624C 8006AE4C 240A0001 */  addiu     $t2, $zero, 1
/* 46250 8006AE50 AD2A0000 */  sw        $t2, ($t1)
/* 46254 8006AE54 0C01ABD7 */  jal       func_8006AF5C
/* 46258 8006AE58 24040070 */   addiu    $a0, $zero, 0x70
/* 4625C 8006AE5C 2401EFFF */  addiu     $at, $zero, -0x1001
/* 46260 8006AE60 02018024 */  and       $s0, $s0, $at
/* 46264 8006AE64 3C0A8009 */  lui       $t2, %hi(D_80094638)
/* 46268 8006AE68 8D4A4638 */  lw        $t2, %lo(D_80094638)($t2)
/* 4626C 8006AE6C 8D5B0118 */  lw        $k1, 0x118($t2)
/* 46270 8006AE70 2401EFFF */  addiu     $at, $zero, -0x1001
/* 46274 8006AE74 0361D824 */  and       $k1, $k1, $at
/* 46278 8006AE78 10000019 */  b         .L8006AEE0
/* 4627C 8006AE7C AD5B0118 */   sw       $k1, 0x118($t2)
/* 46280 8006AE80 2401FDFF */  addiu     $at, $zero, -0x201
/* 46284 8006AE84 01014024 */  and       $t0, $t0, $at
/* 46288 8006AE88 40886800 */  mtc0      $t0, $13
/* 4628C 8006AE8C 24040008 */  addiu     $a0, $zero, 8
/* 46290 8006AE90 0C01ABD7 */  jal       func_8006AF5C
/* 46294 8006AE94 00000000 */   nop
/* 46298 8006AE98 2401FDFF */  addiu     $at, $zero, -0x201
/* 4629C 8006AE9C 1000FF53 */  b         .L8006ABEC
/* 462A0 8006AEA0 02018024 */   and      $s0, $s0, $at
/* 462A4 8006AEA4 2401FEFF */  addiu     $at, $zero, -0x101
/* 462A8 8006AEA8 01014024 */  and       $t0, $t0, $at
/* 462AC 8006AEAC 40886800 */  mtc0      $t0, $13
/* 462B0 8006AEB0 24040000 */  addiu     $a0, $zero, 0
/* 462B4 8006AEB4 0C01ABD7 */  jal       func_8006AF5C
/* 462B8 8006AEB8 00000000 */   nop
/* 462BC 8006AEBC 2401FEFF */  addiu     $at, $zero, -0x101
/* 462C0 8006AEC0 1000FF4A */  b         .L8006ABEC
/* 462C4 8006AEC4 02018024 */   and      $s0, $s0, $at
.L8006AEC8:
/* 462C8 8006AEC8 24090001 */  addiu     $t1, $zero, 1
/* 462CC 8006AECC A7490012 */  sh        $t1, 0x12($k0)
/* 462D0 8006AED0 0C01ABD7 */  jal       func_8006AF5C
/* 462D4 8006AED4 24040050 */   addiu    $a0, $zero, 0x50
/* 462D8 8006AED8 10000001 */  b         .L8006AEE0
/* 462DC 8006AEDC 00000000 */   nop
.L8006AEE0:
/* 462E0 8006AEE0 8F490004 */  lw        $t1, 4($k0)
/* 462E4 8006AEE4 3C0A8009 */  lui       $t2, %hi(D_80094638)
/* 462E8 8006AEE8 8D4A4638 */  lw        $t2, %lo(D_80094638)($t2)
/* 462EC 8006AEEC 8D4B0004 */  lw        $t3, 4($t2)
/* 462F0 8006AEF0 012B082A */  slt       $at, $t1, $t3
/* 462F4 8006AEF4 10200007 */  beqz      $at, .L8006AF14
/* 462F8 8006AEF8 00000000 */   nop
/* 462FC 8006AEFC 03402821 */  addu      $a1, $k0, $zero
/* 46300 8006AF00 3C048009 */  lui       $a0, %hi(D_80094638)
/* 46304 8006AF04 0C01AC55 */  jal       func_8006B154
/* 46308 8006AF08 24844638 */   addiu    $a0, $a0, %lo(D_80094638)
/* 4630C 8006AF0C 0801AC6D */  j         .L8006B1B4
/* 46310 8006AF10 00000000 */   nop
.L8006AF14:
/* 46314 8006AF14 3C098009 */  lui       $t1, %hi(D_80094638)
/* 46318 8006AF18 25294638 */  addiu     $t1, $t1, %lo(D_80094638)
/* 4631C 8006AF1C 8D2A0000 */  lw        $t2, ($t1)
/* 46320 8006AF20 AF4A0000 */  sw        $t2, ($k0)
/* 46324 8006AF24 0801AC6D */  j         .L8006B1B4
/* 46328 8006AF28 AD3A0000 */   sw       $k0, ($t1)
.L8006AF2C:
/* 4632C 8006AF2C 3C018009 */  lui       $at, %hi(D_80094644)
/* 46330 8006AF30 AC3A4644 */  sw        $k0, %lo(D_80094644)($at)
/* 46334 8006AF34 24090001 */  addiu     $t1, $zero, 1
/* 46338 8006AF38 A7490010 */  sh        $t1, 0x10($k0)
/* 4633C 8006AF3C 24090002 */  addiu     $t1, $zero, 2
/* 46340 8006AF40 A7490012 */  sh        $t1, 0x12($k0)
/* 46344 8006AF44 400A4000 */  mfc0      $t2, $8
/* 46348 8006AF48 AF4A0124 */  sw        $t2, 0x124($k0)
/* 4634C 8006AF4C 0C01ABD7 */  jal       func_8006AF5C
/* 46350 8006AF50 24040060 */   addiu    $a0, $zero, 0x60
/* 46354 8006AF54 0801AC6D */  j         .L8006B1B4
/* 46358 8006AF58 00000000 */   nop
