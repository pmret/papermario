.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8023F088
/* 16D968 8023F088 27BDFF80 */  addiu     $sp, $sp, -0x80
/* 16D96C 8023F08C AFB40068 */  sw        $s4, 0x68($sp)
/* 16D970 8023F090 0000A02D */  daddu     $s4, $zero, $zero
/* 16D974 8023F094 3C03800A */  lui       $v1, %hi(gCurrentCamID)
/* 16D978 8023F098 8463A634 */  lh        $v1, %lo(gCurrentCamID)($v1)
/* 16D97C 8023F09C 3C04800B */  lui       $a0, %hi(gCameras)
/* 16D980 8023F0A0 24841D80 */  addiu     $a0, $a0, %lo(gCameras)
/* 16D984 8023F0A4 AFBF007C */  sw        $ra, 0x7c($sp)
/* 16D988 8023F0A8 AFBE0078 */  sw        $fp, 0x78($sp)
/* 16D98C 8023F0AC AFB70074 */  sw        $s7, 0x74($sp)
/* 16D990 8023F0B0 AFB60070 */  sw        $s6, 0x70($sp)
/* 16D994 8023F0B4 AFB5006C */  sw        $s5, 0x6c($sp)
/* 16D998 8023F0B8 AFB30064 */  sw        $s3, 0x64($sp)
/* 16D99C 8023F0BC AFB20060 */  sw        $s2, 0x60($sp)
/* 16D9A0 8023F0C0 AFB1005C */  sw        $s1, 0x5c($sp)
/* 16D9A4 8023F0C4 AFB00058 */  sw        $s0, 0x58($sp)
/* 16D9A8 8023F0C8 00031080 */  sll       $v0, $v1, 2
/* 16D9AC 8023F0CC 00431021 */  addu      $v0, $v0, $v1
/* 16D9B0 8023F0D0 00021080 */  sll       $v0, $v0, 2
/* 16D9B4 8023F0D4 00431023 */  subu      $v0, $v0, $v1
/* 16D9B8 8023F0D8 000218C0 */  sll       $v1, $v0, 3
/* 16D9BC 8023F0DC 00431021 */  addu      $v0, $v0, $v1
/* 16D9C0 8023F0E0 000210C0 */  sll       $v0, $v0, 3
/* 16D9C4 8023F0E4 0C099EF7 */  jal       hide_foreground_models_unsafe
/* 16D9C8 8023F0E8 0044B821 */   addu     $s7, $v0, $a0
/* 16D9CC 8023F0EC 0C046EE9 */  jal       is_world_fog_enabled
/* 16D9D0 8023F0F0 00000000 */   nop
/* 16D9D4 8023F0F4 10400043 */  beqz      $v0, .L8023F204
/* 16D9D8 8023F0F8 27A40010 */   addiu    $a0, $sp, 0x10
/* 16D9DC 8023F0FC 24140001 */  addiu     $s4, $zero, 1
/* 16D9E0 8023F100 27A50014 */  addiu     $a1, $sp, 0x14
/* 16D9E4 8023F104 27A60018 */  addiu     $a2, $sp, 0x18
/* 16D9E8 8023F108 0C046EF6 */  jal       get_world_fog_color
/* 16D9EC 8023F10C 27A7001C */   addiu    $a3, $sp, 0x1c
/* 16D9F0 8023F110 27A40020 */  addiu     $a0, $sp, 0x20
/* 16D9F4 8023F114 27A50021 */  addiu     $a1, $sp, 0x21
/* 16D9F8 8023F118 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 16D9FC 8023F11C 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 16DA00 8023F120 27A60022 */  addiu     $a2, $sp, 0x22
/* 16DA04 8023F124 9442015C */  lhu       $v0, 0x15c($v0)
/* 16DA08 8023F128 27A70023 */  addiu     $a3, $sp, 0x23
/* 16DA0C 8023F12C 0C046FA0 */  jal       get_background_color_blend
/* 16DA10 8023F130 AFA2001C */   sw       $v0, 0x1c($sp)
/* 16DA14 8023F134 8FA3001C */  lw        $v1, 0x1c($sp)
/* 16DA18 8023F138 240200FF */  addiu     $v0, $zero, 0xff
/* 16DA1C 8023F13C 1462000B */  bne       $v1, $v0, .L8023F16C
/* 16DA20 8023F140 0000902D */   daddu    $s2, $zero, $zero
/* 16DA24 8023F144 0280182D */  daddu     $v1, $s4, $zero
/* 16DA28 8023F148 0040902D */  daddu     $s2, $v0, $zero
/* 16DA2C 8023F14C 3C02802A */  lui       $v0, %hi(D_8029F236)
/* 16DA30 8023F150 2442F236 */  addiu     $v0, $v0, %lo(D_8029F236)
.L8023F154:
/* 16DA34 8023F154 A4430000 */  sh        $v1, ($v0)
/* 16DA38 8023F158 2652FFFF */  addiu     $s2, $s2, -1
/* 16DA3C 8023F15C 0641FFFD */  bgez      $s2, .L8023F154
/* 16DA40 8023F160 2442FFFE */   addiu    $v0, $v0, -2
/* 16DA44 8023F164 0808FC81 */  j         .L8023F204
/* 16DA48 8023F168 00000000 */   nop
.L8023F16C:
/* 16DA4C 8023F16C 3C13802A */  lui       $s3, %hi(D_8029F038)
/* 16DA50 8023F170 2673F038 */  addiu     $s3, $s3, %lo(D_8029F038)
.L8023F174:
/* 16DA54 8023F174 00121840 */  sll       $v1, $s2, 1
/* 16DA58 8023F178 26520001 */  addiu     $s2, $s2, 1
/* 16DA5C 8023F17C 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 16DA60 8023F180 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 16DA64 8023F184 8FA6001C */  lw        $a2, 0x1c($sp)
/* 16DA68 8023F188 8C420158 */  lw        $v0, 0x158($v0)
/* 16DA6C 8023F18C 8FA50018 */  lw        $a1, 0x18($sp)
/* 16DA70 8023F190 00621821 */  addu      $v1, $v1, $v0
/* 16DA74 8023F194 94700000 */  lhu       $s0, ($v1)
/* 16DA78 8023F198 000528C3 */  sra       $a1, $a1, 3
/* 16DA7C 8023F19C 00102042 */  srl       $a0, $s0, 1
/* 16DA80 8023F1A0 0C08FC18 */  jal       func_8023F060
/* 16DA84 8023F1A4 3084001F */   andi     $a0, $a0, 0x1f
/* 16DA88 8023F1A8 00102182 */  srl       $a0, $s0, 6
/* 16DA8C 8023F1AC 3084001F */  andi      $a0, $a0, 0x1f
/* 16DA90 8023F1B0 0040882D */  daddu     $s1, $v0, $zero
/* 16DA94 8023F1B4 8FA50014 */  lw        $a1, 0x14($sp)
/* 16DA98 8023F1B8 8FA6001C */  lw        $a2, 0x1c($sp)
/* 16DA9C 8023F1BC 0C08FC18 */  jal       func_8023F060
/* 16DAA0 8023F1C0 000528C3 */   sra      $a1, $a1, 3
/* 16DAA4 8023F1C4 001022C2 */  srl       $a0, $s0, 0xb
/* 16DAA8 8023F1C8 0040802D */  daddu     $s0, $v0, $zero
/* 16DAAC 8023F1CC 8FA50010 */  lw        $a1, 0x10($sp)
/* 16DAB0 8023F1D0 8FA6001C */  lw        $a2, 0x1c($sp)
/* 16DAB4 8023F1D4 0C08FC18 */  jal       func_8023F060
/* 16DAB8 8023F1D8 000528C3 */   sra      $a1, $a1, 3
/* 16DABC 8023F1DC 00118840 */  sll       $s1, $s1, 1
/* 16DAC0 8023F1E0 00108180 */  sll       $s0, $s0, 6
/* 16DAC4 8023F1E4 02308825 */  or        $s1, $s1, $s0
/* 16DAC8 8023F1E8 000212C0 */  sll       $v0, $v0, 0xb
/* 16DACC 8023F1EC 02228825 */  or        $s1, $s1, $v0
/* 16DAD0 8023F1F0 36310001 */  ori       $s1, $s1, 1
/* 16DAD4 8023F1F4 A6710000 */  sh        $s1, ($s3)
/* 16DAD8 8023F1F8 2A420100 */  slti      $v0, $s2, 0x100
/* 16DADC 8023F1FC 1440FFDD */  bnez      $v0, .L8023F174
/* 16DAE0 8023F200 26730002 */   addiu    $s3, $s3, 2
.L8023F204:
/* 16DAE4 8023F204 3C0D8007 */  lui       $t5, %hi(gGameStatusPtr)
/* 16DAE8 8023F208 8DAD419C */  lw        $t5, %lo(gGameStatusPtr)($t5)
/* 16DAEC 8023F20C 95A20148 */  lhu       $v0, 0x148($t5)
/* 16DAF0 8023F210 30420001 */  andi      $v0, $v0, 1
/* 16DAF4 8023F214 104001ED */  beqz      $v0, .L8023F9CC
/* 16DAF8 8023F218 3C03E300 */   lui      $v1, 0xe300
/* 16DAFC 8023F21C 34630A01 */  ori       $v1, $v1, 0xa01
/* 16DB00 8023F220 3C04E300 */  lui       $a0, 0xe300
/* 16DB04 8023F224 34840C00 */  ori       $a0, $a0, 0xc00
/* 16DB08 8023F228 3C05E300 */  lui       $a1, 0xe300
/* 16DB0C 8023F22C 34A51001 */  ori       $a1, $a1, 0x1001
/* 16DB10 8023F230 3C09FCFF */  lui       $t1, 0xfcff
/* 16DB14 8023F234 3529FFFF */  ori       $t1, $t1, 0xffff
/* 16DB18 8023F238 3C08FFFC */  lui       $t0, 0xfffc
/* 16DB1C 8023F23C 3508F87C */  ori       $t0, $t0, 0xf87c
/* 16DB20 8023F240 3C06E200 */  lui       $a2, 0xe200
/* 16DB24 8023F244 34C6001C */  ori       $a2, $a2, 0x1c
/* 16DB28 8023F248 3C07E300 */  lui       $a3, 0xe300
/* 16DB2C 8023F24C 3C0B800A */  lui       $t3, %hi(gMasterGfxPos)
/* 16DB30 8023F250 256BA66C */  addiu     $t3, $t3, %lo(gMasterGfxPos)
/* 16DB34 8023F254 34E71201 */  ori       $a3, $a3, 0x1201
/* 16DB38 8023F258 3C0CE700 */  lui       $t4, 0xe700
/* 16DB3C 8023F25C 8D6A0000 */  lw        $t2, ($t3)
/* 16DB40 8023F260 3C014080 */  lui       $at, 0x4080
/* 16DB44 8023F264 44812000 */  mtc1      $at, $f4
/* 16DB48 8023F268 0140102D */  daddu     $v0, $t2, $zero
/* 16DB4C 8023F26C 254A0008 */  addiu     $t2, $t2, 8
/* 16DB50 8023F270 AD6A0000 */  sw        $t2, ($t3)
/* 16DB54 8023F274 AC4C0000 */  sw        $t4, ($v0)
/* 16DB58 8023F278 AC400004 */  sw        $zero, 4($v0)
/* 16DB5C 8023F27C 25420008 */  addiu     $v0, $t2, 8
/* 16DB60 8023F280 AD620000 */  sw        $v0, ($t3)
/* 16DB64 8023F284 3C020020 */  lui       $v0, 0x20
/* 16DB68 8023F288 AD420004 */  sw        $v0, 4($t2)
/* 16DB6C 8023F28C 25420010 */  addiu     $v0, $t2, 0x10
/* 16DB70 8023F290 AD430000 */  sw        $v1, ($t2)
/* 16DB74 8023F294 AD620000 */  sw        $v0, ($t3)
/* 16DB78 8023F298 25420018 */  addiu     $v0, $t2, 0x18
/* 16DB7C 8023F29C AD440008 */  sw        $a0, 8($t2)
/* 16DB80 8023F2A0 AD40000C */  sw        $zero, 0xc($t2)
/* 16DB84 8023F2A4 AD620000 */  sw        $v0, ($t3)
/* 16DB88 8023F2A8 34028000 */  ori       $v0, $zero, 0x8000
/* 16DB8C 8023F2AC AD420014 */  sw        $v0, 0x14($t2)
/* 16DB90 8023F2B0 25420020 */  addiu     $v0, $t2, 0x20
/* 16DB94 8023F2B4 AD450010 */  sw        $a1, 0x10($t2)
/* 16DB98 8023F2B8 AD620000 */  sw        $v0, ($t3)
/* 16DB9C 8023F2BC AD490018 */  sw        $t1, 0x18($t2)
/* 16DBA0 8023F2C0 AD48001C */  sw        $t0, 0x1c($t2)
/* 16DBA4 8023F2C4 AD460020 */  sw        $a2, 0x20($t2)
/* 16DBA8 8023F2C8 AD400024 */  sw        $zero, 0x24($t2)
/* 16DBAC 8023F2CC AD470028 */  sw        $a3, 0x28($t2)
/* 16DBB0 8023F2D0 AD40002C */  sw        $zero, 0x2c($t2)
/* 16DBB4 8023F2D4 86E2000E */  lh        $v0, 0xe($s7)
/* 16DBB8 8023F2D8 25430028 */  addiu     $v1, $t2, 0x28
/* 16DBBC 8023F2DC AD630000 */  sw        $v1, ($t3)
/* 16DBC0 8023F2E0 44821000 */  mtc1      $v0, $f2
/* 16DBC4 8023F2E4 00000000 */  nop
/* 16DBC8 8023F2E8 468010A0 */  cvt.s.w   $f2, $f2
/* 16DBCC 8023F2EC 46041082 */  mul.s     $f2, $f2, $f4
/* 16DBD0 8023F2F0 00000000 */  nop
/* 16DBD4 8023F2F4 25430030 */  addiu     $v1, $t2, 0x30
/* 16DBD8 8023F2F8 86E20010 */  lh        $v0, 0x10($s7)
/* 16DBDC 8023F2FC 3C04ED00 */  lui       $a0, 0xed00
/* 16DBE0 8023F300 44820000 */  mtc1      $v0, $f0
/* 16DBE4 8023F304 00000000 */  nop
/* 16DBE8 8023F308 46800020 */  cvt.s.w   $f0, $f0
/* 16DBEC 8023F30C 46040002 */  mul.s     $f0, $f0, $f4
/* 16DBF0 8023F310 00000000 */  nop
/* 16DBF4 8023F314 AD630000 */  sw        $v1, ($t3)
/* 16DBF8 8023F318 4600118D */  trunc.w.s $f6, $f2
/* 16DBFC 8023F31C 44023000 */  mfc1      $v0, $f6
/* 16DC00 8023F320 00000000 */  nop
/* 16DC04 8023F324 30420FFF */  andi      $v0, $v0, 0xfff
/* 16DC08 8023F328 00021300 */  sll       $v0, $v0, 0xc
/* 16DC0C 8023F32C 4600018D */  trunc.w.s $f6, $f0
/* 16DC10 8023F330 44033000 */  mfc1      $v1, $f6
/* 16DC14 8023F334 00000000 */  nop
/* 16DC18 8023F338 30630FFF */  andi      $v1, $v1, 0xfff
/* 16DC1C 8023F33C 00641825 */  or        $v1, $v1, $a0
/* 16DC20 8023F340 00431025 */  or        $v0, $v0, $v1
/* 16DC24 8023F344 AD420030 */  sw        $v0, 0x30($t2)
/* 16DC28 8023F348 86E2000E */  lh        $v0, 0xe($s7)
/* 16DC2C 8023F34C 86E4000A */  lh        $a0, 0xa($s7)
/* 16DC30 8023F350 25430038 */  addiu     $v1, $t2, 0x38
/* 16DC34 8023F354 AD630000 */  sw        $v1, ($t3)
/* 16DC38 8023F358 86E3000C */  lh        $v1, 0xc($s7)
/* 16DC3C 8023F35C 00441021 */  addu      $v0, $v0, $a0
/* 16DC40 8023F360 2442FFFF */  addiu     $v0, $v0, -1
/* 16DC44 8023F364 44821000 */  mtc1      $v0, $f2
/* 16DC48 8023F368 00000000 */  nop
/* 16DC4C 8023F36C 468010A0 */  cvt.s.w   $f2, $f2
/* 16DC50 8023F370 25440040 */  addiu     $a0, $t2, 0x40
/* 16DC54 8023F374 86E20010 */  lh        $v0, 0x10($s7)
/* 16DC58 8023F378 46041082 */  mul.s     $f2, $f2, $f4
/* 16DC5C 8023F37C 00000000 */  nop
/* 16DC60 8023F380 AD640000 */  sw        $a0, ($t3)
/* 16DC64 8023F384 00431021 */  addu      $v0, $v0, $v1
/* 16DC68 8023F388 2442FFFF */  addiu     $v0, $v0, -1
/* 16DC6C 8023F38C 44820000 */  mtc1      $v0, $f0
/* 16DC70 8023F390 00000000 */  nop
/* 16DC74 8023F394 46800020 */  cvt.s.w   $f0, $f0
/* 16DC78 8023F398 46040002 */  mul.s     $f0, $f0, $f4
/* 16DC7C 8023F39C 00000000 */  nop
/* 16DC80 8023F3A0 AD4C0038 */  sw        $t4, 0x38($t2)
/* 16DC84 8023F3A4 4600118D */  trunc.w.s $f6, $f2
/* 16DC88 8023F3A8 44023000 */  mfc1      $v0, $f6
/* 16DC8C 8023F3AC 00000000 */  nop
/* 16DC90 8023F3B0 30420FFF */  andi      $v0, $v0, 0xfff
/* 16DC94 8023F3B4 00021300 */  sll       $v0, $v0, 0xc
/* 16DC98 8023F3B8 4600018D */  trunc.w.s $f6, $f0
/* 16DC9C 8023F3BC 44033000 */  mfc1      $v1, $f6
/* 16DCA0 8023F3C0 00000000 */  nop
/* 16DCA4 8023F3C4 30630FFF */  andi      $v1, $v1, 0xfff
/* 16DCA8 8023F3C8 00431025 */  or        $v0, $v0, $v1
/* 16DCAC 8023F3CC AD420034 */  sw        $v0, 0x34($t2)
/* 16DCB0 8023F3D0 16800024 */  bnez      $s4, .L8023F464
/* 16DCB4 8023F3D4 AD40003C */   sw       $zero, 0x3c($t2)
/* 16DCB8 8023F3D8 3C03F500 */  lui       $v1, 0xf500
/* 16DCBC 8023F3DC 34630100 */  ori       $v1, $v1, 0x100
/* 16DCC0 8023F3E0 3C05073F */  lui       $a1, 0x73f
/* 16DCC4 8023F3E4 34A5C000 */  ori       $a1, $a1, 0xc000
/* 16DCC8 8023F3E8 25420048 */  addiu     $v0, $t2, 0x48
/* 16DCCC 8023F3EC AD620000 */  sw        $v0, ($t3)
/* 16DCD0 8023F3F0 3C02FD10 */  lui       $v0, 0xfd10
/* 16DCD4 8023F3F4 AD420040 */  sw        $v0, 0x40($t2)
/* 16DCD8 8023F3F8 25420050 */  addiu     $v0, $t2, 0x50
/* 16DCDC 8023F3FC AD620000 */  sw        $v0, ($t3)
/* 16DCE0 8023F400 8DA40158 */  lw        $a0, 0x158($t5)
/* 16DCE4 8023F404 3C02E800 */  lui       $v0, 0xe800
/* 16DCE8 8023F408 AD420048 */  sw        $v0, 0x48($t2)
/* 16DCEC 8023F40C 25420058 */  addiu     $v0, $t2, 0x58
/* 16DCF0 8023F410 AD40004C */  sw        $zero, 0x4c($t2)
/* 16DCF4 8023F414 AD620000 */  sw        $v0, ($t3)
/* 16DCF8 8023F418 3C020700 */  lui       $v0, 0x700
/* 16DCFC 8023F41C AD420054 */  sw        $v0, 0x54($t2)
/* 16DD00 8023F420 25420060 */  addiu     $v0, $t2, 0x60
/* 16DD04 8023F424 AD430050 */  sw        $v1, 0x50($t2)
/* 16DD08 8023F428 AD620000 */  sw        $v0, ($t3)
/* 16DD0C 8023F42C 3C02E600 */  lui       $v0, 0xe600
/* 16DD10 8023F430 AD420058 */  sw        $v0, 0x58($t2)
/* 16DD14 8023F434 25420068 */  addiu     $v0, $t2, 0x68
/* 16DD18 8023F438 AD40005C */  sw        $zero, 0x5c($t2)
/* 16DD1C 8023F43C AD620000 */  sw        $v0, ($t3)
/* 16DD20 8023F440 3C02F000 */  lui       $v0, 0xf000
/* 16DD24 8023F444 AD420060 */  sw        $v0, 0x60($t2)
/* 16DD28 8023F448 25420070 */  addiu     $v0, $t2, 0x70
/* 16DD2C 8023F44C AD450064 */  sw        $a1, 0x64($t2)
/* 16DD30 8023F450 AD620000 */  sw        $v0, ($t3)
/* 16DD34 8023F454 AD4C0068 */  sw        $t4, 0x68($t2)
/* 16DD38 8023F458 AD40006C */  sw        $zero, 0x6c($t2)
/* 16DD3C 8023F45C 0808FD3C */  j         .L8023F4F0
/* 16DD40 8023F460 AD440044 */   sw       $a0, 0x44($t2)
.L8023F464:
/* 16DD44 8023F464 3C03F500 */  lui       $v1, 0xf500
/* 16DD48 8023F468 34630100 */  ori       $v1, $v1, 0x100
/* 16DD4C 8023F46C 3C04073F */  lui       $a0, 0x73f
/* 16DD50 8023F470 3484C000 */  ori       $a0, $a0, 0xc000
/* 16DD54 8023F474 25420048 */  addiu     $v0, $t2, 0x48
/* 16DD58 8023F478 AD620000 */  sw        $v0, ($t3)
/* 16DD5C 8023F47C 3C02FD10 */  lui       $v0, 0xfd10
/* 16DD60 8023F480 AD420040 */  sw        $v0, 0x40($t2)
/* 16DD64 8023F484 3C02802A */  lui       $v0, %hi(D_8029F038)
/* 16DD68 8023F488 2442F038 */  addiu     $v0, $v0, %lo(D_8029F038)
/* 16DD6C 8023F48C AD420044 */  sw        $v0, 0x44($t2)
/* 16DD70 8023F490 25420050 */  addiu     $v0, $t2, 0x50
/* 16DD74 8023F494 AD620000 */  sw        $v0, ($t3)
/* 16DD78 8023F498 3C02E800 */  lui       $v0, 0xe800
/* 16DD7C 8023F49C AD420048 */  sw        $v0, 0x48($t2)
/* 16DD80 8023F4A0 25420058 */  addiu     $v0, $t2, 0x58
/* 16DD84 8023F4A4 AD40004C */  sw        $zero, 0x4c($t2)
/* 16DD88 8023F4A8 AD620000 */  sw        $v0, ($t3)
/* 16DD8C 8023F4AC 3C020700 */  lui       $v0, 0x700
/* 16DD90 8023F4B0 AD420054 */  sw        $v0, 0x54($t2)
/* 16DD94 8023F4B4 25420060 */  addiu     $v0, $t2, 0x60
/* 16DD98 8023F4B8 AD430050 */  sw        $v1, 0x50($t2)
/* 16DD9C 8023F4BC AD620000 */  sw        $v0, ($t3)
/* 16DDA0 8023F4C0 3C02E600 */  lui       $v0, 0xe600
/* 16DDA4 8023F4C4 AD420058 */  sw        $v0, 0x58($t2)
/* 16DDA8 8023F4C8 25420068 */  addiu     $v0, $t2, 0x68
/* 16DDAC 8023F4CC AD40005C */  sw        $zero, 0x5c($t2)
/* 16DDB0 8023F4D0 AD620000 */  sw        $v0, ($t3)
/* 16DDB4 8023F4D4 3C02F000 */  lui       $v0, 0xf000
/* 16DDB8 8023F4D8 AD420060 */  sw        $v0, 0x60($t2)
/* 16DDBC 8023F4DC 25420070 */  addiu     $v0, $t2, 0x70
/* 16DDC0 8023F4E0 AD440064 */  sw        $a0, 0x64($t2)
/* 16DDC4 8023F4E4 AD620000 */  sw        $v0, ($t3)
/* 16DDC8 8023F4E8 AD4C0068 */  sw        $t4, 0x68($t2)
/* 16DDCC 8023F4EC AD40006C */  sw        $zero, 0x6c($t2)
.L8023F4F0:
/* 16DDD0 8023F4F0 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* 16DDD4 8023F4F4 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* 16DDD8 8023F4F8 846E014E */  lh        $t6, 0x14e($v1)
/* 16DDDC 8023F4FC 24020800 */  addiu     $v0, $zero, 0x800
/* 16DDE0 8023F500 15C00002 */  bnez      $t6, .L8023F50C
/* 16DDE4 8023F504 004E001A */   div      $zero, $v0, $t6
/* 16DDE8 8023F508 0007000D */  break     7
.L8023F50C:
/* 16DDEC 8023F50C 2401FFFF */   addiu    $at, $zero, -1
/* 16DDF0 8023F510 15C10004 */  bne       $t6, $at, .L8023F524
/* 16DDF4 8023F514 3C018000 */   lui      $at, 0x8000
/* 16DDF8 8023F518 14410002 */  bne       $v0, $at, .L8023F524
/* 16DDFC 8023F51C 00000000 */   nop
/* 16DE00 8023F520 0006000D */  break     6
.L8023F524:
/* 16DE04 8023F524 00006812 */   mflo     $t5
/* 16DE08 8023F528 84630150 */  lh        $v1, 0x150($v1)
/* 16DE0C 8023F52C 15A00002 */  bnez      $t5, .L8023F538
/* 16DE10 8023F530 006D001A */   div      $zero, $v1, $t5
/* 16DE14 8023F534 0007000D */  break     7
.L8023F538:
/* 16DE18 8023F538 2401FFFF */   addiu    $at, $zero, -1
/* 16DE1C 8023F53C 15A10004 */  bne       $t5, $at, .L8023F550
/* 16DE20 8023F540 3C018000 */   lui      $at, 0x8000
/* 16DE24 8023F544 14610002 */  bne       $v1, $at, .L8023F550
/* 16DE28 8023F548 00000000 */   nop
/* 16DE2C 8023F54C 0006000D */  break     6
.L8023F550:
/* 16DE30 8023F550 0000B012 */   mflo     $s6
/* 16DE34 8023F554 0000A810 */  mfhi      $s5
/* 16DE38 8023F558 AFA00028 */  sw        $zero, 0x28($sp)
/* 16DE3C 8023F55C AFA30024 */  sw        $v1, 0x24($sp)
/* 16DE40 8023F560 AFB5002C */  sw        $s5, 0x2c($sp)
/* 16DE44 8023F564 86F8000E */  lh        $t8, 0xe($s7)
/* 16DE48 8023F568 86F90010 */  lh        $t9, 0x10($s7)
/* 16DE4C 8023F56C 1AC0008F */  blez      $s6, .L8023F7AC
/* 16DE50 8023F570 0000902D */   daddu    $s2, $zero, $zero
/* 16DE54 8023F574 3C0A800A */  lui       $t2, %hi(gMasterGfxPos)
/* 16DE58 8023F578 254AA66C */  addiu     $t2, $t2, %lo(gMasterGfxPos)
/* 16DE5C 8023F57C 25C2FFFF */  addiu     $v0, $t6, -1
/* 16DE60 8023F580 30420FFF */  andi      $v0, $v0, 0xfff
/* 16DE64 8023F584 3C03FD48 */  lui       $v1, 0xfd48
/* 16DE68 8023F588 00431025 */  or        $v0, $v0, $v1
/* 16DE6C 8023F58C 3C14F548 */  lui       $s4, 0xf548
/* 16DE70 8023F590 36944A00 */  ori       $s4, $s4, 0x4a00
/* 16DE74 8023F594 AFA20030 */  sw        $v0, 0x30($sp)
/* 16DE78 8023F598 2702FFFF */  addiu     $v0, $t8, -1
/* 16DE7C 8023F59C 00021080 */  sll       $v0, $v0, 2
/* 16DE80 8023F5A0 30420FFF */  andi      $v0, $v0, 0xfff
/* 16DE84 8023F5A4 00021300 */  sll       $v0, $v0, 0xc
/* 16DE88 8023F5A8 000EAD40 */  sll       $s5, $t6, 0x15
/* 16DE8C 8023F5AC 3C1EF100 */  lui       $fp, 0xf100
/* 16DE90 8023F5B0 3C131000 */  lui       $s3, 0x1000
/* 16DE94 8023F5B4 36730400 */  ori       $s3, $s3, 0x400
/* 16DE98 8023F5B8 AFA20034 */  sw        $v0, 0x34($sp)
/* 16DE9C 8023F5BC 01D81021 */  addu      $v0, $t6, $t8
/* 16DEA0 8023F5C0 2442FFFF */  addiu     $v0, $v0, -1
/* 16DEA4 8023F5C4 00021080 */  sll       $v0, $v0, 2
/* 16DEA8 8023F5C8 30420FFF */  andi      $v0, $v0, 0xfff
/* 16DEAC 8023F5CC 00021300 */  sll       $v0, $v0, 0xc
/* 16DEB0 8023F5D0 AFA2003C */  sw        $v0, 0x3c($sp)
/* 16DEB4 8023F5D4 00181080 */  sll       $v0, $t8, 2
/* 16DEB8 8023F5D8 30420FFF */  andi      $v0, $v0, 0xfff
/* 16DEBC 8023F5DC 00021300 */  sll       $v0, $v0, 0xc
/* 16DEC0 8023F5E0 AFB50038 */  sw        $s5, 0x38($sp)
/* 16DEC4 8023F5E4 0040A82D */  daddu     $s5, $v0, $zero
/* 16DEC8 8023F5E8 0320882D */  daddu     $s1, $t9, $zero
/* 16DECC 8023F5EC 01A0802D */  daddu     $s0, $t5, $zero
/* 16DED0 8023F5F0 0240782D */  daddu     $t7, $s2, $zero
/* 16DED4 8023F5F4 AFA20050 */  sw        $v0, 0x50($sp)
/* 16DED8 8023F5F8 AFB50040 */  sw        $s5, 0x40($sp)
.L8023F5FC:
/* 16DEDC 8023F5FC 3C028028 */  lui       $v0, %hi(D_802809FA)
/* 16DEE0 8023F600 944209FA */  lhu       $v0, %lo(D_802809FA)($v0)
/* 16DEE4 8023F604 3C0C8007 */  lui       $t4, %hi(gGameStatusPtr)
/* 16DEE8 8023F608 8D8C419C */  lw        $t4, %lo(gGameStatusPtr)($t4)
/* 16DEEC 8023F60C 004F2021 */  addu      $a0, $v0, $t7
/* 16DEF0 8023F610 00041400 */  sll       $v0, $a0, 0x10
/* 16DEF4 8023F614 85830150 */  lh        $v1, 0x150($t4)
/* 16DEF8 8023F618 00021403 */  sra       $v0, $v0, 0x10
/* 16DEFC 8023F61C 0062182A */  slt       $v1, $v1, $v0
/* 16DF00 8023F620 95820150 */  lhu       $v0, 0x150($t4)
/* 16DF04 8023F624 10600002 */  beqz      $v1, .L8023F630
/* 16DF08 8023F628 0080582D */   daddu    $t3, $a0, $zero
/* 16DF0C 8023F62C 00825823 */  subu      $t3, $a0, $v0
.L8023F630:
/* 16DF10 8023F630 3C080749 */  lui       $t0, 0x749
/* 16DF14 8023F634 3508C014 */  ori       $t0, $t0, 0xc014
/* 16DF18 8023F638 3C090049 */  lui       $t1, 0x49
/* 16DF1C 8023F63C 3529C014 */  ori       $t1, $t1, 0xc014
/* 16DF20 8023F640 00113080 */  sll       $a2, $s1, 2
/* 16DF24 8023F644 022D8821 */  addu      $s1, $s1, $t5
/* 16DF28 8023F648 2725FFFF */  addiu     $a1, $t9, -1
/* 16DF2C 8023F64C 02052821 */  addu      $a1, $s0, $a1
/* 16DF30 8023F650 020D8021 */  addu      $s0, $s0, $t5
/* 16DF34 8023F654 00052880 */  sll       $a1, $a1, 2
/* 16DF38 8023F658 8D430000 */  lw        $v1, ($t2)
/* 16DF3C 8023F65C 30A50FFF */  andi      $a1, $a1, 0xfff
/* 16DF40 8023F660 0060382D */  daddu     $a3, $v1, $zero
/* 16DF44 8023F664 24630008 */  addiu     $v1, $v1, 8
/* 16DF48 8023F668 24620008 */  addiu     $v0, $v1, 8
/* 16DF4C 8023F66C AD430000 */  sw        $v1, ($t2)
/* 16DF50 8023F670 8FB50030 */  lw        $s5, 0x30($sp)
/* 16DF54 8023F674 24640048 */  addiu     $a0, $v1, 0x48
/* 16DF58 8023F678 ACF50000 */  sw        $s5, ($a3)
/* 16DF5C 8023F67C AD420000 */  sw        $v0, ($t2)
/* 16DF60 8023F680 24620010 */  addiu     $v0, $v1, 0x10
/* 16DF64 8023F684 AD420000 */  sw        $v0, ($t2)
/* 16DF68 8023F688 24620018 */  addiu     $v0, $v1, 0x18
/* 16DF6C 8023F68C AD420000 */  sw        $v0, ($t2)
/* 16DF70 8023F690 24620020 */  addiu     $v0, $v1, 0x20
/* 16DF74 8023F694 AD420000 */  sw        $v0, ($t2)
/* 16DF78 8023F698 24620028 */  addiu     $v0, $v1, 0x28
/* 16DF7C 8023F69C AD420000 */  sw        $v0, ($t2)
/* 16DF80 8023F6A0 24620030 */  addiu     $v0, $v1, 0x30
/* 16DF84 8023F6A4 AD420000 */  sw        $v0, ($t2)
/* 16DF88 8023F6A8 24620038 */  addiu     $v0, $v1, 0x38
/* 16DF8C 8023F6AC AD420000 */  sw        $v0, ($t2)
/* 16DF90 8023F6B0 24620040 */  addiu     $v0, $v1, 0x40
/* 16DF94 8023F6B4 AD420000 */  sw        $v0, ($t2)
/* 16DF98 8023F6B8 000B1400 */  sll       $v0, $t3, 0x10
/* 16DF9C 8023F6BC 00021403 */  sra       $v0, $v0, 0x10
/* 16DFA0 8023F6C0 01C20018 */  mult      $t6, $v0
/* 16DFA4 8023F6C4 AD440000 */  sw        $a0, ($t2)
/* 16DFA8 8023F6C8 8D840154 */  lw        $a0, 0x154($t4)
/* 16DFAC 8023F6CC 24620050 */  addiu     $v0, $v1, 0x50
/* 16DFB0 8023F6D0 AD420000 */  sw        $v0, ($t2)
/* 16DFB4 8023F6D4 3C020700 */  lui       $v0, 0x700
/* 16DFB8 8023F6D8 0000A812 */  mflo      $s5
/* 16DFBC 8023F6DC 00952021 */  addu      $a0, $a0, $s5
/* 16DFC0 8023F6E0 ACE40004 */  sw        $a0, 4($a3)
/* 16DFC4 8023F6E4 AC620004 */  sw        $v0, 4($v1)
/* 16DFC8 8023F6E8 3C02E600 */  lui       $v0, 0xe600
/* 16DFCC 8023F6EC AC620008 */  sw        $v0, 8($v1)
/* 16DFD0 8023F6F0 3C02F400 */  lui       $v0, 0xf400
/* 16DFD4 8023F6F4 AC620010 */  sw        $v0, 0x10($v1)
/* 16DFD8 8023F6F8 3C02E700 */  lui       $v0, 0xe700
/* 16DFDC 8023F6FC AC620018 */  sw        $v0, 0x18($v1)
/* 16DFE0 8023F700 3C02F200 */  lui       $v0, 0xf200
/* 16DFE4 8023F704 AC620028 */  sw        $v0, 0x28($v1)
/* 16DFE8 8023F708 3C02E400 */  lui       $v0, 0xe400
/* 16DFEC 8023F70C AC740000 */  sw        $s4, ($v1)
/* 16DFF0 8023F710 AC60000C */  sw        $zero, 0xc($v1)
/* 16DFF4 8023F714 AC680014 */  sw        $t0, 0x14($v1)
/* 16DFF8 8023F718 AC60001C */  sw        $zero, 0x1c($v1)
/* 16DFFC 8023F71C AC740020 */  sw        $s4, 0x20($v1)
/* 16E000 8023F720 AC600024 */  sw        $zero, 0x24($v1)
/* 16E004 8023F724 AC69002C */  sw        $t1, 0x2c($v1)
/* 16E008 8023F728 8FB50034 */  lw        $s5, 0x34($sp)
/* 16E00C 8023F72C 00A22825 */  or        $a1, $a1, $v0
/* 16E010 8023F730 02A51025 */  or        $v0, $s5, $a1
/* 16E014 8023F734 AC620030 */  sw        $v0, 0x30($v1)
/* 16E018 8023F738 8FB50050 */  lw        $s5, 0x50($sp)
/* 16E01C 8023F73C 30C60FFF */  andi      $a2, $a2, 0xfff
/* 16E020 8023F740 02A61025 */  or        $v0, $s5, $a2
/* 16E024 8023F744 3C15E100 */  lui       $s5, 0xe100
/* 16E028 8023F748 AC620034 */  sw        $v0, 0x34($v1)
/* 16E02C 8023F74C AC750038 */  sw        $s5, 0x38($v1)
/* 16E030 8023F750 8FB50038 */  lw        $s5, 0x38($sp)
/* 16E034 8023F754 01ED7821 */  addu      $t7, $t7, $t5
/* 16E038 8023F758 AC75003C */  sw        $s5, 0x3c($v1)
/* 16E03C 8023F75C AC7E0040 */  sw        $fp, 0x40($v1)
/* 16E040 8023F760 AC730044 */  sw        $s3, 0x44($v1)
/* 16E044 8023F764 8FB5003C */  lw        $s5, 0x3c($sp)
/* 16E048 8023F768 26520001 */  addiu     $s2, $s2, 1
/* 16E04C 8023F76C 02A52825 */  or        $a1, $s5, $a1
/* 16E050 8023F770 AC650048 */  sw        $a1, 0x48($v1)
/* 16E054 8023F774 8FB50040 */  lw        $s5, 0x40($sp)
/* 16E058 8023F778 24620058 */  addiu     $v0, $v1, 0x58
/* 16E05C 8023F77C 02A63025 */  or        $a2, $s5, $a2
/* 16E060 8023F780 3C15E100 */  lui       $s5, 0xe100
/* 16E064 8023F784 AC66004C */  sw        $a2, 0x4c($v1)
/* 16E068 8023F788 AD420000 */  sw        $v0, ($t2)
/* 16E06C 8023F78C 24620060 */  addiu     $v0, $v1, 0x60
/* 16E070 8023F790 AC750050 */  sw        $s5, 0x50($v1)
/* 16E074 8023F794 AC600054 */  sw        $zero, 0x54($v1)
/* 16E078 8023F798 AD420000 */  sw        $v0, ($t2)
/* 16E07C 8023F79C 0256102A */  slt       $v0, $s2, $s6
/* 16E080 8023F7A0 AC7E0058 */  sw        $fp, 0x58($v1)
/* 16E084 8023F7A4 1440FF95 */  bnez      $v0, .L8023F5FC
/* 16E088 8023F7A8 AC73005C */   sw       $s3, 0x5c($v1)
.L8023F7AC:
/* 16E08C 8023F7AC 8FB5002C */  lw        $s5, 0x2c($sp)
/* 16E090 8023F7B0 12A00086 */  beqz      $s5, .L8023F9CC
/* 16E094 8023F7B4 01B20018 */   mult     $t5, $s2
/* 16E098 8023F7B8 3C0C8007 */  lui       $t4, %hi(gGameStatusPtr)
/* 16E09C 8023F7BC 8D8C419C */  lw        $t4, %lo(gGameStatusPtr)($t4)
/* 16E0A0 8023F7C0 3C028028 */  lui       $v0, %hi(D_802809FA)
/* 16E0A4 8023F7C4 944209FA */  lhu       $v0, %lo(D_802809FA)($v0)
/* 16E0A8 8023F7C8 85830150 */  lh        $v1, 0x150($t4)
/* 16E0AC 8023F7CC 00006812 */  mflo      $t5
/* 16E0B0 8023F7D0 004D2021 */  addu      $a0, $v0, $t5
/* 16E0B4 8023F7D4 00041400 */  sll       $v0, $a0, 0x10
/* 16E0B8 8023F7D8 00021403 */  sra       $v0, $v0, 0x10
/* 16E0BC 8023F7DC 0062182A */  slt       $v1, $v1, $v0
/* 16E0C0 8023F7E0 95820150 */  lhu       $v0, 0x150($t4)
/* 16E0C4 8023F7E4 10600002 */  beqz      $v1, .L8023F7F0
/* 16E0C8 8023F7E8 0080582D */   daddu    $t3, $a0, $zero
/* 16E0CC 8023F7EC 00825823 */  subu      $t3, $a0, $v0
.L8023F7F0:
/* 16E0D0 8023F7F0 3C08F548 */  lui       $t0, 0xf548
/* 16E0D4 8023F7F4 35084A00 */  ori       $t0, $t0, 0x4a00
/* 16E0D8 8023F7F8 3C050749 */  lui       $a1, 0x749
/* 16E0DC 8023F7FC 34A5C000 */  ori       $a1, $a1, 0xc000
/* 16E0E0 8023F800 3C090049 */  lui       $t1, 0x49
/* 16E0E4 8023F804 3529C000 */  ori       $t1, $t1, 0xc000
/* 16E0E8 8023F808 3C0A1000 */  lui       $t2, 0x1000
/* 16E0EC 8023F80C 3C07800A */  lui       $a3, %hi(gMasterGfxPos)
/* 16E0F0 8023F810 24E7A66C */  addiu     $a3, $a3, %lo(gMasterGfxPos)
/* 16E0F4 8023F814 354A0400 */  ori       $t2, $t2, 0x400
/* 16E0F8 8023F818 25C2FFFF */  addiu     $v0, $t6, -1
/* 16E0FC 8023F81C 30420FFF */  andi      $v0, $v0, 0xfff
/* 16E100 8023F820 3C03FD48 */  lui       $v1, 0xfd48
/* 16E104 8023F824 8CE40000 */  lw        $a0, ($a3)
/* 16E108 8023F828 00431025 */  or        $v0, $v0, $v1
/* 16E10C 8023F82C 0080302D */  daddu     $a2, $a0, $zero
/* 16E110 8023F830 24840008 */  addiu     $a0, $a0, 8
/* 16E114 8023F834 ACE40000 */  sw        $a0, ($a3)
/* 16E118 8023F838 ACC20000 */  sw        $v0, ($a2)
/* 16E11C 8023F83C 24820008 */  addiu     $v0, $a0, 8
/* 16E120 8023F840 ACE20000 */  sw        $v0, ($a3)
/* 16E124 8023F844 24820010 */  addiu     $v0, $a0, 0x10
/* 16E128 8023F848 ACE20000 */  sw        $v0, ($a3)
/* 16E12C 8023F84C 24820018 */  addiu     $v0, $a0, 0x18
/* 16E130 8023F850 ACE20000 */  sw        $v0, ($a3)
/* 16E134 8023F854 24820020 */  addiu     $v0, $a0, 0x20
/* 16E138 8023F858 ACE20000 */  sw        $v0, ($a3)
/* 16E13C 8023F85C 24820028 */  addiu     $v0, $a0, 0x28
/* 16E140 8023F860 ACE20000 */  sw        $v0, ($a3)
/* 16E144 8023F864 24820030 */  addiu     $v0, $a0, 0x30
/* 16E148 8023F868 ACE20000 */  sw        $v0, ($a3)
/* 16E14C 8023F86C 24820038 */  addiu     $v0, $a0, 0x38
/* 16E150 8023F870 ACE20000 */  sw        $v0, ($a3)
/* 16E154 8023F874 24820040 */  addiu     $v0, $a0, 0x40
/* 16E158 8023F878 ACE20000 */  sw        $v0, ($a3)
/* 16E15C 8023F87C 000B1400 */  sll       $v0, $t3, 0x10
/* 16E160 8023F880 00021403 */  sra       $v0, $v0, 0x10
/* 16E164 8023F884 24830048 */  addiu     $v1, $a0, 0x48
/* 16E168 8023F888 01C20018 */  mult      $t6, $v0
/* 16E16C 8023F88C ACE30000 */  sw        $v1, ($a3)
/* 16E170 8023F890 8D820154 */  lw        $v0, 0x154($t4)
/* 16E174 8023F894 24830050 */  addiu     $v1, $a0, 0x50
/* 16E178 8023F898 ACE30000 */  sw        $v1, ($a3)
/* 16E17C 8023F89C 0000A812 */  mflo      $s5
/* 16E180 8023F8A0 00551021 */  addu      $v0, $v0, $s5
/* 16E184 8023F8A4 ACC20004 */  sw        $v0, 4($a2)
/* 16E188 8023F8A8 3C020700 */  lui       $v0, 0x700
/* 16E18C 8023F8AC AC820004 */  sw        $v0, 4($a0)
/* 16E190 8023F8B0 3C02E600 */  lui       $v0, 0xe600
/* 16E194 8023F8B4 AC820008 */  sw        $v0, 8($a0)
/* 16E198 8023F8B8 3C02F400 */  lui       $v0, 0xf400
/* 16E19C 8023F8BC AC880000 */  sw        $t0, ($a0)
/* 16E1A0 8023F8C0 AC80000C */  sw        $zero, 0xc($a0)
/* 16E1A4 8023F8C4 AC820010 */  sw        $v0, 0x10($a0)
/* 16E1A8 8023F8C8 8FB5002C */  lw        $s5, 0x2c($sp)
/* 16E1AC 8023F8CC 3C03E700 */  lui       $v1, 0xe700
/* 16E1B0 8023F8D0 26A2FFFF */  addiu     $v0, $s5, -1
/* 16E1B4 8023F8D4 00021080 */  sll       $v0, $v0, 2
/* 16E1B8 8023F8D8 30420FFF */  andi      $v0, $v0, 0xfff
/* 16E1BC 8023F8DC 00452825 */  or        $a1, $v0, $a1
/* 16E1C0 8023F8E0 AC830018 */  sw        $v1, 0x18($a0)
/* 16E1C4 8023F8E4 3C03F200 */  lui       $v1, 0xf200
/* 16E1C8 8023F8E8 00491025 */  or        $v0, $v0, $t1
/* 16E1CC 8023F8EC AC850014 */  sw        $a1, 0x14($a0)
/* 16E1D0 8023F8F0 2725FFFF */  addiu     $a1, $t9, -1
/* 16E1D4 8023F8F4 AC830028 */  sw        $v1, 0x28($a0)
/* 16E1D8 8023F8F8 3C03E400 */  lui       $v1, 0xe400
/* 16E1DC 8023F8FC AC880020 */  sw        $t0, 0x20($a0)
/* 16E1E0 8023F900 3C08E100 */  lui       $t0, 0xe100
/* 16E1E4 8023F904 AC80001C */  sw        $zero, 0x1c($a0)
/* 16E1E8 8023F908 AC800024 */  sw        $zero, 0x24($a0)
/* 16E1EC 8023F90C AC82002C */  sw        $v0, 0x2c($a0)
/* 16E1F0 8023F910 8FB50028 */  lw        $s5, 0x28($sp)
/* 16E1F4 8023F914 3C09F100 */  lui       $t1, 0xf100
/* 16E1F8 8023F918 02B83021 */  addu      $a2, $s5, $t8
/* 16E1FC 8023F91C 24C2FFFF */  addiu     $v0, $a2, -1
/* 16E200 8023F920 00021080 */  sll       $v0, $v0, 2
/* 16E204 8023F924 30420FFF */  andi      $v0, $v0, 0xfff
/* 16E208 8023F928 00021300 */  sll       $v0, $v0, 0xc
/* 16E20C 8023F92C 00063080 */  sll       $a2, $a2, 2
/* 16E210 8023F930 30C60FFF */  andi      $a2, $a2, 0xfff
/* 16E214 8023F934 8FB50024 */  lw        $s5, 0x24($sp)
/* 16E218 8023F938 00063300 */  sll       $a2, $a2, 0xc
/* 16E21C 8023F93C 02A52821 */  addu      $a1, $s5, $a1
/* 16E220 8023F940 00052880 */  sll       $a1, $a1, 2
/* 16E224 8023F944 30A50FFF */  andi      $a1, $a1, 0xfff
/* 16E228 8023F948 00A32825 */  or        $a1, $a1, $v1
/* 16E22C 8023F94C 00451025 */  or        $v0, $v0, $a1
/* 16E230 8023F950 AC820030 */  sw        $v0, 0x30($a0)
/* 16E234 8023F954 00181080 */  sll       $v0, $t8, 2
/* 16E238 8023F958 30420FFF */  andi      $v0, $v0, 0xfff
/* 16E23C 8023F95C 00021300 */  sll       $v0, $v0, 0xc
/* 16E240 8023F960 01B91821 */  addu      $v1, $t5, $t9
/* 16E244 8023F964 00031880 */  sll       $v1, $v1, 2
/* 16E248 8023F968 30630FFF */  andi      $v1, $v1, 0xfff
/* 16E24C 8023F96C 00431025 */  or        $v0, $v0, $v1
/* 16E250 8023F970 AC820034 */  sw        $v0, 0x34($a0)
/* 16E254 8023F974 000E1540 */  sll       $v0, $t6, 0x15
/* 16E258 8023F978 AC82003C */  sw        $v0, 0x3c($a0)
/* 16E25C 8023F97C 01D81021 */  addu      $v0, $t6, $t8
/* 16E260 8023F980 2442FFFF */  addiu     $v0, $v0, -1
/* 16E264 8023F984 00021080 */  sll       $v0, $v0, 2
/* 16E268 8023F988 30420FFF */  andi      $v0, $v0, 0xfff
/* 16E26C 8023F98C 00021300 */  sll       $v0, $v0, 0xc
/* 16E270 8023F990 00451025 */  or        $v0, $v0, $a1
/* 16E274 8023F994 00C33025 */  or        $a2, $a2, $v1
/* 16E278 8023F998 AC880038 */  sw        $t0, 0x38($a0)
/* 16E27C 8023F99C AC890040 */  sw        $t1, 0x40($a0)
/* 16E280 8023F9A0 AC8A0044 */  sw        $t2, 0x44($a0)
/* 16E284 8023F9A4 AC820048 */  sw        $v0, 0x48($a0)
/* 16E288 8023F9A8 24820058 */  addiu     $v0, $a0, 0x58
/* 16E28C 8023F9AC AC86004C */  sw        $a2, 0x4c($a0)
/* 16E290 8023F9B0 ACE20000 */  sw        $v0, ($a3)
/* 16E294 8023F9B4 24820060 */  addiu     $v0, $a0, 0x60
/* 16E298 8023F9B8 AC880050 */  sw        $t0, 0x50($a0)
/* 16E29C 8023F9BC AC800054 */  sw        $zero, 0x54($a0)
/* 16E2A0 8023F9C0 ACE20000 */  sw        $v0, ($a3)
/* 16E2A4 8023F9C4 AC890058 */  sw        $t1, 0x58($a0)
/* 16E2A8 8023F9C8 AC8A005C */  sw        $t2, 0x5c($a0)
.L8023F9CC:
/* 16E2AC 8023F9CC 3C02DC08 */  lui       $v0, 0xdc08
/* 16E2B0 8023F9D0 34420008 */  ori       $v0, $v0, 8
/* 16E2B4 8023F9D4 3C04D9C0 */  lui       $a0, 0xd9c0
/* 16E2B8 8023F9D8 3484F9FB */  ori       $a0, $a0, 0xf9fb
/* 16E2BC 8023F9DC 3C15E300 */  lui       $s5, 0xe300
/* 16E2C0 8023F9E0 36B50A01 */  ori       $s5, $s5, 0xa01
/* 16E2C4 8023F9E4 3C05E300 */  lui       $a1, 0xe300
/* 16E2C8 8023F9E8 34A50800 */  ori       $a1, $a1, 0x800
/* 16E2CC 8023F9EC 3C07E300 */  lui       $a3, 0xe300
/* 16E2D0 8023F9F0 34E70F00 */  ori       $a3, $a3, 0xf00
/* 16E2D4 8023F9F4 3C08E300 */  lui       $t0, 0xe300
/* 16E2D8 8023F9F8 35081001 */  ori       $t0, $t0, 0x1001
/* 16E2DC 8023F9FC 3C09E300 */  lui       $t1, 0xe300
/* 16E2E0 8023FA00 35290D01 */  ori       $t1, $t1, 0xd01
/* 16E2E4 8023FA04 3C0AE300 */  lui       $t2, 0xe300
/* 16E2E8 8023FA08 354A0C00 */  ori       $t2, $t2, 0xc00
/* 16E2EC 8023FA0C 3C0BE300 */  lui       $t3, 0xe300
/* 16E2F0 8023FA10 356B1201 */  ori       $t3, $t3, 0x1201
/* 16E2F4 8023FA14 3C0CE300 */  lui       $t4, 0xe300
/* 16E2F8 8023FA18 358C1402 */  ori       $t4, $t4, 0x1402
/* 16E2FC 8023FA1C 3C0EFCFF */  lui       $t6, 0xfcff
/* 16E300 8023FA20 35CEFFFF */  ori       $t6, $t6, 0xffff
/* 16E304 8023FA24 3C0DFFFE */  lui       $t5, 0xfffe
/* 16E308 8023FA28 35AD793C */  ori       $t5, $t5, 0x793c
/* 16E30C 8023FA2C 3C0FE300 */  lui       $t7, 0xe300
/* 16E310 8023FA30 35EF1700 */  ori       $t7, $t7, 0x1700
/* 16E314 8023FA34 3C11E200 */  lui       $s1, 0xe200
/* 16E318 8023FA38 36311E01 */  ori       $s1, $s1, 0x1e01
/* 16E31C 8023FA3C 3C12E200 */  lui       $s2, 0xe200
/* 16E320 8023FA40 3652001C */  ori       $s2, $s2, 0x1c
/* 16E324 8023FA44 3C130F0A */  lui       $s3, 0xf0a
/* 16E328 8023FA48 36734000 */  ori       $s3, $s3, 0x4000
/* 16E32C 8023FA4C 3C14E300 */  lui       $s4, 0xe300
/* 16E330 8023FA50 36941801 */  ori       $s4, $s4, 0x1801
/* 16E334 8023FA54 AFB50044 */  sw        $s5, 0x44($sp)
/* 16E338 8023FA58 3C15DB04 */  lui       $s5, 0xdb04
/* 16E33C 8023FA5C 36B50004 */  ori       $s5, $s5, 4
/* 16E340 8023FA60 AFB50050 */  sw        $s5, 0x50($sp)
/* 16E344 8023FA64 3C15DB04 */  lui       $s5, 0xdb04
/* 16E348 8023FA68 36B5000C */  ori       $s5, $s5, 0xc
/* 16E34C 8023FA6C 3C18DB04 */  lui       $t8, 0xdb04
/* 16E350 8023FA70 37180014 */  ori       $t8, $t8, 0x14
/* 16E354 8023FA74 3C19DB04 */  lui       $t9, 0xdb04
/* 16E358 8023FA78 3739001C */  ori       $t9, $t9, 0x1c
/* 16E35C 8023FA7C 3C1E800A */  lui       $fp, %hi(gMasterGfxPos)
/* 16E360 8023FA80 27DEA66C */  addiu     $fp, $fp, %lo(gMasterGfxPos)
/* 16E364 8023FA84 3C16FF10 */  lui       $s6, 0xff10
/* 16E368 8023FA88 36D6013F */  ori       $s6, $s6, 0x13f
/* 16E36C 8023FA8C AFB50048 */  sw        $s5, 0x48($sp)
/* 16E370 8023FA90 8FD00000 */  lw        $s0, ($fp)
/* 16E374 8023FA94 3C014080 */  lui       $at, 0x4080
/* 16E378 8023FA98 44812000 */  mtc1      $at, $f4
/* 16E37C 8023FA9C 0200182D */  daddu     $v1, $s0, $zero
/* 16E380 8023FAA0 26100008 */  addiu     $s0, $s0, 8
/* 16E384 8023FAA4 AFD00000 */  sw        $s0, ($fp)
/* 16E388 8023FAA8 AC620000 */  sw        $v0, ($v1)
/* 16E38C 8023FAAC 26E200A0 */  addiu     $v0, $s7, 0xa0
/* 16E390 8023FAB0 AC620004 */  sw        $v0, 4($v1)
/* 16E394 8023FAB4 26020008 */  addiu     $v0, $s0, 8
/* 16E398 8023FAB8 AFC20000 */  sw        $v0, ($fp)
/* 16E39C 8023FABC 26020010 */  addiu     $v0, $s0, 0x10
/* 16E3A0 8023FAC0 AE040000 */  sw        $a0, ($s0)
/* 16E3A4 8023FAC4 AE000004 */  sw        $zero, 4($s0)
/* 16E3A8 8023FAC8 AFC20000 */  sw        $v0, ($fp)
/* 16E3AC 8023FACC 3C02D700 */  lui       $v0, 0xd700
/* 16E3B0 8023FAD0 AE020008 */  sw        $v0, 8($s0)
/* 16E3B4 8023FAD4 26020018 */  addiu     $v0, $s0, 0x18
/* 16E3B8 8023FAD8 AE00000C */  sw        $zero, 0xc($s0)
/* 16E3BC 8023FADC AFC20000 */  sw        $v0, ($fp)
/* 16E3C0 8023FAE0 26020020 */  addiu     $v0, $s0, 0x20
/* 16E3C4 8023FAE4 8FB50044 */  lw        $s5, 0x44($sp)
/* 16E3C8 8023FAE8 3C04ED00 */  lui       $a0, 0xed00
/* 16E3CC 8023FAEC AE000014 */  sw        $zero, 0x14($s0)
/* 16E3D0 8023FAF0 AE150010 */  sw        $s5, 0x10($s0)
/* 16E3D4 8023FAF4 AFC20000 */  sw        $v0, ($fp)
/* 16E3D8 8023FAF8 26020028 */  addiu     $v0, $s0, 0x28
/* 16E3DC 8023FAFC AE050018 */  sw        $a1, 0x18($s0)
/* 16E3E0 8023FB00 AE00001C */  sw        $zero, 0x1c($s0)
/* 16E3E4 8023FB04 AFC20000 */  sw        $v0, ($fp)
/* 16E3E8 8023FB08 86E2000E */  lh        $v0, 0xe($s7)
/* 16E3EC 8023FB0C 86E30010 */  lh        $v1, 0x10($s7)
/* 16E3F0 8023FB10 44821000 */  mtc1      $v0, $f2
/* 16E3F4 8023FB14 00000000 */  nop
/* 16E3F8 8023FB18 468010A0 */  cvt.s.w   $f2, $f2
/* 16E3FC 8023FB1C 46041082 */  mul.s     $f2, $f2, $f4
/* 16E400 8023FB20 00000000 */  nop
/* 16E404 8023FB24 26020030 */  addiu     $v0, $s0, 0x30
/* 16E408 8023FB28 44830000 */  mtc1      $v1, $f0
/* 16E40C 8023FB2C 00000000 */  nop
/* 16E410 8023FB30 46800020 */  cvt.s.w   $f0, $f0
/* 16E414 8023FB34 AFC20000 */  sw        $v0, ($fp)
/* 16E418 8023FB38 26020038 */  addiu     $v0, $s0, 0x38
/* 16E41C 8023FB3C 46040002 */  mul.s     $f0, $f0, $f4
/* 16E420 8023FB40 00000000 */  nop
/* 16E424 8023FB44 AFC20000 */  sw        $v0, ($fp)
/* 16E428 8023FB48 4600118D */  trunc.w.s $f6, $f2
/* 16E42C 8023FB4C 44023000 */  mfc1      $v0, $f6
/* 16E430 8023FB50 00000000 */  nop
/* 16E434 8023FB54 30420FFF */  andi      $v0, $v0, 0xfff
/* 16E438 8023FB58 00021300 */  sll       $v0, $v0, 0xc
/* 16E43C 8023FB5C 4600018D */  trunc.w.s $f6, $f0
/* 16E440 8023FB60 44033000 */  mfc1      $v1, $f6
/* 16E444 8023FB64 00000000 */  nop
/* 16E448 8023FB68 30630FFF */  andi      $v1, $v1, 0xfff
/* 16E44C 8023FB6C 00641825 */  or        $v1, $v1, $a0
/* 16E450 8023FB70 00431025 */  or        $v0, $v0, $v1
/* 16E454 8023FB74 AE020020 */  sw        $v0, 0x20($s0)
/* 16E458 8023FB78 86E3000E */  lh        $v1, 0xe($s7)
/* 16E45C 8023FB7C 86E5000A */  lh        $a1, 0xa($s7)
/* 16E460 8023FB80 86E40010 */  lh        $a0, 0x10($s7)
/* 16E464 8023FB84 86E6000C */  lh        $a2, 0xc($s7)
/* 16E468 8023FB88 26020040 */  addiu     $v0, $s0, 0x40
/* 16E46C 8023FB8C AFC20000 */  sw        $v0, ($fp)
/* 16E470 8023FB90 AE070028 */  sw        $a3, 0x28($s0)
/* 16E474 8023FB94 AE00002C */  sw        $zero, 0x2c($s0)
/* 16E478 8023FB98 00651821 */  addu      $v1, $v1, $a1
/* 16E47C 8023FB9C 44831000 */  mtc1      $v1, $f2
/* 16E480 8023FBA0 00000000 */  nop
/* 16E484 8023FBA4 468010A0 */  cvt.s.w   $f2, $f2
/* 16E488 8023FBA8 46041082 */  mul.s     $f2, $f2, $f4
/* 16E48C 8023FBAC 00000000 */  nop
/* 16E490 8023FBB0 AE080030 */  sw        $t0, 0x30($s0)
/* 16E494 8023FBB4 AE000034 */  sw        $zero, 0x34($s0)
/* 16E498 8023FBB8 00862021 */  addu      $a0, $a0, $a2
/* 16E49C 8023FBBC 44840000 */  mtc1      $a0, $f0
/* 16E4A0 8023FBC0 00000000 */  nop
/* 16E4A4 8023FBC4 46800020 */  cvt.s.w   $f0, $f0
/* 16E4A8 8023FBC8 46040002 */  mul.s     $f0, $f0, $f4
/* 16E4AC 8023FBCC 00000000 */  nop
/* 16E4B0 8023FBD0 AE090038 */  sw        $t1, 0x38($s0)
/* 16E4B4 8023FBD4 4600118D */  trunc.w.s $f6, $f2
/* 16E4B8 8023FBD8 44023000 */  mfc1      $v0, $f6
/* 16E4BC 8023FBDC 00000000 */  nop
/* 16E4C0 8023FBE0 30420FFF */  andi      $v0, $v0, 0xfff
/* 16E4C4 8023FBE4 00021300 */  sll       $v0, $v0, 0xc
/* 16E4C8 8023FBE8 4600018D */  trunc.w.s $f6, $f0
/* 16E4CC 8023FBEC 44033000 */  mfc1      $v1, $f6
/* 16E4D0 8023FBF0 00000000 */  nop
/* 16E4D4 8023FBF4 30630FFF */  andi      $v1, $v1, 0xfff
/* 16E4D8 8023FBF8 00431025 */  or        $v0, $v0, $v1
/* 16E4DC 8023FBFC AE020024 */  sw        $v0, 0x24($s0)
/* 16E4E0 8023FC00 26020048 */  addiu     $v0, $s0, 0x48
/* 16E4E4 8023FC04 AE00003C */  sw        $zero, 0x3c($s0)
/* 16E4E8 8023FC08 AFC20000 */  sw        $v0, ($fp)
/* 16E4EC 8023FC0C 3C020008 */  lui       $v0, 8
/* 16E4F0 8023FC10 AE020044 */  sw        $v0, 0x44($s0)
/* 16E4F4 8023FC14 26020050 */  addiu     $v0, $s0, 0x50
/* 16E4F8 8023FC18 AE0A0040 */  sw        $t2, 0x40($s0)
/* 16E4FC 8023FC1C AFC20000 */  sw        $v0, ($fp)
/* 16E500 8023FC20 24022000 */  addiu     $v0, $zero, 0x2000
/* 16E504 8023FC24 AE02004C */  sw        $v0, 0x4c($s0)
/* 16E508 8023FC28 26020058 */  addiu     $v0, $s0, 0x58
/* 16E50C 8023FC2C AE0B0048 */  sw        $t3, 0x48($s0)
/* 16E510 8023FC30 AFC20000 */  sw        $v0, ($fp)
/* 16E514 8023FC34 24020C00 */  addiu     $v0, $zero, 0xc00
/* 16E518 8023FC38 AE020054 */  sw        $v0, 0x54($s0)
/* 16E51C 8023FC3C 26020060 */  addiu     $v0, $s0, 0x60
/* 16E520 8023FC40 AE0C0050 */  sw        $t4, 0x50($s0)
/* 16E524 8023FC44 AFC20000 */  sw        $v0, ($fp)
/* 16E528 8023FC48 26020068 */  addiu     $v0, $s0, 0x68
/* 16E52C 8023FC4C AE0E0058 */  sw        $t6, 0x58($s0)
/* 16E530 8023FC50 AE0D005C */  sw        $t5, 0x5c($s0)
/* 16E534 8023FC54 AFC20000 */  sw        $v0, ($fp)
/* 16E538 8023FC58 26020070 */  addiu     $v0, $s0, 0x70
/* 16E53C 8023FC5C AE0F0060 */  sw        $t7, 0x60($s0)
/* 16E540 8023FC60 AE000064 */  sw        $zero, 0x64($s0)
/* 16E544 8023FC64 AFC20000 */  sw        $v0, ($fp)
/* 16E548 8023FC68 26020078 */  addiu     $v0, $s0, 0x78
/* 16E54C 8023FC6C AE110068 */  sw        $s1, 0x68($s0)
/* 16E550 8023FC70 AE00006C */  sw        $zero, 0x6c($s0)
/* 16E554 8023FC74 AFC20000 */  sw        $v0, ($fp)
/* 16E558 8023FC78 26020080 */  addiu     $v0, $s0, 0x80
/* 16E55C 8023FC7C AE120070 */  sw        $s2, 0x70($s0)
/* 16E560 8023FC80 AE130074 */  sw        $s3, 0x74($s0)
/* 16E564 8023FC84 AFC20000 */  sw        $v0, ($fp)
/* 16E568 8023FC88 240200C0 */  addiu     $v0, $zero, 0xc0
/* 16E56C 8023FC8C AE02007C */  sw        $v0, 0x7c($s0)
/* 16E570 8023FC90 26020088 */  addiu     $v0, $s0, 0x88
/* 16E574 8023FC94 24030002 */  addiu     $v1, $zero, 2
/* 16E578 8023FC98 AE140078 */  sw        $s4, 0x78($s0)
/* 16E57C 8023FC9C AFC20000 */  sw        $v0, ($fp)
/* 16E580 8023FCA0 26020090 */  addiu     $v0, $s0, 0x90
/* 16E584 8023FCA4 3C12E700 */  lui       $s2, 0xe700
/* 16E588 8023FCA8 8FB50050 */  lw        $s5, 0x50($sp)
/* 16E58C 8023FCAC 3C130030 */  lui       $s3, 0x30
/* 16E590 8023FCB0 AE150080 */  sw        $s5, 0x80($s0)
/* 16E594 8023FCB4 AE030084 */  sw        $v1, 0x84($s0)
/* 16E598 8023FCB8 AFC20000 */  sw        $v0, ($fp)
/* 16E59C 8023FCBC 8FB50048 */  lw        $s5, 0x48($sp)
/* 16E5A0 8023FCC0 26020098 */  addiu     $v0, $s0, 0x98
/* 16E5A4 8023FCC4 AE150088 */  sw        $s5, 0x88($s0)
/* 16E5A8 8023FCC8 AE03008C */  sw        $v1, 0x8c($s0)
/* 16E5AC 8023FCCC 3403FFFE */  ori       $v1, $zero, 0xfffe
/* 16E5B0 8023FCD0 AFC20000 */  sw        $v0, ($fp)
/* 16E5B4 8023FCD4 260200A0 */  addiu     $v0, $s0, 0xa0
/* 16E5B8 8023FCD8 AE180090 */  sw        $t8, 0x90($s0)
/* 16E5BC 8023FCDC AE030094 */  sw        $v1, 0x94($s0)
/* 16E5C0 8023FCE0 AFC20000 */  sw        $v0, ($fp)
/* 16E5C4 8023FCE4 3C04800A */  lui       $a0, %hi(nuGfxZBuffer)
/* 16E5C8 8023FCE8 8C84A5DC */  lw        $a0, %lo(nuGfxZBuffer)($a0)
/* 16E5CC 8023FCEC 260200A8 */  addiu     $v0, $s0, 0xa8
/* 16E5D0 8023FCF0 AE190098 */  sw        $t9, 0x98($s0)
/* 16E5D4 8023FCF4 AE03009C */  sw        $v1, 0x9c($s0)
/* 16E5D8 8023FCF8 AFC20000 */  sw        $v0, ($fp)
/* 16E5DC 8023FCFC 260200B0 */  addiu     $v0, $s0, 0xb0
/* 16E5E0 8023FD00 AE1200A0 */  sw        $s2, 0xa0($s0)
/* 16E5E4 8023FD04 AE0000A4 */  sw        $zero, 0xa4($s0)
/* 16E5E8 8023FD08 AFC20000 */  sw        $v0, ($fp)
/* 16E5EC 8023FD0C 8FB50044 */  lw        $s5, 0x44($sp)
/* 16E5F0 8023FD10 260200B8 */  addiu     $v0, $s0, 0xb8
/* 16E5F4 8023FD14 AE1300AC */  sw        $s3, 0xac($s0)
/* 16E5F8 8023FD18 AE1500A8 */  sw        $s5, 0xa8($s0)
/* 16E5FC 8023FD1C AFC20000 */  sw        $v0, ($fp)
/* 16E600 8023FD20 0C0187A4 */  jal       osVirtualToPhysical
/* 16E604 8023FD24 AE1600B0 */   sw       $s6, 0xb0($s0)
/* 16E608 8023FD28 3C03FFFC */  lui       $v1, 0xfffc
/* 16E60C 8023FD2C 8FD10000 */  lw        $s1, ($fp)
/* 16E610 8023FD30 3463FFFC */  ori       $v1, $v1, 0xfffc
/* 16E614 8023FD34 AE0200B4 */  sw        $v0, 0xb4($s0)
/* 16E618 8023FD38 3C10F700 */  lui       $s0, 0xf700
/* 16E61C 8023FD3C 3C14F600 */  lui       $s4, 0xf600
/* 16E620 8023FD40 3C04800A */  lui       $a0, %hi(D_8009A64C)
/* 16E624 8023FD44 8C84A64C */  lw        $a0, %lo(D_8009A64C)($a0)
/* 16E628 8023FD48 0220102D */  daddu     $v0, $s1, $zero
/* 16E62C 8023FD4C 26310008 */  addiu     $s1, $s1, 8
/* 16E630 8023FD50 AFD10000 */  sw        $s1, ($fp)
/* 16E634 8023FD54 AC500000 */  sw        $s0, ($v0)
/* 16E638 8023FD58 AC430004 */  sw        $v1, 4($v0)
/* 16E63C 8023FD5C 26220008 */  addiu     $v0, $s1, 8
/* 16E640 8023FD60 AFC20000 */  sw        $v0, ($fp)
/* 16E644 8023FD64 86E3000E */  lh        $v1, 0xe($s7)
/* 16E648 8023FD68 86E5000A */  lh        $a1, 0xa($s7)
/* 16E64C 8023FD6C 26220010 */  addiu     $v0, $s1, 0x10
/* 16E650 8023FD70 AFC20000 */  sw        $v0, ($fp)
/* 16E654 8023FD74 86E20010 */  lh        $v0, 0x10($s7)
/* 16E658 8023FD78 00651821 */  addu      $v1, $v1, $a1
/* 16E65C 8023FD7C 2463FFFF */  addiu     $v1, $v1, -1
/* 16E660 8023FD80 306303FF */  andi      $v1, $v1, 0x3ff
/* 16E664 8023FD84 86E5000C */  lh        $a1, 0xc($s7)
/* 16E668 8023FD88 00031B80 */  sll       $v1, $v1, 0xe
/* 16E66C 8023FD8C 00451021 */  addu      $v0, $v0, $a1
/* 16E670 8023FD90 2442FFFF */  addiu     $v0, $v0, -1
/* 16E674 8023FD94 304203FF */  andi      $v0, $v0, 0x3ff
/* 16E678 8023FD98 00021080 */  sll       $v0, $v0, 2
/* 16E67C 8023FD9C 00541025 */  or        $v0, $v0, $s4
/* 16E680 8023FDA0 00621825 */  or        $v1, $v1, $v0
/* 16E684 8023FDA4 AE230000 */  sw        $v1, ($s1)
/* 16E688 8023FDA8 96E2000E */  lhu       $v0, 0xe($s7)
/* 16E68C 8023FDAC 96E50010 */  lhu       $a1, 0x10($s7)
/* 16E690 8023FDB0 26230018 */  addiu     $v1, $s1, 0x18
/* 16E694 8023FDB4 AFC30000 */  sw        $v1, ($fp)
/* 16E698 8023FDB8 AE320008 */  sw        $s2, 8($s1)
/* 16E69C 8023FDBC AE20000C */  sw        $zero, 0xc($s1)
/* 16E6A0 8023FDC0 AE360010 */  sw        $s6, 0x10($s1)
/* 16E6A4 8023FDC4 304203FF */  andi      $v0, $v0, 0x3ff
/* 16E6A8 8023FDC8 00021380 */  sll       $v0, $v0, 0xe
/* 16E6AC 8023FDCC 30A503FF */  andi      $a1, $a1, 0x3ff
/* 16E6B0 8023FDD0 00052880 */  sll       $a1, $a1, 2
/* 16E6B4 8023FDD4 00451025 */  or        $v0, $v0, $a1
/* 16E6B8 8023FDD8 0C0187A4 */  jal       osVirtualToPhysical
/* 16E6BC 8023FDDC AE220004 */   sw       $v0, 4($s1)
/* 16E6C0 8023FDE0 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* 16E6C4 8023FDE4 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* 16E6C8 8023FDE8 AE220014 */  sw        $v0, 0x14($s1)
/* 16E6CC 8023FDEC 94620148 */  lhu       $v0, 0x148($v1)
/* 16E6D0 8023FDF0 30420001 */  andi      $v0, $v0, 1
/* 16E6D4 8023FDF4 14400034 */  bnez      $v0, .L8023FEC8
/* 16E6D8 8023FDF8 26E400D4 */   addiu    $a0, $s7, 0xd4
/* 16E6DC 8023FDFC 8FC50000 */  lw        $a1, ($fp)
/* 16E6E0 8023FE00 00A0102D */  daddu     $v0, $a1, $zero
/* 16E6E4 8023FE04 24A50008 */  addiu     $a1, $a1, 8
/* 16E6E8 8023FE08 AC550000 */  sw        $s5, ($v0)
/* 16E6EC 8023FE0C AC530004 */  sw        $s3, 4($v0)
/* 16E6F0 8023FE10 ACB00000 */  sw        $s0, ($a1)
/* 16E6F4 8023FE14 86E4002C */  lh        $a0, 0x2c($s7)
/* 16E6F8 8023FE18 AFC50000 */  sw        $a1, ($fp)
/* 16E6FC 8023FE1C 86E3002E */  lh        $v1, 0x2e($s7)
/* 16E700 8023FE20 96E20030 */  lhu       $v0, 0x30($s7)
/* 16E704 8023FE24 00042200 */  sll       $a0, $a0, 8
/* 16E708 8023FE28 3084F800 */  andi      $a0, $a0, 0xf800
/* 16E70C 8023FE2C 000318C0 */  sll       $v1, $v1, 3
/* 16E710 8023FE30 306307C0 */  andi      $v1, $v1, 0x7c0
/* 16E714 8023FE34 00832025 */  or        $a0, $a0, $v1
/* 16E718 8023FE38 00021082 */  srl       $v0, $v0, 2
/* 16E71C 8023FE3C 3042003E */  andi      $v0, $v0, 0x3e
/* 16E720 8023FE40 00822025 */  or        $a0, $a0, $v0
/* 16E724 8023FE44 34820001 */  ori       $v0, $a0, 1
/* 16E728 8023FE48 00021400 */  sll       $v0, $v0, 0x10
/* 16E72C 8023FE4C 34420001 */  ori       $v0, $v0, 1
/* 16E730 8023FE50 00441025 */  or        $v0, $v0, $a0
/* 16E734 8023FE54 ACA20004 */  sw        $v0, 4($a1)
/* 16E738 8023FE58 86E3000E */  lh        $v1, 0xe($s7)
/* 16E73C 8023FE5C 86E4000A */  lh        $a0, 0xa($s7)
/* 16E740 8023FE60 24A20008 */  addiu     $v0, $a1, 8
/* 16E744 8023FE64 AFC20000 */  sw        $v0, ($fp)
/* 16E748 8023FE68 86E20010 */  lh        $v0, 0x10($s7)
/* 16E74C 8023FE6C 00641821 */  addu      $v1, $v1, $a0
/* 16E750 8023FE70 2463FFFF */  addiu     $v1, $v1, -1
/* 16E754 8023FE74 306303FF */  andi      $v1, $v1, 0x3ff
/* 16E758 8023FE78 86E4000C */  lh        $a0, 0xc($s7)
/* 16E75C 8023FE7C 00031B80 */  sll       $v1, $v1, 0xe
/* 16E760 8023FE80 00441021 */  addu      $v0, $v0, $a0
/* 16E764 8023FE84 2442FFFF */  addiu     $v0, $v0, -1
/* 16E768 8023FE88 304203FF */  andi      $v0, $v0, 0x3ff
/* 16E76C 8023FE8C 00021080 */  sll       $v0, $v0, 2
/* 16E770 8023FE90 00541025 */  or        $v0, $v0, $s4
/* 16E774 8023FE94 00621825 */  or        $v1, $v1, $v0
/* 16E778 8023FE98 ACA30008 */  sw        $v1, 8($a1)
/* 16E77C 8023FE9C 96E3000E */  lhu       $v1, 0xe($s7)
/* 16E780 8023FEA0 24A20010 */  addiu     $v0, $a1, 0x10
/* 16E784 8023FEA4 AFC20000 */  sw        $v0, ($fp)
/* 16E788 8023FEA8 96E20010 */  lhu       $v0, 0x10($s7)
/* 16E78C 8023FEAC 306303FF */  andi      $v1, $v1, 0x3ff
/* 16E790 8023FEB0 00031B80 */  sll       $v1, $v1, 0xe
/* 16E794 8023FEB4 304203FF */  andi      $v0, $v0, 0x3ff
/* 16E798 8023FEB8 00021080 */  sll       $v0, $v0, 2
/* 16E79C 8023FEBC 00621825 */  or        $v1, $v1, $v0
/* 16E7A0 8023FEC0 ACA3000C */  sw        $v1, 0xc($a1)
/* 16E7A4 8023FEC4 26E400D4 */  addiu     $a0, $s7, 0xd4
.L8023FEC8:
/* 16E7A8 8023FEC8 3C10800A */  lui       $s0, %hi(gCurrentCamID)
/* 16E7AC 8023FECC 2610A634 */  addiu     $s0, $s0, %lo(gCurrentCamID)
/* 16E7B0 8023FED0 3C11800A */  lui       $s1, %hi(gDisplayContext)
/* 16E7B4 8023FED4 2631A674 */  addiu     $s1, $s1, %lo(gDisplayContext)
/* 16E7B8 8023FED8 8FC30000 */  lw        $v1, ($fp)
/* 16E7BC 8023FEDC 86050000 */  lh        $a1, ($s0)
/* 16E7C0 8023FEE0 8E220000 */  lw        $v0, ($s1)
/* 16E7C4 8023FEE4 0060302D */  daddu     $a2, $v1, $zero
/* 16E7C8 8023FEE8 24630008 */  addiu     $v1, $v1, 8
/* 16E7CC 8023FEEC 00052980 */  sll       $a1, $a1, 6
/* 16E7D0 8023FEF0 24A50030 */  addiu     $a1, $a1, 0x30
/* 16E7D4 8023FEF4 00452821 */  addu      $a1, $v0, $a1
/* 16E7D8 8023FEF8 3C02DB0E */  lui       $v0, 0xdb0e
/* 16E7DC 8023FEFC AFC30000 */  sw        $v1, ($fp)
/* 16E7E0 8023FF00 ACD20000 */  sw        $s2, ($a2)
/* 16E7E4 8023FF04 ACC00004 */  sw        $zero, 4($a2)
/* 16E7E8 8023FF08 AC620000 */  sw        $v0, ($v1)
/* 16E7EC 8023FF0C 96E60038 */  lhu       $a2, 0x38($s7)
/* 16E7F0 8023FF10 24620008 */  addiu     $v0, $v1, 8
/* 16E7F4 8023FF14 AFC20000 */  sw        $v0, ($fp)
/* 16E7F8 8023FF18 0C019D40 */  jal       guMtxF2L
/* 16E7FC 8023FF1C AC660004 */   sw       $a2, 4($v1)
/* 16E800 8023FF20 3C05DA38 */  lui       $a1, 0xda38
/* 16E804 8023FF24 34A50007 */  ori       $a1, $a1, 7
/* 16E808 8023FF28 8FC20000 */  lw        $v0, ($fp)
/* 16E80C 8023FF2C 86030000 */  lh        $v1, ($s0)
/* 16E810 8023FF30 0040202D */  daddu     $a0, $v0, $zero
/* 16E814 8023FF34 24420008 */  addiu     $v0, $v0, 8
/* 16E818 8023FF38 00031980 */  sll       $v1, $v1, 6
/* 16E81C 8023FF3C AFC20000 */  sw        $v0, ($fp)
/* 16E820 8023FF40 AC850000 */  sw        $a1, ($a0)
/* 16E824 8023FF44 8E220000 */  lw        $v0, ($s1)
/* 16E828 8023FF48 24630030 */  addiu     $v1, $v1, 0x30
/* 16E82C 8023FF4C 00431021 */  addu      $v0, $v0, $v1
/* 16E830 8023FF50 AC820004 */  sw        $v0, 4($a0)
/* 16E834 8023FF54 8FBF007C */  lw        $ra, 0x7c($sp)
/* 16E838 8023FF58 8FBE0078 */  lw        $fp, 0x78($sp)
/* 16E83C 8023FF5C 8FB70074 */  lw        $s7, 0x74($sp)
/* 16E840 8023FF60 8FB60070 */  lw        $s6, 0x70($sp)
/* 16E844 8023FF64 8FB5006C */  lw        $s5, 0x6c($sp)
/* 16E848 8023FF68 8FB40068 */  lw        $s4, 0x68($sp)
/* 16E84C 8023FF6C 8FB30064 */  lw        $s3, 0x64($sp)
/* 16E850 8023FF70 8FB20060 */  lw        $s2, 0x60($sp)
/* 16E854 8023FF74 8FB1005C */  lw        $s1, 0x5c($sp)
/* 16E858 8023FF78 8FB00058 */  lw        $s0, 0x58($sp)
/* 16E85C 8023FF7C 03E00008 */  jr        $ra
/* 16E860 8023FF80 27BD0080 */   addiu    $sp, $sp, 0x80
