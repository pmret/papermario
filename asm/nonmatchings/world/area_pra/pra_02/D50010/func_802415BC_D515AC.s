.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802415BC_D515AC
/* D515AC 802415BC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D515B0 802415C0 AFB20018 */  sw        $s2, 0x18($sp)
/* D515B4 802415C4 0080902D */  daddu     $s2, $a0, $zero
/* D515B8 802415C8 AFBF001C */  sw        $ra, 0x1c($sp)
/* D515BC 802415CC AFB10014 */  sw        $s1, 0x14($sp)
/* D515C0 802415D0 AFB00010 */  sw        $s0, 0x10($sp)
/* D515C4 802415D4 8E50000C */  lw        $s0, 0xc($s2)
/* D515C8 802415D8 8E050000 */  lw        $a1, ($s0)
/* D515CC 802415DC 0C0B1EAF */  jal       get_variable
/* D515D0 802415E0 26100004 */   addiu    $s0, $s0, 4
/* D515D4 802415E4 0C04417A */  jal       get_entity_by_index
/* D515D8 802415E8 0040202D */   daddu    $a0, $v0, $zero
/* D515DC 802415EC 8E050000 */  lw        $a1, ($s0)
/* D515E0 802415F0 26100004 */  addiu     $s0, $s0, 4
/* D515E4 802415F4 0040882D */  daddu     $s1, $v0, $zero
/* D515E8 802415F8 C6200048 */  lwc1      $f0, 0x48($s1)
/* D515EC 802415FC 4600008D */  trunc.w.s $f2, $f0
/* D515F0 80241600 44061000 */  mfc1      $a2, $f2
/* D515F4 80241604 0C0B2026 */  jal       set_variable
/* D515F8 80241608 0240202D */   daddu    $a0, $s2, $zero
/* D515FC 8024160C 8E050000 */  lw        $a1, ($s0)
/* D51600 80241610 26100004 */  addiu     $s0, $s0, 4
/* D51604 80241614 C620004C */  lwc1      $f0, 0x4c($s1)
/* D51608 80241618 4600008D */  trunc.w.s $f2, $f0
/* D5160C 8024161C 44061000 */  mfc1      $a2, $f2
/* D51610 80241620 0C0B2026 */  jal       set_variable
/* D51614 80241624 0240202D */   daddu    $a0, $s2, $zero
/* D51618 80241628 C6200050 */  lwc1      $f0, 0x50($s1)
/* D5161C 8024162C 8E050000 */  lw        $a1, ($s0)
/* D51620 80241630 4600008D */  trunc.w.s $f2, $f0
/* D51624 80241634 44061000 */  mfc1      $a2, $f2
/* D51628 80241638 0C0B2026 */  jal       set_variable
/* D5162C 8024163C 0240202D */   daddu    $a0, $s2, $zero
/* D51630 80241640 8FBF001C */  lw        $ra, 0x1c($sp)
/* D51634 80241644 8FB20018 */  lw        $s2, 0x18($sp)
/* D51638 80241648 8FB10014 */  lw        $s1, 0x14($sp)
/* D5163C 8024164C 8FB00010 */  lw        $s0, 0x10($sp)
/* D51640 80241650 24020002 */  addiu     $v0, $zero, 2
/* D51644 80241654 03E00008 */  jr        $ra
/* D51648 80241658 27BD0020 */   addiu    $sp, $sp, 0x20
/* D5164C 8024165C 00000000 */  nop       
