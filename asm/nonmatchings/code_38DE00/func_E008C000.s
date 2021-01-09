.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E008C000
/* 38DE00 E008C000 27BDFF90 */  addiu     $sp, $sp, -0x70
/* 38DE04 E008C004 AFB00038 */  sw        $s0, 0x38($sp)
/* 38DE08 E008C008 00E0802D */  daddu     $s0, $a3, $zero
/* 38DE0C E008C00C AFA40070 */  sw        $a0, 0x70($sp)
/* 38DE10 E008C010 27A40010 */  addiu     $a0, $sp, 0x10
/* 38DE14 E008C014 F7B40060 */  sdc1      $f20, 0x60($sp)
/* 38DE18 E008C018 4486A000 */  mtc1      $a2, $f20
/* 38DE1C E008C01C 3C02E009 */  lui       $v0, %hi(func_E008C3F4)
/* 38DE20 E008C020 2442C3F4 */  addiu     $v0, $v0, %lo(func_E008C3F4)
/* 38DE24 E008C024 AFA20018 */  sw        $v0, 0x18($sp)
/* 38DE28 E008C028 3C02E009 */  lui       $v0, %hi(func_E008C3FC)
/* 38DE2C E008C02C 2442C3FC */  addiu     $v0, $v0, %lo(func_E008C3FC)
/* 38DE30 E008C030 AFA2001C */  sw        $v0, 0x1c($sp)
/* 38DE34 E008C034 3C02E009 */  lui       $v0, %hi(func_E008C6B8)
/* 38DE38 E008C038 2442C6B8 */  addiu     $v0, $v0, %lo(func_E008C6B8)
/* 38DE3C E008C03C AFA20020 */  sw        $v0, 0x20($sp)
/* 38DE40 E008C040 24020046 */  addiu     $v0, $zero, 0x46
/* 38DE44 E008C044 AFBF005C */  sw        $ra, 0x5c($sp)
/* 38DE48 E008C048 AFBE0058 */  sw        $fp, 0x58($sp)
/* 38DE4C E008C04C AFB70054 */  sw        $s7, 0x54($sp)
/* 38DE50 E008C050 AFB60050 */  sw        $s6, 0x50($sp)
/* 38DE54 E008C054 AFB5004C */  sw        $s5, 0x4c($sp)
/* 38DE58 E008C058 AFB40048 */  sw        $s4, 0x48($sp)
/* 38DE5C E008C05C AFB30044 */  sw        $s3, 0x44($sp)
/* 38DE60 E008C060 AFB20040 */  sw        $s2, 0x40($sp)
/* 38DE64 E008C064 AFB1003C */  sw        $s1, 0x3c($sp)
/* 38DE68 E008C068 F7B60068 */  sdc1      $f22, 0x68($sp)
/* 38DE6C E008C06C AFA50074 */  sw        $a1, 0x74($sp)
/* 38DE70 E008C070 AFA00010 */  sw        $zero, 0x10($sp)
/* 38DE74 E008C074 AFA00024 */  sw        $zero, 0x24($sp)
/* 38DE78 E008C078 0C080124 */  jal       func_E0200490
/* 38DE7C E008C07C AFA20014 */   sw       $v0, 0x14($sp)
/* 38DE80 E008C080 24040168 */  addiu     $a0, $zero, 0x168
/* 38DE84 E008C084 AFA20028 */  sw        $v0, 0x28($sp)
/* 38DE88 E008C088 24080005 */  addiu     $t0, $zero, 5
/* 38DE8C E008C08C 0C08012C */  jal       func_E02004B0
/* 38DE90 E008C090 AC480008 */   sw       $t0, 8($v0)
/* 38DE94 E008C094 8FA90028 */  lw        $t1, 0x28($sp)
/* 38DE98 E008C098 0040202D */  daddu     $a0, $v0, $zero
/* 38DE9C E008C09C 14800003 */  bnez      $a0, .LE008C0AC
/* 38DEA0 E008C0A0 AD24000C */   sw       $a0, 0xc($t1)
.LE008C0A4:
/* 38DEA4 E008C0A4 08023029 */  j         .LE008C0A4
/* 38DEA8 E008C0A8 00000000 */   nop      
.LE008C0AC:
/* 38DEAC E008C0AC 4600A0A1 */  cvt.d.s   $f2, $f20
/* 38DEB0 E008C0B0 24110001 */  addiu     $s1, $zero, 1
/* 38DEB4 E008C0B4 3C01E009 */  lui       $at, %hi(D_E008CB20)
/* 38DEB8 E008C0B8 D420CB20 */  ldc1      $f0, %lo(D_E008CB20)($at)
/* 38DEBC E008C0BC 8FA80070 */  lw        $t0, 0x70($sp)
/* 38DEC0 E008C0C0 46201082 */  mul.d     $f2, $f2, $f0
/* 38DEC4 E008C0C4 00000000 */  nop       
/* 38DEC8 E008C0C8 AC880000 */  sw        $t0, ($a0)
/* 38DECC E008C0CC 8FA90074 */  lw        $t1, 0x74($sp)
/* 38DED0 E008C0D0 2A220005 */  slti      $v0, $s1, 5
/* 38DED4 E008C0D4 AC900020 */  sw        $s0, 0x20($a0)
/* 38DED8 E008C0D8 AC900024 */  sw        $s0, 0x24($a0)
/* 38DEDC E008C0DC AC80001C */  sw        $zero, 0x1c($a0)
/* 38DEE0 E008C0E0 AC800028 */  sw        $zero, 0x28($a0)
/* 38DEE4 E008C0E4 AC890004 */  sw        $t1, 4($a0)
/* 38DEE8 E008C0E8 462010A0 */  cvt.s.d   $f2, $f2
/* 38DEEC E008C0EC E4820014 */  swc1      $f2, 0x14($a0)
/* 38DEF0 E008C0F0 E4820018 */  swc1      $f2, 0x18($a0)
/* 38DEF4 E008C0F4 104000B0 */  beqz      $v0, .LE008C3B8
/* 38DEF8 E008C0F8 24840048 */   addiu    $a0, $a0, 0x48
/* 38DEFC E008C0FC 3C03E009 */  lui       $v1, %hi(D_E008CB28)
/* 38DF00 E008C100 2463CB28 */  addiu     $v1, $v1, %lo(D_E008CB28)
/* 38DF04 E008C104 00081080 */  sll       $v0, $t0, 2
/* 38DF08 E008C108 00431021 */  addu      $v0, $v0, $v1
/* 38DF0C E008C10C 24080005 */  addiu     $t0, $zero, 5
/* 38DF10 E008C110 2517FFFF */  addiu     $s7, $t0, -1
/* 38DF14 E008C114 3C03E009 */  lui       $v1, %hi(D_E008CB48)
/* 38DF18 E008C118 2463CB48 */  addiu     $v1, $v1, %lo(D_E008CB48)
/* 38DF1C E008C11C 24900046 */  addiu     $s0, $a0, 0x46
/* 38DF20 E008C120 24160026 */  addiu     $s6, $zero, 0x26
/* 38DF24 E008C124 0000A02D */  daddu     $s4, $zero, $zero
/* 38DF28 E008C128 24150019 */  addiu     $s5, $zero, 0x19
/* 38DF2C E008C12C 24130078 */  addiu     $s3, $zero, 0x78
/* 38DF30 E008C130 8FA90070 */  lw        $t1, 0x70($sp)
/* 38DF34 E008C134 3C013F80 */  lui       $at, 0x3f80
/* 38DF38 E008C138 4481B000 */  mtc1      $at, $f22
/* 38DF3C E008C13C 3C013FE0 */  lui       $at, 0x3fe0
/* 38DF40 E008C140 4481A800 */  mtc1      $at, $f21
/* 38DF44 E008C144 4480A000 */  mtc1      $zero, $f20
/* 38DF48 E008C148 2412000B */  addiu     $s2, $zero, 0xb
/* 38DF4C E008C14C AFA2002C */  sw        $v0, 0x2c($sp)
/* 38DF50 E008C150 253EFFFE */  addiu     $fp, $t1, -2
/* 38DF54 E008C154 001E1080 */  sll       $v0, $fp, 2
/* 38DF58 E008C158 00431021 */  addu      $v0, $v0, $v1
/* 38DF5C E008C15C AFA20030 */  sw        $v0, 0x30($sp)
.LE008C160:
/* 38DF60 E008C160 8FA80070 */  lw        $t0, 0x70($sp)
/* 38DF64 E008C164 2D020008 */  sltiu     $v0, $t0, 8
/* 38DF68 E008C168 50400030 */  beql      $v0, $zero, .LE008C22C
/* 38DF6C E008C16C AE00FFC2 */   sw       $zero, -0x3e($s0)
/* 38DF70 E008C170 8FA9002C */  lw        $t1, 0x2c($sp)
/* 38DF74 E008C174 8D220000 */  lw        $v0, ($t1)
/* 38DF78 E008C178 00400008 */  jr        $v0
/* 38DF7C E008C17C 00000000 */   nop      
/* 38DF80 E008C180 3C014270 */  lui       $at, 0x4270
/* 38DF84 E008C184 44811000 */  mtc1      $at, $f2
/* 38DF88 E008C188 44920000 */  mtc1      $s2, $f0
/* 38DF8C E008C18C 00000000 */  nop       
/* 38DF90 E008C190 46800020 */  cvt.s.w   $f0, $f0
/* 38DF94 E008C194 E600FFC6 */  swc1      $f0, -0x3a($s0)
/* 38DF98 E008C198 44930000 */  mtc1      $s3, $f0
/* 38DF9C E008C19C 00000000 */  nop       
/* 38DFA0 E008C1A0 46800020 */  cvt.s.w   $f0, $f0
/* 38DFA4 E008C1A4 AE00FFC2 */  sw        $zero, -0x3e($s0)
/* 38DFA8 E008C1A8 AE00FFCA */  sw        $zero, -0x36($s0)
/* 38DFAC E008C1AC AE00FFF2 */  sw        $zero, -0xe($s0)
/* 38DFB0 E008C1B0 AE00FFFA */  sw        $zero, -6($s0)
/* 38DFB4 E008C1B4 AE00FFE6 */  sw        $zero, -0x1a($s0)
/* 38DFB8 E008C1B8 E600FFEA */  swc1      $f0, -0x16($s0)
/* 38DFBC E008C1BC AE00FFEE */  sw        $zero, -0x12($s0)
/* 38DFC0 E008C1C0 E616FFCE */  swc1      $f22, -0x32($s0)
/* 38DFC4 E008C1C4 080230CC */  j         .LE008C330
/* 38DFC8 E008C1C8 E602FFF6 */   swc1     $f2, -0xa($s0)
/* 38DFCC E008C1CC 44920000 */  mtc1      $s2, $f0
/* 38DFD0 E008C1D0 00000000 */  nop       
/* 38DFD4 E008C1D4 46800020 */  cvt.s.w   $f0, $f0
/* 38DFD8 E008C1D8 E600FFC6 */  swc1      $f0, -0x3a($s0)
/* 38DFDC E008C1DC 44930000 */  mtc1      $s3, $f0
/* 38DFE0 E008C1E0 00000000 */  nop       
/* 38DFE4 E008C1E4 46800020 */  cvt.s.w   $f0, $f0
/* 38DFE8 E008C1E8 240800FF */  addiu     $t0, $zero, 0xff
/* 38DFEC E008C1EC 3C01C270 */  lui       $at, 0xc270
/* 38DFF0 E008C1F0 44811000 */  mtc1      $at, $f2
/* 38DFF4 E008C1F4 0100482D */  daddu     $t1, $t0, $zero
/* 38DFF8 E008C1F8 AE00FFC2 */  sw        $zero, -0x3e($s0)
/* 38DFFC E008C1FC AE00FFCA */  sw        $zero, -0x36($s0)
/* 38E000 E008C200 AE00FFF2 */  sw        $zero, -0xe($s0)
/* 38E004 E008C204 AE00FFFA */  sw        $zero, -6($s0)
/* 38E008 E008C208 AE00FFE6 */  sw        $zero, -0x1a($s0)
/* 38E00C E008C20C E600FFEA */  swc1      $f0, -0x16($s0)
/* 38E010 E008C210 AE00FFEE */  sw        $zero, -0x12($s0)
/* 38E014 E008C214 E616FFCE */  swc1      $f22, -0x32($s0)
/* 38E018 E008C218 A2080000 */  sb        $t0, ($s0)
/* 38E01C E008C21C A209FFFF */  sb        $t1, -1($s0)
/* 38E020 E008C220 A208FFFE */  sb        $t0, -2($s0)
/* 38E024 E008C224 080230CC */  j         .LE008C330
/* 38E028 E008C228 E602FFF6 */   swc1     $f2, -0xa($s0)
.LE008C22C:
/* 38E02C E008C22C 8FA90074 */  lw        $t1, 0x74($sp)
/* 38E030 E008C230 852200B0 */  lh        $v0, 0xb0($t1)
/* 38E034 E008C234 44820000 */  mtc1      $v0, $f0
/* 38E038 E008C238 00000000 */  nop       
/* 38E03C E008C23C 46800021 */  cvt.d.w   $f0, $f0
/* 38E040 E008C240 46340002 */  mul.d     $f0, $f0, $f20
/* 38E044 E008C244 00000000 */  nop       
/* 38E048 E008C248 24040001 */  addiu     $a0, $zero, 1
/* 38E04C E008C24C AE00FFCA */  sw        $zero, -0x36($s0)
/* 38E050 E008C250 46200020 */  cvt.s.d   $f0, $f0
/* 38E054 E008C254 0C080000 */  jal       func_E0200000
/* 38E058 E008C258 E600FFC6 */   swc1     $f0, -0x3a($s0)
/* 38E05C E008C25C 24040001 */  addiu     $a0, $zero, 1
/* 38E060 E008C260 000210C0 */  sll       $v0, $v0, 3
/* 38E064 E008C264 2442FFFC */  addiu     $v0, $v0, -4
/* 38E068 E008C268 44820000 */  mtc1      $v0, $f0
/* 38E06C E008C26C 00000000 */  nop       
/* 38E070 E008C270 46800020 */  cvt.s.w   $f0, $f0
/* 38E074 E008C274 E600FFF2 */  swc1      $f0, -0xe($s0)
/* 38E078 E008C278 0C080000 */  jal       func_E0200000
/* 38E07C E008C27C AE00FFF6 */   sw       $zero, -0xa($s0)
/* 38E080 E008C280 16E00002 */  bnez      $s7, .LE008C28C
/* 38E084 E008C284 0297001A */   div      $zero, $s4, $s7
/* 38E088 E008C288 0007000D */  break     7
.LE008C28C:
/* 38E08C E008C28C 2401FFFF */   addiu    $at, $zero, -1
/* 38E090 E008C290 16E10004 */  bne       $s7, $at, .LE008C2A4
/* 38E094 E008C294 3C018000 */   lui      $at, 0x8000
/* 38E098 E008C298 16810002 */  bne       $s4, $at, .LE008C2A4
/* 38E09C E008C29C 00000000 */   nop      
/* 38E0A0 E008C2A0 0006000D */  break     6
.LE008C2A4:
/* 38E0A4 E008C2A4 00002012 */   mflo     $a0
/* 38E0A8 E008C2A8 000210C0 */  sll       $v0, $v0, 3
/* 38E0AC E008C2AC 2623FFFF */  addiu     $v1, $s1, -1
/* 38E0B0 E008C2B0 44830000 */  mtc1      $v1, $f0
/* 38E0B4 E008C2B4 00000000 */  nop       
/* 38E0B8 E008C2B8 46800020 */  cvt.s.w   $f0, $f0
/* 38E0BC E008C2BC 44971000 */  mtc1      $s7, $f2
/* 38E0C0 E008C2C0 00000000 */  nop       
/* 38E0C4 E008C2C4 468010A0 */  cvt.s.w   $f2, $f2
/* 38E0C8 E008C2C8 46020003 */  div.s     $f0, $f0, $f2
/* 38E0CC E008C2CC 46000021 */  cvt.d.s   $f0, $f0
/* 38E0D0 E008C2D0 46340002 */  mul.d     $f0, $f0, $f20
/* 38E0D4 E008C2D4 00000000 */  nop       
/* 38E0D8 E008C2D8 2442FFFC */  addiu     $v0, $v0, -4
/* 38E0DC E008C2DC 44821000 */  mtc1      $v0, $f2
/* 38E0E0 E008C2E0 00000000 */  nop       
/* 38E0E4 E008C2E4 468010A0 */  cvt.s.w   $f2, $f2
/* 38E0E8 E008C2E8 E602FFFA */  swc1      $f2, -6($s0)
/* 38E0EC E008C2EC 44951000 */  mtc1      $s5, $f2
/* 38E0F0 E008C2F0 00000000 */  nop       
/* 38E0F4 E008C2F4 468010A0 */  cvt.s.w   $f2, $f2
/* 38E0F8 E008C2F8 24020168 */  addiu     $v0, $zero, 0x168
/* 38E0FC E008C2FC 00561023 */  subu      $v0, $v0, $s6
/* 38E100 E008C300 E602FFE6 */  swc1      $f2, -0x1a($s0)
/* 38E104 E008C304 46340000 */  add.d     $f0, $f0, $f20
/* 38E108 E008C308 44821000 */  mtc1      $v0, $f2
/* 38E10C E008C30C 00000000 */  nop       
/* 38E110 E008C310 468010A0 */  cvt.s.w   $f2, $f2
/* 38E114 E008C314 E602FFEE */  swc1      $f2, -0x12($s0)
/* 38E118 E008C318 46200020 */  cvt.s.d   $f0, $f0
/* 38E11C E008C31C E600FFCE */  swc1      $f0, -0x32($s0)
/* 38E120 E008C320 44840000 */  mtc1      $a0, $f0
/* 38E124 E008C324 00000000 */  nop       
/* 38E128 E008C328 46800020 */  cvt.s.w   $f0, $f0
/* 38E12C E008C32C E600FFEA */  swc1      $f0, -0x16($s0)
.LE008C330:
/* 38E130 E008C330 2FC20006 */  sltiu     $v0, $fp, 6
/* 38E134 E008C334 1040000B */  beqz      $v0, .LE008C364
/* 38E138 E008C338 0000182D */   daddu    $v1, $zero, $zero
/* 38E13C E008C33C 8FA80030 */  lw        $t0, 0x30($sp)
/* 38E140 E008C340 8D020000 */  lw        $v0, ($t0)
/* 38E144 E008C344 00400008 */  jr        $v0
/* 38E148 E008C348 00000000 */   nop      
/* 38E14C E008C34C 080230D9 */  j         .LE008C364
/* 38E150 E008C350 24030001 */   addiu    $v1, $zero, 1
/* 38E154 E008C354 080230D9 */  j         .LE008C364
/* 38E158 E008C358 24030002 */   addiu    $v1, $zero, 2
/* 38E15C E008C35C 32220001 */  andi      $v0, $s1, 1
/* 38E160 E008C360 24430001 */  addiu     $v1, $v0, 1
.LE008C364:
/* 38E164 E008C364 26D60026 */  addiu     $s6, $s6, 0x26
/* 38E168 E008C368 26940168 */  addiu     $s4, $s4, 0x168
/* 38E16C E008C36C 26B50019 */  addiu     $s5, $s5, 0x19
/* 38E170 E008C370 3C02E009 */  lui       $v0, %hi(D_E008CB14)
/* 38E174 E008C374 00431021 */  addu      $v0, $v0, $v1
/* 38E178 E008C378 9042CB14 */  lbu       $v0, %lo(D_E008CB14)($v0)
/* 38E17C E008C37C 26730078 */  addiu     $s3, $s3, 0x78
/* 38E180 E008C380 A202FFFE */  sb        $v0, -2($s0)
/* 38E184 E008C384 3C02E009 */  lui       $v0, %hi(D_E008CB18)
/* 38E188 E008C388 00431021 */  addu      $v0, $v0, $v1
/* 38E18C E008C38C 9042CB18 */  lbu       $v0, %lo(D_E008CB18)($v0)
/* 38E190 E008C390 26520007 */  addiu     $s2, $s2, 7
/* 38E194 E008C394 A202FFFF */  sb        $v0, -1($s0)
/* 38E198 E008C398 3C02E009 */  lui       $v0, %hi(D_E008CB1C)
/* 38E19C E008C39C 00431021 */  addu      $v0, $v0, $v1
/* 38E1A0 E008C3A0 9042CB1C */  lbu       $v0, %lo(D_E008CB1C)($v0)
/* 38E1A4 E008C3A4 26310001 */  addiu     $s1, $s1, 1
/* 38E1A8 E008C3A8 A2020000 */  sb        $v0, ($s0)
/* 38E1AC E008C3AC 2A220005 */  slti      $v0, $s1, 5
/* 38E1B0 E008C3B0 1440FF6B */  bnez      $v0, .LE008C160
/* 38E1B4 E008C3B4 26100048 */   addiu    $s0, $s0, 0x48
.LE008C3B8:
/* 38E1B8 E008C3B8 8FA20028 */  lw        $v0, 0x28($sp)
/* 38E1BC E008C3BC 8FBF005C */  lw        $ra, 0x5c($sp)
/* 38E1C0 E008C3C0 8FBE0058 */  lw        $fp, 0x58($sp)
/* 38E1C4 E008C3C4 8FB70054 */  lw        $s7, 0x54($sp)
/* 38E1C8 E008C3C8 8FB60050 */  lw        $s6, 0x50($sp)
/* 38E1CC E008C3CC 8FB5004C */  lw        $s5, 0x4c($sp)
/* 38E1D0 E008C3D0 8FB40048 */  lw        $s4, 0x48($sp)
/* 38E1D4 E008C3D4 8FB30044 */  lw        $s3, 0x44($sp)
/* 38E1D8 E008C3D8 8FB20040 */  lw        $s2, 0x40($sp)
/* 38E1DC E008C3DC 8FB1003C */  lw        $s1, 0x3c($sp)
/* 38E1E0 E008C3E0 8FB00038 */  lw        $s0, 0x38($sp)
/* 38E1E4 E008C3E4 D7B60068 */  ldc1      $f22, 0x68($sp)
/* 38E1E8 E008C3E8 D7B40060 */  ldc1      $f20, 0x60($sp)
/* 38E1EC E008C3EC 03E00008 */  jr        $ra
/* 38E1F0 E008C3F0 27BD0070 */   addiu    $sp, $sp, 0x70
