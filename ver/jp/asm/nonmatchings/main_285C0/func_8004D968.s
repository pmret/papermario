.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004D968
/* 28D68 8004D968 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 28D6C 8004D96C AFB20018 */  sw        $s2, 0x18($sp)
/* 28D70 8004D970 0080902D */  daddu     $s2, $a0, $zero
/* 28D74 8004D974 AFB50024 */  sw        $s5, 0x24($sp)
/* 28D78 8004D978 00A0A82D */  daddu     $s5, $a1, $zero
/* 28D7C 8004D97C AFB3001C */  sw        $s3, 0x1c($sp)
/* 28D80 8004D980 AFBF0028 */  sw        $ra, 0x28($sp)
/* 28D84 8004D984 AFB40020 */  sw        $s4, 0x20($sp)
/* 28D88 8004D988 AFB10014 */  sw        $s1, 0x14($sp)
/* 28D8C 8004D98C AFB00010 */  sw        $s0, 0x10($sp)
/* 28D90 8004D990 8E510000 */  lw        $s1, ($s2)
/* 28D94 8004D994 8E540010 */  lw        $s4, 0x10($s2)
/* 28D98 8004D998 12200045 */  beqz      $s1, .L8004DAB0
/* 28D9C 8004D99C 0000982D */   daddu    $s3, $zero, $zero
/* 28DA0 8004D9A0 0C013511 */  jal       func_8004D444
/* 28DA4 8004D9A4 0220202D */   daddu    $a0, $s1, $zero
/* 28DA8 8004D9A8 0040802D */  daddu     $s0, $v0, $zero
/* 28DAC 8004D9AC 52000041 */  beql      $s0, $zero, .L8004DAB4
/* 28DB0 8004D9B0 24130002 */   addiu    $s3, $zero, 2
/* 28DB4 8004D9B4 8E420014 */  lw        $v0, 0x14($s2)
/* 28DB8 8004D9B8 14400032 */  bnez      $v0, .L8004DA84
/* 28DBC 8004D9BC 00000000 */   nop
/* 28DC0 8004D9C0 0C014F05 */  jal       func_80053C14
/* 28DC4 8004D9C4 0280202D */   daddu    $a0, $s4, $zero
/* 28DC8 8004D9C8 0040402D */  daddu     $t0, $v0, $zero
/* 28DCC 8004D9CC 51000039 */  beql      $t0, $zero, .L8004DAB4
/* 28DD0 8004D9D0 24130004 */   addiu    $s3, $zero, 4
/* 28DD4 8004D9D4 8E02001C */  lw        $v0, 0x1c($s0)
/* 28DD8 8004D9D8 16220037 */  bne       $s1, $v0, .L8004DAB8
/* 28DDC 8004D9DC 0260102D */   daddu    $v0, $s3, $zero
/* 28DE0 8004D9E0 16A00015 */  bnez      $s5, .L8004DA38
/* 28DE4 8004D9E4 001428C0 */   sll      $a1, $s4, 3
/* 28DE8 8004D9E8 0260382D */  daddu     $a3, $s3, $zero
/* 28DEC 8004D9EC 2406025C */  addiu     $a2, $zero, 0x25c
.L8004D9F0:
/* 28DF0 8004D9F0 02062821 */  addu      $a1, $s0, $a2
/* 28DF4 8004D9F4 8CA20000 */  lw        $v0, ($a1)
/* 28DF8 8004D9F8 5040000B */  beql      $v0, $zero, .L8004DA28
/* 28DFC 8004D9FC 24E70001 */   addiu    $a3, $a3, 1
/* 28E00 8004DA00 90A30052 */  lbu       $v1, 0x52($a1)
/* 28E04 8004DA04 90A40053 */  lbu       $a0, 0x53($a1)
/* 28E08 8004DA08 0064102B */  sltu      $v0, $v1, $a0
/* 28E0C 8004DA0C 50400006 */  beql      $v0, $zero, .L8004DA28
/* 28E10 8004DA10 24E70001 */   addiu    $a3, $a3, 1
.L8004DA14:
/* 28E14 8004DA14 24630001 */  addiu     $v1, $v1, 1
/* 28E18 8004DA18 0064102B */  sltu      $v0, $v1, $a0
/* 28E1C 8004DA1C 1440FFFD */  bnez      $v0, .L8004DA14
/* 28E20 8004DA20 ACA00040 */   sw       $zero, 0x40($a1)
/* 28E24 8004DA24 24E70001 */  addiu     $a3, $a3, 1
.L8004DA28:
/* 28E28 8004DA28 2CE20010 */  sltiu     $v0, $a3, 0x10
/* 28E2C 8004DA2C 1440FFF0 */  bnez      $v0, .L8004D9F0
/* 28E30 8004DA30 24C60060 */   addiu    $a2, $a2, 0x60
/* 28E34 8004DA34 001428C0 */  sll       $a1, $s4, 3
.L8004DA38:
/* 28E38 8004DA38 0200202D */  daddu     $a0, $s0, $zero
/* 28E3C 8004DA3C 24060A9C */  addiu     $a2, $zero, 0xa9c
/* 28E40 8004DA40 8E020000 */  lw        $v0, ($s0)
/* 28E44 8004DA44 92030234 */  lbu       $v1, 0x234($s0)
/* 28E48 8004DA48 00451021 */  addu      $v0, $v0, $a1
/* 28E4C 8004DA4C A0430071 */  sb        $v1, 0x71($v0)
/* 28E50 8004DA50 8E020000 */  lw        $v0, ($s0)
/* 28E54 8004DA54 24030001 */  addiu     $v1, $zero, 1
/* 28E58 8004DA58 00451021 */  addu      $v0, $v0, $a1
/* 28E5C 8004DA5C 0100282D */  daddu     $a1, $t0, $zero
/* 28E60 8004DA60 A0430070 */  sb        $v1, 0x70($v0)
/* 28E64 8004DA64 0C015309 */  jal       func_80054C24
/* 28E68 8004DA68 AE000020 */   sw       $zero, 0x20($s0)
/* 28E6C 8004DA6C 16A00012 */  bnez      $s5, .L8004DAB8
/* 28E70 8004DA70 0260102D */   daddu    $v0, $s3, $zero
/* 28E74 8004DA74 0C0135D6 */  jal       func_8004D758
/* 28E78 8004DA78 0200202D */   daddu    $a0, $s0, $zero
/* 28E7C 8004DA7C 080136AE */  j         .L8004DAB8
/* 28E80 8004DA80 0260102D */   daddu    $v0, $s3, $zero
.L8004DA84:
/* 28E84 8004DA84 8E02001C */  lw        $v0, 0x1c($s0)
/* 28E88 8004DA88 1622000B */  bne       $s1, $v0, .L8004DAB8
/* 28E8C 8004DA8C 0260102D */   daddu    $v0, $s3, $zero
/* 28E90 8004DA90 92020221 */  lbu       $v0, 0x221($s0)
/* 28E94 8004DA94 10400007 */  beqz      $v0, .L8004DAB4
/* 28E98 8004DA98 24020001 */   addiu    $v0, $zero, 1
/* 28E9C 8004DA9C A2020220 */  sb        $v0, 0x220($s0)
/* 28EA0 8004DAA0 0C01416C */  jal       func_800505B0
/* 28EA4 8004DAA4 0200202D */   daddu    $a0, $s0, $zero
/* 28EA8 8004DAA8 080136AE */  j         .L8004DAB8
/* 28EAC 8004DAAC 0260102D */   daddu    $v0, $s3, $zero
.L8004DAB0:
/* 28EB0 8004DAB0 24130003 */  addiu     $s3, $zero, 3
.L8004DAB4:
/* 28EB4 8004DAB4 0260102D */  daddu     $v0, $s3, $zero
.L8004DAB8:
/* 28EB8 8004DAB8 8FBF0028 */  lw        $ra, 0x28($sp)
/* 28EBC 8004DABC 8FB50024 */  lw        $s5, 0x24($sp)
/* 28EC0 8004DAC0 8FB40020 */  lw        $s4, 0x20($sp)
/* 28EC4 8004DAC4 8FB3001C */  lw        $s3, 0x1c($sp)
/* 28EC8 8004DAC8 8FB20018 */  lw        $s2, 0x18($sp)
/* 28ECC 8004DACC 8FB10014 */  lw        $s1, 0x14($sp)
/* 28ED0 8004DAD0 8FB00010 */  lw        $s0, 0x10($sp)
/* 28ED4 8004DAD4 03E00008 */  jr        $ra
/* 28ED8 8004DAD8 27BD0030 */   addiu    $sp, $sp, 0x30
