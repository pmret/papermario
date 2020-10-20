.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243010_A1E110
/* A1E110 80243010 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A1E114 80243014 AFB10014 */  sw        $s1, 0x14($sp)
/* A1E118 80243018 0080882D */  daddu     $s1, $a0, $zero
/* A1E11C 8024301C AFBF0018 */  sw        $ra, 0x18($sp)
/* A1E120 80243020 AFB00010 */  sw        $s0, 0x10($sp)
/* A1E124 80243024 8E30000C */  lw        $s0, 0xc($s1)
/* A1E128 80243028 8E050000 */  lw        $a1, ($s0)
/* A1E12C 8024302C 0C0B1EAF */  jal       get_variable
/* A1E130 80243030 26100004 */   addiu    $s0, $s0, 4
/* A1E134 80243034 0220202D */  daddu     $a0, $s1, $zero
/* A1E138 80243038 8E050000 */  lw        $a1, ($s0)
/* A1E13C 8024303C 0C0B210B */  jal       get_float_variable
/* A1E140 80243040 0040802D */   daddu    $s0, $v0, $zero
/* A1E144 80243044 24020002 */  addiu     $v0, $zero, 2
/* A1E148 80243048 00501804 */  sllv      $v1, $s0, $v0
/* A1E14C 8024304C 00701821 */  addu      $v1, $v1, $s0
/* A1E150 80243050 00431804 */  sllv      $v1, $v1, $v0
/* A1E154 80243054 00701823 */  subu      $v1, $v1, $s0
/* A1E158 80243058 000320C0 */  sll       $a0, $v1, 3
/* A1E15C 8024305C 00641821 */  addu      $v1, $v1, $a0
/* A1E160 80243060 000318C0 */  sll       $v1, $v1, 3
/* A1E164 80243064 3C01800B */  lui       $at, 0x800b
/* A1E168 80243068 00230821 */  addu      $at, $at, $v1
/* A1E16C 8024306C E4201D98 */  swc1      $f0, 0x1d98($at)
/* A1E170 80243070 8FBF0018 */  lw        $ra, 0x18($sp)
/* A1E174 80243074 8FB10014 */  lw        $s1, 0x14($sp)
/* A1E178 80243078 8FB00010 */  lw        $s0, 0x10($sp)
/* A1E17C 8024307C 03E00008 */  jr        $ra
/* A1E180 80243080 27BD0020 */   addiu    $sp, $sp, 0x20
