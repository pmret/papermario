.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel DispatchEvent
/* 1ABB44 8027D264 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 1ABB48 8027D268 AFB10014 */  sw        $s1, 0x14($sp)
/* 1ABB4C 8027D26C 0080882D */  daddu     $s1, $a0, $zero
/* 1ABB50 8027D270 AFBF0018 */  sw        $ra, 0x18($sp)
/* 1ABB54 8027D274 AFB00010 */  sw        $s0, 0x10($sp)
/* 1ABB58 8027D278 8E30000C */  lw        $s0, 0xc($s1)
/* 1ABB5C 8027D27C 8E050000 */  lw        $a1, ($s0)
/* 1ABB60 8027D280 0C0B1EAF */  jal       get_variable
/* 1ABB64 8027D284 26100004 */   addiu    $s0, $s0, 4
/* 1ABB68 8027D288 0040202D */  daddu     $a0, $v0, $zero
/* 1ABB6C 8027D28C 2402FF81 */  addiu     $v0, $zero, -0x7f
/* 1ABB70 8027D290 14820002 */  bne       $a0, $v0, .L8027D29C
/* 1ABB74 8027D294 00000000 */   nop      
/* 1ABB78 8027D298 8E240148 */  lw        $a0, 0x148($s1)
.L8027D29C:
/* 1ABB7C 8027D29C 0C09A75B */  jal       get_actor
/* 1ABB80 8027D2A0 00000000 */   nop      
/* 1ABB84 8027D2A4 0220202D */  daddu     $a0, $s1, $zero
/* 1ABB88 8027D2A8 8E050000 */  lw        $a1, ($s0)
/* 1ABB8C 8027D2AC 0C0B1EAF */  jal       get_variable
/* 1ABB90 8027D2B0 0040802D */   daddu    $s0, $v0, $zero
/* 1ABB94 8027D2B4 0200202D */  daddu     $a0, $s0, $zero
/* 1ABB98 8027D2B8 0C09DC58 */  jal       dispatch_event_actor
/* 1ABB9C 8027D2BC 0040282D */   daddu    $a1, $v0, $zero
/* 1ABBA0 8027D2C0 8FBF0018 */  lw        $ra, 0x18($sp)
/* 1ABBA4 8027D2C4 8FB10014 */  lw        $s1, 0x14($sp)
/* 1ABBA8 8027D2C8 8FB00010 */  lw        $s0, 0x10($sp)
/* 1ABBAC 8027D2CC 24020002 */  addiu     $v0, $zero, 2
/* 1ABBB0 8027D2D0 03E00008 */  jr        $ra
/* 1ABBB4 8027D2D4 27BD0020 */   addiu    $sp, $sp, 0x20
