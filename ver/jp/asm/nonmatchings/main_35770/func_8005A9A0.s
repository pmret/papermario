.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8005A9A0
/* 35DA0 8005A9A0 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 35DA4 8005A9A4 AFB00030 */  sw        $s0, 0x30($sp)
/* 35DA8 8005A9A8 0080802D */  daddu     $s0, $a0, $zero
/* 35DAC 8005A9AC AFB3003C */  sw        $s3, 0x3c($sp)
/* 35DB0 8005A9B0 00A0982D */  daddu     $s3, $a1, $zero
/* 35DB4 8005A9B4 3C0401E0 */  lui       $a0, 0x1e0
/* 35DB8 8005A9B8 34840020 */  ori       $a0, $a0, 0x20
/* 35DBC 8005A9BC 3C0501E0 */  lui       $a1, 0x1e0
/* 35DC0 8005A9C0 34A5003C */  ori       $a1, $a1, 0x3c
/* 35DC4 8005A9C4 27A60010 */  addiu     $a2, $sp, 0x10
/* 35DC8 8005A9C8 AFBF0040 */  sw        $ra, 0x40($sp)
/* 35DCC 8005A9CC AFB20038 */  sw        $s2, 0x38($sp)
/* 35DD0 8005A9D0 0C00A5BF */  jal       func_800296FC
/* 35DD4 8005A9D4 AFB10034 */   sw       $s1, 0x34($sp)
/* 35DD8 8005A9D8 8FA40020 */  lw        $a0, 0x20($sp)
/* 35DDC 8005A9DC 0C00AB29 */  jal       func_8002ACA4
/* 35DE0 8005A9E0 00000000 */   nop
/* 35DE4 8005A9E4 0040902D */  daddu     $s2, $v0, $zero
/* 35DE8 8005A9E8 0240882D */  daddu     $s1, $s2, $zero
/* 35DEC 8005A9EC 3C0201E0 */  lui       $v0, 0x1e0
/* 35DF0 8005A9F0 34420020 */  ori       $v0, $v0, 0x20
/* 35DF4 8005A9F4 3C0401E0 */  lui       $a0, 0x1e0
/* 35DF8 8005A9F8 34840020 */  ori       $a0, $a0, 0x20
/* 35DFC 8005A9FC 8FA50020 */  lw        $a1, 0x20($sp)
/* 35E00 8005AA00 0240302D */  daddu     $a2, $s2, $zero
/* 35E04 8005AA04 0C00A5BF */  jal       func_800296FC
/* 35E08 8005AA08 00A22821 */   addu     $a1, $a1, $v0
.L8005AA0C:
/* 35E0C 8005AA0C 0220202D */  daddu     $a0, $s1, $zero
/* 35E10 8005AA10 0C01BB54 */  jal       func_8006ED50
/* 35E14 8005AA14 0200282D */   daddu    $a1, $s0, $zero
/* 35E18 8005AA18 10400003 */  beqz      $v0, .L8005AA28
/* 35E1C 8005AA1C 00000000 */   nop
/* 35E20 8005AA20 08016A83 */  j         .L8005AA0C
/* 35E24 8005AA24 2631001C */   addiu    $s1, $s1, 0x1c
.L8005AA28:
/* 35E28 8005AA28 8E220018 */  lw        $v0, 0x18($s1)
/* 35E2C 8005AA2C AE620000 */  sw        $v0, ($s3)
/* 35E30 8005AA30 0C00AAFA */  jal       func_8002ABE8
/* 35E34 8005AA34 8E240014 */   lw       $a0, 0x14($s1)
/* 35E38 8005AA38 3C0301E0 */  lui       $v1, 0x1e0
/* 35E3C 8005AA3C 34630020 */  ori       $v1, $v1, 0x20
/* 35E40 8005AA40 0040802D */  daddu     $s0, $v0, $zero
/* 35E44 8005AA44 0040302D */  daddu     $a2, $v0, $zero
/* 35E48 8005AA48 8E220010 */  lw        $v0, 0x10($s1)
/* 35E4C 8005AA4C 8E250014 */  lw        $a1, 0x14($s1)
/* 35E50 8005AA50 00432021 */  addu      $a0, $v0, $v1
/* 35E54 8005AA54 00A32821 */  addu      $a1, $a1, $v1
/* 35E58 8005AA58 0C00A5BF */  jal       func_800296FC
/* 35E5C 8005AA5C 00452821 */   addu     $a1, $v0, $a1
/* 35E60 8005AA60 0C00AB3B */  jal       func_8002ACEC
/* 35E64 8005AA64 0240202D */   daddu    $a0, $s2, $zero
/* 35E68 8005AA68 0200102D */  daddu     $v0, $s0, $zero
/* 35E6C 8005AA6C 8FBF0040 */  lw        $ra, 0x40($sp)
/* 35E70 8005AA70 8FB3003C */  lw        $s3, 0x3c($sp)
/* 35E74 8005AA74 8FB20038 */  lw        $s2, 0x38($sp)
/* 35E78 8005AA78 8FB10034 */  lw        $s1, 0x34($sp)
/* 35E7C 8005AA7C 8FB00030 */  lw        $s0, 0x30($sp)
/* 35E80 8005AA80 03E00008 */  jr        $ra
/* 35E84 8005AA84 27BD0048 */   addiu    $sp, $sp, 0x48
