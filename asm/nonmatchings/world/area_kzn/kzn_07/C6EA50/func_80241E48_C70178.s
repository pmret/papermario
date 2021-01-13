.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241E48_C70178
/* C70178 80241E48 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* C7017C 80241E4C AFB3004C */  sw        $s3, 0x4c($sp)
/* C70180 80241E50 0080982D */  daddu     $s3, $a0, $zero
/* C70184 80241E54 AFBF0050 */  sw        $ra, 0x50($sp)
/* C70188 80241E58 AFB20048 */  sw        $s2, 0x48($sp)
/* C7018C 80241E5C AFB10044 */  sw        $s1, 0x44($sp)
/* C70190 80241E60 AFB00040 */  sw        $s0, 0x40($sp)
/* C70194 80241E64 8E720148 */  lw        $s2, 0x148($s3)
/* C70198 80241E68 00A0882D */  daddu     $s1, $a1, $zero
/* C7019C 80241E6C 86440008 */  lh        $a0, 8($s2)
/* C701A0 80241E70 0C00EABB */  jal       get_npc_unsafe
/* C701A4 80241E74 00C0802D */   daddu    $s0, $a2, $zero
/* C701A8 80241E78 0200202D */  daddu     $a0, $s0, $zero
/* C701AC 80241E7C 0240282D */  daddu     $a1, $s2, $zero
/* C701B0 80241E80 24030001 */  addiu     $v1, $zero, 1
/* C701B4 80241E84 AFA30010 */  sw        $v1, 0x10($sp)
/* C701B8 80241E88 8E260024 */  lw        $a2, 0x24($s1)
/* C701BC 80241E8C 8E270028 */  lw        $a3, 0x28($s1)
/* C701C0 80241E90 0C01242D */  jal       func_800490B4
/* C701C4 80241E94 0040802D */   daddu    $s0, $v0, $zero
/* C701C8 80241E98 14400020 */  bnez      $v0, .L80241F1C
/* C701CC 80241E9C 24040002 */   addiu    $a0, $zero, 2
/* C701D0 80241EA0 0200282D */  daddu     $a1, $s0, $zero
/* C701D4 80241EA4 0000302D */  daddu     $a2, $zero, $zero
/* C701D8 80241EA8 860300A8 */  lh        $v1, 0xa8($s0)
/* C701DC 80241EAC 3C013F80 */  lui       $at, 0x3f80
/* C701E0 80241EB0 44810000 */  mtc1      $at, $f0
/* C701E4 80241EB4 3C014000 */  lui       $at, 0x4000
/* C701E8 80241EB8 44811000 */  mtc1      $at, $f2
/* C701EC 80241EBC 3C01C1A0 */  lui       $at, 0xc1a0
/* C701F0 80241EC0 44812000 */  mtc1      $at, $f4
/* C701F4 80241EC4 2402000F */  addiu     $v0, $zero, 0xf
/* C701F8 80241EC8 AFA2001C */  sw        $v0, 0x1c($sp)
/* C701FC 80241ECC 44834000 */  mtc1      $v1, $f8
/* C70200 80241ED0 00000000 */  nop
/* C70204 80241ED4 46804220 */  cvt.s.w   $f8, $f8
/* C70208 80241ED8 44074000 */  mfc1      $a3, $f8
/* C7020C 80241EDC 27A20028 */  addiu     $v0, $sp, 0x28
/* C70210 80241EE0 AFA20020 */  sw        $v0, 0x20($sp)
/* C70214 80241EE4 E7A00010 */  swc1      $f0, 0x10($sp)
/* C70218 80241EE8 E7A20014 */  swc1      $f2, 0x14($sp)
/* C7021C 80241EEC 0C01BFA4 */  jal       fx_emote
/* C70220 80241EF0 E7A40018 */   swc1     $f4, 0x18($sp)
/* C70224 80241EF4 8E4200CC */  lw        $v0, 0xcc($s2)
/* C70228 80241EF8 8C430000 */  lw        $v1, ($v0)
/* C7022C 80241EFC 2402001E */  addiu     $v0, $zero, 0x1e
/* C70230 80241F00 A602008E */  sh        $v0, 0x8e($s0)
/* C70234 80241F04 24020014 */  addiu     $v0, $zero, 0x14
/* C70238 80241F08 AE030028 */  sw        $v1, 0x28($s0)
/* C7023C 80241F0C AE620070 */  sw        $v0, 0x70($s3)
/* C70240 80241F10 2402001E */  addiu     $v0, $zero, 0x1e
/* C70244 80241F14 0809082B */  j         .L802420AC
/* C70248 80241F18 AE420090 */   sw       $v0, 0x90($s2)
.L80241F1C:
/* C7024C 80241F1C 8E050018 */  lw        $a1, 0x18($s0)
/* C70250 80241F20 8E06000C */  lw        $a2, 0xc($s0)
/* C70254 80241F24 0C00EA95 */  jal       npc_move_heading
/* C70258 80241F28 0200202D */   daddu    $a0, $s0, $zero
/* C7025C 80241F2C 8E020000 */  lw        $v0, ($s0)
/* C70260 80241F30 30420008 */  andi      $v0, $v0, 8
/* C70264 80241F34 14400028 */  bnez      $v0, .L80241FD8
/* C70268 80241F38 0000882D */   daddu    $s1, $zero, $zero
/* C7026C 80241F3C 27A5002C */  addiu     $a1, $sp, 0x2c
/* C70270 80241F40 27A60030 */  addiu     $a2, $sp, 0x30
/* C70274 80241F44 860200A8 */  lh        $v0, 0xa8($s0)
/* C70278 80241F48 C6000038 */  lwc1      $f0, 0x38($s0)
/* C7027C 80241F4C 44821000 */  mtc1      $v0, $f2
/* C70280 80241F50 00000000 */  nop
/* C70284 80241F54 468010A0 */  cvt.s.w   $f2, $f2
/* C70288 80241F58 E7A0002C */  swc1      $f0, 0x2c($sp)
/* C7028C 80241F5C 860200A8 */  lh        $v0, 0xa8($s0)
/* C70290 80241F60 C604003C */  lwc1      $f4, 0x3c($s0)
/* C70294 80241F64 C6060040 */  lwc1      $f6, 0x40($s0)
/* C70298 80241F68 44820000 */  mtc1      $v0, $f0
/* C7029C 80241F6C 00000000 */  nop
/* C702A0 80241F70 46800021 */  cvt.d.w   $f0, $f0
/* C702A4 80241F74 46022100 */  add.s     $f4, $f4, $f2
/* C702A8 80241F78 3C014008 */  lui       $at, 0x4008
/* C702AC 80241F7C 44811800 */  mtc1      $at, $f3
/* C702B0 80241F80 44801000 */  mtc1      $zero, $f2
/* C702B4 80241F84 27A20038 */  addiu     $v0, $sp, 0x38
/* C702B8 80241F88 46220000 */  add.d     $f0, $f0, $f2
/* C702BC 80241F8C E7A60034 */  swc1      $f6, 0x34($sp)
/* C702C0 80241F90 E7A40030 */  swc1      $f4, 0x30($sp)
/* C702C4 80241F94 46200020 */  cvt.s.d   $f0, $f0
/* C702C8 80241F98 E7A00038 */  swc1      $f0, 0x38($sp)
/* C702CC 80241F9C AFA20010 */  sw        $v0, 0x10($sp)
/* C702D0 80241FA0 8E040080 */  lw        $a0, 0x80($s0)
/* C702D4 80241FA4 0C0372DF */  jal       func_800DCB7C
/* C702D8 80241FA8 27A70034 */   addiu    $a3, $sp, 0x34
/* C702DC 80241FAC 1040000A */  beqz      $v0, .L80241FD8
/* C702E0 80241FB0 00000000 */   nop
/* C702E4 80241FB4 860200A8 */  lh        $v0, 0xa8($s0)
/* C702E8 80241FB8 C7A20038 */  lwc1      $f2, 0x38($sp)
/* C702EC 80241FBC 44820000 */  mtc1      $v0, $f0
/* C702F0 80241FC0 00000000 */  nop
/* C702F4 80241FC4 46800020 */  cvt.s.w   $f0, $f0
/* C702F8 80241FC8 4600103C */  c.lt.s    $f2, $f0
/* C702FC 80241FCC 00000000 */  nop
/* C70300 80241FD0 45030001 */  bc1tl     .L80241FD8
/* C70304 80241FD4 24110001 */   addiu    $s1, $zero, 1
.L80241FD8:
/* C70308 80241FD8 12200008 */  beqz      $s1, .L80241FFC
/* C7030C 80241FDC 00000000 */   nop
/* C70310 80241FE0 C7A00030 */  lwc1      $f0, 0x30($sp)
/* C70314 80241FE4 3C013FF0 */  lui       $at, 0x3ff0
/* C70318 80241FE8 44811800 */  mtc1      $at, $f3
/* C7031C 80241FEC 44801000 */  mtc1      $zero, $f2
/* C70320 80241FF0 46000021 */  cvt.d.s   $f0, $f0
/* C70324 80241FF4 08090821 */  j         .L80242084
/* C70328 80241FF8 46220000 */   add.d    $f0, $f0, $f2
.L80241FFC:
/* C7032C 80241FFC 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* C70330 80242000 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* C70334 80242004 3C014018 */  lui       $at, 0x4018
/* C70338 80242008 44811800 */  mtc1      $at, $f3
/* C7033C 8024200C 44801000 */  mtc1      $zero, $f2
/* C70340 80242010 C440002C */  lwc1      $f0, 0x2c($v0)
/* C70344 80242014 C604003C */  lwc1      $f4, 0x3c($s0)
/* C70348 80242018 46000021 */  cvt.d.s   $f0, $f0
/* C7034C 8024201C 46220000 */  add.d     $f0, $f0, $f2
/* C70350 80242020 46002121 */  cvt.d.s   $f4, $f4
/* C70354 80242024 46202001 */  sub.d     $f0, $f4, $f0
/* C70358 80242028 462001A0 */  cvt.s.d   $f6, $f0
/* C7035C 8024202C 44800000 */  mtc1      $zero, $f0
/* C70360 80242030 44800800 */  mtc1      $zero, $f1
/* C70364 80242034 460030A1 */  cvt.d.s   $f2, $f6
/* C70368 80242038 4620103C */  c.lt.d    $f2, $f0
/* C7036C 8024203C 00000000 */  nop
/* C70370 80242040 45010009 */  bc1t      .L80242068
/* C70374 80242044 00000000 */   nop
/* C70378 80242048 3C014010 */  lui       $at, 0x4010
/* C7037C 8024204C 44810800 */  mtc1      $at, $f1
/* C70380 80242050 44800000 */  mtc1      $zero, $f0
/* C70384 80242054 00000000 */  nop
/* C70388 80242058 4622003C */  c.lt.d    $f0, $f2
/* C7038C 8024205C 00000000 */  nop
/* C70390 80242060 4500000A */  bc1f      .L8024208C
/* C70394 80242064 00000000 */   nop
.L80242068:
/* C70398 80242068 3C018024 */  lui       $at, %hi(D_802430E8)
/* C7039C 8024206C D42230E8 */  ldc1      $f2, %lo(D_802430E8)($at)
/* C703A0 80242070 46003187 */  neg.s     $f6, $f6
/* C703A4 80242074 46003021 */  cvt.d.s   $f0, $f6
/* C703A8 80242078 46220002 */  mul.d     $f0, $f0, $f2
/* C703AC 8024207C 00000000 */  nop
/* C703B0 80242080 46202000 */  add.d     $f0, $f4, $f0
.L80242084:
/* C703B4 80242084 46200020 */  cvt.s.d   $f0, $f0
/* C703B8 80242088 E600003C */  swc1      $f0, 0x3c($s0)
.L8024208C:
/* C703BC 8024208C 8602008E */  lh        $v0, 0x8e($s0)
/* C703C0 80242090 9603008E */  lhu       $v1, 0x8e($s0)
/* C703C4 80242094 18400003 */  blez      $v0, .L802420A4
/* C703C8 80242098 2462FFFF */   addiu    $v0, $v1, -1
/* C703CC 8024209C 0809082B */  j         .L802420AC
/* C703D0 802420A0 A602008E */   sh       $v0, 0x8e($s0)
.L802420A4:
/* C703D4 802420A4 2402000C */  addiu     $v0, $zero, 0xc
/* C703D8 802420A8 AE620070 */  sw        $v0, 0x70($s3)
.L802420AC:
/* C703DC 802420AC 8FBF0050 */  lw        $ra, 0x50($sp)
/* C703E0 802420B0 8FB3004C */  lw        $s3, 0x4c($sp)
/* C703E4 802420B4 8FB20048 */  lw        $s2, 0x48($sp)
/* C703E8 802420B8 8FB10044 */  lw        $s1, 0x44($sp)
/* C703EC 802420BC 8FB00040 */  lw        $s0, 0x40($sp)
/* C703F0 802420C0 03E00008 */  jr        $ra
/* C703F4 802420C4 27BD0058 */   addiu    $sp, $sp, 0x58
