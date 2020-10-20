.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802407F8
/* DDD028 802407F8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* DDD02C 802407FC AFB00010 */  sw        $s0, 0x10($sp)
/* DDD030 80240800 0080802D */  daddu     $s0, $a0, $zero
/* DDD034 80240804 AFBF0018 */  sw        $ra, 0x18($sp)
/* DDD038 80240808 AFB10014 */  sw        $s1, 0x14($sp)
/* DDD03C 8024080C 8E11000C */  lw        $s1, 0xc($s0)
/* DDD040 80240810 8E250000 */  lw        $a1, ($s1)
/* DDD044 80240814 0C0B1EAF */  jal       get_variable
/* DDD048 80240818 26310004 */   addiu    $s1, $s1, 4
/* DDD04C 8024081C 0200202D */  daddu     $a0, $s0, $zero
/* DDD050 80240820 3C038011 */  lui       $v1, %hi(gPlayerData)
/* DDD054 80240824 2463F290 */  addiu     $v1, $v1, %lo(gPlayerData)
/* DDD058 80240828 000210C0 */  sll       $v0, $v0, 3
/* DDD05C 8024082C 00431021 */  addu      $v0, $v0, $v1
/* DDD060 80240830 90460015 */  lbu       $a2, 0x15($v0)
/* DDD064 80240834 8E250000 */  lw        $a1, ($s1)
/* DDD068 80240838 24C60001 */  addiu     $a2, $a2, 1
/* DDD06C 8024083C A0460015 */  sb        $a2, 0x15($v0)
/* DDD070 80240840 00063600 */  sll       $a2, $a2, 0x18
/* DDD074 80240844 0C0B2026 */  jal       set_variable
/* DDD078 80240848 00063603 */   sra      $a2, $a2, 0x18
/* DDD07C 8024084C 8FBF0018 */  lw        $ra, 0x18($sp)
/* DDD080 80240850 8FB10014 */  lw        $s1, 0x14($sp)
/* DDD084 80240854 8FB00010 */  lw        $s0, 0x10($sp)
/* DDD088 80240858 24020002 */  addiu     $v0, $zero, 2
/* DDD08C 8024085C 03E00008 */  jr        $ra
/* DDD090 80240860 27BD0020 */   addiu    $sp, $sp, 0x20
