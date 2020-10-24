.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242534_A3BA14
/* A3BA14 80242534 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A3BA18 80242538 AFB00010 */  sw        $s0, 0x10($sp)
/* A3BA1C 8024253C AFBF0014 */  sw        $ra, 0x14($sp)
/* A3BA20 80242540 0C039D88 */  jal       get_item_empty_count
/* A3BA24 80242544 0080802D */   daddu    $s0, $a0, $zero
/* A3BA28 80242548 AE020088 */  sw        $v0, 0x88($s0)
/* A3BA2C 8024254C 8FBF0014 */  lw        $ra, 0x14($sp)
/* A3BA30 80242550 8FB00010 */  lw        $s0, 0x10($sp)
/* A3BA34 80242554 24020002 */  addiu     $v0, $zero, 2
/* A3BA38 80242558 03E00008 */  jr        $ra
/* A3BA3C 8024255C 27BD0018 */   addiu    $sp, $sp, 0x18
