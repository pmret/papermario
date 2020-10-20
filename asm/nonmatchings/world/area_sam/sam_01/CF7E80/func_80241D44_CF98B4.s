.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241D44_CF98B4
/* CF98B4 80241D44 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* CF98B8 80241D48 AFB00010 */  sw        $s0, 0x10($sp)
/* CF98BC 80241D4C 0080802D */  daddu     $s0, $a0, $zero
/* CF98C0 80241D50 AFBF0018 */  sw        $ra, 0x18($sp)
/* CF98C4 80241D54 AFB10014 */  sw        $s1, 0x14($sp)
/* CF98C8 80241D58 8E02000C */  lw        $v0, 0xc($s0)
/* CF98CC 80241D5C 8C510000 */  lw        $s1, ($v0)
/* CF98D0 80241D60 0C0B1EAF */  jal       get_variable
/* CF98D4 80241D64 0220282D */   daddu    $a1, $s1, $zero
/* CF98D8 80241D68 3C03FFF0 */  lui       $v1, 0xfff0
/* CF98DC 80241D6C 3463FFFF */  ori       $v1, $v1, 0xffff
/* CF98E0 80241D70 0200202D */  daddu     $a0, $s0, $zero
/* CF98E4 80241D74 00431024 */  and       $v0, $v0, $v1
/* CF98E8 80241D78 00021140 */  sll       $v0, $v0, 5
/* CF98EC 80241D7C 3C068008 */  lui       $a2, %hi(gItemTable)
/* CF98F0 80241D80 00C23021 */  addu      $a2, $a2, $v0
/* CF98F4 80241D84 8CC678E0 */  lw        $a2, %lo(gItemTable)($a2)
/* CF98F8 80241D88 0C0B2026 */  jal       set_variable
/* CF98FC 80241D8C 0220282D */   daddu    $a1, $s1, $zero
/* CF9900 80241D90 8FBF0018 */  lw        $ra, 0x18($sp)
/* CF9904 80241D94 8FB10014 */  lw        $s1, 0x14($sp)
/* CF9908 80241D98 8FB00010 */  lw        $s0, 0x10($sp)
/* CF990C 80241D9C 24020002 */  addiu     $v0, $zero, 2
/* CF9910 80241DA0 03E00008 */  jr        $ra
/* CF9914 80241DA4 27BD0020 */   addiu    $sp, $sp, 0x20
