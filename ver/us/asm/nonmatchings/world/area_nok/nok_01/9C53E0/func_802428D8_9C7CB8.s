.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802428D8_9C7CB8
/* 9C7CB8 802428D8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 9C7CBC 802428DC AFBF0010 */  sw        $ra, 0x10($sp)
/* 9C7CC0 802428E0 8C82000C */  lw        $v0, 0xc($a0)
/* 9C7CC4 802428E4 0C0B1EAF */  jal       evt_get_variable
/* 9C7CC8 802428E8 8C450000 */   lw       $a1, ($v0)
/* 9C7CCC 802428EC 00021040 */  sll       $v0, $v0, 1
/* 9C7CD0 802428F0 3C048025 */  lui       $a0, %hi(D_80250810_9D5BF0)
/* 9C7CD4 802428F4 00822021 */  addu      $a0, $a0, $v0
/* 9C7CD8 802428F8 0C015612 */  jal       func_80055848
/* 9C7CDC 802428FC 84840810 */   lh       $a0, %lo(D_80250810_9D5BF0)($a0)
/* 9C7CE0 80242900 8FBF0010 */  lw        $ra, 0x10($sp)
/* 9C7CE4 80242904 24020002 */  addiu     $v0, $zero, 2
/* 9C7CE8 80242908 03E00008 */  jr        $ra
/* 9C7CEC 8024290C 27BD0018 */   addiu    $sp, $sp, 0x18
