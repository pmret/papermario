.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802CD7D8
/* F2188 802CD7D8 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* F218C 802CD7DC AFB20038 */  sw        $s2, 0x38($sp)
/* F2190 802CD7E0 0080902D */  daddu     $s2, $a0, $zero
/* F2194 802CD7E4 AFBF0048 */  sw        $ra, 0x48($sp)
/* F2198 802CD7E8 AFB50044 */  sw        $s5, 0x44($sp)
/* F219C 802CD7EC AFB40040 */  sw        $s4, 0x40($sp)
/* F21A0 802CD7F0 AFB3003C */  sw        $s3, 0x3c($sp)
/* F21A4 802CD7F4 AFB10034 */  sw        $s1, 0x34($sp)
/* F21A8 802CD7F8 AFB00030 */  sw        $s0, 0x30($sp)
/* F21AC 802CD7FC 8E50000C */  lw        $s0, 0xc($s2)
/* F21B0 802CD800 8E050000 */  lw        $a1, ($s0)
/* F21B4 802CD804 0C0B1EAF */  jal       get_variable
/* F21B8 802CD808 26100004 */   addiu    $s0, $s0, 4
/* F21BC 802CD80C 8E050000 */  lw        $a1, ($s0)
/* F21C0 802CD810 26100004 */  addiu     $s0, $s0, 4
/* F21C4 802CD814 0240202D */  daddu     $a0, $s2, $zero
/* F21C8 802CD818 0C0B1EAF */  jal       get_variable
/* F21CC 802CD81C 0040882D */   daddu    $s1, $v0, $zero
/* F21D0 802CD820 00118880 */  sll       $s1, $s1, 2
/* F21D4 802CD824 8E140000 */  lw        $s4, ($s0)
/* F21D8 802CD828 26100004 */  addiu     $s0, $s0, 4
/* F21DC 802CD82C 3C03802E */  lui       $v1, 0x802e
/* F21E0 802CD830 8C63AE30 */  lw        $v1, -0x51d0($v1)
/* F21E4 802CD834 8E150000 */  lw        $s5, ($s0)
/* F21E8 802CD838 02238821 */  addu      $s1, $s1, $v1
/* F21EC 802CD83C 8E330000 */  lw        $s3, ($s1)
/* F21F0 802CD840 8E100004 */  lw        $s0, 4($s0)
/* F21F4 802CD844 8E640000 */  lw        $a0, ($s3)
/* F21F8 802CD848 0C047FF8 */  jal       func_8011FFE0
/* F21FC 802CD84C 0040882D */   daddu    $s1, $v0, $zero
/* F2200 802CD850 0040202D */  daddu     $a0, $v0, $zero
/* F2204 802CD854 0C047FDD */  jal       func_8011FF74
/* F2208 802CD858 0220282D */   daddu    $a1, $s1, $zero
/* F220C 802CD85C 27A30020 */  addiu     $v1, $sp, 0x20
/* F2210 802CD860 AFA30010 */  sw        $v1, 0x10($sp)
/* F2214 802CD864 27A30024 */  addiu     $v1, $sp, 0x24
/* F2218 802CD868 AFA30014 */  sw        $v1, 0x14($sp)
/* F221C 802CD86C 27A30028 */  addiu     $v1, $sp, 0x28
/* F2220 802CD870 AFA30018 */  sw        $v1, 0x18($sp)
/* F2224 802CD874 8C450090 */  lw        $a1, 0x90($v0)
/* F2228 802CD878 8C460094 */  lw        $a2, 0x94($v0)
/* F222C 802CD87C 8C470098 */  lw        $a3, 0x98($v0)
/* F2230 802CD880 0C019E78 */  jal       guMtxXFML
/* F2234 802CD884 26640028 */   addiu    $a0, $s3, 0x28
/* F2238 802CD888 0240202D */  daddu     $a0, $s2, $zero
/* F223C 802CD88C C7A00020 */  lwc1      $f0, 0x20($sp)
/* F2240 802CD890 4600008D */  trunc.w.s $f2, $f0
/* F2244 802CD894 44061000 */  mfc1      $a2, $f2
/* F2248 802CD898 0C0B2026 */  jal       set_variable
/* F224C 802CD89C 0280282D */   daddu    $a1, $s4, $zero
/* F2250 802CD8A0 0240202D */  daddu     $a0, $s2, $zero
/* F2254 802CD8A4 C7A00024 */  lwc1      $f0, 0x24($sp)
/* F2258 802CD8A8 4600008D */  trunc.w.s $f2, $f0
/* F225C 802CD8AC 44061000 */  mfc1      $a2, $f2
/* F2260 802CD8B0 0C0B2026 */  jal       set_variable
/* F2264 802CD8B4 02A0282D */   daddu    $a1, $s5, $zero
/* F2268 802CD8B8 0240202D */  daddu     $a0, $s2, $zero
/* F226C 802CD8BC C7A00028 */  lwc1      $f0, 0x28($sp)
/* F2270 802CD8C0 4600008D */  trunc.w.s $f2, $f0
/* F2274 802CD8C4 44061000 */  mfc1      $a2, $f2
/* F2278 802CD8C8 0C0B2026 */  jal       set_variable
/* F227C 802CD8CC 0200282D */   daddu    $a1, $s0, $zero
/* F2280 802CD8D0 8FBF0048 */  lw        $ra, 0x48($sp)
/* F2284 802CD8D4 8FB50044 */  lw        $s5, 0x44($sp)
/* F2288 802CD8D8 8FB40040 */  lw        $s4, 0x40($sp)
/* F228C 802CD8DC 8FB3003C */  lw        $s3, 0x3c($sp)
/* F2290 802CD8E0 8FB20038 */  lw        $s2, 0x38($sp)
/* F2294 802CD8E4 8FB10034 */  lw        $s1, 0x34($sp)
/* F2298 802CD8E8 8FB00030 */  lw        $s0, 0x30($sp)
/* F229C 802CD8EC 24020002 */  addiu     $v0, $zero, 2
/* F22A0 802CD8F0 03E00008 */  jr        $ra
/* F22A4 802CD8F4 27BD0050 */   addiu    $sp, $sp, 0x50
