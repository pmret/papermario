.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80219C74_6A0E74
/* 6A0E74 80219C74 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 6A0E78 80219C78 AFB10014 */  sw        $s1, 0x14($sp)
/* 6A0E7C 80219C7C 0080882D */  daddu     $s1, $a0, $zero
/* 6A0E80 80219C80 AFB20018 */  sw        $s2, 0x18($sp)
/* 6A0E84 80219C84 3C12800E */  lui       $s2, %hi(gBattleStatus)
/* 6A0E88 80219C88 2652C070 */  addiu     $s2, $s2, %lo(gBattleStatus)
/* 6A0E8C 80219C8C AFBF001C */  sw        $ra, 0x1c($sp)
/* 6A0E90 80219C90 AFB00010 */  sw        $s0, 0x10($sp)
/* 6A0E94 80219C94 8E30000C */  lw        $s0, 0xc($s1)
/* 6A0E98 80219C98 82460097 */  lb        $a2, 0x97($s2)
/* 6A0E9C 80219C9C 8E050000 */  lw        $a1, ($s0)
/* 6A0EA0 80219CA0 0C0B2026 */  jal       set_variable
/* 6A0EA4 80219CA4 26100004 */   addiu    $s0, $s0, 4
/* 6A0EA8 80219CA8 8E050000 */  lw        $a1, ($s0)
/* 6A0EAC 80219CAC 82460096 */  lb        $a2, 0x96($s2)
/* 6A0EB0 80219CB0 0C0B2026 */  jal       set_variable
/* 6A0EB4 80219CB4 0220202D */   daddu    $a0, $s1, $zero
/* 6A0EB8 80219CB8 8FBF001C */  lw        $ra, 0x1c($sp)
/* 6A0EBC 80219CBC 8FB20018 */  lw        $s2, 0x18($sp)
/* 6A0EC0 80219CC0 8FB10014 */  lw        $s1, 0x14($sp)
/* 6A0EC4 80219CC4 8FB00010 */  lw        $s0, 0x10($sp)
/* 6A0EC8 80219CC8 24020002 */  addiu     $v0, $zero, 2
/* 6A0ECC 80219CCC 03E00008 */  jr        $ra
/* 6A0ED0 80219CD0 27BD0020 */   addiu    $sp, $sp, 0x20
