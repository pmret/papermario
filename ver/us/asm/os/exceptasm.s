.include "macro.inc"

# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64     # allow use of 64-bit general purpose registers

.section .rodata

dlabel jtbl_80099D80
.word 0x141818, 0x1C1C1C1C, 0x20202020, 0x20202020, 0x40808, 0xC0C0C0C, 0x10101010, 0x10101010

dlabel jtbl_80099DA0
.word .L8006AF00_46300, .L8006AEC4_462C4, .L8006AEA0_462A0, .L8006ACC8_460C8, .L8006AC80_46080, .L8006AE3C_4623C, .L8006AC44_46044, .L8006AC50_46050, .L8006AC5C_4605C, 0, 0, 0

.section .text, "ax"

glabel __osExceptionPreamble
/* 45DF0 8006A9F0 3C1A8007 */  lui       $k0, %hi(__osException)
/* 45DF4 8006A9F4 275AAA00 */  addiu     $k0, $k0, %lo(__osException)
/* 45DF8 8006A9F8 03400008 */  jr        $k0
/* 45DFC 8006A9FC 00000000 */   nop

glabel __osException
/* 45E00 8006AA00 3C1A800B */  lui       $k0, %hi(__osThreadSave)
/* 45E04 8006AA04 275A0D08 */  addiu     $k0, $k0, %lo(__osThreadSave)
/* 45E08 8006AA08 FF410020 */  sd        $at, 0x20($k0)
/* 45E0C 8006AA0C 401B6000 */  mfc0      $k1, $12
/* 45E10 8006AA10 AF5B0118 */  sw        $k1, 0x118($k0)
/* 45E14 8006AA14 2401FFFC */  addiu     $at, $zero, -4
/* 45E18 8006AA18 0361D824 */  and       $k1, $k1, $at
/* 45E1C 8006AA1C 409B6000 */  mtc0      $k1, $12
/* 45E20 8006AA20 FF480058 */  sd        $t0, 0x58($k0)
/* 45E24 8006AA24 FF490060 */  sd        $t1, 0x60($k0)
/* 45E28 8006AA28 FF4A0068 */  sd        $t2, 0x68($k0)
/* 45E2C 8006AA2C AF400018 */  sw        $zero, 0x18($k0)
/* 45E30 8006AA30 40086800 */  mfc0      $t0, $13

