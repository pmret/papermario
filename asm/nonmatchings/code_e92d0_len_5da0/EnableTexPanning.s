.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel EnableTexPanning
/* EDBB8 802C9208 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* EDBBC 802C920C AFB10014 */  sw        $s1, 0x14($sp)
/* EDBC0 802C9210 0080882D */  daddu     $s1, $a0, $zero
/* EDBC4 802C9214 AFBF0018 */  sw        $ra, 0x18($sp)
/* EDBC8 802C9218 AFB00010 */  sw        $s0, 0x10($sp)
/* EDBCC 802C921C 8E30000C */  lw        $s0, 0xc($s1)
/* EDBD0 802C9220 8E050000 */  lw        $a1, ($s0)
/* EDBD4 802C9224 0C0B1EAF */  jal       get_variable
/* EDBD8 802C9228 26100004 */   addiu    $s0, $s0, 4
/* EDBDC 802C922C 0220202D */  daddu     $a0, $s1, $zero
/* EDBE0 802C9230 8E050000 */  lw        $a1, ($s0)
/* EDBE4 802C9234 0C0B1EAF */  jal       get_variable
/* EDBE8 802C9238 0040802D */   daddu    $s0, $v0, $zero
/* EDBEC 802C923C 0200202D */  daddu     $a0, $s0, $zero
/* EDBF0 802C9240 0C046C04 */  jal       get_model_list_index_from_tree_index
/* EDBF4 802C9244 0040802D */   daddu    $s0, $v0, $zero
/* EDBF8 802C9248 0C046B4C */  jal       get_model_from_list_index
/* EDBFC 802C924C 0040202D */   daddu    $a0, $v0, $zero
/* EDC00 802C9250 12000004 */  beqz      $s0, .L802C9264
/* EDC04 802C9254 0040182D */   daddu    $v1, $v0, $zero
/* EDC08 802C9258 94620000 */  lhu       $v0, ($v1)
/* EDC0C 802C925C 080B249B */  j         .L802C926C
/* EDC10 802C9260 34420800 */   ori      $v0, $v0, 0x800
.L802C9264:
/* EDC14 802C9264 94620000 */  lhu       $v0, ($v1)
/* EDC18 802C9268 3042F7FF */  andi      $v0, $v0, 0xf7ff
.L802C926C:
/* EDC1C 802C926C A4620000 */  sh        $v0, ($v1)
/* EDC20 802C9270 8FBF0018 */  lw        $ra, 0x18($sp)
/* EDC24 802C9274 8FB10014 */  lw        $s1, 0x14($sp)
/* EDC28 802C9278 8FB00010 */  lw        $s0, 0x10($sp)
/* EDC2C 802C927C 24020002 */  addiu     $v0, $zero, 2
/* EDC30 802C9280 03E00008 */  jr        $ra
/* EDC34 802C9284 27BD0020 */   addiu    $sp, $sp, 0x20
