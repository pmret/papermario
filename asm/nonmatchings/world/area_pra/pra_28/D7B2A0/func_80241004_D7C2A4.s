.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241004_D7C2A4
/* D7C2A4 80241004 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D7C2A8 80241008 AFB00010 */  sw        $s0, 0x10($sp)
/* D7C2AC 8024100C 0080802D */  daddu     $s0, $a0, $zero
/* D7C2B0 80241010 AFBF0018 */  sw        $ra, 0x18($sp)
/* D7C2B4 80241014 AFB10014 */  sw        $s1, 0x14($sp)
/* D7C2B8 80241018 8E02000C */  lw        $v0, 0xc($s0)
/* D7C2BC 8024101C 8C510000 */  lw        $s1, ($v0)
/* D7C2C0 80241020 0C0B1EAF */  jal       get_variable
/* D7C2C4 80241024 0220282D */   daddu    $a1, $s1, $zero
/* D7C2C8 80241028 3C03FFF0 */  lui       $v1, 0xfff0
/* D7C2CC 8024102C 3463FFFF */  ori       $v1, $v1, 0xffff
/* D7C2D0 80241030 0200202D */  daddu     $a0, $s0, $zero
/* D7C2D4 80241034 00431024 */  and       $v0, $v0, $v1
/* D7C2D8 80241038 00021140 */  sll       $v0, $v0, 5
/* D7C2DC 8024103C 3C068008 */  lui       $a2, %hi(gItemTable)
/* D7C2E0 80241040 00C23021 */  addu      $a2, $a2, $v0
/* D7C2E4 80241044 8CC678E0 */  lw        $a2, %lo(gItemTable)($a2)
/* D7C2E8 80241048 0C0B2026 */  jal       set_variable
/* D7C2EC 8024104C 0220282D */   daddu    $a1, $s1, $zero
/* D7C2F0 80241050 8FBF0018 */  lw        $ra, 0x18($sp)
/* D7C2F4 80241054 8FB10014 */  lw        $s1, 0x14($sp)
/* D7C2F8 80241058 8FB00010 */  lw        $s0, 0x10($sp)
/* D7C2FC 8024105C 24020002 */  addiu     $v0, $zero, 2
/* D7C300 80241060 03E00008 */  jr        $ra
/* D7C304 80241064 27BD0020 */   addiu    $sp, $sp, 0x20
