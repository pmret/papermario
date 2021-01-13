.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240054_D4D094
/* D4D094 80240054 00041403 */  sra       $v0, $a0, 0x10
/* D4D098 80240058 304300FF */  andi      $v1, $v0, 0xff
/* D4D09C 8024005C 24020006 */  addiu     $v0, $zero, 6
/* D4D0A0 80240060 10620015 */  beq       $v1, $v0, .L802400B8
/* D4D0A4 80240064 28620007 */   slti     $v0, $v1, 7
/* D4D0A8 80240068 10400005 */  beqz      $v0, .L80240080
/* D4D0AC 8024006C 24020001 */   addiu    $v0, $zero, 1
/* D4D0B0 80240070 1062000A */  beq       $v1, $v0, .L8024009C
/* D4D0B4 80240074 3C020100 */   lui      $v0, 0x100
/* D4D0B8 80240078 03E00008 */  jr        $ra
/* D4D0BC 8024007C 00821025 */   or       $v0, $a0, $v0
.L80240080:
/* D4D0C0 80240080 2862000A */  slti      $v0, $v1, 0xa
/* D4D0C4 80240084 10400016 */  beqz      $v0, .L802400E0
/* D4D0C8 80240088 28620008 */   slti     $v0, $v1, 8
/* D4D0CC 8024008C 14400015 */  bnez      $v0, .L802400E4
/* D4D0D0 80240090 3C020100 */   lui      $v0, 0x100
/* D4D0D4 80240094 03E00008 */  jr        $ra
/* D4D0D8 80240098 0080102D */   daddu    $v0, $a0, $zero
.L8024009C:
/* D4D0DC 8024009C 3C020001 */  lui       $v0, 1
/* D4D0E0 802400A0 3442000C */  ori       $v0, $v0, 0xc
/* D4D0E4 802400A4 0044102A */  slt       $v0, $v0, $a0
/* D4D0E8 802400A8 1040000E */  beqz      $v0, .L802400E4
/* D4D0EC 802400AC 3C020100 */   lui      $v0, 0x100
.L802400B0:
/* D4D0F0 802400B0 03E00008 */  jr        $ra
/* D4D0F4 802400B4 0080102D */   daddu    $v0, $a0, $zero
.L802400B8:
/* D4D0F8 802400B8 3C02FFF9 */  lui       $v0, 0xfff9
/* D4D0FC 802400BC 3442FFF4 */  ori       $v0, $v0, 0xfff4
/* D4D100 802400C0 00821821 */  addu      $v1, $a0, $v0
/* D4D104 802400C4 2C620010 */  sltiu     $v0, $v1, 0x10
/* D4D108 802400C8 10400005 */  beqz      $v0, .L802400E0
/* D4D10C 802400CC 30620001 */   andi     $v0, $v1, 1
/* D4D110 802400D0 1440FFF7 */  bnez      $v0, .L802400B0
/* D4D114 802400D4 24820001 */   addiu    $v0, $a0, 1
/* D4D118 802400D8 03E00008 */  jr        $ra
/* D4D11C 802400DC 00000000 */   nop
.L802400E0:
/* D4D120 802400E0 3C020100 */  lui       $v0, 0x100
.L802400E4:
/* D4D124 802400E4 03E00008 */  jr        $ra
/* D4D128 802400E8 00821025 */   or       $v0, $a0, $v0
