.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8003C7E0
/* 17BE0 8003C7E0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 17BE4 8003C7E4 00052880 */  sll       $a1, $a1, 2
/* 17BE8 8003C7E8 00852021 */  addu      $a0, $a0, $a1
/* 17BEC 8003C7EC AFBF0010 */  sw        $ra, 0x10($sp)
/* 17BF0 8003C7F0 0C016840 */  jal       func_8005A100
/* 17BF4 8003C7F4 8C840324 */   lw       $a0, 0x324($a0)
/* 17BF8 8003C7F8 8FBF0010 */  lw        $ra, 0x10($sp)
/* 17BFC 8003C7FC 03E00008 */  jr        $ra
/* 17C00 8003C800 27BD0018 */   addiu    $sp, $sp, 0x18