glabel func_8006AA34
/* 45E34 8006AA34 03404021 */  addu      $t0, $k0, $zero
/* 45E38 8006AA38 3C1A8009 */  lui       $k0, %hi(__osRunningThread)
/* 45E3C 8006AA3C 8F5A4660 */  lw        $k0, %lo(__osRunningThread)($k0)
/* 45E40 8006AA40 DD090020 */  ld        $t1, 0x20($t0)
/* 45E44 8006AA44 FF490020 */  sd        $t1, 0x20($k0)
/* 45E48 8006AA48 DD090118 */  ld        $t1, 0x118($t0)
/* 45E4C 8006AA4C FF490118 */  sd        $t1, 0x118($k0)
/* 45E50 8006AA50 DD090058 */  ld        $t1, 0x58($t0)
/* 45E54 8006AA54 FF490058 */  sd        $t1, 0x58($k0)
/* 45E58 8006AA58 DD090060 */  ld        $t1, 0x60($t0)
/* 45E5C 8006AA5C FF490060 */  sd        $t1, 0x60($k0)
/* 45E60 8006AA60 DD090068 */  ld        $t1, 0x68($t0)
/* 45E64 8006AA64 FF490068 */  sd        $t1, 0x68($k0)
/* 45E68 8006AA68 FF420028 */  sd        $v0, 0x28($k0)
/* 45E6C 8006AA6C FF430030 */  sd        $v1, 0x30($k0)
/* 45E70 8006AA70 FF440038 */  sd        $a0, 0x38($k0)
/* 45E74 8006AA74 FF450040 */  sd        $a1, 0x40($k0)
/* 45E78 8006AA78 FF460048 */  sd        $a2, 0x48($k0)
/* 45E7C 8006AA7C FF470050 */  sd        $a3, 0x50($k0)
/* 45E80 8006AA80 FF4B0070 */  sd        $t3, 0x70($k0)
/* 45E84 8006AA84 FF4C0078 */  sd        $t4, 0x78($k0)
/* 45E88 8006AA88 FF4D0080 */  sd        $t5, 0x80($k0)
/* 45E8C 8006AA8C FF4E0088 */  sd        $t6, 0x88($k0)
/* 45E90 8006AA90 FF4F0090 */  sd        $t7, 0x90($k0)
/* 45E94 8006AA94 FF500098 */  sd        $s0, 0x98($k0)
/* 45E98 8006AA98 FF5100A0 */  sd        $s1, 0xa0($k0)
/* 45E9C 8006AA9C FF5200A8 */  sd        $s2, 0xa8($k0)
/* 45EA0 8006AAA0 FF5300B0 */  sd        $s3, 0xb0($k0)
/* 45EA4 8006AAA4 FF5400B8 */  sd        $s4, 0xb8($k0)
/* 45EA8 8006AAA8 FF5500C0 */  sd        $s5, 0xc0($k0)
/* 45EAC 8006AAAC FF5600C8 */  sd        $s6, 0xc8($k0)
/* 45EB0 8006AAB0 FF5700D0 */  sd        $s7, 0xd0($k0)
/* 45EB4 8006AAB4 FF5800D8 */  sd        $t8, 0xd8($k0)
/* 45EB8 8006AAB8 FF5900E0 */  sd        $t9, 0xe0($k0)
/* 45EBC 8006AABC FF5C00E8 */  sd        $gp, 0xe8($k0)
/* 45EC0 8006AAC0 FF5D00F0 */  sd        $sp, 0xf0($k0)
/* 45EC4 8006AAC4 FF5E00F8 */  sd        $fp, 0xf8($k0)
/* 45EC8 8006AAC8 FF5F0100 */  sd        $ra, 0x100($k0)
/* 45ECC 8006AACC 00004012 */  mflo      $t0
/* 45ED0 8006AAD0 FF480108 */  sd        $t0, 0x108($k0)
/* 45ED4 8006AAD4 00004010 */  mfhi      $t0
/* 45ED8 8006AAD8 FF480110 */  sd        $t0, 0x110($k0)
/* 45EDC 8006AADC 8F5B0118 */  lw        $k1, 0x118($k0)
/* 45EE0 8006AAE0 3369FF00 */  andi      $t1, $k1, 0xff00
/* 45EE4 8006AAE4 11200013 */  beqz      $t1, .L8006AB34
/* 45EE8 8006AAE8 00000000 */   nop
/* 45EEC 8006AAEC 3C088009 */  lui       $t0, %hi(__OSGlobalIntMask)
/* 45EF0 8006AAF0 25085900 */  addiu     $t0, $t0, %lo(__OSGlobalIntMask)
/* 45EF4 8006AAF4 8D080000 */  lw        $t0, ($t0)
/* 45EF8 8006AAF8 2401FFFF */  addiu     $at, $zero, -1
/* 45EFC 8006AAFC 01015026 */  xor       $t2, $t0, $at
/* 45F00 8006AB00 314AFF00 */  andi      $t2, $t2, 0xff00
/* 45F04 8006AB04 012A6025 */  or        $t4, $t1, $t2
/* 45F08 8006AB08 3C01FFFF */  lui       $at, 0xffff
/* 45F0C 8006AB0C 342100FF */  ori       $at, $at, 0xff
/* 45F10 8006AB10 03615824 */  and       $t3, $k1, $at
/* 45F14 8006AB14 016C5825 */  or        $t3, $t3, $t4
/* 45F18 8006AB18 AF4B0118 */  sw        $t3, 0x118($k0)
/* 45F1C 8006AB1C 3108FF00 */  andi      $t0, $t0, 0xff00
/* 45F20 8006AB20 01284824 */  and       $t1, $t1, $t0
/* 45F24 8006AB24 3C01FFFF */  lui       $at, 0xffff
/* 45F28 8006AB28 342100FF */  ori       $at, $at, 0xff
/* 45F2C 8006AB2C 0361D824 */  and       $k1, $k1, $at
/* 45F30 8006AB30 0369D825 */  or        $k1, $k1, $t1
.L8006AB34:
/* 45F34 8006AB34 3C09A430 */  lui       $t1, %hi(D_A430000C)
/* 45F38 8006AB38 8D29000C */  lw        $t1, %lo(D_A430000C)($t1)
/* 45F3C 8006AB3C 1120000B */  beqz      $t1, .L8006AB6C
/* 45F40 8006AB40 00000000 */   nop
/* 45F44 8006AB44 3C088009 */  lui       $t0, %hi(__OSGlobalIntMask)
/* 45F48 8006AB48 25085900 */  addiu     $t0, $t0, %lo(__OSGlobalIntMask)
/* 45F4C 8006AB4C 8D080000 */  lw        $t0, ($t0)
/* 45F50 8006AB50 00084402 */  srl       $t0, $t0, 0x10
/* 45F54 8006AB54 2401FFFF */  addiu     $at, $zero, -1
/* 45F58 8006AB58 01014026 */  xor       $t0, $t0, $at
/* 45F5C 8006AB5C 3108003F */  andi      $t0, $t0, 0x3f
/* 45F60 8006AB60 8F4C0128 */  lw        $t4, 0x128($k0)
/* 45F64 8006AB64 010C4024 */  and       $t0, $t0, $t4
/* 45F68 8006AB68 01284825 */  or        $t1, $t1, $t0
.L8006AB6C:
/* 45F6C 8006AB6C AF490128 */  sw        $t1, 0x128($k0)
/* 45F70 8006AB70 40087000 */  mfc0      $t0, $14
/* 45F74 8006AB74 AF48011C */  sw        $t0, 0x11c($k0)
/* 45F78 8006AB78 8F480018 */  lw        $t0, 0x18($k0)
/* 45F7C 8006AB7C 11000014 */  beqz      $t0, .L8006ABD0
/* 45F80 8006AB80 00000000 */   nop
/* 45F84 8006AB84 4448F800 */  cfc1      $t0, $31
/* 45F88 8006AB88 00000000 */  nop
/* 45F8C 8006AB8C AF48012C */  sw        $t0, 0x12c($k0)
/* 45F90 8006AB90 F7400130 */  sdc1      $f0, 0x130($k0)
/* 45F94 8006AB94 F7420138 */  sdc1      $f2, 0x138($k0)
/* 45F98 8006AB98 F7440140 */  sdc1      $f4, 0x140($k0)
/* 45F9C 8006AB9C F7460148 */  sdc1      $f6, 0x148($k0)
/* 45FA0 8006ABA0 F7480150 */  sdc1      $f8, 0x150($k0)
/* 45FA4 8006ABA4 F74A0158 */  sdc1      $f10, 0x158($k0)
/* 45FA8 8006ABA8 F74C0160 */  sdc1      $f12, 0x160($k0)
/* 45FAC 8006ABAC F74E0168 */  sdc1      $f14, 0x168($k0)
/* 45FB0 8006ABB0 F7500170 */  sdc1      $f16, 0x170($k0)
/* 45FB4 8006ABB4 F7520178 */  sdc1      $f18, 0x178($k0)
/* 45FB8 8006ABB8 F7540180 */  sdc1      $f20, 0x180($k0)
/* 45FBC 8006ABBC F7560188 */  sdc1      $f22, 0x188($k0)
/* 45FC0 8006ABC0 F7580190 */  sdc1      $f24, 0x190($k0)
/* 45FC4 8006ABC4 F75A0198 */  sdc1      $f26, 0x198($k0)
/* 45FC8 8006ABC8 F75C01A0 */  sdc1      $f28, 0x1a0($k0)
/* 45FCC 8006ABCC F75E01A8 */  sdc1      $f30, 0x1a8($k0)
.L8006ABD0:
/* 45FD0 8006ABD0 40086800 */  mfc0      $t0, $13
/* 45FD4 8006ABD4 AF480120 */  sw        $t0, 0x120($k0)
/* 45FD8 8006ABD8 24090002 */  addiu     $t1, $zero, 2
/* 45FDC 8006ABDC A7490010 */  sh        $t1, 0x10($k0)
/* 45FE0 8006ABE0 3109007C */  andi      $t1, $t0, 0x7c
/* 45FE4 8006ABE4 240A0024 */  addiu     $t2, $zero, 0x24
/* 45FE8 8006ABE8 112A00BF */  beq       $t1, $t2, .L8006AEE8
/* 45FEC 8006ABEC 00000000 */   nop
/* 45FF0 8006ABF0 240A002C */  addiu     $t2, $zero, 0x2c
/* 45FF4 8006ABF4 112A0110 */  beq       $t1, $t2, handle_CPU
/* 45FF8 8006ABF8 00000000 */   nop
/* 45FFC 8006ABFC 240A0000 */  addiu     $t2, $zero, 0
/* 46000 8006AC00 152A00D2 */  bne       $t1, $t2, .L8006AF4C
/* 46004 8006AC04 00000000 */   nop
/* 46008 8006AC08 03688024 */  and       $s0, $k1, $t0
.L8006AC0C:
/* 4600C 8006AC0C 3209FF00 */  andi      $t1, $s0, 0xff00
/* 46010 8006AC10 00095302 */  srl       $t2, $t1, 0xc
/* 46014 8006AC14 15400003 */  bnez      $t2, .L8006AC24
/* 46018 8006AC18 00000000 */   nop
/* 4601C 8006AC1C 00095202 */  srl       $t2, $t1, 8
/* 46020 8006AC20 214A0010 */  addi      $t2, $t2, 0x10
.L8006AC24:
/* 46024 8006AC24 3C01800A */  lui       $at, %hi(jtbl_80099D80)
/* 46028 8006AC28 002A0821 */  addu      $at, $at, $t2
/* 4602C 8006AC2C 902A9D80 */  lbu       $t2, %lo(jtbl_80099D80)($at)
/* 46030 8006AC30 3C01800A */  lui       $at, %hi(jtbl_80099DA0)
/* 46034 8006AC34 002A0821 */  addu      $at, $at, $t2
/* 46038 8006AC38 8C2A9DA0 */  lw        $t2, %lo(jtbl_80099DA0)($at)
/* 4603C 8006AC3C 01400008 */  jr        $t2
/* 46040 8006AC40 00000000 */   nop
.L8006AC44_46044:
/* 46044 8006AC44 2401DFFF */  addiu     $at, $zero, -0x2001
/* 46048 8006AC48 1000FFF0 */  b         .L8006AC0C
/* 4604C 8006AC4C 02018024 */   and      $s0, $s0, $at
.L8006AC50_46050:
/* 46050 8006AC50 2401BFFF */  addiu     $at, $zero, -0x4001
/* 46054 8006AC54 1000FFED */  b         .L8006AC0C
/* 46058 8006AC58 02018024 */   and      $s0, $s0, $at
.L8006AC5C_4605C:
/* 4605C 8006AC5C 40095800 */  mfc0      $t1, $11
/* 46060 8006AC60 40895800 */  mtc0      $t1, $11
/* 46064 8006AC64 24040018 */  addiu     $a0, $zero, 0x18
/* 46068 8006AC68 0C01ABDF */  jal       send_mesg
/* 4606C 8006AC6C 00000000 */   nop
/* 46070 8006AC70 3C01FFFF */  lui       $at, 0xffff
/* 46074 8006AC74 34217FFF */  ori       $at, $at, 0x7fff
/* 46078 8006AC78 1000FFE4 */  b         .L8006AC0C
/* 4607C 8006AC7C 02018024 */   and      $s0, $s0, $at
.L8006AC80_46080:
/* 46080 8006AC80 2401F7FF */  addiu     $at, $zero, -0x801
/* 46084 8006AC84 02018024 */  and       $s0, $s0, $at
/* 46088 8006AC88 3C098009 */  lui       $t1, %hi(D_80095910)
/* 4608C 8006AC8C 25295910 */  addiu     $t1, $t1, %lo(D_80095910)
/* 46090 8006AC90 21290008 */  addi      $t1, $t1, 8
/* 46094 8006AC94 8D2A0000 */  lw        $t2, ($t1)
/* 46098 8006AC98 11400007 */  beqz      $t2, .L8006ACB8
/* 4609C 8006AC9C 00000000 */   nop
/* 460A0 8006ACA0 0140F809 */  jalr      $t2
/* 460A4 8006ACA4 8D3D0004 */   lw       $sp, 4($t1)
/* 460A8 8006ACA8 10400003 */  beqz      $v0, .L8006ACB8
/* 460AC 8006ACAC 00000000 */   nop
/* 460B0 8006ACB0 10000093 */  b         .L8006AF00
/* 460B4 8006ACB4 00000000 */   nop
.L8006ACB8:
/* 460B8 8006ACB8 0C01ABDF */  jal       send_mesg
/* 460BC 8006ACBC 24040010 */   addiu    $a0, $zero, 0x10
/* 460C0 8006ACC0 1000FFD2 */  b         .L8006AC0C
/* 460C4 8006ACC4 00000000 */   nop
.L8006ACC8_460C8:
/* 460C8 8006ACC8 3C11A430 */  lui       $s1, %hi(D_A4300008)
/* 460CC 8006ACCC 8E310008 */  lw        $s1, %lo(D_A4300008)($s1)
/* 460D0 8006ACD0 3C088009 */  lui       $t0, %hi(__OSGlobalIntMask)
/* 460D4 8006ACD4 25085900 */  addiu     $t0, $t0, %lo(__OSGlobalIntMask)
/* 460D8 8006ACD8 8D080000 */  lw        $t0, ($t0)
/* 460DC 8006ACDC 00084402 */  srl       $t0, $t0, 0x10
/* 460E0 8006ACE0 02288824 */  and       $s1, $s1, $t0
/* 460E4 8006ACE4 32290001 */  andi      $t1, $s1, 1
/* 460E8 8006ACE8 11200014 */  beqz      $t1, .L8006AD3C
/* 460EC 8006ACEC 00000000 */   nop
/* 460F0 8006ACF0 3231003E */  andi      $s1, $s1, 0x3e
/* 460F4 8006ACF4 3C0CA404 */  lui       $t4, %hi(D_A4040010)
/* 460F8 8006ACF8 8D8C0010 */  lw        $t4, %lo(D_A4040010)($t4)
/* 460FC 8006ACFC 34098008 */  ori       $t1, $zero, 0x8008
/* 46100 8006AD00 3C01A404 */  lui       $at, %hi(D_A4040010)
/* 46104 8006AD04 AC290010 */  sw        $t1, %lo(D_A4040010)($at)
/* 46108 8006AD08 318C0300 */  andi      $t4, $t4, 0x300
/* 4610C 8006AD0C 11800007 */  beqz      $t4, .L8006AD2C
/* 46110 8006AD10 00000000 */   nop
/* 46114 8006AD14 0C01ABDF */  jal       send_mesg
/* 46118 8006AD18 24040020 */   addiu    $a0, $zero, 0x20
/* 4611C 8006AD1C 12200044 */  beqz      $s1, .L8006AE30
/* 46120 8006AD20 00000000 */   nop
/* 46124 8006AD24 10000005 */  b         .L8006AD3C
/* 46128 8006AD28 00000000 */   nop
.L8006AD2C:
/* 4612C 8006AD2C 0C01ABDF */  jal       send_mesg
/* 46130 8006AD30 24040058 */   addiu    $a0, $zero, 0x58
/* 46134 8006AD34 1220003E */  beqz      $s1, .L8006AE30
/* 46138 8006AD38 00000000 */   nop
.L8006AD3C:
/* 4613C 8006AD3C 32290008 */  andi      $t1, $s1, 8
/* 46140 8006AD40 11200008 */  beqz      $t1, .L8006AD64
/* 46144 8006AD44 00000000 */   nop
/* 46148 8006AD48 32310037 */  andi      $s1, $s1, 0x37
/* 4614C 8006AD4C 3C01A440 */  lui       $at, %hi(D_A4400010)
/* 46150 8006AD50 AC200010 */  sw        $zero, %lo(D_A4400010)($at)
/* 46154 8006AD54 0C01ABDF */  jal       send_mesg
/* 46158 8006AD58 24040038 */   addiu    $a0, $zero, 0x38
/* 4615C 8006AD5C 12200034 */  beqz      $s1, .L8006AE30
/* 46160 8006AD60 00000000 */   nop
.L8006AD64:
/* 46164 8006AD64 32290004 */  andi      $t1, $s1, 4
/* 46168 8006AD68 11200009 */  beqz      $t1, .L8006AD90
/* 4616C 8006AD6C 00000000 */   nop
/* 46170 8006AD70 3231003B */  andi      $s1, $s1, 0x3b
/* 46174 8006AD74 24090001 */  addiu     $t1, $zero, 1
/* 46178 8006AD78 3C01A450 */  lui       $at, %hi(D_A450000C)
/* 4617C 8006AD7C AC29000C */  sw        $t1, %lo(D_A450000C)($at)
/* 46180 8006AD80 0C01ABDF */  jal       send_mesg
/* 46184 8006AD84 24040030 */   addiu    $a0, $zero, 0x30
/* 46188 8006AD88 12200029 */  beqz      $s1, .L8006AE30
/* 4618C 8006AD8C 00000000 */   nop
.L8006AD90:
/* 46190 8006AD90 32290002 */  andi      $t1, $s1, 2
/* 46194 8006AD94 11200008 */  beqz      $t1, .L8006ADB8
/* 46198 8006AD98 00000000 */   nop
/* 4619C 8006AD9C 3231003D */  andi      $s1, $s1, 0x3d
/* 461A0 8006ADA0 3C01A480 */  lui       $at, %hi(D_A4800018)
/* 461A4 8006ADA4 AC200018 */  sw        $zero, %lo(D_A4800018)($at)
/* 461A8 8006ADA8 0C01ABDF */  jal       send_mesg
/* 461AC 8006ADAC 24040028 */   addiu    $a0, $zero, 0x28
/* 461B0 8006ADB0 1220001F */  beqz      $s1, .L8006AE30
/* 461B4 8006ADB4 00000000 */   nop
.L8006ADB8:
/* 461B8 8006ADB8 32290010 */  andi      $t1, $s1, 0x10
/* 461BC 8006ADBC 11200013 */  beqz      $t1, .L8006AE0C
/* 461C0 8006ADC0 00000000 */   nop
/* 461C4 8006ADC4 3231002F */  andi      $s1, $s1, 0x2f
/* 461C8 8006ADC8 24090002 */  addiu     $t1, $zero, 2
/* 461CC 8006ADCC 3C01A460 */  lui       $at, %hi(D_A4600010)
/* 461D0 8006ADD0 AC290010 */  sw        $t1, %lo(D_A4600010)($at)
/* 461D4 8006ADD4 3C098009 */  lui       $t1, %hi(D_80095938)
/* 461D8 8006ADD8 25295938 */  addiu     $t1, $t1, %lo(D_80095938)
/* 461DC 8006ADDC 8D2A0000 */  lw        $t2, ($t1)
/* 461E0 8006ADE0 11400006 */  beqz      $t2, .L8006ADFC
/* 461E4 8006ADE4 00000000 */   nop
/* 461E8 8006ADE8 8D3D0004 */  lw        $sp, 4($t1)
/* 461EC 8006ADEC 0140F809 */  jalr      $t2
/* 461F0 8006ADF0 00402021 */   addu     $a0, $v0, $zero
/* 461F4 8006ADF4 14400003 */  bnez      $v0, .L8006AE04
/* 461F8 8006ADF8 00000000 */   nop
.L8006ADFC:
/* 461FC 8006ADFC 0C01ABDF */  jal       send_mesg
/* 46200 8006AE00 24040040 */   addiu    $a0, $zero, 0x40
.L8006AE04:
/* 46204 8006AE04 1220000A */  beqz      $s1, .L8006AE30
/* 46208 8006AE08 00000000 */   nop
.L8006AE0C:
/* 4620C 8006AE0C 32290020 */  andi      $t1, $s1, 0x20
/* 46210 8006AE10 11200007 */  beqz      $t1, .L8006AE30
/* 46214 8006AE14 00000000 */   nop
/* 46218 8006AE18 3231001F */  andi      $s1, $s1, 0x1f
/* 4621C 8006AE1C 24090800 */  addiu     $t1, $zero, 0x800
/* 46220 8006AE20 3C01A430 */  lui       $at, 0xa430
/* 46224 8006AE24 AC290000 */  sw        $t1, ($at)
/* 46228 8006AE28 0C01ABDF */  jal       send_mesg
/* 4622C 8006AE2C 24040048 */   addiu    $a0, $zero, 0x48
.L8006AE30:
/* 46230 8006AE30 2401FBFF */  addiu     $at, $zero, -0x401
/* 46234 8006AE34 1000FF75 */  b         .L8006AC0C
/* 46238 8006AE38 02018024 */   and      $s0, $s0, $at
.L8006AE3C_4623C:
/* 4623C 8006AE3C 8F5B0118 */  lw        $k1, 0x118($k0)
/* 46240 8006AE40 2401EFFF */  addiu     $at, $zero, -0x1001
/* 46244 8006AE44 0361D824 */  and       $k1, $k1, $at
/* 46248 8006AE48 AF5B0118 */  sw        $k1, 0x118($k0)
/* 4624C 8006AE4C 3C098009 */  lui       $t1, %hi(__osShutdown)
/* 46250 8006AE50 252958FC */  addiu     $t1, $t1, %lo(__osShutdown)
/* 46254 8006AE54 8D2A0000 */  lw        $t2, ($t1)
/* 46258 8006AE58 11400004 */  beqz      $t2, .L8006AE6C
/* 4625C 8006AE5C 00000000 */   nop
/* 46260 8006AE60 2401EFFF */  addiu     $at, $zero, -0x1001
/* 46264 8006AE64 10000026 */  b         .L8006AF00
/* 46268 8006AE68 02018024 */   and      $s0, $s0, $at
.L8006AE6C:
/* 4626C 8006AE6C 240A0001 */  addiu     $t2, $zero, 1
/* 46270 8006AE70 AD2A0000 */  sw        $t2, ($t1)
/* 46274 8006AE74 0C01ABDF */  jal       send_mesg
/* 46278 8006AE78 24040070 */   addiu    $a0, $zero, 0x70
/* 4627C 8006AE7C 2401EFFF */  addiu     $at, $zero, -0x1001
/* 46280 8006AE80 02018024 */  and       $s0, $s0, $at
/* 46284 8006AE84 3C0A8009 */  lui       $t2, %hi(__osRunQueue)
/* 46288 8006AE88 8D4A4658 */  lw        $t2, %lo(__osRunQueue)($t2)
/* 4628C 8006AE8C 8D5B0118 */  lw        $k1, 0x118($t2)
/* 46290 8006AE90 2401EFFF */  addiu     $at, $zero, -0x1001
/* 46294 8006AE94 0361D824 */  and       $k1, $k1, $at
/* 46298 8006AE98 10000019 */  b         .L8006AF00
/* 4629C 8006AE9C AD5B0118 */   sw       $k1, 0x118($t2)
.L8006AEA0_462A0:
/* 462A0 8006AEA0 2401FDFF */  addiu     $at, $zero, -0x201
/* 462A4 8006AEA4 01014024 */  and       $t0, $t0, $at
/* 462A8 8006AEA8 40886800 */  mtc0      $t0, $13
/* 462AC 8006AEAC 24040008 */  addiu     $a0, $zero, 8
/* 462B0 8006AEB0 0C01ABDF */  jal       send_mesg
/* 462B4 8006AEB4 00000000 */   nop
/* 462B8 8006AEB8 2401FDFF */  addiu     $at, $zero, -0x201
/* 462BC 8006AEBC 1000FF53 */  b         .L8006AC0C
/* 462C0 8006AEC0 02018024 */   and      $s0, $s0, $at
.L8006AEC4_462C4:
/* 462C4 8006AEC4 2401FEFF */  addiu     $at, $zero, -0x101
/* 462C8 8006AEC8 01014024 */  and       $t0, $t0, $at
/* 462CC 8006AECC 40886800 */  mtc0      $t0, $13
/* 462D0 8006AED0 24040000 */  addiu     $a0, $zero, 0
/* 462D4 8006AED4 0C01ABDF */  jal       send_mesg
/* 462D8 8006AED8 00000000 */   nop
/* 462DC 8006AEDC 2401FEFF */  addiu     $at, $zero, -0x101
/* 462E0 8006AEE0 1000FF4A */  b         .L8006AC0C
/* 462E4 8006AEE4 02018024 */   and      $s0, $s0, $at
.L8006AEE8:
/* 462E8 8006AEE8 24090001 */  addiu     $t1, $zero, 1
/* 462EC 8006AEEC A7490012 */  sh        $t1, 0x12($k0)
/* 462F0 8006AEF0 0C01ABDF */  jal       send_mesg
/* 462F4 8006AEF4 24040050 */   addiu    $a0, $zero, 0x50
/* 462F8 8006AEF8 10000001 */  b         .L8006AF00
/* 462FC 8006AEFC 00000000 */   nop
.L8006AF00:
.L8006AF00_46300:
/* 46300 8006AF00 8F490004 */  lw        $t1, 4($k0)
/* 46304 8006AF04 3C0A8009 */  lui       $t2, %hi(__osRunQueue)
/* 46308 8006AF08 8D4A4658 */  lw        $t2, %lo(__osRunQueue)($t2)
/* 4630C 8006AF0C 8D4B0004 */  lw        $t3, 4($t2)
/* 46310 8006AF10 012B082A */  slt       $at, $t1, $t3
/* 46314 8006AF14 10200007 */  beqz      $at, .L8006AF34
/* 46318 8006AF18 00000000 */   nop
/* 4631C 8006AF1C 03402821 */  addu      $a1, $k0, $zero
/* 46320 8006AF20 3C048009 */  lui       $a0, %hi(__osRunQueue)
/* 46324 8006AF24 0C01AC5D */  jal       __osEnqueueThread
/* 46328 8006AF28 24844658 */   addiu    $a0, $a0, %lo(__osRunQueue)
/* 4632C 8006AF2C 0801AC75 */  j         __osDispatchThread
/* 46330 8006AF30 00000000 */   nop
.L8006AF34:
/* 46334 8006AF34 3C098009 */  lui       $t1, %hi(__osRunQueue)
/* 46338 8006AF38 25294658 */  addiu     $t1, $t1, %lo(__osRunQueue)
/* 4633C 8006AF3C 8D2A0000 */  lw        $t2, ($t1)
/* 46340 8006AF40 AF4A0000 */  sw        $t2, ($k0)
/* 46344 8006AF44 0801AC75 */  j         __osDispatchThread
/* 46348 8006AF48 AD3A0000 */   sw       $k0, ($t1)
.L8006AF4C:
/* 4634C 8006AF4C 3C018009 */  lui       $at, %hi(__osFaultedThread)
/* 46350 8006AF50 AC3A4664 */  sw        $k0, %lo(__osFaultedThread)($at)
/* 46354 8006AF54 24090001 */  addiu     $t1, $zero, 1
/* 46358 8006AF58 A7490010 */  sh        $t1, 0x10($k0)
/* 4635C 8006AF5C 24090002 */  addiu     $t1, $zero, 2
/* 46360 8006AF60 A7490012 */  sh        $t1, 0x12($k0)
/* 46364 8006AF64 400A4000 */  mfc0      $t2, $8
/* 46368 8006AF68 AF4A0124 */  sw        $t2, 0x124($k0)
/* 4636C 8006AF6C 0C01ABDF */  jal       send_mesg
/* 46370 8006AF70 24040060 */   addiu    $a0, $zero, 0x60
/* 46374 8006AF74 0801AC75 */  j         __osDispatchThread
/* 46378 8006AF78 00000000 */   nop

