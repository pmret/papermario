.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802190D0_5CF760
/* 5CF760 802190D0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 5CF764 802190D4 AFB20020 */  sw        $s2, 0x20($sp)
/* 5CF768 802190D8 0000902D */  daddu     $s2, $zero, $zero
/* 5CF76C 802190DC AFB1001C */  sw        $s1, 0x1c($sp)
/* 5CF770 802190E0 0240882D */  daddu     $s1, $s2, $zero
/* 5CF774 802190E4 AFB30024 */  sw        $s3, 0x24($sp)
/* 5CF778 802190E8 3C138009 */  lui       $s3, %hi(gAreas)
/* 5CF77C 802190EC 267334F0 */  addiu     $s3, $s3, %lo(gAreas)
/* 5CF780 802190F0 AFB00018 */  sw        $s0, 0x18($sp)
/* 5CF784 802190F4 3C108023 */  lui       $s0, %hi(D_80233F98_5EA628)
/* 5CF788 802190F8 26103F98 */  addiu     $s0, $s0, %lo(D_80233F98_5EA628)
/* 5CF78C 802190FC AFBF0028 */  sw        $ra, 0x28($sp)
.L80219100:
/* 5CF790 80219100 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 5CF794 80219104 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 5CF798 80219108 8E050000 */  lw        $a1, ($s0)
/* 5CF79C 8021910C 84430086 */  lh        $v1, 0x86($v0)
/* 5CF7A0 80219110 8442008C */  lh        $v0, 0x8c($v0)
/* 5CF7A4 80219114 00031900 */  sll       $v1, $v1, 4
/* 5CF7A8 80219118 00731821 */  addu      $v1, $v1, $s3
/* 5CF7AC 8021911C 8C630004 */  lw        $v1, 4($v1)
/* 5CF7B0 80219120 00021140 */  sll       $v0, $v0, 5
/* 5CF7B4 80219124 00431021 */  addu      $v0, $v0, $v1
/* 5CF7B8 80219128 0C01BB5C */  jal       strcmp
/* 5CF7BC 8021912C 8C440000 */   lw       $a0, ($v0)
/* 5CF7C0 80219130 14400003 */  bnez      $v0, .L80219140
/* 5CF7C4 80219134 26310001 */   addiu    $s1, $s1, 1
/* 5CF7C8 80219138 08086453 */  j         .L8021914C
/* 5CF7CC 8021913C 24120001 */   addiu    $s2, $zero, 1
.L80219140:
/* 5CF7D0 80219140 2E22000B */  sltiu     $v0, $s1, 0xb
/* 5CF7D4 80219144 1440FFEE */  bnez      $v0, .L80219100
/* 5CF7D8 80219148 26100004 */   addiu    $s0, $s0, 4
.L8021914C:
/* 5CF7DC 8021914C 44800000 */  mtc1      $zero, $f0
/* 5CF7E0 80219150 00000000 */  nop
/* 5CF7E4 80219154 44050000 */  mfc1      $a1, $f0
/* 5CF7E8 80219158 0240202D */  daddu     $a0, $s2, $zero
/* 5CF7EC 8021915C AFA00014 */  sw        $zero, 0x14($sp)
/* 5CF7F0 80219160 00A0302D */  daddu     $a2, $a1, $zero
/* 5CF7F4 80219164 00A0382D */  daddu     $a3, $a1, $zero
/* 5CF7F8 80219168 0C01CA54 */  jal       func_80072950
/* 5CF7FC 8021916C AFA50010 */   sw       $a1, 0x10($sp)
/* 5CF800 80219170 8FBF0028 */  lw        $ra, 0x28($sp)
/* 5CF804 80219174 8FB30024 */  lw        $s3, 0x24($sp)
/* 5CF808 80219178 8FB20020 */  lw        $s2, 0x20($sp)
/* 5CF80C 8021917C 8FB1001C */  lw        $s1, 0x1c($sp)
/* 5CF810 80219180 8FB00018 */  lw        $s0, 0x18($sp)
/* 5CF814 80219184 24020002 */  addiu     $v0, $zero, 2
/* 5CF818 80219188 03E00008 */  jr        $ra
/* 5CF81C 8021918C 27BD0030 */   addiu    $sp, $sp, 0x30
