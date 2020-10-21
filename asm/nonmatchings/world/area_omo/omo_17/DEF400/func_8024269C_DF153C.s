.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024269C_DF153C
/* DF153C 8024269C 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* DF1540 802426A0 AFB20038 */  sw        $s2, 0x38($sp)
/* DF1544 802426A4 0080902D */  daddu     $s2, $a0, $zero
/* DF1548 802426A8 AFB00030 */  sw        $s0, 0x30($sp)
/* DF154C 802426AC AFBF003C */  sw        $ra, 0x3c($sp)
/* DF1550 802426B0 AFB10034 */  sw        $s1, 0x34($sp)
/* DF1554 802426B4 F7B60048 */  sdc1      $f22, 0x48($sp)
/* DF1558 802426B8 F7B40040 */  sdc1      $f20, 0x40($sp)
/* DF155C 802426BC 8E510148 */  lw        $s1, 0x148($s2)
/* DF1560 802426C0 4485A000 */  mtc1      $a1, $f20
/* DF1564 802426C4 86240008 */  lh        $a0, 8($s1)
/* DF1568 802426C8 4486B000 */  mtc1      $a2, $f22
/* DF156C 802426CC 0C00EABB */  jal       get_npc_unsafe
/* DF1570 802426D0 00E0802D */   daddu    $s0, $a3, $zero
/* DF1574 802426D4 0200202D */  daddu     $a0, $s0, $zero
/* DF1578 802426D8 0220282D */  daddu     $a1, $s1, $zero
/* DF157C 802426DC 24030001 */  addiu     $v1, $zero, 1
/* DF1580 802426E0 4406A000 */  mfc1      $a2, $f20
/* DF1584 802426E4 4407B000 */  mfc1      $a3, $f22
/* DF1588 802426E8 0040802D */  daddu     $s0, $v0, $zero
/* DF158C 802426EC 0C01242D */  jal       func_800490B4
/* DF1590 802426F0 AFA30010 */   sw       $v1, 0x10($sp)
/* DF1594 802426F4 1440001D */  bnez      $v0, .L8024276C
/* DF1598 802426F8 24040002 */   addiu    $a0, $zero, 2
/* DF159C 802426FC 0200282D */  daddu     $a1, $s0, $zero
/* DF15A0 80242700 0000302D */  daddu     $a2, $zero, $zero
/* DF15A4 80242704 860300A8 */  lh        $v1, 0xa8($s0)
/* DF15A8 80242708 3C013F80 */  lui       $at, 0x3f80
/* DF15AC 8024270C 44810000 */  mtc1      $at, $f0
/* DF15B0 80242710 3C014000 */  lui       $at, 0x4000
/* DF15B4 80242714 44811000 */  mtc1      $at, $f2
/* DF15B8 80242718 3C01C1A0 */  lui       $at, 0xc1a0
/* DF15BC 8024271C 44812000 */  mtc1      $at, $f4
/* DF15C0 80242720 2402000F */  addiu     $v0, $zero, 0xf
/* DF15C4 80242724 AFA2001C */  sw        $v0, 0x1c($sp)
/* DF15C8 80242728 44833000 */  mtc1      $v1, $f6
/* DF15CC 8024272C 00000000 */  nop       
/* DF15D0 80242730 468031A0 */  cvt.s.w   $f6, $f6
/* DF15D4 80242734 44073000 */  mfc1      $a3, $f6
/* DF15D8 80242738 27A20028 */  addiu     $v0, $sp, 0x28
/* DF15DC 8024273C AFA20020 */  sw        $v0, 0x20($sp)
/* DF15E0 80242740 E7A00010 */  swc1      $f0, 0x10($sp)
/* DF15E4 80242744 E7A20014 */  swc1      $f2, 0x14($sp)
/* DF15E8 80242748 0C01BFA4 */  jal       fx_emote
/* DF15EC 8024274C E7A40018 */   swc1     $f4, 0x18($sp)
/* DF15F0 80242750 8E2200CC */  lw        $v0, 0xcc($s1)
/* DF15F4 80242754 8C430000 */  lw        $v1, ($v0)
/* DF15F8 80242758 24020014 */  addiu     $v0, $zero, 0x14
/* DF15FC 8024275C A602008E */  sh        $v0, 0x8e($s0)
/* DF1600 80242760 24020021 */  addiu     $v0, $zero, 0x21
/* DF1604 80242764 080909EF */  j         .L802427BC
/* DF1608 80242768 AE030028 */   sw       $v1, 0x28($s0)
.L8024276C:
/* DF160C 8024276C 0C09092B */  jal       func_802424AC_DF134C
/* DF1610 80242770 0240202D */   daddu    $a0, $s2, $zero
/* DF1614 80242774 0040202D */  daddu     $a0, $v0, $zero
/* DF1618 80242778 2402FFFF */  addiu     $v0, $zero, -1
/* DF161C 8024277C 10820010 */  beq       $a0, $v0, .L802427C0
/* DF1620 80242780 00000000 */   nop      
/* DF1624 80242784 0C00FB3A */  jal       get_enemy
/* DF1628 80242788 00000000 */   nop      
/* DF162C 8024278C 8C42006C */  lw        $v0, 0x6c($v0)
/* DF1630 80242790 1440000B */  bnez      $v0, .L802427C0
/* DF1634 80242794 00000000 */   nop      
/* DF1638 80242798 8602008C */  lh        $v0, 0x8c($s0)
/* DF163C 8024279C 14400008 */  bnez      $v0, .L802427C0
/* DF1640 802427A0 00000000 */   nop      
/* DF1644 802427A4 8E2200CC */  lw        $v0, 0xcc($s1)
/* DF1648 802427A8 8C420020 */  lw        $v0, 0x20($v0)
/* DF164C 802427AC AE020028 */  sw        $v0, 0x28($s0)
/* DF1650 802427B0 96220072 */  lhu       $v0, 0x72($s1)
/* DF1654 802427B4 A602008E */  sh        $v0, 0x8e($s0)
/* DF1658 802427B8 2402001E */  addiu     $v0, $zero, 0x1e
.L802427BC:
/* DF165C 802427BC AE420070 */  sw        $v0, 0x70($s2)
.L802427C0:
/* DF1660 802427C0 8FBF003C */  lw        $ra, 0x3c($sp)
/* DF1664 802427C4 8FB20038 */  lw        $s2, 0x38($sp)
/* DF1668 802427C8 8FB10034 */  lw        $s1, 0x34($sp)
/* DF166C 802427CC 8FB00030 */  lw        $s0, 0x30($sp)
/* DF1670 802427D0 D7B60048 */  ldc1      $f22, 0x48($sp)
/* DF1674 802427D4 D7B40040 */  ldc1      $f20, 0x40($sp)
/* DF1678 802427D8 03E00008 */  jr        $ra
/* DF167C 802427DC 27BD0050 */   addiu    $sp, $sp, 0x50
