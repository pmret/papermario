.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel PlayModelAnimation
/* F181C 802CCE6C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* F1820 802CCE70 AFB10014 */  sw        $s1, 0x14($sp)
/* F1824 802CCE74 0080882D */  daddu     $s1, $a0, $zero
/* F1828 802CCE78 AFBF0018 */  sw        $ra, 0x18($sp)
/* F182C 802CCE7C AFB00010 */  sw        $s0, 0x10($sp)
/* F1830 802CCE80 8E30000C */  lw        $s0, 0xc($s1)
/* F1834 802CCE84 8E050000 */  lw        $a1, ($s0)
/* F1838 802CCE88 0C0B1EAF */  jal       get_variable
/* F183C 802CCE8C 26100004 */   addiu    $s0, $s0, 4
/* F1840 802CCE90 0220202D */  daddu     $a0, $s1, $zero
/* F1844 802CCE94 8E050000 */  lw        $a1, ($s0)
/* F1848 802CCE98 0C0B1EAF */  jal       get_variable
/* F184C 802CCE9C 0040802D */   daddu    $s0, $v0, $zero
/* F1850 802CCEA0 3C03802E */  lui       $v1, %hi(gMeshAnimationsPtr)
/* F1854 802CCEA4 8C63AE30 */  lw        $v1, %lo(gMeshAnimationsPtr)($v1)
/* F1858 802CCEA8 00108080 */  sll       $s0, $s0, 2
/* F185C 802CCEAC 02038021 */  addu      $s0, $s0, $v1
/* F1860 802CCEB0 8E030000 */  lw        $v1, ($s0)
/* F1864 802CCEB4 8C640000 */  lw        $a0, ($v1)
/* F1868 802CCEB8 0040282D */  daddu     $a1, $v0, $zero
/* F186C 802CCEBC 0C048052 */  jal       play_model_animation
/* F1870 802CCEC0 AC650068 */   sw       $a1, 0x68($v1)
/* F1874 802CCEC4 8FBF0018 */  lw        $ra, 0x18($sp)
/* F1878 802CCEC8 8FB10014 */  lw        $s1, 0x14($sp)
/* F187C 802CCECC 8FB00010 */  lw        $s0, 0x10($sp)
/* F1880 802CCED0 24020002 */  addiu     $v0, $zero, 2
/* F1884 802CCED4 03E00008 */  jr        $ra
/* F1888 802CCED8 27BD0020 */   addiu    $sp, $sp, 0x20
