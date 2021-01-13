.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802E8A58
/* 10A2D8 802E8A58 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 10A2DC 802E8A5C 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 10A2E0 802E8A60 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 10A2E4 802E8A64 AFBF0010 */  sw        $ra, 0x10($sp)
/* 10A2E8 802E8A68 8C850040 */  lw        $a1, 0x40($a0)
/* 10A2EC 802E8A6C 8443008E */  lh        $v1, 0x8e($v0)
/* 10A2F0 802E8A70 8CA2000C */  lw        $v0, 0xc($a1)
/* 10A2F4 802E8A74 14430014 */  bne       $v0, $v1, .L802E8AC8
/* 10A2F8 802E8A78 00000000 */   nop
/* 10A2FC 802E8A7C 8CA30004 */  lw        $v1, 4($a1)
/* 10A300 802E8A80 10600005 */  beqz      $v1, .L802E8A98
/* 10A304 802E8A84 24020001 */   addiu    $v0, $zero, 1
/* 10A308 802E8A88 10620009 */  beq       $v1, $v0, .L802E8AB0
/* 10A30C 802E8A8C 00000000 */   nop
/* 10A310 802E8A90 080BA2B2 */  j         .L802E8AC8
/* 10A314 802E8A94 00000000 */   nop
.L802E8A98:
/* 10A318 802E8A98 3C028016 */  lui       $v0, %hi(gCollisionStatus+0x2)
/* 10A31C 802E8A9C 8442A552 */  lh        $v0, %lo(gCollisionStatus+0x2)($v0)
/* 10A320 802E8AA0 1840000B */  blez      $v0, .L802E8AD0
/* 10A324 802E8AA4 24020001 */   addiu    $v0, $zero, 1
/* 10A328 802E8AA8 080BA2B4 */  j         .L802E8AD0
/* 10A32C 802E8AAC ACA20004 */   sw       $v0, 4($a1)
.L802E8AB0:
/* 10A330 802E8AB0 3C028016 */  lui       $v0, %hi(gCollisionStatus+0x2)
/* 10A334 802E8AB4 8442A552 */  lh        $v0, %lo(gCollisionStatus+0x2)($v0)
/* 10A338 802E8AB8 04410005 */  bgez      $v0, .L802E8AD0
/* 10A33C 802E8ABC 24020002 */   addiu    $v0, $zero, 2
/* 10A340 802E8AC0 080BA2B4 */  j         .L802E8AD0
/* 10A344 802E8AC4 ACA20004 */   sw       $v0, 4($a1)
.L802E8AC8:
/* 10A348 802E8AC8 0C043F5A */  jal       func_8010FD68
/* 10A34C 802E8ACC 00000000 */   nop
.L802E8AD0:
/* 10A350 802E8AD0 8FBF0010 */  lw        $ra, 0x10($sp)
/* 10A354 802E8AD4 03E00008 */  jr        $ra
/* 10A358 802E8AD8 27BD0018 */   addiu    $sp, $sp, 0x18
