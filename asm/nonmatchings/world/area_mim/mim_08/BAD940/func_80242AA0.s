.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242AA0
/* BB03E0 80242AA0 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* BB03E4 80242AA4 AFB10034 */  sw        $s1, 0x34($sp)
/* BB03E8 80242AA8 0080882D */  daddu     $s1, $a0, $zero
/* BB03EC 80242AAC AFBF0038 */  sw        $ra, 0x38($sp)
/* BB03F0 80242AB0 AFB00030 */  sw        $s0, 0x30($sp)
/* BB03F4 80242AB4 8E300148 */  lw        $s0, 0x148($s1)
/* BB03F8 80242AB8 0C00EABB */  jal       get_npc_unsafe
/* BB03FC 80242ABC 86040008 */   lh       $a0, 8($s0)
/* BB0400 80242AC0 0040282D */  daddu     $a1, $v0, $zero
/* BB0404 80242AC4 94A2008E */  lhu       $v0, 0x8e($a1)
/* BB0408 80242AC8 24420001 */  addiu     $v0, $v0, 1
/* BB040C 80242ACC A4A2008E */  sh        $v0, 0x8e($a1)
/* BB0410 80242AD0 00021400 */  sll       $v0, $v0, 0x10
/* BB0414 80242AD4 8E0300A0 */  lw        $v1, 0xa0($s0)
/* BB0418 80242AD8 00021403 */  sra       $v0, $v0, 0x10
/* BB041C 80242ADC 14430004 */  bne       $v0, $v1, .L80242AF0
/* BB0420 80242AE0 00000000 */   nop      
/* BB0424 80242AE4 8E0200CC */  lw        $v0, 0xcc($s0)
/* BB0428 80242AE8 8C42002C */  lw        $v0, 0x2c($v0)
/* BB042C 80242AEC ACA20028 */  sw        $v0, 0x28($a1)
.L80242AF0:
/* BB0430 80242AF0 84A3008E */  lh        $v1, 0x8e($a1)
/* BB0434 80242AF4 8E0200A4 */  lw        $v0, 0xa4($s0)
/* BB0438 80242AF8 14620002 */  bne       $v1, $v0, .L80242B04
/* BB043C 80242AFC 24020003 */   addiu    $v0, $zero, 3
/* BB0440 80242B00 AE02006C */  sw        $v0, 0x6c($s0)
.L80242B04:
/* BB0444 80242B04 84A2008E */  lh        $v0, 0x8e($a1)
/* BB0448 80242B08 8E03009C */  lw        $v1, 0x9c($s0)
/* BB044C 80242B0C 0043102A */  slt       $v0, $v0, $v1
/* BB0450 80242B10 1440001E */  bnez      $v0, .L80242B8C
/* BB0454 80242B14 24020004 */   addiu    $v0, $zero, 4
/* BB0458 80242B18 AE02006C */  sw        $v0, 0x6c($s0)
/* BB045C 80242B1C 24020008 */  addiu     $v0, $zero, 8
/* BB0460 80242B20 24040003 */  addiu     $a0, $zero, 3
/* BB0464 80242B24 A4A2008E */  sh        $v0, 0x8e($a1)
/* BB0468 80242B28 8E0200CC */  lw        $v0, 0xcc($s0)
/* BB046C 80242B2C 84A300A8 */  lh        $v1, 0xa8($a1)
/* BB0470 80242B30 3C013F80 */  lui       $at, 0x3f80
/* BB0474 80242B34 44810000 */  mtc1      $at, $f0
/* BB0478 80242B38 3C014000 */  lui       $at, 0x4000
/* BB047C 80242B3C 44811000 */  mtc1      $at, $f2
/* BB0480 80242B40 3C01C1A0 */  lui       $at, 0xc1a0
/* BB0484 80242B44 44812000 */  mtc1      $at, $f4
/* BB0488 80242B48 44833000 */  mtc1      $v1, $f6
/* BB048C 80242B4C 00000000 */  nop       
/* BB0490 80242B50 468031A0 */  cvt.s.w   $f6, $f6
/* BB0494 80242B54 8C420000 */  lw        $v0, ($v0)
/* BB0498 80242B58 44073000 */  mfc1      $a3, $f6
/* BB049C 80242B5C 0000302D */  daddu     $a2, $zero, $zero
/* BB04A0 80242B60 ACA20028 */  sw        $v0, 0x28($a1)
/* BB04A4 80242B64 2402000A */  addiu     $v0, $zero, 0xa
/* BB04A8 80242B68 AFA2001C */  sw        $v0, 0x1c($sp)
/* BB04AC 80242B6C 27A20028 */  addiu     $v0, $sp, 0x28
/* BB04B0 80242B70 E7A00010 */  swc1      $f0, 0x10($sp)
/* BB04B4 80242B74 E7A20014 */  swc1      $f2, 0x14($sp)
/* BB04B8 80242B78 E7A40018 */  swc1      $f4, 0x18($sp)
/* BB04BC 80242B7C 0C01BFA4 */  jal       fx_emote
/* BB04C0 80242B80 AFA20020 */   sw       $v0, 0x20($sp)
/* BB04C4 80242B84 2402000D */  addiu     $v0, $zero, 0xd
/* BB04C8 80242B88 AE220070 */  sw        $v0, 0x70($s1)
.L80242B8C:
/* BB04CC 80242B8C 8FBF0038 */  lw        $ra, 0x38($sp)
/* BB04D0 80242B90 8FB10034 */  lw        $s1, 0x34($sp)
/* BB04D4 80242B94 8FB00030 */  lw        $s0, 0x30($sp)
/* BB04D8 80242B98 03E00008 */  jr        $ra
/* BB04DC 80242B9C 27BD0040 */   addiu    $sp, $sp, 0x40
