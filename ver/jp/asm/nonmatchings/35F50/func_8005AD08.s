.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8005AD08
/* 36108 8005AD08 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 3610C 8005AD0C AFBF002C */  sw        $ra, 0x2c($sp)
/* 36110 8005AD10 AFB60028 */  sw        $s6, 0x28($sp)
/* 36114 8005AD14 AFB50024 */  sw        $s5, 0x24($sp)
/* 36118 8005AD18 AFB40020 */  sw        $s4, 0x20($sp)
/* 3611C 8005AD1C AFB3001C */  sw        $s3, 0x1c($sp)
/* 36120 8005AD20 AFB20018 */  sw        $s2, 0x18($sp)
/* 36124 8005AD24 AFB10014 */  sw        $s1, 0x14($sp)
/* 36128 8005AD28 0C016B1C */  jal       func_8005AC70
/* 3612C 8005AD2C AFB00010 */   sw       $s0, 0x10($sp)
/* 36130 8005AD30 3C13800B */  lui       $s3, %hi(D_800B42C0)
/* 36134 8005AD34 267342C0 */  addiu     $s3, $s3, %lo(D_800B42C0)
/* 36138 8005AD38 8662000C */  lh        $v0, 0xc($s3)
/* 3613C 8005AD3C 3C11800A */  lui       $s1, %hi(D_800A2074)
/* 36140 8005AD40 8E312074 */  lw        $s1, %lo(D_800A2074)($s1)
/* 36144 8005AD44 1840001C */  blez      $v0, .L8005ADB8
/* 36148 8005AD48 0000902D */   daddu    $s2, $zero, $zero
/* 3614C 8005AD4C 2416FFFF */  addiu     $s6, $zero, -1
/* 36150 8005AD50 3C158000 */  lui       $s5, 0x8000
/* 36154 8005AD54 0240A02D */  daddu     $s4, $s2, $zero
.L8005AD58:
/* 36158 8005AD58 8E620004 */  lw        $v0, 4($s3)
/* 3615C 8005AD5C 8E230000 */  lw        $v1, ($s1)
/* 36160 8005AD60 00542021 */  addu      $a0, $v0, $s4
/* 36164 8005AD64 AC830000 */  sw        $v1, ($a0)
/* 36168 8005AD68 96250004 */  lhu       $a1, 4($s1)
/* 3616C 8005AD6C 0060102D */  daddu     $v0, $v1, $zero
/* 36170 8005AD70 1056000B */  beq       $v0, $s6, .L8005ADA0
/* 36174 8005AD74 A4850008 */   sh       $a1, 8($a0)
/* 36178 8005AD78 00551024 */  and       $v0, $v0, $s5
/* 3617C 8005AD7C 10400008 */  beqz      $v0, .L8005ADA0
/* 36180 8005AD80 00052C00 */   sll      $a1, $a1, 0x10
/* 36184 8005AD84 00128400 */  sll       $s0, $s2, 0x10
/* 36188 8005AD88 00108403 */  sra       $s0, $s0, 0x10
/* 3618C 8005AD8C 0200202D */  daddu     $a0, $s0, $zero
/* 36190 8005AD90 0C016D0C */  jal       func_8005B430
/* 36194 8005AD94 00052C03 */   sra      $a1, $a1, 0x10
/* 36198 8005AD98 0C016DB5 */  jal       func_8005B6D4
/* 3619C 8005AD9C 0200202D */   daddu    $a0, $s0, $zero
.L8005ADA0:
/* 361A0 8005ADA0 2694001C */  addiu     $s4, $s4, 0x1c
/* 361A4 8005ADA4 26520001 */  addiu     $s2, $s2, 1
/* 361A8 8005ADA8 8662000C */  lh        $v0, 0xc($s3)
/* 361AC 8005ADAC 0242102A */  slt       $v0, $s2, $v0
/* 361B0 8005ADB0 1440FFE9 */  bnez      $v0, .L8005AD58
/* 361B4 8005ADB4 26310008 */   addiu    $s1, $s1, 8
.L8005ADB8:
/* 361B8 8005ADB8 3C13800E */  lui       $s3, %hi(D_800D91B0)
/* 361BC 8005ADBC 267391B0 */  addiu     $s3, $s3, %lo(D_800D91B0)
/* 361C0 8005ADC0 8662000C */  lh        $v0, 0xc($s3)
/* 361C4 8005ADC4 3C11800A */  lui       $s1, %hi(D_800A2078)
/* 361C8 8005ADC8 8E312078 */  lw        $s1, %lo(D_800A2078)($s1)
/* 361CC 8005ADCC 1840000E */  blez      $v0, .L8005AE08
/* 361D0 8005ADD0 0000902D */   daddu    $s2, $zero, $zero
/* 361D4 8005ADD4 0240282D */  daddu     $a1, $s2, $zero
.L8005ADD8:
/* 361D8 8005ADD8 26520001 */  addiu     $s2, $s2, 1
/* 361DC 8005ADDC 8E620004 */  lw        $v0, 4($s3)
/* 361E0 8005ADE0 8E230000 */  lw        $v1, ($s1)
/* 361E4 8005ADE4 00452021 */  addu      $a0, $v0, $a1
/* 361E8 8005ADE8 AC830000 */  sw        $v1, ($a0)
/* 361EC 8005ADEC 96220004 */  lhu       $v0, 4($s1)
/* 361F0 8005ADF0 24A5001C */  addiu     $a1, $a1, 0x1c
/* 361F4 8005ADF4 A4820008 */  sh        $v0, 8($a0)
/* 361F8 8005ADF8 8662000C */  lh        $v0, 0xc($s3)
/* 361FC 8005ADFC 0242102A */  slt       $v0, $s2, $v0
/* 36200 8005AE00 1440FFF5 */  bnez      $v0, .L8005ADD8
/* 36204 8005AE04 26310008 */   addiu    $s1, $s1, 8
.L8005AE08:
/* 36208 8005AE08 3C04800A */  lui       $a0, %hi(D_800A2074)
/* 3620C 8005AE0C 8C842074 */  lw        $a0, %lo(D_800A2074)($a0)
/* 36210 8005AE10 0C00AB0E */  jal       func_8002AC38
/* 36214 8005AE14 00000000 */   nop
/* 36218 8005AE18 3C04800A */  lui       $a0, %hi(D_800A2078)
/* 3621C 8005AE1C 8C842078 */  lw        $a0, %lo(D_800A2078)($a0)
/* 36220 8005AE20 0C00AB0E */  jal       func_8002AC38
/* 36224 8005AE24 00000000 */   nop
/* 36228 8005AE28 8FBF002C */  lw        $ra, 0x2c($sp)
/* 3622C 8005AE2C 8FB60028 */  lw        $s6, 0x28($sp)
/* 36230 8005AE30 8FB50024 */  lw        $s5, 0x24($sp)
/* 36234 8005AE34 8FB40020 */  lw        $s4, 0x20($sp)
/* 36238 8005AE38 8FB3001C */  lw        $s3, 0x1c($sp)
/* 3623C 8005AE3C 8FB20018 */  lw        $s2, 0x18($sp)
/* 36240 8005AE40 8FB10014 */  lw        $s1, 0x14($sp)
/* 36244 8005AE44 8FB00010 */  lw        $s0, 0x10($sp)
/* 36248 8005AE48 03E00008 */  jr        $ra
/* 3624C 8005AE4C 27BD0030 */   addiu    $sp, $sp, 0x30
