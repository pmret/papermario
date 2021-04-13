.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80033418
/* E818 80033418 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* E81C 8003341C 240200FF */  addiu     $v0, $zero, 0xff
/* E820 80033420 0000202D */  daddu     $a0, $zero, $zero
/* E824 80033424 0080282D */  daddu     $a1, $a0, $zero
/* E828 80033428 2406013F */  addiu     $a2, $zero, 0x13f
/* E82C 8003342C 240700EF */  addiu     $a3, $zero, 0xef
/* E830 80033430 AFBF0020 */  sw        $ra, 0x20($sp)
/* E834 80033434 AFA00010 */  sw        $zero, 0x10($sp)
/* E838 80033438 AFA00014 */  sw        $zero, 0x14($sp)
/* E83C 8003343C AFA00018 */  sw        $zero, 0x18($sp)
/* E840 80033440 0C00AAC7 */  jal       func_8002AB1C
/* E844 80033444 AFA2001C */   sw       $v0, 0x1c($sp)
/* E848 80033448 8FBF0020 */  lw        $ra, 0x20($sp)
/* E84C 8003344C 03E00008 */  jr        $ra
/* E850 80033450 27BD0028 */   addiu    $sp, $sp, 0x28
/* E854 80033454 00000000 */  nop
/* E858 80033458 00000000 */  nop
/* E85C 8003345C 00000000 */  nop
