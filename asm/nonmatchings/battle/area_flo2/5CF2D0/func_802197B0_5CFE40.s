.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802197B0_5CFE40
/* 5CFE40 802197B0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 5CFE44 802197B4 AFB20020 */  sw        $s2, 0x20($sp)
/* 5CFE48 802197B8 0000902D */  daddu     $s2, $zero, $zero
/* 5CFE4C 802197BC AFB1001C */  sw        $s1, 0x1c($sp)
/* 5CFE50 802197C0 0240882D */  daddu     $s1, $s2, $zero
/* 5CFE54 802197C4 AFB30024 */  sw        $s3, 0x24($sp)
/* 5CFE58 802197C8 3C138009 */  lui       $s3, %hi(gAreas)
/* 5CFE5C 802197CC 267334F0 */  addiu     $s3, $s3, %lo(gAreas)
/* 5CFE60 802197D0 AFB00018 */  sw        $s0, 0x18($sp)
/* 5CFE64 802197D4 3C108023 */  lui       $s0, %hi(D_802354C0)
/* 5CFE68 802197D8 261054C0 */  addiu     $s0, $s0, %lo(D_802354C0)
/* 5CFE6C 802197DC AFBF0028 */  sw        $ra, 0x28($sp)
.L802197E0:
/* 5CFE70 802197E0 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 5CFE74 802197E4 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 5CFE78 802197E8 8E050000 */  lw        $a1, ($s0)
/* 5CFE7C 802197EC 84430086 */  lh        $v1, 0x86($v0)
/* 5CFE80 802197F0 8442008C */  lh        $v0, 0x8c($v0)
/* 5CFE84 802197F4 00031900 */  sll       $v1, $v1, 4
/* 5CFE88 802197F8 00731821 */  addu      $v1, $v1, $s3
/* 5CFE8C 802197FC 8C630004 */  lw        $v1, 4($v1)
/* 5CFE90 80219800 00021140 */  sll       $v0, $v0, 5
/* 5CFE94 80219804 00431021 */  addu      $v0, $v0, $v1
/* 5CFE98 80219808 0C01BB5C */  jal       strcmp
/* 5CFE9C 8021980C 8C440000 */   lw       $a0, ($v0)
/* 5CFEA0 80219810 14400003 */  bnez      $v0, .L80219820
/* 5CFEA4 80219814 26310001 */   addiu    $s1, $s1, 1
/* 5CFEA8 80219818 0808660B */  j         .L8021982C
/* 5CFEAC 8021981C 24120001 */   addiu    $s2, $zero, 1
.L80219820:
/* 5CFEB0 80219820 2E22000B */  sltiu     $v0, $s1, 0xb
/* 5CFEB4 80219824 1440FFEE */  bnez      $v0, .L802197E0
/* 5CFEB8 80219828 26100004 */   addiu    $s0, $s0, 4
.L8021982C:
/* 5CFEBC 8021982C 44800000 */  mtc1      $zero, $f0
/* 5CFEC0 80219830 00000000 */  nop
/* 5CFEC4 80219834 44050000 */  mfc1      $a1, $f0
/* 5CFEC8 80219838 0240202D */  daddu     $a0, $s2, $zero
/* 5CFECC 8021983C AFA00014 */  sw        $zero, 0x14($sp)
/* 5CFED0 80219840 00A0302D */  daddu     $a2, $a1, $zero
/* 5CFED4 80219844 00A0382D */  daddu     $a3, $a1, $zero
/* 5CFED8 80219848 0C01CA54 */  jal       func_80072950
/* 5CFEDC 8021984C AFA50010 */   sw       $a1, 0x10($sp)
/* 5CFEE0 80219850 8FBF0028 */  lw        $ra, 0x28($sp)
/* 5CFEE4 80219854 8FB30024 */  lw        $s3, 0x24($sp)
/* 5CFEE8 80219858 8FB20020 */  lw        $s2, 0x20($sp)
/* 5CFEEC 8021985C 8FB1001C */  lw        $s1, 0x1c($sp)
/* 5CFEF0 80219860 8FB00018 */  lw        $s0, 0x18($sp)
/* 5CFEF4 80219864 24020002 */  addiu     $v0, $zero, 2
/* 5CFEF8 80219868 03E00008 */  jr        $ra
/* 5CFEFC 8021986C 27BD0030 */   addiu    $sp, $sp, 0x30
