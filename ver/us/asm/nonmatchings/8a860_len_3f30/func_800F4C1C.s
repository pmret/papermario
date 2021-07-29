.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800F4C1C
/* 8E0CC 800F4C1C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 8E0D0 800F4C20 3C04001D */  lui       $a0, 0x1d
/* 8E0D4 800F4C24 34840069 */  ori       $a0, $a0, 0x69
/* 8E0D8 800F4C28 24A5000B */  addiu     $a1, $a1, 0xb
/* 8E0DC 800F4C2C 24C60008 */  addiu     $a2, $a2, 8
/* 8E0E0 800F4C30 3C038011 */  lui       $v1, %hi(D_8010D699)
/* 8E0E4 800F4C34 8063D699 */  lb        $v1, %lo(D_8010D699)($v1)
/* 8E0E8 800F4C38 24020001 */  addiu     $v0, $zero, 1
/* 8E0EC 800F4C3C 14620003 */  bne       $v1, $v0, .L800F4C4C
/* 8E0F0 800F4C40 AFBF0018 */   sw       $ra, 0x18($sp)
/* 8E0F4 800F4C44 3C04001D */  lui       $a0, 0x1d
/* 8E0F8 800F4C48 34840068 */  ori       $a0, $a0, 0x68
.L800F4C4C:
/* 8E0FC 800F4C4C 2402000F */  addiu     $v0, $zero, 0xf
/* 8E100 800F4C50 240700FF */  addiu     $a3, $zero, 0xff
/* 8E104 800F4C54 AFA20010 */  sw        $v0, 0x10($sp)
/* 8E108 800F4C58 0C04993B */  jal       draw_string
/* 8E10C 800F4C5C AFA00014 */   sw       $zero, 0x14($sp)
/* 8E110 800F4C60 8FBF0018 */  lw        $ra, 0x18($sp)
/* 8E114 800F4C64 03E00008 */  jr        $ra
/* 8E118 800F4C68 27BD0020 */   addiu    $sp, $sp, 0x20
