.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800F4CF0
/* 8E1A0 800F4CF0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 8E1A4 800F4CF4 3C04001D */  lui       $a0, 0x1d
/* 8E1A8 800F4CF8 3484006B */  ori       $a0, $a0, 0x6b
/* 8E1AC 800F4CFC 2402000F */  addiu     $v0, $zero, 0xf
/* 8E1B0 800F4D00 24A50010 */  addiu     $a1, $a1, 0x10
/* 8E1B4 800F4D04 24C60002 */  addiu     $a2, $a2, 2
/* 8E1B8 800F4D08 240700FF */  addiu     $a3, $zero, 0xff
/* 8E1BC 800F4D0C AFBF0018 */  sw        $ra, 0x18($sp)
/* 8E1C0 800F4D10 AFA20010 */  sw        $v0, 0x10($sp)
/* 8E1C4 800F4D14 0C04993B */  jal       draw_msg
/* 8E1C8 800F4D18 AFA00014 */   sw       $zero, 0x14($sp)
/* 8E1CC 800F4D1C 8FBF0018 */  lw        $ra, 0x18($sp)
/* 8E1D0 800F4D20 03E00008 */  jr        $ra
/* 8E1D4 800F4D24 27BD0020 */   addiu    $sp, $sp, 0x20
