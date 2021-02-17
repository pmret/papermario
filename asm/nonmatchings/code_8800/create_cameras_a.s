.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel create_cameras_a
/* 92F4 8002DEF4 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 92F8 8002DEF8 AFB60040 */  sw        $s6, 0x40($sp)
/* 92FC 8002DEFC 27B60010 */  addiu     $s6, $sp, 0x10
/* 9300 8002DF00 24030003 */  addiu     $v1, $zero, 3
/* 9304 8002DF04 3C013F80 */  lui       $at, 0x3f80
/* 9308 8002DF08 44810000 */  mtc1      $at, $f0
/* 930C 8002DF0C 3C02800B */  lui       $v0, %hi(gCameras+0x1008)
/* 9310 8002DF10 24422D88 */  addiu     $v0, $v0, %lo(gCameras+0x1008)
/* 9314 8002DF14 AFBF0044 */  sw        $ra, 0x44($sp)
/* 9318 8002DF18 AFB5003C */  sw        $s5, 0x3c($sp)
/* 931C 8002DF1C AFB40038 */  sw        $s4, 0x38($sp)
/* 9320 8002DF20 AFB30034 */  sw        $s3, 0x34($sp)
/* 9324 8002DF24 AFB20030 */  sw        $s2, 0x30($sp)
/* 9328 8002DF28 AFB1002C */  sw        $s1, 0x2c($sp)
/* 932C 8002DF2C AFB00028 */  sw        $s0, 0x28($sp)
/* 9330 8002DF30 3C01800A */  lui       $at, %hi(D_8009A5EC)
/* 9334 8002DF34 E420A5EC */  swc1      $f0, %lo(D_8009A5EC)($at)
.L8002DF38:
/* 9338 8002DF38 A4400000 */  sh        $zero, ($v0)
/* 933C 8002DF3C 2463FFFF */  addiu     $v1, $v1, -1
/* 9340 8002DF40 0461FFFD */  bgez      $v1, .L8002DF38
/* 9344 8002DF44 2442FAA8 */   addiu    $v0, $v0, -0x558
/* 9348 8002DF48 02C0202D */  daddu     $a0, $s6, $zero
/* 934C 8002DF4C 24150002 */  addiu     $s5, $zero, 2
/* 9350 8002DF50 241100A0 */  addiu     $s1, $zero, 0xa0
/* 9354 8002DF54 24100078 */  addiu     $s0, $zero, 0x78
/* 9358 8002DF58 24140008 */  addiu     $s4, $zero, 8
/* 935C 8002DF5C 24134000 */  addiu     $s3, $zero, 0x4000
/* 9360 8002DF60 24120032 */  addiu     $s2, $zero, 0x32
/* 9364 8002DF64 A6D50000 */  sh        $s5, ($s6)
/* 9368 8002DF68 A2C00002 */  sb        $zero, 2($s6)
/* 936C 8002DF6C A6D10004 */  sh        $s1, 4($s6)
/* 9370 8002DF70 A6D00006 */  sh        $s0, 6($s6)
/* 9374 8002DF74 A6C00008 */  sh        $zero, 8($s6)
/* 9378 8002DF78 A6C0000A */  sh        $zero, 0xa($s6)
/* 937C 8002DF7C A6D4000C */  sh        $s4, 0xc($s6)
/* 9380 8002DF80 A6D3000E */  sh        $s3, 0xe($s6)
/* 9384 8002DF84 0C00B85B */  jal       initialize_next_camera
/* 9388 8002DF88 A6D20010 */   sh       $s2, 0x10($s6)
/* 938C 8002DF8C 02C0202D */  daddu     $a0, $s6, $zero
/* 9390 8002DF90 A6D50000 */  sh        $s5, ($s6)
/* 9394 8002DF94 A2C00002 */  sb        $zero, 2($s6)
/* 9398 8002DF98 A6D10004 */  sh        $s1, 4($s6)
/* 939C 8002DF9C A6D00006 */  sh        $s0, 6($s6)
/* 93A0 8002DFA0 A6D10008 */  sh        $s1, 8($s6)
/* 93A4 8002DFA4 A6C0000A */  sh        $zero, 0xa($s6)
/* 93A8 8002DFA8 A6D4000C */  sh        $s4, 0xc($s6)
/* 93AC 8002DFAC A6D3000E */  sh        $s3, 0xe($s6)
/* 93B0 8002DFB0 0C00B85B */  jal       initialize_next_camera
/* 93B4 8002DFB4 A6D20010 */   sh       $s2, 0x10($s6)
/* 93B8 8002DFB8 02C0202D */  daddu     $a0, $s6, $zero
/* 93BC 8002DFBC A6D50000 */  sh        $s5, ($s6)
/* 93C0 8002DFC0 A2C00002 */  sb        $zero, 2($s6)
/* 93C4 8002DFC4 A6D10004 */  sh        $s1, 4($s6)
/* 93C8 8002DFC8 A6D00006 */  sh        $s0, 6($s6)
/* 93CC 8002DFCC A6C00008 */  sh        $zero, 8($s6)
/* 93D0 8002DFD0 A6D0000A */  sh        $s0, 0xa($s6)
/* 93D4 8002DFD4 A6D4000C */  sh        $s4, 0xc($s6)
/* 93D8 8002DFD8 A6D3000E */  sh        $s3, 0xe($s6)
/* 93DC 8002DFDC 0C00B85B */  jal       initialize_next_camera
/* 93E0 8002DFE0 A6D20010 */   sh       $s2, 0x10($s6)
/* 93E4 8002DFE4 02C0202D */  daddu     $a0, $s6, $zero
/* 93E8 8002DFE8 A4950000 */  sh        $s5, ($a0)
/* 93EC 8002DFEC A0800002 */  sb        $zero, 2($a0)
/* 93F0 8002DFF0 A4910004 */  sh        $s1, 4($a0)
/* 93F4 8002DFF4 A4900006 */  sh        $s0, 6($a0)
/* 93F8 8002DFF8 A4910008 */  sh        $s1, 8($a0)
/* 93FC 8002DFFC A490000A */  sh        $s0, 0xa($a0)
/* 9400 8002E000 A494000C */  sh        $s4, 0xc($a0)
/* 9404 8002E004 A493000E */  sh        $s3, 0xe($a0)
/* 9408 8002E008 0C00B85B */  jal       initialize_next_camera
/* 940C 8002E00C A4920010 */   sh       $s2, 0x10($a0)
/* 9410 8002E010 8FBF0044 */  lw        $ra, 0x44($sp)
/* 9414 8002E014 8FB60040 */  lw        $s6, 0x40($sp)
/* 9418 8002E018 8FB5003C */  lw        $s5, 0x3c($sp)
/* 941C 8002E01C 8FB40038 */  lw        $s4, 0x38($sp)
/* 9420 8002E020 8FB30034 */  lw        $s3, 0x34($sp)
/* 9424 8002E024 8FB20030 */  lw        $s2, 0x30($sp)
/* 9428 8002E028 8FB1002C */  lw        $s1, 0x2c($sp)
/* 942C 8002E02C 8FB00028 */  lw        $s0, 0x28($sp)
/* 9430 8002E030 03E00008 */  jr        $ra
/* 9434 8002E034 27BD0048 */   addiu    $sp, $sp, 0x48
