.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel remove_part_shadow
/* 195C80 802673A0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 195C84 802673A4 AFB00010 */  sw        $s0, 0x10($sp)
/* 195C88 802673A8 AFBF0014 */  sw        $ra, 0x14($sp)
/* 195C8C 802673AC 0C09A75B */  jal       get_actor
/* 195C90 802673B0 00A0802D */   daddu    $s0, $a1, $zero
/* 195C94 802673B4 0040202D */  daddu     $a0, $v0, $zero
/* 195C98 802673B8 0C099117 */  jal       get_actor_part
/* 195C9C 802673BC 0200282D */   daddu    $a1, $s0, $zero
/* 195CA0 802673C0 8C430000 */  lw        $v1, ($v0)
/* 195CA4 802673C4 8C44009C */  lw        $a0, 0x9c($v0)
/* 195CA8 802673C8 34630004 */  ori       $v1, $v1, 4
/* 195CAC 802673CC 0C0448CA */  jal       func_80112328
/* 195CB0 802673D0 AC430000 */   sw       $v1, ($v0)
/* 195CB4 802673D4 8FBF0014 */  lw        $ra, 0x14($sp)
/* 195CB8 802673D8 8FB00010 */  lw        $s0, 0x10($sp)
/* 195CBC 802673DC 03E00008 */  jr        $ra
/* 195CC0 802673E0 27BD0018 */   addiu    $sp, $sp, 0x18
