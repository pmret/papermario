.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80269160
/* 197A40 80269160 3C03802A */  lui       $v1, %hi(D_8029FBE0)
/* 197A44 80269164 2463FBE0 */  addiu     $v1, $v1, %lo(D_8029FBE0)
/* 197A48 80269168 8062005E */  lb        $v0, 0x5e($v1)
/* 197A4C 8026916C 3C048011 */  lui       $a0, %hi(gPlayerData)
/* 197A50 80269170 2484F290 */  addiu     $a0, $a0, %lo(gPlayerData)
/* 197A54 80269174 14400007 */  bnez      $v0, .L80269194
/* 197A58 80269178 00000000 */   nop      
/* 197A5C 8026917C 8462006E */  lh        $v0, 0x6e($v1)
/* 197A60 80269180 10400004 */  beqz      $v0, .L80269194
/* 197A64 80269184 00000000 */   nop      
/* 197A68 80269188 94820296 */  lhu       $v0, 0x296($a0)
/* 197A6C 8026918C 24420001 */  addiu     $v0, $v0, 1
/* 197A70 80269190 A4820296 */  sh        $v0, 0x296($a0)
.L80269194:
/* 197A74 80269194 03E00008 */  jr        $ra
/* 197A78 80269198 00000000 */   nop      
