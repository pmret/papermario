.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel spr_init_quad_cache
/* FEE30 802DBD40 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* FEE34 802DBD44 3C048035 */  lui       $a0, %hi(gSpriteHeapPtr)
/* FEE38 802DBD48 2484F800 */  addiu     $a0, $a0, %lo(gSpriteHeapPtr)
/* FEE3C 802DBD4C AFBF0010 */  sw        $ra, 0x10($sp)
/* FEE40 802DBD50 0C00A41B */  jal       _heap_malloc
/* FEE44 802DBD54 24050580 */   addiu    $a1, $zero, 0x580
/* FEE48 802DBD58 2404FFFF */  addiu     $a0, $zero, -1
/* FEE4C 802DBD5C 24030015 */  addiu     $v1, $zero, 0x15
/* FEE50 802DBD60 3C01802E */  lui       $at, %hi(D_802DFE44)
/* FEE54 802DBD64 AC22FE44 */  sw        $v0, %lo(D_802DFE44)($at)
/* FEE58 802DBD68 3C02802E */  lui       $v0, %hi(D_802DFE9C)
/* FEE5C 802DBD6C 2442FE9C */  addiu     $v0, $v0, %lo(D_802DFE9C)
.L802DBD70:
/* FEE60 802DBD70 AC440000 */  sw        $a0, ($v0)
/* FEE64 802DBD74 2463FFFF */  addiu     $v1, $v1, -1
/* FEE68 802DBD78 0461FFFD */  bgez      $v1, .L802DBD70
/* FEE6C 802DBD7C 2442FFFC */   addiu    $v0, $v0, -4
/* FEE70 802DBD80 8FBF0010 */  lw        $ra, 0x10($sp)
/* FEE74 802DBD84 03E00008 */  jr        $ra
/* FEE78 802DBD88 27BD0018 */   addiu    $sp, $sp, 0x18
