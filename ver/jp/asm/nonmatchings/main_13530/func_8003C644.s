.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8003C644
/* 17A44 8003C644 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 17A48 8003C648 00052880 */  sll       $a1, $a1, 2
/* 17A4C 8003C64C 00852021 */  addu      $a0, $a0, $a1
/* 17A50 8003C650 AFBF0010 */  sw        $ra, 0x10($sp)
/* 17A54 8003C654 0C016840 */  jal       func_8005A100
/* 17A58 8003C658 8C840324 */   lw       $a0, 0x324($a0)
/* 17A5C 8003C65C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 17A60 8003C660 03E00008 */  jr        $ra
/* 17A64 8003C664 27BD0018 */   addiu    $sp, $sp, 0x18
