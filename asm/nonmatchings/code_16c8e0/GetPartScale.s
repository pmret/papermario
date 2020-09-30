.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel GetPartScale
/* 19B514 8026CC34 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 19B518 8026CC38 AFB40020 */  sw        $s4, 0x20($sp)
/* 19B51C 8026CC3C 0080A02D */  daddu     $s4, $a0, $zero
/* 19B520 8026CC40 AFBF0028 */  sw        $ra, 0x28($sp)
/* 19B524 8026CC44 AFB50024 */  sw        $s5, 0x24($sp)
/* 19B528 8026CC48 AFB3001C */  sw        $s3, 0x1c($sp)
/* 19B52C 8026CC4C AFB20018 */  sw        $s2, 0x18($sp)
/* 19B530 8026CC50 AFB10014 */  sw        $s1, 0x14($sp)
/* 19B534 8026CC54 AFB00010 */  sw        $s0, 0x10($sp)
/* 19B538 8026CC58 8E90000C */  lw        $s0, 0xc($s4)
/* 19B53C 8026CC5C 8E050000 */  lw        $a1, ($s0)
/* 19B540 8026CC60 0C0B1EAF */  jal       get_variable
/* 19B544 8026CC64 26100004 */   addiu    $s0, $s0, 4
/* 19B548 8026CC68 0040902D */  daddu     $s2, $v0, $zero
/* 19B54C 8026CC6C 8E050000 */  lw        $a1, ($s0)
/* 19B550 8026CC70 26100004 */  addiu     $s0, $s0, 4
/* 19B554 8026CC74 0C0B1EAF */  jal       get_variable
/* 19B558 8026CC78 0280202D */   daddu    $a0, $s4, $zero
/* 19B55C 8026CC7C 0040A82D */  daddu     $s5, $v0, $zero
/* 19B560 8026CC80 2402FF81 */  addiu     $v0, $zero, -0x7f
/* 19B564 8026CC84 16420002 */  bne       $s2, $v0, .L8026CC90
/* 19B568 8026CC88 00000000 */   nop      
/* 19B56C 8026CC8C 8E920148 */  lw        $s2, 0x148($s4)
.L8026CC90:
/* 19B570 8026CC90 8E110000 */  lw        $s1, ($s0)
/* 19B574 8026CC94 26100004 */  addiu     $s0, $s0, 4
/* 19B578 8026CC98 0240202D */  daddu     $a0, $s2, $zero
/* 19B57C 8026CC9C 8E120000 */  lw        $s2, ($s0)
/* 19B580 8026CCA0 0C09A75B */  jal       get_actor
/* 19B584 8026CCA4 8E130004 */   lw       $s3, 4($s0)
/* 19B588 8026CCA8 0040202D */  daddu     $a0, $v0, $zero
/* 19B58C 8026CCAC 0C099117 */  jal       get_actor_part
/* 19B590 8026CCB0 02A0282D */   daddu    $a1, $s5, $zero
/* 19B594 8026CCB4 0280202D */  daddu     $a0, $s4, $zero
/* 19B598 8026CCB8 0040802D */  daddu     $s0, $v0, $zero
/* 19B59C 8026CCBC 8E06004C */  lw        $a2, 0x4c($s0)
/* 19B5A0 8026CCC0 0C0B2190 */  jal       set_float_variable
/* 19B5A4 8026CCC4 0220282D */   daddu    $a1, $s1, $zero
/* 19B5A8 8026CCC8 0280202D */  daddu     $a0, $s4, $zero
/* 19B5AC 8026CCCC 8E060050 */  lw        $a2, 0x50($s0)
/* 19B5B0 8026CCD0 0C0B2190 */  jal       set_float_variable
/* 19B5B4 8026CCD4 0240282D */   daddu    $a1, $s2, $zero
/* 19B5B8 8026CCD8 0280202D */  daddu     $a0, $s4, $zero
/* 19B5BC 8026CCDC 8E060054 */  lw        $a2, 0x54($s0)
/* 19B5C0 8026CCE0 0C0B2190 */  jal       set_float_variable
/* 19B5C4 8026CCE4 0260282D */   daddu    $a1, $s3, $zero
/* 19B5C8 8026CCE8 8FBF0028 */  lw        $ra, 0x28($sp)
/* 19B5CC 8026CCEC 8FB50024 */  lw        $s5, 0x24($sp)
/* 19B5D0 8026CCF0 8FB40020 */  lw        $s4, 0x20($sp)
/* 19B5D4 8026CCF4 8FB3001C */  lw        $s3, 0x1c($sp)
/* 19B5D8 8026CCF8 8FB20018 */  lw        $s2, 0x18($sp)
/* 19B5DC 8026CCFC 8FB10014 */  lw        $s1, 0x14($sp)
/* 19B5E0 8026CD00 8FB00010 */  lw        $s0, 0x10($sp)
/* 19B5E4 8026CD04 24020002 */  addiu     $v0, $zero, 2
/* 19B5E8 8026CD08 03E00008 */  jr        $ra
/* 19B5EC 8026CD0C 27BD0030 */   addiu    $sp, $sp, 0x30
