.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024033C_B2C7AC
/* B2C7AC 8024033C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B2C7B0 80240340 0000202D */  daddu     $a0, $zero, $zero
/* B2C7B4 80240344 AFBF0010 */  sw        $ra, 0x10($sp)
/* B2C7B8 80240348 0C052AD8 */  jal       func_8014AB60
/* B2C7BC 8024034C 0080282D */   daddu    $a1, $a0, $zero
/* B2C7C0 80240350 8FBF0010 */  lw        $ra, 0x10($sp)
/* B2C7C4 80240354 24020002 */  addiu     $v0, $zero, 2
/* B2C7C8 80240358 03E00008 */  jr        $ra
/* B2C7CC 8024035C 27BD0018 */   addiu    $sp, $sp, 0x18
