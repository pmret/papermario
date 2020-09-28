.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80041964
/* 1CD64 80041964 27BDFF88 */  addiu     $sp, $sp, -0x78
/* 1CD68 80041968 AFB00038 */  sw        $s0, 0x38($sp)
/* 1CD6C 8004196C 3C10800B */  lui       $s0, %hi(gCurrentEncounter)
/* 1CD70 80041970 26100F10 */  addiu     $s0, $s0, %lo(gCurrentEncounter)
/* 1CD74 80041974 AFBF0040 */  sw        $ra, 0x40($sp)
/* 1CD78 80041978 AFB1003C */  sw        $s1, 0x3c($sp)
/* 1CD7C 8004197C F7BE0070 */  sdc1      $f30, 0x70($sp)
/* 1CD80 80041980 F7BC0068 */  sdc1      $f28, 0x68($sp)
/* 1CD84 80041984 F7BA0060 */  sdc1      $f26, 0x60($sp)
/* 1CD88 80041988 F7B80058 */  sdc1      $f24, 0x58($sp)
/* 1CD8C 8004198C F7B60050 */  sdc1      $f22, 0x50($sp)
/* 1CD90 80041990 F7B40048 */  sdc1      $f20, 0x48($sp)
/* 1CD94 80041994 8E02008C */  lw        $v0, 0x8c($s0)
/* 1CD98 80041998 84440008 */  lh        $a0, 8($v0)
/* 1CD9C 8004199C 0C00EABB */  jal       get_npc_unsafe
/* 1CDA0 800419A0 0200882D */   daddu    $s1, $s0, $zero
/* 1CDA4 800419A4 0040382D */  daddu     $a3, $v0, $zero
/* 1CDA8 800419A8 8E020094 */  lw        $v0, 0x94($s0)
/* 1CDAC 800419AC 3C048011 */  lui       $a0, %hi(gPlayerStatus)
/* 1CDB0 800419B0 2484EFC8 */  addiu     $a0, $a0, %lo(gPlayerStatus)
/* 1CDB4 800419B4 1040009E */  beqz      $v0, .L80041C30
/* 1CDB8 800419B8 240500FF */   addiu    $a1, $zero, 0xff
/* 1CDBC 800419BC 8E030090 */  lw        $v1, 0x90($s0)
/* 1CDC0 800419C0 1065009B */  beq       $v1, $a1, .L80041C30
/* 1CDC4 800419C4 00000000 */   nop      
/* 1CDC8 800419C8 8E020098 */  lw        $v0, 0x98($s0)
/* 1CDCC 800419CC 24420001 */  addiu     $v0, $v0, 1
/* 1CDD0 800419D0 AE020098 */  sw        $v0, 0x98($s0)
/* 1CDD4 800419D4 2842000B */  slti      $v0, $v0, 0xb
/* 1CDD8 800419D8 14400002 */  bnez      $v0, .L800419E4
/* 1CDDC 800419DC 2402000A */   addiu    $v0, $zero, 0xa
/* 1CDE0 800419E0 AE020098 */  sw        $v0, 0x98($s0)
.L800419E4:
/* 1CDE4 800419E4 8E020098 */  lw        $v0, 0x98($s0)
/* 1CDE8 800419E8 00621021 */  addu      $v0, $v1, $v0
/* 1CDEC 800419EC AE020090 */  sw        $v0, 0x90($s0)
/* 1CDF0 800419F0 28420100 */  slti      $v0, $v0, 0x100
/* 1CDF4 800419F4 50400001 */  beql      $v0, $zero, .L800419FC
/* 1CDF8 800419F8 AE050090 */   sw       $a1, 0x90($s0)
.L800419FC:
/* 1CDFC 800419FC C4FE0038 */  lwc1      $f30, 0x38($a3)
/* 1CE00 80041A00 C4FA003C */  lwc1      $f26, 0x3c($a3)
/* 1CE04 80041A04 3C01C477 */  lui       $at, 0xc477
/* 1CE08 80041A08 34218000 */  ori       $at, $at, 0x8000
/* 1CE0C 80041A0C 44810000 */  mtc1      $at, $f0
/* 1CE10 80041A10 C4FC0040 */  lwc1      $f28, 0x40($a3)
/* 1CE14 80041A14 C4940028 */  lwc1      $f20, 0x28($a0)
/* 1CE18 80041A18 C498002C */  lwc1      $f24, 0x2c($a0)
/* 1CE1C 80041A1C C4960030 */  lwc1      $f22, 0x30($a0)
/* 1CE20 80041A20 4600D03C */  c.lt.s    $f26, $f0
/* 1CE24 80041A24 00000000 */  nop       
/* 1CE28 80041A28 45000004 */  bc1f      .L80041A3C
/* 1CE2C 80041A2C 00000000 */   nop      
/* 1CE30 80041A30 4600A786 */  mov.s     $f30, $f20
/* 1CE34 80041A34 4600C686 */  mov.s     $f26, $f24
/* 1CE38 80041A38 4600B706 */  mov.s     $f28, $f22
.L80041A3C:
/* 1CE3C 80041A3C 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 1CE40 80041A40 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 1CE44 80041A44 80430071 */  lb        $v1, 0x71($v0)
/* 1CE48 80041A48 24020002 */  addiu     $v0, $zero, 2
/* 1CE4C 80041A4C 1462003C */  bne       $v1, $v0, .L80041B40
/* 1CE50 80041A50 00000000 */   nop      
/* 1CE54 80041A54 C6020090 */  lwc1      $f2, 0x90($s0)
/* 1CE58 80041A58 468010A0 */  cvt.s.w   $f2, $f2
/* 1CE5C 80041A5C 44051000 */  mfc1      $a1, $f2
/* 1CE60 80041A60 0C04DF69 */  jal       func_80137DA4
/* 1CE64 80041A64 2404000A */   addiu    $a0, $zero, 0xa
/* 1CE68 80041A68 3C05437F */  lui       $a1, 0x437f
/* 1CE6C 80041A6C 0C04E035 */  jal       func_801380D4
/* 1CE70 80041A70 24040001 */   addiu    $a0, $zero, 1
/* 1CE74 80041A74 24040001 */  addiu     $a0, $zero, 1
/* 1CE78 80041A78 0000282D */  daddu     $a1, $zero, $zero
/* 1CE7C 80041A7C 00A0302D */  daddu     $a2, $a1, $zero
/* 1CE80 80041A80 0C04DF84 */  jal       func_80137E10
/* 1CE84 80041A84 00A0382D */   daddu    $a3, $a1, $zero
/* 1CE88 80041A88 3C108007 */  lui       $s0, %hi(gCurrentCameraID)
/* 1CE8C 80041A8C 26107410 */  addiu     $s0, $s0, %lo(gCurrentCameraID)
/* 1CE90 80041A90 8E040000 */  lw        $a0, ($s0)
/* 1CE94 80041A94 4405A000 */  mfc1      $a1, $f20
/* 1CE98 80041A98 4407B000 */  mfc1      $a3, $f22
/* 1CE9C 80041A9C 3C0141A0 */  lui       $at, 0x41a0
/* 1CEA0 80041AA0 44810000 */  mtc1      $at, $f0
/* 1CEA4 80041AA4 27A20020 */  addiu     $v0, $sp, 0x20
/* 1CEA8 80041AA8 AFA20010 */  sw        $v0, 0x10($sp)
/* 1CEAC 80041AAC 4600C600 */  add.s     $f24, $f24, $f0
/* 1CEB0 80041AB0 27A20024 */  addiu     $v0, $sp, 0x24
/* 1CEB4 80041AB4 AFA20014 */  sw        $v0, 0x14($sp)
/* 1CEB8 80041AB8 4406C000 */  mfc1      $a2, $f24
/* 1CEBC 80041ABC 27A20028 */  addiu     $v0, $sp, 0x28
/* 1CEC0 80041AC0 0C00B94E */  jal       get_screen_coords
/* 1CEC4 80041AC4 AFA20018 */   sw       $v0, 0x18($sp)
/* 1CEC8 80041AC8 8E040000 */  lw        $a0, ($s0)
/* 1CECC 80041ACC 4405F000 */  mfc1      $a1, $f30
/* 1CED0 80041AD0 4407E000 */  mfc1      $a3, $f28
/* 1CED4 80041AD4 3C014170 */  lui       $at, 0x4170
/* 1CED8 80041AD8 44810000 */  mtc1      $at, $f0
/* 1CEDC 80041ADC 27A2002C */  addiu     $v0, $sp, 0x2c
/* 1CEE0 80041AE0 AFA20010 */  sw        $v0, 0x10($sp)
/* 1CEE4 80041AE4 4600D680 */  add.s     $f26, $f26, $f0
/* 1CEE8 80041AE8 27A20030 */  addiu     $v0, $sp, 0x30
/* 1CEEC 80041AEC AFA20014 */  sw        $v0, 0x14($sp)
/* 1CEF0 80041AF0 4406D000 */  mfc1      $a2, $f26
/* 1CEF4 80041AF4 27A20034 */  addiu     $v0, $sp, 0x34
/* 1CEF8 80041AF8 0C00B94E */  jal       get_screen_coords
/* 1CEFC 80041AFC AFA20018 */   sw       $v0, 0x18($sp)
/* 1CF00 80041B00 24040001 */  addiu     $a0, $zero, 1
/* 1CF04 80041B04 0000282D */  daddu     $a1, $zero, $zero
/* 1CF08 80041B08 8FA60020 */  lw        $a2, 0x20($sp)
/* 1CF0C 80041B0C 8FA8002C */  lw        $t0, 0x2c($sp)
/* 1CF10 80041B10 8FA70024 */  lw        $a3, 0x24($sp)
/* 1CF14 80041B14 8FA30030 */  lw        $v1, 0x30($sp)
/* 1CF18 80041B18 00C83023 */  subu      $a2, $a2, $t0
/* 1CF1C 80041B1C 000617C2 */  srl       $v0, $a2, 0x1f
/* 1CF20 80041B20 00C23021 */  addu      $a2, $a2, $v0
/* 1CF24 80041B24 00863007 */  srav      $a2, $a2, $a0
/* 1CF28 80041B28 00C83021 */  addu      $a2, $a2, $t0
/* 1CF2C 80041B2C 00E33823 */  subu      $a3, $a3, $v1
/* 1CF30 80041B30 000717C2 */  srl       $v0, $a3, 0x1f
/* 1CF34 80041B34 00E23821 */  addu      $a3, $a3, $v0
/* 1CF38 80041B38 0801070A */  j         .L80041C28
/* 1CF3C 80041B3C 00873807 */   srav     $a3, $a3, $a0
.L80041B40:
/* 1CF40 80041B40 C6220090 */  lwc1      $f2, 0x90($s1)
/* 1CF44 80041B44 468010A0 */  cvt.s.w   $f2, $f2
/* 1CF48 80041B48 44051000 */  mfc1      $a1, $f2
/* 1CF4C 80041B4C 0C04DF62 */  jal       func_80137D88
/* 1CF50 80041B50 2404000A */   addiu    $a0, $zero, 0xa
/* 1CF54 80041B54 3C05437F */  lui       $a1, 0x437f
/* 1CF58 80041B58 0C04E035 */  jal       func_801380D4
/* 1CF5C 80041B5C 0000202D */   daddu    $a0, $zero, $zero
/* 1CF60 80041B60 0000202D */  daddu     $a0, $zero, $zero
/* 1CF64 80041B64 0080282D */  daddu     $a1, $a0, $zero
/* 1CF68 80041B68 0080302D */  daddu     $a2, $a0, $zero
/* 1CF6C 80041B6C 0C04DF84 */  jal       func_80137E10
/* 1CF70 80041B70 0080382D */   daddu    $a3, $a0, $zero
/* 1CF74 80041B74 3C108007 */  lui       $s0, %hi(gCurrentCameraID)
/* 1CF78 80041B78 26107410 */  addiu     $s0, $s0, %lo(gCurrentCameraID)
/* 1CF7C 80041B7C 8E040000 */  lw        $a0, ($s0)
/* 1CF80 80041B80 4405A000 */  mfc1      $a1, $f20
/* 1CF84 80041B84 4407B000 */  mfc1      $a3, $f22
/* 1CF88 80041B88 3C0141A0 */  lui       $at, 0x41a0
/* 1CF8C 80041B8C 44810000 */  mtc1      $at, $f0
/* 1CF90 80041B90 27A20020 */  addiu     $v0, $sp, 0x20
/* 1CF94 80041B94 AFA20010 */  sw        $v0, 0x10($sp)
/* 1CF98 80041B98 4600C600 */  add.s     $f24, $f24, $f0
/* 1CF9C 80041B9C 27A20024 */  addiu     $v0, $sp, 0x24
/* 1CFA0 80041BA0 AFA20014 */  sw        $v0, 0x14($sp)
/* 1CFA4 80041BA4 4406C000 */  mfc1      $a2, $f24
/* 1CFA8 80041BA8 27A20028 */  addiu     $v0, $sp, 0x28
/* 1CFAC 80041BAC 0C00B94E */  jal       get_screen_coords
/* 1CFB0 80041BB0 AFA20018 */   sw       $v0, 0x18($sp)
/* 1CFB4 80041BB4 8E040000 */  lw        $a0, ($s0)
/* 1CFB8 80041BB8 4405F000 */  mfc1      $a1, $f30
/* 1CFBC 80041BBC 4407E000 */  mfc1      $a3, $f28
/* 1CFC0 80041BC0 3C014170 */  lui       $at, 0x4170
/* 1CFC4 80041BC4 44810000 */  mtc1      $at, $f0
/* 1CFC8 80041BC8 27A2002C */  addiu     $v0, $sp, 0x2c
/* 1CFCC 80041BCC AFA20010 */  sw        $v0, 0x10($sp)
/* 1CFD0 80041BD0 4600D680 */  add.s     $f26, $f26, $f0
/* 1CFD4 80041BD4 27A20030 */  addiu     $v0, $sp, 0x30
/* 1CFD8 80041BD8 AFA20014 */  sw        $v0, 0x14($sp)
/* 1CFDC 80041BDC 4406D000 */  mfc1      $a2, $f26
/* 1CFE0 80041BE0 27A20034 */  addiu     $v0, $sp, 0x34
/* 1CFE4 80041BE4 0C00B94E */  jal       get_screen_coords
/* 1CFE8 80041BE8 AFA20018 */   sw       $v0, 0x18($sp)
/* 1CFEC 80041BEC 0000202D */  daddu     $a0, $zero, $zero
/* 1CFF0 80041BF0 0080282D */  daddu     $a1, $a0, $zero
/* 1CFF4 80041BF4 8FA60020 */  lw        $a2, 0x20($sp)
/* 1CFF8 80041BF8 8FA8002C */  lw        $t0, 0x2c($sp)
/* 1CFFC 80041BFC 8FA70024 */  lw        $a3, 0x24($sp)
/* 1D000 80041C00 8FA30030 */  lw        $v1, 0x30($sp)
/* 1D004 80041C04 00C83023 */  subu      $a2, $a2, $t0
/* 1D008 80041C08 000617C2 */  srl       $v0, $a2, 0x1f
/* 1D00C 80041C0C 00C23021 */  addu      $a2, $a2, $v0
/* 1D010 80041C10 00063043 */  sra       $a2, $a2, 1
/* 1D014 80041C14 00C83021 */  addu      $a2, $a2, $t0
/* 1D018 80041C18 00E33823 */  subu      $a3, $a3, $v1
/* 1D01C 80041C1C 000717C2 */  srl       $v0, $a3, 0x1f
/* 1D020 80041C20 00E23821 */  addu      $a3, $a3, $v0
/* 1D024 80041C24 00073843 */  sra       $a3, $a3, 1
.L80041C28:
/* 1D028 80041C28 0C04DF93 */  jal       func_80137E4C
/* 1D02C 80041C2C 00E33821 */   addu     $a3, $a3, $v1
.L80041C30:
/* 1D030 80041C30 8FBF0040 */  lw        $ra, 0x40($sp)
/* 1D034 80041C34 8FB1003C */  lw        $s1, 0x3c($sp)
/* 1D038 80041C38 8FB00038 */  lw        $s0, 0x38($sp)
/* 1D03C 80041C3C D7BE0070 */  ldc1      $f30, 0x70($sp)
/* 1D040 80041C40 D7BC0068 */  ldc1      $f28, 0x68($sp)
/* 1D044 80041C44 D7BA0060 */  ldc1      $f26, 0x60($sp)
/* 1D048 80041C48 D7B80058 */  ldc1      $f24, 0x58($sp)
/* 1D04C 80041C4C D7B60050 */  ldc1      $f22, 0x50($sp)
/* 1D050 80041C50 D7B40048 */  ldc1      $f20, 0x48($sp)
/* 1D054 80041C54 03E00008 */  jr        $ra
/* 1D058 80041C58 27BD0078 */   addiu    $sp, $sp, 0x78
