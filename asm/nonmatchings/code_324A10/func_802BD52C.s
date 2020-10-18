.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BD52C
/* 324E3C 802BD52C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 324E40 802BD530 AFBF0014 */  sw        $ra, 0x14($sp)
/* 324E44 802BD534 AFB00010 */  sw        $s0, 0x10($sp)
/* 324E48 802BD538 10A00003 */  beqz      $a1, .L802BD548
/* 324E4C 802BD53C 8C90014C */   lw       $s0, 0x14c($a0)
/* 324E50 802BD540 0C03BA65 */  jal       func_800EE994
/* 324E54 802BD544 0200202D */   daddu    $a0, $s0, $zero
.L802BD548:
/* 324E58 802BD548 0C03BA6E */  jal       func_800EE9B8
/* 324E5C 802BD54C 0200202D */   daddu    $a0, $s0, $zero
/* 324E60 802BD550 8FBF0014 */  lw        $ra, 0x14($sp)
/* 324E64 802BD554 8FB00010 */  lw        $s0, 0x10($sp)
/* 324E68 802BD558 0002102B */  sltu      $v0, $zero, $v0
/* 324E6C 802BD55C 03E00008 */  jr        $ra
/* 324E70 802BD560 27BD0018 */   addiu    $sp, $sp, 0x18
/* 324E74 802BD564 00000000 */  nop       
/* 324E78 802BD568 00000000 */  nop       
/* 324E7C 802BD56C 00000000 */  nop       
