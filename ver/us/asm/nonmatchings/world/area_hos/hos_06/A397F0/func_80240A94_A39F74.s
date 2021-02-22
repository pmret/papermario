.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240A94_A39F74
/* A39F74 80240A94 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A39F78 80240A98 AFBF0010 */  sw        $ra, 0x10($sp)
/* A39F7C 80240A9C 8C82000C */  lw        $v0, 0xc($a0)
/* A39F80 80240AA0 0C0B1EAF */  jal       get_variable
/* A39F84 80240AA4 8C450000 */   lw       $a1, ($v0)
/* A39F88 80240AA8 3C05F840 */  lui       $a1, 0xf840
/* A39F8C 80240AAC 34A5626B */  ori       $a1, $a1, 0x626b
/* A39F90 80240AB0 0000202D */  daddu     $a0, $zero, $zero
/* A39F94 80240AB4 00452821 */  addu      $a1, $v0, $a1
/* A39F98 80240AB8 0C0B2026 */  jal       set_variable
/* A39F9C 80240ABC 24060001 */   addiu    $a2, $zero, 1
/* A39FA0 80240AC0 8FBF0010 */  lw        $ra, 0x10($sp)
/* A39FA4 80240AC4 24020002 */  addiu     $v0, $zero, 2
/* A39FA8 80240AC8 03E00008 */  jr        $ra
/* A39FAC 80240ACC 27BD0018 */   addiu    $sp, $sp, 0x18
