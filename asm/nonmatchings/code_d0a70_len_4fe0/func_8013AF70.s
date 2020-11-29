.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8013AF70
/* D1670 8013AF70 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D1674 8013AF74 0080402D */  daddu     $t0, $a0, $zero
/* D1678 8013AF78 AFB20018 */  sw        $s2, 0x18($sp)
/* D167C 8013AF7C 00E0902D */  daddu     $s2, $a3, $zero
/* D1680 8013AF80 AFB10014 */  sw        $s1, 0x14($sp)
/* D1684 8013AF84 0000882D */  daddu     $s1, $zero, $zero
/* D1688 8013AF88 00081140 */  sll       $v0, $t0, 5
/* D168C 8013AF8C 00481023 */  subu      $v0, $v0, $t0
/* D1690 8013AF90 3C038015 */  lui       $v1, %hi(D_80156954)
/* D1694 8013AF94 8C636954 */  lw        $v1, %lo(D_80156954)($v1)
/* D1698 8013AF98 00021080 */  sll       $v0, $v0, 2
/* D169C 8013AF9C AFBF001C */  sw        $ra, 0x1c($sp)
/* D16A0 8013AFA0 AFB00010 */  sw        $s0, 0x10($sp)
/* D16A4 8013AFA4 90A40010 */  lbu       $a0, 0x10($a1)
/* D16A8 8013AFA8 10800049 */  beqz      $a0, .L8013B0D0
/* D16AC 8013AFAC 00628021 */   addu     $s0, $v1, $v0
/* D16B0 8013AFB0 8E020014 */  lw        $v0, 0x14($s0)
/* D16B4 8013AFB4 A2080000 */  sb        $t0, ($s0)
/* D16B8 8013AFB8 3C038015 */  lui       $v1, %hi(D_8014EE10)
/* D16BC 8013AFBC 8C63EE10 */  lw        $v1, %lo(D_8014EE10)($v1)
/* D16C0 8013AFC0 00461025 */  or        $v0, $v0, $a2
/* D16C4 8013AFC4 AE020014 */  sw        $v0, 0x14($s0)
/* D16C8 8013AFC8 8CA20000 */  lw        $v0, ($a1)
/* D16CC 8013AFCC AC620000 */  sw        $v0, ($v1)
/* D16D0 8013AFD0 8CA20004 */  lw        $v0, 4($a1)
/* D16D4 8013AFD4 AC620004 */  sw        $v0, 4($v1)
/* D16D8 8013AFD8 94A20008 */  lhu       $v0, 8($a1)
/* D16DC 8013AFDC A4620008 */  sh        $v0, 8($v1)
/* D16E0 8013AFE0 94A2000A */  lhu       $v0, 0xa($a1)
/* D16E4 8013AFE4 A462000A */  sh        $v0, 0xa($v1)
/* D16E8 8013AFE8 94A2000C */  lhu       $v0, 0xc($a1)
/* D16EC 8013AFEC A462000C */  sh        $v0, 0xc($v1)
/* D16F0 8013AFF0 94A2000E */  lhu       $v0, 0xe($a1)
/* D16F4 8013AFF4 A4600018 */  sh        $zero, 0x18($v1)
/* D16F8 8013AFF8 A460001E */  sh        $zero, 0x1e($v1)
/* D16FC 8013AFFC A462000E */  sh        $v0, 0xe($v1)
/* D1700 8013B000 90A20010 */  lbu       $v0, 0x10($a1)
/* D1704 8013B004 A0620024 */  sb        $v0, 0x24($v1)
/* D1708 8013B008 2D02005A */  sltiu     $v0, $t0, 0x5a
/* D170C 8013B00C 14400003 */  bnez      $v0, .L8013B01C
/* D1710 8013B010 2902005A */   slti     $v0, $t0, 0x5a
/* D1714 8013B014 0804EC35 */  j         .L8013B0D4
/* D1718 8013B018 0000102D */   daddu    $v0, $zero, $zero
.L8013B01C:
/* D171C 8013B01C 1040002D */  beqz      $v0, .L8013B0D4
/* D1720 8013B020 0000102D */   daddu    $v0, $zero, $zero
/* D1724 8013B024 1200002B */  beqz      $s0, .L8013B0D4
/* D1728 8013B028 00000000 */   nop      
/* D172C 8013B02C 0C04EC3B */  jal       func_8013B0EC
/* D1730 8013B030 0200202D */   daddu    $a0, $s0, $zero
/* D1734 8013B034 0200202D */  daddu     $a0, $s0, $zero
/* D1738 8013B038 0C04EC6C */  jal       func_8013B1B0
/* D173C 8013B03C 0240282D */   daddu    $a1, $s2, $zero
/* D1740 8013B040 8E030014 */  lw        $v1, 0x14($s0)
/* D1744 8013B044 30621000 */  andi      $v0, $v1, 0x1000
/* D1748 8013B048 1040000F */  beqz      $v0, .L8013B088
/* D174C 8013B04C 0200202D */   daddu    $a0, $s0, $zero
/* D1750 8013B050 24110001 */  addiu     $s1, $zero, 1
/* D1754 8013B054 2402FFFF */  addiu     $v0, $zero, -1
/* D1758 8013B058 AC82001C */  sw        $v0, 0x1c($a0)
/* D175C 8013B05C AC82002C */  sw        $v0, 0x2c($a0)
/* D1760 8013B060 8C820014 */  lw        $v0, 0x14($a0)
/* D1764 8013B064 2403E67F */  addiu     $v1, $zero, -0x1981
/* D1768 8013B068 A0800005 */  sb        $zero, 5($a0)
/* D176C 8013B06C A0800001 */  sb        $zero, 1($a0)
/* D1770 8013B070 A0800002 */  sb        $zero, 2($a0)
/* D1774 8013B074 00431024 */  and       $v0, $v0, $v1
/* D1778 8013B078 0C04EA4F */  jal       func_8013A93C
/* D177C 8013B07C AC820014 */   sw       $v0, 0x14($a0)
/* D1780 8013B080 0804EC35 */  j         .L8013B0D4
/* D1784 8013B084 0220102D */   daddu    $v0, $s1, $zero
.L8013B088:
/* D1788 8013B088 30624000 */  andi      $v0, $v1, 0x4000
/* D178C 8013B08C 10400003 */  beqz      $v0, .L8013B09C
/* D1790 8013B090 3C020002 */   lui      $v0, 2
/* D1794 8013B094 0804EC34 */  j         .L8013B0D0
/* D1798 8013B098 24110002 */   addiu    $s1, $zero, 2
.L8013B09C:
/* D179C 8013B09C 00621024 */  and       $v0, $v1, $v0
/* D17A0 8013B0A0 1040000B */  beqz      $v0, .L8013B0D0
/* D17A4 8013B0A4 2403FFFF */   addiu    $v1, $zero, -1
/* D17A8 8013B0A8 24110001 */  addiu     $s1, $zero, 1
/* D17AC 8013B0AC 8E020014 */  lw        $v0, 0x14($s0)
/* D17B0 8013B0B0 A2000005 */  sb        $zero, 5($s0)
/* D17B4 8013B0B4 A2000006 */  sb        $zero, 6($s0)
/* D17B8 8013B0B8 A2000001 */  sb        $zero, 1($s0)
/* D17BC 8013B0BC A2000002 */  sb        $zero, 2($s0)
/* D17C0 8013B0C0 AE03001C */  sw        $v1, 0x1c($s0)
/* D17C4 8013B0C4 AE03002C */  sw        $v1, 0x2c($s0)
/* D17C8 8013B0C8 00511024 */  and       $v0, $v0, $s1
/* D17CC 8013B0CC AE020014 */  sw        $v0, 0x14($s0)
.L8013B0D0:
/* D17D0 8013B0D0 0220102D */  daddu     $v0, $s1, $zero
.L8013B0D4:
/* D17D4 8013B0D4 8FBF001C */  lw        $ra, 0x1c($sp)
/* D17D8 8013B0D8 8FB20018 */  lw        $s2, 0x18($sp)
/* D17DC 8013B0DC 8FB10014 */  lw        $s1, 0x14($sp)
/* D17E0 8013B0E0 8FB00010 */  lw        $s0, 0x10($sp)
/* D17E4 8013B0E4 03E00008 */  jr        $ra
/* D17E8 8013B0E8 27BD0020 */   addiu    $sp, $sp, 0x20
