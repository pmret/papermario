.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240358_C8DF08
/* C8DF08 80240358 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* C8DF0C 8024035C AFB20020 */  sw        $s2, 0x20($sp)
/* C8DF10 80240360 0080902D */  daddu     $s2, $a0, $zero
/* C8DF14 80240364 AFBF0024 */  sw        $ra, 0x24($sp)
/* C8DF18 80240368 AFB1001C */  sw        $s1, 0x1c($sp)
/* C8DF1C 8024036C AFB00018 */  sw        $s0, 0x18($sp)
/* C8DF20 80240370 10A0004A */  beqz      $a1, .L8024049C
/* C8DF24 80240374 8E51000C */   lw       $s1, 0xc($s2)
/* C8DF28 80240378 0C00AB39 */  jal       heap_malloc
/* C8DF2C 8024037C 24040058 */   addiu    $a0, $zero, 0x58
/* C8DF30 80240380 0000202D */  daddu     $a0, $zero, $zero
/* C8DF34 80240384 3C05FD05 */  lui       $a1, 0xfd05
/* C8DF38 80240388 34A50F81 */  ori       $a1, $a1, 0xf81
/* C8DF3C 8024038C 0040802D */  daddu     $s0, $v0, $zero
/* C8DF40 80240390 0200302D */  daddu     $a2, $s0, $zero
/* C8DF44 80240394 0C0B2026 */  jal       evt_set_variable
/* C8DF48 80240398 AE500084 */   sw       $s0, 0x84($s2)
/* C8DF4C 8024039C 8E250000 */  lw        $a1, ($s1)
/* C8DF50 802403A0 26310004 */  addiu     $s1, $s1, 4
/* C8DF54 802403A4 0C0B1EAF */  jal       evt_get_variable
/* C8DF58 802403A8 0240202D */   daddu    $a0, $s2, $zero
/* C8DF5C 802403AC AE020038 */  sw        $v0, 0x38($s0)
/* C8DF60 802403B0 8E250000 */  lw        $a1, ($s1)
/* C8DF64 802403B4 26310004 */  addiu     $s1, $s1, 4
/* C8DF68 802403B8 0C0B1EAF */  jal       evt_get_variable
/* C8DF6C 802403BC 0240202D */   daddu    $a0, $s2, $zero
/* C8DF70 802403C0 AE02003C */  sw        $v0, 0x3c($s0)
/* C8DF74 802403C4 8E250000 */  lw        $a1, ($s1)
/* C8DF78 802403C8 26310004 */  addiu     $s1, $s1, 4
/* C8DF7C 802403CC 0C0B210B */  jal       evt_get_float_variable
/* C8DF80 802403D0 0240202D */   daddu    $a0, $s2, $zero
/* C8DF84 802403D4 E600000C */  swc1      $f0, 0xc($s0)
/* C8DF88 802403D8 8E250000 */  lw        $a1, ($s1)
/* C8DF8C 802403DC 26310004 */  addiu     $s1, $s1, 4
/* C8DF90 802403E0 0C0B210B */  jal       evt_get_float_variable
/* C8DF94 802403E4 0240202D */   daddu    $a0, $s2, $zero
/* C8DF98 802403E8 E6000010 */  swc1      $f0, 0x10($s0)
/* C8DF9C 802403EC 8E250000 */  lw        $a1, ($s1)
/* C8DFA0 802403F0 26310004 */  addiu     $s1, $s1, 4
/* C8DFA4 802403F4 0C0B210B */  jal       evt_get_float_variable
/* C8DFA8 802403F8 0240202D */   daddu    $a0, $s2, $zero
/* C8DFAC 802403FC E6000014 */  swc1      $f0, 0x14($s0)
/* C8DFB0 80240400 8E250000 */  lw        $a1, ($s1)
/* C8DFB4 80240404 26310004 */  addiu     $s1, $s1, 4
/* C8DFB8 80240408 0C0B210B */  jal       evt_get_float_variable
/* C8DFBC 8024040C 0240202D */   daddu    $a0, $s2, $zero
/* C8DFC0 80240410 E6000018 */  swc1      $f0, 0x18($s0)
/* C8DFC4 80240414 8E250000 */  lw        $a1, ($s1)
/* C8DFC8 80240418 26310004 */  addiu     $s1, $s1, 4
/* C8DFCC 8024041C 0C0B210B */  jal       evt_get_float_variable
/* C8DFD0 80240420 0240202D */   daddu    $a0, $s2, $zero
/* C8DFD4 80240424 E600001C */  swc1      $f0, 0x1c($s0)
/* C8DFD8 80240428 8E250000 */  lw        $a1, ($s1)
/* C8DFDC 8024042C 26310004 */  addiu     $s1, $s1, 4
/* C8DFE0 80240430 0C0B210B */  jal       evt_get_float_variable
/* C8DFE4 80240434 0240202D */   daddu    $a0, $s2, $zero
/* C8DFE8 80240438 E6000020 */  swc1      $f0, 0x20($s0)
/* C8DFEC 8024043C 8E250000 */  lw        $a1, ($s1)
/* C8DFF0 80240440 26310004 */  addiu     $s1, $s1, 4
/* C8DFF4 80240444 0C0B210B */  jal       evt_get_float_variable
/* C8DFF8 80240448 0240202D */   daddu    $a0, $s2, $zero
/* C8DFFC 8024044C E6000024 */  swc1      $f0, 0x24($s0)
/* C8E000 80240450 8E250000 */  lw        $a1, ($s1)
/* C8E004 80240454 0C0B210B */  jal       evt_get_float_variable
/* C8E008 80240458 0240202D */   daddu    $a0, $s2, $zero
/* C8E00C 8024045C 3C013F80 */  lui       $at, 0x3f80
/* C8E010 80240460 44811000 */  mtc1      $at, $f2
/* C8E014 80240464 E6000028 */  swc1      $f0, 0x28($s0)
/* C8E018 80240468 AFA00014 */  sw        $zero, 0x14($sp)
/* C8E01C 8024046C E7A20010 */  swc1      $f2, 0x10($sp)
/* C8E020 80240470 8E05000C */  lw        $a1, 0xc($s0)
/* C8E024 80240474 8E060010 */  lw        $a2, 0x10($s0)
/* C8E028 80240478 8E070014 */  lw        $a3, 0x14($s0)
/* C8E02C 8024047C 0C01CA6C */  jal       playFX_83
/* C8E030 80240480 24040002 */   addiu    $a0, $zero, 2
/* C8E034 80240484 AE020050 */  sw        $v0, 0x50($s0)
/* C8E038 80240488 A600004E */  sh        $zero, 0x4e($s0)
/* C8E03C 8024048C A6000048 */  sh        $zero, 0x48($s0)
/* C8E040 80240490 A600004A */  sh        $zero, 0x4a($s0)
/* C8E044 80240494 A6000044 */  sh        $zero, 0x44($s0)
/* C8E048 80240498 A6000046 */  sh        $zero, 0x46($s0)
.L8024049C:
/* C8E04C 8024049C 8FBF0024 */  lw        $ra, 0x24($sp)
/* C8E050 802404A0 8FB20020 */  lw        $s2, 0x20($sp)
/* C8E054 802404A4 8FB1001C */  lw        $s1, 0x1c($sp)
/* C8E058 802404A8 8FB00018 */  lw        $s0, 0x18($sp)
/* C8E05C 802404AC 24020002 */  addiu     $v0, $zero, 2
/* C8E060 802404B0 03E00008 */  jr        $ra
/* C8E064 802404B4 27BD0028 */   addiu    $sp, $sp, 0x28