glabel send_mesg
/* 4637C 8006AF7C 03E09021 */  addu      $s2, $ra, $zero
/* 46380 8006AF80 3C0A800E */  lui       $t2, %hi(__osEventStateTab)
/* 46384 8006AF84 254A9F80 */  addiu     $t2, $t2, %lo(__osEventStateTab)
/* 46388 8006AF88 01445021 */  addu      $t2, $t2, $a0
/* 4638C 8006AF8C 8D490000 */  lw        $t1, ($t2)
/* 46390 8006AF90 11200027 */  beqz      $t1, .L8006B030
/* 46394 8006AF94 00000000 */   nop
/* 46398 8006AF98 8D2B0008 */  lw        $t3, 8($t1)
/* 4639C 8006AF9C 8D2C0010 */  lw        $t4, 0x10($t1)
/* 463A0 8006AFA0 016C082A */  slt       $at, $t3, $t4
/* 463A4 8006AFA4 10200022 */  beqz      $at, .L8006B030
/* 463A8 8006AFA8 00000000 */   nop
/* 463AC 8006AFAC 8D2D000C */  lw        $t5, 0xc($t1)
/* 463B0 8006AFB0 01AB6821 */  addu      $t5, $t5, $t3
/* 463B4 8006AFB4 01AC001A */  div       $zero, $t5, $t4
/* 463B8 8006AFB8 15800002 */  bnez      $t4, .L8006AFC4
/* 463BC 8006AFBC 00000000 */   nop
/* 463C0 8006AFC0 0007000D */  break     7
.L8006AFC4:
/* 463C4 8006AFC4 2401FFFF */   addiu    $at, $zero, -1
/* 463C8 8006AFC8 15810004 */  bne       $t4, $at, .L8006AFDC
/* 463CC 8006AFCC 3C018000 */   lui      $at, 0x8000
/* 463D0 8006AFD0 15A10002 */  bne       $t5, $at, .L8006AFDC
/* 463D4 8006AFD4 00000000 */   nop
/* 463D8 8006AFD8 0006000D */  break     6
.L8006AFDC:
/* 463DC 8006AFDC 00006810 */   mfhi     $t5
/* 463E0 8006AFE0 8D2C0014 */  lw        $t4, 0x14($t1)
/* 463E4 8006AFE4 24010004 */  addiu     $at, $zero, 4
/* 463E8 8006AFE8 01A10018 */  mult      $t5, $at
/* 463EC 8006AFEC 00006812 */  mflo      $t5
/* 463F0 8006AFF0 018D6021 */  addu      $t4, $t4, $t5
/* 463F4 8006AFF4 8D4D0004 */  lw        $t5, 4($t2)
/* 463F8 8006AFF8 AD8D0000 */  sw        $t5, ($t4)
/* 463FC 8006AFFC 256A0001 */  addiu     $t2, $t3, 1
/* 46400 8006B000 AD2A0008 */  sw        $t2, 8($t1)
/* 46404 8006B004 8D2A0000 */  lw        $t2, ($t1)
/* 46408 8006B008 8D4B0000 */  lw        $t3, ($t2)
/* 4640C 8006B00C 11600008 */  beqz      $t3, .L8006B030
/* 46410 8006B010 00000000 */   nop
/* 46414 8006B014 0C01AC6F */  jal       __osPopThread
/* 46418 8006B018 01202021 */   addu     $a0, $t1, $zero
/* 4641C 8006B01C 00405021 */  addu      $t2, $v0, $zero
/* 46420 8006B020 01402821 */  addu      $a1, $t2, $zero
/* 46424 8006B024 3C048009 */  lui       $a0, %hi(__osRunQueue)
/* 46428 8006B028 0C01AC5D */  jal       __osEnqueueThread
/* 4642C 8006B02C 24844658 */   addiu    $a0, $a0, %lo(__osRunQueue)
.L8006B030:
/* 46430 8006B030 02400008 */  jr        $s2
/* 46434 8006B034 00000000 */   nop

