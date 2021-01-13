.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240084_D62D94
/* D62D94 80240084 00041403 */  sra       $v0, $a0, 0x10
/* D62D98 80240088 304300FF */  andi      $v1, $v0, 0xff
/* D62D9C 8024008C 24020006 */  addiu     $v0, $zero, 6
/* D62DA0 80240090 10620015 */  beq       $v1, $v0, .L802400E8
/* D62DA4 80240094 28620007 */   slti     $v0, $v1, 7
/* D62DA8 80240098 10400005 */  beqz      $v0, .L802400B0
/* D62DAC 8024009C 24020001 */   addiu    $v0, $zero, 1
/* D62DB0 802400A0 1062000A */  beq       $v1, $v0, .L802400CC
/* D62DB4 802400A4 3C020100 */   lui      $v0, 0x100
/* D62DB8 802400A8 03E00008 */  jr        $ra
/* D62DBC 802400AC 00821025 */   or       $v0, $a0, $v0
.L802400B0:
/* D62DC0 802400B0 2862000A */  slti      $v0, $v1, 0xa
/* D62DC4 802400B4 10400016 */  beqz      $v0, .L80240110
/* D62DC8 802400B8 28620008 */   slti     $v0, $v1, 8
/* D62DCC 802400BC 14400015 */  bnez      $v0, .L80240114
/* D62DD0 802400C0 3C020100 */   lui      $v0, 0x100
/* D62DD4 802400C4 03E00008 */  jr        $ra
/* D62DD8 802400C8 0080102D */   daddu    $v0, $a0, $zero
.L802400CC:
/* D62DDC 802400CC 3C020001 */  lui       $v0, 1
/* D62DE0 802400D0 3442000C */  ori       $v0, $v0, 0xc
/* D62DE4 802400D4 0044102A */  slt       $v0, $v0, $a0
/* D62DE8 802400D8 1040000E */  beqz      $v0, .L80240114
/* D62DEC 802400DC 3C020100 */   lui      $v0, 0x100
.L802400E0:
/* D62DF0 802400E0 03E00008 */  jr        $ra
/* D62DF4 802400E4 0080102D */   daddu    $v0, $a0, $zero
.L802400E8:
/* D62DF8 802400E8 3C02FFF9 */  lui       $v0, 0xfff9
/* D62DFC 802400EC 3442FFF4 */  ori       $v0, $v0, 0xfff4
/* D62E00 802400F0 00821821 */  addu      $v1, $a0, $v0
/* D62E04 802400F4 2C620010 */  sltiu     $v0, $v1, 0x10
/* D62E08 802400F8 10400005 */  beqz      $v0, .L80240110
/* D62E0C 802400FC 30620001 */   andi     $v0, $v1, 1
/* D62E10 80240100 1440FFF7 */  bnez      $v0, .L802400E0
/* D62E14 80240104 24820001 */   addiu    $v0, $a0, 1
/* D62E18 80240108 03E00008 */  jr        $ra
/* D62E1C 8024010C 00000000 */   nop
.L80240110:
/* D62E20 80240110 3C020100 */  lui       $v0, 0x100
.L80240114:
/* D62E24 80240114 03E00008 */  jr        $ra
/* D62E28 80240118 00821025 */   or       $v0, $a0, $v0
