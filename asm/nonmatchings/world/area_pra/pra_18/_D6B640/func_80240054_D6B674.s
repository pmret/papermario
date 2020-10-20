.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240054_D6B674
/* D6B674 80240054 00041403 */  sra       $v0, $a0, 0x10
/* D6B678 80240058 304300FF */  andi      $v1, $v0, 0xff
/* D6B67C 8024005C 24020006 */  addiu     $v0, $zero, 6
/* D6B680 80240060 10620015 */  beq       $v1, $v0, .L802400B8
/* D6B684 80240064 28620007 */   slti     $v0, $v1, 7
/* D6B688 80240068 10400005 */  beqz      $v0, .L80240080
/* D6B68C 8024006C 24020001 */   addiu    $v0, $zero, 1
/* D6B690 80240070 1062000A */  beq       $v1, $v0, .L8024009C
/* D6B694 80240074 3C020100 */   lui      $v0, 0x100
/* D6B698 80240078 03E00008 */  jr        $ra
/* D6B69C 8024007C 00821025 */   or       $v0, $a0, $v0
.L80240080:
/* D6B6A0 80240080 2862000A */  slti      $v0, $v1, 0xa
/* D6B6A4 80240084 10400016 */  beqz      $v0, .L802400E0
/* D6B6A8 80240088 28620008 */   slti     $v0, $v1, 8
/* D6B6AC 8024008C 14400015 */  bnez      $v0, .L802400E4
/* D6B6B0 80240090 3C020100 */   lui      $v0, 0x100
/* D6B6B4 80240094 03E00008 */  jr        $ra
/* D6B6B8 80240098 0080102D */   daddu    $v0, $a0, $zero
.L8024009C:
/* D6B6BC 8024009C 3C020001 */  lui       $v0, 1
/* D6B6C0 802400A0 3442000C */  ori       $v0, $v0, 0xc
/* D6B6C4 802400A4 0044102A */  slt       $v0, $v0, $a0
/* D6B6C8 802400A8 1040000E */  beqz      $v0, .L802400E4
/* D6B6CC 802400AC 3C020100 */   lui      $v0, 0x100
.L802400B0:
/* D6B6D0 802400B0 03E00008 */  jr        $ra
/* D6B6D4 802400B4 0080102D */   daddu    $v0, $a0, $zero
.L802400B8:
/* D6B6D8 802400B8 3C02FFF9 */  lui       $v0, 0xfff9
/* D6B6DC 802400BC 3442FFF4 */  ori       $v0, $v0, 0xfff4
/* D6B6E0 802400C0 00821821 */  addu      $v1, $a0, $v0
/* D6B6E4 802400C4 2C620010 */  sltiu     $v0, $v1, 0x10
/* D6B6E8 802400C8 10400005 */  beqz      $v0, .L802400E0
/* D6B6EC 802400CC 30620001 */   andi     $v0, $v1, 1
/* D6B6F0 802400D0 1440FFF7 */  bnez      $v0, .L802400B0
/* D6B6F4 802400D4 24820001 */   addiu    $v0, $a0, 1
/* D6B6F8 802400D8 03E00008 */  jr        $ra
/* D6B6FC 802400DC 00000000 */   nop      
.L802400E0:
/* D6B700 802400E0 3C020100 */  lui       $v0, 0x100
.L802400E4:
/* D6B704 802400E4 03E00008 */  jr        $ra
/* D6B708 802400E8 00821025 */   or       $v0, $a0, $v0
