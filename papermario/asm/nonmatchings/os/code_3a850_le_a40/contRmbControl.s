.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel contRmbControl
/* 03AF10 8005FB10 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 03AF14 8005FB14 AFB10014 */  sw    $s1, 0x14($sp)
/* 03AF18 8005FB18 0000882D */  daddu $s1, $zero, $zero
/* 03AF1C 8005FB1C AFB40020 */  sw    $s4, 0x20($sp)
/* 03AF20 8005FB20 24140002 */  addiu $s4, $zero, 2
/* 03AF24 8005FB24 AFB50024 */  sw    $s5, 0x24($sp)
/* 03AF28 8005FB28 24150001 */  addiu $s5, $zero, 1
/* 03AF2C 8005FB2C AFB3001C */  sw    $s3, 0x1c($sp)
/* 03AF30 8005FB30 0220982D */  daddu $s3, $s1, $zero
/* 03AF34 8005FB34 AFB20018 */  sw    $s2, 0x18($sp)
/* 03AF38 8005FB38 0220902D */  daddu $s2, $s1, $zero
/* 03AF3C 8005FB3C AFBF0028 */  sw    $ra, 0x28($sp)
/* 03AF40 8005FB40 AFB00010 */  sw    $s0, 0x10($sp)
.L8005FB44:
/* 03AF44 8005FB44 3C02800B */  lui   $v0, 0x800b
/* 03AF48 8005FB48 24421D40 */  addiu $v0, $v0, 0x1d40
/* 03AF4C 8005FB4C 02428021 */  addu  $s0, $s2, $v0
/* 03AF50 8005FB50 92030007 */  lbu   $v1, 7($s0)
/* 03AF54 8005FB54 10740015 */  beq   $v1, $s4, .L8005FBAC
/* 03AF58 8005FB58 28620003 */   slti  $v0, $v1, 3
/* 03AF5C 8005FB5C 50400007 */  beql  $v0, $zero, .L8005FB7C
/* 03AF60 8005FB60 28620083 */   slti  $v0, $v1, 0x83
/* 03AF64 8005FB64 5060003B */  beql  $v1, $zero, .L8005FC54
/* 03AF68 8005FB68 26730068 */   addiu $s3, $s3, 0x68
/* 03AF6C 8005FB6C 10750009 */  beq   $v1, $s5, .L8005FB94
/* 03AF70 8005FB70 0200202D */   daddu $a0, $s0, $zero
/* 03AF74 8005FB74 08017F15 */  j     .L8005FC54
/* 03AF78 8005FB78 26730068 */   addiu $s3, $s3, 0x68

.L8005FB7C:
/* 03AF7C 8005FB7C 10400034 */  beqz  $v0, .L8005FC50
/* 03AF80 8005FB80 28620081 */   slti  $v0, $v1, 0x81
/* 03AF84 8005FB84 54400033 */  bnel  $v0, $zero, .L8005FC54
/* 03AF88 8005FB88 26730068 */   addiu $s3, $s3, 0x68
/* 03AF8C 8005FB8C 08017F0E */  j     .L8005FC38
/* 03AF90 8005FB90 00000000 */   nop   

.L8005FB94:
/* 03AF94 8005FB94 0C017E48 */  jal   osMotorStop
/* 03AF98 8005FB98 0220282D */   daddu $a1, $s1, $zero
/* 03AF9C 8005FB9C 5440002C */  bnel  $v0, $zero, .L8005FC50
/* 03AFA0 8005FBA0 A2000007 */   sb    $zero, 7($s0)
/* 03AFA4 8005FBA4 08017F15 */  j     .L8005FC54
/* 03AFA8 8005FBA8 26730068 */   addiu $s3, $s3, 0x68

