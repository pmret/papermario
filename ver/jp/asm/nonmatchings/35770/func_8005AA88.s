.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8005AA88
/* 35E88 8005AA88 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 35E8C 8005AA8C AFB20038 */  sw        $s2, 0x38($sp)
/* 35E90 8005AA90 0080902D */  daddu     $s2, $a0, $zero
/* 35E94 8005AA94 AFB3003C */  sw        $s3, 0x3c($sp)
/* 35E98 8005AA98 00A0982D */  daddu     $s3, $a1, $zero
/* 35E9C 8005AA9C 3C0401E0 */  lui       $a0, 0x1e0
/* 35EA0 8005AAA0 34840020 */  ori       $a0, $a0, 0x20
/* 35EA4 8005AAA4 3C0501E0 */  lui       $a1, 0x1e0
/* 35EA8 8005AAA8 34A5003C */  ori       $a1, $a1, 0x3c
/* 35EAC 8005AAAC 27A60010 */  addiu     $a2, $sp, 0x10
/* 35EB0 8005AAB0 AFBF0040 */  sw        $ra, 0x40($sp)
/* 35EB4 8005AAB4 AFB10034 */  sw        $s1, 0x34($sp)
/* 35EB8 8005AAB8 0C00A5BF */  jal       func_800296FC
/* 35EBC 8005AABC AFB00030 */   sw       $s0, 0x30($sp)
/* 35EC0 8005AAC0 8FA40020 */  lw        $a0, 0x20($sp)
/* 35EC4 8005AAC4 0C00AB29 */  jal       func_8002ACA4
/* 35EC8 8005AAC8 00000000 */   nop
/* 35ECC 8005AACC 0040882D */  daddu     $s1, $v0, $zero
/* 35ED0 8005AAD0 0220802D */  daddu     $s0, $s1, $zero
/* 35ED4 8005AAD4 3C0201E0 */  lui       $v0, 0x1e0
/* 35ED8 8005AAD8 34420020 */  ori       $v0, $v0, 0x20
/* 35EDC 8005AADC 3C0401E0 */  lui       $a0, 0x1e0
/* 35EE0 8005AAE0 34840020 */  ori       $a0, $a0, 0x20
/* 35EE4 8005AAE4 8FA50020 */  lw        $a1, 0x20($sp)
/* 35EE8 8005AAE8 0220302D */  daddu     $a2, $s1, $zero
/* 35EEC 8005AAEC 0C00A5BF */  jal       func_800296FC
/* 35EF0 8005AAF0 00A22821 */   addu     $a1, $a1, $v0
.L8005AAF4:
/* 35EF4 8005AAF4 0200202D */  daddu     $a0, $s0, $zero
/* 35EF8 8005AAF8 0C01BB54 */  jal       func_8006ED50
/* 35EFC 8005AAFC 0240282D */   daddu    $a1, $s2, $zero
/* 35F00 8005AB00 10400003 */  beqz      $v0, .L8005AB10
/* 35F04 8005AB04 3C0301E0 */   lui      $v1, 0x1e0
/* 35F08 8005AB08 08016ABD */  j         .L8005AAF4
/* 35F0C 8005AB0C 2610001C */   addiu    $s0, $s0, 0x1c
.L8005AB10:
/* 35F10 8005AB10 8E020014 */  lw        $v0, 0x14($s0)
/* 35F14 8005AB14 34630020 */  ori       $v1, $v1, 0x20
/* 35F18 8005AB18 AE620000 */  sw        $v0, ($s3)
/* 35F1C 8005AB1C 8E100010 */  lw        $s0, 0x10($s0)
/* 35F20 8005AB20 0220202D */  daddu     $a0, $s1, $zero
/* 35F24 8005AB24 0C00AB3B */  jal       func_8002ACEC
/* 35F28 8005AB28 02038021 */   addu     $s0, $s0, $v1
/* 35F2C 8005AB2C 0200102D */  daddu     $v0, $s0, $zero
/* 35F30 8005AB30 8FBF0040 */  lw        $ra, 0x40($sp)
/* 35F34 8005AB34 8FB3003C */  lw        $s3, 0x3c($sp)
/* 35F38 8005AB38 8FB20038 */  lw        $s2, 0x38($sp)
/* 35F3C 8005AB3C 8FB10034 */  lw        $s1, 0x34($sp)
/* 35F40 8005AB40 8FB00030 */  lw        $s0, 0x30($sp)
/* 35F44 8005AB44 03E00008 */  jr        $ra
/* 35F48 8005AB48 27BD0048 */   addiu    $sp, $sp, 0x48
/* 35F4C 8005AB4C 00000000 */  nop
