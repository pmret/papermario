.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel check_input_midair_jump
/* 07E47C 800E4FCC 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 07E480 800E4FD0 3C030080 */  lui   $v1, 0x80
/* 07E484 800E4FD4 AFB00010 */  sw    $s0, 0x10($sp)
/* 07E488 800E4FD8 3C108011 */  lui   $s0, 0x8011
/* 07E48C 800E4FDC 2610EFC8 */  addiu $s0, $s0, -0x1038
/* 07E490 800E4FE0 AFBF0014 */  sw    $ra, 0x14($sp)
/* 07E494 800E4FE4 8E020000 */  lw    $v0, ($s0)
/* 07E498 800E4FE8 34630018 */  ori   $v1, $v1, 0x18
/* 07E49C 800E4FEC 00431024 */  and   $v0, $v0, $v1
/* 07E4A0 800E4FF0 14400021 */  bnez  $v0, .L800E5078
/* 07E4A4 800E4FF4 00000000 */   nop   
/* 07E4A8 800E4FF8 8E020004 */  lw    $v0, 4($s0)
/* 07E4AC 800E4FFC 30424001 */  andi  $v0, $v0, 0x4001
/* 07E4B0 800E5000 1440001D */  bnez  $v0, .L800E5078
/* 07E4B4 800E5004 00000000 */   nop   
/* 07E4B8 800E5008 860200C2 */  lh    $v0, 0xc2($s0)
/* 07E4BC 800E500C 28420006 */  slti  $v0, $v0, 6
/* 07E4C0 800E5010 14400019 */  bnez  $v0, .L800E5078
/* 07E4C4 800E5014 00000000 */   nop   
/* 07E4C8 800E5018 860200C0 */  lh    $v0, 0xc0($s0)
/* 07E4CC 800E501C 28420012 */  slti  $v0, $v0, 0x12
/* 07E4D0 800E5020 10400015 */  beqz  $v0, .L800E5078
/* 07E4D4 800E5024 00000000 */   nop   
/* 07E4D8 800E5028 8E0200E0 */  lw    $v0, 0xe0($s0)
/* 07E4DC 800E502C 30428000 */  andi  $v0, $v0, 0x8000
/* 07E4E0 800E5030 10400011 */  beqz  $v0, .L800E5078
/* 07E4E4 800E5034 24020001 */   addiu $v0, $zero, 1
/* 07E4E8 800E5038 3C038011 */  lui   $v1, 0x8011
/* 07E4EC 800E503C 8063F290 */  lb    $v1, -0xd70($v1)
/* 07E4F0 800E5040 10620007 */  beq   $v1, $v0, .L800E5060
/* 07E4F4 800E5044 28620002 */   slti  $v0, $v1, 2
/* 07E4F8 800E5048 1440000B */  bnez  $v0, .L800E5078
/* 07E4FC 800E504C 24020002 */   addiu $v0, $zero, 2
/* 07E500 800E5050 10620004 */  beq   $v1, $v0, .L800E5064
/* 07E504 800E5054 2404000F */   addiu $a0, $zero, 0xf
/* 07E508 800E5058 0803941E */  j     .L800E5078
/* 07E50C 800E505C 00000000 */   nop   

.L800E5060:
/* 07E510 800E5060 2404000D */  addiu $a0, $zero, 0xd
.L800E5064:
/* 07E514 800E5064 0C039769 */  jal   set_action_state
/* 07E518 800E5068 00000000 */   nop   
/* 07E51C 800E506C 8E020000 */  lw    $v0, ($s0)
/* 07E520 800E5070 34420008 */  ori   $v0, $v0, 8
/* 07E524 800E5074 AE020000 */  sw    $v0, ($s0)
.L800E5078:
/* 07E528 800E5078 8FBF0014 */  lw    $ra, 0x14($sp)
/* 07E52C 800E507C 8FB00010 */  lw    $s0, 0x10($sp)
/* 07E530 800E5080 03E00008 */  jr    $ra
/* 07E534 800E5084 27BD0018 */   addiu $sp, $sp, 0x18

