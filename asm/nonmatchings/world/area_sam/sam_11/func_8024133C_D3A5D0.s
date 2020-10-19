.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024133C_D3B90C
/* D3B90C 8024133C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D3B910 80241340 AFB10014 */  sw        $s1, 0x14($sp)
/* D3B914 80241344 0080882D */  daddu     $s1, $a0, $zero
/* D3B918 80241348 AFBF0018 */  sw        $ra, 0x18($sp)
/* D3B91C 8024134C AFB00010 */  sw        $s0, 0x10($sp)
/* D3B920 80241350 8E30000C */  lw        $s0, 0xc($s1)
/* D3B924 80241354 8E050000 */  lw        $a1, ($s0)
/* D3B928 80241358 0C0B1EAF */  jal       get_variable
/* D3B92C 8024135C 26100004 */   addiu    $s0, $s0, 4
/* D3B930 80241360 0220202D */  daddu     $a0, $s1, $zero
/* D3B934 80241364 8E050000 */  lw        $a1, ($s0)
/* D3B938 80241368 0C0B210B */  jal       get_float_variable
/* D3B93C 8024136C 0040802D */   daddu    $s0, $v0, $zero
/* D3B940 80241370 24020002 */  addiu     $v0, $zero, 2
/* D3B944 80241374 00501804 */  sllv      $v1, $s0, $v0
/* D3B948 80241378 00701821 */  addu      $v1, $v1, $s0
/* D3B94C 8024137C 00431804 */  sllv      $v1, $v1, $v0
/* D3B950 80241380 00701823 */  subu      $v1, $v1, $s0
/* D3B954 80241384 000320C0 */  sll       $a0, $v1, 3
/* D3B958 80241388 00641821 */  addu      $v1, $v1, $a0
/* D3B95C 8024138C 000318C0 */  sll       $v1, $v1, 3
/* D3B960 80241390 3C01800B */  lui       $at, 0x800b
/* D3B964 80241394 00230821 */  addu      $at, $at, $v1
/* D3B968 80241398 E4201D98 */  swc1      $f0, 0x1d98($at)
/* D3B96C 8024139C 8FBF0018 */  lw        $ra, 0x18($sp)
/* D3B970 802413A0 8FB10014 */  lw        $s1, 0x14($sp)
/* D3B974 802413A4 8FB00010 */  lw        $s0, 0x10($sp)
/* D3B978 802413A8 03E00008 */  jr        $ra
/* D3B97C 802413AC 27BD0020 */   addiu    $sp, $sp, 0x20
