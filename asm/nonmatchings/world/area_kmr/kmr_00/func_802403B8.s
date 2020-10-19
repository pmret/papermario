.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802403B8
/* 8AC348 802403B8 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 8AC34C 802403BC AFB1001C */  sw        $s1, 0x1c($sp)
/* 8AC350 802403C0 0080882D */  daddu     $s1, $a0, $zero
/* 8AC354 802403C4 AFBF002C */  sw        $ra, 0x2c($sp)
/* 8AC358 802403C8 AFB40028 */  sw        $s4, 0x28($sp)
/* 8AC35C 802403CC AFB30024 */  sw        $s3, 0x24($sp)
/* 8AC360 802403D0 AFB20020 */  sw        $s2, 0x20($sp)
/* 8AC364 802403D4 AFB00018 */  sw        $s0, 0x18($sp)
/* 8AC368 802403D8 8E30000C */  lw        $s0, 0xc($s1)
/* 8AC36C 802403DC 8E050000 */  lw        $a1, ($s0)
/* 8AC370 802403E0 0C0B1EAF */  jal       get_variable
/* 8AC374 802403E4 26100004 */   addiu    $s0, $s0, 4
/* 8AC378 802403E8 8E050000 */  lw        $a1, ($s0)
/* 8AC37C 802403EC 26100004 */  addiu     $s0, $s0, 4
/* 8AC380 802403F0 0220202D */  daddu     $a0, $s1, $zero
/* 8AC384 802403F4 0C0B1EAF */  jal       get_variable
/* 8AC388 802403F8 0040A02D */   daddu    $s4, $v0, $zero
/* 8AC38C 802403FC 8E050000 */  lw        $a1, ($s0)
/* 8AC390 80240400 26100004 */  addiu     $s0, $s0, 4
/* 8AC394 80240404 0220202D */  daddu     $a0, $s1, $zero
/* 8AC398 80240408 0C0B1EAF */  jal       get_variable
/* 8AC39C 8024040C 0040982D */   daddu    $s3, $v0, $zero
/* 8AC3A0 80240410 8E050000 */  lw        $a1, ($s0)
/* 8AC3A4 80240414 26100004 */  addiu     $s0, $s0, 4
/* 8AC3A8 80240418 0220202D */  daddu     $a0, $s1, $zero
/* 8AC3AC 8024041C 0C0B1EAF */  jal       get_variable
/* 8AC3B0 80240420 0040902D */   daddu    $s2, $v0, $zero
/* 8AC3B4 80240424 0220202D */  daddu     $a0, $s1, $zero
/* 8AC3B8 80240428 8E050000 */  lw        $a1, ($s0)
/* 8AC3BC 8024042C 0C0B1EAF */  jal       get_variable
/* 8AC3C0 80240430 0040802D */   daddu    $s0, $v0, $zero
/* 8AC3C4 80240434 0280202D */  daddu     $a0, $s4, $zero
/* 8AC3C8 80240438 44931000 */  mtc1      $s3, $f2
/* 8AC3CC 8024043C 00000000 */  nop       
/* 8AC3D0 80240440 468010A0 */  cvt.s.w   $f2, $f2
/* 8AC3D4 80240444 44051000 */  mfc1      $a1, $f2
/* 8AC3D8 80240448 44921000 */  mtc1      $s2, $f2
/* 8AC3DC 8024044C 00000000 */  nop       
/* 8AC3E0 80240450 468010A0 */  cvt.s.w   $f2, $f2
/* 8AC3E4 80240454 44061000 */  mfc1      $a2, $f2
/* 8AC3E8 80240458 44901000 */  mtc1      $s0, $f2
/* 8AC3EC 8024045C 00000000 */  nop       
/* 8AC3F0 80240460 468010A0 */  cvt.s.w   $f2, $f2
/* 8AC3F4 80240464 44071000 */  mfc1      $a3, $f2
/* 8AC3F8 80240468 44820000 */  mtc1      $v0, $f0
/* 8AC3FC 8024046C 00000000 */  nop       
/* 8AC400 80240470 46800020 */  cvt.s.w   $f0, $f0
/* 8AC404 80240474 0C01BFBC */  jal       func_8006FEF0
/* 8AC408 80240478 E7A00010 */   swc1     $f0, 0x10($sp)
/* 8AC40C 8024047C 8FBF002C */  lw        $ra, 0x2c($sp)
/* 8AC410 80240480 8FB40028 */  lw        $s4, 0x28($sp)
/* 8AC414 80240484 8FB30024 */  lw        $s3, 0x24($sp)
/* 8AC418 80240488 8FB20020 */  lw        $s2, 0x20($sp)
/* 8AC41C 8024048C 8FB1001C */  lw        $s1, 0x1c($sp)
/* 8AC420 80240490 8FB00018 */  lw        $s0, 0x18($sp)
/* 8AC424 80240494 24020002 */  addiu     $v0, $zero, 2
/* 8AC428 80240498 03E00008 */  jr        $ra
/* 8AC42C 8024049C 27BD0030 */   addiu    $sp, $sp, 0x30
