.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel DispatchDamageEvent
/* 1ABA9C 8027D1BC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 1ABAA0 8027D1C0 AFB20018 */  sw        $s2, 0x18($sp)
/* 1ABAA4 8027D1C4 0080902D */  daddu     $s2, $a0, $zero
/* 1ABAA8 8027D1C8 AFBF001C */  sw        $ra, 0x1c($sp)
/* 1ABAAC 8027D1CC AFB10014 */  sw        $s1, 0x14($sp)
/* 1ABAB0 8027D1D0 AFB00010 */  sw        $s0, 0x10($sp)
/* 1ABAB4 8027D1D4 8E50000C */  lw        $s0, 0xc($s2)
/* 1ABAB8 8027D1D8 8E050000 */  lw        $a1, ($s0)
/* 1ABABC 8027D1DC 0C0B1EAF */  jal       get_variable
/* 1ABAC0 8027D1E0 26100004 */   addiu    $s0, $s0, 4
/* 1ABAC4 8027D1E4 0040202D */  daddu     $a0, $v0, $zero
/* 1ABAC8 8027D1E8 2402FF81 */  addiu     $v0, $zero, -0x7f
/* 1ABACC 8027D1EC 14820002 */  bne       $a0, $v0, .L8027D1F8
/* 1ABAD0 8027D1F0 00000000 */   nop      
/* 1ABAD4 8027D1F4 8E440148 */  lw        $a0, 0x148($s2)
.L8027D1F8:
/* 1ABAD8 8027D1F8 0C09A75B */  jal       get_actor
/* 1ABADC 8027D1FC 00000000 */   nop      
/* 1ABAE0 8027D200 8E050000 */  lw        $a1, ($s0)
/* 1ABAE4 8027D204 26100004 */  addiu     $s0, $s0, 4
/* 1ABAE8 8027D208 0240202D */  daddu     $a0, $s2, $zero
/* 1ABAEC 8027D20C 0C0B1EAF */  jal       get_variable
/* 1ABAF0 8027D210 0040882D */   daddu    $s1, $v0, $zero
/* 1ABAF4 8027D214 0240202D */  daddu     $a0, $s2, $zero
/* 1ABAF8 8027D218 8E050000 */  lw        $a1, ($s0)
/* 1ABAFC 8027D21C 0C0B1EAF */  jal       get_variable
/* 1ABB00 8027D220 0040802D */   daddu    $s0, $v0, $zero
/* 1ABB04 8027D224 0220202D */  daddu     $a0, $s1, $zero
/* 1ABB08 8027D228 0200282D */  daddu     $a1, $s0, $zero
/* 1ABB0C 8027D22C 0C09E23E */  jal       dispatch_damage_event_actor_0
/* 1ABB10 8027D230 0040302D */   daddu    $a2, $v0, $zero
/* 1ABB14 8027D234 04420005 */  bltzl     $v0, .L8027D24C
/* 1ABB18 8027D238 0000102D */   daddu    $v0, $zero, $zero
/* 1ABB1C 8027D23C 0C0B1069 */  jal       does_script_exist_by_ref
/* 1ABB20 8027D240 0240202D */   daddu    $a0, $s2, $zero
/* 1ABB24 8027D244 0002102B */  sltu      $v0, $zero, $v0
/* 1ABB28 8027D248 00021040 */  sll       $v0, $v0, 1
.L8027D24C:
/* 1ABB2C 8027D24C 8FBF001C */  lw        $ra, 0x1c($sp)
/* 1ABB30 8027D250 8FB20018 */  lw        $s2, 0x18($sp)
/* 1ABB34 8027D254 8FB10014 */  lw        $s1, 0x14($sp)
/* 1ABB38 8027D258 8FB00010 */  lw        $s0, 0x10($sp)
/* 1ABB3C 8027D25C 03E00008 */  jr        $ra
/* 1ABB40 8027D260 27BD0020 */   addiu    $sp, $sp, 0x20
