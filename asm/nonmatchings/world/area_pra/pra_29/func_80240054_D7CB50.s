.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240054_D7CBA4
/* D7CBA4 80240054 00041403 */  sra       $v0, $a0, 0x10
/* D7CBA8 80240058 304300FF */  andi      $v1, $v0, 0xff
/* D7CBAC 8024005C 24020006 */  addiu     $v0, $zero, 6
/* D7CBB0 80240060 10620015 */  beq       $v1, $v0, .L802400B8
/* D7CBB4 80240064 28620007 */   slti     $v0, $v1, 7
/* D7CBB8 80240068 10400005 */  beqz      $v0, .L80240080
/* D7CBBC 8024006C 24020001 */   addiu    $v0, $zero, 1
/* D7CBC0 80240070 1062000A */  beq       $v1, $v0, .L8024009C
/* D7CBC4 80240074 3C020100 */   lui      $v0, 0x100
/* D7CBC8 80240078 03E00008 */  jr        $ra
/* D7CBCC 8024007C 00821025 */   or       $v0, $a0, $v0
.L80240080:
/* D7CBD0 80240080 2862000A */  slti      $v0, $v1, 0xa
/* D7CBD4 80240084 10400016 */  beqz      $v0, .L802400E0
/* D7CBD8 80240088 28620008 */   slti     $v0, $v1, 8
/* D7CBDC 8024008C 14400015 */  bnez      $v0, .L802400E4
/* D7CBE0 80240090 3C020100 */   lui      $v0, 0x100
/* D7CBE4 80240094 03E00008 */  jr        $ra
/* D7CBE8 80240098 0080102D */   daddu    $v0, $a0, $zero
.L8024009C:
/* D7CBEC 8024009C 3C020001 */  lui       $v0, 1
/* D7CBF0 802400A0 3442000C */  ori       $v0, $v0, 0xc
/* D7CBF4 802400A4 0044102A */  slt       $v0, $v0, $a0
/* D7CBF8 802400A8 1040000E */  beqz      $v0, .L802400E4
/* D7CBFC 802400AC 3C020100 */   lui      $v0, 0x100
.L802400B0:
/* D7CC00 802400B0 03E00008 */  jr        $ra
/* D7CC04 802400B4 0080102D */   daddu    $v0, $a0, $zero
.L802400B8:
/* D7CC08 802400B8 3C02FFF9 */  lui       $v0, 0xfff9
/* D7CC0C 802400BC 3442FFF4 */  ori       $v0, $v0, 0xfff4
/* D7CC10 802400C0 00821821 */  addu      $v1, $a0, $v0
/* D7CC14 802400C4 2C620010 */  sltiu     $v0, $v1, 0x10
/* D7CC18 802400C8 10400005 */  beqz      $v0, .L802400E0
/* D7CC1C 802400CC 30620001 */   andi     $v0, $v1, 1
/* D7CC20 802400D0 1440FFF7 */  bnez      $v0, .L802400B0
/* D7CC24 802400D4 24820001 */   addiu    $v0, $a0, 1
/* D7CC28 802400D8 03E00008 */  jr        $ra
/* D7CC2C 802400DC 00000000 */   nop      
.L802400E0:
/* D7CC30 802400E0 3C020100 */  lui       $v0, 0x100
.L802400E4:
/* D7CC34 802400E4 03E00008 */  jr        $ra
/* D7CC38 802400E8 00821025 */   or       $v0, $a0, $v0
