.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802433BC_85552C
/* 85552C 802433BC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 855530 802433C0 AFB00010 */  sw        $s0, 0x10($sp)
/* 855534 802433C4 AFBF0014 */  sw        $ra, 0x14($sp)
/* 855538 802433C8 0C039D7B */  jal       get_item_count
/* 85553C 802433CC 0080802D */   daddu    $s0, $a0, $zero
/* 855540 802433D0 AE020084 */  sw        $v0, 0x84($s0)
/* 855544 802433D4 8FBF0014 */  lw        $ra, 0x14($sp)
/* 855548 802433D8 8FB00010 */  lw        $s0, 0x10($sp)
/* 85554C 802433DC 24020002 */  addiu     $v0, $zero, 2
/* 855550 802433E0 03E00008 */  jr        $ra
/* 855554 802433E4 27BD0018 */   addiu    $sp, $sp, 0x18
/* 855558 802433E8 00000000 */  nop
/* 85555C 802433EC 00000000 */  nop
