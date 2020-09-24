.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80035E54
/* 11254 80035E54 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 11258 80035E58 24020004 */  addiu     $v0, $zero, 4
/* 1125C 80035E5C AFB10014 */  sw        $s1, 0x14($sp)
/* 11260 80035E60 3C118007 */  lui       $s1, 0x8007
/* 11264 80035E64 2631419C */  addiu     $s1, $s1, 0x419c
/* 11268 80035E68 AFB00010 */  sw        $s0, 0x10($sp)
/* 1126C 80035E6C 3C10800A */  lui       $s0, 0x800a
/* 11270 80035E70 26100940 */  addiu     $s0, $s0, 0x940
/* 11274 80035E74 AFBF0018 */  sw        $ra, 0x18($sp)
/* 11278 80035E78 3C01800A */  lui       $at, 0x800a
/* 1127C 80035E7C A4200944 */  sh        $zero, 0x944($at)
/* 11280 80035E80 3C01800A */  lui       $at, 0x800a
/* 11284 80035E84 A4220946 */  sh        $v0, 0x946($at)
/* 11288 80035E88 8E230000 */  lw        $v1, ($s1)
/* 1128C 80035E8C 240200FF */  addiu     $v0, $zero, 0xff
/* 11290 80035E90 A6020000 */  sh        $v0, ($s0)
/* 11294 80035E94 0C018030 */  jal       nuContRmbForceStopEnd
/* 11298 80035E98 AC600094 */   sw       $zero, 0x94($v1)
/* 1129C 80035E9C 0C04E0AB */  jal       func_801382AC
/* 112A0 80035EA0 0200202D */   daddu    $a0, $s0, $zero
/* 112A4 80035EA4 0000202D */  daddu     $a0, $zero, $zero
/* 112A8 80035EA8 3C05F5DE */  lui       $a1, 0xf5de
/* 112AC 80035EAC 3C03800A */  lui       $v1, 0x800a
/* 112B0 80035EB0 2463A650 */  addiu     $v1, $v1, -0x59b0
/* 112B4 80035EB4 8C620000 */  lw        $v0, ($v1)
/* 112B8 80035EB8 8E260000 */  lw        $a2, ($s1)
/* 112BC 80035EBC 34420008 */  ori       $v0, $v0, 8
/* 112C0 80035EC0 AC620000 */  sw        $v0, ($v1)
/* 112C4 80035EC4 80C600A9 */  lb        $a2, 0xa9($a2)
/* 112C8 80035EC8 0C0B2026 */  jal       set_variable
/* 112CC 80035ECC 34A50181 */   ori      $a1, $a1, 0x181
/* 112D0 80035ED0 8FBF0018 */  lw        $ra, 0x18($sp)
/* 112D4 80035ED4 8FB10014 */  lw        $s1, 0x14($sp)
/* 112D8 80035ED8 8FB00010 */  lw        $s0, 0x10($sp)
/* 112DC 80035EDC 3C01800A */  lui       $at, 0x800a
/* 112E0 80035EE0 AC20A5D8 */  sw        $zero, -0x5a28($at)
/* 112E4 80035EE4 03E00008 */  jr        $ra
/* 112E8 80035EE8 27BD0020 */   addiu    $sp, $sp, 0x20
