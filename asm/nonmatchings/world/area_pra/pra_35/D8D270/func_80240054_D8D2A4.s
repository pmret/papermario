.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240054_D8D2A4
/* D8D2A4 80240054 00041403 */  sra       $v0, $a0, 0x10
/* D8D2A8 80240058 304300FF */  andi      $v1, $v0, 0xff
/* D8D2AC 8024005C 24020006 */  addiu     $v0, $zero, 6
/* D8D2B0 80240060 10620015 */  beq       $v1, $v0, .L802400B8
/* D8D2B4 80240064 28620007 */   slti     $v0, $v1, 7
/* D8D2B8 80240068 10400005 */  beqz      $v0, .L80240080
/* D8D2BC 8024006C 24020001 */   addiu    $v0, $zero, 1
/* D8D2C0 80240070 1062000A */  beq       $v1, $v0, .L8024009C
/* D8D2C4 80240074 3C020100 */   lui      $v0, 0x100
/* D8D2C8 80240078 03E00008 */  jr        $ra
/* D8D2CC 8024007C 00821025 */   or       $v0, $a0, $v0
.L80240080:
/* D8D2D0 80240080 2862000A */  slti      $v0, $v1, 0xa
/* D8D2D4 80240084 10400016 */  beqz      $v0, .L802400E0
/* D8D2D8 80240088 28620008 */   slti     $v0, $v1, 8
/* D8D2DC 8024008C 14400015 */  bnez      $v0, .L802400E4
/* D8D2E0 80240090 3C020100 */   lui      $v0, 0x100
/* D8D2E4 80240094 03E00008 */  jr        $ra
/* D8D2E8 80240098 0080102D */   daddu    $v0, $a0, $zero
.L8024009C:
/* D8D2EC 8024009C 3C020001 */  lui       $v0, 1
/* D8D2F0 802400A0 3442000C */  ori       $v0, $v0, 0xc
/* D8D2F4 802400A4 0044102A */  slt       $v0, $v0, $a0
/* D8D2F8 802400A8 1040000E */  beqz      $v0, .L802400E4
/* D8D2FC 802400AC 3C020100 */   lui      $v0, 0x100
.L802400B0:
/* D8D300 802400B0 03E00008 */  jr        $ra
/* D8D304 802400B4 0080102D */   daddu    $v0, $a0, $zero
.L802400B8:
/* D8D308 802400B8 3C02FFF9 */  lui       $v0, 0xfff9
/* D8D30C 802400BC 3442FFF4 */  ori       $v0, $v0, 0xfff4
/* D8D310 802400C0 00821821 */  addu      $v1, $a0, $v0
/* D8D314 802400C4 2C620010 */  sltiu     $v0, $v1, 0x10
/* D8D318 802400C8 10400005 */  beqz      $v0, .L802400E0
/* D8D31C 802400CC 30620001 */   andi     $v0, $v1, 1
/* D8D320 802400D0 1440FFF7 */  bnez      $v0, .L802400B0
/* D8D324 802400D4 24820001 */   addiu    $v0, $a0, 1
/* D8D328 802400D8 03E00008 */  jr        $ra
/* D8D32C 802400DC 00000000 */   nop
.L802400E0:
/* D8D330 802400E0 3C020100 */  lui       $v0, 0x100
.L802400E4:
/* D8D334 802400E4 03E00008 */  jr        $ra
/* D8D338 802400E8 00821025 */   or       $v0, $a0, $v0
