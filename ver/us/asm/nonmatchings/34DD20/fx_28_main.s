.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_28_main
/* 34DD20 E0038000 27BDFF38 */  addiu     $sp, $sp, -0xc8
/* 34DD24 E0038004 F7BE00C0 */  sdc1      $f30, 0xc0($sp)
/* 34DD28 E0038008 4485F000 */  mtc1      $a1, $f30
/* 34DD2C E003800C F7B600A0 */  sdc1      $f22, 0xa0($sp)
/* 34DD30 E0038010 4480B000 */  mtc1      $zero, $f22
/* 34DD34 E0038014 3C013F80 */  lui       $at, 0x3f80
/* 34DD38 E0038018 44816000 */  mtc1      $at, $f12
/* 34DD3C E003801C F7B800A8 */  sdc1      $f24, 0xa8($sp)
/* 34DD40 E0038020 3C01BF80 */  lui       $at, 0xbf80
/* 34DD44 E0038024 4481C000 */  mtc1      $at, $f24
/* 34DD48 E0038028 AFBF0094 */  sw        $ra, 0x94($sp)
/* 34DD4C E003802C AFBE0090 */  sw        $fp, 0x90($sp)
/* 34DD50 E0038030 AFB7008C */  sw        $s7, 0x8c($sp)
/* 34DD54 E0038034 AFB60088 */  sw        $s6, 0x88($sp)
/* 34DD58 E0038038 AFB50084 */  sw        $s5, 0x84($sp)
/* 34DD5C E003803C AFB40080 */  sw        $s4, 0x80($sp)
/* 34DD60 E0038040 AFB3007C */  sw        $s3, 0x7c($sp)
/* 34DD64 E0038044 AFB20078 */  sw        $s2, 0x78($sp)
/* 34DD68 E0038048 AFB10074 */  sw        $s1, 0x74($sp)
/* 34DD6C E003804C AFB00070 */  sw        $s0, 0x70($sp)
/* 34DD70 E0038050 F7BC00B8 */  sdc1      $f28, 0xb8($sp)
/* 34DD74 E0038054 F7BA00B0 */  sdc1      $f26, 0xb0($sp)
/* 34DD78 E0038058 F7B40098 */  sdc1      $f20, 0x98($sp)
/* 34DD7C E003805C AFA400C8 */  sw        $a0, 0xc8($sp)
/* 34DD80 E0038060 AFA600D0 */  sw        $a2, 0xd0($sp)
/* 34DD84 E0038064 AFA700D4 */  sw        $a3, 0xd4($sp)
/* 34DD88 E0038068 0C080154 */  jal       func_E0200550
/* 34DD8C E003806C 46006706 */   mov.s    $f28, $f12
/* 34DD90 E0038070 4600C303 */  div.s     $f12, $f24, $f0
/* 34DD94 E0038074 46166682 */  mul.s     $f26, $f12, $f22
/* 34DD98 E0038078 00000000 */  nop
/* 34DD9C E003807C 4600B506 */  mov.s     $f20, $f22
/* 34DDA0 E0038080 27B00018 */  addiu     $s0, $sp, 0x18
/* 34DDA4 E0038084 24150005 */  addiu     $s5, $zero, 5
/* 34DDA8 E0038088 4600D586 */  mov.s     $f22, $f26
/* 34DDAC E003808C 4614B032 */  c.eq.s    $f22, $f20
/* 34DDB0 E0038090 00000000 */  nop
/* 34DDB4 E0038094 45010005 */  bc1t      .LE00380AC
/* 34DDB8 E0038098 46006607 */   neg.s    $f24, $f12
/* 34DDBC E003809C 46166003 */  div.s     $f0, $f12, $f22
/* 34DDC0 E00380A0 4600E086 */  mov.s     $f2, $f28
/* 34DDC4 E00380A4 0800E036 */  j         .LE00380D8
/* 34DDC8 E00380A8 4600A106 */   mov.s    $f4, $f20
.LE00380AC:
/* 34DDCC E00380AC 4614C032 */  c.eq.s    $f24, $f20
/* 34DDD0 E00380B0 00000000 */  nop
/* 34DDD4 E00380B4 45010005 */  bc1t      .LE00380CC
/* 34DDD8 E00380B8 4600B007 */   neg.s    $f0, $f22
/* 34DDDC E00380BC 46180083 */  div.s     $f2, $f0, $f24
/* 34DDE0 E00380C0 4600E006 */  mov.s     $f0, $f28
/* 34DDE4 E00380C4 0800E036 */  j         .LE00380D8
/* 34DDE8 E00380C8 4600A106 */   mov.s    $f4, $f20
.LE00380CC:
/* 34DDEC E00380CC 46160103 */  div.s     $f4, $f0, $f22
/* 34DDF0 E00380D0 4600A086 */  mov.s     $f2, $f20
/* 34DDF4 E00380D4 4600E006 */  mov.s     $f0, $f28
.LE00380D8:
/* 34DDF8 E00380D8 46000002 */  mul.s     $f0, $f0, $f0
/* 34DDFC E00380DC 00000000 */  nop
/* 34DE00 E00380E0 46021082 */  mul.s     $f2, $f2, $f2
/* 34DE04 E00380E4 00000000 */  nop
/* 34DE08 E00380E8 46042102 */  mul.s     $f4, $f4, $f4
/* 34DE0C E00380EC 00000000 */  nop
/* 34DE10 E00380F0 46020000 */  add.s     $f0, $f0, $f2
/* 34DE14 E00380F4 46040300 */  add.s     $f12, $f0, $f4
/* 34DE18 E00380F8 44800000 */  mtc1      $zero, $f0
/* 34DE1C E00380FC 00000000 */  nop
/* 34DE20 E0038100 46006032 */  c.eq.s    $f12, $f0
/* 34DE24 E0038104 00000000 */  nop
/* 34DE28 E0038108 450100B2 */  bc1t      .LE00383D4
/* 34DE2C E003810C 00000000 */   nop
/* 34DE30 E0038110 0C080154 */  jal       func_E0200550
/* 34DE34 E0038114 00000000 */   nop
/* 34DE38 E0038118 0200202D */  daddu     $a0, $s0, $zero
/* 34DE3C E003811C 3C014190 */  lui       $at, 0x4190
/* 34DE40 E0038120 44810000 */  mtc1      $at, $f0
/* 34DE44 E0038124 3C02E004 */  lui       $v0, %hi(func_E003841C)
/* 34DE48 E0038128 2442841C */  addiu     $v0, $v0, %lo(func_E003841C)
/* 34DE4C E003812C AC820008 */  sw        $v0, 8($a0)
/* 34DE50 E0038130 4600D682 */  mul.s     $f26, $f26, $f0
/* 34DE54 E0038134 00000000 */  nop
/* 34DE58 E0038138 3C02E004 */  lui       $v0, %hi(func_E0038424)
/* 34DE5C E003813C 24428424 */  addiu     $v0, $v0, %lo(func_E0038424)
/* 34DE60 E0038140 AC82000C */  sw        $v0, 0xc($a0)
/* 34DE64 E0038144 3C02E004 */  lui       $v0, %hi(func_E0038704)
/* 34DE68 E0038148 24428704 */  addiu     $v0, $v0, %lo(func_E0038704)
/* 34DE6C E003814C AC820010 */  sw        $v0, 0x10($a0)
/* 34DE70 E0038150 4600C602 */  mul.s     $f24, $f24, $f0
/* 34DE74 E0038154 00000000 */  nop
/* 34DE78 E0038158 2402001C */  addiu     $v0, $zero, 0x1c
/* 34DE7C E003815C AC800000 */  sw        $zero, ($a0)
/* 34DE80 E0038160 AC800014 */  sw        $zero, 0x14($a0)
/* 34DE84 E0038164 4600B582 */  mul.s     $f22, $f22, $f0
/* 34DE88 E0038168 00000000 */  nop
/* 34DE8C E003816C 0C080124 */  jal       func_E0200490
/* 34DE90 E0038170 AC820004 */   sw       $v0, 4($a0)
/* 34DE94 E0038174 00152040 */  sll       $a0, $s5, 1
/* 34DE98 E0038178 00952021 */  addu      $a0, $a0, $s5
/* 34DE9C E003817C 00042100 */  sll       $a0, $a0, 4
/* 34DEA0 E0038180 0040802D */  daddu     $s0, $v0, $zero
/* 34DEA4 E0038184 0C08012C */  jal       func_E02004B0
/* 34DEA8 E0038188 AE150008 */   sw       $s5, 8($s0)
/* 34DEAC E003818C 0040902D */  daddu     $s2, $v0, $zero
/* 34DEB0 E0038190 16400003 */  bnez      $s2, .LE00381A0
/* 34DEB4 E0038194 AE12000C */   sw       $s2, 0xc($s0)
.LE0038198:
/* 34DEB8 E0038198 0800E066 */  j         .LE0038198
/* 34DEBC E003819C 00000000 */   nop
.LE00381A0:
/* 34DEC0 E00381A0 12A0008C */  beqz      $s5, .LE00383D4
/* 34DEC4 E00381A4 0000A02D */   daddu    $s4, $zero, $zero
/* 34DEC8 E00381A8 3C17800B */  lui       $s7, %hi(gCameras)
/* 34DECC E00381AC 26F71D80 */  addiu     $s7, $s7, %lo(gCameras)
/* 34DED0 E00381B0 3C168007 */  lui       $s6, %hi(gCurrentCameraID)
/* 34DED4 E00381B4 26D67410 */  addiu     $s6, $s6, %lo(gCurrentCameraID)
/* 34DED8 E00381B8 27BE0030 */  addiu     $fp, $sp, 0x30
/* 34DEDC E00381BC 26B3FFFF */  addiu     $s3, $s5, -1
/* 34DEE0 E00381C0 3C01E004 */  lui       $at, %hi(D_E0038A20)
/* 34DEE4 E00381C4 D43C8A20 */  ldc1      $f28, %lo(D_E0038A20)($at)
/* 34DEE8 E00381C8 26500024 */  addiu     $s0, $s2, 0x24
/* 34DEEC E00381CC 0280882D */  daddu     $s1, $s4, $zero
.LE00381D0:
/* 34DEF0 E00381D0 8EC30000 */  lw        $v1, ($s6)
/* 34DEF4 E00381D4 8FA800C8 */  lw        $t0, 0xc8($sp)
/* 34DEF8 E00381D8 00031080 */  sll       $v0, $v1, 2
/* 34DEFC E00381DC 00431021 */  addu      $v0, $v0, $v1
/* 34DF00 E00381E0 00021080 */  sll       $v0, $v0, 2
/* 34DF04 E00381E4 00431023 */  subu      $v0, $v0, $v1
/* 34DF08 E00381E8 000218C0 */  sll       $v1, $v0, 3
/* 34DF0C E00381EC 00431021 */  addu      $v0, $v0, $v1
/* 34DF10 E00381F0 AE480000 */  sw        $t0, ($s2)
/* 34DF14 E00381F4 E61EFFE0 */  swc1      $f30, -0x20($s0)
/* 34DF18 E00381F8 C7A600D0 */  lwc1      $f6, 0xd0($sp)
/* 34DF1C E00381FC 000210C0 */  sll       $v0, $v0, 3
/* 34DF20 E0038200 E606FFE4 */  swc1      $f6, -0x1c($s0)
/* 34DF24 E0038204 C7A600D4 */  lwc1      $f6, 0xd4($sp)
/* 34DF28 E0038208 00571021 */  addu      $v0, $v0, $s7
/* 34DF2C E003820C E606FFE8 */  swc1      $f6, -0x18($s0)
/* 34DF30 E0038210 0C080140 */  jal       func_E0200500
/* 34DF34 E0038214 C44C006C */   lwc1     $f12, 0x6c($v0)
/* 34DF38 E0038218 8EC30000 */  lw        $v1, ($s6)
/* 34DF3C E003821C 00031080 */  sll       $v0, $v1, 2
/* 34DF40 E0038220 00431021 */  addu      $v0, $v0, $v1
/* 34DF44 E0038224 00021080 */  sll       $v0, $v0, 2
/* 34DF48 E0038228 00431023 */  subu      $v0, $v0, $v1
/* 34DF4C E003822C 000218C0 */  sll       $v1, $v0, 3
/* 34DF50 E0038230 00431021 */  addu      $v0, $v0, $v1
/* 34DF54 E0038234 000210C0 */  sll       $v0, $v0, 3
/* 34DF58 E0038238 00571021 */  addu      $v0, $v0, $s7
/* 34DF5C E003823C C44C006C */  lwc1      $f12, 0x6c($v0)
/* 34DF60 E0038240 0C080144 */  jal       func_E0200510
/* 34DF64 E0038244 46000506 */   mov.s    $f20, $f0
/* 34DF68 E0038248 24020001 */  addiu     $v0, $zero, 1
/* 34DF6C E003824C 12A20011 */  beq       $s5, $v0, .LE0038294
/* 34DF70 E0038250 46000007 */   neg.s    $f0, $f0
/* 34DF74 E0038254 16600002 */  bnez      $s3, .LE0038260
/* 34DF78 E0038258 0233001A */   div      $zero, $s1, $s3
/* 34DF7C E003825C 0007000D */  break     7
.LE0038260:
/* 34DF80 E0038260 2401FFFF */   addiu    $at, $zero, -1
/* 34DF84 E0038264 16610004 */  bne       $s3, $at, .LE0038278
/* 34DF88 E0038268 3C018000 */   lui      $at, 0x8000
/* 34DF8C E003826C 16210002 */  bne       $s1, $at, .LE0038278
/* 34DF90 E0038270 00000000 */   nop
/* 34DF94 E0038274 0006000D */  break     6
.LE0038278:
/* 34DF98 E0038278 00001012 */   mflo     $v0
/* 34DF9C E003827C 2442FFCE */  addiu     $v0, $v0, -0x32
/* 34DFA0 E0038280 44821000 */  mtc1      $v0, $f2
/* 34DFA4 E0038284 00000000 */  nop
/* 34DFA8 E0038288 468010A0 */  cvt.s.w   $f2, $f2
/* 34DFAC E003828C 0800E0A7 */  j         .LE003829C
/* 34DFB0 E0038290 03C0202D */   daddu    $a0, $fp, $zero
.LE0038294:
/* 34DFB4 E0038294 44801000 */  mtc1      $zero, $f2
/* 34DFB8 E0038298 03C0202D */  daddu     $a0, $fp, $zero
.LE003829C:
/* 34DFBC E003829C 44051000 */  mfc1      $a1, $f2
/* 34DFC0 E00382A0 4406A000 */  mfc1      $a2, $f20
/* 34DFC4 E00382A4 0000382D */  daddu     $a3, $zero, $zero
/* 34DFC8 E00382A8 0C080104 */  jal       func_E0200410
/* 34DFCC E00382AC E7A00010 */   swc1     $f0, 0x10($sp)
/* 34DFD0 E00382B0 16600002 */  bnez      $s3, .LE00382BC
/* 34DFD4 E00382B4 0233001A */   div      $zero, $s1, $s3
/* 34DFD8 E00382B8 0007000D */  break     7
.LE00382BC:
/* 34DFDC E00382BC 2401FFFF */   addiu    $at, $zero, -1
/* 34DFE0 E00382C0 16610004 */  bne       $s3, $at, .LE00382D4
/* 34DFE4 E00382C4 3C018000 */   lui      $at, 0x8000
/* 34DFE8 E00382C8 16210002 */  bne       $s1, $at, .LE00382D4
/* 34DFEC E00382CC 00000000 */   nop
/* 34DFF0 E00382D0 0006000D */  break     6
.LE00382D4:
/* 34DFF4 E00382D4 00001812 */   mflo     $v1
/* 34DFF8 E00382D8 C7A00030 */  lwc1      $f0, 0x30($sp)
/* 34DFFC E00382DC 461A0002 */  mul.s     $f0, $f0, $f26
/* 34E000 E00382E0 00000000 */  nop
/* 34E004 E00382E4 C7A40040 */  lwc1      $f4, 0x40($sp)
/* 34E008 E00382E8 46182102 */  mul.s     $f4, $f4, $f24
/* 34E00C E00382EC 00000000 */  nop
/* 34E010 E00382F0 C7A20050 */  lwc1      $f2, 0x50($sp)
/* 34E014 E00382F4 46161082 */  mul.s     $f2, $f2, $f22
/* 34E018 E00382F8 00000000 */  nop
/* 34E01C E00382FC 46040000 */  add.s     $f0, $f0, $f4
/* 34E020 E0038300 46020000 */  add.s     $f0, $f0, $f2
/* 34E024 E0038304 46000021 */  cvt.d.s   $f0, $f0
/* 34E028 E0038308 463C0002 */  mul.d     $f0, $f0, $f28
/* 34E02C E003830C 00000000 */  nop
/* 34E030 E0038310 46200020 */  cvt.s.d   $f0, $f0
/* 34E034 E0038314 E600FFEC */  swc1      $f0, -0x14($s0)
/* 34E038 E0038318 C7A00034 */  lwc1      $f0, 0x34($sp)
/* 34E03C E003831C 461A0002 */  mul.s     $f0, $f0, $f26
/* 34E040 E0038320 00000000 */  nop
/* 34E044 E0038324 C7A40044 */  lwc1      $f4, 0x44($sp)
/* 34E048 E0038328 46182102 */  mul.s     $f4, $f4, $f24
/* 34E04C E003832C 00000000 */  nop
/* 34E050 E0038330 C7A20054 */  lwc1      $f2, 0x54($sp)
/* 34E054 E0038334 46161082 */  mul.s     $f2, $f2, $f22
/* 34E058 E0038338 00000000 */  nop
/* 34E05C E003833C 46040000 */  add.s     $f0, $f0, $f4
/* 34E060 E0038340 46020000 */  add.s     $f0, $f0, $f2
/* 34E064 E0038344 E600FFF0 */  swc1      $f0, -0x10($s0)
/* 34E068 E0038348 C7A00038 */  lwc1      $f0, 0x38($sp)
/* 34E06C E003834C 461A0002 */  mul.s     $f0, $f0, $f26
/* 34E070 E0038350 00000000 */  nop
/* 34E074 E0038354 C7A20048 */  lwc1      $f2, 0x48($sp)
/* 34E078 E0038358 46181082 */  mul.s     $f2, $f2, $f24
/* 34E07C E003835C 00000000 */  nop
/* 34E080 E0038360 C7A40058 */  lwc1      $f4, 0x58($sp)
/* 34E084 E0038364 46162102 */  mul.s     $f4, $f4, $f22
/* 34E088 E0038368 00000000 */  nop
/* 34E08C E003836C 26940001 */  addiu     $s4, $s4, 1
/* 34E090 E0038370 26520030 */  addiu     $s2, $s2, 0x30
/* 34E094 E0038374 26310064 */  addiu     $s1, $s1, 0x64
/* 34E098 E0038378 46020000 */  add.s     $f0, $f0, $f2
/* 34E09C E003837C 24020032 */  addiu     $v0, $zero, 0x32
/* 34E0A0 E0038380 3C013F00 */  lui       $at, 0x3f00
/* 34E0A4 E0038384 44811000 */  mtc1      $at, $f2
/* 34E0A8 E0038388 46040000 */  add.s     $f0, $f0, $f4
/* 34E0AC E003838C E602FFFC */  swc1      $f2, -4($s0)
/* 34E0B0 E0038390 8FA800D8 */  lw        $t0, 0xd8($sp)
/* 34E0B4 E0038394 46000021 */  cvt.d.s   $f0, $f0
/* 34E0B8 E0038398 463C0002 */  mul.d     $f0, $f0, $f28
/* 34E0BC E003839C 00000000 */  nop
/* 34E0C0 E00383A0 AE000008 */  sw        $zero, 8($s0)
/* 34E0C4 E00383A4 AE000000 */  sw        $zero, ($s0)
/* 34E0C8 E00383A8 AE080004 */  sw        $t0, 4($s0)
/* 34E0CC E00383AC 00431023 */  subu      $v0, $v0, $v1
/* 34E0D0 E00383B0 44821000 */  mtc1      $v0, $f2
/* 34E0D4 E00383B4 00000000 */  nop
/* 34E0D8 E00383B8 468010A0 */  cvt.s.w   $f2, $f2
/* 34E0DC E00383BC 0295102A */  slt       $v0, $s4, $s5
/* 34E0E0 E00383C0 E602FFF8 */  swc1      $f2, -8($s0)
/* 34E0E4 E00383C4 46200020 */  cvt.s.d   $f0, $f0
/* 34E0E8 E00383C8 E600FFF4 */  swc1      $f0, -0xc($s0)
/* 34E0EC E00383CC 1440FF80 */  bnez      $v0, .LE00381D0
/* 34E0F0 E00383D0 26100030 */   addiu    $s0, $s0, 0x30
.LE00383D4:
/* 34E0F4 E00383D4 8FBF0094 */  lw        $ra, 0x94($sp)
/* 34E0F8 E00383D8 8FBE0090 */  lw        $fp, 0x90($sp)
/* 34E0FC E00383DC 8FB7008C */  lw        $s7, 0x8c($sp)
/* 34E100 E00383E0 8FB60088 */  lw        $s6, 0x88($sp)
/* 34E104 E00383E4 8FB50084 */  lw        $s5, 0x84($sp)
/* 34E108 E00383E8 8FB40080 */  lw        $s4, 0x80($sp)
/* 34E10C E00383EC 8FB3007C */  lw        $s3, 0x7c($sp)
/* 34E110 E00383F0 8FB20078 */  lw        $s2, 0x78($sp)
/* 34E114 E00383F4 8FB10074 */  lw        $s1, 0x74($sp)
/* 34E118 E00383F8 8FB00070 */  lw        $s0, 0x70($sp)
/* 34E11C E00383FC D7BE00C0 */  ldc1      $f30, 0xc0($sp)
/* 34E120 E0038400 D7BC00B8 */  ldc1      $f28, 0xb8($sp)
/* 34E124 E0038404 D7BA00B0 */  ldc1      $f26, 0xb0($sp)
/* 34E128 E0038408 D7B800A8 */  ldc1      $f24, 0xa8($sp)
/* 34E12C E003840C D7B600A0 */  ldc1      $f22, 0xa0($sp)
/* 34E130 E0038410 D7B40098 */  ldc1      $f20, 0x98($sp)
/* 34E134 E0038414 03E00008 */  jr        $ra
/* 34E138 E0038418 27BD00C8 */   addiu    $sp, $sp, 0xc8
