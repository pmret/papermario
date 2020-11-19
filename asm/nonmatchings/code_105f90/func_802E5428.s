.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802E5428
/* 106CA8 802E5428 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 106CAC 802E542C AFB00010 */  sw        $s0, 0x10($sp)
/* 106CB0 802E5430 AFBF0014 */  sw        $ra, 0x14($sp)
/* 106CB4 802E5434 0C0B92D8 */  jal       func_802E4B60
/* 106CB8 802E5438 0080802D */   daddu    $s0, $a0, $zero
/* 106CBC 802E543C 3C05802F */  lui       $a1, 0x802f
/* 106CC0 802E5440 24A5A728 */  addiu     $a1, $a1, -0x58d8
/* 106CC4 802E5444 0C0442F3 */  jal       func_80110BCC
/* 106CC8 802E5448 0200202D */   daddu    $a0, $s0, $zero
/* 106CCC 802E544C 8FBF0014 */  lw        $ra, 0x14($sp)
/* 106CD0 802E5450 8FB00010 */  lw        $s0, 0x10($sp)
/* 106CD4 802E5454 03E00008 */  jr        $ra
/* 106CD8 802E5458 27BD0018 */   addiu    $sp, $sp, 0x18
