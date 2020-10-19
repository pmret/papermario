.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802404D0_9AEBD0
/* 9AEBD0 802404D0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 9AEBD4 802404D4 AFB00010 */  sw        $s0, 0x10($sp)
/* 9AEBD8 802404D8 3C108024 */  lui       $s0, 0x8024
/* 9AEBDC 802404DC 26103090 */  addiu     $s0, $s0, 0x3090
/* 9AEBE0 802404E0 AFBF0014 */  sw        $ra, 0x14($sp)
/* 9AEBE4 802404E4 0C04EA15 */  jal       func_8013A854
/* 9AEBE8 802404E8 8E040000 */   lw       $a0, ($s0)
/* 9AEBEC 802404EC 0C048D70 */  jal       func_801235C0
/* 9AEBF0 802404F0 8E040004 */   lw       $a0, 4($s0)
/* 9AEBF4 802404F4 8FBF0014 */  lw        $ra, 0x14($sp)
/* 9AEBF8 802404F8 8FB00010 */  lw        $s0, 0x10($sp)
/* 9AEBFC 802404FC 24020002 */  addiu     $v0, $zero, 2
/* 9AEC00 80240500 03E00008 */  jr        $ra
/* 9AEC04 80240504 27BD0018 */   addiu    $sp, $sp, 0x18
