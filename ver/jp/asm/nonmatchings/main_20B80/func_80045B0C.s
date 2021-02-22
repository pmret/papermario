.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80045B0C
/* 20F0C 80045B0C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 20F10 80045B10 24A5000B */  addiu     $a1, $a1, 0xb
/* 20F14 80045B14 AFBF0018 */  sw        $ra, 0x18($sp)
/* 20F18 80045B18 84830012 */  lh        $v1, 0x12($a0)
/* 20F1C 80045B1C 28620002 */  slti      $v0, $v1, 2
/* 20F20 80045B20 1040000B */  beqz      $v0, .L80045B50
/* 20F24 80045B24 24C60006 */   addiu    $a2, $a2, 6
/* 20F28 80045B28 04600009 */  bltz      $v1, .L80045B50
/* 20F2C 80045B2C 00031080 */   sll      $v0, $v1, 2
/* 20F30 80045B30 3C048008 */  lui       $a0, %hi(D_80078130)
/* 20F34 80045B34 00822021 */  addu      $a0, $a0, $v0
/* 20F38 80045B38 8C848130 */  lw        $a0, %lo(D_80078130)($a0)
/* 20F3C 80045B3C 2402000F */  addiu     $v0, $zero, 0xf
/* 20F40 80045B40 240700FF */  addiu     $a3, $zero, 0xff
/* 20F44 80045B44 AFA20010 */  sw        $v0, 0x10($sp)
/* 20F48 80045B48 0C04ADC4 */  jal       func_8012B710
/* 20F4C 80045B4C AFA00014 */   sw       $zero, 0x14($sp)
.L80045B50:
/* 20F50 80045B50 8FBF0018 */  lw        $ra, 0x18($sp)
/* 20F54 80045B54 03E00008 */  jr        $ra
/* 20F58 80045B58 27BD0020 */   addiu    $sp, $sp, 0x20
