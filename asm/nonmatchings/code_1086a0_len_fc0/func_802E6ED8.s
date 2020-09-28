.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802E6ED8
/* 108758 802E6ED8 27BDFF48 */  addiu     $sp, $sp, -0xb8
/* 10875C 802E6EDC AFB500AC */  sw        $s5, 0xac($sp)
/* 108760 802E6EE0 3C15800A */  lui       $s5, 0x800a
/* 108764 802E6EE4 26B5A66C */  addiu     $s5, $s5, -0x5994
/* 108768 802E6EE8 AFBF00B0 */  sw        $ra, 0xb0($sp)
/* 10876C 802E6EEC AFB400A8 */  sw        $s4, 0xa8($sp)
/* 108770 802E6EF0 AFB300A4 */  sw        $s3, 0xa4($sp)
/* 108774 802E6EF4 AFB200A0 */  sw        $s2, 0xa0($sp)
/* 108778 802E6EF8 AFB1009C */  sw        $s1, 0x9c($sp)
/* 10877C 802E6EFC AFB00098 */  sw        $s0, 0x98($sp)
/* 108780 802E6F00 8EB00000 */  lw        $s0, ($s5)
/* 108784 802E6F04 0C04417A */  jal       get_entity_by_index
/* 108788 802E6F08 3C140001 */   lui      $s4, 1
/* 10878C 802E6F0C 27B10058 */  addiu     $s1, $sp, 0x58
/* 108790 802E6F10 0220202D */  daddu     $a0, $s1, $zero
/* 108794 802E6F14 0040902D */  daddu     $s2, $v0, $zero
/* 108798 802E6F18 3C063F80 */  lui       $a2, 0x3f80
/* 10879C 802E6F1C 8E420040 */  lw        $v0, 0x40($s2)
/* 1087A0 802E6F20 44800000 */  mtc1      $zero, $f0
/* 1087A4 802E6F24 00000000 */  nop       
/* 1087A8 802E6F28 E7A00010 */  swc1      $f0, 0x10($sp)
/* 1087AC 802E6F2C 8C450008 */  lw        $a1, 8($v0)
/* 1087B0 802E6F30 44070000 */  mfc1      $a3, $f0
/* 1087B4 802E6F34 0C019EC8 */  jal       guRotateF
/* 1087B8 802E6F38 36941630 */   ori      $s4, $s4, 0x1630
/* 1087BC 802E6F3C 27A40018 */  addiu     $a0, $sp, 0x18
/* 1087C0 802E6F40 3C050A00 */  lui       $a1, 0xa00
/* 1087C4 802E6F44 24A50C48 */  addiu     $a1, $a1, 0xc48
/* 1087C8 802E6F48 8E420044 */  lw        $v0, 0x44($s2)
/* 1087CC 802E6F4C 30A5FFFF */  andi      $a1, $a1, 0xffff
/* 1087D0 802E6F50 0C019D60 */  jal       guMtxL2F
/* 1087D4 802E6F54 00452821 */   addu     $a1, $v0, $a1
/* 1087D8 802E6F58 0220202D */  daddu     $a0, $s1, $zero
/* 1087DC 802E6F5C 27A50018 */  addiu     $a1, $sp, 0x18
/* 1087E0 802E6F60 0C019D80 */  jal       guMtxCatF
/* 1087E4 802E6F64 00A0302D */   daddu    $a2, $a1, $zero
/* 1087E8 802E6F68 27A40018 */  addiu     $a0, $sp, 0x18
/* 1087EC 802E6F6C 3C118007 */  lui       $s1, 0x8007
/* 1087F0 802E6F70 263141F0 */  addiu     $s1, $s1, 0x41f0
/* 1087F4 802E6F74 3C13800A */  lui       $s3, 0x800a
/* 1087F8 802E6F78 2673A674 */  addiu     $s3, $s3, -0x598c
/* 1087FC 802E6F7C 96250000 */  lhu       $a1, ($s1)
/* 108800 802E6F80 8E620000 */  lw        $v0, ($s3)
/* 108804 802E6F84 00052980 */  sll       $a1, $a1, 6
/* 108808 802E6F88 00B42821 */  addu      $a1, $a1, $s4
/* 10880C 802E6F8C 0C019D40 */  jal       guMtxF2L
/* 108810 802E6F90 00452821 */   addu     $a1, $v0, $a1
/* 108814 802E6F94 0200202D */  daddu     $a0, $s0, $zero
/* 108818 802E6F98 26100008 */  addiu     $s0, $s0, 8
/* 10881C 802E6F9C 0200282D */  daddu     $a1, $s0, $zero
/* 108820 802E6FA0 26100008 */  addiu     $s0, $s0, 8
/* 108824 802E6FA4 0200302D */  daddu     $a2, $s0, $zero
/* 108828 802E6FA8 26100008 */  addiu     $s0, $s0, 8
/* 10882C 802E6FAC 3C07D838 */  lui       $a3, 0xd838
/* 108830 802E6FB0 34E70002 */  ori       $a3, $a3, 2
/* 108834 802E6FB4 96220000 */  lhu       $v0, ($s1)
/* 108838 802E6FB8 3C03DA38 */  lui       $v1, 0xda38
/* 10883C 802E6FBC AC830000 */  sw        $v1, ($a0)
/* 108840 802E6FC0 AEB00000 */  sw        $s0, ($s5)
/* 108844 802E6FC4 24430001 */  addiu     $v1, $v0, 1
/* 108848 802E6FC8 3042FFFF */  andi      $v0, $v0, 0xffff
/* 10884C 802E6FCC 00021180 */  sll       $v0, $v0, 6
/* 108850 802E6FD0 A6230000 */  sh        $v1, ($s1)
/* 108854 802E6FD4 8E630000 */  lw        $v1, ($s3)
/* 108858 802E6FD8 00541021 */  addu      $v0, $v0, $s4
/* 10885C 802E6FDC 00621821 */  addu      $v1, $v1, $v0
/* 108860 802E6FE0 AC830004 */  sw        $v1, 4($a0)
/* 108864 802E6FE4 8E430044 */  lw        $v1, 0x44($s2)
/* 108868 802E6FE8 3C02DE00 */  lui       $v0, 0xde00
/* 10886C 802E6FEC ACA20000 */  sw        $v0, ($a1)
/* 108870 802E6FF0 3C020A00 */  lui       $v0, 0xa00
/* 108874 802E6FF4 24420DC0 */  addiu     $v0, $v0, 0xdc0
/* 108878 802E6FF8 3042FFFF */  andi      $v0, $v0, 0xffff
/* 10887C 802E6FFC 00621821 */  addu      $v1, $v1, $v0
/* 108880 802E7000 24020040 */  addiu     $v0, $zero, 0x40
/* 108884 802E7004 ACA30004 */  sw        $v1, 4($a1)
/* 108888 802E7008 ACC70000 */  sw        $a3, ($a2)
/* 10888C 802E700C ACC20004 */  sw        $v0, 4($a2)
/* 108890 802E7010 8FBF00B0 */  lw        $ra, 0xb0($sp)
/* 108894 802E7014 8FB500AC */  lw        $s5, 0xac($sp)
/* 108898 802E7018 8FB400A8 */  lw        $s4, 0xa8($sp)
/* 10889C 802E701C 8FB300A4 */  lw        $s3, 0xa4($sp)
/* 1088A0 802E7020 8FB200A0 */  lw        $s2, 0xa0($sp)
/* 1088A4 802E7024 8FB1009C */  lw        $s1, 0x9c($sp)
/* 1088A8 802E7028 8FB00098 */  lw        $s0, 0x98($sp)
/* 1088AC 802E702C 03E00008 */  jr        $ra
/* 1088B0 802E7030 27BD00B8 */   addiu    $sp, $sp, 0xb8
