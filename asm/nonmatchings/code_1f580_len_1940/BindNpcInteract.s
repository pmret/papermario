.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel BindNpcInteract
/* 204A4 800450A4 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 204A8 800450A8 AFB10014 */  sw        $s1, 0x14($sp)
/* 204AC 800450AC 0080882D */  daddu     $s1, $a0, $zero
/* 204B0 800450B0 AFBF0020 */  sw        $ra, 0x20($sp)
/* 204B4 800450B4 AFB3001C */  sw        $s3, 0x1c($sp)
/* 204B8 800450B8 AFB20018 */  sw        $s2, 0x18($sp)
/* 204BC 800450BC AFB00010 */  sw        $s0, 0x10($sp)
/* 204C0 800450C0 8E30000C */  lw        $s0, 0xc($s1)
/* 204C4 800450C4 8E330148 */  lw        $s3, 0x148($s1)
/* 204C8 800450C8 8E050000 */  lw        $a1, ($s0)
/* 204CC 800450CC 0C0B1EAF */  jal       get_variable
/* 204D0 800450D0 26100004 */   addiu    $s0, $s0, 4
/* 204D4 800450D4 0040902D */  daddu     $s2, $v0, $zero
/* 204D8 800450D8 8E050000 */  lw        $a1, ($s0)
/* 204DC 800450DC 0C0B1EAF */  jal       get_variable
/* 204E0 800450E0 0220202D */   daddu    $a0, $s1, $zero
/* 204E4 800450E4 0040802D */  daddu     $s0, $v0, $zero
/* 204E8 800450E8 2402FFFF */  addiu     $v0, $zero, -1
/* 204EC 800450EC 16420002 */  bne       $s2, $v0, .L800450F8
/* 204F0 800450F0 00000000 */   nop      
/* 204F4 800450F4 86720008 */  lh        $s2, 8($s3)
.L800450F8:
/* 204F8 800450F8 0C00FB3A */  jal       get_enemy
/* 204FC 800450FC 0240202D */   daddu    $a0, $s2, $zero
/* 20500 80045100 0040982D */  daddu     $s3, $v0, $zero
/* 20504 80045104 8E620038 */  lw        $v0, 0x38($s3)
/* 20508 80045108 50400005 */  beql      $v0, $zero, .L80045120
/* 2050C 8004510C AE700020 */   sw       $s0, 0x20($s3)
/* 20510 80045110 8E640050 */  lw        $a0, 0x50($s3)
/* 20514 80045114 0C0B102B */  jal       kill_script_by_ID
/* 20518 80045118 00000000 */   nop      
/* 2051C 8004511C AE700020 */  sw        $s0, 0x20($s3)
.L80045120:
/* 20520 80045120 8FBF0020 */  lw        $ra, 0x20($sp)
/* 20524 80045124 8FB3001C */  lw        $s3, 0x1c($sp)
/* 20528 80045128 8FB20018 */  lw        $s2, 0x18($sp)
/* 2052C 8004512C 8FB10014 */  lw        $s1, 0x14($sp)
/* 20530 80045130 8FB00010 */  lw        $s0, 0x10($sp)
/* 20534 80045134 24020002 */  addiu     $v0, $zero, 2
/* 20538 80045138 03E00008 */  jr        $ra
/* 2053C 8004513C 27BD0028 */   addiu    $sp, $sp, 0x28
