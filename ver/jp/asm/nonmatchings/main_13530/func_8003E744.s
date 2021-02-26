.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8003E744
/* 19B44 8003E744 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 19B48 8003E748 AFB3001C */  sw        $s3, 0x1c($sp)
/* 19B4C 8003E74C 0080982D */  daddu     $s3, $a0, $zero
/* 19B50 8003E750 AFB40020 */  sw        $s4, 0x20($sp)
/* 19B54 8003E754 00A0A02D */  daddu     $s4, $a1, $zero
/* 19B58 8003E758 AFB20018 */  sw        $s2, 0x18($sp)
/* 19B5C 8003E75C 3C12800B */  lui       $s2, %hi(D_800B0EF0)
/* 19B60 8003E760 26520EF0 */  addiu     $s2, $s2, %lo(D_800B0EF0)
/* 19B64 8003E764 AFBF0024 */  sw        $ra, 0x24($sp)
/* 19B68 8003E768 AFB10014 */  sw        $s1, 0x14($sp)
/* 19B6C 8003E76C AFB00010 */  sw        $s0, 0x10($sp)
/* 19B70 8003E770 8242001C */  lb        $v0, 0x1c($s2)
/* 19B74 8003E774 1840001E */  blez      $v0, .L8003E7F0
/* 19B78 8003E778 0000802D */   daddu    $s0, $zero, $zero
/* 19B7C 8003E77C 0240882D */  daddu     $s1, $s2, $zero
.L8003E780:
/* 19B80 8003E780 8E260028 */  lw        $a2, 0x28($s1)
/* 19B84 8003E784 50C00015 */  beql      $a2, $zero, .L8003E7DC
/* 19B88 8003E788 26310004 */   addiu    $s1, $s1, 4
/* 19B8C 8003E78C 8CC20000 */  lw        $v0, ($a2)
/* 19B90 8003E790 18400011 */  blez      $v0, .L8003E7D8
/* 19B94 8003E794 0000282D */   daddu    $a1, $zero, $zero
/* 19B98 8003E798 00C0182D */  daddu     $v1, $a2, $zero
.L8003E79C:
/* 19B9C 8003E79C 8C640004 */  lw        $a0, 4($v1)
/* 19BA0 8003E7A0 10800008 */  beqz      $a0, .L8003E7C4
/* 19BA4 8003E7A4 00000000 */   nop
/* 19BA8 8003E7A8 84820008 */  lh        $v0, 8($a0)
/* 19BAC 8003E7AC 14530005 */  bne       $v0, $s3, .L8003E7C4
/* 19BB0 8003E7B0 00000000 */   nop
/* 19BB4 8003E7B4 0C00F983 */  jal       func_8003E60C
/* 19BB8 8003E7B8 0280282D */   daddu    $a1, $s4, $zero
/* 19BBC 8003E7BC 0800F9F7 */  j         .L8003E7DC
/* 19BC0 8003E7C0 26310004 */   addiu    $s1, $s1, 4
.L8003E7C4:
/* 19BC4 8003E7C4 8CC20000 */  lw        $v0, ($a2)
/* 19BC8 8003E7C8 24A50001 */  addiu     $a1, $a1, 1
/* 19BCC 8003E7CC 00A2102A */  slt       $v0, $a1, $v0
/* 19BD0 8003E7D0 1440FFF2 */  bnez      $v0, .L8003E79C
/* 19BD4 8003E7D4 24630004 */   addiu    $v1, $v1, 4
.L8003E7D8:
/* 19BD8 8003E7D8 26310004 */  addiu     $s1, $s1, 4
.L8003E7DC:
/* 19BDC 8003E7DC 8242001C */  lb        $v0, 0x1c($s2)
/* 19BE0 8003E7E0 26100001 */  addiu     $s0, $s0, 1
/* 19BE4 8003E7E4 0202102A */  slt       $v0, $s0, $v0
/* 19BE8 8003E7E8 1440FFE5 */  bnez      $v0, .L8003E780
/* 19BEC 8003E7EC 00000000 */   nop
.L8003E7F0:
/* 19BF0 8003E7F0 8FBF0024 */  lw        $ra, 0x24($sp)
/* 19BF4 8003E7F4 8FB40020 */  lw        $s4, 0x20($sp)
/* 19BF8 8003E7F8 8FB3001C */  lw        $s3, 0x1c($sp)
/* 19BFC 8003E7FC 8FB20018 */  lw        $s2, 0x18($sp)
/* 19C00 8003E800 8FB10014 */  lw        $s1, 0x14($sp)
/* 19C04 8003E804 8FB00010 */  lw        $s0, 0x10($sp)
/* 19C08 8003E808 03E00008 */  jr        $ra
/* 19C0C 8003E80C 27BD0028 */   addiu    $sp, $sp, 0x28
