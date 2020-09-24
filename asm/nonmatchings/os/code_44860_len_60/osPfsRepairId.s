.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel osPfsRepairId
/* 44860 80069460 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 44864 80069464 AFB00010 */  sw        $s0, 0x10($sp)
/* 44868 80069468 00808021 */  addu      $s0, $a0, $zero
/* 4486C 8006946C AFBF0014 */  sw        $ra, 0x14($sp)
/* 44870 80069470 8E020000 */  lw        $v0, ($s0)
/* 44874 80069474 30420005 */  andi      $v0, $v0, 5
/* 44878 80069478 5040000A */  beql      $v0, $zero, .L800694A4
/* 4487C 8006947C 24040005 */   addiu    $a0, $zero, 5
/* 44880 80069480 0C01A702 */  jal       osGetId
/* 44884 80069484 00000000 */   nop      
/* 44888 80069488 00402021 */  addu      $a0, $v0, $zero
/* 4488C 8006948C 14800006 */  bnez      $a0, .L800694A8
/* 44890 80069490 00801021 */   addu     $v0, $a0, $zero
/* 44894 80069494 8E020000 */  lw        $v0, ($s0)
/* 44898 80069498 2403FFFB */  addiu     $v1, $zero, -5
/* 4489C 8006949C 00431024 */  and       $v0, $v0, $v1
/* 448A0 800694A0 AE020000 */  sw        $v0, ($s0)
.L800694A4:
/* 448A4 800694A4 00801021 */  addu      $v0, $a0, $zero
.L800694A8:
/* 448A8 800694A8 8FBF0014 */  lw        $ra, 0x14($sp)
/* 448AC 800694AC 8FB00010 */  lw        $s0, 0x10($sp)
/* 448B0 800694B0 03E00008 */  jr        $ra
/* 448B4 800694B4 27BD0018 */   addiu    $sp, $sp, 0x18
/* 448B8 800694B8 00000000 */  nop       
/* 448BC 800694BC 00000000 */  nop       
