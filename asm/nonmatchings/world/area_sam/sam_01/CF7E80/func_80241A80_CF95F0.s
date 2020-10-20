.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241A80_CF95F0
/* CF95F0 80241A80 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* CF95F4 80241A84 AFB20018 */  sw        $s2, 0x18($sp)
/* CF95F8 80241A88 0080902D */  daddu     $s2, $a0, $zero
/* CF95FC 80241A8C AFBF001C */  sw        $ra, 0x1c($sp)
/* CF9600 80241A90 AFB10014 */  sw        $s1, 0x14($sp)
/* CF9604 80241A94 AFB00010 */  sw        $s0, 0x10($sp)
/* CF9608 80241A98 8E50000C */  lw        $s0, 0xc($s2)
/* CF960C 80241A9C 8E050000 */  lw        $a1, ($s0)
/* CF9610 80241AA0 0C0B1EAF */  jal       get_variable
/* CF9614 80241AA4 26100004 */   addiu    $s0, $s0, 4
/* CF9618 80241AA8 0C04C3D6 */  jal       get_item_entity
/* CF961C 80241AAC 0040202D */   daddu    $a0, $v0, $zero
/* CF9620 80241AB0 8E050000 */  lw        $a1, ($s0)
/* CF9624 80241AB4 26100004 */  addiu     $s0, $s0, 4
/* CF9628 80241AB8 0040882D */  daddu     $s1, $v0, $zero
/* CF962C 80241ABC C6200008 */  lwc1      $f0, 8($s1)
/* CF9630 80241AC0 4600008D */  trunc.w.s $f2, $f0
/* CF9634 80241AC4 44061000 */  mfc1      $a2, $f2
/* CF9638 80241AC8 0C0B2026 */  jal       set_variable
/* CF963C 80241ACC 0240202D */   daddu    $a0, $s2, $zero
/* CF9640 80241AD0 8E050000 */  lw        $a1, ($s0)
/* CF9644 80241AD4 26100004 */  addiu     $s0, $s0, 4
/* CF9648 80241AD8 C620000C */  lwc1      $f0, 0xc($s1)
/* CF964C 80241ADC 4600008D */  trunc.w.s $f2, $f0
/* CF9650 80241AE0 44061000 */  mfc1      $a2, $f2
/* CF9654 80241AE4 0C0B2026 */  jal       set_variable
/* CF9658 80241AE8 0240202D */   daddu    $a0, $s2, $zero
/* CF965C 80241AEC C6200010 */  lwc1      $f0, 0x10($s1)
/* CF9660 80241AF0 8E050000 */  lw        $a1, ($s0)
/* CF9664 80241AF4 4600008D */  trunc.w.s $f2, $f0
/* CF9668 80241AF8 44061000 */  mfc1      $a2, $f2
/* CF966C 80241AFC 0C0B2026 */  jal       set_variable
/* CF9670 80241B00 0240202D */   daddu    $a0, $s2, $zero
/* CF9674 80241B04 8FBF001C */  lw        $ra, 0x1c($sp)
/* CF9678 80241B08 8FB20018 */  lw        $s2, 0x18($sp)
/* CF967C 80241B0C 8FB10014 */  lw        $s1, 0x14($sp)
/* CF9680 80241B10 8FB00010 */  lw        $s0, 0x10($sp)
/* CF9684 80241B14 24020002 */  addiu     $v0, $zero, 2
/* CF9688 80241B18 03E00008 */  jr        $ra
/* CF968C 80241B1C 27BD0020 */   addiu    $sp, $sp, 0x20
