.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240054_D6EA04
/* D6EA04 80240054 00041403 */  sra       $v0, $a0, 0x10
/* D6EA08 80240058 304300FF */  andi      $v1, $v0, 0xff
/* D6EA0C 8024005C 24020006 */  addiu     $v0, $zero, 6
/* D6EA10 80240060 10620015 */  beq       $v1, $v0, .L802400B8
/* D6EA14 80240064 28620007 */   slti     $v0, $v1, 7
/* D6EA18 80240068 10400005 */  beqz      $v0, .L80240080
/* D6EA1C 8024006C 24020001 */   addiu    $v0, $zero, 1
/* D6EA20 80240070 1062000A */  beq       $v1, $v0, .L8024009C
/* D6EA24 80240074 3C020100 */   lui      $v0, 0x100
/* D6EA28 80240078 03E00008 */  jr        $ra
/* D6EA2C 8024007C 00821025 */   or       $v0, $a0, $v0
.L80240080:
/* D6EA30 80240080 2862000A */  slti      $v0, $v1, 0xa
/* D6EA34 80240084 10400016 */  beqz      $v0, .L802400E0
/* D6EA38 80240088 28620008 */   slti     $v0, $v1, 8
/* D6EA3C 8024008C 14400015 */  bnez      $v0, .L802400E4
/* D6EA40 80240090 3C020100 */   lui      $v0, 0x100
/* D6EA44 80240094 03E00008 */  jr        $ra
/* D6EA48 80240098 0080102D */   daddu    $v0, $a0, $zero
.L8024009C:
/* D6EA4C 8024009C 3C020001 */  lui       $v0, 1
/* D6EA50 802400A0 3442000C */  ori       $v0, $v0, 0xc
/* D6EA54 802400A4 0044102A */  slt       $v0, $v0, $a0
/* D6EA58 802400A8 1040000E */  beqz      $v0, .L802400E4
/* D6EA5C 802400AC 3C020100 */   lui      $v0, 0x100
.L802400B0:
/* D6EA60 802400B0 03E00008 */  jr        $ra
/* D6EA64 802400B4 0080102D */   daddu    $v0, $a0, $zero
.L802400B8:
/* D6EA68 802400B8 3C02FFF9 */  lui       $v0, 0xfff9
/* D6EA6C 802400BC 3442FFF4 */  ori       $v0, $v0, 0xfff4
/* D6EA70 802400C0 00821821 */  addu      $v1, $a0, $v0
/* D6EA74 802400C4 2C620010 */  sltiu     $v0, $v1, 0x10
/* D6EA78 802400C8 10400005 */  beqz      $v0, .L802400E0
/* D6EA7C 802400CC 30620001 */   andi     $v0, $v1, 1
/* D6EA80 802400D0 1440FFF7 */  bnez      $v0, .L802400B0
/* D6EA84 802400D4 24820001 */   addiu    $v0, $a0, 1
/* D6EA88 802400D8 03E00008 */  jr        $ra
/* D6EA8C 802400DC 00000000 */   nop      
.L802400E0:
/* D6EA90 802400E0 3C020100 */  lui       $v0, 0x100
.L802400E4:
/* D6EA94 802400E4 03E00008 */  jr        $ra
/* D6EA98 802400E8 00821025 */   or       $v0, $a0, $v0
