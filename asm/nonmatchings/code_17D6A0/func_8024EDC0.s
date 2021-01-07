.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024EDC0
/* 17D6A0 8024EDC0 0000202D */  daddu     $a0, $zero, $zero
/* 17D6A4 8024EDC4 3C03802A */  lui       $v1, %hi(D_8029F2C0)
/* 17D6A8 8024EDC8 2463F2C0 */  addiu     $v1, $v1, %lo(D_8029F2C0)
.L8024EDCC:
/* 17D6AC 8024EDCC A4600010 */  sh        $zero, 0x10($v1)
/* 17D6B0 8024EDD0 AC600018 */  sw        $zero, 0x18($v1)
/* 17D6B4 8024EDD4 24840001 */  addiu     $a0, $a0, 1
/* 17D6B8 8024EDD8 28820020 */  slti      $v0, $a0, 0x20
/* 17D6BC 8024EDDC 1440FFFB */  bnez      $v0, .L8024EDCC
/* 17D6C0 8024EDE0 2463001C */   addiu    $v1, $v1, 0x1c
/* 17D6C4 8024EDE4 03E00008 */  jr        $ra
/* 17D6C8 8024EDE8 00000000 */   nop      
