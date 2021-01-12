.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8021818C_48D32C
/* 48D32C 8021818C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 48D330 80218190 AFB40020 */  sw        $s4, 0x20($sp)
/* 48D334 80218194 0080A02D */  daddu     $s4, $a0, $zero
/* 48D338 80218198 AFBF0024 */  sw        $ra, 0x24($sp)
/* 48D33C 8021819C AFB3001C */  sw        $s3, 0x1c($sp)
/* 48D340 802181A0 AFB20018 */  sw        $s2, 0x18($sp)
/* 48D344 802181A4 AFB10014 */  sw        $s1, 0x14($sp)
/* 48D348 802181A8 AFB00010 */  sw        $s0, 0x10($sp)
/* 48D34C 802181AC 8E92000C */  lw        $s2, 0xc($s4)
/* 48D350 802181B0 8E450000 */  lw        $a1, ($s2)
/* 48D354 802181B4 0C0B1EAF */  jal       get_variable
/* 48D358 802181B8 26520004 */   addiu    $s2, $s2, 4
/* 48D35C 802181BC 8E450000 */  lw        $a1, ($s2)
/* 48D360 802181C0 26520004 */  addiu     $s2, $s2, 4
/* 48D364 802181C4 0280202D */  daddu     $a0, $s4, $zero
/* 48D368 802181C8 0C0B1EAF */  jal       get_variable
/* 48D36C 802181CC 0040802D */   daddu    $s0, $v0, $zero
/* 48D370 802181D0 8E450000 */  lw        $a1, ($s2)
/* 48D374 802181D4 26520004 */  addiu     $s2, $s2, 4
/* 48D378 802181D8 0280202D */  daddu     $a0, $s4, $zero
/* 48D37C 802181DC 0C0B1EAF */  jal       get_variable
/* 48D380 802181E0 0040882D */   daddu    $s1, $v0, $zero
/* 48D384 802181E4 0040982D */  daddu     $s3, $v0, $zero
/* 48D388 802181E8 8E450000 */  lw        $a1, ($s2)
/* 48D38C 802181EC 26520004 */  addiu     $s2, $s2, 4
/* 48D390 802181F0 0280202D */  daddu     $a0, $s4, $zero
/* 48D394 802181F4 0C0B1EAF */  jal       get_variable
/* 48D398 802181F8 02709823 */   subu     $s3, $s3, $s0
/* 48D39C 802181FC 0040802D */  daddu     $s0, $v0, $zero
/* 48D3A0 80218200 0280202D */  daddu     $a0, $s4, $zero
/* 48D3A4 80218204 8E450000 */  lw        $a1, ($s2)
/* 48D3A8 80218208 0C0B1EAF */  jal       get_variable
/* 48D3AC 8021820C 02118023 */   subu     $s0, $s0, $s1
/* 48D3B0 80218210 16600006 */  bnez      $s3, .L8021822C
/* 48D3B4 80218214 00000000 */   nop
/* 48D3B8 80218218 16000004 */  bnez      $s0, .L8021822C
/* 48D3BC 8021821C 0280202D */   daddu    $a0, $s4, $zero
/* 48D3C0 80218220 8E450000 */  lw        $a1, ($s2)
/* 48D3C4 80218224 08086095 */  j         .L80218254
/* 48D3C8 80218228 0040302D */   daddu    $a2, $v0, $zero
.L8021822C:
/* 48D3CC 8021822C 44936000 */  mtc1      $s3, $f12
/* 48D3D0 80218230 00000000 */  nop
/* 48D3D4 80218234 46806320 */  cvt.s.w   $f12, $f12
/* 48D3D8 80218238 44907000 */  mtc1      $s0, $f14
/* 48D3DC 8021823C 00000000 */  nop
/* 48D3E0 80218240 0C086000 */  jal       func_80218000_48D1A0
/* 48D3E4 80218244 468073A0 */   cvt.s.w  $f14, $f14
/* 48D3E8 80218248 0280202D */  daddu     $a0, $s4, $zero
/* 48D3EC 8021824C 8E450000 */  lw        $a1, ($s2)
/* 48D3F0 80218250 2446FFA6 */  addiu     $a2, $v0, -0x5a
.L80218254:
/* 48D3F4 80218254 0C0B2026 */  jal       set_variable
/* 48D3F8 80218258 00000000 */   nop
/* 48D3FC 8021825C 24020002 */  addiu     $v0, $zero, 2
/* 48D400 80218260 8FBF0024 */  lw        $ra, 0x24($sp)
/* 48D404 80218264 8FB40020 */  lw        $s4, 0x20($sp)
/* 48D408 80218268 8FB3001C */  lw        $s3, 0x1c($sp)
/* 48D40C 8021826C 8FB20018 */  lw        $s2, 0x18($sp)
/* 48D410 80218270 8FB10014 */  lw        $s1, 0x14($sp)
/* 48D414 80218274 8FB00010 */  lw        $s0, 0x10($sp)
/* 48D418 80218278 03E00008 */  jr        $ra
/* 48D41C 8021827C 27BD0028 */   addiu    $sp, $sp, 0x28
