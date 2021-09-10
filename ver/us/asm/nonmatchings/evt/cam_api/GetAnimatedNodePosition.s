.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel GetAnimatedNodePosition
/* F1F70 802CD5C0 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* F1F74 802CD5C4 AFB20038 */  sw        $s2, 0x38($sp)
/* F1F78 802CD5C8 0080902D */  daddu     $s2, $a0, $zero
/* F1F7C 802CD5CC AFBF0048 */  sw        $ra, 0x48($sp)
/* F1F80 802CD5D0 AFB50044 */  sw        $s5, 0x44($sp)
/* F1F84 802CD5D4 AFB40040 */  sw        $s4, 0x40($sp)
/* F1F88 802CD5D8 AFB3003C */  sw        $s3, 0x3c($sp)
/* F1F8C 802CD5DC AFB10034 */  sw        $s1, 0x34($sp)
/* F1F90 802CD5E0 AFB00030 */  sw        $s0, 0x30($sp)
/* F1F94 802CD5E4 8E50000C */  lw        $s0, 0xc($s2)
/* F1F98 802CD5E8 8E050000 */  lw        $a1, ($s0)
/* F1F9C 802CD5EC 0C0B1EAF */  jal       evt_get_variable
/* F1FA0 802CD5F0 26100004 */   addiu    $s0, $s0, 4
/* F1FA4 802CD5F4 8E050000 */  lw        $a1, ($s0)
/* F1FA8 802CD5F8 26100004 */  addiu     $s0, $s0, 4
/* F1FAC 802CD5FC 0240202D */  daddu     $a0, $s2, $zero
/* F1FB0 802CD600 0C0B1EAF */  jal       evt_get_variable
/* F1FB4 802CD604 0040882D */   daddu    $s1, $v0, $zero
/* F1FB8 802CD608 00118880 */  sll       $s1, $s1, 2
/* F1FBC 802CD60C 8E140000 */  lw        $s4, ($s0)
/* F1FC0 802CD610 26100004 */  addiu     $s0, $s0, 4
/* F1FC4 802CD614 3C03802E */  lui       $v1, %hi(gCurrentMeshAnimationListPtr)
/* F1FC8 802CD618 8C63AE30 */  lw        $v1, %lo(gCurrentMeshAnimationListPtr)($v1)
/* F1FCC 802CD61C 8E150000 */  lw        $s5, ($s0)
/* F1FD0 802CD620 02238821 */  addu      $s1, $s1, $v1
/* F1FD4 802CD624 8E330000 */  lw        $s3, ($s1)
/* F1FD8 802CD628 8E100004 */  lw        $s0, 4($s0)
/* F1FDC 802CD62C 8E640000 */  lw        $a0, ($s3)
/* F1FE0 802CD630 0C047FF8 */  jal       get_animator_by_index
/* F1FE4 802CD634 0040882D */   daddu    $s1, $v0, $zero
/* F1FE8 802CD638 0040202D */  daddu     $a0, $v0, $zero
/* F1FEC 802CD63C 0C047FE6 */  jal       get_animator_node_with_id
/* F1FF0 802CD640 0220282D */   daddu    $a1, $s1, $zero
/* F1FF4 802CD644 27A30020 */  addiu     $v1, $sp, 0x20
/* F1FF8 802CD648 AFA30010 */  sw        $v1, 0x10($sp)
/* F1FFC 802CD64C 27A30024 */  addiu     $v1, $sp, 0x24
/* F2000 802CD650 AFA30014 */  sw        $v1, 0x14($sp)
/* F2004 802CD654 27A30028 */  addiu     $v1, $sp, 0x28
/* F2008 802CD658 AFA30018 */  sw        $v1, 0x18($sp)
/* F200C 802CD65C 8C450090 */  lw        $a1, 0x90($v0)
/* F2010 802CD660 8C460094 */  lw        $a2, 0x94($v0)
/* F2014 802CD664 8C470098 */  lw        $a3, 0x98($v0)
/* F2018 802CD668 0C019E78 */  jal       guMtxXFML
/* F201C 802CD66C 26640028 */   addiu    $a0, $s3, 0x28
/* F2020 802CD670 0240202D */  daddu     $a0, $s2, $zero
/* F2024 802CD674 C7A00020 */  lwc1      $f0, 0x20($sp)
/* F2028 802CD678 4600008D */  trunc.w.s $f2, $f0
/* F202C 802CD67C 44061000 */  mfc1      $a2, $f2
/* F2030 802CD680 0C0B2026 */  jal       evt_set_variable
/* F2034 802CD684 0280282D */   daddu    $a1, $s4, $zero
/* F2038 802CD688 0240202D */  daddu     $a0, $s2, $zero
/* F203C 802CD68C C7A00024 */  lwc1      $f0, 0x24($sp)
/* F2040 802CD690 4600008D */  trunc.w.s $f2, $f0
/* F2044 802CD694 44061000 */  mfc1      $a2, $f2
/* F2048 802CD698 0C0B2026 */  jal       evt_set_variable
/* F204C 802CD69C 02A0282D */   daddu    $a1, $s5, $zero
/* F2050 802CD6A0 0240202D */  daddu     $a0, $s2, $zero
/* F2054 802CD6A4 C7A00028 */  lwc1      $f0, 0x28($sp)
/* F2058 802CD6A8 4600008D */  trunc.w.s $f2, $f0
/* F205C 802CD6AC 44061000 */  mfc1      $a2, $f2
/* F2060 802CD6B0 0C0B2026 */  jal       evt_set_variable
/* F2064 802CD6B4 0200282D */   daddu    $a1, $s0, $zero
/* F2068 802CD6B8 8FBF0048 */  lw        $ra, 0x48($sp)
/* F206C 802CD6BC 8FB50044 */  lw        $s5, 0x44($sp)
/* F2070 802CD6C0 8FB40040 */  lw        $s4, 0x40($sp)
/* F2074 802CD6C4 8FB3003C */  lw        $s3, 0x3c($sp)
/* F2078 802CD6C8 8FB20038 */  lw        $s2, 0x38($sp)
/* F207C 802CD6CC 8FB10034 */  lw        $s1, 0x34($sp)
/* F2080 802CD6D0 8FB00030 */  lw        $s0, 0x30($sp)
/* F2084 802CD6D4 24020002 */  addiu     $v0, $zero, 2
/* F2088 802CD6D8 03E00008 */  jr        $ra
/* F208C 802CD6DC 27BD0050 */   addiu    $sp, $sp, 0x50
