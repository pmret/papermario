.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel tik_10_UnkFunc38
/* 886B60 802407A0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 886B64 802407A4 AFB3001C */  sw        $s3, 0x1c($sp)
/* 886B68 802407A8 0080982D */  daddu     $s3, $a0, $zero
/* 886B6C 802407AC AFB00010 */  sw        $s0, 0x10($sp)
/* 886B70 802407B0 24100001 */  addiu     $s0, $zero, 1
/* 886B74 802407B4 AFB40020 */  sw        $s4, 0x20($sp)
/* 886B78 802407B8 2414FFFF */  addiu     $s4, $zero, -1
/* 886B7C 802407BC AFB50024 */  sw        $s5, 0x24($sp)
/* 886B80 802407C0 0200A82D */  daddu     $s5, $s0, $zero
/* 886B84 802407C4 AFB10014 */  sw        $s1, 0x14($sp)
/* 886B88 802407C8 3C118011 */  lui       $s1, %hi(gPlayerData+0x8)
/* 886B8C 802407CC 2631F298 */  addiu     $s1, $s1, %lo(gPlayerData+0x8)
/* 886B90 802407D0 AFBF0028 */  sw        $ra, 0x28($sp)
/* 886B94 802407D4 AFB20018 */  sw        $s2, 0x18($sp)
/* 886B98 802407D8 8E6200B4 */  lw        $v0, 0xb4($s3)
/* 886B9C 802407DC 0280182D */  daddu     $v1, $s4, $zero
/* 886BA0 802407E0 AE630084 */  sw        $v1, 0x84($s3)
/* 886BA4 802407E4 00021027 */  nor       $v0, $zero, $v0
/* 886BA8 802407E8 000217C2 */  srl       $v0, $v0, 0x1f
/* 886BAC 802407EC 00029400 */  sll       $s2, $v0, 0x10
.L802407F0:
/* 886BB0 802407F0 92220014 */  lbu       $v0, 0x14($s1)
/* 886BB4 802407F4 50400008 */  beql      $v0, $zero, .L80240818
/* 886BB8 802407F8 26100001 */   addiu    $s0, $s0, 1
/* 886BBC 802407FC 0200202D */  daddu     $a0, $s0, $zero
/* 886BC0 80240800 0C0901D5 */  jal       tik_10_UnkFunc37
/* 886BC4 80240804 00122C03 */   sra      $a1, $s2, 0x10
/* 886BC8 80240808 10540003 */  beq       $v0, $s4, .L80240818
/* 886BCC 8024080C 26100001 */   addiu    $s0, $s0, 1
/* 886BD0 80240810 08090209 */  j         .L80240824
/* 886BD4 80240814 AE750084 */   sw       $s5, 0x84($s3)
.L80240818:
/* 886BD8 80240818 2A02000C */  slti      $v0, $s0, 0xc
/* 886BDC 8024081C 1440FFF4 */  bnez      $v0, .L802407F0
/* 886BE0 80240820 26310008 */   addiu    $s1, $s1, 8
.L80240824:
/* 886BE4 80240824 8FBF0028 */  lw        $ra, 0x28($sp)
/* 886BE8 80240828 8FB50024 */  lw        $s5, 0x24($sp)
/* 886BEC 8024082C 8FB40020 */  lw        $s4, 0x20($sp)
/* 886BF0 80240830 8FB3001C */  lw        $s3, 0x1c($sp)
/* 886BF4 80240834 8FB20018 */  lw        $s2, 0x18($sp)
/* 886BF8 80240838 8FB10014 */  lw        $s1, 0x14($sp)
/* 886BFC 8024083C 8FB00010 */  lw        $s0, 0x10($sp)
/* 886C00 80240840 24020002 */  addiu     $v0, $zero, 2
/* 886C04 80240844 03E00008 */  jr        $ra
/* 886C08 80240848 27BD0030 */   addiu    $sp, $sp, 0x30
