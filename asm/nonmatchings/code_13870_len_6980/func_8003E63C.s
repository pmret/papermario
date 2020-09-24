.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8003E63C
/* 19A3C 8003E63C 3C03800A */  lui       $v1, 0x800a
/* 19A40 8003E640 8C63A600 */  lw        $v1, -0x5a00($v1)
/* 19A44 8003E644 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 19A48 8003E648 10600006 */  beqz      $v1, .L8003E664
/* 19A4C 8003E64C AFBF0010 */   sw       $ra, 0x10($sp)
/* 19A50 8003E650 24020003 */  addiu     $v0, $zero, 3
/* 19A54 8003E654 14620003 */  bne       $v1, $v0, .L8003E664
/* 19A58 8003E658 00000000 */   nop      
/* 19A5C 8003E65C 0C010717 */  jal       show_first_strike_message
/* 19A60 8003E660 00000000 */   nop      
.L8003E664:
/* 19A64 8003E664 8FBF0010 */  lw        $ra, 0x10($sp)
/* 19A68 8003E668 03E00008 */  jr        $ra
/* 19A6C 8003E66C 27BD0018 */   addiu    $sp, $sp, 0x18
