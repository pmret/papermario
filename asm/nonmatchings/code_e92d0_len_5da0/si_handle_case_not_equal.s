.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel si_handle_case_not_equal
/* E9A6C 802C50BC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* E9A70 802C50C0 AFB10014 */  sw        $s1, 0x14($sp)
/* E9A74 802C50C4 0080882D */  daddu     $s1, $a0, $zero
/* E9A78 802C50C8 AFBF0018 */  sw        $ra, 0x18($sp)
/* E9A7C 802C50CC AFB00010 */  sw        $s0, 0x10($sp)
/* E9A80 802C50D0 82300007 */  lb        $s0, 7($s1)
/* E9A84 802C50D4 06010003 */  bgez      $s0, .L802C50E4
/* E9A88 802C50D8 8E25000C */   lw       $a1, 0xc($s1)
.L802C50DC:
/* E9A8C 802C50DC 080B1437 */  j         .L802C50DC
/* E9A90 802C50E0 00000000 */   nop      
.L802C50E4:
/* E9A94 802C50E4 8CA50000 */  lw        $a1, ($a1)
/* E9A98 802C50E8 0C0B1EAF */  jal       get_variable
/* E9A9C 802C50EC 0220202D */   daddu    $a0, $s1, $zero
/* E9AA0 802C50F0 0040282D */  daddu     $a1, $v0, $zero
/* E9AA4 802C50F4 00101080 */  sll       $v0, $s0, 2
/* E9AA8 802C50F8 02221021 */  addu      $v0, $s1, $v0
/* E9AAC 802C50FC 02302021 */  addu      $a0, $s1, $s0
/* E9AB0 802C5100 80830110 */  lb        $v1, 0x110($a0)
/* E9AB4 802C5104 1C600005 */  bgtz      $v1, .L802C511C
/* E9AB8 802C5108 8C420118 */   lw       $v0, 0x118($v0)
/* E9ABC 802C510C 0C0B2279 */  jal       si_goto_end_case
/* E9AC0 802C5110 0220202D */   daddu    $a0, $s1, $zero
/* E9AC4 802C5114 080B144C */  j         .L802C5130
/* E9AC8 802C5118 AE220008 */   sw       $v0, 8($s1)
.L802C511C:
/* E9ACC 802C511C 54A20004 */  bnel      $a1, $v0, .L802C5130
/* E9AD0 802C5120 A0800110 */   sb       $zero, 0x110($a0)
/* E9AD4 802C5124 0C0B2298 */  jal       si_goto_next_case
/* E9AD8 802C5128 0220202D */   daddu    $a0, $s1, $zero
/* E9ADC 802C512C AE220008 */  sw        $v0, 8($s1)
.L802C5130:
/* E9AE0 802C5130 24020002 */  addiu     $v0, $zero, 2
/* E9AE4 802C5134 8FBF0018 */  lw        $ra, 0x18($sp)
/* E9AE8 802C5138 8FB10014 */  lw        $s1, 0x14($sp)
/* E9AEC 802C513C 8FB00010 */  lw        $s0, 0x10($sp)
/* E9AF0 802C5140 03E00008 */  jr        $ra
/* E9AF4 802C5144 27BD0020 */   addiu    $sp, $sp, 0x20
