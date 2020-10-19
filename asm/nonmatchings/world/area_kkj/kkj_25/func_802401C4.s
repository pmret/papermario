.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802401C4
/* B06BC4 802401C4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B06BC8 802401C8 AFB20018 */  sw        $s2, 0x18($sp)
/* B06BCC 802401CC 0080902D */  daddu     $s2, $a0, $zero
/* B06BD0 802401D0 AFBF001C */  sw        $ra, 0x1c($sp)
/* B06BD4 802401D4 AFB10014 */  sw        $s1, 0x14($sp)
/* B06BD8 802401D8 AFB00010 */  sw        $s0, 0x10($sp)
/* B06BDC 802401DC 8E50000C */  lw        $s0, 0xc($s2)
/* B06BE0 802401E0 8E050000 */  lw        $a1, ($s0)
/* B06BE4 802401E4 0C0B1EAF */  jal       get_variable
/* B06BE8 802401E8 26100004 */   addiu    $s0, $s0, 4
/* B06BEC 802401EC 0C04417A */  jal       get_entity_by_index
/* B06BF0 802401F0 0040202D */   daddu    $a0, $v0, $zero
/* B06BF4 802401F4 8E050000 */  lw        $a1, ($s0)
/* B06BF8 802401F8 26100004 */  addiu     $s0, $s0, 4
/* B06BFC 802401FC 0040882D */  daddu     $s1, $v0, $zero
/* B06C00 80240200 C6200048 */  lwc1      $f0, 0x48($s1)
/* B06C04 80240204 4600008D */  trunc.w.s $f2, $f0
/* B06C08 80240208 44061000 */  mfc1      $a2, $f2
/* B06C0C 8024020C 0C0B2026 */  jal       set_variable
/* B06C10 80240210 0240202D */   daddu    $a0, $s2, $zero
/* B06C14 80240214 8E050000 */  lw        $a1, ($s0)
/* B06C18 80240218 26100004 */  addiu     $s0, $s0, 4
/* B06C1C 8024021C C620004C */  lwc1      $f0, 0x4c($s1)
/* B06C20 80240220 4600008D */  trunc.w.s $f2, $f0
/* B06C24 80240224 44061000 */  mfc1      $a2, $f2
/* B06C28 80240228 0C0B2026 */  jal       set_variable
/* B06C2C 8024022C 0240202D */   daddu    $a0, $s2, $zero
/* B06C30 80240230 C6200050 */  lwc1      $f0, 0x50($s1)
/* B06C34 80240234 8E050000 */  lw        $a1, ($s0)
/* B06C38 80240238 4600008D */  trunc.w.s $f2, $f0
/* B06C3C 8024023C 44061000 */  mfc1      $a2, $f2
/* B06C40 80240240 0C0B2026 */  jal       set_variable
/* B06C44 80240244 0240202D */   daddu    $a0, $s2, $zero
/* B06C48 80240248 8FBF001C */  lw        $ra, 0x1c($sp)
/* B06C4C 8024024C 8FB20018 */  lw        $s2, 0x18($sp)
/* B06C50 80240250 8FB10014 */  lw        $s1, 0x14($sp)
/* B06C54 80240254 8FB00010 */  lw        $s0, 0x10($sp)
/* B06C58 80240258 24020002 */  addiu     $v0, $zero, 2
/* B06C5C 8024025C 03E00008 */  jr        $ra
/* B06C60 80240260 27BD0020 */   addiu    $sp, $sp, 0x20
