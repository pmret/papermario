.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802CCAC0
/* F1470 802CCAC0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* F1474 802CCAC4 AFB00010 */  sw        $s0, 0x10($sp)
/* F1478 802CCAC8 0000802D */  daddu     $s0, $zero, $zero
/* F147C 802CCACC AFBF0014 */  sw        $ra, 0x14($sp)
.L802CCAD0:
/* F1480 802CCAD0 3C03802E */  lui       $v1, 0x802e
/* F1484 802CCAD4 8C63AE30 */  lw        $v1, -0x51d0($v1)
/* F1488 802CCAD8 00101080 */  sll       $v0, $s0, 2
/* F148C 802CCADC 00431021 */  addu      $v0, $v0, $v1
/* F1490 802CCAE0 8C420000 */  lw        $v0, ($v0)
/* F1494 802CCAE4 8C440000 */  lw        $a0, ($v0)
/* F1498 802CCAE8 04820004 */  bltzl     $a0, .L802CCAFC
/* F149C 802CCAEC 26100001 */   addiu    $s0, $s0, 1
/* F14A0 802CCAF0 0C047A95 */  jal       func_8011EA54
/* F14A4 802CCAF4 24450028 */   addiu    $a1, $v0, 0x28
/* F14A8 802CCAF8 26100001 */  addiu     $s0, $s0, 1
.L802CCAFC:
/* F14AC 802CCAFC 2A020010 */  slti      $v0, $s0, 0x10
/* F14B0 802CCB00 1440FFF3 */  bnez      $v0, .L802CCAD0
/* F14B4 802CCB04 00000000 */   nop      
/* F14B8 802CCB08 8FBF0014 */  lw        $ra, 0x14($sp)
/* F14BC 802CCB0C 8FB00010 */  lw        $s0, 0x10($sp)
/* F14C0 802CCB10 03E00008 */  jr        $ra
/* F14C4 802CCB14 27BD0018 */   addiu    $sp, $sp, 0x18
