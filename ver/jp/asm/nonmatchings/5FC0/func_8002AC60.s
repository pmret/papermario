.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8002AC60
/* 6060 8002AC60 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 6064 8002AC64 AFBF0010 */  sw        $ra, 0x10($sp)
/* 6068 8002AC68 3C050002 */  lui       $a1, 2
/* 606C 8002AC6C 3C04803E */  lui       $a0, %hi(D_803DA800)
/* 6070 8002AC70 2484A800 */  addiu     $a0, $a0, %lo(D_803DA800)
/* 6074 8002AC74 0C00A3FC */  jal       func_80028FF0
/* 6078 8002AC78 34A55800 */   ori      $a1, $a1, 0x5800
/* 607C 8002AC7C 0040202D */  daddu     $a0, $v0, $zero
/* 6080 8002AC80 2402FFFF */  addiu     $v0, $zero, -1
/* 6084 8002AC84 0040182D */  daddu     $v1, $v0, $zero
/* 6088 8002AC88 54830001 */  bnel      $a0, $v1, .L8002AC90
/* 608C 8002AC8C 0000102D */   daddu    $v0, $zero, $zero
.L8002AC90:
/* 6090 8002AC90 8FBF0010 */  lw        $ra, 0x10($sp)
/* 6094 8002AC94 03E00008 */  jr        $ra
/* 6098 8002AC98 27BD0018 */   addiu    $sp, $sp, 0x18
