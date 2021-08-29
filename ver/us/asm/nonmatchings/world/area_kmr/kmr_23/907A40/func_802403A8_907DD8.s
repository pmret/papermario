.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802403A8_907DD8
/* 907DD8 802403A8 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 907DDC 802403AC AFB20020 */  sw        $s2, 0x20($sp)
/* 907DE0 802403B0 0080902D */  daddu     $s2, $a0, $zero
/* 907DE4 802403B4 AFB00018 */  sw        $s0, 0x18($sp)
/* 907DE8 802403B8 00A0802D */  daddu     $s0, $a1, $zero
/* 907DEC 802403BC 3C05FD05 */  lui       $a1, 0xfd05
/* 907DF0 802403C0 AFBF0028 */  sw        $ra, 0x28($sp)
/* 907DF4 802403C4 AFB30024 */  sw        $s3, 0x24($sp)
/* 907DF8 802403C8 AFB1001C */  sw        $s1, 0x1c($sp)
/* 907DFC 802403CC 8E51000C */  lw        $s1, 0xc($s2)
/* 907E00 802403D0 0C0B1EAF */  jal       evt_get_variable
/* 907E04 802403D4 34A50F80 */   ori      $a1, $a1, 0xf80
/* 907E08 802403D8 12000015 */  beqz      $s0, .L80240430
/* 907E0C 802403DC 0040982D */   daddu    $s3, $v0, $zero
/* 907E10 802403E0 AE400070 */  sw        $zero, 0x70($s2)
/* 907E14 802403E4 8E250000 */  lw        $a1, ($s1)
/* 907E18 802403E8 26310004 */  addiu     $s1, $s1, 4
/* 907E1C 802403EC 0C0B1EAF */  jal       evt_get_variable
/* 907E20 802403F0 0240202D */   daddu    $a0, $s2, $zero
/* 907E24 802403F4 AE420084 */  sw        $v0, 0x84($s2)
/* 907E28 802403F8 8E250000 */  lw        $a1, ($s1)
/* 907E2C 802403FC 26310004 */  addiu     $s1, $s1, 4
/* 907E30 80240400 0C0B1EAF */  jal       evt_get_variable
/* 907E34 80240404 0240202D */   daddu    $a0, $s2, $zero
/* 907E38 80240408 AE420074 */  sw        $v0, 0x74($s2)
/* 907E3C 8024040C 8E250000 */  lw        $a1, ($s1)
/* 907E40 80240410 26310004 */  addiu     $s1, $s1, 4
/* 907E44 80240414 0C0B1EAF */  jal       evt_get_variable
/* 907E48 80240418 0240202D */   daddu    $a0, $s2, $zero
/* 907E4C 8024041C AE420078 */  sw        $v0, 0x78($s2)
/* 907E50 80240420 8E250000 */  lw        $a1, ($s1)
/* 907E54 80240424 0C0B1EAF */  jal       evt_get_variable
/* 907E58 80240428 0240202D */   daddu    $a0, $s2, $zero
/* 907E5C 8024042C AE42007C */  sw        $v0, 0x7c($s2)
.L80240430:
/* 907E60 80240430 C6400074 */  lwc1      $f0, 0x74($s2)
/* 907E64 80240434 46800020 */  cvt.s.w   $f0, $f0
/* 907E68 80240438 44050000 */  mfc1      $a1, $f0
/* 907E6C 8024043C C6400078 */  lwc1      $f0, 0x78($s2)
/* 907E70 80240440 46800020 */  cvt.s.w   $f0, $f0
/* 907E74 80240444 8E42007C */  lw        $v0, 0x7c($s2)
/* 907E78 80240448 44060000 */  mfc1      $a2, $f0
/* 907E7C 8024044C AFA20010 */  sw        $v0, 0x10($sp)
/* 907E80 80240450 8E440084 */  lw        $a0, 0x84($s2)
/* 907E84 80240454 0C00A8ED */  jal       update_lerp
/* 907E88 80240458 8E470070 */   lw       $a3, 0x70($s2)
/* 907E8C 8024045C E6600004 */  swc1      $f0, 4($s3)
/* 907E90 80240460 8E430070 */  lw        $v1, 0x70($s2)
/* 907E94 80240464 8E42007C */  lw        $v0, 0x7c($s2)
/* 907E98 80240468 24630001 */  addiu     $v1, $v1, 1
/* 907E9C 8024046C 0062102A */  slt       $v0, $v1, $v0
/* 907EA0 80240470 AE430070 */  sw        $v1, 0x70($s2)
/* 907EA4 80240474 8FBF0028 */  lw        $ra, 0x28($sp)
/* 907EA8 80240478 8FB30024 */  lw        $s3, 0x24($sp)
/* 907EAC 8024047C 8FB20020 */  lw        $s2, 0x20($sp)
/* 907EB0 80240480 8FB1001C */  lw        $s1, 0x1c($sp)
/* 907EB4 80240484 8FB00018 */  lw        $s0, 0x18($sp)
/* 907EB8 80240488 38420001 */  xori      $v0, $v0, 1
/* 907EBC 8024048C 03E00008 */  jr        $ra
/* 907EC0 80240490 27BD0030 */   addiu    $sp, $sp, 0x30
