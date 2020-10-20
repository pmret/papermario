.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243E64
/* 9DAE84 80243E64 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 9DAE88 80243E68 AFB00010 */  sw        $s0, 0x10($sp)
/* 9DAE8C 80243E6C 0080802D */  daddu     $s0, $a0, $zero
/* 9DAE90 80243E70 AFBF0018 */  sw        $ra, 0x18($sp)
/* 9DAE94 80243E74 AFB10014 */  sw        $s1, 0x14($sp)
/* 9DAE98 80243E78 8E02000C */  lw        $v0, 0xc($s0)
/* 9DAE9C 80243E7C 8C510000 */  lw        $s1, ($v0)
/* 9DAEA0 80243E80 0C0B1EAF */  jal       get_variable
/* 9DAEA4 80243E84 0220282D */   daddu    $a1, $s1, $zero
/* 9DAEA8 80243E88 3C03FFF0 */  lui       $v1, 0xfff0
/* 9DAEAC 80243E8C 3463FFFF */  ori       $v1, $v1, 0xffff
/* 9DAEB0 80243E90 0200202D */  daddu     $a0, $s0, $zero
/* 9DAEB4 80243E94 00431024 */  and       $v0, $v0, $v1
/* 9DAEB8 80243E98 00021140 */  sll       $v0, $v0, 5
/* 9DAEBC 80243E9C 3C068008 */  lui       $a2, %hi(gItemTable)
/* 9DAEC0 80243EA0 00C23021 */  addu      $a2, $a2, $v0
/* 9DAEC4 80243EA4 8CC678E0 */  lw        $a2, %lo(gItemTable)($a2)
/* 9DAEC8 80243EA8 0C0B2026 */  jal       set_variable
/* 9DAECC 80243EAC 0220282D */   daddu    $a1, $s1, $zero
/* 9DAED0 80243EB0 8FBF0018 */  lw        $ra, 0x18($sp)
/* 9DAED4 80243EB4 8FB10014 */  lw        $s1, 0x14($sp)
/* 9DAED8 80243EB8 8FB00010 */  lw        $s0, 0x10($sp)
/* 9DAEDC 80243EBC 24020002 */  addiu     $v0, $zero, 2
/* 9DAEE0 80243EC0 03E00008 */  jr        $ra
/* 9DAEE4 80243EC4 27BD0020 */   addiu    $sp, $sp, 0x20
