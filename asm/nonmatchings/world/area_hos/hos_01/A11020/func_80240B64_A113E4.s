.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240B64_A113E4
/* A113E4 80240B64 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A113E8 80240B68 AFB10014 */  sw        $s1, 0x14($sp)
/* A113EC 80240B6C 0080882D */  daddu     $s1, $a0, $zero
/* A113F0 80240B70 AFBF0018 */  sw        $ra, 0x18($sp)
/* A113F4 80240B74 AFB00010 */  sw        $s0, 0x10($sp)
/* A113F8 80240B78 8E30000C */  lw        $s0, 0xc($s1)
/* A113FC 80240B7C 8E050000 */  lw        $a1, ($s0)
/* A11400 80240B80 0C0B1EAF */  jal       get_variable
/* A11404 80240B84 26100004 */   addiu    $s0, $s0, 4
/* A11408 80240B88 0220202D */  daddu     $a0, $s1, $zero
/* A1140C 80240B8C 8E050000 */  lw        $a1, ($s0)
/* A11410 80240B90 0C0B1EAF */  jal       get_variable
/* A11414 80240B94 0040802D */   daddu    $s0, $v0, $zero
/* A11418 80240B98 8E03000C */  lw        $v1, 0xc($s0)
/* A1141C 80240B9C AC620038 */  sw        $v0, 0x38($v1)
/* A11420 80240BA0 8FBF0018 */  lw        $ra, 0x18($sp)
/* A11424 80240BA4 8FB10014 */  lw        $s1, 0x14($sp)
/* A11428 80240BA8 8FB00010 */  lw        $s0, 0x10($sp)
/* A1142C 80240BAC 24020002 */  addiu     $v0, $zero, 2
/* A11430 80240BB0 03E00008 */  jr        $ra
/* A11434 80240BB4 27BD0020 */   addiu    $sp, $sp, 0x20
