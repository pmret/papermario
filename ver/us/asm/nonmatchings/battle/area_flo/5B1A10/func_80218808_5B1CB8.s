.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218808_5B1CB8
/* 5B1CB8 80218808 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 5B1CBC 8021880C AFB10014 */  sw        $s1, 0x14($sp)
/* 5B1CC0 80218810 0080882D */  daddu     $s1, $a0, $zero
/* 5B1CC4 80218814 AFBF0018 */  sw        $ra, 0x18($sp)
/* 5B1CC8 80218818 AFB00010 */  sw        $s0, 0x10($sp)
/* 5B1CCC 8021881C 8E30000C */  lw        $s0, 0xc($s1)
/* 5B1CD0 80218820 8E050000 */  lw        $a1, ($s0)
/* 5B1CD4 80218824 0C0B1EAF */  jal       get_variable
/* 5B1CD8 80218828 26100004 */   addiu    $s0, $s0, 4
/* 5B1CDC 8021882C 0040202D */  daddu     $a0, $v0, $zero
/* 5B1CE0 80218830 2402FF81 */  addiu     $v0, $zero, -0x7f
/* 5B1CE4 80218834 14820002 */  bne       $a0, $v0, .L80218840
/* 5B1CE8 80218838 00000000 */   nop
/* 5B1CEC 8021883C 8E240148 */  lw        $a0, 0x148($s1)
.L80218840:
/* 5B1CF0 80218840 0C09A75B */  jal       get_actor
/* 5B1CF4 80218844 00000000 */   nop
/* 5B1CF8 80218848 0040202D */  daddu     $a0, $v0, $zero
/* 5B1CFC 8021884C 90830136 */  lbu       $v1, 0x136($a0)
/* 5B1D00 80218850 24020047 */  addiu     $v0, $zero, 0x47
/* 5B1D04 80218854 1062000B */  beq       $v1, $v0, .L80218884
/* 5B1D08 80218858 0062102A */   slt      $v0, $v1, $v0
/* 5B1D0C 8021885C 54400011 */  bnel      $v0, $zero, .L802188A4
/* 5B1D10 80218860 0220202D */   daddu    $a0, $s1, $zero
/* 5B1D14 80218864 28620065 */  slti      $v0, $v1, 0x65
/* 5B1D18 80218868 1040000D */  beqz      $v0, .L802188A0
/* 5B1D1C 8021886C 2862004D */   slti     $v0, $v1, 0x4d
/* 5B1D20 80218870 1440000C */  bnez      $v0, .L802188A4
/* 5B1D24 80218874 0220202D */   daddu    $a0, $s1, $zero
/* 5B1D28 80218878 8E050000 */  lw        $a1, ($s0)
/* 5B1D2C 8021887C 0808622B */  j         .L802188AC
/* 5B1D30 80218880 2406FFFF */   addiu    $a2, $zero, -1
.L80218884:
/* 5B1D34 80218884 8C8300A8 */  lw        $v1, 0xa8($a0)
/* 5B1D38 80218888 24020001 */  addiu     $v0, $zero, 1
/* 5B1D3C 8021888C 14620005 */  bne       $v1, $v0, .L802188A4
/* 5B1D40 80218890 0220202D */   daddu    $a0, $s1, $zero
/* 5B1D44 80218894 8E050000 */  lw        $a1, ($s0)
/* 5B1D48 80218898 0808622B */  j         .L802188AC
/* 5B1D4C 8021889C 2406FFFF */   addiu    $a2, $zero, -1
.L802188A0:
/* 5B1D50 802188A0 0220202D */  daddu     $a0, $s1, $zero
.L802188A4:
/* 5B1D54 802188A4 8E050000 */  lw        $a1, ($s0)
/* 5B1D58 802188A8 0000302D */  daddu     $a2, $zero, $zero
.L802188AC:
/* 5B1D5C 802188AC 0C0B2026 */  jal       evt_set_variable
/* 5B1D60 802188B0 00000000 */   nop
/* 5B1D64 802188B4 8FBF0018 */  lw        $ra, 0x18($sp)
/* 5B1D68 802188B8 8FB10014 */  lw        $s1, 0x14($sp)
/* 5B1D6C 802188BC 8FB00010 */  lw        $s0, 0x10($sp)
/* 5B1D70 802188C0 24020002 */  addiu     $v0, $zero, 2
/* 5B1D74 802188C4 03E00008 */  jr        $ra
/* 5B1D78 802188C8 27BD0020 */   addiu    $sp, $sp, 0x20
/* 5B1D7C 802188CC 00000000 */  nop
