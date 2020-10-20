.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240054_D69B74
/* D69B74 80240054 00041403 */  sra       $v0, $a0, 0x10
/* D69B78 80240058 304300FF */  andi      $v1, $v0, 0xff
/* D69B7C 8024005C 24020006 */  addiu     $v0, $zero, 6
/* D69B80 80240060 10620015 */  beq       $v1, $v0, .L802400B8
/* D69B84 80240064 28620007 */   slti     $v0, $v1, 7
/* D69B88 80240068 10400005 */  beqz      $v0, .L80240080
/* D69B8C 8024006C 24020001 */   addiu    $v0, $zero, 1
/* D69B90 80240070 1062000A */  beq       $v1, $v0, .L8024009C
/* D69B94 80240074 3C020100 */   lui      $v0, 0x100
/* D69B98 80240078 03E00008 */  jr        $ra
/* D69B9C 8024007C 00821025 */   or       $v0, $a0, $v0
.L80240080:
/* D69BA0 80240080 2862000A */  slti      $v0, $v1, 0xa
/* D69BA4 80240084 10400016 */  beqz      $v0, .L802400E0
/* D69BA8 80240088 28620008 */   slti     $v0, $v1, 8
/* D69BAC 8024008C 14400015 */  bnez      $v0, .L802400E4
/* D69BB0 80240090 3C020100 */   lui      $v0, 0x100
/* D69BB4 80240094 03E00008 */  jr        $ra
/* D69BB8 80240098 0080102D */   daddu    $v0, $a0, $zero
.L8024009C:
/* D69BBC 8024009C 3C020001 */  lui       $v0, 1
/* D69BC0 802400A0 3442000C */  ori       $v0, $v0, 0xc
/* D69BC4 802400A4 0044102A */  slt       $v0, $v0, $a0
/* D69BC8 802400A8 1040000E */  beqz      $v0, .L802400E4
/* D69BCC 802400AC 3C020100 */   lui      $v0, 0x100
.L802400B0:
/* D69BD0 802400B0 03E00008 */  jr        $ra
/* D69BD4 802400B4 0080102D */   daddu    $v0, $a0, $zero
.L802400B8:
/* D69BD8 802400B8 3C02FFF9 */  lui       $v0, 0xfff9
/* D69BDC 802400BC 3442FFF4 */  ori       $v0, $v0, 0xfff4
/* D69BE0 802400C0 00821821 */  addu      $v1, $a0, $v0
/* D69BE4 802400C4 2C620010 */  sltiu     $v0, $v1, 0x10
/* D69BE8 802400C8 10400005 */  beqz      $v0, .L802400E0
/* D69BEC 802400CC 30620001 */   andi     $v0, $v1, 1
/* D69BF0 802400D0 1440FFF7 */  bnez      $v0, .L802400B0
/* D69BF4 802400D4 24820001 */   addiu    $v0, $a0, 1
/* D69BF8 802400D8 03E00008 */  jr        $ra
/* D69BFC 802400DC 00000000 */   nop      
.L802400E0:
/* D69C00 802400E0 3C020100 */  lui       $v0, 0x100
.L802400E4:
/* D69C04 802400E4 03E00008 */  jr        $ra
/* D69C08 802400E8 00821025 */   or       $v0, $a0, $v0
