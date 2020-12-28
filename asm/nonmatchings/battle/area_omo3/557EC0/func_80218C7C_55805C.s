.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218C7C_55805C
/* 55805C 80218C7C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 558060 80218C80 AFB10014 */  sw        $s1, 0x14($sp)
/* 558064 80218C84 0080882D */  daddu     $s1, $a0, $zero
/* 558068 80218C88 AFBF0018 */  sw        $ra, 0x18($sp)
/* 55806C 80218C8C AFB00010 */  sw        $s0, 0x10($sp)
/* 558070 80218C90 8E30000C */  lw        $s0, 0xc($s1)
/* 558074 80218C94 8E050000 */  lw        $a1, ($s0)
/* 558078 80218C98 0C0B1EAF */  jal       get_variable
/* 55807C 80218C9C 26100004 */   addiu    $s0, $s0, 4
/* 558080 80218CA0 0220202D */  daddu     $a0, $s1, $zero
/* 558084 80218CA4 8E050000 */  lw        $a1, ($s0)
/* 558088 80218CA8 0C0B1EAF */  jal       get_variable
/* 55808C 80218CAC 0040802D */   daddu    $s0, $v0, $zero
/* 558090 80218CB0 0200202D */  daddu     $a0, $s0, $zero
/* 558094 80218CB4 0C00A3C2 */  jal       start_rumble
/* 558098 80218CB8 0040282D */   daddu    $a1, $v0, $zero
/* 55809C 80218CBC 8FBF0018 */  lw        $ra, 0x18($sp)
/* 5580A0 80218CC0 8FB10014 */  lw        $s1, 0x14($sp)
/* 5580A4 80218CC4 8FB00010 */  lw        $s0, 0x10($sp)
/* 5580A8 80218CC8 24020002 */  addiu     $v0, $zero, 2
/* 5580AC 80218CCC 03E00008 */  jr        $ra
/* 5580B0 80218CD0 27BD0020 */   addiu    $sp, $sp, 0x20
/* 5580B4 80218CD4 00000000 */  nop       
/* 5580B8 80218CD8 00000000 */  nop       
/* 5580BC 80218CDC 00000000 */  nop       
