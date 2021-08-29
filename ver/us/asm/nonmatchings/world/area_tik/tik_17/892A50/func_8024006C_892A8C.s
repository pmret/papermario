.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024006C_892A8C
/* 892A8C 8024006C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 892A90 80240070 AFBF0010 */  sw        $ra, 0x10($sp)
/* 892A94 80240074 8C82000C */  lw        $v0, 0xc($a0)
/* 892A98 80240078 0C0B1EAF */  jal       evt_get_variable
/* 892A9C 8024007C 8C450000 */   lw       $a1, ($v0)
/* 892AA0 80240080 0C0B95A4 */  jal       entity_upgrade_block_hide_content
/* 892AA4 80240084 0040202D */   daddu    $a0, $v0, $zero
/* 892AA8 80240088 8FBF0010 */  lw        $ra, 0x10($sp)
/* 892AAC 8024008C 24020002 */  addiu     $v0, $zero, 2
/* 892AB0 80240090 03E00008 */  jr        $ra
/* 892AB4 80240094 27BD0018 */   addiu    $sp, $sp, 0x18
