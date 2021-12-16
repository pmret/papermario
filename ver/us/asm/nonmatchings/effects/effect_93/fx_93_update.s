.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata
dlabel D_E00BAE80
.double 0.7

dlabel D_E00BAE88
.double 0.98

dlabel D_E00BAE90
.double 0.02

.section .text
glabel fx_93_update
/* 3B8D44 E00BA174 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 3B8D48 E00BA178 AFBF0024 */  sw        $ra, 0x24($sp)
/* 3B8D4C E00BA17C AFB40020 */  sw        $s4, 0x20($sp)
/* 3B8D50 E00BA180 AFB3001C */  sw        $s3, 0x1c($sp)
/* 3B8D54 E00BA184 AFB20018 */  sw        $s2, 0x18($sp)
/* 3B8D58 E00BA188 AFB10014 */  sw        $s1, 0x14($sp)
/* 3B8D5C E00BA18C AFB00010 */  sw        $s0, 0x10($sp)
/* 3B8D60 E00BA190 F7B60030 */  sdc1      $f22, 0x30($sp)
/* 3B8D64 E00BA194 F7B40028 */  sdc1      $f20, 0x28($sp)
/* 3B8D68 E00BA198 8C830000 */  lw        $v1, ($a0)
/* 3B8D6C E00BA19C 8C90000C */  lw        $s0, 0xc($a0)
/* 3B8D70 E00BA1A0 30620010 */  andi      $v0, $v1, 0x10
/* 3B8D74 E00BA1A4 10400005 */  beqz      $v0, .LE00BA1BC
/* 3B8D78 E00BA1A8 2402FFEF */   addiu    $v0, $zero, -0x11
/* 3B8D7C E00BA1AC 00621024 */  and       $v0, $v1, $v0
/* 3B8D80 E00BA1B0 AC820000 */  sw        $v0, ($a0)
/* 3B8D84 E00BA1B4 24020020 */  addiu     $v0, $zero, 0x20
/* 3B8D88 E00BA1B8 AE020010 */  sw        $v0, 0x10($s0)
.LE00BA1BC:
/* 3B8D8C E00BA1BC 8E030010 */  lw        $v1, 0x10($s0)
/* 3B8D90 E00BA1C0 286203E8 */  slti      $v0, $v1, 0x3e8
/* 3B8D94 E00BA1C4 10400002 */  beqz      $v0, .LE00BA1D0
/* 3B8D98 E00BA1C8 2462FFFF */   addiu    $v0, $v1, -1
/* 3B8D9C E00BA1CC AE020010 */  sw        $v0, 0x10($s0)
.LE00BA1D0:
/* 3B8DA0 E00BA1D0 8E020014 */  lw        $v0, 0x14($s0)
/* 3B8DA4 E00BA1D4 8E030010 */  lw        $v1, 0x10($s0)
/* 3B8DA8 E00BA1D8 24420001 */  addiu     $v0, $v0, 1
/* 3B8DAC E00BA1DC 04610005 */  bgez      $v1, .LE00BA1F4
/* 3B8DB0 E00BA1E0 AE020014 */   sw       $v0, 0x14($s0)
/* 3B8DB4 E00BA1E4 0C080128 */  jal       shim_remove_effect
/* 3B8DB8 E00BA1E8 00000000 */   nop
/* 3B8DBC E00BA1EC 0802E96D */  j         .LE00BA5B4
/* 3B8DC0 E00BA1F0 00000000 */   nop
.LE00BA1F4:
/* 3B8DC4 E00BA1F4 0060A02D */  daddu     $s4, $v1, $zero
/* 3B8DC8 E00BA1F8 0040982D */  daddu     $s3, $v0, $zero
/* 3B8DCC E00BA1FC 2A820020 */  slti      $v0, $s4, 0x20
/* 3B8DD0 E00BA200 10400002 */  beqz      $v0, .LE00BA20C
/* 3B8DD4 E00BA204 240400FF */   addiu    $a0, $zero, 0xff
/* 3B8DD8 E00BA208 001420C0 */  sll       $a0, $s4, 3
.LE00BA20C:
/* 3B8DDC E00BA20C 2A620010 */  slti      $v0, $s3, 0x10
/* 3B8DE0 E00BA210 10400002 */  beqz      $v0, .LE00BA21C
/* 3B8DE4 E00BA214 00131100 */   sll      $v0, $s3, 4
/* 3B8DE8 E00BA218 2444000F */  addiu     $a0, $v0, 0xf
.LE00BA21C:
/* 3B8DEC E00BA21C 3C014F00 */  lui       $at, 0x4f00
/* 3B8DF0 E00BA220 44811000 */  mtc1      $at, $f2
/* 3B8DF4 E00BA224 44840000 */  mtc1      $a0, $f0
/* 3B8DF8 E00BA228 00000000 */  nop
/* 3B8DFC E00BA22C 46800020 */  cvt.s.w   $f0, $f0
/* 3B8E00 E00BA230 4600103E */  c.le.s    $f2, $f0
/* 3B8E04 E00BA234 00000000 */  nop
/* 3B8E08 E00BA238 45010005 */  bc1t      .LE00BA250
/* 3B8E0C E00BA23C 2605001F */   addiu    $a1, $s0, 0x1f
/* 3B8E10 E00BA240 4600038D */  trunc.w.s $f14, $f0
/* 3B8E14 E00BA244 44037000 */  mfc1      $v1, $f14
/* 3B8E18 E00BA248 0802E89B */  j         .LE00BA26C
/* 3B8E1C E00BA24C 24120001 */   addiu    $s2, $zero, 1
.LE00BA250:
/* 3B8E20 E00BA250 46020001 */  sub.s     $f0, $f0, $f2
/* 3B8E24 E00BA254 3C028000 */  lui       $v0, 0x8000
/* 3B8E28 E00BA258 4600038D */  trunc.w.s $f14, $f0
/* 3B8E2C E00BA25C 44037000 */  mfc1      $v1, $f14
/* 3B8E30 E00BA260 00000000 */  nop
/* 3B8E34 E00BA264 00621825 */  or        $v1, $v1, $v0
/* 3B8E38 E00BA268 24120001 */  addiu     $s2, $zero, 1
.LE00BA26C:
/* 3B8E3C E00BA26C 2611000D */  addiu     $s1, $s0, 0xd
/* 3B8E40 E00BA270 3C01C280 */  lui       $at, 0xc280
/* 3B8E44 E00BA274 4481B000 */  mtc1      $at, $f22
/* 3B8E48 E00BA278 3C01437F */  lui       $at, 0x437f
/* 3B8E4C E00BA27C 44811000 */  mtc1      $at, $f2
/* 3B8E50 E00BA280 44840000 */  mtc1      $a0, $f0
/* 3B8E54 E00BA284 00000000 */  nop
/* 3B8E58 E00BA288 46800020 */  cvt.s.w   $f0, $f0
/* 3B8E5C E00BA28C A0A30000 */  sb        $v1, ($a1)
/* 3B8E60 E00BA290 46020503 */  div.s     $f20, $f0, $f2
.LE00BA294:
/* 3B8E64 E00BA294 02721823 */  subu      $v1, $s3, $s2
/* 3B8E68 E00BA298 00031080 */  sll       $v0, $v1, 2
/* 3B8E6C E00BA29C 00431021 */  addu      $v0, $v0, $v1
/* 3B8E70 E00BA2A0 00021080 */  sll       $v0, $v0, 2
/* 3B8E74 E00BA2A4 00021023 */  negu      $v0, $v0
/* 3B8E78 E00BA2A8 44826000 */  mtc1      $v0, $f12
/* 3B8E7C E00BA2AC 00000000 */  nop
/* 3B8E80 E00BA2B0 46806320 */  cvt.s.w   $f12, $f12
/* 3B8E84 E00BA2B4 0C080140 */  jal       shim_sin_deg
/* 3B8E88 E00BA2B8 26520001 */   addiu    $s2, $s2, 1
/* 3B8E8C E00BA2BC 46160002 */  mul.s     $f0, $f0, $f22
/* 3B8E90 E00BA2C0 00000000 */  nop
/* 3B8E94 E00BA2C4 46140002 */  mul.s     $f0, $f0, $f20
/* 3B8E98 E00BA2C8 00000000 */  nop
/* 3B8E9C E00BA2CC 4600038D */  trunc.w.s $f14, $f0
/* 3B8EA0 E00BA2D0 44027000 */  mfc1      $v0, $f14
/* 3B8EA4 E00BA2D4 00000000 */  nop
/* 3B8EA8 E00BA2D8 A2220029 */  sb        $v0, 0x29($s1)
/* 3B8EAC E00BA2DC 2A420012 */  slti      $v0, $s2, 0x12
/* 3B8EB0 E00BA2E0 1440FFEC */  bnez      $v0, .LE00BA294
/* 3B8EB4 E00BA2E4 2631000D */   addiu    $s1, $s1, 0xd
/* 3B8EB8 E00BA2E8 24120001 */  addiu     $s2, $zero, 1
/* 3B8EBC E00BA2EC 240F001A */  addiu     $t7, $zero, 0x1a
/* 3B8EC0 E00BA2F0 240EFFFF */  addiu     $t6, $zero, -1
/* 3B8EC4 E00BA2F4 240D0019 */  addiu     $t5, $zero, 0x19
/* 3B8EC8 E00BA2F8 0000602D */  daddu     $t4, $zero, $zero
/* 3B8ECC E00BA2FC 01E0582D */  daddu     $t3, $t7, $zero
/* 3B8ED0 E00BA300 240A000D */  addiu     $t2, $zero, 0xd
.LE00BA304:
/* 3B8ED4 E00BA304 24050001 */  addiu     $a1, $zero, 1
/* 3B8ED8 E00BA308 0140382D */  daddu     $a3, $t2, $zero
/* 3B8EDC E00BA30C 0160482D */  daddu     $t1, $t3, $zero
/* 3B8EE0 E00BA310 0180402D */  daddu     $t0, $t4, $zero
/* 3B8EE4 E00BA314 01A0982D */  daddu     $s3, $t5, $zero
/* 3B8EE8 E00BA318 01C0882D */  daddu     $s1, $t6, $zero
/* 3B8EEC E00BA31C 25E60002 */  addiu     $a2, $t7, 2
.LE00BA320:
/* 3B8EF0 E00BA320 25220001 */  addiu     $v0, $t1, 1
/* 3B8EF4 E00BA324 00A21021 */  addu      $v0, $a1, $v0
/* 3B8EF8 E00BA328 02021021 */  addu      $v0, $s0, $v0
/* 3B8EFC E00BA32C 00A72021 */  addu      $a0, $a1, $a3
/* 3B8F00 E00BA330 00B31821 */  addu      $v1, $a1, $s3
/* 3B8F04 E00BA334 02031821 */  addu      $v1, $s0, $v1
/* 3B8F08 E00BA338 80420023 */  lb        $v0, 0x23($v0)
/* 3B8F0C E00BA33C 80630023 */  lb        $v1, 0x23($v1)
/* 3B8F10 E00BA340 44822000 */  mtc1      $v0, $f4
/* 3B8F14 E00BA344 00000000 */  nop
/* 3B8F18 E00BA348 46802120 */  cvt.s.w   $f4, $f4
/* 3B8F1C E00BA34C 25020001 */  addiu     $v0, $t0, 1
/* 3B8F20 E00BA350 00A21021 */  addu      $v0, $a1, $v0
/* 3B8F24 E00BA354 02021021 */  addu      $v0, $s0, $v0
/* 3B8F28 E00BA358 80420023 */  lb        $v0, 0x23($v0)
/* 3B8F2C E00BA35C 44831000 */  mtc1      $v1, $f2
/* 3B8F30 E00BA360 00000000 */  nop
/* 3B8F34 E00BA364 468010A0 */  cvt.s.w   $f2, $f2
/* 3B8F38 E00BA368 44820000 */  mtc1      $v0, $f0
/* 3B8F3C E00BA36C 00000000 */  nop
/* 3B8F40 E00BA370 46800020 */  cvt.s.w   $f0, $f0
/* 3B8F44 E00BA374 00B11021 */  addu      $v0, $a1, $s1
/* 3B8F48 E00BA378 46002100 */  add.s     $f4, $f4, $f0
/* 3B8F4C E00BA37C 02021021 */  addu      $v0, $s0, $v0
/* 3B8F50 E00BA380 80420023 */  lb        $v0, 0x23($v0)
/* 3B8F54 E00BA384 46022100 */  add.s     $f4, $f4, $f2
/* 3B8F58 E00BA388 02042021 */  addu      $a0, $s0, $a0
/* 3B8F5C E00BA38C 44820000 */  mtc1      $v0, $f0
/* 3B8F60 E00BA390 00000000 */  nop
/* 3B8F64 E00BA394 46800020 */  cvt.s.w   $f0, $f0
/* 3B8F68 E00BA398 46002100 */  add.s     $f4, $f4, $f0
/* 3B8F6C E00BA39C 80830023 */  lb        $v1, 0x23($a0)
/* 3B8F70 E00BA3A0 3C013FE0 */  lui       $at, 0x3fe0
/* 3B8F74 E00BA3A4 44810800 */  mtc1      $at, $f1
/* 3B8F78 E00BA3A8 44800000 */  mtc1      $zero, $f0
/* 3B8F7C E00BA3AC 46002121 */  cvt.d.s   $f4, $f4
/* 3B8F80 E00BA3B0 46202102 */  mul.d     $f4, $f4, $f0
/* 3B8F84 E00BA3B4 00000000 */  nop
/* 3B8F88 E00BA3B8 44835000 */  mtc1      $v1, $f10
/* 3B8F8C E00BA3BC 00000000 */  nop
/* 3B8F90 E00BA3C0 468052A0 */  cvt.s.w   $f10, $f10
/* 3B8F94 E00BA3C4 00A81821 */  addu      $v1, $a1, $t0
/* 3B8F98 E00BA3C8 02031821 */  addu      $v1, $s0, $v1
/* 3B8F9C E00BA3CC 00A91021 */  addu      $v0, $a1, $t1
/* 3B8FA0 E00BA3D0 02021021 */  addu      $v0, $s0, $v0
/* 3B8FA4 E00BA3D4 3C014080 */  lui       $at, 0x4080
/* 3B8FA8 E00BA3D8 44810000 */  mtc1      $at, $f0
/* 3B8FAC E00BA3DC 80420023 */  lb        $v0, 0x23($v0)
/* 3B8FB0 E00BA3E0 46005282 */  mul.s     $f10, $f10, $f0
/* 3B8FB4 E00BA3E4 00000000 */  nop
/* 3B8FB8 E00BA3E8 44821000 */  mtc1      $v0, $f2
/* 3B8FBC E00BA3EC 00000000 */  nop
/* 3B8FC0 E00BA3F0 468010A0 */  cvt.s.w   $f2, $f2
/* 3B8FC4 E00BA3F4 24E20001 */  addiu     $v0, $a3, 1
/* 3B8FC8 E00BA3F8 00A21021 */  addu      $v0, $a1, $v0
/* 3B8FCC E00BA3FC 3C01E00C */  lui       $at, %hi(D_E00BAE80)
/* 3B8FD0 E00BA400 D420AE80 */  ldc1      $f0, %lo(D_E00BAE80)($at)
/* 3B8FD4 E00BA404 460051A1 */  cvt.d.s   $f6, $f10
/* 3B8FD8 E00BA408 46203182 */  mul.d     $f6, $f6, $f0
/* 3B8FDC E00BA40C 00000000 */  nop
/* 3B8FE0 E00BA410 02021021 */  addu      $v0, $s0, $v0
/* 3B8FE4 E00BA414 80420023 */  lb        $v0, 0x23($v0)
/* 3B8FE8 E00BA418 80630023 */  lb        $v1, 0x23($v1)
/* 3B8FEC E00BA41C 44824000 */  mtc1      $v0, $f8
/* 3B8FF0 E00BA420 00000000 */  nop
/* 3B8FF4 E00BA424 46804220 */  cvt.s.w   $f8, $f8
/* 3B8FF8 E00BA428 24E2FFFF */  addiu     $v0, $a3, -1
/* 3B8FFC E00BA42C 00A21021 */  addu      $v0, $a1, $v0
/* 3B9000 E00BA430 44830000 */  mtc1      $v1, $f0
/* 3B9004 E00BA434 00000000 */  nop
/* 3B9008 E00BA438 46800020 */  cvt.s.w   $f0, $f0
/* 3B900C E00BA43C 46001080 */  add.s     $f2, $f2, $f0
/* 3B9010 E00BA440 02021021 */  addu      $v0, $s0, $v0
/* 3B9014 E00BA444 80420023 */  lb        $v0, 0x23($v0)
/* 3B9018 E00BA448 46081080 */  add.s     $f2, $f2, $f8
/* 3B901C E00BA44C 44820000 */  mtc1      $v0, $f0
/* 3B9020 E00BA450 00000000 */  nop
/* 3B9024 E00BA454 46800020 */  cvt.s.w   $f0, $f0
/* 3B9028 E00BA458 46001080 */  add.s     $f2, $f2, $f0
/* 3B902C E00BA45C 460A1081 */  sub.s     $f2, $f2, $f10
/* 3B9030 E00BA460 46202120 */  cvt.s.d   $f4, $f4
/* 3B9034 E00BA464 46041080 */  add.s     $f2, $f2, $f4
/* 3B9038 E00BA468 02061821 */  addu      $v1, $s0, $a2
/* 3B903C E00BA46C 8462011A */  lh        $v0, 0x11a($v1)
/* 3B9040 E00BA470 460010A1 */  cvt.d.s   $f2, $f2
/* 3B9044 E00BA474 46261081 */  sub.d     $f2, $f2, $f6
/* 3B9048 E00BA478 44820000 */  mtc1      $v0, $f0
/* 3B904C E00BA47C 00000000 */  nop
/* 3B9050 E00BA480 46800021 */  cvt.d.w   $f0, $f0
/* 3B9054 E00BA484 46220000 */  add.d     $f0, $f0, $f2
/* 3B9058 E00BA488 3C01E00C */  lui       $at, %hi(D_E00BAE88)
/* 3B905C E00BA48C D422AE88 */  ldc1      $f2, %lo(D_E00BAE88)($at)
/* 3B9060 E00BA490 4620038D */  trunc.w.d $f14, $f0
/* 3B9064 E00BA494 44027000 */  mfc1      $v0, $f14
/* 3B9068 E00BA498 00000000 */  nop
/* 3B906C E00BA49C 00021400 */  sll       $v0, $v0, 0x10
/* 3B9070 E00BA4A0 00021403 */  sra       $v0, $v0, 0x10
/* 3B9074 E00BA4A4 44820000 */  mtc1      $v0, $f0
/* 3B9078 E00BA4A8 00000000 */  nop
/* 3B907C E00BA4AC 46800021 */  cvt.d.w   $f0, $f0
/* 3B9080 E00BA4B0 46220002 */  mul.d     $f0, $f0, $f2
/* 3B9084 E00BA4B4 00000000 */  nop
/* 3B9088 E00BA4B8 4620038D */  trunc.w.d $f14, $f0
/* 3B908C E00BA4BC 44027000 */  mfc1      $v0, $f14
/* 3B9090 E00BA4C0 00000000 */  nop
/* 3B9094 E00BA4C4 A462011A */  sh        $v0, 0x11a($v1)
/* 3B9098 E00BA4C8 2A820020 */  slti      $v0, $s4, 0x20
/* 3B909C E00BA4CC 1040000B */  beqz      $v0, .LE00BA4FC
/* 3B90A0 E00BA4D0 24A50001 */   addiu    $a1, $a1, 1
/* 3B90A4 E00BA4D4 80820023 */  lb        $v0, 0x23($a0)
/* 3B90A8 E00BA4D8 44820000 */  mtc1      $v0, $f0
/* 3B90AC E00BA4DC 00000000 */  nop
/* 3B90B0 E00BA4E0 46800020 */  cvt.s.w   $f0, $f0
/* 3B90B4 E00BA4E4 46140002 */  mul.s     $f0, $f0, $f20
/* 3B90B8 E00BA4E8 00000000 */  nop
/* 3B90BC E00BA4EC 4600038D */  trunc.w.s $f14, $f0
/* 3B90C0 E00BA4F0 44027000 */  mfc1      $v0, $f14
/* 3B90C4 E00BA4F4 00000000 */  nop
/* 3B90C8 E00BA4F8 A0820023 */  sb        $v0, 0x23($a0)
.LE00BA4FC:
/* 3B90CC E00BA4FC 28A2000C */  slti      $v0, $a1, 0xc
/* 3B90D0 E00BA500 1440FF87 */  bnez      $v0, .LE00BA320
/* 3B90D4 E00BA504 24C60002 */   addiu    $a2, $a2, 2
/* 3B90D8 E00BA508 25EF001A */  addiu     $t7, $t7, 0x1a
/* 3B90DC E00BA50C 25CE000D */  addiu     $t6, $t6, 0xd
/* 3B90E0 E00BA510 25AD000D */  addiu     $t5, $t5, 0xd
/* 3B90E4 E00BA514 258C000D */  addiu     $t4, $t4, 0xd
/* 3B90E8 E00BA518 256B000D */  addiu     $t3, $t3, 0xd
/* 3B90EC E00BA51C 26520001 */  addiu     $s2, $s2, 1
/* 3B90F0 E00BA520 2A420012 */  slti      $v0, $s2, 0x12
/* 3B90F4 E00BA524 1440FF77 */  bnez      $v0, .LE00BA304
/* 3B90F8 E00BA528 254A000D */   addiu    $t2, $t2, 0xd
/* 3B90FC E00BA52C 24120001 */  addiu     $s2, $zero, 1
/* 3B9100 E00BA530 3C01E00C */  lui       $at, %hi(D_E00BAE90)
/* 3B9104 E00BA534 D424AE90 */  ldc1      $f4, %lo(D_E00BAE90)($at)
/* 3B9108 E00BA538 2407001A */  addiu     $a3, $zero, 0x1a
/* 3B910C E00BA53C 2406000D */  addiu     $a2, $zero, 0xd
.LE00BA540:
/* 3B9110 E00BA540 24050001 */  addiu     $a1, $zero, 1
/* 3B9114 E00BA544 24E40002 */  addiu     $a0, $a3, 2
.LE00BA548:
/* 3B9118 E00BA548 02041021 */  addu      $v0, $s0, $a0
/* 3B911C E00BA54C 8442011A */  lh        $v0, 0x11a($v0)
/* 3B9120 E00BA550 44821000 */  mtc1      $v0, $f2
/* 3B9124 E00BA554 00000000 */  nop
/* 3B9128 E00BA558 468010A1 */  cvt.d.w   $f2, $f2
/* 3B912C E00BA55C 46241082 */  mul.d     $f2, $f2, $f4
/* 3B9130 E00BA560 00000000 */  nop
/* 3B9134 E00BA564 00A61821 */  addu      $v1, $a1, $a2
/* 3B9138 E00BA568 02031821 */  addu      $v1, $s0, $v1
/* 3B913C E00BA56C 80620023 */  lb        $v0, 0x23($v1)
/* 3B9140 E00BA570 44820000 */  mtc1      $v0, $f0
/* 3B9144 E00BA574 00000000 */  nop
/* 3B9148 E00BA578 46800021 */  cvt.d.w   $f0, $f0
/* 3B914C E00BA57C 46220000 */  add.d     $f0, $f0, $f2
/* 3B9150 E00BA580 24A50001 */  addiu     $a1, $a1, 1
/* 3B9154 E00BA584 4620038D */  trunc.w.d $f14, $f0
/* 3B9158 E00BA588 44027000 */  mfc1      $v0, $f14
/* 3B915C E00BA58C 00000000 */  nop
/* 3B9160 E00BA590 A0620023 */  sb        $v0, 0x23($v1)
/* 3B9164 E00BA594 28A2000C */  slti      $v0, $a1, 0xc
/* 3B9168 E00BA598 1440FFEB */  bnez      $v0, .LE00BA548
/* 3B916C E00BA59C 24840002 */   addiu    $a0, $a0, 2
/* 3B9170 E00BA5A0 24E7001A */  addiu     $a3, $a3, 0x1a
/* 3B9174 E00BA5A4 26520001 */  addiu     $s2, $s2, 1
/* 3B9178 E00BA5A8 2A420012 */  slti      $v0, $s2, 0x12
/* 3B917C E00BA5AC 1440FFE4 */  bnez      $v0, .LE00BA540
/* 3B9180 E00BA5B0 24C6000D */   addiu    $a2, $a2, 0xd
.LE00BA5B4:
/* 3B9184 E00BA5B4 8FBF0024 */  lw        $ra, 0x24($sp)
/* 3B9188 E00BA5B8 8FB40020 */  lw        $s4, 0x20($sp)
/* 3B918C E00BA5BC 8FB3001C */  lw        $s3, 0x1c($sp)
/* 3B9190 E00BA5C0 8FB20018 */  lw        $s2, 0x18($sp)
/* 3B9194 E00BA5C4 8FB10014 */  lw        $s1, 0x14($sp)
/* 3B9198 E00BA5C8 8FB00010 */  lw        $s0, 0x10($sp)
/* 3B919C E00BA5CC D7B60030 */  ldc1      $f22, 0x30($sp)
/* 3B91A0 E00BA5D0 D7B40028 */  ldc1      $f20, 0x28($sp)
/* 3B91A4 E00BA5D4 03E00008 */  jr        $ra
/* 3B91A8 E00BA5D8 27BD0038 */   addiu    $sp, $sp, 0x38
