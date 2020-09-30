.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel si_handle_case_equal
/* E99E0 802C5030 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* E99E4 802C5034 AFB10014 */  sw        $s1, 0x14($sp)
/* E99E8 802C5038 0080882D */  daddu     $s1, $a0, $zero
/* E99EC 802C503C AFBF0018 */  sw        $ra, 0x18($sp)
/* E99F0 802C5040 AFB00010 */  sw        $s0, 0x10($sp)
/* E99F4 802C5044 82300007 */  lb        $s0, 7($s1)
/* E99F8 802C5048 06010003 */  bgez      $s0, .L802C5058
/* E99FC 802C504C 8E25000C */   lw       $a1, 0xc($s1)
.L802C5050:
/* E9A00 802C5050 080B1414 */  j         .L802C5050
/* E9A04 802C5054 00000000 */   nop      
.L802C5058:
/* E9A08 802C5058 8CA50000 */  lw        $a1, ($a1)
/* E9A0C 802C505C 0C0B1EAF */  jal       get_variable
/* E9A10 802C5060 0220202D */   daddu    $a0, $s1, $zero
/* E9A14 802C5064 0040282D */  daddu     $a1, $v0, $zero
/* E9A18 802C5068 00101080 */  sll       $v0, $s0, 2
/* E9A1C 802C506C 02221021 */  addu      $v0, $s1, $v0
/* E9A20 802C5070 02302021 */  addu      $a0, $s1, $s0
/* E9A24 802C5074 80830110 */  lb        $v1, 0x110($a0)
/* E9A28 802C5078 1C600005 */  bgtz      $v1, .L802C5090
/* E9A2C 802C507C 8C420118 */   lw       $v0, 0x118($v0)
/* E9A30 802C5080 0C0B2279 */  jal       si_goto_end_case
/* E9A34 802C5084 0220202D */   daddu    $a0, $s1, $zero
/* E9A38 802C5088 080B1429 */  j         .L802C50A4
/* E9A3C 802C508C AE220008 */   sw       $v0, 8($s1)
.L802C5090:
/* E9A40 802C5090 50A20004 */  beql      $a1, $v0, .L802C50A4
/* E9A44 802C5094 A0800110 */   sb       $zero, 0x110($a0)
/* E9A48 802C5098 0C0B2298 */  jal       si_goto_next_case
/* E9A4C 802C509C 0220202D */   daddu    $a0, $s1, $zero
/* E9A50 802C50A0 AE220008 */  sw        $v0, 8($s1)
.L802C50A4:
/* E9A54 802C50A4 24020002 */  addiu     $v0, $zero, 2
/* E9A58 802C50A8 8FBF0018 */  lw        $ra, 0x18($sp)
/* E9A5C 802C50AC 8FB10014 */  lw        $s1, 0x14($sp)
/* E9A60 802C50B0 8FB00010 */  lw        $s0, 0x10($sp)
/* E9A64 802C50B4 03E00008 */  jr        $ra
/* E9A68 802C50B8 27BD0020 */   addiu    $sp, $sp, 0x20
