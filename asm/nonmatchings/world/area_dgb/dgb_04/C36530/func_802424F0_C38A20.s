.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802424F0_C38A20
/* C38A20 802424F0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* C38A24 802424F4 AFB3001C */  sw        $s3, 0x1c($sp)
/* C38A28 802424F8 0080982D */  daddu     $s3, $a0, $zero
/* C38A2C 802424FC AFB00010 */  sw        $s0, 0x10($sp)
/* C38A30 80242500 24100001 */  addiu     $s0, $zero, 1
/* C38A34 80242504 AFB40020 */  sw        $s4, 0x20($sp)
/* C38A38 80242508 2414FFFF */  addiu     $s4, $zero, -1
/* C38A3C 8024250C AFB50024 */  sw        $s5, 0x24($sp)
/* C38A40 80242510 0200A82D */  daddu     $s5, $s0, $zero
/* C38A44 80242514 AFB10014 */  sw        $s1, 0x14($sp)
/* C38A48 80242518 3C118011 */  lui       $s1, 0x8011
/* C38A4C 8024251C 2631F298 */  addiu     $s1, $s1, -0xd68
/* C38A50 80242520 AFBF0028 */  sw        $ra, 0x28($sp)
/* C38A54 80242524 AFB20018 */  sw        $s2, 0x18($sp)
/* C38A58 80242528 8E6200B4 */  lw        $v0, 0xb4($s3)
/* C38A5C 8024252C 0280182D */  daddu     $v1, $s4, $zero
/* C38A60 80242530 AE630084 */  sw        $v1, 0x84($s3)
/* C38A64 80242534 00021027 */  nor       $v0, $zero, $v0
/* C38A68 80242538 000217C2 */  srl       $v0, $v0, 0x1f
/* C38A6C 8024253C 00029400 */  sll       $s2, $v0, 0x10
.L80242540:
/* C38A70 80242540 92220014 */  lbu       $v0, 0x14($s1)
/* C38A74 80242544 50400008 */  beql      $v0, $zero, .L80242568
/* C38A78 80242548 26100001 */   addiu    $s0, $s0, 1
/* C38A7C 8024254C 0200202D */  daddu     $a0, $s0, $zero
/* C38A80 80242550 0C090929 */  jal       func_802424A4
/* C38A84 80242554 00122C03 */   sra      $a1, $s2, 0x10
/* C38A88 80242558 10540003 */  beq       $v0, $s4, .L80242568
/* C38A8C 8024255C 26100001 */   addiu    $s0, $s0, 1
/* C38A90 80242560 0809095D */  j         .L80242574
/* C38A94 80242564 AE750084 */   sw       $s5, 0x84($s3)
.L80242568:
/* C38A98 80242568 2A02000C */  slti      $v0, $s0, 0xc
/* C38A9C 8024256C 1440FFF4 */  bnez      $v0, .L80242540
/* C38AA0 80242570 26310008 */   addiu    $s1, $s1, 8
.L80242574:
/* C38AA4 80242574 8FBF0028 */  lw        $ra, 0x28($sp)
/* C38AA8 80242578 8FB50024 */  lw        $s5, 0x24($sp)
/* C38AAC 8024257C 8FB40020 */  lw        $s4, 0x20($sp)
/* C38AB0 80242580 8FB3001C */  lw        $s3, 0x1c($sp)
/* C38AB4 80242584 8FB20018 */  lw        $s2, 0x18($sp)
/* C38AB8 80242588 8FB10014 */  lw        $s1, 0x14($sp)
/* C38ABC 8024258C 8FB00010 */  lw        $s0, 0x10($sp)
/* C38AC0 80242590 24020002 */  addiu     $v0, $zero, 2
/* C38AC4 80242594 03E00008 */  jr        $ra
/* C38AC8 80242598 27BD0030 */   addiu    $sp, $sp, 0x30
