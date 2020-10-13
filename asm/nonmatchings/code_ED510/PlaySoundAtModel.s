.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel PlaySoundAtModel
/* EEF08 802CA558 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* EEF0C 802CA55C AFB1003C */  sw        $s1, 0x3c($sp)
/* EEF10 802CA560 0080882D */  daddu     $s1, $a0, $zero
/* EEF14 802CA564 AFBF0044 */  sw        $ra, 0x44($sp)
/* EEF18 802CA568 AFB20040 */  sw        $s2, 0x40($sp)
/* EEF1C 802CA56C AFB00038 */  sw        $s0, 0x38($sp)
/* EEF20 802CA570 8E30000C */  lw        $s0, 0xc($s1)
/* EEF24 802CA574 8E050000 */  lw        $a1, ($s0)
/* EEF28 802CA578 0C0B1EAF */  jal       get_variable
/* EEF2C 802CA57C 26100004 */   addiu    $s0, $s0, 4
/* EEF30 802CA580 8E050000 */  lw        $a1, ($s0)
/* EEF34 802CA584 26100004 */  addiu     $s0, $s0, 4
/* EEF38 802CA588 0220202D */  daddu     $a0, $s1, $zero
/* EEF3C 802CA58C 0C0B1EAF */  jal       get_variable
/* EEF40 802CA590 0040902D */   daddu    $s2, $v0, $zero
/* EEF44 802CA594 0220202D */  daddu     $a0, $s1, $zero
/* EEF48 802CA598 8E050000 */  lw        $a1, ($s0)
/* EEF4C 802CA59C 0C0B1EAF */  jal       get_variable
/* EEF50 802CA5A0 0040882D */   daddu    $s1, $v0, $zero
/* EEF54 802CA5A4 3244FFFF */  andi      $a0, $s2, 0xffff
/* EEF58 802CA5A8 27A50020 */  addiu     $a1, $sp, 0x20
/* EEF5C 802CA5AC 27A60024 */  addiu     $a2, $sp, 0x24
/* EEF60 802CA5B0 27A70028 */  addiu     $a3, $sp, 0x28
/* EEF64 802CA5B4 27A3002C */  addiu     $v1, $sp, 0x2c
/* EEF68 802CA5B8 AFA30010 */  sw        $v1, 0x10($sp)
/* EEF6C 802CA5BC 27A30030 */  addiu     $v1, $sp, 0x30
/* EEF70 802CA5C0 AFA30014 */  sw        $v1, 0x14($sp)
/* EEF74 802CA5C4 27A30034 */  addiu     $v1, $sp, 0x34
/* EEF78 802CA5C8 0040802D */  daddu     $s0, $v0, $zero
/* EEF7C 802CA5CC 0C046C3B */  jal       get_model_center_and_size
/* EEF80 802CA5D0 AFA30018 */   sw       $v1, 0x18($sp)
/* EEF84 802CA5D4 0220202D */  daddu     $a0, $s1, $zero
/* EEF88 802CA5D8 C7A00020 */  lwc1      $f0, 0x20($sp)
/* EEF8C 802CA5DC C7A20024 */  lwc1      $f2, 0x24($sp)
/* EEF90 802CA5E0 44060000 */  mfc1      $a2, $f0
/* EEF94 802CA5E4 44071000 */  mfc1      $a3, $f2
/* EEF98 802CA5E8 C7A00028 */  lwc1      $f0, 0x28($sp)
/* EEF9C 802CA5EC 0200282D */  daddu     $a1, $s0, $zero
/* EEFA0 802CA5F0 0C052757 */  jal       play_sound_at_position
/* EEFA4 802CA5F4 E7A00010 */   swc1     $f0, 0x10($sp)
/* EEFA8 802CA5F8 8FBF0044 */  lw        $ra, 0x44($sp)
/* EEFAC 802CA5FC 8FB20040 */  lw        $s2, 0x40($sp)
/* EEFB0 802CA600 8FB1003C */  lw        $s1, 0x3c($sp)
/* EEFB4 802CA604 8FB00038 */  lw        $s0, 0x38($sp)
/* EEFB8 802CA608 24020002 */  addiu     $v0, $zero, 2
/* EEFBC 802CA60C 03E00008 */  jr        $ra
/* EEFC0 802CA610 27BD0048 */   addiu    $sp, $sp, 0x48
