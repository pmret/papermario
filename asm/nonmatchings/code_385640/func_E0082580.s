.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E0082580
/* 385BC0 E0082580 27BDFF50 */  addiu     $sp, $sp, -0xb0
/* 385BC4 E0082584 AFB00098 */  sw        $s0, 0x98($sp)
/* 385BC8 E0082588 0080802D */  daddu     $s0, $a0, $zero
/* 385BCC E008258C 27A40018 */  addiu     $a0, $sp, 0x18
/* 385BD0 E0082590 AFB200A0 */  sw        $s2, 0xa0($sp)
/* 385BD4 E0082594 3C120001 */  lui       $s2, 1
/* 385BD8 E0082598 AFBF00A4 */  sw        $ra, 0xa4($sp)
/* 385BDC E008259C AFB1009C */  sw        $s1, 0x9c($sp)
/* 385BE0 E00825A0 F7B400A8 */  sdc1      $f20, 0xa8($sp)
/* 385BE4 E00825A4 8E050008 */  lw        $a1, 8($s0)
/* 385BE8 E00825A8 8E06000C */  lw        $a2, 0xc($s0)
/* 385BEC E00825AC 8E070010 */  lw        $a3, 0x10($s0)
/* 385BF0 E00825B0 0C080108 */  jal       func_E0200420
/* 385BF4 E00825B4 36521630 */   ori      $s2, $s2, 0x1630
/* 385BF8 E00825B8 27B10058 */  addiu     $s1, $sp, 0x58
/* 385BFC E00825BC 0220202D */  daddu     $a0, $s1, $zero
/* 385C00 E00825C0 3C013F80 */  lui       $at, 0x3f80
/* 385C04 E00825C4 4481A000 */  mtc1      $at, $f20
/* 385C08 E00825C8 8E050034 */  lw        $a1, 0x34($s0)
/* 385C0C E00825CC 4407A000 */  mfc1      $a3, $f20
/* 385C10 E00825D0 0C080110 */  jal       func_E0200440
/* 385C14 E00825D4 00A0302D */   daddu    $a2, $a1, $zero
/* 385C18 E00825D8 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 385C1C E00825DC 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 385C20 E00825E0 44800000 */  mtc1      $zero, $f0
/* 385C24 E00825E4 00031080 */  sll       $v0, $v1, 2
/* 385C28 E00825E8 00431021 */  addu      $v0, $v0, $v1
/* 385C2C E00825EC 00021080 */  sll       $v0, $v0, 2
/* 385C30 E00825F0 00431023 */  subu      $v0, $v0, $v1
/* 385C34 E00825F4 000218C0 */  sll       $v1, $v0, 3
/* 385C38 E00825F8 00431021 */  addu      $v0, $v0, $v1
/* 385C3C E00825FC 000210C0 */  sll       $v0, $v0, 3
/* 385C40 E0082600 44060000 */  mfc1      $a2, $f0
/* 385C44 E0082604 3C01800B */  lui       $at, %hi(D_800B1DEC)
/* 385C48 E0082608 00220821 */  addu      $at, $at, $v0
/* 385C4C E008260C C4201DEC */  lwc1      $f0, %lo(D_800B1DEC)($at)
/* 385C50 E0082610 4407A000 */  mfc1      $a3, $f20
/* 385C54 E0082614 46000007 */  neg.s     $f0, $f0
/* 385C58 E0082618 44050000 */  mfc1      $a1, $f0
/* 385C5C E008261C 0220202D */  daddu     $a0, $s1, $zero
/* 385C60 E0082620 0C080104 */  jal       func_E0200410
/* 385C64 E0082624 AFA60010 */   sw       $a2, 0x10($sp)
/* 385C68 E0082628 0220202D */  daddu     $a0, $s1, $zero
/* 385C6C E008262C 27A50018 */  addiu     $a1, $sp, 0x18
/* 385C70 E0082630 0C080114 */  jal       func_E0200450
/* 385C74 E0082634 00A0302D */   daddu    $a2, $a1, $zero
/* 385C78 E0082638 27A40018 */  addiu     $a0, $sp, 0x18
/* 385C7C E008263C 3C108007 */  lui       $s0, %hi(gMatrixListPos)
/* 385C80 E0082640 261041F0 */  addiu     $s0, $s0, %lo(gMatrixListPos)
/* 385C84 E0082644 3C11800A */  lui       $s1, %hi(gDisplayContext)
/* 385C88 E0082648 2631A674 */  addiu     $s1, $s1, %lo(gDisplayContext)
/* 385C8C E008264C 96050000 */  lhu       $a1, ($s0)
/* 385C90 E0082650 8E220000 */  lw        $v0, ($s1)
/* 385C94 E0082654 00052980 */  sll       $a1, $a1, 6
/* 385C98 E0082658 00B22821 */  addu      $a1, $a1, $s2
/* 385C9C E008265C 0C080118 */  jal       func_E0200460
/* 385CA0 E0082660 00452821 */   addu     $a1, $v0, $a1
/* 385CA4 E0082664 3C03800A */  lui       $v1, %hi(gMasterGfxPos)
/* 385CA8 E0082668 2463A66C */  addiu     $v1, $v1, %lo(gMasterGfxPos)
/* 385CAC E008266C 8C620000 */  lw        $v0, ($v1)
/* 385CB0 E0082670 0040202D */  daddu     $a0, $v0, $zero
/* 385CB4 E0082674 24420008 */  addiu     $v0, $v0, 8
/* 385CB8 E0082678 AC620000 */  sw        $v0, ($v1)
/* 385CBC E008267C 96020000 */  lhu       $v0, ($s0)
/* 385CC0 E0082680 3C03DA38 */  lui       $v1, 0xda38
/* 385CC4 E0082684 AC830000 */  sw        $v1, ($a0)
/* 385CC8 E0082688 24430001 */  addiu     $v1, $v0, 1
/* 385CCC E008268C 3042FFFF */  andi      $v0, $v0, 0xffff
/* 385CD0 E0082690 00021180 */  sll       $v0, $v0, 6
/* 385CD4 E0082694 A6030000 */  sh        $v1, ($s0)
/* 385CD8 E0082698 8E230000 */  lw        $v1, ($s1)
/* 385CDC E008269C 00521021 */  addu      $v0, $v0, $s2
/* 385CE0 E00826A0 00621821 */  addu      $v1, $v1, $v0
/* 385CE4 E00826A4 AC830004 */  sw        $v1, 4($a0)
/* 385CE8 E00826A8 8FBF00A4 */  lw        $ra, 0xa4($sp)
/* 385CEC E00826AC 8FB200A0 */  lw        $s2, 0xa0($sp)
/* 385CF0 E00826B0 8FB1009C */  lw        $s1, 0x9c($sp)
/* 385CF4 E00826B4 8FB00098 */  lw        $s0, 0x98($sp)
/* 385CF8 E00826B8 D7B400A8 */  ldc1      $f20, 0xa8($sp)
/* 385CFC E00826BC 03E00008 */  jr        $ra
/* 385D00 E00826C0 27BD00B0 */   addiu    $sp, $sp, 0xb0