glabel handle_CPU
/* 46438 8006B038 3C013000 */  lui       $at, 0x3000
/* 4643C 8006B03C 01014824 */  and       $t1, $t0, $at
/* 46440 8006B040 00094F02 */  srl       $t1, $t1, 0x1c
/* 46444 8006B044 240A0001 */  addiu     $t2, $zero, 1
/* 46448 8006B048 152AFFC0 */  bne       $t1, $t2, .L8006AF4C
/* 4644C 8006B04C 00000000 */   nop
/* 46450 8006B050 24090001 */  addiu     $t1, $zero, 1
/* 46454 8006B054 AF490018 */  sw        $t1, 0x18($k0)
/* 46458 8006B058 8F5B0118 */  lw        $k1, 0x118($k0)
/* 4645C 8006B05C 3C012000 */  lui       $at, 0x2000
/* 46460 8006B060 0361D825 */  or        $k1, $k1, $at
/* 46464 8006B064 1000FFB3 */  b         .L8006AF34
/* 46468 8006B068 AF5B0118 */   sw       $k1, 0x118($k0)

glabel __osEnqueueAndYield
/* 4646C 8006B06C 3C058009 */  lui       $a1, %hi(__osRunningThread)
/* 46470 8006B070 8CA54660 */  lw        $a1, %lo(__osRunningThread)($a1)
/* 46474 8006B074 40086000 */  mfc0      $t0, $12
/* 46478 8006B078 35080002 */  ori       $t0, $t0, 2
/* 4647C 8006B07C ACA80118 */  sw        $t0, 0x118($a1)
/* 46480 8006B080 FCB00098 */  sd        $s0, 0x98($a1)
/* 46484 8006B084 FCB100A0 */  sd        $s1, 0xa0($a1)
/* 46488 8006B088 FCB200A8 */  sd        $s2, 0xa8($a1)
/* 4648C 8006B08C FCB300B0 */  sd        $s3, 0xb0($a1)
/* 46490 8006B090 FCB400B8 */  sd        $s4, 0xb8($a1)
/* 46494 8006B094 FCB500C0 */  sd        $s5, 0xc0($a1)
/* 46498 8006B098 FCB600C8 */  sd        $s6, 0xc8($a1)
/* 4649C 8006B09C FCB700D0 */  sd        $s7, 0xd0($a1)
/* 464A0 8006B0A0 FCBC00E8 */  sd        $gp, 0xe8($a1)
/* 464A4 8006B0A4 FCBD00F0 */  sd        $sp, 0xf0($a1)
/* 464A8 8006B0A8 FCBE00F8 */  sd        $fp, 0xf8($a1)
/* 464AC 8006B0AC FCBF0100 */  sd        $ra, 0x100($a1)
/* 464B0 8006B0B0 ACBF011C */  sw        $ra, 0x11c($a1)
/* 464B4 8006B0B4 8CBB0018 */  lw        $k1, 0x18($a1)
/* 464B8 8006B0B8 1360000A */  beqz      $k1, .L8006B0E4
/* 464BC 8006B0BC 00000000 */   nop
/* 464C0 8006B0C0 445BF800 */  cfc1      $k1, $31
/* 464C4 8006B0C4 00000000 */  nop
/* 464C8 8006B0C8 ACBB012C */  sw        $k1, 0x12c($a1)
/* 464CC 8006B0CC F4B40180 */  sdc1      $f20, 0x180($a1)
/* 464D0 8006B0D0 F4B60188 */  sdc1      $f22, 0x188($a1)
/* 464D4 8006B0D4 F4B80190 */  sdc1      $f24, 0x190($a1)
/* 464D8 8006B0D8 F4BA0198 */  sdc1      $f26, 0x198($a1)
/* 464DC 8006B0DC F4BC01A0 */  sdc1      $f28, 0x1a0($a1)
/* 464E0 8006B0E0 F4BE01A8 */  sdc1      $f30, 0x1a8($a1)
.L8006B0E4:
/* 464E4 8006B0E4 8CBB0118 */  lw        $k1, 0x118($a1)
/* 464E8 8006B0E8 3369FF00 */  andi      $t1, $k1, 0xff00
/* 464EC 8006B0EC 1120000D */  beqz      $t1, .L8006B124
/* 464F0 8006B0F0 00000000 */   nop
/* 464F4 8006B0F4 3C088009 */  lui       $t0, %hi(__OSGlobalIntMask)
/* 464F8 8006B0F8 25085900 */  addiu     $t0, $t0, %lo(__OSGlobalIntMask)
/* 464FC 8006B0FC 8D080000 */  lw        $t0, ($t0)
/* 46500 8006B100 2401FFFF */  addiu     $at, $zero, -1
/* 46504 8006B104 01014026 */  xor       $t0, $t0, $at
/* 46508 8006B108 3108FF00 */  andi      $t0, $t0, 0xff00
/* 4650C 8006B10C 01284825 */  or        $t1, $t1, $t0
/* 46510 8006B110 3C01FFFF */  lui       $at, 0xffff
/* 46514 8006B114 342100FF */  ori       $at, $at, 0xff
/* 46518 8006B118 0361D824 */  and       $k1, $k1, $at
/* 4651C 8006B11C 0369D825 */  or        $k1, $k1, $t1
/* 46520 8006B120 ACBB0118 */  sw        $k1, 0x118($a1)
.L8006B124:
/* 46524 8006B124 3C1BA430 */  lui       $k1, %hi(D_A430000C)
/* 46528 8006B128 8F7B000C */  lw        $k1, %lo(D_A430000C)($k1)
/* 4652C 8006B12C 1360000B */  beqz      $k1, .L8006B15C
/* 46530 8006B130 00000000 */   nop
/* 46534 8006B134 3C1A8009 */  lui       $k0, %hi(__OSGlobalIntMask)
/* 46538 8006B138 275A5900 */  addiu     $k0, $k0, %lo(__OSGlobalIntMask)
/* 4653C 8006B13C 8F5A0000 */  lw        $k0, ($k0)
/* 46540 8006B140 001AD402 */  srl       $k0, $k0, 0x10
/* 46544 8006B144 2401FFFF */  addiu     $at, $zero, -1
/* 46548 8006B148 0341D026 */  xor       $k0, $k0, $at
/* 4654C 8006B14C 335A003F */  andi      $k0, $k0, 0x3f
/* 46550 8006B150 8CA80128 */  lw        $t0, 0x128($a1)
/* 46554 8006B154 0348D024 */  and       $k0, $k0, $t0
/* 46558 8006B158 037AD825 */  or        $k1, $k1, $k0
.L8006B15C:
/* 4655C 8006B15C 10800003 */  beqz      $a0, .L8006B16C
/* 46560 8006B160 ACBB0128 */   sw       $k1, 0x128($a1)
/* 46564 8006B164 0C01AC5D */  jal       __osEnqueueThread
/* 46568 8006B168 00000000 */   nop
.L8006B16C:
/* 4656C 8006B16C 0801AC75 */  j         __osDispatchThread
/* 46570 8006B170 00000000 */   nop

