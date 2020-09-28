.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8014ABB4
/* E12B4 8014ABB4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* E12B8 8014ABB8 3C028016 */  lui       $v0, 0x8016
/* E12BC 8014ABBC 24429AF0 */  addiu     $v0, $v0, -0x6510
/* E12C0 8014ABC0 00041840 */  sll       $v1, $a0, 1
/* E12C4 8014ABC4 00641821 */  addu      $v1, $v1, $a0
/* E12C8 8014ABC8 00031900 */  sll       $v1, $v1, 4
/* E12CC 8014ABCC 00621821 */  addu      $v1, $v1, $v0
/* E12D0 8014ABD0 AFBF0010 */  sw        $ra, 0x10($sp)
/* E12D4 8014ABD4 94620000 */  lhu       $v0, ($v1)
/* E12D8 8014ABD8 30420001 */  andi      $v0, $v0, 1
/* E12DC 8014ABDC 10400006 */  beqz      $v0, .L8014ABF8
/* E12E0 8014ABE0 00052C00 */   sll      $a1, $a1, 0x10
/* E12E4 8014ABE4 8C640018 */  lw        $a0, 0x18($v1)
/* E12E8 8014ABE8 0C015731 */  jal       func_80055CC4
/* E12EC 8014ABEC 00052C03 */   sra      $a1, $a1, 0x10
/* E12F0 8014ABF0 08052AFF */  j         .L8014ABFC
/* E12F4 8014ABF4 00000000 */   nop      
.L8014ABF8:
/* E12F8 8014ABF8 0000102D */  daddu     $v0, $zero, $zero
.L8014ABFC:
/* E12FC 8014ABFC 8FBF0010 */  lw        $ra, 0x10($sp)
/* E1300 8014AC00 03E00008 */  jr        $ra
/* E1304 8014AC04 27BD0018 */   addiu    $sp, $sp, 0x18
