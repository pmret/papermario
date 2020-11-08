.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel LoadModelAnimation
/* F169C 802CCCEC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* F16A0 802CCCF0 AFB10014 */  sw        $s1, 0x14($sp)
/* F16A4 802CCCF4 0080882D */  daddu     $s1, $a0, $zero
/* F16A8 802CCCF8 AFBF001C */  sw        $ra, 0x1c($sp)
/* F16AC 802CCCFC AFB20018 */  sw        $s2, 0x18($sp)
/* F16B0 802CCD00 AFB00010 */  sw        $s0, 0x10($sp)
/* F16B4 802CCD04 8E30000C */  lw        $s0, 0xc($s1)
/* F16B8 802CCD08 8E050000 */  lw        $a1, ($s0)
/* F16BC 802CCD0C 0C0B1EAF */  jal       get_variable
/* F16C0 802CCD10 26100004 */   addiu    $s0, $s0, 4
/* F16C4 802CCD14 0220202D */  daddu     $a0, $s1, $zero
/* F16C8 802CCD18 8E050000 */  lw        $a1, ($s0)
/* F16CC 802CCD1C 0C0B1EAF */  jal       get_variable
/* F16D0 802CCD20 0040802D */   daddu    $s0, $v0, $zero
/* F16D4 802CCD24 0040902D */  daddu     $s2, $v0, $zero
/* F16D8 802CCD28 3C02802E */  lui       $v0, %hi(gAnimatedMeshesPtr)
/* F16DC 802CCD2C 8C42AE30 */  lw        $v0, %lo(gAnimatedMeshesPtr)($v0)
/* F16E0 802CCD30 00108080 */  sll       $s0, $s0, 2
/* F16E4 802CCD34 02028021 */  addu      $s0, $s0, $v0
/* F16E8 802CCD38 8E100000 */  lw        $s0, ($s0)
/* F16EC 802CCD3C 0C04792E */  jal       func_8011E4B8
/* F16F0 802CCD40 0000202D */   daddu    $a0, $zero, $zero
/* F16F4 802CCD44 0040882D */  daddu     $s1, $v0, $zero
/* F16F8 802CCD48 0220202D */  daddu     $a0, $s1, $zero
/* F16FC 802CCD4C 0C0480EB */  jal       func_801203AC
/* F1700 802CCD50 0240282D */   daddu    $a1, $s2, $zero
/* F1704 802CCD54 3C013F80 */  lui       $at, 0x3f80
/* F1708 802CCD58 44810000 */  mtc1      $at, $f0
/* F170C 802CCD5C 26040028 */  addiu     $a0, $s0, 0x28
/* F1710 802CCD60 AE110000 */  sw        $s1, ($s0)
/* F1714 802CCD64 AE000004 */  sw        $zero, 4($s0)
/* F1718 802CCD68 AE000008 */  sw        $zero, 8($s0)
/* F171C 802CCD6C AE00000C */  sw        $zero, 0xc($s0)
/* F1720 802CCD70 AE000010 */  sw        $zero, 0x10($s0)
/* F1724 802CCD74 AE000014 */  sw        $zero, 0x14($s0)
/* F1728 802CCD78 AE000018 */  sw        $zero, 0x18($s0)
/* F172C 802CCD7C E600001C */  swc1      $f0, 0x1c($s0)
/* F1730 802CCD80 E6000020 */  swc1      $f0, 0x20($s0)
/* F1734 802CCD84 E6000024 */  swc1      $f0, 0x24($s0)
/* F1738 802CCD88 0C019D10 */  jal       guMtxIdent
/* F173C 802CCD8C AE000068 */   sw       $zero, 0x68($s0)
/* F1740 802CCD90 8FBF001C */  lw        $ra, 0x1c($sp)
/* F1744 802CCD94 8FB20018 */  lw        $s2, 0x18($sp)
/* F1748 802CCD98 8FB10014 */  lw        $s1, 0x14($sp)
/* F174C 802CCD9C 8FB00010 */  lw        $s0, 0x10($sp)
/* F1750 802CCDA0 24020002 */  addiu     $v0, $zero, 2
/* F1754 802CCDA4 03E00008 */  jr        $ra
/* F1758 802CCDA8 27BD0020 */   addiu    $sp, $sp, 0x20
