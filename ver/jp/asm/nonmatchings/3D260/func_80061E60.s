.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80061E60
/* 3D260 80061E60 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 3D264 80061E64 3C031FFF */  lui       $v1, 0x1fff
/* 3D268 80061E68 3463FFFF */  ori       $v1, $v1, 0xffff
/* 3D26C 80061E6C 3C028000 */  lui       $v0, 0x8000
/* 3D270 80061E70 00821023 */  subu      $v0, $a0, $v0
/* 3D274 80061E74 0062102B */  sltu      $v0, $v1, $v0
/* 3D278 80061E78 1040000A */  beqz      $v0, .L80061EA4
/* 3D27C 80061E7C AFBF0010 */   sw       $ra, 0x10($sp)
/* 3D280 80061E80 3C026000 */  lui       $v0, 0x6000
/* 3D284 80061E84 00821021 */  addu      $v0, $a0, $v0
/* 3D288 80061E88 0062102B */  sltu      $v0, $v1, $v0
/* 3D28C 80061E8C 10400006 */  beqz      $v0, .L80061EA8
/* 3D290 80061E90 00831024 */   and      $v0, $a0, $v1
/* 3D294 80061E94 0C019A0C */  jal       func_80066830
/* 3D298 80061E98 00000000 */   nop
/* 3D29C 80061E9C 080187AA */  j         .L80061EA8
/* 3D2A0 80061EA0 00000000 */   nop
.L80061EA4:
/* 3D2A4 80061EA4 00831024 */  and       $v0, $a0, $v1
.L80061EA8:
/* 3D2A8 80061EA8 8FBF0010 */  lw        $ra, 0x10($sp)
/* 3D2AC 80061EAC 03E00008 */  jr        $ra
/* 3D2B0 80061EB0 27BD0018 */   addiu    $sp, $sp, 0x18
/* 3D2B4 80061EB4 00000000 */  nop
/* 3D2B8 80061EB8 00000000 */  nop
/* 3D2BC 80061EBC 00000000 */  nop
