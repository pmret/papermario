.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8003C2DC
/* 176DC 8003C2DC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 176E0 8003C2E0 00851021 */  addu      $v0, $a0, $a1
/* 176E4 8003C2E4 AFBF0010 */  sw        $ra, 0x10($sp)
/* 176E8 8003C2E8 8043032C */  lb        $v1, 0x32c($v0)
/* 176EC 8003C2EC 04600007 */  bltz      $v1, .L8003C30C
/* 176F0 8003C2F0 28620006 */   slti     $v0, $v1, 6
/* 176F4 8003C2F4 14400005 */  bnez      $v0, .L8003C30C
/* 176F8 8003C2F8 24020006 */   addiu    $v0, $zero, 6
/* 176FC 8003C2FC 14620003 */  bne       $v1, $v0, .L8003C30C
/* 17700 8003C300 00000000 */   nop
/* 17704 8003C304 0C00F31A */  jal       func_8003CC68
/* 17708 8003C308 00000000 */   nop
.L8003C30C:
/* 1770C 8003C30C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 17710 8003C310 03E00008 */  jr        $ra
/* 17714 8003C314 27BD0018 */   addiu    $sp, $sp, 0x18
