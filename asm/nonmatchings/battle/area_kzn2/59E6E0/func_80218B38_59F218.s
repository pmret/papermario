.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218B38_59F218
/* 59F218 80218B38 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 59F21C 80218B3C AFB10014 */  sw        $s1, 0x14($sp)
/* 59F220 80218B40 0080882D */  daddu     $s1, $a0, $zero
/* 59F224 80218B44 AFBF0018 */  sw        $ra, 0x18($sp)
/* 59F228 80218B48 AFB00010 */  sw        $s0, 0x10($sp)
/* 59F22C 80218B4C 8E30000C */  lw        $s0, 0xc($s1)
/* 59F230 80218B50 8E050000 */  lw        $a1, ($s0)
/* 59F234 80218B54 0C0B1EAF */  jal       get_variable
/* 59F238 80218B58 26100004 */   addiu    $s0, $s0, 4
/* 59F23C 80218B5C 00021080 */  sll       $v0, $v0, 2
/* 59F240 80218B60 8E050000 */  lw        $a1, ($s0)
/* 59F244 80218B64 3C068022 */  lui       $a2, %hi(D_80222D48)
/* 59F248 80218B68 00C23021 */  addu      $a2, $a2, $v0
/* 59F24C 80218B6C 8CC62D48 */  lw        $a2, %lo(D_80222D48)($a2)
/* 59F250 80218B70 0C0B2026 */  jal       set_variable
/* 59F254 80218B74 0220202D */   daddu    $a0, $s1, $zero
/* 59F258 80218B78 8FBF0018 */  lw        $ra, 0x18($sp)
/* 59F25C 80218B7C 8FB10014 */  lw        $s1, 0x14($sp)
/* 59F260 80218B80 8FB00010 */  lw        $s0, 0x10($sp)
/* 59F264 80218B84 24020002 */  addiu     $v0, $zero, 2
/* 59F268 80218B88 03E00008 */  jr        $ra
/* 59F26C 80218B8C 27BD0020 */   addiu    $sp, $sp, 0x20
