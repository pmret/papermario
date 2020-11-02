.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802E1660
/* 102EE0 802E1660 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 102EE4 802E1664 AFB00010 */  sw        $s0, 0x10($sp)
/* 102EE8 802E1668 0080802D */  daddu     $s0, $a0, $zero
/* 102EEC 802E166C AFBF0020 */  sw        $ra, 0x20($sp)
/* 102EF0 802E1670 AFB3001C */  sw        $s3, 0x1c($sp)
/* 102EF4 802E1674 AFB20018 */  sw        $s2, 0x18($sp)
/* 102EF8 802E1678 AFB10014 */  sw        $s1, 0x14($sp)
/* 102EFC 802E167C 0C0B854F */  jal       func_802E153C
/* 102F00 802E1680 8E130040 */   lw       $s3, 0x40($s0)
/* 102F04 802E1684 3C118011 */  lui       $s1, %hi(gPlayerStatus)
/* 102F08 802E1688 2631EFC8 */  addiu     $s1, $s1, %lo(gPlayerStatus)
/* 102F0C 802E168C 92020006 */  lbu       $v0, 6($s0)
/* 102F10 802E1690 3C128011 */  lui       $s2, %hi(D_8010EBB0)
/* 102F14 802E1694 2652EBB0 */  addiu     $s2, $s2, %lo(D_8010EBB0)
/* 102F18 802E1698 30420040 */  andi      $v0, $v0, 0x40
/* 102F1C 802E169C 1040000A */  beqz      $v0, .L802E16C8
/* 102F20 802E16A0 24020012 */   addiu    $v0, $zero, 0x12
/* 102F24 802E16A4 822300B4 */  lb        $v1, 0xb4($s1)
/* 102F28 802E16A8 14620009 */  bne       $v1, $v0, .L802E16D0
/* 102F2C 802E16AC 2402000D */   addiu    $v0, $zero, 0xd
/* 102F30 802E16B0 3C028011 */  lui       $v0, %hi(gPlayerData+0x1)
/* 102F34 802E16B4 8042F291 */  lb        $v0, %lo(gPlayerData+0x1)($v0)
/* 102F38 802E16B8 0440001A */  bltz      $v0, .L802E1724
/* 102F3C 802E16BC 00000000 */   nop      
/* 102F40 802E16C0 080B85C2 */  j         .L802E1708
/* 102F44 802E16C4 00000000 */   nop      
.L802E16C8:
/* 102F48 802E16C8 822300B4 */  lb        $v1, 0xb4($s1)
/* 102F4C 802E16CC 2402000D */  addiu     $v0, $zero, 0xd
.L802E16D0:
/* 102F50 802E16D0 10620014 */  beq       $v1, $v0, .L802E1724
/* 102F54 802E16D4 24020004 */   addiu    $v0, $zero, 4
/* 102F58 802E16D8 82430003 */  lb        $v1, 3($s2)
/* 102F5C 802E16DC 14620004 */  bne       $v1, $v0, .L802E16F0
/* 102F60 802E16E0 00000000 */   nop      
/* 102F64 802E16E4 82420000 */  lb        $v0, ($s2)
/* 102F68 802E16E8 1440000E */  bnez      $v0, .L802E1724
/* 102F6C 802E16EC 00000000 */   nop      
.L802E16F0:
/* 102F70 802E16F0 92030006 */  lbu       $v1, 6($s0)
/* 102F74 802E16F4 30620001 */  andi      $v0, $v1, 1
/* 102F78 802E16F8 14400003 */  bnez      $v0, .L802E1708
/* 102F7C 802E16FC 30620080 */   andi     $v0, $v1, 0x80
/* 102F80 802E1700 10400008 */  beqz      $v0, .L802E1724
/* 102F84 802E1704 00000000 */   nop      
.L802E1708:
/* 102F88 802E1708 0C043F5A */  jal       func_8010FD68
/* 102F8C 802E170C 0200202D */   daddu    $a0, $s0, $zero
/* 102F90 802E1710 8E640028 */  lw        $a0, 0x28($s3)
/* 102F94 802E1714 10800003 */  beqz      $a0, .L802E1724
/* 102F98 802E1718 00000000 */   nop      
/* 102F9C 802E171C 0C043F5A */  jal       func_8010FD68
/* 102FA0 802E1720 00000000 */   nop      
.L802E1724:
/* 102FA4 802E1724 8FBF0020 */  lw        $ra, 0x20($sp)
/* 102FA8 802E1728 8FB3001C */  lw        $s3, 0x1c($sp)
/* 102FAC 802E172C 8FB20018 */  lw        $s2, 0x18($sp)
/* 102FB0 802E1730 8FB10014 */  lw        $s1, 0x14($sp)
/* 102FB4 802E1734 8FB00010 */  lw        $s0, 0x10($sp)
/* 102FB8 802E1738 03E00008 */  jr        $ra
/* 102FBC 802E173C 27BD0028 */   addiu    $sp, $sp, 0x28
