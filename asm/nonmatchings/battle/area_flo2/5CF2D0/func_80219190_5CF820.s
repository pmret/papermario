.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80219190_5CF820
/* 5CF820 80219190 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 5CF824 80219194 AFB20020 */  sw        $s2, 0x20($sp)
/* 5CF828 80219198 0000902D */  daddu     $s2, $zero, $zero
/* 5CF82C 8021919C AFB1001C */  sw        $s1, 0x1c($sp)
/* 5CF830 802191A0 0240882D */  daddu     $s1, $s2, $zero
/* 5CF834 802191A4 AFB30024 */  sw        $s3, 0x24($sp)
/* 5CF838 802191A8 3C138009 */  lui       $s3, %hi(gAreas)
/* 5CF83C 802191AC 267334F0 */  addiu     $s3, $s3, %lo(gAreas)
/* 5CF840 802191B0 AFB00018 */  sw        $s0, 0x18($sp)
/* 5CF844 802191B4 3C108023 */  lui       $s0, %hi(D_80234448)
/* 5CF848 802191B8 26104448 */  addiu     $s0, $s0, %lo(D_80234448)
/* 5CF84C 802191BC AFBF0028 */  sw        $ra, 0x28($sp)
.L802191C0:
/* 5CF850 802191C0 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 5CF854 802191C4 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 5CF858 802191C8 8E050000 */  lw        $a1, ($s0)
/* 5CF85C 802191CC 84430086 */  lh        $v1, 0x86($v0)
/* 5CF860 802191D0 8442008C */  lh        $v0, 0x8c($v0)
/* 5CF864 802191D4 00031900 */  sll       $v1, $v1, 4
/* 5CF868 802191D8 00731821 */  addu      $v1, $v1, $s3
/* 5CF86C 802191DC 8C630004 */  lw        $v1, 4($v1)
/* 5CF870 802191E0 00021140 */  sll       $v0, $v0, 5
/* 5CF874 802191E4 00431021 */  addu      $v0, $v0, $v1
/* 5CF878 802191E8 0C01BB5C */  jal       strcmp
/* 5CF87C 802191EC 8C440000 */   lw       $a0, ($v0)
/* 5CF880 802191F0 14400003 */  bnez      $v0, .L80219200
/* 5CF884 802191F4 26310001 */   addiu    $s1, $s1, 1
/* 5CF888 802191F8 08086483 */  j         .L8021920C
/* 5CF88C 802191FC 24120001 */   addiu    $s2, $zero, 1
.L80219200:
/* 5CF890 80219200 2E22000B */  sltiu     $v0, $s1, 0xb
/* 5CF894 80219204 1440FFEE */  bnez      $v0, .L802191C0
/* 5CF898 80219208 26100004 */   addiu    $s0, $s0, 4
.L8021920C:
/* 5CF89C 8021920C 44800000 */  mtc1      $zero, $f0
/* 5CF8A0 80219210 00000000 */  nop       
/* 5CF8A4 80219214 44050000 */  mfc1      $a1, $f0
/* 5CF8A8 80219218 0240202D */  daddu     $a0, $s2, $zero
/* 5CF8AC 8021921C AFA00014 */  sw        $zero, 0x14($sp)
/* 5CF8B0 80219220 00A0302D */  daddu     $a2, $a1, $zero
/* 5CF8B4 80219224 00A0382D */  daddu     $a3, $a1, $zero
/* 5CF8B8 80219228 0C01CA54 */  jal       func_80072950
/* 5CF8BC 8021922C AFA50010 */   sw       $a1, 0x10($sp)
/* 5CF8C0 80219230 8FBF0028 */  lw        $ra, 0x28($sp)
/* 5CF8C4 80219234 8FB30024 */  lw        $s3, 0x24($sp)
/* 5CF8C8 80219238 8FB20020 */  lw        $s2, 0x20($sp)
/* 5CF8CC 8021923C 8FB1001C */  lw        $s1, 0x1c($sp)
/* 5CF8D0 80219240 8FB00018 */  lw        $s0, 0x18($sp)
/* 5CF8D4 80219244 24020002 */  addiu     $v0, $zero, 2
/* 5CF8D8 80219248 03E00008 */  jr        $ra
/* 5CF8DC 8021924C 27BD0030 */   addiu    $sp, $sp, 0x30