glabel __osEnqueueThread
/* 46574 8006B174 0080C821 */  addu      $t9, $a0, $zero
/* 46578 8006B178 8C980000 */  lw        $t8, ($a0)
/* 4657C 8006B17C 8CAF0004 */  lw        $t7, 4($a1)
/* 46580 8006B180 8F0E0004 */  lw        $t6, 4($t8)
/* 46584 8006B184 01CF082A */  slt       $at, $t6, $t7
/* 46588 8006B188 14200007 */  bnez      $at, .L8006B1A8
/* 4658C 8006B18C 00000000 */   nop
.L8006B190:
/* 46590 8006B190 0300C821 */  addu      $t9, $t8, $zero
/* 46594 8006B194 8F180000 */  lw        $t8, ($t8)
/* 46598 8006B198 8F0E0004 */  lw        $t6, 4($t8)
/* 4659C 8006B19C 01CF082A */  slt       $at, $t6, $t7
/* 465A0 8006B1A0 1020FFFB */  beqz      $at, .L8006B190
/* 465A4 8006B1A4 00000000 */   nop
.L8006B1A8:
/* 465A8 8006B1A8 8F380000 */  lw        $t8, ($t9)
/* 465AC 8006B1AC ACB80000 */  sw        $t8, ($a1)
/* 465B0 8006B1B0 AF250000 */  sw        $a1, ($t9)
/* 465B4 8006B1B4 03E00008 */  jr        $ra
/* 465B8 8006B1B8 ACA40008 */   sw       $a0, 8($a1)

