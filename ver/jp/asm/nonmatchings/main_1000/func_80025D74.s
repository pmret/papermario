.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80025D74
/* 1174 80025D74 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* 1178 80025D78 AFB30024 */  sw        $s3, 0x24($sp)
/* 117C 80025D7C 00A0982D */  daddu     $s3, $a1, $zero
/* 1180 80025D80 AFB40028 */  sw        $s4, 0x28($sp)
/* 1184 80025D84 00C0A02D */  daddu     $s4, $a2, $zero
/* 1188 80025D88 3C05B3FF */  lui       $a1, 0xb3ff
/* 118C 80025D8C AFB1001C */  sw        $s1, 0x1c($sp)
/* 1190 80025D90 3C11800A */  lui       $s1, %hi(D_8009A618)
/* 1194 80025D94 2631A618 */  addiu     $s1, $s1, %lo(D_8009A618)
/* 1198 80025D98 AFB00018 */  sw        $s0, 0x18($sp)
/* 119C 80025D9C 27B00010 */  addiu     $s0, $sp, 0x10
/* 11A0 80025DA0 AFBF003C */  sw        $ra, 0x3c($sp)
/* 11A4 80025DA4 AFBE0038 */  sw        $fp, 0x38($sp)
/* 11A8 80025DA8 AFB70034 */  sw        $s7, 0x34($sp)
/* 11AC 80025DAC AFB60030 */  sw        $s6, 0x30($sp)
/* 11B0 80025DB0 AFB5002C */  sw        $s5, 0x2c($sp)
/* 11B4 80025DB4 AFB20020 */  sw        $s2, 0x20($sp)
/* 11B8 80025DB8 8E240000 */  lw        $a0, ($s1)
/* 11BC 80025DBC 0C018364 */  jal       func_80060D90
/* 11C0 80025DC0 0200302D */   daddu    $a2, $s0, $zero
/* 11C4 80025DC4 3C034953 */  lui       $v1, 0x4953
/* 11C8 80025DC8 8FA20010 */  lw        $v0, 0x10($sp)
/* 11CC 80025DCC 34633634 */  ori       $v1, $v1, 0x3634
/* 11D0 80025DD0 14430050 */  bne       $v0, $v1, .L80025F14
/* 11D4 80025DD4 24020001 */   addiu    $v0, $zero, 1
/* 11D8 80025DD8 3C05B3FF */  lui       $a1, 0xb3ff
/* 11DC 80025DDC 34A50004 */  ori       $a1, $a1, 4
/* 11E0 80025DE0 8E240000 */  lw        $a0, ($s1)
/* 11E4 80025DE4 0C018364 */  jal       func_80060D90
/* 11E8 80025DE8 0200302D */   daddu    $a2, $s0, $zero
/* 11EC 80025DEC 3C05B3FF */  lui       $a1, 0xb3ff
/* 11F0 80025DF0 0200302D */  daddu     $a2, $s0, $zero
/* 11F4 80025DF4 8E240000 */  lw        $a0, ($s1)
/* 11F8 80025DF8 8FB00010 */  lw        $s0, 0x10($sp)
/* 11FC 80025DFC 0C018364 */  jal       func_80060D90
/* 1200 80025E00 34A50014 */   ori      $a1, $a1, 0x14
/* 1204 80025E04 8FB20010 */  lw        $s2, 0x10($sp)
/* 1208 80025E08 3402FFDF */  ori       $v0, $zero, 0xffdf
/* 120C 80025E0C 02541821 */  addu      $v1, $s2, $s4
/* 1210 80025E10 0043102A */  slt       $v0, $v0, $v1
/* 1214 80025E14 1040000B */  beqz      $v0, .L80025E44
/* 1218 80025E18 3C02FFFF */   lui      $v0, 0xffff
/* 121C 80025E1C 34420020 */  ori       $v0, $v0, 0x20
/* 1220 80025E20 00621821 */  addu      $v1, $v1, $v0
/* 1224 80025E24 0203102A */  slt       $v0, $s0, $v1
/* 1228 80025E28 1440003A */  bnez      $v0, .L80025F14
/* 122C 80025E2C 24020001 */   addiu    $v0, $zero, 1
/* 1230 80025E30 0250102A */  slt       $v0, $s2, $s0
/* 1234 80025E34 10400008 */  beqz      $v0, .L80025E58
/* 1238 80025E38 24020001 */   addiu    $v0, $zero, 1
/* 123C 80025E3C 080097C5 */  j         .L80025F14
/* 1240 80025E40 00000000 */   nop
.L80025E44:
/* 1244 80025E44 0250102A */  slt       $v0, $s2, $s0
/* 1248 80025E48 10400003 */  beqz      $v0, .L80025E58
/* 124C 80025E4C 0203102A */   slt      $v0, $s0, $v1
/* 1250 80025E50 14400030 */  bnez      $v0, .L80025F14
/* 1254 80025E54 24020001 */   addiu    $v0, $zero, 1
.L80025E58:
/* 1258 80025E58 12800027 */  beqz      $s4, .L80025EF8
/* 125C 80025E5C 3C1E0FFF */   lui      $fp, 0xfff
/* 1260 80025E60 37DEFFFC */  ori       $fp, $fp, 0xfffc
/* 1264 80025E64 3C17B3FF */  lui       $s7, 0xb3ff
/* 1268 80025E68 36F70020 */  ori       $s7, $s7, 0x20
/* 126C 80025E6C 3C15800A */  lui       $s5, %hi(D_8009A618)
/* 1270 80025E70 26B5A618 */  addiu     $s5, $s5, %lo(D_8009A618)
/* 1274 80025E74 3C16FFFF */  lui       $s6, 0xffff
/* 1278 80025E78 36D60020 */  ori       $s6, $s6, 0x20
.L80025E7C:
/* 127C 80025E7C 92620000 */  lbu       $v0, ($s3)
/* 1280 80025E80 1040001A */  beqz      $v0, .L80025EEC
/* 1284 80025E84 025E8824 */   and      $s1, $s2, $fp
/* 1288 80025E88 02378821 */  addu      $s1, $s1, $s7
/* 128C 80025E8C 0220282D */  daddu     $a1, $s1, $zero
/* 1290 80025E90 27A60010 */  addiu     $a2, $sp, 0x10
/* 1294 80025E94 32500003 */  andi      $s0, $s2, 3
/* 1298 80025E98 26520001 */  addiu     $s2, $s2, 1
/* 129C 80025E9C 24070003 */  addiu     $a3, $zero, 3
/* 12A0 80025EA0 00F08023 */  subu      $s0, $a3, $s0
/* 12A4 80025EA4 8EA40000 */  lw        $a0, ($s5)
/* 12A8 80025EA8 0C018364 */  jal       func_80060D90
/* 12AC 80025EAC 00F08004 */   sllv     $s0, $s0, $a3
/* 12B0 80025EB0 0220282D */  daddu     $a1, $s1, $zero
/* 12B4 80025EB4 240700FF */  addiu     $a3, $zero, 0xff
/* 12B8 80025EB8 02071004 */  sllv      $v0, $a3, $s0
/* 12BC 80025EBC 00021027 */  nor       $v0, $zero, $v0
/* 12C0 80025EC0 8EA40000 */  lw        $a0, ($s5)
/* 12C4 80025EC4 8FA30010 */  lw        $v1, 0x10($sp)
/* 12C8 80025EC8 92660000 */  lbu       $a2, ($s3)
/* 12CC 80025ECC 00621824 */  and       $v1, $v1, $v0
/* 12D0 80025ED0 02063004 */  sllv      $a2, $a2, $s0
/* 12D4 80025ED4 0C01834C */  jal       func_80060D30
/* 12D8 80025ED8 00663025 */   or       $a2, $v1, $a2
/* 12DC 80025EDC 3407FFDF */  ori       $a3, $zero, 0xffdf
/* 12E0 80025EE0 00F2102A */  slt       $v0, $a3, $s2
/* 12E4 80025EE4 54400001 */  bnel      $v0, $zero, .L80025EEC
/* 12E8 80025EE8 02569021 */   addu     $s2, $s2, $s6
.L80025EEC:
/* 12EC 80025EEC 2694FFFF */  addiu     $s4, $s4, -1
/* 12F0 80025EF0 1680FFE2 */  bnez      $s4, .L80025E7C
/* 12F4 80025EF4 26730001 */   addiu    $s3, $s3, 1
.L80025EF8:
/* 12F8 80025EF8 3C04800A */  lui       $a0, %hi(D_8009A618)
/* 12FC 80025EFC 8C84A618 */  lw        $a0, %lo(D_8009A618)($a0)
/* 1300 80025F00 3C05B3FF */  lui       $a1, 0xb3ff
/* 1304 80025F04 34A50014 */  ori       $a1, $a1, 0x14
/* 1308 80025F08 0C01834C */  jal       func_80060D30
/* 130C 80025F0C 0240302D */   daddu    $a2, $s2, $zero
/* 1310 80025F10 24020001 */  addiu     $v0, $zero, 1
.L80025F14:
/* 1314 80025F14 8FBF003C */  lw        $ra, 0x3c($sp)
/* 1318 80025F18 8FBE0038 */  lw        $fp, 0x38($sp)
/* 131C 80025F1C 8FB70034 */  lw        $s7, 0x34($sp)
/* 1320 80025F20 8FB60030 */  lw        $s6, 0x30($sp)
/* 1324 80025F24 8FB5002C */  lw        $s5, 0x2c($sp)
/* 1328 80025F28 8FB40028 */  lw        $s4, 0x28($sp)
/* 132C 80025F2C 8FB30024 */  lw        $s3, 0x24($sp)
/* 1330 80025F30 8FB20020 */  lw        $s2, 0x20($sp)
/* 1334 80025F34 8FB1001C */  lw        $s1, 0x1c($sp)
/* 1338 80025F38 8FB00018 */  lw        $s0, 0x18($sp)
/* 133C 80025F3C 03E00008 */  jr        $ra
/* 1340 80025F40 27BD0040 */   addiu    $sp, $sp, 0x40
