.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel load_model_transforms
/* B14C8 8011ADC8 27BDFF00 */  addiu     $sp, $sp, -0x100
/* B14CC 8011ADCC AFB100E4 */  sw        $s1, 0xe4($sp)
/* B14D0 8011ADD0 0080882D */  daddu     $s1, $a0, $zero
/* B14D4 8011ADD4 AFB500F4 */  sw        $s5, 0xf4($sp)
/* B14D8 8011ADD8 00A0A82D */  daddu     $s5, $a1, $zero
/* B14DC 8011ADDC AFB300EC */  sw        $s3, 0xec($sp)
/* B14E0 8011ADE0 00C0982D */  daddu     $s3, $a2, $zero
/* B14E4 8011ADE4 AFB400F0 */  sw        $s4, 0xf0($sp)
/* B14E8 8011ADE8 00E0A02D */  daddu     $s4, $a3, $zero
/* B14EC 8011ADEC AFBF00F8 */  sw        $ra, 0xf8($sp)
/* B14F0 8011ADF0 AFB200E8 */  sw        $s2, 0xe8($sp)
/* B14F4 8011ADF4 AFB000E0 */  sw        $s0, 0xe0($sp)
/* B14F8 8011ADF8 8E250010 */  lw        $a1, 0x10($s1)
/* B14FC 8011ADFC 10A00041 */  beqz      $a1, .L8011AF04
/* B1500 8011AE00 27B20090 */   addiu    $s2, $sp, 0x90
/* B1504 8011AE04 8CA2000C */  lw        $v0, 0xc($a1)
/* B1508 8011AE08 5040003F */  beql      $v0, $zero, .L8011AF08
/* B150C 8011AE0C 0260202D */   daddu    $a0, $s3, $zero
/* B1510 8011AE10 8CA50000 */  lw        $a1, ($a1)
/* B1514 8011AE14 10A00007 */  beqz      $a1, .L8011AE34
/* B1518 8011AE18 27B000A0 */   addiu    $s0, $sp, 0xa0
/* B151C 8011AE1C 0C019D60 */  jal       guMtxL2F
/* B1520 8011AE20 0200202D */   daddu    $a0, $s0, $zero
/* B1524 8011AE24 0200202D */  daddu     $a0, $s0, $zero
/* B1528 8011AE28 0260282D */  daddu     $a1, $s3, $zero
/* B152C 8011AE2C 0C019D80 */  jal       guMtxCatF
/* B1530 8011AE30 27A60010 */   addiu    $a2, $sp, 0x10
.L8011AE34:
/* B1534 8011AE34 0220202D */  daddu     $a0, $s1, $zero
/* B1538 8011AE38 0C0456C3 */  jal       get_model_property
/* B153C 8011AE3C 24050060 */   addiu    $a1, $zero, 0x60
/* B1540 8011AE40 10400002 */  beqz      $v0, .L8011AE4C
/* B1544 8011AE44 0000202D */   daddu    $a0, $zero, $zero
/* B1548 8011AE48 8C440008 */  lw        $a0, 8($v0)
.L8011AE4C:
/* B154C 8011AE4C 8E230000 */  lw        $v1, ($s1)
/* B1550 8011AE50 24020005 */  addiu     $v0, $zero, 5
/* B1554 8011AE54 14620003 */  bne       $v1, $v0, .L8011AE64
/* B1558 8011AE58 00000000 */   nop
/* B155C 8011AE5C 1480002A */  bnez      $a0, .L8011AF08
/* B1560 8011AE60 0260202D */   daddu    $a0, $s3, $zero
.L8011AE64:
/* B1564 8011AE64 8E240010 */  lw        $a0, 0x10($s1)
/* B1568 8011AE68 8C82000C */  lw        $v0, 0xc($a0)
/* B156C 8011AE6C 18400012 */  blez      $v0, .L8011AEB8
/* B1570 8011AE70 0000802D */   daddu    $s0, $zero, $zero
/* B1574 8011AE74 0260302D */  daddu     $a2, $s3, $zero
.L8011AE78:
/* B1578 8011AE78 00101080 */  sll       $v0, $s0, 2
/* B157C 8011AE7C 8C830010 */  lw        $v1, 0x10($a0)
/* B1580 8011AE80 8C840000 */  lw        $a0, ($a0)
/* B1584 8011AE84 10800002 */  beqz      $a0, .L8011AE90
/* B1588 8011AE88 00431021 */   addu     $v0, $v0, $v1
/* B158C 8011AE8C 27A60010 */  addiu     $a2, $sp, 0x10
.L8011AE90:
/* B1590 8011AE90 0220282D */  daddu     $a1, $s1, $zero
/* B1594 8011AE94 8C440000 */  lw        $a0, ($v0)
/* B1598 8011AE98 0C046B72 */  jal       load_model_transforms
/* B159C 8011AE9C 26870001 */   addiu    $a3, $s4, 1
/* B15A0 8011AEA0 8E240010 */  lw        $a0, 0x10($s1)
/* B15A4 8011AEA4 8C82000C */  lw        $v0, 0xc($a0)
/* B15A8 8011AEA8 26100001 */  addiu     $s0, $s0, 1
/* B15AC 8011AEAC 0202102A */  slt       $v0, $s0, $v0
/* B15B0 8011AEB0 1440FFF1 */  bnez      $v0, .L8011AE78
/* B15B4 8011AEB4 0260302D */   daddu    $a2, $s3, $zero
.L8011AEB8:
/* B15B8 8011AEB8 3C048015 */  lui       $a0, %hi(D_80153224)
/* B15BC 8011AEBC 24843224 */  addiu     $a0, $a0, %lo(D_80153224)
/* B15C0 8011AEC0 3C05800A */  lui       $a1, %hi(D_8009A5F4)
/* B15C4 8011AEC4 24A5A5F4 */  addiu     $a1, $a1, %lo(D_8009A5F4)
/* B15C8 8011AEC8 8C820000 */  lw        $v0, ($a0)
/* B15CC 8011AECC 8CA30000 */  lw        $v1, ($a1)
/* B15D0 8011AED0 00021080 */  sll       $v0, $v0, 2
/* B15D4 8011AED4 00431021 */  addu      $v0, $v0, $v1
/* B15D8 8011AED8 240300FF */  addiu     $v1, $zero, 0xff
/* B15DC 8011AEDC A0430000 */  sb        $v1, ($v0)
/* B15E0 8011AEE0 8C820000 */  lw        $v0, ($a0)
/* B15E4 8011AEE4 8CA30000 */  lw        $v1, ($a1)
/* B15E8 8011AEE8 00021080 */  sll       $v0, $v0, 2
/* B15EC 8011AEEC 00431021 */  addu      $v0, $v0, $v1
/* B15F0 8011AEF0 A0540001 */  sb        $s4, 1($v0)
/* B15F4 8011AEF4 8C820000 */  lw        $v0, ($a0)
/* B15F8 8011AEF8 24420001 */  addiu     $v0, $v0, 1
/* B15FC 8011AEFC 08046BFB */  j         .L8011AFEC
/* B1600 8011AF00 AC820000 */   sw       $v0, ($a0)
.L8011AF04:
/* B1604 8011AF04 0260202D */  daddu     $a0, $s3, $zero
.L8011AF08:
/* B1608 8011AF08 27B00050 */  addiu     $s0, $sp, 0x50
/* B160C 8011AF0C 0C019D40 */  jal       guMtxF2L
/* B1610 8011AF10 0200282D */   daddu    $a1, $s0, $zero
/* B1614 8011AF14 A6400000 */  sh        $zero, ($s2)
/* B1618 8011AF18 AE510004 */  sw        $s1, 4($s2)
/* B161C 8011AF1C 8EA20010 */  lw        $v0, 0x10($s5)
/* B1620 8011AF20 AE50000C */  sw        $s0, 0xc($s2)
/* B1624 8011AF24 AE420008 */  sw        $v0, 8($s2)
/* B1628 8011AF28 8E230000 */  lw        $v1, ($s1)
/* B162C 8011AF2C 24020005 */  addiu     $v0, $zero, 5
/* B1630 8011AF30 14620021 */  bne       $v1, $v0, .L8011AFB8
/* B1634 8011AF34 0240202D */   daddu    $a0, $s2, $zero
/* B1638 8011AF38 0C04572A */  jal       mdl_get_child_count
/* B163C 8011AF3C 0220202D */   daddu    $a0, $s1, $zero
/* B1640 8011AF40 3C078015 */  lui       $a3, %hi(D_80153224)
/* B1644 8011AF44 24E73224 */  addiu     $a3, $a3, %lo(D_80153224)
/* B1648 8011AF48 8CF00000 */  lw        $s0, ($a3)
/* B164C 8011AF4C 0040202D */  daddu     $a0, $v0, $zero
/* B1650 8011AF50 02041021 */  addu      $v0, $s0, $a0
/* B1654 8011AF54 0202102A */  slt       $v0, $s0, $v0
/* B1658 8011AF58 10400011 */  beqz      $v0, .L8011AFA0
/* B165C 8011AF5C 240800FF */   addiu    $t0, $zero, 0xff
/* B1660 8011AF60 3C05800A */  lui       $a1, %hi(D_8009A5F4)
/* B1664 8011AF64 24A5A5F4 */  addiu     $a1, $a1, %lo(D_8009A5F4)
/* B1668 8011AF68 26860001 */  addiu     $a2, $s4, 1
.L8011AF6C:
/* B166C 8011AF6C 8CA20000 */  lw        $v0, ($a1)
/* B1670 8011AF70 00101880 */  sll       $v1, $s0, 2
/* B1674 8011AF74 00621021 */  addu      $v0, $v1, $v0
/* B1678 8011AF78 A0480000 */  sb        $t0, ($v0)
/* B167C 8011AF7C 8CA20000 */  lw        $v0, ($a1)
/* B1680 8011AF80 00621821 */  addu      $v1, $v1, $v0
/* B1684 8011AF84 A0660001 */  sb        $a2, 1($v1)
/* B1688 8011AF88 8CE20000 */  lw        $v0, ($a3)
/* B168C 8011AF8C 26100001 */  addiu     $s0, $s0, 1
/* B1690 8011AF90 00441021 */  addu      $v0, $v0, $a0
/* B1694 8011AF94 0202102A */  slt       $v0, $s0, $v0
/* B1698 8011AF98 1440FFF4 */  bnez      $v0, .L8011AF6C
/* B169C 8011AF9C 00000000 */   nop
.L8011AFA0:
/* B16A0 8011AFA0 3C038015 */  lui       $v1, %hi(D_80153224)
/* B16A4 8011AFA4 24633224 */  addiu     $v1, $v1, %lo(D_80153224)
/* B16A8 8011AFA8 8C620000 */  lw        $v0, ($v1)
/* B16AC 8011AFAC 00441021 */  addu      $v0, $v0, $a0
/* B16B0 8011AFB0 AC620000 */  sw        $v0, ($v1)
/* B16B4 8011AFB4 0240202D */  daddu     $a0, $s2, $zero
.L8011AFB8:
/* B16B8 8011AFB8 0C045883 */  jal       mdl_create_model
/* B16BC 8011AFBC 24050004 */   addiu    $a1, $zero, 4
/* B16C0 8011AFC0 3C038015 */  lui       $v1, %hi(D_80153224)
/* B16C4 8011AFC4 24633224 */  addiu     $v1, $v1, %lo(D_80153224)
/* B16C8 8011AFC8 8C620000 */  lw        $v0, ($v1)
/* B16CC 8011AFCC 3C04800A */  lui       $a0, %hi(D_8009A5F4)
/* B16D0 8011AFD0 8C84A5F4 */  lw        $a0, %lo(D_8009A5F4)($a0)
/* B16D4 8011AFD4 00021080 */  sll       $v0, $v0, 2
/* B16D8 8011AFD8 00441021 */  addu      $v0, $v0, $a0
/* B16DC 8011AFDC A0540001 */  sb        $s4, 1($v0)
/* B16E0 8011AFE0 8C620000 */  lw        $v0, ($v1)
/* B16E4 8011AFE4 24420001 */  addiu     $v0, $v0, 1
/* B16E8 8011AFE8 AC620000 */  sw        $v0, ($v1)
.L8011AFEC:
/* B16EC 8011AFEC 8FBF00F8 */  lw        $ra, 0xf8($sp)
/* B16F0 8011AFF0 8FB500F4 */  lw        $s5, 0xf4($sp)
/* B16F4 8011AFF4 8FB400F0 */  lw        $s4, 0xf0($sp)
/* B16F8 8011AFF8 8FB300EC */  lw        $s3, 0xec($sp)
/* B16FC 8011AFFC 8FB200E8 */  lw        $s2, 0xe8($sp)
/* B1700 8011B000 8FB100E4 */  lw        $s1, 0xe4($sp)
/* B1704 8011B004 8FB000E0 */  lw        $s0, 0xe0($sp)
/* B1708 8011B008 03E00008 */  jr        $ra
/* B170C 8011B00C 27BD0100 */   addiu    $sp, $sp, 0x100
