.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242524_B2E994
/* B2E994 80242524 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* B2E998 80242528 AFB10014 */  sw        $s1, 0x14($sp)
/* B2E99C 8024252C 0080882D */  daddu     $s1, $a0, $zero
/* B2E9A0 80242530 AFB00010 */  sw        $s0, 0x10($sp)
/* B2E9A4 80242534 00A0802D */  daddu     $s0, $a1, $zero
/* B2E9A8 80242538 AFBF001C */  sw        $ra, 0x1c($sp)
/* B2E9AC 8024253C AFB20018 */  sw        $s2, 0x18($sp)
/* B2E9B0 80242540 F7B40020 */  sdc1      $f20, 0x20($sp)
/* B2E9B4 80242544 0C00EABB */  jal       get_npc_unsafe
/* B2E9B8 80242548 2404FFFC */   addiu    $a0, $zero, -4
/* B2E9BC 8024254C 12000017 */  beqz      $s0, .L802425AC
/* B2E9C0 80242550 0040902D */   daddu    $s2, $v0, $zero
/* B2E9C4 80242554 0220202D */  daddu     $a0, $s1, $zero
/* B2E9C8 80242558 3C05FE36 */  lui       $a1, 0xfe36
/* B2E9CC 8024255C 0C0B210B */  jal       get_float_variable
/* B2E9D0 80242560 34A53C80 */   ori      $a1, $a1, 0x3c80
/* B2E9D4 80242564 0220202D */  daddu     $a0, $s1, $zero
/* B2E9D8 80242568 3C05FE36 */  lui       $a1, 0xfe36
/* B2E9DC 8024256C 3C014270 */  lui       $at, 0x4270
/* B2E9E0 80242570 4481A000 */  mtc1      $at, $f20
/* B2E9E4 80242574 34A53C85 */  ori       $a1, $a1, 0x3c85
/* B2E9E8 80242578 46140003 */  div.s     $f0, $f0, $f20
/* B2E9EC 8024257C 0C0B210B */  jal       get_float_variable
/* B2E9F0 80242580 E6200074 */   swc1     $f0, 0x74($s1)
/* B2E9F4 80242584 0220202D */  daddu     $a0, $s1, $zero
/* B2E9F8 80242588 3C05FE36 */  lui       $a1, 0xfe36
/* B2E9FC 8024258C 34A53C81 */  ori       $a1, $a1, 0x3c81
/* B2EA00 80242590 46140003 */  div.s     $f0, $f0, $f20
/* B2EA04 80242594 0C0B210B */  jal       get_float_variable
/* B2EA08 80242598 E6200078 */   swc1     $f0, 0x78($s1)
/* B2EA0C 8024259C 46140003 */  div.s     $f0, $f0, $f20
/* B2EA10 802425A0 2402003C */  addiu     $v0, $zero, 0x3c
/* B2EA14 802425A4 E620007C */  swc1      $f0, 0x7c($s1)
/* B2EA18 802425A8 AE220070 */  sw        $v0, 0x70($s1)
.L802425AC:
/* B2EA1C 802425AC C6400038 */  lwc1      $f0, 0x38($s2)
/* B2EA20 802425B0 C6220074 */  lwc1      $f2, 0x74($s1)
/* B2EA24 802425B4 46020000 */  add.s     $f0, $f0, $f2
/* B2EA28 802425B8 E6400038 */  swc1      $f0, 0x38($s2)
/* B2EA2C 802425BC C640003C */  lwc1      $f0, 0x3c($s2)
/* B2EA30 802425C0 C6220078 */  lwc1      $f2, 0x78($s1)
/* B2EA34 802425C4 46020000 */  add.s     $f0, $f0, $f2
/* B2EA38 802425C8 E640003C */  swc1      $f0, 0x3c($s2)
/* B2EA3C 802425CC C6400040 */  lwc1      $f0, 0x40($s2)
/* B2EA40 802425D0 C622007C */  lwc1      $f2, 0x7c($s1)
/* B2EA44 802425D4 46020000 */  add.s     $f0, $f0, $f2
/* B2EA48 802425D8 E6400040 */  swc1      $f0, 0x40($s2)
/* B2EA4C 802425DC 8E230070 */  lw        $v1, 0x70($s1)
/* B2EA50 802425E0 2463FFFF */  addiu     $v1, $v1, -1
/* B2EA54 802425E4 2C620001 */  sltiu     $v0, $v1, 1
/* B2EA58 802425E8 AE230070 */  sw        $v1, 0x70($s1)
/* B2EA5C 802425EC 8FBF001C */  lw        $ra, 0x1c($sp)
/* B2EA60 802425F0 8FB20018 */  lw        $s2, 0x18($sp)
/* B2EA64 802425F4 8FB10014 */  lw        $s1, 0x14($sp)
/* B2EA68 802425F8 8FB00010 */  lw        $s0, 0x10($sp)
/* B2EA6C 802425FC D7B40020 */  ldc1      $f20, 0x20($sp)
/* B2EA70 80242600 00021040 */  sll       $v0, $v0, 1
/* B2EA74 80242604 03E00008 */  jr        $ra
/* B2EA78 80242608 27BD0028 */   addiu    $sp, $sp, 0x28
