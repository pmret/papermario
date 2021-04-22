.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004507C
/* 2047C 8004507C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 20480 80045080 AFB3001C */  sw        $s3, 0x1c($sp)
/* 20484 80045084 0080982D */  daddu     $s3, $a0, $zero
/* 20488 80045088 AFBF0024 */  sw        $ra, 0x24($sp)
/* 2048C 8004508C AFB40020 */  sw        $s4, 0x20($sp)
/* 20490 80045090 AFB20018 */  sw        $s2, 0x18($sp)
/* 20494 80045094 AFB10014 */  sw        $s1, 0x14($sp)
/* 20498 80045098 AFB00010 */  sw        $s0, 0x10($sp)
/* 2049C 8004509C 8E70000C */  lw        $s0, 0xc($s3)
/* 204A0 800450A0 8E720148 */  lw        $s2, 0x148($s3)
/* 204A4 800450A4 8E050000 */  lw        $a1, ($s0)
/* 204A8 800450A8 0C0B1EAF */  jal       func_802C7ABC
/* 204AC 800450AC 26100004 */   addiu    $s0, $s0, 4
/* 204B0 800450B0 0040882D */  daddu     $s1, $v0, $zero
/* 204B4 800450B4 8E050000 */  lw        $a1, ($s0)
/* 204B8 800450B8 26100004 */  addiu     $s0, $s0, 4
/* 204BC 800450BC 0C0B1EAF */  jal       func_802C7ABC
/* 204C0 800450C0 0260202D */   daddu    $a0, $s3, $zero
/* 204C4 800450C4 0040A02D */  daddu     $s4, $v0, $zero
/* 204C8 800450C8 2402FFFF */  addiu     $v0, $zero, -1
/* 204CC 800450CC 16220002 */  bne       $s1, $v0, .L800450D8
/* 204D0 800450D0 8E100000 */   lw       $s0, ($s0)
/* 204D4 800450D4 86510008 */  lh        $s1, 8($s2)
.L800450D8:
/* 204D8 800450D8 0C00FA6A */  jal       func_8003E9A8
/* 204DC 800450DC 0220202D */   daddu    $a0, $s1, $zero
/* 204E0 800450E0 0260202D */  daddu     $a0, $s3, $zero
/* 204E4 800450E4 00141880 */  sll       $v1, $s4, 2
/* 204E8 800450E8 00431021 */  addu      $v0, $v0, $v1
/* 204EC 800450EC 8C46006C */  lw        $a2, 0x6c($v0)
/* 204F0 800450F0 0C0B2026 */  jal       func_802C8098
/* 204F4 800450F4 0200282D */   daddu    $a1, $s0, $zero
/* 204F8 800450F8 8FBF0024 */  lw        $ra, 0x24($sp)
/* 204FC 800450FC 8FB40020 */  lw        $s4, 0x20($sp)
/* 20500 80045100 8FB3001C */  lw        $s3, 0x1c($sp)
/* 20504 80045104 8FB20018 */  lw        $s2, 0x18($sp)
/* 20508 80045108 8FB10014 */  lw        $s1, 0x14($sp)
/* 2050C 8004510C 8FB00010 */  lw        $s0, 0x10($sp)
/* 20510 80045110 24020002 */  addiu     $v0, $zero, 2
/* 20514 80045114 03E00008 */  jr        $ra
/* 20518 80045118 27BD0028 */   addiu    $sp, $sp, 0x28
