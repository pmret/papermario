.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80219010_5CF6A0
/* 5CF6A0 80219010 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 5CF6A4 80219014 AFB20020 */  sw        $s2, 0x20($sp)
/* 5CF6A8 80219018 0000902D */  daddu     $s2, $zero, $zero
/* 5CF6AC 8021901C AFB1001C */  sw        $s1, 0x1c($sp)
/* 5CF6B0 80219020 0240882D */  daddu     $s1, $s2, $zero
/* 5CF6B4 80219024 AFB30024 */  sw        $s3, 0x24($sp)
/* 5CF6B8 80219028 3C138009 */  lui       $s3, %hi(gAreas)
/* 5CF6BC 8021902C 267334F0 */  addiu     $s3, $s3, %lo(gAreas)
/* 5CF6C0 80219030 AFB00018 */  sw        $s0, 0x18($sp)
/* 5CF6C4 80219034 3C108023 */  lui       $s0, %hi(D_80233B18)
/* 5CF6C8 80219038 26103B18 */  addiu     $s0, $s0, %lo(D_80233B18)
/* 5CF6CC 8021903C AFBF0028 */  sw        $ra, 0x28($sp)
.L80219040:
/* 5CF6D0 80219040 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 5CF6D4 80219044 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 5CF6D8 80219048 8E050000 */  lw        $a1, ($s0)
/* 5CF6DC 8021904C 84430086 */  lh        $v1, 0x86($v0)
/* 5CF6E0 80219050 8442008C */  lh        $v0, 0x8c($v0)
/* 5CF6E4 80219054 00031900 */  sll       $v1, $v1, 4
/* 5CF6E8 80219058 00731821 */  addu      $v1, $v1, $s3
/* 5CF6EC 8021905C 8C630004 */  lw        $v1, 4($v1)
/* 5CF6F0 80219060 00021140 */  sll       $v0, $v0, 5
/* 5CF6F4 80219064 00431021 */  addu      $v0, $v0, $v1
/* 5CF6F8 80219068 0C01BB5C */  jal       strcmp
/* 5CF6FC 8021906C 8C440000 */   lw       $a0, ($v0)
/* 5CF700 80219070 14400003 */  bnez      $v0, .L80219080
/* 5CF704 80219074 26310001 */   addiu    $s1, $s1, 1
/* 5CF708 80219078 08086423 */  j         .L8021908C
/* 5CF70C 8021907C 24120001 */   addiu    $s2, $zero, 1
.L80219080:
/* 5CF710 80219080 2E22000B */  sltiu     $v0, $s1, 0xb
/* 5CF714 80219084 1440FFEE */  bnez      $v0, .L80219040
/* 5CF718 80219088 26100004 */   addiu    $s0, $s0, 4
.L8021908C:
/* 5CF71C 8021908C 44800000 */  mtc1      $zero, $f0
/* 5CF720 80219090 00000000 */  nop
/* 5CF724 80219094 44050000 */  mfc1      $a1, $f0
/* 5CF728 80219098 0240202D */  daddu     $a0, $s2, $zero
/* 5CF72C 8021909C AFA00014 */  sw        $zero, 0x14($sp)
/* 5CF730 802190A0 00A0302D */  daddu     $a2, $a1, $zero
/* 5CF734 802190A4 00A0382D */  daddu     $a3, $a1, $zero
/* 5CF738 802190A8 0C01CA54 */  jal       func_80072950
/* 5CF73C 802190AC AFA50010 */   sw       $a1, 0x10($sp)
/* 5CF740 802190B0 8FBF0028 */  lw        $ra, 0x28($sp)
/* 5CF744 802190B4 8FB30024 */  lw        $s3, 0x24($sp)
/* 5CF748 802190B8 8FB20020 */  lw        $s2, 0x20($sp)
/* 5CF74C 802190BC 8FB1001C */  lw        $s1, 0x1c($sp)
/* 5CF750 802190C0 8FB00018 */  lw        $s0, 0x18($sp)
/* 5CF754 802190C4 24020002 */  addiu     $v0, $zero, 2
/* 5CF758 802190C8 03E00008 */  jr        $ra
/* 5CF75C 802190CC 27BD0030 */   addiu    $sp, $sp, 0x30
