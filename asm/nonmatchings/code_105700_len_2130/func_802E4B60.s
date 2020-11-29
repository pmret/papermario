.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802E4B60
/* 1063E0 802E4B60 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 1063E4 802E4B64 AFB10014 */  sw        $s1, 0x14($sp)
/* 1063E8 802E4B68 0080882D */  daddu     $s1, $a0, $zero
/* 1063EC 802E4B6C 3C02802E */  lui       $v0, %hi(D_802E4AEC)
/* 1063F0 802E4B70 24424AEC */  addiu     $v0, $v0, %lo(D_802E4AEC)
/* 1063F4 802E4B74 AFBF0018 */  sw        $ra, 0x18($sp)
/* 1063F8 802E4B78 AFB00010 */  sw        $s0, 0x10($sp)
/* 1063FC 802E4B7C AE22003C */  sw        $v0, 0x3c($s1)
/* 106400 802E4B80 240200FF */  addiu     $v0, $zero, 0xff
/* 106404 802E4B84 A222000B */  sb        $v0, 0xb($s1)
/* 106408 802E4B88 8E220000 */  lw        $v0, ($s1)
/* 10640C 802E4B8C 8E300040 */  lw        $s0, 0x40($s1)
/* 106410 802E4B90 34422000 */  ori       $v0, $v0, 0x2000
/* 106414 802E4B94 AE220000 */  sw        $v0, ($s1)
/* 106418 802E4B98 0C04417A */  jal       get_entity_by_index
/* 10641C 802E4B9C 92040000 */   lbu      $a0, ($s0)
/* 106420 802E4BA0 92020009 */  lbu       $v0, 9($s0)
/* 106424 802E4BA4 54400009 */  bnel      $v0, $zero, .L802E4BCC
/* 106428 802E4BA8 A2000001 */   sb       $zero, 1($s0)
/* 10642C 802E4BAC 3C013F80 */  lui       $at, 0x3f80
/* 106430 802E4BB0 44810000 */  mtc1      $at, $f0
/* 106434 802E4BB4 24020001 */  addiu     $v0, $zero, 1
/* 106438 802E4BB8 A2020009 */  sb        $v0, 9($s0)
/* 10643C 802E4BBC 24020002 */  addiu     $v0, $zero, 2
/* 106440 802E4BC0 A2020001 */  sb        $v0, 1($s0)
/* 106444 802E4BC4 080B92F4 */  j         .L802E4BD0
/* 106448 802E4BC8 E6200054 */   swc1     $f0, 0x54($s1)
.L802E4BCC:
/* 10644C 802E4BCC AE200054 */  sw        $zero, 0x54($s1)
.L802E4BD0:
/* 106450 802E4BD0 AE00000C */  sw        $zero, 0xc($s0)
/* 106454 802E4BD4 AE000010 */  sw        $zero, 0x10($s0)
/* 106458 802E4BD8 C6200054 */  lwc1      $f0, 0x54($s1)
/* 10645C 802E4BDC 0220202D */  daddu     $a0, $s1, $zero
/* 106460 802E4BE0 AC800060 */  sw        $zero, 0x60($a0)
/* 106464 802E4BE4 AC800064 */  sw        $zero, 0x64($a0)
/* 106468 802E4BE8 AC800068 */  sw        $zero, 0x68($a0)
/* 10646C 802E4BEC 46000086 */  mov.s     $f2, $f0
/* 106470 802E4BF0 E4800058 */  swc1      $f0, 0x58($a0)
/* 106474 802E4BF4 0C0B92C4 */  jal       func_802E4B10
/* 106478 802E4BF8 E482005C */   swc1     $f2, 0x5c($a0)
/* 10647C 802E4BFC 8FBF0018 */  lw        $ra, 0x18($sp)
/* 106480 802E4C00 8FB10014 */  lw        $s1, 0x14($sp)
/* 106484 802E4C04 8FB00010 */  lw        $s0, 0x10($sp)
/* 106488 802E4C08 03E00008 */  jr        $ra
/* 10648C 802E4C0C 27BD0020 */   addiu    $sp, $sp, 0x20
