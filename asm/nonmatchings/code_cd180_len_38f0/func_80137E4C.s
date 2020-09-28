.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80137E4C
/* CE54C 80137E4C 28820002 */  slti      $v0, $a0, 2
/* CE550 80137E50 10400019 */  beqz      $v0, .L80137EB8
/* CE554 80137E54 00000000 */   nop      
/* CE558 80137E58 04800017 */  bltz      $a0, .L80137EB8
/* CE55C 80137E5C 00000000 */   nop      
/* CE560 80137E60 10A00005 */  beqz      $a1, .L80137E78
/* CE564 80137E64 24020001 */   addiu    $v0, $zero, 1
/* CE568 80137E68 10A2000C */  beq       $a1, $v0, .L80137E9C
/* CE56C 80137E6C 00041040 */   sll      $v0, $a0, 1
/* CE570 80137E70 03E00008 */  jr        $ra
/* CE574 80137E74 00000000 */   nop      
.L80137E78:
/* CE578 80137E78 3C038016 */  lui       $v1, 0x8016
/* CE57C 80137E7C 2463C790 */  addiu     $v1, $v1, -0x3870
/* CE580 80137E80 00041040 */  sll       $v0, $a0, 1
/* CE584 80137E84 00441021 */  addu      $v0, $v0, $a0
/* CE588 80137E88 000210C0 */  sll       $v0, $v0, 3
/* CE58C 80137E8C 00431021 */  addu      $v0, $v0, $v1
/* CE590 80137E90 AC460004 */  sw        $a2, 4($v0)
/* CE594 80137E94 03E00008 */  jr        $ra
/* CE598 80137E98 AC470008 */   sw       $a3, 8($v0)
.L80137E9C:
/* CE59C 80137E9C 3C038016 */  lui       $v1, 0x8016
/* CE5A0 80137EA0 2463C790 */  addiu     $v1, $v1, -0x3870
/* CE5A4 80137EA4 00441021 */  addu      $v0, $v0, $a0
/* CE5A8 80137EA8 000210C0 */  sll       $v0, $v0, 3
/* CE5AC 80137EAC 00431021 */  addu      $v0, $v0, $v1
/* CE5B0 80137EB0 AC46000C */  sw        $a2, 0xc($v0)
/* CE5B4 80137EB4 AC470010 */  sw        $a3, 0x10($v0)
.L80137EB8:
/* CE5B8 80137EB8 03E00008 */  jr        $ra
/* CE5BC 80137EBC 00000000 */   nop      
