.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel si_handle_case_equal_AND
/* E9F68 802C55B8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* E9F6C 802C55BC AFB10014 */  sw        $s1, 0x14($sp)
/* E9F70 802C55C0 0080882D */  daddu     $s1, $a0, $zero
/* E9F74 802C55C4 AFBF0018 */  sw        $ra, 0x18($sp)
/* E9F78 802C55C8 AFB00010 */  sw        $s0, 0x10($sp)
/* E9F7C 802C55CC 82300007 */  lb        $s0, 7($s1)
/* E9F80 802C55D0 06010003 */  bgez      $s0, .L802C55E0
/* E9F84 802C55D4 8E25000C */   lw       $a1, 0xc($s1)
.L802C55D8:
/* E9F88 802C55D8 080B1576 */  j         .L802C55D8
/* E9F8C 802C55DC 00000000 */   nop      
.L802C55E0:
/* E9F90 802C55E0 8CA50000 */  lw        $a1, ($a1)
/* E9F94 802C55E4 0C0B1EAF */  jal       get_variable
/* E9F98 802C55E8 0220202D */   daddu    $a0, $s1, $zero
/* E9F9C 802C55EC 0040302D */  daddu     $a2, $v0, $zero
/* E9FA0 802C55F0 00101080 */  sll       $v0, $s0, 2
/* E9FA4 802C55F4 02221021 */  addu      $v0, $s1, $v0
/* E9FA8 802C55F8 02301821 */  addu      $v1, $s1, $s0
/* E9FAC 802C55FC 80640110 */  lb        $a0, 0x110($v1)
/* E9FB0 802C5600 8C420118 */  lw        $v0, 0x118($v0)
/* E9FB4 802C5604 14800005 */  bnez      $a0, .L802C561C
/* E9FB8 802C5608 2405FFFE */   addiu    $a1, $zero, -2
/* E9FBC 802C560C 0C0B2279 */  jal       si_goto_end_case
/* E9FC0 802C5610 0220202D */   daddu    $a0, $s1, $zero
/* E9FC4 802C5614 080B1591 */  j         .L802C5644
/* E9FC8 802C5618 AE220008 */   sw       $v0, 8($s1)
.L802C561C:
/* E9FCC 802C561C 10850006 */  beq       $a0, $a1, .L802C5638
/* E9FD0 802C5620 0220202D */   daddu    $a0, $s1, $zero
/* E9FD4 802C5624 54C20004 */  bnel      $a2, $v0, .L802C5638
/* E9FD8 802C5628 A0650110 */   sb       $a1, 0x110($v1)
/* E9FDC 802C562C 2402FFFF */  addiu     $v0, $zero, -1
/* E9FE0 802C5630 080B1591 */  j         .L802C5644
/* E9FE4 802C5634 A0620110 */   sb       $v0, 0x110($v1)
.L802C5638:
/* E9FE8 802C5638 0C0B2298 */  jal       si_goto_next_case
/* E9FEC 802C563C 00000000 */   nop      
/* E9FF0 802C5640 AE220008 */  sw        $v0, 8($s1)
.L802C5644:
/* E9FF4 802C5644 24020002 */  addiu     $v0, $zero, 2
/* E9FF8 802C5648 8FBF0018 */  lw        $ra, 0x18($sp)
/* E9FFC 802C564C 8FB10014 */  lw        $s1, 0x14($sp)
/* EA000 802C5650 8FB00010 */  lw        $s0, 0x10($sp)
/* EA004 802C5654 03E00008 */  jr        $ra
/* EA008 802C5658 27BD0020 */   addiu    $sp, $sp, 0x20
