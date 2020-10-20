.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024034C_A5A37C
/* A5A37C 8024034C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A5A380 80240350 0000202D */  daddu     $a0, $zero, $zero
/* A5A384 80240354 AFBF0010 */  sw        $ra, 0x10($sp)
/* A5A388 80240358 0C015586 */  jal       func_80055618
/* A5A38C 8024035C 24050001 */   addiu    $a1, $zero, 1
/* A5A390 80240360 8FBF0010 */  lw        $ra, 0x10($sp)
/* A5A394 80240364 24020002 */  addiu     $v0, $zero, 2
/* A5A398 80240368 03E00008 */  jr        $ra
/* A5A39C 8024036C 27BD0018 */   addiu    $sp, $sp, 0x18
