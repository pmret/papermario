.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel entity_HiddenPanel_idle
/* 107C28 802E63A8 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 107C2C 802E63AC AFB3001C */  sw        $s3, 0x1c($sp)
/* 107C30 802E63B0 0080982D */  daddu     $s3, $a0, $zero
/* 107C34 802E63B4 AFBF0020 */  sw        $ra, 0x20($sp)
/* 107C38 802E63B8 AFB20018 */  sw        $s2, 0x18($sp)
/* 107C3C 802E63BC AFB10014 */  sw        $s1, 0x14($sp)
/* 107C40 802E63C0 AFB00010 */  sw        $s0, 0x10($sp)
/* 107C44 802E63C4 92620006 */  lbu       $v0, 6($s3)
/* 107C48 802E63C8 8E720040 */  lw        $s2, 0x40($s3)
/* 107C4C 802E63CC 30420001 */  andi      $v0, $v0, 1
/* 107C50 802E63D0 5040000A */  beql      $v0, $zero, .L802E63FC
/* 107C54 802E63D4 A2400004 */   sb       $zero, 4($s2)
/* 107C58 802E63D8 82420004 */  lb        $v0, 4($s2)
/* 107C5C 802E63DC 14400008 */  bnez      $v0, .L802E6400
/* 107C60 802E63E0 2402FFFF */   addiu    $v0, $zero, -1
/* 107C64 802E63E4 24020001 */  addiu     $v0, $zero, 1
/* 107C68 802E63E8 A2420004 */  sb        $v0, 4($s2)
/* 107C6C 802E63EC 0C03BCF5 */  jal       func_800EF3D4
/* 107C70 802E63F0 24040001 */   addiu    $a0, $zero, 1
/* 107C74 802E63F4 080B9900 */  j         .L802E6400
/* 107C78 802E63F8 2402FFFF */   addiu    $v0, $zero, -1
.L802E63FC:
/* 107C7C 802E63FC 2402FFFF */  addiu     $v0, $zero, -1
.L802E6400:
/* 107C80 802E6400 3C038016 */  lui       $v1, %hi(D_8015A578)
/* 107C84 802E6404 2463A578 */  addiu     $v1, $v1, %lo(D_8015A578)
/* 107C88 802E6408 AE420008 */  sw        $v0, 8($s2)
/* 107C8C 802E640C AE40000C */  sw        $zero, 0xc($s2)
/* 107C90 802E6410 80620000 */  lb        $v0, ($v1)
/* 107C94 802E6414 10400050 */  beqz      $v0, .L802E6558
/* 107C98 802E6418 00000000 */   nop
/* 107C9C 802E641C C4600008 */  lwc1      $f0, 8($v1)
/* 107CA0 802E6420 C662004C */  lwc1      $f2, 0x4c($s3)
/* 107CA4 802E6424 46020001 */  sub.s     $f0, $f0, $f2
/* 107CA8 802E6428 3C014024 */  lui       $at, 0x4024
/* 107CAC 802E642C 44811800 */  mtc1      $at, $f3
/* 107CB0 802E6430 44801000 */  mtc1      $zero, $f2
/* 107CB4 802E6434 46000021 */  cvt.d.s   $f0, $f0
/* 107CB8 802E6438 46200005 */  abs.d     $f0, $f0
/* 107CBC 802E643C 4622003E */  c.le.d    $f0, $f2
/* 107CC0 802E6440 00000000 */  nop
/* 107CC4 802E6444 45000044 */  bc1f      .L802E6558
/* 107CC8 802E6448 2402000A */   addiu    $v0, $zero, 0xa
/* 107CCC 802E644C A2420000 */  sb        $v0, ($s2)
/* 107CD0 802E6450 C66C0048 */  lwc1      $f12, 0x48($s3)
/* 107CD4 802E6454 0C038022 */  jal       get_xz_dist_to_player
/* 107CD8 802E6458 C66E0050 */   lwc1     $f14, 0x50($s3)
/* 107CDC 802E645C 4600010D */  trunc.w.s $f4, $f0
/* 107CE0 802E6460 44102000 */  mfc1      $s0, $f4
/* 107CE4 802E6464 00000000 */  nop
/* 107CE8 802E6468 2A020065 */  slti      $v0, $s0, 0x65
/* 107CEC 802E646C 1040003A */  beqz      $v0, .L802E6558
/* 107CF0 802E6470 00000000 */   nop
/* 107CF4 802E6474 92620006 */  lbu       $v0, 6($s3)
/* 107CF8 802E6478 30420001 */  andi      $v0, $v0, 1
/* 107CFC 802E647C 10400005 */  beqz      $v0, .L802E6494
/* 107D00 802E6480 0260202D */   daddu    $a0, $s3, $zero
/* 107D04 802E6484 3C013F00 */  lui       $at, 0x3f00
/* 107D08 802E6488 44810000 */  mtc1      $at, $f0
/* 107D0C 802E648C 080B9954 */  j         .L802E6550
/* 107D10 802E6490 00000000 */   nop
.L802E6494:
/* 107D14 802E6494 0C0B9ADB */  jal       entity_HiddenPanel_is_item_on_top
/* 107D18 802E6498 0260202D */   daddu    $a0, $s3, $zero
/* 107D1C 802E649C 10400005 */  beqz      $v0, .L802E64B4
/* 107D20 802E64A0 0260202D */   daddu    $a0, $s3, $zero
/* 107D24 802E64A4 3C013F00 */  lui       $at, 0x3f00
/* 107D28 802E64A8 44810000 */  mtc1      $at, $f0
/* 107D2C 802E64AC 080B9954 */  j         .L802E6550
/* 107D30 802E64B0 00000000 */   nop
.L802E64B4:
/* 107D34 802E64B4 0C00F475 */  jal       npc_find_standing_on_entity
/* 107D38 802E64B8 92640004 */   lbu      $a0, 4($s3)
/* 107D3C 802E64BC 0040882D */  daddu     $s1, $v0, $zero
/* 107D40 802E64C0 06200016 */  bltz      $s1, .L802E651C
/* 107D44 802E64C4 00000000 */   nop
/* 107D48 802E64C8 0C00E2B7 */  jal       get_npc_by_index
/* 107D4C 802E64CC 0220202D */   daddu    $a0, $s1, $zero
/* 107D50 802E64D0 0040802D */  daddu     $s0, $v0, $zero
/* 107D54 802E64D4 C66C0048 */  lwc1      $f12, 0x48($s3)
/* 107D58 802E64D8 C66E0050 */  lwc1      $f14, 0x50($s3)
/* 107D5C 802E64DC 8E060038 */  lw        $a2, 0x38($s0)
/* 107D60 802E64E0 0C00A7B5 */  jal       dist2D
/* 107D64 802E64E4 8E070040 */   lw       $a3, 0x40($s0)
/* 107D68 802E64E8 0260202D */  daddu     $a0, $s3, $zero
/* 107D6C 802E64EC AE510008 */  sw        $s1, 8($s2)
/* 107D70 802E64F0 8E020000 */  lw        $v0, ($s0)
/* 107D74 802E64F4 2403FFF7 */  addiu     $v1, $zero, -9
/* 107D78 802E64F8 30420208 */  andi      $v0, $v0, 0x208
/* 107D7C 802E64FC AE42000C */  sw        $v0, 0xc($s2)
/* 107D80 802E6500 8E020000 */  lw        $v0, ($s0)
/* 107D84 802E6504 3C013F00 */  lui       $at, 0x3f00
/* 107D88 802E6508 44810000 */  mtc1      $at, $f0
/* 107D8C 802E650C 00431024 */  and       $v0, $v0, $v1
/* 107D90 802E6510 34420200 */  ori       $v0, $v0, 0x200
/* 107D94 802E6514 080B9954 */  j         .L802E6550
/* 107D98 802E6518 AE020000 */   sw       $v0, ($s0)
.L802E651C:
/* 107D9C 802E651C 8E620000 */  lw        $v0, ($s3)
/* 107DA0 802E6520 34420020 */  ori       $v0, $v0, 0x20
/* 107DA4 802E6524 AE620000 */  sw        $v0, ($s3)
/* 107DA8 802E6528 2A02003D */  slti      $v0, $s0, 0x3d
/* 107DAC 802E652C 14400005 */  bnez      $v0, .L802E6544
/* 107DB0 802E6530 0260202D */   daddu    $a0, $s3, $zero
/* 107DB4 802E6534 3C013F00 */  lui       $at, 0x3f00
/* 107DB8 802E6538 44810000 */  mtc1      $at, $f0
/* 107DBC 802E653C 080B9954 */  j         .L802E6550
/* 107DC0 802E6540 00000000 */   nop
.L802E6544:
/* 107DC4 802E6544 3C014120 */  lui       $at, 0x4120
/* 107DC8 802E6548 44810000 */  mtc1      $at, $f0
/* 107DCC 802E654C A2400000 */  sb        $zero, ($s2)
.L802E6550:
/* 107DD0 802E6550 0C043F5A */  jal       exec_entity_commandlist
/* 107DD4 802E6554 E6400028 */   swc1     $f0, 0x28($s2)
.L802E6558:
/* 107DD8 802E6558 8FBF0020 */  lw        $ra, 0x20($sp)
/* 107DDC 802E655C 8FB3001C */  lw        $s3, 0x1c($sp)
/* 107DE0 802E6560 8FB20018 */  lw        $s2, 0x18($sp)
/* 107DE4 802E6564 8FB10014 */  lw        $s1, 0x14($sp)
/* 107DE8 802E6568 8FB00010 */  lw        $s0, 0x10($sp)
/* 107DEC 802E656C 03E00008 */  jr        $ra
/* 107DF0 802E6570 27BD0028 */   addiu    $sp, $sp, 0x28
