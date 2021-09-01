.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel pause_map_draw_contents
/* 140E5C 8024DB1C 27BDFF60 */  addiu     $sp, $sp, -0xa0
/* 140E60 8024DB20 AFB7008C */  sw        $s7, 0x8c($sp)
/* 140E64 8024DB24 0000B82D */  daddu     $s7, $zero, $zero
/* 140E68 8024DB28 3C02800A */  lui       $v0, %hi(gMasterGfxPos)
/* 140E6C 8024DB2C 2442A66C */  addiu     $v0, $v0, %lo(gMasterGfxPos)
/* 140E70 8024DB30 AFB10074 */  sw        $s1, 0x74($sp)
/* 140E74 8024DB34 0040882D */  daddu     $s1, $v0, $zero
/* 140E78 8024DB38 AFB40080 */  sw        $s4, 0x80($sp)
/* 140E7C 8024DB3C 3C14F548 */  lui       $s4, 0xf548
/* 140E80 8024DB40 3C018027 */  lui       $at, %hi(pause_map_cameraY)
/* 140E84 8024DB44 C4200708 */  lwc1      $f0, %lo(pause_map_cameraY)($at)
/* 140E88 8024DB48 36945000 */  ori       $s4, $s4, 0x5000
/* 140E8C 8024DB4C AFBE0090 */  sw        $fp, 0x90($sp)
/* 140E90 8024DB50 3C1EE700 */  lui       $fp, 0xe700
/* 140E94 8024DB54 AFB50084 */  sw        $s5, 0x84($sp)
/* 140E98 8024DB58 AFA500A4 */  sw        $a1, 0xa4($sp)
/* 140E9C 8024DB5C 24B5001A */  addiu     $s5, $a1, 0x1a
/* 140EA0 8024DB60 AFB60088 */  sw        $s6, 0x88($sp)
/* 140EA4 8024DB64 24B60104 */  addiu     $s6, $a1, 0x104
/* 140EA8 8024DB68 AFB20078 */  sw        $s2, 0x78($sp)
/* 140EAC 8024DB6C 24120004 */  addiu     $s2, $zero, 4
/* 140EB0 8024DB70 AFB3007C */  sw        $s3, 0x7c($sp)
/* 140EB4 8024DB74 24130016 */  addiu     $s3, $zero, 0x16
/* 140EB8 8024DB78 AFB00070 */  sw        $s0, 0x70($sp)
/* 140EBC 8024DB7C 02E0802D */  daddu     $s0, $s7, $zero
/* 140EC0 8024DB80 AFBF0094 */  sw        $ra, 0x94($sp)
/* 140EC4 8024DB84 F7B40098 */  sdc1      $f20, 0x98($sp)
/* 140EC8 8024DB88 AFA600A8 */  sw        $a2, 0xa8($sp)
/* 140ECC 8024DB8C AFA700AC */  sw        $a3, 0xac($sp)
/* 140ED0 8024DB90 8E220000 */  lw        $v0, ($s1)
/* 140ED4 8024DB94 4600018D */  trunc.w.s $f6, $f0
/* 140ED8 8024DB98 E7A60054 */  swc1      $f6, 0x54($sp)
/* 140EDC 8024DB9C 3C018027 */  lui       $at, %hi(pause_map_cameraX)
/* 140EE0 8024DBA0 C4200704 */  lwc1      $f0, %lo(pause_map_cameraX)($at)
/* 140EE4 8024DBA4 0040202D */  daddu     $a0, $v0, $zero
/* 140EE8 8024DBA8 4600018D */  trunc.w.s $f6, $f0
/* 140EEC 8024DBAC E7A60050 */  swc1      $f6, 0x50($sp)
/* 140EF0 8024DBB0 8FAF0050 */  lw        $t7, 0x50($sp)
/* 140EF4 8024DBB4 24420008 */  addiu     $v0, $v0, 8
/* 140EF8 8024DBB8 000F1823 */  negu      $v1, $t7
/* 140EFC 8024DBBC 00031940 */  sll       $v1, $v1, 5
/* 140F00 8024DBC0 AFA30058 */  sw        $v1, 0x58($sp)
/* 140F04 8024DBC4 AE220000 */  sw        $v0, ($s1)
/* 140F08 8024DBC8 3C02DE00 */  lui       $v0, 0xde00
/* 140F0C 8024DBCC AC820000 */  sw        $v0, ($a0)
/* 140F10 8024DBD0 3C028027 */  lui       $v0, %hi(D_8026F118)
/* 140F14 8024DBD4 2442F118 */  addiu     $v0, $v0, %lo(D_8026F118)
/* 140F18 8024DBD8 AC820004 */  sw        $v0, 4($a0)
.L8024DBDC:
/* 140F1C 8024DBDC 2A42006F */  slti      $v0, $s2, 0x6f
/* 140F20 8024DBE0 14400003 */  bnez      $v0, .L8024DBF0
/* 140F24 8024DBE4 240D0004 */   addiu    $t5, $zero, 4
/* 140F28 8024DBE8 2402006F */  addiu     $v0, $zero, 0x6f
/* 140F2C 8024DBEC 00506823 */  subu      $t5, $v0, $s0
.L8024DBF0:
/* 140F30 8024DBF0 3C02FD48 */  lui       $v0, 0xfd48
/* 140F34 8024DBF4 3442013F */  ori       $v0, $v0, 0x13f
/* 140F38 8024DBF8 3C090708 */  lui       $t1, 0x708
/* 140F3C 8024DBFC 35290200 */  ori       $t1, $t1, 0x200
/* 140F40 8024DC00 3C0A074F */  lui       $t2, 0x74f
/* 140F44 8024DC04 354AC000 */  ori       $t2, $t2, 0xc000
/* 140F48 8024DC08 3C0B0008 */  lui       $t3, 8
/* 140F4C 8024DC0C 356B0200 */  ori       $t3, $t3, 0x200
/* 140F50 8024DC10 3C0C004F */  lui       $t4, 0x4f
/* 140F54 8024DC14 358CC000 */  ori       $t4, $t4, 0xc000
/* 140F58 8024DC18 00152080 */  sll       $a0, $s5, 2
/* 140F5C 8024DC1C 00163080 */  sll       $a2, $s6, 2
/* 140F60 8024DC20 8FAE00A8 */  lw        $t6, 0xa8($sp)
/* 140F64 8024DC24 8E230000 */  lw        $v1, ($s1)
/* 140F68 8024DC28 01D33821 */  addu      $a3, $t6, $s3
/* 140F6C 8024DC2C 00072880 */  sll       $a1, $a3, 2
/* 140F70 8024DC30 00ED3821 */  addu      $a3, $a3, $t5
/* 140F74 8024DC34 00073880 */  sll       $a3, $a3, 2
/* 140F78 8024DC38 0060402D */  daddu     $t0, $v1, $zero
/* 140F7C 8024DC3C 24630008 */  addiu     $v1, $v1, 8
/* 140F80 8024DC40 AE230000 */  sw        $v1, ($s1)
/* 140F84 8024DC44 AD020000 */  sw        $v0, ($t0)
/* 140F88 8024DC48 3C028025 */  lui       $v0, %hi(D_802510B0)
/* 140F8C 8024DC4C 244210B0 */  addiu     $v0, $v0, %lo(D_802510B0)
/* 140F90 8024DC50 AD020004 */  sw        $v0, 4($t0)
/* 140F94 8024DC54 24620008 */  addiu     $v0, $v1, 8
/* 140F98 8024DC58 AE220000 */  sw        $v0, ($s1)
/* 140F9C 8024DC5C 24620010 */  addiu     $v0, $v1, 0x10
/* 140FA0 8024DC60 AC740000 */  sw        $s4, ($v1)
/* 140FA4 8024DC64 AC690004 */  sw        $t1, 4($v1)
/* 140FA8 8024DC68 AE220000 */  sw        $v0, ($s1)
/* 140FAC 8024DC6C 3C02E600 */  lui       $v0, 0xe600
/* 140FB0 8024DC70 AC620008 */  sw        $v0, 8($v1)
/* 140FB4 8024DC74 24620018 */  addiu     $v0, $v1, 0x18
/* 140FB8 8024DC78 AC60000C */  sw        $zero, 0xc($v1)
/* 140FBC 8024DC7C AE220000 */  sw        $v0, ($s1)
/* 140FC0 8024DC80 3C02F400 */  lui       $v0, 0xf400
/* 140FC4 8024DC84 8FAF0054 */  lw        $t7, 0x54($sp)
/* 140FC8 8024DC88 020D4021 */  addu      $t0, $s0, $t5
/* 140FCC 8024DC8C 020F4823 */  subu      $t1, $s0, $t7
/* 140FD0 8024DC90 00094880 */  sll       $t1, $t1, 2
/* 140FD4 8024DC94 31290FFF */  andi      $t1, $t1, 0xfff
/* 140FD8 8024DC98 01221025 */  or        $v0, $t1, $v0
/* 140FDC 8024DC9C AC620010 */  sw        $v0, 0x10($v1)
/* 140FE0 8024DCA0 25E20001 */  addiu     $v0, $t7, 1
/* 140FE4 8024DCA4 01024023 */  subu      $t0, $t0, $v0
/* 140FE8 8024DCA8 00084080 */  sll       $t0, $t0, 2
/* 140FEC 8024DCAC 31080FFF */  andi      $t0, $t0, 0xfff
/* 140FF0 8024DCB0 010A5025 */  or        $t2, $t0, $t2
/* 140FF4 8024DCB4 24620020 */  addiu     $v0, $v1, 0x20
/* 140FF8 8024DCB8 AC6A0014 */  sw        $t2, 0x14($v1)
/* 140FFC 8024DCBC AE220000 */  sw        $v0, ($s1)
/* 141000 8024DCC0 24620028 */  addiu     $v0, $v1, 0x28
/* 141004 8024DCC4 AC7E0018 */  sw        $fp, 0x18($v1)
/* 141008 8024DCC8 AC60001C */  sw        $zero, 0x1c($v1)
/* 14100C 8024DCCC AE220000 */  sw        $v0, ($s1)
/* 141010 8024DCD0 24620030 */  addiu     $v0, $v1, 0x30
/* 141014 8024DCD4 AC740020 */  sw        $s4, 0x20($v1)
/* 141018 8024DCD8 AC6B0024 */  sw        $t3, 0x24($v1)
/* 14101C 8024DCDC AE220000 */  sw        $v0, ($s1)
/* 141020 8024DCE0 3C02F200 */  lui       $v0, 0xf200
/* 141024 8024DCE4 01224825 */  or        $t1, $t1, $v0
/* 141028 8024DCE8 010C4025 */  or        $t0, $t0, $t4
/* 14102C 8024DCEC 020F1023 */  subu      $v0, $s0, $t7
/* 141030 8024DCF0 AC690028 */  sw        $t1, 0x28($v1)
/* 141034 8024DCF4 AC68002C */  sw        $t0, 0x2c($v1)
/* 141038 8024DCF8 8FAE0058 */  lw        $t6, 0x58($sp)
/* 14103C 8024DCFC 00021140 */  sll       $v0, $v0, 5
/* 141040 8024DD00 AFA20018 */  sw        $v0, 0x18($sp)
/* 141044 8024DD04 24020400 */  addiu     $v0, $zero, 0x400
/* 141048 8024DD08 AFA00010 */  sw        $zero, 0x10($sp)
/* 14104C 8024DD0C AFA2001C */  sw        $v0, 0x1c($sp)
/* 141050 8024DD10 AFA20020 */  sw        $v0, 0x20($sp)
/* 141054 8024DD14 0C091216 */  jal       pause_draw_rect
/* 141058 8024DD18 AFAE0014 */   sw       $t6, 0x14($sp)
/* 14105C 8024DD1C 8E250000 */  lw        $a1, ($s1)
/* 141060 8024DD20 00A0102D */  daddu     $v0, $a1, $zero
/* 141064 8024DD24 24A50008 */  addiu     $a1, $a1, 8
/* 141068 8024DD28 AE250000 */  sw        $a1, ($s1)
/* 14106C 8024DD2C AC5E0000 */  sw        $fp, ($v0)
/* 141070 8024DD30 AC400004 */  sw        $zero, 4($v0)
/* 141074 8024DD34 2A42006E */  slti      $v0, $s2, 0x6e
/* 141078 8024DD38 10400008 */  beqz      $v0, .L8024DD5C
/* 14107C 8024DD3C 02A0202D */   daddu    $a0, $s5, $zero
/* 141080 8024DD40 26520004 */  addiu     $s2, $s2, 4
/* 141084 8024DD44 26730004 */  addiu     $s3, $s3, 4
/* 141088 8024DD48 26F70001 */  addiu     $s7, $s7, 1
/* 14108C 8024DD4C 2AE2003C */  slti      $v0, $s7, 0x3c
/* 141090 8024DD50 1440FFA2 */  bnez      $v0, .L8024DBDC
/* 141094 8024DD54 26100004 */   addiu    $s0, $s0, 4
/* 141098 8024DD58 02A0202D */  daddu     $a0, $s5, $zero
.L8024DD5C:
/* 14109C 8024DD5C 02C0302D */  daddu     $a2, $s6, $zero
/* 1410A0 8024DD60 8FAF00A8 */  lw        $t7, 0xa8($sp)
/* 1410A4 8024DD64 24A20008 */  addiu     $v0, $a1, 8
/* 1410A8 8024DD68 AE220000 */  sw        $v0, ($s1)
/* 1410AC 8024DD6C 3C02DE00 */  lui       $v0, 0xde00
/* 1410B0 8024DD70 ACA20000 */  sw        $v0, ($a1)
/* 1410B4 8024DD74 3C028027 */  lui       $v0, %hi(D_8026F1B8)
/* 1410B8 8024DD78 2442F1B8 */  addiu     $v0, $v0, %lo(D_8026F1B8)
/* 1410BC 8024DD7C ACA20004 */  sw        $v0, 4($a1)
/* 1410C0 8024DD80 25E30016 */  addiu     $v1, $t7, 0x16
/* 1410C4 8024DD84 1C800002 */  bgtz      $a0, .L8024DD90
/* 1410C8 8024DD88 25E70084 */   addiu    $a3, $t7, 0x84
/* 1410CC 8024DD8C 24040001 */  addiu     $a0, $zero, 1
.L8024DD90:
/* 1410D0 8024DD90 58600001 */  blezl     $v1, .L8024DD98
/* 1410D4 8024DD94 24030001 */   addiu    $v1, $zero, 1
.L8024DD98:
/* 1410D8 8024DD98 18C001DF */  blez      $a2, .L8024E518
/* 1410DC 8024DD9C 00000000 */   nop
/* 1410E0 8024DDA0 18E001DD */  blez      $a3, .L8024E518
/* 1410E4 8024DDA4 2882013F */   slti     $v0, $a0, 0x13f
/* 1410E8 8024DDA8 104001DB */  beqz      $v0, .L8024E518
/* 1410EC 8024DDAC 286200EF */   slti     $v0, $v1, 0xef
/* 1410F0 8024DDB0 104001D9 */  beqz      $v0, .L8024E518
/* 1410F4 8024DDB4 28C2013F */   slti     $v0, $a2, 0x13f
/* 1410F8 8024DDB8 50400001 */  beql      $v0, $zero, .L8024DDC0
/* 1410FC 8024DDBC 2406013F */   addiu    $a2, $zero, 0x13f
.L8024DDC0:
/* 141100 8024DDC0 28E200EF */  slti      $v0, $a3, 0xef
/* 141104 8024DDC4 50400001 */  beql      $v0, $zero, .L8024DDCC
/* 141108 8024DDC8 240700EF */   addiu    $a3, $zero, 0xef
.L8024DDCC:
/* 14110C 8024DDCC 3C0E8025 */  lui       $t6, %hi(D_802502B8)
/* 141110 8024DDD0 25CE02B8 */  addiu     $t6, $t6, %lo(D_802502B8)
/* 141114 8024DDD4 0000B82D */  daddu     $s7, $zero, $zero
/* 141118 8024DDD8 3C08800A */  lui       $t0, %hi(gMasterGfxPos)
/* 14111C 8024DDDC 2508A66C */  addiu     $t0, $t0, %lo(gMasterGfxPos)
/* 141120 8024DDE0 44841000 */  mtc1      $a0, $f2
/* 141124 8024DDE4 00000000 */  nop
/* 141128 8024DDE8 468010A0 */  cvt.s.w   $f2, $f2
/* 14112C 8024DDEC 24A20010 */  addiu     $v0, $a1, 0x10
/* 141130 8024DDF0 8FAF0050 */  lw        $t7, 0x50($sp)
/* 141134 8024DDF4 44830000 */  mtc1      $v1, $f0
/* 141138 8024DDF8 00000000 */  nop
/* 14113C 8024DDFC 46800020 */  cvt.s.w   $f0, $f0
/* 141140 8024DE00 AFAE005C */  sw        $t6, 0x5c($sp)
/* 141144 8024DE04 8FAE00A4 */  lw        $t6, 0xa4($sp)
/* 141148 8024DE08 3C014080 */  lui       $at, 0x4080
/* 14114C 8024DE0C 44812000 */  mtc1      $at, $f4
/* 141150 8024DE10 01EE7821 */  addu      $t7, $t7, $t6
/* 141154 8024DE14 46041082 */  mul.s     $f2, $f2, $f4
/* 141158 8024DE18 00000000 */  nop
/* 14115C 8024DE1C AFAF0060 */  sw        $t7, 0x60($sp)
/* 141160 8024DE20 8FAF0054 */  lw        $t7, 0x54($sp)
/* 141164 8024DE24 8FAE00A8 */  lw        $t6, 0xa8($sp)
/* 141168 8024DE28 3C04ED00 */  lui       $a0, 0xed00
/* 14116C 8024DE2C 01EE7821 */  addu      $t7, $t7, $t6
/* 141170 8024DE30 AFAF0064 */  sw        $t7, 0x64($sp)
/* 141174 8024DE34 8FAF005C */  lw        $t7, 0x5c($sp)
/* 141178 8024DE38 46040002 */  mul.s     $f0, $f0, $f4
/* 14117C 8024DE3C 00000000 */  nop
/* 141180 8024DE40 AE220000 */  sw        $v0, ($s1)
/* 141184 8024DE44 25FE0008 */  addiu     $fp, $t7, 8
/* 141188 8024DE48 4600118D */  trunc.w.s $f6, $f2
/* 14118C 8024DE4C 44023000 */  mfc1      $v0, $f6
/* 141190 8024DE50 00000000 */  nop
/* 141194 8024DE54 30420FFF */  andi      $v0, $v0, 0xfff
/* 141198 8024DE58 00021300 */  sll       $v0, $v0, 0xc
/* 14119C 8024DE5C 4600018D */  trunc.w.s $f6, $f0
/* 1411A0 8024DE60 44033000 */  mfc1      $v1, $f6
/* 1411A4 8024DE64 44861000 */  mtc1      $a2, $f2
/* 1411A8 8024DE68 00000000 */  nop
/* 1411AC 8024DE6C 468010A0 */  cvt.s.w   $f2, $f2
/* 1411B0 8024DE70 46041082 */  mul.s     $f2, $f2, $f4
/* 1411B4 8024DE74 00000000 */  nop
/* 1411B8 8024DE78 30630FFF */  andi      $v1, $v1, 0xfff
/* 1411BC 8024DE7C 00641825 */  or        $v1, $v1, $a0
/* 1411C0 8024DE80 00431025 */  or        $v0, $v0, $v1
/* 1411C4 8024DE84 44870000 */  mtc1      $a3, $f0
/* 1411C8 8024DE88 00000000 */  nop
/* 1411CC 8024DE8C 46800020 */  cvt.s.w   $f0, $f0
/* 1411D0 8024DE90 46040002 */  mul.s     $f0, $f0, $f4
/* 1411D4 8024DE94 00000000 */  nop
/* 1411D8 8024DE98 ACA20008 */  sw        $v0, 8($a1)
/* 1411DC 8024DE9C 4600118D */  trunc.w.s $f6, $f2
/* 1411E0 8024DEA0 44023000 */  mfc1      $v0, $f6
/* 1411E4 8024DEA4 00000000 */  nop
/* 1411E8 8024DEA8 30420FFF */  andi      $v0, $v0, 0xfff
/* 1411EC 8024DEAC 00021300 */  sll       $v0, $v0, 0xc
/* 1411F0 8024DEB0 4600018D */  trunc.w.s $f6, $f0
/* 1411F4 8024DEB4 44033000 */  mfc1      $v1, $f6
/* 1411F8 8024DEB8 00000000 */  nop
/* 1411FC 8024DEBC 30630FFF */  andi      $v1, $v1, 0xfff
/* 141200 8024DEC0 00431025 */  or        $v0, $v0, $v1
/* 141204 8024DEC4 ACA2000C */  sw        $v0, 0xc($a1)
.L8024DEC8:
/* 141208 8024DEC8 3C05F840 */  lui       $a1, 0xf840
/* 14120C 8024DECC 34A5632A */  ori       $a1, $a1, 0x632a
/* 141210 8024DED0 0000202D */  daddu     $a0, $zero, $zero
/* 141214 8024DED4 8FAF005C */  lw        $t7, 0x5c($sp)
/* 141218 8024DED8 87D1FFFA */  lh        $s1, -6($fp)
/* 14121C 8024DEDC 85F00000 */  lh        $s0, ($t7)
/* 141220 8024DEE0 02E52821 */  addu      $a1, $s7, $a1
/* 141224 8024DEE4 0C0B1EAF */  jal       evt_get_variable
/* 141228 8024DEE8 AFA80068 */   sw       $t0, 0x68($sp)
/* 14122C 8024DEEC 8FA80068 */  lw        $t0, 0x68($sp)
/* 141230 8024DEF0 5040007D */  beql      $v0, $zero, .L8024E0E8
/* 141234 8024DEF4 26F70001 */   addiu    $s7, $s7, 1
/* 141238 8024DEF8 3C028027 */  lui       $v0, %hi(pause_map_cursorCurrentOption)
/* 14123C 8024DEFC 8C42071C */  lw        $v0, %lo(pause_map_cursorCurrentOption)($v0)
/* 141240 8024DF00 12E2000A */  beq       $s7, $v0, .L8024DF2C
/* 141244 8024DF04 3C02DC50 */   lui      $v0, 0xdc50
/* 141248 8024DF08 8D030000 */  lw        $v1, ($t0)
/* 14124C 8024DF0C 34421EFF */  ori       $v0, $v0, 0x1eff
/* 141250 8024DF10 0060202D */  daddu     $a0, $v1, $zero
/* 141254 8024DF14 24630008 */  addiu     $v1, $v1, 8
/* 141258 8024DF18 3C0EFA00 */  lui       $t6, 0xfa00
/* 14125C 8024DF1C AD030000 */  sw        $v1, ($t0)
/* 141260 8024DF20 AC8E0000 */  sw        $t6, ($a0)
/* 141264 8024DF24 080937ED */  j         .L8024DFB4
/* 141268 8024DF28 AC820004 */   sw       $v0, 4($a0)
.L8024DF2C:
/* 14126C 8024DF2C 3C058888 */  lui       $a1, 0x8888
/* 141270 8024DF30 8D030000 */  lw        $v1, ($t0)
/* 141274 8024DF34 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 141278 8024DF38 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 14127C 8024DF3C 0060302D */  daddu     $a2, $v1, $zero
/* 141280 8024DF40 3C0FFA00 */  lui       $t7, 0xfa00
/* 141284 8024DF44 ACCF0000 */  sw        $t7, ($a2)
/* 141288 8024DF48 94420134 */  lhu       $v0, 0x134($v0)
/* 14128C 8024DF4C 34A58889 */  ori       $a1, $a1, 0x8889
/* 141290 8024DF50 00022080 */  sll       $a0, $v0, 2
/* 141294 8024DF54 00822021 */  addu      $a0, $a0, $v0
/* 141298 8024DF58 00042040 */  sll       $a0, $a0, 1
/* 14129C 8024DF5C 00850018 */  mult      $a0, $a1
/* 1412A0 8024DF60 24630008 */  addiu     $v1, $v1, 8
/* 1412A4 8024DF64 AD030000 */  sw        $v1, ($t0)
/* 1412A8 8024DF68 000417C3 */  sra       $v0, $a0, 0x1f
/* 1412AC 8024DF6C 00007010 */  mfhi      $t6
/* 1412B0 8024DF70 01C41821 */  addu      $v1, $t6, $a0
/* 1412B4 8024DF74 00031983 */  sra       $v1, $v1, 6
/* 1412B8 8024DF78 00621823 */  subu      $v1, $v1, $v0
/* 1412BC 8024DF7C 00031100 */  sll       $v0, $v1, 4
/* 1412C0 8024DF80 00431023 */  subu      $v0, $v0, $v1
/* 1412C4 8024DF84 000210C0 */  sll       $v0, $v0, 3
/* 1412C8 8024DF88 00822023 */  subu      $a0, $a0, $v0
/* 1412CC 8024DF8C 24820078 */  addiu     $v0, $a0, 0x78
/* 1412D0 8024DF90 304200FF */  andi      $v0, $v0, 0xff
/* 1412D4 8024DF94 00021E00 */  sll       $v1, $v0, 0x18
/* 1412D8 8024DF98 00021400 */  sll       $v0, $v0, 0x10
/* 1412DC 8024DF9C 00621825 */  or        $v1, $v1, $v0
/* 1412E0 8024DFA0 308400FF */  andi      $a0, $a0, 0xff
/* 1412E4 8024DFA4 00042200 */  sll       $a0, $a0, 8
/* 1412E8 8024DFA8 00641825 */  or        $v1, $v1, $a0
/* 1412EC 8024DFAC 346300FF */  ori       $v1, $v1, 0xff
/* 1412F0 8024DFB0 ACC30004 */  sw        $v1, 4($a2)
.L8024DFB4:
/* 1412F4 8024DFB4 8FAF0060 */  lw        $t7, 0x60($sp)
/* 1412F8 8024DFB8 8FAE0064 */  lw        $t6, 0x64($sp)
/* 1412FC 8024DFBC 2602001A */  addiu     $v0, $s0, 0x1a
/* 141300 8024DFC0 AFA00010 */  sw        $zero, 0x10($sp)
/* 141304 8024DFC4 AFA00014 */  sw        $zero, 0x14($sp)
/* 141308 8024DFC8 AFA00018 */  sw        $zero, 0x18($sp)
/* 14130C 8024DFCC AFA80068 */  sw        $t0, 0x68($sp)
/* 141310 8024DFD0 01E2A821 */  addu      $s5, $t7, $v0
/* 141314 8024DFD4 26A4FFF8 */  addiu     $a0, $s5, -8
/* 141318 8024DFD8 00042080 */  sll       $a0, $a0, 2
/* 14131C 8024DFDC 26220016 */  addiu     $v0, $s1, 0x16
/* 141320 8024DFE0 01C2A021 */  addu      $s4, $t6, $v0
/* 141324 8024DFE4 2685FFF8 */  addiu     $a1, $s4, -8
/* 141328 8024DFE8 00052880 */  sll       $a1, $a1, 2
/* 14132C 8024DFEC 26A60008 */  addiu     $a2, $s5, 8
/* 141330 8024DFF0 00063080 */  sll       $a2, $a2, 2
/* 141334 8024DFF4 26870008 */  addiu     $a3, $s4, 8
/* 141338 8024DFF8 00073880 */  sll       $a3, $a3, 2
/* 14133C 8024DFFC 240F0400 */  addiu     $t7, $zero, 0x400
/* 141340 8024E000 01E0702D */  daddu     $t6, $t7, $zero
/* 141344 8024E004 AFAF001C */  sw        $t7, 0x1c($sp)
/* 141348 8024E008 0C091216 */  jal       pause_draw_rect
/* 14134C 8024E00C AFAE0020 */   sw       $t6, 0x20($sp)
/* 141350 8024E010 3C05E6BE */  lui       $a1, 0xe6be
/* 141354 8024E014 8FA80068 */  lw        $t0, 0x68($sp)
/* 141358 8024E018 34A5B4FF */  ori       $a1, $a1, 0xb4ff
/* 14135C 8024E01C 8D030000 */  lw        $v1, ($t0)
/* 141360 8024E020 3C02E700 */  lui       $v0, 0xe700
/* 141364 8024E024 0060202D */  daddu     $a0, $v1, $zero
/* 141368 8024E028 24630008 */  addiu     $v1, $v1, 8
/* 14136C 8024E02C AC820000 */  sw        $v0, ($a0)
/* 141370 8024E030 AC800004 */  sw        $zero, 4($a0)
/* 141374 8024E034 3C0FFA00 */  lui       $t7, 0xfa00
/* 141378 8024E038 AC6F0000 */  sw        $t7, ($v1)
/* 14137C 8024E03C AC650004 */  sw        $a1, 4($v1)
/* 141380 8024E040 8FD00000 */  lw        $s0, ($fp)
/* 141384 8024E044 AD030000 */  sw        $v1, ($t0)
/* 141388 8024E048 24630008 */  addiu     $v1, $v1, 8
/* 14138C 8024E04C AD030000 */  sw        $v1, ($t0)
/* 141390 8024E050 93D6FFFD */  lbu       $s6, -3($fp)
/* 141394 8024E054 52000024 */  beql      $s0, $zero, .L8024E0E8
/* 141398 8024E058 26F70001 */   addiu    $s7, $s7, 1
/* 14139C 8024E05C 0000982D */  daddu     $s3, $zero, $zero
/* 1413A0 8024E060 0260902D */  daddu     $s2, $s3, $zero
/* 1413A4 8024E064 12C0001F */  beqz      $s6, .L8024E0E4
/* 1413A8 8024E068 0260882D */   daddu    $s1, $s3, $zero
/* 1413AC 8024E06C 26310001 */  addiu     $s1, $s1, 1
.L8024E070:
/* 1413B0 8024E070 82020000 */  lb        $v0, ($s0)
/* 1413B4 8024E074 82030001 */  lb        $v1, 1($s0)
/* 1413B8 8024E078 26100002 */  addiu     $s0, $s0, 2
/* 1413BC 8024E07C 240E0001 */  addiu     $t6, $zero, 1
/* 1413C0 8024E080 240F0400 */  addiu     $t7, $zero, 0x400
/* 1413C4 8024E084 AFAE0010 */  sw        $t6, 0x10($sp)
/* 1413C8 8024E088 01E0702D */  daddu     $t6, $t7, $zero
/* 1413CC 8024E08C AFA00014 */  sw        $zero, 0x14($sp)
/* 1413D0 8024E090 AFA00018 */  sw        $zero, 0x18($sp)
/* 1413D4 8024E094 AFAF001C */  sw        $t7, 0x1c($sp)
/* 1413D8 8024E098 AFAE0020 */  sw        $t6, 0x20($sp)
/* 1413DC 8024E09C AFA80068 */  sw        $t0, 0x68($sp)
/* 1413E0 8024E0A0 02629821 */  addu      $s3, $s3, $v0
/* 1413E4 8024E0A4 02439021 */  addu      $s2, $s2, $v1
/* 1413E8 8024E0A8 02B33021 */  addu      $a2, $s5, $s3
/* 1413EC 8024E0AC 24C4FFF8 */  addiu     $a0, $a2, -8
/* 1413F0 8024E0B0 00042080 */  sll       $a0, $a0, 2
/* 1413F4 8024E0B4 02923821 */  addu      $a3, $s4, $s2
/* 1413F8 8024E0B8 24E5FFF8 */  addiu     $a1, $a3, -8
/* 1413FC 8024E0BC 00052880 */  sll       $a1, $a1, 2
/* 141400 8024E0C0 24C60008 */  addiu     $a2, $a2, 8
/* 141404 8024E0C4 00063080 */  sll       $a2, $a2, 2
/* 141408 8024E0C8 24E70008 */  addiu     $a3, $a3, 8
/* 14140C 8024E0CC 0C091216 */  jal       pause_draw_rect
/* 141410 8024E0D0 00073880 */   sll      $a3, $a3, 2
/* 141414 8024E0D4 0236102A */  slt       $v0, $s1, $s6
/* 141418 8024E0D8 8FA80068 */  lw        $t0, 0x68($sp)
/* 14141C 8024E0DC 1440FFE4 */  bnez      $v0, .L8024E070
/* 141420 8024E0E0 26310001 */   addiu    $s1, $s1, 1
.L8024E0E4:
/* 141424 8024E0E4 26F70001 */  addiu     $s7, $s7, 1
.L8024E0E8:
/* 141428 8024E0E8 27DE0014 */  addiu     $fp, $fp, 0x14
/* 14142C 8024E0EC 8FAF005C */  lw        $t7, 0x5c($sp)
/* 141430 8024E0F0 2AE20022 */  slti      $v0, $s7, 0x22
/* 141434 8024E0F4 25EF0014 */  addiu     $t7, $t7, 0x14
/* 141438 8024E0F8 1440FF73 */  bnez      $v0, .L8024DEC8
/* 14143C 8024E0FC AFAF005C */   sw       $t7, 0x5c($sp)
/* 141440 8024E100 3C108027 */  lui       $s0, %hi(D_80270700)
/* 141444 8024E104 26100700 */  addiu     $s0, $s0, %lo(D_80270700)
/* 141448 8024E108 8E040000 */  lw        $a0, ($s0)
/* 14144C 8024E10C 8FAE0050 */  lw        $t6, 0x50($sp)
/* 141450 8024E110 3C058027 */  lui       $a1, %hi(pause_map_marioX)
/* 141454 8024E114 8CA5070C */  lw        $a1, %lo(pause_map_marioX)($a1)
/* 141458 8024E118 8FAF00A4 */  lw        $t7, 0xa4($sp)
/* 14145C 8024E11C 3C068027 */  lui       $a2, %hi(pause_map_marioY)
/* 141460 8024E120 8CC60710 */  lw        $a2, %lo(pause_map_marioY)($a2)
/* 141464 8024E124 25C2001A */  addiu     $v0, $t6, 0x1a
/* 141468 8024E128 01E29021 */  addu      $s2, $t7, $v0
/* 14146C 8024E12C 02452821 */  addu      $a1, $s2, $a1
/* 141470 8024E130 8FAE0054 */  lw        $t6, 0x54($sp)
/* 141474 8024E134 8FAF00A8 */  lw        $t7, 0xa8($sp)
/* 141478 8024E138 25C20016 */  addiu     $v0, $t6, 0x16
/* 14147C 8024E13C 01E28821 */  addu      $s1, $t7, $v0
/* 141480 8024E140 02263021 */  addu      $a2, $s1, $a2
/* 141484 8024E144 0C051261 */  jal       set_hud_element_render_pos
/* 141488 8024E148 24C6FFF9 */   addiu    $a2, $a2, -7
/* 14148C 8024E14C 8E040000 */  lw        $a0, ($s0)
/* 141490 8024E150 0C0511F8 */  jal       draw_hud_element_3
/* 141494 8024E154 00000000 */   nop
/* 141498 8024E158 3C138027 */  lui       $s3, %hi(gPauseMenuCurrentTab)
/* 14149C 8024E15C 267300D4 */  addiu     $s3, $s3, %lo(gPauseMenuCurrentTab)
/* 1414A0 8024E160 82700000 */  lb        $s0, ($s3)
/* 1414A4 8024E164 24020006 */  addiu     $v0, $zero, 6
/* 1414A8 8024E168 16020081 */  bne       $s0, $v0, .L8024E370
/* 1414AC 8024E16C 00000000 */   nop
/* 1414B0 8024E170 3C018027 */  lui       $at, %hi(pause_map_cursorX)
/* 1414B4 8024E174 C4200714 */  lwc1      $f0, %lo(pause_map_cursorX)($at)
/* 1414B8 8024E178 44922000 */  mtc1      $s2, $f4
/* 1414BC 8024E17C 00000000 */  nop
/* 1414C0 8024E180 46802120 */  cvt.s.w   $f4, $f4
/* 1414C4 8024E184 46002100 */  add.s     $f4, $f4, $f0
/* 1414C8 8024E188 3C018027 */  lui       $at, %hi(pause_map_cursorY)
/* 1414CC 8024E18C C4200718 */  lwc1      $f0, %lo(pause_map_cursorY)($at)
/* 1414D0 8024E190 44911000 */  mtc1      $s1, $f2
/* 1414D4 8024E194 00000000 */  nop
/* 1414D8 8024E198 468010A0 */  cvt.s.w   $f2, $f2
/* 1414DC 8024E19C 46001080 */  add.s     $f2, $f2, $f0
/* 1414E0 8024E1A0 3C014100 */  lui       $at, 0x4100
/* 1414E4 8024E1A4 44810000 */  mtc1      $at, $f0
/* 1414E8 8024E1A8 00000000 */  nop
/* 1414EC 8024E1AC 46002101 */  sub.s     $f4, $f4, $f0
/* 1414F0 8024E1B0 4600118D */  trunc.w.s $f6, $f2
/* 1414F4 8024E1B4 44063000 */  mfc1      $a2, $f6
/* 1414F8 8024E1B8 4600218D */  trunc.w.s $f6, $f4
/* 1414FC 8024E1BC 44053000 */  mfc1      $a1, $f6
/* 141500 8024E1C0 0C090B41 */  jal       func_80242D04
/* 141504 8024E1C4 24040029 */   addiu    $a0, $zero, 0x29
/* 141508 8024E1C8 82620000 */  lb        $v0, ($s3)
/* 14150C 8024E1CC 14500068 */  bne       $v0, $s0, .L8024E370
/* 141510 8024E1D0 00000000 */   nop
/* 141514 8024E1D4 3C06800A */  lui       $a2, %hi(gMasterGfxPos)
/* 141518 8024E1D8 24C6A66C */  addiu     $a2, $a2, %lo(gMasterGfxPos)
/* 14151C 8024E1DC 3C05AAAA */  lui       $a1, 0xaaaa
/* 141520 8024E1E0 34A5AAAB */  ori       $a1, $a1, 0xaaab
/* 141524 8024E1E4 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 141528 8024E1E8 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 14152C 8024E1EC 3C148027 */  lui       $s4, %hi(pause_map_cameraX)
/* 141530 8024E1F0 26940704 */  addiu     $s4, $s4, %lo(pause_map_cameraX)
/* 141534 8024E1F4 94430134 */  lhu       $v1, 0x134($v0)
/* 141538 8024E1F8 8CC40000 */  lw        $a0, ($a2)
/* 14153C 8024E1FC 00650019 */  multu     $v1, $a1
/* 141540 8024E200 C6800000 */  lwc1      $f0, ($s4)
/* 141544 8024E204 4480A000 */  mtc1      $zero, $f20
/* 141548 8024E208 0080382D */  daddu     $a3, $a0, $zero
/* 14154C 8024E20C 24840008 */  addiu     $a0, $a0, 8
/* 141550 8024E210 4614003C */  c.lt.s    $f0, $f20
/* 141554 8024E214 ACC40000 */  sw        $a0, ($a2)
/* 141558 8024E218 00007010 */  mfhi      $t6
/* 14155C 8024E21C 000E20C2 */  srl       $a0, $t6, 3
/* 141560 8024E220 00041040 */  sll       $v0, $a0, 1
/* 141564 8024E224 00441021 */  addu      $v0, $v0, $a0
/* 141568 8024E228 00021080 */  sll       $v0, $v0, 2
/* 14156C 8024E22C 00621823 */  subu      $v1, $v1, $v0
/* 141570 8024E230 3063FFFF */  andi      $v1, $v1, 0xffff
/* 141574 8024E234 00031880 */  sll       $v1, $v1, 2
/* 141578 8024E238 3C118025 */  lui       $s1, %hi(D_80250560)
/* 14157C 8024E23C 02238821 */  addu      $s1, $s1, $v1
/* 141580 8024E240 8E310560 */  lw        $s1, %lo(D_80250560)($s1)
/* 141584 8024E244 3C02DE00 */  lui       $v0, 0xde00
/* 141588 8024E248 ACE20000 */  sw        $v0, ($a3)
/* 14158C 8024E24C 3C028027 */  lui       $v0, %hi(D_8026F2A0)
/* 141590 8024E250 2442F2A0 */  addiu     $v0, $v0, %lo(D_8026F2A0)
/* 141594 8024E254 ACE20004 */  sw        $v0, 4($a3)
/* 141598 8024E258 0220282D */  daddu     $a1, $s1, $zero
/* 14159C 8024E25C 0220902D */  daddu     $s2, $s1, $zero
/* 1415A0 8024E260 45010002 */  bc1t      .L8024E26C
/* 1415A4 8024E264 0220982D */   daddu    $s3, $s1, $zero
/* 1415A8 8024E268 0000282D */  daddu     $a1, $zero, $zero
.L8024E26C:
/* 1415AC 8024E26C 0000202D */  daddu     $a0, $zero, $zero
/* 1415B0 8024E270 24A5FFE6 */  addiu     $a1, $a1, -0x1a
/* 1415B4 8024E274 8FAF00A4 */  lw        $t7, 0xa4($sp)
/* 1415B8 8024E278 8FAE00B0 */  lw        $t6, 0xb0($sp)
/* 1415BC 8024E27C 01E52823 */  subu      $a1, $t7, $a1
/* 1415C0 8024E280 000E17C2 */  srl       $v0, $t6, 0x1f
/* 1415C4 8024E284 01C21021 */  addu      $v0, $t6, $v0
/* 1415C8 8024E288 8FAF00A8 */  lw        $t7, 0xa8($sp)
/* 1415CC 8024E28C 00021043 */  sra       $v0, $v0, 1
/* 1415D0 8024E290 01E21021 */  addu      $v0, $t7, $v0
/* 1415D4 8024E294 2450FFF8 */  addiu     $s0, $v0, -8
/* 1415D8 8024E298 0C09368A */  jal       pause_map_draw_border_arrows
/* 1415DC 8024E29C 0200302D */   daddu    $a2, $s0, $zero
/* 1415E0 8024E2A0 C6820000 */  lwc1      $f2, ($s4)
/* 1415E4 8024E2A4 3C01C2AC */  lui       $at, 0xc2ac
/* 1415E8 8024E2A8 44810000 */  mtc1      $at, $f0
/* 1415EC 8024E2AC 00000000 */  nop
/* 1415F0 8024E2B0 4602003C */  c.lt.s    $f0, $f2
/* 1415F4 8024E2B4 00000000 */  nop
/* 1415F8 8024E2B8 45020001 */  bc1fl     .L8024E2C0
/* 1415FC 8024E2BC 0000902D */   daddu    $s2, $zero, $zero
.L8024E2C0:
/* 141600 8024E2C0 24040001 */  addiu     $a0, $zero, 1
/* 141604 8024E2C4 2645FFCE */  addiu     $a1, $s2, -0x32
/* 141608 8024E2C8 8FAE00A4 */  lw        $t6, 0xa4($sp)
/* 14160C 8024E2CC 8FAF00AC */  lw        $t7, 0xac($sp)
/* 141610 8024E2D0 0200302D */  daddu     $a2, $s0, $zero
/* 141614 8024E2D4 01CF1021 */  addu      $v0, $t6, $t7
/* 141618 8024E2D8 0C09368A */  jal       pause_map_draw_border_arrows
/* 14161C 8024E2DC 00452821 */   addu     $a1, $v0, $a1
/* 141620 8024E2E0 3C128027 */  lui       $s2, %hi(pause_map_cameraY)
/* 141624 8024E2E4 26520708 */  addiu     $s2, $s2, %lo(pause_map_cameraY)
/* 141628 8024E2E8 C6400000 */  lwc1      $f0, ($s2)
/* 14162C 8024E2EC 4614003C */  c.lt.s    $f0, $f20
/* 141630 8024E2F0 00000000 */  nop
/* 141634 8024E2F4 45020001 */  bc1fl     .L8024E2FC
/* 141638 8024E2F8 0000982D */   daddu    $s3, $zero, $zero
.L8024E2FC:
/* 14163C 8024E2FC 24040002 */  addiu     $a0, $zero, 2
/* 141640 8024E300 2666FFE8 */  addiu     $a2, $s3, -0x18
/* 141644 8024E304 8FAE00AC */  lw        $t6, 0xac($sp)
/* 141648 8024E308 8FAF00A4 */  lw        $t7, 0xa4($sp)
/* 14164C 8024E30C 000E17C2 */  srl       $v0, $t6, 0x1f
/* 141650 8024E310 01C21021 */  addu      $v0, $t6, $v0
/* 141654 8024E314 00021043 */  sra       $v0, $v0, 1
/* 141658 8024E318 01E21021 */  addu      $v0, $t7, $v0
/* 14165C 8024E31C 2450FFF8 */  addiu     $s0, $v0, -8
/* 141660 8024E320 8FAE00A8 */  lw        $t6, 0xa8($sp)
/* 141664 8024E324 0200282D */  daddu     $a1, $s0, $zero
/* 141668 8024E328 0C09368A */  jal       pause_map_draw_border_arrows
/* 14166C 8024E32C 01C63023 */   subu     $a2, $t6, $a2
/* 141670 8024E330 C6420000 */  lwc1      $f2, ($s2)
/* 141674 8024E334 3C01C352 */  lui       $at, 0xc352
/* 141678 8024E338 44810000 */  mtc1      $at, $f0
/* 14167C 8024E33C 00000000 */  nop
/* 141680 8024E340 4602003C */  c.lt.s    $f0, $f2
/* 141684 8024E344 00000000 */  nop
/* 141688 8024E348 45020001 */  bc1fl     .L8024E350
/* 14168C 8024E34C 0000882D */   daddu    $s1, $zero, $zero
.L8024E350:
/* 141690 8024E350 24040003 */  addiu     $a0, $zero, 3
/* 141694 8024E354 0200282D */  daddu     $a1, $s0, $zero
/* 141698 8024E358 8FAF00A8 */  lw        $t7, 0xa8($sp)
/* 14169C 8024E35C 8FAE00B0 */  lw        $t6, 0xb0($sp)
/* 1416A0 8024E360 2626FFD4 */  addiu     $a2, $s1, -0x2c
/* 1416A4 8024E364 01EE1021 */  addu      $v0, $t7, $t6
/* 1416A8 8024E368 0C09368A */  jal       pause_map_draw_border_arrows
/* 1416AC 8024E36C 00463021 */   addu     $a2, $v0, $a2
.L8024E370:
/* 1416B0 8024E370 8FAF00A4 */  lw        $t7, 0xa4($sp)
/* 1416B4 8024E374 8FAE00A8 */  lw        $t6, 0xa8($sp)
/* 1416B8 8024E378 25E70012 */  addiu     $a3, $t7, 0x12
/* 1416BC 8024E37C 25C8000E */  addiu     $t0, $t6, 0xe
/* 1416C0 8024E380 25EA010C */  addiu     $t2, $t7, 0x10c
/* 1416C4 8024E384 1CE00002 */  bgtz      $a3, .L8024E390
/* 1416C8 8024E388 25CB008C */   addiu    $t3, $t6, 0x8c
/* 1416CC 8024E38C 24070001 */  addiu     $a3, $zero, 1
.L8024E390:
/* 1416D0 8024E390 59000001 */  blezl     $t0, .L8024E398
/* 1416D4 8024E394 24080001 */   addiu    $t0, $zero, 1
.L8024E398:
/* 1416D8 8024E398 1940005F */  blez      $t2, .L8024E518
/* 1416DC 8024E39C 00000000 */   nop
/* 1416E0 8024E3A0 1960005D */  blez      $t3, .L8024E518
/* 1416E4 8024E3A4 28E2013F */   slti     $v0, $a3, 0x13f
/* 1416E8 8024E3A8 1040005B */  beqz      $v0, .L8024E518
/* 1416EC 8024E3AC 290200EF */   slti     $v0, $t0, 0xef
/* 1416F0 8024E3B0 10400059 */  beqz      $v0, .L8024E518
/* 1416F4 8024E3B4 2942013F */   slti     $v0, $t2, 0x13f
/* 1416F8 8024E3B8 50400001 */  beql      $v0, $zero, .L8024E3C0
/* 1416FC 8024E3BC 240A013F */   addiu    $t2, $zero, 0x13f
.L8024E3C0:
/* 141700 8024E3C0 296200EF */  slti      $v0, $t3, 0xef
/* 141704 8024E3C4 50400001 */  beql      $v0, $zero, .L8024E3CC
/* 141708 8024E3C8 240B00EF */   addiu    $t3, $zero, 0xef
.L8024E3CC:
/* 14170C 8024E3CC 3C03800A */  lui       $v1, %hi(gMasterGfxPos)
/* 141710 8024E3D0 2463A66C */  addiu     $v1, $v1, %lo(gMasterGfxPos)
/* 141714 8024E3D4 44871000 */  mtc1      $a3, $f2
/* 141718 8024E3D8 00000000 */  nop
/* 14171C 8024E3DC 468010A0 */  cvt.s.w   $f2, $f2
/* 141720 8024E3E0 44880000 */  mtc1      $t0, $f0
/* 141724 8024E3E4 00000000 */  nop
/* 141728 8024E3E8 46800020 */  cvt.s.w   $f0, $f0
/* 14172C 8024E3EC 3C08ED00 */  lui       $t0, 0xed00
/* 141730 8024E3F0 8FAF00A4 */  lw        $t7, 0xa4($sp)
/* 141734 8024E3F4 8C620000 */  lw        $v0, ($v1)
/* 141738 8024E3F8 3C014080 */  lui       $at, 0x4080
/* 14173C 8024E3FC 44812000 */  mtc1      $at, $f4
/* 141740 8024E400 8FAE00A8 */  lw        $t6, 0xa8($sp)
/* 141744 8024E404 46041082 */  mul.s     $f2, $f2, $f4
/* 141748 8024E408 00000000 */  nop
/* 14174C 8024E40C 25E60012 */  addiu     $a2, $t7, 0x12
/* 141750 8024E410 25C7000E */  addiu     $a3, $t6, 0xe
/* 141754 8024E414 0040482D */  daddu     $t1, $v0, $zero
/* 141758 8024E418 24420008 */  addiu     $v0, $v0, 8
/* 14175C 8024E41C 46040002 */  mul.s     $f0, $f0, $f4
/* 141760 8024E420 00000000 */  nop
/* 141764 8024E424 AC620000 */  sw        $v0, ($v1)
/* 141768 8024E428 4600118D */  trunc.w.s $f6, $f2
/* 14176C 8024E42C 44023000 */  mfc1      $v0, $f6
/* 141770 8024E430 00000000 */  nop
/* 141774 8024E434 30420FFF */  andi      $v0, $v0, 0xfff
/* 141778 8024E438 00021300 */  sll       $v0, $v0, 0xc
/* 14177C 8024E43C 4600018D */  trunc.w.s $f6, $f0
/* 141780 8024E440 44033000 */  mfc1      $v1, $f6
/* 141784 8024E444 448A1000 */  mtc1      $t2, $f2
/* 141788 8024E448 00000000 */  nop
/* 14178C 8024E44C 468010A0 */  cvt.s.w   $f2, $f2
/* 141790 8024E450 46041082 */  mul.s     $f2, $f2, $f4
/* 141794 8024E454 00000000 */  nop
/* 141798 8024E458 30630FFF */  andi      $v1, $v1, 0xfff
/* 14179C 8024E45C 00681825 */  or        $v1, $v1, $t0
/* 1417A0 8024E460 00431025 */  or        $v0, $v0, $v1
/* 1417A4 8024E464 448B0000 */  mtc1      $t3, $f0
/* 1417A8 8024E468 00000000 */  nop
/* 1417AC 8024E46C 46800020 */  cvt.s.w   $f0, $f0
/* 1417B0 8024E470 46040002 */  mul.s     $f0, $f0, $f4
/* 1417B4 8024E474 00000000 */  nop
/* 1417B8 8024E478 AD220000 */  sw        $v0, ($t1)
/* 1417BC 8024E47C 4600118D */  trunc.w.s $f6, $f2
/* 1417C0 8024E480 44023000 */  mfc1      $v0, $f6
/* 1417C4 8024E484 00000000 */  nop
/* 1417C8 8024E488 30420FFF */  andi      $v0, $v0, 0xfff
/* 1417CC 8024E48C 00021300 */  sll       $v0, $v0, 0xc
/* 1417D0 8024E490 4600018D */  trunc.w.s $f6, $f0
/* 1417D4 8024E494 44033000 */  mfc1      $v1, $f6
/* 1417D8 8024E498 00000000 */  nop
/* 1417DC 8024E49C 30630FFF */  andi      $v1, $v1, 0xfff
/* 1417E0 8024E4A0 00431025 */  or        $v0, $v0, $v1
/* 1417E4 8024E4A4 AD220004 */  sw        $v0, 4($t1)
/* 1417E8 8024E4A8 240200FA */  addiu     $v0, $zero, 0xfa
/* 1417EC 8024E4AC AFA20014 */  sw        $v0, 0x14($sp)
/* 1417F0 8024E4B0 2402007E */  addiu     $v0, $zero, 0x7e
/* 1417F4 8024E4B4 AFA20018 */  sw        $v0, 0x18($sp)
/* 1417F8 8024E4B8 93A200B7 */  lbu       $v0, 0xb7($sp)
/* 1417FC 8024E4BC 3C013F80 */  lui       $at, 0x3f80
/* 141800 8024E4C0 44810000 */  mtc1      $at, $f0
/* 141804 8024E4C4 8FAF00AC */  lw        $t7, 0xac($sp)
/* 141808 8024E4C8 8FAE00B0 */  lw        $t6, 0xb0($sp)
/* 14180C 8024E4CC 0000202D */  daddu     $a0, $zero, $zero
/* 141810 8024E4D0 AFA2001C */  sw        $v0, 0x1c($sp)
/* 141814 8024E4D4 93A200BB */  lbu       $v0, 0xbb($sp)
/* 141818 8024E4D8 3C058027 */  lui       $a1, %hi(D_8026FEE8)
/* 14181C 8024E4DC 24A5FEE8 */  addiu     $a1, $a1, %lo(D_8026FEE8)
/* 141820 8024E4E0 AFA00010 */  sw        $zero, 0x10($sp)
/* 141824 8024E4E4 AFA0002C */  sw        $zero, 0x2c($sp)
/* 141828 8024E4E8 AFA00030 */  sw        $zero, 0x30($sp)
/* 14182C 8024E4EC AFA00034 */  sw        $zero, 0x34($sp)
/* 141830 8024E4F0 AFA00038 */  sw        $zero, 0x38($sp)
/* 141834 8024E4F4 AFA0003C */  sw        $zero, 0x3c($sp)
/* 141838 8024E4F8 AFA00040 */  sw        $zero, 0x40($sp)
/* 14183C 8024E4FC AFA0004C */  sw        $zero, 0x4c($sp)
/* 141840 8024E500 E7A00024 */  swc1      $f0, 0x24($sp)
/* 141844 8024E504 E7A00028 */  swc1      $f0, 0x28($sp)
/* 141848 8024E508 AFAF0044 */  sw        $t7, 0x44($sp)
/* 14184C 8024E50C AFAE0048 */  sw        $t6, 0x48($sp)
/* 141850 8024E510 0C03D4B8 */  jal       draw_box
/* 141854 8024E514 AFA20020 */   sw       $v0, 0x20($sp)
.L8024E518:
/* 141858 8024E518 8FBF0094 */  lw        $ra, 0x94($sp)
/* 14185C 8024E51C 8FBE0090 */  lw        $fp, 0x90($sp)
/* 141860 8024E520 8FB7008C */  lw        $s7, 0x8c($sp)
/* 141864 8024E524 8FB60088 */  lw        $s6, 0x88($sp)
/* 141868 8024E528 8FB50084 */  lw        $s5, 0x84($sp)
/* 14186C 8024E52C 8FB40080 */  lw        $s4, 0x80($sp)
/* 141870 8024E530 8FB3007C */  lw        $s3, 0x7c($sp)
/* 141874 8024E534 8FB20078 */  lw        $s2, 0x78($sp)
/* 141878 8024E538 8FB10074 */  lw        $s1, 0x74($sp)
/* 14187C 8024E53C 8FB00070 */  lw        $s0, 0x70($sp)
/* 141880 8024E540 D7B40098 */  ldc1      $f20, 0x98($sp)
/* 141884 8024E544 03E00008 */  jr        $ra
/* 141888 8024E548 27BD00A0 */   addiu    $sp, $sp, 0xa0
