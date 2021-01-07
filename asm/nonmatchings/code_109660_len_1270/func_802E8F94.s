.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802E8F94
/* 10A814 802E8F94 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 10A818 802E8F98 AFB10014 */  sw        $s1, 0x14($sp)
/* 10A81C 802E8F9C 0080882D */  daddu     $s1, $a0, $zero
/* 10A820 802E8FA0 3C028016 */  lui       $v0, %hi(D_8015C7D0)
/* 10A824 802E8FA4 2442C7D0 */  addiu     $v0, $v0, %lo(D_8015C7D0)
/* 10A828 802E8FA8 AFBF001C */  sw        $ra, 0x1c($sp)
/* 10A82C 802E8FAC AFB20018 */  sw        $s2, 0x18($sp)
/* 10A830 802E8FB0 AFB00010 */  sw        $s0, 0x10($sp)
/* 10A834 802E8FB4 8C430000 */  lw        $v1, ($v0)
/* 10A838 802E8FB8 8C440004 */  lw        $a0, 4($v0)
/* 10A83C 802E8FBC 8C450008 */  lw        $a1, 8($v0)
/* 10A840 802E8FC0 3C02802F */  lui       $v0, %hi(push_entity_matrix)
/* 10A844 802E8FC4 24428E4C */  addiu     $v0, $v0, %lo(push_entity_matrix)
/* 10A848 802E8FC8 8E300040 */  lw        $s0, 0x40($s1)
/* 10A84C 802E8FCC 2632004C */  addiu     $s2, $s1, 0x4c
/* 10A850 802E8FD0 AE22003C */  sw        $v0, 0x3c($s1)
/* 10A854 802E8FD4 AE03000C */  sw        $v1, 0xc($s0)
/* 10A858 802E8FD8 AE040010 */  sw        $a0, 0x10($s0)
/* 10A85C 802E8FDC AE050014 */  sw        $a1, 0x14($s0)
/* 10A860 802E8FE0 C620004C */  lwc1      $f0, 0x4c($s1)
/* 10A864 802E8FE4 00A0202D */  daddu     $a0, $a1, $zero
/* 10A868 802E8FE8 0C05152F */  jal       get_global_flag
/* 10A86C 802E8FEC E6000018 */   swc1     $f0, 0x18($s0)
/* 10A870 802E8FF0 AE020008 */  sw        $v0, 8($s0)
/* 10A874 802E8FF4 C620004C */  lwc1      $f0, 0x4c($s1)
/* 10A878 802E8FF8 460000A1 */  cvt.d.s   $f2, $f0
/* 10A87C 802E8FFC 3C01404A */  lui       $at, 0x404a
/* 10A880 802E9000 44810800 */  mtc1      $at, $f1
/* 10A884 802E9004 44800000 */  mtc1      $zero, $f0
/* 10A888 802E9008 50400006 */  beql      $v0, $zero, .L802E9024
/* 10A88C 802E900C 46201001 */   sub.d    $f0, $f2, $f0
/* 10A890 802E9010 3C01402E */  lui       $at, 0x402e
/* 10A894 802E9014 44810800 */  mtc1      $at, $f1
/* 10A898 802E9018 44800000 */  mtc1      $zero, $f0
/* 10A89C 802E901C 00000000 */  nop       
/* 10A8A0 802E9020 46201001 */  sub.d     $f0, $f2, $f0
.L802E9024:
/* 10A8A4 802E9024 46200020 */  cvt.s.d   $f0, $f0
/* 10A8A8 802E9028 E6400000 */  swc1      $f0, ($s2)
/* 10A8AC 802E902C 8FBF001C */  lw        $ra, 0x1c($sp)
/* 10A8B0 802E9030 8FB20018 */  lw        $s2, 0x18($sp)
/* 10A8B4 802E9034 8FB10014 */  lw        $s1, 0x14($sp)
/* 10A8B8 802E9038 8FB00010 */  lw        $s0, 0x10($sp)
/* 10A8BC 802E903C 03E00008 */  jr        $ra
/* 10A8C0 802E9040 27BD0020 */   addiu    $sp, $sp, 0x20
/* 10A8C4 802E9044 00000000 */  nop       
/* 10A8C8 802E9048 00000000 */  nop       
/* 10A8CC 802E904C 00000000 */  nop       
