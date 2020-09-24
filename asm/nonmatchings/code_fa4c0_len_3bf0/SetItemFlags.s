.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel SetItemFlags
/* FBB44 802D7194 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* FBB48 802D7198 AFB10014 */  sw        $s1, 0x14($sp)
/* FBB4C 802D719C 0080882D */  daddu     $s1, $a0, $zero
/* FBB50 802D71A0 AFBF001C */  sw        $ra, 0x1c($sp)
/* FBB54 802D71A4 AFB20018 */  sw        $s2, 0x18($sp)
/* FBB58 802D71A8 AFB00010 */  sw        $s0, 0x10($sp)
/* FBB5C 802D71AC 8E30000C */  lw        $s0, 0xc($s1)
/* FBB60 802D71B0 8E050000 */  lw        $a1, ($s0)
/* FBB64 802D71B4 0C0B1EAF */  jal       get_variable
/* FBB68 802D71B8 26100004 */   addiu    $s0, $s0, 4
/* FBB6C 802D71BC 0220202D */  daddu     $a0, $s1, $zero
/* FBB70 802D71C0 8E050004 */  lw        $a1, 4($s0)
/* FBB74 802D71C4 8E120000 */  lw        $s2, ($s0)
/* FBB78 802D71C8 0C0B1EAF */  jal       get_variable
/* FBB7C 802D71CC 0040882D */   daddu    $s1, $v0, $zero
/* FBB80 802D71D0 0220202D */  daddu     $a0, $s1, $zero
/* FBB84 802D71D4 0C04C3D6 */  jal       get_item_entity
/* FBB88 802D71D8 0040802D */   daddu    $s0, $v0, $zero
/* FBB8C 802D71DC 12000004 */  beqz      $s0, .L802D71F0
/* FBB90 802D71E0 0040202D */   daddu    $a0, $v0, $zero
/* FBB94 802D71E4 8C820000 */  lw        $v0, ($a0)
/* FBB98 802D71E8 080B5C7F */  j         .L802D71FC
/* FBB9C 802D71EC 00521025 */   or       $v0, $v0, $s2
.L802D71F0:
/* FBBA0 802D71F0 8C820000 */  lw        $v0, ($a0)
/* FBBA4 802D71F4 00121827 */  nor       $v1, $zero, $s2
/* FBBA8 802D71F8 00431024 */  and       $v0, $v0, $v1
.L802D71FC:
/* FBBAC 802D71FC AC820000 */  sw        $v0, ($a0)
/* FBBB0 802D7200 8FBF001C */  lw        $ra, 0x1c($sp)
/* FBBB4 802D7204 8FB20018 */  lw        $s2, 0x18($sp)
/* FBBB8 802D7208 8FB10014 */  lw        $s1, 0x14($sp)
/* FBBBC 802D720C 8FB00010 */  lw        $s0, 0x10($sp)
/* FBBC0 802D7210 24020002 */  addiu     $v0, $zero, 2
/* FBBC4 802D7214 03E00008 */  jr        $ra
/* FBBC8 802D7218 27BD0020 */   addiu    $sp, $sp, 0x20
