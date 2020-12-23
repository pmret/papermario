.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BD5A8
/* 3174C8 802BD5A8 3C028011 */  lui       $v0, %hi(D_8010EBB0)
/* 3174CC 802BD5AC 8042EBB0 */  lb        $v0, %lo(D_8010EBB0)($v0)
/* 3174D0 802BD5B0 14400005 */  bnez      $v0, .L802BD5C8
/* 3174D4 802BD5B4 24031000 */   addiu    $v1, $zero, 0x1000
/* 3174D8 802BD5B8 8C820000 */  lw        $v0, ($a0)
/* 3174DC 802BD5BC 30421800 */  andi      $v0, $v0, 0x1800
/* 3174E0 802BD5C0 10430003 */  beq       $v0, $v1, .L802BD5D0
/* 3174E4 802BD5C4 00000000 */   nop      
.L802BD5C8:
/* 3174E8 802BD5C8 03E00008 */  jr        $ra
/* 3174EC 802BD5CC 0000102D */   daddu    $v0, $zero, $zero
.L802BD5D0:
/* 3174F0 802BD5D0 03E00008 */  jr        $ra
/* 3174F4 802BD5D4 24020001 */   addiu    $v0, $zero, 1
