.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80219630_5CFCC0
/* 5CFCC0 80219630 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 5CFCC4 80219634 AFB20020 */  sw        $s2, 0x20($sp)
/* 5CFCC8 80219638 0000902D */  daddu     $s2, $zero, $zero
/* 5CFCCC 8021963C AFB1001C */  sw        $s1, 0x1c($sp)
/* 5CFCD0 80219640 0240882D */  daddu     $s1, $s2, $zero
/* 5CFCD4 80219644 AFB30024 */  sw        $s3, 0x24($sp)
/* 5CFCD8 80219648 3C138009 */  lui       $s3, %hi(gAreas)
/* 5CFCDC 8021964C 267334F0 */  addiu     $s3, $s3, %lo(gAreas)
/* 5CFCE0 80219650 AFB00018 */  sw        $s0, 0x18($sp)
/* 5CFCE4 80219654 3C108023 */  lui       $s0, %hi(D_802350D4_5EB764)
/* 5CFCE8 80219658 261050D4 */  addiu     $s0, $s0, %lo(D_802350D4_5EB764)
/* 5CFCEC 8021965C AFBF0028 */  sw        $ra, 0x28($sp)
.L80219660:
/* 5CFCF0 80219660 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 5CFCF4 80219664 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 5CFCF8 80219668 8E050000 */  lw        $a1, ($s0)
/* 5CFCFC 8021966C 84430086 */  lh        $v1, 0x86($v0)
/* 5CFD00 80219670 8442008C */  lh        $v0, 0x8c($v0)
/* 5CFD04 80219674 00031900 */  sll       $v1, $v1, 4
/* 5CFD08 80219678 00731821 */  addu      $v1, $v1, $s3
/* 5CFD0C 8021967C 8C630004 */  lw        $v1, 4($v1)
/* 5CFD10 80219680 00021140 */  sll       $v0, $v0, 5
/* 5CFD14 80219684 00431021 */  addu      $v0, $v0, $v1
/* 5CFD18 80219688 0C01BB5C */  jal       strcmp
/* 5CFD1C 8021968C 8C440000 */   lw       $a0, ($v0)
/* 5CFD20 80219690 14400003 */  bnez      $v0, .L802196A0
/* 5CFD24 80219694 26310001 */   addiu    $s1, $s1, 1
/* 5CFD28 80219698 080865AB */  j         .L802196AC
/* 5CFD2C 8021969C 24120001 */   addiu    $s2, $zero, 1
.L802196A0:
/* 5CFD30 802196A0 2E22000B */  sltiu     $v0, $s1, 0xb
/* 5CFD34 802196A4 1440FFEE */  bnez      $v0, .L80219660
/* 5CFD38 802196A8 26100004 */   addiu    $s0, $s0, 4
.L802196AC:
/* 5CFD3C 802196AC 44800000 */  mtc1      $zero, $f0
/* 5CFD40 802196B0 00000000 */  nop
/* 5CFD44 802196B4 44050000 */  mfc1      $a1, $f0
/* 5CFD48 802196B8 0240202D */  daddu     $a0, $s2, $zero
/* 5CFD4C 802196BC AFA00014 */  sw        $zero, 0x14($sp)
/* 5CFD50 802196C0 00A0302D */  daddu     $a2, $a1, $zero
/* 5CFD54 802196C4 00A0382D */  daddu     $a3, $a1, $zero
/* 5CFD58 802196C8 0C01CA54 */  jal       func_80072950
/* 5CFD5C 802196CC AFA50010 */   sw       $a1, 0x10($sp)
/* 5CFD60 802196D0 8FBF0028 */  lw        $ra, 0x28($sp)
/* 5CFD64 802196D4 8FB30024 */  lw        $s3, 0x24($sp)
/* 5CFD68 802196D8 8FB20020 */  lw        $s2, 0x20($sp)
/* 5CFD6C 802196DC 8FB1001C */  lw        $s1, 0x1c($sp)
/* 5CFD70 802196E0 8FB00018 */  lw        $s0, 0x18($sp)
/* 5CFD74 802196E4 24020002 */  addiu     $v0, $zero, 2
/* 5CFD78 802196E8 03E00008 */  jr        $ra
/* 5CFD7C 802196EC 27BD0030 */   addiu    $sp, $sp, 0x30
