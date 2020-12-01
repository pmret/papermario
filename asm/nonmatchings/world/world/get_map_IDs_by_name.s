.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel get_map_IDs_by_name
/* 35FF8 8005ABF8 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 35FFC 8005ABFC AFB50024 */  sw        $s5, 0x24($sp)
/* 36000 8005AC00 0080A82D */  daddu     $s5, $a0, $zero
/* 36004 8005AC04 AFB60028 */  sw        $s6, 0x28($sp)
/* 36008 8005AC08 00A0B02D */  daddu     $s6, $a1, $zero
/* 3600C 8005AC0C AFB7002C */  sw        $s7, 0x2c($sp)
/* 36010 8005AC10 00C0B82D */  daddu     $s7, $a2, $zero
/* 36014 8005AC14 3C028009 */  lui       $v0, %hi(gAreas)
/* 36018 8005AC18 244234F0 */  addiu     $v0, $v0, %lo(gAreas)
/* 3601C 8005AC1C AFBF0030 */  sw        $ra, 0x30($sp)
/* 36020 8005AC20 AFB40020 */  sw        $s4, 0x20($sp)
/* 36024 8005AC24 AFB3001C */  sw        $s3, 0x1c($sp)
/* 36028 8005AC28 AFB20018 */  sw        $s2, 0x18($sp)
/* 3602C 8005AC2C AFB10014 */  sw        $s1, 0x14($sp)
/* 36030 8005AC30 AFB00010 */  sw        $s0, 0x10($sp)
/* 36034 8005AC34 8C440004 */  lw        $a0, 4($v0)
/* 36038 8005AC38 1080001F */  beqz      $a0, .L8005ACB8
/* 3603C 8005AC3C 0000A02D */   daddu    $s4, $zero, $zero
/* 36040 8005AC40 0280902D */  daddu     $s2, $s4, $zero
.L8005AC44:
/* 36044 8005AC44 02421021 */  addu      $v0, $s2, $v0
/* 36048 8005AC48 8C420000 */  lw        $v0, ($v0)
/* 3604C 8005AC4C 18400012 */  blez      $v0, .L8005AC98
/* 36050 8005AC50 0000802D */   daddu    $s0, $zero, $zero
/* 36054 8005AC54 3C028009 */  lui       $v0, %hi(gAreas)
/* 36058 8005AC58 244234F0 */  addiu     $v0, $v0, %lo(gAreas)
/* 3605C 8005AC5C 02429821 */  addu      $s3, $s2, $v0
/* 36060 8005AC60 0080882D */  daddu     $s1, $a0, $zero
.L8005AC64:
/* 36064 8005AC64 8E240000 */  lw        $a0, ($s1)
/* 36068 8005AC68 0C01BB5C */  jal       strcmp
/* 3606C 8005AC6C 02A0282D */   daddu    $a1, $s5, $zero
/* 36070 8005AC70 54400005 */  bnel      $v0, $zero, .L8005AC88
/* 36074 8005AC74 26100001 */   addiu    $s0, $s0, 1
/* 36078 8005AC78 24020001 */  addiu     $v0, $zero, 1
/* 3607C 8005AC7C A6D40000 */  sh        $s4, ($s6)
/* 36080 8005AC80 08016B2F */  j         .L8005ACBC
/* 36084 8005AC84 A6F00000 */   sh       $s0, ($s7)
.L8005AC88:
/* 36088 8005AC88 8E620000 */  lw        $v0, ($s3)
/* 3608C 8005AC8C 0202102A */  slt       $v0, $s0, $v0
/* 36090 8005AC90 1440FFF4 */  bnez      $v0, .L8005AC64
/* 36094 8005AC94 26310020 */   addiu    $s1, $s1, 0x20
.L8005AC98:
/* 36098 8005AC98 26520010 */  addiu     $s2, $s2, 0x10
/* 3609C 8005AC9C 3C048009 */  lui       $a0, %hi(D_800934F4)
/* 360A0 8005ACA0 00922021 */  addu      $a0, $a0, $s2
/* 360A4 8005ACA4 8C8434F4 */  lw        $a0, %lo(D_800934F4)($a0)
/* 360A8 8005ACA8 3C028009 */  lui       $v0, %hi(gAreas)
/* 360AC 8005ACAC 244234F0 */  addiu     $v0, $v0, %lo(gAreas)
/* 360B0 8005ACB0 1480FFE4 */  bnez      $a0, .L8005AC44
/* 360B4 8005ACB4 26940001 */   addiu    $s4, $s4, 1
.L8005ACB8:
/* 360B8 8005ACB8 0000102D */  daddu     $v0, $zero, $zero
.L8005ACBC:
/* 360BC 8005ACBC 8FBF0030 */  lw        $ra, 0x30($sp)
/* 360C0 8005ACC0 8FB7002C */  lw        $s7, 0x2c($sp)
/* 360C4 8005ACC4 8FB60028 */  lw        $s6, 0x28($sp)
/* 360C8 8005ACC8 8FB50024 */  lw        $s5, 0x24($sp)
/* 360CC 8005ACCC 8FB40020 */  lw        $s4, 0x20($sp)
/* 360D0 8005ACD0 8FB3001C */  lw        $s3, 0x1c($sp)
/* 360D4 8005ACD4 8FB20018 */  lw        $s2, 0x18($sp)
/* 360D8 8005ACD8 8FB10014 */  lw        $s1, 0x14($sp)
/* 360DC 8005ACDC 8FB00010 */  lw        $s0, 0x10($sp)
/* 360E0 8005ACE0 03E00008 */  jr        $ra
/* 360E4 8005ACE4 27BD0038 */   addiu    $sp, $sp, 0x38
