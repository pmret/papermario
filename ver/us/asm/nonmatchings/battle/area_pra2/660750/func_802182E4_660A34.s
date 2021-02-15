.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802182E4_660A34
/* 660A34 802182E4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 660A38 802182E8 AFBF0010 */  sw        $ra, 0x10($sp)
/* 660A3C 802182EC 8C82000C */  lw        $v0, 0xc($a0)
/* 660A40 802182F0 0C0B1EAF */  jal       get_variable
/* 660A44 802182F4 8C450000 */   lw       $a1, ($v0)
/* 660A48 802182F8 8C43000C */  lw        $v1, 0xc($v0)
/* 660A4C 802182FC 240500FF */  addiu     $a1, $zero, 0xff
/* 660A50 80218300 AC650030 */  sw        $a1, 0x30($v1)
/* 660A54 80218304 8C43000C */  lw        $v1, 0xc($v0)
/* 660A58 80218308 AC650034 */  sw        $a1, 0x34($v1)
/* 660A5C 8021830C 8C43000C */  lw        $v1, 0xc($v0)
/* 660A60 80218310 AC650038 */  sw        $a1, 0x38($v1)
/* 660A64 80218314 8C44000C */  lw        $a0, 0xc($v0)
/* 660A68 80218318 240300C8 */  addiu     $v1, $zero, 0xc8
/* 660A6C 8021831C AC830040 */  sw        $v1, 0x40($a0)
/* 660A70 80218320 8C44000C */  lw        $a0, 0xc($v0)
/* 660A74 80218324 240300F0 */  addiu     $v1, $zero, 0xf0
/* 660A78 80218328 AC830044 */  sw        $v1, 0x44($a0)
/* 660A7C 8021832C 8C43000C */  lw        $v1, 0xc($v0)
/* 660A80 80218330 AC650048 */  sw        $a1, 0x48($v1)
/* 660A84 80218334 8FBF0010 */  lw        $ra, 0x10($sp)
/* 660A88 80218338 24020002 */  addiu     $v0, $zero, 2
/* 660A8C 8021833C 03E00008 */  jr        $ra
/* 660A90 80218340 27BD0018 */   addiu    $sp, $sp, 0x18
