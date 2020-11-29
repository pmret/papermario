.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024030C_C9A50C
/* C9A50C 8024030C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C9A510 80240310 AFBF0010 */  sw        $ra, 0x10($sp)
/* C9A514 80240314 8C82000C */  lw        $v0, 0xc($a0)
/* C9A518 80240318 3C068016 */  lui       $a2, %hi(gCollisionStatus+0x2)
/* C9A51C 8024031C 84C6A552 */  lh        $a2, %lo(gCollisionStatus+0x2)($a2)
/* C9A520 80240320 0C0B2026 */  jal       set_variable
/* C9A524 80240324 8C450000 */   lw       $a1, ($v0)
/* C9A528 80240328 8FBF0010 */  lw        $ra, 0x10($sp)
/* C9A52C 8024032C 24020002 */  addiu     $v0, $zero, 2
/* C9A530 80240330 03E00008 */  jr        $ra
/* C9A534 80240334 27BD0018 */   addiu    $sp, $sp, 0x18
/* C9A538 80240338 00000000 */  nop       
/* C9A53C 8024033C 00000000 */  nop       
