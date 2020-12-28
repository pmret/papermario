.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218180_6DBF20
/* 6DBF20 80218180 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 6DBF24 80218184 AFB20018 */  sw        $s2, 0x18($sp)
/* 6DBF28 80218188 0080902D */  daddu     $s2, $a0, $zero
/* 6DBF2C 8021818C AFBF001C */  sw        $ra, 0x1c($sp)
/* 6DBF30 80218190 AFB10014 */  sw        $s1, 0x14($sp)
/* 6DBF34 80218194 AFB00010 */  sw        $s0, 0x10($sp)
/* 6DBF38 80218198 8E50000C */  lw        $s0, 0xc($s2)
/* 6DBF3C 8021819C 8E050000 */  lw        $a1, ($s0)
/* 6DBF40 802181A0 0C0B1EAF */  jal       get_variable
/* 6DBF44 802181A4 26100004 */   addiu    $s0, $s0, 4
/* 6DBF48 802181A8 0C04417A */  jal       get_entity_by_index
/* 6DBF4C 802181AC 0040202D */   daddu    $a0, $v0, $zero
/* 6DBF50 802181B0 8E050000 */  lw        $a1, ($s0)
/* 6DBF54 802181B4 26100004 */  addiu     $s0, $s0, 4
/* 6DBF58 802181B8 0040882D */  daddu     $s1, $v0, $zero
/* 6DBF5C 802181BC C6200048 */  lwc1      $f0, 0x48($s1)
/* 6DBF60 802181C0 4600008D */  trunc.w.s $f2, $f0
/* 6DBF64 802181C4 44061000 */  mfc1      $a2, $f2
/* 6DBF68 802181C8 0C0B2026 */  jal       set_variable
/* 6DBF6C 802181CC 0240202D */   daddu    $a0, $s2, $zero
/* 6DBF70 802181D0 8E050000 */  lw        $a1, ($s0)
/* 6DBF74 802181D4 26100004 */  addiu     $s0, $s0, 4
/* 6DBF78 802181D8 C620004C */  lwc1      $f0, 0x4c($s1)
/* 6DBF7C 802181DC 4600008D */  trunc.w.s $f2, $f0
/* 6DBF80 802181E0 44061000 */  mfc1      $a2, $f2
/* 6DBF84 802181E4 0C0B2026 */  jal       set_variable
/* 6DBF88 802181E8 0240202D */   daddu    $a0, $s2, $zero
/* 6DBF8C 802181EC C6200050 */  lwc1      $f0, 0x50($s1)
/* 6DBF90 802181F0 8E050000 */  lw        $a1, ($s0)
/* 6DBF94 802181F4 4600008D */  trunc.w.s $f2, $f0
/* 6DBF98 802181F8 44061000 */  mfc1      $a2, $f2
/* 6DBF9C 802181FC 0C0B2026 */  jal       set_variable
/* 6DBFA0 80218200 0240202D */   daddu    $a0, $s2, $zero
/* 6DBFA4 80218204 8FBF001C */  lw        $ra, 0x1c($sp)
/* 6DBFA8 80218208 8FB20018 */  lw        $s2, 0x18($sp)
/* 6DBFAC 8021820C 8FB10014 */  lw        $s1, 0x14($sp)
/* 6DBFB0 80218210 8FB00010 */  lw        $s0, 0x10($sp)
/* 6DBFB4 80218214 24020002 */  addiu     $v0, $zero, 2
/* 6DBFB8 80218218 03E00008 */  jr        $ra
/* 6DBFBC 8021821C 27BD0020 */   addiu    $sp, $sp, 0x20
