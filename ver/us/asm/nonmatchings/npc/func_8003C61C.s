.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8003C61C
/* 17A1C 8003C61C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 17A20 8003C620 00851021 */  addu      $v0, $a0, $a1
/* 17A24 8003C624 AFBF0010 */  sw        $ra, 0x10($sp)
/* 17A28 8003C628 8043032C */  lb        $v1, 0x32c($v0)
/* 17A2C 8003C62C 04600007 */  bltz      $v1, .L8003C64C
/* 17A30 8003C630 28620006 */   slti     $v0, $v1, 6
/* 17A34 8003C634 14400005 */  bnez      $v0, .L8003C64C
/* 17A38 8003C638 24020006 */   addiu    $v0, $zero, 6
/* 17A3C 8003C63C 14620003 */  bne       $v1, $v0, .L8003C64C
/* 17A40 8003C640 00000000 */   nop
/* 17A44 8003C644 0C00F3EA */  jal       func_8003CFA8
/* 17A48 8003C648 00000000 */   nop
.L8003C64C:
/* 17A4C 8003C64C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 17A50 8003C650 03E00008 */  jr        $ra
/* 17A54 8003C654 27BD0018 */   addiu    $sp, $sp, 0x18
