.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240330_C7E4B0
/* C7E4B0 80240330 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C7E4B4 80240334 AFBF0010 */  sw        $ra, 0x10($sp)
/* C7E4B8 80240338 0C03A8CD */  jal       subtract_hp
/* C7E4BC 8024033C 24040001 */   addiu    $a0, $zero, 1
/* C7E4C0 80240340 8FBF0010 */  lw        $ra, 0x10($sp)
/* C7E4C4 80240344 24020002 */  addiu     $v0, $zero, 2
/* C7E4C8 80240348 03E00008 */  jr        $ra
/* C7E4CC 8024034C 27BD0018 */   addiu    $sp, $sp, 0x18
