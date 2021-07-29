.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8003E810
/* 19C10 8003E810 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 19C14 8003E814 AFB3001C */  sw        $s3, 0x1c($sp)
/* 19C18 8003E818 0080982D */  daddu     $s3, $a0, $zero
/* 19C1C 8003E81C AFB40020 */  sw        $s4, 0x20($sp)
/* 19C20 8003E820 00A0A02D */  daddu     $s4, $a1, $zero
/* 19C24 8003E824 AFB20018 */  sw        $s2, 0x18($sp)
/* 19C28 8003E828 3C12800B */  lui       $s2, %hi(D_800B0EF0)
/* 19C2C 8003E82C 26520EF0 */  addiu     $s2, $s2, %lo(D_800B0EF0)
/* 19C30 8003E830 AFBF0024 */  sw        $ra, 0x24($sp)
/* 19C34 8003E834 AFB10014 */  sw        $s1, 0x14($sp)
/* 19C38 8003E838 AFB00010 */  sw        $s0, 0x10($sp)
/* 19C3C 8003E83C 8242001C */  lb        $v0, 0x1c($s2)
/* 19C40 8003E840 1840001E */  blez      $v0, .L8003E8BC
/* 19C44 8003E844 0000802D */   daddu    $s0, $zero, $zero
/* 19C48 8003E848 0240882D */  daddu     $s1, $s2, $zero
.L8003E84C:
/* 19C4C 8003E84C 8E260028 */  lw        $a2, 0x28($s1)
/* 19C50 8003E850 50C00015 */  beql      $a2, $zero, .L8003E8A8
/* 19C54 8003E854 26310004 */   addiu    $s1, $s1, 4
/* 19C58 8003E858 8CC20000 */  lw        $v0, ($a2)
/* 19C5C 8003E85C 18400011 */  blez      $v0, .L8003E8A4
/* 19C60 8003E860 0000282D */   daddu    $a1, $zero, $zero
/* 19C64 8003E864 00C0182D */  daddu     $v1, $a2, $zero
.L8003E868:
/* 19C68 8003E868 8C640004 */  lw        $a0, 4($v1)
/* 19C6C 8003E86C 10800008 */  beqz      $a0, .L8003E890
/* 19C70 8003E870 00000000 */   nop
/* 19C74 8003E874 84820008 */  lh        $v0, 8($a0)
/* 19C78 8003E878 14530005 */  bne       $v0, $s3, .L8003E890
/* 19C7C 8003E87C 00000000 */   nop
/* 19C80 8003E880 0C00F99D */  jal       func_8003E674
/* 19C84 8003E884 0280282D */   daddu    $a1, $s4, $zero
/* 19C88 8003E888 0800FA2A */  j         .L8003E8A8
/* 19C8C 8003E88C 26310004 */   addiu    $s1, $s1, 4
.L8003E890:
/* 19C90 8003E890 8CC20000 */  lw        $v0, ($a2)
/* 19C94 8003E894 24A50001 */  addiu     $a1, $a1, 1
/* 19C98 8003E898 00A2102A */  slt       $v0, $a1, $v0
/* 19C9C 8003E89C 1440FFF2 */  bnez      $v0, .L8003E868
/* 19CA0 8003E8A0 24630004 */   addiu    $v1, $v1, 4
.L8003E8A4:
/* 19CA4 8003E8A4 26310004 */  addiu     $s1, $s1, 4
.L8003E8A8:
/* 19CA8 8003E8A8 8242001C */  lb        $v0, 0x1c($s2)
/* 19CAC 8003E8AC 26100001 */  addiu     $s0, $s0, 1
/* 19CB0 8003E8B0 0202102A */  slt       $v0, $s0, $v0
/* 19CB4 8003E8B4 1440FFE5 */  bnez      $v0, .L8003E84C
/* 19CB8 8003E8B8 00000000 */   nop
.L8003E8BC:
/* 19CBC 8003E8BC 8FBF0024 */  lw        $ra, 0x24($sp)
/* 19CC0 8003E8C0 8FB40020 */  lw        $s4, 0x20($sp)
/* 19CC4 8003E8C4 8FB3001C */  lw        $s3, 0x1c($sp)
/* 19CC8 8003E8C8 8FB20018 */  lw        $s2, 0x18($sp)
/* 19CCC 8003E8CC 8FB10014 */  lw        $s1, 0x14($sp)
/* 19CD0 8003E8D0 8FB00010 */  lw        $s0, 0x10($sp)
/* 19CD4 8003E8D4 03E00008 */  jr        $ra
/* 19CD8 8003E8D8 27BD0028 */   addiu    $sp, $sp, 0x28
