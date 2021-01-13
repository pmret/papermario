.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80219250_5CF8E0
/* 5CF8E0 80219250 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 5CF8E4 80219254 AFB20020 */  sw        $s2, 0x20($sp)
/* 5CF8E8 80219258 0000902D */  daddu     $s2, $zero, $zero
/* 5CF8EC 8021925C AFB1001C */  sw        $s1, 0x1c($sp)
/* 5CF8F0 80219260 0240882D */  daddu     $s1, $s2, $zero
/* 5CF8F4 80219264 AFB30024 */  sw        $s3, 0x24($sp)
/* 5CF8F8 80219268 3C138009 */  lui       $s3, %hi(gAreas)
/* 5CF8FC 8021926C 267334F0 */  addiu     $s3, $s3, %lo(gAreas)
/* 5CF900 80219270 AFB00018 */  sw        $s0, 0x18($sp)
/* 5CF904 80219274 3C108023 */  lui       $s0, %hi(D_80234758)
/* 5CF908 80219278 26104758 */  addiu     $s0, $s0, %lo(D_80234758)
/* 5CF90C 8021927C AFBF0028 */  sw        $ra, 0x28($sp)
.L80219280:
/* 5CF910 80219280 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 5CF914 80219284 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 5CF918 80219288 8E050000 */  lw        $a1, ($s0)
/* 5CF91C 8021928C 84430086 */  lh        $v1, 0x86($v0)
/* 5CF920 80219290 8442008C */  lh        $v0, 0x8c($v0)
/* 5CF924 80219294 00031900 */  sll       $v1, $v1, 4
/* 5CF928 80219298 00731821 */  addu      $v1, $v1, $s3
/* 5CF92C 8021929C 8C630004 */  lw        $v1, 4($v1)
/* 5CF930 802192A0 00021140 */  sll       $v0, $v0, 5
/* 5CF934 802192A4 00431021 */  addu      $v0, $v0, $v1
/* 5CF938 802192A8 0C01BB5C */  jal       strcmp
/* 5CF93C 802192AC 8C440000 */   lw       $a0, ($v0)
/* 5CF940 802192B0 14400003 */  bnez      $v0, .L802192C0
/* 5CF944 802192B4 26310001 */   addiu    $s1, $s1, 1
/* 5CF948 802192B8 080864B3 */  j         .L802192CC
/* 5CF94C 802192BC 24120001 */   addiu    $s2, $zero, 1
.L802192C0:
/* 5CF950 802192C0 2E22000B */  sltiu     $v0, $s1, 0xb
/* 5CF954 802192C4 1440FFEE */  bnez      $v0, .L80219280
/* 5CF958 802192C8 26100004 */   addiu    $s0, $s0, 4
.L802192CC:
/* 5CF95C 802192CC 44800000 */  mtc1      $zero, $f0
/* 5CF960 802192D0 00000000 */  nop
/* 5CF964 802192D4 44050000 */  mfc1      $a1, $f0
/* 5CF968 802192D8 0240202D */  daddu     $a0, $s2, $zero
/* 5CF96C 802192DC AFA00014 */  sw        $zero, 0x14($sp)
/* 5CF970 802192E0 00A0302D */  daddu     $a2, $a1, $zero
/* 5CF974 802192E4 00A0382D */  daddu     $a3, $a1, $zero
/* 5CF978 802192E8 0C01CA54 */  jal       func_80072950
/* 5CF97C 802192EC AFA50010 */   sw       $a1, 0x10($sp)
/* 5CF980 802192F0 8FBF0028 */  lw        $ra, 0x28($sp)
/* 5CF984 802192F4 8FB30024 */  lw        $s3, 0x24($sp)
/* 5CF988 802192F8 8FB20020 */  lw        $s2, 0x20($sp)
/* 5CF98C 802192FC 8FB1001C */  lw        $s1, 0x1c($sp)
/* 5CF990 80219300 8FB00018 */  lw        $s0, 0x18($sp)
/* 5CF994 80219304 24020002 */  addiu     $v0, $zero, 2
/* 5CF998 80219308 03E00008 */  jr        $ra
/* 5CF99C 8021930C 27BD0030 */   addiu    $sp, $sp, 0x30
