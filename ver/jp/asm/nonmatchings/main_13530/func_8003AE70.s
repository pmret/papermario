.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8003AE70
/* 16270 8003AE70 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 16274 8003AE74 AFB20018 */  sw        $s2, 0x18($sp)
/* 16278 8003AE78 0000902D */  daddu     $s2, $zero, $zero
/* 1627C 8003AE7C AFB40020 */  sw        $s4, 0x20($sp)
/* 16280 8003AE80 3C144000 */  lui       $s4, 0x4000
/* 16284 8003AE84 AFB3001C */  sw        $s3, 0x1c($sp)
/* 16288 8003AE88 3C130100 */  lui       $s3, 0x100
/* 1628C 8003AE8C AFBF0024 */  sw        $ra, 0x24($sp)
/* 16290 8003AE90 AFB10014 */  sw        $s1, 0x14($sp)
/* 16294 8003AE94 AFB00010 */  sw        $s0, 0x10($sp)
.L8003AE98:
/* 16298 8003AE98 3C03800A */  lui       $v1, %hi(D_8009E9A0)
/* 1629C 8003AE9C 8C63E9A0 */  lw        $v1, %lo(D_8009E9A0)($v1)
/* 162A0 8003AEA0 00121080 */  sll       $v0, $s2, 2
/* 162A4 8003AEA4 00431021 */  addu      $v0, $v0, $v1
/* 162A8 8003AEA8 8C510000 */  lw        $s1, ($v0)
/* 162AC 8003AEAC 52200049 */  beql      $s1, $zero, .L8003AFD4
/* 162B0 8003AEB0 26520001 */   addiu    $s2, $s2, 1
/* 162B4 8003AEB4 8E230000 */  lw        $v1, ($s1)
/* 162B8 8003AEB8 50600046 */  beql      $v1, $zero, .L8003AFD4
/* 162BC 8003AEBC 26520001 */   addiu    $s2, $s2, 1
/* 162C0 8003AEC0 00741024 */  and       $v0, $v1, $s4
/* 162C4 8003AEC4 54400043 */  bnel      $v0, $zero, .L8003AFD4
/* 162C8 8003AEC8 26520001 */   addiu    $s2, $s2, 1
/* 162CC 8003AECC 00731024 */  and       $v0, $v1, $s3
/* 162D0 8003AED0 14400010 */  bnez      $v0, .L8003AF14
/* 162D4 8003AED4 00741024 */   and      $v0, $v1, $s4
/* 162D8 8003AED8 3C020400 */  lui       $v0, 0x400
/* 162DC 8003AEDC 00621024 */  and       $v0, $v1, $v0
/* 162E0 8003AEE0 14400004 */  bnez      $v0, .L8003AEF4
/* 162E4 8003AEE4 3C048000 */   lui      $a0, 0x8000
/* 162E8 8003AEE8 8E240028 */  lw        $a0, 0x28($s1)
/* 162EC 8003AEEC 0800EBC0 */  j         .L8003AF00
/* 162F0 8003AEF0 8E2500B0 */   lw       $a1, 0xb0($s1)
.L8003AEF4:
/* 162F4 8003AEF4 8E220028 */  lw        $v0, 0x28($s1)
/* 162F8 8003AEF8 8E2500B0 */  lw        $a1, 0xb0($s1)
/* 162FC 8003AEFC 00442025 */  or        $a0, $v0, $a0
.L8003AF00:
/* 16300 8003AF00 0C04470F */  jal       func_80111C3C
/* 16304 8003AF04 00000000 */   nop
/* 16308 8003AF08 AE220024 */  sw        $v0, 0x24($s1)
/* 1630C 8003AF0C 8E230000 */  lw        $v1, ($s1)
/* 16310 8003AF10 00741024 */  and       $v0, $v1, $s4
.L8003AF14:
/* 16314 8003AF14 5440002F */  bnel      $v0, $zero, .L8003AFD4
/* 16318 8003AF18 26520001 */   addiu    $s2, $s2, 1
/* 1631C 8003AF1C 00731024 */  and       $v0, $v1, $s3
/* 16320 8003AF20 1440001A */  bnez      $v0, .L8003AF8C
/* 16324 8003AF24 00000000 */   nop
/* 16328 8003AF28 822200B4 */  lb        $v0, 0xb4($s1)
/* 1632C 8003AF2C 10400017 */  beqz      $v0, .L8003AF8C
/* 16330 8003AF30 00000000 */   nop
/* 16334 8003AF34 0C044964 */  jal       func_80112590
/* 16338 8003AF38 96240028 */   lhu      $a0, 0x28($s1)
/* 1633C 8003AF3C AE2200C4 */  sw        $v0, 0xc4($s1)
/* 16340 8003AF40 0040202D */  daddu     $a0, $v0, $zero
/* 16344 8003AF44 A22000C1 */  sb        $zero, 0xc1($s1)
/* 16348 8003AF48 8C830000 */  lw        $v1, ($a0)
/* 1634C 8003AF4C 2402FFFF */  addiu     $v0, $zero, -1
/* 16350 8003AF50 1062000B */  beq       $v1, $v0, .L8003AF80
/* 16354 8003AF54 0080182D */   daddu    $v1, $a0, $zero
/* 16358 8003AF58 0040202D */  daddu     $a0, $v0, $zero
.L8003AF5C:
/* 1635C 8003AF5C 922200C1 */  lbu       $v0, 0xc1($s1)
/* 16360 8003AF60 24420001 */  addiu     $v0, $v0, 1
/* 16364 8003AF64 A22200C1 */  sb        $v0, 0xc1($s1)
/* 16368 8003AF68 00021600 */  sll       $v0, $v0, 0x18
/* 1636C 8003AF6C 00021583 */  sra       $v0, $v0, 0x16
/* 16370 8003AF70 00431021 */  addu      $v0, $v0, $v1
/* 16374 8003AF74 8C420000 */  lw        $v0, ($v0)
/* 16378 8003AF78 1444FFF8 */  bne       $v0, $a0, .L8003AF5C
/* 1637C 8003AF7C 00000000 */   nop
.L8003AF80:
/* 16380 8003AF80 0C04496F */  jal       func_801125BC
/* 16384 8003AF84 96240028 */   lhu      $a0, 0x28($s1)
/* 16388 8003AF88 A22200C0 */  sb        $v0, 0xc0($s1)
.L8003AF8C:
/* 1638C 8003AF8C 8E230000 */  lw        $v1, ($s1)
/* 16390 8003AF90 00741024 */  and       $v0, $v1, $s4
/* 16394 8003AF94 5440000F */  bnel      $v0, $zero, .L8003AFD4
/* 16398 8003AF98 26520001 */   addiu    $s2, $s2, 1
/* 1639C 8003AF9C 00731024 */  and       $v0, $v1, $s3
/* 163A0 8003AFA0 5440000C */  bnel      $v0, $zero, .L8003AFD4
/* 163A4 8003AFA4 26520001 */   addiu    $s2, $s2, 1
/* 163A8 8003AFA8 0000802D */  daddu     $s0, $zero, $zero
/* 163AC 8003AFAC 0220202D */  daddu     $a0, $s1, $zero
.L8003AFB0:
/* 163B0 8003AFB0 0C00F0B7 */  jal       func_8003C2DC
/* 163B4 8003AFB4 0200282D */   daddu    $a1, $s0, $zero
/* 163B8 8003AFB8 26100001 */  addiu     $s0, $s0, 1
/* 163BC 8003AFBC 2A020002 */  slti      $v0, $s0, 2
/* 163C0 8003AFC0 1440FFFB */  bnez      $v0, .L8003AFB0
/* 163C4 8003AFC4 0220202D */   daddu    $a0, $s1, $zero
/* 163C8 8003AFC8 0C00F41F */  jal       func_8003D07C
/* 163CC 8003AFCC 0220202D */   daddu    $a0, $s1, $zero
/* 163D0 8003AFD0 26520001 */  addiu     $s2, $s2, 1
.L8003AFD4:
/* 163D4 8003AFD4 2A420040 */  slti      $v0, $s2, 0x40
/* 163D8 8003AFD8 1440FFAF */  bnez      $v0, .L8003AE98
/* 163DC 8003AFDC 00000000 */   nop
/* 163E0 8003AFE0 8FBF0024 */  lw        $ra, 0x24($sp)
/* 163E4 8003AFE4 8FB40020 */  lw        $s4, 0x20($sp)
/* 163E8 8003AFE8 8FB3001C */  lw        $s3, 0x1c($sp)
/* 163EC 8003AFEC 8FB20018 */  lw        $s2, 0x18($sp)
/* 163F0 8003AFF0 8FB10014 */  lw        $s1, 0x14($sp)
/* 163F4 8003AFF4 8FB00010 */  lw        $s0, 0x10($sp)
/* 163F8 8003AFF8 03E00008 */  jr        $ra
/* 163FC 8003AFFC 27BD0028 */   addiu    $sp, $sp, 0x28
