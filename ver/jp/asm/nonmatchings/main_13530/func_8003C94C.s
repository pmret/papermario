.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8003C94C
/* 17D4C 8003C94C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 17D50 8003C950 00052880 */  sll       $a1, $a1, 2
/* 17D54 8003C954 00852021 */  addu      $a0, $a0, $a1
/* 17D58 8003C958 AFBF0010 */  sw        $ra, 0x10($sp)
/* 17D5C 8003C95C 0C016840 */  jal       func_8005A100
/* 17D60 8003C960 8C840324 */   lw       $a0, 0x324($a0)
/* 17D64 8003C964 8FBF0010 */  lw        $ra, 0x10($sp)
/* 17D68 8003C968 03E00008 */  jr        $ra
/* 17D6C 8003C96C 27BD0018 */   addiu    $sp, $sp, 0x18
