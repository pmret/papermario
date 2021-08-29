.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802403DC_BD3C4C
/* BD3C4C 802403DC 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* BD3C50 802403E0 AFB3001C */  sw        $s3, 0x1c($sp)
/* BD3C54 802403E4 0080982D */  daddu     $s3, $a0, $zero
/* BD3C58 802403E8 AFBF0020 */  sw        $ra, 0x20($sp)
/* BD3C5C 802403EC AFB20018 */  sw        $s2, 0x18($sp)
/* BD3C60 802403F0 AFB10014 */  sw        $s1, 0x14($sp)
/* BD3C64 802403F4 AFB00010 */  sw        $s0, 0x10($sp)
/* BD3C68 802403F8 8E70000C */  lw        $s0, 0xc($s3)
/* BD3C6C 802403FC 8E050000 */  lw        $a1, ($s0)
/* BD3C70 80240400 0C0B1EAF */  jal       get_variable
/* BD3C74 80240404 26100004 */   addiu    $s0, $s0, 4
/* BD3C78 80240408 0260202D */  daddu     $a0, $s3, $zero
/* BD3C7C 8024040C 8E050000 */  lw        $a1, ($s0)
/* BD3C80 80240410 0C0B1EAF */  jal       get_variable
/* BD3C84 80240414 0040902D */   daddu    $s2, $v0, $zero
/* BD3C88 80240418 2404003C */  addiu     $a0, $zero, 0x3c
/* BD3C8C 8024041C 0C00AB39 */  jal       heap_malloc
/* BD3C90 80240420 0040882D */   daddu    $s1, $v0, $zero
/* BD3C94 80240424 0040802D */  daddu     $s0, $v0, $zero
/* BD3C98 80240428 3C038011 */  lui       $v1, %hi(gPlayerStatus)
/* BD3C9C 8024042C 2463EFC8 */  addiu     $v1, $v1, %lo(gPlayerStatus)
/* BD3CA0 80240430 AE120008 */  sw        $s2, 8($s0)
/* BD3CA4 80240434 AE11000C */  sw        $s1, 0xc($s0)
/* BD3CA8 80240438 846200B0 */  lh        $v0, 0xb0($v1)
/* BD3CAC 8024043C 44820000 */  mtc1      $v0, $f0
/* BD3CB0 80240440 00000000 */  nop
/* BD3CB4 80240444 46800020 */  cvt.s.w   $f0, $f0
/* BD3CB8 80240448 E6000034 */  swc1      $f0, 0x34($s0)
/* BD3CBC 8024044C 846200B2 */  lh        $v0, 0xb2($v1)
/* BD3CC0 80240450 44820000 */  mtc1      $v0, $f0
/* BD3CC4 80240454 00000000 */  nop
/* BD3CC8 80240458 46800020 */  cvt.s.w   $f0, $f0
/* BD3CCC 8024045C E6000038 */  swc1      $f0, 0x38($s0)
/* BD3CD0 80240460 C4600028 */  lwc1      $f0, 0x28($v1)
/* BD3CD4 80240464 E6000010 */  swc1      $f0, 0x10($s0)
/* BD3CD8 80240468 C460002C */  lwc1      $f0, 0x2c($v1)
/* BD3CDC 8024046C E6000014 */  swc1      $f0, 0x14($s0)
/* BD3CE0 80240470 C4620030 */  lwc1      $f2, 0x30($v1)
/* BD3CE4 80240474 3C013F36 */  lui       $at, 0x3f36
/* BD3CE8 80240478 3421DB6E */  ori       $at, $at, 0xdb6e
/* BD3CEC 8024047C 44810000 */  mtc1      $at, $f0
/* BD3CF0 80240480 24040001 */  addiu     $a0, $zero, 1
/* BD3CF4 80240484 AE00001C */  sw        $zero, 0x1c($s0)
/* BD3CF8 80240488 AE000020 */  sw        $zero, 0x20($s0)
/* BD3CFC 8024048C AE000024 */  sw        $zero, 0x24($s0)
/* BD3D00 80240490 E6000028 */  swc1      $f0, 0x28($s0)
/* BD3D04 80240494 E600002C */  swc1      $f0, 0x2c($s0)
/* BD3D08 80240498 E6000030 */  swc1      $f0, 0x30($s0)
/* BD3D0C 8024049C 0C04E9C1 */  jal       func_8013A704
/* BD3D10 802404A0 E6020018 */   swc1     $f2, 0x18($s0)
/* BD3D14 802404A4 0000202D */  daddu     $a0, $zero, $zero
/* BD3D18 802404A8 3C058024 */  lui       $a1, %hi(func_80240000_BD3870)
/* BD3D1C 802404AC 24A50000 */  addiu     $a1, $a1, %lo(func_80240000_BD3870)
/* BD3D20 802404B0 0C048C56 */  jal       create_generic_entity_world
/* BD3D24 802404B4 AE020000 */   sw       $v0, ($s0)
/* BD3D28 802404B8 0260202D */  daddu     $a0, $s3, $zero
/* BD3D2C 802404BC 3C05FD05 */  lui       $a1, 0xfd05
/* BD3D30 802404C0 34A50F8A */  ori       $a1, $a1, 0xf8a
/* BD3D34 802404C4 0200302D */  daddu     $a2, $s0, $zero
/* BD3D38 802404C8 0C0B2026 */  jal       evt_set_variable
/* BD3D3C 802404CC AE020004 */   sw       $v0, 4($s0)
/* BD3D40 802404D0 8FBF0020 */  lw        $ra, 0x20($sp)
/* BD3D44 802404D4 8FB3001C */  lw        $s3, 0x1c($sp)
/* BD3D48 802404D8 8FB20018 */  lw        $s2, 0x18($sp)
/* BD3D4C 802404DC 8FB10014 */  lw        $s1, 0x14($sp)
/* BD3D50 802404E0 8FB00010 */  lw        $s0, 0x10($sp)
/* BD3D54 802404E4 24020002 */  addiu     $v0, $zero, 2
/* BD3D58 802404E8 03E00008 */  jr        $ra
/* BD3D5C 802404EC 27BD0028 */   addiu    $sp, $sp, 0x28
