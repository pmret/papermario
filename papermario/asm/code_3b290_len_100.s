
.section .text8005FE90, "ax"

nuContRmbStart:
/* 03B290 8005FE90 00041080 */  sll   $v0, $a0, 2
/* 03B294 8005FE94 00441021 */  addu  $v0, $v0, $a0
/* 03B298 8005FE98 00021040 */  sll   $v0, $v0, 1
/* 03B29C 8005FE9C 3C01800B */  lui   $at, 0x800b
/* 03B2A0 8005FEA0 00220821 */  addu  $at, $at, $v0
/* 03B2A4 8005FEA4 90221D47 */  lbu   $v0, 0x1d47($at)
/* 03B2A8 8005FEA8 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 03B2AC 8005FEAC 30420080 */  andi  $v0, $v0, 0x80
/* 03B2B0 8005FEB0 1440000B */  bnez  $v0, .L8005FEE0
/* 03B2B4 8005FEB4 AFBF0030 */   sw    $ra, 0x30($sp)
/* 03B2B8 8005FEB8 24020003 */  addiu $v0, $zero, 3
/* 03B2BC 8005FEBC A3A20016 */  sb    $v0, 0x16($sp)
/* 03B2C0 8005FEC0 27A20010 */  addiu $v0, $sp, 0x10
/* 03B2C4 8005FEC4 A3A40020 */  sb    $a0, 0x20($sp)
/* 03B2C8 8005FEC8 24040302 */  addiu $a0, $zero, 0x302
/* 03B2CC 8005FECC A7A50010 */  sh    $a1, 0x10($sp)
/* 03B2D0 8005FED0 27A50020 */  addiu $a1, $sp, 0x20
/* 03B2D4 8005FED4 A7A60012 */  sh    $a2, 0x12($sp)
/* 03B2D8 8005FED8 0C00B3CA */  jal   nuSiSendMesg
/* 03B2DC 8005FEDC AFA20028 */   sw    $v0, 0x28($sp)
.L8005FEE0:
/* 03B2E0 8005FEE0 8FBF0030 */  lw    $ra, 0x30($sp)
/* 03B2E4 8005FEE4 03E00008 */  jr    $ra
/* 03B2E8 8005FEE8 27BD0038 */   addiu $sp, $sp, 0x38

/* 03B2EC 8005FEEC 00000000 */  nop   
nuContRmbCheck:
/* 03B2F0 8005FEF0 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 03B2F4 8005FEF4 AFB00020 */  sw    $s0, 0x20($sp)
/* 03B2F8 8005FEF8 0080802D */  daddu $s0, $a0, $zero
/* 03B2FC 8005FEFC 24040301 */  addiu $a0, $zero, 0x301
/* 03B300 8005FF00 27A50010 */  addiu $a1, $sp, 0x10
/* 03B304 8005FF04 AFBF0028 */  sw    $ra, 0x28($sp)
/* 03B308 8005FF08 AFB10024 */  sw    $s1, 0x24($sp)
/* 03B30C 8005FF0C 0C00B3CA */  jal   nuSiSendMesg
/* 03B310 8005FF10 A3B00010 */   sb    $s0, 0x10($sp)
/* 03B314 8005FF14 24040001 */  addiu $a0, $zero, 1
/* 03B318 8005FF18 0C018250 */  jal   osSetIntMask
/* 03B31C 8005FF1C 0040882D */   daddu $s1, $v0, $zero
/* 03B320 8005FF20 1620000A */  bnez  $s1, .L8005FF4C
/* 03B324 8005FF24 0040202D */   daddu $a0, $v0, $zero
/* 03B328 8005FF28 00101080 */  sll   $v0, $s0, 2
/* 03B32C 8005FF2C 00501021 */  addu  $v0, $v0, $s0
/* 03B330 8005FF30 00021040 */  sll   $v0, $v0, 1
/* 03B334 8005FF34 24030002 */  addiu $v1, $zero, 2
/* 03B338 8005FF38 3C01800B */  lui   $at, 0x800b
/* 03B33C 8005FF3C 00220821 */  addu  $at, $at, $v0
/* 03B340 8005FF40 A0231D49 */  sb    $v1, 0x1d49($at)
/* 03B344 8005FF44 08017FD9 */  j     func_8005FF64
/* 03B348 8005FF48 00000000 */   nop   

.L8005FF4C:
/* 03B34C 8005FF4C 00101080 */  sll   $v0, $s0, 2
/* 03B350 8005FF50 00501021 */  addu  $v0, $v0, $s0
/* 03B354 8005FF54 00021040 */  sll   $v0, $v0, 1
/* 03B358 8005FF58 3C01800B */  lui   $at, 0x800b
/* 03B35C 8005FF5C 00220821 */  addu  $at, $at, $v0
/* 03B360 8005FF60 A0201D49 */  sb    $zero, 0x1d49($at)
func_8005FF64:
/* 03B364 8005FF64 0C018250 */  jal   osSetIntMask
/* 03B368 8005FF68 00000000 */   nop   
/* 03B36C 8005FF6C 0220102D */  daddu $v0, $s1, $zero
/* 03B370 8005FF70 8FBF0028 */  lw    $ra, 0x28($sp)
/* 03B374 8005FF74 8FB10024 */  lw    $s1, 0x24($sp)
/* 03B378 8005FF78 8FB00020 */  lw    $s0, 0x20($sp)
/* 03B37C 8005FF7C 03E00008 */  jr    $ra
/* 03B380 8005FF80 27BD0030 */   addiu $sp, $sp, 0x30

/* 03B384 8005FF84 00000000 */  nop   
/* 03B388 8005FF88 00000000 */  nop   
/* 03B38C 8005FF8C 00000000 */  nop   
