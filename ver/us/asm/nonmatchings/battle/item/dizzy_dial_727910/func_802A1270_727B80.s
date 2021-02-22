.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A1270_727B80
/* 727B80 802A1270 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 727B84 802A1274 AFB00018 */  sw        $s0, 0x18($sp)
/* 727B88 802A1278 0080802D */  daddu     $s0, $a0, $zero
/* 727B8C 802A127C AFB1001C */  sw        $s1, 0x1c($sp)
/* 727B90 802A1280 3C11800B */  lui       $s1, %hi(gCameras+0x558)
/* 727B94 802A1284 263122D8 */  addiu     $s1, $s1, %lo(gCameras+0x558)
/* 727B98 802A1288 10A00002 */  beqz      $a1, .L802A1294
/* 727B9C 802A128C AFBF0020 */   sw       $ra, 0x20($sp)
/* 727BA0 802A1290 AE000070 */  sw        $zero, 0x70($s0)
.L802A1294:
/* 727BA4 802A1294 8E030070 */  lw        $v1, 0x70($s0)
/* 727BA8 802A1298 10600005 */  beqz      $v1, .L802A12B0
/* 727BAC 802A129C 24020001 */   addiu    $v0, $zero, 1
/* 727BB0 802A12A0 10620010 */  beq       $v1, $v0, .L802A12E4
/* 727BB4 802A12A4 0000102D */   daddu    $v0, $zero, $zero
/* 727BB8 802A12A8 080A84EF */  j         .L802A13BC
/* 727BBC 802A12AC 00000000 */   nop
.L802A12B0:
/* 727BC0 802A12B0 24042033 */  addiu     $a0, $zero, 0x2033
/* 727BC4 802A12B4 AE000074 */  sw        $zero, 0x74($s0)
/* 727BC8 802A12B8 0C05272D */  jal       play_sound
/* 727BCC 802A12BC AE000078 */   sw       $zero, 0x78($s0)
/* 727BD0 802A12C0 0000202D */  daddu     $a0, $zero, $zero
/* 727BD4 802A12C4 3C05802A */  lui       $a1, %hi(func_802A123C_727B4C)
/* 727BD8 802A12C8 24A5123C */  addiu     $a1, $a1, %lo(func_802A123C_727B4C)
/* 727BDC 802A12CC 0C048C8F */  jal       bind_dynamic_entity_7
/* 727BE0 802A12D0 A620001C */   sh       $zero, 0x1c($s1)
/* 727BE4 802A12D4 3C01802A */  lui       $at, %hi(D_802A1CD0)
/* 727BE8 802A12D8 AC221CD0 */  sw        $v0, %lo(D_802A1CD0)($at)
/* 727BEC 802A12DC 24020001 */  addiu     $v0, $zero, 1
/* 727BF0 802A12E0 AE020070 */  sw        $v0, 0x70($s0)
.L802A12E4:
/* 727BF4 802A12E4 96220000 */  lhu       $v0, ($s1)
/* 727BF8 802A12E8 34420008 */  ori       $v0, $v0, 8
/* 727BFC 802A12EC A6220000 */  sh        $v0, ($s1)
/* 727C00 802A12F0 C6000074 */  lwc1      $f0, 0x74($s0)
/* 727C04 802A12F4 46800020 */  cvt.s.w   $f0, $f0
/* 727C08 802A12F8 44050000 */  mfc1      $a1, $f0
/* 727C0C 802A12FC 44800000 */  mtc1      $zero, $f0
/* 727C10 802A1300 3C013F80 */  lui       $at, 0x3f80
/* 727C14 802A1304 44811000 */  mtc1      $at, $f2
/* 727C18 802A1308 44060000 */  mfc1      $a2, $f0
/* 727C1C 802A130C 26240194 */  addiu     $a0, $s1, 0x194
/* 727C20 802A1310 E7A20010 */  swc1      $f2, 0x10($sp)
/* 727C24 802A1314 0C019EC8 */  jal       guRotateF
/* 727C28 802A1318 00C0382D */   daddu    $a3, $a2, $zero
/* 727C2C 802A131C 8E020078 */  lw        $v0, 0x78($s0)
/* 727C30 802A1320 3C0140C9 */  lui       $at, 0x40c9
/* 727C34 802A1324 34210FD0 */  ori       $at, $at, 0xfd0
/* 727C38 802A1328 44810000 */  mtc1      $at, $f0
/* 727C3C 802A132C 2442005A */  addiu     $v0, $v0, 0x5a
/* 727C40 802A1330 44826000 */  mtc1      $v0, $f12
/* 727C44 802A1334 00000000 */  nop
/* 727C48 802A1338 46806320 */  cvt.s.w   $f12, $f12
/* 727C4C 802A133C 46006302 */  mul.s     $f12, $f12, $f0
/* 727C50 802A1340 00000000 */  nop
/* 727C54 802A1344 3C0143B4 */  lui       $at, 0x43b4
/* 727C58 802A1348 44810000 */  mtc1      $at, $f0
/* 727C5C 802A134C 0C00A85B */  jal       sin_rad
/* 727C60 802A1350 46006303 */   div.s    $f12, $f12, $f0
/* 727C64 802A1354 3C013FF0 */  lui       $at, 0x3ff0
/* 727C68 802A1358 44811800 */  mtc1      $at, $f3
/* 727C6C 802A135C 44801000 */  mtc1      $zero, $f2
/* 727C70 802A1360 46000021 */  cvt.d.s   $f0, $f0
/* 727C74 802A1364 46201081 */  sub.d     $f2, $f2, $f0
/* 727C78 802A1368 3C01802A */  lui       $at, %hi(D_802A1CC0_7285D0)
/* 727C7C 802A136C D4201CC0 */  ldc1      $f0, %lo(D_802A1CC0_7285D0)($at)
/* 727C80 802A1370 46201082 */  mul.d     $f2, $f2, $f0
/* 727C84 802A1374 00000000 */  nop
/* 727C88 802A1378 8E020078 */  lw        $v0, 0x78($s0)
/* 727C8C 802A137C 24420001 */  addiu     $v0, $v0, 1
/* 727C90 802A1380 46221080 */  add.d     $f2, $f2, $f2
/* 727C94 802A1384 AE020078 */  sw        $v0, 0x78($s0)
/* 727C98 802A1388 2842005B */  slti      $v0, $v0, 0x5b
/* 727C9C 802A138C 4620110D */  trunc.w.d $f4, $f2
/* 727CA0 802A1390 E6040074 */  swc1      $f4, 0x74($s0)
/* 727CA4 802A1394 54400009 */  bnel      $v0, $zero, .L802A13BC
/* 727CA8 802A1398 0000102D */   daddu    $v0, $zero, $zero
/* 727CAC 802A139C 3C04802A */  lui       $a0, %hi(D_802A1CD0)
/* 727CB0 802A13A0 8C841CD0 */  lw        $a0, %lo(D_802A1CD0)($a0)
/* 727CB4 802A13A4 96220000 */  lhu       $v0, ($s1)
/* 727CB8 802A13A8 A620001C */  sh        $zero, 0x1c($s1)
/* 727CBC 802A13AC 3042FFF7 */  andi      $v0, $v0, 0xfff7
/* 727CC0 802A13B0 0C048D70 */  jal       func_801235C0
/* 727CC4 802A13B4 A6220000 */   sh       $v0, ($s1)
/* 727CC8 802A13B8 24020002 */  addiu     $v0, $zero, 2
.L802A13BC:
/* 727CCC 802A13BC 8FBF0020 */  lw        $ra, 0x20($sp)
/* 727CD0 802A13C0 8FB1001C */  lw        $s1, 0x1c($sp)
/* 727CD4 802A13C4 8FB00018 */  lw        $s0, 0x18($sp)
/* 727CD8 802A13C8 03E00008 */  jr        $ra
/* 727CDC 802A13CC 27BD0028 */   addiu    $sp, $sp, 0x28
