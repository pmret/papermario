.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel jan_08_UnkFunc38
/* B5EA30 80240780 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* B5EA34 80240784 AFB3001C */  sw        $s3, 0x1c($sp)
/* B5EA38 80240788 0080982D */  daddu     $s3, $a0, $zero
/* B5EA3C 8024078C AFB00010 */  sw        $s0, 0x10($sp)
/* B5EA40 80240790 24100001 */  addiu     $s0, $zero, 1
/* B5EA44 80240794 AFB40020 */  sw        $s4, 0x20($sp)
/* B5EA48 80240798 2414FFFF */  addiu     $s4, $zero, -1
/* B5EA4C 8024079C AFB50024 */  sw        $s5, 0x24($sp)
/* B5EA50 802407A0 0200A82D */  daddu     $s5, $s0, $zero
/* B5EA54 802407A4 AFB10014 */  sw        $s1, 0x14($sp)
/* B5EA58 802407A8 3C118011 */  lui       $s1, %hi(gPlayerData+0x8)
/* B5EA5C 802407AC 2631F298 */  addiu     $s1, $s1, %lo(gPlayerData+0x8)
/* B5EA60 802407B0 AFBF0028 */  sw        $ra, 0x28($sp)
/* B5EA64 802407B4 AFB20018 */  sw        $s2, 0x18($sp)
/* B5EA68 802407B8 8E6200B4 */  lw        $v0, 0xb4($s3)
/* B5EA6C 802407BC 0280182D */  daddu     $v1, $s4, $zero
/* B5EA70 802407C0 AE630084 */  sw        $v1, 0x84($s3)
/* B5EA74 802407C4 00021027 */  nor       $v0, $zero, $v0
/* B5EA78 802407C8 000217C2 */  srl       $v0, $v0, 0x1f
/* B5EA7C 802407CC 00029400 */  sll       $s2, $v0, 0x10
.L802407D0:
/* B5EA80 802407D0 92220014 */  lbu       $v0, 0x14($s1)
/* B5EA84 802407D4 50400008 */  beql      $v0, $zero, .L802407F8
/* B5EA88 802407D8 26100001 */   addiu    $s0, $s0, 1
/* B5EA8C 802407DC 0200202D */  daddu     $a0, $s0, $zero
/* B5EA90 802407E0 0C0901CD */  jal       jan_08_UnkFunc37
/* B5EA94 802407E4 00122C03 */   sra      $a1, $s2, 0x10
/* B5EA98 802407E8 10540003 */  beq       $v0, $s4, .L802407F8
/* B5EA9C 802407EC 26100001 */   addiu    $s0, $s0, 1
/* B5EAA0 802407F0 08090201 */  j         .L80240804
/* B5EAA4 802407F4 AE750084 */   sw       $s5, 0x84($s3)
.L802407F8:
/* B5EAA8 802407F8 2A02000C */  slti      $v0, $s0, 0xc
/* B5EAAC 802407FC 1440FFF4 */  bnez      $v0, .L802407D0
/* B5EAB0 80240800 26310008 */   addiu    $s1, $s1, 8
.L80240804:
/* B5EAB4 80240804 8FBF0028 */  lw        $ra, 0x28($sp)
/* B5EAB8 80240808 8FB50024 */  lw        $s5, 0x24($sp)
/* B5EABC 8024080C 8FB40020 */  lw        $s4, 0x20($sp)
/* B5EAC0 80240810 8FB3001C */  lw        $s3, 0x1c($sp)
/* B5EAC4 80240814 8FB20018 */  lw        $s2, 0x18($sp)
/* B5EAC8 80240818 8FB10014 */  lw        $s1, 0x14($sp)
/* B5EACC 8024081C 8FB00010 */  lw        $s0, 0x10($sp)
/* B5EAD0 80240820 24020002 */  addiu     $v0, $zero, 2
/* B5EAD4 80240824 03E00008 */  jr        $ra
/* B5EAD8 80240828 27BD0030 */   addiu    $sp, $sp, 0x30
