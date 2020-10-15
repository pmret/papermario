.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80263CC4
/* 1925A4 80263CC4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 1925A8 80263CC8 AFB00010 */  sw        $s0, 0x10($sp)
/* 1925AC 80263CCC 0080802D */  daddu     $s0, $a0, $zero
/* 1925B0 80263CD0 3C048029 */  lui       $a0, 0x8029
/* 1925B4 80263CD4 24843820 */  addiu     $a0, $a0, 0x3820
/* 1925B8 80263CD8 2405000A */  addiu     $a1, $zero, 0xa
/* 1925BC 80263CDC AFBF0014 */  sw        $ra, 0x14($sp)
/* 1925C0 80263CE0 0C0B0CF8 */  jal       start_script
/* 1925C4 80263CE4 0000302D */   daddu    $a2, $zero, $zero
/* 1925C8 80263CE8 AC500084 */  sw        $s0, 0x84($v0)
/* 1925CC 80263CEC 8FBF0014 */  lw        $ra, 0x14($sp)
/* 1925D0 80263CF0 8FB00010 */  lw        $s0, 0x10($sp)
/* 1925D4 80263CF4 03E00008 */  jr        $ra
/* 1925D8 80263CF8 27BD0018 */   addiu    $sp, $sp, 0x18