.L8005FBAC:
/* 03AFAC 8005FBAC 92020008 */  lbu   $v0, 8($s0)
/* 03AFB0 8005FBB0 14400019 */  bnez  $v0, .L8005FC18
/* 03AFB4 8005FBB4 0200202D */   daddu $a0, $s0, $zero
/* 03AFB8 8005FBB8 96030004 */  lhu   $v1, 4($s0)
/* 03AFBC 8005FBBC 3C028009 */  lui   $v0, 0x8009
/* 03AFC0 8005FBC0 8C423CE0 */  lw    $v0, 0x3ce0($v0)
/* 03AFC4 8005FBC4 14400002 */  bnez  $v0, .L8005FBD0
/* 03AFC8 8005FBC8 0062001B */   divu  $zero, $v1, $v0
/* 03AFCC 8005FBCC 0007000D */  break 7
.L8005FBD0:
/* 03AFD0 8005FBD0 00001010 */  mfhi  $v0
/* 03AFD4 8005FBD4 1440000C */  bnez  $v0, .L8005FC08
/* 03AFD8 8005FBD8 00000000 */   nop   
/* 03AFDC 8005FBDC 3C04800E */  lui   $a0, 0x800e
/* 03AFE0 8005FBE0 2484AC78 */  addiu $a0, $a0, -0x5388
/* 03AFE4 8005FBE4 3C05800E */  lui   $a1, 0x800e
/* 03AFE8 8005FBE8 24A5AAD8 */  addiu $a1, $a1, -0x5528
/* 03AFEC 8005FBEC 02652821 */  addu  $a1, $s3, $a1
/* 03AFF0 8005FBF0 0C019FD1 */  jal   osMotorInit
/* 03AFF4 8005FBF4 0220302D */   daddu $a2, $s1, $zero
/* 03AFF8 8005FBF8 14400003 */  bnez  $v0, .L8005FC08
/* 03AFFC 8005FBFC 00000000 */   nop   
/* 03B000 8005FC00 A2150008 */  sb    $s5, 8($s0)
/* 03B004 8005FC04 A2140009 */  sb    $s4, 9($s0)
.L8005FC08:
/* 03B008 8005FC08 96020004 */  lhu   $v0, 4($s0)
/* 03B00C 8005FC0C 24420001 */  addiu $v0, $v0, 1
/* 03B010 8005FC10 08017F14 */  j     .L8005FC50
/* 03B014 8005FC14 A6020004 */   sh    $v0, 4($s0)

.L8005FC18:
/* 03B018 8005FC18 0C017E48 */  jal   osMotorStop
/* 03B01C 8005FC1C 0220282D */   daddu $a1, $s1, $zero
/* 03B020 8005FC20 5040000C */  beql  $v0, $zero, .L8005FC54
/* 03B024 8005FC24 26730068 */   addiu $s3, $s3, 0x68
/* 03B028 8005FC28 A6110004 */  sh    $s1, 4($s0)
/* 03B02C 8005FC2C A2000008 */  sb    $zero, 8($s0)
/* 03B030 8005FC30 08017F14 */  j     .L8005FC50
/* 03B034 8005FC34 A2000009 */   sb    $zero, 9($s0)

.L8005FC38:
/* 03B038 8005FC38 92020009 */  lbu   $v0, 9($s0)
/* 03B03C 8005FC3C 54540005 */  bnel  $v0, $s4, .L8005FC54
/* 03B040 8005FC40 26730068 */   addiu $s3, $s3, 0x68
/* 03B044 8005FC44 0200202D */  daddu $a0, $s0, $zero
/* 03B048 8005FC48 0C017E48 */  jal   osMotorStop
/* 03B04C 8005FC4C 0220282D */   daddu $a1, $s1, $zero
.L8005FC50:
/* 03B050 8005FC50 26730068 */  addiu $s3, $s3, 0x68
.L8005FC54:
/* 03B054 8005FC54 26310001 */  addiu $s1, $s1, 1
/* 03B058 8005FC58 2E220004 */  sltiu $v0, $s1, 4
/* 03B05C 8005FC5C 1440FFB9 */  bnez  $v0, .L8005FB44
/* 03B060 8005FC60 2652000A */   addiu $s2, $s2, 0xa
/* 03B064 8005FC64 8FBF0028 */  lw    $ra, 0x28($sp)
/* 03B068 8005FC68 8FB50024 */  lw    $s5, 0x24($sp)
/* 03B06C 8005FC6C 8FB40020 */  lw    $s4, 0x20($sp)
/* 03B070 8005FC70 8FB3001C */  lw    $s3, 0x1c($sp)
/* 03B074 8005FC74 8FB20018 */  lw    $s2, 0x18($sp)
/* 03B078 8005FC78 8FB10014 */  lw    $s1, 0x14($sp)
/* 03B07C 8005FC7C 8FB00010 */  lw    $s0, 0x10($sp)
/* 03B080 8005FC80 0000102D */  daddu $v0, $zero, $zero
/* 03B084 8005FC84 03E00008 */  jr    $ra
/* 03B088 8005FC88 27BD0030 */   addiu $sp, $sp, 0x30

