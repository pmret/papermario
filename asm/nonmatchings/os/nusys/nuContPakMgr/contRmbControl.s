.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel contRmbControl
/* 3AD20 8005F920 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 3AD24 8005F924 AFB20018 */  sw        $s2, 0x18($sp)
/* 3AD28 8005F928 0080902D */  daddu     $s2, $a0, $zero
/* 3AD2C 8005F92C 00A0302D */  daddu     $a2, $a1, $zero
/* 3AD30 8005F930 AFB00010 */  sw        $s0, 0x10($sp)
/* 3AD34 8005F934 AFBF0020 */  sw        $ra, 0x20($sp)
/* 3AD38 8005F938 AFB3001C */  sw        $s3, 0x1c($sp)
/* 3AD3C 8005F93C AFB10014 */  sw        $s1, 0x14($sp)
/* 3AD40 8005F940 92430006 */  lbu       $v1, 6($s2)
/* 3AD44 8005F944 24130002 */  addiu     $s3, $zero, 2
/* 3AD48 8005F948 10730069 */  beq       $v1, $s3, .L8005FAF0
/* 3AD4C 8005F94C 0000802D */   daddu    $s0, $zero, $zero
/* 3AD50 8005F950 28620003 */  slti      $v0, $v1, 3
/* 3AD54 8005F954 10400005 */  beqz      $v0, .L8005F96C
/* 3AD58 8005F958 24020001 */   addiu    $v0, $zero, 1
/* 3AD5C 8005F95C 1062000A */  beq       $v1, $v0, .L8005F988
/* 3AD60 8005F960 0200102D */   daddu    $v0, $s0, $zero
/* 3AD64 8005F964 08017EBD */  j         .L8005FAF4
/* 3AD68 8005F968 00000000 */   nop
.L8005F96C:
/* 3AD6C 8005F96C 24020003 */  addiu     $v0, $zero, 3
/* 3AD70 8005F970 10620018 */  beq       $v1, $v0, .L8005F9D4
/* 3AD74 8005F974 24020004 */   addiu    $v0, $zero, 4
/* 3AD78 8005F978 10620048 */  beq       $v1, $v0, .L8005FA9C
/* 3AD7C 8005F97C 0200102D */   daddu    $v0, $s0, $zero
/* 3AD80 8005F980 08017EBD */  j         .L8005FAF4
/* 3AD84 8005F984 00000000 */   nop
.L8005F988:
/* 3AD88 8005F988 96420004 */  lhu       $v0, 4($s2)
/* 3AD8C 8005F98C 1040000C */  beqz      $v0, .L8005F9C0
/* 3AD90 8005F990 00062040 */   sll      $a0, $a2, 1
/* 3AD94 8005F994 00862021 */  addu      $a0, $a0, $a2
/* 3AD98 8005F998 00042080 */  sll       $a0, $a0, 2
/* 3AD9C 8005F99C 00862021 */  addu      $a0, $a0, $a2
/* 3ADA0 8005F9A0 000420C0 */  sll       $a0, $a0, 3
/* 3ADA4 8005F9A4 3C02800E */  lui       $v0, %hi(nuContPfs)
/* 3ADA8 8005F9A8 2442AAD8 */  addiu     $v0, $v0, %lo(nuContPfs)
/* 3ADAC 8005F9AC 00822021 */  addu      $a0, $a0, $v0
/* 3ADB0 8005F9B0 0C019F80 */  jal       __osMotorAccess
/* 3ADB4 8005F9B4 0000282D */   daddu    $a1, $zero, $zero
/* 3ADB8 8005F9B8 08017E71 */  j         .L8005F9C4
/* 3ADBC 8005F9BC 0040802D */   daddu    $s0, $v0, $zero
.L8005F9C0:
/* 3ADC0 8005F9C0 A2530006 */  sb        $s3, 6($s2)
.L8005F9C4:
/* 3ADC4 8005F9C4 96420004 */  lhu       $v0, 4($s2)
/* 3ADC8 8005F9C8 2442FFFF */  addiu     $v0, $v0, -1
/* 3ADCC 8005F9CC 08017EBC */  j         .L8005FAF0
/* 3ADD0 8005F9D0 A6420004 */   sh       $v0, 4($s2)
.L8005F9D4:
/* 3ADD4 8005F9D4 96420002 */  lhu       $v0, 2($s2)
/* 3ADD8 8005F9D8 1040001F */  beqz      $v0, .L8005FA58
/* 3ADDC 8005F9DC 00062040 */   sll      $a0, $a2, 1
/* 3ADE0 8005F9E0 96420004 */  lhu       $v0, 4($s2)
/* 3ADE4 8005F9E4 96430000 */  lhu       $v1, ($s2)
/* 3ADE8 8005F9E8 00431021 */  addu      $v0, $v0, $v1
/* 3ADEC 8005F9EC 304300FF */  andi      $v1, $v0, 0xff
/* 3ADF0 8005F9F0 3042FFFF */  andi      $v0, $v0, 0xffff
/* 3ADF4 8005F9F4 00021202 */  srl       $v0, $v0, 8
/* 3ADF8 8005F9F8 1040000B */  beqz      $v0, .L8005FA28
/* 3ADFC 8005F9FC A6430004 */   sh       $v1, 4($s2)
/* 3AE00 8005FA00 00062040 */  sll       $a0, $a2, 1
/* 3AE04 8005FA04 00862021 */  addu      $a0, $a0, $a2
/* 3AE08 8005FA08 00042080 */  sll       $a0, $a0, 2
/* 3AE0C 8005FA0C 00862021 */  addu      $a0, $a0, $a2
/* 3AE10 8005FA10 000420C0 */  sll       $a0, $a0, 3
/* 3AE14 8005FA14 3C02800E */  lui       $v0, %hi(nuContPfs)
/* 3AE18 8005FA18 2442AAD8 */  addiu     $v0, $v0, %lo(nuContPfs)
/* 3AE1C 8005FA1C 00822021 */  addu      $a0, $a0, $v0
/* 3AE20 8005FA20 08017E92 */  j         .L8005FA48
/* 3AE24 8005FA24 24050001 */   addiu    $a1, $zero, 1
.L8005FA28:
/* 3AE28 8005FA28 00862021 */  addu      $a0, $a0, $a2
/* 3AE2C 8005FA2C 00042080 */  sll       $a0, $a0, 2
/* 3AE30 8005FA30 00862021 */  addu      $a0, $a0, $a2
/* 3AE34 8005FA34 000420C0 */  sll       $a0, $a0, 3
/* 3AE38 8005FA38 3C02800E */  lui       $v0, %hi(nuContPfs)
/* 3AE3C 8005FA3C 2442AAD8 */  addiu     $v0, $v0, %lo(nuContPfs)
/* 3AE40 8005FA40 00822021 */  addu      $a0, $a0, $v0
/* 3AE44 8005FA44 0000282D */  daddu     $a1, $zero, $zero
.L8005FA48:
/* 3AE48 8005FA48 0C019F80 */  jal       __osMotorAccess
/* 3AE4C 8005FA4C 00000000 */   nop
/* 3AE50 8005FA50 08017EA3 */  j         .L8005FA8C
/* 3AE54 8005FA54 0040802D */   daddu    $s0, $v0, $zero
.L8005FA58:
/* 3AE58 8005FA58 00862021 */  addu      $a0, $a0, $a2
/* 3AE5C 8005FA5C 00042080 */  sll       $a0, $a0, 2
/* 3AE60 8005FA60 00862021 */  addu      $a0, $a0, $a2
/* 3AE64 8005FA64 000420C0 */  sll       $a0, $a0, 3
/* 3AE68 8005FA68 3C02800E */  lui       $v0, %hi(nuContPfs)
/* 3AE6C 8005FA6C 2442AAD8 */  addiu     $v0, $v0, %lo(nuContPfs)
/* 3AE70 8005FA70 00822021 */  addu      $a0, $a0, $v0
/* 3AE74 8005FA74 0C019F80 */  jal       __osMotorAccess
/* 3AE78 8005FA78 0000282D */   daddu    $a1, $zero, $zero
/* 3AE7C 8005FA7C 0040802D */  daddu     $s0, $v0, $zero
/* 3AE80 8005FA80 24020001 */  addiu     $v0, $zero, 1
/* 3AE84 8005FA84 A2420006 */  sb        $v0, 6($s2)
/* 3AE88 8005FA88 A6530004 */  sh        $s3, 4($s2)
.L8005FA8C:
/* 3AE8C 8005FA8C 96420002 */  lhu       $v0, 2($s2)
/* 3AE90 8005FA90 2442FFFF */  addiu     $v0, $v0, -1
/* 3AE94 8005FA94 08017EBC */  j         .L8005FAF0
/* 3AE98 8005FA98 A6420002 */   sh       $v0, 2($s2)
.L8005FA9C:
/* 3AE9C 8005FA9C 3C04800E */  lui       $a0, %hi(nuSiMesgQ)
/* 3AEA0 8005FAA0 2484AC78 */  addiu     $a0, $a0, %lo(nuSiMesgQ)
/* 3AEA4 8005FAA4 00061040 */  sll       $v0, $a2, 1
/* 3AEA8 8005FAA8 00461021 */  addu      $v0, $v0, $a2
/* 3AEAC 8005FAAC 00021080 */  sll       $v0, $v0, 2
/* 3AEB0 8005FAB0 00461021 */  addu      $v0, $v0, $a2
/* 3AEB4 8005FAB4 000210C0 */  sll       $v0, $v0, 3
/* 3AEB8 8005FAB8 3C03800E */  lui       $v1, %hi(nuContPfs)
/* 3AEBC 8005FABC 2463AAD8 */  addiu     $v1, $v1, %lo(nuContPfs)
/* 3AEC0 8005FAC0 00438821 */  addu      $s1, $v0, $v1
/* 3AEC4 8005FAC4 0C019FD1 */  jal       osMotorInit
/* 3AEC8 8005FAC8 0220282D */   daddu    $a1, $s1, $zero
/* 3AECC 8005FACC 0040802D */  daddu     $s0, $v0, $zero
/* 3AED0 8005FAD0 16000005 */  bnez      $s0, .L8005FAE8
/* 3AED4 8005FAD4 24020001 */   addiu    $v0, $zero, 1
/* 3AED8 8005FAD8 0220202D */  daddu     $a0, $s1, $zero
/* 3AEDC 8005FADC 0C019F80 */  jal       __osMotorAccess
/* 3AEE0 8005FAE0 0000282D */   daddu    $a1, $zero, $zero
/* 3AEE4 8005FAE4 24020001 */  addiu     $v0, $zero, 1
.L8005FAE8:
/* 3AEE8 8005FAE8 A2420006 */  sb        $v0, 6($s2)
/* 3AEEC 8005FAEC A6530004 */  sh        $s3, 4($s2)
.L8005FAF0:
/* 3AEF0 8005FAF0 0200102D */  daddu     $v0, $s0, $zero
.L8005FAF4:
/* 3AEF4 8005FAF4 8FBF0020 */  lw        $ra, 0x20($sp)
/* 3AEF8 8005FAF8 8FB3001C */  lw        $s3, 0x1c($sp)
/* 3AEFC 8005FAFC 8FB20018 */  lw        $s2, 0x18($sp)
/* 3AF00 8005FB00 8FB10014 */  lw        $s1, 0x14($sp)
/* 3AF04 8005FB04 8FB00010 */  lw        $s0, 0x10($sp)
/* 3AF08 8005FB08 03E00008 */  jr        $ra
/* 3AF0C 8005FB0C 27BD0028 */   addiu    $sp, $sp, 0x28
