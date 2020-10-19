.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024228C_91193C
/* 91193C 8024228C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 911940 80242290 3C05FE36 */  lui       $a1, 0xfe36
/* 911944 80242294 AFBF0010 */  sw        $ra, 0x10($sp)
/* 911948 80242298 8C820148 */  lw        $v0, 0x148($a0)
/* 91194C 8024229C 3C06800B */  lui       $a2, 0x800b
/* 911950 802422A0 8CC60F9C */  lw        $a2, 0xf9c($a2)
/* 911954 802422A4 34A53C80 */  ori       $a1, $a1, 0x3c80
/* 911958 802422A8 00C23026 */  xor       $a2, $a2, $v0
/* 91195C 802422AC 0C0B2026 */  jal       set_variable
/* 911960 802422B0 2CC60001 */   sltiu    $a2, $a2, 1
/* 911964 802422B4 8FBF0010 */  lw        $ra, 0x10($sp)
/* 911968 802422B8 24020002 */  addiu     $v0, $zero, 2
/* 91196C 802422BC 03E00008 */  jr        $ra
/* 911970 802422C0 27BD0018 */   addiu    $sp, $sp, 0x18
