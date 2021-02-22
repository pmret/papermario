.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240358_EA8E38
/* EA8E38 80240358 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* EA8E3C 8024035C AFB20020 */  sw        $s2, 0x20($sp)
/* EA8E40 80240360 0080902D */  daddu     $s2, $a0, $zero
/* EA8E44 80240364 AFBF0024 */  sw        $ra, 0x24($sp)
/* EA8E48 80240368 AFB1001C */  sw        $s1, 0x1c($sp)
/* EA8E4C 8024036C AFB00018 */  sw        $s0, 0x18($sp)
/* EA8E50 80240370 10A0004A */  beqz      $a1, .L8024049C
/* EA8E54 80240374 8E51000C */   lw       $s1, 0xc($s2)
/* EA8E58 80240378 0C00AFF5 */  jal       func_8002BFD4
/* EA8E5C 8024037C 24040058 */   addiu    $a0, $zero, 0x58
/* EA8E60 80240380 0000202D */  daddu     $a0, $zero, $zero
/* EA8E64 80240384 3C05FD05 */  lui       $a1, 0xfd05
/* EA8E68 80240388 34A50F81 */  ori       $a1, $a1, 0xf81
/* EA8E6C 8024038C 0040802D */  daddu     $s0, $v0, $zero
/* EA8E70 80240390 0200302D */  daddu     $a2, $s0, $zero
/* EA8E74 80240394 0C0B551A */  jal       func_802D5468
/* EA8E78 80240398 AE500084 */   sw       $s0, 0x84($s2)
/* EA8E7C 8024039C 8E250000 */  lw        $a1, ($s1)
/* EA8E80 802403A0 26310004 */  addiu     $s1, $s1, 4
/* EA8E84 802403A4 0C0B53A3 */  jal       func_802D4E8C
/* EA8E88 802403A8 0240202D */   daddu    $a0, $s2, $zero
/* EA8E8C 802403AC AE020038 */  sw        $v0, 0x38($s0)
/* EA8E90 802403B0 8E250000 */  lw        $a1, ($s1)
/* EA8E94 802403B4 26310004 */  addiu     $s1, $s1, 4
/* EA8E98 802403B8 0C0B53A3 */  jal       func_802D4E8C
/* EA8E9C 802403BC 0240202D */   daddu    $a0, $s2, $zero
/* EA8EA0 802403C0 AE02003C */  sw        $v0, 0x3c($s0)
/* EA8EA4 802403C4 8E250000 */  lw        $a1, ($s1)
/* EA8EA8 802403C8 26310004 */  addiu     $s1, $s1, 4
/* EA8EAC 802403CC 0C0B55FF */  jal       func_802D57FC
/* EA8EB0 802403D0 0240202D */   daddu    $a0, $s2, $zero
/* EA8EB4 802403D4 E600000C */  swc1      $f0, 0xc($s0)
/* EA8EB8 802403D8 8E250000 */  lw        $a1, ($s1)
/* EA8EBC 802403DC 26310004 */  addiu     $s1, $s1, 4
/* EA8EC0 802403E0 0C0B55FF */  jal       func_802D57FC
/* EA8EC4 802403E4 0240202D */   daddu    $a0, $s2, $zero
/* EA8EC8 802403E8 E6000010 */  swc1      $f0, 0x10($s0)
/* EA8ECC 802403EC 8E250000 */  lw        $a1, ($s1)
/* EA8ED0 802403F0 26310004 */  addiu     $s1, $s1, 4
/* EA8ED4 802403F4 0C0B55FF */  jal       func_802D57FC
/* EA8ED8 802403F8 0240202D */   daddu    $a0, $s2, $zero
/* EA8EDC 802403FC E6000014 */  swc1      $f0, 0x14($s0)
/* EA8EE0 80240400 8E250000 */  lw        $a1, ($s1)
/* EA8EE4 80240404 26310004 */  addiu     $s1, $s1, 4
/* EA8EE8 80240408 0C0B55FF */  jal       func_802D57FC
/* EA8EEC 8024040C 0240202D */   daddu    $a0, $s2, $zero
/* EA8EF0 80240410 E6000018 */  swc1      $f0, 0x18($s0)
/* EA8EF4 80240414 8E250000 */  lw        $a1, ($s1)
/* EA8EF8 80240418 26310004 */  addiu     $s1, $s1, 4
/* EA8EFC 8024041C 0C0B55FF */  jal       func_802D57FC
/* EA8F00 80240420 0240202D */   daddu    $a0, $s2, $zero
/* EA8F04 80240424 E600001C */  swc1      $f0, 0x1c($s0)
/* EA8F08 80240428 8E250000 */  lw        $a1, ($s1)
/* EA8F0C 8024042C 26310004 */  addiu     $s1, $s1, 4
/* EA8F10 80240430 0C0B55FF */  jal       func_802D57FC
/* EA8F14 80240434 0240202D */   daddu    $a0, $s2, $zero
/* EA8F18 80240438 E6000020 */  swc1      $f0, 0x20($s0)
/* EA8F1C 8024043C 8E250000 */  lw        $a1, ($s1)
/* EA8F20 80240440 26310004 */  addiu     $s1, $s1, 4
/* EA8F24 80240444 0C0B55FF */  jal       func_802D57FC
/* EA8F28 80240448 0240202D */   daddu    $a0, $s2, $zero
/* EA8F2C 8024044C E6000024 */  swc1      $f0, 0x24($s0)
/* EA8F30 80240450 8E250000 */  lw        $a1, ($s1)
/* EA8F34 80240454 0C0B55FF */  jal       func_802D57FC
/* EA8F38 80240458 0240202D */   daddu    $a0, $s2, $zero
/* EA8F3C 8024045C 3C013F80 */  lui       $at, 0x3f80
/* EA8F40 80240460 44811000 */  mtc1      $at, $f2
/* EA8F44 80240464 E6000028 */  swc1      $f0, 0x28($s0)
/* EA8F48 80240468 AFA00014 */  sw        $zero, 0x14($sp)
/* EA8F4C 8024046C E7A20010 */  swc1      $f2, 0x10($sp)
/* EA8F50 80240470 8E05000C */  lw        $a1, 0xc($s0)
/* EA8F54 80240474 8E060010 */  lw        $a2, 0x10($s0)
/* EA8F58 80240478 8E070014 */  lw        $a3, 0x14($s0)
/* EA8F5C 8024047C 0C01DF0C */  jal       func_80077C30
/* EA8F60 80240480 24040002 */   addiu    $a0, $zero, 2
/* EA8F64 80240484 AE020050 */  sw        $v0, 0x50($s0)
/* EA8F68 80240488 A600004E */  sh        $zero, 0x4e($s0)
/* EA8F6C 8024048C A6000048 */  sh        $zero, 0x48($s0)
/* EA8F70 80240490 A600004A */  sh        $zero, 0x4a($s0)
/* EA8F74 80240494 A6000044 */  sh        $zero, 0x44($s0)
/* EA8F78 80240498 A6000046 */  sh        $zero, 0x46($s0)
.L8024049C:
/* EA8F7C 8024049C 8FBF0024 */  lw        $ra, 0x24($sp)
/* EA8F80 802404A0 8FB20020 */  lw        $s2, 0x20($sp)
/* EA8F84 802404A4 8FB1001C */  lw        $s1, 0x1c($sp)
/* EA8F88 802404A8 8FB00018 */  lw        $s0, 0x18($sp)
/* EA8F8C 802404AC 24020002 */  addiu     $v0, $zero, 2
/* EA8F90 802404B0 03E00008 */  jr        $ra
/* EA8F94 802404B4 27BD0028 */   addiu    $sp, $sp, 0x28