glabel __osPopThread
/* 465BC 8006B1BC 8C820000 */  lw        $v0, ($a0)
/* 465C0 8006B1C0 8C590000 */  lw        $t9, ($v0)
/* 465C4 8006B1C4 03E00008 */  jr        $ra
/* 465C8 8006B1C8 AC990000 */   sw       $t9, ($a0)
/* 465CC 8006B1CC 03E00008 */  jr        $ra
/* 465D0 8006B1D0 00000000 */   nop

glabel __osDispatchThread
/* 465D4 8006B1D4 3C048009 */  lui       $a0, %hi(__osRunQueue)
/* 465D8 8006B1D8 0C01AC6F */  jal       __osPopThread
/* 465DC 8006B1DC 24844658 */   addiu    $a0, $a0, %lo(__osRunQueue)
/* 465E0 8006B1E0 3C018009 */  lui       $at, %hi(__osRunningThread)
/* 465E4 8006B1E4 AC224660 */  sw        $v0, %lo(__osRunningThread)($at)
/* 465E8 8006B1E8 24080004 */  addiu     $t0, $zero, 4
/* 465EC 8006B1EC A4480010 */  sh        $t0, 0x10($v0)
/* 465F0 8006B1F0 0040D021 */  addu      $k0, $v0, $zero
/* 465F4 8006B1F4 8F5B0118 */  lw        $k1, 0x118($k0)
/* 465F8 8006B1F8 3C088009 */  lui       $t0, %hi(__OSGlobalIntMask)
/* 465FC 8006B1FC 25085900 */  addiu     $t0, $t0, %lo(__OSGlobalIntMask)
/* 46600 8006B200 8D080000 */  lw        $t0, ($t0)
/* 46604 8006B204 3108FF00 */  andi      $t0, $t0, 0xff00
/* 46608 8006B208 3369FF00 */  andi      $t1, $k1, 0xff00
/* 4660C 8006B20C 01284824 */  and       $t1, $t1, $t0
/* 46610 8006B210 3C01FFFF */  lui       $at, 0xffff
/* 46614 8006B214 342100FF */  ori       $at, $at, 0xff
/* 46618 8006B218 0361D824 */  and       $k1, $k1, $at
/* 4661C 8006B21C 0369D825 */  or        $k1, $k1, $t1
/* 46620 8006B220 409B6000 */  mtc0      $k1, $12
/* 46624 8006B224 DF410020 */  ld        $at, 0x20($k0)
/* 46628 8006B228 DF420028 */  ld        $v0, 0x28($k0)
/* 4662C 8006B22C DF430030 */  ld        $v1, 0x30($k0)
/* 46630 8006B230 DF440038 */  ld        $a0, 0x38($k0)
/* 46634 8006B234 DF450040 */  ld        $a1, 0x40($k0)
/* 46638 8006B238 DF460048 */  ld        $a2, 0x48($k0)
/* 4663C 8006B23C DF470050 */  ld        $a3, 0x50($k0)
/* 46640 8006B240 DF480058 */  ld        $t0, 0x58($k0)
/* 46644 8006B244 DF490060 */  ld        $t1, 0x60($k0)
/* 46648 8006B248 DF4A0068 */  ld        $t2, 0x68($k0)
/* 4664C 8006B24C DF4B0070 */  ld        $t3, 0x70($k0)
/* 46650 8006B250 DF4C0078 */  ld        $t4, 0x78($k0)
/* 46654 8006B254 DF4D0080 */  ld        $t5, 0x80($k0)
/* 46658 8006B258 DF4E0088 */  ld        $t6, 0x88($k0)
/* 4665C 8006B25C DF4F0090 */  ld        $t7, 0x90($k0)
/* 46660 8006B260 DF500098 */  ld        $s0, 0x98($k0)
/* 46664 8006B264 DF5100A0 */  ld        $s1, 0xa0($k0)
/* 46668 8006B268 DF5200A8 */  ld        $s2, 0xa8($k0)
/* 4666C 8006B26C DF5300B0 */  ld        $s3, 0xb0($k0)
/* 46670 8006B270 DF5400B8 */  ld        $s4, 0xb8($k0)
/* 46674 8006B274 DF5500C0 */  ld        $s5, 0xc0($k0)
/* 46678 8006B278 DF5600C8 */  ld        $s6, 0xc8($k0)
/* 4667C 8006B27C DF5700D0 */  ld        $s7, 0xd0($k0)
/* 46680 8006B280 DF5800D8 */  ld        $t8, 0xd8($k0)
/* 46684 8006B284 DF5900E0 */  ld        $t9, 0xe0($k0)
/* 46688 8006B288 DF5C00E8 */  ld        $gp, 0xe8($k0)
/* 4668C 8006B28C DF5D00F0 */  ld        $sp, 0xf0($k0)
/* 46690 8006B290 DF5E00F8 */  ld        $fp, 0xf8($k0)
/* 46694 8006B294 DF5F0100 */  ld        $ra, 0x100($k0)
/* 46698 8006B298 DF5B0108 */  ld        $k1, 0x108($k0)
/* 4669C 8006B29C 03600013 */  mtlo      $k1
/* 466A0 8006B2A0 DF5B0110 */  ld        $k1, 0x110($k0)
/* 466A4 8006B2A4 03600011 */  mthi      $k1
/* 466A8 8006B2A8 8F5B011C */  lw        $k1, 0x11c($k0)
/* 466AC 8006B2AC 409B7000 */  mtc0      $k1, $14
/* 466B0 8006B2B0 8F5B0018 */  lw        $k1, 0x18($k0)
/* 466B4 8006B2B4 13600013 */  beqz      $k1, .L8006B304
/* 466B8 8006B2B8 00000000 */   nop
/* 466BC 8006B2BC 8F5B012C */  lw        $k1, 0x12c($k0)
/* 466C0 8006B2C0 44DBF800 */  ctc1      $k1, $31
/* 466C4 8006B2C4 D7400130 */  ldc1      $f0, 0x130($k0)
/* 466C8 8006B2C8 D7420138 */  ldc1      $f2, 0x138($k0)
/* 466CC 8006B2CC D7440140 */  ldc1      $f4, 0x140($k0)
/* 466D0 8006B2D0 D7460148 */  ldc1      $f6, 0x148($k0)
/* 466D4 8006B2D4 D7480150 */  ldc1      $f8, 0x150($k0)
/* 466D8 8006B2D8 D74A0158 */  ldc1      $f10, 0x158($k0)
/* 466DC 8006B2DC D74C0160 */  ldc1      $f12, 0x160($k0)
/* 466E0 8006B2E0 D74E0168 */  ldc1      $f14, 0x168($k0)
/* 466E4 8006B2E4 D7500170 */  ldc1      $f16, 0x170($k0)
/* 466E8 8006B2E8 D7520178 */  ldc1      $f18, 0x178($k0)
/* 466EC 8006B2EC D7540180 */  ldc1      $f20, 0x180($k0)
/* 466F0 8006B2F0 D7560188 */  ldc1      $f22, 0x188($k0)
/* 466F4 8006B2F4 D7580190 */  ldc1      $f24, 0x190($k0)
/* 466F8 8006B2F8 D75A0198 */  ldc1      $f26, 0x198($k0)
/* 466FC 8006B2FC D75C01A0 */  ldc1      $f28, 0x1a0($k0)
/* 46700 8006B300 D75E01A8 */  ldc1      $f30, 0x1a8($k0)
.L8006B304:
/* 46704 8006B304 8F5B0128 */  lw        $k1, 0x128($k0)
/* 46708 8006B308 3C1A8009 */  lui       $k0, %hi(__OSGlobalIntMask)
/* 4670C 8006B30C 275A5900 */  addiu     $k0, $k0, %lo(__OSGlobalIntMask)
/* 46710 8006B310 8F5A0000 */  lw        $k0, ($k0)
/* 46714 8006B314 001AD402 */  srl       $k0, $k0, 0x10
/* 46718 8006B318 037AD824 */  and       $k1, $k1, $k0
/* 4671C 8006B31C 001BD840 */  sll       $k1, $k1, 1
/* 46720 8006B320 3C1A800A */  lui       $k0, %hi(D_80099AA0)
/* 46724 8006B324 275A9AA0 */  addiu     $k0, $k0, %lo(D_80099AA0)
/* 46728 8006B328 037AD821 */  addu      $k1, $k1, $k0
/* 4672C 8006B32C 977B0000 */  lhu       $k1, ($k1)
/* 46730 8006B330 3C1AA430 */  lui       $k0, 0xa430
/* 46734 8006B334 375A000C */  ori       $k0, $k0, 0xc
/* 46738 8006B338 AF5B0000 */  sw        $k1, ($k0)
/* 4673C 8006B33C 00000000 */  nop
/* 46740 8006B340 00000000 */  nop
/* 46744 8006B344 00000000 */  nop
/* 46748 8006B348 00000000 */  nop
/* 4674C 8006B34C 42000018 */  eret

glabel __osCleanupThread
/* 46750 8006B350 00002021 */  addu      $a0, $zero, $zero
/* 46754 8006B354 0C01B254 */  jal       osDestroyThread
/* 46758 8006B358 00000000 */   nop
/* 4675C 8006B35C 00000000 */  nop
