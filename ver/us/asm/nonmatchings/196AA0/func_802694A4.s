.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802694A4
/* 197D84 802694A4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 197D88 802694A8 AFBF0018 */  sw        $ra, 0x18($sp)
/* 197D8C 802694AC AFB10014 */  sw        $s1, 0x14($sp)
/* 197D90 802694B0 AFB00010 */  sw        $s0, 0x10($sp)
/* 197D94 802694B4 8C82000C */  lw        $v0, 0xc($a0)
/* 197D98 802694B8 3C10802A */  lui       $s0, %hi(gActionCommandStatus)
/* 197D9C 802694BC 2610FBE0 */  addiu     $s0, $s0, %lo(gActionCommandStatus)
/* 197DA0 802694C0 8C450000 */  lw        $a1, ($v0)
/* 197DA4 802694C4 0C0B1EAF */  jal       get_variable
/* 197DA8 802694C8 0200882D */   daddu    $s1, $s0, $zero
/* 197DAC 802694CC 14400003 */  bnez      $v0, .L802694DC
/* 197DB0 802694D0 24020001 */   addiu    $v0, $zero, 1
/* 197DB4 802694D4 0809A538 */  j         .L802694E0
/* 197DB8 802694D8 A2000061 */   sb       $zero, 0x61($s0)
.L802694DC:
/* 197DBC 802694DC A2220061 */  sb        $v0, 0x61($s1)
.L802694E0:
/* 197DC0 802694E0 8FBF0018 */  lw        $ra, 0x18($sp)
/* 197DC4 802694E4 8FB10014 */  lw        $s1, 0x14($sp)
/* 197DC8 802694E8 8FB00010 */  lw        $s0, 0x10($sp)
/* 197DCC 802694EC 24020002 */  addiu     $v0, $zero, 2
/* 197DD0 802694F0 03E00008 */  jr        $ra
/* 197DD4 802694F4 27BD0020 */   addiu    $sp, $sp, 0x20
