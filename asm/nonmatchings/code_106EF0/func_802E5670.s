.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802E5670
/* 106EF0 802E5670 948200D0 */  lhu       $v0, 0xd0($a0)
/* 106EF4 802E5674 00451023 */  subu      $v0, $v0, $a1
/* 106EF8 802E5678 04420001 */  bltzl     $v0, .L802E5680
/* 106EFC 802E567C 24420014 */   addiu    $v0, $v0, 0x14
.L802E5680:
/* 106F00 802E5680 00021080 */  sll       $v0, $v0, 2
/* 106F04 802E5684 00821021 */  addu      $v0, $a0, $v0
/* 106F08 802E5688 03E00008 */  jr        $ra
/* 106F0C 802E568C C44000D4 */   lwc1     $f0, 0xd4($v0)
