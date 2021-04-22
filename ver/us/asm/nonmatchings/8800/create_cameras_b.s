.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel create_cameras_b
/* 9438 8002E038 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 943C 8002E03C AFB60040 */  sw        $s6, 0x40($sp)
/* 9440 8002E040 27B60010 */  addiu     $s6, $sp, 0x10
/* 9444 8002E044 24030003 */  addiu     $v1, $zero, 3
/* 9448 8002E048 3C02800B */  lui       $v0, %hi(gCameras+0x1008)
/* 944C 8002E04C 24422D88 */  addiu     $v0, $v0, %lo(gCameras+0x1008)
/* 9450 8002E050 AFBF0044 */  sw        $ra, 0x44($sp)
/* 9454 8002E054 AFB5003C */  sw        $s5, 0x3c($sp)
/* 9458 8002E058 AFB40038 */  sw        $s4, 0x38($sp)
/* 945C 8002E05C AFB30034 */  sw        $s3, 0x34($sp)
/* 9460 8002E060 AFB20030 */  sw        $s2, 0x30($sp)
/* 9464 8002E064 AFB1002C */  sw        $s1, 0x2c($sp)
/* 9468 8002E068 AFB00028 */  sw        $s0, 0x28($sp)
.L8002E06C:
/* 946C 8002E06C A4400000 */  sh        $zero, ($v0)
/* 9470 8002E070 2463FFFF */  addiu     $v1, $v1, -1
/* 9474 8002E074 0461FFFD */  bgez      $v1, .L8002E06C
/* 9478 8002E078 2442FAA8 */   addiu    $v0, $v0, -0x558
/* 947C 8002E07C 02C0202D */  daddu     $a0, $s6, $zero
/* 9480 8002E080 24150002 */  addiu     $s5, $zero, 2
/* 9484 8002E084 241100A0 */  addiu     $s1, $zero, 0xa0
/* 9488 8002E088 24100078 */  addiu     $s0, $zero, 0x78
/* 948C 8002E08C 24140008 */  addiu     $s4, $zero, 8
/* 9490 8002E090 24134000 */  addiu     $s3, $zero, 0x4000
/* 9494 8002E094 24120032 */  addiu     $s2, $zero, 0x32
/* 9498 8002E098 A6D50000 */  sh        $s5, ($s6)
/* 949C 8002E09C A2C00002 */  sb        $zero, 2($s6)
/* 94A0 8002E0A0 A6D10004 */  sh        $s1, 4($s6)
/* 94A4 8002E0A4 A6D00006 */  sh        $s0, 6($s6)
/* 94A8 8002E0A8 A6C00008 */  sh        $zero, 8($s6)
/* 94AC 8002E0AC A6C0000A */  sh        $zero, 0xa($s6)
/* 94B0 8002E0B0 A6D4000C */  sh        $s4, 0xc($s6)
/* 94B4 8002E0B4 A6D3000E */  sh        $s3, 0xe($s6)
/* 94B8 8002E0B8 0C00B85B */  jal       initialize_next_camera
/* 94BC 8002E0BC A6D20010 */   sh       $s2, 0x10($s6)
/* 94C0 8002E0C0 02C0202D */  daddu     $a0, $s6, $zero
/* 94C4 8002E0C4 A6D50000 */  sh        $s5, ($s6)
/* 94C8 8002E0C8 A2C00002 */  sb        $zero, 2($s6)
/* 94CC 8002E0CC A6D10004 */  sh        $s1, 4($s6)
/* 94D0 8002E0D0 A6D00006 */  sh        $s0, 6($s6)
/* 94D4 8002E0D4 A6D10008 */  sh        $s1, 8($s6)
/* 94D8 8002E0D8 A6C0000A */  sh        $zero, 0xa($s6)
/* 94DC 8002E0DC A6D4000C */  sh        $s4, 0xc($s6)
/* 94E0 8002E0E0 A6D3000E */  sh        $s3, 0xe($s6)
/* 94E4 8002E0E4 0C00B85B */  jal       initialize_next_camera
/* 94E8 8002E0E8 A6D20010 */   sh       $s2, 0x10($s6)
/* 94EC 8002E0EC 02C0202D */  daddu     $a0, $s6, $zero
/* 94F0 8002E0F0 A6D50000 */  sh        $s5, ($s6)
/* 94F4 8002E0F4 A2C00002 */  sb        $zero, 2($s6)
/* 94F8 8002E0F8 A6D10004 */  sh        $s1, 4($s6)
/* 94FC 8002E0FC A6D00006 */  sh        $s0, 6($s6)
/* 9500 8002E100 A6C00008 */  sh        $zero, 8($s6)
/* 9504 8002E104 A6D0000A */  sh        $s0, 0xa($s6)
/* 9508 8002E108 A6D4000C */  sh        $s4, 0xc($s6)
/* 950C 8002E10C A6D3000E */  sh        $s3, 0xe($s6)
/* 9510 8002E110 0C00B85B */  jal       initialize_next_camera
/* 9514 8002E114 A6D20010 */   sh       $s2, 0x10($s6)
/* 9518 8002E118 02C0202D */  daddu     $a0, $s6, $zero
/* 951C 8002E11C A4950000 */  sh        $s5, ($a0)
/* 9520 8002E120 A0800002 */  sb        $zero, 2($a0)
/* 9524 8002E124 A4910004 */  sh        $s1, 4($a0)
/* 9528 8002E128 A4900006 */  sh        $s0, 6($a0)
/* 952C 8002E12C A4910008 */  sh        $s1, 8($a0)
/* 9530 8002E130 A490000A */  sh        $s0, 0xa($a0)
/* 9534 8002E134 A494000C */  sh        $s4, 0xc($a0)
/* 9538 8002E138 A493000E */  sh        $s3, 0xe($a0)
/* 953C 8002E13C 0C00B85B */  jal       initialize_next_camera
/* 9540 8002E140 A4920010 */   sh       $s2, 0x10($a0)
/* 9544 8002E144 8FBF0044 */  lw        $ra, 0x44($sp)
/* 9548 8002E148 8FB60040 */  lw        $s6, 0x40($sp)
/* 954C 8002E14C 8FB5003C */  lw        $s5, 0x3c($sp)
/* 9550 8002E150 8FB40038 */  lw        $s4, 0x38($sp)
/* 9554 8002E154 8FB30034 */  lw        $s3, 0x34($sp)
/* 9558 8002E158 8FB20030 */  lw        $s2, 0x30($sp)
/* 955C 8002E15C 8FB1002C */  lw        $s1, 0x2c($sp)
/* 9560 8002E160 8FB00028 */  lw        $s0, 0x28($sp)
/* 9564 8002E164 03E00008 */  jr        $ra
/* 9568 8002E168 27BD0048 */   addiu    $sp, $sp, 0x48
