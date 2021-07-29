.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel osRecvMesg
/* 40AF0 800656F0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 40AF4 800656F4 AFB00010 */  sw        $s0, 0x10($sp)
/* 40AF8 800656F8 00808021 */  addu      $s0, $a0, $zero
/* 40AFC 800656FC AFB40020 */  sw        $s4, 0x20($sp)
/* 40B00 80065700 00A0A021 */  addu      $s4, $a1, $zero
/* 40B04 80065704 AFB10014 */  sw        $s1, 0x14($sp)
/* 40B08 80065708 00C08821 */  addu      $s1, $a2, $zero
/* 40B0C 8006570C AFBF0024 */  sw        $ra, 0x24($sp)
/* 40B10 80065710 AFB3001C */  sw        $s3, 0x1c($sp)
/* 40B14 80065714 0C01ACD8 */  jal       osDisableInt
/* 40B18 80065718 AFB20018 */   sw       $s2, 0x18($sp)
/* 40B1C 8006571C 8E030008 */  lw        $v1, 8($s0)
/* 40B20 80065720 1460000F */  bnez      $v1, .L80065760
/* 40B24 80065724 00409021 */   addu     $s2, $v0, $zero
/* 40B28 80065728 24130008 */  addiu     $s3, $zero, 8
.L8006572C:
/* 40B2C 8006572C 16200005 */  bnez      $s1, .L80065744
/* 40B30 80065730 02002021 */   addu     $a0, $s0, $zero
/* 40B34 80065734 0C01ACF4 */  jal       osRestoreInt
/* 40B38 80065738 02402021 */   addu     $a0, $s2, $zero
/* 40B3C 8006573C 080195FD */  j         .L800657F4
/* 40B40 80065740 2402FFFF */   addiu    $v0, $zero, -1
.L80065744:
/* 40B44 80065744 3C028009 */  lui       $v0, %hi(__osRunningThread)
/* 40B48 80065748 8C424660 */  lw        $v0, %lo(__osRunningThread)($v0)
/* 40B4C 8006574C 0C01AC1B */  jal       osEnqueueAndYield
/* 40B50 80065750 A4530010 */   sh       $s3, 0x10($v0)
/* 40B54 80065754 8E020008 */  lw        $v0, 8($s0)
/* 40B58 80065758 1040FFF4 */  beqz      $v0, .L8006572C
/* 40B5C 8006575C 00000000 */   nop
.L80065760:
/* 40B60 80065760 12800007 */  beqz      $s4, .L80065780
/* 40B64 80065764 00000000 */   nop
/* 40B68 80065768 8E02000C */  lw        $v0, 0xc($s0)
/* 40B6C 8006576C 8E030014 */  lw        $v1, 0x14($s0)
/* 40B70 80065770 00021080 */  sll       $v0, $v0, 2
/* 40B74 80065774 00431021 */  addu      $v0, $v0, $v1
/* 40B78 80065778 8C420000 */  lw        $v0, ($v0)
/* 40B7C 8006577C AE820000 */  sw        $v0, ($s4)
.L80065780:
/* 40B80 80065780 8E02000C */  lw        $v0, 0xc($s0)
/* 40B84 80065784 8E030010 */  lw        $v1, 0x10($s0)
/* 40B88 80065788 24420001 */  addiu     $v0, $v0, 1
/* 40B8C 8006578C 0043001A */  div       $zero, $v0, $v1
/* 40B90 80065790 14600002 */  bnez      $v1, .L8006579C
/* 40B94 80065794 00000000 */   nop
/* 40B98 80065798 0007000D */  break     7
.L8006579C:
/* 40B9C 8006579C 2401FFFF */   addiu    $at, $zero, -1
/* 40BA0 800657A0 14610004 */  bne       $v1, $at, .L800657B4
/* 40BA4 800657A4 3C018000 */   lui      $at, 0x8000
/* 40BA8 800657A8 14410002 */  bne       $v0, $at, .L800657B4
/* 40BAC 800657AC 00000000 */   nop
/* 40BB0 800657B0 0006000D */  break     6
.L800657B4:
/* 40BB4 800657B4 00002010 */   mfhi     $a0
/* 40BB8 800657B8 8E020008 */  lw        $v0, 8($s0)
/* 40BBC 800657BC 8E030004 */  lw        $v1, 4($s0)
/* 40BC0 800657C0 2442FFFF */  addiu     $v0, $v0, -1
/* 40BC4 800657C4 AE020008 */  sw        $v0, 8($s0)
/* 40BC8 800657C8 AE04000C */  sw        $a0, 0xc($s0)
/* 40BCC 800657CC 8C620000 */  lw        $v0, ($v1)
/* 40BD0 800657D0 10400005 */  beqz      $v0, .L800657E8
/* 40BD4 800657D4 00000000 */   nop
/* 40BD8 800657D8 0C01AC6F */  jal       osPopThread
/* 40BDC 800657DC 26040004 */   addiu    $a0, $s0, 4
/* 40BE0 800657E0 0C019808 */  jal       osStartThread
/* 40BE4 800657E4 00402021 */   addu     $a0, $v0, $zero
.L800657E8:
/* 40BE8 800657E8 0C01ACF4 */  jal       osRestoreInt
/* 40BEC 800657EC 02402021 */   addu     $a0, $s2, $zero
/* 40BF0 800657F0 00001021 */  addu      $v0, $zero, $zero
.L800657F4:
/* 40BF4 800657F4 8FBF0024 */  lw        $ra, 0x24($sp)
/* 40BF8 800657F8 8FB40020 */  lw        $s4, 0x20($sp)
/* 40BFC 800657FC 8FB3001C */  lw        $s3, 0x1c($sp)
/* 40C00 80065800 8FB20018 */  lw        $s2, 0x18($sp)
/* 40C04 80065804 8FB10014 */  lw        $s1, 0x14($sp)
/* 40C08 80065808 8FB00010 */  lw        $s0, 0x10($sp)
/* 40C0C 8006580C 03E00008 */  jr        $ra
/* 40C10 80065810 27BD0028 */   addiu    $sp, $sp, 0x28
/* 40C14 80065814 00000000 */  nop
/* 40C18 80065818 00000000 */  nop
/* 40C1C 8006581C 00000000 */  nop
