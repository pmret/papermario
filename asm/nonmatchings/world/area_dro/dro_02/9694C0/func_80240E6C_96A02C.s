.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240E6C_96A02C
/* 96A02C 80240E6C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 96A030 80240E70 AFB10014 */  sw        $s1, 0x14($sp)
/* 96A034 80240E74 0080882D */  daddu     $s1, $a0, $zero
/* 96A038 80240E78 AFBF0018 */  sw        $ra, 0x18($sp)
/* 96A03C 80240E7C AFB00010 */  sw        $s0, 0x10($sp)
/* 96A040 80240E80 8E30000C */  lw        $s0, 0xc($s1)
/* 96A044 80240E84 8E050000 */  lw        $a1, ($s0)
/* 96A048 80240E88 0C0B1EAF */  jal       get_variable
/* 96A04C 80240E8C 26100004 */   addiu    $s0, $s0, 4
/* 96A050 80240E90 0220202D */  daddu     $a0, $s1, $zero
/* 96A054 80240E94 8E050000 */  lw        $a1, ($s0)
/* 96A058 80240E98 0C0B210B */  jal       get_float_variable
/* 96A05C 80240E9C 0040802D */   daddu    $s0, $v0, $zero
/* 96A060 80240EA0 24020002 */  addiu     $v0, $zero, 2
/* 96A064 80240EA4 00501804 */  sllv      $v1, $s0, $v0
/* 96A068 80240EA8 00701821 */  addu      $v1, $v1, $s0
/* 96A06C 80240EAC 00431804 */  sllv      $v1, $v1, $v0
/* 96A070 80240EB0 00701823 */  subu      $v1, $v1, $s0
/* 96A074 80240EB4 000320C0 */  sll       $a0, $v1, 3
/* 96A078 80240EB8 00641821 */  addu      $v1, $v1, $a0
/* 96A07C 80240EBC 000318C0 */  sll       $v1, $v1, 3
/* 96A080 80240EC0 3C01800B */  lui       $at, 0x800b
/* 96A084 80240EC4 00230821 */  addu      $at, $at, $v1
/* 96A088 80240EC8 E4201D98 */  swc1      $f0, 0x1d98($at)
/* 96A08C 80240ECC 8FBF0018 */  lw        $ra, 0x18($sp)
/* 96A090 80240ED0 8FB10014 */  lw        $s1, 0x14($sp)
/* 96A094 80240ED4 8FB00010 */  lw        $s0, 0x10($sp)
/* 96A098 80240ED8 03E00008 */  jr        $ra
/* 96A09C 80240EDC 27BD0020 */   addiu    $sp, $sp, 0x20
