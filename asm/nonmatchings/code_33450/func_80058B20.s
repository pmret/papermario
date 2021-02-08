.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80058B20
/* 33F20 80058B20 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 33F24 80058B24 AFB3001C */  sw        $s3, 0x1c($sp)
/* 33F28 80058B28 8FB30044 */  lw        $s3, 0x44($sp)
/* 33F2C 80058B2C AFB50024 */  sw        $s5, 0x24($sp)
/* 33F30 80058B30 8FB50048 */  lw        $s5, 0x48($sp)
/* 33F34 80058B34 AFB40020 */  sw        $s4, 0x20($sp)
/* 33F38 80058B38 97B40042 */  lhu       $s4, 0x42($sp)
/* 33F3C 80058B3C AFB10014 */  sw        $s1, 0x14($sp)
/* 33F40 80058B40 0080882D */  daddu     $s1, $a0, $zero
/* 33F44 80058B44 AFB20018 */  sw        $s2, 0x18($sp)
/* 33F48 80058B48 00A0902D */  daddu     $s2, $a1, $zero
/* 33F4C 80058B4C AFB60028 */  sw        $s6, 0x28($sp)
/* 33F50 80058B50 00C0B02D */  daddu     $s6, $a2, $zero
/* 33F54 80058B54 AFB00010 */  sw        $s0, 0x10($sp)
/* 33F58 80058B58 00E0802D */  daddu     $s0, $a3, $zero
/* 33F5C 80058B5C 1A000019 */  blez      $s0, .L80058BC4
/* 33F60 80058B60 AFBF002C */   sw       $ra, 0x2c($sp)
/* 33F64 80058B64 8E430014 */  lw        $v1, 0x14($s2)
/* 33F68 80058B68 8E42001C */  lw        $v0, 0x1c($s2)
/* 33F6C 80058B6C 8E440030 */  lw        $a0, 0x30($s2)
/* 33F70 80058B70 8E460020 */  lw        $a2, 0x20($s2)
/* 33F74 80058B74 90670025 */  lbu       $a3, 0x25($v1)
/* 33F78 80058B78 0040F809 */  jalr      $v0
/* 33F7C 80058B7C 0200282D */   daddu    $a1, $s0, $zero
/* 33F80 80058B80 30480007 */  andi      $t0, $v0, 7
/* 33F84 80058B84 02088021 */  addu      $s0, $s0, $t0
/* 33F88 80058B88 0220302D */  daddu     $a2, $s1, $zero
/* 33F8C 80058B8C 26310008 */  addiu     $s1, $s1, 8
/* 33F90 80058B90 32030007 */  andi      $v1, $s0, 7
/* 33F94 80058B94 2463FFF8 */  addiu     $v1, $v1, -8
/* 33F98 80058B98 02031823 */  subu      $v1, $s0, $v1
/* 33F9C 80058B9C 30630FFF */  andi      $v1, $v1, 0xfff
/* 33FA0 80058BA0 00031B00 */  sll       $v1, $v1, 0xc
/* 33FA4 80058BA4 32640FFF */  andi      $a0, $s3, 0xfff
/* 33FA8 80058BA8 3C050400 */  lui       $a1, 0x400
/* 33FAC 80058BAC 00852025 */  or        $a0, $a0, $a1
/* 33FB0 80058BB0 00641825 */  or        $v1, $v1, $a0
/* 33FB4 80058BB4 00481023 */  subu      $v0, $v0, $t0
/* 33FB8 80058BB8 ACC30000 */  sw        $v1, ($a2)
/* 33FBC 80058BBC 080162F2 */  j         .L80058BC8
/* 33FC0 80058BC0 ACC20004 */   sw       $v0, 4($a2)
.L80058BC4:
/* 33FC4 80058BC4 0000402D */  daddu     $t0, $zero, $zero
.L80058BC8:
/* 33FC8 80058BC8 32A20002 */  andi      $v0, $s5, 2
/* 33FCC 80058BCC 10400009 */  beqz      $v0, .L80058BF4
/* 33FD0 80058BD0 0220202D */   daddu    $a0, $s1, $zero
/* 33FD4 80058BD4 26310008 */  addiu     $s1, $s1, 8
/* 33FD8 80058BD8 3C031FFF */  lui       $v1, 0x1fff
/* 33FDC 80058BDC 3C020F00 */  lui       $v0, 0xf00
/* 33FE0 80058BE0 AC820000 */  sw        $v0, ($a0)
/* 33FE4 80058BE4 8E420004 */  lw        $v0, 4($s2)
/* 33FE8 80058BE8 3463FFFF */  ori       $v1, $v1, 0xffff
/* 33FEC 80058BEC 00431024 */  and       $v0, $v0, $v1
/* 33FF0 80058BF0 AC820004 */  sw        $v0, 4($a0)
.L80058BF4:
/* 33FF4 80058BF4 3C0700FF */  lui       $a3, 0xff
/* 33FF8 80058BF8 34E7FFFF */  ori       $a3, $a3, 0xffff
/* 33FFC 80058BFC 26220008 */  addiu     $v0, $s1, 8
/* 34000 80058C00 0220302D */  daddu     $a2, $s1, $zero
/* 34004 80058C04 00152700 */  sll       $a0, $s5, 0x1c
/* 34008 80058C08 00161840 */  sll       $v1, $s6, 1
/* 3400C 80058C0C 30630FFF */  andi      $v1, $v1, 0xfff
/* 34010 80058C10 00031C00 */  sll       $v1, $v1, 0x10
/* 34014 80058C14 00832025 */  or        $a0, $a0, $v1
/* 34018 80058C18 00081B00 */  sll       $v1, $t0, 0xc
/* 3401C 80058C1C 00832025 */  or        $a0, $a0, $v1
/* 34020 80058C20 32850FFF */  andi      $a1, $s4, 0xfff
/* 34024 80058C24 8E430000 */  lw        $v1, ($s2)
/* 34028 80058C28 00852025 */  or        $a0, $a0, $a1
/* 3402C 80058C2C ACC40004 */  sw        $a0, 4($a2)
/* 34030 80058C30 3C040100 */  lui       $a0, 0x100
/* 34034 80058C34 00671824 */  and       $v1, $v1, $a3
/* 34038 80058C38 00641825 */  or        $v1, $v1, $a0
/* 3403C 80058C3C ACC30000 */  sw        $v1, ($a2)
/* 34040 80058C40 AE40002C */  sw        $zero, 0x2c($s2)
/* 34044 80058C44 8FBF002C */  lw        $ra, 0x2c($sp)
/* 34048 80058C48 8FB60028 */  lw        $s6, 0x28($sp)
/* 3404C 80058C4C 8FB50024 */  lw        $s5, 0x24($sp)
/* 34050 80058C50 8FB40020 */  lw        $s4, 0x20($sp)
/* 34054 80058C54 8FB3001C */  lw        $s3, 0x1c($sp)
/* 34058 80058C58 8FB20018 */  lw        $s2, 0x18($sp)
/* 3405C 80058C5C 8FB10014 */  lw        $s1, 0x14($sp)
/* 34060 80058C60 8FB00010 */  lw        $s0, 0x10($sp)
/* 34064 80058C64 03E00008 */  jr        $ra
/* 34068 80058C68 27BD0030 */   addiu    $sp, $sp, 0x30
