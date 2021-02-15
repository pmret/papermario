.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802197E0_5B2C90
/* 5B2C90 802197E0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 5B2C94 802197E4 AFB20020 */  sw        $s2, 0x20($sp)
/* 5B2C98 802197E8 0000902D */  daddu     $s2, $zero, $zero
/* 5B2C9C 802197EC AFB1001C */  sw        $s1, 0x1c($sp)
/* 5B2CA0 802197F0 0240882D */  daddu     $s1, $s2, $zero
/* 5B2CA4 802197F4 AFB30024 */  sw        $s3, 0x24($sp)
/* 5B2CA8 802197F8 3C138009 */  lui       $s3, %hi(gAreas)
/* 5B2CAC 802197FC 267334F0 */  addiu     $s3, $s3, %lo(gAreas)
/* 5B2CB0 80219800 AFB00018 */  sw        $s0, 0x18($sp)
/* 5B2CB4 80219804 3C108023 */  lui       $s0, %hi(D_802328D8_5CBD88)
/* 5B2CB8 80219808 261028D8 */  addiu     $s0, $s0, %lo(D_802328D8_5CBD88)
/* 5B2CBC 8021980C AFBF0028 */  sw        $ra, 0x28($sp)
.L80219810:
/* 5B2CC0 80219810 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 5B2CC4 80219814 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 5B2CC8 80219818 8E050000 */  lw        $a1, ($s0)
/* 5B2CCC 8021981C 84430086 */  lh        $v1, 0x86($v0)
/* 5B2CD0 80219820 8442008C */  lh        $v0, 0x8c($v0)
/* 5B2CD4 80219824 00031900 */  sll       $v1, $v1, 4
/* 5B2CD8 80219828 00731821 */  addu      $v1, $v1, $s3
/* 5B2CDC 8021982C 8C630004 */  lw        $v1, 4($v1)
/* 5B2CE0 80219830 00021140 */  sll       $v0, $v0, 5
/* 5B2CE4 80219834 00431021 */  addu      $v0, $v0, $v1
/* 5B2CE8 80219838 0C01BB5C */  jal       strcmp
/* 5B2CEC 8021983C 8C440000 */   lw       $a0, ($v0)
/* 5B2CF0 80219840 14400003 */  bnez      $v0, .L80219850
/* 5B2CF4 80219844 26310001 */   addiu    $s1, $s1, 1
/* 5B2CF8 80219848 08086617 */  j         .L8021985C
/* 5B2CFC 8021984C 24120001 */   addiu    $s2, $zero, 1
.L80219850:
/* 5B2D00 80219850 2E22000B */  sltiu     $v0, $s1, 0xb
/* 5B2D04 80219854 1440FFEE */  bnez      $v0, .L80219810
/* 5B2D08 80219858 26100004 */   addiu    $s0, $s0, 4
.L8021985C:
/* 5B2D0C 8021985C 44800000 */  mtc1      $zero, $f0
/* 5B2D10 80219860 00000000 */  nop
/* 5B2D14 80219864 44050000 */  mfc1      $a1, $f0
/* 5B2D18 80219868 0240202D */  daddu     $a0, $s2, $zero
/* 5B2D1C 8021986C AFA00014 */  sw        $zero, 0x14($sp)
/* 5B2D20 80219870 00A0302D */  daddu     $a2, $a1, $zero
/* 5B2D24 80219874 00A0382D */  daddu     $a3, $a1, $zero
/* 5B2D28 80219878 0C01CA54 */  jal       func_80072950
/* 5B2D2C 8021987C AFA50010 */   sw       $a1, 0x10($sp)
/* 5B2D30 80219880 8FBF0028 */  lw        $ra, 0x28($sp)
/* 5B2D34 80219884 8FB30024 */  lw        $s3, 0x24($sp)
/* 5B2D38 80219888 8FB20020 */  lw        $s2, 0x20($sp)
/* 5B2D3C 8021988C 8FB1001C */  lw        $s1, 0x1c($sp)
/* 5B2D40 80219890 8FB00018 */  lw        $s0, 0x18($sp)
/* 5B2D44 80219894 24020002 */  addiu     $v0, $zero, 2
/* 5B2D48 80219898 03E00008 */  jr        $ra
/* 5B2D4C 8021989C 27BD0030 */   addiu    $sp, $sp, 0x30
