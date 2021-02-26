.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel create_audio_system
/* 25F00 8004AB00 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* 25F04 8004AB04 AFB00030 */  sw        $s0, 0x30($sp)
/* 25F08 8004AB08 3C10800E */  lui       $s0, %hi(D_800D9248)
/* 25F0C 8004AB0C 26109248 */  addiu     $s0, $s0, %lo(D_800D9248)
/* 25F10 8004AB10 0200202D */  daddu     $a0, $s0, $zero
/* 25F14 8004AB14 3C05801B */  lui       $a1, %hi(D_801AA000)
/* 25F18 8004AB18 24A5A000 */  addiu     $a1, $a1, %lo(D_801AA000)
/* 25F1C 8004AB1C 3C060005 */  lui       $a2, 5
/* 25F20 8004AB20 24020001 */  addiu     $v0, $zero, 1
/* 25F24 8004AB24 AFBF003C */  sw        $ra, 0x3c($sp)
/* 25F28 8004AB28 AFB20038 */  sw        $s2, 0x38($sp)
/* 25F2C 8004AB2C AFB10034 */  sw        $s1, 0x34($sp)
/* 25F30 8004AB30 3C018008 */  lui       $at, %hi(nuAuTaskStop)
/* 25F34 8004AB34 A0228180 */  sb        $v0, %lo(nuAuTaskStop)($at)
/* 25F38 8004AB38 3C018008 */  lui       $at, %hi(D_80078170)
/* 25F3C 8004AB3C A0208170 */  sb        $zero, %lo(D_80078170)($at)
/* 25F40 8004AB40 0C015FC8 */  jal       alHeapInit
/* 25F44 8004AB44 34C66000 */   ori      $a2, $a2, 0x6000
/* 25F48 8004AB48 24047D00 */  addiu     $a0, $zero, 0x7d00
/* 25F4C 8004AB4C 24020018 */  addiu     $v0, $zero, 0x18
/* 25F50 8004AB50 AFA20018 */  sw        $v0, 0x18($sp)
/* 25F54 8004AB54 24020004 */  addiu     $v0, $zero, 4
/* 25F58 8004AB58 0C018558 */  jal       osAiSetFrequency
/* 25F5C 8004AB5C AFA2001C */   sw       $v0, 0x1c($sp)
/* 25F60 8004AB60 3C03800E */  lui       $v1, %hi(D_800DAAB8)
/* 25F64 8004AB64 8C63AAB8 */  lw        $v1, %lo(D_800DAAB8)($v1)
/* 25F68 8004AB68 00620018 */  mult      $v1, $v0
/* 25F6C 8004AB6C 00001812 */  mflo      $v1
/* 25F70 8004AB70 2464003B */  addiu     $a0, $v1, 0x3b
/* 25F74 8004AB74 3C038888 */  lui       $v1, 0x8888
/* 25F78 8004AB78 34638889 */  ori       $v1, $v1, 0x8889
/* 25F7C 8004AB7C 00830019 */  multu     $a0, $v1
/* 25F80 8004AB80 0000882D */  daddu     $s1, $zero, $zero
/* 25F84 8004AB84 3C12800A */  lui       $s2, %hi(D_800A3510)
/* 25F88 8004AB88 26523510 */  addiu     $s2, $s2, %lo(D_800A3510)
/* 25F8C 8004AB8C AFA20020 */  sw        $v0, 0x20($sp)
/* 25F90 8004AB90 00001810 */  mfhi      $v1
/* 25F94 8004AB94 3C02B216 */  lui       $v0, 0xb216
/* 25F98 8004AB98 344242C9 */  ori       $v0, $v0, 0x42c9
/* 25F9C 8004AB9C 00031942 */  srl       $v1, $v1, 5
/* 25FA0 8004ABA0 00620019 */  multu     $v1, $v0
/* 25FA4 8004ABA4 A3A00024 */  sb        $zero, 0x24($sp)
/* 25FA8 8004ABA8 AFB0002C */  sw        $s0, 0x2c($sp)
/* 25FAC 8004ABAC 3C028005 */  lui       $v0, %hi(nuAuDmaNew)
/* 25FB0 8004ABB0 2442B224 */  addiu     $v0, $v0, %lo(nuAuDmaNew)
/* 25FB4 8004ABB4 AFA20028 */  sw        $v0, 0x28($sp)
/* 25FB8 8004ABB8 00001810 */  mfhi      $v1
/* 25FBC 8004ABBC 000319C2 */  srl       $v1, $v1, 7
/* 25FC0 8004ABC0 24630001 */  addiu     $v1, $v1, 1
/* 25FC4 8004ABC4 00031040 */  sll       $v0, $v1, 1
/* 25FC8 8004ABC8 00431021 */  addu      $v0, $v0, $v1
/* 25FCC 8004ABCC 000210C0 */  sll       $v0, $v0, 3
/* 25FD0 8004ABD0 00431023 */  subu      $v0, $v0, $v1
/* 25FD4 8004ABD4 000210C0 */  sll       $v0, $v0, 3
/* 25FD8 8004ABD8 3C01800A */  lui       $at, %hi(nuAuFrameSampleSize)
/* 25FDC 8004ABDC AC223634 */  sw        $v0, %lo(nuAuFrameSampleSize)($at)
/* 25FE0 8004ABE0 2442FF48 */  addiu     $v0, $v0, -0xb8
/* 25FE4 8004ABE4 3C01800A */  lui       $at, %hi(D_800A3638)
/* 25FE8 8004ABE8 AC223638 */  sw        $v0, %lo(D_800A3638)($at)
.L8004ABEC:
/* 25FEC 8004ABEC 24050001 */  addiu     $a1, $zero, 1
/* 25FF0 8004ABF0 24064000 */  addiu     $a2, $zero, 0x4000
/* 25FF4 8004ABF4 8FA4002C */  lw        $a0, 0x2c($sp)
/* 25FF8 8004ABF8 0C015FE4 */  jal       alHeapAlloc
/* 25FFC 8004ABFC 02258821 */   addu     $s1, $s1, $a1
/* 26000 8004AC00 AE420000 */  sw        $v0, ($s2)
/* 26004 8004AC04 2E220003 */  sltiu     $v0, $s1, 3
/* 26008 8004AC08 1440FFF8 */  bnez      $v0, .L8004ABEC
/* 2600C 8004AC0C 26520004 */   addiu    $s2, $s2, 4
/* 26010 8004AC10 0000882D */  daddu     $s1, $zero, $zero
/* 26014 8004AC14 24090002 */  addiu     $t1, $zero, 2
/* 26018 8004AC18 3C08800E */  lui       $t0, %hi(D_800D9780)
/* 2601C 8004AC1C 25089780 */  addiu     $t0, $t0, %lo(D_800D9780)
/* 26020 8004AC20 24070100 */  addiu     $a3, $zero, 0x100
/* 26024 8004AC24 3C068007 */  lui       $a2, %hi(D_800731A0)
/* 26028 8004AC28 24C631A0 */  addiu     $a2, $a2, %lo(D_800731A0)
/* 2602C 8004AC2C 3C058009 */  lui       $a1, %hi(D_80097A80)
/* 26030 8004AC30 24A57A80 */  addiu     $a1, $a1, %lo(D_80097A80)
/* 26034 8004AC34 24040800 */  addiu     $a0, $zero, 0x800
/* 26038 8004AC38 3C03800A */  lui       $v1, %hi(D_800A3520)
/* 2603C 8004AC3C 24633520 */  addiu     $v1, $v1, %lo(D_800A3520)
.L8004AC40:
/* 26040 8004AC40 AC600000 */  sw        $zero, ($v1)
/* 26044 8004AC44 AC600054 */  sw        $zero, 0x54($v1)
/* 26048 8004AC48 AC690010 */  sw        $t1, 0x10($v1)
/* 2604C 8004AC4C AC680018 */  sw        $t0, 0x18($v1)
/* 26050 8004AC50 AC67001C */  sw        $a3, 0x1c($v1)
/* 26054 8004AC54 AC660020 */  sw        $a2, 0x20($v1)
/* 26058 8004AC58 AC650028 */  sw        $a1, 0x28($v1)
/* 2605C 8004AC5C AC64002C */  sw        $a0, 0x2c($v1)
/* 26060 8004AC60 AC600030 */  sw        $zero, 0x30($v1)
/* 26064 8004AC64 AC600034 */  sw        $zero, 0x34($v1)
/* 26068 8004AC68 AC600038 */  sw        $zero, 0x38($v1)
/* 2606C 8004AC6C AC60003C */  sw        $zero, 0x3c($v1)
/* 26070 8004AC70 AC600048 */  sw        $zero, 0x48($v1)
/* 26074 8004AC74 AC60004C */  sw        $zero, 0x4c($v1)
/* 26078 8004AC78 26310001 */  addiu     $s1, $s1, 1
/* 2607C 8004AC7C 2E220003 */  sltiu     $v0, $s1, 3
/* 26080 8004AC80 1440FFEF */  bnez      $v0, .L8004AC40
/* 26084 8004AC84 24630058 */   addiu    $v1, $v1, 0x58
/* 26088 8004AC88 0000882D */  daddu     $s1, $zero, $zero
/* 2608C 8004AC8C 3C10800A */  lui       $s0, %hi(D_800A3628)
/* 26090 8004AC90 26103628 */  addiu     $s0, $s0, %lo(D_800A3628)
.L8004AC94:
/* 26094 8004AC94 24050001 */  addiu     $a1, $zero, 1
/* 26098 8004AC98 02258821 */  addu      $s1, $s1, $a1
/* 2609C 8004AC9C 3C06800A */  lui       $a2, %hi(nuAuFrameSampleSize)
/* 260A0 8004ACA0 8CC63634 */  lw        $a2, %lo(nuAuFrameSampleSize)($a2)
/* 260A4 8004ACA4 8FA4002C */  lw        $a0, 0x2c($sp)
/* 260A8 8004ACA8 0C015FE4 */  jal       alHeapAlloc
/* 260AC 8004ACAC 00063080 */   sll      $a2, $a2, 2
/* 260B0 8004ACB0 AE020000 */  sw        $v0, ($s0)
/* 260B4 8004ACB4 2E220003 */  sltiu     $v0, $s1, 3
/* 260B8 8004ACB8 1440FFF6 */  bnez      $v0, .L8004AC94
/* 260BC 8004ACBC 26100004 */   addiu    $s0, $s0, 4
/* 260C0 8004ACC0 0000882D */  daddu     $s1, $zero, $zero
/* 260C4 8004ACC4 3C02800A */  lui       $v0, %hi(nuAuDmaBuf)
/* 260C8 8004ACC8 24423BE0 */  addiu     $v0, $v0, %lo(nuAuDmaBuf)
/* 260CC 8004ACCC 0040802D */  daddu     $s0, $v0, $zero
/* 260D0 8004ACD0 26120014 */  addiu     $s2, $s0, 0x14
/* 260D4 8004ACD4 AE000004 */  sw        $zero, 4($s0)
/* 260D8 8004ACD8 AE000000 */  sw        $zero, ($s0)
.L8004ACDC:
/* 260DC 8004ACDC 0240202D */  daddu     $a0, $s2, $zero
/* 260E0 8004ACE0 0C012CFB */  jal       alLink
/* 260E4 8004ACE4 0200282D */   daddu    $a1, $s0, $zero
/* 260E8 8004ACE8 24050001 */  addiu     $a1, $zero, 1
/* 260EC 8004ACEC 24060500 */  addiu     $a2, $zero, 0x500
/* 260F0 8004ACF0 26520014 */  addiu     $s2, $s2, 0x14
/* 260F4 8004ACF4 8FA4002C */  lw        $a0, 0x2c($sp)
/* 260F8 8004ACF8 0C015FE4 */  jal       alHeapAlloc
/* 260FC 8004ACFC 02258821 */   addu     $s1, $s1, $a1
/* 26100 8004AD00 AE020010 */  sw        $v0, 0x10($s0)
/* 26104 8004AD04 2E220031 */  sltiu     $v0, $s1, 0x31
/* 26108 8004AD08 1440FFF4 */  bnez      $v0, .L8004ACDC
/* 2610C 8004AD0C 26100014 */   addiu    $s0, $s0, 0x14
/* 26110 8004AD10 24050001 */  addiu     $a1, $zero, 1
/* 26114 8004AD14 8FA4002C */  lw        $a0, 0x2c($sp)
/* 26118 8004AD18 0C015FE4 */  jal       alHeapAlloc
/* 2611C 8004AD1C 24060500 */   addiu    $a2, $zero, 0x500
/* 26120 8004AD20 3C04800A */  lui       $a0, %hi(D_800A3640)
/* 26124 8004AD24 24843640 */  addiu     $a0, $a0, %lo(D_800A3640)
/* 26128 8004AD28 3C05800A */  lui       $a1, %hi(D_800A3658)
/* 2612C 8004AD2C 24A53658 */  addiu     $a1, $a1, %lo(D_800A3658)
/* 26130 8004AD30 00111880 */  sll       $v1, $s1, 2
/* 26134 8004AD34 00711821 */  addu      $v1, $v1, $s1
/* 26138 8004AD38 00031880 */  sll       $v1, $v1, 2
/* 2613C 8004AD3C 3C01800A */  lui       $at, %hi(D_800A3BF0)
/* 26140 8004AD40 00230821 */  addu      $at, $at, $v1
/* 26144 8004AD44 AC223BF0 */  sw        $v0, %lo(D_800A3BF0)($at)
/* 26148 8004AD48 0C019560 */  jal       osCreateMesgQueue
/* 2614C 8004AD4C 24060032 */   addiu    $a2, $zero, 0x32
/* 26150 8004AD50 3C04800C */  lui       $a0, %hi(D_800B91A0)
/* 26154 8004AD54 248491A0 */  addiu     $a0, $a0, %lo(D_800B91A0)
/* 26158 8004AD58 3C028005 */  lui       $v0, %hi(func_8004B328)
/* 2615C 8004AD5C 2442B328 */  addiu     $v0, $v0, %lo(func_8004B328)
/* 26160 8004AD60 3C018008 */  lui       $at, %hi(nuAuPreNMIFunc)
/* 26164 8004AD64 AC228174 */  sw        $v0, %lo(nuAuPreNMIFunc)($at)
/* 26168 8004AD68 0C015894 */  jal       func_80056250
/* 2616C 8004AD6C 27A50018 */   addiu    $a1, $sp, 0x18
/* 26170 8004AD70 8FA40020 */  lw        $a0, 0x20($sp)
/* 26174 8004AD74 0C014B97 */  jal       func_80052E5C
/* 26178 8004AD78 00000000 */   nop
/* 2617C 8004AD7C 3C10800A */  lui       $s0, %hi(D_800A0F58)
/* 26180 8004AD80 26100F58 */  addiu     $s0, $s0, %lo(D_800A0F58)
/* 26184 8004AD84 0200202D */  daddu     $a0, $s0, $zero
/* 26188 8004AD88 24050003 */  addiu     $a1, $zero, 3
/* 2618C 8004AD8C 3C068005 */  lui       $a2, %hi(func_8004AE08)
/* 26190 8004AD90 24C6AE08 */  addiu     $a2, $a2, %lo(func_8004AE08)
/* 26194 8004AD94 3C02800A */  lui       $v0, %hi(D_800A3510)
/* 26198 8004AD98 24423510 */  addiu     $v0, $v0, %lo(D_800A3510)
/* 2619C 8004AD9C AFA20010 */  sw        $v0, 0x10($sp)
/* 261A0 8004ADA0 24020046 */  addiu     $v0, $zero, 0x46
/* 261A4 8004ADA4 0000382D */  daddu     $a3, $zero, $zero
/* 261A8 8004ADA8 0C019798 */  jal       osCreateThread
/* 261AC 8004ADAC AFA20014 */   sw       $v0, 0x14($sp)
/* 261B0 8004ADB0 0C019808 */  jal       osStartThread
/* 261B4 8004ADB4 0200202D */   daddu    $a0, $s0, $zero
/* 261B8 8004ADB8 8FBF003C */  lw        $ra, 0x3c($sp)
/* 261BC 8004ADBC 8FB20038 */  lw        $s2, 0x38($sp)
/* 261C0 8004ADC0 8FB10034 */  lw        $s1, 0x34($sp)
/* 261C4 8004ADC4 8FB00030 */  lw        $s0, 0x30($sp)
/* 261C8 8004ADC8 03E00008 */  jr        $ra
/* 261CC 8004ADCC 27BD0040 */   addiu    $sp, $sp, 0x40
