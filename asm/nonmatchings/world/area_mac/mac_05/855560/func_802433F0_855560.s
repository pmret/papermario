.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802433F0_855560
/* 855560 802433F0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 855564 802433F4 0080182D */  daddu     $v1, $a0, $zero
/* 855568 802433F8 00A0202D */  daddu     $a0, $a1, $zero
/* 85556C 802433FC 2402FFFF */  addiu     $v0, $zero, -1
/* 855570 80243400 14820004 */  bne       $a0, $v0, .L80243414
/* 855574 80243404 AFBF0010 */   sw       $ra, 0x10($sp)
/* 855578 80243408 8C64014C */  lw        $a0, 0x14c($v1)
/* 85557C 8024340C 08090D0A */  j         .L80243428
/* 855580 80243410 00000000 */   nop      
.L80243414:
/* 855584 80243414 3C02EFE8 */  lui       $v0, 0xefe8
/* 855588 80243418 34422080 */  ori       $v0, $v0, 0x2080
/* 85558C 8024341C 0082102A */  slt       $v0, $a0, $v0
/* 855590 80243420 14400003 */  bnez      $v0, .L80243430
/* 855594 80243424 0080102D */   daddu    $v0, $a0, $zero
.L80243428:
/* 855598 80243428 0C00EAD2 */  jal       get_npc_safe
/* 85559C 8024342C 00000000 */   nop      
.L80243430:
/* 8555A0 80243430 8FBF0010 */  lw        $ra, 0x10($sp)
/* 8555A4 80243434 03E00008 */  jr        $ra
/* 8555A8 80243438 27BD0018 */   addiu    $sp, $sp, 0x18
