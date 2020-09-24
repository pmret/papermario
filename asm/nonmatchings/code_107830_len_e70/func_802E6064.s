.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802E6064
/* 1078E4 802E6064 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 1078E8 802E6068 AFB00018 */  sw        $s0, 0x18($sp)
/* 1078EC 802E606C 0080802D */  daddu     $s0, $a0, $zero
/* 1078F0 802E6070 3C058011 */  lui       $a1, 0x8011
/* 1078F4 802E6074 24A5EFC8 */  addiu     $a1, $a1, -0x1038
/* 1078F8 802E6078 AFB1001C */  sw        $s1, 0x1c($sp)
/* 1078FC 802E607C 24030021 */  addiu     $v1, $zero, 0x21
/* 107900 802E6080 AFBF0020 */  sw        $ra, 0x20($sp)
/* 107904 802E6084 80A200B4 */  lb        $v0, 0xb4($a1)
/* 107908 802E6088 8E040040 */  lw        $a0, 0x40($s0)
/* 10790C 802E608C 1043001D */  beq       $v0, $v1, .L802E6104
/* 107910 802E6090 00A0882D */   daddu    $s1, $a1, $zero
/* 107914 802E6094 92020006 */  lbu       $v0, 6($s0)
/* 107918 802E6098 30420001 */  andi      $v0, $v0, 1
/* 10791C 802E609C 10400019 */  beqz      $v0, .L802E6104
/* 107920 802E60A0 00000000 */   nop      
/* 107924 802E60A4 8C820000 */  lw        $v0, ($a0)
/* 107928 802E60A8 28420046 */  slti      $v0, $v0, 0x46
/* 10792C 802E60AC 14400002 */  bnez      $v0, .L802E60B8
/* 107930 802E60B0 24020005 */   addiu    $v0, $zero, 5
/* 107934 802E60B4 A0A200C5 */  sb        $v0, 0xc5($a1)
.L802E60B8:
/* 107938 802E60B8 86040014 */  lh        $a0, 0x14($s0)
/* 10793C 802E60BC 3C050000 */  lui       $a1, 0
/* 107940 802E60C0 24A501E4 */  addiu     $a1, $a1, 0x1e4
/* 107944 802E60C4 0C048052 */  jal       play_model_animation
/* 107948 802E60C8 00000000 */   nop      
/* 10794C 802E60CC 0C04419E */  jal       func_80110678
/* 107950 802E60D0 0200202D */   daddu    $a0, $s0, $zero
/* 107954 802E60D4 0C043F5A */  jal       func_8010FD68
/* 107958 802E60D8 0200202D */   daddu    $a0, $s0, $zero
/* 10795C 802E60DC C6000050 */  lwc1      $f0, 0x50($s0)
/* 107960 802E60E0 24042086 */  addiu     $a0, $zero, 0x2086
/* 107964 802E60E4 E7A00010 */  swc1      $f0, 0x10($sp)
/* 107968 802E60E8 8E060048 */  lw        $a2, 0x48($s0)
/* 10796C 802E60EC 8E07004C */  lw        $a3, 0x4c($s0)
/* 107970 802E60F0 0C052757 */  jal       play_sound_at_position
/* 107974 802E60F4 0000282D */   daddu    $a1, $zero, $zero
/* 107978 802E60F8 0C03805E */  jal       disable_player_input
/* 10797C 802E60FC 00000000 */   nop      
/* 107980 802E6100 AE200054 */  sw        $zero, 0x54($s1)
.L802E6104:
/* 107984 802E6104 8FBF0020 */  lw        $ra, 0x20($sp)
/* 107988 802E6108 8FB1001C */  lw        $s1, 0x1c($sp)
/* 10798C 802E610C 8FB00018 */  lw        $s0, 0x18($sp)
/* 107990 802E6110 03E00008 */  jr        $ra
/* 107994 802E6114 27BD0028 */   addiu    $sp, $sp, 0x28
