.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800614E0
/* 3C8E0 800614E0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 3C8E4 800614E4 AFBF0010 */  sw        $ra, 0x10($sp)
/* 3C8E8 800614E8 3C04800B */  lui       $a0, %hi(D_800B4360)
/* 3C8EC 800614EC 24844360 */  addiu     $a0, $a0, %lo(D_800B4360)
/* 3C8F0 800614F0 00002821 */  addu      $a1, $zero, $zero
/* 3C8F4 800614F4 0C0195FC */  jal       func_800657F0
/* 3C8F8 800614F8 00003021 */   addu     $a2, $zero, $zero
/* 3C8FC 800614FC 8FBF0010 */  lw        $ra, 0x10($sp)
/* 3C900 80061500 03E00008 */  jr        $ra
/* 3C904 80061504 27BD0018 */   addiu    $sp, $sp, 0x18
/* 3C908 80061508 00000000 */  nop
/* 3C90C 8006150C 00000000 */  nop
