.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel osSendMesg
/* 40C20 80065820 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 40C24 80065824 AFB00010 */  sw        $s0, 0x10($sp)
/* 40C28 80065828 00808021 */  addu      $s0, $a0, $zero
/* 40C2C 8006582C AFB50024 */  sw        $s5, 0x24($sp)
/* 40C30 80065830 00A0A821 */  addu      $s5, $a1, $zero
/* 40C34 80065834 AFB20018 */  sw        $s2, 0x18($sp)
/* 40C38 80065838 00C09021 */  addu      $s2, $a2, $zero
/* 40C3C 8006583C AFBF0028 */  sw        $ra, 0x28($sp)
/* 40C40 80065840 AFB40020 */  sw        $s4, 0x20($sp)
/* 40C44 80065844 AFB3001C */  sw        $s3, 0x1c($sp)
/* 40C48 80065848 0C01ACD8 */  jal       __osDisableInt
/* 40C4C 8006584C AFB10014 */   sw       $s1, 0x14($sp)
/* 40C50 80065850 8E030008 */  lw        $v1, 8($s0)
/* 40C54 80065854 8E040010 */  lw        $a0, 0x10($s0)
/* 40C58 80065858 0064182A */  slt       $v1, $v1, $a0
/* 40C5C 8006585C 14600012 */  bnez      $v1, .L800658A8
/* 40C60 80065860 00408821 */   addu     $s1, $v0, $zero
/* 40C64 80065864 24140001 */  addiu     $s4, $zero, 1
/* 40C68 80065868 24130008 */  addiu     $s3, $zero, 8
.L8006586C:
/* 40C6C 8006586C 12540005 */  beq       $s2, $s4, .L80065884
/* 40C70 80065870 26040004 */   addiu    $a0, $s0, 4
/* 40C74 80065874 0C01ACF4 */  jal       __osRestoreInt
/* 40C78 80065878 02202021 */   addu     $a0, $s1, $zero
/* 40C7C 8006587C 0801964B */  j         .L8006592C
/* 40C80 80065880 2402FFFF */   addiu    $v0, $zero, -1
.L80065884:
/* 40C84 80065884 3C028009 */  lui       $v0, %hi(__osRunningThread)
/* 40C88 80065888 8C424660 */  lw        $v0, %lo(__osRunningThread)($v0)
/* 40C8C 8006588C 0C01AC1B */  jal       osEnqueueAndYield
/* 40C90 80065890 A4530010 */   sh       $s3, 0x10($v0)
/* 40C94 80065894 8E020008 */  lw        $v0, 8($s0)
/* 40C98 80065898 8E030010 */  lw        $v1, 0x10($s0)
/* 40C9C 8006589C 0043102A */  slt       $v0, $v0, $v1
/* 40CA0 800658A0 1040FFF2 */  beqz      $v0, .L8006586C
/* 40CA4 800658A4 00000000 */   nop
.L800658A8:
/* 40CA8 800658A8 8E03000C */  lw        $v1, 0xc($s0)
/* 40CAC 800658AC 8E040008 */  lw        $a0, 8($s0)
/* 40CB0 800658B0 8E020010 */  lw        $v0, 0x10($s0)
/* 40CB4 800658B4 00641821 */  addu      $v1, $v1, $a0
/* 40CB8 800658B8 0062001A */  div       $zero, $v1, $v0
/* 40CBC 800658BC 14400002 */  bnez      $v0, .L800658C8
/* 40CC0 800658C0 00000000 */   nop
/* 40CC4 800658C4 0007000D */  break     7
.L800658C8:
/* 40CC8 800658C8 2401FFFF */   addiu    $at, $zero, -1
/* 40CCC 800658CC 14410004 */  bne       $v0, $at, .L800658E0
/* 40CD0 800658D0 3C018000 */   lui      $at, 0x8000
/* 40CD4 800658D4 14610002 */  bne       $v1, $at, .L800658E0
/* 40CD8 800658D8 00000000 */   nop
/* 40CDC 800658DC 0006000D */  break     6
.L800658E0:
/* 40CE0 800658E0 00001010 */   mfhi     $v0
/* 40CE4 800658E4 8E030014 */  lw        $v1, 0x14($s0)
/* 40CE8 800658E8 00021080 */  sll       $v0, $v0, 2
/* 40CEC 800658EC 00431021 */  addu      $v0, $v0, $v1
/* 40CF0 800658F0 AC550000 */  sw        $s5, ($v0)
/* 40CF4 800658F4 8E020008 */  lw        $v0, 8($s0)
/* 40CF8 800658F8 8E030000 */  lw        $v1, ($s0)
/* 40CFC 800658FC 24420001 */  addiu     $v0, $v0, 1
/* 40D00 80065900 AE020008 */  sw        $v0, 8($s0)
/* 40D04 80065904 8C620000 */  lw        $v0, ($v1)
/* 40D08 80065908 10400005 */  beqz      $v0, .L80065920
/* 40D0C 8006590C 00000000 */   nop
/* 40D10 80065910 0C01AC6F */  jal       osPopThread
/* 40D14 80065914 02002021 */   addu     $a0, $s0, $zero
/* 40D18 80065918 0C019808 */  jal       osStartThread
/* 40D1C 8006591C 00402021 */   addu     $a0, $v0, $zero
.L80065920:
/* 40D20 80065920 0C01ACF4 */  jal       __osRestoreInt
/* 40D24 80065924 02202021 */   addu     $a0, $s1, $zero
/* 40D28 80065928 00001021 */  addu      $v0, $zero, $zero
.L8006592C:
/* 40D2C 8006592C 8FBF0028 */  lw        $ra, 0x28($sp)
/* 40D30 80065930 8FB50024 */  lw        $s5, 0x24($sp)
/* 40D34 80065934 8FB40020 */  lw        $s4, 0x20($sp)
/* 40D38 80065938 8FB3001C */  lw        $s3, 0x1c($sp)
/* 40D3C 8006593C 8FB20018 */  lw        $s2, 0x18($sp)
/* 40D40 80065940 8FB10014 */  lw        $s1, 0x14($sp)
/* 40D44 80065944 8FB00010 */  lw        $s0, 0x10($sp)
/* 40D48 80065948 03E00008 */  jr        $ra
/* 40D4C 8006594C 27BD0030 */   addiu    $sp, $sp, 0x30
