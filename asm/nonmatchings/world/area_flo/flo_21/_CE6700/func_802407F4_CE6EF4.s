.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802407F4_CE6EF4
/* CE6EF4 802407F4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* CE6EF8 802407F8 AFB00010 */  sw        $s0, 0x10($sp)
/* CE6EFC 802407FC 0080802D */  daddu     $s0, $a0, $zero
/* CE6F00 80240800 AFBF0014 */  sw        $ra, 0x14($sp)
/* CE6F04 80240804 8E0300A8 */  lw        $v1, 0xa8($s0)
/* CE6F08 80240808 8E020088 */  lw        $v0, 0x88($s0)
/* CE6F0C 8024080C 00621821 */  addu      $v1, $v1, $v0
/* CE6F10 80240810 04610004 */  bgez      $v1, .L80240824
/* CE6F14 80240814 AE0300A8 */   sw       $v1, 0xa8($s0)
/* CE6F18 80240818 3C020002 */  lui       $v0, 2
/* CE6F1C 8024081C 0809020D */  j         .L80240834
/* CE6F20 80240820 00621021 */   addu     $v0, $v1, $v0
.L80240824:
/* CE6F24 80240824 3C040002 */  lui       $a0, 2
/* CE6F28 80240828 0083102A */  slt       $v0, $a0, $v1
/* CE6F2C 8024082C 10400002 */  beqz      $v0, .L80240838
/* CE6F30 80240830 00641023 */   subu     $v0, $v1, $a0
.L80240834:
/* CE6F34 80240834 AE0200A8 */  sw        $v0, 0xa8($s0)
.L80240838:
/* CE6F38 80240838 8E0300AC */  lw        $v1, 0xac($s0)
/* CE6F3C 8024083C 8E02008C */  lw        $v0, 0x8c($s0)
/* CE6F40 80240840 00621821 */  addu      $v1, $v1, $v0
/* CE6F44 80240844 04610004 */  bgez      $v1, .L80240858
/* CE6F48 80240848 AE0300AC */   sw       $v1, 0xac($s0)
/* CE6F4C 8024084C 3C020002 */  lui       $v0, 2
/* CE6F50 80240850 0809021A */  j         .L80240868
/* CE6F54 80240854 00621021 */   addu     $v0, $v1, $v0
.L80240858:
/* CE6F58 80240858 3C040002 */  lui       $a0, 2
/* CE6F5C 8024085C 0083102A */  slt       $v0, $a0, $v1
/* CE6F60 80240860 10400002 */  beqz      $v0, .L8024086C
/* CE6F64 80240864 00641023 */   subu     $v0, $v1, $a0
.L80240868:
/* CE6F68 80240868 AE0200AC */  sw        $v0, 0xac($s0)
.L8024086C:
/* CE6F6C 8024086C 8E0300B0 */  lw        $v1, 0xb0($s0)
/* CE6F70 80240870 8E020090 */  lw        $v0, 0x90($s0)
/* CE6F74 80240874 00621821 */  addu      $v1, $v1, $v0
/* CE6F78 80240878 04610004 */  bgez      $v1, .L8024088C
/* CE6F7C 8024087C AE0300B0 */   sw       $v1, 0xb0($s0)
/* CE6F80 80240880 3C020002 */  lui       $v0, 2
/* CE6F84 80240884 08090227 */  j         .L8024089C
/* CE6F88 80240888 00621021 */   addu     $v0, $v1, $v0
.L8024088C:
/* CE6F8C 8024088C 3C040002 */  lui       $a0, 2
/* CE6F90 80240890 0083102A */  slt       $v0, $a0, $v1
/* CE6F94 80240894 10400002 */  beqz      $v0, .L802408A0
/* CE6F98 80240898 00641023 */   subu     $v0, $v1, $a0
.L8024089C:
/* CE6F9C 8024089C AE0200B0 */  sw        $v0, 0xb0($s0)
.L802408A0:
/* CE6FA0 802408A0 8E0300B4 */  lw        $v1, 0xb4($s0)
/* CE6FA4 802408A4 8E020094 */  lw        $v0, 0x94($s0)
/* CE6FA8 802408A8 00621821 */  addu      $v1, $v1, $v0
/* CE6FAC 802408AC 04610004 */  bgez      $v1, .L802408C0
/* CE6FB0 802408B0 AE0300B4 */   sw       $v1, 0xb4($s0)
/* CE6FB4 802408B4 3C020002 */  lui       $v0, 2
/* CE6FB8 802408B8 08090234 */  j         .L802408D0
/* CE6FBC 802408BC 00621021 */   addu     $v0, $v1, $v0
.L802408C0:
/* CE6FC0 802408C0 3C040002 */  lui       $a0, 2
/* CE6FC4 802408C4 0083102A */  slt       $v0, $a0, $v1
/* CE6FC8 802408C8 10400002 */  beqz      $v0, .L802408D4
/* CE6FCC 802408CC 00641023 */   subu     $v0, $v1, $a0
.L802408D0:
/* CE6FD0 802408D0 AE0200B4 */  sw        $v0, 0xb4($s0)
.L802408D4:
/* CE6FD4 802408D4 8E040084 */  lw        $a0, 0x84($s0)
/* CE6FD8 802408D8 0C046F07 */  jal       set_main_pan_u
/* CE6FDC 802408DC 8E0500A8 */   lw       $a1, 0xa8($s0)
/* CE6FE0 802408E0 8E040084 */  lw        $a0, 0x84($s0)
/* CE6FE4 802408E4 0C046F0D */  jal       set_main_pan_v
/* CE6FE8 802408E8 8E0500AC */   lw       $a1, 0xac($s0)
/* CE6FEC 802408EC 8E040084 */  lw        $a0, 0x84($s0)
/* CE6FF0 802408F0 0C046F13 */  jal       set_aux_pan_u
/* CE6FF4 802408F4 8E0500B0 */   lw       $a1, 0xb0($s0)
/* CE6FF8 802408F8 8E040084 */  lw        $a0, 0x84($s0)
/* CE6FFC 802408FC 0C046F19 */  jal       set_aux_pan_v
/* CE7000 80240900 8E0500B4 */   lw       $a1, 0xb4($s0)
/* CE7004 80240904 8FBF0014 */  lw        $ra, 0x14($sp)
/* CE7008 80240908 8FB00010 */  lw        $s0, 0x10($sp)
/* CE700C 8024090C 0000102D */  daddu     $v0, $zero, $zero
/* CE7010 80240910 03E00008 */  jr        $ra
/* CE7014 80240914 27BD0018 */   addiu    $sp, $sp, 0x18
