.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024228C_7ECF9C
/* 7ECF9C 8024228C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 7ECFA0 80242290 AFB00010 */  sw        $s0, 0x10($sp)
/* 7ECFA4 80242294 AFBF0014 */  sw        $ra, 0x14($sp)
/* 7ECFA8 80242298 0C039D7B */  jal       get_item_count
/* 7ECFAC 8024229C 0080802D */   daddu    $s0, $a0, $zero
/* 7ECFB0 802422A0 AE020084 */  sw        $v0, 0x84($s0)
/* 7ECFB4 802422A4 8FBF0014 */  lw        $ra, 0x14($sp)
/* 7ECFB8 802422A8 8FB00010 */  lw        $s0, 0x10($sp)
/* 7ECFBC 802422AC 24020002 */  addiu     $v0, $zero, 2
/* 7ECFC0 802422B0 03E00008 */  jr        $ra
/* 7ECFC4 802422B4 27BD0018 */   addiu    $sp, $sp, 0x18
/* 7ECFC8 802422B8 00000000 */  nop
/* 7ECFCC 802422BC 00000000 */  nop
