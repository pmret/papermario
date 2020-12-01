.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802E56EC
/* 106F6C 802E56EC 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 106F70 802E56F0 AFB1001C */  sw        $s1, 0x1c($sp)
/* 106F74 802E56F4 0080882D */  daddu     $s1, $a0, $zero
/* 106F78 802E56F8 AFBF0020 */  sw        $ra, 0x20($sp)
/* 106F7C 802E56FC AFB00018 */  sw        $s0, 0x18($sp)
/* 106F80 802E5700 8E300040 */  lw        $s0, 0x40($s1)
/* 106F84 802E5704 9603000A */  lhu       $v1, 0xa($s0)
/* 106F88 802E5708 3402FFFF */  ori       $v0, $zero, 0xffff
/* 106F8C 802E570C 1062001A */  beq       $v1, $v0, .L802E5778
/* 106F90 802E5710 00000000 */   nop      
/* 106F94 802E5714 0C05152F */  jal       get_global_flag
/* 106F98 802E5718 0060202D */   daddu    $a0, $v1, $zero
/* 106F9C 802E571C 14400016 */  bnez      $v0, .L802E5778
/* 106FA0 802E5720 3C028000 */   lui      $v0, 0x8000
/* 106FA4 802E5724 3C04802F */  lui       $a0, %hi(D_802EA934)
/* 106FA8 802E5728 2484A934 */  addiu     $a0, $a0, %lo(D_802EA934)
/* 106FAC 802E572C C6200048 */  lwc1      $f0, 0x48($s1)
/* 106FB0 802E5730 C622004C */  lwc1      $f2, 0x4c($s1)
/* 106FB4 802E5734 C6240050 */  lwc1      $f4, 0x50($s1)
/* 106FB8 802E5738 AFA00010 */  sw        $zero, 0x10($sp)
/* 106FBC 802E573C 4600018D */  trunc.w.s $f6, $f0
/* 106FC0 802E5740 44053000 */  mfc1      $a1, $f6
/* 106FC4 802E5744 4600118D */  trunc.w.s $f6, $f2
/* 106FC8 802E5748 44063000 */  mfc1      $a2, $f6
/* 106FCC 802E574C 4600218D */  trunc.w.s $f6, $f4
/* 106FD0 802E5750 44073000 */  mfc1      $a3, $f6
/* 106FD4 802E5754 0C044631 */  jal       create_entity
/* 106FD8 802E5758 AFA20014 */   sw       $v0, 0x14($sp)
/* 106FDC 802E575C 00022400 */  sll       $a0, $v0, 0x10
/* 106FE0 802E5760 00042403 */  sra       $a0, $a0, 0x10
/* 106FE4 802E5764 0C04417A */  jal       get_entity_by_index
/* 106FE8 802E5768 A6020012 */   sh       $v0, 0x12($s0)
/* 106FEC 802E576C 8C430040 */  lw        $v1, 0x40($v0)
/* 106FF0 802E5770 92220004 */  lbu       $v0, 4($s1)
/* 106FF4 802E5774 A0620000 */  sb        $v0, ($v1)
.L802E5778:
/* 106FF8 802E5778 8FBF0020 */  lw        $ra, 0x20($sp)
/* 106FFC 802E577C 8FB1001C */  lw        $s1, 0x1c($sp)
/* 107000 802E5780 8FB00018 */  lw        $s0, 0x18($sp)
/* 107004 802E5784 03E00008 */  jr        $ra
/* 107008 802E5788 27BD0028 */   addiu    $sp, $sp, 0x28
